class ADFRC_Specter_RAR : ItemCore
	{
		displayName="Elcan SpecterDR 1x/4x (RAR)";
		author="Brucey";
		picture="\ADF_Optics\Spectr\UI\Spectr_RAR_ca.paa";
		uipicture="\ADF_Optics\Spectr\UI\Spectr_RAR_ca.paa";
		model = "ADF_Optics\Spectr\ADFRC_Spectr_RAR.p3d";
		scope =2;
		descriptionShort = "Spectr DR 1x/4x";
		
		
		class CBA_ScriptedOptic {
            reticleTexture = "\ADF_Optics\Spectr\Textures\ADRC_Spectr_Ret_CA.paa";
            reticleTextureSize = 1.05;

            bodyTexture = "\ADF_Optics\Spectr\Textures\ScopeBody_RAR_D_ca.paa";
            bodyTextureNight = "\ADF_Optics\Spectr\Textures\ScopeBody_RAR_N_ca.paa";
			bodyTextureSize = 1.15;
        };
        weaponInfoType = "CBA_ScriptedOptic";
		modelOptics = "\x\cba\addons\optics\cba_optic_small_pip.p3d";
		
		class ItemInfo : InventoryOpticsItem_Base_F {
			opticType = 2;
			mass = 14;
			RMBhint = "1/4x";
			optics = true;
			modelOptics = "\x\cba\addons\optics\cba_optic_small_pip.p3d";

			class OpticsModes {
				
				class Snip {
					opticsID = 1;
					opticsDisplayName = WFOV;
					useModelOptics = 1;
					opticsPPEffects[] = {"OpticsCHAbera1", "OpticsBlur1"};
					opticsZoomMin = "4 call (uiNamespace getVariable 'cba_optics_fnc_setOpticMagnificationHelper')";
					opticsZoomMax = "4 call (uiNamespace getVariable 'cba_optics_fnc_setOpticMagnificationHelper')";
					opticsZoomInit = "4 call (uiNamespace getVariable 'cba_optics_fnc_setOpticMagnificationHelper')";
					discreteDistance[]={25,50,100,200,300,400};
					discreteDistanceInitIndex=0;
					distanceZoomMin = 100;
					distanceZoomMax = 100;
					memoryPointCamera = "opticView";
					visionMode[] = {"Normal"};
					opticsFlare = true;
					opticsDisablePeripherialVision = true;
					cameraDir = "";
				};
				class Optic1x
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
					memoryPointCamera="eye1";
					visionMode[]={};
					opticsFlare=0;
					opticsDisablePeripherialVision=0;
					discreteDistance[]={25,50,100,200,300,400};
					discreteDistanceInitIndex=0;
					distanceZoomMin=300;
					distanceZoomMax=300;
					cameraDir="";
				};
				class RDS1x
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
					discreteDistance[]={25};
					discreteDistanceInitIndex=0;
					visionMode[]={};
					opticsFlare=0;
					opticsDisablePeripherialVision=0;
					distanceZoomMin=300;
					distanceZoomMax=300;
					cameraDir="";
				};
			};

		};
		inertia = 0.1;
	};
	
class ADFRC_Specter_RAR_pip: ADFRC_Specter_RAR
	{};
		
class ADFRC_Specter_RAR_KF : ADFRC_Specter_RAR
	{
		displayName="Elcan SpecterDR 1x/4x (RAR - KF)";
		author="Brucey";
		picture="\ADF_Optics\Spectr\UI\Spectr_RAR_KF_ca.paa";
		uipicture="\ADF_Optics\Spectr\UI\Spectr_RAR_KF_ca.paa";
		model = "ADF_Optics\Spectr\ADFRC_Spectr_RAR_KF.p3d";
	};
	
class ADFRC_Specter_CDO : ADFRC_Specter_RAR
	{
		displayName="Elcan SpecterDR 1x/4x (CDO)";
		author="Brucey";
		picture="\ADF_Optics\Spectr\UI\Spectr_CDO_ca.paa";
		uipicture="\ADF_Optics\Spectr\UI\Spectr_CDO_ca.paa";
		model = "ADF_Optics\Spectr\ADFRC_Spectr_CDO.p3d";
		
		class CBA_ScriptedOptic {
            reticleTexture = "\ADF_Optics\Spectr\Textures\ADRC_Spectr_Ret_CA.paa";
            reticleTextureSize = 1.05;

            bodyTexture = "\ADF_Optics\Spectr\Textures\ScopeBody_CDO_D_ca.paa";
            bodyTextureNight = "\ADF_Optics\Spectr\Textures\ScopeBody_CDO_N_ca.paa";
			bodyTextureSize = 1.15;
        };
	};
	
