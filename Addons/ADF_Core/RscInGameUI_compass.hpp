// Generated: vanilla turret optic overlays (a3\ui_f) copied verbatim under ADFRC_ names,
// plus a white horizontal compass tape + azimuth mark (as on RscOptics_MBT_01_gunner) at the top.
// The top-level group uses RscControlsGroupNoScrollbars (vanilla: RscControlsGroup with zero-size
// scrollbars) so nothing needs a vanilla nested class. Vanilla classes are not touched; turrets opt
// in through turretInfoType.

class RscText;
class RscPicture;
class RscControlsGroupNoScrollbars;

class RscInGameUI
{
	class RscUnitInfo;
	class ADFRC_RscOptics_APC_Tracked_03_gunner: RscUnitInfo
	{
		idd = 300;
		controls[] = {"CA_Zeroing","CA_IGUI_elements_group","CA_APC_WFOV_mode_group","CA_APC_NFOV_mode_group"};
		class CA_IGUI_elements_group: RscControlsGroupNoScrollbars
		{
			idc = 170;
			x = "0 * 		(0.01875 * SafezoneH) + 		(SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y = "0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w = "53.5 * 		(0.01875 * SafezoneH)";
			h = "40 * 		(0.025 * SafezoneH)";
			class controls
			{
				class CA_TurretIndicator: RscPicture
				{
					IDC = 206;
					type = 105;
					textSize = "0.02*SafezoneH";
					style = 0;
					color[] = {0.95,0.95,0.95,1};
					x = "5.25 * 		(0.01875 * SafezoneH)";
					y = "10.5 * 		(0.025 * SafezoneH)";
					w = "7 * 		(0.01875 * SafezoneH)";
					h = "7 * 		(0.025 * SafezoneH)";
					imageHull = "A3\Ui_f\data\IGUI\RscIngameUI\RscOptics\turretIndicatorHull_AAF.paa";
					imageTurret = "A3\Ui_f\data\IGUI\RscIngameUI\RscOptics\turretIndicatorTurret_RWS.paa";
					imageObsTurret = "A3\Ui_f\data\IGUI\RscIngameUI\RscOptics\turretIndicatorObsTurret_RWS.paa";
					imageGun = "#(rgb,8,8,3)color(0,0,0,0)";
				};
				class CA_Heading: RscText
				{
					idc = 156;
					style = 2;
					sizeEx = "0.038*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "015";
					x = "7.25 * 		(0.01875 * SafezoneH)";
					y = "16.3 * 		(0.025 * SafezoneH)";
					w = "3 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
				};
				class CA_OpticsPitch: RscText
				{
					idc = 182;
					style = 1;
					sizeEx = "0.038*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "36";
					x = "1 * 		(0.01875 * SafezoneH)";
					y = "19.3 * 		(0.025 * SafezoneH)";
					w = "5.2 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_Distance: RscText
				{
					idc = 198;
					style = 2;
					sizeEx = "0.040*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "2456";
					x = "24.15 * 		(0.01875 * SafezoneH)";
					y = "28.5 * 		(0.025 * SafezoneH)";
					w = "5 * 		(0.01875 * SafezoneH)";
					h = "2 * 		(0.025 * SafezoneH)";
				};
				class FireSolutionValid: RscPicture
				{
					idc = 200;
					text = "\A3\Ui_f\data\IGUI\RscIngameUI\RscOptics\square.paa";
					x = "24.25 * 		(0.01875 * SafezoneH)";
					y = "28.5 * 		(0.025 * SafezoneH)";
					w = "0.6 * 		(0.01875 * SafezoneH)";
					h = "0.6 * 		(0.025 * SafezoneH)";
				};
				class TargetSpeedText: RscText
				{
					idc = 1050;
					sizeEx = "0.032*SafezoneH";
					style = 1;
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "SPD:";
					x = "4.85 * 		(0.025 * SafezoneH)";
					y = "29.2 * 		(0.025 * SafezoneH)";
					w = "3 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class TargetSpeed: TargetSpeedText
				{
					idc = 199;
					style = 0;
					text = "2456";
					x = "7.2 * 		(0.025 * SafezoneH)";
					w = "5.2 * 		(0.01875 * SafezoneH)";
				};
				class CA_VisionMode: RscText
				{
					idc = 152;
					style = 0;
					sizeEx = "0.038*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "FLIR";
					x = "40.2 * 		(0.01875 * SafezoneH)";
					y = "9 * 		(0.025 * SafezoneH)";
					w = "4.5 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_FlirMode: RscText
				{
					idc = 153;
					style = 0;
					sizeEx = "0.038*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "BHOT";
					x = "44.2 * 		(0.01875 * SafezoneH)";
					y = "9 * 		(0.025 * SafezoneH)";
					w = "4.5 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class ADFRC_HorizontalCompass: RscPicture
				{
					idc = 207;
					type = 105;
					font = "EtelkaMonospacePro";
					textSize = "0.02*SafezoneH";
					style = 1;
					color[] = {1,1,1,1};
					x = "13.04 * 		(0.01875 * SafezoneH)";
					y = "3.5 * 		(0.025 * SafezoneH)";
					w = "27.18 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
					imageHull = "A3\Ui_f\data\IGUI\RscIngameUI\RscOptics\horizontalCompassHull.paa";
					imageTurret = "A3\Ui_f\data\IGUI\RscIngameUI\RscOptics\horizontalCompassTurret.paa";
					imageObsTurret = "A3\Ui_f\data\IGUI\RscIngameUI\RscOptics\horizontalCompassObsTurret.paa";
					imageGun = "#(rgb,8,8,3)color(0,0,0,0)";
				};
				class ADFRC_AzimuthMark: RscPicture
				{
					idc = 1012;
					text = "A3\Ui_f\data\IGUI\RscIngameUI\RscOptics\AzimuthMark.paa";
					x = "26.35 * 		(0.01875 * SafezoneH)";
					y = "3.0 * 		(0.025 * SafezoneH)";
					w = "0.5 * 		(0.01875 * SafezoneH)";
					h = "0.5 * 		(0.025 * SafezoneH)";
					colorText[] = {1,1,1,1};
				};
			};
		};
		class CA_APC_WFOV_mode_group: RscControlsGroupNoScrollbars
		{
			idc = 163;
			x = "0 * 		(0.01875 * SafezoneH) + 		(SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y = "0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w = "53.5 * 		(0.01875 * SafezoneH)";
			h = "40 * 		(0.025 * SafezoneH)";
			class controls
			{
				class CA_FOVModeWFOV: RscText
				{
					shadow = 0;
					font = "EtelkaMonospacePro";
					sizeEx = "0.038*SafezoneH";
					idc = 1002;
					text = "WFOV";
					x = "8 * 		(0.01875 * SafezoneH)";
					y = "9 * 		(0.025 * SafezoneH)";
					w = "5 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
			};
		};
		class CA_APC_NFOV_mode_group: RscControlsGroupNoScrollbars
		{
			idc = 162;
			x = "0 * 		(0.01875 * SafezoneH) + 		(SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y = "0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w = "53.5 * 		(0.01875 * SafezoneH)";
			h = "40 * 		(0.025 * SafezoneH)";
			class controls
			{
				class CA_FOVModeNFOV: RscText
				{
					shadow = 0;
					font = "EtelkaMonospacePro";
					sizeEx = "0.038*SafezoneH";
					idc = 1007;
					text = "NFOV";
					x = "8 * 		(0.01875 * SafezoneH)";
					y = "9 * 		(0.025 * SafezoneH)";
					w = "5 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
			};
		};
	};
	class ADFRC_RscOptics_APC_Wheeled_01_gunner: RscUnitInfo
	{
		idd = 300;
		controls[] = {"CA_Zeroing","CA_IGUI_elements_group","CA_APC_WFOV_mode_group","CA_APC_NFOV_mode_group"};
		class CA_IGUI_elements_group: RscControlsGroupNoScrollbars
		{
			idc = 170;
			x = "0 * 		(0.01875 * SafezoneH) + 		(SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y = "0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w = "53.5 * 		(0.01875 * SafezoneH)";
			h = "40 * 		(0.025 * SafezoneH)";
			class controls
			{
				class CA_TurretIndicator: RscPicture
				{
					IDC = 206;
					type = 105;
					textSize = "0.02*SafezoneH";
					style = 0;
					color[] = {0.706,0.0745,0.0196,1};
					x = "36.25 * 		(0.01875 * SafezoneH)";
					y = "27.5 * 		(0.025 * SafezoneH)";
					w = "6 * 		(0.01875 * SafezoneH)";
					h = "6 * 		(0.025 * SafezoneH)";
					imageHull = "A3\Ui_f\data\IGUI\RscIngameUI\RscOptics\turretIndicatorHull.paa";
					imageTurret = "A3\Ui_f\data\IGUI\RscIngameUI\RscOptics\turretIndicatorTurret.paa";
					imageObsTurret = "A3\Ui_f\data\IGUI\RscIngameUI\RscOptics\turretIndicatorObsTurret.paa";
					imageGun = "#(rgb,8,8,3)color(0,0,0,0)";
				};
				class CA_Heading: RscText
				{
					idc = 156;
					style = 2;
					sizeEx = "0.038*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					colorText[] = {0.706,0.0745,0.0196,1};
					text = "015";
					x = "25.15 * 		(0.01875 * SafezoneH)";
					y = "11 * 		(0.025 * SafezoneH)";
					w = "3 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
				};
				class CA_OpticsPitch: RscText
				{
					idc = 182;
					style = 1;
					colorText[] = {0.706,0.0745,0.0196,1};
					sizeEx = "0.038*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "36";
					x = "1 * 		(0.01875 * SafezoneH)";
					y = "19.3 * 		(0.025 * SafezoneH)";
					w = "5.2 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_Distance: RscText
				{
					idc = 198;
					style = 2;
					sizeEx = "0.040*SafezoneH";
					colorText[] = {0.706,0.0745,0.0196,1};
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "2456";
					x = "24.15 * 		(0.01875 * SafezoneH)";
					y = "28.5 * 		(0.025 * SafezoneH)";
					w = "5 * 		(0.01875 * SafezoneH)";
					h = "2 * 		(0.025 * SafezoneH)";
				};
				class FireSolutionValid: RscPicture
				{
					idc = 200;
					text = "\A3\Ui_f\data\IGUI\RscIngameUI\RscOptics\square.paa";
					colorText[] = {0.706,0.0745,0.0196,1};
					x = "24.25 * 		(0.01875 * SafezoneH)";
					y = "28.5 * 		(0.025 * SafezoneH)";
					w = "0.6 * 		(0.01875 * SafezoneH)";
					h = "0.6 * 		(0.025 * SafezoneH)";
				};
				class TargetSpeedText: RscText
				{
					idc = 1050;
					sizeEx = "0.032*SafezoneH";
					style = 1;
					shadow = 0;
					font = "EtelkaMonospacePro";
					colorText[] = {0.706,0.0745,0.0196,1};
					text = "SPD:";
					x = "4.85 * 		(0.025 * SafezoneH)";
					y = "29.2 * 		(0.025 * SafezoneH)";
					w = "3 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class TargetSpeed: TargetSpeedText
				{
					idc = 199;
					style = 0;
					text = "2456";
					x = "7.2 * 		(0.025 * SafezoneH)";
					w = "5.2 * 		(0.01875 * SafezoneH)";
				};
				class CA_VisionMode: RscText
				{
					idc = 152;
					style = 0;
					sizeEx = "0.038*SafezoneH";
					colorText[] = {0.706,0.0745,0.0196,1};
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "FLIR";
					x = "40.2 * 		(0.01875 * SafezoneH)";
					y = "11 * 		(0.025 * SafezoneH)";
					w = "4.5 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_FlirMode: RscText
				{
					idc = 153;
					style = 0;
					sizeEx = "0.038*SafezoneH";
					colorText[] = {0.706,0.0745,0.0196,1};
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "BHOT";
					x = "44.2 * 		(0.01875 * SafezoneH)";
					y = "11 * 		(0.025 * SafezoneH)";
					w = "4.5 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class ADFRC_HorizontalCompass: RscPicture
				{
					idc = 207;
					type = 105;
					font = "EtelkaMonospacePro";
					textSize = "0.02*SafezoneH";
					style = 1;
					color[] = {1,1,1,1};
					x = "13.04 * 		(0.01875 * SafezoneH)";
					y = "3.5 * 		(0.025 * SafezoneH)";
					w = "27.18 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
					imageHull = "A3\Ui_f\data\IGUI\RscIngameUI\RscOptics\horizontalCompassHull.paa";
					imageTurret = "A3\Ui_f\data\IGUI\RscIngameUI\RscOptics\horizontalCompassTurret.paa";
					imageObsTurret = "A3\Ui_f\data\IGUI\RscIngameUI\RscOptics\horizontalCompassObsTurret.paa";
					imageGun = "#(rgb,8,8,3)color(0,0,0,0)";
				};
				class ADFRC_AzimuthMark: RscPicture
				{
					idc = 1012;
					text = "A3\Ui_f\data\IGUI\RscIngameUI\RscOptics\AzimuthMark.paa";
					x = "26.35 * 		(0.01875 * SafezoneH)";
					y = "3.0 * 		(0.025 * SafezoneH)";
					w = "0.5 * 		(0.01875 * SafezoneH)";
					h = "0.5 * 		(0.025 * SafezoneH)";
					colorText[] = {1,1,1,1};
				};
			};
		};
		class CA_APC_WFOV_mode_group: RscControlsGroupNoScrollbars
		{
			idc = 163;
			x = "0 * 		(0.01875 * SafezoneH) + 		(SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y = "0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w = "53.5 * 		(0.01875 * SafezoneH)";
			h = "40 * 		(0.025 * SafezoneH)";
			class controls
			{
				class CA_FOVModeWFOV: RscText
				{
					colorText[] = {0.706,0.0745,0.0196,1};
					shadow = 0;
					font = "EtelkaMonospacePro";
					sizeEx = "0.038*SafezoneH";
					idc = 1002;
					text = "WFOV";
					x = "8 * 		(0.01875 * SafezoneH)";
					y = "11 * 		(0.025 * SafezoneH)";
					w = "5 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
			};
		};
		class CA_APC_NFOV_mode_group: RscControlsGroupNoScrollbars
		{
			idc = 162;
			x = "0 * 		(0.01875 * SafezoneH) + 		(SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y = "0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w = "53.5 * 		(0.01875 * SafezoneH)";
			h = "40 * 		(0.025 * SafezoneH)";
			class controls
			{
				class CA_FOVModeNFOV: RscText
				{
					colorText[] = {0.706,0.0745,0.0196,1};
					shadow = 0;
					font = "EtelkaMonospacePro";
					sizeEx = "0.038*SafezoneH";
					idc = 1007;
					text = "NFOV";
					x = "8 * 		(0.01875 * SafezoneH)";
					y = "11 * 		(0.025 * SafezoneH)";
					w = "5 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
			};
		};
	};
	class ADFRC_RscOptics_APC_Wheeled_03_commander: RscUnitInfo
	{
		idd = 300;
		controls[] = {"CA_Zeroing","CA_IGUI_elements_group","CA_APC_WFOV_mode_group","CA_APC_NFOV_mode_group"};
		class CA_IGUI_elements_group: RscControlsGroupNoScrollbars
		{
			idc = 170;
			x = "0 * 		(0.01875 * SafezoneH) + 		(SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y = "0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w = "53.5 * 		(0.01875 * SafezoneH)";
			h = "40 * 		(0.025 * SafezoneH)";
			class controls
			{
				class CA_TurretIndicator: RscPicture
				{
					IDC = 206;
					type = 105;
					textSize = "0.02*SafezoneH";
					style = 0;
					color[] = {0.95,0.95,0.95,1};
					x = "5.25 * 		(0.01875 * SafezoneH)";
					y = "10.5 * 		(0.025 * SafezoneH)";
					w = "7 * 		(0.01875 * SafezoneH)";
					h = "7 * 		(0.025 * SafezoneH)";
					imageHull = "A3\Ui_f\data\IGUI\RscIngameUI\RscOptics\turretIndicatorHull_AAF.paa";
					imageTurret = "A3\Ui_f\data\IGUI\RscIngameUI\RscOptics\turretIndicatorTurret_RWS.paa";
					imageObsTurret = "A3\Ui_f\data\IGUI\RscIngameUI\RscOptics\turretIndicatorObsTurret_RWS.paa";
					imageGun = "#(rgb,8,8,3)color(0,0,0,0)";
				};
				class CA_Heading: RscText
				{
					idc = 156;
					style = 2;
					sizeEx = "0.038*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "015";
					x = "7.25 * 		(0.01875 * SafezoneH)";
					y = "16.3 * 		(0.025 * SafezoneH)";
					w = "3 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
				};
				class TextOpticsPitch: RscText
				{
					style = 0;
					sizeEx = "0.032*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					idc = 1008;
					text = "E:";
					x = "6.8 * 		(0.01875 * SafezoneH)";
					y = "9.6 * 		(0.025 * SafezoneH)";
					w = "2 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_OpticsPitch: RscText
				{
					idc = 182;
					style = 0;
					sizeEx = "0.032*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "36";
					x = "8 * 		(0.01875 * SafezoneH)";
					y = "9.6 * 		(0.025 * SafezoneH)";
					w = "5.2 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_Distance: RscText
				{
					idc = 198;
					style = 0;
					sizeEx = "0.032*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "2456";
					x = "40.4 * 		(0.01875 * SafezoneH)";
					y = "9.6 * 		(0.025 * SafezoneH)";
					w = "5 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_VisionMode: RscText
				{
					idc = 152;
					style = 0;
					sizeEx = "0.032*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "FLIR";
					x = "44 * 		(0.01875 * SafezoneH)";
					y = "29.2 * 		(0.025 * SafezoneH)";
					w = "4.5 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_FlirMode: RscText
				{
					idc = 153;
					style = 0;
					sizeEx = "0.032*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "BHOT";
					x = "47.5 * 		(0.01875 * SafezoneH)";
					y = "29.2 * 		(0.025 * SafezoneH)";
					w = "4.5 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class ADFRC_HorizontalCompass: RscPicture
				{
					idc = 207;
					type = 105;
					font = "EtelkaMonospacePro";
					textSize = "0.02*SafezoneH";
					style = 1;
					color[] = {1,1,1,1};
					x = "13.04 * 		(0.01875 * SafezoneH)";
					y = "3.5 * 		(0.025 * SafezoneH)";
					w = "27.18 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
					imageHull = "A3\Ui_f\data\IGUI\RscIngameUI\RscOptics\horizontalCompassHull.paa";
					imageTurret = "A3\Ui_f\data\IGUI\RscIngameUI\RscOptics\horizontalCompassTurret.paa";
					imageObsTurret = "A3\Ui_f\data\IGUI\RscIngameUI\RscOptics\horizontalCompassObsTurret.paa";
					imageGun = "#(rgb,8,8,3)color(0,0,0,0)";
				};
				class ADFRC_AzimuthMark: RscPicture
				{
					idc = 1012;
					text = "A3\Ui_f\data\IGUI\RscIngameUI\RscOptics\AzimuthMark.paa";
					x = "26.35 * 		(0.01875 * SafezoneH)";
					y = "3.0 * 		(0.025 * SafezoneH)";
					w = "0.5 * 		(0.01875 * SafezoneH)";
					h = "0.5 * 		(0.025 * SafezoneH)";
					colorText[] = {1,1,1,1};
				};
			};
		};
		class CA_APC_WFOV_mode_group: RscControlsGroupNoScrollbars
		{
			idc = 163;
			x = "0 * 		(0.01875 * SafezoneH) + 		(SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y = "0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w = "53.5 * 		(0.01875 * SafezoneH)";
			h = "40 * 		(0.025 * SafezoneH)";
			class controls
			{
				class CA_FOVModeWFOV: RscText
				{
					shadow = 0;
					font = "EtelkaMonospacePro";
					sizeEx = "0.032*SafezoneH";
					idc = 1002;
					text = "WFOV";
					x = "40.4 * 		(0.01875 * SafezoneH)";
					y = "29.2 * 		(0.025 * SafezoneH)";
					w = "5 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
			};
		};
		class CA_APC_NFOV_mode_group: RscControlsGroupNoScrollbars
		{
			idc = 162;
			x = "0 * 		(0.01875 * SafezoneH) + 		(SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y = "0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w = "53.5 * 		(0.01875 * SafezoneH)";
			h = "40 * 		(0.025 * SafezoneH)";
			class controls
			{
				class CA_FOVModeNFOV: RscText
				{
					shadow = 0;
					font = "EtelkaMonospacePro";
					sizeEx = "0.032*SafezoneH";
					idc = 1007;
					text = "NFOV";
					x = "40.4 * 		(0.01875 * SafezoneH)";
					y = "29.2 * 		(0.025 * SafezoneH)";
					w = "5 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
			};
		};
	};
	class ADFRC_RscOptics_APC_Wheeled_03_gunner: RscUnitInfo
	{
		idd = 300;
		controls[] = {"CA_Zeroing","CA_IGUI_elements_group","CA_APC_WFOV_mode_group","CA_APC_NFOV_mode_group"};
		class CA_IGUI_elements_group: RscControlsGroupNoScrollbars
		{
			idc = 170;
			x = "0 * 		(0.01875 * SafezoneH) + 		(SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y = "0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w = "53.5 * 		(0.01875 * SafezoneH)";
			h = "40 * 		(0.025 * SafezoneH)";
			class controls
			{
				class CA_TurretIndicator: RscPicture
				{
					IDC = 206;
					type = 105;
					textSize = "0.02*SafezoneH";
					style = 0;
					color[] = {0.95,0.95,0.95,1};
					x = "5.25 * 		(0.01875 * SafezoneH)";
					y = "10.5 * 		(0.025 * SafezoneH)";
					w = "7 * 		(0.01875 * SafezoneH)";
					h = "7 * 		(0.025 * SafezoneH)";
					imageHull = "A3\Ui_f\data\IGUI\RscIngameUI\RscOptics\turretIndicatorHull_AAF.paa";
					imageTurret = "A3\Ui_f\data\IGUI\RscIngameUI\RscOptics\turretIndicatorTurret_RWS.paa";
					imageObsTurret = "A3\Ui_f\data\IGUI\RscIngameUI\RscOptics\turretIndicatorObsTurret_RWS.paa";
					imageGun = "#(rgb,8,8,3)color(0,0,0,0)";
				};
				class CA_Heading: RscText
				{
					idc = 156;
					style = 2;
					sizeEx = "0.038*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "015";
					x = "7.25 * 		(0.01875 * SafezoneH)";
					y = "16.3 * 		(0.025 * SafezoneH)";
					w = "3 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
				};
				class TextOpticsPitch: RscText
				{
					style = 0;
					sizeEx = "0.032*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					idc = 1008;
					text = "E:";
					x = "6.8 * 		(0.01875 * SafezoneH)";
					y = "9.6 * 		(0.025 * SafezoneH)";
					w = "2 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_OpticsPitch: RscText
				{
					idc = 182;
					style = 0;
					sizeEx = "0.032*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "36";
					x = "8 * 		(0.01875 * SafezoneH)";
					y = "9.6 * 		(0.025 * SafezoneH)";
					w = "5.2 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_Distance: RscText
				{
					idc = 198;
					style = 2;
					sizeEx = "0.040*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "2456";
					x = "24.15 * 		(0.01875 * SafezoneH)";
					y = "28.5 * 		(0.025 * SafezoneH)";
					w = "5 * 		(0.01875 * SafezoneH)";
					h = "2 * 		(0.025 * SafezoneH)";
				};
				class FireSolutionValid: RscPicture
				{
					idc = 200;
					text = "\A3\Ui_f\data\IGUI\RscIngameUI\RscOptics\square.paa";
					x = "24.25 * 		(0.01875 * SafezoneH)";
					y = "28.5 * 		(0.025 * SafezoneH)";
					w = "0.6 * 		(0.01875 * SafezoneH)";
					h = "0.6 * 		(0.025 * SafezoneH)";
				};
				class TargetSpeedText: RscText
				{
					idc = 1050;
					sizeEx = "0.032*SafezoneH";
					style = 1;
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "SPD:";
					x = "4.85 * 		(0.025 * SafezoneH)";
					y = "29.2 * 		(0.025 * SafezoneH)";
					w = "3 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class TargetSpeed: TargetSpeedText
				{
					idc = 199;
					style = 0;
					text = "2456";
					x = "7.2 * 		(0.025 * SafezoneH)";
					w = "5.2 * 		(0.01875 * SafezoneH)";
				};
				class CA_VisionMode: RscText
				{
					idc = 152;
					style = 0;
					sizeEx = "0.032*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "FLIR";
					x = "44 * 		(0.01875 * SafezoneH)";
					y = "29.2 * 		(0.025 * SafezoneH)";
					w = "4.5 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_FlirMode: RscText
				{
					idc = 153;
					style = 0;
					sizeEx = "0.032*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "BHOT";
					x = "47.5 * 		(0.01875 * SafezoneH)";
					y = "29.2 * 		(0.025 * SafezoneH)";
					w = "4.5 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class ADFRC_HorizontalCompass: RscPicture
				{
					idc = 207;
					type = 105;
					font = "EtelkaMonospacePro";
					textSize = "0.02*SafezoneH";
					style = 1;
					color[] = {1,1,1,1};
					x = "13.04 * 		(0.01875 * SafezoneH)";
					y = "3.5 * 		(0.025 * SafezoneH)";
					w = "27.18 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
					imageHull = "A3\Ui_f\data\IGUI\RscIngameUI\RscOptics\horizontalCompassHull.paa";
					imageTurret = "A3\Ui_f\data\IGUI\RscIngameUI\RscOptics\horizontalCompassTurret.paa";
					imageObsTurret = "A3\Ui_f\data\IGUI\RscIngameUI\RscOptics\horizontalCompassObsTurret.paa";
					imageGun = "#(rgb,8,8,3)color(0,0,0,0)";
				};
				class ADFRC_AzimuthMark: RscPicture
				{
					idc = 1012;
					text = "A3\Ui_f\data\IGUI\RscIngameUI\RscOptics\AzimuthMark.paa";
					x = "26.35 * 		(0.01875 * SafezoneH)";
					y = "3.0 * 		(0.025 * SafezoneH)";
					w = "0.5 * 		(0.01875 * SafezoneH)";
					h = "0.5 * 		(0.025 * SafezoneH)";
					colorText[] = {1,1,1,1};
				};
			};
		};
		class CA_APC_WFOV_mode_group: RscControlsGroupNoScrollbars
		{
			idc = 163;
			x = "0 * 		(0.01875 * SafezoneH) + 		(SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y = "0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w = "53.5 * 		(0.01875 * SafezoneH)";
			h = "40 * 		(0.025 * SafezoneH)";
			class controls
			{
				class CA_FOVModeWFOV: RscText
				{
					shadow = 0;
					font = "EtelkaMonospacePro";
					sizeEx = "0.032*SafezoneH";
					idc = 1002;
					text = "WFOV";
					x = "40.4 * 		(0.01875 * SafezoneH)";
					y = "29.2 * 		(0.025 * SafezoneH)";
					w = "5 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
			};
		};
		class CA_APC_NFOV_mode_group: RscControlsGroupNoScrollbars
		{
			idc = 162;
			x = "0 * 		(0.01875 * SafezoneH) + 		(SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y = "0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w = "53.5 * 		(0.01875 * SafezoneH)";
			h = "40 * 		(0.025 * SafezoneH)";
			class controls
			{
				class CA_FOVModeNFOV: RscText
				{
					shadow = 0;
					font = "EtelkaMonospacePro";
					sizeEx = "0.032*SafezoneH";
					idc = 1007;
					text = "NFOV";
					x = "40.4 * 		(0.01875 * SafezoneH)";
					y = "29.2 * 		(0.025 * SafezoneH)";
					w = "5 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
			};
		};
	};
};
