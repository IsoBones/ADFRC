
	class Rifle_Long_Base_F: Rifle_Base_F
	{};
	class ADFRC_minimi_BASE: Rifle_Long_Base_F
	{
		JSRS_adsSound = "lmg";
		JSRS_magazineEmptySound = "lmg";
		JSRS_openBoltSound = "lmg";
		nullbullet[] = {"z\jsrs2025\addons\data\null.wss",0,1,0};
		soundbullet[] = {"nullbullet",1};
		class manual: Mode_FullAuto
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
	class ADFRC_F89_Minimi: ADFRC_minimi_BASE
	{
		JSRS_adsSound = "lmg";
		JSRS_magazineEmptySound = "lmg";
		JSRS_openBoltSound = "lmg";
		nullbullet[] = {"z\jsrs2025\addons\data\null.wss",0,1,0};
		soundbullet[] = {"nullbullet",1};
		class manual: Mode_FullAuto
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
