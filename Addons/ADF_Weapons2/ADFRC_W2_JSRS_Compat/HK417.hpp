	class ADFRC_HK417_Base: Rifle_Base_F
    {
		nullbullet[] = {"z\jsrs2025\addons\data\null.wss",0,1,0};
		soundbullet[] = {"nullbullet",1};
		drySound[] = {"z\jsrs2025\addons\sounds_weapons\sounds\mechanics\ar_dry.wss",1,1,10};
		changeFiremodeSound[] = {"z\jsrs2025\addons\sounds_weapons\sounds\mechanics\ar_firemode.wss",1,1,10};
		reloadmagazinesound[] = {"z\jsrs2025\addons\sounds_weapons\sounds\mechanics\reloads\ar_reload_generic_1.wss",2,1,35};
		class Single: Mode_SemiAuto
		{
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				soundsetshot[] = {"jsrs_2025_spar17_shot_soundset","jsrs_2025_tailsystem_762mm_DMR_soundset"};
			};
			class SilencedSound: BaseSoundModeType
			{
				soundsetshot[] = {"jsrs_2025_spar17_shot_silenced_soundset","jsrs_2025_tailsystem_762mm_DMR_silenced_soundset"};
			};
		};
		class FullAuto: Mode_FullAuto
		{
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				soundsetshot[] = {"jsrs_2025_spar17_shot_soundset","jsrs_2025_tailsystem_762mm_DMR_soundset"};
			};
			class SilencedSound: BaseSoundModeType
			{
				soundsetshot[] = {"jsrs_2025_spar17_shot_silenced_soundset","jsrs_2025_tailsystem_762mm_DMR_silenced_soundset"};
			};
		};
};
