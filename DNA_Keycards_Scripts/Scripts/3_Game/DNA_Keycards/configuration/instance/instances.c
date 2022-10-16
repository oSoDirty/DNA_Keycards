class DNA_Keycards_Main_System
{
	protected static ref DNA_Keycards_Main_System Instance;
	
	protected static ref KeyCard_Config_Main_System m_KeyCard_Main_System_Config;
	
	void DNA_Keycards_Main_System()
	{
		if(GetGame().IsServer())
			m_KeyCard_Main_System_Config = new KeyCard_Config_Main_System;
		
	}
	
	static DNA_Keycards_Main_System GetInstance()
	{
		if(!Instance)
			Instance = new DNA_Keycards_Main_System();
		return Instance;
	}
	
	static void ClearInstance()
	{
		Instance = null;
	}
	
	KeyCard_Config_Main_System GetConfig()
	{
		if(!m_KeyCard_Main_System_Config)
			m_KeyCard_Main_System_Config = new KeyCard_Config_Main_System();
		return m_KeyCard_Main_System_Config;
	}

	static int GetTimeInSeconds()
	{
		int hours, minutes, seconds, hoursToMinutes, minutesToSeconds, minutesAdded;
		GetHourMinuteSecond(hours, minutes, seconds);
		hoursToMinutes = hours * 60;
		minutesAdded = hoursToMinutes + minutes;
		minutesToSeconds = minutesAdded * 60;
		return seconds + minutesToSeconds;
	}
}

class DNA_Keycards_Container_System
{
	
	protected static ref DNA_Keycards_Container_System Instance;
	
	protected static ref KeyCard_Config_Container_System m_KeyCard_Container_System_Config;
	
	void DNA_Keycards_Container_System()
	{
		if(GetGame().IsServer())
			m_KeyCard_Container_System_Config = new KeyCard_Config_Container_System;
		
	}
	
	static DNA_Keycards_Container_System GetInstance()
	{
		if(!Instance)
			Instance = new DNA_Keycards_Container_System();
		return Instance;
	}
	
	static void ClearInstance()
	{
		Instance = null;
	}
	
	KeyCard_Config_Container_System GetConfig()
	{
		if(!m_KeyCard_Container_System_Config)
			m_KeyCard_Container_System_Config = new KeyCard_Config_Container_System();
		return m_KeyCard_Container_System_Config;
	}
}

class DNA_Keycards_Mob_System
{
	
	protected static ref DNA_Keycards_Mob_System Instance;
	
	protected static ref KeyCard_Config_Mob_System m_KeyCard_Mob_System_Config;
	
	void DNA_Keycards_Mob_System()
	{
		if(GetGame().IsServer())
			m_KeyCard_Mob_System_Config = new KeyCard_Config_Mob_System;
		
	}
	
	static DNA_Keycards_Mob_System GetInstance()
	{
		if(!Instance)
			Instance = new DNA_Keycards_Mob_System();
		return Instance;
	}
	
	static void ClearInstance()
	{
		Instance = null;
	}
	
	KeyCard_Config_Mob_System GetConfig()
	{
		if(!m_KeyCard_Mob_System_Config)
			m_KeyCard_Mob_System_Config = new KeyCard_Config_Mob_System();
		return m_KeyCard_Mob_System_Config;
	}
}

class DNA_Keycards_Loot
{
	protected static ref DNA_Keycards_Loot Instance;
	
	protected static ref KeyCard_Config_Loot m_KeyCard_Loot_Config;
	
	void DNA_Keycards_Loot()
	{
		if(GetGame().IsServer())
			m_KeyCard_Loot_Config = new KeyCard_Config_Loot;
	}
	
	static DNA_Keycards_Loot GetInstance()
	{
		if(!Instance)
			Instance = new DNA_Keycards_Loot();
		return Instance;
	}
	
	static void ClearInstance()
	{
		Instance = null;
	}
	
	KeyCard_Config_Loot GetConfig()
	{
		if(!m_KeyCard_Loot_Config)
			m_KeyCard_Loot_Config = new KeyCard_Config_Loot();
		return m_KeyCard_Loot_Config;
	}
}

class DNA_Keycards_Clothing
{
	protected static ref DNA_Keycards_Clothing Instance;
	
	protected static ref KeyCard_Config_Clothing m_KeyCard_Clothing_Config;
	
	void DNA_Keycards_Clothing()
	{
		if(GetGame().IsServer())
			m_KeyCard_Clothing_Config = new KeyCard_Config_Clothing;
	}
	
	static DNA_Keycards_Clothing GetInstance()
	{
		if(!Instance)
			Instance = new DNA_Keycards_Clothing();
		return Instance;
	}
	
	static void ClearInstance()
	{
		Instance = null;
	}
	
	KeyCard_Config_Clothing GetConfig()
	{
		if(!m_KeyCard_Clothing_Config)
			m_KeyCard_Clothing_Config = new KeyCard_Config_Clothing();
		return m_KeyCard_Clothing_Config;
	}
}

class DNA_Keycards_Weapons
{
	protected static ref DNA_Keycards_Weapons Instance;
	
	protected static ref KeyCard_Config_Weapons m_KeyCard_Weapons_Config;
	
	void DNA_Keycards_Weapons()
	{
		if(GetGame().IsServer())
			m_KeyCard_Weapons_Config = new KeyCard_Config_Weapons;
	}
	
	static DNA_Keycards_Weapons GetInstance()
	{
		if(!Instance)
			Instance = new DNA_Keycards_Weapons();
		return Instance;
	}
	
	static void ClearInstance()
	{
		Instance = null;
	}
	
	KeyCard_Config_Weapons GetConfig()
	{
		if(!m_KeyCard_Weapons_Config)
			m_KeyCard_Weapons_Config = new KeyCard_Config_Weapons();
		return m_KeyCard_Weapons_Config;
	}
}

/*class DNA_Crafting_Instance
{
	
	protected static ref DNA_Crafting_Instance Instance;
	
	protected static ref DNA_Crafting_Config m_DNA_Crafting_Config;
	
	void DNA_Crafting_Instance()
	{
		if(GetGame().IsServer())
			m_DNA_Crafting_Config = new DNA_Crafting_Config;
		
	}
	
	static DNA_Crafting_Instance GetInstance()
	{
		if(!Instance)
			Instance = new DNA_Crafting_Instance();
		return Instance;
	}
	
	static void ClearInstance()
	{
		Instance = null;
	}
	
	DNA_Crafting_Config GetConfig()
	{
		if(!m_DNA_Crafting_Config)
			m_DNA_Crafting_Config = new DNA_Crafting_Config();
		return m_DNA_Crafting_Config;
	}
}*/