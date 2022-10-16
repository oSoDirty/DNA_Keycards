class ActionRequiresKeycard: ActionInteractBase
{
	
	void ActionRequiresKeycard()
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
		return "Requires Keycard";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if ( !target ) 
			return false;
		DNA_KeyCard_ColourBase card;
		DNA_Crate_ColourBase crate;
		DNA_Strongroom_ColourBase building;
		DNA_Lockout_ColourBase lockout;
		DNA_WarpDoor_ColourBase warpDoor;
		DNA_Lockout_OneWayDoor_Locked_ColourBase oneWayLockout;
		string warpDoorType, buildingType, crateType, lockoutType, oneWayLockoutType;
		if ( !IsInReach(player, target, UAMaxDistances.DEFAULT) ) return false;
		
		if(CastTo(oneWayLockout, target.GetObject()))
		{
			oneWayLockoutType = oneWayLockout.GetType();
			if(CastTo(card, item))
				return card.GetType() != "DNA_KeyCard" + warpDoorType.SubstringInverted(oneWayLockoutType, 0, 29) && oneWayLockout.IsAreaLocked() && !oneWayLockout.IsCardInserted();
			return !oneWayLockout.IsCardInserted() && oneWayLockout.IsAreaLocked();
		}
		if(CastTo(warpDoor, target.GetObject()))
		{
			warpDoorType = warpDoor.GetType();
			if(CastTo(card, item))
				return card.GetType() != "DNA_KeyCard" + warpDoorType.SubstringInverted(warpDoorType, 0, 14) && warpDoor.IsAreaLocked() && !warpDoor.IsCardInserted();
			return !warpDoor.IsCardInserted() && warpDoor.IsAreaLocked();
		}
		if ( CastTo(building, target.GetObject()) )
		{
			buildingType = building.GetType();
			int doorIndex = building.GetDoorIndex(target.GetComponentIndex());
			if ( doorIndex != -1 )
			{
				if(CastTo(card, item))
					return card.GetType() != "DNA_KeyCard" + buildingType.SubstringInverted(buildingType, 0, 14) && !building.IsDoorOpen(doorIndex) && !building.IsCardInserted() && doorIndex == 5;
				return !building.IsCardInserted() && doorIndex == 5;
			}
		}
		if ( CastTo(crate, target.GetObject()) )
		{
			crateType = crate.GetType();
			if(CastTo(card, item))
				return card.GetType() != "DNA_KeyCard" + crateType.SubstringInverted(crateType, 0, 9) && !crate.IsOpen() && !crate.IsCardInserted();
			return !crate.IsCardInserted() && !crate.IsOpen();
		}
		if(CastTo(lockout, target.GetObject()))
		{
			lockoutType = lockout.GetType();
			if(CastTo(card, item))
				return card.GetType() != "DNA_KeyCard" + lockoutType.SubstringInverted(lockoutType, 0, 11) && lockout.IsAreaLocked() && !lockout.IsCardInserted();
			return !lockout.IsCardInserted() && lockout.IsAreaLocked();
		}
		return false;
	}

	override void OnExecuteServer( ActionData action_data )
	{
		PlayerBase player = action_data.m_Player;
		if(player)
		{
			NotificationSystem.SendNotificationToPlayerIdentityExtended(player.GetIdentity(), 15.0, "ERROR", "Access has been denied. Matching keycard required for entry.", "DNA_Keycards_Scripts/icons/KCB.edds");
		}
	}
}