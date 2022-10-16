class ActionAttachBattery40V: ActionInteractBase
{
	void ActionAttachBattery40V()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_HUDCursorIcon = CursorIcons.CloseHood;
	}	

	override string GetText()
	{
		return "Attach Battery";
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object target_object = target.GetObject();
		if(target_object)
			string action_selection = target_object.GetActionComponentName( target.GetComponentIndex() );

		if(action_selection && action_selection == "battery")
		{
			DNA_Battery_40v battery;
			
			if(!CastTo(battery, item))
				return false;
			
			DNA_Workbench workbench;
			
			if(CastTo(workbench, target_object))
				return !workbench.IsBatteryAttached() && !workbench.IsInUse();
		}
		return false;
	}
	
	override bool Can(PlayerBase player, ActionTarget target, ItemBase item)
	{
		return true;
	}
	
	override void OnExecuteServer( ActionData action_data )
	{
		DNA_Workbench workbench;
		if(CastTo(workbench, action_data.m_Target.GetObject()))
			workbench.TakeBatteryToSlot(action_data.m_Player);
	}
}