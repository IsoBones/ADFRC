/*
    adfrc_aslav_fnc_mastLock

    Holds the ASLAV-S in place while the camera mast is up, without touching
    the engine. Same approach BI use for the Contact Mini UGV track lock: the
    vehicle is attached, in its current position and orientation, to a game
    logic parked at world origin, so it can't drive off but the engine,
    turrets and mast keep working.

    Called from the Deploy / Retract Camera user actions via
    remoteExecCall [..., 2]. Runs on the server only.

    Lock: attaches straight away.
    Unlock: waits for the mast to finish coming down (cameraelevation_deployed
    has animPeriod 15, scaled by how far up it currently is), then releases.
    Re-deploying during the descent cancels the pending release.

    Params:
        0: ASLAV-S <OBJECT>
        1: true to lock, false to release once the mast is down <BOOL>

    Returns: nothing
*/
params ["_vehicle", "_lock"];

if (!isServer || {isNull _vehicle}) exitWith {};

// mast travel time from config (AnimationSources >> cameraelevation_deployed >> animPeriod)
#define MAST_ANIM_PERIOD 15

// bump the token so any pending release from an earlier retract is ignored
private _token = (_vehicle getVariable ["adfrc_aslav_mastLockToken", 0]) + 1;
_vehicle setVariable ["adfrc_aslav_mastLockToken", _token];

if (_lock) exitWith {
    if (!isNull (_vehicle getVariable ["adfrc_aslav_mastAnchor", objNull])) exitWith {};

    // game logic anchor parked at world origin; attachToRelative keeps the vehicle exactly where it is
    private _group = createGroup [sideLogic, true];
    private _anchor = _group createUnit ["Logic", [0, 0, 0], [], 0, "CAN_COLLIDE"];

    _vehicle setVelocity [0, 0, 0];
    [_vehicle, _anchor, false] call BIS_fnc_attachToRelative;
    _vehicle setVariable ["adfrc_aslav_mastAnchor", _anchor, true];

    // don't leave the anchor behind if the vehicle is deleted while locked
    if (isNil {_vehicle getVariable "adfrc_aslav_mastDeletedEH"}) then {
        _vehicle setVariable ["adfrc_aslav_mastDeletedEH", _vehicle addEventHandler ["Deleted", {
            params ["_entity"];
            deleteVehicle (_entity getVariable ["adfrc_aslav_mastAnchor", objNull]);
        }]];
    };
};

private _delay = MAST_ANIM_PERIOD * (_vehicle animationSourcePhase "cameraelevation_deployed");

[_vehicle, _token, _delay] spawn {
    params ["_vehicle", "_token", "_delay"];
    sleep (_delay + 0.5);

    if (isNull _vehicle) exitWith {};
    if ((_vehicle getVariable ["adfrc_aslav_mastLockToken", 0]) != _token) exitWith {};

    private _anchor = _vehicle getVariable ["adfrc_aslav_mastAnchor", objNull];
    detach _vehicle;
    deleteVehicle _anchor;
    _vehicle setVariable ["adfrc_aslav_mastAnchor", nil, true];
};
