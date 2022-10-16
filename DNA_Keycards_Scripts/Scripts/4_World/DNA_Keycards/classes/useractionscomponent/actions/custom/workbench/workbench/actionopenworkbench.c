class ActionOpenWorkbench: ActionInteractBase
{
	void ActionOpenWorkbench()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_HUDCursorIcon = CursorIcons.CloseHood;
	}

	override string GetText()
	{
		return "Open Drawer";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object target_object = target.GetObject();
		DNA_Workbench workbench;
		if(CastTo(workbench, target_object))
		{
			string action_selection = workbench.GetActionComponentName( target.GetComponentIndex() );
			return action_selection == "draw" && !workbench.IsOpen() && !workbench.IsInUse();
		}
		return false;
	}

	override void OnExecuteServer( ActionData action_data )
	{
		Object target_object = action_data.m_Target.GetObject();
		DNA_Workbench bench = DNA_Workbench.Cast( target_object );
		bench.Open();
	}
	
	override void OnExecuteClient( ActionData action_data )
	{
		Object target_object = action_data.m_Target.GetObject();
		DNA_Workbench bench;
		
		if(CastTo(bench, target_object))
			DNA_Sounds.SoundKCOpenDrawerPlay(bench.GetPosition());
	}
	
	override void OnEndServer( ActionData action_data )
	{
		Object target_object = action_data.m_Target.GetObject();
		DNA_Workbench bench;
		
		if(CastTo(bench, target_object))
			bench.SoundSynchRemoteReset();
	}
}
