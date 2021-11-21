class KeyCard_ConfigData_Main_System
{
	protected ref array<ref KCM_Config_Version> m_KCMConfig_Version;
	protected ref array<ref KCM_Config_Main_System> m_KCMConfig_Main_System;
	protected ref array<ref KCM_Yellow_Crate_Locations> m_KCMYellow_Crate_Locations;
	protected ref array<ref KCM_Green_Crate_Locations> m_KCMGreen_Crate_Locations;
	protected ref array<ref KCM_Blue_Crate_Locations> m_KCMBlue_Crate_Locations;
	protected ref array<ref KCM_Purple_Crate_Locations> m_KCMPurple_Crate_Locations;
	protected ref array<ref KCM_Red_Crate_Locations> m_KCMRed_Crate_Locations;
	protected ref array<ref KCM_Yellow_Vault_Locations> m_KCMYellow_Vault_Locations;
	protected ref array<ref KCM_Green_Vault_Locations> m_KCMGreen_Vault_Locations;
	protected ref array<ref KCM_Blue_Vault_Locations> m_KCMBlue_Vault_Locations;
	protected ref array<ref KCM_Purple_Vault_Locations> m_KCMPurple_Vault_Locations;
	protected ref array<ref KCM_Red_Vault_Locations> m_KCMRed_Vault_Locations;
	
	void KeyCard_ConfigData_Main_System()
	{
		m_KCMConfig_Version = new array<ref KCM_Config_Version>;
		m_KCMConfig_Main_System = new array<ref KCM_Config_Main_System>;
		m_KCMYellow_Crate_Locations = new array<ref KCM_Yellow_Crate_Locations>;
		m_KCMGreen_Crate_Locations = new array<ref KCM_Green_Crate_Locations>;
		m_KCMBlue_Crate_Locations = new array<ref KCM_Blue_Crate_Locations>;
		m_KCMPurple_Crate_Locations = new array<ref KCM_Purple_Crate_Locations>;
		m_KCMRed_Crate_Locations = new array<ref KCM_Red_Crate_Locations>;
		m_KCMYellow_Vault_Locations = new array<ref KCM_Yellow_Vault_Locations>;
		m_KCMGreen_Vault_Locations = new array<ref KCM_Green_Vault_Locations>;
		m_KCMBlue_Vault_Locations = new array<ref KCM_Blue_Vault_Locations>;
		m_KCMPurple_Vault_Locations = new array<ref KCM_Purple_Vault_Locations>;
		m_KCMRed_Vault_Locations = new array<ref KCM_Red_Vault_Locations>;
	}
	
	array<ref KCM_Config_Version> GetVersionArray()
	{
		return m_KCMConfig_Version;
	}
	
	array<ref KCM_Config_Main_System> GetSystemArray()
	{
		return m_KCMConfig_Main_System;
	}
	
	array<ref KCM_Yellow_Crate_Locations> GetLocationsYArray()
	{
		return m_KCMYellow_Crate_Locations;
	}
	
	array<ref KCM_Green_Crate_Locations> GetLocationsGArray()
	{
		return m_KCMGreen_Crate_Locations;
	}
	
	array<ref KCM_Blue_Crate_Locations> GetLocationsBArray()
	{
		return m_KCMBlue_Crate_Locations;
	}
	
	array<ref KCM_Purple_Crate_Locations> GetLocationsPArray()
	{
		return m_KCMPurple_Crate_Locations;
	}
	
	array<ref KCM_Red_Crate_Locations> GetLocationsRArray()
	{
		return m_KCMRed_Crate_Locations;
	}
	
	array<ref KCM_Yellow_Vault_Locations> GetVaultLocationsYArray()
	{
		return m_KCMYellow_Vault_Locations;
	}
	
	array<ref KCM_Green_Vault_Locations> GetVaultLocationsGArray()
	{
		return m_KCMGreen_Vault_Locations;
	}
	
	array<ref KCM_Blue_Vault_Locations> GetVaultLocationsBArray()
	{
		return m_KCMBlue_Vault_Locations;
	}
	
	array<ref KCM_Purple_Vault_Locations> GetVaultLocationsPArray()
	{
		return m_KCMPurple_Vault_Locations;
	}
	
	array<ref KCM_Red_Vault_Locations> GetVaultLocationsRArray()
	{
		return m_KCMRed_Vault_Locations;
	}
}

