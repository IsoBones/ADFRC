class CfgPatches
{
	class adfrc_truckercap
	{
		name = "ADF Re-Cut Trucker Cap";
		author = "$STR_ADF_AUTHOR";
		requiredVersion = 0.1;
		requiredAddons[] = {"A3_Characters_F", "A3_Weapons_F", "ADF_Core"};
		units[] = {"Headgear_adfrc_truckercap_wdl", "Headgear_adfrc_truckercap_amcu", "Headgear_adfrc_truckercap_mmp", "Headgear_adfrc_truckercap_tan", "Headgear_adfrc_truckercap_blk", "Headgear_adfrc_truckercap_grn"};
		weapons[] = {"adfrc_truckercap_wdl", "adfrc_truckercap_amcu", "adfrc_truckercap_mmp", "adfrc_truckercap_tan", "adfrc_truckercap_blk", "adfrc_truckercap_grn"};
	};
};

class CfgWeapons
{
	class ItemCore;
	class HeadgearItem;

	class adfrc_truckercap_base: ItemCore
	{
		scope = 0;
		author = "$STR_ADF_AUTHOR";
		weaponPoolAvailable = 1;
		displayName = "Trucker Cap";
		picture = "\ADF_Gear\adfrc_truckercap\icons\adfrc_truckercap_wdl_ca.paa";
		model = "\ADF_Gear\adfrc_truckercap\adfrc_truckercap.p3d";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\ADF_Gear\adfrc_truckercap\data\adfrc_truckercap_wdl_co.paa"};
		class ItemInfo: HeadgearItem
		{
			mass = 4; // vanilla cap value
			uniformModel = "\ADF_Gear\adfrc_truckercap\adfrc_truckercap.p3d";
			allowedSlots[] = {801, 901, 701, 605}; // uniform, backpack, vest, head (as vanilla H_Cap_red)
			modelSides[] = {6};
			hiddenSelections[] = {"camo"};
		};
	};
	class adfrc_truckercap_wdl: adfrc_truckercap_base
	{
		picture = "\ADF_Gear\adfrc_truckercap\icons\adfrc_truckercap_wdl_ca.paa";
		scope = 2;
		displayName = "Trucker Cap [Woodland]";
		hiddenSelectionsTextures[] = {"\ADF_Gear\adfrc_truckercap\data\adfrc_truckercap_wdl_co.paa"};
	};
	class adfrc_truckercap_amcu: adfrc_truckercap_base
	{
		picture = "\ADF_Gear\adfrc_truckercap\icons\adfrc_truckercap_amcu_ca.paa";
		scope = 2;
		displayName = "Trucker Cap [AMCU]";
		hiddenSelectionsTextures[] = {"\ADF_Gear\adfrc_truckercap\data\adfrc_truckercap_amcu_co.paa"};
	};
	class adfrc_truckercap_mmp: adfrc_truckercap_base
	{
		picture = "\ADF_Gear\adfrc_truckercap\icons\adfrc_truckercap_mmp_ca.paa";
		scope = 2;
		displayName = "Trucker Cap [MMP]";
		hiddenSelectionsTextures[] = {"\ADF_Gear\adfrc_truckercap\data\adfrc_truckercap_mmp_co.paa"};
	};
	class adfrc_truckercap_tan: adfrc_truckercap_base
	{
		picture = "\ADF_Gear\adfrc_truckercap\icons\adfrc_truckercap_tan_ca.paa";
		scope = 2;
		displayName = "Trucker Cap [Tan]";
		hiddenSelectionsTextures[] = {"\ADF_Gear\adfrc_truckercap\data\adfrc_truckercap_tan_co.paa"};
	};
	class adfrc_truckercap_blk: adfrc_truckercap_base
	{
		picture = "\ADF_Gear\adfrc_truckercap\icons\adfrc_truckercap_blk_ca.paa";
		scope = 2;
		displayName = "Trucker Cap [Black]";
		hiddenSelectionsTextures[] = {"\ADF_Gear\adfrc_truckercap\data\adfrc_truckercap_blk_co.paa"};
	};
	class adfrc_truckercap_grn: adfrc_truckercap_base
	{
		picture = "\ADF_Gear\adfrc_truckercap\icons\adfrc_truckercap_grn_ca.paa";
		scope = 2;
		displayName = "Trucker Cap [Green]";
		hiddenSelectionsTextures[] = {"\ADF_Gear\adfrc_truckercap\data\adfrc_truckercap_grn_co.paa"};
	};
	// @variants-weapons (new variants from the Claude Tools GUI go above this line)
};

