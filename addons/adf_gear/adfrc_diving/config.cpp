class CfgPatches
{
	class adfrc_divekit
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1;
		requiredAddons[] = {"ADF_Core", "Extended_Eventhandlers"};
	};
};
class cfgWeapons
{
	class ItemCore;
	class InventoryItem_Base_F;
	class VestItem;
	class Uniform_Base;
	class UniformItem;
	class HeadgearItem;
	class V_RebreatherB;
	class U_B_survival_uniform;
	class adfrc_rebreather: V_RebreatherB
	{
		scope = 2;
		scopeCurator = 2;
		scopeArsenal = 2;
		displayName = "Dive Rebreather";
		allowedSlots[] = {901};
		picture = "";
		model = "ADF_Gear\adfrc_diving\rebreather.p3d";
		hiddenUnderwaterSelections[] = {"Camo2","Camo3"};
		shownUnderwaterSelections[] = {"Camo1"};
		hiddenUnderwaterSelectionsTextures[] = {"ADF_Gear\adfrc_diving\data\dive_1_co.paa","ADF_Gear\adfrc_diving\data\sp_hero_ghost_udt_divegear_co.paa","ADF_Gear\adfrc_diving\data\dive_1_co.paa"};
		class ItemInfo: VestItem
		{
			uniformModel = "ADF_Gear\adfrc_diving\rebreather.p3d";
			vestType = "Rebreather";
			hiddenUnderwaterSelections[] = {"Camo2","Camo3"};
			shownUnderwaterSelections[] = {"Camo1"};
			hiddenUnderwaterSelectionsTextures[] = {"ADF_Gear\adfrc_diving\data\dive_1_co.paa","ADF_Gear\adfrc_diving\data\sp_hero_ghost_udt_divegear_co.paa","ADF_Gear\adfrc_diving\data\dive_1_co.paa"};
			picture = "";
			containerClass = "Supply0";
			mass = 95;
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 100;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 100;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 100;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class adfrc_drysuit_gry: U_B_survival_uniform
	{
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		displayName = "Drysuit [Grey]";
		picture = "";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";
		hiddenSelections[] = {"Camo2"};
		hiddenSelectionsTextures[] = {"ADF_Gear\adfrc_diving\data\drysuit_mas_co.paa"};
		hiddenUnderwaterSelections[] = {"Hide"};
		shownUnderwaterSelections[] = {"Camo1"};
		hiddenUnderwaterSelectionsTextures[] = {"ADF_Gear\adfrc_diving\data\sp_hero_ghost_udt_divegear_co.paa"};
		class ItemInfo: UniformItem
		{
			uniformModel = "-";
			uniformType = "Neopren";
			modelSides[] = {0,1,2,3};
			uniformClass = "adfrc_drysuit_gry";
			containerClass = "Supply80";
			mass = 30;
			allowedSlots[] = {"701","801","901"};
			armor = 0;
		};
	};
	class adfrc_drysuit_blk: U_B_survival_uniform
	{
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;
		displayName = "Drysuit [Black]";
		picture = "";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";
		hiddenSelections[] = {"Camo2"};
		hiddenSelectionsTextures[] = {"ADF_Gear\adfrc_diving\data\sp_hero_ghost_udt_rubber_drysuitv2_co.paa"};
		hiddenUnderwaterSelections[] = {"Hide"};
		shownUnderwaterSelections[] = {"Camo1"};
		hiddenUnderwaterSelectionsTextures[] = {"ADF_Gear\adfrc_diving\data\sp_hero_ghost_udt_divegear_co.paa"};
		class ItemInfo: UniformItem
		{
			uniformModel = "-";
			uniformType = "Neopren";
			modelSides[] = {0,1,2,3};
			uniformClass = "adfrc_drysuit_blk";
			containerClass = "Supply80";
			mass = 30;
			allowedSlots[] = {"701","801","901"};
			armor = 0;
		};
	};
};
class CfgVehicles
{
	class b_soldier_survival_F;
	class adfrc_drysuit_gry: b_soldier_survival_F
	{
		scope = 1;
		dlc = "";
		modelSides[] = {0,1,2,3};
		displayName = "Drysuit [Grey]";
		model = "ADF_Gear\adfrc_diving\drysuit.p3d";
		hiddenSelections[] = {"Camo2"};
		hiddenSelectionsTextures[] = {"ADF_Gear\adfrc_diving\data\drysuit_mas_co.paa"};
		hiddenUnderwaterSelections[] = {"hide"};
		shownUnderwaterSelections[] = {"unhide"};
		hiddenUnderwaterSelectionsTextures[] = {"ADF_Gear\adfrc_diving\data\sp_hero_ghost_udt_divegear_co.paa","ADF_Gear\adfrc_diving\data\sp_hero_ghost_udt_divegear_co.paa"};
	};
	class adfrc_drysuit_blk: b_soldier_survival_F
	{
		scope = 1;
		dlc = "";
		modelSides[] = {0,1,2,3};
		displayName = "Drysuit [Black]";
		model = "ADF_Gear\adfrc_diving\drysuit.p3d";
		hiddenSelections[] = {"Camo2"};
		hiddenSelectionsTextures[] = {"ADF_Gear\adfrc_diving\data\sp_hero_ghost_udt_rubber_drysuitv2_co.paa"};
		hiddenUnderwaterSelections[] = {"hide"};
		shownUnderwaterSelections[] = {"unhide"};
		hiddenUnderwaterSelectionsTextures[] = {"ADF_Gear\adfrc_diving\data\sp_hero_ghost_udt_divegear_co.paa","ADF_Gear\adfrc_diving\data\sp_hero_ghost_udt_divegear_co.paa"};
	};
};
class CfgGlasses
{
	class None;
	class G_Diving;
	class adfrc_dive_ggl: G_Diving
	{
		displayname = "Diving Goggles";
		model = "ADF_Gear\adfrc_diving\diving_goggles.p3d";
		picture = "";
		hiddenSelections[] = {""};
		hiddenSelectionsTextures[] = {""};
		mass = 4;
	};
};
