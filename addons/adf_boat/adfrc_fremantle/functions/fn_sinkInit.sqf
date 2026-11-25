/*
    adfrc_fremantle_fnc_sinkInit

    Runs on every machine via XEH init (Fremantle and Arafura). Adds the MPKilled
    handler that plays the death sequence (adfrc_fremantle_fnc_sinkFx).

    MPKilled triggers once on every connected machine even if it is added on all
    of them (BIKI safeguard), so adding it from XEH init everywhere is safe.
    CBA XEH has no MPKilled event, hence the scripted handler.

    Params (from XEH):
        0: SHIP <OBJECT>

    Returns: nothing
*/
params ["_ship"];

if (_ship getVariable ["adfrc_sinkFx_eh", -1] >= 0) exitWith {};

private _id = _ship addMPEventHandler ["MPKilled", {
    _this call adfrc_fremantle_fnc_sinkFx;
}];
_ship setVariable ["adfrc_sinkFx_eh", _id];
