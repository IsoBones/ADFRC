class CfgPatches
{
	class ADF_Optics
	{
		units[]={};
		weapons[]=
		{
			"ADFRC_swarovski_optic",
			"ADFRC_elcan_c79",
			"ADFRC_acog_ta648",
			"ADFRC_acog_ta648_rds",
			"ADFRC_acog_ta648_t",
			"ADFRC_acog_ta648_rds_t",
			"ADFRC_acog_ta31",
			"ADFRC_acog_ta31_t",
			"ADFRC_eotech552",
			"ADFRC_eotech552_3XDOWN",
			"ADFRC_eotech552_3XUP",
			"ADFRC_MicroT2"
		};
		requiredVersion=1;
		requiredAddons[]=
		{
			"ADF_Core",
			"A3_Weapons_F",
			"A3_Weapons_F_Acc"
		};
	};
};

#include "Optics_JR.hpp"

class CBA_PIPItems
{
	ADFRC_Specter_RAR = "ADFRC_Specter_RAR_pip";
};
class cfgWeapons
{
	class SlotInfo;
	class ItemCore;
	class InventoryOpticsItem_Base_F;
	class InventoryFlashLightItem_Base_F;
	class InventoryMuzzleItem_Base_F;
	class muzzle_snds_M;
	
	#include "T2\T2.hpp"
	#include "EXPS3\EXPS3.hpp"
	#include "DPP\DPP.hpp"
	#include "PRO\Aimpoint_PRO.hpp"
	#include "Romeo2\Romeo2.hpp"
	#include "Spectr\Spectr.hpp"
	#include "TA31\TA31.hpp"
	#include "TA648\TA648.hpp"
	class ADFRC_swarovski_optic: ItemCore
	{
		scope=2;
		displayName="Swarovski CQB Optic";
		author="Quiggs & Brucey";
		picture="\ADF_Optics\Swaro\ui\SMAV_CA.paa";
		model="\ADF_Optics\Swaro\ADFRC_SWAV.p3d";
		descriptionShort="1.5x Swarovski Rifle Optic &lt;br/&gt; Rail Mounted AUG A1 Optics";
		weaponInfoType="RscWeaponZeroing";
		class ItemInfo: InventoryOpticsItem_Base_F
		{
			mass=10;
			weaponInfoType="RscWeaponRangeZeroingFOV";
			modelOptics = "\A3\Weapons_F\empty";
			optics=1;
			class OpticsModes
			{
				class Snip
				{
					opticsID=1;
					opticsDisplayName="OPTIC";
					useModelOptics=0;
					opticsPPEffects[]=
					{
						""
					};
					opticsZoomMin = "1.5 call (uiNamespace getVariable 'cba_optics_fnc_setOpticMagnificationHelper')";
					opticsZoomMax = "1.5 call (uiNamespace getVariable 'cba_optics_fnc_setOpticMagnificationHelper')";
					opticsZoomInit = "1.5 call (uiNamespace getVariable 'cba_optics_fnc_setOpticMagnificationHelper')";
					discreteDistance[]={25,50,100,200,300,400,500};
					discreteDistanceInitIndex=3;
					distanceZoomMin=300;
					distanceZoomMax=300;
					discreteInitIndex=0;
					memoryPointCamera="opticView";
					visionMode[]=
					{
						"Normal"
					};
					opticsFlare=1;
					opticsDisablePeripherialVision=1;
				};
				class Iron: Snip
				{
					opticsID=2;
					opticsDisplayName="";
					useModelOptics=0;
					opticsFlare=0;
					opticsDisablePeripherialVision=0;
					opticsZoomMin=0.375;
					opticsZoomMax=1.1;
					opticsZoomInit=0.75;
					memoryPointCamera="eye";
					visionMode[]={};
					discretefov[]={};
					discreteDistance[]={100};
					discreteDistanceInitIndex=0;
				};
			};
		};
	};
	
