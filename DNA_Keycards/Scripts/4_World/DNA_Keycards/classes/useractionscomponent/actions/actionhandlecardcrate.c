class ActionHandleCardCrate: ActionInteractBase
{

	void ActionHandleCardCrate()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_HUDCursorIcon = CursorIcons.CloseHood;
	}

	override string GetText()
	{
		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		if(player)
		{
			KC_KeyCard_ColourBase card = KC_KeyCard_ColourBase.Cast(player.GetItemInHands());
			if(!card)
				return "Remove Card";
		}
		return "Insert Card";
	}
	
	override bool Can(PlayerBase player, ActionTarget target, ItemBase item)
	{
		return true;
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object target_object = target.GetObject();
		
		KC_Crate_ColourBase crate = KC_Crate_ColourBase.Cast( target_object );
		KC_KeyCard_ColourBase card = KC_KeyCard_ColourBase.Cast(item);
		string crateType, cardType;
		crateType = crate.GetType();
		cardType = card.GetType();
		
		if(card && crate && !crate.IsCardInserted() && crate.IsLocked() && !crate.IsOpen())
			return cardType == "KC_KeyCard" + crateType.SubstringInverted(crateType, 0, 8);
		
		if(!card && crate && crate.IsCardInserted() && !crate.IsLocked() && !crate.IsOpen())
			return true;
		
		return false;
	}

	override void OnExecuteServer( ActionData action_data )
	{
		Object target_object = action_data.m_Target.GetObject();
		KC_Crate_ColourBase crate = KC_Crate_ColourBase.Cast( target_object );
		PlayerBase player = action_data.m_Player;
		if(crate && !crate.IsOpen())
		{
			if(crate.IsCardInserted())
			{	
				KC_Crate_Yellow yellowCrate;
				if(CastTo(yellowCrate, target_object))
					yellowCrate.DoTheDamnThing("yellow");
						
				KC_Crate_Green greenCrate;
				if(CastTo(greenCrate, target_object))
					greenCrate.DoTheDamnThing("green");
						
				KC_Crate_Blue blueCrate;
				if(CastTo(blueCrate, target_object))
					blueCrate.DoTheDamnThing("blue");
				
						
				KC_Crate_Purple purpleCrate;
				if(CastTo(purpleCrate, target_object))
					purpleCrate.DoTheDamnThing("purple");
				
						
				KC_Crate_Red redCrate;
				if(CastTo(redCrate, target_object))
					redCrate.DoTheDamnThing("red");
				
				crate.ReturnCardToPlayer(player);
				crate.Open();
			}
			else
			{
				crate.TakeCardToSlot(player);
				GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(Message, 3000, false, player.GetIdentity());
			}
		}			
	}

	override void OnExecuteClient( ActionData action_data )
	{
		Object target_object = action_data.m_Target.GetObject();
		KC_Crate_ColourBase crate;
		if(CastTo(crate, target_object))
		{
			if(crate.IsCardInserted())
			{
				//crate.SoundKCCrateRemovePlay();
			}
			else
			{
				crate.SoundKCCrateScanPlay();
			}
		}
	}
	
	void Message(PlayerIdentity identity)
	{
		if(identity)
			NotificationSystem.SendNotificationToPlayerIdentityExtended(identity, 15.0, "DNA Keycards", "Crate Unlocked! You may remove keycard to open.");
	}
	
	override void OnEndServer( ActionData action_data )
	{
		Object target_object = action_data.m_Target.GetObject();
		KC_Crate_ColourBase crate = KC_Crate_ColourBase.Cast( target_object );
		if( crate )
		{
			crate.SoundSynchRemoteReset();
		}
	}
}
