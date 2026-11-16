/*
    adfrc_lcm_fnc_hullDistance

    Horizontal distance (m) from an object to the edge of the LCM's bounding
    box, in the boat's model space. 0 when the object is over the hull
    footprint (on deck, or directly beside/under it).

    Used instead of plain `distance`, which measures to the model centre and
    makes range settings meaningless along a 20+ m hull.

    Params:
        0: OBJECT <OBJECT> - unit or vehicle
        1: BOAT   <OBJECT>

    Returns: <NUMBER> metres, or 1e10 if either object is null
*/
params ["_obj", "_boat"];

if (isNull _obj || isNull _boat) exitWith {1e10};

private _p = _boat worldToModel (ASLToAGL getPosASL _obj);
(boundingBoxReal _boat) params ["_min", "_max"];

private _dx = ((_min select 0) - (_p select 0)) max 0 max ((_p select 0) - (_max select 0));
private _dy = ((_min select 1) - (_p select 1)) max 0 max ((_p select 1) - (_max select 1));

sqrt (_dx * _dx + _dy * _dy)
