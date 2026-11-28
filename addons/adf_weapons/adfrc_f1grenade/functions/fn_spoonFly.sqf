/*
 * Author: ADF Re-Cut
 * Spawns a local spoon at the grenade's exact pose (the spoon model shares the
 * grenade's origin) and flies it: flick off the lever, gravity, light drag and
 * tumble about the lever hinge. Bounces off whatever it hits up to twice, then
 * lies flat on the surface and is deleted after 60 seconds.
 *
 * Arguments:
 * 0: Thrower <OBJECT>
 * 1: Grenade projectile <OBJECT>
 * 2: Spoon model path <STRING>
 *
 * Return Value: None
 */

params ["_unit", "_projectile", "_model"];

private _dir = vectorDirVisual _projectile;
private _up = vectorUpVisual _projectile;
private _side = _dir vectorCrossProduct _up;

private _spoon = createSimpleObject [_model, getPosWorldVisual _projectile, true];
_spoon setVectorDirAndUp [_dir, _up];

// Model +z is the spoon side of the grenade and +y the fuse end, so the lever flicks out and up.
private _kick = (vectorNormalized ((_dir vectorMultiply 0.5) vectorAdd _up)) vectorMultiply (2.5 + random 1.5);
private _vel = ((velocity _projectile) vectorMultiply 0.3) vectorAdd _kick vectorAdd (_side vectorMultiply (random 0.6 - 0.3));
private _axis = vectorNormalized (_side vectorAdd [random 0.4 - 0.2, random 0.4 - 0.2, random 0.4 - 0.2]);
private _omega = 20 + random 15;

private _rest = {
    params ["_spoon", "_pos", "_normal"];
    private _yaw = random 360;
    private _flat = [sin _yaw, cos _yaw, 0];
    private _fwd = vectorNormalized (_flat vectorDiff (_normal vectorMultiply (_flat vectorDotProduct _normal)));
    if (_fwd isEqualTo [0, 0, 0]) then {
        _fwd = vectorNormalized ([0, 0, 1] vectorDiff (_normal vectorMultiply (_normal select 2)));
    };
    _spoon setVectorDirAndUp [_fwd, _normal];
    _spoon setPosWorld (_pos vectorAdd (_normal vectorMultiply 0.02));
    [{deleteVehicle _this}, _spoon, 60] call CBA_fnc_waitAndExecute;
};

[{
    params ["_args", "_handle"];
    _args params ["_spoon", "_unit", "_vel", "_axis", "_omega", "_last", "_start", "_bounces", "_rest"];

    if (isNull _spoon) exitWith {
        [_handle] call CBA_fnc_removePerFrameHandler;
    };

    private _now = time;
    private _dt = (_now - _last) min 0.05;
    _args set [5, _now];
    if (_dt <= 0) exitWith {};

    if (_now - _start > 5) exitWith {
        [_handle] call CBA_fnc_removePerFrameHandler;
        deleteVehicle _spoon;
    };

    _vel = (_vel vectorAdd [0, 0, -9.81 * _dt]) vectorMultiply (1 - 0.6 * _dt);
    private _pos = getPosWorld _spoon;
    private _next = _pos vectorAdd (_vel vectorMultiply _dt);

    // lineIntersectsSurfaces ignores the sea surface, so the spoon just sinks.
    if ((_next select 2) < 0 && {surfaceIsWater _next}) exitWith {
        [_handle] call CBA_fnc_removePerFrameHandler;
        deleteVehicle _spoon;
    };

    private _hits = lineIntersectsSurfaces [_pos, _next, _spoon, _unit, true, 1, "GEOM", "FIRE"];

    if (_hits isNotEqualTo []) exitWith {
        (_hits select 0) params ["_hitPos", "_normal"];

        if (vectorMagnitude _vel < 1.5 || {_bounces >= 2}) exitWith {
            [_handle] call CBA_fnc_removePerFrameHandler;
            [_spoon, _hitPos, _normal] call _rest;
        };

        _vel = (_vel vectorDiff (_normal vectorMultiply (2 * (_vel vectorDotProduct _normal)))) vectorMultiply 0.3;
        _args set [2, _vel];
        _args set [4, _omega * 0.5];
        _args set [7, _bounces + 1];
        _spoon setPosWorld (_hitPos vectorAdd (_normal vectorMultiply 0.02));
    };

    _args set [2, _vel];

    private _angle = deg (_omega * _dt);
    private _c = cos _angle;
    private _s = sin _angle;
    private _vDir = vectorDir _spoon;
    private _vUp = vectorUp _spoon;
    _vDir = (_vDir vectorMultiply _c) vectorAdd ((_axis vectorCrossProduct _vDir) vectorMultiply _s) vectorAdd (_axis vectorMultiply ((_axis vectorDotProduct _vDir) * (1 - _c)));
    _vUp = (_vUp vectorMultiply _c) vectorAdd ((_axis vectorCrossProduct _vUp) vectorMultiply _s) vectorAdd (_axis vectorMultiply ((_axis vectorDotProduct _vUp) * (1 - _c)));

    _spoon setPosWorld _next;
    _spoon setVectorDirAndUp [_vDir, _vUp];
}, 0, [_spoon, _unit, _vel, _axis, _omega, time, time, 0, _rest]] call CBA_fnc_addPerFrameHandler;
