	// Royal Australian Navy crew. ADFRC_MD_AMCU_Soldier_Base is forward-declared in
	// Modern\RAR\Infantry.hpp (same CfgVehicles scope), so don't declare it again here.

	////////////////////////RAN Boat Crew///////////////////////////////////////////////////////////
	// Default crew for the LCM-1E (ADF_Boat\adfrc_lcm).
	class ADFRC_MD_RAN_Coxswain: ADFRC_MD_AMCU_Soldier_Base{
		editorPreview = "\ADF_Units\Modern\RAN\data\editorPreviews\ADFRC_MD_RAN_Coxswain.jpg";
		displayName="Coxswain";
		author="$STR_ADF_AUTHOR";
		scope=2;
		scopeCurator=2;
		editorSubcategory="ADFRC_MD_RAN_MMP";
		role="Crewman";
		uniformClass="ADFRC_Uniform_G3_MMP";
		hiddenSelectionsTextures[] = {
			"\ADF_Gear\adfrc_uniforms\data\Crye_G3_Gloves_Grey_co.paa",
			"\ADF_Gear\adfrc_uniforms\data\Crye_G3_Pants_MMP_co.paa",
			"",
			"\ADF_Gear\adfrc_uniforms\data\Crye_G3_Boots_Ranger_Green_co.paa",
			"",
			"",
			"",
			"\ADF_Gear\adfrc_uniforms\data\Crye_G3_Shirt_MMP_co.paa"
		};
		weapons[]={
			"ADFRC_EF88C_Black",
			"ADFRC_G19_G5_SLICK",
			"Binocular",
			"Throw",
			"Put"
		};
		respawnWeapons[]={
			"ADFRC_EF88C_Black",
			"ADFRC_G19_G5_SLICK",
			"Binocular",
			"Throw",
			"Put"
		};
		magazines[]={
			"ADFRC_30Rnd_aug_ef88",
			"ADFRC_30Rnd_aug_ef88",
			"ADFRC_30Rnd_aug_ef88",
			"ADFRC_15rnd_9MM_BALL_G19",
			"ADFRC_15rnd_9MM_BALL_G19",
			"SmokeShellGreen"
		};
		respawnMagazines[]={
			"ADFRC_30Rnd_aug_ef88",
			"ADFRC_30Rnd_aug_ef88",
			"ADFRC_30Rnd_aug_ef88",
			"ADFRC_15rnd_9MM_BALL_G19",
			"ADFRC_15rnd_9MM_BALL_G19",
			"SmokeShellGreen"
		};
		items[] = {"FirstAidKit", "FirstAidKit"};
		respawnItems[] = {"FirstAidKit", "FirstAidKit"};
		linkedItems[]={
			"ADFRC_Peacekeeper_Mk5_AMCU",
			"adfrc_opscore_marine_Snakeskin_blk_Ct_1_Aus",
			"adfrc_facewear_gatorz_1",
			"ItemMap",
			"ItemCompass",
			"ItemWatch",
			"ItemRadio",
			"ItemGPS"
		};
		respawnLinkedItems[]={
			"ADFRC_Peacekeeper_Mk5_AMCU",
			"adfrc_opscore_marine_Snakeskin_blk_Ct_1_Aus",
			"adfrc_facewear_gatorz_1",
			"ItemMap",
			"ItemCompass",
			"ItemWatch",
			"ItemRadio",
			"ItemGPS"
		};
	};
