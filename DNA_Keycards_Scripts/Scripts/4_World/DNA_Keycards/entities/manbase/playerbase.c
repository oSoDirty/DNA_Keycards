modded class PlayerBase
{
	
	protected bool dna_IsHolding;
	
	override void Init()
	{
		super.Init();
		
		RegisterNetSyncVariableBool("dna_IsHolding");
		dna_IsHolding = false;
	}
	
	bool IsHolding()
	{
		return dna_IsHolding;
	}
	
	void SetHoldState(bool state)
	{
		dna_IsHolding = state;
		SetSynchDirty();
	}
	
	void DelayedMsg(DNA_Crate_ColourBase crate)
	{
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(DNAMessage, 3000, false, crate);
	}
	
	void DNAMessage(DNA_Crate_ColourBase crate)
	{
		NotificationSystem.SendNotificationToPlayerIdentityExtended(GetIdentity(), 15.0, "Scan Complete", "You may remove keycard to open.", "DNA_Keycards_Scripts/icons/KCB.edds");
		if(crate)
		{
			crate.Unlock();
		}
		else
		{
			SetHoldState(false);
		}
	}
}