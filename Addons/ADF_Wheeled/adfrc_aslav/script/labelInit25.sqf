params ["_veh"];
if (!local _veh) exitWith {};

_markingSet = _veh getVariable ["PlatoonMarkings", 0];
if !(_markingSet isEqualTo 0) exitWith {}; // explicit callsign chosen, leave it

uiSleep 0.5; // let bis_fnc_initVehicle finish before we set the label

private _idx = floor (random 16) + 1;
private _file = if (_idx < 10) then {
    format ["\ADF_Wheeled\adfrc_aslav\data\labels\labels_0%1.paa", _idx]
} else {
    format ["\ADF_Wheeled\adfrc_aslav\data\labels\labels_%1.paa", _idx]
};
_veh setObjectTextureGlobal [7, _file];