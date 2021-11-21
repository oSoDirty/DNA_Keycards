class KeyCard_Config_Main_System
{	
	protected static ref KeyCard_ConfigData_Main_System m_KeyCard_Main_System_ConfigData;
	protected static bool kcm_UpdateCheckComplete;
	protected static bool kcm_RecentlyUpdated = false;
	
	void KeyCard_Config_Main_System()
	{
		LoadConfig();
	}
	
	static void CreateMainDirectory()
	{
		if (!FileExist(kcm_ProfilePath + kcm_ConfigFolderName + "/"))
        {
			Print("[KCM Debug] - DNA_Keycards Config: Main directory not found, creating directory!");
			MakeDirectory(kcm_ProfilePath + kcm_ConfigFolderName + "/");
		}
	}
	
	static void CheckForConfigUpdate()
	{
		array<string> configPaths =
		{
			kcm_MainSystemConfigPath,
			kcm_CrateSystemConfigPath,
			kcm_VaultSystemConfigPath,
			kcm_BasicConfigPath,
			kcm_YellowConfigPath,
			kcm_GreenConfigPath,
			kcm_BlueConfigPath,
			kcm_PurpleConfigPath,
			kcm_RedConfigPath
		};
		array<string> categoties =
		{
			"main_system",
			"crate_system",
			"vault_system",
			"basic",
			"yellow",
			"green",
			"blue",
			"purple",
			"red"
		};
		string kcm_ConfigcppVersion;
		GetGame().ConfigGetText("CfgMods DNA_Keycards configVersion", kcm_ConfigcppVersion);
		if(FileExist(kcm_ProfilePath + kcm_ConfigFolderName) && kcm_ConfigcppVersion != DNA_Keycards_Main_System.GetInstance().GetConfig().GetConfigData().GetVersionArray().Get(0).GetConfigVersion())
		{
			if(!FileExist(kcm_BackupConfigFolderPath))
				MakeDirectory(kcm_BackupConfigFolderPath);
			
			for(int i = 0; i < categoties.Count(); i++)
			{
				string existingConfig = configPaths.Get(i);
				if(FileExist(existingConfig))
				{
					string backupConfig = kcm_BackupConfigFolderPath + "/" + categoties.Get(i) + ".json";
					if(FileExist(backupConfig))
						DeleteFile(backupConfig);
					CopyFile(existingConfig, backupConfig);
					DeleteFile(existingConfig);
				}
			}
			kcm_RecentlyUpdated = true;
			Print("[KCM Debug] - Configs outdated! Creating backups in Profile/DNA_Keycards/ConfigBackups and placing new defaults. Don't forget to merge your old settings!!!");
		}
		kcm_UpdateCheckComplete = true;
	}
	
	static bool RecentlyUpdated()
	{
		return kcm_RecentlyUpdated;
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
		if (!FileExist(kcm_ProfilePath + kcm_ConfigFolderName + "/System/"))
        {
			Print("[KCM Debug] - DNA_Keycards System: Directory not found, creating directory!");
			MakeDirectory(kcm_ProfilePath + kcm_ConfigFolderName + "/System/");
		}
		
		if (!FileExist(kcm_ProfilePath + kcm_ConfigFolderName + "/System/Main/"))
        {
			Print("[KCM Debug] - DNA_Keycards Main System: Directory not found, creating directory!");
			MakeDirectory(kcm_ProfilePath + kcm_ConfigFolderName + "/System/Main/");
		}
		
		m_KeyCard_Main_System_ConfigData = new KeyCard_ConfigData_Main_System();
		
		if (!FileExist(kcm_MainSystemConfigPath))
        {
			if(!RecentlyUpdated()) Print("[KCM Debug] - DNA_Keycards Main System Settings: Config not found, creating default config!");
            CreateDefaultConfig();
        }
		else
		{
			JsonFileLoader<KeyCard_ConfigData_Main_System>.JsonLoadFile(kcm_MainSystemConfigPath, m_KeyCard_Main_System_ConfigData);
			if(kcm_UpdateCheckComplete) Print("[KCM Debug] - DNA_Keycards Main System Settings: Config found, loading settings!");
		}
	}
	
	static void CreateDefaultConfig()
	{
		m_KeyCard_Main_System_ConfigData.GetVersionArray().Insert(new KCM_Config_Version("DO NOT CHANGE THIS! IT WILL DELETE YOUR CONFIG!!!!!!(but also creates a backup ;) )", "1.0"));
		
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Main_System("(0) Use KCM To Random Spawn Crates (1 true, 0 false) If false, you will need to place the crates yourself" ,1));
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Main_System("(1) Use KCM To Random Spawn Vaults (1 true, 0 false) If false, you will need to place the crates yourself" ,0));
		
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Main_System("(2) Yellow Crates Spawn Count (0 to turn off this tier, don't set higher than number of available positions",5));
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Main_System("(3) Green Crates Spawn Count (0 to turn off this tier, don't set higher than number of available positions",4));
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Main_System("(4) Blue Crates Spawn Count (0 to turn off this tier, don't set higher than number of available positions",3));
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Main_System("(5) Purple Crates Spawn Count (0 to turn off this tier, don't set higher than number of available positions",2));
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Main_System("(6) Red Crates Spawn Count (0 to turn off this tier, don't set higher than number of available positions",1));
		
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Main_System("(7) Yellow Vaults Spawn Count (0 to turn off this tier, don't set higher than number of available positions",0));
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Main_System("(8) Green Vaults Spawn Count (0 to turn off this tier, don't set higher than number of available positions",0));
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Main_System("(9) Blue Vaults Spawn Count (0 to turn off this tier, don't set higher than number of available positions",1));
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Main_System("(10) Purple Vaults Spawn Count (0 to turn off this tier, don't set higher than number of available positions",1));
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Main_System("(11) Red Vaults Spawn Count (0 to turn off this tier, don't set higher than number of available positions",1));
		
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Main_System("(12) Yellow Card Usage Allotment", 5));
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Main_System("(13) Green Card Usage Allotment", 4));
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Main_System("(14) Blue Card Usage Allotment", 3));
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Main_System("(15) Purple Card Usage Allotment", 2));
		m_KeyCard_Main_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Main_System("(16) Red Card Usage Allotment", 1));
		
		m_KeyCard_Main_System_ConfigData.GetLocationsYArray().Insert(new KCM_Yellow_Crate_Locations("4670.778809 339.372198 9856.767578", "0.000000 -0.000000 -0.000000"));
		m_KeyCard_Main_System_ConfigData.GetLocationsYArray().Insert(new KCM_Yellow_Crate_Locations("4669.937012 339.372168 9848.751953", "0.000000 -0.000000 -0.000000"));
		m_KeyCard_Main_System_ConfigData.GetLocationsYArray().Insert(new KCM_Yellow_Crate_Locations("4667.031738 339.372198 9860.922852", "0.000000 -0.000000 -0.000000"));
		m_KeyCard_Main_System_ConfigData.GetLocationsYArray().Insert(new KCM_Yellow_Crate_Locations("4664.092285 339.372198 9862.980469", "0.000000 -0.000000 -0.000000"));
		m_KeyCard_Main_System_ConfigData.GetLocationsYArray().Insert(new KCM_Yellow_Crate_Locations("4665.296875 339.372168 9860.949219", "0.000000 -0.000000 -0.000000"));
		
		m_KeyCard_Main_System_ConfigData.GetLocationsGArray().Insert(new KCM_Green_Crate_Locations("4659.698730 339.372198 9879.450195", "0.000000 -0.000000 -0.000000"));
		m_KeyCard_Main_System_ConfigData.GetLocationsGArray().Insert(new KCM_Green_Crate_Locations("4658.307617 339.372198 9877.361328", "0.000000 -0.000000 -0.000000"));
		m_KeyCard_Main_System_ConfigData.GetLocationsGArray().Insert(new KCM_Green_Crate_Locations("4662.786133 339.372198 9877.178711", "0.000000 -0.000000 -0.000000"));
		m_KeyCard_Main_System_ConfigData.GetLocationsGArray().Insert(new KCM_Green_Crate_Locations("4663.692383 339.372198 9879.638672", "0.000000 -0.000000 -0.000000"));
		m_KeyCard_Main_System_ConfigData.GetLocationsGArray().Insert(new KCM_Green_Crate_Locations("4666.832520 339.372260 9877.065430", "0.000000 -0.000000 -0.000000"));
		
		m_KeyCard_Main_System_ConfigData.GetLocationsBArray().Insert(new KCM_Blue_Crate_Locations("4672.081055 339.372198 9884.833008", "0.000000 -0.000000 -0.000000"));
		m_KeyCard_Main_System_ConfigData.GetLocationsBArray().Insert(new KCM_Blue_Crate_Locations("4672.953613 339.372290 9887.461914", "0.000000 -0.000000 -0.000000"));
		m_KeyCard_Main_System_ConfigData.GetLocationsBArray().Insert(new KCM_Blue_Crate_Locations("4675.708008 339.372229 9889.149414", "0.000000 -0.000000 -0.000000"));
		m_KeyCard_Main_System_ConfigData.GetLocationsBArray().Insert(new KCM_Blue_Crate_Locations("4676.007324 339.372229 9886.689453", "0.000000 -0.000000 -0.000000"));
		m_KeyCard_Main_System_ConfigData.GetLocationsBArray().Insert(new KCM_Blue_Crate_Locations("4675.590820 339.372137 9883.307617", "0.000000 -0.000000 -0.000000"));
		
		m_KeyCard_Main_System_ConfigData.GetLocationsPArray().Insert(new KCM_Purple_Crate_Locations("4682.869141 339.372168 9889.340820", "0.000000 -0.000000 -0.000000"));
		m_KeyCard_Main_System_ConfigData.GetLocationsPArray().Insert(new KCM_Purple_Crate_Locations("4685.238770 339.403998 9888.849609", "0.000000 -0.000000 -0.000000"));
		m_KeyCard_Main_System_ConfigData.GetLocationsPArray().Insert(new KCM_Purple_Crate_Locations("4687.677246 339.408362 9886.628906", "0.000000 -0.000000 -0.000000"));
		m_KeyCard_Main_System_ConfigData.GetLocationsPArray().Insert(new KCM_Purple_Crate_Locations("4685.790527 339.372229 9884.399414", "0.000000 -0.000000 -0.000000"));
		m_KeyCard_Main_System_ConfigData.GetLocationsPArray().Insert(new KCM_Purple_Crate_Locations("4683.372070 339.372229 9884.746094", "0.000000 -0.000000 -0.000000"));
		
		m_KeyCard_Main_System_ConfigData.GetLocationsRArray().Insert(new KCM_Red_Crate_Locations("4691.393066 339.372198 9877.183594", "0.000000 -0.000000 -0.000000"));
		m_KeyCard_Main_System_ConfigData.GetLocationsRArray().Insert(new KCM_Red_Crate_Locations("4691.466797 339.372198 9879.052734", "0.000000 -0.000000 -0.000000"));
		m_KeyCard_Main_System_ConfigData.GetLocationsRArray().Insert(new KCM_Red_Crate_Locations("4691.968750 339.372198 9875.055664", "0.000000 -0.000000 -0.000000"));
		m_KeyCard_Main_System_ConfigData.GetLocationsRArray().Insert(new KCM_Red_Crate_Locations("4688.981934 339.372229 9874.983398", "0.000000 -0.000000 -0.000000"));
		m_KeyCard_Main_System_ConfigData.GetLocationsRArray().Insert(new KCM_Red_Crate_Locations("4688.340820 339.372168 9877.572266", "0.000000 -0.000000 -0.000000"));
		
		m_KeyCard_Main_System_ConfigData.GetVaultLocationsYArray().Insert(new KCM_Yellow_Vault_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_Main_System_ConfigData.GetVaultLocationsYArray().Insert(new KCM_Yellow_Vault_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_Main_System_ConfigData.GetVaultLocationsYArray().Insert(new KCM_Yellow_Vault_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_Main_System_ConfigData.GetVaultLocationsYArray().Insert(new KCM_Yellow_Vault_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_Main_System_ConfigData.GetVaultLocationsYArray().Insert(new KCM_Yellow_Vault_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		
		m_KeyCard_Main_System_ConfigData.GetVaultLocationsGArray().Insert(new KCM_Green_Vault_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_Main_System_ConfigData.GetVaultLocationsGArray().Insert(new KCM_Green_Vault_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_Main_System_ConfigData.GetVaultLocationsGArray().Insert(new KCM_Green_Vault_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_Main_System_ConfigData.GetVaultLocationsGArray().Insert(new KCM_Green_Vault_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_Main_System_ConfigData.GetVaultLocationsGArray().Insert(new KCM_Green_Vault_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		
		m_KeyCard_Main_System_ConfigData.GetVaultLocationsBArray().Insert(new KCM_Blue_Vault_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_Main_System_ConfigData.GetVaultLocationsBArray().Insert(new KCM_Blue_Vault_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_Main_System_ConfigData.GetVaultLocationsBArray().Insert(new KCM_Blue_Vault_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_Main_System_ConfigData.GetVaultLocationsBArray().Insert(new KCM_Blue_Vault_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_Main_System_ConfigData.GetVaultLocationsBArray().Insert(new KCM_Blue_Vault_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		
		m_KeyCard_Main_System_ConfigData.GetVaultLocationsPArray().Insert(new KCM_Purple_Vault_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_Main_System_ConfigData.GetVaultLocationsPArray().Insert(new KCM_Purple_Vault_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_Main_System_ConfigData.GetVaultLocationsPArray().Insert(new KCM_Purple_Vault_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_Main_System_ConfigData.GetVaultLocationsPArray().Insert(new KCM_Purple_Vault_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_Main_System_ConfigData.GetVaultLocationsPArray().Insert(new KCM_Purple_Vault_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		
		m_KeyCard_Main_System_ConfigData.GetVaultLocationsRArray().Insert(new KCM_Red_Vault_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_Main_System_ConfigData.GetVaultLocationsRArray().Insert(new KCM_Red_Vault_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_Main_System_ConfigData.GetVaultLocationsRArray().Insert(new KCM_Red_Vault_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_Main_System_ConfigData.GetVaultLocationsRArray().Insert(new KCM_Red_Vault_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		m_KeyCard_Main_System_ConfigData.GetVaultLocationsRArray().Insert(new KCM_Red_Vault_Locations("0.0 0.0 0.0", "0.0 0.0 0.0"));
		
		JsonFileLoader<KeyCard_ConfigData_Main_System>.JsonSaveFile(kcm_MainSystemConfigPath, m_KeyCard_Main_System_ConfigData);
	}
}