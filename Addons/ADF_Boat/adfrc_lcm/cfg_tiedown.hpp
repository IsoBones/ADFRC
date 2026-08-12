// cfg_tiedown.hpp
// Tie-down system config.
//
// Function tag note: BIS CfgFunctions names functions <TAG>_fnc_<name>, where
// TAG is the FIRST-level class below CfgFunctions. This must be "adfrc_lcm" so
// functions compile as adfrc_lcm_fnc_* (which is what all the SQF calls use).
// The second-level class (TieDown) is just a project subcategory and sets the
// shared source folder via "file".

class CfgFunctions
{
    class adfrc_lcm
    {
        class TieDown
        {
            file = "ADF_Boat\adfrc_lcm\functions";
            class preInit       { preInit = 1; };
            class tieDown       {};
            class untie         {};
            class boatInit          {};
            class addVehicleActions {};
            class nearestLCM        {};
            class board             {};
        };
    };
};
