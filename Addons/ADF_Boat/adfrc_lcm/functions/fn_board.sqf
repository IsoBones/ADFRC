/*
    adfrc_lcm_fnc_board

    Self-board: a swimmer places themselves onto the LCM deck. Runs on the
    swimmer's own machine (they are local to themselves), so the position
    write lands on the sim owner with no locality routing needed.

    Placement target priority:
        1. boat memory point "adfrc_board_pos" (add to p3d when convenient)
        2. fallback: deck-relative model offset adfrc_lcm_boardOffset

    The unit is placed slightly above the deck and allowed to settle, which
    avoids the swim->stand transition flinging them at boat speed.

    Params:
        0: BOAT <OBJECT>
        1: UNIT <OBJECT> - the boarding swimmer (should be the local player)

    Returns: nothing
*/
params ["_boat", "_unit"];

if (isNull _boat || isNull _unit) exitWith {};
if (!local _unit) exitWith {
    [_boat, _unit] remoteExec ["adfrc_lcm_fnc_board", _unit];
};

// must actually be in/near water and on foot
if (!isNull objectParent _unit) exitWith {};
if (vehicle _unit != _unit) exitWith {};

private _range = missionNamespace getVariable ["ADFRC_lcm_boardRange", 8];
if (_unit distance _boat > _range) exitWith {};

// resolve deck target
private _memPos = _boat selectionPosition "adfrc_board_pos";
private _targetModel = if (_memPos isEqualTo [0,0,0]) then {
    // fallback offset: x=right, y=fwd, z=up, relative to boat model origin
    missionNamespace getVariable ["adfrc_lcm_boardOffset", [0, -2, 0.6]]
} else {
    _memPos
};

private _targetWorld = _boat modelToWorldVisual _targetModel;
// lift slightly so they settle onto the deck instead of clipping through
_targetWorld set [2, (_targetWorld select 2) + 0.4];

// brief swim->stand settle to avoid fling at speed
[_unit, _targetWorld, _boat] spawn {
    params ["_unit", "_pos", "_boat"];
    _unit setPosWorld _pos;
    _unit setVectorDirAndUp [_boat vectorModelToWorld [0,1,0], _boat vectorModelToWorld [0,0,1]];
    _unit setVelocity [0,0,0];
    // settle frame: re-seat once after the engine processes the move
    uiSleep 0.05;
    if (alive _unit && {!isNull _boat}) then {
        _unit setVelocity (velocity _boat);
    };
};
