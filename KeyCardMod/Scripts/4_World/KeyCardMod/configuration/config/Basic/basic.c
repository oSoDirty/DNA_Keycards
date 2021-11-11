class KeyCard_Config_Base
{	
	protected static ref KeyCard_ConfigData_Base m_KeyCard_Base_ConfigData;

	void KeyCard_Config_Base()
	{
		LoadConfig();
	}
	
	KeyCard_ConfigData_Base GetConfigData()
	{
		if(!m_KeyCard_Base_ConfigData)
		{
			LoadConfig();
		}
		return m_KeyCard_Base_ConfigData;
	}
	
	protected static void LoadConfig()
	{
		if (!FileExist(kcm_ProfilePath + m_ConfigFolderName + "/Basic/"))
        {
			Print("[KCM_Debug] - KeyCardMod Basic: Directory not found, creating directory!");
			MakeDirectory(kcm_ProfilePath + m_ConfigFolderName + "/Basic/");
		}
		
		m_KeyCard_Base_ConfigData = new KeyCard_ConfigData_Base();
		
		if (!FileExist(kcm_ProfilePath + m_ConfigFolderName + "/Basic/" + m_ConfigName + "Basic" + m_ConfigExtension))
        {
			Print("[KCM_Debug] - KeyCardMod Basic: Config not found, creating default config!");
            CreateDefaultConfig();
        }
		else
		{
			JsonFileLoader<KeyCard_ConfigData_Base>.JsonLoadFile(kcm_ProfilePath + m_ConfigFolderName + "/Basic/" + m_ConfigName + "Basic" + m_ConfigExtension, m_KeyCard_Base_ConfigData);
		}
	}
	
	static void CreateDefaultConfig()
	{
		m_KeyCard_Base_ConfigData.GetSideArmArray().Insert(new KCM_SideArm("Glock19", "FNP45_MRDSOptic", "PistolSuppressor", "TLRLight", "Mag_Glock_15Rnd", "Battery9V", "AmmoBox_9x19_25rnd"));
		m_KeyCard_Base_ConfigData.GetSideArmArray().Insert(new KCM_SideArm("FNX45", "FNP45_MRDSOptic", "PistolSuppressor", "TLRLight", "Mag_FNX45_15Rnd", "Battery9V", "AmmoBox_45ACP_25rnd"));
		
		m_KeyCard_Base_ConfigData.GetFoodArray().Insert(new KCM_Food("BoxCerealCrunchin"));
		m_KeyCard_Base_ConfigData.GetFoodArray().Insert(new KCM_Food("PeachesCan_Opened"));
		
		m_KeyCard_Base_ConfigData.GetDrinkArray().Insert(new KCM_Drink("SodaCan_Pipsi"));
		m_KeyCard_Base_ConfigData.GetDrinkArray().Insert(new KCM_Drink("SodaCan_Fronta"));
		
		m_KeyCard_Base_ConfigData.GetToolsArray().Insert(new KCM_Tools("Pickaxe"));
		m_KeyCard_Base_ConfigData.GetToolsArray().Insert(new KCM_Tools("HuntingKnife"));
		
		m_KeyCard_Base_ConfigData.GetMedicalArray().Insert(new KCM_Medical("BandageDressing"));
		m_KeyCard_Base_ConfigData.GetMedicalArray().Insert(new KCM_Medical("Morphine"));
		
		m_KeyCard_Base_ConfigData.GetBuildingArray().Insert(new KCM_BuildingMats("NailBox"));
		m_KeyCard_Base_ConfigData.GetBuildingArray().Insert(new KCM_BuildingMats("WoodenPlank"));
		
		m_KeyCard_Base_ConfigData.GetValuablesArray().Insert(new KCM_Valuables("This is reserved for niche items you may have in your server"));
		m_KeyCard_Base_ConfigData.GetValuablesArray().Insert(new KCM_Valuables("Change these to the name of your items/add more and turn on Valuables in System config"));
		m_KeyCard_Base_ConfigData.GetValuablesArray().Insert(new KCM_Valuables("!!! WARNING - Remove This and any description entries once valuables is turned on!!!!"));
		
		m_KeyCard_Base_ConfigData.GetBaseVarsArray().Insert(new Base_Variables("(0) Min Extra Mags to give for Side Arm (Don't set below 1! - Can turn off in system config)", 1));
		m_KeyCard_Base_ConfigData.GetBaseVarsArray().Insert(new Base_Variables("(1) Max Extra Mags to give for Side Arm (Don't set lower than min!)", 3));
		m_KeyCard_Base_ConfigData.GetBaseVarsArray().Insert(new Base_Variables("(2) Min Food Types to give (Don't set below 1! - Can turn off in system config)", 1));
		m_KeyCard_Base_ConfigData.GetBaseVarsArray().Insert(new Base_Variables("(3) Max Food Types to give (Don't set higher than food type entry count or lower than min!)", 1));
		m_KeyCard_Base_ConfigData.GetBaseVarsArray().Insert(new Base_Variables("(4) Min Amount Of Each Food Type to give (Don't set lower than 1)", 1));
		m_KeyCard_Base_ConfigData.GetBaseVarsArray().Insert(new Base_Variables("(5) Max Amount Of Each Food Type to give (Don't set lower than min!)", 3));
		m_KeyCard_Base_ConfigData.GetBaseVarsArray().Insert(new Base_Variables("(6) Min Drink Types to give (Don't set below 1! - Can turn off in system config)", 1));
		m_KeyCard_Base_ConfigData.GetBaseVarsArray().Insert(new Base_Variables("(7) Max Drink Types to give (Don't set higher than drink type entry count or lower than min!)", 1));
		m_KeyCard_Base_ConfigData.GetBaseVarsArray().Insert(new Base_Variables("(8) Min Amount Of Each Drink Type to give (Don't set lower than 1)", 1));
		m_KeyCard_Base_ConfigData.GetBaseVarsArray().Insert(new Base_Variables("(9) Max Amount Of Each Drink Type to give (Don't set lower than min!)", 3));
		m_KeyCard_Base_ConfigData.GetBaseVarsArray().Insert(new Base_Variables("(10) Min Extra Ammo to give for Side Arm (Don't set below 1! - Can turn off in system config)", 1));
		m_KeyCard_Base_ConfigData.GetBaseVarsArray().Insert(new Base_Variables("(11) Max Extra Ammo to give for Side Arm (Don't set lower than min!)", 2));
		m_KeyCard_Base_ConfigData.GetBaseVarsArray().Insert(new Base_Variables("(12) Min Tool Types to give (Don't set below 1! - Can turn off in system config)", 2));
		m_KeyCard_Base_ConfigData.GetBaseVarsArray().Insert(new Base_Variables("(13) Max Tool Types to give (Don't set lower than min!)", 3));
		m_KeyCard_Base_ConfigData.GetBaseVarsArray().Insert(new Base_Variables("(14) Min Amount Of Each Tool Type to give (Don't set below 1! - Can turn off in system config)", 2));
		m_KeyCard_Base_ConfigData.GetBaseVarsArray().Insert(new Base_Variables("(15) Max Amount Of Each Tool Type to give (Don't set lower than min!)", 3));
		m_KeyCard_Base_ConfigData.GetBaseVarsArray().Insert(new Base_Variables("(16) Min Med Types to give (Don't set below 1! - Can turn off in system config)", 2));
		m_KeyCard_Base_ConfigData.GetBaseVarsArray().Insert(new Base_Variables("(17) Max Med Types to give (Don't set lower than min!)", 3));
		m_KeyCard_Base_ConfigData.GetBaseVarsArray().Insert(new Base_Variables("(18) Min Amount Of Each Med Type to give (Don't set below 1! - Can turn off in system config)", 2));
		m_KeyCard_Base_ConfigData.GetBaseVarsArray().Insert(new Base_Variables("(19) Max Amount Of Each Med Type to give (Don't set lower than min!)", 3));
		m_KeyCard_Base_ConfigData.GetBaseVarsArray().Insert(new Base_Variables("(20) Min Material Types to give (Don't set below 1! - Can turn off in system config)", 2));
		m_KeyCard_Base_ConfigData.GetBaseVarsArray().Insert(new Base_Variables("(21) Max Material Types to give (Don't set lower than min!)", 3));
		m_KeyCard_Base_ConfigData.GetBaseVarsArray().Insert(new Base_Variables("(22) Min Amount Of Each Material Type to give (Don't set below 1! - Can turn off in system config)", 2));
		m_KeyCard_Base_ConfigData.GetBaseVarsArray().Insert(new Base_Variables("(23) Max Amount Of Each Material Type to give (Don't set lower than min!)", 3));
		m_KeyCard_Base_ConfigData.GetBaseVarsArray().Insert(new Base_Variables("(24) Min Valuable Types to give (Don't set below 1! - Can turn off in system config)", 2));
		m_KeyCard_Base_ConfigData.GetBaseVarsArray().Insert(new Base_Variables("(25) Max Valuable Types to give (Don't set lower than min!)", 3));
		m_KeyCard_Base_ConfigData.GetBaseVarsArray().Insert(new Base_Variables("(26) Min Amount Of Each Valuable Type to give (Don't set below 1! - Can turn off in system config)", 2));
		m_KeyCard_Base_ConfigData.GetBaseVarsArray().Insert(new Base_Variables("(27) Max Amount Of Each Valuable Type to give (Don't set lower than min!)", 3));
		
		JsonFileLoader<KeyCard_ConfigData_Base>.JsonSaveFile(kcm_ProfilePath + m_ConfigFolderName + "/Basic/" + m_ConfigName + "Basic" + m_ConfigExtension, m_KeyCard_Base_ConfigData);
	}
}