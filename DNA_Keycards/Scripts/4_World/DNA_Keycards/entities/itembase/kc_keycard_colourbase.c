class KC_KeyCard_ColourBase: ItemBase
{
	protected int kcm_RemainingUses;
	
	protected ref array<ref KCM_Config_System> kcm_SystemConfig;
	
	void KC_KeyCard_ColourBase()
	{
		RegisterNetSyncVariableInt("kcm_RemainingUses", 1, int.MAX);
		kcm_SystemConfig = DNA_Keycards_System.GetInstance().GetConfig().GetConfigData().GetSystemArray();
		SetInitialUsageAllotment();
	}
	
	void SetInitialUsageAllotment()
	{
		if(kcm_SystemConfig)
		{
			float remainingUses;
			int configIndex;
			remainingUses = GetQuantity();
			if(GetQuantity() == 0)
			{
				switch(GetType())
				{
					case "KC_KeyCard_Yellow":
						configIndex = 81;
						break;
					case "KC_KeyCard_Green":
						configIndex = 82;
						break;
					case "KC_KeyCard_Blue":
						configIndex = 83;
						break;
					case "KC_KeyCard_Purple":
						configIndex = 84;
						break;
					case "KC_KeyCard_Red":
						configIndex = 85;
						break;
				}
				SetQuantity(GetRemQTY(configIndex));
			}
		}
	}
	
	/*void Downgrade(string type)
	{
		switch(type()
		{
			case "KC_KeyCard_Green":
				qty = m_IngredientsToBeDeleted.Get(i).GetQuantity();
				type = "KC_KeyCard_Yellow";
				break;
				
			case "KC_KeyCard_Blue":    
				qty = m_IngredientsToBeDeleted.Get(i).GetQuantity();
				type = "KC_KeyCard_Green";        
				break;
				
			case "KC_KeyCard_Purple":
				qty = m_IngredientsToBeDeleted.Get(i).GetQuantity();
				type = "KC_KeyCard_Blue";            
				break;    
				
			case "KC_KeyCard_Red":
				qty = m_IngredientsToBeDeleted.Get(i).GetQuantity();
				type = "KC_KeyCard_Purple";            
				break;
				
			default:
			type = "";
				break;
		}
		if(type && type != "")
		{
			card = KC_KeyCard_ColourBase.Cast(player.GetHumanInventory().CreateInHands(type));
			if(card)
				card.SetQuantity(qty + 1); // add some config shit
		}
	}*/
	
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
	
	float GetRemQTY(int configIndex)
	{
		int qty = kcm_SystemConfig.Get(configIndex).GetSystemSetting();
		return (float)qty;
	}
	
	bool IsMatchingTier(string typeName)
	{
		return GetType() == "KC_KeyCard" + typeName.SubstringInverted(typeName, 0, 8);
	}

	override void OnStoreSave(ParamsWriteContext ctx)
	{
		super.OnStoreSave(ctx);

		ctx.Write(kcm_RemainingUses);
	}

	override bool OnStoreLoad(ParamsReadContext ctx, int version)
	{
		if (!super.OnStoreLoad(ctx, version))
			return false;

		if (!ctx.Read(kcm_RemainingUses))
			return false;

		return true;
	}
}

class KC_KeyCard_Yellow: KC_KeyCard_ColourBase {}
class KC_KeyCard_Green: KC_KeyCard_ColourBase {}
class KC_KeyCard_Blue: KC_KeyCard_ColourBase {}
class KC_KeyCard_Purple: KC_KeyCard_ColourBase {}
class KC_KeyCard_Red: KC_KeyCard_ColourBase {}
class KC_KeyCard_Error: ItemBase {} // maybe change in future, but probably not? 