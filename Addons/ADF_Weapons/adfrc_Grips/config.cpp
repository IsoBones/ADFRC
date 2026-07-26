
class CfgPatches
{
 class ADFRC_GRIPS
 {
	requiredaddons[] = {"ADF_Weapons","rhsusf_c_weapons","rhsusf_main"};
	units[] = {};
	weapons[] = {""};
	magazines[] = {""};
	version="0.1";
	author="Brucey";
	skipWhenMissingDependencies = 1;
 };
};
//////////////////////////////////
class UnderBarrelSlot;
class ItemInfo;
class rhsusf_acc_grip1;
class rhsusf_acc_grip2;
class rhsusf_acc_grip3;

class rhs_rifle_gripod_slot: UnderBarrelSlot
{
	class compatibleItems
	{
	////Pic Rail Grips
	ADFRC_Grippod=1;
	
	};
};

class adfrc_MLOK_grip_slot: UnderBarrelSlot
{
	displayName = "Gripod slot";
	linkProxy = "\ADF_Weapons\core\ADFRC_Grip_Proxy_MLOK";
	class compatibleItems
	{
	////M-LOK
	ADFRC_MLOK_MVG_BLK=1;
	ADFRC_MLOK_MVG_FDE=1;
	ADFRC_MLOK_AFG_BLK=1;
	ADFRC_MLOK_AFG_FDE=1;
	
	};
};

class adfrc_PIC_grip_slot: UnderBarrelSlot
{
	displayName = "Gripod slot";
	linkProxy = "\ADF_Weapons\core\ADFRC_Grip_Proxy_Pic";
	class compatibleItems
	{
		rhsusf_acc_grip1=1;
        rhsusf_acc_grip2=1;
        rhsusf_acc_grip2_tan=1;
        rhsusf_acc_grip3=1;
        rhsusf_acc_grip3_tan=1;
		rhsusf_acc_rvg_blk=1;
		rhsusf_acc_rvg_de=1;
		rhsusf_acc_tacsac_blk=1;
		rhsusf_acc_tacsac_tan=1;
		rhsusf_acc_tdstubby_blk=1;
		rhsusf_acc_tdstubby_tan=1;
	};
};


class CfgWeapons {
class Rifle_Base_F;
class ADFRC_EF88_Base: Rifle_Base_F
    {
		handAnim[] =
		{
			"OFP2_ManSkeleton",
			"\ADF_Weapons\core\data\anims\EF88_static.rtm"
			//"\A3\Weapons_F_beta\rifles\mk20\data\Anim\mk20.rtm"
		};
};



class ADFRC_MLOK_MVG_BLK: rhsusf_acc_grip3
	{
		scope = 2;
		scopeArsenal = 2;
		author = "Brucey";
		displayName = "Magpul MVG (BLK)";
		descriptionShort = "Magpul MVG";
		model = "\ADF_Weapons\adfrc_Grips\models\ADFRC_MVG_BLK.p3d";
		inertia = -0.1;
		rhs_grip_type = "rhs_grip1_change";
		picture = "\ADF_Weapons\adfrc_Grips\ui\MVG_BLK_CA.paa";
		UiPicture = "\ADF_Weapons\adfrc_Grips\ui\MVG_BLK_CA.paa";
		
		class ItemInfo: ItemInfo {
		mass = 0.875;
		};
	};
	
	class ADFRC_MLOK_MVG_FDE: ADFRC_MLOK_MVG_BLK
	{
		scope = 2;
		scopeArsenal = 2;
		author = "Brucey";
		displayName = "Magpul MVG (FDE)";
		descriptionShort = "Magpul MVG)";
		model = "\ADF_Weapons\adfrc_Grips\models\ADFRC_MVG_FDE.p3d";
		inertia = -0.1;
		rhs_grip_type = "rhs_grip1_change";
		picture = "\ADF_Weapons\adfrc_Grips\ui\MVG_FDE_CA.paa";
		UiPicture = "\ADF_Weapons\adfrc_Grips\ui\MVG_FDE_CA.paa";
	};
	
	
	class ADFRC_MLOK_AFG_BLK: rhsusf_acc_grip2
	{
		scope = 2;
		scopeArsenal = 2;
		author = "Brucey";
		displayName = "Magpul AFG (BLK)";
		descriptionShort = "Magpul AFG";
		model = "\ADF_Weapons\adfrc_Grips\models\ADFRC_AFG_BLK.p3d";
		inertia = -0.1;
		rhs_grip_type = "rhs_grip2_change";
		picture = "\ADF_Weapons\adfrc_Grips\ui\AFG_BLK_CA.paa";
		UiPicture = "\ADF_Weapons\adfrc_Grips\ui\AFG_BLK_CA.paa";
		
		class ItemInfo: ItemInfo {
		mass = 0.75;
		};
	};
	
	class ADFRC_MLOK_AFG_FDE: ADFRC_MLOK_AFG_BLK
	{
		scope = 2;
		scopeArsenal = 2;
		author = "Brucey";
		displayName = "Magpul AFG (FDE)";
		descriptionShort = "Magpul AFG";
		model = "\ADF_Weapons\adfrc_Grips\models\ADFRC_AFG_FDE.p3d";
		inertia = -0.1;
		rhs_grip_type = "rhs_grip2_change";
		picture = "\ADF_Weapons\adfrc_Grips\ui\AFG_FDE_CA.paa";
		UiPicture = "\ADF_Weapons\adfrc_Grips\ui\AFG_FDE_CA.paa";
	};
	
	};
