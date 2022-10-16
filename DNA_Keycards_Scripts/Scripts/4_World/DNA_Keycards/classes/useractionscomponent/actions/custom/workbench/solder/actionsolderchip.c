class ActionSolderChip: ActionContinuousBase
{
	protected bool m_BatteryIsDead, m_IsOpen, m_NoBattery, m_NoChip, m_NoFlux, m_NoSolder;
	
	void ActionSolderChip()
	{
		m_BatteryIsDead = false;
		m_IsOpen = false;
		m_NoBattery = false;
		m_NoChip = false;
		m_NoFlux = false;
		m_NoSolder = false;
		m_CallbackClass = ActionProgramKeycardCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_INTERACT;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
	}
	
	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINotPresent;
		m_ConditionTarget = new CCTCursor;
	}
	
	override typename GetInputType()
	{
		return ContinuousInteractActionInput;
	}
	
	override string GetText()
	{
		return "Install New Chip";
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if(m_BatteryIsDead || m_IsOpen || m_NoBattery || m_NoChip || m_NoFlux || m_NoSolder)
		{
			m_BatteryIsDead = false;
			m_IsOpen = false;
			m_NoBattery = false;
			m_NoChip = false;
			m_NoFlux = false;
			m_NoSolder = false;
			return false;
		}
		Object target_object = target.GetObject();
		if(target_object)
			string action_selection = target_object.GetActionComponentName( target.GetComponentIndex() );

		if(action_selection && action_selection == "sold")
		{
			DNA_KeyCard_Blank blankCard;
			DNA_Workbench workbench;
			
			if(CastTo(workbench, target_object))
			{
				ItemBase insertedCard = ItemBase.Cast(workbench.FindAttachmentBySlotName("ErrorCard"));
				if(CastTo(blankCard, insertedCard))
					return !blankCard.HasChip();
			}
		}
		return false;
	}
	
	override void OnStartServer(ActionData action_data)
	{
		float pwrLvl;
		DNA_Workbench workbench;
		Object target_object = action_data.m_Target.GetObject();
		PlayerBase player = PlayerBase.Cast(action_data.m_Player);
		if(!player) return;
		if(CastTo(workbench, target_object))
		{
			if(!workbench.IsBatteryAttached())
			{
				m_NoBattery = true;
				NotificationSystem.SendNotificationToPlayerIdentityExtended(player.GetIdentity(), 15.0, "DNA Keycards", "You need a battery to complete this task!", "DNA_Keycards_Scripts/icons/KCB.edds");
				return;
			}
			if(!workbench.IsChipAttached())
			{
				m_NoChip = true;
				NotificationSystem.SendNotificationToPlayerIdentityExtended(player.GetIdentity(), 15.0, "DNA Keycards", "You need a chip to complete this task!", "DNA_Keycards_Scripts/icons/KCB.edds");
				return;
			}
			if(workbench.IsOpen())
			{
				m_IsOpen = true;
				NotificationSystem.SendNotificationToPlayerIdentityExtended(player.GetIdentity(), 15.0, "DNA Keycards", "Workbench drawer must be closed to complete this task!", "DNA_Keycards_Scripts/icons/KCB.edds");
				return;
			}
			if(!workbench.IsSolderAttached())
			{
				m_NoSolder = true;
				NotificationSystem.SendNotificationToPlayerIdentityExtended(player.GetIdentity(), 15.0, "DNA Keycards", "You need solder to complete this task!", "DNA_Keycards_Scripts/icons/KCB.edds");
				return;
			}
			if(!workbench.IsFluxAttached())
			{
				m_NoFlux = true;
				NotificationSystem.SendNotificationToPlayerIdentityExtended(player.GetIdentity(), 15.0, "DNA Keycards", "You need flux to complete this task!", "DNA_Keycards_Scripts/icons/KCB.edds");
				return;
			}
			DNA_Battery_40v battery = DNA_Battery_40v.Cast(workbench.GetBattery());
			pwrLvl = battery.GetCompEM().GetEnergy();
			if(pwrLvl < 100)
			{
				m_BatteryIsDead = true;
				NotificationSystem.SendNotificationToPlayerIdentityExtended(player.GetIdentity(), 15.0, "DNA Keycards", "Battery does not have enough power to complete this task!", "DNA_Keycards_Scripts/icons/KCB.edds");
				return;
			}
			workbench.SetInUse(true);
		}
	}
	
	override void OnStartClient(ActionData action_data)
	{
		float pwrLvl;
		DNA_Workbench workbench;
		Object target_object = action_data.m_Target.GetObject();
		PlayerBase player = PlayerBase.Cast(action_data.m_Player);
		if(!player) return;
		if(CastTo(workbench, target_object))
		{	
			DNA_Battery_40v battery = DNA_Battery_40v.Cast(workbench.GetBattery());
			pwrLvl = battery.GetCompEM().GetEnergy();
			
			if(pwrLvl < 100)
				return;
			
			if(!workbench.IsBatteryAttached())
				return;
			
			if(!workbench.IsSolderAttached())
				return;
			
			if(!workbench.IsFluxAttached())
				return;
			
			if(!workbench.IsChipAttached())
				return;
				
			if(workbench.IsOpen())
				return;
			
			DNA_Sounds.SoundKCCardSolderPlay(workbench.GetPosition());
		}
	}
	
	override void OnFinishProgressServer( ActionData action_data )
	{
		float pwrLvl, newPwrLvl;
		
		DNA_Workbench workbench;
		Object target_object = action_data.m_Target.GetObject();
		if(CastTo(workbench, target_object))
		{
			if(!workbench.IsBatteryAttached())
				return;
			if(!workbench.IsChipAttached())
				return;
			if(!workbench.IsFluxAttached())
				return;
			if(!workbench.IsSolderAttached())
				return;
			if(workbench.IsOpen())
				return;
			DNA_Battery_40v battery = DNA_Battery_40v.Cast(workbench.GetBattery());
			DNA_KeyCard_KeyCardChip_Base chip = DNA_KeyCard_KeyCardChip_Base.Cast(workbench.GetChip());
			DNA_Flux flux = DNA_Flux.Cast(workbench.GetFlux());
			DNA_Solder solder = DNA_Solder.Cast(workbench.GetSolder());
			pwrLvl = battery.GetCompEM().GetEnergy();
			if(pwrLvl < 100)
				return;
			battery.GetCompEM().AddEnergy(-100);
			flux.SetQuantity(flux.GetQuantity() + -20);
			solder.SetQuantity(solder.GetQuantity() + -20);
			DNA_KeyCard_Blank blankCard = DNA_KeyCard_Blank.Cast(workbench.FindAttachmentBySlotName("ErrorCard"));
			string switchClass = chip.GetSwitchClass();
			GetGame().ObjectDelete(chip);
			chip.DeleteSave();
			GetGame().ObjectDelete(blankCard);
			blankCard.DeleteSave();
			workbench.GetInventory().CreateAttachment(switchClass);
			workbench.SetInUse(false);
			PlayerBase player;
			if(CastTo(player, action_data.m_Player))
				NotificationSystem.SendNotificationToPlayerIdentityExtended(player.GetIdentity(), 15.0, "DNA Keycards", "Chip installation complete!", "DNA_Keycards_Scripts/icons/KCB.edds");
		}
	}
	
	override void OnEndInput( ActionData action_data )
	{
		super.OnEndInput(action_data);
		
		DNA_Workbench workbench;
		Object target_object = action_data.m_Target.GetObject();
		if(CastTo(workbench, target_object))
		{
			workbench.SetInUse(false);
		}
	}
}