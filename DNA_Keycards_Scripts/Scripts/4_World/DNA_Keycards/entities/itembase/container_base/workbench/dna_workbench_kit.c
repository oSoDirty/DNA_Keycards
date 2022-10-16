class DNA_Workbench_Kit: ItemBase
{
	void DNA_Workbench_Kit()
	{
		RegisterNetSyncVariableBool("m_IsSoundSynchRemote");
	}
	
	/*override bool CanReceiveAttachment(EntityAI attachment, int slotId)
	{
		if ( !super.CanReceiveAttachment(attachment, slotId) )
			return false;
		
		ItemBase att = ItemBase.Cast(GetInventory().FindAttachment(slotId));
		if (att)
			return false;
		
		return true;
	}*/	
		
	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
	{
		super.OnPlacementComplete( player, position, orientation );
		
		if ( GetGame().IsServer() )
		{
			//Create workbench
			
			EntityAI workbench = EntityAI.Cast( GetGame().CreateObjectEx( "DNA_Workbench_Build", position, ECE_PLACE_ON_SURFACE ) );
			workbench.SetPosition( position );
			workbench.SetOrientation( orientation );
			
			SetIsDeploySound( true );
		}	
	}
	
	override bool IsBasebuildingKit()
	{
		return true;
	}

	override bool IsDeployable()
	{
		return true;
	}
	
	bool AreHelpingHandsAttached()
	{
		return FindAttachmentBySlotName("HelpingHands") != null;
	}
	
	bool IsSolderIronAttached()
	{
		return FindAttachmentBySlotName("SolderIron") != null;
	}

	override string GetPlaceSoundset()
	{
		return "putDown_FenceKit_SoundSet";
	}

	override void SetActions()
	{
		super.SetActions();

		AddAction(ActionTogglePlaceObject);
		AddAction(ActionPlaceObject);
	}
	
	/*override void DisassembleKit(ItemBase item)
	{
		if (!IsHologram())
		{
			ItemBase stick = ItemBase.Cast(GetGame().CreateObjectEx("WoodenStick",GetPosition(),ECE_PLACE_ON_SURFACE));
			MiscGameplayFunctions.TransferItemProperties(this, stick);
			stick.SetQuantity(2);
			Rope rope = Rope.Cast(item);
			CreateRope(rope);
		}
	}*/
}