class CfgMovesBasic
{
	class DefaultDie;
	class ManActions
	{

		adfrc_LAV_Commander = "adfrc_LAV_Commander";
		adfrc_aslav25_commander_mg_out = "adfrc_aslav25_commander_mg_out";
	};
};
class CfgMovesMaleSdr: CfgMovesBasic
{
	class States
	{
		class Crew;
		class adfrc_aslav25_commander_mg_out: Crew
		{
			file="adf_wheeled\adfrc_aslav\data\Anim\adfrc_aslav25_commander_mg.rtm";
		};
	};	
};
/*class CfgMovesBasic 
{
    class ManActions 
    {
        adfrc_aslav25_commander_mg_out = "adfrc_aslav25_commander_mg_out_SettleIn";
        adfrc_Commander_LAV25_In = "adfrc_Commander_LAV25_In";
    };
};

class CfgMovesMaleSdr : CfgMovesBasic 
{
    class States 
    {
        class Crew;
        class Crew_Tank01_In;

        class aadfrc_aslav25_commander_in : Crew_Tank01_In
        {
			interpolateTo[] = 
			{ 
                "KIA_Crew_Tank01", 1, 
                "adfrc_aslav25_commander_mg_SettleIn", 1 
            };
        };

        class adfrc_aslav25_commander_mg_SettleIn : Crew 
        {
            file               = "\A3\cargoposes_F_exp\Anim\gunner_lsv02_settleIn.rtm";

            looped             = 0;
            speed              = 0.96774;
            useIdles           = 0;


            leftHandIKCurve[]  = { 0 };
            rightHandIKCurve[] = { 0 };

            variantAfter[]     = { 1.5, 1.5, 1.5 };
			
            variantsAI[]       = { "adfrc_aslav25_commander_mg_out", 1 };
            variantsPlayer[]   = { "adfrc_aslav25_commander_mg_out", 1 };
            connectTo[]        = { "adfrc_aslav25_commander_mg_out", 0.1 };
			interpolateTo[]    = { "gunner_lsv02_kia", 1 };
        };

        class adfrc_aslav25_commander_mg_out : Crew 
        {
            file            = "\ADF_Wheeled\adfrc_aslav\data\Anim\adfrc_aslav25_commander_mg.rtm";

            speed           = -11;

            interpolateTo[] = { 
                "gunner_lsv02_kia", 1, 
                "adfrc_Commander_LAV25_In", 1
            };
        };
    };
};

class CfgMovesBasic
{
    class ManActions
    {
        gunner_lsv_02="gunner_lsv_02_settlein";
    };
};

class CfgMovesMaleSdr: CfgMovesBasic
{
    class States
    {
        class gunner_lsv_02_settlein: Crew
        {
            file="\A3\cargoposes_F_exp\Anim\gunner_lsv02_settleIn.rtm";
            speed=0.96774;
            looped=0;
            connectTo[]=
            {
                "gunner_lsv_02",
                1
            };
            interpolateTo[]=
            {
                "gunner_lsv02_kia",
                1
            };
            variantsAI[]=
            {
                "gunner_lsv_02",
                1
            };
            variantsPlayer[]=
            {
                "gunner_lsv_02",
                1
            };
            variantAfter[]={1.5,1.5,1.5};
            useIdles=0;
            leftHandIKCurve[]={0};
            rightHandIKCurve[]={0};
        };
        class gunner_lsv_02: Crew
        {
            file="\A3\cargoposes_F_exp\Anim\gunner_lsv02.rtm";
            interpolateTo[]=
            {
                "gunner_lsv02_kia",
                1
            };
            speed=0.17341;
            variantAfter[]={5,5,5};
            leftHandIKCurve[]={1};
            rightHandIKCurve[]={1};
        };
        class gunner_lsv02_kia: DefaultDie
        {
            actions="DeadActions";
            file="\A3\cargoposes_F_exp\Anim\gunner_lsv02_kia.rtm";
            speed=0.19868;
            looped=0;
            terminal=1;
            soundEnabled=0;
            connectTo[]=
            {
                "Unconscious",
                0.1
            };
        };
    };
};*/