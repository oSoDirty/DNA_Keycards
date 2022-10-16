class CrateSmol_Settings_Description
{
	string dna_ConfigDescription;
	string dna_ConfigDescriptionCont;
	string dna_ConfigDescriptionCont2;
	bool dna_UseConfig;
}

class CrateSmol_Yellow_Settings
{
	string dna_Description;
	string dna_DescriptionCont;
	string dna_DescriptionCont2;
	bool dna_SpawnMainWeapons;
	bool dna_RandomizeWeapons;
	int dna_WeaponCount;
	ref array<ref DNA_Config_Weapons_Smol> weaponTypesYellow;
	bool dna_SpawnLootSet1;
	bool dna_RandomizeLootSet1;
	int dna_LootSet1Count;
	ref array<string> dna_LootSetY1 = {};
	bool dna_SpawnLootSet2;
	bool dna_RandomizeLootSet2;
	int dna_LootSet2Count;
	ref array<string> dna_LootSetY2 = {};
	bool dna_SpawnLootSet3;
	bool dna_RandomizeLootSet3;
	int dna_LootSet3Count;
	ref array<string> dna_LootSetY3 = {};
	bool dna_SpawnLootSet4;
	bool dna_RandomizeLootSet4;
	int dna_LootSet4Count;
	ref array<string> dna_LootSetY4 = {};
	
	void CrateSmol_Yellow_Settings()
	{
		weaponTypesYellow = new array<ref DNA_Config_Weapons_Smol>;
	}
}

class CrateSmol_Green_Settings
{
	string dna_Description;
	string dna_DescriptionCont;
	string dna_DescriptionCont2;
	bool dna_SpawnMainWeapons;
	bool dna_RandomizeWeapons;
	int dna_WeaponCount;
	ref array<ref DNA_Config_Weapons_Smol> weaponTypesGreen;
	bool dna_SpawnLootSet1;
	bool dna_RandomizeLootSet1;
	int dna_LootSet1Count;
	ref array<string> dna_LootSetG1 = {};
	bool dna_SpawnLootSet2;
	bool dna_RandomizeLootSet2;
	int dna_LootSet2Count;
	ref array<string> dna_LootSetG2 = {};
	bool dna_SpawnLootSet3;
	bool dna_RandomizeLootSet3;
	int dna_LootSet3Count;
	ref array<string> dna_LootSetG3 = {};
	bool dna_SpawnLootSet4;
	bool dna_RandomizeLootSet4;
	int dna_LootSet4Count;
	ref array<string> dna_LootSetG4 = {};
	
	void CrateSmol_Green_Settings()
	{
		weaponTypesGreen = new array<ref DNA_Config_Weapons_Smol>;
	}
}

class CrateSmol_Blue_Settings
{
	string dna_Description;
	string dna_DescriptionCont;
	string dna_DescriptionCont2;
	bool dna_SpawnMainWeapons;
	bool dna_RandomizeWeapons;
	int dna_WeaponCount;
	ref array<ref DNA_Config_Weapons_Smol> weaponTypesBlue;
	bool dna_SpawnLootSet1;
	bool dna_RandomizeLootSet1;
	int dna_LootSet1Count;
	ref array<string> dna_LootSetB1 = {};
	bool dna_SpawnLootSet2;
	bool dna_RandomizeLootSet2;
	int dna_LootSet2Count;
	ref array<string> dna_LootSetB2 = {};
	bool dna_SpawnLootSet3;
	bool dna_RandomizeLootSet3;
	int dna_LootSet3Count;
	ref array<string> dna_LootSetB3 = {};
	bool dna_SpawnLootSet4;
	bool dna_RandomizeLootSet4;
	int dna_LootSet4Count;
	ref array<string> dna_LootSetB4 = {};
	
	void CrateSmol_Blue_Settings()
	{
		weaponTypesBlue = new array<ref DNA_Config_Weapons_Smol>;
	}
}

