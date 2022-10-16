class ActionUnlockOneWayDoors: ActionUnlockSecuredDoors
{
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if( !target ) return false;
		if(player.IsHolding()) return false;
		if(target.GetComponentIndex() == 0) return false;
		
		Object target_object = Object.Cast(target.GetObject());
		
		DNA_Lockout_OneWayDoor_Locked_ColourBase lockout;
		string lockoutType;
		
		if(item)
		{
			if(CastTo(lockout, target_object))
			{
				lockoutType = lockout.GetType();
				if(!lockout.IsAreaLocked()) return false;
					
				return item.GetType() == "DNA_KeyCard" + lockoutType.SubstringInverted(lockoutType, 0 ,29) && !lockout.IsCardInserted();
			}
		}
		else
		{
			if(CastTo(lockout, target_object))
			{
				if(!lockout.IsAreaLocked()) return false;
				
				return lockout.IsCardInserted();
			}
		}
		
		return false;
	}
	
	override void OnExecuteServer( ActionData action_data )
	{
		DNA_Lockout_OneWayDoor_Locked_ColourBase lockout;
		
		Object target_object = Object.Cast(action_data.m_Target.GetObject());
		ItemBase key = ItemBase.Cast(action_data.m_MainItem);
		PlayerBase player;
		if(!CastTo(player, action_data.m_Player)) return;
		
		if(CastTo(lockout, target_object))
		{
			string lockoutType = lockout.GetType();
			if(lockout.IsCardInserted())
			{
				lockout.ReturnCardToPlayer(player);
				string tier;
				GetGame().ConfigGetText("CfgVehicles " + lockout.GetType() + " tier", tier);
				tier.ToLower();
				DNA_Logging.LogActivity("At " + DNA_Logging.GetTime() + " - " + DNA_Logging.GetPlayerInfo(player) + " has opened a " + tier + " tier lockout door.");
			}
			else
			{
				player.SetHoldState(true);
				lockout.TakeCardToSlot(player);
				player.DelayedMsg(null);
			}
		}
	}
}