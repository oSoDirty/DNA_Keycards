class DNA_Workbench: Container_Base
{
	private ref Timer m_WBDrawerOpener;
	protected ref OpenableBehaviour m_Openable;
	protected bool m_IsInUse;
	
	void DNA_Workbench()
	{
		
		m_WBDrawerOpener = new Timer();
		
		m_Openable = new OpenableBehaviour(false);
		
		RegisterNetSyncVariableBool("m_Openable.m_IsOpened");
		RegisterNetSyncVariableBool("m_IsSoundSynchRemote");
		RegisterNetSyncVariableBool("m_IsPlaceSound");
		RegisterNetSyncVariableBool("m_IsInUse");
		m_IsInUse = false;
	}
	
	override void EEItemAttached(EntityAI item, string slot_name)
	{
		super.EEItemAttached(item, slot_name);
		if(GetGame().IsClient())
		{
			switch(slot_name)
			{
				/*case"ErrorCard":
					DNA_Sounds.SoundKCCardInsertPlay(GetPosition());
					break;
					
				case"BlankCard":
					DNA_Sounds.SoundKCCardInsertPlay(GetPosition());
					break;*/
					
				case"BenchBattery":
					float energy = item.GetCompEM().GetEnergy();
					if(energy < 100)
						DNA_Sounds.SoundKCAddBatteryDeadPlay(GetPosition());
					else
						DNA_Sounds.SoundKCAddBatteryPlay(GetPosition());
					break;
			}
		}		
	}
	
	override void EEItemDetached(EntityAI item, string slot_name)
	{
		super.EEItemDetached(item, slot_name);
		if(GetGame().IsClient())
		{
			switch(slot_name)
			{
				/*case"ErrorCard":
					DNA_Sounds.SoundKCCardRemovePlay(GetPosition());
					break;
					
				case"BlankCard":
					DNA_Sounds.SoundKCCardRemovePlay(GetPosition());
					break;*/
					
				case"BenchBattery":
					if(item.GetCompEM().GetEnergy() < 100)
						DNA_Sounds.SoundKCRemoveBatteryDeadPlay(GetPosition());
					else
						DNA_Sounds.SoundKCRemoveBatteryPlay(GetPosition());
					break;
			}
		}
	}
	
	void TakeBatteryToSlot(PlayerBase player)
	{
		DNA_Battery_40v battery, newBattery;
		if(player && CastTo(battery, player.GetItemInHands()))
		{
			newBattery = DNA_Battery_40v.Cast(g_Game.CreateObject("DNA_Battery_40v", GetPosition()+"0 150 0", false));
			newBattery.CopyScriptPropertiesFrom(battery);
			battery.Delete();
			g_Game.GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(ServerTakeEntityAsAttachment, 100, false, newBattery);
		}
	}
	
	void ReturnBatteryToPlayer(PlayerBase player)
	{
		DNA_Battery_40v battery, newBattery;
		battery = DNA_Battery_40v.Cast(FindAttachmentBySlotName("BenchBattery"));
		if(player && battery)
		{
			newBattery = DNA_Battery_40v.Cast(player.GetHumanInventory().CreateInHands("DNA_Battery_40v"));
			newBattery.CopyScriptPropertiesFrom(battery);
			GetGame().ObjectDelete(battery);
			battery.DeleteSave();
		}
	}
	
	void TakeErrorCardToSlot(PlayerBase player)
	{
		DNA_KeyCard_Program_Base_ER keycard;
		if(player && CastTo(keycard, player.GetItemInHands()))
		{
			GetInventory().CreateAttachment(keycard.GetInsertClass());
			keycard.Delete();
		}
	}
	
	void ReturnErrorCardToPlayer(PlayerBase player)
	{
		DNA_KeyCard_Program_Base_ER keycard = DNA_KeyCard_Program_Base_ER.Cast(FindAttachmentBySlotName("ErrorCard"));
		if(player && keycard)
		{
			GetGame().ObjectDelete(keycard);
			keycard.DeleteSave();
			player.GetHumanInventory().CreateInHands(keycard.GetRemoveClass());
		}
	}
	
	void TakeBlankCardToSlot(PlayerBase player)
	{
		DNA_KeyCard_Program_Base_BL keycard;
		if(player && CastTo(keycard, player.GetItemInHands()))
		{
			GetInventory().CreateAttachment(keycard.GetInsertClass());
			keycard.Delete();
		}
	}
	
	void ReturnBlankCardToPlayer(PlayerBase player)
	{
		DNA_KeyCard_Program_Base_BL keycard = DNA_KeyCard_Program_Base_BL.Cast(FindAttachmentBySlotName("BlankCard"));
		if(player && keycard)
		{
			GetGame().ObjectDelete(keycard);
			keycard.DeleteSave();
			player.GetHumanInventory().CreateInHands(keycard.GetRemoveClass());
		}
	}
	
	void SetInUse(bool isInUse)
	{
		m_IsInUse = isInUse;
		SetSynchDirty();
	}
	
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionOpenWorkbench);
		AddAction(ActionCloseWorkbench);
		AddAction(ActionAttachBattery40V);
		AddAction(ActionDetachBattery40V);
		AddAction(ActionAttachBlankCard);
		AddAction(ActionDetachBlankCard);
		AddAction(ActionAttachErrorCard);
		AddAction(ActionDetachErrorCard);
		AddAction(ActionSolderChip);
		AddAction(ActionRemoveChip);
		AddAction(ActionProgramKeycard);
		AddAction(ActionDismantleWorkBench);
	}
	
	override void Open()
	{
		if(IsOpen())
			m_Openable.Close();
		else
			m_Openable.Open();
		
		SoundSynchRemote();

		UpdateVisualState();
	}
	
	DNA_Battery_40v GetBattery()
	{
		return DNA_Battery_40v.Cast(FindAttachmentBySlotName("BenchBattery"));
	}
	
	DNA_Solder GetSolder()
	{
		return DNA_Solder.Cast(FindAttachmentBySlotName("Solder"));
	}
	
	DNA_Flux GetFlux()
	{
		return DNA_Flux.Cast(FindAttachmentBySlotName("Flux"));
	}
	
	DNA_KeyCard_KeyCardChip_Base GetChip()
	{
		return DNA_KeyCard_KeyCardChip_Base.Cast(FindAttachmentBySlotName("CardChip"));
	}

	protected void UpdateVisualState()
	{
		if ( IsOpen() )
			SetAnimationPhase("Draw",1);
		else
			SetAnimationPhase("Draw",0);
	}
	/* A LOT OF BOOL SHIT */
	
	override bool IsOpen()
	{
		return m_Openable.IsOpened();
	}
	
	override bool CanReceiveItemIntoCargo( EntityAI item )
	{
		return IsOpen();
	}

	override bool CanPutInCargo( EntityAI parent )
	{
		return false;
	}
	
	override bool CanPutIntoHands( EntityAI parent )
	{
		return false;
	}
	
	override bool IsInventoryVisible()
	{
		return IsOpen();
	}
	
	override bool CanReleaseCargo( EntityAI attachment )
	{
		return IsOpen();
	}
	
	bool IsBatteryAttached()
	{
		return FindAttachmentBySlotName("BenchBattery") != null;
	}
	
	bool IsBlankCardAttached()
	{
		return FindAttachmentBySlotName("BlankCard") != null;
	}
	
	bool IsErrorCardAttached()
	{
		return FindAttachmentBySlotName("ErrorCard") != null;
	}
	
	bool IsChipAttached()
	{
		return FindAttachmentBySlotName("CardChip") != null;
	}
	
	bool IsSolderAttached()
	{
		return FindAttachmentBySlotName("Solder") != null;
	}
	
	bool IsFluxAttached()
	{
		return FindAttachmentBySlotName("Flux") != null;
	}
	
	bool IsInUse()
	{
		return m_IsInUse;
	}
	
	override bool OnStoreLoad( ParamsReadContext ctx, int version )
	{
		if ( !super.OnStoreLoad( ctx, version ) )
			return false;
		
		bool opened;
		if ( version >= 110 && !ctx.Read( opened ) )
		{
			return false;
		}
		
		if ( opened )
		{
			OpenLoad();
		}
		else
		{
			CloseLoad();
		}
		
		return true;
	}
	/* END OF THE BOOL SHIT */
	
	override int GetDamageSystemVersionChange()
	{
		return 110;
	}
	
	override void OnStoreSave( ParamsWriteContext ctx )
	{   
		super.OnStoreSave( ctx );
		
		ctx.Write( m_Openable.IsOpened() );
	}
	
	void OpenLoad()
	{
		m_Openable.Open();
		SetSynchDirty();
		
		UpdateVisualState();
	}
	
	void CloseLoad()
	{
		m_Openable.Close();
		SetSynchDirty();
		
		UpdateVisualState();
	}
}

class DNA_Workbench_Perm: DNA_Workbench
{
	override void SetActions()
	{
		super.SetActions();
		
		RemoveAction(ActionDismantleWorkBench);
	}
}