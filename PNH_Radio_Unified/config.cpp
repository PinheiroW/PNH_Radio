class CfgPatches
{
	class PNH_Radio_Unified
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Data",
			"DZ_Scripts",
			"DZ_Sounds_Effects",
			"DZ_Gear_Books"
		};
	};
};

class CfgMods
{
	class PNH_Radio_Unified
	{
		type = "mod";
		dependencies[] = {"Game", "World", "Mission"};
		
		class defs
		{
			class engineScriptModule
			{
				value = "";
				files[] = {"PNH_Radio_Unified/scripts/1_Core"};
			};
			class gameScriptModule
			{
				value = "";
				files[] = {"PNH_Radio_Unified/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"PNH_Radio_Unified/scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"PNH_Radio_Unified/scripts/5_Mission"};
			};
		};
	};
};
