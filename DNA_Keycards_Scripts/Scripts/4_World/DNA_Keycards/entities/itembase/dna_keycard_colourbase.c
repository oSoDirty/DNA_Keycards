class DNA_KeyCard_ColourBase: ItemBase
{	
	protected ref array<ref DNA_Config_Main_System> dna_MainSystemConfig;
	
	string dna_Tier;
	
	void DNA_KeyCard_ColourBase()
	{
		if(GetGame().IsDedicatedServer())
		{
			dna_MainSystemConfig = DNA_Keycards_Main_System.GetInstance().GetConfig().GetConfigData().GetSystemArray();
		}
	}
	
	void SetInitialUsageAllotment()
	{
		if(dna_MainSystemConfig)
		{
			int maxAllowedUses;
			int configIndex;
			
			switch(GetType())
			{
				case "DNA_KeyCard_Yellow":
					configIndex = 12;
					break;
				case "DNA_KeyCard_Green":
					configIndex = 13;
					break;
				case "DNA_KeyCard_Blue":
					configIndex = 14;
					break;
				case "DNA_KeyCard_Purple":
					configIndex = 15;
					break;
				case "DNA_KeyCard_Red":
					configIndex = 16;
					break;
			}
			
			maxAllowedUses = GetCfgAllotment(configIndex);
			
			if(maxAllowedUses > 10)
				maxAllowedUses = 10;

			SetRemainingUses(maxAllowedUses);
		}
	}
	
	override string GetDisplayName()
	{
		return super.GetDisplayName() + " - Remaining Uses: " + GetRemainingUses();
	}
	
	int GetRemainingUses()
	{
		return (int)Math.Round(GetQuantity());
	}
	
	void SetRemainingUses(int remainingUses)
	{
		if(remainingUses)
		{
			float uses = remainingUses;
			SetQuantity(uses);
		}
		
	}
	
	int GetCfgAllotment(int configIndex)
	{
		return dna_MainSystemConfig.Get(configIndex).GetSystemSetting();
	}
}

class DNA_KeyCard_Yellow: DNA_KeyCard_ColourBase
{
	void DNA_KeyCard_()
	{
		dna_Tier = "Yellow";
	}
}

class DNA_KeyCard_Green: DNA_KeyCard_ColourBase
{
	void DNA_KeyCard_()
	{
		dna_Tier = "Green";
	}
}

class DNA_KeyCard_Blue: DNA_KeyCard_ColourBase
{
	void DNA_KeyCard_()
	{
		dna_Tier = "Blue";
	}
}

class DNA_KeyCard_Purple: DNA_KeyCard_ColourBase
{
	void DNA_KeyCard_()
	{
		dna_Tier = "Purple";
	}
}

class DNA_KeyCard_Red: DNA_KeyCard_ColourBase
{
	void DNA_KeyCard_()
	{
		dna_Tier = "Red";
	}

}
class DNA_KeyCard_Orange: DNA_KeyCard_ColourBase
{
	void DNA_KeyCard_()
	{
		dna_Tier = "Orange";
	}
	
	override string GetDisplayName()
	{
		return ConfigGetString("displayName") + " - Remaining Uses: 1";
	}
}

class DNA_KeyCard_Program_Base: ItemBase
{
	string GetSwitchClass()
	{
		return ConfigGetString("switchClass");
	}
	
	string GetInsertClass()
	{
		return ConfigGetString("insertClass");
	}
	
	string GetRemoveClass()
	{
		return ConfigGetString("removeClass");
	}
	bool HasChip()
	{
		return true;
	}
}

class DNA_KeyCard_Program_Base_BL: DNA_KeyCard_Program_Base {}

class DNA_KeyCard_Yellow_Unprogrammed: DNA_KeyCard_Program_Base_BL {}
class DNA_KeyCard_Green_Unprogrammed: DNA_KeyCard_Program_Base_BL {}
class DNA_KeyCard_Blue_Unprogrammed: DNA_KeyCard_Program_Base_BL {}
class DNA_KeyCard_Purple_Unprogrammed: DNA_KeyCard_Program_Base_BL {}
class DNA_KeyCard_Red_Unprogrammed: DNA_KeyCard_Program_Base_BL {}
class DNA_KeyCard_Orange_Unprogrammed: DNA_KeyCard_Program_Base_BL {}

class DNA_KeyCard_Programmed: DNA_KeyCard_Program_Base_BL{}

class DNA_KeyCard_Yellow_Programmed_DoNotUse: DNA_KeyCard_Programmed {}
class DNA_KeyCard_Green_Programmed_DoNotUse: DNA_KeyCard_Programmed {}
class DNA_KeyCard_Blue_Programmed_DoNotUse: DNA_KeyCard_Programmed {}
class DNA_KeyCard_Purple_Programmed_DoNotUse: DNA_KeyCard_Programmed {}
class DNA_KeyCard_Red_Programmed_DoNotUse: DNA_KeyCard_Programmed {}
class DNA_KeyCard_Orange_Programmed_DoNotUse: DNA_KeyCard_Programmed {}

class DNA_KeyCard_Program_Base_ER: DNA_KeyCard_Program_Base {}

class DNA_KeyCard_Error: DNA_KeyCard_Program_Base_ER
{
	bool HasChip()
	{
		return false;
	}
}
class DNA_KeyCard_Blank: DNA_KeyCard_Program_Base_ER
{
	bool HasChip()
	{
		return false;
	}
}
class DNA_KeyCard_Yellow_Unprogrammed_DoNotUse: DNA_KeyCard_Program_Base_ER {}
class DNA_KeyCard_Green_Unprogrammed_DoNotUse: DNA_KeyCard_Program_Base_ER {}
class DNA_KeyCard_Blue_Unprogrammed_DoNotUse: DNA_KeyCard_Program_Base_ER {}
class DNA_KeyCard_Purple_Unprogrammed_DoNotUse: DNA_KeyCard_Program_Base_ER {}
class DNA_KeyCard_Red_Unprogrammed_DoNotUse: DNA_KeyCard_Program_Base_ER {}
class DNA_KeyCard_Orange_Unprogrammed_DoNotUse: DNA_KeyCard_Program_Base_ER {}