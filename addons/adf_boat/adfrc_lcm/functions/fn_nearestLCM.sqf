/*
    adfrc_lcm_fnc_nearestLCM

    Returns the nearest LCM within tie-down range of the given vehicle, or
    objNull if none. Range is measured to the hull edge (fn_hullDistance), not
    the model centre. Used by the vehicle-side action condition and statement.

    Params:
        0: VEHICLE <OBJECT>

    Returns: <OBJECT> nearest LCM in range, or objNull
*/
params ["_veh"];

if (isNull _veh) exitWith {objNull};

private _range = missionNamespace getVariable ["ADFRC_lcm_tieRange", 12];
// search wide enough to reach the centre of a long hull, then filter by edge distance
private _best = objNull;
private _bestDist = _range;
{
    private _d = [_veh, _x] call adfrc_lcm_fnc_hullDistance;
    if (_d <= _bestDist) then { _best = _x; _bestDist = _d; };
} forEach (nearestObjects [_veh, ["adfrc_lcm_base"], _range + 30]);

_best
