class KeyCard_Config_Mob_System
{	
	protected static ref KeyCard_ConfigData_Mob_System m_KeyCard_Mob_System_ConfigData;
	
	void KeyCard_Config_Mob_System()
	{
		if(GetGame().IsDedicatedServer())
			LoadConfig();
	}
	
	KeyCard_ConfigData_Mob_System GetConfigData()
	{
		if(!m_KeyCard_Mob_System_ConfigData)
		{
			LoadConfig();
		}
		return m_KeyCard_Mob_System_ConfigData;
	}
	
	protected static void LoadConfig()
	{	
		if(GetGame().IsDedicatedServer())
		{
			if (!FileExist(dna_ProfilePath + dna_ConfigFolderName + "/System/Mobs/"))
			{
				Print("[DNA DEBUG] - DNA_Keycards Mob System: Directory not found, creating directory!");
				MakeDirectory(dna_ProfilePath + dna_ConfigFolderName + "/System/Mobs/");
			}
			
			m_KeyCard_Mob_System_ConfigData = new KeyCard_ConfigData_Mob_System();
			
			if (!FileExist(dna_MobSystemConfigPath))
			{
				if(!KeyCard_Config_Main_System.RecentlyUpdated()) Print("[DNA DEBUG] - DNA_Keycards Mob System Settings: Config not found, creating default config!");
				CreateDefaultConfig();
			}
			else
			{
				JsonFileLoader<KeyCard_ConfigData_Mob_System>.JsonLoadFile(dna_MobSystemConfigPath, m_KeyCard_Mob_System_ConfigData);
				if(KeyCard_Config_Main_System.HasBeenChecked()) Print("[DNA DEBUG] - DNA_Keycards Mob System Settings: Config found, loading settings!");
			}
		}
	}
	