class CrateSmol_Purple_Settings
{
	string dna_Description;
	string dna_DescriptionCont;
	string dna_DescriptionCont2;
	bool dna_SpawnMainWeapons;
	bool dna_RandomizeWeapons;
	int dna_WeaponCount;
	ref array<ref DNA_Config_Weapons_Smol> weaponTypesPurple;
	bool dna_SpawnLootSet1;
	bool dna_RandomizeLootSet1;
	int dna_LootSet1Count;
	ref array<string> dna_LootSetP1 = {};
	bool dna_SpawnLootSet2;
	bool dna_RandomizeLootSet2;
	int dna_LootSet2Count;
	ref array<string> dna_LootSetP2 = {};
	bool dna_SpawnLootSet3;
	bool dna_RandomizeLootSet3;
	int dna_LootSet3Count;
	ref array<string> dna_LootSetP3 = {};
	bool dna_SpawnLootSet4;
	bool dna_RandomizeLootSet4;
	int dna_LootSet4Count;
	ref array<string> dna_LootSetP4 = {};
	
	void CrateSmol_Purple_Settings()
	{
		weaponTypesPurple = new array<ref DNA_Config_Weapons_Smol>;
	}
}

class CrateSmol_Red_Settings
{
	string dna_Description;
	string dna_DescriptionCont;
	string dna_DescriptionCont2;
	bool dna_SpawnMainWeapons;
	bool dna_RandomizeWeapons;
	int dna_WeaponCount;
	ref array<ref DNA_Config_Weapons_Smol> weaponTypesRed;
	bool dna_SpawnLootSet1;
	bool dna_RandomizeLootSet1;
	int dna_LootSet1Count;
	ref array<string> dna_LootSetR1 = {};
	bool dna_SpawnLootSet2;
	bool dna_RandomizeLootSet2;
	int dna_LootSet2Count;
	ref array<string> dna_LootSetR2 = {};
	bool dna_SpawnLootSet3;
	bool dna_RandomizeLootSet3;
	int dna_LootSet3Count;
	ref array<string> dna_LootSetR3 = {};
	bool dna_SpawnLootSet4;
	bool dna_RandomizeLootSet4;
	int dna_LootSet4Count;
	ref array<string> dna_LootSetR4 = {};
	
	void CrateSmol_Red_Settings()
	{
		weaponTypesRed = new array<ref DNA_Config_Weapons_Smol>;
	}
}

class DNA_CrateSmol_Data
{
	private static ref CrateSmol_Settings_Description dna_Description = NULL;
	private static ref CrateSmol_Yellow_Settings dna_YellowSettings = NULL;
	private static ref CrateSmol_Green_Settings dna_GreenSettings = NULL;
	private static ref CrateSmol_Blue_Settings dna_BlueSettings = NULL;
	private static ref CrateSmol_Purple_Settings dna_PurpleSettings = NULL;
	private static ref CrateSmol_Red_Settings dna_RedSettings = NULL;
	private static ref CrateSmol_TimerSettings dna_TimerSettings = NULL;
	
	static CrateSmol_Settings_Description GetSettingsDescription()
	{
		if(dna_Description == NULL && GetGame().IsDedicatedServer())
			InitSettingsDescription();
		
		return dna_Description;
	}
	
	static void InitSettingsDescription()
	{
		if(GetGame().IsDedicatedServer())
			dna_Description = LoadSettingsDescription();
	}
	
	private static CrateSmol_Settings_Description LoadSettingsDescription()
	{
		CrateSmol_Settings_Description config = new CrateSmol_Settings_Description;
		if(!FileExist(SmolCrateConfigDescription))
		{
			if(GetGame().IsDedicatedServer())
			{
				Print("[DNA DEBUG] - Smol Crate Settings Description not found.... Creating now.");
				CreateDefaultDescription(config);
			}
		}
		else
		{
			if(GetGame().IsDedicatedServer())
				Print("[DNA DEBUG] - Smol Crate Settings Description found.... Loading.");
		}
		JsonFileLoader<CrateSmol_Settings_Description>.JsonLoadFile(SmolCrateConfigDescription, config);
		return config;
	}
	