// Eden/Zeus placeable ground items (vanilla Headgear_H_Cap_red pattern)
class CfgVehicles
{
	class Headgear_Base_F;
	class Headgear_adfrc_truckercap_wdl: Headgear_Base_F
	{
		scope = 2;
		scopeCurator = 2;
		displayName = "Trucker Cap [Woodland]";
		author = "$STR_ADF_AUTHOR";
		editorCategory = "EdCat_Equipment";
		editorSubcategory = "EdSubcat_Hats";
		vehicleClass = "ItemsHeadgear";
		model = "\A3\Weapons_F\DummyCap.p3d";
		class TransportItems
		{
			class adfrc_truckercap_wdl
			{
				name = "adfrc_truckercap_wdl";
				count = 1;
			};
		};
	};
	class Headgear_adfrc_truckercap_amcu: Headgear_Base_F
	{
		scope = 2;
		scopeCurator = 2;
		displayName = "Trucker Cap [AMCU]";
		author = "$STR_ADF_AUTHOR";
		editorCategory = "EdCat_Equipment";
		editorSubcategory = "EdSubcat_Hats";
		vehicleClass = "ItemsHeadgear";
		model = "\A3\Weapons_F\DummyCap.p3d";
		class TransportItems
		{
			class adfrc_truckercap_amcu
			{
				name = "adfrc_truckercap_amcu";
				count = 1;
			};
		};
	};
	class Headgear_adfrc_truckercap_mmp: Headgear_Base_F
	{
		scope = 2;
		scopeCurator = 2;
		displayName = "Trucker Cap [MMP]";
		author = "$STR_ADF_AUTHOR";
		editorCategory = "EdCat_Equipment";
		editorSubcategory = "EdSubcat_Hats";
		vehicleClass = "ItemsHeadgear";
		model = "\A3\Weapons_F\DummyCap.p3d";
		class TransportItems
		{
			class adfrc_truckercap_mmp
			{
				name = "adfrc_truckercap_mmp";
				count = 1;
			};
		};
	};
	class Headgear_adfrc_truckercap_tan: Headgear_Base_F
	{
		scope = 2;
		scopeCurator = 2;
		displayName = "Trucker Cap [Tan]";
		author = "$STR_ADF_AUTHOR";
		editorCategory = "EdCat_Equipment";
		editorSubcategory = "EdSubcat_Hats";
		vehicleClass = "ItemsHeadgear";
		model = "\A3\Weapons_F\DummyCap.p3d";
		class TransportItems
		{
			class adfrc_truckercap_tan
			{
				name = "adfrc_truckercap_tan";
				count = 1;
			};
		};
	};
	class Headgear_adfrc_truckercap_blk: Headgear_Base_F
	{
		scope = 2;
		scopeCurator = 2;
		displayName = "Trucker Cap [Black]";
		author = "$STR_ADF_AUTHOR";
		editorCategory = "EdCat_Equipment";
		editorSubcategory = "EdSubcat_Hats";
		vehicleClass = "ItemsHeadgear";
		model = "\A3\Weapons_F\DummyCap.p3d";
		class TransportItems
		{
			class adfrc_truckercap_blk
			{
				name = "adfrc_truckercap_blk";
				count = 1;
			};
		};
	};
	class Headgear_adfrc_truckercap_grn: Headgear_Base_F
	{
		scope = 2;
		scopeCurator = 2;
		displayName = "Trucker Cap [Green]";
		author = "$STR_ADF_AUTHOR";
		editorCategory = "EdCat_Equipment";
		editorSubcategory = "EdSubcat_Hats";
		vehicleClass = "ItemsHeadgear";
		model = "\A3\Weapons_F\DummyCap.p3d";
		class TransportItems
		{
			class adfrc_truckercap_grn
			{
				name = "adfrc_truckercap_grn";
				count = 1;
			};
		};
	};
	// @variants-vehicles (new variants from the Claude Tools GUI go above this line)
};
