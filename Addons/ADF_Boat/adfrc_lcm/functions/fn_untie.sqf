/*
    adfrc_lcm_fnc_untie

    Releases a tied-down vehicle: re-enable simulation, detach, settle it onto
    the surface. Server-authoritative (detach + enableSimulationGlobal must run
    server-side to replicate).

    Params:
        0: VEHICLE <OBJECT>

    Returns: nothing
*/
params ["_vehicle"];

if (!isServer) exitWith {
    [_vehicle] remoteExec ["adfrc_lcm_fnc_untie", 2];
};

if (isNull _vehicle) exitWith {};
if (!(_vehicle getVariable ["adfrc_tiedDown", false])) exitWith {};

// re-enable sim before detaching so physics resumes cleanly
_vehicle enableSimulationGlobal true;

// capture world pos/orientation before detach so it doesn't snap
private _wPos = getPosWorld _vehicle;
private _wDir = vectorDir _vehicle;
private _wUp  = vectorUp _vehicle;

detach _vehicle;

// re-place at the exact spot it was attached (detach can nudge it)
_vehicle setPosWorld _wPos;
_vehicle setVectorDirAndUp [_wDir, _wUp];
_vehicle setVelocity [0,0,0];

_vehicle setVariable ["adfrc_tiedDown", false, true];
_vehicle setVariable ["adfrc_tieBoat", objNull, true];