	class ADFRC_swarovski_optic_SA2: ItemCore
	{
		scope=2;
		displayName="Swarovski CQB Optic (SA2)";
		author="Quiggs & Brucey";
		picture="\ADF_Optics\Swaro\ui\SMAV_SA2_CA.paa";
		model="\ADF_Optics\Swaro\ADFRC_SWAV_SA2.p3d";
		descriptionShort="1.5x Swarovski Rifle Optic &lt;br/&gt; Rail Mounted AUG A1 Optics";
		weaponInfoType="RscWeaponZeroing";
		class ItemInfo: InventoryOpticsItem_Base_F
		{
			mass=11;
			weaponInfoType="RscWeaponRangeZeroingFOV";
			modelOptics = "\A3\Weapons_F\empty";
			optics=1;
			class OpticsModes
			{
				class Snip
				{
					opticsID=1;
					opticsDisplayName="OPTIC";
					useModelOptics=0;
					opticsPPEffects[]=
					{
						""
					};
					opticsZoomMin = "1.5 call (uiNamespace getVariable 'cba_optics_fnc_setOpticMagnificationHelper')";
					opticsZoomMax = "1.5 call (uiNamespace getVariable 'cba_optics_fnc_setOpticMagnificationHelper')";
					opticsZoomInit = "1.5 call (uiNamespace getVariable 'cba_optics_fnc_setOpticMagnificationHelper')";
					discreteDistance[]={25,50,100,200,300,400,500};
					discreteDistanceInitIndex=3;
					distanceZoomMin=300;
					distanceZoomMax=300;
					discreteInitIndex=0;
					memoryPointCamera="opticView";
					visionMode[]=
					{
						"Normal"
					};
					opticsFlare=1;
					opticsDisablePeripherialVision=1;
				};
				class Iron: Snip
				{
					opticsID=2;
					opticsDisplayName="";
					useModelOptics=0;
					opticsFlare=0;
					opticsDisablePeripherialVision=0;
					opticsZoomMin=0.375;
					opticsZoomMax=1.1;
					opticsZoomInit=0.75;
					memoryPointCamera="eye";
					visionMode[]={};
					discretefov[]={};
					discreteDistance[]={100};
					discreteDistanceInitIndex=0;
				};
			};
		};
	};
	class ADFRC_elcan_c79: ItemCore
	{
		scope=2;
		displayName="Elcan C79";
		author="$STR_ADF_AUTHOR";
		picture="\ADF_Optics\ui\optic_elcan_ca.paa";
		model="\ADF_Optics\C79\ADFRC_C79.p3d";
		descriptionShort="3.4x Battle Sight &lt;br/&gt; SpecterOS3.4x";
		
		
		class CBA_ScriptedOptic {
            reticleTexture = "\ADF_Optics\C79\Textures\ADRC_C79_Ret_CA.paa";
            reticleTextureSize = 1;

            bodyTexture = "\ADF_Optics\C79\Textures\ScopeBody_D_ca.paa";
            bodyTextureNight = "\ADF_Optics\C79\Textures\ScopeBody_N_ca.paa";
			bodyTextureSize = 1.15;
        };
        weaponInfoType = "CBA_ScriptedOptic";
		
		class ItemInfo : InventoryOpticsItem_Base_F {
			opticType = 2;
			mass = 15;
			RMBhint = "3.4x Battle Sight";
			optics = true;
			modelOptics = "\x\cba\addons\optics\cba_optic_small_pip.p3d";

			class OpticsModes {
				class Snip {
					opticsID = 1;
					opticsDisplayName = WFOV;
					useModelOptics = 1;
					opticsPPEffects[] = {"OpticsCHAbera1", "OpticsBlur1"};
					opticsZoomMin = "3.4 call (uiNamespace getVariable 'cba_optics_fnc_setOpticMagnificationHelper')";
					opticsZoomMax = "3.4 call (uiNamespace getVariable 'cba_optics_fnc_setOpticMagnificationHelper')";
					opticsZoomInit = "3.4 call (uiNamespace getVariable 'cba_optics_fnc_setOpticMagnificationHelper')";
					discreteDistance[]={50,100,200,300,400,500};
					discreteDistanceInitIndex=2;
					distanceZoomMin = 100;
					distanceZoomMax = 100;
					memoryPointCamera = "opticView";
					visionMode[] = {"Normal"};
					opticsFlare = true;
					opticsDisablePeripherialVision = true;
					cameraDir = "";
				};
				class Irons
				{
					opticsID=1;
					useModelOptics=0;
					opticsPPEffects[]=
					{
						""
					};
					opticsZoomMin=0.375;
					opticsZoomMax=1.1;
					opticsZoomInit=0.75;
					memoryPointCamera="eye2";
					visionMode[]={};
					opticsFlare=0;
					opticsDisablePeripherialVision=0;
					distanceZoomMin=300;
					distanceZoomMax=300;
					cameraDir="";
				};
			};

		};
	};
	/// Original ACOGs
	class ADFRC_acog_ta31 : ADFRC_TA31_BLK
	{
		scope=1;
	};
	
