// ADF Re-Cut: JSRS SOUNDMOD 2025 compatibility (aircraft).
// Same rules as ADF_Ace: only ADFRC classes are patched, vanilla classes are only
// forward-declared. skipWhenMissingDependencies = 1, so if JSRS or any addon listed
// here is missing (or misspelled) this config is silently skipped. Check the RPT.
class CfgPatches
{
	class ADFRC_JSRS_Air
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"jsrs2025_config_c", "ADFRC_blackhawk", "adfrc_chinook", "adfrc_apache", "adfrc_c130"};
		skipWhenMissingDependencies = 1;
		author = "ADF Re-Cut";
	};
};

class Mode_SemiAuto;
class Mode_FullAuto;
class Mode_Burst;
class CfgWeapons
{
	class MGun;
	class LMG_RCWS;
	class gatling_30mm_base;
	class CMFlareLauncher;
	// Black Hawk door MAG58s: same JSRS M240 set as the infantry MAG58 (right gun inherits left)
	class ADFRC_blackhawk_MAG58_left: LMG_RCWS
	{
		class manual: MGun
		{
			class StandardSound
			{
				soundsetshot[] = {"jsrs_2025_m240_shot_soundset","jsrs_2025_tailsystem_762mm_lmg_soundset"};
			};
		};
	};
	// Apache M230 (Chaingun_30mm and its HEDP muzzle inherit this): what JSRS uses for the RHS M230
	class ADFRC_gatling_30mm_base: gatling_30mm_base
	{
		class FullAuto: Mode_FullAuto
		{
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				soundsetshot[] = {"jsrs_2025_autocannon_air_shot_soundset"};
			};
		};
	};
	// Chinook flares: what JSRS uses for vanilla CMFlareLauncher (Burst2-6 inherit Burst1)
	class ADFRC_PHOENIX_CMFlareLauncher: CMFlareLauncher
	{
		class Single: Mode_SemiAuto
		{
			class StandardSound
			{
				soundsetshot[] = {"jsrs_2025_cmr_flare_shot_soundset"};
			};
		};
		class Burst1: Mode_Burst
		{
			class StandardSound
			{
				soundsetshot[] = {"jsrs_2025_cmr_flare_shot_soundset"};
			};
		};
	};
};
class CfgVehicles
{
	class Helicopter_Base_F;
	class Helicopter_Base_H;
	class ADFRC_chinook_base;
	class Plane_Base_F;
	class ADFRC_blackhawk_BASE: Helicopter_Base_H
	{
		// JSRS sounds from RHS_UH60_Base (JSRS compat_rhs_usf)
		class Sounds
		{
			class Engine { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class RotorLowOut { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class RotorHighOut { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class EngineIn { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class RotorLowIn { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class RotorHighIn { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class TransmissionDamageExt_phase1 { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class TransmissionDamageExt_phase2 { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class TransmissionDamageInt_phase1 { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class TransmissionDamageInt_phase2 { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class damageAlarm { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class scrubLandInt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class scrubLandExt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class scrubBuildingInt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class scrubBuildingExt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class scrubTreeInt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class scrubTreeExt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class RainExt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class RainInt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class SlingLoadDownExt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class SlingLoadUpExt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class SlingLoadDownInt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class SlingLoadUpInt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class WindInt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class GStress { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class SpeedStress { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class engineext
			{
				sound[] = {"z\jsrs2025\addons\sounds_air\sounds\helicopters\uh80_ghosthawk\turbine_ext_close.ogg",1.4,1,400};
				frequency = "rotorspeed * (1-rotorthrust/15) * 1.25";
				volume = "campos*((rotorspeed-0.72)*4)";
			};
			class rotorext
			{
				sound[] = {"z\jsrs2025\addons\sounds_air\sounds\helicopters\uh80_ghosthawk\rotor_ext_close.ogg",1,1,700};
				frequency = "rotorspeed * (1-rotorthrust/15) * 1.25";
				volume = "1*campos*(0 max (rotorspeed-0.5))*(1 + rotorthrust)";
				cone[] = {1.6,3.14,1.6,0.95};
			};
			class engineextdist
			{
				sound[] = {"z\jsrs2025\addons\sounds_air\sounds\helicopters\uh80_ghosthawk\turbine_ext_distance.ogg",1,1,1000};
				frequency = "rotorspeed * (1-rotorthrust/15) * 1.25";
				volume = "campos*((rotorspeed-0.72)*4)";
			};
			class rotorextdist
			{
				sound[] = {"z\jsrs2025\addons\sounds_air\sounds\helicopters\uh80_ghosthawk\rotor_ext_distance.ogg",1,1,3000};
				frequency = "rotorspeed * (1-rotorthrust/15) * 1.25";
				volume = "1*campos*(0 max (rotorspeed-0.5))*(1 + rotorthrust)";
				cone[] = {1.6,3.14,1.6,0.95};
			};
			class rotornoiseext
			{
				sound[] = {"z\jsrs2025\addons\sounds_air\sounds\helicopters\uh80_ghosthawk\rotor_ext_distance.ogg",0,1,0};
				frequency = "rotorspeed* 1";
				volume = "campos * (rotorthrust factor [0.7,0.9])";
				cone[] = {0.7,1.3,1,0};
			};
			class engineint
			{
				sound[] = {"z\jsrs2025\addons\sounds_air\sounds\helicopters\uh80_ghosthawk\turbine_int.ogg",1,1};
				frequency = "1";
				volume = "(1-campos)*((rotorspeed-0.75)*3)";
			};
			class rotorint
			{
				sound[] = {"z\jsrs2025\addons\sounds_air\sounds\helicopters\uh80_ghosthawk\rotor_int.ogg",0.5011872,1};
				frequency = "rotorspeed * (1-rotorthrust/15) * 1.25";
				volume = "(1-campos)*(0 max (rotorspeed-0.5))*(1 + rotorthrust)";
			};
			soundsetsint[] = {"jsrs_2025_helicopter_uh80_ghosthawk_engineint_soundset","jsrs_2025_helicopter_uh80_ghosthawk_rotorint_soundset","jsrs_2025_helicopter_transmissiondamageint_phase1_soundset","jsrs_2025_helicopter_transmissiondamageint_phase2_soundset","jsrs_2025_helicopter_damagealarmint_soundset","jsrs_2025_helicopter_rotorlowalarmint_soundset","jsrs_2025_helicopter_scrublandint_soundset","jsrs_2025_helicopter_scrubbuildingint_soundset","jsrs_2025_helicopter_scrubtreeint_soundset","jsrs_2025_helicopter_slingloaddownint_soundset","jsrs_2025_helicopter_slingloadupint_soundset","jsrs_2025_helicopter_rainint_soundset","jsrs_2025_helicopter_windint_soundset","jsrs_2025_helicopter_uh80_ghosthawk_gstress_soundset"};
			soundsetsext[] = {"jsrs_2025_helicopter_uh80_ghosthawk_engineext_soundset","jsrs_2025_helicopter_uh80_ghosthawk_rotorext_soundset","jsrs_2025_helicopter_uh80_ghosthawk_evr_soundset","jsrs_2025_helicopter_uh80_ghosthawk_rotordistance_soundset","jsrs_2025_helicopter_uh80_ghosthawk_enginedistance_soundset","jsrs_2025_helicopter_transmissiondamageext_phase1_soundset","jsrs_2025_helicopter_transmissiondamageext_phase2_soundset","jsrs_2025_helicopter_scrublandext_soundset","jsrs_2025_helicopter_scrubbuildingext_soundset","jsrs_2025_helicopter_scrubtreeext_soundset","jsrs_2025_helicopter_slingloaddownext_soundset","jsrs_2025_helicopter_slingloadupext_soundset","jsrs_2025_helicopter_rainext_soundset"};
		};
		class SoundsExt
		{
			class SoundEvents{};
			class Sounds
			{
				class TransmissionDamageExt_phase1 { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
				class TransmissionDamageExt_phase2 { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
				class TransmissionDamageInt_phase1 { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
				class TransmissionDamageInt_phase2 { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
				class damageAlarm { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
				class scrubLandInt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
				class scrubLandExt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
				class scrubBuildingInt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
				class scrubBuildingExt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
				class scrubTreeInt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
				class scrubTreeExt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
				class RainExt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
				class RainInt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
				class SlingLoadDownExt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
				class SlingLoadUpExt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
				class SlingLoadDownInt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
				class SlingLoadUpInt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
				class WindInt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
				class GStress { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
				class SpeedStress { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
				class engineext
				{
					sound[] = {"z\jsrs2025\addons\sounds_air\sounds\helicopters\uh80_ghosthawk\turbine_ext_close.ogg",1.4,1,400};
					frequency = "rotorspeed * (1-rotorthrust/15) * 1.25";
					volume = "campos*((rotorspeed-0.72)*4)";
				};
				class rotorext
				{
					sound[] = {"z\jsrs2025\addons\sounds_air\sounds\helicopters\uh80_ghosthawk\rotor_ext_close.ogg",1,1,700};
					frequency = "rotorspeed * (1-rotorthrust/15) * 1.25";
					volume = "1*campos*(0 max (rotorspeed-0.5))*(1 + rotorthrust)";
					cone[] = {1.6,3.14,1.6,0.95};
				};
				class engineextdist
				{
					sound[] = {"z\jsrs2025\addons\sounds_air\sounds\helicopters\uh80_ghosthawk\turbine_ext_distance.ogg",1,1,1000};
					frequency = "rotorspeed * (1-rotorthrust/15) * 1.25";
					volume = "campos*((rotorspeed-0.72)*4)";
				};
				class rotorextdist
				{
					sound[] = {"z\jsrs2025\addons\sounds_air\sounds\helicopters\uh80_ghosthawk\rotor_ext_distance.ogg",1,1,3000};
					frequency = "rotorspeed * (1-rotorthrust/15) * 1.25";
					volume = "1*campos*(0 max (rotorspeed-0.5))*(1 + rotorthrust)";
					cone[] = {1.6,3.14,1.6,0.95};
				};
				class rotornoiseext
				{
					sound[] = {"z\jsrs2025\addons\sounds_air\sounds\helicopters\uh80_ghosthawk\rotor_ext_distance.ogg",0,1,0};
					frequency = "rotorspeed* 1";
					volume = "campos * (rotorthrust factor [0.7,0.9])";
					cone[] = {0.7,1.3,1,0};
				};
				class engineint
				{
					sound[] = {"z\jsrs2025\addons\sounds_air\sounds\helicopters\uh80_ghosthawk\turbine_int.ogg",1,1};
					frequency = "1";
					volume = "(1-campos)*((rotorspeed-0.75)*3)";
				};
				class rotorint
				{
					sound[] = {"z\jsrs2025\addons\sounds_air\sounds\helicopters\uh80_ghosthawk\rotor_int.ogg",0.5011872,1};
					frequency = "rotorspeed * (1-rotorthrust/15) * 1.25";
					volume = "(1-campos)*(0 max (rotorspeed-0.5))*(1 + rotorthrust)";
				};
				soundsetsint[] = {"jsrs_2025_helicopter_uh60_blackhawk_engineint_soundset","jsrs_2025_helicopter_uh60_blackhawk_rotorint_soundset","jsrs_2025_helicopter_transmissiondamageint_phase1_soundset","jsrs_2025_helicopter_transmissiondamageint_phase2_soundset","jsrs_2025_helicopter_damagealarmint_soundset","jsrs_2025_helicopter_rotorlowalarmint_soundset","jsrs_2025_helicopter_scrublandint_soundset","jsrs_2025_helicopter_scrubbuildingint_soundset","jsrs_2025_helicopter_scrubtreeint_soundset","jsrs_2025_helicopter_slingloaddownint_soundset","jsrs_2025_helicopter_slingloadupint_soundset","jsrs_2025_helicopter_rainint_soundset","jsrs_2025_helicopter_windint_soundset","jsrs_2025_helicopter_uh60_blackhawk_gstress_soundset"};
				soundsetsext[] = {"jsrs_2025_helicopter_uh60_blackhawk_engineext_soundset","jsrs_2025_helicopter_uh60_blackhawk_rotorext_soundset","jsrs_2025_helicopter_uh60_blackhawk_evr_soundset","jsrs_2025_helicopter_uh60_blackhawk_rotordistance_soundset","jsrs_2025_helicopter_uh60_blackhawk_enginedistance_soundset","jsrs_2025_helicopter_transmissiondamageext_phase1_soundset","jsrs_2025_helicopter_transmissiondamageext_phase2_soundset","jsrs_2025_helicopter_scrublandext_soundset","jsrs_2025_helicopter_scrubbuildingext_soundset","jsrs_2025_helicopter_scrubtreeext_soundset","jsrs_2025_helicopter_slingloaddownext_soundset","jsrs_2025_helicopter_slingloadupext_soundset","jsrs_2025_helicopter_rainext_soundset"};
			};
		};
	};
	class ADFRC_chinook: ADFRC_chinook_base
	{
		// JSRS sounds from RHS_CH_47F_base (JSRS compat_rhs_usf)
		class Sounds
		{
			class Engine { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class RotorLowOut { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class RotorHighOut { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class EngineIn { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class RotorLowIn { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class RotorHighIn { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class TransmissionDamageExt_phase1 { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class TransmissionDamageExt_phase2 { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class TransmissionDamageInt_phase1 { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class TransmissionDamageInt_phase2 { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class damageAlarmInt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class damageAlarmExt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class rotorLowAlarmInt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class rotorLowAlarmExt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class scrubLandInt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class scrubLandExt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class scrubBuildingInt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class scrubBuildingExt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class scrubTreeInt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class scrubTreeExt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class RainExt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class RainInt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class SlingLoadDownExt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class SlingLoadUpExt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class SlingLoadDownInt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class SlingLoadUpInt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class WindInt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class GStress { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class SpeedStress { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class engineext
			{
				sound[] = {"z\jsrs2025\addons\sounds_air\sounds\helicopters\ch67_huron\turbine_ext_close.ogg",1.4,1,400};
				frequency = "rotorspeed * (1-rotorthrust/15) * 1.25";
				volume = "campos*((rotorspeed-0.72)*4)";
			};
			class rotorext
			{
				sound[] = {"z\jsrs2025\addons\sounds_air\sounds\helicopters\ch67_huron\rotor_ext_close.ogg",1,1,700};
				frequency = "rotorspeed * (1-rotorthrust/15) * 1.25";
				volume = "1*campos*(0 max (rotorspeed-0.5))*(1 + rotorthrust)";
				cone[] = {1.6,3.14,1.6,0.95};
			};
			class engineextdist
			{
				sound[] = {"z\jsrs2025\addons\sounds_air\sounds\helicopters\ch67_huron\turbine_ext_distance.ogg",1,1,1000};
				frequency = "rotorspeed * (1-rotorthrust/15) * 1.25";
				volume = "campos*((rotorspeed-0.72)*4)";
			};
			class rotorextdist
			{
				sound[] = {"z\jsrs2025\addons\sounds_air\sounds\helicopters\ch67_huron\rotor_ext_distance.ogg",1,1,3000};
				frequency = "rotorspeed * (1-rotorthrust/15) * 1.25";
				volume = "1*campos*(0 max (rotorspeed-0.5))*(1 + rotorthrust)";
				cone[] = {1.6,3.14,1.6,0.95};
			};
			class rotornoiseext
			{
				sound[] = {"z\jsrs2025\addons\sounds_air\sounds\helicopters\ch67_huron\rotor_ext_distance.ogg",0,1,0};
				frequency = "rotorspeed* 1";
				volume = "campos * (rotorthrust factor [0.7,0.9])";
				cone[] = {0.7,1.3,1,0};
			};
			class engineint
			{
				sound[] = {"z\jsrs2025\addons\sounds_air\sounds\helicopters\ch67_huron\turbine_int.ogg",1,1};
				frequency = "1";
				volume = "(1-campos)*((rotorspeed-0.75)*3)";
			};
			class rotorint
			{
				sound[] = {"z\jsrs2025\addons\sounds_air\sounds\helicopters\ch67_huron\rotor_int.ogg",0.5011872,1};
				frequency = "rotorspeed * (1-rotorthrust/15) * 1.25";
				volume = "(1-campos)*(0 max (rotorspeed-0.5))*(1 + rotorthrust)";
			};
			soundsetsint[] = {"jsrs_2025_helicopter_ch47_chinook_engineint_soundset","jsrs_2025_helicopter_ch47_chinook_rotorint_soundset","jsrs_2025_helicopter_transmissiondamageint_phase1_soundset","jsrs_2025_helicopter_transmissiondamageint_phase2_soundset","jsrs_2025_helicopter_damagealarmint_soundset","jsrs_2025_helicopter_rotorlowalarmint_soundset","jsrs_2025_helicopter_scrublandint_soundset","jsrs_2025_helicopter_scrubbuildingint_soundset","jsrs_2025_helicopter_scrubtreeint_soundset","jsrs_2025_helicopter_slingloaddownint_soundset","jsrs_2025_helicopter_slingloadupint_soundset","jsrs_2025_helicopter_rainint_soundset","jsrs_2025_helicopter_windint_soundset","jsrs_2025_helicopter_ch47_chinook_gstress_soundset"};
			soundsetsext[] = {"jsrs_2025_helicopter_ch47_chinook_engineext_soundset","jsrs_2025_helicopter_ch47_chinook_rotorext_soundset","jsrs_2025_helicopter_ch47_chinook_evr_soundset","jsrs_2025_helicopter_ch47_chinook_rotordistance_soundset","jsrs_2025_helicopter_ch47_chinook_enginedistance_soundset","jsrs_2025_helicopter_transmissiondamageext_phase1_soundset","jsrs_2025_helicopter_transmissiondamageext_phase2_soundset","jsrs_2025_helicopter_scrublandext_soundset","jsrs_2025_helicopter_scrubbuildingext_soundset","jsrs_2025_helicopter_scrubtreeext_soundset","jsrs_2025_helicopter_slingloaddownext_soundset","jsrs_2025_helicopter_slingloadupext_soundset","jsrs_2025_helicopter_rainext_soundset"};
		};
		class SoundsExt
		{
			class SoundEvents{};
			class Sounds
			{
				class TransmissionDamageExt_phase1 { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
				class TransmissionDamageExt_phase2 { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
				class TransmissionDamageInt_phase1 { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
				class TransmissionDamageInt_phase2 { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
				class damageAlarmInt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
				class damageAlarmExt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
				class rotorLowAlarmInt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
				class rotorLowAlarmExt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
				class scrubLandInt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
				class scrubLandExt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
				class scrubBuildingInt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
				class scrubBuildingExt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
				class scrubTreeInt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
				class scrubTreeExt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
				class RainExt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
				class RainInt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
				class SlingLoadDownExt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
				class SlingLoadUpExt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
				class SlingLoadDownInt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
				class SlingLoadUpInt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
				class WindInt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
				class GStress { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
				class SpeedStress { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
				class engineext
				{
					sound[] = {"z\jsrs2025\addons\sounds_air\sounds\helicopters\ch67_huron\turbine_ext_close.ogg",1.4,1,400};
					frequency = "rotorspeed * (1-rotorthrust/15) * 1.25";
					volume = "campos*((rotorspeed-0.72)*4)";
				};
				class rotorext
				{
					sound[] = {"z\jsrs2025\addons\sounds_air\sounds\helicopters\ch67_huron\rotor_ext_close.ogg",1,1,700};
					frequency = "rotorspeed * (1-rotorthrust/15) * 1.25";
					volume = "1*campos*(0 max (rotorspeed-0.5))*(1 + rotorthrust)";
					cone[] = {1.6,3.14,1.6,0.95};
				};
				class engineextdist
				{
					sound[] = {"z\jsrs2025\addons\sounds_air\sounds\helicopters\ch67_huron\turbine_ext_distance.ogg",1,1,1000};
					frequency = "rotorspeed * (1-rotorthrust/15) * 1.25";
					volume = "campos*((rotorspeed-0.72)*4)";
				};
				class rotorextdist
				{
					sound[] = {"z\jsrs2025\addons\sounds_air\sounds\helicopters\ch67_huron\rotor_ext_distance.ogg",1,1,3000};
					frequency = "rotorspeed * (1-rotorthrust/15) * 1.25";
					volume = "1*campos*(0 max (rotorspeed-0.5))*(1 + rotorthrust)";
					cone[] = {1.6,3.14,1.6,0.95};
				};
				class rotornoiseext
				{
					sound[] = {"z\jsrs2025\addons\sounds_air\sounds\helicopters\ch67_huron\rotor_ext_distance.ogg",0,1,0};
					frequency = "rotorspeed* 1";
					volume = "campos * (rotorthrust factor [0.7,0.9])";
					cone[] = {0.7,1.3,1,0};
				};
				class engineint
				{
					sound[] = {"z\jsrs2025\addons\sounds_air\sounds\helicopters\ch67_huron\turbine_int.ogg",1,1};
					frequency = "1";
					volume = "(1-campos)*((rotorspeed-0.75)*3)";
				};
				class rotorint
				{
					sound[] = {"z\jsrs2025\addons\sounds_air\sounds\helicopters\ch67_huron\rotor_int.ogg",0.5011872,1};
					frequency = "rotorspeed * (1-rotorthrust/15) * 1.25";
					volume = "(1-campos)*(0 max (rotorspeed-0.5))*(1 + rotorthrust)";
				};
				soundsetsint[] = {"jsrs_2025_helicopter_ch67_huron_engineint_soundset","jsrs_2025_helicopter_ch67_huron_rotorint_soundset","jsrs_2025_helicopter_transmissiondamageint_phase1_soundset","jsrs_2025_helicopter_transmissiondamageint_phase2_soundset","jsrs_2025_helicopter_damagealarmint_soundset","jsrs_2025_helicopter_rotorlowalarmint_soundset","jsrs_2025_helicopter_scrublandint_soundset","jsrs_2025_helicopter_scrubbuildingint_soundset","jsrs_2025_helicopter_scrubtreeint_soundset","jsrs_2025_helicopter_slingloaddownint_soundset","jsrs_2025_helicopter_slingloadupint_soundset","jsrs_2025_helicopter_rainint_soundset","jsrs_2025_helicopter_windint_soundset","jsrs_2025_helicopter_ch67_huron_gstress_soundset"};
				soundsetsext[] = {"jsrs_2025_helicopter_ch67_huron_engineext_soundset","jsrs_2025_helicopter_ch67_huron_rotorext_soundset","jsrs_2025_helicopter_ch67_huron_evr_soundset","jsrs_2025_helicopter_ch67_huron_rotordistance_soundset","jsrs_2025_helicopter_ch67_huron_enginedistance_soundset","jsrs_2025_helicopter_transmissiondamageext_phase1_soundset","jsrs_2025_helicopter_transmissiondamageext_phase2_soundset","jsrs_2025_helicopter_scrublandext_soundset","jsrs_2025_helicopter_scrubbuildingext_soundset","jsrs_2025_helicopter_scrubtreeext_soundset","jsrs_2025_helicopter_slingloaddownext_soundset","jsrs_2025_helicopter_slingloadupext_soundset","jsrs_2025_helicopter_rainext_soundset"};
			};
		};
	};
	class adfrc_apache_base: Helicopter_Base_F
	{
		// JSRS sounds from RHS_AH64_base (JSRS compat_rhs_usf)
		class Sounds
		{
			class RotorSwist { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class TransmissionDamageExt_phase1 { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class TransmissionDamageExt_phase2 { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class TransmissionDamageInt_phase1 { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class TransmissionDamageInt_phase2 { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class damageAlarmInt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class damageAlarmExt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class rotorLowAlarmInt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class rotorLowAlarmExt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class scrubLandInt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class scrubLandExt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class scrubBuildingInt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class scrubBuildingExt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class scrubTreeInt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class scrubTreeExt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class RainExt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class RainInt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class SlingLoadDownExt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class SlingLoadUpExt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class SlingLoadDownInt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class SlingLoadUpInt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class WindInt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class GStress { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class engineext
			{
				sound[] = {"z\jsrs2025\addons\sounds_air\sounds\helicopters\AH64_Apache\turbine_ext_close.ogg",1.4,1,400};
				frequency = "rotorspeed * (1-rotorthrust/15) * 1.25";
				volume = "campos*((rotorspeed-0.72)*4)";
			};
			class rotorext
			{
				sound[] = {"z\jsrs2025\addons\sounds_air\sounds\helicopters\AH64_Apache\rotor_ext_close.ogg",1,1,700};
				frequency = "rotorspeed * (1-rotorthrust/15) * 1.25";
				volume = "1*campos*(0 max (rotorspeed-0.5))*(1 + rotorthrust)";
				cone[] = {1.6,3.14,1.6,0.95};
			};
			class engineextdist
			{
				sound[] = {"z\jsrs2025\addons\sounds_air\sounds\helicopters\AH64_Apache\turbine_ext_distance.ogg",1,1,1000};
				frequency = "rotorspeed * (1-rotorthrust/15) * 1.25";
				volume = "campos*((rotorspeed-0.72)*4)";
			};
			class rotorextdist
			{
				sound[] = {"z\jsrs2025\addons\sounds_air\sounds\helicopters\AH64_Apache\rotor_ext_distance.ogg",1,1,3000};
				frequency = "rotorspeed * (1-rotorthrust/15) * 1.25";
				volume = "1*campos*(0 max (rotorspeed-0.5))*(1 + rotorthrust)";
				cone[] = {1.6,3.14,1.6,0.95};
			};
			class rotornoiseext
			{
				sound[] = {"z\jsrs2025\addons\sounds_air\sounds\helicopters\AH64_Apache\rotor_ext_distance.ogg",0,1,0};
				frequency = "rotorspeed* 1";
				volume = "campos * (rotorthrust factor [0.7,0.9])";
				cone[] = {0.7,1.3,1,0};
			};
			class engineint
			{
				sound[] = {"z\jsrs2025\addons\sounds_air\sounds\helicopters\AH64_Apache\turbine_int.ogg",1,1};
				frequency = "1";
				volume = "(1-campos)*((rotorspeed-0.75)*3)";
			};
			class rotorint
			{
				sound[] = {"z\jsrs2025\addons\sounds_air\sounds\helicopters\AH64_Apache\rotor_int.ogg",0.5011872,1};
				frequency = "rotorspeed * (1-rotorthrust/15) * 1.25";
				volume = "(1-campos)*(0 max (rotorspeed-0.5))*(1 + rotorthrust)";
			};
			soundsetsint[] = {"jsrs_2025_helicopter_AH64_Apache_engineint_soundset","jsrs_2025_helicopter_AH64_Apache_rotorint_soundset","jsrs_2025_helicopter_transmissiondamageint_phase1_soundset","jsrs_2025_helicopter_transmissiondamageint_phase2_soundset","jsrs_2025_helicopter_damagealarmint_soundset","jsrs_2025_helicopter_rotorlowalarmint_soundset","jsrs_2025_helicopter_scrublandint_soundset","jsrs_2025_helicopter_scrubbuildingint_soundset","jsrs_2025_helicopter_scrubtreeint_soundset","jsrs_2025_helicopter_slingloaddownint_soundset","jsrs_2025_helicopter_slingloadupint_soundset","jsrs_2025_helicopter_rainint_soundset","jsrs_2025_helicopter_windint_soundset","jsrs_2025_helicopter_AH64_Apache_gstress_soundset"};
			soundsetsext[] = {"jsrs_2025_helicopter_AH64_Apache_engineext_soundset","jsrs_2025_helicopter_AH64_Apache_rotorext_soundset","jsrs_2025_helicopter_AH64_Apache_evr_soundset","jsrs_2025_helicopter_AH64_Apache_rotordistance_soundset","jsrs_2025_helicopter_AH64_Apache_enginedistance_soundset","jsrs_2025_helicopter_transmissiondamageext_phase1_soundset","jsrs_2025_helicopter_transmissiondamageext_phase2_soundset","jsrs_2025_helicopter_scrublandext_soundset","jsrs_2025_helicopter_scrubbuildingext_soundset","jsrs_2025_helicopter_scrubtreeext_soundset","jsrs_2025_helicopter_slingloaddownext_soundset","jsrs_2025_helicopter_slingloadupext_soundset","jsrs_2025_helicopter_rainext_soundset"};
		};
		class SoundsExt
		{
			class SoundEvents{};
			class Sounds
			{
				class RotorSwist { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
				class TransmissionDamageExt_phase1 { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
				class TransmissionDamageExt_phase2 { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
				class TransmissionDamageInt_phase1 { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
				class TransmissionDamageInt_phase2 { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
				class damageAlarmInt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
				class damageAlarmExt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
				class rotorLowAlarmInt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
				class rotorLowAlarmExt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
				class scrubLandInt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
				class scrubLandExt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
				class scrubBuildingInt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
				class scrubBuildingExt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
				class scrubTreeInt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
				class scrubTreeExt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
				class RainExt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
				class RainInt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
				class SlingLoadDownExt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
				class SlingLoadUpExt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
				class SlingLoadDownInt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
				class SlingLoadUpInt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
				class WindInt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
				class GStress { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
				class engineext
				{
					sound[] = {"z\jsrs2025\addons\sounds_air\sounds\helicopters\AH64_Apache\turbine_ext_close.ogg",1.4,1,400};
					frequency = "rotorspeed * (1-rotorthrust/15) * 1.25";
					volume = "campos*((rotorspeed-0.72)*4)";
				};
				class rotorext
				{
					sound[] = {"z\jsrs2025\addons\sounds_air\sounds\helicopters\AH64_Apache\rotor_ext_close.ogg",1,1,700};
					frequency = "rotorspeed * (1-rotorthrust/15) * 1.25";
					volume = "1*campos*(0 max (rotorspeed-0.5))*(1 + rotorthrust)";
					cone[] = {1.6,3.14,1.6,0.95};
				};
				class engineextdist
				{
					sound[] = {"z\jsrs2025\addons\sounds_air\sounds\helicopters\AH64_Apache\turbine_ext_distance.ogg",1,1,1000};
					frequency = "rotorspeed * (1-rotorthrust/15) * 1.25";
					volume = "campos*((rotorspeed-0.72)*4)";
				};
				class rotorextdist
				{
					sound[] = {"z\jsrs2025\addons\sounds_air\sounds\helicopters\AH64_Apache\rotor_ext_distance.ogg",1,1,3000};
					frequency = "rotorspeed * (1-rotorthrust/15) * 1.25";
					volume = "1*campos*(0 max (rotorspeed-0.5))*(1 + rotorthrust)";
					cone[] = {1.6,3.14,1.6,0.95};
				};
				class rotornoiseext
				{
					sound[] = {"z\jsrs2025\addons\sounds_air\sounds\helicopters\AH64_Apache\rotor_ext_distance.ogg",0,1,0};
					frequency = "rotorspeed* 1";
					volume = "campos * (rotorthrust factor [0.7,0.9])";
					cone[] = {0.7,1.3,1,0};
				};
				class engineint
				{
					sound[] = {"z\jsrs2025\addons\sounds_air\sounds\helicopters\AH64_Apache\turbine_int.ogg",1,1};
					frequency = "1";
					volume = "(1-campos)*((rotorspeed-0.75)*3)";
				};
				class rotorint
				{
					sound[] = {"z\jsrs2025\addons\sounds_air\sounds\helicopters\AH64_Apache\rotor_int.ogg",0.5011872,1};
					frequency = "rotorspeed * (1-rotorthrust/15) * 1.25";
					volume = "(1-campos)*(0 max (rotorspeed-0.5))*(1 + rotorthrust)";
				};
				soundsetsint[] = {"jsrs_2025_helicopter_AH64_Apache_engineint_soundset","jsrs_2025_helicopter_AH64_Apache_rotorint_soundset","jsrs_2025_helicopter_transmissiondamageint_phase1_soundset","jsrs_2025_helicopter_transmissiondamageint_phase2_soundset","jsrs_2025_helicopter_damagealarmint_soundset","jsrs_2025_helicopter_rotorlowalarmint_soundset","jsrs_2025_helicopter_scrublandint_soundset","jsrs_2025_helicopter_scrubbuildingint_soundset","jsrs_2025_helicopter_scrubtreeint_soundset","jsrs_2025_helicopter_slingloaddownint_soundset","jsrs_2025_helicopter_slingloadupint_soundset","jsrs_2025_helicopter_rainint_soundset","jsrs_2025_helicopter_windint_soundset","jsrs_2025_helicopter_AH64_Apache_gstress_soundset"};
				soundsetsext[] = {"jsrs_2025_helicopter_AH64_Apache_engineext_soundset","jsrs_2025_helicopter_AH64_Apache_rotorext_soundset","jsrs_2025_helicopter_AH64_Apache_evr_soundset","jsrs_2025_helicopter_AH64_Apache_rotordistance_soundset","jsrs_2025_helicopter_AH64_Apache_enginedistance_soundset","jsrs_2025_helicopter_transmissiondamageext_phase1_soundset","jsrs_2025_helicopter_transmissiondamageext_phase2_soundset","jsrs_2025_helicopter_scrublandext_soundset","jsrs_2025_helicopter_scrubbuildingext_soundset","jsrs_2025_helicopter_scrubtreeext_soundset","jsrs_2025_helicopter_slingloaddownext_soundset","jsrs_2025_helicopter_slingloadupext_soundset","jsrs_2025_helicopter_rainext_soundset"};
			};
		};
	};
	class Plane_Transport_01_base_F: Plane_Base_F
	{
		// JSRS sounds from RHS_C130J_Base (JSRS compat_rhs_usf)
		class Sounds
		{
			class EngineMidhExt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class EngineHighExt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class ForsageExt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class EngineMidhInt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class EngineHighInt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class ForsageInt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class scrubLandInt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class scrubLandExt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class RainExt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class RainInt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class WindInt { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class GStress { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			class SpeedStress { sound[] = {"z\jsrs2025\addons\data\null.wss",0,1,0}; volume = "0"; };
			soundsets[] = {""};
			soundsetsint[] = {"jsrs_2025_C130_cockpit_idle_soundset","jsrs_2025_C130_cockpit_thrust_soundset","jsrs_2025_basic_plane_rain_internal_soundset"};
			soundsetsext[] = {"jsrs_2025_C130_idle_soundset","jsrs_2025_C130_thrust_soundset","jsrs_2025_C130_evr_soundset","jsrs_2025_basic_plane_rain_external_soundset","jsrs_2025_C130_plane_distance_front_soundset","jsrs_2025_C130_plane_distance_middle_soundset","jsrs_2025_C130_plane_distance_back_soundset"};
		};
	};
};
