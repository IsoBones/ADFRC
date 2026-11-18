	// Fixed: the old W1 compat patched a "manual" mode these guns don't have.
	// Modes are FullAuto + FullAutoDeployed; close/short/medium/far_* inherit FullAuto.
	class ADFRC_minimi_BASE: Rifle_Long_Base_F
	{
		JSRS_adsSound = "lmg";
		JSRS_magazineEmptySound = "lmg";
		JSRS_openBoltSound = "lmg";
		nullbullet[] = {"z\jsrs2025\addons\data\null.wss",0,1,0};
		soundbullet[] = {"nullbullet",1};
		class FullAuto: Mode_FullAuto
		{
			class StandardSound
			{
				soundsetshot[] = {"jsrs_2025_lim85_shot_soundset","jsrs_2025_tailsystem_556mm_lmg_soundset"};
			};
		};
		class FullAutoDeployed: Mode_SemiAuto
		{
			class StandardSound
			{
				soundsetshot[] = {"jsrs_2025_lim85_shot_soundset","jsrs_2025_tailsystem_556mm_lmg_soundset"};
			};
		};
	};
	class ADFRC_F89_Minimi: ADFRC_minimi_BASE
	{
		JSRS_adsSound = "lmg";
		JSRS_magazineEmptySound = "lmg";
		JSRS_openBoltSound = "lmg";
		nullbullet[] = {"z\jsrs2025\addons\data\null.wss",0,1,0};
		soundbullet[] = {"nullbullet",1};
		class FullAuto: Mode_FullAuto
		{
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				soundsetshot[] = {"jsrs_2025_lim85_shot_soundset","jsrs_2025_tailsystem_556mm_lmg_soundset"};
			};
			class SilencedSound: BaseSoundModeType
			{
				soundsetshot[] = {"jsrs_2025_lim85_shot_silenced_soundset","jsrs_2025_tailsystem_556mm_lmg_silenced_soundset"};
			};
		};
		class FullAutoDeployed: Mode_SemiAuto
		{
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				soundsetshot[] = {"jsrs_2025_lim85_shot_soundset","jsrs_2025_tailsystem_556mm_lmg_soundset"};
			};
			class SilencedSound: BaseSoundModeType
			{
				soundsetshot[] = {"jsrs_2025_lim85_shot_silenced_soundset","jsrs_2025_tailsystem_556mm_lmg_silenced_soundset"};
			};
		};
	};
