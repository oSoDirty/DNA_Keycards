class ActionDismantleWorkBenchKit: ActionContinuousBase
{
	void ActionDismantleWorkBenchKit()
	{
		m_CallbackClass = ActionProgramKeycardCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_ASSEMBLE;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;
	}
	
	override string GetText()
	{
		return "Dismantle Workbench Kit";
	}
	
	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNone;
	}
	
	override typename GetInputType()
	{
		return ContinuousInteractActionInput;
	}
	
	override bool CanBeUsedLeaning()
	{
		return false;
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object target_object = target.GetObject();
		DNA_Workbench_Build workbench;
		
		if ( player.IsPlacingLocal() || player.IsPlacingServer() )
			return false;
		
		if (player.GetBrokenLegs() == eBrokenLegs.BROKEN_LEGS)
			return false;
		
		if(CastTo(workbench, target_object))
			return player.GetItemInHands().GetType() == "Hatchet";
		
		return false;
	}
	
	
	
	override void OnFinishProgressServer( ActionData action_data )
	{
		Object target_object = action_data.m_Target.GetObject();
		DNA_Workbench_Build workbench;
		vector position;
		if(CastTo(workbench, target_object))
		{
			position = workbench.GetPosition();
			GetGame().ObjectDelete(workbench);
			workbench.DeleteSave();
			EntityAI workbenchKit = EntityAI.Cast( GetGame().CreateObjectEx( "DNA_Workbench_Kit", position, ECE_PLACE_ON_SURFACE ) );
			workbenchKit.GetInventory().CreateInInventory("DNA_Solder_Kit");
			workbenchKit.GetInventory().CreateInInventory("DNA_HelpingHands_Kit");
		}
	}
}