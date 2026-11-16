/*
    adfrc_lcm_fnc_nearestLCM

    Returns the nearest LCM within tie-down range of the given vehicle, or
    objNull if none. Used by the vehicle-side action condition and statement.

    Params:
        0: VEHICLE <OBJECT>

    Returns: <OBJECT> nearest LCM in range, or objNull
*/
params ["_veh"];

if (isNull _veh) exitWith {objNull};

private _range = missionNamespace getVariable ["ADFRC_lcm_tieRange", 12];
private _boats = nearestObjects [_veh, ["adfrc_lcm_base"], _range];

if (_boats isEqualTo []) exitWith {objNull};
_boats select 0;
