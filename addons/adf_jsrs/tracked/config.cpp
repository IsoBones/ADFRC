// ADF Re-Cut: JSRS SOUNDMOD 2025 compatibility (tracked).
// Same rules as ADF_Ace: only ADFRC classes are patched, vanilla classes are only
// forward-declared. skipWhenMissingDependencies = 1, so if JSRS or any addon listed
// here is missing (or misspelled) this config is silently skipped. Check the RPT.
class CfgPatches
{
	class ADFRC_JSRS_Tracked
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"jsrs2025_config_c", "adfrc_abrams"};
		skipWhenMissingDependencies = 1;
		author = "ADF Re-Cut";
	};
};

class CfgVehicles
{
	class I_MBT_03_cannon_F;
	class adfrc_abrams: I_MBT_03_cannon_F
	{
		// JSRS sounds from rhsusf_m1a1tank_base (JSRS compat_rhs_usf)
		class Sounds
		{
			class Engine { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class Engine1_ext { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class Engine2_ext { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class Engine3_ext { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class Engine4_ext { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class Engine5_ext { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class EngineThrust { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class Engine1_Thrust_ext { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class Engine2_Thrust_ext { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class Engine3_Thrust_ext { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class Engine4_Thrust_ext { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class Engine5_Thrust_ext { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class IdleOut { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class NoiseOut { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class ThreadsOutH0 { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class ThreadsOutH1 { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class ThreadsOutH2 { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class ThreadsOutH3 { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class ThreadsOutH4 { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class ThreadsOutS0 { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class ThreadsOutS1 { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class ThreadsOutS2 { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class ThreadsOutS3 { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class ThreadsOutS4 { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class Movement { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class Engine_int { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class IdleIn { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class NoiseIn { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class ThreadsInH0 { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class ThreadsInH1 { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class ThreadsInH2 { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class ThreadsInH3 { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class ThreadsInH4 { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class ThreadsInS0 { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class ThreadsInS1 { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class ThreadsInS2 { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class ThreadsInS3 { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class ThreadsInS4 { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class Engine1_int { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class Engine2_int { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class Engine3_int { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class Engine4_int { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class Engine5_int { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class IdleThrust_int { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class EngineThrust_int { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class Engine1_Thrust_int { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class Engine2_Thrust_int { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class Engine3_Thrust_int { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class Engine4_Thrust_int { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class Engine5_Thrust_int { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			soundsetsint[] = {"jsrs_2025_abrams_engine_int_idle_soundset","jsrs_2025_abrams_engine_int_drive_soundset","jsrs_2025_abrams_engine_int_release_soundset","jsrs_2025_tracks_interior_modern_heavy_soundset","jsrs_2025_base_tanks_rattle_int_soundset","jsrs_2025_base_tanks_stress_int_soundset","jsrs_2025_base_tanks_Rain_INT_SoundSet","mbt_01_tracks_brake_hard_int_soundset","mbt_01_tracks_brake_soft_int_soundset","mbt_01_tracks_turn_hard_int_soundset","mbt_01_tracks_turn_soft_int_soundset","mbt_01_drive_water_int_soundset","mbt_01_drive_dirt_int_soundset","tank_general_collision_int_soundset"};
			soundsetsext[] = {"jsrs_2025_abrams_engine_ext_idle_soundset","jsrs_2025_abrams_engine_ext_drive_soundset","jsrs_2025_abrams_engine_evr_soundset","jsrs_2025_abrams_engine_ext_release_soundset","jsrs_2025_abrams_engine_ext_distance_soundset","jsrs_2025_tracks_modern_heavy_soundset","jsrs_2025_tracks_modern_heavy_distance_soundset","jsrs_2025_base_tanks_rattle_ext_soundset","jsrs_2025_base_tanks_stress_ext_soundset","mbt_01_rain_ext_soundset","mbt_01_drive_water_ext_soundset","mbt_01_drive_dirt_ext_soundset","tracks_movement_dirt_ext_01_soundset","tracks_surface_soft_ext_soundset","tracks_surface_sand_ext_soundset","tank_general_collision_soundshader"};
		};
	};
};
