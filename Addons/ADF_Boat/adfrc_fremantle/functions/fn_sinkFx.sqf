/*
    adfrc_fremantle_fnc_sinkFx

    Death sequence for any ship with an adfrc_sinkFx config class (Fremantle, Arafura):
    hull explosions at memory points, fires above the waterline, and each fire goes out
    once its point drops below the surface as the wreck sinks.

    Called by the MPKilled handler from adfrc_fremantle_fnc_sinkInit, so it runs once
    on every machine:
      - server:  hull explosions (createVehicle is global, so only one machine spawns them)
      - owner:   optional sink assist (mass / centre of mass), off by default
      - clients: fires, smoke, fire light (local effects, each client makes its own)

    Config (CfgVehicles >> <ship> >> adfrc_sinkFx):
        explosions[]     {memPoint, {offset}, ammo, delay}
        fires[]          {memPoint, {offset}, "big" | "medium" | "small", delay}
        extinguishHeight fire goes out when its point is at or below this height ASL (m)
        burnTime         max seconds a fire burns if the wreck never goes under (grounded)
        sinkAssist       0/1, scripted sinking on top of the engine's waterLeakiness
        sinkMassMult     mass multiplier reached over sinkTime (sinkAssist only)
        sinkTime         seconds for the mass ramp (sinkAssist only)
        sinkTowards      memory point the centre of mass shifts towards (sinkAssist only)
        sinkBias         0..1, how far the centre of mass moves towards that point

    Offsets are model space [x, y, z], z up, applied from the memory point.
    Delays are seconds after death.

    Params (MPKilled):
        0: SHIP <OBJECT>
        1: KILLER <OBJECT> (unused)
        2: INSTIGATOR <OBJECT> (unused)
        3: USE EFFECTS <BOOL> - false when killed with setDamage [1, false]

    Returns: nothing
*/
params ["_ship", "", "", ["_useEffects", true]];

if (!_useEffects) exitWith {};
if (_ship getVariable ["adfrc_sinkFx_done", false]) exitWith {};
_ship setVariable ["adfrc_sinkFx_done", true];

private _cfg = configOf _ship >> "adfrc_sinkFx";
if (!isClass _cfg) exitWith {};

// ---------------------------------------------------------------- hull explosions (server)
if (isServer) then {
    [_ship, getArray (_cfg >> "explosions")] spawn {
        params ["_ship", "_list"];
        private _queue = _list apply {[_x param [3, 0], _x]};
        _queue sort true;
        private _t0 = time;
        {
            (_x select 1) params ["_mem", ["_off", [0, 0, 0]], ["_ammo", "adfrc_ship_explosion_big"], ["_delay", 0]];
            private _wait = _t0 + _delay - time;
            if (_wait > 0) then {sleep _wait};
            if (isNull _ship) exitWith {};
            private _rel = _ship selectionPosition [_mem, "Memory"];
            if (_rel isEqualTo [0, 0, 0]) then {
                diag_log format ["[ADFRC] sinkFx: memory point '%1' not found on %2", _mem, typeOf _ship];
            };
            private _pos = _ship modelToWorldWorld (_rel vectorAdd _off);
            _pos set [2, (_pos select 2) max 0.5];  // keep the blast at or above the surface so the fireball shows
            private _blast = createVehicle [_ammo, ASLToATL _pos, [], 0, "CAN_COLLIDE"];
            _blast setPosASL _pos;
        } forEach _queue;
    };
};

// ---------------------------------------------------------------- sink assist (owner, opt-in)
if (local _ship && {getNumber (_cfg >> "sinkAssist") > 0}) then {
    private _time = (getNumber (_cfg >> "sinkTime")) max 1;
    private _mult = (getNumber (_cfg >> "sinkMassMult")) max 1;
    private _towards = getText (_cfg >> "sinkTowards");
    private _bias = ((getNumber (_cfg >> "sinkBias")) min 1) max 0;
    if (_towards != "") then {
        private _com = getCenterOfMass _ship;
        private _p = _ship selectionPosition [_towards, "Memory"];
        private _target = [_p select 0, _p select 1, _com select 2];
        _ship setCenterOfMass [_com vectorAdd ((_target vectorDiff _com) vectorMultiply _bias), _time * 0.5];
    };
    _ship setMass [(getMass _ship) * _mult, _time];
};

