class CfgPatches
{
	class KeyCardMod
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.25;
		requiredAddons[] = {"DZ_Data"};
	};
};
class CfgMods
{
	class KeyCardMod
	{
		dir = "KeyCardMod";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "KeyCardMod";
		credits = "Arrakis and Dirty";
		author = "Arrakis and Dirty";
		authorID = "0";
		version = "1.0";
		extra = 0;
		type = "mod";
		dependencies[] = {"Game","World","Mission"};
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = {"KeyCardMod/Scripts/3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"KeyCardMod/Scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"KeyCardMod/Scripts/5_Mission"};
			};
		};
	};
};