class KeyCard_ConfigData_Crate_System
{
	protected ref array<ref KCM_Config_Crate_System> m_KCMConfig_Crate_System;
	
	void KeyCard_ConfigData_Crate_System()
	{
		m_KCMConfig_Crate_System = new array<ref KCM_Config_Crate_System>;
	}
	
	array<ref KCM_Config_Crate_System> GetSystemArray()
	{
		return m_KCMConfig_Crate_System;
	}
}

class KeyCard_ConfigData_Vault_System
{
	protected ref array<ref KCM_Config_Vault_System> m_KCMConfig_Vault_System;
	
	void KeyCard_ConfigData_Vault_System()
	{
		m_KCMConfig_Vault_System = new array<ref KCM_Config_Vault_System>;
	}
	
	array<ref KCM_Config_Vault_System> GetSystemArray()
	{
		return m_KCMConfig_Vault_System;
	}
}
	
class KeyCard_ConfigData_Base
{
	protected ref array<ref KCM_SideArm> m_KCMSideArm;
	protected ref array<ref KCM_Food> m_KCMFood;
	protected ref array<ref KCM_Drink> m_KCMDrink;
	protected ref array<ref KCM_Tools> m_KCMTools;
	protected ref array<ref KCM_Medical> m_KCMMedical;
	protected ref array<ref KCM_BuildingMats> m_KCMBuildingMats;
	protected ref array<ref KCM_Valuables> m_KCMValuables;
	protected ref array<ref Base_Variables> m_KCMBaseVars;
	
	void KeyCard_ConfigData_Base()
	{
		m_KCMSideArm = new array<ref KCM_SideArm>;
		m_KCMFood = new array<ref KCM_Food>;
		m_KCMDrink = new array<ref KCM_Drink>;
		m_KCMTools = new array<ref KCM_Tools>;
		m_KCMMedical = new array<ref KCM_Medical>;
		m_KCMBuildingMats = new array<ref KCM_BuildingMats>;
		m_KCMValuables = new array<ref KCM_Valuables>;
		m_KCMBaseVars = new array<ref Base_Variables>;
	}
	
	array<ref KCM_SideArm> GetSideArmArray()
	{
		return m_KCMSideArm;
	}
	
	array<ref KCM_Food> GetFoodArray()
	{
		return m_KCMFood;
	}
	
	array<ref KCM_Drink> GetDrinkArray()
	{
		return m_KCMDrink;
	}
	
	array<ref KCM_Tools> GetToolsArray()
	{
		return m_KCMTools;
	}
	
	array<ref KCM_Medical> GetMedicalArray()
	{
		return m_KCMMedical;
	}
	
	array<ref KCM_BuildingMats> GetBuildingArray()
	{
		return m_KCMBuildingMats;
	}
	
	array<ref KCM_Valuables> GetValuablesArray()
	{
		return m_KCMValuables;
	}
	
	array<ref Base_Variables> GetBaseVarsArray()
	{
		return m_KCMBaseVars;
	}
}
	
class KeyCard_ConfigData_Yellow
{
	protected ref array<ref KCM_Weapons_Yellow> m_KCMWeaponArray_Yellow;
	protected ref array<ref Weapon_Variables_Yellow> m_KCMWeaponVarsYellow;
	protected ref array<ref KCM_Clothing_Y> m_KCMClothingY;
	
	void KeyCard_ConfigData_Yellow()
	{
		m_KCMWeaponArray_Yellow = new array<ref KCM_Weapons_Yellow>;
		m_KCMWeaponVarsYellow = new array<ref Weapon_Variables_Yellow>;
		m_KCMClothingY = new array<ref KCM_Clothing_Y>;
	}
	
	array<ref KCM_Weapons_Yellow> GetWeaponsArray()
	{
		return m_KCMWeaponArray_Yellow;
	}
	
	array<ref Weapon_Variables_Yellow> GetWeaponVarsArray()
	{
		return m_KCMWeaponVarsYellow;
	}
	
	array<ref KCM_Clothing_Y> GetClothingArray()
	{
		return m_KCMClothingY;
	}
}
	
