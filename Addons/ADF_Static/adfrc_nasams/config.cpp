class CfgPatches
{
	class adfrc_AA
	{
		addonRootClass = "ADF_Static";
		units[]=
		{
			"ADFRC_mml",
			"ADFRC_fdc"
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"A3_Static_F",
			"ADF_Core"
			
		};
		magazines[]={};
		ammo[]={};
	};
};
class CfgVehicles
{
	class B_SAM_System_03_F;
	class ADFRC_mml: B_SAM_System_03_F
	{
		author = "ADFRC Quiggs";
		editorPreview = "\ADF_Static\adfrc_nasams\data\editorPreviews\ADFRC_mml.jpg";
		scope = 2;
		scopeCurator = 2;
		displayName = "MIM-145 Defender";
		side = 1;
		faction = "ADFRC_F_MD";
	};
	class B_Radar_System_01_F;
	class ADFRC_fdc: B_Radar_System_01_F
	{
		author = "ADFRC Quiggs";
		editorPreview = "\ADF_Static\adfrc_nasams\data\editorPreviews\ADFRC_fdc.jpg";
		scope = 2;
		scopeCurator = 2;
		displayName = "AN/MPQ-105 Radar";
		side = 1;
		faction = "ADFRC_F_MD";
	};
};