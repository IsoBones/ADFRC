// ADF Re-Cut: JSRS SOUNDMOD 2025 compatibility (wheeled).
// Same rules as ADF_Ace: only ADFRC classes are patched, vanilla classes are only
// forward-declared. skipWhenMissingDependencies = 1, so if JSRS or any addon listed
// here is missing (or misspelled) this config is silently skipped. Check the RPT.
class CfgPatches
{
	class ADFRC_JSRS_Wheeled
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"jsrs2025_config_c", "adfrc_boxer"};
		skipWhenMissingDependencies = 1;
		author = "ADF Re-Cut";
	};
};

// ASLAV, Boxer and HEMTT already get JSRS through their vanilla parents (the same Gorgon
// set JSRS uses for its own LAV-25 patch, and JSRS's HEMTT set), so only the Boxer gun is here.
class CfgWeapons
{
	class CannonCore;
	// Nested forward declaration only (same parent as vanilla, no properties): rapify needs
	// "player" visible here for the "class player: player" lines below.
	class autocannon_Base_F: CannonCore
	{
		class player;
	};
	class autocannon_40mm_CTWS;
	// Boxer 30mm: what JSRS uses for the vanilla 30mm autocannon (close/short/medium/far inherit player)
	class ADFRC_boxer_mk30: autocannon_40mm_CTWS
	{
		class HE: autocannon_Base_F
		{
			class player: player
			{
				class StandardSound
				{
					soundsetshot[] = {"jsrs_2025_autocannon_small_shot_soundset","jsrs_2025_tailsystem_Autocannon_soundset"};
				};
			};
		};
		class AP: autocannon_Base_F
		{
			class player: player
			{
				class StandardSound
				{
					soundsetshot[] = {"jsrs_2025_autocannon_small_shot_soundset","jsrs_2025_tailsystem_Autocannon_soundset"};
				};
			};
		};
	};
};
