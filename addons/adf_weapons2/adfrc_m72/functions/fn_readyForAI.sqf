/*
 * Author: ADF Re-Cut
 * AI can't press Reload, so non-playable AI carrying a collapsed M72A6 get the CBA loaded launcher
 * instead (CBA then turns it into a ready-to-fire tube). Players and playable/switchable units keep
 * the collapsed tube.
 *
 * Arguments:
 * 0: Unit <OBJECT>
 *
 * Return Value:
 * None
 */
params ["_unit"];

if (!local _unit || {!alive _unit}) exitWith {};
if (secondaryWeapon _unit != "adfrc_m72a6_collapsed") exitWith {};
if (isPlayer _unit || {_unit in (playableUnits + switchableUnits)}) exitWith {};

_unit removeWeapon "adfrc_m72a6_collapsed";
[_unit, "adfrc_m72a6"] call CBA_fnc_addWeaponWithoutItems;
_unit addWeaponItem ["adfrc_m72a6", "adfrc_m72a6_mag"];
