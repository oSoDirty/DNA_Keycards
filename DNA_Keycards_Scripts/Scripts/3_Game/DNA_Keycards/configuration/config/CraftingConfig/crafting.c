class DNA_Crafting_Config
{
	protected static ref DNA_Crafting_Data m_DNA_Crafting_Data;
	
	void DNA_Crafting_Config()
	{
		if(GetGame().IsDedicatedServer())
			LoadConfig();
	}
	
	static void CreateDirectory()
	{
		if(GetGame().IsDedicatedServer())
		{
			if (!FileExist("$profile:" + dna_Crafting_ConfigFolderName + "/"))
			{
				Print("[DNA DEBUG] - DNA_Crafting Config: Directory not found, creating directory!");
				MakeDirectory("$profile:" + dna_Crafting_ConfigFolderName + "/");
			}
		}
	}
	
	DNA_Crafting_Data GetConfigData()
	{
		if(!m_DNA_Crafting_Data)
		{
			LoadConfig();
		}
		return m_DNA_Crafting_Data;
	}
	
	protected static void LoadConfig()
	{	
		if(GetGame().IsDedicatedServer())
		{
			
			m_DNA_Crafting_Data = new DNA_Crafting_Data();
			
			if (!FileExist(dna_CraftingConfigPath))
			{
				Print("[DNA DEBUG] - DNA_Crafting: Config not found, creating default config!");
				CreateDefaultConfig();
			}
			else
			{
				JsonFileLoader<DNA_Crafting_Data>.JsonLoadFile(dna_CraftingConfigPath, m_DNA_Crafting_Data);
				Print("[DNA DEBUG] - DNA_Crafting: Config found, loading settings!");
			}
		}
	}
	
	static void CreateDefaultConfig()
	{
		m_DNA_Crafting_Data.GetRecipeArray().Insert(new DNA_Crafting_Defines("", "", "", "", "", "", "", "", ""));
		JsonFileLoader<DNA_Crafting_Data>.JsonSaveFile(dna_CraftingConfigPath, m_DNA_Crafting_Data);
	}
}