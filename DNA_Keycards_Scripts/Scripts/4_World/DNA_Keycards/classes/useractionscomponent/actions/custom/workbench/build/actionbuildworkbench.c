class ActionBuildWorkBench: ActionContinuousBase
{
	void ActionBuildWorkBench()
	{
		m_CallbackClass = ActionProgramKeycardCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_ASSEMBLE;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;
	}
	
	override string GetText()
	{
		return "Assemble Workbench";
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
		
		if(player.GetItemInHands().GetType() != "Hammer")
			return false;
		
		if(CastTo(workbench, target_object))
			return workbench.IsMetalAttached() && workbench.AreBoltsAttached() && workbench.IsWoodAttached() && workbench.IsWireAttached() && workbench.IsLaptopAttached() && workbench.IsReaderAttached();
		
		return false;
	}
	
	
	
	override void OnFinishProgressServer( ActionData action_data )
	{
		Object target_object = action_data.m_Target.GetObject();
		DNA_Workbench_Build workbenchBuild;
		vector position, orientation;
		if(CastTo(workbenchBuild, target_object))
		{
			position = workbenchBuild.GetPosition();
			orientation = workbenchBuild.GetOrientation();
			GetGame().ObjectDelete(workbenchBuild);
			workbenchBuild.DeleteSave();
			EntityAI workbench = EntityAI.Cast( GetGame().CreateObjectEx( "DNA_Workbench", position, ECE_PLACE_ON_SURFACE ) );
			workbench.SetPosition( position );
			workbench.SetOrientation( orientation );
		}
	}
}