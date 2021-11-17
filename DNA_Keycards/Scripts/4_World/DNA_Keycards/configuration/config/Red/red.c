class KeyCard_Config_Red
{	
	protected static ref KeyCard_ConfigData_Red m_KeyCard_Red_ConfigData;
	
	void KeyCard_Config_Red()
	{
		LoadConfig();
	}
	
	KeyCard_ConfigData_Red GetConfigData()
	{
		if(!m_KeyCard_Red_ConfigData)
		{
			LoadConfig();
		}
		return m_KeyCard_Red_ConfigData;
	}
	
	protected static void LoadConfig()
	{		
		if (!FileExist(kcm_ProfilePath + kcm_ConfigFolderName + "/Red/"))
        {
			Print("[KCM_Debug] - DNA_Keycards Red Tier: Directory not found, creating directory!");
			MakeDirectory(kcm_ProfilePath + kcm_ConfigFolderName + "/Red/");
		}
		
		m_KeyCard_Red_ConfigData = new KeyCard_ConfigData_Red();
		
		if (!FileExist(kcm_RedConfigPath))
        {
			if(!KeyCard_Config_System.RecentlyUpdated()) Print("[KCM_Debug] - DNA_Keycards Red Tier: Config not found, creating default config!");
            CreateDefaultConfig();
        }
		else
		{
			JsonFileLoader<KeyCard_ConfigData_Red>.JsonLoadFile(kcm_RedConfigPath, m_KeyCard_Red_ConfigData);
			Print("[KCM Debug] - DNA_Keycards Red Tier: Config found, loading settings!");
		}
	}
	
	static void CreateDefaultConfig()
	{
		m_KeyCard_Red_ConfigData.GetWeaponsArray().Insert(new KCM_Weapons_Red("SVD", "PSO1Optic", "AK_Suppressor", "", "", "", "Mag_SVD_10Rnd", "AmmoBox_762x54_20Rnd", "Battery9V"));
		m_KeyCard_Red_ConfigData.GetWeaponsArray().Insert(new KCM_Weapons_Red("Winchester70", "HuntingOptic", "", "", "", "", "", "AmmoBox_308WIN_20Rnd", ""));
		
		m_KeyCard_Red_ConfigData.GetWeaponVarsArray().Insert(new Weapon_Variables_Red("(0) Min Weapons to give for Red Tier (Don't set below 1! - Can turn off in system config)", 1));
		m_KeyCard_Red_ConfigData.GetWeaponVarsArray().Insert(new Weapon_Variables_Red("(1) Max Weapons to give for Red Tier (Don't set lower than min!)", 3));
		m_KeyCard_Red_ConfigData.GetWeaponVarsArray().Insert(new Weapon_Variables_Red("(2) Min Extra Mags to give for Red Tier Main Weapon (Don't set below 1! - Can turn off in system config)", 2));
		m_KeyCard_Red_ConfigData.GetWeaponVarsArray().Insert(new Weapon_Variables_Red("(3) Max Extra Mags to give for Red Tier Main Weapon (Don't set lower than min!)", 4));
		m_KeyCard_Red_ConfigData.GetWeaponVarsArray().Insert(new Weapon_Variables_Red("(4) Min Extra Ammo to give for Red Tier Main Weapon (Don't set below 1! - Can turn off in system config)", 1));
		m_KeyCard_Red_ConfigData.GetWeaponVarsArray().Insert(new Weapon_Variables_Red("(5) Max Extra Ammo to give for Red Tier Main Weapon (Don't set lower than min!)", 2));
		
		m_KeyCard_Red_ConfigData.GetClothingArray().Insert(new KCM_Clothing_R("Mich2001Helmet", "GorkaEJacket_Autumn", "HighCapacityVest_Olive", "GorkaPants_Autumn", "JumgleBoots_Green", "AliceBag_Green", "TacticalGloves_Green"));
		m_KeyCard_Red_ConfigData.GetClothingArray().Insert(new KCM_Clothing_R("Mich2001Helmet", "M65Jacket_Black", "HighCapacityVest_Black", "GorkaPants_Autumn", "JumgleBoots_Black", "AliceBag_Black", "TacticalGloves_Black"));
		
		JsonFileLoader<KeyCard_ConfigData_Red>.JsonSaveFile(kcm_RedConfigPath, m_KeyCard_Red_ConfigData);
	}
}