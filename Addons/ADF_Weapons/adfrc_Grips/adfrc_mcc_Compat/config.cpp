
class CfgPatches
{
 class Adfrc_Tier1_Compat
 {
	requiredaddons[] = {"adfrc_GRIPS","rhsusf_c_weapons","MCC_Core"};
	units[] = {};
	weapons[] = {""};
	magazines[] = {""};
	version="0.5";
	author="Brucey";
	skipWhenMissingDependencies = 1;
 };
};
//////////////////////////////////


class UnderBarrelSlot;
class rhsusf_acc_grip1;
class rhsusf_acc_grip2;
class rhsusf_acc_grip3;

class rhs_rifle_gripod_slot: UnderBarrelSlot
{
	class compatibleItems
	{
	////Pic Rail Grips
	};
};

class adfrc_MLOK_grip_slot: UnderBarrelSlot
{
	displayName = "Gripod slot";
	linkProxy = "\ADF_Weapons\core\ADFRC_Grip_Proxy_MLOK";
	class compatibleItems
	{
	#include "\MCC\MCC_Core\MCC_Grips\Griplist.hpp"
	};
};