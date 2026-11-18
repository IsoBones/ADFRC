#define _ARMA_

class CfgPatches
{
	class adfrc_vests
	{
		name = "adfrc_vests";
		author = "$STR_ADF_AUTHOR";
		requiredAddons[] = {"A3_Data_F_AoW_Loadorder","A3_Data_F_Mod_Loadorder","ADF_Core"};
		units[] = {};
		weapons[] = {"ADFRC_carrierLite_dpcu","ADFRC_plateCarrier_dpcu","ADFRC_tacticalVest_dpcu","ADFRC_carrierlite_dpdu","ADFRC_tacticalvest_dpdu","ADFRC_TBAS_T2_Medic","ADFRC_TBAS_T2_TL","ADFRC_TBAS_T2_LMG","ADFRC_TBAS_T2_Rifleman_Pistol","ADFRC_TBAS_T2_DMR","ADFRC_TBAS_T2_Eng","ADFRC_TBAS_T2_Gren","ADFRC_TBAS_T2_Scout","ADFRC_TBAS_T2_Rifleman","ADFRC_TBAS_T2_Rifleman_Light","ADFRC_TBAS_T2_Officer","ADFRC_TBAS_T2_SECO","ADFRC_TBAS_T5_CFA","ADFRC_TBAS_T5_TL","ADFRC_TBAS_T5_LMG","ADFRC_TBAS_T5_DMR","ADFRC_TBAS_T5_Eng","ADFRC_TBAS_T5_Gren","ADFRC_TBAS_T5_Breacher","ADFRC_TBAS_T5_Operator","ADFRC_TBAS_T5_Commando_CQB","ADFRC_TBAS_T5_PatrolCom","ADFRC_TBAS_T5_TAG","ADFRC_TBAS_T5_TAG_TL","ADFRC_TBAS_T5_TAG_CFA","ADFRC_TBAS_T5_TAG_Breacher","ADFRC_JPC_CFA","ADFRC_JPC_TL","ADFRC_JPC_LMG","ADFRC_JPC_DMR","ADFRC_JPC_Eng","ADFRC_JPC_Gren","ADFRC_JPC_Breacher","ADFRC_JPC_Operator","ADFRC_JPC_Commando_CQB","ADFRC_JPC_PatrolCom","ADFRC_JPC_TAG","ADFRC_JPC_TAG_TL","ADFRC_JPC_TAG_CFA","ADFRC_JPC_TAG_Breacher","ADFRC_PilotVest","ADFRC_Peacekeeper_Mk5_MC","ADFRC_Peacekeeper_Mk5_Tan","ADFRC_Peacekeeper_Mk5_AMCU","ADFRC_Peacekeeper_Mk5_MC_NoFlaps","ADFRC_Peacekeeper_Mk5_Tan_NoFlaps"};
	};
};
class CfgVehicles
{
	class ReammoBox;
	class Man;
	class ContainerSupply;
	class B_Soldier_F;
	class B_diver_F;
};
class cfgWeapons
{
	class ItemCore;
	class VestItem;
	class V_PlateCarrier1_blk;
	class V_PlateCarrierH_CTRG;
	class V_TacVest_blk;
	class V_PlateCarrierGL_rgr;
	class Vest_Camo_Base;
	class ADFRC_carrierLite_dpcu: V_PlateCarrier1_blk
	{
		scope = 2;
		author = "$STR_ADF_AUTHOR";
		displayName = "ADF Carrier-Lite [DPCU]";
		model = "\A3\Characters_F_EPA\BLUFOR\equip_b_vest_kerry";
		picture = "\ADF_Gear_2\adfrc_vests\data\icons\icon_DPCU_Vest_ca.paa";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\ADF_Gear_2\adfrc_vests\data\adfrc_carrierLite_dpcu.paa"};
	};
	class ADFRC_plateCarrier_dpcu: V_PlateCarrierH_CTRG
	{
		scope = 2;
		author = "$STR_ADF_AUTHOR";
		displayName = "ADF Carrier Rig [DPCU]";
		picture = "\ADF_Gear_2\adfrc_vests\data\icons\icon_DPCU_Vest_ca.paa";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\ADF_Gear_2\adfrc_vests\data\adfrc_carrierLite_dpcu.paa"};
	};
	class ADFRC_tacticalVest_dpcu: V_TacVest_blk
	{
		scope = 2;
		author = "$STR_ADF_AUTHOR";
		displayName = "ADF Tactical Vest [DPCU]";
		picture = "\ADF_Gear_2\adfrc_vests\data\icons\icon_DPCU_Vest_ca.paa";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\ADF_Gear_2\adfrc_vests\data\tacticalVest_DPCU_co.paa"};
	};
	class ADFRC_carrierlite_dpdu: V_PlateCarrier1_blk
	{
		scope = 2;
		author = "$STR_ADF_AUTHOR";
		displayName = "ADF Carrier-Lite [DPDU]";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\ADF_Gear_2\adfrc_vests\data\adfrc_carrierLite_dpdu.paa"};
	};
	class ADFRC_tacticalvest_dpdu: V_TacVest_blk
	{
		scope = 2;
		author = "$STR_ADF_AUTHOR";
		displayName = "ADF Tactical Vest [DPDU]";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\ADF_Gear_2\adfrc_vests\data\tacticalVest_DPDU_co.paa"};
	};
	class ADFRC_TBAS_T2_Medic: Vest_Camo_Base
	{
		scope = 2;
		author = "Exer";
		weaponPoolAvailable = 1;
		allowedSlots[] = {901};
		displayName = "TBAS T2 - Medic";
		picture = "\ADF_Gear_2\adfrc_vests\data\icons\icon_TBAS_T2_MED_ca.paa";
		model = "\ADF_Gear_2\adfrc_vests\TBAS_T2\tbas_T2_Medic.p3d";
		hiddenSelections[] = {};
		hiddenSelectionsTextures[] = {};
		class ItemInfo: VestItem
		{
			uniformModel = "\ADF_Gear_2\adfrc_vests\TBAS_T2\tbas_T2_Medic.p3d";
			containerClass = "Supply180";
			mass = 60;
			hiddenSelections[] = {};
			hiddenSelectionsTextures[] = {};
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 24;
					PassThrough = 0.1;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 24;
					PassThrough = 0.1;
				};
				class Abdomen
				{
					HitpointName = "HitAbdomen";
					armor = 24;
					PassThrough = 0.1;
				};
				class Body
				{
					hitpointName = "HitBody";
					PassThrough = 0.1;
				};
			};
		};
	};
	class ADFRC_TBAS_T2_TL: Vest_Camo_Base
	{
		scope = 2;
		author = "Exer";
		weaponPoolAvailable = 1;
		allowedSlots[] = {901};
		displayName = "TBAS T2 - Team Leader";
		picture = "\ADF_Gear_2\adfrc_vests\data\icons\icon_TBAS_T2_TL_ca.paa";
		model = "\ADF_Gear_2\adfrc_vests\TBAS_T2\tbas_T2_TL.p3d";
		hiddenSelections[] = {};
		hiddenSelectionsTextures[] = {};
		class ItemInfo: VestItem
		{
			uniformModel = "\ADF_Gear_2\adfrc_vests\TBAS_T2\tbas_T2_TL.p3d";
			containerClass = "Supply180";
			mass = 60;
			hiddenSelections[] = {};
			hiddenSelectionsTextures[] = {};
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 24;
					PassThrough = 0.1;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 24;
					PassThrough = 0.1;
				};
				class Abdomen
				{
					HitpointName = "HitAbdomen";
					armor = 24;
					PassThrough = 0.1;
				};
				class Body
				{
					hitpointName = "HitBody";
					PassThrough = 0.1;
				};
			};
		};
	};
	class ADFRC_TBAS_T2_LMG: Vest_Camo_Base
	{
		scope = 2;
		author = "Exer";
		weaponPoolAvailable = 1;
		allowedSlots[] = {901};
		displayName = "TBAS T2 - Machine Gunner";
		picture = "\ADF_Gear_2\adfrc_vests\data\icons\icon_TBAS_T2_MG_ca.paa";
		model = "\ADF_Gear_2\adfrc_vests\TBAS_T2\tbas_T2_MG.p3d";
		hiddenSelections[] = {};
		hiddenSelectionsTextures[] = {};
		class ItemInfo: VestItem
		{
			uniformModel = "\ADF_Gear_2\adfrc_vests\TBAS_T2\tbas_T2_MG.p3d";
			containerClass = "Supply180";
			mass = 60;
			hiddenSelections[] = {};
			hiddenSelectionsTextures[] = {};
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 24;
					PassThrough = 0.1;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 24;
					PassThrough = 0.1;
				};
				class Abdomen
				{
					HitpointName = "HitAbdomen";
					armor = 24;
					PassThrough = 0.1;
				};
				class Body
				{
					hitpointName = "HitBody";
					PassThrough = 0.1;
				};
			};
		};
	};
	class ADFRC_TBAS_T2_Rifleman_Pistol: Vest_Camo_Base
	{
		scope = 2;
		author = "Exer";
		weaponPoolAvailable = 1;
		allowedSlots[] = {901};
		displayName = "TBAS T2 - Rifleman (Pistol)";
		picture = "\ADF_Gear_2\adfrc_vests\data\icons\adfrc_tbas_t2_rifleman_pistol_ca.paa";
		model = "\ADF_Gear_2\adfrc_vests\TBAS_T2\tbas_T2_Rifleman_Pistol.p3d";
		hiddenSelections[] = {};
		hiddenSelectionsTextures[] = {};
		class ItemInfo: VestItem
		{
			uniformModel = "\ADF_Gear_2\adfrc_vests\TBAS_T2\tbas_T2_Rifleman_Pistol.p3d";
			containerClass = "Supply180";
			mass = 60;
			hiddenSelections[] = {};
			hiddenSelectionsTextures[] = {};
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 24;
					PassThrough = 0.1;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 24;
					PassThrough = 0.1;
				};
				class Abdomen
				{
					HitpointName = "HitAbdomen";
					armor = 24;
					PassThrough = 0.1;
				};
				class Body
				{
					hitpointName = "HitBody";
					PassThrough = 0.1;
				};
			};
		};
	};
	class ADFRC_TBAS_T2_DMR: Vest_Camo_Base
	{
		scope = 2;
		author = "Exer";
		weaponPoolAvailable = 1;
		allowedSlots[] = {901};
		displayName = "TBAS T2 - DMR";
		picture = "\ADF_Gear_2\adfrc_vests\data\icons\icon_TBAS_T2_DMR_ca.paa";
		model = "\ADF_Gear_2\adfrc_vests\TBAS_T2\tbas_T2_DMR.p3d";
		hiddenSelections[] = {};
		hiddenSelectionsTextures[] = {};
		class ItemInfo: VestItem
		{
			uniformModel = "\ADF_Gear_2\adfrc_vests\TBAS_T2\tbas_T2_DMR.p3d";
			containerClass = "Supply180";
			mass = 60;
			hiddenSelections[] = {};
			hiddenSelectionsTextures[] = {};
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 24;
					PassThrough = 0.1;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 24;
					PassThrough = 0.1;
				};
				class Abdomen
				{
					HitpointName = "HitAbdomen";
					armor = 24;
					PassThrough = 0.1;
				};
				class Body
				{
					hitpointName = "HitBody";
					PassThrough = 0.1;
				};
			};
		};
	};
	class ADFRC_TBAS_T2_Eng: Vest_Camo_Base
	{
		scope = 2;
		author = "Exer";
		weaponPoolAvailable = 1;
		allowedSlots[] = {901};
		displayName = "TBAS T2 - Engineer";
		picture = "\ADF_Gear_2\adfrc_vests\data\icons\icon_TBAS_T2_ENG_ca.paa";
		model = "\ADF_Gear_2\adfrc_vests\TBAS_T2\tbas_T2_Engineer.p3d";
		hiddenSelections[] = {};
		hiddenSelectionsTextures[] = {};
		class ItemInfo: VestItem
		{
			uniformModel = "\ADF_Gear_2\adfrc_vests\TBAS_T2\tbas_T2_Engineer.p3d";
			containerClass = "Supply180";
			mass = 60;
			hiddenSelections[] = {};
			hiddenSelectionsTextures[] = {};
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 24;
					PassThrough = 0.1;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 24;
					PassThrough = 0.1;
				};
				class Abdomen
				{
					HitpointName = "HitAbdomen";
					armor = 24;
					PassThrough = 0.1;
				};
				class Body
				{
					hitpointName = "HitBody";
					PassThrough = 0.1;
				};
			};
		};
	};
	class ADFRC_TBAS_T2_Gren: Vest_Camo_Base
	{
		scope = 2;
		author = "Exer";
		weaponPoolAvailable = 1;
		allowedSlots[] = {901};
		displayName = "TBAS T2 - Grenadier";
		picture = "\ADF_Gear_2\adfrc_vests\data\icons\icon_TBAS_T2_GRN_ca.paa";
		model = "\ADF_Gear_2\adfrc_vests\TBAS_T2\tbas_T2_Gren.p3d";
		hiddenSelections[] = {};
		hiddenSelectionsTextures[] = {};
		class ItemInfo: VestItem
		{
			uniformModel = "\ADF_Gear_2\adfrc_vests\TBAS_T2\tbas_T2_Gren.p3d";
			containerClass = "Supply180";
			mass = 60;
			hiddenSelections[] = {};
			hiddenSelectionsTextures[] = {};
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 24;
					PassThrough = 0.1;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 24;
					PassThrough = 0.1;
				};
				class Abdomen
				{
					HitpointName = "HitAbdomen";
					armor = 24;
					PassThrough = 0.1;
				};
				class Body
				{
					hitpointName = "HitBody";
					PassThrough = 0.1;
				};
			};
		};
	};
	class ADFRC_TBAS_T2_Scout: Vest_Camo_Base
	{
		scope = 2;
		author = "Exer";
		weaponPoolAvailable = 1;
		allowedSlots[] = {901};
		displayName = "TBAS T2 - Scout";
		picture = "\ADF_Gear_2\adfrc_vests\data\icons\icon_TBAS_T2_SCT_ca.paa";
		model = "\ADF_Gear_2\adfrc_vests\TBAS_T2\tbas_T2_Scout.p3d";
		hiddenSelections[] = {};
		hiddenSelectionsTextures[] = {};
		class ItemInfo: VestItem
		{
			uniformModel = "\ADF_Gear_2\adfrc_vests\TBAS_T2\tbas_T2_Scout.p3d";
			containerClass = "Supply180";
			mass = 60;
			hiddenSelections[] = {};
			hiddenSelectionsTextures[] = {};
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 24;
					PassThrough = 0.1;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 24;
					PassThrough = 0.1;
				};
				class Abdomen
				{
					HitpointName = "HitAbdomen";
					armor = 24;
					PassThrough = 0.1;
				};
				class Body
				{
					hitpointName = "HitBody";
					PassThrough = 0.1;
				};
			};
		};
	};
	class ADFRC_TBAS_T2_Rifleman: Vest_Camo_Base
	{
		scope = 2;
		author = "Exer";
		weaponPoolAvailable = 1;
		allowedSlots[] = {901};
		displayName = "TBAS T2 - Rifleman";
		picture = "\ADF_Gear_2\adfrc_vests\data\icons\adfrc_tbas_t2_rifleman_ca.paa";
		model = "\ADF_Gear_2\adfrc_vests\TBAS_T2\tbas_T2_Rifleman.p3d";
		hiddenSelections[] = {};
		hiddenSelectionsTextures[] = {};
		class ItemInfo: VestItem
		{
			uniformModel = "\ADF_Gear_2\adfrc_vests\TBAS_T2\tbas_T2_Rifleman.p3d";
			containerClass = "Supply180";
			mass = 60;
			hiddenSelections[] = {};
			hiddenSelectionsTextures[] = {};
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 24;
					PassThrough = 0.1;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 24;
					PassThrough = 0.1;
				};
				class Abdomen
				{
					HitpointName = "HitAbdomen";
					armor = 24;
					PassThrough = 0.1;
				};
				class Body
				{
					hitpointName = "HitBody";
					PassThrough = 0.1;
				};
			};
		};
	};
	class ADFRC_TBAS_T2_Rifleman_Light: Vest_Camo_Base
	{
		scope = 2;
		author = "Exer";
		weaponPoolAvailable = 1;
		allowedSlots[] = {901};
		displayName = "TBAS T2 - Rifleman (Light)";
		picture = "\ADF_Gear_2\adfrc_vests\data\icons\icon_TBAS_T2_RFL_L_ca.paa";
		model = "\ADF_Gear_2\adfrc_vests\TBAS_T2\tbas_T2_Rifleman_Light.p3d";
		hiddenSelections[] = {};
		hiddenSelectionsTextures[] = {};
		class ItemInfo: VestItem
		{
			uniformModel = "\ADF_Gear_2\adfrc_vests\TBAS_T2\tbas_T2_Rifleman_Light.p3d";
			containerClass = "Supply180";
			mass = 60;
			hiddenSelections[] = {};
			hiddenSelectionsTextures[] = {};
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 24;
					PassThrough = 0.1;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 24;
					PassThrough = 0.1;
				};
				class Abdomen
				{
					HitpointName = "HitAbdomen";
					armor = 24;
					PassThrough = 0.1;
				};
				class Body
				{
					hitpointName = "HitBody";
					PassThrough = 0.1;
				};
			};
		};
	};
	class ADFRC_TBAS_T2_Officer: Vest_Camo_Base
	{
		scope = 2;
		author = "Exer";
		weaponPoolAvailable = 1;
		allowedSlots[] = {901};
		displayName = "TBAS T2 - Officer";
		picture = "\ADF_Gear_2\adfrc_vests\data\icons\icon_TBAS_T2_OFR_ca.paa";
		model = "\ADF_Gear_2\adfrc_vests\TBAS_T2\tbas_T2_Officer.p3d";
		hiddenSelections[] = {};
		hiddenSelectionsTextures[] = {};
		class ItemInfo: VestItem
		{
			uniformModel = "\ADF_Gear_2\adfrc_vests\TBAS_T2\tbas_T2_Officer.p3d";
			containerClass = "Supply180";
			mass = 60;
			hiddenSelections[] = {};
			hiddenSelectionsTextures[] = {};
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 24;
					PassThrough = 0.1;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 24;
					PassThrough = 0.1;
				};
				class Abdomen
				{
					HitpointName = "HitAbdomen";
					armor = 24;
					PassThrough = 0.1;
				};
				class Body
				{
					hitpointName = "HitBody";
					PassThrough = 0.1;
				};
			};
		};
	};
	class ADFRC_TBAS_T2_SECO: Vest_Camo_Base
	{
		scope = 2;
		author = "Exer";
		weaponPoolAvailable = 1;
		allowedSlots[] = {901};
		displayName = "TBAS T2 - Section Commander";
		picture = "\ADF_Gear_2\adfrc_vests\data\icons\icon_TBAS_T2_SCO_ca.paa";
		model = "\ADF_Gear_2\adfrc_vests\TBAS_T2\tbas_T2_Seco.p3d";
		hiddenSelections[] = {};
		hiddenSelectionsTextures[] = {};
		class ItemInfo: VestItem
		{
			uniformModel = "\ADF_Gear_2\adfrc_vests\TBAS_T2\tbas_T2_Seco.p3d";
			containerClass = "Supply180";
			mass = 60;
			hiddenSelections[] = {};
			hiddenSelectionsTextures[] = {};
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 24;
					PassThrough = 0.1;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 24;
					PassThrough = 0.1;
				};
				class Abdomen
				{
					HitpointName = "HitAbdomen";
					armor = 24;
					PassThrough = 0.1;
				};
				class Body
				{
					hitpointName = "HitBody";
					PassThrough = 0.1;
				};
			};
		};
	};
	class ADFRC_TBAS_T5_CFA: Vest_Camo_Base
	{
		scope = 2;
		author = "Brucey";
		weaponPoolAvailable = 1;
		allowedSlots[] = {901};
		displayName = "TBAS T5 - CFA";
		picture = "\ADF_Gear_2\adfrc_vests\data\icons\icon_TBAS_T5_CFA_ca.paa";
		model = "\ADF_Gear_2\adfrc_vests\TBAS_T5\TBAS_T5_CFA.p3d";
		hiddenSelections[] = {};
		hiddenSelectionsTextures[] = {};
		class ItemInfo: VestItem
		{
			uniformModel = "\ADF_Gear_2\adfrc_vests\TBAS_T5\TBAS_T5_CFA.p3d";
			containerClass = "Supply180";
			mass = 60;
			hiddenSelections[] = {};
			hiddenSelectionsTextures[] = {};
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 24;
					PassThrough = 0.1;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 24;
					PassThrough = 0.1;
				};
				class Abdomen
				{
					HitpointName = "HitAbdomen";
					armor = 24;
					PassThrough = 0.1;
				};
				class Body
				{
					hitpointName = "HitBody";
					PassThrough = 0.1;
				};
			};
		};
	};
	class ADFRC_TBAS_T5_TL: Vest_Camo_Base
	{
		scope = 2;
		author = "Brucey";
		weaponPoolAvailable = 1;
		allowedSlots[] = {901};
		displayName = "TBAS T5 - Team Leader";
		picture = "\ADF_Gear_2\adfrc_vests\data\icons\icon_TBAS_T5_TL_ca.paa";
		model = "\ADF_Gear_2\adfrc_vests\TBAS_T5\TBAS_T5_TL.p3d";
		hiddenSelections[] = {};
		hiddenSelectionsTextures[] = {};
		class ItemInfo: VestItem
		{
			uniformModel = "\ADF_Gear_2\adfrc_vests\TBAS_T5\TBAS_T5_TL.p3d";
			containerClass = "Supply180";
			mass = 60;
			hiddenSelections[] = {};
			hiddenSelectionsTextures[] = {};
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 24;
					PassThrough = 0.1;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 24;
					PassThrough = 0.1;
				};
				class Abdomen
				{
					HitpointName = "HitAbdomen";
					armor = 24;
					PassThrough = 0.1;
				};
				class Body
				{
					hitpointName = "HitBody";
					PassThrough = 0.1;
				};
			};
		};
	};
	class ADFRC_TBAS_T5_LMG: Vest_Camo_Base
	{
		scope = 2;
		author = "Brucey";
		weaponPoolAvailable = 1;
		allowedSlots[] = {901};
		displayName = "TBAS T5 - Machine Gunner";
		picture = "\ADF_Gear_2\adfrc_vests\data\icons\icon_TBAS_T5_LMG_ca.paa";
		model = "\ADF_Gear_2\adfrc_vests\TBAS_T5\TBAS_T5_MG.p3d";
		hiddenSelections[] = {};
		hiddenSelectionsTextures[] = {};
		class ItemInfo: VestItem
		{
			uniformModel = "\ADF_Gear_2\adfrc_vests\TBAS_T5\TBAS_T5_MG.p3d";
			containerClass = "Supply180";
			mass = 60;
			hiddenSelections[] = {};
			hiddenSelectionsTextures[] = {};
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 24;
					PassThrough = 0.1;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 24;
					PassThrough = 0.1;
				};
				class Abdomen
				{
					HitpointName = "HitAbdomen";
					armor = 24;
					PassThrough = 0.1;
				};
				class Body
				{
					hitpointName = "HitBody";
					PassThrough = 0.1;
				};
			};
		};
	};
	class ADFRC_TBAS_T5_DMR: Vest_Camo_Base
	{
		scope = 1;
		author = "Brucey";
		weaponPoolAvailable = 1;
		allowedSlots[] = {901};
		displayName = "TBAS T5 - DMR";
		picture = "";
		model = "\ADF_Gear_2\adfrc_vests\TBAS_T5\TBAS_T5_Base.p3d";
		hiddenSelections[] = {};
		hiddenSelectionsTextures[] = {};
		class ItemInfo: VestItem
		{
			uniformModel = "\ADF_Gear_2\adfrc_vests\TBAS_T5\TBAS_T5_Base.p3d";
			containerClass = "Supply180";
			mass = 60;
			hiddenSelections[] = {};
			hiddenSelectionsTextures[] = {};
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 24;
					PassThrough = 0.1;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 24;
					PassThrough = 0.1;
				};
				class Abdomen
				{
					HitpointName = "HitAbdomen";
					armor = 24;
					PassThrough = 0.1;
				};
				class Body
				{
					hitpointName = "HitBody";
					PassThrough = 0.1;
				};
			};
		};
	};
	class ADFRC_TBAS_T5_Eng: Vest_Camo_Base
	{
		scope = 2;
		author = "Brucey";
		weaponPoolAvailable = 1;
		allowedSlots[] = {901};
		displayName = "TBAS T5 - Engineer";
		picture = "\ADF_Gear_2\adfrc_vests\data\icons\icon_TBAS_T5_Eng_ca.paa";
		model = "\ADF_Gear_2\adfrc_vests\TBAS_T5\TBAS_T5_Eng.p3d";
		hiddenSelections[] = {};
		hiddenSelectionsTextures[] = {};
		class ItemInfo: VestItem
		{
			uniformModel = "\ADF_Gear_2\adfrc_vests\TBAS_T5\TBAS_T5_Eng.p3d";
			containerClass = "Supply180";
			mass = 60;
			hiddenSelections[] = {};
			hiddenSelectionsTextures[] = {};
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 24;
					PassThrough = 0.1;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 24;
					PassThrough = 0.1;
				};
				class Abdomen
				{
					HitpointName = "HitAbdomen";
					armor = 24;
					PassThrough = 0.1;
				};
				class Body
				{
					hitpointName = "HitBody";
					PassThrough = 0.1;
				};
			};
		};
	};
	class ADFRC_TBAS_T5_Gren: Vest_Camo_Base
	{
		scope = 1;
		author = "Brucey";
		weaponPoolAvailable = 1;
		allowedSlots[] = {901};
		displayName = "TBAS T5 - Grenadier";
		picture = "";
		model = "\ADF_Gear_2\adfrc_vests\TBAS_T5\TBAS_T5_Base.p3d";
		hiddenSelections[] = {};
		hiddenSelectionsTextures[] = {};
		class ItemInfo: VestItem
		{
			uniformModel = "\ADF_Gear_2\adfrc_vests\TBAS_T5\TBAS_T5_Base.p3d";
			containerClass = "Supply180";
			mass = 60;
			hiddenSelections[] = {};
			hiddenSelectionsTextures[] = {};
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 24;
					PassThrough = 0.1;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 24;
					PassThrough = 0.1;
				};
				class Abdomen
				{
					HitpointName = "HitAbdomen";
					armor = 24;
					PassThrough = 0.1;
				};
				class Body
				{
					hitpointName = "HitBody";
					PassThrough = 0.1;
				};
			};
		};
	};
	class ADFRC_TBAS_T5_Breacher: Vest_Camo_Base
	{
		scope = 2;
		author = "Brucey";
		weaponPoolAvailable = 1;
		allowedSlots[] = {901};
		displayName = "TBAS T5 - Breacher";
		picture = "\ADF_Gear_2\adfrc_vests\data\icons\icon_TBAS_T5_Breacher_ca.paa";
		model = "\ADF_Gear_2\adfrc_vests\TBAS_T5\TBAS_T5_Base.p3d";
		hiddenSelections[] = {};
		hiddenSelectionsTextures[] = {};
		class ItemInfo: VestItem
		{
			uniformModel = "\ADF_Gear_2\adfrc_vests\TBAS_T5\TBAS_T5_Base.p3d";
			containerClass = "Supply180";
			mass = 60;
			hiddenSelections[] = {};
			hiddenSelectionsTextures[] = {};
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 24;
					PassThrough = 0.1;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 24;
					PassThrough = 0.1;
				};
				class Abdomen
				{
					HitpointName = "HitAbdomen";
					armor = 24;
					PassThrough = 0.1;
				};
				class Body
				{
					hitpointName = "HitBody";
					PassThrough = 0.1;
				};
			};
		};
	};
	class ADFRC_TBAS_T5_Operator: Vest_Camo_Base
	{
		scope = 2;
		author = "Brucey";
		weaponPoolAvailable = 1;
		allowedSlots[] = {901};
		displayName = "TBAS T5 - Operator";
		picture = "\ADF_Gear_2\adfrc_vests\data\icons\icon_TBAS_T5_Operator_ca.paa";
		model = "\ADF_Gear_2\adfrc_vests\TBAS_T5\TBAS_T5_Base.p3d";
		hiddenSelections[] = {};
		hiddenSelectionsTextures[] = {};
		class ItemInfo: VestItem
		{
			uniformModel = "\ADF_Gear_2\adfrc_vests\TBAS_T5\TBAS_T5_Base.p3d";
			containerClass = "Supply170";
			mass = 60;
			hiddenSelections[] = {};
			hiddenSelectionsTextures[] = {};
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 24;
					PassThrough = 0.1;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 24;
					PassThrough = 0.1;
				};
				class Abdomen
				{
					HitpointName = "HitAbdomen";
					armor = 24;
					PassThrough = 0.1;
				};
				class Body
				{
					hitpointName = "HitBody";
					PassThrough = 0.1;
				};
			};
		};
	};
	class ADFRC_TBAS_T5_Commando_CQB: Vest_Camo_Base
	{
		scope = 2;
		author = "Brucey";
		weaponPoolAvailable = 1;
		allowedSlots[] = {901};
		displayName = "TBAS T5 - CQB";
		picture = "\ADF_Gear_2\adfrc_vests\data\icons\icon_TBAS_T5_CDO_ca.paa";
		model = "\ADF_Gear_2\adfrc_vests\TBAS_T5\TBAS_T5_CQB.p3d";
		hiddenSelections[] = {};
		hiddenSelectionsTextures[] = {};
		class ItemInfo: VestItem
		{
			uniformModel = "\ADF_Gear_2\adfrc_vests\TBAS_T5\TBAS_T5_CQB.p3d";
			containerClass = "Supply160";
			mass = 60;
			hiddenSelections[] = {};
			hiddenSelectionsTextures[] = {};
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 24;
					PassThrough = 0.1;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 24;
					PassThrough = 0.1;
				};
				class Abdomen
				{
					HitpointName = "HitAbdomen";
					armor = 24;
					PassThrough = 0.1;
				};
				class Body
				{
					hitpointName = "HitBody";
					PassThrough = 0.1;
				};
			};
		};
	};
	class ADFRC_TBAS_T5_PatrolCom: Vest_Camo_Base
	{
		scope = 2;
		author = "Brucey";
		weaponPoolAvailable = 1;
		allowedSlots[] = {901};
		displayName = "TBAS T5 - Patrol Commander";
		picture = "\ADF_Gear_2\adfrc_vests\data\icons\icon_TBAS_T5_PC_ca.paa";
		model = "\ADF_Gear_2\adfrc_vests\TBAS_T5\TBAS_T5_PC.p3d";
		hiddenSelections[] = {};
		hiddenSelectionsTextures[] = {};
		class ItemInfo: VestItem
		{
			uniformModel = "\ADF_Gear_2\adfrc_vests\TBAS_T5\TBAS_T5_PC.p3d";
			containerClass = "Supply170";
			mass = 60;
			hiddenSelections[] = {};
			hiddenSelectionsTextures[] = {};
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 24;
					PassThrough = 0.1;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 24;
					PassThrough = 0.1;
				};
				class Abdomen
				{
					HitpointName = "HitAbdomen";
					armor = 24;
					PassThrough = 0.1;
				};
				class Body
				{
					hitpointName = "HitBody";
					PassThrough = 0.1;
				};
			};
		};
	};
	class ADFRC_TBAS_T5_TAG: Vest_Camo_Base
	{
		scope = 1;
		author = "Brucey";
		weaponPoolAvailable = 1;
		allowedSlots[] = {901};
		displayName = "TBAS T5 - TAG Operator";
		picture = "";
		model = "\ADF_Gear_2\adfrc_vests\TBAS_T5\TBAS_T5_Base.p3d";
		hiddenSelections[] = {};
		hiddenSelectionsTextures[] = {};
		class ItemInfo: VestItem
		{
			uniformModel = "\ADF_Gear_2\adfrc_vests\TBAS_T5\TBAS_T5_Base.p3d";
			containerClass = "Supply180";
			mass = 60;
			hiddenSelections[] = {};
			hiddenSelectionsTextures[] = {};
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 24;
					PassThrough = 0.1;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 24;
					PassThrough = 0.1;
				};
				class Abdomen
				{
					HitpointName = "HitAbdomen";
					armor = 24;
					PassThrough = 0.1;
				};
				class Body
				{
					hitpointName = "HitBody";
					PassThrough = 0.1;
				};
			};
		};
	};
	class ADFRC_TBAS_T5_TAG_TL: Vest_Camo_Base
	{
		scope = 1;
		author = "Brucey";
		weaponPoolAvailable = 1;
		allowedSlots[] = {901};
		displayName = "TBAS T5 - TAG Team Leader";
		picture = "";
		model = "\ADF_Gear_2\adfrc_vests\TBAS_T5\TBAS_T5_Base.p3d";
		hiddenSelections[] = {};
		hiddenSelectionsTextures[] = {};
		class ItemInfo: VestItem
		{
			uniformModel = "\ADF_Gear_2\adfrc_vests\TBAS_T5\TBAS_T5_Base.p3d";
			containerClass = "Supply180";
			mass = 60;
			hiddenSelections[] = {};
			hiddenSelectionsTextures[] = {};
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 24;
					PassThrough = 0.1;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 24;
					PassThrough = 0.1;
				};
				class Abdomen
				{
					HitpointName = "HitAbdomen";
					armor = 24;
					PassThrough = 0.1;
				};
				class Body
				{
					hitpointName = "HitBody";
					PassThrough = 0.1;
				};
			};
		};
	};
	class ADFRC_TBAS_T5_TAG_CFA: Vest_Camo_Base
	{
		scope = 1;
		author = "Brucey";
		weaponPoolAvailable = 1;
		allowedSlots[] = {901};
		displayName = "TBAS T5 - TAG CFA";
		picture = "";
		model = "\ADF_Gear_2\adfrc_vests\TBAS_T5\TBAS_T5_Base.p3d";
		hiddenSelections[] = {};
		hiddenSelectionsTextures[] = {};
		class ItemInfo: VestItem
		{
			uniformModel = "\ADF_Gear_2\adfrc_vests\TBAS_T5\TBAS_T5_Base.p3d";
			containerClass = "Supply180";
			mass = 60;
			hiddenSelections[] = {};
			hiddenSelectionsTextures[] = {};
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 24;
					PassThrough = 0.1;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 24;
					PassThrough = 0.1;
				};
				class Abdomen
				{
					HitpointName = "HitAbdomen";
					armor = 24;
					PassThrough = 0.1;
				};
				class Body
				{
					hitpointName = "HitBody";
					PassThrough = 0.1;
				};
			};
		};
	};
	class ADFRC_TBAS_T5_TAG_Breacher: Vest_Camo_Base
	{
		scope = 1;
		author = "Brucey";
		weaponPoolAvailable = 1;
		allowedSlots[] = {901};
		displayName = "TBAS T5 - TAG Breacher";
		picture = "";
		model = "\ADF_Gear_2\adfrc_vests\TBAS_T5\TBAS_T5_Base.p3d";
		hiddenSelections[] = {};
		hiddenSelectionsTextures[] = {};
		class ItemInfo: VestItem
		{
			uniformModel = "\ADF_Gear_2\adfrc_vests\TBAS_T5\TBAS_T5_Base.p3d";
			containerClass = "Supply180";
			mass = 60;
			hiddenSelections[] = {};
			hiddenSelectionsTextures[] = {};
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 24;
					PassThrough = 0.1;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 24;
					PassThrough = 0.1;
				};
				class Abdomen
				{
					HitpointName = "HitAbdomen";
					armor = 24;
					PassThrough = 0.1;
				};
				class Body
				{
					hitpointName = "HitBody";
					PassThrough = 0.1;
				};
			};
		};
	};
	class ADFRC_JPC_CFA: Vest_Camo_Base
	{
		scope = 1;
		author = "Brucey";
		weaponPoolAvailable = 1;
		allowedSlots[] = {901};
		displayName = "JPC - CFA";
		picture = "";
		model = "\ADF_Gear_2\adfrc_vests\JPC\JPC_Base.p3d";
		hiddenSelections[] = {};
		hiddenSelectionsTextures[] = {};
		class ItemInfo: VestItem
		{
			uniformModel = "\ADF_Gear_2\adfrc_vests\JPC\JPC_Base.p3d";
			containerClass = "Supply180";
			mass = 60;
			hiddenSelections[] = {};
			hiddenSelectionsTextures[] = {};
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 24;
					PassThrough = 0.1;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 24;
					PassThrough = 0.1;
				};
				class Abdomen
				{
					HitpointName = "HitAbdomen";
					armor = 24;
					PassThrough = 0.1;
				};
				class Body
				{
					hitpointName = "HitBody";
					PassThrough = 0.1;
				};
			};
		};
	};
	class ADFRC_JPC_TL: Vest_Camo_Base
	{
		scope = 1;
		author = "Brucey";
		weaponPoolAvailable = 1;
		allowedSlots[] = {901};
		displayName = "JPC - Team Leader";
		picture = "";
		model = "\ADF_Gear_2\adfrc_vests\JPC\JPC_Base.p3d";
		hiddenSelections[] = {};
		hiddenSelectionsTextures[] = {};
		class ItemInfo: VestItem
		{
			uniformModel = "\ADF_Gear_2\adfrc_vests\JPC\JPC_Base.p3d";
			containerClass = "Supply180";
			mass = 60;
			hiddenSelections[] = {};
			hiddenSelectionsTextures[] = {};
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 24;
					PassThrough = 0.1;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 24;
					PassThrough = 0.1;
				};
				class Abdomen
				{
					HitpointName = "HitAbdomen";
					armor = 24;
					PassThrough = 0.1;
				};
				class Body
				{
					hitpointName = "HitBody";
					PassThrough = 0.1;
				};
			};
		};
	};
	class ADFRC_JPC_LMG: Vest_Camo_Base
	{
		scope = 1;
		author = "Brucey";
		weaponPoolAvailable = 1;
		allowedSlots[] = {901};
		displayName = "JPC - Machine Gunner";
		picture = "";
		model = "\ADF_Gear_2\adfrc_vests\JPC\JPC_Base.p3d";
		hiddenSelections[] = {};
		hiddenSelectionsTextures[] = {};
		class ItemInfo: VestItem
		{
			uniformModel = "\ADF_Gear_2\adfrc_vests\JPC\JPC_Base.p3d";
			containerClass = "Supply210";
			mass = 70;
			hiddenSelections[] = {};
			hiddenSelectionsTextures[] = {};
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 24;
					PassThrough = 0.1;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 24;
					PassThrough = 0.1;
				};
				class Abdomen
				{
					HitpointName = "HitAbdomen";
					armor = 24;
					PassThrough = 0.1;
				};
				class Body
				{
					hitpointName = "HitBody";
					PassThrough = 0.1;
				};
			};
		};
	};
	class ADFRC_JPC_DMR: Vest_Camo_Base
	{
		scope = 1;
		author = "Brucey";
		weaponPoolAvailable = 1;
		allowedSlots[] = {901};
		displayName = "JPC - DMR";
		picture = "";
		model = "\ADF_Gear_2\adfrc_vests\JPC\JPC_Base.p3d";
		hiddenSelections[] = {};
		hiddenSelectionsTextures[] = {};
		class ItemInfo: VestItem
		{
			uniformModel = "\ADF_Gear_2\adfrc_vests\JPC\JPC_Base.p3d";
			containerClass = "Supply190";
			mass = 60;
			hiddenSelections[] = {};
			hiddenSelectionsTextures[] = {};
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 24;
					PassThrough = 0.1;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 24;
					PassThrough = 0.1;
				};
				class Abdomen
				{
					HitpointName = "HitAbdomen";
					armor = 24;
					PassThrough = 0.1;
				};
				class Body
				{
					hitpointName = "HitBody";
					PassThrough = 0.1;
				};
			};
		};
	};
	class ADFRC_JPC_Eng: Vest_Camo_Base
	{
		scope = 1;
		author = "Brucey";
		weaponPoolAvailable = 1;
		allowedSlots[] = {901};
		displayName = "JPC - Engineer";
		picture = "";
		model = "\ADF_Gear_2\adfrc_vests\JPC\JPC_Base.p3d";
		hiddenSelections[] = {};
		hiddenSelectionsTextures[] = {};
		class ItemInfo: VestItem
		{
			uniformModel = "\ADF_Gear_2\adfrc_vests\JPC\JPC_Base.p3d";
			containerClass = "Supply200";
			mass = 60;
			hiddenSelections[] = {};
			hiddenSelectionsTextures[] = {};
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 24;
					PassThrough = 0.1;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 24;
					PassThrough = 0.1;
				};
				class Abdomen
				{
					HitpointName = "HitAbdomen";
					armor = 24;
					PassThrough = 0.1;
				};
				class Body
				{
					hitpointName = "HitBody";
					PassThrough = 0.1;
				};
			};
		};
	};
	class ADFRC_JPC_Gren: Vest_Camo_Base
	{
		scope = 1;
		author = "Brucey";
		weaponPoolAvailable = 1;
		allowedSlots[] = {901};
		displayName = "JPC - Grenadier";
		picture = "";
		model = "\ADF_Gear_2\adfrc_vests\JPC\JPC_Base.p3d";
		hiddenSelections[] = {};
		hiddenSelectionsTextures[] = {};
		class ItemInfo: VestItem
		{
			uniformModel = "\ADF_Gear_2\adfrc_vests\JPC\JPC_Base.p3d";
			containerClass = "Supply170";
			mass = 60;
			hiddenSelections[] = {};
			hiddenSelectionsTextures[] = {};
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 24;
					PassThrough = 0.1;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 24;
					PassThrough = 0.1;
				};
				class Abdomen
				{
					HitpointName = "HitAbdomen";
					armor = 24;
					PassThrough = 0.1;
				};
				class Body
				{
					hitpointName = "HitBody";
					PassThrough = 0.1;
				};
			};
		};
	};
	class ADFRC_JPC_Breacher: Vest_Camo_Base
	{
		scope = 1;
		author = "Brucey";
		weaponPoolAvailable = 1;
		allowedSlots[] = {901};
		displayName = "JPC - Breacher";
		picture = "";
		model = "\ADF_Gear_2\adfrc_vests\JPC\JPC_Base.p3d";
		hiddenSelections[] = {};
		hiddenSelectionsTextures[] = {};
		class ItemInfo: VestItem
		{
			uniformModel = "\ADF_Gear_2\adfrc_vests\JPC\JPC_Base.p3d";
			containerClass = "Supply180";
			mass = 60;
			hiddenSelections[] = {};
			hiddenSelectionsTextures[] = {};
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 24;
					PassThrough = 0.1;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 24;
					PassThrough = 0.1;
				};
				class Abdomen
				{
					HitpointName = "HitAbdomen";
					armor = 24;
					PassThrough = 0.1;
				};
				class Body
				{
					hitpointName = "HitBody";
					PassThrough = 0.1;
				};
			};
		};
	};
	class ADFRC_JPC_Operator: Vest_Camo_Base
	{
		scope = 2;
		author = "Brucey";
		weaponPoolAvailable = 1;
		allowedSlots[] = {901};
		displayName = "JPC - Operator";
		picture = "\ADF_Gear_2\adfrc_vests\data\icons\icon_JPC_Operator_ca.paa";
		model = "\ADF_Gear_2\adfrc_vests\JPC\JPC_Base.p3d";
		hiddenSelections[] = {};
		hiddenSelectionsTextures[] = {};
		class ItemInfo: VestItem
		{
			uniformModel = "\ADF_Gear_2\adfrc_vests\JPC\JPC_Base.p3d";
			containerClass = "Supply160";
			mass = 60;
			hiddenSelections[] = {};
			hiddenSelectionsTextures[] = {};
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 24;
					PassThrough = 0.1;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 24;
					PassThrough = 0.1;
				};
				class Abdomen
				{
					HitpointName = "HitAbdomen";
					armor = 24;
					PassThrough = 0.1;
				};
				class Body
				{
					hitpointName = "HitBody";
					PassThrough = 0.1;
				};
			};
		};
	};
	class ADFRC_JPC_Commando_CQB: Vest_Camo_Base
	{
		scope = 1;
		author = "Brucey";
		weaponPoolAvailable = 1;
		allowedSlots[] = {901};
		displayName = "JPC - CQB";
		picture = "";
		model = "\ADF_Gear_2\adfrc_vests\JPC\JPC_Base.p3d";
		hiddenSelections[] = {};
		hiddenSelectionsTextures[] = {};
		class ItemInfo: VestItem
		{
			uniformModel = "\ADF_Gear_2\adfrc_vests\JPC\JPC_Base.p3d";
			containerClass = "Supply140";
			mass = 60;
			hiddenSelections[] = {};
			hiddenSelectionsTextures[] = {};
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 24;
					PassThrough = 0.1;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 24;
					PassThrough = 0.1;
				};
				class Abdomen
				{
					HitpointName = "HitAbdomen";
					armor = 24;
					PassThrough = 0.1;
				};
				class Body
				{
					hitpointName = "HitBody";
					PassThrough = 0.1;
				};
			};
		};
	};
	class ADFRC_JPC_PatrolCom: Vest_Camo_Base
	{
		scope = 1;
		author = "Brucey";
		weaponPoolAvailable = 1;
		allowedSlots[] = {901};
		displayName = "JPC - Patrol Commander";
		picture = "";
		model = "\ADF_Gear_2\adfrc_vests\JPC\JPC_Base.p3d";
		hiddenSelections[] = {};
		hiddenSelectionsTextures[] = {};
		class ItemInfo: VestItem
		{
			uniformModel = "\ADF_Gear_2\adfrc_vests\JPC\JPC_Base.p3d";
			containerClass = "Supply170";
			mass = 60;
			hiddenSelections[] = {};
			hiddenSelectionsTextures[] = {};
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 24;
					PassThrough = 0.1;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 24;
					PassThrough = 0.1;
				};
				class Abdomen
				{
					HitpointName = "HitAbdomen";
					armor = 24;
					PassThrough = 0.1;
				};
				class Body
				{
					hitpointName = "HitBody";
					PassThrough = 0.1;
				};
			};
		};
	};
	class ADFRC_JPC_TAG: Vest_Camo_Base
	{
		scope = 1;
		author = "Brucey";
		weaponPoolAvailable = 1;
		allowedSlots[] = {901};
		displayName = "JPC - TAG Operator";
		picture = "";
		model = "\ADF_Gear_2\adfrc_vests\JPC\JPC_Base.p3d";
		hiddenSelections[] = {};
		hiddenSelectionsTextures[] = {};
		class ItemInfo: VestItem
		{
			uniformModel = "\ADF_Gear_2\adfrc_vests\JPC\JPC_Base.p3d";
			containerClass = "Supply180";
			mass = 60;
			hiddenSelections[] = {};
			hiddenSelectionsTextures[] = {};
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 24;
					PassThrough = 0.1;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 24;
					PassThrough = 0.1;
				};
				class Abdomen
				{
					HitpointName = "HitAbdomen";
					armor = 24;
					PassThrough = 0.1;
				};
				class Body
				{
					hitpointName = "HitBody";
					PassThrough = 0.1;
				};
			};
		};
	};
	class ADFRC_JPC_TAG_TL: Vest_Camo_Base
	{
		scope = 1;
		author = "Brucey";
		weaponPoolAvailable = 1;
		allowedSlots[] = {901};
		displayName = "JPC - TAG Team Leader";
		picture = "";
		model = "\ADF_Gear_2\adfrc_vests\JPC\JPC_Base.p3d";
		hiddenSelections[] = {};
		hiddenSelectionsTextures[] = {};
		class ItemInfo: VestItem
		{
			uniformModel = "\ADF_Gear_2\adfrc_vests\JPC\JPC_Base.p3d";
			containerClass = "Supply180";
			mass = 60;
			hiddenSelections[] = {};
			hiddenSelectionsTextures[] = {};
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 24;
					PassThrough = 0.1;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 24;
					PassThrough = 0.1;
				};
				class Abdomen
				{
					HitpointName = "HitAbdomen";
					armor = 24;
					PassThrough = 0.1;
				};
				class Body
				{
					hitpointName = "HitBody";
					PassThrough = 0.1;
				};
			};
		};
	};
	class ADFRC_JPC_TAG_CFA: Vest_Camo_Base
	{
		scope = 1;
		author = "Brucey";
		weaponPoolAvailable = 1;
		allowedSlots[] = {901};
		displayName = "JPC - TAG CFA";
		picture = "";
		model = "\ADF_Gear_2\adfrc_vests\JPC\JPC_Base.p3d";
		hiddenSelections[] = {};
		hiddenSelectionsTextures[] = {};
		class ItemInfo: VestItem
		{
			uniformModel = "\ADF_Gear_2\adfrc_vests\JPC\JPC_Base.p3d";
			containerClass = "Supply180";
			mass = 60;
			hiddenSelections[] = {};
			hiddenSelectionsTextures[] = {};
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 24;
					PassThrough = 0.1;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 24;
					PassThrough = 0.1;
				};
				class Abdomen
				{
					HitpointName = "HitAbdomen";
					armor = 24;
					PassThrough = 0.1;
				};
				class Body
				{
					hitpointName = "HitBody";
					PassThrough = 0.1;
				};
			};
		};
	};
	class ADFRC_JPC_TAG_Breacher: Vest_Camo_Base
	{
		scope = 1;
		author = "Brucey";
		weaponPoolAvailable = 1;
		allowedSlots[] = {901};
		displayName = "JPC - TAG Breacher";
		picture = "";
		model = "\ADF_Gear_2\adfrc_vests\JPC\JPC_Base.p3d";
		hiddenSelections[] = {};
		hiddenSelectionsTextures[] = {};
		class ItemInfo: VestItem
		{
			uniformModel = "\ADF_Gear_2\adfrc_vests\JPC\JPC_Base.p3d";
			containerClass = "Supply180";
			mass = 60;
			hiddenSelections[] = {};
			hiddenSelectionsTextures[] = {};
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 24;
					PassThrough = 0.1;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 24;
					PassThrough = 0.1;
				};
				class Abdomen
				{
					HitpointName = "HitAbdomen";
					armor = 24;
					PassThrough = 0.1;
				};
				class Body
				{
					hitpointName = "HitBody";
					PassThrough = 0.1;
				};
			};
		};
	};
	
	class ADFRC_Peacekeeper_Mk5_MC: Vest_Camo_Base
	{
		scope = 2;
		author = "Brucey";
		weaponPoolAvailable = 1;
		allowedSlots[] = {901};
		displayName = "Platatac Peacekeeper Mk5 (MC)";
		picture = "\ADF_Gear_2\adfrc_vests\data\icons\adfrc_peacekeeper_mk5_mc_ca.paa";
		model = "\ADF_Gear_2\adfrc_vests\Peacekeeper\Peacekeeper_SOCOM.p3d";
		hiddenSelections[] = {};
		hiddenSelectionsTextures[] = {};
		class ItemInfo: VestItem
		{
			uniformModel = "\ADF_Gear_2\adfrc_vests\Peacekeeper\Peacekeeper_SOCOM.p3d";
			containerClass = "Supply160";
			mass = 40;
			hiddenSelections[] = {};
			hiddenSelectionsTextures[] = {};
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 0;
					PassThrough = 1;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 0;
					PassThrough = 1;
				};
				class Abdomen
				{
					HitpointName = "HitAbdomen";
					armor = 2;
					passThrough = 0.9;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 1;
				};
			};
		};
	};
	
	class ADFRC_Peacekeeper_Mk5_MC_NoFlaps: ADFRC_Peacekeeper_Mk5_MC
	{
		scope = 2;
		author = "Brucey";
		weaponPoolAvailable = 1;
		allowedSlots[] = {901};
		displayName = "Platatac Peacekeeper Mk5 (MC) - No Flaps";
		picture = "\ADF_Gear_2\adfrc_vests\data\icons\adfrc_peacekeeper_mk5_mc_noflaps_ca.paa";
		model = "\ADF_Gear_2\adfrc_vests\Peacekeeper\Peacekeeper_SOCOM.p3d";
		// Selections listed with an empty texture are hidden. The worn vest reads ItemInfo's
		// list, so it has to be set there too (the inherited MC ItemInfo list is empty).
		hiddenSelections[] = {"magazine_flap_01", "magazine_flap_02", "magazine_flap_03"};
		hiddenSelectionsTextures[] = {"", "", ""};
		class ItemInfo: ItemInfo
		{
			hiddenSelections[] = {"magazine_flap_01", "magazine_flap_02", "magazine_flap_03"};
		};
	};
	
	class ADFRC_Peacekeeper_Mk5_Tan: Vest_Camo_Base
	{
		scope = 2;
		author = "Brucey";
		weaponPoolAvailable = 1;
		allowedSlots[] = {901};
		displayName = "Platatac Peacekeeper Mk5 (Tan)";
		picture = "\ADF_Gear_2\adfrc_vests\data\icons\adfrc_peacekeeper_mk5_tan_ca.paa";
		model = "\ADF_Gear_2\adfrc_vests\Peacekeeper\Peacekeeper_RAR.p3d";
		hiddenSelections[] = {};
		hiddenSelectionsTextures[] = {};
		class ItemInfo: VestItem
		{
			uniformModel = "\ADF_Gear_2\adfrc_vests\Peacekeeper\Peacekeeper_RAR.p3d";
			containerClass = "Supply160";
			mass = 40;
			hiddenSelections[] = {};
			hiddenSelectionsTextures[] = {};
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 0;
					PassThrough = 1;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 0;
					PassThrough = 1;
				};
				class Abdomen
				{
					HitpointName = "HitAbdomen";
					armor = 2;
					passThrough = 0.9;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 1;
				};
			};
		};
	};
	class ADFRC_Peacekeeper_Mk5_Tan_NoFlaps: ADFRC_Peacekeeper_Mk5_Tan
	{
		picture = "\ADF_Gear_2\adfrc_vests\data\icons\adfrc_peacekeeper_mk5_tan_noflaps_ca.paa";
		scope = 2;
		displayName = "Platatac Peacekeeper Mk5 (Tan) - No Flaps";
		// Same as the MC No Flaps: empty textures hide the flaps, ItemInfo list covers the worn vest.
		hiddenSelections[] = {"magazine_flap_01", "magazine_flap_02", "magazine_flap_03"};
		hiddenSelectionsTextures[] = {"", "", ""};
		class ItemInfo: ItemInfo
		{
			hiddenSelections[] = {"magazine_flap_01", "magazine_flap_02", "magazine_flap_03"};
		};
	};
	class ADFRC_Peacekeeper_Mk5_AMCU: ADFRC_Peacekeeper_Mk5_Tan
	{
		// Hidden until a real AMCU texture exists: Peacekeeper_AMCU_CO.paa is currently a
		// byte-identical copy of Peacekeeper_Tan_CO.paa. Paint it, then set scope = 2.
		// The rig and flaps carry the whole Peacekeeper texture; the rig selection is in
		// the Peacekeeper model.cfg sections so this swap applies when worn.
		scope = 1;
		displayName = "Platatac Peacekeeper Mk5 (AMCU)";
		hiddenSelections[] = {"platatac_peackeeper_mk5_rig", "magazine_flap_01", "magazine_flap_02", "magazine_flap_03"};
		hiddenSelectionsTextures[] = {"\ADF_Gear_2\adfrc_vests\Peacekeeper\Textures\Peacekeeper_AMCU_CO.paa", "\ADF_Gear_2\adfrc_vests\Peacekeeper\Textures\Peacekeeper_AMCU_CO.paa", "\ADF_Gear_2\adfrc_vests\Peacekeeper\Textures\Peacekeeper_AMCU_CO.paa", "\ADF_Gear_2\adfrc_vests\Peacekeeper\Textures\Peacekeeper_AMCU_CO.paa"};
		class ItemInfo: ItemInfo
		{
			hiddenSelections[] = {"platatac_peackeeper_mk5_rig", "magazine_flap_01", "magazine_flap_02", "magazine_flap_03"};
		};
	};
	
	
	class ADFRC_PilotVest: Vest_Camo_Base
	{
		scope = 2;
		author = "Exer";
		weaponPoolAvailable = 1;
		allowedSlots[] = {901};
		displayName = "ADF Aircrew Vest";
		picture = "\ADF_Gear_2\adfrc_vests\data\icons\icon_Aircrew_vest_ca.paa";
		model = "\ADF_Gear_2\adfrc_vests\vest_aircrew.p3d";
		hiddenSelections[] = {};
		hiddenSelectionsTextures[] = {};
		class ItemInfo: VestItem
		{
			uniformModel = "\ADF_Gear_2\adfrc_vests\vest_aircrew.p3d";
			containerClass = "Supply90";
			mass = 30;
			hiddenSelections[] = {};
			hiddenSelectionsTextures[] = {};
		};
	};
	
	
	
	//////////////////////// LEGACY VESTS POINTING TO NEW VESTS ////////////////////////
	class ADFRC_PC_Tan_1: ADFRC_TBAS_T2_Rifleman_Pistol
	{
		scope=1;
	};
	class ADFRC_PC_Tan_2: ADFRC_TBAS_T2_Rifleman_Pistol
	{
		scope=1;
	};
	class ADFRC_PC_Tan_3: ADFRC_TBAS_T2_Rifleman_Pistol
	{
		scope=1;
	};
    class ADFRC_PC_Tan_4: ADFRC_TBAS_T2_Rifleman_Pistol
	{
		scope=1;
	};
    class ADFRC_PC_Tan_5: ADFRC_TBAS_T2_Rifleman_Pistol
	{
		scope=1;
	};
    class ADFRC_PC_Tan_6: ADFRC_TBAS_T2_Rifleman_Pistol
	{
		scope=1;
	};
    class ADFRC_PC_Tan_7: ADFRC_TBAS_T2_Rifleman_Pistol
	{
		scope=1;
	};
    class ADFRC_LPC_Tan_1: ADFRC_TBAS_T2_Rifleman_Light
	{
		scope=1;
	};
    class ADFRC_LPC_Tan_2: ADFRC_TBAS_T2_Rifleman_Light
	{
		scope=1;
	};
};
