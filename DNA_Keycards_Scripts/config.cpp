class CfgPatches
{
	class DNA_Keycards_Scripts
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.25;
		requiredAddons[] = 
		{
			"DZ_Data",
			"JM_CF_Scripts",
			"DNA_Keycards_Icons"
		};
	};
};
class CfgMods
{
	class DNA_Keycards_Scripts
	{
		dir = "DNA_Keycards_Scripts";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "DNA_Keycards";
		credits = "Arrakis and Dirty";
		author = "Arrakis and Dirty";
		authorID = "0";
		version = "1.0";
		configVersion = 2;
		extra = 0;
		type = "mod";
		dependencies[] = {"Game","World","Mission"};
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = {"DNA_Keycards_Scripts/Scripts/3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"DNA_Keycards_Scripts/Scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"DNA_Keycards_Scripts/Scripts/5_Mission"};
			};
		};
	};
};

