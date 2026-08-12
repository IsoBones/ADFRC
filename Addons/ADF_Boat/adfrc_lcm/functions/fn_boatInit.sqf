/*
    adfrc_lcm_fnc_boatInit

    Runs on each machine via XEH init on the boat. Adds the "Board Landing
    Craft" scroll action for swimmers/dismounts on foot near the boat.

    Params (from XEH):
        0: BOAT <OBJECT>

    Returns: nothing
*/
params ["_boat"];

if (!hasInterface) exitWith {};

// --- Board landing craft (self-board for swimmers / dismounts on foot) ---
_boat addAction [
    "<t color='#8cd0ff'>Board Landing Craft</t>",
    {
        params ["_boat", "_caller", "_actionId", "_args"];
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
        {_this distance _target < (missionNamespace getVariable ['ADFRC_lcm_boardRange', 8])} &&
        {(getPosASL _this) select 2 < 1}
    ",
    (missionNamespace getVariable ["ADFRC_lcm_boardRange", 8])
];
