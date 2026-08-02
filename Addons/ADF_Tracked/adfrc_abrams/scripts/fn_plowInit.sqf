// Plow control with grad_trenches soft dependency.
// Two-depth system: clearance (mines only) and digging (mines + trenches).
// Both states use full plow animation; the grad trench dig-in emulates depth.
// Gated by CBA settings: ADFRC_plow_clearMines, ADFRC_plow_digTrenches,
// and ADFRC_plow_extraMineClasses.
// Plow state stored in adfrc_plowState: 0 = raised, 1 = clearance, 2 = digging.

params ["_vehicle"];

if (_vehicle getVariable ["adfrc_plowInitDone", false]) exitWith {};
_vehicle setVariable ["adfrc_plowInitDone", true];
_vehicle setVariable ["adfrc_plowState", 0, true];

// =====================================================================
// SERVER: mine clearing whenever plow is lowered (clearance or digging)
// =====================================================================
if (isServer) then {
    [{
        params ["_args", "_handle"];
        _args params ["_vehicle"];

        if (isNull _vehicle || !alive _vehicle) exitWith {
            [_handle] call CBA_fnc_removePerFrameHandler;
        };

        if !(missionNamespace getVariable ["ADFRC_plow_clearMines", true]) exitWith {};

        // State 1 (clearance) or 2 (digging) both clear mines
        if ((_vehicle getVariable ["adfrc_plowState", 0]) < 1) exitWith {};

        // Build the class filter: always MineBase + MineGeneric, plus any user-listed extras.
        // Cache the parsed result, only re-parse when the setting string changes.
        private _raw = missionNamespace getVariable ["ADFRC_plow_extraMineClasses", ""];
        private _classes = missionNamespace getVariable ["ADFRC_plow_mineClassCache", []];
        private _cachedRaw = missionNamespace getVariable ["ADFRC_plow_mineClassCacheRaw", "\n"];

        if !(_raw isEqualTo _cachedRaw) then {
            _classes = ["MineBase", "MineGeneric"];
            {
                private _trimmed = _x splitString " " joinString "";  // strip all spaces
                if (_trimmed != "") then { _classes pushBackUnique _trimmed };
            } forEach (_raw splitString ",");
            missionNamespace setVariable ["ADFRC_plow_mineClassCache", _classes];
            missionNamespace setVariable ["ADFRC_plow_mineClassCacheRaw", _raw];
        };

        private _searchPos = _vehicle modelToWorld [0, 6, 0];
        private _mines = nearestObjects [_searchPos, _classes, 4];
        { deleteVehicle _x; } forEach _mines;

    }, 0.1, [_vehicle]] call CBA_fnc_addPerFrameHandler;
};

if (!hasInterface) exitWith {};

// =====================================================================
// CLIENTS: state-aware plow actions
// =====================================================================
[{
    params ["_vehicle"];

    // Strip grad_trenches' default actions
    for "_i" from 50 to 0 step -1 do {
        private _params = _vehicle actionParams _i;
        if (count _params > 0 && {(_params select 0) in ["Lower Plow", "Raise Plow"]}) then {
            _vehicle removeAction _i;
        };
    };

    // Shared driver/engine/plow-fitted gate
    private _baseCond = "alive _target && {isEngineOn _target} && {(_target animationSourcePhase 'hideplow') == 1} && {_this == driver _target}";

    // Helper: applies a target state to the vehicle. Handles animation,
    // cruise control, and grad_trenches sync in one place.
    // State 0 = raised, 1 = clearance, 2 = digging.
    if (isNil "ADFRC_fnc_setPlowState") then {
        ADFRC_fnc_setPlowState = {
            params ["_target", "_state"];

            _target setVariable ["adfrc_plowState", _state, true];

            if (_state > 0) then {
                _target animateDoor ["plow", 1];
                _target setCruiseControl [7, false];
            } else {
                _target animateDoor ["plow", 0];
                _target setCruiseControl [0, false];
            };

            // grad_trenches digging only at state 2, and only if loaded + enabled
            private _gradActive = (missionNamespace getVariable ["ADFRC_plow_digTrenches", true])
                && {isClass (configFile >> "CfgPatches" >> "grad_trenches_functions")};

            if (_gradActive) then {
                if (_state == 2) then {
                    // Mark animating, then flag digging once plow reaches full depth
                    _target setVariable ["grad_trenches_functions_plowlowered", -1, true];
                    [
                        { (_this animationPhase "plow") >= 0.99 },
                        { _this setVariable ["grad_trenches_functions_plowlowered", 1, true] },
                        _target
                    ] call CBA_fnc_waitUntilAndExecute;
                } else {
                    // Raised or clearance: ensure trench builder is off
                    _target setVariable ["grad_trenches_functions_plowlowered", 0, true];
                };
            };
        };
    };

    // ---- Lower to clearance depth (from raised) ----
    _vehicle addAction [
        "Lower plow to clearance depth",
        { [_this select 0, 1] call ADFRC_fnc_setPlowState; },
        nil, 1.6, true, true, "",
        format ["%1 && {(_target getVariable ['adfrc_plowState', 0]) == 0}", _baseCond],
        10, false, "", ""
    ];

    // ---- Lower to digging depth (from raised or clearance) ----
    _vehicle addAction [
        "Lower plow to digging depth",
        { [_this select 0, 2] call ADFRC_fnc_setPlowState; },
        nil, 1.5, true, true, "",
        format ["%1 && {(_target getVariable ['adfrc_plowState', 0]) in [0, 1]}", _baseCond],
        10, false, "", ""
    ];

    // ---- Raise to clearance depth (from digging) ----
    _vehicle addAction [
        "Raise plow to clearance depth",
        { [_this select 0, 1] call ADFRC_fnc_setPlowState; },
        nil, 1.6, true, true, "",
        format ["%1 && {(_target getVariable ['adfrc_plowState', 0]) == 2}", _baseCond],
        10, false, "", ""
    ];

    // ---- Raise plow fully (from clearance or digging) ----
    _vehicle addAction [
        "Raise plow",
        { [_this select 0, 0] call ADFRC_fnc_setPlowState; },
        nil, 1.5, true, true, "",
        format ["%1 && {(_target getVariable ['adfrc_plowState', 0]) in [1, 2]}", _baseCond],
        10, false, "", ""
    ];

}, [_vehicle], 0.25] call CBA_fnc_waitAndExecute;