class DNA_Workbench_Build: Container_Base
{
	void DNA_Workbench_Build()
	{
	}

	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionBuildWorkBench);
		AddAction(ActionDismantleWorkBenchKit);
	}

	override bool CanPutInCargo( EntityAI parent )
	{
		return false;
	}
	
	override bool CanPutIntoHands( EntityAI parent )
	{
		return false;
	}
	
	bool CanSwapItemInCargo(EntityAI child_entity, EntityAI new_entity)
	{
		return false;
	}
	
	bool IsMetalAttached()
	{
		EntityAI metal = EntityAI.Cast(FindAttachmentBySlotName("MetalSheet_DNA"));
		if(metal)
			return metal.GetQuantity() == 5;
		
		return false;
	}
	
	bool IsWoodAttached()
	{
		EntityAI planks = EntityAI.Cast(FindAttachmentBySlotName("Plank_DNA"));
		if(planks)
			return planks.GetQuantity() == 13;
		
		return false;
	}
	
	bool AreBoltsAttached()
	{
		EntityAI bolts = EntityAI.Cast(FindAttachmentBySlotName("Bolts"));
		if(bolts)
			return bolts.GetQuantity() == 16;
		
		return false;
	}
	
	bool IsWireAttached()
	{
		return FindAttachmentBySlotName("Wire_DNA") != null;
	}
	
	bool IsReaderAttached()
	{
		return FindAttachmentBySlotName("CardReader") != null;
	}
	
	bool IsLaptopAttached()
	{
		return FindAttachmentBySlotName("Laptop") != null;
	}
}