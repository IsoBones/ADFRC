// M72A6: Reload (R) with the collapsed tube in hand prepares it. See functions\fn_prepare.sqf
addUserActionEventHandler ["ReloadMagazine", "Activate", {
    private _unit = call CBA_fnc_currentUnit;
    if (currentWeapon _unit == "adfrc_m72a6_collapsed") then {
        [_unit] call adfrc_m72_fnc_prepare;
    };
}];
