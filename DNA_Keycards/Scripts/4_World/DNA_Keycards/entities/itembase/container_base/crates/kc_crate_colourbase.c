class KC_Crate_ColourBase: Container_Base
{    

    private bool m_IsLocked;
	private ref Timer m_KCCrateOpener;
	protected ref OpenableBehaviour m_Openable;
	protected ref array<ref KCM_Config_System> kcm_SystemConfig;
	protected ref array<ref Base_Variables> kcm_BaseConfig;
	protected ref array<ref KCM_SideArm> kcm_SideArms;
	protected ref array<ref KCM_Food> kcm_FoodItems;
	protected ref array<ref KCM_Drink> kcm_DrinkItems;
	protected ref array<ref KCM_Tools> kcm_ToolItems;
	protected ref array<ref KCM_BuildingMats> kcm_BuildingItems;
	protected ref array<ref KCM_Medical> kcm_MedicalItems;
	protected ref array<ref KCM_Valuables> kcm_Valuables;
	
	protected int kcm_TestVar;

	void KC_Crate_ColourBase()
	{
		kcm_SystemConfig = DNA_Keycards_System.GetInstance().GetConfig().GetConfigData().GetSystemArray();
		kcm_SideArms = DNA_Keycards_Base.GetInstance().GetConfig().GetConfigData().GetSideArmArray();
		kcm_FoodItems = DNA_Keycards_Base.GetInstance().GetConfig().GetConfigData().GetFoodArray();
		kcm_DrinkItems = DNA_Keycards_Base.GetInstance().GetConfig().GetConfigData().GetDrinkArray();
		kcm_ToolItems = DNA_Keycards_Base.GetInstance().GetConfig().GetConfigData().GetToolsArray();
		kcm_BuildingItems = DNA_Keycards_Base.GetInstance().GetConfig().GetConfigData().GetBuildingArray();
		kcm_MedicalItems = DNA_Keycards_Base.GetInstance().GetConfig().GetConfigData().GetMedicalArray();
		kcm_Valuables = DNA_Keycards_Base.GetInstance().GetConfig().GetConfigData().GetValuablesArray();
		kcm_BaseConfig = DNA_Keycards_Base.GetInstance().GetConfig().GetConfigData().GetBaseVarsArray();
		m_KCCrateOpener = new Timer();

		m_Openable = new OpenableBehaviour(false);


		RegisterNetSyncVariableBool("m_Openable.m_IsOpened");
		RegisterNetSyncVariableBool("m_IsLocked");
		RegisterNetSyncVariableBool("m_IsSoundSynchRemote");
		RegisterNetSyncVariableBool("m_IsPlaceSound");
		Lock();
	}

	/*override void EEInit()
	{
		super.EEInit();
		GetInventory().LockInventory(HIDE_INV_FROM_SCRIPT);
	}*/
	
	override void Open()
	{
		m_Openable.Open();
		//GetInventory().UnlockInventory(HIDE_INV_FROM_SCRIPT);
		SoundSynchRemote();

		UpdateVisualState();
	}

	protected void UpdateVisualState()
	{
		if ( IsOpen() )
		{
			SetAnimationPhase("Door1",1);
		}
		else
		{
			SetAnimationPhase("Door1",0);
		}
	}

	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
		
		if ( IsPlaceSound() )
		{
			PlayPlaceSound();
		}
		else if ( IsSoundSynchRemote() && !IsBeingPlaced() && m_Initialized )
		{
			if ( IsOpen() )
			{
				SoundKCCrateOpenPlay();
			}
			else if ( !IsOpen() )
			{
				SoundKCCrateClosePlay();
			}
		}
		UpdateVisualState();
	}
	
	void TakeCardToSlot(PlayerBase player)
	{
		KC_KeyCard_ColourBase cardInHand, keyCard;
		cardInHand = KC_KeyCard_ColourBase.Cast(player.GetItemInHands());
		if(player && cardInHand)
		{
			int remainingUses = cardInHand.GetQuantity();
			keyCard = KC_KeyCard_ColourBase.Cast(GetInventory().CreateAttachment(cardInHand.GetType()));
			keyCard.SetQuantity(remainingUses);
			cardInHand.Delete();
			GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(Unlock, 3000, false);
		}
	}
	
	void ReturnCardToPlayer(PlayerBase player)
	{
		KC_KeyCard_ColourBase keyCard = KC_KeyCard_ColourBase.Cast(FindAttachmentBySlotName("KeyCard"));
		if(player && keyCard)
		{
			
			if(keyCard.GetQuantity() > 1)
			{
				KC_KeyCard_ColourBase cardInHand = KC_KeyCard_ColourBase.Cast(player.GetHumanInventory().CreateInHands(keyCard.GetType()));
				cardInHand.SetQuantity(keyCard.GetQuantity() + -1);
				keyCard.Delete();
			}
			else
			{
				GetGame().ObjectDelete(keyCard);
				keyCard.DeleteSave();
				player.GetHumanInventory().CreateInHands("KC_KeyCard_Error");	
			}
		}
	}
	
	void SoundKCCrateOpenPlay()
	{
		EffectSound sound =	SEffectManager.PlaySound( "DNA_KeycardOpen_SoundSet", GetPosition() );
		sound.SetSoundAutodestroy( true );
	}
	
	void SoundKCCrateScanPlay()
	{
		EffectSound sound =	SEffectManager.PlaySound( "DNA_KeycardScan_SoundSet", GetPosition() );
		sound.SetSoundAutodestroy( true );
	}
	
	/*void SoundKCCrateRemovePlay()
	{
		EffectSound sound =	SEffectManager.PlaySound( "DNA_KeycardRemove_SoundSet", GetPosition() );
		sound.SetSoundAutodestroy( true );
	}*/
	
	void SoundKCCrateClosePlay() //not needed?
	{
		EffectSound sound =	SEffectManager.PlaySound( "DNA_KeycardOpen_SoundSet", GetPosition() );
		sound.SetSoundAutodestroy( true );
	}
	
	void Lock()
	{
		m_IsLocked = true;
		SetSynchDirty();
	}
	
	void Unlock()
	{
		m_IsLocked = false;
		SetSynchDirty();
	}

	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionHandleCardCrate);
	}
	
	/* This down here is a bunch of bool shit*/
	override bool IsOpen()
	{
		return m_Openable.IsOpened();
	}
	
	override bool CanDisplayAttachmentSlot()
	{
		return false;
	}
	
	override bool CanDisplayAttachmentCategory()
	{
		return false;
	}
	
	bool IsLocked()
	{
		return m_IsLocked;
	}

	override bool CanPutInCargo( EntityAI parent )
	{
		return false;
	}
	
	override bool CanPutIntoHands( EntityAI parent )
	{
		return false;
	}
	
	override bool CanReceiveItemIntoCargo( EntityAI item )
	{
		if(IsLocked())
			return false;
		
		return !item.IsInherited(KC_KeyCard_ColourBase) && !item.IsInherited(KC_KeyCard_Error);
	}
	
	bool CanReceiveAttachment (EntityAI attachment, int slotId)
	{
		return IsLocked();
	}
	
	override bool IsInventoryVisible()
	{
		return IsOpen();
	}
	
	override bool CanReleaseCargo( EntityAI attachment )
	{
		return IsOpen();
	}
	
	bool IsCardInserted()
	{
		return FindAttachmentBySlotName("KeyCard") != null;
	}
	
	bool CanSpawnMainWeapon(string color)
	{
		if(kcm_SystemConfig && color)
		{
			switch(color)
			{
				case "yellow":
					return kcm_SystemConfig.Get(1).GetSystemSetting() != 0;
				case "green":
					return kcm_SystemConfig.Get(14).GetSystemSetting() != 0;
				case "blue":
					return kcm_SystemConfig.Get(27).GetSystemSetting() != 0;
				case "purple":
					return kcm_SystemConfig.Get(40).GetSystemSetting() != 0;
				case "red":
					return kcm_SystemConfig.Get(53).GetSystemSetting() != 0;
			}
		}
		return false;
	}
	
	bool CanSpawnSideArm(string color)
	{
		if(kcm_SystemConfig && color)
		{
			switch(color)
			{
				case "yellow":
					return kcm_SystemConfig.Get(4).GetSystemSetting() != 0;
				case "green":
					return kcm_SystemConfig.Get(17).GetSystemSetting() != 0;
				case "blue":
					return kcm_SystemConfig.Get(30).GetSystemSetting() != 0;
				case "purple":
					return kcm_SystemConfig.Get(43).GetSystemSetting() != 0;
				case "red":
					return kcm_SystemConfig.Get(56).GetSystemSetting() != 0;
			}
		}
		return false;
	}
	
	bool CanSpawnMainMagsExtra(string color)
	{
		if(kcm_SystemConfig && color)
		{
			switch(color)
			{
				case "yellow":
					return kcm_SystemConfig.Get(2).GetSystemSetting() != 0;
				case "green":
					return kcm_SystemConfig.Get(15).GetSystemSetting() != 0;
				case "blue":
					return kcm_SystemConfig.Get(28).GetSystemSetting() != 0;
				case "purple":
					return kcm_SystemConfig.Get(41).GetSystemSetting() != 0;
				case "red":
					return kcm_SystemConfig.Get(54).GetSystemSetting() != 0;
			}
		}
		return false;
	}
	
	bool CanSpawnSideMagsExtra(string color)
	{
		if(kcm_SystemConfig && color)
		{
			switch(color)
			{
				case "yellow":
					return kcm_SystemConfig.Get(5).GetSystemSetting() != 0;
				case "green":
					return kcm_SystemConfig.Get(18).GetSystemSetting() != 0;
				case "blue":
					return kcm_SystemConfig.Get(31).GetSystemSetting() != 0;
				case "purple":
					return kcm_SystemConfig.Get(44).GetSystemSetting() != 0;
				case "red":
					return kcm_SystemConfig.Get(57).GetSystemSetting() != 0;
			}
		}
		return false;
	}
	
	bool CanSpawnMainAttachments(string color)
	{
		if(kcm_SystemConfig && color)
		{
			switch(color)
			{
				case "yellow":
					return kcm_SystemConfig.Get(3).GetSystemSetting() != 0;
				case "green":
					return kcm_SystemConfig.Get(16).GetSystemSetting() != 0;
				case "blue":
					return kcm_SystemConfig.Get(29).GetSystemSetting() != 0;
				case "purple":
					return kcm_SystemConfig.Get(42).GetSystemSetting() != 0;
				case "red":
					return kcm_SystemConfig.Get(55).GetSystemSetting() != 0;
			}
		}
		return false;
	}
	
	bool CanSpawnSideAttachments(string color)
	{
		if(kcm_SystemConfig && color)
		{
			switch(color)
			{
				case "yellow":
					return kcm_SystemConfig.Get(6).GetSystemSetting() != 0;
				case "green":
					return kcm_SystemConfig.Get(19).GetSystemSetting() != 0;
				case "blue":
					return kcm_SystemConfig.Get(32).GetSystemSetting() != 0;
				case "purple":
					return kcm_SystemConfig.Get(45).GetSystemSetting() != 0;
				case "red":
					return kcm_SystemConfig.Get(58).GetSystemSetting() != 0;
			}
		}
		return false;
	}
	
	bool CanSpawnMainAmmoExtra(string color)
	{
		if(kcm_SystemConfig && color)
		{
			switch(color)
			{
				case "yellow":
					return kcm_SystemConfig.Get(66).GetSystemSetting() != 0;
				case "green":
					return kcm_SystemConfig.Get(68).GetSystemSetting() != 0;
				case "blue":
					return kcm_SystemConfig.Get(70).GetSystemSetting() != 0;
				case "purple":
					return kcm_SystemConfig.Get(72).GetSystemSetting() != 0;
				case "red":
					return kcm_SystemConfig.Get(74).GetSystemSetting() != 0;
			}
		}
		return false;
	}
	
	bool CanSpawnSideAmmoExtra(string color)
	{
		if(kcm_SystemConfig && color)
		{
			switch(color)
			{
				case "yellow":
					return kcm_SystemConfig.Get(67).GetSystemSetting() != 0;
				case "green":
					return kcm_SystemConfig.Get(69).GetSystemSetting() != 0;
				case "blue":
					return kcm_SystemConfig.Get(71).GetSystemSetting() != 0;
				case "purple":
					return kcm_SystemConfig.Get(73).GetSystemSetting() != 0;
				case "red":
					return kcm_SystemConfig.Get(75).GetSystemSetting() != 0;
			}
		}
		return false;
	}
	
	bool CanSpawnFood(string color)
	{
		if(kcm_SystemConfig && color)
		{
			switch(color)
			{
				case "yellow":
					return kcm_SystemConfig.Get(7).GetSystemSetting() != 0;
				case "green":
					return kcm_SystemConfig.Get(20).GetSystemSetting() != 0;
				case "blue":
					return kcm_SystemConfig.Get(33).GetSystemSetting() != 0;
				case "purple":
					return kcm_SystemConfig.Get(46).GetSystemSetting() != 0;
				case "red":
					return kcm_SystemConfig.Get(59).GetSystemSetting() != 0;
			}
		}
		return false;
	}
	
	bool CanSpawnDrink(string color)
	{
		if(kcm_SystemConfig && color)
		{
			switch(color)
			{
				case "yellow":
					return kcm_SystemConfig.Get(8).GetSystemSetting() != 0;
				case "green":
					return kcm_SystemConfig.Get(21).GetSystemSetting() != 0;
				case "blue":
					return kcm_SystemConfig.Get(34).GetSystemSetting() != 0;
				case "purple":
					return kcm_SystemConfig.Get(47).GetSystemSetting() != 0;
				case "red":
					return kcm_SystemConfig.Get(60).GetSystemSetting() != 0;
			}
		}
		return false;
	}
	
	bool CanSpawnMeds(string color)
	{
		if(kcm_SystemConfig && color)
		{
			switch(color)
			{
				case "yellow":
					return kcm_SystemConfig.Get(76).GetSystemSetting() != 0;
				case "green":
					return kcm_SystemConfig.Get(77).GetSystemSetting() != 0;
				case "blue":
					return kcm_SystemConfig.Get(78).GetSystemSetting() != 0;
				case "purple":
					return kcm_SystemConfig.Get(79).GetSystemSetting() != 0;
				case "red":
					return kcm_SystemConfig.Get(80).GetSystemSetting() != 0;
			}
		}
		return false;
	}
	
	bool CanSpawnTools(string color)
	{
		if(kcm_SystemConfig && color)
		{
			switch(color)
			{
				case "yellow":
					return kcm_SystemConfig.Get(9).GetSystemSetting() != 0;
				case "green":
					return kcm_SystemConfig.Get(22).GetSystemSetting() != 0;
				case "blue":
					return kcm_SystemConfig.Get(35).GetSystemSetting() != 0;
				case "purple":
					return kcm_SystemConfig.Get(48).GetSystemSetting() != 0;
				case "red":
					return kcm_SystemConfig.Get(61).GetSystemSetting() != 0;
			}
		}
		return false;
	}
	
	bool CanSpawnBuildMats(string color)
	{
		if(kcm_SystemConfig && color)
		{
			switch(color)
			{
				case "yellow":
					return kcm_SystemConfig.Get(10).GetSystemSetting() != 0;
				case "green":
					return kcm_SystemConfig.Get(23).GetSystemSetting() != 0;
				case "blue":
					return kcm_SystemConfig.Get(36).GetSystemSetting() != 0;
				case "purple":
					return kcm_SystemConfig.Get(49).GetSystemSetting() != 0;
				case "red":
					return kcm_SystemConfig.Get(62).GetSystemSetting() != 0;
			}
		}
		return false;
	}
	
	bool CanSpawnValuables(string color)
	{
		if(kcm_SystemConfig && color)
		{
			switch(color)
			{
				case "yellow":
					return kcm_SystemConfig.Get(11).GetSystemSetting() != 0;
				case "green":
					return kcm_SystemConfig.Get(24).GetSystemSetting() != 0;
				case "blue":
					return kcm_SystemConfig.Get(37).GetSystemSetting() != 0;
				case "purple":
					return kcm_SystemConfig.Get(50).GetSystemSetting() != 0;
				case "red":
					return kcm_SystemConfig.Get(63).GetSystemSetting() != 0;
			}
		}
		return false;
	}
	
	bool CanSpawnClothes(string color)
	{
		if(kcm_SystemConfig && color)
		{
			switch(color)
			{
				case "yellow":
					return kcm_SystemConfig.Get(12).GetSystemSetting() != 0;
				case "green":
					return kcm_SystemConfig.Get(25).GetSystemSetting() != 0;
				case "blue":
					return kcm_SystemConfig.Get(38).GetSystemSetting() != 0;
				case "purple":
					return kcm_SystemConfig.Get(51).GetSystemSetting() != 0;
				case "red":
					return kcm_SystemConfig.Get(64).GetSystemSetting() != 0;
			}
		}
		return false;
	} //!The bool shit stops NOW!
	
	int ValuableSpawnChance(string color)
	{
		if(kcm_SystemConfig && color)
		{
			switch(color)
			{
				case "yellow":
					return kcm_SystemConfig.Get(11).GetSystemSetting();
				case "green":
					return kcm_SystemConfig.Get(24).GetSystemSetting();
				case "blue":
					return kcm_SystemConfig.Get(37).GetSystemSetting();
				case "purple":
					return kcm_SystemConfig.Get(50).GetSystemSetting();
				case "red":
					return kcm_SystemConfig.Get(63).GetSystemSetting();
			}
		}
		return 0;
	}	
		
	void SpawnLoop(string typeName, int count)
	{
		if(typeName && count)
		{
			for(int kcm = 0; kcm < count; kcm++)
			{
				GetInventory().CreateInInventory(typeName);
			}
		}
	}
	
	void GiveSideArm(string color)
	{
		KCM_SideArm sideArmLoadout = kcm_SideArms.GetRandomElement();
		EntityAI sideArm;
		int min, max, choice;
		string sideArmType, magazine, suppressor, optic, opticBattery, underBarrel, ammo;
		if(CanSpawnSideArm(color))
		{
			sideArmType = sideArmLoadout.GetWeapon();
			if(sideArmType && sideArmType != "")
			{
				sideArm = EntityAI.Cast(GetInventory().CreateInInventory(sideArmType));
				if(sideArm)
				{
					magazine = sideArmLoadout.GetMagazine();
					if(magazine && magazine != "")
					{
						GetInventory().CreateInInventory(magazine);
						if(CanSpawnSideMagsExtra(color))
						{
							min = kcm_BaseConfig.Get(0).GetBaseVar();
							max = kcm_BaseConfig.Get(1).GetBaseVar();
							choice = Math.RandomIntInclusive(min, max);
							SpawnLoop(magazine, choice);
						}
					}					
					
					ammo = sideArmLoadout.GetAmmo();
					if(ammo && ammo != "")
					{
						GetInventory().CreateInInventory(ammo);
						if(CanSpawnSideAmmoExtra(color))
						{
							min = kcm_BaseConfig.Get(10).GetBaseVar();
							max = kcm_BaseConfig.Get(11).GetBaseVar();
							choice = Math.RandomIntInclusive(min, max);
							SpawnLoop(ammo, choice);
						}
					}
					
					if(CanSpawnSideAttachments(color))
					{
						optic = sideArmLoadout.GetOptic();
						if(optic && optic != "")
						{
							sideArm.GetInventory().CreateAttachment(optic);
							opticBattery = sideArmLoadout.GetOpticBattery();
							if(opticBattery && opticBattery != "")
								sideArm.GetInventory().CreateInInventory(opticBattery);
						}
						
						suppressor = sideArmLoadout.GetSuppressor();
						if(suppressor && suppressor != "")
							sideArm.GetInventory().CreateAttachment(suppressor);
						
						underBarrel = sideArmLoadout.GetUnderBarrel();
						if(underBarrel && underBarrel != "")
							sideArm.GetInventory().CreateAttachment(underBarrel);
						if(underBarrel && underBarrel == "TLRLight")
							sideArm.GetInventory().CreateInInventory("Battery9V");
					}
				}
			}
		}
	}

	void GiveSustenance(string color)
	{
		string food, drink;
		int i, f_minEach, f_maxEach, f_minTypes, f_maxTypes, f_amount, f_amountPerType, d_minEach, d_maxEach, d_minTypes, d_maxTypes, d_amount, d_amountPerType;
		if(CanSpawnFood(color))
		{
			f_minTypes =  kcm_BaseConfig.Get(2).GetBaseVar();
			f_maxTypes =  kcm_BaseConfig.Get(3).GetBaseVar();
			f_minEach =  kcm_BaseConfig.Get(4).GetBaseVar();
			f_maxEach =  kcm_BaseConfig.Get(5).GetBaseVar();
			f_amount = Math.RandomIntInclusive(f_minTypes, f_maxTypes);
			f_amountPerType = Math.RandomIntInclusive(f_minEach, f_maxEach);
			for(i = 0; i < f_amount; i++)
			{
				food = kcm_FoodItems.GetRandomElement().GetFood();
				SpawnLoop(food, f_amountPerType);
			}
		}
		
		if(CanSpawnDrink(color))
		{
			d_minTypes = kcm_BaseConfig.Get(6).GetBaseVar();
			d_maxTypes = kcm_BaseConfig.Get(7).GetBaseVar();
			d_minEach = kcm_BaseConfig.Get(8).GetBaseVar();
			d_maxEach = kcm_BaseConfig.Get(9).GetBaseVar();
			d_amount = Math.RandomIntInclusive(d_minTypes, d_maxTypes);
			d_amountPerType = Math.RandomIntInclusive(d_minEach, d_maxEach);
			for(i = 0; i < d_amount; i++)
			{
				drink = kcm_DrinkItems.GetRandomElement().GetDrink();
				SpawnLoop(drink, d_amountPerType);
			}
		}
	}
	
	void GiveTools(string color)
	{
		string tool;
		int i, minTypes, maxTypes, minEach, maxEach, amount, amountPerType;
		if(CanSpawnTools(color))
		{
			minTypes = kcm_BaseConfig.Get(12).GetBaseVar();
			maxTypes = kcm_BaseConfig.Get(13).GetBaseVar();
			minEach = kcm_BaseConfig.Get(14).GetBaseVar();
			maxEach = kcm_BaseConfig.Get(15).GetBaseVar();
			amount = Math.RandomIntInclusive(minTypes, maxTypes);
			amountPerType = Math.RandomIntInclusive(minEach, maxEach);
			for(i = 0; i < amount; i++)
			{
				tool = kcm_ToolItems.GetRandomElement().GetTool();
				SpawnLoop(tool, amountPerType);
			}
		}
	}
	
	void GiveMeds(string color)
	{
		string med;
		int i, minTypes, maxTypes, minEach, maxEach, amount, amountPerType;
		if(CanSpawnMeds(color))
		{
			minTypes = kcm_BaseConfig.Get(16).GetBaseVar();
			maxTypes = kcm_BaseConfig.Get(17).GetBaseVar();
			minEach = kcm_BaseConfig.Get(18).GetBaseVar();
			maxEach = kcm_BaseConfig.Get(19).GetBaseVar();
			amount = Math.RandomIntInclusive(minTypes, maxTypes);
			amountPerType = Math.RandomIntInclusive(minEach, maxEach);
			for(i = 0; i < amount; i++)
			{
				med = kcm_MedicalItems.GetRandomElement().GetMeds();
				SpawnLoop(med, amountPerType);
			}
		}
	}
	
	void GiveBuildMats(string color)
	{
		string material;
		int i, minTypes, maxTypes, minEach, maxEach, amount, amountPerType;
		if(CanSpawnBuildMats(color))
		{
			minTypes = kcm_BaseConfig.Get(20).GetBaseVar();
			maxTypes = kcm_BaseConfig.Get(21).GetBaseVar();
			minEach = kcm_BaseConfig.Get(22).GetBaseVar();
			maxEach = kcm_BaseConfig.Get(23).GetBaseVar();
			amount = Math.RandomIntInclusive(minTypes, maxTypes);
			amountPerType = Math.RandomIntInclusive(minEach, maxEach);
			for(i = 0; i < amount; i++)
			{
				material = kcm_BuildingItems.GetRandomElement().GetMaterial();
				SpawnLoop(material, amountPerType);
			}
		}
	}
	
	void GiveValuables(string color)
	{
		string valuable;
		int i, minTypes, maxTypes, minEach, maxEach, amount, amountPerType, spawnChance;
		if(CanSpawnValuables(color))
		{
			minTypes = kcm_BaseConfig.Get(24).GetBaseVar();
			maxTypes = kcm_BaseConfig.Get(25).GetBaseVar();
			minEach = kcm_BaseConfig.Get(26).GetBaseVar();
			maxEach = kcm_BaseConfig.Get(27).GetBaseVar();
			amount = Math.RandomIntInclusive(minTypes, maxTypes);
			amountPerType = Math.RandomIntInclusive(minEach, maxEach);
			for(i = 0; i < amount; i++)
			{
				spawnChance = 100 - ValuableSpawnChance(color);
				if(Math.RandomIntInclusive(1, 100) > spawnChance)
				{
					valuable = kcm_Valuables.GetRandomElement().GetValuable();
					SpawnLoop(valuable, amountPerType);
				}
			}
		}
	}
	
	void DoTheDamnThing(string color)
	{
		GiveSideArm(color);
		GiveSustenance(color);
		GiveTools(color);
		GiveMeds(color);
		GiveBuildMats(color);
		GiveValuables(color);
		
		Print("DNA_Keycards: - A " + color + " tier crate has spawned loot at: " + GetPosition().ToString());
	}
};