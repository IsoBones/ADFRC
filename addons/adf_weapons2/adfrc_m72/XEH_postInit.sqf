// M72A6: non-playable AI get a ready tube (they can't press Reload). See functions\fn_readyForAI.sqf
["CAManBase", "InitPost", {
    params ["_unit"];
    [_unit] call adfrc_m72_fnc_readyForAI;
}, true, [], true] call CBA_fnc_addClassEventHandler;
["CAManBase", "Take", {
    params ["_unit"];
    [_unit] call adfrc_m72_fnc_readyForAI;
}] call CBA_fnc_addClassEventHandler;
