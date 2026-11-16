// CBA mod-wide settings for ADF Re-Cut.
// Uses CBA_fnc_addSetting (safe to call from preInit without cba_settings as a hard dependency).

[
    "ADFRC_plow_clearMines",
    "CHECKBOX",
    ["Mine plow clears mines", "When enabled, lowered mine plows automatically destroy mines they encounter without damaging the vehicle. Plow must be fully deployed."],
    "ADF Re-Cut",
    true
] call CBA_fnc_addSetting;

[
    "ADFRC_plow_digTrenches",
    "CHECKBOX",
    ["Mine plow digs trenches", "When enabled and grad_trenches is loaded, lowered mine plows can dig vehicle trenches by driving forward. No effect without grad_trenches."],
    "ADF Re-Cut",
    true
] call CBA_fnc_addSetting;

[
    "ADFRC_plow_extraMineClasses",
    "EDITBOX",
    ["Additional mine classes", "Comma-separated list of extra mine/explosive classnames the plow should clear, for mines that don't inherit from MineBase or MineGeneric. MineBase and MineGeneric are always cleared. Example: ACE_Explosives_Place,RKG3_Mine."],
    "ADF Re-Cut",
    "ATMine_Range_Ammo,APERSMine_Range_Ammo,SLAMDirectionalMine_Ammo,APERSBoundingMine_Range_Ammo,APERSTripMine_Wire_Ammo,IEDUrbanBig_Remote_Ammo,IEDLandBig_Remote_Ammo,IEDUrbanSmall_Remote_Ammo,IEDLandSmall_Remote_Ammo"
] call CBA_fnc_addSetting;

// ===== LCM-1E tie-down / boarding settings =====

[
    "ADFRC_lcm_tieRange",
    "SLIDER",
    ["LCM tie-down range", "Max distance (m) from the LCM at which a vehicle driver can tie down."],
    "ADF Re-Cut",
    [2, 30, 12, 0],
    true
] call CBA_fnc_addSetting;

[
    "ADFRC_lcm_boardRange",
    "SLIDER",
    ["LCM board range", "Max distance (m) from the LCM at which a swimmer can self-board onto the deck."],
    "ADF Re-Cut",
    [2, 20, 8, 0],
    true
] call CBA_fnc_addSetting;
