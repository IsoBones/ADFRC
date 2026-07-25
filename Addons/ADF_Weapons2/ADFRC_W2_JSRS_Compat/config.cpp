class CfgPatches
{
 class ADFRC_W2_JSRS_Compat
 {
	requiredaddons[] = {"ADF_Weapons2","jsrs2025_config_c"};
	units[] = {};
	weapons[] = {""};
	magazines[] = {""};
	version="1.1";
	author="Brucey";
	skipWhenMissingDependencies = 1;
 };
};
class Mode_SemiAuto;
class Mode_FullAuto;
class CfgWeapons
{
	class Pistol_base_F;
	#include "HK416.hpp"
	#include "HK417.hpp"
	#include "SR25.hpp"
	//EOF
	};