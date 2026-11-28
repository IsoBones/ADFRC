/*
 * Author: ADF Re-Cut
 * Prepare a collapsed M72A6: play the prep gesture + sound, then swap the collapsed tube for the
 * extended launcher with the rocket already loaded. Nothing goes in or comes out of the inventory.
 * Called when the player presses Reload with adfrc_m72a6_collapsed in hand (XEH_postInitClient.sqf).
 *
 * The wait is the prep gesture's length (1 / speed of ADFRC_GestureReloadM72), so a new animation
 * only needs its speed set in config.
 *
 * Arguments:
 * 0: Unit <OBJECT>
 *
 * Return Value:
 * Started <BOOL>
 */
params ["_unit"];

if (!local _unit || {!alive _unit}) exitWith {false};
if (currentWeapon _unit != "adfrc_m72a6_collapsed") exitWith {false};
if (vehicle _unit != _unit) exitWith {false};
if (_unit getVariable ["adfrc_m72_preparing", false]) exitWith {false};

_unit setVariable ["adfrc_m72_preparing", true];
_unit playActionNow "ADFRC_GestureReloadM72";
playSound3D ["A3\Sounds_F\arsenal\weapons\Launchers\RPG32\reload_RPG32.wss", _unit];

private _speed = getNumber (configFile >> "CfgGesturesMale" >> "States" >> "ADFRC_GestureReloadM72" >> "speed");
private _time = [3, 1 / _speed] select (_speed > 0);

[{
    params ["_unit"];
    _unit setVariable ["adfrc_m72_preparing", nil];
    if (!alive _unit || {secondaryWeapon _unit != "adfrc_m72a6_collapsed"}) exitWith {};

    // Same swap CBA does for its loaded launchers: add the launcher empty, then load the rocket into it
    private _selected = currentWeapon _unit == "adfrc_m72a6_collapsed";
    _unit removeWeapon "adfrc_m72a6_collapsed";
    [_unit, "adfrc_m72a6"] call CBA_fnc_addWeaponWithoutItems;
    _unit addWeaponItem ["adfrc_m72a6", "adfrc_m72a6_mag"];
    if (_selected) then {
        _unit selectWeapon "adfrc_m72a6";
    };
}, [_unit], _time] call CBA_fnc_waitAndExecute;

true
