class ActionUnlockWarpDoors: ActionInteractBase
{
	void ActionUnlockWarpDoors()
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
		
		DNA_WarpDoor_NoLock_ColourBase warpDoor;
		string warpDoorType;
		
		if(item)
		{
			if(CastTo(warpDoor, target_object))
			{
				warpDoorType = warpDoor.GetType();
				if(!warpDoor.IsAreaLocked()) return false;
					
				return item.GetType() == "DNA_KeyCard" + warpDoorType.SubstringInverted(warpDoorType, 0 ,14) && !warpDoor.IsCardInserted();
			}
		}
		else
		{
			if(CastTo(warpDoor, target_object))
			{
				if(!warpDoor.IsAreaLocked()) return false;
				
				return warpDoor.IsCardInserted();
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
		DNA_WarpDoor_ColourBase warpDoor;
		
		Object target_object = Object.Cast(action_data.m_Target.GetObject());
		ItemBase key = ItemBase.Cast(action_data.m_MainItem);
		PlayerBase player;
		if(!CastTo(player, action_data.m_Player)) return;
		
		if(CastTo(warpDoor, target_object))
		{
			string warpDoorType = warpDoor.GetType();
			if(warpDoor.IsCardInserted())
			{
				warpDoor.ReturnCardToPlayer(player);
				UnlockArea(warpDoor, DNA_WarpDoor_ColourBase.FindMatch(warpDoor));
				string tier;
				GetGame().ConfigGetText("CfgVehicles " + warpDoor.GetType() + " tier", tier);
				tier.ToLower();
				DNA_Logging.LogActivity("At " + DNA_Logging.GetTime() + " - " + DNA_Logging.GetPlayerInfo(player) + " has opened a " + tier + " tier warp door.");
			}
			else
			{
				player.SetHoldState(true);
				warpDoor.TakeCardToSlot(player);
				player.DelayedMsg(null);
			}
		}
	}

	override void OnExecuteClient( ActionData action_data )
	{
		Object target_object = action_data.m_Target.GetObject();
		DNA_WarpDoor_ColourBase warpDoor;
		
		if(CastTo(warpDoor, target_object))
		{
			vector pos = warpDoor.GetPosition();
			if(warpDoor.IsCardInserted())
			{
				DNA_Sounds.SoundKCCardRemovePlay(pos);
			}
			else
			{
				DNA_Sounds.SoundKCCardScanPlay(pos);
			}
		}
	}
}