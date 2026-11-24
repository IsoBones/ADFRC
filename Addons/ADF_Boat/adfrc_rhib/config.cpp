class CfgPatches
{
	class adfrc_rhib
	{
		addonRootClass = "A3_Boat_F_Exp";
		requiredAddons[] = {"A3_Boat_F_Exp", "ADF_Core", "ADF_Units", "A3_Data_F_Mod_Loadorder"};
		requiredVersion = 0.1;
		units[] = {"adfrc_rhib"};
		weapons[] = {};
	};
};

class CfgVehicles
{
	class Boat_Transport_02_base_F;
	class C_Boat_Transport_02_F: Boat_Transport_02_base_F
	{
		class TextureSources;
	};

	// Retexture of the vanilla RHIB (Apex). Model, handling and seats are vanilla.
	class adfrc_rhib: C_Boat_Transport_02_F
	{
		author = "ADFRC";
		displayName = "RHIB";
		// Placeholder until the editor preview tool generates \ADF_Boat\adfrc_rhib\data\editorPreviews\adfrc_rhib.jpg
		editorPreview = "\A3\EditorPreviews_F_Exp\Data\CfgVehicles\I_C_Boat_Transport_02_F.jpg";
		scope = 2;
		scopeCurator = 2;
		side = 1;
		faction = "ADFRC_F_MD";
		crew = "ADFRC_MD_RAN_Coxswain";
		typicalCargo[] = {"ADFRC_MD_RAN_Coxswain"};
		textureList[] = {"ADFRC_Black", 1};
		hiddenSelectionsTextures[] =
		{
			"\ADF_Boat\adfrc_rhib\data\textures\adfrc_rhib_exterior_co.paa",
			"\ADF_Boat\adfrc_rhib\data\textures\adfrc_rhib_interior_co.paa"
		};
		class TextureSources: TextureSources
		{
			class ADFRC_Black
			{
				displayName = "ADF Black";
				author = "ADFRC";
				textures[] =
				{
					"\ADF_Boat\adfrc_rhib\data\textures\adfrc_rhib_exterior_co.paa",
					"\ADF_Boat\adfrc_rhib\data\textures\adfrc_rhib_interior_co.paa"
				};
				factions[] = {"ADFRC_F_MD"};
			};
		};
	};
};
