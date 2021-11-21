class KeyCard_Config_Blue
{	
	protected static ref KeyCard_ConfigData_Blue m_KeyCard_Blue_ConfigData;
	
	void KeyCard_Config_Blue()
	{
		LoadConfig();
	}
	
	KeyCard_ConfigData_Blue GetConfigData()
	{
		if(!m_KeyCard_Blue_ConfigData)
		{
			LoadConfig();
		}
		return m_KeyCard_Blue_ConfigData;
	}
	
	protected static void LoadConfig()
	{
		if (!FileExist(kcm_ProfilePath + kcm_ConfigFolderName + "/Blue"))
        {
			Print("[KCM_Debug] - DNA_Keycards Blue Tier: Config directory not found, creating directory!");
			MakeDirectory(kcm_ProfilePath + kcm_ConfigFolderName + "/Blue");
		}
		
		m_KeyCard_Blue_ConfigData = new KeyCard_ConfigData_Blue();
		
		if (!FileExist(kcm_BlueConfigPath))
        {
			if(!KeyCard_Config_Main_System.RecentlyUpdated()) Print("[KCM_Debug] - DNA_Keycards Blue Tier: Config not found, creating default config!");
            CreateDefaultConfig();
        }
		else
		{
			JsonFileLoader<KeyCard_ConfigData_Blue>.JsonLoadFile(kcm_BlueConfigPath, m_KeyCard_Blue_ConfigData);
			Print("[KCM Debug] - DNA_Keycards Blue Tier: Config found, loading settings!");
		}
	}
	
	static void CreateDefaultConfig()
	{
		m_KeyCard_Blue_ConfigData.GetWeaponsArray().Insert(new KCM_Weapons_Blue("MP5K", "ReflexOptic", "PistolSuppressor", "MP5k_StockBttstck", "MP5_RailHndgrd", "UniversalFlashlight", "Mag_MP5_30Rnd", "AmmoBox_9x19_25rnd", "Battery9V"));
		m_KeyCard_Blue_ConfigData.GetWeaponsArray().Insert(new KCM_Weapons_Blue("AKS74U_Black", "", "AK_Suppressor", "AKS74U_Bttstck_Black", "", "", "Mag_AK74_30Rnd_Black", "AmmoBox_545x39_20Rnd", ""));
		
		m_KeyCard_Blue_ConfigData.GetClothingArray().Insert(new KCM_Clothing_B("GorkaHelmet_Green", "M65Jacket_Olive", "UKAssVest_Olive", "USMCPants_Woodland", "CombatBoots_Green", "AssaultBag_Ttsko", "TacticalGloves_Green"));
		m_KeyCard_Blue_ConfigData.GetClothingArray().Insert(new KCM_Clothing_B("GorkaHelmet_Black", "M65Jacket_Black", "UKAssVest_Black", "USMCPants_Woodland", "CombatBoots_Black", "AssaultBag_Black", "TacticalGloves_Black"));
		
		m_KeyCard_Blue_ConfigData.GetWeaponVarsArray().Insert(new Weapon_Variables_Blue("(0) Min Weapons to give for Blue Tier Crate (Can turn off in system config)", 1));
		m_KeyCard_Blue_ConfigData.GetWeaponVarsArray().Insert(new Weapon_Variables_Blue("(1) Max Weapons to give for Blue Tier Crate (Don't set lower than min!)", 3));
		m_KeyCard_Blue_ConfigData.GetWeaponVarsArray().Insert(new Weapon_Variables_Blue("(2) Min Extra Mags to give for Blue Tier Crate Main Weapon (Can turn off in system config)", 2));
		m_KeyCard_Blue_ConfigData.GetWeaponVarsArray().Insert(new Weapon_Variables_Blue("(3) Max Extra Mags to give for Blue Tier Crate Main Weapon (Don't set lower than min!)", 4));
		m_KeyCard_Blue_ConfigData.GetWeaponVarsArray().Insert(new Weapon_Variables_Blue("(4) Min Extra Ammo to give for Blue Tier Crate Main Weapon (Can turn off in system config)", 1));
		m_KeyCard_Blue_ConfigData.GetWeaponVarsArray().Insert(new Weapon_Variables_Blue("(5) Max Extra Ammo to give for Blue Tier Crate Main Weapon (Don't set lower than min!)", 2));
		
		m_KeyCard_Blue_ConfigData.GetWeaponVarsArray().Insert(new Weapon_Variables_Blue("(6) Min Weapons to give for Blue Tier Vault (Can turn off in system config)", 1));
		m_KeyCard_Blue_ConfigData.GetWeaponVarsArray().Insert(new Weapon_Variables_Blue("(7) Max Weapons to give for Blue Tier Vault Vault (Don't set lower than min!)", 3));
		m_KeyCard_Blue_ConfigData.GetWeaponVarsArray().Insert(new Weapon_Variables_Blue("(8) Min Extra Mags to give for Blue Tier Vault Main Weapon (Can turn off in system config)", 2));
		m_KeyCard_Blue_ConfigData.GetWeaponVarsArray().Insert(new Weapon_Variables_Blue("(9) Max Extra Mags to give for Blue Tier Vault Main Weapon (Don't set lower than min!)", 4));
		m_KeyCard_Blue_ConfigData.GetWeaponVarsArray().Insert(new Weapon_Variables_Blue("(10) Min Extra Ammo to give for Blue Tier Vault Main Weapon (Can turn off in system config)", 1));
		m_KeyCard_Blue_ConfigData.GetWeaponVarsArray().Insert(new Weapon_Variables_Blue("(11) Max Extra Ammo to give for Blue Tier Vault Main Weapon (Don't set lower than min!)", 2));
		
		JsonFileLoader<KeyCard_ConfigData_Blue>.JsonSaveFile(kcm_BlueConfigPath, m_KeyCard_Blue_ConfigData);
	}
}