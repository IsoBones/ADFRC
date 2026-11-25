class ADFRC_USP_Base : Pistol_Base_F
    {
		nullbullet[] = {"z\jsrs2025\addons\data\null.wss",0,1,0};
		soundbullet[] = {"nullbullet",1};
		class Single: Mode_SemiAuto
		{
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				soundsetshot[] = {"jsrs_2025_4five_shot_soundset","jsrs_2025_tailsystem_acp_pistol_soundset"};
			};
			class SilencedSound: BaseSoundModeType
			{
				soundsetshot[] = {"jsrs_2025_4five_shot_silenced_soundset","jsrs_2025_tailsystem_acp_pistol_silenced_soundset"};
			};
		};
};