	private static void CreateDefaultDescription(CrateSmol_Settings_Description config)
	{
		config.dna_ConfigDescription = "This section of configs is used to fill smol crates and other crates we may add in the future that you place with editor";
		config.dna_ConfigDescriptionCont = "(or whatever you choose to use). If you are already using the smol crates and loading them another way, you can leave"; 
		config.dna_ConfigDescriptionCont2 = "the setting below to false (0) and it will not interfere with your current setup. Set below to true (1) to use configs.";
		config.dna_UseConfig = false;
		if(!FileExist(SmolCrateConfigRoot))
		{
			Print("[DNA DEBUG] - Smol Crate Root not found.... Creating now.");
			MakeDirectory(SmolCrateConfigRoot);
		}
		else
		{
			Print("[DNA DEBUG] - Smol Crate Root found.... Loading.");
		}
		JsonFileLoader<CrateSmol_Settings_Description>.JsonSaveFile(SmolCrateConfigDescription, config);
	}
	
	static CrateSmol_Yellow_Settings GetSettingsYellow()
	{
		if(dna_YellowSettings == NULL && GetGame().IsDedicatedServer())
			InitYellowSettings();
		
		return dna_YellowSettings;
	}
	
	static void InitYellowSettings()
	{
		if(GetGame().IsDedicatedServer())
			dna_YellowSettings = LoadSettingsYellow();
	}
	
	private static CrateSmol_Yellow_Settings LoadSettingsYellow()
	{
		CrateSmol_Yellow_Settings config = new CrateSmol_Yellow_Settings;
		if(!FileExist(SmolCrateYellowConfig))
		{
			if(GetGame().IsDedicatedServer())
			{
				Print("[DNA DEBUG] - Smol Crate Yellow Config not found.... Creating now.");
				CreateDefaultYellow(config);
			}
		}
		else
		{
			if(GetGame().IsDedicatedServer())
				Print("[DNA DEBUG] - Smol Crate Yellow Config Found.... Loading ");
		}
		JsonFileLoader<CrateSmol_Yellow_Settings>.JsonLoadFile(SmolCrateYellowConfig, config);
		
		return config;
	}
	
	private static void CreateDefaultYellow(CrateSmol_Yellow_Settings config)
	{
		config.dna_Description = "DNA SMOL CRATE CONFIG (Yellow Tier). Below are settings to spawn either static or randomized loot. To spawn all items in array, use randomize setting 0,"; 
		config.dna_DescriptionCont = "if set to 1, it will use the count setting found just below the randomize setting. When using randomized loot, the system can and likely WILL";
		config.dna_DescriptionCont2 = "spawn duplicates. I suggest using static and manually adding desired duplicates. Each loot set, including weapons can be turned off as well.";
		config.dna_SpawnMainWeapons = true;
		config.dna_RandomizeWeapons = true;
		config.dna_WeaponCount = 1;
		config.weaponTypesYellow.Insert(new DNA_Config_Weapons_Smol("Mp133Shotgun", "", 0, "AmmoBox_00buck_10rnd", 1, "", "", "", "", "", ""));
		config.weaponTypesYellow.Insert(new DNA_Config_Weapons_Smol("Izh43Shotgun", "", 0, "AmmoBox_00buck_10rnd", 1, "", "", "", "", "", ""));
		config.dna_SpawnLootSet1 = true;
		config.dna_RandomizeLootSet1 = true;
		config.dna_LootSet1Count = 3;
		config.dna_LootSetY1 = {"BloodTestKit","TetracyclineAntibiotics","BandageDressing","BloodBagIV","Morphine","Epinephrine"};
		config.dna_SpawnLootSet2 = true;
		config.dna_RandomizeLootSet2 = true;
		config.dna_LootSet2Count = 3;
		config.dna_LootSetY2 = {"BoxCerealCrunchin","PeachesCan_Opened","TacticalBaconCan","BakedBeansCan","BakedBeansCan_Opened"};
		config.dna_SpawnLootSet3 = true;
		config.dna_RandomizeLootSet3 = true;
		config.dna_LootSet3Count = 3;
		config.dna_LootSetY3 = {"SodaCan_Pipsi","WaterBottle","SodaCan_Fronta","SodaCan_Cola","SodaCan_Spite"};
		config.dna_SpawnLootSet4 = true;
		config.dna_RandomizeLootSet4 = false;
		config.dna_LootSet4Count = 3;
		config.dna_LootSetY4 = {"WoodenPlank","NailBox","Shovel","WoodAxe","Screwdriver"};
		JsonFileLoader<CrateSmol_Yellow_Settings>.JsonSaveFile(SmolCrateYellowConfig, config);
	}
	
