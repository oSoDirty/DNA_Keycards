class KeyCard_Config_Crate_System
{	
	protected static ref KeyCard_ConfigData_Crate_System m_KeyCard_Crate_System_ConfigData;
	protected static bool kcm_UpdateCheckComplete;
	protected static bool kcm_RecentlyUpdated = false;
	
	void KeyCard_Config_Crate_System()
	{
		LoadConfig();
	}
	
	KeyCard_ConfigData_Crate_System GetConfigData()
	{
		if(!m_KeyCard_Crate_System_ConfigData)
		{
			LoadConfig();
		}
		return m_KeyCard_Crate_System_ConfigData;
	}
	
	protected static void LoadConfig()
	{	
		if (!FileExist(kcm_ProfilePath + kcm_ConfigFolderName + "/System/Crate/"))
        {
			Print("[KCM Debug] - DNA_Keycards Crate System: Directory not found, creating directory!");
			MakeDirectory(kcm_ProfilePath + kcm_ConfigFolderName + "/System/Crate/");
		}
		
		m_KeyCard_Crate_System_ConfigData = new KeyCard_ConfigData_Crate_System();
		
		if (!FileExist(kcm_CrateSystemConfigPath))
        {
			if(!KeyCard_Config_Main_System.RecentlyUpdated()) Print("[KCM Debug] - DNA_Keycards Crate System Settings: Config not found, creating default config!");
            CreateDefaultConfig();
        }
		else
		{
			JsonFileLoader<KeyCard_ConfigData_Crate_System>.JsonLoadFile(kcm_CrateSystemConfigPath, m_KeyCard_Crate_System_ConfigData);
			if(kcm_UpdateCheckComplete) Print("[KCM Debug] - DNA_Keycards Crate System Settings: Config found, loading settings!");
		}
	}
	
	static void CreateDefaultConfig()
	{
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(0) Yellow Spawn Main Weapon (1 true, 0 false)",1));
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(1) Yellow Spawn Extra Main Weapon Mags(1 true, 0 false)",1));
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(2) Yellow Spawn Main Weapon Attachments(1 true, 0 false)",1));
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(3) Yellow Spawn Extra Main Weapon Ammo (1 true, 0 false)", 1));
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(4) Yellow Spawn Side Arm (1 true, 0 false)",1));
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(5) Yellow Spawn Extra Side Arm Mags (1 true, 0 false)",1));
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(6) Yellow Spawn Side Arm Attachments (1 true, 0 false)",1));
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(7) Yellow Spawn Extra Side Arm Ammo (1 true, 0 false)", 1));
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(8) Yellow Spawn Food (1 true, 0 false)",1));
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(9) Yellow Spawn Drinks (1 true, 0 false)",1));
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(10) Yellow Spawn Tools (1 true, 0 false)",1));
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(11) Yellow Spawn Buiding Materials (1 true, 0 false)",1));
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(12) Yellow Spawn Valuables ODDS % (0-100) 0 = OFF (Default)", 0));
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(13) Yellow Spawn Clothing (1 true, 0 false)",1));
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(14) Yellow Spawn Meds (1 true, 0 false)", 1));

		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(15) Green Spawn Main Weapon (1 true, 0 false)",1));
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(16) Green Spawn Extra Main Weapon Mags(1 true, 0 false)",1));
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(17) Green Spawn Main Weapon Attachments(1 true, 0 false)",1));
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(18) Green Spawn Extra Main Weapon Ammo (1 true, 0 false)", 1));
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(19) Green Spawn Side Arm (1 true, 0 false)",1));
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(20) Green Spawn Extra Side Arm Mags (1 true, 0 false)",1));
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(21) Green Spawn Side Arm Attachments (1 true, 0 false)",1));
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(22) Green Spawn Extra Side Arm Ammo (1 true, 0 false)", 1));
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(23) Green Spawn Food (1 true, 0 false)",1));
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(24) Green Spawn Drinks (1 true, 0 false)",1));
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(25) Green Spawn Tools (1 true, 0 false)",1));
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(26) Green Spawn Buiding Materials (1 true, 0 false)",1));
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(27) Green Spawn Valuables ODDS % (0-100) 0 = OFF (Default)", 0));
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(28) Green Spawn Clothing (1 true, 0 false)",1));
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(29) Green Spawn Meds (1 true, 0 false)", 1));

		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(30) Blue Spawn Main Weapon (1 true, 0 false)",1));
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(31) Blue Spawn Extra Main Weapon Mags(1 true, 0 false)",1));
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(32) Blue Spawn Main Weapon Attachments(1 true, 0 false)",1));
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(33) Blue Spawn Extra Main Weapon Ammo (1 true, 0 false)", 1));
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(34) Blue Spawn Side Arm (1 true, 0 false)",1));
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(35) Blue Spawn Extra Side Arm Mags (1 true, 0 false)",1));
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(36) Blue Spawn Side Arm Attachments (1 true, 0 false)",1));
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(37) Blue Spawn Extra Side Arm Ammo (1 true, 0 false)", 1));
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(38) Blue Spawn Food (1 true, 0 false)",1));
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(39) Blue Spawn Drinks (1 true, 0 false)",1));
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(40) Blue Spawn Tools (1 true, 0 false)",1));
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(41) Blue Spawn Buiding Materials (1 true, 0 false)",1));
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(42) Blue Spawn Valuables ODDS % (0-100) 0 = OFF (Default)", 0));
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(43) Blue Spawn Clothing (1 true, 0 false)",1));
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(44) Blue Spawn Meds (1 true, 0 false)", 1));
		
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(45) Purple Spawn Main Weapon (1 true, 0 false)",1));
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(46) Purple Spawn Extra Main Weapon Mags(1 true, 0 false)",1));
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(47) Purple Spawn Main Weapon Attachments(1 true, 0 false)",1));
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(48) Purple Spawn Extra Main Weapon Ammo (1 true, 0 false)", 1));
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(49) Purple Spawn Side Arm (1 true, 0 false)",1));
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(50) Purple Spawn Extra Side Arm Mags (1 true, 0 false)",1));
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(51) Purple Spawn Side Arm Attachments (1 true, 0 false)",1));
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(52) Purple Spawn Extra Side Arm Ammo (1 true, 0 false)", 1));
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(53) Purple Spawn Food (1 true, 0 false)",1));
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(54) Purple Spawn Drinks (1 true, 0 false)",1));
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(55) Purple Spawn Tools (1 true, 0 false)",1));
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(56) Purple Spawn Buiding Materials (1 true, 0 false)",1));
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(57) Purple Spawn Valuables ODDS % (0-100) 0 = OFF (Default)", 0));
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(58) Purple Spawn Clothing (1 true, 0 false)",1));
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(59) Purple Spawn Meds (1 true, 0 false)", 1));
		
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(60) Red Spawn Main Weapon (1 true, 0 false)",1));
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(61) Red Spawn Extra Main Weapon Mags(1 true, 0 false)",1));
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(62) Red Spawn Main Weapon Attachments(1 true, 0 false)",1));
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(63) Red Spawn Extra Main Weapon Ammo (1 true, 0 false)", 1));
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(64) Red Spawn Side Arm (1 true, 0 false)",1));
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(65) Red Spawn Extra Side Arm Mags (1 true, 0 false)",1));
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(66) Red Spawn Side Arm Attachments (1 true, 0 false)",1));
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(67) Red Spawn Extra Side Arm Ammo (1 true, 0 false)", 1));
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(68) Red Spawn Food (1 true, 0 false)",1));
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(69) Red Spawn Drinks (1 true, 0 false)",1));
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(70) Red Spawn Tools (1 true, 0 false)",1));
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(71) Red Spawn Buiding Materials (1 true, 0 false)",1));
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(72) Red Spawn Valuables ODDS % (0-100) 0 = OFF (Default)", 0));
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(73) Red Spawn Clothing (1 true, 0 false)",1));
		m_KeyCard_Crate_System_ConfigData.GetSystemArray().Insert(new KCM_Config_Crate_System("(74) Red Spawn Meds (1 true, 0 false)", 1));
				
		JsonFileLoader<KeyCard_ConfigData_Crate_System>.JsonSaveFile(kcm_CrateSystemConfigPath, m_KeyCard_Crate_System_ConfigData);
	}
}