class KeyCard_ConfigData_Green
{
	protected ref array<ref KCM_Weapons_Green> m_KCMWeaponArray_Green;
	protected ref array<ref Weapon_Variables_Green> m_KCMWeaponVarsGreen;
	protected ref array<ref KCM_Clothing_G> m_KCMClothingG;
	
	void KeyCard_ConfigData_Green()
	{
		m_KCMWeaponArray_Green = new array<ref KCM_Weapons_Green>;
		m_KCMWeaponVarsGreen = new array<ref Weapon_Variables_Green>;
		m_KCMClothingG = new array<ref KCM_Clothing_G>;
	}
	
	array<ref KCM_Weapons_Green> GetWeaponsArray()
	{
		return m_KCMWeaponArray_Green;
	}
	
	array<ref Weapon_Variables_Green> GetWeaponVarsArray()
	{
		return m_KCMWeaponVarsGreen;
	}
	
	array<ref KCM_Clothing_G> GetClothingArray()
	{
		return m_KCMClothingG;
	}
}
	
class KeyCard_ConfigData_Blue
{
	protected ref array<ref KCM_Weapons_Blue> m_KCMWeaponArray_Blue;
	protected ref array<ref Weapon_Variables_Blue> m_KCMWeaponVarsBlue;
	protected ref array<ref KCM_Clothing_B> m_KCMClothingB;
	
	void KeyCard_ConfigData_Blue()
	{
		m_KCMWeaponArray_Blue = new array<ref KCM_Weapons_Blue>;
		m_KCMWeaponVarsBlue = new array<ref Weapon_Variables_Blue>;
		m_KCMClothingB = new array<ref KCM_Clothing_B>;
	}
	
	array<ref KCM_Weapons_Blue> GetWeaponsArray()
	{
		return m_KCMWeaponArray_Blue;
	}
	
	array<ref Weapon_Variables_Blue> GetWeaponVarsArray()
	{
		return m_KCMWeaponVarsBlue;
	}
	
	array<ref KCM_Clothing_B> GetClothingArray()
	{
		return m_KCMClothingB;
	}
}
	
class KeyCard_ConfigData_Purple
{
	protected ref array<ref KCM_Weapons_Purple> m_KCMWeaponArray_Purple;
	protected ref array<ref Weapon_Variables_Purple> m_KCMWeaponVarsPurple;
	protected ref array<ref KCM_Clothing_P> m_KCMClothingP;
	
	void KeyCard_ConfigData_Purple()
	{
		m_KCMWeaponArray_Purple = new array<ref KCM_Weapons_Purple>;
		m_KCMWeaponVarsPurple = new array<ref Weapon_Variables_Purple>;
		m_KCMClothingP = new array<ref KCM_Clothing_P>;
	}
	
	array<ref KCM_Weapons_Purple> GetWeaponsArray()
	{
		return m_KCMWeaponArray_Purple;
	}
	
	array<ref Weapon_Variables_Purple> GetWeaponVarsArray()
	{
		return m_KCMWeaponVarsPurple;
	}
	
	array<ref KCM_Clothing_P> GetClothingArray()
	{
		return m_KCMClothingP;
	}
}
	
class KeyCard_ConfigData_Red
{
	protected ref array<ref KCM_Weapons_Red> m_KCMWeaponArray_Red;
	protected ref array<ref Weapon_Variables_Red> m_KCMWeaponVarsRed;
	protected ref array<ref KCM_Clothing_R> m_KCMClothingR;
	
	void KeyCard_ConfigData_Red()
	{
		m_KCMWeaponArray_Red = new array<ref KCM_Weapons_Red>;
		m_KCMWeaponVarsRed = new array<ref Weapon_Variables_Red>;
		m_KCMClothingR = new array<ref KCM_Clothing_R>;
	}
	
	array<ref KCM_Weapons_Red> GetWeaponsArray()
	{
		return m_KCMWeaponArray_Red;
	}
	
	array<ref Weapon_Variables_Red> GetWeaponVarsArray()
	{
		return m_KCMWeaponVarsRed;
	}
	
	array<ref KCM_Clothing_R> GetClothingArray()
	{
		return m_KCMClothingR;
	}
}