	static CrateSmol_Green_Settings GetSettingsGreen()
	{
		if(dna_GreenSettings == NULL && GetGame().IsDedicatedServer())
			InitGreenSettings();
		
		return dna_GreenSettings;
	}
	
	static void InitGreenSettings()
	{
		if(GetGame().IsDedicatedServer())
			dna_GreenSettings = LoadSettingsGreen();
	}
	
	private static CrateSmol_Green_Settings LoadSettingsGreen()
	{
		CrateSmol_Green_Settings config = new CrateSmol_Green_Settings;
		if(!FileExist(SmolCrateGreenConfig))
		{
			if(GetGame().IsDedicatedServer())
			{
				Print("[DNA DEBUG] - Smol Crate Green Config not found.... Creating now.");
				CreateDefaultGreen(config);
			}
		}
		else
		{
			if(GetGame().IsDedicatedServer())
				Print("[DNA DEBUG] - Smol Crate Green Config Found.... Loading ");
		}
		JsonFileLoader<CrateSmol_Green_Settings>.JsonLoadFile(SmolCrateGreenConfig, config);
		
		return config;
	}
	
	private static void CreateDefaultGreen(CrateSmol_Green_Settings config)
	{
		config.dna_Description = "DNA SMOL CRATE CONFIG (Green Tier). Below are settings to spawn either static or randomized loot. To spawn all items in array, use randomize setting 0,"; 
		config.dna_DescriptionCont = "if set to 1, it will use the count setting found just below the randomize setting. When using randomized loot, the system can and likely WILL";
		config.dna_DescriptionCont2 = "spawn duplicates. I suggest using static and manually adding desired duplicates. Each loot set, including weapons can be turned off as well.";
		config.dna_SpawnMainWeapons = true;
		config.dna_RandomizeWeapons = true;
		config.dna_WeaponCount = 1;
		config.weaponTypesGreen.Insert(new DNA_Config_Weapons_Smol("Izh18", "", 0, "AmmoBox_762x39_20Rnd", 1, "", "", "", "", "", ""));
		config.weaponTypesGreen.Insert(new DNA_Config_Weapons_Smol("SKS_Black", "", 0, "AmmoBox_762x39_20Rnd",  1,"PUScopeOptic", "SKS_Bayonet", "", "", "", ""));
		config.dna_SpawnLootSet1 = true;
		config.dna_RandomizeLootSet1 = true;
		config.dna_LootSet1Count = 3;
		config.dna_LootSetG1 = {"BloodTestKit","TetracyclineAntibiotics","BandageDressing","BloodBagIV","Morphine","Epinephrine"};
		config.dna_SpawnLootSet2 = true;
		config.dna_RandomizeLootSet2 = true;
		config.dna_LootSet2Count = 3;
		config.dna_LootSetG2 = {"BoxCerealCrunchin","PeachesCan_Opened","TacticalBaconCan","BakedBeansCan","BakedBeansCan_Opened"};
		config.dna_SpawnLootSet3 = true;
		config.dna_RandomizeLootSet3 = true;
		config.dna_LootSet3Count = 3;
		config.dna_LootSetG3 = {"SodaCan_Pipsi","WaterBottle","SodaCan_Fronta","SodaCan_Cola","SodaCan_Spite"};
		config.dna_SpawnLootSet4 = true;
		config.dna_RandomizeLootSet4 = false;
		config.dna_LootSet4Count = 3;
		config.dna_LootSetG4 = {"WoodenPlank","NailBox","Shovel","WoodAxe","Screwdriver"};
		JsonFileLoader<CrateSmol_Green_Settings>.JsonSaveFile(SmolCrateGreenConfig, config);
	}
	
	static CrateSmol_Blue_Settings GetSettingsBlue()
	{
		if(dna_BlueSettings == NULL && GetGame().IsDedicatedServer())
			InitBlueSettings();
		
		return dna_BlueSettings;
	}
	
	static void InitBlueSettings()
	{
		if(GetGame().IsDedicatedServer())
			dna_BlueSettings = LoadSettingsBlue();
	}
	
