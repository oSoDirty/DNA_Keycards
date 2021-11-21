class KC_KeyCard_ColourBase: ItemBase
{	
	protected ref array<ref KCM_Config_Main_System> kcm_MainSystemConfig;
	
	void KC_KeyCard_ColourBase()
	{
		kcm_MainSystemConfig = DNA_Keycards_Main_System.GetInstance().GetConfig().GetConfigData().GetSystemArray();
		if(GetGame().IsServer())
			SetInitialUsageAllotment();
	}
	
	void SetInitialUsageAllotment()
	{
		if(kcm_MainSystemConfig)
		{
			float remainingUses;
			int configIndex;
			remainingUses = GetQuantity();
			if(GetQuantity() == 0)
			{
				switch(GetType())
				{
					case "KC_KeyCard_Yellow":
						configIndex = 12;
						break;
					case "KC_KeyCard_Green":
						configIndex = 13;
						break;
					case "KC_KeyCard_Blue":
						configIndex = 14;
						break;
					case "KC_KeyCard_Purple":
						configIndex = 15;
						break;
					case "KC_KeyCard_Red":
						configIndex = 16;
						break;
				}
				SetQuantity(GetCfgAllotment(configIndex));
			}
		}
	}
	
	int GetRemaingUses()
	{
		return (int)GetQuantity();
	}
	
	override string GetDisplayName()
	{
		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		int remainingUses = GetRemaingUses();
		if(player && remainingUses)
		{
			if (remainingUses > 1)
				return super.GetDisplayName() + ": " + remainingUses + " Uses Remaining";
			
			if (remainingUses == 1)
				return super.GetDisplayName() + ": 1 Use Remaining";
		}
		
		return super.GetDisplayName();
	}
	
	float GetCfgAllotment(int configIndex)
	{
		int qty = kcm_MainSystemConfig.Get(configIndex).GetSystemSetting();
		return (float)qty;
	}
	
	bool IsMatchingTier(string typeName)
	{
		return GetType() == "KC_KeyCard" + typeName.SubstringInverted(typeName, 0, 8);
	}
}

class KC_KeyCard_Yellow: KC_KeyCard_ColourBase {}
class KC_KeyCard_Green: KC_KeyCard_ColourBase {}
class KC_KeyCard_Blue: KC_KeyCard_ColourBase {}
class KC_KeyCard_Purple: KC_KeyCard_ColourBase {}
class KC_KeyCard_Red: KC_KeyCard_ColourBase {}
class KC_KeyCard_Error: ItemBase {} // maybe change in future, but probably not? 