class ADFRC_Specter_CDO_KF : ADFRC_Specter_CDO
	{
		displayName="Elcan SpecterDR 1x/4x (CDO - KF)";
		author="Brucey";
		picture="\ADF_Optics\Spectr\UI\Spectr_CDO_KF_ca.paa";
		uipicture="\ADF_Optics\Spectr\UI\Spectr_CDO_KF_ca.paa";
		model = "ADF_Optics\Spectr\ADFRC_Spectr_CDO_KF.p3d";
	};
	
	
class ADFRC_Specter_CDO_DPP : ADFRC_Specter_RAR
	{
		displayName="Elcan SpecterDR 1x/4x Leupold DPP (CDO)";
		author="Brucey";
		picture="\ADF_Optics\Spectr\UI\Spectr_CDO_ca.paa";
		uipicture="\ADF_Optics\Spectr\UI\Spectr_CDO_ca.paa";
		model = "ADF_Optics\Spectr\ADFRC_Spectr_CDO_DP.p3d";
		
		class CBA_ScriptedOptic {
            reticleTexture = "\ADF_Optics\Spectr\Textures\ADRC_Spectr_Ret_CA.paa";
            reticleTextureSize = 1.05;

            bodyTexture = "\ADF_Optics\Spectr\Textures\ScopeBody_CDO_DPP_D_ca.paa";
            bodyTextureNight = "\ADF_Optics\Spectr\Textures\ScopeBody_CDO_DPP_N_ca.paa";
			bodyTextureSize = 1.15;
        };
	};
	
class ADFRC_Specter_CDO_KF_DPP : ADFRC_Specter_CDO
	{
		displayName="Elcan SpecterDR 1x/4x Leupold DPP (CDO - KF)";
		author="Brucey";
		picture="\ADF_Optics\Spectr\UI\Spectr_CDO_KF_ca.paa";
		uipicture="\ADF_Optics\Spectr\UI\Spectr_CDO_KF_ca.paa";
		model = "ADF_Optics\Spectr\ADFRC_Spectr_CDO_DP_KF.p3d";
		
		class CBA_ScriptedOptic {
            reticleTexture = "\ADF_Optics\Spectr\Textures\ADRC_Spectr_Ret_CA.paa";
            reticleTextureSize = 1.05;

            bodyTexture = "\ADF_Optics\Spectr\Textures\ScopeBody_CDO_DPP_D_ca.paa";
            bodyTextureNight = "\ADF_Optics\Spectr\Textures\ScopeBody_CDO_DPP_N_ca.paa";
			bodyTextureSize = 1.15;
        };
	};
	
	
class ADFRC_Specter_C_RAR : ADFRC_Specter_RAR
	{
		displayName="Elcan SpecterDR 1x/4x (RAR) - Camo";
		picture="\ADF_Optics\Spectr\UI\Spectr_RAR_C_ca.paa";
		uipicture="\ADF_Optics\Spectr\UI\Spectr_RAR_C_ca.paa";
		model = "ADF_Optics\Spectr\ADFRC_Spectr_C_RAR.p3d";
		
		class CBA_ScriptedOptic {
            reticleTexture = "\ADF_Optics\Spectr\Textures\ADRC_Spectr_Ret_CA.paa";
            reticleTextureSize = 1.05;

            bodyTexture = "\ADF_Optics\Spectr\Textures\ScopeBody_RAR_C_D_ca.paa";
            bodyTextureNight = "\ADF_Optics\Spectr\Textures\ScopeBody_RAR_C_N_ca.paa";
			bodyTextureSize = 1.15;
        };
	};
	
class ADFRC_Specter_RAR_C : ADFRC_Specter_C_RAR
	{
	scope = 1;
	};
	
class ADFRC_Specter_RAR_C_KF : ADFRC_Specter_RAR
	{
		displayName="Elcan SpecterDR 1x/4x (RAR - KF) - Camo";
		author="Brucey";
		picture="\ADF_Optics\Spectr\UI\Spectr_RAR_C_KF_ca.paa";
		uipicture="\ADF_Optics\Spectr\UI\Spectr_RAR_C_KF_ca.paa";
		model = "ADF_Optics\Spectr\ADFRC_Spectr_C_RAR_KF.p3d";
		
		class CBA_ScriptedOptic {
            reticleTexture = "\ADF_Optics\Spectr\Textures\ADRC_Spectr_Ret_CA.paa";
            reticleTextureSize = 1.05;

            bodyTexture = "\ADF_Optics\Spectr\Textures\ScopeBody_RAR_C_D_ca.paa";
            bodyTextureNight = "\ADF_Optics\Spectr\Textures\ScopeBody_RAR_C_N_ca.paa";
			bodyTextureSize = 1.15;
        };
	};
	

	
