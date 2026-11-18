////////////////////////////////////////////////////////////////////
//DeRap: adfrc_weaponbox\config.bin
//Produced from mikero's Dos Tools Dll version 10.13
//https://mikero.bytex.digital/Downloads
//'now' is Thu Nov 19 02:29:05 2026 : 'file' last modified on Thu Nov 19 02:29:05 2026
////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgPatches
{
	class ADFRC_Weaponbox
	{
		units[] = {"ADFRC_weaponbox_launchers","ADFRC_weaponbox_optics","ADFRC_weaponbox_pistols","ADFRC_weaponbox_m4a5","ADFRC_weaponbox_f88","ADFRC_weaponbox_mg","ADFRC_weaponbox_sr25","ADFRC_weaponbox_amp","ADFRC_weaponbox_dpcu","ADFRC_weaponbox_dpdu","ADFRC_weaponbox_large","ADFRC_weaponbox_medium"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"A3_Weapons_F","A3_Weapons_F_Acc","ADF_Core"};
	};
};
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class SlotInfo;
class CowsSlot;
class PointerSlot;
class CfgVehicleIcons
{
	icon_ADFRC_box = "\ADF_Weapons\adfrc_weaponbox\icons\iconbox_ADFRC_ca.paa";
	icon_ADFRC_uniform = "\ADF_Weapons\adfrc_weaponbox\icons\iconbox_uni_ca.paa";
	icon_ADFRC_crate = "\ADF_Weapons\adfrc_weaponbox\icons\iconcrate_ADFRC_ca.paa";
};
class CfgVehicles
{
	class NATO_Box_Base;
	class Box_NATO_Wps_F;
	class Box_NATO_AmmoVeh_F;
	class ADFRC_weaponbox_large: Box_NATO_AmmoVeh_F
	{
		scope = 2;
		icon = "icon_ADFRC_box";
		displayName = "[ADF] Empty Container";
		author = "$STR_ADFRC_AUTHOR";
		maximumLoad = 99999;
		transportMaxWeapons = 15000;
		transportMaxMagazines = 20000;
		transportMaxBackpacks = 50;
		weight = 1000;
		class TransportWeapons{};
		class TransportMagazines{};
		class TransportItems{};
		hiddenSelectionsTextures[] = {"","ADF_Weapons\adfrc_weaponbox\data\ADFRC_container_dpcu_co.paa"};
	};
	class ADFRC_weaponbox_medium: Box_NATO_Wps_F
	{
		scope = 2;
		displayName = "[ADF] Empty Weaponbox";
		icon = "icon_ADFRC_crate";
		author = "$STR_ADFRC_AUTHOR";
		transportMaxWeapons = 50;
		transportMaxMagazines = 200;
		transportMaxBackpacks = 5;
		class TransportWeapons{};
		class TransportMagazines{};
		class TransportItems{};
		slingLoadCargoMemoryPoints[] = {"SlingLoadCargo1","SlingLoadCargo2","SlingLoadCargo3","SlingLoadCargo4"};
		model = "\ADF_Weapons\adfrc_weaponbox\Weaponbox.p3d";
		hiddenSelections[] = {"Camo1","Camo2"};
		hiddenSelectionsTextures[] = {"ADF_Weapons\adfrc_weaponbox\data\ADFRC_weaponbox_co.paa","ADF_Weapons\adfrc_weaponbox\data\ADFRC_weaponbox_signs_ca.paa"};
	};
	class ADFRC_weaponbox_launchers: ADFRC_weaponbox_large
	{
		scope = 2;
		accuracy = 1000;
		vehicleClass = "Ammo";
		displayName = "[ADF] Launchers";
		author = "$STR_ADFRC_AUTHOR";
		maximumLoad = 99999;
		transportMaxWeapons = 15000;
		transportMaxMagazines = 20000;
		transportMaxBackpacks = 50;
		class TransportWeapons
		{
			class _xx_ADFRC_carlgustav_m3
			{
				weapon = "ADFRC_carlgustav_m3";
				count = 10;
			};
			class _xx_ADFRC_carlgustav_m4
			{
				weapon = "ADFRC_carlgustav_m4";
				count = 10;
			};
		};
		class TransportMagazines
		{
			class _xx_ADFRC_magazine_84mm_asm_509
			{
				magazine = "ADFRC_magazine_84mm_asm_509";
				count = 20;
			};
			class _xx_ADFRC_magazine_84mm_he_441d
			{
				magazine = "ADFRC_magazine_84mm_he_441d";
				count = 20;
			};
			class _xx_ADFRC_magazine_84mm_heat_551c
			{
				magazine = "ADFRC_magazine_84mm_heat_551c";
				count = 20;
			};
			class _xx_ADFRC_magazine_84mm_heat_751
			{
				magazine = "ADFRC_magazine_84mm_heat_751";
				count = 20;
			};
			class _xx_ADFRC_magazine_84mm_hedp_502
			{
				magazine = "ADFRC_magazine_84mm_hedp_502";
				count = 20;
			};
		};
	};
	class ADFRC_weaponbox_optics: ADFRC_weaponbox_medium
	{
		scope = 2;
		displayName = "[ADF] Optics Container";
		author = "$STR_ADFRC_AUTHOR";
		class TransportWeapons{};
		class TransportMagazines{};
		class TransportItems
		{
			class _xx_ADFRC_swarovski_optic
			{
				name = "ADFRC_swarovski_optic";
				count = 10;
			};
			class _xx_ADFRC_swarovski_optic_SA2
			{
				name = "ADFRC_swarovski_optic_SA2";
				count = 10;
			};
			class _xx_ADFRC_elcan_c79
			{
				name = "ADFRC_elcan_c79";
				count = 10;
			};
			class _xx_ADFRC_Specter_CDO_KF
			{
				name = "ADFRC_Specter_CDO_KF";
				count = 10;
			};
			class _xx_ADFRC_Specter_CDO_C_KF
			{
				name = "ADFRC_Specter_CDO_C_KF";
				count = 10;
			};
			class _xx_ADFRC_Specter_CDO
			{
				name = "ADFRC_Specter_CDO";
				count = 10;
			};
			class _xx_ADFRC_Specter_C_CDO
			{
				name = "ADFRC_Specter_C_CDO";
				count = 10;
			};
			class _xx_ADFRC_Specter_RAR_KF
			{
				name = "ADFRC_Specter_RAR_KF";
				count = 10;
			};
			class _xx_ADFRC_Specter_RAR_C_KF
			{
				name = "ADFRC_Specter_RAR_C_KF";
				count = 10;
			};
			class _xx_ADFRC_Specter_RAR
			{
				name = "ADFRC_Specter_RAR";
				count = 10;
			};
			class _xx_ADFRC_Specter_C_RAR
			{
				name = "ADFRC_Specter_C_RAR";
				count = 10;
			};
			class _xx_ADFRC_Specter_CDO_KF_DPP
			{
				name = "ADFRC_Specter_CDO_KF_DPP";
				count = 10;
			};
			class _xx_ADFRC_Specter_CDO_C_KF_DPP
			{
				name = "ADFRC_Specter_CDO_C_KF_DPP";
				count = 10;
			};
			class _xx_ADFRC_Specter_CDO_CPP
			{
				name = "ADFRC_Specter_CDO_CPP";
				count = 10;
			};
			class _xx_ADFRC_Specter_CDO_C_DPP
			{
				name = "ADFRC_Specter_CDO_C_DPP";
				count = 10;
			};
			class _xx_ADFRC_acog_ta648
			{
				name = "ADFRC_acog_ta648";
				count = 10;
			};
			class _xx_ADFRC_acog_ta648_rds
			{
				name = "ADFRC_acog_ta648_rds";
				count = 10;
			};
			class _xx_ADFRC_TA31_BLK
			{
				name = "ADFRC_TA31_BLK";
				count = 10;
			};
			class _xx_ADFRC_TA31_RMR_BLK
			{
				name = "ADFRC_TA31_RMR_BLK";
				count = 10;
			};
			class _xx_ADFRC_TA31_KF_BLK
			{
				name = "ADFRC_TA31_KF_BLK";
				count = 10;
			};
			class _xx_ADFRC_TA31_KF_RMR_BLK
			{
				name = "ADFRC_TA31_KF_RMR_BLK";
				count = 10;
			};
			class _xx_ADFRC_TA31_FDE
			{
				name = "ADFRC_TA31_FDE";
				count = 10;
			};
			class _xx_ADFRC_TA31_RMR_FDE
			{
				name = "ADFRC_TA31_RMR_FDE";
				count = 10;
			};
			class _xx_ADFRC_TA31_KF_FDE
			{
				name = "ADFRC_TA31_KF_FDE";
				count = 10;
			};
			class _xx_ADFRC_TA31_KF_RMR_FDE
			{
				name = "ADFRC_TA31_KF_RMR_FDE";
				count = 10;
			};
			class _xx_ADFRC_eotech552
			{
				name = "ADFRC_eotech552";
				count = 10;
			};
			class _xx_ADFRC_eotech552_3XDOWN
			{
				name = "ADFRC_eotech552_3XDOWN";
				count = 10;
			};
			class _xx_ADFRC_eotech552_3XUP
			{
				name = "ADFRC_eotech552_3XUP";
				count = 10;
			};
			class _xx_ADFRC_EXPS3
			{
				name = "ADFRC_EXPS3";
				count = 10;
			};
			class _xx_ADFRC_EXPS3_Down
			{
				name = "ADFRC_EXPS3_Down";
				count = 10;
			};
			class _xx_ADFRC_EXPS3_Up
			{
				name = "ADFRC_EXPS3_Up";
				count = 10;
			};
			class _xx_ADFRC_DPP
			{
				name = "ADFRC_DPP";
				count = 10;
			};
			class _xx_ADFRC_F9_Romeo2
			{
				name = "ADFRC_F9_Romeo2";
				count = 10;
			};
			class _xx_ADFRC_Aimpoint_Pro_S_FC
			{
				name = "ADFRC_Aimpoint_Pro_S_FC";
				count = 10;
			};
			class _xx_ADFRC_Aimpoint_Pro_S
			{
				name = "ADFRC_Aimpoint_Pro_S";
				count = 10;
			};
			class _xx_ADFRC_Aimpoint_Pro_T_FC
			{
				name = "ADFRC_Aimpoint_Pro_T_FC";
				count = 10;
			};
			class _xx_ADFRC_Aimpoint_Pro_T
			{
				name = "ADFRC_Aimpoint_Pro_T";
				count = 10;
			};
			class _xx_ADFRC_MicroT2
			{
				name = "ADFRC_MicroT2";
				count = 10;
			};
			class _xx_ADFRC_MicroT2_Down
			{
				name = "ADFRC_MicroT2_Down";
				count = 10;
			};
			class _xx_ADFRC_MicroT2_Up
			{
				name = "ADFRC_MicroT2_Up";
				count = 10;
			};
		};
	};
	class ADFRC_weaponbox_pistols: ADFRC_weaponbox_medium
	{
		scope = 2;
		displayName = "[ADF] Handgun Container";
		author = "$STR_ADFRC_AUTHOR";
		class TransportWeapons
		{
			class _xx_ADFRC_HP_MK3
			{
				weapon = "ADFRC_HP_MK3";
				count = 20;
			};
			class _xx_ADFRC_usp_9MM
			{
				weapon = "ADFRC_usp_9MM";
				count = 20;
			};
			class _xx_ADFRC_F9
			{
				weapon = "ADFRC_F9";
				count = 20;
			};
			class _xx_ADFRC_G19_G5_SLICK
			{
				weapon = "ADFRC_G19_G5_SLICK";
				count = 20;
			};
			class _xx_ADFRC_G19_G5_MOS_9
			{
				weapon = "ADFRC_G19_G5_MOS_9";
				count = 20;
			};
		};
		class TransportMagazines
		{
			class _xx_ADFRC_13rnd_9x19_mag
			{
				magazine = "ADFRC_13rnd_9x19_mag";
				count = 50;
			};
			class _xx_ADFRC_17rnd_9MM_BALL_F9
			{
				magazine = "ADFRC_17rnd_9MM_BALL_F9";
				count = 50;
			};
			class _xx_ADFRC_15rnd_9MM_BALL_G19
			{
				magazine = "ADFRC_15rnd_9MM_BALL_G19";
				count = 50;
			};
			class _xx_ADFRC_15rnd_9MM_BALL_USP
			{
				magazine = "ADFRC_15rnd_9MM_BALL_USP";
				count = 50;
			};
		};
		class TransportItems
		{
			class _xx_ADFRC_Ryder9
			{
				name = "ADFRC_Ryder9";
				count = 10;
			};
			class _xx_ADFRC_Zev
			{
				name = "ADFRC_Zev";
				count = 10;
			};
			class _xx_ADFRC_F9_FOXTROT2
			{
				name = "ADFRC_F9_FOXTROT2";
				count = 10;
			};
			class _xx_ADFRC_X400_Laser
			{
				name = "ADFRC_X400_Laser";
				count = 10;
			};
			class _xx_ADFRC_X400_Light
			{
				name = "ADRC_X400_Light";
				count = 10;
			};
		};
	};
	class ADFRC_weaponbox_m4a5: ADFRC_weaponbox_medium
	{
		scope = 2;
		displayName = "[ADF] M4A5 Weapon Box";
		author = "$STR_ADFRC_AUTHOR";
		hiddenSelections[] = {"Camo1","Camo2"};
		hiddenSelectionsTextures[] = {"ADF_Weapons\adfrc_weaponbox\data\ADFRC_weaponbox_co.paa","ADF_Weapons\adfrc_weaponbox\data\labels_m4a5_ca.paa"};
		class TransportWeapons
		{
			class _xx_ADFRC_HK416_556_115
			{
				weapon = "ADFRC_HK416_556_115";
				count = 5;
			};
			class _xx_ADFRC_HK416_556_145
			{
				weapon = "ADFRC_HK416_556_145";
				count = 5;
			};
			class _xx_ADFRC_M4A5_Classic_556
			{
				weapon = "ADFRC_M4A5_Classic_556";
				count = 5;
			};
			class _xx_ADFRC_M4A5_KAC_556
			{
				weapon = "ADFRC_M4A5_KAC_556";
				count = 5;
			};
			class _xx_ADFRC_M4A5_KAC_556_CTR
			{
				weapon = "ADFRC_M4A5_KAC_556_CTR";
				count = 5;
			};
			class _xx_ADFRC_M4A5_KAC_NOFS_556_CTR
			{
				weapon = "ADFRC_M4A5_KAC_NOFS_556_CTR";
				count = 5;
			};
			class _xx_ADFRC_M4A5_KAC_NOFS_556
			{
				weapon = "ADFRC_M4A5_KAC_NOFS_556";
				count = 5;
			};
			class _xx_ADFRC_M4A5_Troy_556_14_BLK
			{
				weapon = "ADFRC_M4A5_Troy_556_14_BLK";
				count = 5;
			};
			class _xx_ADFRC_M4A5_Troy_556_14_FDE_CTR
			{
				weapon = "ADFRC_M4A5_Troy_556_14_FDE_CTR";
				count = 5;
			};
			class _xx_ADFRC_M4A5_Troy_556_14_BLK_CTR
			{
				weapon = "ADFRC_M4A5_Troy_556_14_BLK_CTR";
				count = 5;
			};
			class _xx_ADFRC_M4A5_Troy_556_14
			{
				weapon = "ADFRC_M4A5_Troy_556_14";
				count = 5;
			};
			class _xx_ADFRC_M4A5_KAC_M203_556
			{
				weapon = "ADFRC_M4A5_KAC_M203_556";
				count = 5;
			};
			class _xx_ADFRC_M4A5_KAC_M203_556_CTR
			{
				weapon = "ADFRC_M4A5_KAC_M203_556_CTR";
				count = 5;
			};
			class _xx_ADFRC_M4A5_Combo_556_10_BLK
			{
				weapon = "ADFRC_M4A5_Combo_556_10_BLK";
				count = 5;
			};
			class _xx_ADFRC_M4A5_Combo_556_10_FDE
			{
				weapon = "ADFRC_M4A5_Combo_556_10_FDE";
				count = 5;
			};
			class _xx_ADFRC_M4A5_Combo_556_14_BLK
			{
				weapon = "ADFRC_M4A5_Combo_556_14_BLK";
				count = 5;
			};
			class _xx_ADFRC_M4A5_Combo_556_14_FDE
			{
				weapon = "ADFRC_M4A5_Combo_556_14_FDE";
				count = 5;
			};
		};
		class TransportMagazines
		{
			class _xx_30Rnd_556x45_Stanag
			{
				magazine = "30Rnd_556x45_Stanag";
				count = 100;
			};
			class _xx_30Rnd_556x45_Stanag_Tracer_Red
			{
				magazine = "30Rnd_556x45_Stanag_Tracer_Red";
				count = 30;
			};
			class _xx_30Rnd_556x45_Stanag_Tracer_Green
			{
				magazine = "30Rnd_556x45_Stanag_Tracer_Green";
				count = 30;
			};
			class _xx_30Rnd_556x45_Stanag_Tracer_Yellow
			{
				magazine = "30Rnd_556x45_Stanag_Tracer_Yellow";
				count = 30;
			};
			class _xx_ADFRC_30Rnd_STANAG
			{
				magazine = "ADFRC_30Rnd_STANAG";
				count = 100;
			};
			class _xx_ADFRC_30Rnd_STANAG_TR
			{
				magazine = "ADFRC_30Rnd_STANAG_TR";
				count = 100;
			};
			class _xx_ADFRC_30Rnd_STANAG_TG
			{
				magazine = "ADFRC_30Rnd_STANAG_TG";
				count = 100;
			};
			class _xx_ADFRC_30Rnd_STANAG_TY
			{
				magazine = "ADFRC_30Rnd_STANAG_TY";
				count = 100;
			};
			class _xx_ADFRC_30Rnd_STANAG_IR
			{
				magazine = "ADFRC_30Rnd_STANAG_IR";
				count = 100;
			};
			class _xx_ADFRC_30Rnd_STANAG_mixed
			{
				magazine = "ADFRC_30Rnd_STANAG_mixed";
				count = 100;
			};
			class _xx_ADFRC_30Rnd_PMAG
			{
				magazine = "ADFRC_30Rnd_PMAG";
				count = 100;
			};
			class _xx_ADFRC_30Rnd_PMAG_TR
			{
				magazine = "ADFRC_30Rnd_PMAG_TR";
				count = 100;
			};
			class _xx_ADFRC_30Rnd_PMAG_TG
			{
				magazine = "ADFRC_30Rnd_PMAG_TG";
				count = 100;
			};
			class _xx_ADFRC_30Rnd_PMAG_TY
			{
				magazine = "ADFRC_30Rnd_PMAG_TY";
				count = 100;
			};
			class _xx_ADFRC_30Rnd_PMAG_IR
			{
				magazine = "ADFRC_30Rnd_PMAG_IR";
				count = 100;
			};
			class _xx_ADFRC_30Rnd_PMAG_mixed
			{
				magazine = "ADFRC_30Rnd_PMAG_mixed";
				count = 100;
			};
			class _xx_1Rnd_HE_Grenade_Shell
			{
				magazine = "1Rnd_HE_Grenade_Shell";
				count = 100;
			};
		};
		class TransportItems
		{
			class _xx_ADFRC_KAC_NT4
			{
				name = "ADFRC_KAC_NT4";
				count = 30;
			};
			class _xx_ADFRC_SOCOM_556
			{
				name = "ADFRC_SOCOM_556";
				count = 30;
			};
			class _xx_ADFRC_WARCOMP_556
			{
				name = "ADFRC_WARCOMP_556";
				count = 30;
			};
			class _xx_ADFRC_WMLx_BLK_R_IR
			{
				name = "ADFRC_WMLx_BKL_R_IR";
				count = 30;
			};
			class _xx_ADFRC_WMLx_BLK_R_WL
			{
				name = "ADFRC_WMLx_BLK_R_WL";
				count = 30;
			};
			class _xx_ADFRC_PEQ15_BLK_IRL
			{
				name = "ADFRC_PEQ15_BLK_IRL";
				count = 30;
			};
			class _xx_ADFRC_PEQ15_BLK_IRT
			{
				name = "ADFRC_PEQ15_BLK_IRT";
				count = 30;
			};
			class _xx_ADFRC_PEQ15_FDE_IRL
			{
				name = "ADFRC_PEQ15_FDE_IRL";
				count = 30;
			};
			class _xx_ADFRC_PEQ15_FDE_IRT
			{
				name = "ADFRC_PEQ15_FDE_IRT";
				count = 30;
			};
			class _xx_ADFRC_PEQ15_M4_Top_BLK_IRL
			{
				name = "ADFRC_PEQ15_M4_Top_BLK_IRL";
				count = 30;
			};
			class _xx_ADFRC_PEQ15_M4_Top_BLK_IRT
			{
				name = "ADFRC_PEQ15_M4_Top_BLK_IRT";
				count = 30;
			};
			class _xx_ADFRC_PEQ15_M4_Top_FDE_IRL
			{
				name = "ADFRC_PEQ15_M4_Top_FDE_IRL";
				count = 30;
			};
			class _xx_ADFRC_PEQ15_M4_Top_FDE_IRT
			{
				name = "ADFRC_PEQ15_M4_Top_FDE_IRT";
				count = 30;
			};
		};
	};
	class ADFRC_weaponbox_f88: ADFRC_weaponbox_medium
	{
		scope = 2;
		displayName = "[ADF] Austeyr Box";
		author = "$STR_ADFRC_AUTHOR";
		hiddenSelections[] = {"Camo1","Camo2"};
		hiddenSelectionsTextures[] = {"ADF_Weapons\adfrc_weaponbox\data\ADFRC_weaponbox_co.paa","ADF_Weapons\adfrc_weaponbox\data\labels_aug_ca.paa"};
		class TransportWeapons
		{
			class _xx_ADFRC_F88
			{
				weapon = "ADFRC_F88";
				count = 5;
			};
			class _xx_ADFRC_F88SA1
			{
				weapon = "ADFRC_F88SA1";
				count = 5;
			};
			class _xx_ADFRC_F88SA1_gl
			{
				weapon = "ADFRC_F88SA1_gl";
				count = 5;
			};
			class _xx_ADFRC_f88sa2
			{
				weapon = "ADFRC_f88sa2";
				count = 5;
			};
			class _xx_ADFRC_f88sa2_gl
			{
				weapon = "ADFRC_f88sa2_gl";
				count = 5;
			};
			class _xx_ADFRC_EF88_Black
			{
				weapon = "ADFRC_EF88_Black";
				count = 5;
			};
			class _xx_ADFRC_EF88_Camo
			{
				weapon = "ADFRC_EF88_Camo";
				count = 5;
			};
			class _xx_ADFRC_EF88_SL40_Black
			{
				weapon = "ADFRC_EF88_SL40_Black";
				count = 5;
			};
			class _xx_ADFRC_EF88_SL40_Camo
			{
				weapon = "ADFRC_EF88_SL40_Camo";
				count = 5;
			};
			class _xx_ADFRC_EF88C_Black
			{
				weapon = "ADFRC_EF88C_Black";
				count = 5;
			};
			class _xx_ADFRC_EF88C_Camo
			{
				weapon = "ADFRC_EF88C_Camo";
				count = 5;
			};
		};
		class TransportMagazines
		{
			class _xx_ADFRC_30Rnd_aug
			{
				magazine = "ADFRC_30Rnd_aug";
				count = 100;
			};
			class _xx_ADFRC_30Rnd_aug_TR
			{
				magazine = "ADFRC_30Rnd_aug_TR";
				count = 30;
			};
			class _xx_ADFRC_30Rnd_aug_TY
			{
				magazine = "ADFRC_30Rnd_aug_TY";
				count = 30;
			};
			class _xx_ADFRC_30Rnd_aug_TG
			{
				magazine = "ADFRC_30Rnd_aug_TG";
				count = 30;
			};
			class _xx_ADFRC_30Rnd_aug_IR
			{
				magazine = "ADFRC_30Rnd_aug_IR";
				count = 30;
			};
			class _xx_ADFRC_30Rnd_aug_mixed
			{
				magazine = "ADFRC_30Rnd_aug_mixed";
				count = 30;
			};
			class _xx_ADFRC_30Rnd_aug_ef88
			{
				magazine = "ADFRC_30Rnd_aug_ef88";
				count = 100;
			};
			class _xx_ADFRC_30Rnd_aug_TR_ef88
			{
				magazine = "ADFRC_30Rnd_aug_TR_ef88";
				count = 30;
			};
			class _xx_ADFRC_30Rnd_aug_TY_ef88
			{
				magazine = "ADFRC_30Rnd_aug_TY_ef88";
				count = 30;
			};
			class _xx_ADFRC_30Rnd_aug_TG_ef88
			{
				magazine = "ADFRC_30Rnd_aug_TG_ef88";
				count = 30;
			};
			class _xx_ADFRC_30Rnd_aug_IR_ef88
			{
				magazine = "ADFRC_30Rnd_aug_IR_ef88";
				count = 30;
			};
			class _xx_ADFRC_30Rnd_aug_mixed_ef88
			{
				magazine = "ADFRC_30Rnd_aug_mixed_ef88";
				count = 30;
			};
			class _xx_1Rnd_HE_Grenade_Shell
			{
				magazine = "1Rnd_HE_Grenade_Shell";
				count = 50;
			};
		};
		class TransportItems
		{
			class _xx_ADFRC_f88_muzzle_snds
			{
				name = "ADFRC_f88_muzzle_snds";
				count = 20;
			};
			class _xx_ADFRC_f88_muzzle_snds_tan
			{
				name = "ADFRC_f88_muzzle_snds_tan";
				count = 20;
			};
			class _xx_ADFRC_WMLx_BLK_R_IR
			{
				name = "ADFRC_WMLx_BKL_R_IR";
				count = 20;
			};
			class _xx_ADFRC_WMLx_BLK_R_WL
			{
				name = "ADFRC_WMLx_BLK_R_WL";
				count = 20;
			};
			class _xx_ADFRC_L3Squad_IRL
			{
				name = "ADFRC_L3Squad_IRL";
				count = 20;
			};
			class _xx_ADFRC_L3Squad_IRT
			{
				name = "ADFRC_L3Squad_IRT";
				count = 20;
			};
			class _xx_ADFRC_L3Squad_EF88_Top_IRL
			{
				name = "ADFRC_L3Squad_EF88_Top_IRL";
				count = 20;
			};
			class _xx_ADFRC_L3Squad_EF88_Top_IRT
			{
				name = "ADFRC_L3Squad_EF88_Top_IRT";
				count = 20;
			};
		};
	};
	class ADFRC_weaponbox_mg: ADFRC_weaponbox_medium
	{
		scope = 2;
		displayName = "[ADF] Support Weapons";
		author = "$STR_ADFRC_AUTHOR";
		hiddenSelections[] = {"Camo1","Camo2"};
		hiddenSelectionsTextures[] = {"ADF_Weapons\adfrc_weaponbox\data\ADFRC_weaponbox_co.paa","ADF_Weapons\adfrc_weaponbox\data\ADFRC_weaponbox_signs_ca.paa"};
		class TransportWeapons
		{
			class _xx_ADFRC_maximi
			{
				weapon = "ADFRC_maximi";
				count = 5;
			};
			class _xx_ADFRC_maximi_Modern
			{
				weapon = "ADFRC_maximi_Modern";
				count = 5;
			};
			class _xx_ADFRC_maximi_Modern_Short
			{
				weapon = "ADFRC_maximi_Modern_Short";
				count = 5;
			};
			class _xx_ADFRC_maximi_Para
			{
				weapon = "ADFRC_maximi_Para";
				count = 5;
			};
			class _xx_ADFRC_maximi_Para_Short
			{
				weapon = "ADFRC_maximi_Para_Short";
				count = 5;
			};
			class _xx_ADFRC_F89_Minimi
			{
				weapon = "ADFRC_F89_Minimi";
				count = 5;
			};
			class _xx_ADFRC_F89_Minimi_Classic
			{
				weapon = "ADFRC_F89_Minimi_Classic";
				count = 5;
			};
			class _xx_ADFRC_F89_Minimi_Mod
			{
				weapon = "ADFRC_F89_Minimi_Mod";
				count = 5;
			};
			class _xx_ADFRC_F89_Minimi_Mod_S
			{
				weapon = "ADFRC_F89_Minimi_Mod_S";
				count = 5;
			};
			class _xx_ADFRC_F89_Minimi_Para
			{
				weapon = "ADFRC_F89_Minimi_Para";
				count = 5;
			};
			class _xx_ADFRC_F89_Minimi_Para_S
			{
				weapon = "ADFRC_F89_Minimi_Para_S";
				count = 5;
			};
			class _xx_ADFRC_mag58
			{
				weapon = "ADFRC_mag58";
				count = 5;
			};
		};
		class TransportMagazines
		{
			class _xx_ADFRC_100Rnd_556_Belt
			{
				magazine = "ADFRC_100Rnd_556_Belt";
				count = 25;
			};
			class _xx_ADFRC_100Rnd_556_Belt_TR
			{
				magazine = "ADFRC_100Rnd_556_Belt_TR";
				count = 25;
			};
			class _xx_ADFRC_100Rnd_556_Belt_TR5
			{
				magazine = "ADFRC_100Rnd_556_Belt_TR5";
				count = 25;
			};
			class _xx_ADFRC_200Rnd_556_Belt
			{
				magazine = "ADFRC_200Rnd_556_Belt";
				count = 25;
			};
			class _xx_ADFRC_200Rnd_556_Belt_TR
			{
				magazine = "ADFRC_200Rnd_556_Belt_TR";
				count = 25;
			};
			class _xx_ADFRC_200Rnd_556_Belt_TR5
			{
				magazine = "ADFRC_200Rnd_556_Belt_TR5";
				count = 25;
			};
			class _xx_ADFRC_100Rnd_556_Minimi
			{
				magazine = "ADFRC_100Rnd_556_Minimi";
				count = 25;
			};
			class _xx_ADFRC_100Rnd_556_Minimi_TR
			{
				magazine = "ADFRC_100Rnd_556_Minimi_TR";
				count = 25;
			};
			class _xx_ADFRC_100Rnd_556_Minimi_TR5
			{
				magazine = "ADFRC_100Rnd_556_Minimi_TR5";
				count = 25;
			};
			class _xx_ADFRC_200Rnd_556_Minimi
			{
				magazine = "ADFRC_200Rnd_556_Minimi";
				count = 25;
			};
			class _xx_ADFRC_200Rnd_556_Minimi_TR
			{
				magazine = "ADFRC_200Rnd_556_Minimi_TR";
				count = 25;
			};
			class _xx_ADFRC_200Rnd_556_Minimi_TR5
			{
				magazine = "ADFRC_200Rnd_556_Minimi_TR5";
				count = 25;
			};
			class _xx_ADFRC_250Rnd_556_Minimi
			{
				magazine = "ADFRC_250Rnd_556_Minimi";
				count = 25;
			};
			class _xx_ADFRC_250Rnd_556_Minimi_TR
			{
				magazine = "ADFRC_250Rnd_556_Minimi_TR";
				count = 25;
			};
			class _xx_ADFRC_250Rnd_556_Minimi_TR5
			{
				magazine = "ADFRC_250Rnd_556_Minimi_TR5";
				count = 25;
			};
			class _xx_ADFRC_50Rnd_762_Belt
			{
				magazine = "ADFRC_50Rnd_762_Belt";
				count = 25;
			};
			class _xx_ADFRC_50Rnd_762_Belt_TR
			{
				magazine = "ADFRC_50Rnd_762_Belt_TR";
				count = 25;
			};
			class _xx_ADFRC_50Rnd_762_Belt_TR5
			{
				magazine = "ADFRC_50Rnd_762_Belt_TR5";
				count = 25;
			};
			class _xx_ADFRC_100Rnd_762_Belt
			{
				magazine = "ADFRC_100Rnd_762_Belt";
				count = 25;
			};
			class _xx_ADFRC_100Rnd_762_Belt_TR
			{
				magazine = "ADFRC_100Rnd_762_Belt_TR";
				count = 25;
			};
			class _xx_ADFRC_100Rnd_762_Belt_TR5
			{
				magazine = "ADFRC_100Rnd_762_Belt_TR5";
				count = 25;
			};
			class _xx_ADFRC_100Rnd_762_Maximi
			{
				magazine = "ADFRC_100Rnd_762_Maximi";
				count = 25;
			};
			class _xx_ADFRC_100Rnd_762_Maximi_TR
			{
				magazine = "ADFRC_100Rnd_762_Maximi_TR";
				count = 25;
			};
			class _xx_ADFRC_100Rnd_762_Maximi_TR5
			{
				magazine = "ADFRC_100Rnd_762_Maximi_TR5";
				count = 25;
			};
			class _xx_ADFRC_150Rnd_762_Belt
			{
				magazine = "ADFRC_150Rnd_762_Belt";
				count = 25;
			};
			class _xx_ADFRC_150Rnd_762_Belt_TR
			{
				magazine = "ADFRC_150Rnd_762_Belt_TR";
				count = 25;
			};
			class _xx_ADFRC_150Rnd_762_Belt_TR5
			{
				magazine = "ADFRC_150Rnd_762_Belt_TR5";
				count = 25;
			};
		};
		class TransportItems
		{
			class _xx_ADFRC_elcan_c79
			{
				name = "ADFRC_elcan_c79";
				count = 10;
			};
			class _xx_ADFRC_swarovski_optic
			{
				name = "ADFRC_swarovski_optic";
				count = 10;
			};
			class _xx_ADFRC_swarovski_optic_SA2
			{
				name = "ADFRC_swarovski_optic_SA2";
				count = 10;
			};
			class _xx_ADFRC_eotech552
			{
				name = "ADFRC_eotech552";
				count = 10;
			};
		};
	};
	class ADFRC_weaponbox_sr25: ADFRC_weaponbox_medium
	{
		scope = 2;
		displayName = "[ADF] DMR Box";
		author = "$STR_ADFRC_AUTHOR";
		hiddenSelections[] = {"Camo1","Camo2"};
		hiddenSelectionsTextures[] = {"ADF_Weapons\adfrc_weaponbox\data\ADFRC_weaponbox_co.paa","ADF_Weapons\adfrc_weaponbox\data\labels_sr25_ca.paa"};
		class TransportWeapons
		{
			class _xx_ADFRC_sr25
			{
				weapon = "ADFRC_sr25";
				count = 10;
			};
			class _xx_ADFRC_sr25E2
			{
				weapon = "ADFRC_sr25E2";
				count = 10;
			};
			class _xx_ADFRC_HK417_Black
			{
				weapon = "ADFRC_HK417_Black"
				count = 10;
			};
		};
		class TransportMagazines
		{
			class _xx_20Rnd_762x51_Mag
			{
				magazine = "20Rnd_762x51_Mag";
				count = 50;
			};
			class _xx_ADFRC_20RD_PMAG_F4
			{
				magazine = "ADFRC_20RD_PMAG_F4";
				count = 50;
			};
			class _xx_ADFRC_20RD_PMAG_M
			{
				magazine = "ADFRC_20RD_PMAG_M";
				count = 50;
			};
			class _xx_ADFRC_20RD_SR25_F4
			{
				magazine = "ADFRC_20RD_SR25_F4";
				count = 50;
			};
			class _xx_ADFRC_20RD_SR25_M
			{
				magazine = "ADFRC_20RD_SR25_M";
				count = 50;
			};
			class _xx_ADFRC_20RD_HK417_F4
			{
				magazine = "ADFRC_20RD_HK417_F4";
				count = 50;
			};
			class _xx_ADFRC_20RD_HK417_M
			{
				magazine = "ADFRC_20RD_HK417_M";
				count = 50;
			};
		};
		class TransportItems
		{
			class _xx_ADFRC_KAC_PRG
			{
				name = "ADFRC_KAC_PRG";
				count = 20;
			};
			class _xx_muzzle_snds_B
			{
				name = "muzzle_snds_B";
				count = 20;
			};
			class _xx_ADFRC_Atlas_BT10
			{
				name = "ADFRC_Atlas_BT10";
				count = 20;
			};
			class _xx_ADFRC_Harris
			{
				name = "ADFRC_Harris";
				count = 20;
			};
		};
	};
	class ADFRC_weaponbox_amp: ADFRC_weaponbox_large
	{
		scope = 2;
		vehicleClass = "Ammo";
		author = "$STR_ADFRC_AUTHOR";
		displayName = "[ADF] Uniforms AMP";
		icon = "icon_ADFRC_uniform";
		maximumLoad = 99999;
		transportMaxWeapons = 15000;
		transportMaxMagazines = 20000;
		transportMaxBackpacks = 50;
		weight = 1000;
		class TransportWeapons{};
		class TransportMagazines{};
		class TransportItems
		{
			/*class _xx_ADFRC_PlateCarrier_Black
			{
				name = "ADFRC_PlateCarrier_Black";
				count = 20;
			};
			class _xx_ADFRC_PlateCarrier_Sand
			{
				name = "ADFRC_PlateCarrier_Sand";
				count = 20;
			};
			class _xx_ADFRC_PlateCarrier_Green
			{
				name = "ADFRC_PlateCarrier_Green";
				count = 20;
			};
			class _xx_ADFRC_PlateCarrier_AMP
			{
				name = "ADFRC_PlateCarrier_AMP";
				count = 20;
			};
			class _xx_ADFRC_PlateCarrier_Black_Snake
			{
				name = "ADFRC_PlateCarrier_Black_Snake";
				count = 20;
			};
			class _xx_ADFRC_PlateCarrier_Sand_Snake
			{
				name = "ADFRC_PlateCarrier_Sand_Snake";
				count = 20;
			};
			class _xx_ADFRC_PlateCarrier_Green_Snake
			{
				name = "ADFRC_PlateCarrier_Green_Snake";
				count = 20;
			};
			class _xx_ADFRC_PlateCarrier_Black_Digi
			{
				name = "ADFRC_PlateCarrier_Black_Digi";
				count = 20;
			};
			class _xx_ADFRC_PlateCarrier_Sand_Digi
			{
				name = "ADFRC_PlateCarrier_Sand_Digi";
				count = 20;
			};
			class _xx_ADFRC_PlateCarrier_Green_Digi
			{
				name = "ADFRC_PlateCarrier_Green_Digi";
				count = 20;
			};
			class _xx_ADFRC_CarrierLite_Black
			{
				name = "ADFRC_CarrierLite_Black";
				count = 20;
			};
			class _xx_ADFRC_CarrierLite_Sand
			{
				name = "ADFRC_CarrierLite_Sand";
				count = 20;
			};
			class _xx_ADFRC_CarrierLite_Green
			{
				name = "ADFRC_CarrierLite_Green";
				count = 20;
			};
			class _xx_ADFRC_CarrierLite_AMP
			{
				name = "ADFRC_CarrierLite_AMP";
				count = 20;
			};
			class _xx_ADFRC_CarrierLite_Black_Snake
			{
				name = "ADFRC_CarrierLite_Black_Snake";
				count = 20;
			};
			class _xx_ADFRC_CarrierLite_Sand_Snake
			{
				name = "ADFRC_CarrierLite_Sand_Snake";
				count = 20;
			};
			class _xx_ADFRC_CarrierLite_Green_Snake
			{
				name = "ADFRC_CarrierLite_Green_Snake";
				count = 20;
			};
			class _xx_ADFRC_CarrierLite_Black_Digi
			{
				name = "ADFRC_CarrierLite_Black_Digi";
				count = 20;
			};
			class _xx_ADFRC_CarrierLite_Sand_Digi
			{
				name = "ADFRC_CarrierLite_Sand_Digi";
				count = 20;
			};
			class _xx_ADFRC_CarrierLite_Green_Digi
			{
				name = "ADFRC_CarrierLite_Green_Digi";
				count = 20;
			};
			class _xx_ADFRC_CarrierHeavy_Black
			{
				name = "ADFRC_CarrierHeavy_Black";
				count = 20;
			};
			class _xx_ADFRC_CarrierHeavy_Sand
			{
				name = "ADFRC_CarrierHeavy_Sand";
				count = 20;
			};
			class _xx_ADFRC_CarrierHeavy_Green
			{
				name = "ADFRC_CarrierHeavy_Green";
				count = 20;
			};
			class _xx_ADFRC_CarrierHeavy_AMP
			{
				name = "ADFRC_CarrierHeavy_AMP";
				count = 20;
			};
			class _xx_ADFRC_CarrierHeavy_Black_Snake
			{
				name = "ADFRC_CarrierHeavy_Black_Snake";
				count = 20;
			};
			class _xx_ADFRC_CarrierHeavy_Sand_Snake
			{
				name = "ADFRC_CarrierHeavy_Sand_Snake";
				count = 20;
			};
			class _xx_ADFRC_CarrierHeavy_Green_Snake
			{
				name = "ADFRC_CarrierHeavy_Green_Snake";
				count = 20;
			};
			class _xx_ADFRC_CarrierHeavy_Black_Digi
			{
				name = "ADFRC_CarrierHeavy_Black_Digi";
				count = 20;
			};
			class _xx_ADFRC_CarrierHeavy_Sand_Digi
			{
				name = "ADFRC_CarrierHeavy_Sand_Digi";
				count = 20;
			};
			class _xx_ADFRC_CarrierHeavy_Green_Digi
			{
				name = "ADFRC_CarrierHeavy_Green_Digi";
				count = 20;
			};
			class _xx_ADFRC_PlateCarrier_BLACK_MEDIC
			{
				name = "ADFRC_PlateCarrier_BLACK_MEDIC";
				count = 20;
			};
			class _xx_ADFRC_PlateCarrier_GREEN_MEDIC
			{
				name = "ADFRC_PlateCarrier_GREEN_MEDIC";
				count = 20;
			};
			class _xx_ADFRC_PlateCarrier_SAND_MEDIC
			{
				name = "ADFRC_PlateCarrier_SAND_MEDIC";
				count = 20;
			};
			class _xx_ADFRC_booniehat_amp
			{
				name = "ADFRC_booniehat_amp";
				count = 20;
			};
			class _xx_ADFRC_cap_tan
			{
				name = "ADFRC_cap_tan";
				count = 20;
			};
			class _xx_ADFRC_cap_green
			{
				name = "ADFRC_cap_green";
				count = 20;
			};
			class _xx_ADFRC_cap_black
			{
				name = "ADFRC_cap_black";
				count = 20;
			};
			class _xx_ADFRC_cap_amp
			{
				name = "ADFRC_cap_amp";
				count = 20;
			};
			class _xx_ADFRC_Helmet_Black
			{
				name = "ADFRC_Helmet_Black";
				count = 20;
			};
			class _xx_ADFRC_Helmet_Desert
			{
				name = "ADFRC_Helmet_Desert";
				count = 20;
			};
			class _xx_ADFRC_Helmet_Grass
			{
				name = "ADFRC_Helmet_Grass";
				count = 20;
			};
			class _xx_ADFRC_Helmet_Sand
			{
				name = "ADFRC_Helmet_Sand";
				count = 20;
			};
			class _xx_ADFRC_Helmet_Snake
			{
				name = "ADFRC_Helmet_Snake";
				count = 20;
			};
			class _xx_ADFRC_Helmet_CamInk
			{
				name = "ADFRC_Helmet_CamInk";
				count = 20;
			};
			class _xx_ADFRC_Helmet_Cam
			{
				name = "ADFRC_Helmet_Cam";
				count = 20;
			};
			class _xx_ADFRC_Helmet_Medic_Black
			{
				name = "ADFRC_Helmet_Medic_Black";
				count = 20;
			};
			class _xx_ADFRC_Helmet_Medic_Desert
			{
				name = "ADFRC_Helmet_Medic_Desert";
				count = 20;
			};
			class _xx_ADFRC_Helmet_Medic_Grass
			{
				name = "ADFRC_Helmet_Medic_Grass";
				count = 20;
			};
			class _xx_ADFRC_Helmet_Medic_Sand
			{
				name = "ADFRC_Helmet_Medic_Sand";
				count = 20;
			};
			class _xx_ADFRC_Helmet_Medic_Snake
			{
				name = "ADFRC_Helmet_Medic_Snake";
				count = 20;
			};
			class _xx_ADFRC_Helmet_Medic_CamInk
			{
				name = "ADFRC_Helmet_Medic_CamInk";
				count = 20;
			};
			class _xx_ADFRC_Helmet_Medic_Cam
			{
				name = "ADFRC_Helmet_Medic_Cam";
				count = 20;
			};
			class _xx_ADFRC_ECH_Desert
			{
				name = "ADFRC_ECH_Desert";
				count = 20;
			};
			class _xx_ADFRC_ECH_Grass
			{
				name = "ADFRC_ECH_Grass";
				count = 20;
			};
			class _xx_ADFRC_ECH_Sand
			{
				name = "ADFRC_ECH_Sand";
				count = 20;
			};
			class _xx_ADFRC_ECH_Snake
			{
				name = "ADFRC_ECH_Snake";
				count = 20;
			};
			class _xx_ADFRC_ECH_CamInk
			{
				name = "ADFRC_ECH_CamInk";
				count = 20;
			};
			class _xx_ADFRC_ECH_Cam
			{
				name = "ADFRC_ECH_Cam";
				count = 20;
			};
			class _xx_ADFRC_ECH_MEDIC_Desert
			{
				name = "ADFRC_ECH_MEDIC_Desert";
				count = 20;
			};
			class _xx_ADFRC_ECH_MEDIC_Grass
			{
				name = "ADFRC_ECH_MEDIC_Grass";
				count = 20;
			};
			class _xx_ADFRC_ECH_MEDIC_Sand
			{
				name = "ADFRC_ECH_MEDIC_Sand";
				count = 20;
			};
			class _xx_ADFRC_ECH_MEDIC_Snake
			{
				name = "ADFRC_ECH_MEDIC_Snake";
				count = 20;
			};
			class _xx_ADFRC_ECH_MEDIC_CamInk
			{
				name = "ADFRC_ECH_MEDIC_CamInk";
				count = 20;
			};
			class _xx_ADFRC_ECH_MEDIC_Cam
			{
				name = "ADFRC_ECH_MEDIC_Cam";
				count = 20;
			};
			class _xx_ADFRC_assaultpack_black
			{
				name = "ADFRC_assaultpack_black";
				count = 20;
			};
			class _xx_ADFRC_assaultpack_green
			{
				name = "ADFRC_assaultpack_green";
				count = 20;
			};
			class _xx_ADFRC_assaultpack_tan
			{
				name = "ADFRC_assaultpack_tan";
				count = 20;
			};
			class _xx_ADFRC_assaultpack_amp
			{
				name = "ADFRC_assaultpack_amp";
				count = 20;
			};
			class _xx_ADFRC_assaultpack_black_medic
			{
				name = "ADFRC_assaultpack_black_medic";
				count = 20;
			};
			class _xx_ADFRC_assaultpack_green_medic
			{
				name = "ADFRC_assaultpack_green_medic";
				count = 20;
			};
			class _xx_ADFRC_assaultpack_tan_medic
			{
				name = "ADFRC_assaultpack_tan_medic";
				count = 20;
			};
			class _xx_ADFRC_assaultpack_amp_medic
			{
				name = "ADFRC_assaultpack_amp_medic";
				count = 20;
			};
			class _xx_ADFRC_kitbag_black
			{
				name = "ADFRC_kitbag_black";
				count = 20;
			};
			class _xx_ADFRC_kitbag_green
			{
				name = "ADFRC_kitbag_green";
				count = 20;
			};
			class _xx_ADFRC_kitbag_tan
			{
				name = "ADFRC_kitbag_tan";
				count = 20;
			};
			class _xx_ADFRC_kitbag_amp
			{
				name = "ADFRC_kitbag_amp";
				count = 20;
			};
			class _xx_ADFRC_kitbag_black_medic
			{
				name = "ADFRC_kitbag_black_medic";
				count = 20;
			};
			class _xx_ADFRC_kitbag_green_medic
			{
				name = "ADFRC_kitbag_green_medic";
				count = 20;
			};
			class _xx_ADFRC_kitbag_tan_medic
			{
				name = "ADFRC_kitbag_tan_medic";
				count = 20;
			};
			class _xx_ADFRC_kitbag_amp_medic
			{
				name = "ADFRC_kitbag_amp_medic";
				count = 20;
			};
			class _xx_ADFRC_carryall_black
			{
				name = "ADFRC_carryall_black";
				count = 20;
			};
			class _xx_ADFRC_carryall_green
			{
				name = "ADFRC_carryall_green";
				count = 20;
			};
			class _xx_ADFRC_carryall_tan
			{
				name = "ADFRC_carryall_tan";
				count = 20;
			};
			class _xx_ADFRC_carryall_amp
			{
				name = "ADFRC_carryall_amp";
				count = 20;
			};
			class _xx_ADFRC_carryall_black_medic
			{
				name = "ADFRC_carryall_black_medic";
				count = 20;
			};
			class _xx_ADFRC_carryall_green_medic
			{
				name = "ADFRC_carryall_green_medic";
				count = 20;
			};
			class _xx_ADFRC_carryall_tan_medic
			{
				name = "ADFRC_carryall_tan_medic";
				count = 20;
			};
			class _xx_ADFRC_carryall_amp_medic
			{
				name = "ADFRC_carryall_amp_medic";
				count = 20;
			};
			class _xx_ADFRC_uniform_amp_cam
			{
				name = "ADFRC_uniform_amp_cam";
				count = 20;
			};
			class _xx_ADFRC_uniform_amp_grn
			{
				name = "ADFRC_uniform_amp_grn";
				count = 20;
			};
			class _xx_ADFRC_uniform_amp_tan
			{
				name = "ADFRC_uniform_amp_tan";
				count = 20;
			};
			class _xx_ADFRC_uniform_amp_cam_ss
			{
				name = "ADFRC_uniform_amp_cam_ss";
				count = 20;
			};
			class _xx_ADFRC_uniform_amp_grn_ss
			{
				name = "ADFRC_uniform_amp_grn_ss";
				count = 20;
			};
			class _xx_ADFRC_uniform_amp_tan_ss
			{
				name = "ADFRC_uniform_amp_tan_ss";
				count = 20;
			};
			class _xx_ADFRC_uniform_amp_tee_grn
			{
				name = "ADFRC_uniform_amp_tee_grn";
				count = 20;
			};
			class _xx_ADFRC_uniform_amp_tee_tan
			{
				name = "ADFRC_uniform_amp_tee_tan";
				count = 20;
			};
			class _xx_ADFRC_uniform_amp_tee_khk
			{
				name = "ADFRC_uniform_amp_tee_khk";
				count = 20;
			};
			class _xx_ADFRC_coveralls_black
			{
				name = "ADFRC_coveralls_black";
				count = 20;
			};
			class _xx_ADFRC_coveralls_green
			{
				name = "ADFRC_coveralls_green";
				count = 20;
			};
			class _xx_ADFRC_coveralls_tan
			{
				name = "ADFRC_coveralls_tan";
				count = 20;
			};*/
		};
	};
	class ADFRC_weaponbox_dpcu: ADFRC_weaponbox_large
	{
		scope = 2;
		vehicleClass = "Ammo";
		author = "$STR_ADFRC_AUTHOR";
		displayName = "[ADF] Uniforms DPCU";
		icon = "icon_ADFRC_uniform";
		maximumLoad = 99999;
		transportMaxWeapons = 15000;
		transportMaxMagazines = 20000;
		transportMaxBackpacks = 50;
		weight = 1000;
		class TransportWeapons{};
		class TransportMagazines{};
		class TransportItems
		{
			/*class _xx_ADFRC_carrierLite_dpcu
			{
				name = "ADFRC_carrierLite_dpcu";
				count = 20;
			};
			class _xx_ADFRC_plateCarrier_dpcu
			{
				name = "ADFRC_plateCarrier_dpcu";
				count = 20;
			};
			class _xx_ADFRC_tacticalVest_dpcu
			{
				name = "ADFRC_tacticalVest_dpcu";
				count = 20;
			};
			class _xx_ADFRC_HelmetC_dpcu
			{
				name = "ADFRC_HelmetC_dpcu";
				count = 20;
			};
			class _xx_ADFRC_helmetB_dpcu
			{
				name = "ADFRC_helmetB_dpcu";
				count = 20;
			};
			class _xx_ADFRC_booniehat_dpcu
			{
				name = "ADFRC_booniehat_dpcu";
				count = 20;
			};
			class _xx_ADFRC_AssaultPack_dpcu
			{
				name = "ADFRC_AssaultPack_dpcu";
				count = 20;
			};
			class _xx_ADFRC_Carryall_dpcu
			{
				name = "ADFRC_Carryall_dpcu";
				count = 20;
			};
			class _xx_ADFRC_Carryall_dpcu_diver
			{
				name = "ADFRC_Carryall_dpcu_diver";
				count = 20;
			};
			class _xx_ADFRC_Carryall_dpcu_medic
			{
				name = "ADFRC_Carryall_dpcu_medic";
				count = 20;
			};
			class _xx_ADFRC_Carryall_dpcu_engineer
			{
				name = "ADFRC_Carryall_dpcu_engineer";
				count = 20;
			};
			class _xx_ADFRC_Carryall_dpcu_at
			{
				name = "ADFRC_Carryall_dpcu_at";
				count = 20;
			};
			class _xx_ADFRC_uniform_dpcu
			{
				name = "ADFRC_uniform_dpcu";
				count = 20;
			};
			class _xx_ADFRC_uniform_dpcu_recon
			{
				name = "ADFRC_uniform_dpcu_recon";
				count = 20;
			};
			class _xx_ADFRC_uniform_dpcu_medic
			{
				name = "ADFRC_uniform_dpcu_medic";
				count = 20;
			};
			class _xx_ADFRC_uniform_dpcu_tee
			{
				name = "ADFRC_uniform_dpcu_tee";
				count = 20;
			};
			class _xx_ADFRC_coveralls_dpcu
			{
				name = "ADFRC_coveralls_dpcu";
				count = 20;
			};*/
		};
	};
	class ADFRC_weaponbox_dpdu: ADFRC_weaponbox_large
	{
		scope = 2;
		vehicleClass = "Ammo";
		author = "$STR_ADFRC_AUTHOR";
		displayName = "[ADF] Uniforms DPDU";
		icon = "icon_ADFRC_uniform";
		maximumLoad = 99999;
		transportMaxWeapons = 15000;
		transportMaxMagazines = 20000;
		transportMaxBackpacks = 50;
		weight = 1000;
		class TransportWeapons{};
		class TransportMagazines{};
		class TransportItems
		{
			/*class _xx_ADFRC_carrierlite_dpdu
			{
				name = "ADFRC_carrierlite_dpdu";
				count = 20;
			};
			class _xx_ADFRC_tacticalvest_dpdu
			{
				name = "ADFRC_tacticalvest_dpdu";
				count = 20;
			};
			class _xx_ADFRC_booniehat_dpdu
			{
				name = "ADFRC_booniehat_dpdu";
				count = 20;
			};
			class _xx_ADFRC_helmetB_dpdu
			{
				name = "ADFRC_helmetB_dpdu";
				count = 20;
			};
			class _xx_ADFRC_carryall_dpdu
			{
				name = "ADFRC_carryall_dpdu";
				count = 20;
			};
			class _xx_ADFRC_carryall_dpdu_medic
			{
				name = "ADFRC_carryall_dpdu_medic";
				count = 20;
			};
			class _xx_ADFRC_carryall_dpdu_engineer
			{
				name = "ADFRC_carryall_dpdu_engineer";
				count = 20;
			};
			class _xx_ADFRC_carryall_dpdu_at
			{
				name = "ADFRC_carryall_dpdu_at";
				count = 20;
			};
			class _xx_ADFRC_uniform_dpdu
			{
				name = "ADFRC_uniform_dpdu";
				count = 20;
			};
			class _xx_ADFRC_uniform_dpdu_medic
			{
				name = "ADFRC_uniform_dpdu_medic";
				count = 20;
			};
			class _xx_ADFRC_uniform_dpdu_recon
			{
				name = "ADFRC_uniform_dpdu_recon";
				count = 20;
			};
			class _xx_ADFRC_uniform_dpdu_pilot
			{
				name = "ADFRC_uniform_dpdu_pilot";
				count = 20;
			};*/
		};
	};
};
