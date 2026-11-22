/*
	ADFRC gear dump for tools/gear_icons (step 0).

	Load the mod, open any mission in Eden, press Play (singleplayer), open the debug console,
	paste this whole file in and press LOCAL EXEC. One line per ADFRC gear class is copied to the
	clipboard: paste it into <build folder>\temp\gear_icons\gear_dump.txt.

	Line format: ADFI|class|category|model|hiddenSelections|hiddenSelectionsTextures|picture|parent|displayName
*/
private _prefixes = ["adf", "bma3"];   // CfgPatches name prefixes that count as ours
private _minScope = 2;                 // 2 = arsenal-visible only; 1 also takes hidden items

private _ours = {
	params ["_cfg"];
	private _src = configSourceAddonList _cfg;
	if (_src isEqualTo []) exitWith {false};
	private _a = toLower (_src select 0);
	(_prefixes findIf {(_a find _x) == 0}) >= 0
};

private _out = [];
private _add = {
	params ["_cfg", "_cat", "_model", "_selCfg", "_texCfg"];
	_out pushBack ([
		"ADFI",
		configName _cfg,
		_cat,
		_model,
		getArray (_selCfg >> "hiddenSelections") joinString ";",
		getArray (_texCfg >> "hiddenSelectionsTextures") joinString ";",
		getText (_cfg >> "picture"),
		configName inheritsFrom _cfg,
		getText (_cfg >> "displayName")
	] joinString "|");
};

// headgear, vests, NVGs, uniforms
{
	if ([_x] call _ours) then {
		private _info = _x >> "ItemInfo";
		private _type = getNumber (_info >> "type");
		private _cat = switch (_type) do {
			case 605: {"headgear"};
			case 701: {"vest"};
			case 616: {"nvg"};
			case 801: {"uniform"};
			default {""};
		};
		if (_cat == "uniform") then {
			private _unit = configFile >> "CfgVehicles" >> getText (_info >> "uniformClass");
			[_x, _cat, getText (_unit >> "model"), _unit, _unit] call _add;
		} else {
			if (_cat != "") then {
				private _selCfg = [_x, _info] select (isArray (_info >> "hiddenSelections"));
				[_x, _cat, getText (_info >> "uniformModel"), _selCfg, _x] call _add;
			};
		};
	};
} forEach (format ["getNumber (_x >> 'scope') >= %1", _minScope] configClasses (configFile >> "CfgWeapons"));

// facewear
{
	if ([_x] call _ours) then {
		[_x, "glasses", getText (_x >> "model"), _x, _x] call _add;
	};
} forEach (format ["getNumber (_x >> 'scope') >= %1", _minScope] configClasses (configFile >> "CfgGlasses"));

// backpacks
{
	if ([_x] call _ours) then {
		[_x, "backpack", getText (_x >> "model"), _x, _x] call _add;
	};
} forEach (format ["getNumber (_x >> 'scope') >= %1 && {getNumber (_x >> 'isBackpack') == 1}", _minScope] configClasses (configFile >> "CfgVehicles"));

copyToClipboard (_out joinString endl);
hint format ["Gear dump: %1 classes copied to the clipboard", count _out];
count _out
