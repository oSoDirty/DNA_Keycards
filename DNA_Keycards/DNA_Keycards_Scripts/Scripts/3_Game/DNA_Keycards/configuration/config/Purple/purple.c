class KeyCard_Config_Purple
{	
	protected static ref KeyCard_ConfigData_Purple m_KeyCard_Purple_ConfigData;
	
	void KeyCard_Config_Purple()
	{
		LoadConfig();
	}
	
	KeyCard_ConfigData_Purple GetConfigData()
	{
		if(!m_KeyCard_Purple_ConfigData)
		{
			LoadConfig();
		}
		return m_KeyCard_Purple_ConfigData;
	}
	
	protected static void LoadConfig()
	{
		if (!FileExist(kcm_ProfilePath + kcm_ConfigFolderName + "/Purple/"))
        {
			Print("[KCM_Debug] - DNA_Keycards Purple Tier: Directory not found, creating directory!");
			MakeDirectory(kcm_ProfilePath + kcm_ConfigFolderName + "/Purple/");
		}
		
		m_KeyCard_Purple_ConfigData = new KeyCard_ConfigData_Purple();
		
		if (!FileExist(kcm_PurpleConfigPath))
        {
			if(!KeyCard_Config_Main_System.RecentlyUpdated()) Print("[KCM_Debug] - DNA_Keycards Purple Tier: Config not found, creating default config!");
            CreateDefaultConfig();
        }
		else
		{
			JsonFileLoader<KeyCard_ConfigData_Purple>.JsonLoadFile(kcm_PurpleConfigPath, m_KeyCard_Purple_ConfigData);
			Print("[KCM Debug] - DNA_Keycards Purple Tier: Config found, loading settings!");
		}
	}
	
	static void CreateDefaultConfig()
	{
		m_KeyCard_Purple_ConfigData.GetWeaponsArray().Insert(new KCM_Weapons_Purple("FAL", "ReflexOptic", "", "Fal_FoldingBttstck", "", "", "Mag_FAL_20Rnd", "AmmoBox_308WIN_20Rnd", "Battery9V"));
		m_KeyCard_Purple_ConfigData.GetWeaponsArray().Insert(new KCM_Weapons_Purple("M4A1_Black", "ACOGOptic", "M4_Suppressor", "M4_MPBttstck", "M4_RISHndgrd_Black", "UniversalFlashlight", "Mag_STANAG_30Rnd", "AmmoBox_556x45_20Rnd", ""));
		
		m_KeyCard_Purple_ConfigData.GetClothingArray().Insert(new KCM_Clothing_P("BallisticHelmet_Green", "TTsKOJacket_Camo", "UKAssVest_Camo", "TTSKO_Pants", "MilitaryBoots_Beige", "CoyoteBag_Green", "TacticalGloves_Green"));
		m_KeyCard_Purple_ConfigData.GetClothingArray().Insert(new KCM_Clothing_P("BallisticHelmet_Black", "M65Jacket_Black", "UKAssVest_Black", "TTSKO_Pants", "MilitaryBoots_Black", "CoyoteBag_Brown", "TacticalGloves_Beige"));
		
		m_KeyCard_Purple_ConfigData.GetWeaponVarsArray().Insert(new Weapon_Variables_Purple("(0) Min Weapons to give for Purple Tier (Don't set below 1! - Can turn off in system config)", 1));
		m_KeyCard_Purple_ConfigData.GetWeaponVarsArray().Insert(new Weapon_Variables_Purple("(1) Max Weapons to give for Purple Tier (Don't set lower than min!)", 3));
		m_KeyCard_Purple_ConfigData.GetWeaponVarsArray().Insert(new Weapon_Variables_Purple("(2) Min Extra Mags to give for Purple Tier Main Weapon (Don't set below 1! - Can turn off in system config)", 2));
		m_KeyCard_Purple_ConfigData.GetWeaponVarsArray().Insert(new Weapon_Variables_Purple("(3) Max Extra Mags to give for Purple Tier Main Weapon (Don't set lower than min!)", 4));
		m_KeyCard_Purple_ConfigData.GetWeaponVarsArray().Insert(new Weapon_Variables_Purple("(4) Min Extra Ammo to give for Purple Tier Main Weapon (Don't set below 1! - Can turn off in system config)", 1));
		m_KeyCard_Purple_ConfigData.GetWeaponVarsArray().Insert(new Weapon_Variables_Purple("(5) Max Extra Ammo to give for Purple Tier Main Weapon (Don't set lower than min!)", 2));
		
		m_KeyCard_Purple_ConfigData.GetWeaponVarsArray().Insert(new Weapon_Variables_Purple("(6) Min Weapons to give for Purple Tier Vault (Can turn off in system config)", 1));
		m_KeyCard_Purple_ConfigData.GetWeaponVarsArray().Insert(new Weapon_Variables_Purple("(7) Max Weapons to give for Purple Tier Vault Vault (Don't set lower than min!)", 3));
		m_KeyCard_Purple_ConfigData.GetWeaponVarsArray().Insert(new Weapon_Variables_Purple("(8) Min Extra Mags to give for Purple Tier Vault Main Weapon (Can turn off in system config)", 2));
		m_KeyCard_Purple_ConfigData.GetWeaponVarsArray().Insert(new Weapon_Variables_Purple("(9) Max Extra Mags to give for Purple Tier Vault Main Weapon (Don't set lower than min!)", 4));
		m_KeyCard_Purple_ConfigData.GetWeaponVarsArray().Insert(new Weapon_Variables_Purple("(10) Min Extra Ammo to give for Purple Tier Vault Main Weapon (Can turn off in system config)", 1));
		m_KeyCard_Purple_ConfigData.GetWeaponVarsArray().Insert(new Weapon_Variables_Purple("(11) Max Extra Ammo to give for Purple Tier Vault Main Weapon (Don't set lower than min!)", 2));
		
		JsonFileLoader<KeyCard_ConfigData_Purple>.JsonSaveFile(kcm_PurpleConfigPath, m_KeyCard_Purple_ConfigData);
	}
}