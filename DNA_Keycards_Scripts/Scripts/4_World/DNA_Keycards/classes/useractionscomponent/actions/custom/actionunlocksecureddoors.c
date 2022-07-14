class ActionUnlockSecuredDoors: ActionInteractBase
{
	void ActionUnlockSecuredDoors()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_HUDCursorIcon = CursorIcons.OpenDoors;
	}

	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTCursor;
	}

	override string GetText()
	{
		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		if(player)
		{
			if(!player.GetItemInHands())
				return "Remove Card";
		}
		return "Insert Card";
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if( !target ) return false;
		if(player.IsHolding()) return false;
		if(target.GetComponentIndex() == 0) return false;
		
		Object target_object = Object.Cast(target.GetObject());
		
		DNA_Lockout_ColourBase lockout;
		string lockoutType;
		
		if(item)
		{
			if(CastTo(lockout, target_object))
			{
				lockoutType = lockout.GetType();
				if(!lockout.IsAreaLocked()) return false;
					
				return item.GetType() == "DNA_KeyCard" + lockoutType.SubstringInverted(lockoutType, 0 ,11) && !lockout.IsCardInserted();
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
	
	override bool Can(PlayerBase player, ActionTarget target, ItemBase item)
	{
		return true;
	}
	
	override void OnExecuteServer( ActionData action_data )
	{
		DNA_Lockout_ColourBase lockout;
		
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
				lockout.NotifyPlayers();
				lockout.SoundAlarm();
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

	override void OnExecuteClient( ActionData action_data )
	{
		Object target_object = action_data.m_Target.GetObject();
		DNA_Lockout_ColourBase lockout;
		
		if(CastTo(lockout, target_object))
		{
			vector pos = lockout.GetPosition();
			if(lockout.IsCardInserted())
			{
				DNA_Sounds.SoundKCCardRemovePlay(pos);
			}
			else
			{
				DNA_Sounds.SoundKCCardScanPlay(pos);
			}
		}
	}
};