	private static CrateSmol_Blue_Settings LoadSettingsBlue()
	{
		CrateSmol_Blue_Settings config = new CrateSmol_Blue_Settings;
		if(!FileExist(SmolCrateBlueConfig))
		{
			if(GetGame().IsDedicatedServer())
			{
				Print("[DNA DEBUG] - Smol Crate Blue Config not found.... Creating now.");
				CreateDefaultBlue(config);
			}
		}
		else
		{
			if(GetGame().IsDedicatedServer())
				Print("[DNA DEBUG] - Smol Crate Blue Config Found.... Loading ");
		}
		JsonFileLoader<CrateSmol_Blue_Settings>.JsonLoadFile(SmolCrateBlueConfig, config);
		
		return config;
	}
	
	private static void CreateDefaultBlue(CrateSmol_Blue_Settings config)
	{
		config.dna_Description = "DNA SMOL CRATE CONFIG (Blue Tier). Below are settings to spawn either static or randomized loot. To spawn all items in array, use randomize setting 0,"; 
		config.dna_DescriptionCont = "if set to 1, it will use the count setting found just below the randomize setting. When using randomized loot, the system can and likely WILL";
		config.dna_DescriptionCont2 = "spawn duplicates. I suggest using static and manually adding desired duplicates. Each loot set, including weapons can be turned off as well.";
		config.dna_SpawnMainWeapons = true;
		config.dna_RandomizeWeapons = true;
		config.dna_WeaponCount = 1;
		config.weaponTypesBlue.Insert(new DNA_Config_Weapons_Smol("MP5K", "Mag_MP5_30Rnd", 1, "AmmoBox_9x19_25rnd", 1, "ReflexOptic", "PistolSuppressor", "UniversalLight", "MP5k_StockBttstck", "MP5_RailHndgrd", ""));
		config.weaponTypesBlue.Insert(new DNA_Config_Weapons_Smol("AKS74U_Black", "Mag_AK74_30Rnd_Black", 1, "AmmoBox_545x39_20Rnd", 1, "", "AK_Suppressor", "", "AKS74U_Bttstck_Black", "", ""));
		config.dna_SpawnLootSet1 = true;
		config.dna_RandomizeLootSet1 = true;
		config.dna_LootSet1Count = 3;
		config.dna_LootSetB1 = {"BloodTestKit","TetracyclineAntibiotics","BandageDressing","BloodBagIV","Morphine","Epinephrine"};
		config.dna_SpawnLootSet2 = true;
		config.dna_RandomizeLootSet2 = true;
		config.dna_LootSet2Count = 3;
		config.dna_LootSetB2 = {"BoxCerealCrunchin","PeachesCan_Opened","TacticalBaconCan","BakedBeansCan","BakedBeansCan_Opened"};
		config.dna_SpawnLootSet3 = true;
		config.dna_RandomizeLootSet3 = true;
		config.dna_LootSet3Count = 3;
		config.dna_LootSetB3 = {"SodaCan_Pipsi","WaterBottle","SodaCan_Fronta","SodaCan_Cola","SodaCan_Spite"};
		config.dna_SpawnLootSet4 = true;
		config.dna_RandomizeLootSet4 = false;
		config.dna_LootSet4Count = 3;
		config.dna_LootSetB4 = {"WoodenPlank","NailBox","Shovel","WoodAxe","Screwdriver"};
		JsonFileLoader<CrateSmol_Blue_Settings>.JsonSaveFile(SmolCrateBlueConfig, config);
	}
	
	static CrateSmol_Purple_Settings GetSettingsPurple()
	{
		if(dna_PurpleSettings == NULL && GetGame().IsDedicatedServer())
			InitPurpleSettings();
		
		return dna_PurpleSettings;
	}
	
	static void InitPurpleSettings()
	{
		if(GetGame().IsDedicatedServer())
			dna_PurpleSettings = LoadSettingsPurple();
	}
	
	private static CrateSmol_Purple_Settings LoadSettingsPurple()
	{
		CrateSmol_Purple_Settings config = new CrateSmol_Purple_Settings;
		if(!FileExist(SmolCratePurpleConfig))
		{
			if(GetGame().IsDedicatedServer())
			{
				Print("[DNA DEBUG] - Smol Crate Purple Config not found.... Creating now.");
				CreateDefaultPurple(config);
			}
		}
		else
		{
			if(GetGame().IsDedicatedServer())
				Print("[DNA DEBUG] - Smol Crate Purple Config Found.... Loading ");
		}
		JsonFileLoader<CrateSmol_Purple_Settings>.JsonLoadFile(SmolCratePurpleConfig, config);
		
		return config;
	}
	
