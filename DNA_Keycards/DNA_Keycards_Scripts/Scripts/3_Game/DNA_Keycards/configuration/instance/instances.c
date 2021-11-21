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
}

class DNA_Keycards_Crate_System
{
	
	protected static ref DNA_Keycards_Crate_System Instance;
	
	protected static ref KeyCard_Config_Crate_System m_KeyCard_Crate_System_Config;
	
	void DNA_Keycards_Crate_System()
	{
		if(GetGame().IsServer())
			m_KeyCard_Crate_System_Config = new KeyCard_Config_Crate_System;
		
	}
	
	static DNA_Keycards_Crate_System GetInstance()
	{
		if(!Instance)
			Instance = new DNA_Keycards_Crate_System();
		return Instance;
	}
	
	static void ClearInstance()
	{
		Instance = null;
	}
	
	KeyCard_Config_Crate_System GetConfig()
	{
		if(!m_KeyCard_Crate_System_Config)
			m_KeyCard_Crate_System_Config = new KeyCard_Config_Crate_System();
		return m_KeyCard_Crate_System_Config;
	}
}

class DNA_Keycards_Vault_System
{
	
	protected static ref DNA_Keycards_Vault_System Instance;
	
	protected static ref KeyCard_Config_Vault_System m_KeyCard_Vault_System_Config;
	
	void DNA_Keycards_Vault_System()
	{
		if(GetGame().IsServer())
			m_KeyCard_Vault_System_Config = new KeyCard_Config_Vault_System;
		
	}
	
	static DNA_Keycards_Vault_System GetInstance()
	{
		if(!Instance)
			Instance = new DNA_Keycards_Vault_System();
		return Instance;
	}
	
	static void ClearInstance()
	{
		Instance = null;
	}
	
	KeyCard_Config_Vault_System GetConfig()
	{
		if(!m_KeyCard_Vault_System_Config)
			m_KeyCard_Vault_System_Config = new KeyCard_Config_Vault_System();
		return m_KeyCard_Vault_System_Config;
	}
}

class DNA_Keycards_Base
{
	protected static ref DNA_Keycards_Base Instance;
	
	protected static ref KeyCard_Config_Base m_KeyCard_Base_Config;
	
	void DNA_Keycards_Base()
	{
		if(GetGame().IsServer())
			m_KeyCard_Base_Config = new KeyCard_Config_Base;
		
	}
	
	static DNA_Keycards_Base GetInstance()
	{
		if(!Instance)
			Instance = new DNA_Keycards_Base();
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

class DNA_Keycards_Yellow
{
	protected static ref DNA_Keycards_Yellow Instance;
	
	protected static ref KeyCard_Config_Yellow m_KeyCard_Yellow_Config;
	
	void DNA_Keycards_Yellow()
	{
		if(GetGame().IsServer())
			m_KeyCard_Yellow_Config = new KeyCard_Config_Yellow;
		
	}
	
	static DNA_Keycards_Yellow GetInstance()
	{
		if(!Instance)
			Instance = new DNA_Keycards_Yellow();
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

class DNA_Keycards_Green
{
	protected static ref DNA_Keycards_Green Instance;
	
	protected static ref KeyCard_Config_Green m_KeyCard_Green_Config;
	
	void DNA_Keycards_Green()
	{
		if(GetGame().IsServer())
			m_KeyCard_Green_Config = new KeyCard_Config_Green;
		
	}
	
	static DNA_Keycards_Green GetInstance()
	{
		if(!Instance)
			Instance = new DNA_Keycards_Green();
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

class DNA_Keycards_Blue
{
	protected static ref DNA_Keycards_Blue Instance;
	
	protected static ref KeyCard_Config_Blue m_KeyCard_Blue_Config;
	
	void DNA_Keycards_Blue()
	{
		if(GetGame().IsServer())
			m_KeyCard_Blue_Config = new KeyCard_Config_Blue;
		
	}
	
	static DNA_Keycards_Blue GetInstance()
	{
		if(!Instance)
			Instance = new DNA_Keycards_Blue();
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

class DNA_Keycards_Purple
{
	protected static ref DNA_Keycards_Purple Instance;
	
	protected static ref KeyCard_Config_Purple m_KeyCard_Purple_Config;
	
	void DNA_Keycards_Purple()
	{
		if(GetGame().IsServer())
			m_KeyCard_Purple_Config = new KeyCard_Config_Purple;
		
	}
	
	static DNA_Keycards_Purple GetInstance()
	{
		if(!Instance)
			Instance = new DNA_Keycards_Purple();
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

class DNA_Keycards_Red
{
	protected static ref DNA_Keycards_Red Instance;
	
	protected static ref KeyCard_Config_Red m_KeyCard_Red_Config;
	
	void DNA_Keycards_Red()
	{
		if(GetGame().IsServer())
			m_KeyCard_Red_Config = new KeyCard_Config_Red;
		
	}
	
	static DNA_Keycards_Red GetInstance()
	{
		if(!Instance)
			Instance = new DNA_Keycards_Red();
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