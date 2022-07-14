class KeyCard_Config_Weapons
{
	protected static ref KeyCard_ConfigData_Weapons m_KeyCard_Weapons_ConfigData;
	
	void KeyCard_Config_Weapons()
	{
		if(GetGame().IsDedicatedServer())
			LoadConfig();
	}
	
	KeyCard_ConfigData_Weapons GetConfigData()
	{
		if(!m_KeyCard_Weapons_ConfigData)
		{
			LoadConfig();
		}
		return m_KeyCard_Weapons_ConfigData;
	}
	
	protected static void LoadConfig()
	{
		if(GetGame().IsDedicatedServer())
		{
			if (!FileExist(dna_ProfilePath + dna_ConfigFolderName + "/Loot/Weapons/"))
			{
				Print("[DNA DEBUG] - DNA Keycards Weapon Loot: Directory not found, creating directory!");
				MakeDirectory(dna_ProfilePath + dna_ConfigFolderName + "/Loot/Weapons/");
			}
			
			m_KeyCard_Weapons_ConfigData = new KeyCard_ConfigData_Weapons();
			
			if (!FileExist(dna_WeaponConfigPath))
			{
				if(!KeyCard_Config_Main_System.RecentlyUpdated()) Print("[DNA DEBUG] - DNA Keycards Weapon Loot: Config not found, creating default config!");
				CreateDefaultConfig();
			}
			else
			{
				JsonFileLoader<KeyCard_ConfigData_Weapons>.JsonLoadFile(dna_WeaponConfigPath, m_KeyCard_Weapons_ConfigData);
				if(KeyCard_Config_Main_System.HasBeenChecked()) Print("[DNA DEBUG] - DNA Keycards Weapon Loot: Config found, loading settings!");
			}
		}
	}
	
	static void CreateDefaultConfig()
	{
		m_KeyCard_Weapons_ConfigData.GetWeaponsArray().Insert(new DNA_Config_Weapons("yellow", "main", "Mp133Shotgun", "", "AmmoBox_00buck_10rnd", "", "", "", "", "", ""));
		m_KeyCard_Weapons_ConfigData.GetWeaponsArray().Insert(new DNA_Config_Weapons("yellow", "main", "Izh43Shotgun", "", "AmmoBox_00buck_10rnd", "", "", "", "", "", ""));
		m_KeyCard_Weapons_ConfigData.GetWeaponsArray().Insert(new DNA_Config_Weapons("yellow", "main", "SawedoffIzh43Shotgun", "", "AmmoBox_00buck_10rnd", "", "", "", "", "", ""));
		m_KeyCard_Weapons_ConfigData.GetWeaponsArray().Insert(new DNA_Config_Weapons("yellow", "side", "Magnum", "", "Ammo_357", "", "", "", "", "", ""));
		m_KeyCard_Weapons_ConfigData.GetWeaponsArray().Insert(new DNA_Config_Weapons("yellow", "side", "MKII", "Mag_MKII_10Rnd", "Ammo_22", "", "", "", "", "", ""));
		
		m_KeyCard_Weapons_ConfigData.GetWeaponsArray().Insert(new DNA_Config_Weapons("green", "main", "Izh18", "", "AmmoBox_762x39_20Rnd", "", "", "", "", "", ""));
		m_KeyCard_Weapons_ConfigData.GetWeaponsArray().Insert(new DNA_Config_Weapons("green", "main", "Mosin9130_Camo", "", "AmmoBox_762x54_20Rnd", "PUScopeOptic", "Mosin_Compensator", "", "", "", ""));
		m_KeyCard_Weapons_ConfigData.GetWeaponsArray().Insert(new DNA_Config_Weapons("green", "main", "SKS_Black", "", "AmmoBox_762x39_20Rnd", "PUScopeOptic", "SKS_Bayonet", "", "", "", ""));
		m_KeyCard_Weapons_ConfigData.GetWeaponsArray().Insert(new DNA_Config_Weapons("green", "side", "Colt1911", "Mag_1911_7Rnd", "Ammo_45ACP", "", "", "", "", "", ""));
		
		m_KeyCard_Weapons_ConfigData.GetWeaponsArray().Insert(new DNA_Config_Weapons("blue", "main", "MP5K", "Mag_MP5_30Rnd", "AmmoBox_9x19_25rnd", "ReflexOptic", "PistolSuppressor", "UniversalLight", "MP5k_StockBttstck", "MP5_RailHndgrd", ""));
		m_KeyCard_Weapons_ConfigData.GetWeaponsArray().Insert(new DNA_Config_Weapons("blue", "main", "AKS74U_Black", "Mag_AK74_30Rnd_Black", "AmmoBox_545x39_20Rnd", "", "AK_Suppressor", "", "AKS74U_Bttstck_Black", "", ""));
		m_KeyCard_Weapons_ConfigData.GetWeaponsArray().Insert(new DNA_Config_Weapons("blue", "side", "Engraved1911", "Mag_1911_7Rnd", "Ammo_45ACP", "", "", "", "", "", ""));
		
		m_KeyCard_Weapons_ConfigData.GetWeaponsArray().Insert(new DNA_Config_Weapons("purple", "main", "FAL", "Mag_FAL_20Rnd", "AmmoBox_308WIN_20Rnd", "ReflexOptic", "", "", "Fal_FoldingBttstck", "", ""));
		m_KeyCard_Weapons_ConfigData.GetWeaponsArray().Insert(new DNA_Config_Weapons("purple", "main", "M4A1_Black", "Mag_STANAG_30Rnd", "AmmoBox_556x45_20Rnd", "ACOGOptic", "M4_Suppressor", "UniversalLight", "M4_MPBttstck", "M4_RISHndgrd_Black", ""));
		m_KeyCard_Weapons_ConfigData.GetWeaponsArray().Insert(new DNA_Config_Weapons("purple", "side", "Glock19", "Mag_Glock_15Rnd", "Ammo_9x19", "FNP45_MRDSOptic", "PistolSuppressor", "TLRLight", "", "", ""));
		
		m_KeyCard_Weapons_ConfigData.GetWeaponsArray().Insert(new DNA_Config_Weapons("red", "main", "SVD", "Mag_SVD_10Rnd", "AmmoBox_762x54_20Rnd", "PSO1Optic", "AK_Suppressor", "", "", "", ""));
		m_KeyCard_Weapons_ConfigData.GetWeaponsArray().Insert(new DNA_Config_Weapons("red", "main", "Winchester70", "", "AmmoBox_308WIN_20Rnd", "HuntingOptic", "", "", "", "", ""));
		m_KeyCard_Weapons_ConfigData.GetWeaponsArray().Insert(new DNA_Config_Weapons("red", "side", "FNX45", "Mag_FNX45_15Rnd", "Ammo_45ACP", "FNP45_MRDSOptic", "PistolSuppressor", "TLRLight", "", "", ""));
	
		JsonFileLoader<KeyCard_ConfigData_Weapons>.JsonSaveFile(dna_WeaponConfigPath, m_KeyCard_Weapons_ConfigData);
	}
}