class ActionActivateKeycard: ActionSingleUseBase
{
	
	override void CreateConditionComponents()  
	{
		m_ConditionTarget = new CCTNone;
	}

	override string GetText()
	{
		return "Activate";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		return true;
	}
	
	override void OnExecuteServer( ActionData action_data )
	{
		PlayerBase player = action_data.m_Player;
		ItemBase item = action_data.m_MainItem;
		if(player && item)
		{
			DNA_KeyCard_InactiveBase inactiveCard;
			if(CastTo(inactiveCard, item))
			{
				string switchType = inactiveCard.GetSwitchType();
				if(switchType)
				{
					
					
					DNA_KeyCard_ColourBase activeCard;
					activeCard = DNA_KeyCard_ColourBase.Cast(GetGame().CreateObject(switchType, player.GetPosition() + "0.0 -0.2 0.0"));
					if(activeCard)
					{	GetGame().ObjectDelete(inactiveCard);
						activeCard.SetInitialUsageAllotment();
						player.TakeEntityToHandsImpl(InventoryMode.SERVER, activeCard);
					}
				}
			}
		}
	}
}