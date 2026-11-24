// adfrc_lrpv physx.hpp
// Based on the vanilla Hunter (MRAP_01_base_F) carx setup, scaled to the LRPV:
//  - engine power/torque scaled by mass ratio (4889 kg LRPV vs ~8264 kg Hunter sprung mass = 0.59)
//    so acceleration feels Hunter-like
//  - final drive scaled by wheel circumference (2.444 vs 3.924) so road speed per gear matches
//  - spring rate/damping keep the Hunter's natural frequency and damping ratio
// Mass comes from the Geometry LOD (4889 kg). Wheel radius 0.389 m measured from the model.
simulation = "carx";
thrustDelay = 0.1;
brakeIdleSpeed = 1.78;
maxSpeed = 110;
fuelCapacity = 26;
wheelCircumference = 2.444;
antiRollbarForceCoef = 12;
antiRollbarForceLimit = 10;
antiRollbarSpeedMin = 20;
antiRollbarSpeedMax = 50;
idleRpm = 800;
redRpm = 4500;
class complexGearbox
{
	GearboxRatios[] = {"R1",-3.182,"N",0,"D1",4.182,"D2",2.318,"D3",1.85,"D4",1.65,"D5",1.45};
	TransmissionRatios[] = {"High",3.45};
	gearBoxMode = "auto";
	moveOffGear = 1;
	driveString = "D";
	neutralString = "N";
	reverseString = "R";
};
dampersBumpCoef = 6.0;
// carx only exposes 4-wheel style diff types; see notes in the hand-over about rear-only drive
differentialType = "all_limited";
frontRearSplit = 0.5;
frontBias = 1.3;
rearBias = 1.3;
centreBias = 1.3;
clutchStrength = 20.0;
enginePower = 163;
maxOmega = 471;
peakTorque = 740;
dampingRateFullThrottle = 0.08;
dampingRateZeroThrottleClutchEngaged = 2.0;
dampingRateZeroThrottleClutchDisengaged = 0.35;
torqueCurve[] = {{0.0,0.0},{0.178,0.5},{0.25,0.85},{0.4,0.9},{0.5,1.0},{0.725,0.95},{0.85,0.6},{1.0,0.3}};
changeGearMinEffectivity[] = {0.95,0.15,0.95,0.95,0.95,0.95,0.95};
switchTime = 0.31;
latency = 1.0;
class Wheels
{
	class LF
	{
		boneName = "wheel_1_1_damper";
		steering = true;
		side = "left";
		center = "wheel_1_1_axis";
		boundary = "wheel_1_1_bound";
		mass = 50;
		MOI = 5;
		dampingRate = 0.1;
		dampingRateDamaged = 1.0;
		dampingRateDestroyed = 1000.0;
		maxBrakeTorque = 8000;
		maxHandBrakeTorque = 0;
		suspTravelDirection[] = {0,-1,0};
		suspForceAppPointOffset = "wheel_1_1_axis";
		tireForceAppPointOffset = "wheel_1_1_axis";
		maxCompression = 0.15;
		maxDroop = 0.15;
		sprungMass = 860;
		springStrength = 83800;
		springDamperRate = 8490;
		longitudinalStiffnessPerUnitGravity = 5000;
		latStiffX = 25;
		latStiffY = 180;
		frictionVsSlipGraph[] = {{0,1},{0.5,1},{1,1}};
	};
	class LM: LF
	{
		boneName = "wheel_1_2_damper";
		steering = false;
		center = "wheel_1_2_axis";
		boundary = "wheel_1_2_bound";
		suspForceAppPointOffset = "wheel_1_2_axis";
		tireForceAppPointOffset = "wheel_1_2_axis";
		maxHandBrakeTorque = 100000;
		sprungMass = 790;
		springStrength = 76950;
		springDamperRate = 7797;
	};
	class LR: LM
	{
		boneName = "wheel_1_3_damper";
		center = "wheel_1_3_axis";
		boundary = "wheel_1_3_bound";
		suspForceAppPointOffset = "wheel_1_3_axis";
		tireForceAppPointOffset = "wheel_1_3_axis";
	};
	class RF: LF
	{
		boneName = "wheel_2_1_damper";
		side = "right";
		center = "wheel_2_1_axis";
		boundary = "wheel_2_1_bound";
		suspForceAppPointOffset = "wheel_2_1_axis";
		tireForceAppPointOffset = "wheel_2_1_axis";
	};
	class RM: LM
	{
		boneName = "wheel_2_2_damper";
		side = "right";
		center = "wheel_2_2_axis";
		boundary = "wheel_2_2_bound";
		suspForceAppPointOffset = "wheel_2_2_axis";
		tireForceAppPointOffset = "wheel_2_2_axis";
	};
	class RR: LM
	{
		boneName = "wheel_2_3_damper";
		side = "right";
		center = "wheel_2_3_axis";
		boundary = "wheel_2_3_bound";
		suspForceAppPointOffset = "wheel_2_3_axis";
		tireForceAppPointOffset = "wheel_2_3_axis";
	};
};
