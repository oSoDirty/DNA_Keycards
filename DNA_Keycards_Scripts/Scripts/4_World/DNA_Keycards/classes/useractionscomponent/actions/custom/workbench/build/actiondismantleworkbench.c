class ActionDismantleWorkBench: ActionContinuousBase
{
	void ActionDismantleWorkBench()
	{
		m_CallbackClass = ActionProgramKeycardCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_ASSEMBLE;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;
	}
	
	override string GetText()
	{
		return "Dismantle Workbench";
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
		DNA_Workbench workbench;
		
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
		DNA_Workbench workbench;
		DNA_Bolts dna_bolts;
		WoodenPlank plank;
		MetalPlate plate;
		vector position;
		if(CastTo(workbench, target_object))
		{
			position = workbench.GetPosition();
			GetGame().ObjectDelete(workbench);
			workbench.DeleteSave();
			GetGame().CreateObjectEx( "DNA_CardReader", position, ECE_PLACE_ON_SURFACE );
			GetGame().CreateObjectEx( "DNA_Laptop", position, ECE_PLACE_ON_SURFACE );
			GetGame().CreateObjectEx( "MetalWire", position, ECE_PLACE_ON_SURFACE );
			EntityAI metalSheet = EntityAI.Cast( GetGame().CreateObjectEx( "MetalPlate", position, ECE_PLACE_ON_SURFACE ) );
			if(CastTo(plate, metalSheet))
				plate.SetQuantity(5);
			EntityAI woodenPlank = EntityAI.Cast( GetGame().CreateObjectEx( "WoodenPlank", position, ECE_PLACE_ON_SURFACE ) );
			if(CastTo(plank, woodenPlank))
				plank.SetQuantity(10);
			EntityAI woodenPlank2 = EntityAI.Cast( GetGame().CreateObjectEx( "WoodenPlank", position, ECE_PLACE_ON_SURFACE ) );
			if(CastTo(plank, woodenPlank2))
				plank.SetQuantity(3);
			EntityAI bolts = EntityAI.Cast( GetGame().CreateObjectEx( "DNA_Bolts", position, ECE_PLACE_ON_SURFACE ) );
			if(CastTo(dna_bolts, bolts))
				dna_bolts.SetQuantity(16);
			EntityAI workbenchKit = EntityAI.Cast( GetGame().CreateObjectEx( "DNA_Workbench_Kit", position, ECE_PLACE_ON_SURFACE ) );
			workbenchKit.GetInventory().CreateInInventory("DNA_Solder_Kit");
			workbenchKit.GetInventory().CreateInInventory("DNA_HelpingHands_Kit");
		}
	}
}