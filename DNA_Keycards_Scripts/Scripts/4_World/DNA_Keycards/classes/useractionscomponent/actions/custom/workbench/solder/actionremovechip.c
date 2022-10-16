class ActionRemoveChip: ActionContinuousBase
{
	protected bool m_BatteryIsDead, m_NoBattery, m_IsOpen;
	
	void ActionRemoveChip()
	{
		m_BatteryIsDead = false;
		m_NoBattery = false;
		m_IsOpen = false;
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
		return "Remove Used Chip";
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if(m_BatteryIsDead || m_NoBattery || m_IsOpen)
		{
			m_BatteryIsDead = false;
			m_NoBattery = false;
			m_IsOpen = false;
			return false;
		}
		Object target_object = target.GetObject();
		if(target_object)
			string action_selection = target_object.GetActionComponentName( target.GetComponentIndex() );

		if(action_selection && action_selection == "sold")
		{
			DNA_KeyCard_Error errorCard;
			DNA_Workbench workbench;
			
			if(CastTo(workbench, target_object))
			{
				ItemBase insertedCard = ItemBase.Cast(workbench.FindAttachmentBySlotName("ErrorCard"));
				if(CastTo(errorCard, insertedCard))
					return true;
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
			if(workbench.IsOpen())
			{
				m_IsOpen = true;
				NotificationSystem.SendNotificationToPlayerIdentityExtended(player.GetIdentity(), 15.0, "DNA Keycards", "Workbench drawer must be closed to complete this task!", "DNA_Keycards_Scripts/icons/KCB.edds");
				return; //add some shit here to be like yo bitch, drawer is open.
			}
			if(!workbench.IsBatteryAttached())
			{
				m_NoBattery = true;
				NotificationSystem.SendNotificationToPlayerIdentityExtended(player.GetIdentity(), 15.0, "DNA Keycards", "You need a battery to complete this task!", "DNA_Keycards_Scripts/icons/KCB.edds");
				return; //add some shit here to be like yo bitch, no battery.
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
			if(workbench.IsOpen())
				return;
			if(!workbench.IsBatteryAttached())
				return;
			DNA_Battery_40v battery = DNA_Battery_40v.Cast(workbench.GetBattery());
			pwrLvl = battery.GetCompEM().GetEnergy();
			if(pwrLvl < 100)
				return;
			battery.GetCompEM().AddEnergy(-100);
			DNA_KeyCard_Error errorCard = DNA_KeyCard_Error.Cast(workbench.FindAttachmentBySlotName("ErrorCard"));
			GetGame().ObjectDelete(errorCard);
			errorCard.DeleteSave();
			workbench.GetInventory().CreateAttachment("DNA_KeyCard_Blank");
			workbench.GetInventory().CreateInInventory("DNA_KeyCard_KeyCardChip_Burnt");
			workbench.SetInUse(false);
			PlayerBase player;
			if(CastTo(player, action_data.m_Player))
				NotificationSystem.SendNotificationToPlayerIdentityExtended(player.GetIdentity(), 15.0, "DNA Keycards", "Chip removal complete!", "DNA_Keycards_Scripts/icons/KCB.edds");
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