	private static void CreateDefaultPurple(CrateSmol_Purple_Settings config)
	{
		config.dna_Description = "DNA SMOL CRATE CONFIG (Purple Tier). Below are settings to spawn either static or randomized loot. To spawn all items in array, use randomize setting 0,"; 
		config.dna_DescriptionCont = "if set to 1, it will use the count setting found just below the randomize setting. When using randomized loot, the system can and likely WILL";
		config.dna_DescriptionCont2 = "spawn duplicates. I suggest using static and manually adding desired duplicates. Each loot set, including weapons can be turned off as well.";
		config.dna_SpawnMainWeapons = true;
		config.dna_RandomizeWeapons = true;
		config.dna_WeaponCount = 1;
		config.weaponTypesPurple.Insert(new DNA_Config_Weapons_Smol("FAL", "Mag_FAL_20Rnd", 1, "AmmoBox_308WIN_20Rnd", 1, "ReflexOptic", "", "", "Fal_FoldingBttstck", "", ""));
		config.weaponTypesPurple.Insert(new DNA_Config_Weapons_Smol("M4A1_Black", "Mag_STANAG_30Rnd", 1, "AmmoBox_556x45_20Rnd", 1, "ACOGOptic", "M4_Suppressor", "UniversalLight", "M4_MPBttstck", "M4_RISHndgrd_Black", ""));
		config.dna_SpawnLootSet1 = true;
		config.dna_RandomizeLootSet1 = true;
		config.dna_LootSet1Count = 3;
		config.dna_LootSetP1 = {"BloodTestKit","TetracyclineAntibiotics","BandageDressing","BloodBagIV","Morphine","Epinephrine"};
		config.dna_SpawnLootSet2 = true;
		config.dna_RandomizeLootSet2 = true;
		config.dna_LootSet2Count = 3;
		config.dna_LootSetP2 = {"BoxCerealCrunchin","PeachesCan_Opened","TacticalBaconCan","BakedBeansCan","BakedBeansCan_Opened"};
		config.dna_SpawnLootSet3 = true;
		config.dna_RandomizeLootSet3 = true;
		config.dna_LootSet3Count = 3;
		config.dna_LootSetP3 = {"SodaCan_Pipsi","WaterBottle","SodaCan_Fronta","SodaCan_Cola","SodaCan_Spite"};
		config.dna_SpawnLootSet4 = true;
		config.dna_RandomizeLootSet4 = false;
		config.dna_LootSet4Count = 3;
		config.dna_LootSetP4 = {"WoodenPlank","NailBox","Shovel","WoodAxe","Screwdriver"};
		JsonFileLoader<CrateSmol_Purple_Settings>.JsonSaveFile(SmolCratePurpleConfig, config);
	}
	
	static CrateSmol_Red_Settings GetSettingsRed()
	{
		if(dna_RedSettings == NULL && GetGame().IsDedicatedServer())
			InitRedSettings();
		
		return dna_RedSettings;
	}
	
	static void InitRedSettings()
	{
		if(GetGame().IsDedicatedServer())
			dna_RedSettings = LoadSettingsRed();
	}
	
	private static CrateSmol_Red_Settings LoadSettingsRed()
	{
		CrateSmol_Red_Settings config = new CrateSmol_Red_Settings;
		if(!FileExist(SmolCrateRedConfig))
		{
			if(GetGame().IsDedicatedServer())
			{
				Print("[DNA DEBUG] - Smol Crate Red Config not found.... Creating now.");
				CreateDefaultRed(config);
			}
		}
		else
		{
			if(GetGame().IsDedicatedServer())
				Print("[DNA DEBUG] - Smol Crate Red Config Found.... Loading");
		}
		JsonFileLoader<CrateSmol_Red_Settings>.JsonLoadFile(SmolCrateRedConfig, config);
		
		return config;
	}
	
