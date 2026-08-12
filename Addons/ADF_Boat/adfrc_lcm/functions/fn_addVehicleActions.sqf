/*
    adfrc_lcm_fnc_addVehicleActions

    Adds the tie-down / release scroll actions to a vehicle. Attached to all
    vehicles via a CBA class init event handler (see preInit) so the driver
    sees the action in their own scroll menu while seated - an addAction on the
    boat would not reach a player sealed inside a vehicle.

    The action finds the nearest LCM in range at evaluation time, so no boat
    reference needs to be wired up front.

    Params (from class init EH):
        0: VEHICLE <OBJECT>

    Returns: nothing
*/
params ["_veh"];

if (!hasInterface) exitWith {};

// don't add to the LCM itself or to non-vehicles
if (_veh isKindOf "adfrc_lcm_base") exitWith {};
if !(_veh isKindOf "LandVehicle") exitWith {};   // cars, tanks, APCs; skip men/boats/air by default

// guard against double-add (JIP + init both firing)
if (_veh getVariable ["adfrc_lcm_actionsAdded", false]) exitWith {};
_veh setVariable ["adfrc_lcm_actionsAdded", true];

_veh addAction [
    "<t color='#8cff9b'>Tie Down to Landing Craft</t>",
    {
        params ["_veh", "_caller", "_actionId", "_args"];
        private _boat = [_veh] call adfrc_lcm_fnc_nearestLCM;
        if (isNull _boat) exitWith { hint "No landing craft in range"; };
        [_boat, _veh] call adfrc_lcm_fnc_tieDown;
    },
    nil,
    1.5,
    false,
    true,
    "",
    "
        _this == (driver _target) &&
        {!(_target getVariable ['adfrc_tiedDown', false])} &&
        {!isNull ([_target] call adfrc_lcm_fnc_nearestLCM)}
    ",
    -1
];

_veh addAction [
    "<t color='#ff8c8c'>Release from Landing Craft</t>",
    {
        params ["_veh", "_caller", "_actionId", "_args"];
        [_veh] call adfrc_lcm_fnc_untie;
    },
    nil,
    1.5,
    false,
    true,
    "",
    "
        _this == (driver _target) &&
        {_target getVariable ['adfrc_tiedDown', false]}
    ",
    -1
];
