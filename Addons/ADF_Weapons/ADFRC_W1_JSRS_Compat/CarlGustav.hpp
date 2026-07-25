	class Launcher_Base_F;
	class ADFRC_carlgustav_m3: Launcher_Base_F
	{
		soundfly[] = {"z\jsrs2025\addons\sounds_weapons\sounds\launchers\rocket_fly.wss",1,1,2500};
		drysound[] = {"z\jsrs2025\addons\sounds_weapons\sounds\mechanics\launcher_dry.wss",1,1,10};
		changefiremodesound[] = {"z\jsrs2025\addons\sounds_weapons\sounds\mechanics\launcher_firemode.wss",1,1,10};
		reloadmagazinesound[] = {"z\jsrs2025\addons\sounds_weapons\sounds\mechanics\reloads\launcher_mraws_reload.wss",2,1,35};
		class Single: Mode_SemiAuto
		{
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				soundsetshot[] = {"jsrs_2025_debris_dust_soundset","jsrs_2025_mraws_shot_soundset","jsrs_2025_tailsystem_Launcher_soundset"};
			};
		};
	};