// ---------------------------------------------------------------- fires (every client)
if (hasInterface) then {
    [_ship, _cfg] spawn {
        params ["_ship", "_cfg"];
        private _extH = getNumber (_cfg >> "extinguishHeight");
        private _burnTime = getNumber (_cfg >> "burnTime");
        if (_burnTime <= 0) then {_burnTime = 600};

        // size -> [fire cloudlet, smoke cloudlet, light [intensity, attenuation]]
        // classes are vanilla CfgCloudlets; light values from BI's Showcase_Future effects.sqf
        private _sizes = createHashMapFromArray [
            ["big",    ["BigDestructionFire",    "BigDestructionSmoke",    [1600, [0, 0, 0, 1.6]]]],
            ["medium", ["MediumDestructionFire", "MediumDestructionSmoke", [400, [0, 0, 0, 2]]]],
            ["small",  ["SmallDestructionFire",  "SmallDestructionSmoke",  []]]
        ];

        // [mem, offset, size, delay, state (0 waiting, 1 burning, 2 out), [fire, smoke, light]]
        private _fires = (getArray (_cfg >> "fires")) apply {
            _x params ["_mem", ["_off", [0, 0, 0]], ["_size", "medium"], ["_delay", 0]];
            [_mem, _off, _size, _delay, 0, []]
        };

        private _t0 = time;
        while {!isNull _ship && {(_fires findIf {(_x select 4) < 2}) >= 0}} do {
            private _now = time - _t0;
            {
                _x params ["_mem", "_off", "_size", "_delay", "_state", "_objs"];
                if (_state < 2 && {_now >= _delay}) then {
                    private _z = (_ship modelToWorldWorld ((_ship selectionPosition [_mem, "Memory"]) vectorAdd _off)) select 2;
                    if (_state == 0) then {
                        if (_z <= _extH) then {
                            _x set [4, 2];  // already under when it was due, never lights
                        } else {
                            (_sizes getOrDefault [_size, _sizes get "medium"]) params ["_fireCls", "_smokeCls", "_light"];
                            private _fire = "#particlesource" createVehicleLocal [0, 0, 0];
                            _fire setParticleClass _fireCls;
                            _fire attachTo [_ship, _off, _mem];
                            private _smoke = "#particlesource" createVehicleLocal [0, 0, 0];
                            _smoke setParticleClass _smokeCls;
                            _smoke attachTo [_ship, _off, _mem];
                            private _lp = objNull;
                            if (_light isNotEqualTo []) then {
                                _light params ["_intensity", "_atten"];
                                _lp = "#lightpoint" createVehicleLocal [0, 0, 0];
                                _lp setLightBrightness 0.025;
                                _lp setLightColor [1, 0.85, 0.6];
                                _lp setLightAmbient [1, 0.3, 0];
                                _lp setLightIntensity _intensity;
                                _lp setLightAttenuation _atten;
                                _lp setLightDayLight true;
                                _lp attachTo [_ship, _off vectorAdd [0, 0, 1], _mem];
                            };
                            _x set [5, [_fire, _smoke, _lp]];
                            _x set [4, 1];
                        };
                    } else {
                        if (_z <= _extH || {_now > _delay + _burnTime}) then {
                            _objs params ["_fire", "_smoke", "_lp"];
                            deleteVehicle _fire;
                            deleteVehicle _lp;
                            _smoke spawn {sleep 8; deleteVehicle _this};  // smoke trails off after the flames go out
                            _x set [4, 2];
                        };
                    };
                };
            } forEach _fires;
            sleep 0.5;
        };

        // Wreck deleted (garbage collector, Zeus): clean up anything still burning
        {
            if ((_x select 4) == 1) then {
                {deleteVehicle _x} forEach (_x select 5);
            };
        } forEach _fires;
    };
};