class ADFRC_Specter_C_CDO : ADFRC_Specter_RAR
	{
		displayName="Elcan SpecterDR 1x/4x (CDO) - Camo";
		author="Brucey";
		picture="\ADF_Optics\Spectr\UI\Spectr_CDO_C_ca.paa";
		uipicture="\ADF_Optics\Spectr\UI\Spectr_CDO_C_ca.paa";
		model = "ADF_Optics\Spectr\ADFRC_Spectr_C_CDO.p3d";
		
		class CBA_ScriptedOptic {
            reticleTexture = "\ADF_Optics\Spectr\Textures\ADRC_Spectr_Ret_CA.paa";
            reticleTextureSize = 1.05;

            bodyTexture = "\ADF_Optics\Spectr\Textures\ScopeBody_C_CDO_D_ca.paa";
            bodyTextureNight = "\ADF_Optics\Spectr\Textures\ScopeBody_C_CDO_N_ca.paa";
			bodyTextureSize = 1.15;
        };
	};
	
class ADFRC_Specter_CDO_C_KF : ADFRC_Specter_CDO
	{
		displayName="Elcan SpecterDR 1x/4x (CDO - KF) - Camo";
		author="Brucey";
		picture="\ADF_Optics\Spectr\UI\Spectr_CDO_C_KF_ca.paa";
		uipicture="\ADF_Optics\Spectr\UI\Spectr_CDO_C_KF_ca.paa";
		model = "ADF_Optics\Spectr\ADFRC_Spectr_C_CDO_KF.p3d";
		
		class CBA_ScriptedOptic {
            reticleTexture = "\ADF_Optics\Spectr\Textures\ADRC_Spectr_Ret_CA.paa";
            reticleTextureSize = 1.05;

            bodyTexture = "\ADF_Optics\Spectr\Textures\ScopeBody_C_CDO_D_ca.paa";
            bodyTextureNight = "\ADF_Optics\Spectr\Textures\ScopeBody_C_CDO_N_ca.paa";
			bodyTextureSize = 1.15;
        };
	};
	
class ADFRC_Specter_CDO_C_DPP : ADFRC_Specter_RAR
	{
		displayName="Elcan SpecterDR 1x/4x Leupold DPP (CDO) - Camo";
		author="Brucey";
		picture="\ADF_Optics\Spectr\UI\Spectr_CDO_c_ca.paa";
		uipicture="\ADF_Optics\Spectr\UI\Spectr_CDO_c_ca.paa";
		model = "ADF_Optics\Spectr\ADFRC_Spectr_C_CDO_DP.p3d";
		
		class CBA_ScriptedOptic {
            reticleTexture = "\ADF_Optics\Spectr\Textures\ADRC_Spectr_Ret_CA.paa";
            reticleTextureSize = 1.05;

            bodyTexture = "\ADF_Optics\Spectr\Textures\ScopeBody_C_CDO_DPP_D_ca.paa";
            bodyTextureNight = "\ADF_Optics\Spectr\Textures\ScopeBody_C_CDO_DPP_N_ca.paa";
			bodyTextureSize = 1.15;
        };
	};
	
class ADFRC_Specter_CDO_C_KF_DPP : ADFRC_Specter_CDO
	{
		displayName="Elcan SpecterDR 1x/4x Leupold DPP (CDO - KF) - Camo";
		author="Brucey";
		picture="\ADF_Optics\Spectr\UI\Spectr_CDO_c_KF_ca.paa";
		uipicture="\ADF_Optics\Spectr\UI\Spectr_CDO_c_KF_ca.paa";
		model = "ADF_Optics\Spectr\ADFRC_Spectr_C_CDO_DP_KF.p3d";
		
		class CBA_ScriptedOptic {
            reticleTexture = "\ADF_Optics\Spectr\Textures\ADRC_Spectr_Ret_CA.paa";
            reticleTextureSize = 1.05;

            bodyTexture = "\ADF_Optics\Spectr\Textures\ScopeBody_C_CDO_DPP_D_ca.paa";
            bodyTextureNight = "\ADF_Optics\Spectr\Textures\ScopeBody_C_CDO_DPP_N_ca.paa";
			bodyTextureSize = 1.15;
        };
	};
