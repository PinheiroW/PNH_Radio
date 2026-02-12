class CfgPatches
{
	class PNH_Radio
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]={"DZ_Data","DZ_Scripts","DZ_Sounds_Effects"};
	};
};

class CfgMods
{
	class PNH_Radio
	{
		dir="PNH_Radio";
		name="PNH Radio System";
		credits="Pinheiro";
		author="Pinheiro";
		version="3.1";
		type="mod";
		dependencies[]={"GameLib","Game","World","Mission"};
		
		class defs
		{
			class gameLibScriptModule
			{
				value="";
				files[]={"PNH_Radio/scripts/2_GameLib"};
			};
			class gameScriptModule 
			{ 
				value=""; 
				files[]={
					"PNH_Radio/scripts/1_Core",
					"PNH_Radio/scripts/3_Game"
				}; 
			};
			class worldScriptModule 
			{ 
				value=""; 
				files[]={"PNH_Radio/scripts/4_World"}; 
			};
			class missionScriptModule 
			{ 
				value=""; 
				files[]={"PNH_Radio/scripts/5_Mission"}; 
			};
		};
	};
};