	static void CreateDefaultConfig()
	{
		m_KeyCard_Mob_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Mob_System("wolf", "Animal_CanisLupus_Grey"));
		m_KeyCard_Mob_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Mob_System("wolf", "Animal_CanisLupus_White"));
		
		m_KeyCard_Mob_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Mob_System("bear", "Animal_UrsusArctos"));

		m_KeyCard_Mob_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Mob_System("infected", "ZmbM_CitizenASkinny_Brown"));
		m_KeyCard_Mob_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Mob_System("infected", "ZmbF_JournalistNormal_White"));
		m_KeyCard_Mob_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Mob_System("infected", "ZmbM_priestPopSkinny"));
		m_KeyCard_Mob_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Mob_System("infected", "ZmbF_Clerk_Normal_White"));
		m_KeyCard_Mob_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Mob_System("infected", "ZmbM_HermitSkinny_Beige"));
		m_KeyCard_Mob_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Mob_System("infected", "ZmbF_CitizenANormal_Blue"));
		m_KeyCard_Mob_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Mob_System("infected", "ZmbM_CitizenBFat_Red"));
		m_KeyCard_Mob_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Mob_System("infected", "ZmbF_CitizenBSkinny"));
		m_KeyCard_Mob_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Mob_System("infected", "ZmbM_FishermanOld_Green"));
		m_KeyCard_Mob_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Mob_System("infected", "ZmbF_HikerSkinny_Grey"));
		m_KeyCard_Mob_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Mob_System("infected", "ZmbM_HunterOld_Autumn"));
		m_KeyCard_Mob_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Mob_System("infected", "ZmbF_SurvivorNormal_Orange"));
		m_KeyCard_Mob_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Mob_System("infected", "ZmbM_CitizenBFat_Blue"));
		m_KeyCard_Mob_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Mob_System("infected", "ZmbF_HikerSkinny_Green"));
		m_KeyCard_Mob_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Mob_System("infected", "ZmbM_MotobikerFat_Black"));
		m_KeyCard_Mob_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Mob_System("infected", "ZmbF_JoggerSkinny_Green"));
		m_KeyCard_Mob_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Mob_System("infected", "ZmbM_JoggerSkinny_Red"));
		m_KeyCard_Mob_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Mob_System("infected", "ZmbF_SkaterYoung_Striped"));
		m_KeyCard_Mob_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Mob_System("infected", "ZmbM_MechanicSkinny_Grey"));
		m_KeyCard_Mob_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Mob_System("infected", "ZmbF_BlueCollarFat_Red"));
		m_KeyCard_Mob_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Mob_System("infected", "ZmbM_HandymanNormal_Green"));
		m_KeyCard_Mob_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Mob_System("infected", "ZmbF_MechanicNormal_Beige"));
		m_KeyCard_Mob_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Mob_System("infected", "ZmbM_HeavyIndustryWorker"));
		m_KeyCard_Mob_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Mob_System("infected", "ZmbF_PatientOld"));
		m_KeyCard_Mob_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Mob_System("infected", "ZmbM_Jacket_black"));
		m_KeyCard_Mob_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Mob_System("infected", "ZmbF_ShortSkirt_beige"));
		m_KeyCard_Mob_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Mob_System("infected", "ZmbM_Jacket_stripes"));
		m_KeyCard_Mob_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Mob_System("infected", "ZmbF_VillagerOld_Red"));
		m_KeyCard_Mob_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Mob_System("infected", "ZmbM_HikerSkinny_Blue"));
		m_KeyCard_Mob_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Mob_System("infected", "ZmbF_JoggerSkinny_Red"));
		m_KeyCard_Mob_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Mob_System("infected", "ZmbM_HikerSkinny_Yellow"));
		m_KeyCard_Mob_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Mob_System("infected", "ZmbF_MilkMaidOld_Beige"));
		m_KeyCard_Mob_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Mob_System("infected", "ZmbM_PolicemanFat"));
		m_KeyCard_Mob_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Mob_System("infected", "ZmbF_VillagerOld_Green"));
		m_KeyCard_Mob_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Mob_System("infected", "ZmbM_PatrolNormal_Summer"));
		m_KeyCard_Mob_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Mob_System("infected", "ZmbF_ShortSkirt_yellow"));
		m_KeyCard_Mob_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Mob_System("infected", "ZmbM_JoggerSkinny_Blue"));
		m_KeyCard_Mob_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Mob_System("infected", "ZmbF_NurseFat"));
		m_KeyCard_Mob_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Mob_System("infected", "ZmbM_VillagerOld_White"));
		m_KeyCard_Mob_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Mob_System("infected", "ZmbF_PoliceWomanNormal"));
		m_KeyCard_Mob_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Mob_System("infected", "ZmbM_SkaterYoung_Brown"));
		m_KeyCard_Mob_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Mob_System("infected", "ZmbF_HikerSkinny_Blue"));
		m_KeyCard_Mob_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Mob_System("infected", "ZmbM_MechanicSkinny_Green"));
		m_KeyCard_Mob_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Mob_System("infected", "ZmbF_ParamedicNormal_Green"));
		m_KeyCard_Mob_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Mob_System("infected", "ZmbM_DoctorFat"));
		m_KeyCard_Mob_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Mob_System("infected", "ZmbF_JournalistNormal_Red"));
		m_KeyCard_Mob_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Mob_System("infected", "ZmbM_PatientSkinny"));
		m_KeyCard_Mob_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Mob_System("infected", "ZmbF_SurvivorNormal_White"));
		m_KeyCard_Mob_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Mob_System("infected", "ZmbM_ClerkFat_Brown"));
		m_KeyCard_Mob_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Mob_System("infected", "ZmbF_JoggerSkinny_Brown"));
		m_KeyCard_Mob_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Mob_System("infected", "ZmbM_ClerkFat_White"));
		m_KeyCard_Mob_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Mob_System("infected", "ZmbF_MechanicNormal_Grey"));
		m_KeyCard_Mob_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Mob_System("infected", "ZmbM_Jacket_magenta"));
		m_KeyCard_Mob_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Mob_System("infected", "ZmbF_BlueCollarFat_Green"));
		m_KeyCard_Mob_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Mob_System("infected", "ZmbM_PolicemanSpecForce"));
		m_KeyCard_Mob_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Mob_System("infected", "ZmbF_DoctorSkinny"));
		
		m_KeyCard_Mob_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Mob_System("bossYellow", ""));
		
		m_KeyCard_Mob_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Mob_System("bossGreen", ""));
		
		m_KeyCard_Mob_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Mob_System("bossBlue", ""));
		
		m_KeyCard_Mob_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Mob_System("bossPurple", ""));
		
		m_KeyCard_Mob_System_ConfigData.GetSystemArray().Insert(new DNA_Config_Mob_System("bossRed", ""));
		
		JsonFileLoader<KeyCard_ConfigData_Mob_System>.JsonSaveFile(dna_MobSystemConfigPath, m_KeyCard_Mob_System_ConfigData);
	}
}