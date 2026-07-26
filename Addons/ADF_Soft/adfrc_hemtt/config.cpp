class CfgPatches
{
	class adfrc_hemtt
	{
		units[]=
		{
			"ADFRC_hemtt_cargo"
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"A3_Soft_F_Enoch",
			"A3_Soft_F_Gamma",
			"ADF_Units",
			"ADF_Core"
			
		};
		magazines[]={};
		ammo[]={};
	};
};
class CfgVehicles
{
	class B_Truck_01_cargo_F;
	class ADFRC_hemtt_cargo: B_Truck_01_cargo_F
	{
		author = "ADFRC Quiggs";
		editorPreview = "\ADF_Soft\adfrc_hemtt\preview\ADFRC_hemtt_cargo.jpg";
		scope = 2;
		scopeCurator = 2;
		displayName = "HEMTT Cargo";
		crew = "ADFRC_MD_AMCU_Soldier_Light";
		typicalCargo[] = {"ADFRC_MD_AMCU_Soldier_Light"};
		side = 1;
		faction = "ADFRC_F_MD";
		textureList[] = {};
		hiddenSelections[]= {"Camo1","Camo2","Camo3","Camo4"};
		hiddenSelectionsTextures[]= {"\ADF_Soft\adfrc_hemtt\data\truck_01_ext_01_co.paa","\ADF_Soft\adfrc_hemtt\data\truck_01_ext_02_co.paa","\ADF_Soft\adfrc_hemtt\data\truck_01_ammo_co.paa","\ADF_Soft\adfrc_hemtt\data\Truck_01_cargo_CO.paa"};
	};
	class B_Truck_01_ammo_F;
	class ADFRC_hemtt_ammo: B_Truck_01_ammo_F
	{
		author = "ADFRC Quiggs";
		editorPreview = "\ADF_Soft\adfrc_hemtt\preview\ADFRC_hemtt_ammo.jpg";
		scope = 2;
		scopeCurator = 2;
		displayName = "HEMTT Ammo";
		crew = "ADFRC_MD_AMCU_Soldier_Light";
		typicalCargo[] = {"ADFRC_MD_AMCU_Soldier_Light"};
		side = 1;
		faction = "ADFRC_F_MD";
		textureList[] = {};
		hiddenSelections[]= {"Camo1","Camo2","Camo3"};
		hiddenSelectionsTextures[]= {"\ADF_Soft\adfrc_hemtt\data\truck_01_ext_01_co.paa","\ADF_Soft\adfrc_hemtt\data\truck_01_ext_02_co.paa","\ADF_Soft\adfrc_hemtt\data\Truck_01_ammo_CO.paa"};
	};
	class B_Truck_01_fuel_F;
	class ADFRC_hemtt_fuel: B_Truck_01_fuel_F
	{
		author = "ADFRC Quiggs";
		editorPreview = "\ADF_Soft\adfrc_hemtt\preview\ADFRC_hemtt_fuel.jpg";
		scope = 2;
		scopeCurator = 2;
		displayName = "HEMTT Fuel";
		crew = "ADFRC_MD_AMCU_Soldier_Light";
		typicalCargo[] = {"ADFRC_MD_AMCU_Soldier_Light"};
		side = 1;
		faction = "ADFRC_F_MD";
		textureList[] = {};
		hiddenSelections[]= {"Camo1","Camo2","Camo3"};
		hiddenSelectionsTextures[]= {"\ADF_Soft\adfrc_hemtt\data\truck_01_ext_01_co.paa","\ADF_Soft\adfrc_hemtt\data\truck_01_ext_02_co.paa","\ADF_Soft\adfrc_hemtt\data\truck_01_Fuel_CO.paa"};
	};
	class B_Truck_01_covered_F;
	class ADFRC_hemtt_transport: B_Truck_01_covered_F
	{
		author = "ADFRC Quiggs";
		editorPreview = "\ADF_Soft\adfrc_hemtt\preview\ADFRC_hemtt_transport.jpg";
		scope = 2;
		scopeCurator = 2;
		displayName = "HEMTT Transport";
		crew = "ADFRC_MD_AMCU_Soldier_Light";
		typicalCargo[] = {"ADFRC_MD_AMCU_Soldier_Light"};
		side = 1;
		faction = "ADFRC_F_MD";
		textureList[] = {};
		hiddenSelections[]= {"Camo1","Camo2","Camo3","Camo4"};
		hiddenSelectionsTextures[]= {"\ADF_Soft\adfrc_hemtt\data\truck_01_ext_01_co.paa","\ADF_Soft\adfrc_hemtt\data\truck_01_ext_02_co.paa","\ADF_Soft\adfrc_hemtt\data\Truck_01_cargo_co.paa","\ADF_Soft\adfrc_hemtt\data\Truck_01_cover_CO.paa"};
	};
	class B_Truck_01_mover_F;
	class ADFRC_hemtt_mover: B_Truck_01_mover_F
	{
		author = "ADFRC Quiggs";
		editorPreview = "\ADF_Soft\adfrc_hemtt\preview\ADFRC_hemtt_mover.jpg";
		scope = 2;
		scopeCurator = 2;
		displayName = "HEMTT Prime Mover";
		crew = "ADFRC_MD_AMCU_Soldier_Light";
		typicalCargo[] = {"ADFRC_MD_AMCU_Soldier_Light"};
		side = 1;
		faction = "ADFRC_F_MD";
		textureList[] = {};
		hiddenSelections[]= {"Camo1","Camo2","Camo3"};
		hiddenSelectionsTextures[]= {"\ADF_Soft\adfrc_hemtt\data\truck_01_ext_01_co.paa","\ADF_Soft\adfrc_hemtt\data\truck_01_ext_02_co.paa","\ADF_Soft\adfrc_hemtt\data\truck_01_mprimer_CO.paa"};
	};
	class B_Truck_01_flatbed_F;
	class ADFRC_hemtt_flatbed: B_Truck_01_flatbed_F
	{
		author = "ADFRC Quiggs";
		editorPreview = "\ADF_Soft\adfrc_hemtt\preview\ADFRC_hemtt_flatbed.jpg";
		scope = 2;
		scopeCurator = 2;
		displayName = "HEMTT Flatbed";
		crew = "ADFRC_MD_AMCU_Soldier_Light";
		typicalCargo[] = {"ADFRC_MD_AMCU_Soldier_Light"};
		side = 1;
		faction = "ADFRC_F_MD";
		textureList[] = {};
		hiddenSelections[]= {"Camo1","Camo2","Camo3"};
		hiddenSelectionsTextures[]= {"\ADF_Soft\adfrc_hemtt\data\truck_01_ext_01_co.paa","\ADF_Soft\adfrc_hemtt\data\truck_01_ext_02_co.paa","\ADF_Soft\adfrc_hemtt\data\Truck_01_ammo_CO.paa"};
	};
	class B_Truck_01_box_F;
	class ADFRC_hemtt_box: B_Truck_01_box_F
	{
		author = "ADFRC Quiggs";
		editorPreview = "\ADF_Soft\adfrc_hemtt\preview\ADFRC_hemtt_flatbed.jpg";
		scope = 2;
		scopeCurator = 2;
		displayName = "HEMTT Box";
		crew = "ADFRC_MD_AMCU_Soldier_Light";
		typicalCargo[] = {"ADFRC_MD_AMCU_Soldier_Light"};
		side = 1;
		faction = "ADFRC_F_MD";
		textureList[] = {};
		hiddenSelections[]= {"Camo1","Camo2","Camo3"};
		hiddenSelectionsTextures[]= {"\ADF_Soft\adfrc_hemtt\data\truck_01_ext_01_co.paa","\ADF_Soft\adfrc_hemtt\data\truck_01_ext_02_co.paa","\ADF_Soft\adfrc_hemtt\data\Truck_01_ammo_CO.paa"};
	};
	
	
////////////////////// ADF GWOT VERSIONS //////////////////////
	class ADFRC_hemtt_cargo_GWOT: ADFRC_hemtt_cargo
	{
		faction = "ADFRC_F_GWOT";
	};
	class ADFRC_hemtt_ammo_GWOT: ADFRC_hemtt_ammo
	{
		faction = "ADFRC_F_GWOT";
	};
	class ADFRC_hemtt_fuel_GWOT: ADFRC_hemtt_fuel
	{
		faction = "ADFRC_F_GWOT";
	};
	class ADFRC_hemtt_transport_GWOT: ADFRC_hemtt_transport
	{
		faction = "ADFRC_F_GWOT";
	};
	class ADFRC_hemtt_mover_GWOT: ADFRC_hemtt_mover
	{
		faction = "ADFRC_F_GWOT";
	};
	class ADFRC_hemtt_flatbed_GWOT: ADFRC_hemtt_flatbed
	{
		faction = "ADFRC_F_GWOT";
	};
	class ADFRC_hemtt_box_GWOT: ADFRC_hemtt_box
	{
		faction = "ADFRC_F_GWOT";
	};
	
////////////////////// OLD REDUNDANT ADF PCW VERSIONS //////////////////////
	class ADFRC_hemtt_cargo_PCW: ADFRC_hemtt_cargo
	{
		scope=1;
		scopeCurator=1;
	};
	class ADFRC_hemtt_ammo_PCW: ADFRC_hemtt_ammo
	{
		scope=1;
		scopeCurator=1;
	};
	class ADFRC_hemtt_fuel_PCW: ADFRC_hemtt_fuel
	{
		scope=1;
		scopeCurator=1;
	};
	class ADFRC_hemtt_transport_PCW: ADFRC_hemtt_transport
	{
		scope=1;
		scopeCurator=1;
	};
	class ADFRC_hemtt_mover_PCW: ADFRC_hemtt_mover
	{
		scope=1;
		scopeCurator=1;
	};
	class ADFRC_hemtt_flatbed_PCW: ADFRC_hemtt_flatbed
	{
		scope=1;
		scopeCurator=1;
	};
};