/*
    adfrc_arafura_fnc_boatInit

    Runs on each machine via XEH init on the Arafura. Adds the swimmer
    self-board action, reusing the LCM board system (adfrc_lcm_fnc_board,
    adfrc_lcm_fnc_hullDistance). The landing spot is the "adfrc_board_pos"
    memory point on the mission deck.

    Params (from XEH):
        0: BOAT <OBJECT>

    Returns: nothing
*/
params ["_boat"];

if (!hasInterface) exitWith {};

_boat addAction [
    "<t color='#8cd0ff'>Board OPV</t>",
    {
        params ["_boat", "_caller"];
        [_boat, _caller] call adfrc_lcm_fnc_board;
    },
    nil,
    1.4,
    true,
    true,
    "",
    "
        (vehicle _this == _this) &&
        {isNull (objectParent _this)} &&
        {(getPosASL _this) select 2 < 1} &&
        {([_this, _target] call adfrc_lcm_fnc_hullDistance) < (missionNamespace getVariable ['ADFRC_lcm_boardRange', 8])}
    ",
    50  // engine pre-filter only (measured to model centre); real range check is the condition above
];
