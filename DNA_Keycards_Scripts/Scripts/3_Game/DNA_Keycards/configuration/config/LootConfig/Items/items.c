class KeyCard_Config_Loot
{
	protected static ref KeyCard_ConfigData_Loot m_KeyCard_Loot_ConfigData;
	
	void KeyCard_Config_Loot()
	{
		if(GetGame().IsDedicatedServer())
			LoadConfig();
	}
	
	KeyCard_ConfigData_Loot GetConfigData()
	{
		if(!m_KeyCard_Loot_ConfigData)
		{
			LoadConfig();
		}
		return m_KeyCard_Loot_ConfigData;
	}
	
	protected static void LoadConfig()
	{
		if(GetGame().IsDedicatedServer())
		{
			if (!FileExist(dna_ProfilePath + dna_ConfigFolderName + "/Loot/"))
			{
				MakeDirectory(dna_ProfilePath + dna_ConfigFolderName + "/Loot/");
			}
			
			if (!FileExist(dna_ProfilePath + dna_ConfigFolderName + "/Loot/General/"))
			{
				Print("[DNA DEBUG] - DNA Keycards General Loot: Directory not found, creating directory!");
				MakeDirectory(dna_ProfilePath + dna_ConfigFolderName + "/Loot/General/");
			}
			
			m_KeyCard_Loot_ConfigData = new KeyCard_ConfigData_Loot();
			
			if (!FileExist(dna_LootConfigPath))
			{
				if(!KeyCard_Config_Main_System.RecentlyUpdated()) Print("[DNA DEBUG] - DNA Keycards General Loot: Config not found, creating default config!");
				CreateDefaultConfig();
			}
			else
			{
				JsonFileLoader<KeyCard_ConfigData_Loot>.JsonLoadFile(dna_LootConfigPath, m_KeyCard_Loot_ConfigData);
				if(KeyCard_Config_Main_System.HasBeenChecked()) Print("[DNA DEBUG] - DNA Keycards General Loot: Config found, loading settings!");
			}
		}
	}
	
	static void CreateDefaultConfig()
	{
		m_KeyCard_Loot_ConfigData.GetLootArray().Insert(new DNA_Config_Loot("yellow", "proprietary", ""));
		m_KeyCard_Loot_ConfigData.GetLootArray().Insert(new DNA_Config_Loot("yellow", "medical", "BloodTestKit"));
		m_KeyCard_Loot_ConfigData.GetLootArray().Insert(new DNA_Config_Loot("yellow", "food", "BoxCerealCrunchin"));
		m_KeyCard_Loot_ConfigData.GetLootArray().Insert(new DNA_Config_Loot("yellow", "drink", "SodaCan_Spite"));
		m_KeyCard_Loot_ConfigData.GetLootArray().Insert(new DNA_Config_Loot("yellow", "tools", "Pickaxe"));
		m_KeyCard_Loot_ConfigData.GetLootArray().Insert(new DNA_Config_Loot("yellow", "material", "WoodenPlank"));
		m_KeyCard_Loot_ConfigData.GetLootArray().Insert(new DNA_Config_Loot("yellow", "valuable", ""));
		m_KeyCard_Loot_ConfigData.GetLootArray().Insert(new DNA_Config_Loot("yellow", "misc", ""));
		
		m_KeyCard_Loot_ConfigData.GetLootArray().Insert(new DNA_Config_Loot("green", "proprietary", ""));
		m_KeyCard_Loot_ConfigData.GetLootArray().Insert(new DNA_Config_Loot("green", "medical", "BloodBagIV"));
		m_KeyCard_Loot_ConfigData.GetLootArray().Insert(new DNA_Config_Loot("green", "food", "PeachesCan_Opened"));
		m_KeyCard_Loot_ConfigData.GetLootArray().Insert(new DNA_Config_Loot("green", "drink", "SodaCan_Cola"));
		m_KeyCard_Loot_ConfigData.GetLootArray().Insert(new DNA_Config_Loot("green", "tools", "Screwdriver"));
		m_KeyCard_Loot_ConfigData.GetLootArray().Insert(new DNA_Config_Loot("green", "material", "NailBox"));
		m_KeyCard_Loot_ConfigData.GetLootArray().Insert(new DNA_Config_Loot("green", "valuable", ""));
		m_KeyCard_Loot_ConfigData.GetLootArray().Insert(new DNA_Config_Loot("green", "misc", ""));
		
		m_KeyCard_Loot_ConfigData.GetLootArray().Insert(new DNA_Config_Loot("blue", "proprietary", ""));
		m_KeyCard_Loot_ConfigData.GetLootArray().Insert(new DNA_Config_Loot("blue", "medical", "TetracyclineAntibiotics"));
		m_KeyCard_Loot_ConfigData.GetLootArray().Insert(new DNA_Config_Loot("blue", "food", "TacticalBaconCan"));
		m_KeyCard_Loot_ConfigData.GetLootArray().Insert(new DNA_Config_Loot("blue", "drink", "SodaCan_Fronta"));
		m_KeyCard_Loot_ConfigData.GetLootArray().Insert(new DNA_Config_Loot("blue", "tools", "Shovel"));
		m_KeyCard_Loot_ConfigData.GetLootArray().Insert(new DNA_Config_Loot("blue", "material", "FenceKit"));
		m_KeyCard_Loot_ConfigData.GetLootArray().Insert(new DNA_Config_Loot("blue", "valuable", ""));
		m_KeyCard_Loot_ConfigData.GetLootArray().Insert(new DNA_Config_Loot("blue", "misc", ""));
		
		m_KeyCard_Loot_ConfigData.GetLootArray().Insert(new DNA_Config_Loot("purple", "proprietary", ""));
		m_KeyCard_Loot_ConfigData.GetLootArray().Insert(new DNA_Config_Loot("purple", "medical", "BandageDressing"));
		m_KeyCard_Loot_ConfigData.GetLootArray().Insert(new DNA_Config_Loot("purple", "food", "BakedBeansCan"));
		m_KeyCard_Loot_ConfigData.GetLootArray().Insert(new DNA_Config_Loot("purple", "drink", "WaterBottle"));
		m_KeyCard_Loot_ConfigData.GetLootArray().Insert(new DNA_Config_Loot("purple", "tools", "WoodAxe"));
		m_KeyCard_Loot_ConfigData.GetLootArray().Insert(new DNA_Config_Loot("purple", "material", "TerritoryFlagKit"));
		m_KeyCard_Loot_ConfigData.GetLootArray().Insert(new DNA_Config_Loot("purple", "valuable", ""));
		m_KeyCard_Loot_ConfigData.GetLootArray().Insert(new DNA_Config_Loot("purple", "misc", ""));
		
		m_KeyCard_Loot_ConfigData.GetLootArray().Insert(new DNA_Config_Loot("red", "proprietary", ""));
		m_KeyCard_Loot_ConfigData.GetLootArray().Insert(new DNA_Config_Loot("red", "medical", "Morphine"));
		m_KeyCard_Loot_ConfigData.GetLootArray().Insert(new DNA_Config_Loot("red", "food", "BakedBeansCan_Opened"));
		m_KeyCard_Loot_ConfigData.GetLootArray().Insert(new DNA_Config_Loot("red", "drink", "SodaCan_Pipsi"));
		m_KeyCard_Loot_ConfigData.GetLootArray().Insert(new DNA_Config_Loot("red", "tools", "FirefighterAxe_Green"));
		m_KeyCard_Loot_ConfigData.GetLootArray().Insert(new DNA_Config_Loot("red", "material", "ShelterKit"));
		m_KeyCard_Loot_ConfigData.GetLootArray().Insert(new DNA_Config_Loot("red", "valuable", ""));
		m_KeyCard_Loot_ConfigData.GetLootArray().Insert(new DNA_Config_Loot("red", "misc", ""));
		
	
		JsonFileLoader<KeyCard_ConfigData_Loot>.JsonSaveFile(dna_LootConfigPath, m_KeyCard_Loot_ConfigData);
	}
}