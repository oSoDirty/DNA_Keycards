class KeyCard_Config_Clothing
{
	protected static ref KeyCard_ConfigData_Clothing m_KeyCard_Clothing_ConfigData;
	
	void KeyCard_Config_Clothing()
	{
		if(GetGame().IsDedicatedServer())
			LoadConfig();
	}
	
	KeyCard_ConfigData_Clothing GetConfigData()
	{
		if(!m_KeyCard_Clothing_ConfigData)
		{
			LoadConfig();
		}
		return m_KeyCard_Clothing_ConfigData;
	}
	
	protected static void LoadConfig()
	{
		if(GetGame().IsDedicatedServer())
		{
			if (!FileExist(dna_ProfilePath + dna_ConfigFolderName + "/Loot/Clothing/"))
			{
				Print("[DNA DEBUG] - DNA Keycards Clothing Loot: Directory not found, creating directory!");
				MakeDirectory(dna_ProfilePath + dna_ConfigFolderName + "/Loot/Clothing/");
			}
			
			m_KeyCard_Clothing_ConfigData = new KeyCard_ConfigData_Clothing();
			
			if (!FileExist(dna_ClothingConfigPath))
			{
				if(!KeyCard_Config_Main_System.RecentlyUpdated()) Print("[DNA DEBUG] - DNA Keycards Clothing Loot: Config not found, creating default config!");
				CreateDefaultConfig();
			}
			else
			{
				JsonFileLoader<KeyCard_ConfigData_Clothing>.JsonLoadFile(dna_ClothingConfigPath, m_KeyCard_Clothing_ConfigData);
				if(KeyCard_Config_Main_System.HasBeenChecked()) Print("[DNA DEBUG] - DNA Keycards Clothing Loot: Config found, loading settings!");
			}
		}
	}
	
	static void CreateDefaultConfig()   //("tier", "helmet", "shirt", "vest", "pants", "shoes", "backpack", "gloves", "belt", "face", "eyes", "armband", "nvg")
	{
		m_KeyCard_Clothing_ConfigData.GetClothingArray().Insert(new DNA_Config_Clothing("yellow", "BaseballCap_Blue", "Shirt_BlueCheck", "PressVest_Blue", "Jeans_Blue", "AthleticShoes_Blue", "ImprovisedBag", "SurgicalGloves_LightBlue", "", "SurgicalMask", "", "", ""));
		m_KeyCard_Clothing_ConfigData.GetClothingArray().Insert(new DNA_Config_Clothing("yellow", "BaseballCap_Red", "TShirt_Red", "PoliceVest", "Jeans_Black", "JoggingShoes_Red", "CourierBag", "LeatherGloves_Brown", "", "", "", "Armband_White", ""));
		
		m_KeyCard_Clothing_ConfigData.GetClothingArray().Insert(new DNA_Config_Clothing("green", "MotoHelmet_Black", "RidersJacket_Black", "LeatherStorageVest_Black", "CargoPants_Black", "HikingBoots_Black", "HuntingBag", "WorkingGloves_Black", "", "", "SportGlasses_Black", "", ""));
		m_KeyCard_Clothing_ConfigData.GetClothingArray().Insert(new DNA_Config_Clothing("green", "SkateHelmet_Green", "HikingJacket_Green", "HuntingVest", "CargoPants_Green", "WorkingBoots_Green", "HuntingBag", "WorkingGloves_Black", "", "", "SportGlasses_Green", "", ""));
		
		m_KeyCard_Clothing_ConfigData.GetClothingArray().Insert(new DNA_Config_Clothing("blue", "GorkaHelmet_Green", "M65Jacket_Olive", "UKAssVest_Olive", "USMCPants_Woodland", "CombatBoots_Green", "AssaultBag_Ttsko", "TacticalGloves_Green", "CivilianBelt", "", "SportGlasses_Green", "", ""));
		m_KeyCard_Clothing_ConfigData.GetClothingArray().Insert(new DNA_Config_Clothing("blue", "GorkaHelmet_Black", "M65Jacket_Black", "UKAssVest_Black", "USMCPants_Woodland", "CombatBoots_Black", "AssaultBag_Black", "TacticalGloves_Black", "CivilianBelt", "", "SportGlasses_Black", "", ""));
		
		m_KeyCard_Clothing_ConfigData.GetClothingArray().Insert(new DNA_Config_Clothing("purple", "BallisticHelmet_Green", "TTsKOJacket_Camo", "UKAssVest_Camo", "TTSKOPants", "MilitaryBoots_Beige", "CoyoteBag_Green", "TacticalGloves_Green", "MilitaryBelt", "GasMask", "", "", ""));
		m_KeyCard_Clothing_ConfigData.GetClothingArray().Insert(new DNA_Config_Clothing("purple", "BallisticHelmet_Black", "M65Jacket_Black", "UKAssVest_Black", "TTSKOPants", "MilitaryBoots_Black", "CoyoteBag_Brown", "TacticalGloves_Beige", "MilitaryBelt", "GasMask", "", "", ""));
		
		m_KeyCard_Clothing_ConfigData.GetClothingArray().Insert(new DNA_Config_Clothing("red", "Mich2001Helmet", "GorkaEJacket_Autumn", "HighCapacityVest_Olive", "GorkaPants_Autumn", "JungleBoots_Green", "AliceBag_Green", "TacticalGloves_Green", "MilitaryBelt", "GP5GasMask", "GasMask_Filter", "", "NVGoggles"));
		m_KeyCard_Clothing_ConfigData.GetClothingArray().Insert(new DNA_Config_Clothing("red", "Mich2001Helmet", "M65Jacket_Black", "HighCapacityVest_Black", "GorkaPants_Autumn", "JungleBoots_Black", "AliceBag_Black", "TacticalGloves_Black", "MilitaryBelt", "GP5GasMask", "GasMask_Filter", "", "NVGoggles"));
	
		JsonFileLoader<KeyCard_ConfigData_Clothing>.JsonSaveFile(dna_ClothingConfigPath, m_KeyCard_Clothing_ConfigData);
	}
}