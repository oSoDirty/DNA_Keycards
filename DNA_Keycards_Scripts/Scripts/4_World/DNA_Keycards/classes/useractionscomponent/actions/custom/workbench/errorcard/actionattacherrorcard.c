class ActionAttachErrorCard: ActionInteractBase
{
	void ActionAttachErrorCard()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_HUDCursorIcon = CursorIcons.CloseHood;
	}	

	override string GetText()
	{
		return "Attach Keycard";
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object target_object = target.GetObject();
		if(target_object)
			string action_selection = target_object.GetActionComponentName( target.GetComponentIndex() );

		if(action_selection && action_selection == "hands")
		{
			DNA_KeyCard_Program_Base_ER errorCard;
			
			if(!CastTo(errorCard, item))
				return false;
			if(errorCard.HasChip())
				return false;
			
			DNA_Workbench workbench;
			
			if(CastTo(workbench, target_object))
				return !workbench.IsErrorCardAttached() && !workbench.IsInUse();
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
			workbench.TakeErrorCardToSlot(action_data.m_Player);
	}
	
	override void OnExecuteClient(ActionData action_data)
	{
		DNA_Workbench workbench;
		Object target_object = action_data.m_Target.GetObject();
		if(CastTo(workbench, target_object))
			DNA_Sounds.SoundKCCardAttachPlay(workbench.GetPosition());
	}
}