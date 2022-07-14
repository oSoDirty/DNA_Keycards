class ActionHandleKeycard: ActionInteractBase
{
	void ActionHandleKeycard()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_HUDCursorIcon = CursorIcons.OpenDoors;
	}

	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTCursor;
	}

	override string GetText()
	{
		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		if(player)
		{
			if(!player.GetItemInHands())
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
		string roomType, cardType, crateType;
		DNA_Strongroom_ColourBase strongRoom;
		DNA_Crate_Keyed_ColourBase crate;
		DNA_KeyCard_ColourBase card = DNA_KeyCard_ColourBase.Cast(item);
		
		if(!target) return false;
		
		Object target_object = target.GetObject();
		if(!CastTo(strongRoom, target_object) && !CastTo(crate, target_object)) return false;
		
		if(CastTo(strongRoom, target_object))
		{
			int x = strongRoom.GetDoorIndex(target.GetComponentIndex());
			if(x != 5) return false;
			
			if(card)
				cardType = card.GetType();
			if(strongRoom)
				roomType = strongRoom.GetType();
			
			if(card && !strongRoom.IsDoorOpen(x) && !strongRoom.IsCardInserted())
				return cardType == "DNA_KeyCard" + roomType.SubstringInverted(roomType, 0, 14);
			
			if(!card && !strongRoom.IsDoorOpen(x) && strongRoom.IsCardInserted() && !player.IsHolding())
				return !player.GetItemInHands();
		}
		
		if(CastTo(crate, target_object))
		{
			if(crate)
				crateType = crate.GetType();
			if(card)
				cardType = card.GetType();
			
			if(card && crate && !crate.IsCardInserted() && crate.IsLocked() && !crate.IsOpen())
				return cardType == "DNA_KeyCard" + crateType.SubstringInverted(crateType, 0, 9);
			
			if(!card && crate && crate.IsCardInserted() && !crate.IsLocked() && !crate.IsOpen())
				return !player.GetItemInHands();		
		}
		return false;
	}
	
	override void OnExecuteServer( ActionData action_data )
	{
		Building building;
		DNA_Strongroom_ColourBase strongRoom;
		DNA_Crate_Keyed_ColourBase crate;
		PlayerBase player = action_data.m_Player;
		vector memPointPos, memPointPosMTW, readerPos, readerPosMTW;
		if (CastTo(building, action_data.m_Target.GetObject()))
		{
			if(CastTo(strongRoom, building))
			{
				readerPos = strongRoom.GetMemoryPointPos("Door8_action");
				readerPosMTW = strongRoom.ModelToWorld(readerPos);
				int doorIndex = strongRoom.GetDoorIndex(action_data.m_Target.GetComponentIndex());
				if(doorIndex != -1)
				{
					if(strongRoom.IsCardInserted())
					{
						strongRoom.ReturnCardToPlayer(player);
						GetRPCManager().SendRPC("DNA_Keycards_Client", "SoundCardReader", new Param2<string, vector> ("out", readerPosMTW), true);
						memPointPos = strongRoom.GetMemoryPointPos("Crate");
						memPointPosMTW = strongRoom.ModelToWorld(memPointPos);
						string buildingType = strongRoom.GetType();
						strongRoom.OpenDoor(doorIndex);
						crate = DNA_Crate_Keyed_ColourBase.Cast(GetGame().CreateObject("DNA_StorageProxy" + buildingType.SubstringInverted(buildingType, 0, 14), memPointPosMTW, false, false, false));
						crate.SetOrientation(strongRoom.GetOrientation());
						GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(DoStuff, 5500, false, crate, player);
						strongRoom.SpawnInfected();
						strongRoom.SpawnWolves();
						strongRoom.SpawnBears();
						strongRoom.SpawnBoss();
					}
					else
					{
						player.SetHoldState(true);
						strongRoom.TakeCardToSlot(player);
						GetRPCManager().SendRPC("DNA_Keycards_Client", "SoundCardReader", new Param2<string, vector> ("in", readerPosMTW), true);
						player.DelayedMsg(null);
					}
				}
			}
		}
		if(CastTo(crate, action_data.m_Target.GetObject()))
		{
			if(crate && !crate.IsOpen())
			{
				if(crate.IsCardInserted())
				{			
					crate.ReturnCardToPlayer(player);
					GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(DoStuff, 25, false, crate, player);
				}
				else
				{
					crate.TakeCardToSlot(player);
					player.DelayedMsg(crate);
				}
			}
		}
	}

	override void OnExecuteClient( ActionData action_data )
	{
		Object target_object = action_data.m_Target.GetObject();
		DNA_Crate_Keyed_ColourBase crate;
		
		if(CastTo(crate, target_object))
		{
			vector pos = crate.GetPosition();
			if(crate.IsCardInserted())
			{
				DNA_Sounds.SoundKCCardRemovePlay(pos);
			}
			else
			{
				DNA_Sounds.SoundKCCardScanPlay(pos);
			}
		}
	}
	
	void DoStuff(DNA_Crate_ColourBase crate, PlayerBase player)
	{
		string tier;
		GetGame().ConfigGetText("CfgVehicles " + crate.GetType() + " tier", tier);
		tier.ToLower();
		crate.Open();
		crate.SoundAlarm();
		crate.DoTheDamnThing();
		GetRPCManager().SendRPC("DNA_Keycards_Client", "SoundCrateOpen", new Param1<vector> (crate.GetPosition()), true);
		DNA_Logging.LogActivity("At " + DNA_Logging.GetTime() + " - " + DNA_Logging.GetPlayerInfo(player) + " has opened a " + tier + " tier " + crate.ContainerType() + ".");
	}
};