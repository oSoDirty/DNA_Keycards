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
		if (!FileExist(kcm_ProfilePath + kcm_ConfigFolderName + "/Green/"))
        {
			Print("[KCM_Debug] - DNA_Keycards Green Tier: Directory not found, creating directory!");
			MakeDirectory(kcm_ProfilePath + kcm_ConfigFolderName + "/Green/");
		}
		
		m_KeyCard_Green_ConfigData = new KeyCard_ConfigData_Green();
		
		if (!FileExist(kcm_GreenConfigPath))
        {
			if(!KeyCard_Config_Main_System.RecentlyUpdated()) Print("[KCM_Debug] - DNA_Keycards Green Tier: Config not found, creating default config!");
            CreateDefaultConfig();
        }
		else
		{
			JsonFileLoader<KeyCard_ConfigData_Green>.JsonLoadFile(kcm_GreenConfigPath, m_KeyCard_Green_ConfigData);
			Print("[KCM Debug] - DNA_Keycards Green Tier: Config found, loading settings!");
		}
	}
	
	static void CreateDefaultConfig()
	{
		m_KeyCard_Green_ConfigData.GetWeaponsArray().Insert(new KCM_Weapons_Green("Izh18", "", "", "", "", "", "", "AmmoBox_762x39_20Rnd", ""));
		m_KeyCard_Green_ConfigData.GetWeaponsArray().Insert(new KCM_Weapons_Green("Mosin9130_Camo", "PUScopeOptic", "Mosin_Compensator", "", "", "", "", "AmmoBox_762x54_20Rnd", ""));
		m_KeyCard_Green_ConfigData.GetWeaponsArray().Insert(new KCM_Weapons_Green("SKS_Black", "PUScopeOptic", "SKS_Bayonet", "", "", "", "", "AmmoBox_762x39_20Rnd", ""));
		
		m_KeyCard_Green_ConfigData.GetClothingArray().Insert(new KCM_Clothing_G("MotoHelmet_Black", "RidersJacket_Black", "LeatherStorageVest_Black", "CargoPants_Black", "HikingBoots_Black", "HuntingBag", "WorkingGloves_Black"));
		m_KeyCard_Green_ConfigData.GetClothingArray().Insert(new KCM_Clothing_G("SkateHelmet_Green", "HikingJacket_Green", "HuntingVest", "CargoPants_Green", "WorkingBoots_Green", "HuntingBag", "WorkingGloves_Black"));
		
		m_KeyCard_Green_ConfigData.GetWeaponVarsArray().Insert(new Weapon_Variables_Green("(0) Min Weapons to give for Green Tier Crate (Can turn off in system config)", 1));
		m_KeyCard_Green_ConfigData.GetWeaponVarsArray().Insert(new Weapon_Variables_Green("(1) Max Weapons to give for Green Tier Crate (Don't set lower than min!)", 2));
		m_KeyCard_Green_ConfigData.GetWeaponVarsArray().Insert(new Weapon_Variables_Green("(2) Min Extra Mags to give for Green Tier Crate Main Weapon (Can turn off in system config)", 2));
		m_KeyCard_Green_ConfigData.GetWeaponVarsArray().Insert(new Weapon_Variables_Green("(3) Max Extra Mags to give for Green Tier Crate Main Weapon (Don't set lower than min!)", 4));
		m_KeyCard_Green_ConfigData.GetWeaponVarsArray().Insert(new Weapon_Variables_Green("(4) Min Extra Ammo to give for Green Tier Crate Main Weapon (Can turn off in system config)", 1));
		m_KeyCard_Green_ConfigData.GetWeaponVarsArray().Insert(new Weapon_Variables_Green("(5) Max Extra Ammo to give for Green Tier Crate Main Weapon (Don't set lower than min!)", 2));
		
		m_KeyCard_Green_ConfigData.GetWeaponVarsArray().Insert(new Weapon_Variables_Green("(6) Min Weapons to give for Green Tier Vault (Can turn off in system config)", 1));
		m_KeyCard_Green_ConfigData.GetWeaponVarsArray().Insert(new Weapon_Variables_Green("(7) Max Weapons to give for Green Tier Vault Vault (Don't set lower than min!)", 3));
		m_KeyCard_Green_ConfigData.GetWeaponVarsArray().Insert(new Weapon_Variables_Green("(8) Min Extra Mags to give for Green Tier Vault Main Weapon (Can turn off in system config)", 2));
		m_KeyCard_Green_ConfigData.GetWeaponVarsArray().Insert(new Weapon_Variables_Green("(9) Max Extra Mags to give for Green Tier Vault Main Weapon (Don't set lower than min!)", 4));
		m_KeyCard_Green_ConfigData.GetWeaponVarsArray().Insert(new Weapon_Variables_Green("(10) Min Extra Ammo to give for Green Tier Vault Main Weapon (Can turn off in system config)", 1));
		m_KeyCard_Green_ConfigData.GetWeaponVarsArray().Insert(new Weapon_Variables_Green("(11) Max Extra Ammo to give for Green Tier Vault Main Weapon (Don't set lower than min!)", 2));
		
		JsonFileLoader<KeyCard_ConfigData_Green>.JsonSaveFile(kcm_GreenConfigPath, m_KeyCard_Green_ConfigData);
	}
}