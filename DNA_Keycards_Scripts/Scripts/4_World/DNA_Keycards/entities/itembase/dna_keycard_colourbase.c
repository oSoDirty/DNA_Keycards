class DNA_KeyCard_ColourBase: ItemBase
{	
	protected ref array<ref DNA_Config_Main_System> dna_MainSystemConfig;
	
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

class DNA_KeyCard_Yellow: DNA_KeyCard_ColourBase {}
class DNA_KeyCard_Green: DNA_KeyCard_ColourBase {}
class DNA_KeyCard_Blue: DNA_KeyCard_ColourBase {}
class DNA_KeyCard_Purple: DNA_KeyCard_ColourBase {}
class DNA_KeyCard_Red: DNA_KeyCard_ColourBase {}
class DNA_KeyCard_Error: ItemBase {}