	private static void CreateDefaultRed(CrateSmol_Red_Settings config)
	{
		config.dna_Description = "DNA SMOL CRATE CONFIG (Red Tier). Below are settings to spawn either static or randomized loot. To spawn all items in array, use randomize setting 0,"; 
		config.dna_DescriptionCont = "if set to 1, it will use the count setting found just below the randomize setting. When using randomized loot, the system can and likely WILL";
		config.dna_DescriptionCont2 = "spawn duplicates. I suggest using static and manually adding desired duplicates. Each loot set, including weapons can be turned off as well.";
		config.dna_SpawnMainWeapons = true;
		config.dna_RandomizeWeapons = true;
		config.dna_WeaponCount = 1;
		config.weaponTypesRed.Insert(new DNA_Config_Weapons_Smol("SVD", "Mag_SVD_10Rnd", 1, "AmmoBox_762x54_20Rnd", 1, "PSO1Optic", "AK_Suppressor", "", "", "", ""));
		config.weaponTypesRed.Insert(new DNA_Config_Weapons_Smol("Winchester70", "", 0, "AmmoBox_308WIN_20Rnd", 1, "HuntingOptic", "", "", "", "", ""));
		config.dna_SpawnLootSet1 = true;
		config.dna_RandomizeLootSet1 = true;
		config.dna_LootSet1Count = 3;
		config.dna_LootSetR1 = {"BloodTestKit","TetracyclineAntibiotics","BandageDressing","BloodBagIV","Morphine","Epinephrine"};
		config.dna_SpawnLootSet2 = true;
		config.dna_RandomizeLootSet2 = true;
		config.dna_LootSet2Count = 3;
		config.dna_LootSetR2 = {"BoxCerealCrunchin","PeachesCan_Opened","TacticalBaconCan","BakedBeansCan","BakedBeansCan_Opened"};
		config.dna_SpawnLootSet3 = true;
		config.dna_RandomizeLootSet3 = true;
		config.dna_LootSet3Count = 3;
		config.dna_LootSetR3 = {"SodaCan_Pipsi","WaterBottle","SodaCan_Fronta","SodaCan_Cola","SodaCan_Spite"};
		config.dna_SpawnLootSet4 = true;
		config.dna_RandomizeLootSet4 = false;
		config.dna_LootSet4Count = 3;
		config.dna_LootSetR4 = {"WoodenPlank","NailBox","Shovel","WoodAxe","Screwdriver"};
		JsonFileLoader<CrateSmol_Red_Settings>.JsonSaveFile(SmolCrateRedConfig, config);
	}
	
	static CrateSmol_TimerSettings GetTimerSettings()
	{
		if(dna_TimerSettings == NULL && GetGame().IsDedicatedServer())
			InitSmolTimerSettings();
		
		return dna_TimerSettings;
	}
	
	static void InitSmolTimerSettings()
	{
		if(GetGame().IsDedicatedServer())
			dna_TimerSettings = LoadTimerSettings();
	}
	
	private static CrateSmol_TimerSettings LoadTimerSettings()
	{
		CrateSmol_TimerSettings config = new CrateSmol_TimerSettings;
		if(!FileExist(SmolCrateConfig))
		{
			if(GetGame().IsDedicatedServer())
			{
				Print("[DNA DEBUG] - Smol Crate Base Config not found.... Creating now.");
				CreateDefault(config);
			}
		}
		else
		{
			if(GetGame().IsDedicatedServer())
				Print("[DNA DEBUG] - Smol Crate Base Config Found.... Loading");
		}
		JsonFileLoader<CrateSmol_TimerSettings>.JsonLoadFile(SmolCrateConfig, config);
		
		return config;
	}
	
