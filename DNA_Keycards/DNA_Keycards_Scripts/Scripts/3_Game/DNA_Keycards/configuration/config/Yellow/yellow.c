class KeyCard_Config_Yellow
{	
	protected static ref KeyCard_ConfigData_Yellow m_KeyCard_Yellow_ConfigData;
	
	void KeyCard_Config_Yellow()
	{
		LoadConfig();
	}
	
	KeyCard_ConfigData_Yellow GetConfigData()
	{
		if(!m_KeyCard_Yellow_ConfigData)
		{
			LoadConfig();
		}
		return m_KeyCard_Yellow_ConfigData;
	}
	
	protected static void LoadConfig()
	{
		if (!FileExist(kcm_ProfilePath + kcm_ConfigFolderName + "/Yellow/"))
        {
			Print("[KCM_Debug] - DNA_Keycards Yellow Tier: Directory not found, creating directory!");
			MakeDirectory(kcm_ProfilePath + kcm_ConfigFolderName + "/Yellow/");
		}
		
		m_KeyCard_Yellow_ConfigData = new KeyCard_ConfigData_Yellow();
		
		if (!FileExist(kcm_YellowConfigPath))
        {
			if(!KeyCard_Config_Main_System.RecentlyUpdated()) Print("[KCM_Debug] - DNA_Keycards Yellow Tier: Config not found, creating default config!");
            CreateDefaultConfig();
        }
		else
		{
			JsonFileLoader<KeyCard_ConfigData_Yellow>.JsonLoadFile(kcm_YellowConfigPath, m_KeyCard_Yellow_ConfigData);
			Print("[KCM Debug] - DNA_Keycards Yellow Tier: Config found, loading settings!");
		}
	}
	
	static void CreateDefaultConfig()
	{
		m_KeyCard_Yellow_ConfigData.GetWeaponsArray().Insert(new KCM_Weapons_Yellow("Mp133Shotgun", "", "", "", "", "", "", "AmmoBox_00buck_10rnd", ""));
		m_KeyCard_Yellow_ConfigData.GetWeaponsArray().Insert(new KCM_Weapons_Yellow("Izh43Shotgun", "", "", "", "", "", "", "AmmoBox_00buck_10rnd", ""));
		m_KeyCard_Yellow_ConfigData.GetWeaponsArray().Insert(new KCM_Weapons_Yellow("SawedoffIzh43Shotgun", "", "", "", "", "", "", "AmmoBox_00buck_10rnd", ""));
		
		m_KeyCard_Yellow_ConfigData.GetClothingArray().Insert(new KCM_Clothing_Y("BaseballCap_Blue", "Shirt_BlueCheck", "PressVest_Blue", "Jeans_Blue", "AthleticShoes_Blue", "ImprovisedBag", "SurgicalGloves_LightBlue"));
		m_KeyCard_Yellow_ConfigData.GetClothingArray().Insert(new KCM_Clothing_Y("BaseballCap_Red", "TShirt_Red", "PoliceVest", "Jeans_Black", "JoggingShoes_Red", "CourierBag", "LeatherGloves_Brown"));
		
		m_KeyCard_Yellow_ConfigData.GetWeaponVarsArray().Insert(new Weapon_Variables_Yellow("(0) Min Weapons to give for Yellow Tier (Don't set below 1! - Can turn off in system config)", 1));
		m_KeyCard_Yellow_ConfigData.GetWeaponVarsArray().Insert(new Weapon_Variables_Yellow("(1) Max Weapons to give for Yellow Tier (Don't set lower than min!)", 2));
		m_KeyCard_Yellow_ConfigData.GetWeaponVarsArray().Insert(new Weapon_Variables_Yellow("(2) Min Extra Mags to give for Yellow Tier Main Weapon (Don't set below 1! - Can turn off in system config)", 2));
		m_KeyCard_Yellow_ConfigData.GetWeaponVarsArray().Insert(new Weapon_Variables_Yellow("(3) Max Extra Mags to give for Yellow Tier Main Weapon (Don't set lower than min!)", 4));
		m_KeyCard_Yellow_ConfigData.GetWeaponVarsArray().Insert(new Weapon_Variables_Yellow("(4) Min Extra Ammo to give for Yellow Tier Main Weapon (Don't set below 1! - Can turn off in system config)", 1));
		m_KeyCard_Yellow_ConfigData.GetWeaponVarsArray().Insert(new Weapon_Variables_Yellow("(5) Max Extra Ammo to give for Yellow Tier Main Weapon (Don't set lower than min!)", 2));
		
		m_KeyCard_Yellow_ConfigData.GetWeaponVarsArray().Insert(new Weapon_Variables_Yellow("(6) Min Weapons to give for Yellow Tier Vault (Can turn off in system config)", 1));
		m_KeyCard_Yellow_ConfigData.GetWeaponVarsArray().Insert(new Weapon_Variables_Yellow("(7) Max Weapons to give for Yellow Tier Vault Vault (Don't set lower than min!)", 3));
		m_KeyCard_Yellow_ConfigData.GetWeaponVarsArray().Insert(new Weapon_Variables_Yellow("(8) Min Extra Mags to give for Yellow Tier Vault Main Weapon (Can turn off in system config)", 2));
		m_KeyCard_Yellow_ConfigData.GetWeaponVarsArray().Insert(new Weapon_Variables_Yellow("(9) Max Extra Mags to give for Yellow Tier Vault Main Weapon (Don't set lower than min!)", 4));
		m_KeyCard_Yellow_ConfigData.GetWeaponVarsArray().Insert(new Weapon_Variables_Yellow("(10) Min Extra Ammo to give for Yellow Tier Vault Main Weapon (Can turn off in system config)", 1));
		m_KeyCard_Yellow_ConfigData.GetWeaponVarsArray().Insert(new Weapon_Variables_Yellow("(11) Max Extra Ammo to give for Yellow Tier Vault Main Weapon (Don't set lower than min!)", 2));
		
		JsonFileLoader<KeyCard_ConfigData_Yellow>.JsonSaveFile(kcm_YellowConfigPath, m_KeyCard_Yellow_ConfigData);
	}
}