
	class ADFRC_M4A5_556_Base: Rifle_Base_F
    {
		nullbullet[] = {"z\jsrs2025\addons\data\null.wss",0,1,0};
		soundbullet[] = {"nullbullet",1};
		drySound[] = {"z\jsrs2025\addons\sounds_weapons\sounds\mechanics\ar_dry.wss",1,1,10};
		changeFiremodeSound[] = {"z\jsrs2025\addons\sounds_weapons\sounds\mechanics\ar_firemode.wss",1,1,10};
		reloadmagazinesound[] = {"z\jsrs2025\addons\sounds_weapons\sounds\mechanics\reloads\rifle_spar_reload.wss",2,1,35};
		class single: mode_semiauto
		{
			class basesoundmodetype;
			class standardsound: basesoundmodetype
			{
				soundsetshot[] = {"jsrs_2025_spar_shot_soundset","jsrs_2025_556mm_tails_soundset","jsrs_2025_556mm_echo_soundset"};
			};
			class silencedsound: basesoundmodetype
			{
				soundsetshot[] = {"jsrs_2025_spar_shot_silenced_soundset","jsrs_2025_556mm_silenced_tails_soundset"};
			};
		};
		class fullauto: mode_fullauto
		{
			class basesoundmodetype;
			class standardsound: basesoundmodetype
			{
				soundsetshot[] = {"jsrs_2025_spar_shot_soundset","jsrs_2025_556mm_tails_soundset","jsrs_2025_556mm_echo_soundset"};
			};
			class silencedsound: basesoundmodetype
			{
				soundsetshot[] = {"jsrs_2025_spar_shot_silenced_soundset","jsrs_2025_556mm_silenced_tails_soundset"};
			};
		};	
};
class ADFRC_M4A5_556_GLBase: Rifle_Base_F
    {
		nullbullet[] = {"z\jsrs2025\addons\data\null.wss",0,1,0};
		soundbullet[] = {"nullbullet",1};
		drySound[] = {"z\jsrs2025\addons\sounds_weapons\sounds\mechanics\ar_dry.wss",1,1,10};
		changeFiremodeSound[] = {"z\jsrs2025\addons\sounds_weapons\sounds\mechanics\ar_firemode.wss",1,1,10};
		reloadmagazinesound[] = {"z\jsrs2025\addons\sounds_weapons\sounds\mechanics\reloads\rifle_spar_reload.wss",2,1,35};
		class single: mode_semiauto
		{
			class basesoundmodetype;
			class standardsound: basesoundmodetype
			{
				soundsetshot[] = {"jsrs_2025_spar_shot_soundset","jsrs_2025_556mm_tails_soundset","jsrs_2025_556mm_echo_soundset"};
			};
			class silencedsound: basesoundmodetype
			{
				soundsetshot[] = {"jsrs_2025_spar_shot_silenced_soundset","jsrs_2025_556mm_silenced_tails_soundset"};
			};
		};
		class fullauto: mode_fullauto
		{
			class basesoundmodetype;
			class standardsound: basesoundmodetype
			{
				soundsetshot[] = {"jsrs_2025_spar_shot_soundset","jsrs_2025_556mm_tails_soundset","jsrs_2025_556mm_echo_soundset"};
			};
			class silencedsound: basesoundmodetype
			{
				soundsetshot[] = {"jsrs_2025_spar_shot_silenced_soundset","jsrs_2025_556mm_silenced_tails_soundset"};
			};
		};	
};