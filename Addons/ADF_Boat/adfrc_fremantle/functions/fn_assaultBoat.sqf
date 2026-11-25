/*
    adfrc_fremantle_fnc_assaultBoat

    Deploy or recover the Fremantle's stowed Assault Boat. Called from the
    ship's UserActions, which only show for the driver or the captain.

    The caller checks there is a boat to recover (so they get the hint),
    then the work is routed to the server: spawn / delete the boat and
    hide / show the stowed proxy (user source assaultboat_deployed).

    Params:
        0: SHIP <OBJECT>
        1: MODE <STRING>   "deploy" | "recover"
        2: SERVER SIDE <BOOL> (internal, default false)

    Returns: nothing
*/
params [["_ship", objNull, [objNull]], ["_mode", "", [""]], ["_serverSide", false, [false]]];

if (isNull _ship || !(_mode in ["deploy", "recover"])) exitWith {};

// nearest empty Assault Boat within 30 m of the stern launch point
private _fnc_findBoat = {
    params ["_ship"];
    private _launch = _ship modelToWorld (_ship selectionPosition ["boat_launch", "Memory"]);
    private _boats = (nearestObjects [_launch, ["Rubber_duck_base_F"], 30]) select {
        alive _x && {(crew _x) findIf {alive _x} == -1}
    };
    if (_boats isEqualTo []) then {objNull} else {_boats select 0}
};

if (!_serverSide) exitWith {
    if (_mode == "recover" && {isNull ([_ship] call _fnc_findBoat)}) exitWith {
        hint "No empty Assault Boat within 30 m of the stern to recover.";
    };
    [_ship, _mode, true] remoteExecCall ["adfrc_fremantle_fnc_assaultBoat", 2];
};

// ---- server
if (_mode == "deploy") exitWith {
    if (_ship animationSourcePhase "assaultboat_deployed" > 0.5) exitWith {};
    private _launch = _ship modelToWorldWorld (_ship selectionPosition ["boat_launch", "Memory"]);
    private _boat = createVehicle ["adfrc_rhib", [0, 0, 0], [], 0, "CAN_COLLIDE"];
    _boat setDir (getDir _ship);
    _boat setPosASL [_launch select 0, _launch select 1, 0.4];
    _boat setVelocity (velocity _ship);
    _ship animateSource ["assaultboat_deployed", 1, true];
};

// recover
private _boat = [_ship] call _fnc_findBoat;
if (isNull _boat) exitWith {};
deleteVehicle _boat;
_ship animateSource ["assaultboat_deployed", 0, true];
