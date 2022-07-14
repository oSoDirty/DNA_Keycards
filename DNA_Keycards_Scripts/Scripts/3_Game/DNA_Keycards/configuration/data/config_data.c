class KeyCard_ConfigData_Main_System
{
	protected ref array<ref DNA_Config_Version> m_DNAConfig_Version;
	protected ref array<ref DNA_Config_Main_System> m_DNAConfig_Main_System;
	protected ref array<ref DNA_Yellow_Crate_Locations> m_DNAYellow_Crate_Locations;
	protected ref array<ref DNA_Green_Crate_Locations> m_DNAGreen_Crate_Locations;
	protected ref array<ref DNA_Blue_Crate_Locations> m_DNABlue_Crate_Locations;
	protected ref array<ref DNA_Purple_Crate_Locations> m_DNAPurple_Crate_Locations;
	protected ref array<ref DNA_Red_Crate_Locations> m_DNARed_Crate_Locations;
	protected ref array<ref DNA_Yellow_Strongroom_Locations> m_DNAYellow_Strongroom_Locations;
	protected ref array<ref DNA_Green_Strongroom_Locations> m_DNAGreen_Strongroom_Locations;
	protected ref array<ref DNA_Blue_Strongroom_Locations> m_DNABlue_Strongroom_Locations;
	protected ref array<ref DNA_Purple_Strongroom_Locations> m_DNAPurple_Strongroom_Locations;
	protected ref array<ref DNA_Red_Strongroom_Locations> m_DNARed_Strongroom_Locations;
	
	void KeyCard_ConfigData_Main_System()
	{
		m_DNAConfig_Version = new array<ref DNA_Config_Version>;
		m_DNAConfig_Main_System = new array<ref DNA_Config_Main_System>;
		m_DNAYellow_Crate_Locations = new array<ref DNA_Yellow_Crate_Locations>;
		m_DNAGreen_Crate_Locations = new array<ref DNA_Green_Crate_Locations>;
		m_DNABlue_Crate_Locations = new array<ref DNA_Blue_Crate_Locations>;
		m_DNAPurple_Crate_Locations = new array<ref DNA_Purple_Crate_Locations>;
		m_DNARed_Crate_Locations = new array<ref DNA_Red_Crate_Locations>;
		m_DNAYellow_Strongroom_Locations = new array<ref DNA_Yellow_Strongroom_Locations>;
		m_DNAGreen_Strongroom_Locations = new array<ref DNA_Green_Strongroom_Locations>;
		m_DNABlue_Strongroom_Locations = new array<ref DNA_Blue_Strongroom_Locations>;
		m_DNAPurple_Strongroom_Locations = new array<ref DNA_Purple_Strongroom_Locations>;
		m_DNARed_Strongroom_Locations = new array<ref DNA_Red_Strongroom_Locations>;
	}
	
	array<ref DNA_Config_Version> GetVersionArray()
	{
		return m_DNAConfig_Version;
	}
	
	array<ref DNA_Config_Main_System> GetSystemArray()
	{
		return m_DNAConfig_Main_System;
	}
	
	array<ref DNA_Yellow_Crate_Locations> GetLocationsYArray()
	{
		return m_DNAYellow_Crate_Locations;
	}
	
	array<ref DNA_Green_Crate_Locations> GetLocationsGArray()
	{
		return m_DNAGreen_Crate_Locations;
	}
	
	array<ref DNA_Blue_Crate_Locations> GetLocationsBArray()
	{
		return m_DNABlue_Crate_Locations;
	}
	
	array<ref DNA_Purple_Crate_Locations> GetLocationsPArray()
	{
		return m_DNAPurple_Crate_Locations;
	}
	
	array<ref DNA_Red_Crate_Locations> GetLocationsRArray()
	{
		return m_DNARed_Crate_Locations;
	}
	
	array<ref DNA_Yellow_Strongroom_Locations> GetStrongroomLocationsYArray()
	{
		return m_DNAYellow_Strongroom_Locations;
	}
	
	array<ref DNA_Green_Strongroom_Locations> GetStrongroomLocationsGArray()
	{
		return m_DNAGreen_Strongroom_Locations;
	}
	
	array<ref DNA_Blue_Strongroom_Locations> GetStrongroomLocationsBArray()
	{
		return m_DNABlue_Strongroom_Locations;
	}
	
	array<ref DNA_Purple_Strongroom_Locations> GetStrongroomLocationsPArray()
	{
		return m_DNAPurple_Strongroom_Locations;
	}
	
	array<ref DNA_Red_Strongroom_Locations> GetStrongroomLocationsRArray()
	{
		return m_DNARed_Strongroom_Locations;
	}
}

class KeyCard_ConfigData_Container_System
{
	protected ref array<ref DNA_Config_Container_System> m_DNAConfig_Container_System;
	
	void KeyCard_ConfigData_Container_System()
	{
		m_DNAConfig_Container_System = new array<ref DNA_Config_Container_System>;
	}
	
	array<ref DNA_Config_Container_System> GetSystemArray()
	{
		return m_DNAConfig_Container_System;
	}
}

class KeyCard_ConfigData_Mob_System
{
	protected ref array<ref DNA_Config_Mob_System> m_DNAConfig_Mob_System;
	
	void KeyCard_ConfigData_Mob_System()
	{
		m_DNAConfig_Mob_System = new array<ref DNA_Config_Mob_System>;
	}
	
	array<ref DNA_Config_Mob_System> GetSystemArray()
	{
		return m_DNAConfig_Mob_System;
	}
}

class KeyCard_ConfigData_Loot
{
	protected ref array<ref DNA_Config_Loot> m_DNAConfig_Loot;
	
	void KeyCard_ConfigData_Loot()
	{
		m_DNAConfig_Loot = new array<ref DNA_Config_Loot>;
	}
	
	array<ref DNA_Config_Loot> GetLootArray()
	{
		return m_DNAConfig_Loot;
	}
}

class KeyCard_ConfigData_Clothing
{
	protected ref array<ref DNA_Config_Clothing> m_DNAConfig_Clothing;
	
	void KeyCard_ConfigData_Clothing()
	{
		m_DNAConfig_Clothing = new array<ref DNA_Config_Clothing>;
	}
	
	array<ref DNA_Config_Clothing> GetClothingArray()
	{
		return m_DNAConfig_Clothing;
	}
}

class KeyCard_ConfigData_Weapons
{
	protected ref array<ref DNA_Config_Weapons> m_DNAConfig_Weapons;
	
	void KeyCard_ConfigData_Weapons()
	{
		m_DNAConfig_Weapons = new array<ref DNA_Config_Weapons>;
	}
	
	array<ref DNA_Config_Weapons> GetWeaponsArray()
	{
		return m_DNAConfig_Weapons;
	}
}

class DNA_Crafting_Data
{
	protected ref array<ref DNA_Crafting_Defines> m_DNA_Crafting_Defines;
	
	void DNA_Crafting_Data()
	{
		m_DNA_Crafting_Defines = new array<ref DNA_Crafting_Defines>;
	}
	
	array<ref DNA_Crafting_Defines> GetRecipeArray()
	{
		return m_DNA_Crafting_Defines;
	}
}