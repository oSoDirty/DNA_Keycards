class ActionUseWarpDoor: ActionInteractBase
{	
	void ActionUseWarpDoor()
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
		return "Use Warp Passage";
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object target_object = target.GetObject();
		
		DNA_WarpDoor_ColourBase warpDoor;
		if(CastTo(warpDoor, target_object))
			return !warpDoor.IsAreaLocked();
		return true;
	}
	
	override void OnExecuteServer( ActionData action_data )
	{
		DNA_WarpDoor_NoLock_ColourBase warpDoor;
		
		Object target_object = Object.Cast(action_data.m_Target.GetObject());
		PlayerBase player;
		if(CastTo(player, action_data.m_Player) && (CastTo(warpDoor, target_object)))
		{
			HashTagSendIt(player, DNA_WarpDoor_ColourBase.FindMatch(warpDoor));
		}
	}
	
	void HashTagSendIt(PlayerBase player, DNA_WarpDoor_NoLock_ColourBase warpDoor)
	{
		if((player) && (warpDoor))
		{
			player.SetPosition(warpDoor.ModelToWorld(warpDoor.GetMemoryPointPos("teleport")));
			player.SetOrientation(warpDoor.GetOrientation() + "180 0.0 0.0");
		}
	}
}