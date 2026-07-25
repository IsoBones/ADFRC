class CfgPatches
{
	class ADFRC_Weapons_Tags
	{
		units[]={};
		weapons[]=
		{
		};
		requiredVersion=1;
		requiredAddons[]=
		{
			"ADF_Weapons",
		};
	};
};


#include "CfgMovesBasic.hpp"

class recoil_default;
class Mode_SemiAuto;

class CfgWeapons
{
    class Rifle;
    class Rifle_Base_F: Rifle {
	class Eventhandlers;
	};
};