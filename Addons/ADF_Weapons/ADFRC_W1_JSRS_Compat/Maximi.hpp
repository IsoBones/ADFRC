	class ADFRC_maximi: ADFRC_minimi_BASE
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
				soundsetshot[] = {"jsrs_2025_mk200_shot_soundset","jsrs_2025_tailsystem_65mm_lmg_soundset"};
			};
			class SilencedSound: BaseSoundModeType
			{
				soundsetshot[] = {"jsrs_2025_mk200_shot_silenced_soundset","jsrs_2025_tailsystem_762mm_DMR_silenced_soundset"};
			};
		};
	};
