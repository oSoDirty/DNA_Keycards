class KeyCard_Config_Green
{	
	protected static ref KeyCard_ConfigData_Green m_KeyCard_Green_ConfigData;
	
	void KeyCard_Config_Green()
	{
		LoadConfig();
	}
	
	KeyCard_ConfigData_Green GetConfigData()
	{
		if(!m_KeyCard_Green_ConfigData)
		{
			LoadConfig();
		}
		return m_KeyCard_Green_ConfigData;
	}
	
	protected static void LoadConfig()
	{
		if (!FileExist(kcm_ProfilePath + m_ConfigFolderName + "/Green/"))
        {
			Print("[KCM_Debug] - KeyCardMod Green Tier: Directory not found, creating directory!");
			MakeDirectory(kcm_ProfilePath + m_ConfigFolderName + "/Green/");
		}
		
		m_KeyCard_Green_ConfigData = new KeyCard_ConfigData_Green();
		
		if (!FileExist(kcm_ProfilePath + m_ConfigFolderName + "/Green/" + m_ConfigName + "Green" + m_ConfigExtension))
        {
			Print("[KCM_Debug] - KeyCardMod Green Tier: Config not found, creating default config!");
            CreateDefaultConfig();
        }
		else
		{
			JsonFileLoader<KeyCard_ConfigData_Green>.JsonLoadFile(kcm_ProfilePath + m_ConfigFolderName + "/Green/" + m_ConfigName + "Green" + m_ConfigExtension, m_KeyCard_Green_ConfigData);
		}
	}
	
	static void CreateDefaultConfig()
	{
		m_KeyCard_Green_ConfigData.GetWeaponsArray().Insert(new KCM_Weapons_Green("Izh18", "", "", "", "", "", "", "AmmoBox_762x39_20Rnd", ""));
		m_KeyCard_Green_ConfigData.GetWeaponsArray().Insert(new KCM_Weapons_Green("Mosin9130_Camo", "PUScopeOptic", "Mosin_Compensator", "", "", "", "", "AmmoBox_762x54_20Rnd", ""));
		m_KeyCard_Green_ConfigData.GetWeaponsArray().Insert(new KCM_Weapons_Green("SKS_Black", "PUScopeOptic", "SKS_Bayonet", "", "", "", "", "AmmoBox_762x39_20Rnd", ""));
		
		m_KeyCard_Green_ConfigData.GetWeaponVarsArray().Insert(new Weapon_Variables_Green("(0) Min Weapons to give for Green Tier (Don't set below 1! - Can turn off in system config)", 1));
		m_KeyCard_Green_ConfigData.GetWeaponVarsArray().Insert(new Weapon_Variables_Green("(1) Max Weapons to give for Green Tier (Don't set lower than min!)", 2));
		m_KeyCard_Green_ConfigData.GetWeaponVarsArray().Insert(new Weapon_Variables_Green("(2) Min Extra Mags to give for Green Tier Main Weapon (Don't set below 1! - Can turn off in system config)", 2));
		m_KeyCard_Green_ConfigData.GetWeaponVarsArray().Insert(new Weapon_Variables_Green("(3) Max Extra Mags to give for Green Tier Main Weapon (Don't set lower than min!)", 4));
		m_KeyCard_Green_ConfigData.GetWeaponVarsArray().Insert(new Weapon_Variables_Green("(4) Min Extra Ammo to give for Green Tier Main Weapon (Don't set below 1! - Can turn off in system config)", 1));
		m_KeyCard_Green_ConfigData.GetWeaponVarsArray().Insert(new Weapon_Variables_Green("(5) Max Extra Ammo to give for Green Tier Main Weapon (Don't set lower than min!)", 2));
		
		m_KeyCard_Green_ConfigData.GetClothingArray().Insert(new KCM_Clothing_G("MotoHelmet_Black", "RidersJacket_Black", "LeatherStorageVest_Black", "CargoPants_Black", "HikingBoots_Black", "HuntingBag", "WorkingGloves_Black"));
		m_KeyCard_Green_ConfigData.GetClothingArray().Insert(new KCM_Clothing_G("SkateHelmet_Green", "HikingJacket_Green", "HuntingVest", "CargoPants_Green", "WorkingBoots_Green", "HuntingBag", "WorkingGloves_Black"));
		
		JsonFileLoader<KeyCard_ConfigData_Green>.JsonSaveFile(kcm_ProfilePath + m_ConfigFolderName + "/Green/" + m_ConfigName + "Green" + m_ConfigExtension, m_KeyCard_Green_ConfigData);
	}
}