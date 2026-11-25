	// Fixed: the MAG58 fires "FullAuto" (close/short/medium/far_* inherit it), not "manual".
	class adfrc_mag58: Rifle_Long_Base_F
	{
		nullbullet[] = {"z\jsrs2025\addons\data\null.wss",0,1,0};
		soundbullet[] = {"nullbullet",1};
		drySound[] = {"z\jsrs2025\addons\sounds_weapons\sounds\mechanics\lmg_dry.wss",1,1,10};
		changeFiremodeSound[] = {"z\jsrs2025\addons\sounds_weapons\sounds\mechanics\lmg_firemode.wss",1,1,10};
		reloadmagazinesound[] = {"z\jsrs2025\addons\sounds_weapons\sounds\mechanics\reloads\lmg_navid_reload.wss",2,1,35};
		class FullAuto: Mode_FullAuto
		{
			class StandardSound
			{
				soundsetshot[] = {"jsrs_2025_m240_shot_soundset","jsrs_2025_tailsystem_762mm_lmg_soundset"};
			};
		};
	};