	private static void CreateDefault(CrateSmol_TimerSettings config)
	{
		config.dna_Description = "Config for spawning and respawning smol crates. In order to use this to spawn smol crates, set dna_SpawnSmolCrates to true, and add your"; 
		config.dna_DescriptionCont = "locations, and orientations along with the desired tier. To use timer settings, the timer must be activated in ResetTimer_Config.json.";
		config.dna_ResetSmolCrates = false;
		config.dna_TimeUntilYellowSmolCrateResets = 30;
		config.dna_TimeUntilGreenSmolCrateResets = 30;
		config.dna_TimeUntilBlueSmolCrateResets = 30;
		config.dna_TimeUntilPurpleSmolCrateResets = 30;
		config.dna_TimeUntilRedSmolCrateResets = 30;
		config.dna_SpawnSmolCrates = false;
		config.dna_CrateSpawns.Insert(new DNA_Smol_Crate_Spawns("Yellow", "0.0 0.0 0.0", "0.0 0.0 0.0"));
		config.dna_CrateSpawns.Insert(new DNA_Smol_Crate_Spawns("Green", "0.0 0.0 0.0", "0.0 0.0 0.0"));
		config.dna_CrateSpawns.Insert(new DNA_Smol_Crate_Spawns("Blue", "0.0 0.0 0.0", "0.0 0.0 0.0"));
		config.dna_CrateSpawns.Insert(new DNA_Smol_Crate_Spawns("Purple", "0.0 0.0 0.0", "0.0 0.0 0.0"));
		config.dna_CrateSpawns.Insert(new DNA_Smol_Crate_Spawns("Red", "0.0 0.0 0.0", "0.0 0.0 0.0"));
		JsonFileLoader<CrateSmol_TimerSettings>.JsonSaveFile(SmolCrateConfig, config);
	}
}

class DNA_Config_Weapons_Smol
{
	string dna_TheChosenOne;
	string dna_Magazine;
	int dna_SpareMagCount;
	string dna_Ammunition;
	int dna_SpareAmmoCount;
	string dna_OpticType;
	string dna_Suppressor;
	string dna_UnderBarrel;
	string dna_ButtStock;
	string dna_HandGuard;
	string dna_Wrap;
	
	void DNA_Config_Weapons_Smol(string theChosenOne, string magazine, int spareMagCount, string ammunition, int spareAmmoCount, string opticType, string suppressor, string underBarrel, string buttStock, string handGuard, string wrap)
	{
		dna_TheChosenOne = theChosenOne;
		dna_Magazine = magazine;
		dna_SpareMagCount = spareMagCount;
		dna_Ammunition = ammunition;
		dna_SpareAmmoCount = spareAmmoCount;
		dna_OpticType = opticType;
		dna_Suppressor = suppressor;
		dna_UnderBarrel = underBarrel;
		dna_ButtStock = buttStock;
		dna_HandGuard = handGuard;
		dna_Wrap = wrap;
	}
	
	/*don't think I need any of this shit below, but we'll see*/
	string GetTheChosenOne()
	{
		return dna_TheChosenOne;
	}	
		
	string GetOpticType()
	{
		return dna_OpticType;
	}
	
	string GetSuppressor()
	{
		return dna_Suppressor;
	}
	
	string GetButtStock()
	{
		return dna_ButtStock;
	}
	
	string GetHandGuard()
	{
		return dna_HandGuard;
	}
	
	string GetUnderBarrel()
	{
		return dna_UnderBarrel;
	}
	
	string GetMagazine()
	{
		return dna_Magazine;
	}
	
	string GetAmmunition()
	{
		return dna_Ammunition;
	}
	
	string GetWrap()
	{
		return dna_Wrap;
	}
	
	int GetSpareMagCount()
	{
		return dna_SpareMagCount;
	}
	
	int GetSpareAmmoCount()
	{
		return dna_SpareAmmoCount;
	}
}
	
class DNA_Smol_Crate_Spawns
{
	string dna_Tier, dna_Location, dna_Rotation;
	
	void DNA_Smol_Crate_Spawns(string tier, string location, string rotation)
	{
		dna_Tier = tier;
		dna_Location = location;
		dna_Rotation = rotation;
	}
}

class CrateSmol_TimerSettings
{
	string dna_Description, dna_DescriptionCont;
	ref array<ref DNA_Smol_Crate_Spawns> dna_CrateSpawns;
	bool dna_SpawnSmolCrates, dna_ResetSmolCrates;
	int dna_TimeUntilYellowSmolCrateResets, dna_TimeUntilGreenSmolCrateResets, dna_TimeUntilBlueSmolCrateResets, dna_TimeUntilPurpleSmolCrateResets, dna_TimeUntilRedSmolCrateResets;
	
	void CrateSmol_TimerSettings()
	{
		dna_CrateSpawns = new array<ref DNA_Smol_Crate_Spawns>;
	}
}