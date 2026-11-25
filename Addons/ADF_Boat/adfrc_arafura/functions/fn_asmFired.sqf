/*
    adfrc_arafura_fnc_asmFired

    XEH firedBIS handler on the Arafura. Anti-ship missiles leave the four launch
    canisters in turn: round 1 uses the turret's missileBeg (asm_tube_1), the
    next rounds are moved to asm_tube_2..4 and pointed along that canister.
    Runs only where the projectile is local (the shooter's machine).

    Params (from XEH firedBIS):
        0: VEHICLE <OBJECT>
        1: WEAPON <STRING>
        6: PROJECTILE <OBJECT>

    Returns: nothing
*/
params ["_ship", "_weapon", "", "", "", "", "_projectile"];

if (_weapon != "adfrc_asm_launcher") exitWith {};
if (isNull _projectile || {!local _projectile}) exitWith {};

private _shot = _ship getVariable ["adfrc_arafura_asmShot", 0];
_ship setVariable ["adfrc_arafura_asmShot", _shot + 1];

private _tube = (_shot mod 4) + 1;
if (_tube == 1) exitWith {};

private _beg = _ship modelToWorldVisualWorld (_ship selectionPosition (format ["asm_tube_%1", _tube]));
private _end = _ship modelToWorldVisualWorld (_ship selectionPosition (format ["asm_tube_%1_end", _tube]));
private _dir = vectorNormalized (_beg vectorDiff _end);
private _side = _dir vectorCrossProduct [0, 0, 1];
private _up = if (vectorMagnitude _side < 0.01) then {[0, 1, 0]} else {vectorNormalized (_side vectorCrossProduct _dir)};

_projectile setPosWorld _beg;
_projectile setVectorDirAndUp [_dir, _up];
_projectile setVelocity ((velocity _ship) vectorAdd (_dir vectorMultiply (vectorMagnitude ((velocity _projectile) vectorDiff (velocity _ship)))));
