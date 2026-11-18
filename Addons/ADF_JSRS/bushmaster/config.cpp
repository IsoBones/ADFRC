// ADF Re-Cut: JSRS SOUNDMOD 2025 compatibility (Bushmaster (bma3)).
// Same rules as ADF_Ace: only ADFRC classes are patched, vanilla classes are only
// forward-declared. skipWhenMissingDependencies = 1, so if JSRS or any addon listed
// here is missing (or misspelled) this config is silently skipped. Check the RPT.
class CfgPatches
{
	class ADFRC_JSRS_Bushmaster
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"jsrs2025_config_c", "adfrc_bushmaster"};
		skipWhenMissingDependencies = 1;
		author = "ADF Re-Cut";
	};
};

// Own config so retiring bma3 only drops this part. No JSRS Bushmaster, so this uses JSRS's
// CUP RG-31 set (closest 4x4 MRAP it has).
class CfgWeapons
{
	class MGun;
	class LMG_RCWS;
	class bma3_bushmaster_mag58: LMG_RCWS
	{
		class manual: MGun
		{
			class StandardSound
			{
				soundsetshot[] = {"jsrs_2025_m240_shot_soundset","jsrs_2025_tailsystem_762mm_lmg_soundset"};
			};
		};
	};
};
class CfgVehicles
{
	class Car_F;
	class adfrc_bushmaster_base_F: Car_F
	{
		// JSRS sounds from CUP_RG31_BASE (JSRS compat_cup_vechicles)
		class Sounds
		{
			class Idle_ext { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class Engine { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class Engine1_ext { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class Engine2_ext { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class Engine3_ext { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class Engine4_ext { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class Idle_int { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class Engine_int { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class Engine1_int { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class Engine2_int { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class Engine3_int { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class Engine4_int { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class IdleThrust { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class EngineThrust { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class Engine1_Thrust_ext { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class Engine2_Thrust_ext { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class Engine3_Thrust_ext { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class IdleThrust_int { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class EngineThrust_int { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class Engine1_Thrust_int { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class Engine2_Thrust_int { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class Engine3_Thrust_int { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class TiresRockOut { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class TiresSandOut { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class TiresGrassOut { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class TiresMudOut { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class TiresGravelOut { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class TiresAsphaltOut { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class NoiseOut { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class TiresRockIn { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class TiresSandIn { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class TiresGrassIn { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class TiresMudIn { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class TiresGravelIn { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class TiresAsphaltIn { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class NoiseIn { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class breaking_ext_road { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class acceleration_ext_road { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class turn_left_ext_road { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class turn_right_ext_road { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class breaking_ext_dirt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class acceleration_ext_dirt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class turn_left_ext_dirt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class turn_right_ext_dirt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class breaking_int_road { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class acceleration_int_road { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class turn_left_int_road { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class turn_right_int_road { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class breaking_int_dirt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class acceleration_int_dirt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class turn_left_int_dirt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class turn_right_int_dirt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			soundsetsint[] = {"jsrs_2025_mrap_01_engine_int_idle_soundset","jsrs_2025_mrap_01_engine_int_drive_soundset","jsrs_2025_base_mraps_engine_int_rev_west_soundset","jsrs_2025_mrap_01_engine_int_release_soundset","jsrs_2025_tires_asphalt_slow_int_soundset","jsrs_2025_tires_asphalt_fast_int_soundset","jsrs_2025_tires_offroad_slow_int_soundset","jsrs_2025_tires_offroad_fast_int_soundset","jsrs_2025_tires_grass_int_soundset","jsrs_2025_wheeled_driving_noises_int_car_1_soundset","jsrs_2025_wheeled_offroad_driving_noises_int_car_1_soundset","jsrs_2025_base_mraps_rattle_int_soundset","jsrs_2025_base_mraps_stress_int_soundset","jsrs_2025_base_mraps_Rain_INT_SoundSet","truck_01_tires_water_fast_int_soundset","truck_01_tires_water_slow_int_soundset","truck_01_tires_turn_hard_int_soundset","truck_01_tires_turn_soft_int_soundset","truck_01_tires_brake_hard_int_soundset","truck_01_tires_brake_soft_int_soundset"};
			soundsetsext[] = {"jsrs_2025_mrap_01_engine_ext_idle_soundset","jsrs_2025_mrap_01_engine_ext_drive_soundset","jsrs_2025_base_mraps_engine_rev_west_soundset","jsrs_2025_mrap_01_engine_evr_soundset","jsrs_2025_mrap_01_engine_ext_release_soundset","jsrs_2025_mrap_01_engine_ext_distance_soundset","jsrs_2025_tires_asphalt_slow_ext_soundset","jsrs_2025_tires_asphalt_fast_ext_soundset","jsrs_2025_tires_asphalt_fast_far_soundset","jsrs_2025_tires_offroad_slow_ext_soundset","jsrs_2025_tires_offroad_fast_ext_soundset","jsrs_2025_tires_grass_ext_soundset","jsrs_2025_base_mraps_rattle_ext_soundset","jsrs_2025_base_mraps_stress_ext_soundset","truck_01_rain_ext_soundset","truck_01_tires_water_fast_ext_soundset","truck_01_tires_water_slow_ext_soundset","truck_01_tires_turn_hard_ext_soundset","truck_01_tires_turn_soft_ext_soundset","truck_01_tires_brake_hard_ext_soundset","truck_01_tires_brake_soft_ext_soundset"};
		};
	};
};
