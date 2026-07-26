
class CfgPatches
{
 class Adfrc_Tier1_Compat
 {
	requiredaddons[] = {"adfrc_GRIPS","rhsusf_c_weapons","Tier1_Weapons_cfg"};
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
	////M-LOK
		Tier1_MVG_MLOK_Black = 1;
		Tier1_MVG_MLOK_FDE = 1;
		Tier1_AFG_MLOK_Black = 1;
		Tier1_AFG_MLOK_FDE = 1;
		Tier1_DD_MLOK_VFG_Black = 1;
		Tier1_DD_MLOK_VFG_FDE = 1;
		Tier1_RVG_MLOK_Black = 1;
		Tier1_RVG_MLOK_FDE = 1;
		Tier1_BCM_Gunfighter_VG_Black = 1;
		Tier1_BCM_Gunfighter_VG_FDE = 1;
		Tier1_DD_VFG_MLOK_DE = 1;
		Tier1_KAC_VFG_MLOK_DE = 1;
		Tier1_GripPod_MLOK_Tan = 1;
		Tier1_GripPod_MLOK_Black = 1;
	};
};