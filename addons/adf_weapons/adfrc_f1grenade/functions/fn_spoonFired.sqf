/*
 * Author: ADF Re-Cut
 * clientFiredBIS XEH on CAManBase. Pops the spoon off any throwable whose
 * CfgAmmo class sets adfrc_spoonModel. Runs for every shot fired, so the
 * config lookup is cached per ammo class and everything else exits early.
 * ACE advanced throwing re-raises this XEH when the grenade is primed.
 *
 * Arguments: FiredBIS arguments [unit, weapon, muzzle, mode, ammo, magazine, projectile, gunner]
 * Return Value: None
 */

params ["_unit", "", "", "", "_ammo", "", "_projectile"];

private _model = [_ammo] call adfrc_f1grenade_fnc_spoonModel;

if (_model isEqualTo "" || {!hasInterface} || {isNull _projectile}) exitWith {};
if ((AGLToASL positionCameraToWorld [0, 0, 0]) vectorDistance (getPosASL _projectile) > 300) exitWith {};

[_unit, _projectile, _model] call adfrc_f1grenade_fnc_spoonFly;
