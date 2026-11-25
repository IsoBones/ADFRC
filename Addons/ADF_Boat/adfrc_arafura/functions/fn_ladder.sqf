/*
    adfrc_arafura_fnc_ladder

    "Climb ladder" for the Arafura. Vehicles don't support real ladders,
    so the unit is moved to the memory point at the other end of the ladder
    and dropped onto the deck under it (same deck ray-cast as the LCM board).

    Runs on the caller's machine; the unit is local to them.

    Params:
        0: SHIP   <OBJECT>
        1: UNIT   <OBJECT>
        2: TARGET <STRING> memory point at the other end of the ladder

    Returns: nothing
*/
params [["_ship", objNull, [objNull]], ["_unit", objNull, [objNull]], ["_point", "", [""]]];

if (isNull _ship || isNull _unit || !local _unit) exitWith {};
if (!isNull objectParent _unit) exitWith {};

private _m = _ship selectionPosition [_point, "Memory"];
if (_m isEqualTo [0, 0, 0]) exitWith {};

// deck surface under the target point
private _from = _ship modelToWorldVisualWorld [_m select 0, _m select 1, (_m select 2) + 1.5];
private _to   = _ship modelToWorldVisualWorld [_m select 0, _m select 1, (_m select 2) - 3];
private _hits = lineIntersectsSurfaces [_from, _to, _unit, objNull, true, -1, "GEOM", "VIEW", false];
private _deck = _hits findIf {(_x select 2) == _ship || {(_x select 3) == _ship}};

private _targetASL = if (_deck >= 0) then {
    ((_hits select _deck) select 0) vectorAdd [0, 0, 0.05]
} else {
    (_ship modelToWorldVisualWorld _m) vectorAdd [0, 0, 0.1]
};

[_unit, _targetASL, _ship] spawn {
    params ["_unit", "_pos", "_ship"];
    _unit setPosASL _pos;
    _unit setVelocity [0, 0, 0];
    uiSleep 0.05;
    if (alive _unit && {!isNull _ship}) then { _unit setVelocity (velocity _ship); };
};
