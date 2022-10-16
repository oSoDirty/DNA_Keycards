class ActionUseOneWayDoor: ActionInteractBase
{
	void ActionUseOneWayDoor()
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
		return "Use One Way Passage";
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object target_object = Object.Cast(target.GetObject());
		DNA_Lockout_OneWayDoor_Locked_ColourBase lockout;
		if(CastTo(lockout, target_object))
			return !lockout.IsAreaLocked();
		return true;
	}
	
	override void OnExecuteServer( ActionData action_data )
	{
		DNA_Lockout_OneWayDoor_ColourBase lockout;
		
		Object target_object = Object.Cast(action_data.m_Target.GetObject());
		PlayerBase player;
		if(CastTo(player, action_data.m_Player))
		{
			if(CastTo(lockout, target_object))
			{
				lockout.MovePlayer(player);
			}
		}
	}
}