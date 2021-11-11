class KeyCardMod_System
{
	
	protected static ref KeyCardMod_System Instance;
	
	protected static ref KeyCard_Config_System m_KeyCard_System_Config;
	
	void KeyCardMod_System()
	{
		if(GetGame().IsServer())
			m_KeyCard_System_Config = new KeyCard_Config_System;
		
	}
	
	static KeyCardMod_System GetInstance()
	{
		if(!Instance)
			Instance = new KeyCardMod_System();
		return Instance;
	}
	
	static void ClearInstance()
	{
		Instance = null;
	}
	
	KeyCard_Config_System GetConfig()
	{
		if(!m_KeyCard_System_Config)
			m_KeyCard_System_Config = new KeyCard_Config_System();
		return m_KeyCard_System_Config;
	}
}

class KeyCardMod_Base
{
	protected static ref KeyCardMod_Base Instance;
	
	protected static ref KeyCard_Config_Base m_KeyCard_Base_Config;
	
	void KeyCardMod_Base()
	{
		if(GetGame().IsServer())
			m_KeyCard_Base_Config = new KeyCard_Config_Base;
		
	}
	
	static KeyCardMod_Base GetInstance()
	{
		if(!Instance)
			Instance = new KeyCardMod_Base();
		return Instance;
	}
	
	static void ClearInstance()
	{
		Instance = null;
	}
	
	KeyCard_Config_Base GetConfig()
	{
		if(!m_KeyCard_Base_Config)
			m_KeyCard_Base_Config = new KeyCard_Config_Base();
		return m_KeyCard_Base_Config;
	}
}

class KeyCardMod_Yellow
{
	protected static ref KeyCardMod_Yellow Instance;
	
	protected static ref KeyCard_Config_Yellow m_KeyCard_Yellow_Config;
	
	void KeyCardMod_Yellow()
	{
		if(GetGame().IsServer())
			m_KeyCard_Yellow_Config = new KeyCard_Config_Yellow;
		
	}
	
	static KeyCardMod_Yellow GetInstance()
	{
		if(!Instance)
			Instance = new KeyCardMod_Yellow();
		return Instance;
	}
	
	static void ClearInstance()
	{
		Instance = null;
	}
	
	KeyCard_Config_Yellow GetConfig()
	{
		if(!m_KeyCard_Yellow_Config)
			m_KeyCard_Yellow_Config = new KeyCard_Config_Yellow();
		return m_KeyCard_Yellow_Config;
	}
}

class KeyCardMod_Green
{
	protected static ref KeyCardMod_Green Instance;
	
	protected static ref KeyCard_Config_Green m_KeyCard_Green_Config;
	
	void KeyCardMod_Green()
	{
		if(GetGame().IsServer())
			m_KeyCard_Green_Config = new KeyCard_Config_Green;
		
	}
	
	static KeyCardMod_Green GetInstance()
	{
		if(!Instance)
			Instance = new KeyCardMod_Green();
		return Instance;
	}
	
	static void ClearInstance()
	{
		Instance = null;
	}
	
	KeyCard_Config_Green GetConfig()
	{
		if(!m_KeyCard_Green_Config)
			m_KeyCard_Green_Config = new KeyCard_Config_Green();
		return m_KeyCard_Green_Config;
	}
}

class KeyCardMod_Blue
{
	protected static ref KeyCardMod_Blue Instance;
	
	protected static ref KeyCard_Config_Blue m_KeyCard_Blue_Config;
	
	void KeyCardMod_Blue()
	{
		if(GetGame().IsServer())
			m_KeyCard_Blue_Config = new KeyCard_Config_Blue;
		
	}
	
	static KeyCardMod_Blue GetInstance()
	{
		if(!Instance)
			Instance = new KeyCardMod_Blue();
		return Instance;
	}
	
	static void ClearInstance()
	{
		Instance = null;
	}
	
	KeyCard_Config_Blue GetConfig()
	{
		if(!m_KeyCard_Blue_Config)
			m_KeyCard_Blue_Config = new KeyCard_Config_Blue();
		return m_KeyCard_Blue_Config;
	}
}

class KeyCardMod_Purple
{
	protected static ref KeyCardMod_Purple Instance;
	
	protected static ref KeyCard_Config_Purple m_KeyCard_Purple_Config;
	
	void KeyCardMod_Purple()
	{
		if(GetGame().IsServer())
			m_KeyCard_Purple_Config = new KeyCard_Config_Purple;
		
	}
	
	static KeyCardMod_Purple GetInstance()
	{
		if(!Instance)
			Instance = new KeyCardMod_Purple();
		return Instance;
	}
	
	static void ClearInstance()
	{
		Instance = null;
	}
	
	KeyCard_Config_Purple GetConfig()
	{
		if(!m_KeyCard_Purple_Config)
			m_KeyCard_Purple_Config = new KeyCard_Config_Purple();
		return m_KeyCard_Purple_Config;
	}
}

class KeyCardMod_Red
{
	protected static ref KeyCardMod_Red Instance;
	
	protected static ref KeyCard_Config_Red m_KeyCard_Red_Config;
	
	void KeyCardMod_Red()
	{
		if(GetGame().IsServer())
			m_KeyCard_Red_Config = new KeyCard_Config_Red;
		
	}
	
	static KeyCardMod_Red GetInstance()
	{
		if(!Instance)
			Instance = new KeyCardMod_Red();
		return Instance;
	}
	
	static void ClearInstance()
	{
		Instance = null;
	}
	
	KeyCard_Config_Red GetConfig()
	{
		if(!m_KeyCard_Red_Config)
			m_KeyCard_Red_Config = new KeyCard_Config_Red();
		return m_KeyCard_Red_Config;
	}
}	