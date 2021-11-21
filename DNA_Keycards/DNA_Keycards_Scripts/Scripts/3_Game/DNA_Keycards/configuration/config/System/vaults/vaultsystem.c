class KeyCard_Config_Vault_System
{	
	protected static ref KeyCard_ConfigData_Vault_System m_KeyCard_Vault_System_ConfigData;
	protected static bool kcm_UpdateCheckComplete;
	protected static bool kcm_RecentlyUpdated = false;
	
	void KeyCard_Config_Vault_System()
	{
		LoadConfig();
	}
	
	KeyCard_ConfigData_Vault_System GetConfigData()
	{
		if(!m_KeyCard_Vault_System_ConfigData)
		{
			LoadConfig();
		}
		return m_KeyCard_Vault_System_ConfigData;
	}
	
	protected static void LoadConfig()
	{	
		if (!FileExist(kcm_ProfilePath + kcm_ConfigFolderName + "/System/Vault/"))
        {
			Print("[KCM Debug] - DNA_Keycards Vault System: Directory not found, creating directory!");
			MakeDirectory(kcm_ProfilePath + kcm_ConfigFolderName + "/System/Vault/");
		}
		
		m_KeyCard_Vault_System_ConfigData = new KeyCard_ConfigData_Vault_System();
		
		if (!FileExist(kcm_VaultSystemConfigPath))
        {
			if(!KeyCard_Config_Main_System.RecentlyUpdated()) Print("[KCM Debug] - DNA_Keycards Vault System Settings: Config not found, creating default config!");
            CreateDefaultConfig();
        }
		else
		{
			JsonFileLoader<KeyCard_ConfigData_Vault_System>.JsonLoadFile(kcm_VaultSystemConfigPath, m_KeyCard_Vault_System_ConfigData);
			if(kcm_UpdateCheckComplete) Print("[KCM Debug] - DNA_Keycards Vault System Settings: Config found, loading settings!");
		}
	}
	
	static void CreateDefaultConfig()
	{
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(0) Yellow Spawn Main Weapon (1 true, 0 false)",1));
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(1) Yellow Spawn Extra Main Weapon Mags(1 true, 0 false)",1));
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(2) Yellow Spawn Main Weapon Attachments(1 true, 0 false)",1));
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(3) Yellow Spawn Extra Main Weapon Ammo (1 true, 0 false)", 1));
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(4) Yellow Spawn Side Arm (1 true, 0 false)",1));
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(5) Yellow Spawn Extra Side Arm Mags (1 true, 0 false)",1));
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(6) Yellow Spawn Side Arm Attachments (1 true, 0 false)",1));
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(7) Yellow Spawn Extra Side Arm Ammo (1 true, 0 false)", 1));
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(8) Yellow Spawn Food (1 true, 0 false)",1));
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(9) Yellow Spawn Drinks (1 true, 0 false)",1));
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(10) Yellow Spawn Tools (1 true, 0 false)",1));
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(11) Yellow Spawn Buiding Materials (1 true, 0 false)",1));
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(12) Yellow Spawn Valuables ODDS % (0-100) 0 = OFF (Default)", 0));
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(13) Yellow Spawn Clothing (1 true, 0 false)",1));
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(14) Yellow Spawn Meds (1 true, 0 false)", 1));

		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(15) Green Spawn Main Weapon (1 true, 0 false)",1));
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(16) Green Spawn Extra Main Weapon Mags(1 true, 0 false)",1));
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(17) Green Spawn Main Weapon Attachments(1 true, 0 false)",1));
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(18) Green Spawn Extra Main Weapon Ammo (1 true, 0 false)", 1));
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(19) Green Spawn Side Arm (1 true, 0 false)",1));
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(20) Green Spawn Extra Side Arm Mags (1 true, 0 false)",1));
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(21) Green Spawn Side Arm Attachments (1 true, 0 false)",1));
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(22) Green Spawn Extra Side Arm Ammo (1 true, 0 false)", 1));
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(23) Green Spawn Food (1 true, 0 false)",1));
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(24) Green Spawn Drinks (1 true, 0 false)",1));
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(25) Green Spawn Tools (1 true, 0 false)",1));
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(26) Green Spawn Buiding Materials (1 true, 0 false)",1));
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(27) Green Spawn Valuables ODDS % (0-100) 0 = OFF (Default)", 0));
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(28) Green Spawn Clothing (1 true, 0 false)",1));
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(29) Green Spawn Meds (1 true, 0 false)", 1));

		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(30) Blue Spawn Main Weapon (1 true, 0 false)",1));
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(31) Blue Spawn Extra Main Weapon Mags(1 true, 0 false)",1));
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(32) Blue Spawn Main Weapon Attachments(1 true, 0 false)",1));
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(33) Blue Spawn Extra Main Weapon Ammo (1 true, 0 false)", 1));
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(34) Blue Spawn Side Arm (1 true, 0 false)",1));
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(35) Blue Spawn Extra Side Arm Mags (1 true, 0 false)",1));
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(36) Blue Spawn Side Arm Attachments (1 true, 0 false)",1));
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(37) Blue Spawn Extra Side Arm Ammo (1 true, 0 false)", 1));
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(38) Blue Spawn Food (1 true, 0 false)",1));
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(39) Blue Spawn Drinks (1 true, 0 false)",1));
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(40) Blue Spawn Tools (1 true, 0 false)",1));
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(41) Blue Spawn Buiding Materials (1 true, 0 false)",1));
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(42) Blue Spawn Valuables ODDS % (0-100) 0 = OFF (Default)", 0));
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(43) Blue Spawn Clothing (1 true, 0 false)",1));
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(44) Blue Spawn Meds (1 true, 0 false)", 1));
		
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(45) Purple Spawn Main Weapon (1 true, 0 false)",1));
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(46) Purple Spawn Extra Main Weapon Mags(1 true, 0 false)",1));
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(47) Purple Spawn Main Weapon Attachments(1 true, 0 false)",1));
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(48) Purple Spawn Extra Main Weapon Ammo (1 true, 0 false)", 1));
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(49) Purple Spawn Side Arm (1 true, 0 false)",1));
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(50) Purple Spawn Extra Side Arm Mags (1 true, 0 false)",1));
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(51) Purple Spawn Side Arm Attachments (1 true, 0 false)",1));
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(52) Purple Spawn Extra Side Arm Ammo (1 true, 0 false)", 1));
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(53) Purple Spawn Food (1 true, 0 false)",1));
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(54) Purple Spawn Drinks (1 true, 0 false)",1));
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(55) Purple Spawn Tools (1 true, 0 false)",1));
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(56) Purple Spawn Buiding Materials (1 true, 0 false)",1));
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(57) Purple Spawn Valuables ODDS % (0-100) 0 = OFF (Default)", 0));
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(58) Purple Spawn Clothing (1 true, 0 false)",1));
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(59) Purple Spawn Meds (1 true, 0 false)", 1));
		
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(60) Red Spawn Main Weapon (1 true, 0 false)",1));
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(61) Red Spawn Extra Main Weapon Mags(1 true, 0 false)",1));
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(62) Red Spawn Main Weapon Attachments(1 true, 0 false)",1));
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(63) Red Spawn Extra Main Weapon Ammo (1 true, 0 false)", 1));
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(64) Red Spawn Side Arm (1 true, 0 false)",1));
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(65) Red Spawn Extra Side Arm Mags (1 true, 0 false)",1));
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(66) Red Spawn Side Arm Attachments (1 true, 0 false)",1));
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(67) Red Spawn Extra Side Arm Ammo (1 true, 0 false)", 1));
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(68) Red Spawn Food (1 true, 0 false)",1));
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(69) Red Spawn Drinks (1 true, 0 false)",1));
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(70) Red Spawn Tools (1 true, 0 false)",1));
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(71) Red Spawn Buiding Materials (1 true, 0 false)",1));
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(72) Red Spawn Valuables ODDS % (0-100) 0 = OFF (Default)", 0));
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(73) Red Spawn Clothing (1 true, 0 false)",1));
		m_KeyCard_Vault_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Vault_System("(74) Red Spawn Meds (1 true, 0 false)", 1));
		
		JsonFileLoader<KeyCard_ConfigData_Vault_System>.JsonSaveFile(kcm_VaultSystemConfigPath, m_KeyCard_Vault_System_ConfigData);
	}
}