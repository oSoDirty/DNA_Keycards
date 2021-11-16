class CfgPatches
{
	class DNA_Keycards
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.25;
		requiredAddons[] = {"DZ_Data"};
	};
};
class CfgMods
{
	class DNA_Keycards
	{
		dir = "DNA_Keycards";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "DNA_Keycards";
		credits = "Arrakis and Dirty";
		author = "Arrakis and Dirty";
		authorID = "0";
		version = "1.0";
		configVersion = "1.0";
		extra = 0;
		type = "mod";
		dependencies[] = {"Game","World","Mission"};
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = {"DNA_Keycards/Scripts/3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"DNA_Keycards/Scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"DNA_Keycards/Scripts/5_Mission"};
			};
		};
	};
};

