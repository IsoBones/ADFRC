/*
 * Author: ADF Re-Cut
 * Returns the spoon model for an ammo class (CfgAmmo adfrc_spoonModel), cached per class.
 *
 * Arguments:
 * 0: Ammo class <STRING>
 *
 * Return Value: Spoon model path, "" if the ammo has no spoon <STRING>
 */

params ["_ammo"];

if (isNil "adfrc_f1grenade_spoonModels") then {
    adfrc_f1grenade_spoonModels = createHashMap;
};

adfrc_f1grenade_spoonModels getOrDefaultCall [_ammo, {
    getText (configFile >> "CfgAmmo" >> _ammo >> "adfrc_spoonModel")
}, true]
