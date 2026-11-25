class CfgMovesBasic {
	class ManActions {
		adfrc_bushmaster_gunner        = "adfrc_bushmaster_gunner_settlein";
		adfrc_bushmaster_driver        = "adfrc_bushmaster_driver";
		adfrc_bushmaster_ffv_front     = "adfrc_bushmaster_ffv_front_settlein";
		adfrc_bushmaster_ffv_rearleft  = "adfrc_bushmaster_ffv_left_settlein";
		adfrc_bushmaster_ffv_rearright = "adfrc_bushmaster_ffv_right_settlein";
	};
};

class CfgMovesMaleSdr : CfgMovesBasic {
	class States {

		//?
		//? Imports
		//?

		class Crew;
		class KIA_passenger_generic01;
		class passenger_generic01_foldhands_settlein;
		class passenger_generic01_foldhands;

		//?
		//? Animations
		//?

		class adfrc_bushmaster_driver : Crew {
			file               = "\adf_mrap\adfrc_bushmaster\data\anims\bushmaster_driver.rtm";

			speed              = -30;

			interpolateTo[]    = { "KIA_Driver_mid01", 1 };
			leftHandIKCurve[]  = { 1 };
			rightHandIKCurve[] = { 1 };
		};

		class adfrc_bushmaster_gunner_settlein : Crew {
			file               = "\a3\cargoposes_f\anim\gunner_mrap_01_settlein.rtm";

			looped             = 0;
			speed              = -1.5;
			useIdles           = 0;

			connectTo[]        = { "adfrc_bushmaster_gunner", 1 };
			interpolateTo[]    = { "KIA_gunner_MRAP_01", 1 };
			leftHandIKCurve[]  = { 0 };
			rightHandIKCurve[] = { 0 };
			variantAfter[]     = { 1.5, 1.5, 1.5 };
			variantsAI[]       = { "adfrc_bushmaster_gunner", 1 };
			variantsPlayer[]   = { "adfrc_bushmaster_gunner", 1 };
		};

		class adfrc_bushmaster_gunner : Crew {
			file            = "\adf_mrap\adfrc_bushmaster\data\anims\bushmaster_gunner_mocap.rtm";

			speed           = -30;

			interpolateTo[] = { "KIA_gunner_MRAP_01", 1 };
		};

		class adfrc_bushmaster_ffv_front_settlein : passenger_generic01_foldhands_settlein {
			file             = "\adf_mrap\adfrc_bushmaster\data\anims\bushmaster_ffv_front_settlein.rtm";

			looped           = 0;
			speed            = -1.5;

			connectTo[]      = { "adfrc_bushmaster_ffv_front", 1 };
			interpolateTo[]  = { "adfrc_bushmaster_ffv_front_kia", 1 };
			variantsAI[]     = { "adfrc_bushmaster_ffv_front", 1 };
			variantsPlayer[] = { "adfrc_bushmaster_ffv_front", 1 };
		};

		class adfrc_bushmaster_ffv_front_idle : passenger_generic01_foldhands {
			file            = "\adf_mrap\adfrc_bushmaster\data\anims\bushmaster_ffv_front_sitting.rtm";

			speed           = -30;

			interpolateTo[] = { "adfrc_bushmaster_ffv_front_kia", 1 };
		};

		class adfrc_bushmaster_ffv_front : passenger_generic01_foldhands {
			file            = "\adf_mrap\adfrc_bushmaster\data\anims\bushmaster_ffv_front_mocap.rtm";

			speed           = -30;

			interpolateTo[] = { "adfrc_bushmaster_ffv_front_kia", 1 };
		};

		class adfrc_bushmaster_ffv_front_kia : KIA_passenger_generic01 {
			file        = "\adf_mrap\adfrc_bushmaster\data\anims\bushmaster_ffv_front_kia.rtm";

			connectTo[] = { "Unconscious", 0.1 };
		};

		class adfrc_bushmaster_ffv_left_settlein : passenger_generic01_foldhands_settlein {
			file             = "\adf_mrap\adfrc_bushmaster\data\anims\bushmaster_ffv_left_settlein.rtm";

			looped           = 0;
			speed            = -1.5;

			connectTo[]      = { "adfrc_bushmaster_ffv_left", 1 };
			interpolateTo[]  = { "adfrc_bushmaster_ffv_left_kia", 1 };
			variantsAI[]     = { "adfrc_bushmaster_ffv_left", 1 };
			variantsPlayer[] = { "adfrc_bushmaster_ffv_left", 1 };
		};

		class adfrc_bushmaster_ffv_left_idle : passenger_generic01_foldhands {
			file            = "\adf_mrap\adfrc_bushmaster\data\anims\bushmaster_ffv_left_sitting.rtm";

			speed           = -30;

			interpolateTo[] = { "adfrc_bushmaster_ffv_left_kia", 1 };
		};

		class adfrc_bushmaster_ffv_left : passenger_generic01_foldhands {
			file            = "\adf_mrap\adfrc_bushmaster\data\anims\bushmaster_ffv_left_mocap.rtm";

			speed           = -30;

			interpolateTo[] = { "bushmaster_ffv_left_kia", 1 };
		};

		class adfrc_bushmaster_ffv_left_kia : KIA_passenger_generic01 {
			file        = "\adf_mrap\adfrc_bushmaster\data\anims\bushmaster_ffv_left_kia.rtm";

			connectTo[] = { "Unconscious", 0.1 };
		};

		class adfrc_bushmaster_ffv_right_settlein : passenger_generic01_foldhands_settlein {
			file             = "\adf_mrap\adfrc_bushmaster\data\anims\bushmaster_ffv_right_settlein.rtm";

			looped           = 0;
			speed            = -1.5;

			connectTo[]      = { "adfrc_bushmaster_ffv_right", 1 };
			interpolateTo[]  = { "adfrc_bushmaster_ffv_right_kia", 1 };
			variantsAI[]     = { "adfrc_bushmaster_ffv_right", 1 };
			variantsPlayer[] = { "adfrc_bushmaster_ffv_right", 1 };
		};

		class adfrc_bushmaster_ffv_right_idle : passenger_generic01_foldhands {
			file            = "\adf_mrap\adfrc_bushmaster\data\anims\bushmaster_ffv_right_sitting.rtm";

			speed           = -30;

			interpolateTo[] = { "adfrc_bushmaster_ffv_right_kia", 1 };
		};

		class adfrc_bushmaster_ffv_right : passenger_generic01_foldhands {
			file            = "\adf_mrap\adfrc_bushmaster\data\anims\bushmaster_ffv_right_mocap.rtm";

			speed           = -30;

			interpolateTo[] = { "adfrc_bushmaster_ffv_right_kia", 1 };
		};

		class adfrc_bushmaster_ffv_right_kia : KIA_passenger_generic01 {
			file        = "\adf_mrap\adfrc_bushmaster\data\anims\bushmaster_ffv_right_kia.rtm";

			connectTo[] = { "Unconscious", 0.1 };
		};
	};
};