	class ADFRC_acog_ta31_RDS: ADFRC_TA31_RMR_BLK
	{
		scope=1;
	};
	
	class ADFRC_acog_ta31_t: ADFRC_TA31_FDE
	{
		scope=1;
	};
	class ADFRC_eotech552: ADFRC_acog_ta648
	{
		scope=2;
		displayName="EOTech 552";
		author="$STR_ADF_AUTHOR";
		picture="\ADF_Optics\ui\optic_eotech552_ca.paa";
		model="\ADF_Optics\552\ADFRC_552.p3d";
		descriptionShort="Holographic Weapon Sight &lt;br/&gt; No Magnification CQB Optic";
		class ItemInfo: InventoryOpticsItem_Base_F
		{
			mass = 1;
			modelOptics = "\A3\Weapons_F\empty";
			optics = 1;
			class OpticsModes
			{
				class Aco
				{
					opticsID = 1;
					useModelOptics = 0;
					opticsZoomMin = 0.25;
					opticsZoomMax = 1.25;
					opticsZoomInit = 0.75;
					memoryPointCamera = "eye";
					opticsFlare = 0;
					opticsDisablePeripherialVision = 1;
					discreteDistance[] = {25,50,100,200,300};
					discreteDistanceInitIndex = 2;
					distanceZoomMin = 50;
					distanceZoomMax = 50;
					cameraDir = "";
					visionMode[] = {};
					opticsPPEffects[] = {"Default"};
				};
			};
		};
	};
	class ADFRC_eotech552_3XDOWN: ADFRC_eotech552
	{
		scope=2;
		displayName="EOTech 552 + 3x Magnifier";
		author="$STR_ADF_AUTHOR";
		picture="\ADF_Optics\ui\optic_eotech552_3x_ca.paa";
		model="\ADF_Optics\552\ADFRC_552_Mag_Down.p3d";
		descriptionShort="Holographic Weapon Sight &lt;br /&gt; Flip Down Magnifier";
		
        MRT_SwitchItemNextClass = "ADFRC_eotech552_3XUP";
        MRT_switchItemHintText = "1x";
		
		class ItemInfo: InventoryOpticsItem_Base_F
		{
			mass = 1;
			modelOptics = "\A3\Weapons_F\empty";
			optics = 1;
			class OpticsModes
			{
				class Aco
				{
					opticsID = 1;
					useModelOptics = 0;
					opticsZoomMin = 0.25;
					opticsZoomMax = 1.25;
					opticsZoomInit = 0.75;
					memoryPointCamera = "eye";
					opticsFlare = 0;
					opticsDisablePeripherialVision = 1;
					discreteDistance[] = {25,50,100,200,300};
					discreteDistanceInitIndex = 2;
					distanceZoomMin = 50;
					distanceZoomMax = 50;
					cameraDir = "";
					visionMode[] = {};
					opticsPPEffects[] = {"Default"};
				};
			};
		};
	};
	class ADFRC_eotech552_3XUP: ADFRC_eotech552_3XDOWN
	{
		scope=2;
		displayName="EOTech 552 + 3x Magnifier";
		author="$STR_ADF_AUTHOR";
		model="\ADF_Optics\552\ADFRC_552_Mag_Up.p3d";
		descriptionShort="Holographic Weapon Sight &lt;br /&gt; Flip Down Magnifier";
		
        MRT_SwitchItemNextClass = "ADFRC_eotech552_3XDOWN";
        MRT_switchItemHintText = "3x";
		
		class ItemInfo: InventoryOpticsItem_Base_F
		{
			mass = 1;
			modelOptics = "\A3\Weapons_F\empty";
			optics = 1;
			class OpticsModes
			{
				class Magnified
				{
					opticsID = 1;
					useModelOptics = 0;
					opticsZoomMin = "0.25/3";
					opticsZoomMax = "0.25/3";
					opticsZoomInit = "0.25/3";
					memoryPointCamera = "eye";
					opticsFlare = 0;
					opticsDisablePeripherialVision = 1;
					discreteDistance[] = {25,50,100,200,300};
					discreteDistanceInitIndex = 2;
					distanceZoomMin = 50;
					distanceZoomMax = 50;
					cameraDir = "";
					visionMode[] = {};
					opticsPPEffects[]=
					{
						"OpticsCHAbera5",
						"OpticsBlur5"
					};
				};
			};
		};
		
	};
};
