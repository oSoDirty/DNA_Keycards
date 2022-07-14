class KeyCard_Config_Main_System
{	
	protected static ref KeyCard_ConfigData_Main_System m_KeyCard_Main_System_ConfigData;
	protected static bool dna_UpdateCheckComplete;
	protected static bool dna_RecentlyUpdated;
	
	void KeyCard_Config_Main_System()
	{
		if(GetGame().IsDedicatedServer())
			LoadConfig();
	}
	
	static void CreateMainDirectory()
	{
		if(GetGame().IsDedicatedServer())
		{
			if (!FileExist(dna_ProfilePath + dna_ConfigFolderName + "/"))
			{
				Print("[DNA DEBUG] - DNA_Keycards Config: Main directory not found, creating directory!");
				MakeDirectory(dna_ProfilePath + dna_ConfigFolderName + "/");
			}
		}
	}
	
	static void CheckForConfigUpdate()
	{
		dna_RecentlyUpdated = false;/*
		array<string> configPaths =
		{
			dna_MainSystemConfigPath,
			dna_LootContainersSystemConfigPath
			//need loot paths
		};
		array<string> categories =
		{
			"system_main",
			"system_containers"
		};
		int dna_ConfigcppVersion = GetGame().ConfigGetInt("CfgMods DNA_Keycards_Scripts configVersion");
		if(FileExist(dna_ProfilePath + dna_ConfigFolderName) && dna_ConfigcppVersion != DNA_Keycards_Main_System.GetInstance().GetConfig().GetConfigData().GetVersionArray().Get(0).GetConfigVersion())
		{
			if(!FileExist(dna_BackupConfigFolderPath))
				MakeDirectory(dna_BackupConfigFolderPath);
			
			for(int i = 0; i < categories.Count(); i++)
			{
				string existingConfig = configPaths[i];
				if(FileExist(existingConfig))
				{
					string backupConfig = dna_BackupConfigFolderPath + "/" + categories[i] + ".json";
					if(FileExist(backupConfig))
						DeleteFile(backupConfig);
					CopyFile(existingConfig, backupConfig);
					DeleteFile(existingConfig);
					if(i > 2)
						DeleteFile(dna_ConfigFolderPath + categories[i]);
				}
			}
			dna_RecentlyUpdated = true;
			Print("[DNA DEBUG] - Configs outdated! Creating backups in Profile/DNA_Keycards/ConfigBackups and placing new defaults. Don't forget to merge your old settings!!!");
		}*/
	}
	
	static void CheckForPreLoadedConfig()
	{/*
		if(FileExist(dna_PreloadConfigFolderPath))
		{
			Print("DNA KEYCARDS - Preloaded configs found, looks like someone did their homework!");
			if (!FileExist(dna_ProfilePath + dna_ConfigFolderName + "/System/"))
			{
				Print("[DNA DEBUG] - DNA_Keycards System: Directory not found, creating directory!");
				MakeDirectory(dna_ProfilePath + dna_ConfigFolderName + "/System/");
			}
			if (!FileExist(dna_ProfilePath + dna_ConfigFolderName + "/System/Main/"))
			{
				Print("[DNA DEBUG] - DNA_Keycards Main System: Directory not found, creating directory!");
				MakeDirectory(dna_ProfilePath + dna_ConfigFolderName + "/System/Main/");
			}
			if (!FileExist(dna_ProfilePath + dna_ConfigFolderName + "/System/Crate/"))
			{
				Print("[DNA DEBUG] - DNA_Keycards Crate System: Directory not found, creating directory!");
				MakeDirectory(dna_ProfilePath + dna_ConfigFolderName + "/System/Crate/");
			}
			if (!FileExist(dna_ProfilePath + dna_ConfigFolderName + "/System/Strongroom/"))
			{
				Print("[DNA DEBUG] - DNA_Keycards Strongroom System: Directory not found, creating directory!");
				MakeDirectory(dna_ProfilePath + dna_ConfigFolderName + "/System/Strongroom/");
			}
			if (!FileExist(dna_ProfilePath + dna_ConfigFolderName + "/Loot/"))
			{
				MakeDirectory(dna_ProfilePath + dna_ConfigFolderName + "/Loot/");
			}
			if (!FileExist(dna_ProfilePath + dna_ConfigFolderName + "/Loot/General/"))
			{
				Print("[DNA DEBUG] - DNA Keycards General Loot: Directory not found, creating directory!");
				MakeDirectory(dna_ProfilePath + dna_ConfigFolderName + "/Loot/General/");
			}
			if (!FileExist(dna_ProfilePath + dna_ConfigFolderName + "/Loot/Clothing/"))
			{
				Print("[DNA DEBUG] - DNA Keycards Clothing Loot: Directory not found, creating directory!");
				MakeDirectory(dna_ProfilePath + dna_ConfigFolderName + "/Loot/Clothing/");
			}
			if (!FileExist(dna_ProfilePath + dna_ConfigFolderName + "/Loot/Weapons/"))
			{
				Print("[DNA DEBUG] - DNA Keycards Weapon Loot: Directory not found, creating directory!");
				MakeDirectory(dna_ProfilePath + dna_ConfigFolderName + "/Loot/Weapons/");
			}
			array<string> configPaths =
			{
				dna_MainSystemConfigPath,
				dna_CrateSystemConfigPath,
				dna_StrongroomSystemConfigPath,
				dna_LootConfigPath,
				dna_ClothingConfigPath,
				dna_WeaponConfigPath
			};
			array<string> preloadedConfigPaths =
			{
				dna_PreloadMainSystemConfigPath,
				dna_PreloadCrateSystemConfigPath,
				dna_PreloadStrongroomSystemConfigPath,
				dna_PreloadLootConfigPath,
				dna_PreloadClothingConfigPath,
				dna_PreloadWeaponConfigPath
			};
			for(int i = 0; i < configPaths.Count(); i++)
			{
				if(FileExist(preloadedConfigPaths[i]))
				{
					if(FileExist(configPaths[i]))
						DeleteFile(configPaths[i]);
					CopyFile(preloadedConfigPaths[i], configPaths[i]);
					DeleteFile(preloadedConfigPaths[i]);
				}
			}
			DeleteFile(dna_PreloadConfigFolderPath + "/" + dna_ConfigFolderName + "/System/Main");
			DeleteFile(dna_PreloadConfigFolderPath + "/" + dna_ConfigFolderName + "/System/Crate");
			DeleteFile(dna_PreloadConfigFolderPath + "/" + dna_ConfigFolderName + "/System/Strongroom");
			DeleteFile(dna_PreloadConfigFolderPath + "/" + dna_ConfigFolderName + "/System");
			DeleteFile(dna_PreloadConfigFolderPath + "/" + dna_ConfigFolderName + "/Loot/General");
			DeleteFile(dna_PreloadConfigFolderPath + "/" + dna_ConfigFolderName + "/Loot/Clothing");
			DeleteFile(dna_PreloadConfigFolderPath + "/" + dna_ConfigFolderName + "/Loot/Weapons");
			DeleteFile(dna_PreloadConfigFolderPath + "/" + dna_ConfigFolderName + "/Loot");
			DeleteFile(dna_PreloadConfigFolderPath + "/" + dna_ConfigFolderName);
			DeleteFile(dna_PreloadConfigFolderPath);
		}*/
		dna_UpdateCheckComplete = true;
	}
	
	static bool HasBeenChecked()
	{
		return dna_UpdateCheckComplete;
	}
	
	static bool RecentlyUpdated()
	{
		return dna_RecentlyUpdated;
	}
	
	KeyCard_ConfigData_Main_System GetConfigData()
	{
		if(!m_KeyCard_Main_System_ConfigData)
		{
			LoadConfig();
		}
		return m_KeyCard_Main_System_ConfigData;
	}
	
	protected static void LoadConfig()
	{	
		if(GetGame().IsDedicatedServer())
		{
			if (!FileExist(dna_ProfilePath + dna_ConfigFolderName + "/System/"))
			{
				Print("[DNA DEBUG] - DNA_Keycards System: Directory not found, creating directory!");
				MakeDirectory(dna_ProfilePath + dna_ConfigFolderName + "/System/");
			}
			
			if (!FileExist(dna_ProfilePath + dna_ConfigFolderName + "/System/Main/"))
			{
				Print("[DNA DEBUG] - DNA_Keycards Main System: Directory not found, creating directory!");
				MakeDirectory(dna_ProfilePath + dna_ConfigFolderName + "/System/Main/");
			}
			
			m_KeyCard_Main_System_ConfigData = new KeyCard_ConfigData_Main_System();
			
			if (!FileExist(dna_MainSystemConfigPath))
			{
				if(!RecentlyUpdated()) Print("[DNA DEBUG] - DNA_Keycards Main System Settings: Config not found, creating default config!");
				CreateDefaultConfig();
			}
			else
			{
				JsonFileLoader<KeyCard_ConfigData_Main_System>.JsonLoadFile(dna_MainSystemConfigPath, m_KeyCard_Main_System_ConfigData);
				if(dna_UpdateCheckComplete) Print("[DNA DEBUG] - DNA_Keycards Main System Settings: Config found, loading settings!");
			}
		}
	}
	
	static void CreateDefaultConfig()
	{
		m_KeyCard_Main_System_ConfigData.GetVersionArray().Insert(new DNA_Config_Version("DO NOT CHANGE THIS! IT WILL DELETE YOUR CONFIGS!!!!!!(but also creates backups ;) )", 2));
		
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Main_System("(0) Use DNA To Spawn Crates (0 = off, 1 = random, 2 = static) If off, you will need to place the crates yourself" ,0));
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Main_System("(1) Use DNA To Spawn Strongrooms (0 = off, 1 = random, 2 = static) If off, you will need to place the Strongrooms yourself" ,0));
		
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Main_System("(2) Yellow Crates Spawn Count (If static or off, ignore setting. 0 to turn off this tier, don't set higher than number of available positions",0));
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Main_System("(3) Green Crates Spawn Count (If static or off, ignore setting. 0 to turn off this tier, don't set higher than number of available positions",0));
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Main_System("(4) Blue Crates Spawn Count (If static or off, ignore setting. 0 to turn off this tier, don't set higher than number of available positions",0));
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Main_System("(5) Purple Crates Spawn Count (If static or off, ignore setting. 0 to turn off this tier, don't set higher than number of available positions",0));
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Main_System("(6) Red Crates Spawn Count (If static or off, ignore setting. 0 to turn off this tier, don't set higher than number of available positions",0));
		
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Main_System("(7) Yellow Strongrooms Spawn Count (If static or off, ignore setting. 0 to turn off this tier, don't set higher than number of available positions",0));
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Main_System("(8) Green Strongrooms Spawn Count (If static or off, ignore setting. 0 to turn off this tier, don't set higher than number of available positions",0));
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Main_System("(9) Blue Strongrooms Spawn Count (If static or off, ignore setting. 0 to turn off this tier, don't set higher than number of available positions",0));
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Main_System("(10) Purple Strongrooms Spawn Count (If static or off, ignore setting. 0 to turn off this tier, don't set higher than number of available positions",0));
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Main_System("(11) Red Strongrooms Spawn Count (If static or off, ignore setting. 0 to turn off this tier, don't set higher than number of available positions",0));
		
		
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Main_System("(12) Yellow Card Usage Allotment", 2));
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Main_System("(13) Green Card Usage Allotment", 2));
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Main_System("(14) Blue Card Usage Allotment", 1));
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Main_System("(15) Purple Card Usage Allotment", 1));
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Main_System("(16) Red Card Usage Allotment", 1));
		
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Main_System("(17) Separate Sidearms by tier (1 = Yes, 0 = No)",0));
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Main_System("(18) Separate Food and Drink by tier (1 = Yes, 0 = No)",0));
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Main_System("(19) Separate Tools by tier (1 = Yes, 0 = No)",0));
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Main_System("(20) Separate Meds by tier (1 = Yes, 0 = No)",0));
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Main_System("(21) Separate Materials by tier (1 = Yes, 0 = No)",0));
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Main_System("(22) Separate Miscellaneous by tier (1 = Yes, 0 = No)",1));
		
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Main_System("(23) Yellow Strongrooms spawn this many wolves when opened - (0 = off - 10 =  max)", 0));
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Main_System("(24) Yellow Strongrooms spawn this many bears when opened - (0 = off - 6 =  max)", 0));
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Main_System("(25) Yellow Strongrooms spawn this many infected when opened - (0 = off - 40 =  max)", 0));
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Main_System("(26) Yellow Strongrooms alarm toggle - (0 = Off - 1 = On)", 0));
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Main_System("(27) Yellow Strongrooms notification range - (0 = Off - Max 2000m - 2001+ shows full server)", 0));
		
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Main_System("(28) Green Strongrooms spawn this many wolves when opened - (0 = off - 10 =  max)", 0));
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Main_System("(29) Green Strongrooms spawn this many bears when opened - (0 = off - 6 =  max)", 0));
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Main_System("(30) Green Strongrooms spawn this many infected when opened - (0 = off - 40 =  max)", 0));
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Main_System("(31) Green Strongrooms alarm toggle - (0 = Off - 1 = On)", 0));
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Main_System("(32) Green Strongrooms notification range - (0 = Off - Max 2000m - 2001+ shows full server)", 0));
		
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Main_System("(33) Blue Strongrooms spawn this many wolves when opened - (0 = off - 10 =  max)", 0));
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Main_System("(34) Blue Strongrooms spawn this many bears when opened - (0 = off - 6 =  max)", 0));
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Main_System("(35) Blue Strongrooms spawn this many infected when opened - (0 = off - 40 =  max)", 0));
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Main_System("(36) Blue Strongrooms alarm toggle - (0 = Off - 1 = On)", 0));
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Main_System("(37) Blue Strongrooms notification range - (0 = Off - Max 2000m - 2001+ shows full server)", 0));
		
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Main_System("(38) Purple Strongrooms spawn this many wolves when opened - (0 = off - 10 =  max)", 0));
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Main_System("(39) Purple Strongrooms spawn this many bears when opened - (0 = off - 6 =  max)", 0));
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Main_System("(40) Purple Strongrooms spawn this many infected when opened - (0 = off - 40 =  max)", 0));
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Main_System("(41) Purple Strongrooms alarm toggle - (0 = Off - 1 = On)", 0));
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Main_System("(42) Purple Strongrooms notification range - (0 = Off - Max 2000m - 2001+ shows full server)", 0));
		
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Main_System("(43) Red Strongrooms spawn this many wolves when opened - (0 = off - 10 =  max)", 0));
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Main_System("(44) Red Strongrooms spawn this many bears when opened - (0 = off - 6 =  max)", 0));
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Main_System("(45) Red Strongrooms spawn this many infected when opened - (0 = off - 40 =  max)", 0));
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Main_System("(46) Red Strongrooms alarm toggle - (0 = Off - 1 = On)", 0));
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Main_System("(47) Red Strongrooms notification range - (0 = Off - Max 2000m - 2001+ shows full server)", 0));
		
		
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Main_System("(48) Yellow Crates alarm toggle - (0 = Off - 1 = On)", 0));
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Main_System("(49) Yellow Crates notification range - (0 = Off - Max 2000m - 2001+ shows full server)", 0));
		
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Main_System("(50) Green Crates alarm toggle - (0 = Off - 1 = On)", 0));
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Main_System("(51) Green Crates notification range - (0 = Off - Max 2000m - 2001+ shows full server)", 0));
		
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Main_System("(52) Blue Crates alarm toggle - (0 = Off - 1 = On)", 0));
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Main_System("(53) Blue Crates notification range - (0 = Off - Max 2000m - 2001+ shows full server)", 0));
		
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Main_System("(54) Purple Crates alarm toggle - (0 = Off - 1 = On)", 0));
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Main_System("(55) Purple Crates notification range - (0 = Off - Max 2000m - 2001+ shows full server)", 0));
		
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Main_System("(56) Red Crates alarm toggle - (0 = Off - 1 = On)", 0));
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Main_System("(57) Red Crates notification range - (0 = Off - Max 2000m - 2001+ shows full server)", 0));
		
		
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Main_System("(58) Yellow Lockout Doors alarm toggle - (0 = Off - 1 = On)", 0));
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Main_System("(59) Yellow Lockout Doors notification range - (0 = Off - Max 2000m - 2001+ shows full server)", 0));
		
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Main_System("(60) Green Lockout Doors alarm toggle - (0 = Off - 1 = On)", 0));
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Main_System("(61) Green Lockout Doors notification range - (0 = Off - Max 2000m - 2001+ shows full server)", 0));
		
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Main_System("(62) Blue Lockout Doors alarm toggle - (0 = Off - 1 = On)", 0));
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Main_System("(63) Blue Lockout Doors notification range - (0 = Off - Max 2000m - 2001+ shows full server)", 0));
		
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Main_System("(64) Purple Lockout Doors alarm toggle - (0 = Off - 1 = On)", 0));
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Main_System("(65) Purple Lockout Doors notification range - (0 = Off - Max 2000m - 2001+ shows full server)", 0));
		
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Main_System("(66) Red Lockout Doors alarm toggle - (0 = Off - 1 = On)", 0));
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Main_System("(67) Red Lockout Doors notification range - (0 = Off - Max 2000m - 2001+ shows full server)", 0));
		
		
		m_KeyCard_Main_System_ConfigData.GetLocationsYArray().Insert(new DNA_Yellow_Crate_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_Main_System_ConfigData.GetLocationsYArray().Insert(new DNA_Yellow_Crate_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_Main_System_ConfigData.GetLocationsYArray().Insert(new DNA_Yellow_Crate_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_Main_System_ConfigData.GetLocationsYArray().Insert(new DNA_Yellow_Crate_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_Main_System_ConfigData.GetLocationsYArray().Insert(new DNA_Yellow_Crate_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		
		m_KeyCard_Main_System_ConfigData.GetLocationsGArray().Insert(new DNA_Green_Crate_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_Main_System_ConfigData.GetLocationsGArray().Insert(new DNA_Green_Crate_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_Main_System_ConfigData.GetLocationsGArray().Insert(new DNA_Green_Crate_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_Main_System_ConfigData.GetLocationsGArray().Insert(new DNA_Green_Crate_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_Main_System_ConfigData.GetLocationsGArray().Insert(new DNA_Green_Crate_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		
		m_KeyCard_Main_System_ConfigData.GetLocationsBArray().Insert(new DNA_Blue_Crate_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_Main_System_ConfigData.GetLocationsBArray().Insert(new DNA_Blue_Crate_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_Main_System_ConfigData.GetLocationsBArray().Insert(new DNA_Blue_Crate_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_Main_System_ConfigData.GetLocationsBArray().Insert(new DNA_Blue_Crate_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_Main_System_ConfigData.GetLocationsBArray().Insert(new DNA_Blue_Crate_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		
		m_KeyCard_Main_System_ConfigData.GetLocationsPArray().Insert(new DNA_Purple_Crate_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_Main_System_ConfigData.GetLocationsPArray().Insert(new DNA_Purple_Crate_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_Main_System_ConfigData.GetLocationsPArray().Insert(new DNA_Purple_Crate_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_Main_System_ConfigData.GetLocationsPArray().Insert(new DNA_Purple_Crate_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_Main_System_ConfigData.GetLocationsPArray().Insert(new DNA_Purple_Crate_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		
		m_KeyCard_Main_System_ConfigData.GetLocationsRArray().Insert(new DNA_Red_Crate_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_Main_System_ConfigData.GetLocationsRArray().Insert(new DNA_Red_Crate_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_Main_System_ConfigData.GetLocationsRArray().Insert(new DNA_Red_Crate_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_Main_System_ConfigData.GetLocationsRArray().Insert(new DNA_Red_Crate_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_Main_System_ConfigData.GetLocationsRArray().Insert(new DNA_Red_Crate_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		
		m_KeyCard_Main_System_ConfigData.GetStrongroomLocationsYArray().Insert(new DNA_Yellow_Strongroom_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_Main_System_ConfigData.GetStrongroomLocationsYArray().Insert(new DNA_Yellow_Strongroom_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_Main_System_ConfigData.GetStrongroomLocationsYArray().Insert(new DNA_Yellow_Strongroom_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_Main_System_ConfigData.GetStrongroomLocationsYArray().Insert(new DNA_Yellow_Strongroom_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_Main_System_ConfigData.GetStrongroomLocationsYArray().Insert(new DNA_Yellow_Strongroom_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		
		m_KeyCard_Main_System_ConfigData.GetStrongroomLocationsGArray().Insert(new DNA_Green_Strongroom_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_Main_System_ConfigData.GetStrongroomLocationsGArray().Insert(new DNA_Green_Strongroom_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_Main_System_ConfigData.GetStrongroomLocationsGArray().Insert(new DNA_Green_Strongroom_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_Main_System_ConfigData.GetStrongroomLocationsGArray().Insert(new DNA_Green_Strongroom_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_Main_System_ConfigData.GetStrongroomLocationsGArray().Insert(new DNA_Green_Strongroom_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		
		m_KeyCard_Main_System_ConfigData.GetStrongroomLocationsBArray().Insert(new DNA_Blue_Strongroom_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_Main_System_ConfigData.GetStrongroomLocationsBArray().Insert(new DNA_Blue_Strongroom_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_Main_System_ConfigData.GetStrongroomLocationsBArray().Insert(new DNA_Blue_Strongroom_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_Main_System_ConfigData.GetStrongroomLocationsBArray().Insert(new DNA_Blue_Strongroom_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_Main_System_ConfigData.GetStrongroomLocationsBArray().Insert(new DNA_Blue_Strongroom_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		
		m_KeyCard_Main_System_ConfigData.GetStrongroomLocationsPArray().Insert(new DNA_Purple_Strongroom_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_Main_System_ConfigData.GetStrongroomLocationsPArray().Insert(new DNA_Purple_Strongroom_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_Main_System_ConfigData.GetStrongroomLocationsPArray().Insert(new DNA_Purple_Strongroom_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_Main_System_ConfigData.GetStrongroomLocationsPArray().Insert(new DNA_Purple_Strongroom_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_Main_System_ConfigData.GetStrongroomLocationsPArray().Insert(new DNA_Purple_Strongroom_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		
		m_KeyCard_Main_System_ConfigData.GetStrongroomLocationsRArray().Insert(new DNA_Red_Strongroom_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_Main_System_ConfigData.GetStrongroomLocationsRArray().Insert(new DNA_Red_Strongroom_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_Main_System_ConfigData.GetStrongroomLocationsRArray().Insert(new DNA_Red_Strongroom_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_Main_System_ConfigData.GetStrongroomLocationsRArray().Insert(new DNA_Red_Strongroom_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_Main_System_ConfigData.GetStrongroomLocationsRArray().Insert(new DNA_Red_Strongroom_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		
		JsonFileLoader<KeyCard_ConfigData_Main_System>.JsonSaveFile(dna_MainSystemConfigPath, m_KeyCard_Main_System_ConfigData);
	}
}