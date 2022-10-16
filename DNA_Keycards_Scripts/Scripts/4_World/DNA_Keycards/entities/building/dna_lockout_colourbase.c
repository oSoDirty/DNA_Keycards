class DNA_Lockout_ColourBase: BuildingSuper
{
	string dna_Tier;
	protected ref array<ref DNA_Config_Main_System> dna_MainSystemConfig;
	protected autoptr array<Man> all_players = new array<Man>;
	int m_TimeOfOpening;
	static ref array<DNA_Lockout_ColourBase> m_LockoutDoors = new array<DNA_Lockout_ColourBase>;
	
	void DNA_Lockout_ColourBase()
	{
		RegisterNetSyncVariableInt("m_TimeOfOpening", int.MIN, int.MAX);
		m_TimeOfOpening = -1;
		if(GetGame().IsDedicatedServer())
			dna_MainSystemConfig = DNA_Keycards_Main_System.GetInstance().GetConfig().GetConfigData().GetSystemArray();
	}
	
	override void EEInit()
	{
		super.EEInit();
		if(GetType().Contains("Lockout"))
			m_LockoutDoors.Insert(this);
	}
	
	void ~DNA_Lockout_ColourBase()
	{
		if(m_LockoutDoors)
		{
			int localIndex = m_LockoutDoors.Find(this);
			if(localIndex >=0)
				m_LockoutDoors.Remove(localIndex);
		}
	}
	
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionRequiresKeycard);
		AddAction(ActionUnlockSecuredDoors);
	}
	
	bool IsCardInserted()
	{
		ItemBase card = ItemBase.Cast(FindAttachmentBySlotName("KeyCard"));
		if(card)
			return card.IsInherited(DNA_KeyCard_ColourBase);
		return false;
	}
	
	void TakeCardToSlot(PlayerBase player)
	{
		DNA_KeyCard_ColourBase cardInHand, keyCard;
		if(player && CastTo(cardInHand, player.GetItemInHands()))
		{
			int remainingUses = cardInHand.GetRemainingUses();
			keyCard = DNA_KeyCard_ColourBase.Cast(GetInventory().CreateAttachment(cardInHand.GetType()));
			keyCard.SetRemainingUses(remainingUses);
			cardInHand.Delete();
		}
	}
	
	void ReturnCardToPlayer(PlayerBase player)
	{
		DNA_KeyCard_ColourBase keyCard = DNA_KeyCard_ColourBase.Cast(FindAttachmentBySlotName("KeyCard"));
		if(player && keyCard)
		{
			
			if(keyCard.GetRemainingUses() > 1 && keyCard.GetRemainingUses() < 11)
			{
				/*DNA_KeyCard_ColourBase cardInHand = DNA_KeyCard_ColourBase.Cast(player.GetHumanInventory().CreateInHands(keyCard.GetType()));
				cardInHand.SetRemainingUses(keyCard.GetRemainingUses() + -1);
				keyCard.Delete();*/
				/*EntityAI item;
				if(CastTo(item, keyCard))
					player.TakeEntityToHandsImpl(InventoryMode.SERVER, item);
				keyCard.SetRemainingUses(keyCard.GetRemainingUses() + -1);*/
				int uses = keyCard.GetRemainingUses();
				string cardType = keyCard.GetType();
				keyCard.Delete();
				DNA_KeyCard_ColourBase newCard = DNA_KeyCard_ColourBase.Cast(player.GetHumanInventory().CreateInHands(cardType));
				newCard.SetRemainingUses(uses + -1);
				UnlockArea();
			}
			else
			{
				keyCard.Delete();
				player.GetHumanInventory().CreateInHands("DNA_KeyCard_Error");
				UnlockArea();
			}
		}
	}
	
	bool IsAreaLocked()
	{
		ItemBase card = ItemBase.Cast(FindAttachmentBySlotName("Unlock"));
		if(card)
			return false;//card.GetType() != "DNA_KeyCard_Unlock";
		return true;
	}
	
	void UnlockArea()
	{
		GetInventory().CreateAttachment("DNA_KeyCard_Unlock");
		m_TimeOfOpening = DNA_Keycards_Main_System.GetTimeInSeconds();
		SetSynchDirty();
	}
	
	int GetNotificationSettings()
	{
		int index;
		switch(dna_Tier)
		{
			case"yellow":
				index = 59;
				break;
			case"green":
				index = 61;
				break;
			case"blue":
				index = 63;
				break;
			case"purple":
				index = 65;
				break;
			case"red":
				index = 67;
				break;
		}
		if(!index)
		{
			Print("DNA KEYCARDS - ERROR - Lockouts::GetNotificationSettings() == NO INDEX FOUND");
			return -1;
		}
		return dna_MainSystemConfig.Get(index).GetSystemSetting();
	}
	
	void NotifyPlayers()
	{
		PlayerBase player;
		int i;
		float notificationRange, distance;
		bool tooClose;
		notificationRange = GetNotificationSettings();
		/*if(!notificationRange)
		{
			Print("DNA KEYCARDS - ERROR - No Return");
			return;
		}*/
		GetGame().GetPlayers(all_players);
		if(!all_players)
		{
			Print("DNA KEYCARDS - ERROR - Where the fuck are the players?!?");
			return;
		}
		if(notificationRange == -1)
		{
			Print("DNA KEYCARDS - ERROR - Notification System Index NOT FOUND!");
			notificationRange = 0;
		}
		
		if(notificationRange > 0)
		{
			for(i = 0; i < all_players.Count(); i++)
			{
				if(CastTo(player, all_players[i]))
				{
					distance = vector.Distance(player.GetPosition(), GetPosition());
					if(!distance) return;
					if(notificationRange > 2000 && distance > 10)
					{
						SendRadiusNotification(player, distance);
						Print("AM SENT");
					}
					else if(distance < notificationRange && distance > 10)
					{
						SendRadiusNotification(player, distance);
						Print("AM SENT");
					}
				}
			}
		}
	}
	
	void SendRadiusNotification(PlayerBase player, float distance)
	{
		NotificationSystem.SendNotificationToPlayerIdentityExtended(player.GetIdentity(), 15.0, "DNA Security", "A " + dna_Tier + " tier lockout door has been opened " + Math.Round(distance) + " meters from your location.", "DNA_Keycards_Scripts/icons/KCB.edds");
	}
	
	int GetAlarmSettings()
	{
		int index;
		switch(dna_Tier)
		{
			case"yellow":
				index = 58;
				break;
			case"green":
				index = 60;
				break;
			case"blue":
				index = 62;
				break;
			case"purple":
				index = 64;
				break;
			case"red":
				index = 66;
				break;
		}
		if(!index)
		{
			Print("DNA KEYCARDS - ERROR - Lockouts::GetAlarmSettings() == NO INDEX FOUND");
			return 0;
		}
		return dna_MainSystemConfig.Get(index).GetSystemSetting();
	}

	void SoundAlarm()
	{
		if(GetAlarmSettings() == 1)
			GetRPCManager().SendRPC("DNA_Keycards_Client", "SoundAlarmBreach", new Param1<vector> (GetPosition() + "0.0 3.0 0.0"), true);
	}
}

class DNA_Lockout_Yellow: DNA_Lockout_ColourBase
{
	void DNA_Lockout_Yellow()
	{
		dna_Tier = "yellow";
	}
}
class DNA_Lockout_Green: DNA_Lockout_ColourBase
{
	void DNA_Lockout_Green()
	{
		dna_Tier = "green";
	}
}
class DNA_Lockout_Blue: DNA_Lockout_ColourBase
{
	void DNA_Lockout_Blue()
	{
		dna_Tier = "blue";
	}
}
class DNA_Lockout_Purple: DNA_Lockout_ColourBase
{
	void DNA_Lockout_Purple()
	{
		dna_Tier = "purple";
	}
}
class DNA_Lockout_Red: DNA_Lockout_ColourBase
{
	void DNA_Lockout_Red()
	{
		dna_Tier = "red";
	}
}
class DNA_Lockout_Orange: DNA_Lockout_ColourBase
{
	void DNA_Lockout_Orange()
	{
		dna_Tier = "orange";
	}
}