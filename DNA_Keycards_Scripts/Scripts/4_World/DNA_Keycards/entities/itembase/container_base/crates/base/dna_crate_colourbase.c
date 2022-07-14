class DNA_Crate_ColourBase: Container_Base
{
	private bool dna_Debugged;
    private bool m_IsLocked;
	private ref Timer m_KCCrateOpener;
	protected ref OpenableBehaviour m_Openable;
	protected ref array<ref DNA_Config_Main_System> dna_MainSystemConfig;
	protected ref array<ref DNA_Config_Container_System> dna_ContainerSystemConfig;
	protected ref array<ref DNA_Config_Loot> dna_LootConfig;
	protected ref array<ref DNA_Config_Clothing> dna_ClothingConfig;
	protected ref array<ref DNA_Config_Weapons> dna_WeaponsConfig;
	
	protected autoptr array<Man> all_players = new array<Man>;
	
	/*! Used for separating config contents !*/
	protected autoptr array<DNA_Config_Weapons> dna_WeaponsSidearm = new array<DNA_Config_Weapons>;
	
	protected autoptr array<DNA_Config_Weapons> dna_YellowWeaponsMain = new array<DNA_Config_Weapons>;
	protected autoptr array<DNA_Config_Weapons> dna_GreenWeaponsMain = new array<DNA_Config_Weapons>;
	protected autoptr array<DNA_Config_Weapons> dna_BlueWeaponsMain = new array<DNA_Config_Weapons>;
	protected autoptr array<DNA_Config_Weapons> dna_PurpleWeaponsMain = new array<DNA_Config_Weapons>;
	protected autoptr array<DNA_Config_Weapons> dna_RedWeaponsMain = new array<DNA_Config_Weapons>;
	
	protected autoptr array<DNA_Config_Weapons> dna_YellowSidearm = new array<DNA_Config_Weapons>;
	protected autoptr array<DNA_Config_Weapons> dna_GreenSidearm = new array<DNA_Config_Weapons>;
	protected autoptr array<DNA_Config_Weapons> dna_BlueSidearm = new array<DNA_Config_Weapons>;
	protected autoptr array<DNA_Config_Weapons> dna_PurpleSidearm = new array<DNA_Config_Weapons>;
	protected autoptr array<DNA_Config_Weapons> dna_RedSidearm = new array<DNA_Config_Weapons>;
	
	protected autoptr array<DNA_Config_Clothing> dna_YellowClothing = new array<DNA_Config_Clothing>;
	protected autoptr array<DNA_Config_Clothing> dna_GreenClothing = new array<DNA_Config_Clothing>;
	protected autoptr array<DNA_Config_Clothing> dna_BlueClothing = new array<DNA_Config_Clothing>;
	protected autoptr array<DNA_Config_Clothing> dna_PurpleClothing = new array<DNA_Config_Clothing>;
	protected autoptr array<DNA_Config_Clothing> dna_RedClothing = new array<DNA_Config_Clothing>;
	
	protected autoptr array<string> dna_MedicalItems = new array<string>;
	protected autoptr array<string> dna_FoodItems = new array<string>;
	protected autoptr array<string> dna_DrinkItems = new array<string>;
	protected autoptr array<string> dna_ToolItems = new array<string>;
	protected autoptr array<string> dna_Materials = new array<string>;
	protected autoptr array<string> dna_Miscellaneous = new array<string>;
	
	protected autoptr array<string> dna_Proprietary_Yellow = new array<string>; //see about removing these autoptrs
	protected autoptr array<string> dna_Medical_Yellow = new array<string>;
	protected autoptr array<string> dna_Food_Yellow = new array<string>;
	protected autoptr array<string> dna_Drink_Yellow = new array<string>;
	protected autoptr array<string> dna_Tools_Yellow = new array<string>;
	protected autoptr array<string> dna_Materials_Yellow = new array<string>;
	protected autoptr array<string> dna_Valuables_Yellow = new array<string>;
	protected autoptr array<string> dna_Miscellaneous_Yellow = new array<string>;
	
	protected autoptr array<string> dna_Proprietary_Green = new array<string>; //see about removing these autoptrs
	protected autoptr array<string> dna_Medical_Green = new array<string>;
	protected autoptr array<string> dna_Food_Green = new array<string>;
	protected autoptr array<string> dna_Drink_Green = new array<string>;
	protected autoptr array<string> dna_Tools_Green = new array<string>;
	protected autoptr array<string> dna_Materials_Green = new array<string>;
	protected autoptr array<string> dna_Valuables_Green = new array<string>;
	protected autoptr array<string> dna_Miscellaneous_Green = new array<string>;
	
	protected autoptr array<string> dna_Proprietary_Blue = new array<string>; //see about removing these autoptrs
	protected autoptr array<string> dna_Medical_Blue = new array<string>;
	protected autoptr array<string> dna_Food_Blue = new array<string>;
	protected autoptr array<string> dna_Drink_Blue = new array<string>;
	protected autoptr array<string> dna_Tools_Blue = new array<string>;
	protected autoptr array<string> dna_Materials_Blue = new array<string>;
	protected autoptr array<string> dna_Valuables_Blue = new array<string>;
	protected autoptr array<string> dna_Miscellaneous_Blue = new array<string>;
	
	protected autoptr array<string> dna_Proprietary_Purple = new array<string>; //see about removing these refs
	protected autoptr array<string> dna_Medical_Purple = new array<string>;
	protected autoptr array<string> dna_Food_Purple = new array<string>;
	protected autoptr array<string> dna_Drink_Purple = new array<string>;
	protected autoptr array<string> dna_Tools_Purple = new array<string>;
	protected autoptr array<string> dna_Materials_Purple = new array<string>;
	protected autoptr array<string> dna_Valuables_Purple = new array<string>;
	protected autoptr array<string> dna_Miscellaneous_Purple = new array<string>;
	
	protected autoptr array<string> dna_Proprietary_Red = new array<string>;  //see about removing these refs
	protected autoptr array<string> dna_Medical_Red = new array<string>;
	protected autoptr array<string> dna_Food_Red = new array<string>;
	protected autoptr array<string> dna_Drink_Red = new array<string>;
	protected autoptr array<string> dna_Tools_Red = new array<string>;
	protected autoptr array<string> dna_Materials_Red = new array<string>;
	protected autoptr array<string> dna_Valuables_Red = new array<string>;
	protected autoptr array<string> dna_Miscellaneous_Red = new array<string>;
	
	
	/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
	
	
	/*! Used for getting random attachments!*/
	protected autoptr array<string> att_slots = new array<string>; //see about removing these refs
	protected autoptr array<string> inv_slots = new array<string>;
	protected autoptr array<string> allAttachments = new array<string>;
	protected autoptr array<string> optics = new array<string>;
	protected autoptr array<string> opticBatteries = new array<string>;
	protected autoptr array<string> muzzles = new array<string>;
	protected autoptr array<string> buttstocks = new array<string>;
	protected autoptr array<string> handguards = new array<string>;
	protected autoptr array<string> lights = new array<string>;
	protected autoptr array<string> wraps = new array<string>;
	protected autoptr array<string> magazineTypes = new array<string>;
	protected autoptr array<string> magazineTypesFiltered = new array<string>;
	protected autoptr array<string> ammunitionTypes = new array<string>;
	/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
	
	protected string dna_ContainerType;
	protected string dna_Tier;

	void DNA_Crate_ColourBase()
	{		
		if(GetGame().IsDedicatedServer())
		{
			dna_MainSystemConfig = DNA_Keycards_Main_System.GetInstance().GetConfig().GetConfigData().GetSystemArray();
			dna_ContainerSystemConfig = DNA_Keycards_Container_System.GetInstance().GetConfig().GetConfigData().GetSystemArray();
			dna_LootConfig = DNA_Keycards_Loot.GetInstance().GetConfig().GetConfigData().GetLootArray();
			dna_ClothingConfig = DNA_Keycards_Clothing.GetInstance().GetConfig().GetConfigData().GetClothingArray();
			dna_WeaponsConfig = DNA_Keycards_Weapons.GetInstance().GetConfig().GetConfigData().GetWeaponsArray();
			//GetGame().GetPlayers(all_players);
		}
		m_KCCrateOpener = new Timer();

		m_Openable = new OpenableBehaviour(false);
		
		dna_ContainerType = "crate";


		RegisterNetSyncVariableBool("m_Openable.m_IsOpened");
		RegisterNetSyncVariableBool("m_IsLocked");
		RegisterNetSyncVariableBool("m_IsSoundSynchRemote");
		RegisterNetSyncVariableBool("m_IsPlaceSound");
		AssortArrays();
		Lock();
	}
	
	override void Open()
	{
		m_Openable.Open();
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
	
	void TakeCardToSlot(PlayerBase player)
	{
		DNA_KeyCard_ColourBase cardInHand, keyCard;
		if(player && CastTo(cardInHand, player.GetItemInHands()))
		{
			int remainingUses = cardInHand.GetRemainingUses();
			keyCard = DNA_KeyCard_ColourBase.Cast(GetInventory().CreateAttachment(cardInHand.GetType()));
			keyCard.SetRemainingUses(remainingUses);
			cardInHand.Delete();
			/*InventoryLocation loc = new InventoryLocation();
			cardInHand.GetInventory().GetCurrentInventoryLocation(loc);
			player.GetInventory().ClearInventoryReservationEx(null, loc);
			player.GetHumanInventory().DropEntity(InventoryMode.SERVER, player, cardInHand);
			ServerTakeEntityAsAttachment(cardInHand);*/
		}
	}
	
	void ReturnCardToPlayer(PlayerBase player)
	{
		DNA_KeyCard_ColourBase keyCard = DNA_KeyCard_ColourBase.Cast(FindAttachmentBySlotName("KeyCard"));
		if(player && keyCard)
		{
			
			if(keyCard.GetRemainingUses() > 1 && keyCard.GetRemainingUses() < 11)
			{
				/*EntityAI item;
				if(CastTo(item, keyCard))
					player.TakeEntityToHandsImpl(InventoryMode.SERVER, item);
				keyCard.SetRemainingUses(keyCard.GetRemainingUses() + -1);*/
				int uses = keyCard.GetRemainingUses();
				string cardType = keyCard.GetType();
				GetGame().ObjectDelete(keyCard);
				keyCard.DeleteSave();
				DNA_KeyCard_ColourBase newCard = DNA_KeyCard_ColourBase.Cast(player.GetHumanInventory().CreateInHands(cardType));
				newCard.SetRemainingUses(uses + -1);
				
			}
			else
			{
				GetGame().ObjectDelete(keyCard);
				keyCard.DeleteSave();
				player.GetHumanInventory().CreateInHands("DNA_KeyCard_Error");	
			}
		}
	}
	
	string ContainerType()
	{
		return dna_ContainerType;
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
	
	/*! This down here is a bunch of bool shit*/
	override bool IsOpen()
	{
		return m_Openable.IsOpened();
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
		return IsOpen();
	}
	
	bool CanReceiveAttachment (EntityAI attachment, int slotId) //! test to see if can be removed
	{
		return !IsOpen();
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
	//!The bool shit stops NOW!
	
	int ValuableSpawnChance()
	{
		int index, odds;
		switch(dna_Tier)
		{
			case "yellow":
				index = 34;
				break;
			case "green":
				index = 79;
				break;
			case "blue":
				index = 124;
				break;
			case "purple":
				index = 169;
				break;
			case "red":
				index = 214;
				break;
		}
		if(index && dna_ContainerSystemConfig)
		{
			switch(dna_ContainerType)
			{
				case"crate":
					odds = dna_ContainerSystemConfig.Get(index).GetCrateSetting();
					break;
				case"strongroom":
					odds = dna_ContainerSystemConfig.Get(index).GetStrongroomSetting();
					break;
			}
		}
		return odds;
	}
		
	void SpawnLoop(string typeName, int count)
	{
		if(typeName && count)
		{
			for(int dna = 0; dna < count; dna++)
			{
				if(typeName.Contains("Ammo") && !typeName.Contains("Box") && !typeName.Contains("box"))
				{
					Magazine ammo = Magazine.Cast(GetInventory().CreateInInventory(typeName));
					if(ammo)
					{
						if(typeName.Contains("RPG") || typeName.Contains("LAW"))
						{
							ammo.ServerSetAmmoCount(ammo.GetAmmoMax());
						}
						else
						{
							int min, max, qty;
							float min_f, max_f;
							max_f = ammo.GetAmmoMax();
							min_f = max_f / 2;
							min = Math.Round(min_f);
							max = Math.Round(max_f);
							qty = Math.RandomIntInclusive(min, max);
							ammo.ServerSetAmmoCount(qty);
						}
					}
				}
				else
				{
					GetInventory().CreateInInventory(typeName);
				}
			}
		}
	}	
	
	array<string> GetRandomWeaponLoadout()
	{
		string weaponType, magazine, ammo, optic, muzzle, buttStock, handGuard, underBarrel, wrap;
		DNA_Config_Weapons mainLoadout;
		if(dna_YellowWeaponsMain && dna_GreenWeaponsMain && dna_BlueWeaponsMain && dna_PurpleWeaponsMain && dna_RedWeaponsMain)
		{
			switch(dna_Tier)
			{
				case "yellow":
					mainLoadout = DNA_Config_Weapons.Cast(dna_YellowWeaponsMain.GetRandomElement());
					break;
					
				case "green":	
					mainLoadout = DNA_Config_Weapons.Cast(dna_GreenWeaponsMain.GetRandomElement());
					break;
					
				case "blue":	
					mainLoadout = DNA_Config_Weapons.Cast(dna_BlueWeaponsMain.GetRandomElement());
					break;
					
				case "purple":	
					mainLoadout = DNA_Config_Weapons.Cast(dna_PurpleWeaponsMain.GetRandomElement());	
					break;
					
				case "red":
					mainLoadout = DNA_Config_Weapons.Cast(dna_RedWeaponsMain.GetRandomElement());
					break;
			}
		}
		if(mainLoadout)
		{
			weaponType = mainLoadout.GetTheChosenOne();
			magazine = mainLoadout.GetMagazine();
			ammo = mainLoadout.GetAmmunition();
			optic = mainLoadout.GetOpticType();
			muzzle = mainLoadout.GetSuppressor();
			buttStock = mainLoadout.GetButtStock();
			handGuard = mainLoadout.GetHandGuard();
			underBarrel = mainLoadout.GetUnderBarrel();
			wrap = mainLoadout.GetWrap();
		}
		else
		{
			Print("WHAT THE FUCK IS GOING ONNNNNN?????");
			return NULL;
		}
		
		return {weaponType, magazine, ammo, optic, muzzle, buttStock, handGuard, underBarrel, wrap};
	}
	
	array<int> GetMWValues()
	{
		int min, minMag, minAmmo, max, maxMag, maxAmmo;
		if(dna_ContainerSystemConfig)
		{
			switch(dna_ContainerType)
			{
				case "strongroom":
					min = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "mainweapon", "min")).GetStrongroomSetting();
					max = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "mainweapon", "max")).GetStrongroomSetting();
					minMag = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "mainweaponmag", "min")).GetStrongroomSetting();
					maxMag = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "mainweaponmag", "max")).GetStrongroomSetting();
					minAmmo = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "mainweaponammo", "min")).GetStrongroomSetting();
					maxAmmo = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "mainweaponammo", "max")).GetStrongroomSetting();
					return {min, max, minMag, maxMag, minAmmo, maxAmmo};
					
				case "crate":
					min = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "mainweapon", "min")).GetCrateSetting();
					max = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "mainweapon", "max")).GetCrateSetting();
					minMag = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "mainweaponmag", "min")).GetCrateSetting();
					maxMag = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "mainweaponmag", "max")).GetCrateSetting(); 
					minAmmo = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "mainweaponammo", "min")).GetCrateSetting();
					maxAmmo = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "mainweaponammo", "max")).GetCrateSetting();
					return {min, max, minMag, maxMag, minAmmo, maxAmmo};
			}
		}
		return NULL;
	}

	void GiveMainWeapon()
	{
		Weapon_Base weapon;
		string weaponType, optic, muzzle, buttStock, handGuard, underBarrel, magazine, ammo, opticBattery, wrap; 
		int i, min, minMag, minAmmo, max, maxMag, maxAmmo, choice, magCount, ammoCount;
		array<int> mwValues = GetMWValues();
		min = mwValues.Get(0);
		max = mwValues.Get(1);
		minMag = mwValues.Get(2);
		maxMag = mwValues.Get(3);
		minAmmo = mwValues.Get(4);
		maxAmmo = mwValues.Get(5);
		if(min >= max)
		{
			choice = max;
		}
		else
		{
			choice = Math.RandomIntInclusive(min, max);
		}
		
		if(DNA_ConfigIndex.CanSpawn(DNA_ConfigIndex.GetIndex(dna_Tier, "mainweapon", "max"), dna_ContainerType))
		{
			for(i = 0; i < choice; i++)
			{
				array<string> mainLoadout = GetRandomWeaponLoadout();
				if(mainLoadout)
				{
					weaponType = mainLoadout.Get(0);
					magazine = mainLoadout.Get(1);
					ammo = mainLoadout.Get(2);
					optic = mainLoadout.Get(3);
					muzzle = mainLoadout.Get(4);
					buttStock = mainLoadout.Get(5);
					handGuard = mainLoadout.Get(6);
					underBarrel = mainLoadout.Get(7);
					wrap = mainLoadout.Get(8);
					mainLoadout.Clear();
				}
				if(weaponType && weaponType != "")
				{
					weapon = Weapon_Base.Cast(GetGame().CreateObjectEx(weaponType, GetWorldPosition(), ECE_PLACE_ON_SURFACE));
					if(weapon)
					{
						if(magazine && magazine != "")
						{
							if(magazine == "random")
								magazine = GetRandomAttachment(weaponType, "mags");
							
							if(magazine && magazine != "")
							{
								bool canSpawnMag = weapon.CF_SpawnMagazine(magazine);
								
								if(DNA_ConfigIndex.CanSpawn(DNA_ConfigIndex.GetIndex(dna_Tier, "mainweaponmag", "max"), dna_ContainerType))
								{
									if(minMag >= maxMag)
										magCount = maxMag;
									else
										magCount = Math.RandomIntInclusive(minMag, maxMag);
									
									SpawnLoop(magazine, magCount);
								}
							}
						}
						if(ammo && ammo != "")
						{
							if(ammo == "random")
								ammo = GetRandomAttachment(weaponType, "ammo");
							
							if(ammo && ammo != "")
							{
								GetInventory().CreateInInventory(ammo);
							
								if(DNA_ConfigIndex.CanSpawn(DNA_ConfigIndex.GetIndex(dna_Tier, "mainweaponammo", "max"), dna_ContainerType))
								{
									if(minAmmo >= maxAmmo)
										ammoCount = maxAmmo;
									else
										ammoCount = Math.RandomIntInclusive(minAmmo, maxAmmo);
									
									SpawnLoop(ammo, ammoCount);
								}
							}
						}
						if(DNA_ConfigIndex.CanSpawn(DNA_ConfigIndex.GetIndex(dna_Tier, "mainweaponattachment", ""), dna_ContainerType))
						{
							if(optic && optic != "")
							{
								if(optic == "random")
									optic = GetRandomAttachment(weaponType, "optic");
								
								GetGame().ConfigGetTextArray("CfgVehicles " + optic + " attachments", opticBatteries);
								if(opticBatteries && opticBatteries.Count() > 0)
								{
									if(opticBatteries.Get(0) == "BatteryD")
										opticBattery = "Battery9V";
								}
								opticBatteries.Clear();
								if(optic && optic != "")
									weapon.GetInventory().CreateAttachment(optic);
								if(opticBattery && opticBattery == "Battery9V")
									weapon.GetInventory().CreateInInventory(opticBattery);
							}
							
							if(muzzle && muzzle != "")
							{
								if(muzzle == "random")
									muzzle = GetRandomAttachment(weaponType, "muzzle");
								
								if(muzzle.Contains("Suppressor") || ("Compensator") || ("Bayonet"))
									weapon.GetInventory().CreateAttachment(muzzle);
							}
							
							if(buttStock && buttStock != "")
							{
								if(buttStock == "random")
								{
									buttStock = GetRandomAttachment(weaponType, "buttstock");
								}
								if(buttStock != "")
									weapon.GetInventory().CreateAttachment(buttStock);
							}
													
							if(handGuard && handGuard != "")
							{
								if(handGuard == "random")
								{
									handGuard = GetRandomAttachment(weaponType, "handguard");
								}
								if(handGuard != "")
									weapon.GetInventory().CreateAttachment(handGuard);	
							}
													
							if(underBarrel && underBarrel != "")
							{						
								if(underBarrel == "random")
								{
									if(handGuard && (handGuard.Contains("RisHndgrd") || handGuard.Contains("RailHndgrd") || handGuard.Contains("RISHndgrd")))
										underBarrel = GetRandomAttachment(weaponType, "light");
								}
								if(underBarrel != "")
								{
									weapon.GetInventory().CreateAttachment(underBarrel);
									weapon.GetInventory().CreateInInventory("Battery9V");
								}
							}
													
							if(wrap && wrap != "")
							{						
								if(wrap == "random")
								{
									wrap = GetRandomAttachment(weaponType, "wrap");
								}
								if(wrap != "")
									weapon.GetInventory().CreateAttachment(wrap);
							}							
						}
						ServerTakeEntityToTargetCargo(this, weapon);
					}
				}
			}
		}
	}	
	
	DNA_Config_Weapons GetRandomSideLoadout()
	{
		DNA_Config_Weapons sideLoadout;
		if(dna_MainSystemConfig && dna_MainSystemConfig.Get(17).GetSystemSetting() == 0)
		{
			sideLoadout = dna_WeaponsSidearm.GetRandomElement();
		}
		else
		{
			switch(dna_Tier)
			{
				case "yellow":
					sideLoadout = DNA_Config_Weapons.Cast(dna_YellowSidearm.GetRandomElement());
					break;
					
				case "green":	
					sideLoadout = DNA_Config_Weapons.Cast(dna_GreenSidearm.GetRandomElement());
					break;
					
				case "blue":	
					sideLoadout = DNA_Config_Weapons.Cast(dna_BlueSidearm.GetRandomElement());
					break;
					
				case "purple":	
					sideLoadout = DNA_Config_Weapons.Cast(dna_PurpleSidearm.GetRandomElement());	
					break;
					
				case "red":
					sideLoadout = DNA_Config_Weapons.Cast(dna_RedSidearm.GetRandomElement());
					break;
			}
		}
		
		return sideLoadout;//{weaponType, magazine, ammo, optic, muzzle, underBarrel};
	}
	
	array<int> GetSAValues()
	{
		int min, minMag, minAmmo, max, maxMag, maxAmmo;
		switch(dna_ContainerType)
		{
			case "strongroom":
				min = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "sidearm", "min")).GetStrongroomSetting();
				max = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "sidearm", "max")).GetStrongroomSetting();
				minMag = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "sidearmmag", "min")).GetStrongroomSetting();
				maxMag = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "sidearmmag", "max")).GetStrongroomSetting();
				minAmmo = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "sidearmammo", "min")).GetStrongroomSetting();
				maxAmmo = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "sidearmammo", "max")).GetStrongroomSetting();
				break;
				
			case "crate":
				min = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "sidearm", "min")).GetCrateSetting();
				max = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "sidearm", "max")).GetCrateSetting();
				minMag = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "sidearmmag", "min")).GetCrateSetting();
				maxMag = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "sidearmmag", "max")).GetCrateSetting(); 
				minAmmo = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "sidearmammo", "min")).GetCrateSetting();
				maxAmmo = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "sidearmammo", "max")).GetCrateSetting();
				break;
		}
		return {min, max, minMag, maxMag, minAmmo, maxAmmo};
	}
	
	void GiveSideArm() //! Edit to check if side arms are separated by tier or combined - get working like normal for meow
	{
		DNA_Config_Weapons sideArmLoadout = GetRandomSideLoadout();
		Weapon_Base sideArm;
		int i, min, max, minMag, maxMag, minAmmo, maxAmmo, choice, magCount, ammoCount;
		array<int> saValues = GetSAValues();
		min = saValues.Get(0);
		max = saValues.Get(1);
		minMag = saValues.Get(2);
		maxMag = saValues.Get(3);
		minAmmo = saValues.Get(4);
		maxAmmo = saValues.Get(5);
		if(min >= max)
		{
			choice = max;
		}
		else
		{
			choice = Math.RandomIntInclusive(min, max);
		}
		string sideArmType, magazine, muzzle, optic, opticBattery, underBarrel, ammo;
		if(DNA_ConfigIndex.CanSpawn(DNA_ConfigIndex.GetIndex(dna_Tier, "sidearm", "max"), dna_ContainerType))
		{
			for(i = 0; i < choice; i++)
			{
				sideArmType = sideArmLoadout.GetTheChosenOne();
				if(sideArmType && sideArmType != "")
				{
					sideArm = Weapon_Base.Cast(GetGame().CreateObjectEx(sideArmType, GetWorldPosition(), ECE_PLACE_ON_SURFACE));
					if(sideArm)
					{
						magazine = sideArmLoadout.GetMagazine();
						if(magazine && magazine != "")
						{
							if(magazine == "random")
								magazine = GetRandomAttachment(sideArmType, "mags");
							
							if(magazine.Contains("Mag"))
							{
								bool canSpawnMag = sideArm.CF_SpawnMagazine(magazine);
								
								if(DNA_ConfigIndex.CanSpawn(DNA_ConfigIndex.GetIndex(dna_Tier, "sidearmmag", "max"), dna_ContainerType))
								{
									if(minMag >= maxMag)
										magCount = maxMag;
									else
										magCount = Math.RandomIntInclusive(minMag, maxMag);
									
									if(magCount > 1)
										SpawnLoop(magazine, magCount);
									else
										GetInventory().CreateInInventory(magazine);
								}
							}
						}					
						ammo = sideArmLoadout.GetAmmunition();
						if(ammo && ammo != "")
						{
							if(ammo == "random")
								ammo = GetRandomAttachment(sideArmType, "ammo");
								
							if(ammo.Contains("Ammo"))
							{
								GetInventory().CreateInInventory(ammo);
								
								if(DNA_ConfigIndex.CanSpawn(DNA_ConfigIndex.GetIndex(dna_Tier, "sidearmammo", "max"), dna_ContainerType))
								{
									if(minAmmo >= maxAmmo)
										ammoCount = maxAmmo;
									else
										ammoCount = Math.RandomIntInclusive(min, max);
									
									SpawnLoop(ammo, ammoCount);
								}
							}
						}				
						if(DNA_ConfigIndex.CanSpawn(DNA_ConfigIndex.GetIndex(dna_Tier, "sidearmattachment", ""), dna_ContainerType))
						{
							optic = sideArmLoadout.GetOpticType();
							if(optic && optic != "")
							{
								if(optic == "random")
									optic = GetRandomAttachment(sideArmType, "optic");
								
								GetGame().ConfigGetTextArray("CfgVehicles " + optic + " attachments", opticBatteries);
								if(opticBatteries && opticBatteries.Count() > 0)
								{
									if(opticBatteries.Get(0) == "BatteryD")
										opticBattery = "Battery9V";
								}
								opticBatteries.Clear();
								if(optic != "random")
									sideArm.GetInventory().CreateAttachment(optic);
								
								if(opticBattery && opticBattery == "Battery9V")
									sideArm.GetInventory().CreateInInventory(opticBattery);
							}
							
							muzzle = sideArmLoadout.GetSuppressor();
							if(muzzle && muzzle != "")
							{
								if(muzzle == "random")
									muzzle = GetRandomAttachment(sideArmType, "muzzle");
								
								if(muzzle.Contains("Suppressor"))
									sideArm.GetInventory().CreateAttachment(muzzle);
							}
							underBarrel = sideArmLoadout.GetUnderBarrel();
							
							array<string> possiblePistols =
							{
								"Glock19",
								"FNX45",
								"CZ75",
								"Expansion_M9"
							};
							
							if(underBarrel && underBarrel != "" && (possiblePistols.Find(sideArmType) != -1 || sideArmType.Contains("1911"))) //1000 1911s fuck putting them in array...
							{
								if(underBarrel == "random")
									underBarrel = GetRandomAttachment(sideArmType, "light");
								
								if(underBarrel.Contains("Light"))
								{
									sideArm.GetInventory().CreateAttachment(underBarrel);
									sideArm.GetInventory().CreateInInventory("Battery9V");
								}
							}
						}
					}
				}
				ServerTakeEntityToTargetCargo(this, sideArm);
			}
		}
	}

	void GiveSustenance()
	{
		string food, drink;
		int i, f_minEach, f_maxEach, f_minTypes, f_maxTypes, f_amount, f_amountPerType, d_minEach, d_maxEach, d_minTypes, d_maxTypes, d_amount, d_amountPerType;
		if(DNA_ConfigIndex.CanSpawn(DNA_ConfigIndex.GetIndex(dna_Tier, "food", "maxT"), dna_ContainerType))
		{
			array<int> foodValues = GetFoodValues();
			f_minTypes =  foodValues.Get(0);
			f_maxTypes =  foodValues.Get(1);
			f_minEach =  foodValues.Get(2);
			f_maxEach =  foodValues.Get(3);
			if(f_minTypes >= f_maxTypes)
			{
				f_amount = f_maxTypes;
			}
			else
			{
				f_amount = Math.RandomIntInclusive(f_minTypes, f_maxTypes);
			}
			if(f_minEach >= f_maxEach)
			{
				f_amountPerType = f_maxEach;
			}
			else
			{
				f_amountPerType = Math.RandomIntInclusive(f_minEach, f_maxEach);
			}
			for(i = 0; i < f_amount; i++)
			{
				food = GetFoodType();
				SpawnLoop(food, f_amountPerType);
			}
		}
		
		if(DNA_ConfigIndex.CanSpawn(DNA_ConfigIndex.GetIndex(dna_Tier, "drink", "maxT"), dna_ContainerType))
		{
			array<int> drinkValues = GetDrinkValues();
			d_minTypes = drinkValues.Get(0);
			d_maxTypes = drinkValues.Get(1);
			d_minEach = drinkValues.Get(2);
			d_maxEach = drinkValues.Get(3);
			if(d_minTypes >= d_maxTypes)
			{
				d_amount = d_maxTypes;
			}
			else
			{
				d_amount = Math.RandomIntInclusive(d_minTypes, d_maxTypes);
			}
			if(d_minEach >= d_maxEach)
			{
				d_amountPerType = d_maxEach;
			}
			else
			{
				d_amountPerType = Math.RandomIntInclusive(d_minEach, d_maxEach);
			}
			for(i = 0; i < d_amount; i++)
			{
				drink = GetDrinkType();
				SpawnLoop(drink, d_amountPerType);
			}
		}
	}
	
	void GiveTools()
	{
		array<string> toolsReserve = {};
		string tool;
		int i, j, minTypes, maxTypes, minEach, maxEach, amount, amountPerType, localIndex;
		if(DNA_ConfigIndex.CanSpawn(DNA_ConfigIndex.GetIndex(dna_Tier, "tools", "maxT"), dna_ContainerType))
		{
			array<int> toolValues = GetToolValues();
			minTypes = toolValues.Get(0);
			maxTypes = toolValues.Get(1);
			minEach = toolValues.Get(2);
			maxEach = toolValues.Get(3);
			if(minTypes >= maxTypes)
			{
				amount = maxTypes;
			}
			else
			{
				amount = Math.RandomIntInclusive(minTypes, maxTypes);
			}
			if(minEach >= maxEach)
			{
				amountPerType = maxEach;
			}
			else
			{
				amountPerType = Math.RandomIntInclusive(minEach, maxEach);
			}
			if(dna_MainSystemConfig && dna_MainSystemConfig.Get(19).GetSystemSetting() == 0)
			{
				if(amount > dna_ToolItems.Count())
					amount = dna_ToolItems.Count();
			}
			else
			{
				switch(dna_Tier)
				{
					case "yellow":
						if(amount > dna_Tools_Yellow.Count())
							amount = dna_Tools_Yellow.Count();
						break;
						
					case "green":
						if(amount > dna_Tools_Green.Count())
							amount = dna_Tools_Green.Count();
						break;
						
					case "blue":
						if(amount > dna_Tools_Blue.Count())
							amount = dna_Tools_Blue.Count();
						break;
						
					case "purple":
						if(amount > dna_Tools_Purple.Count())
							amount = dna_Tools_Purple.Count();
						break;
						
					case "red":
						if(amount > dna_Tools_Red.Count())
							amount = dna_Tools_Red.Count();
						break;
				}
			}
			for(i = 0; i < amount; i++)
			{
				if(dna_MainSystemConfig && dna_MainSystemConfig.Get(19).GetSystemSetting() == 0)
				{
					tool = dna_ToolItems.GetRandomElement();
					localIndex = dna_ToolItems.Find(tool);
					dna_ToolItems.Remove(localIndex);
				}
				else
				{
					switch(dna_Tier)
					{
						case "yellow":
							tool = dna_Tools_Yellow.GetRandomElement();
							localIndex = dna_Tools_Yellow.Find(tool);
							dna_Tools_Yellow.Remove(localIndex);
							break;
							
						case "green":
							tool = dna_Tools_Green.GetRandomElement();
							localIndex = dna_Tools_Green.Find(tool);
							dna_Tools_Green.Remove(localIndex);
							break;
							
						case "blue":
							tool = dna_Tools_Blue.GetRandomElement();
							localIndex = dna_Tools_Blue.Find(tool);
							dna_Tools_Blue.Remove(localIndex);
							break;
							
						case "purple":
							tool = dna_Tools_Purple.GetRandomElement();
							localIndex = dna_Tools_Purple.Find(tool);
							dna_Tools_Purple.Remove(localIndex);
							break;
							
						case "red":
							tool = dna_Tools_Red.GetRandomElement();
							localIndex = dna_Tools_Red.Find(tool);
							dna_Tools_Red.Remove(localIndex);
							break;
					}
				}
				toolsReserve.Insert(tool);
				SpawnLoop(tool, amountPerType);
			}
			for(j = 0; j < toolsReserve.Count(); j++)
			{				
				if(dna_MainSystemConfig && dna_MainSystemConfig.Get(19).GetSystemSetting() == 0)
				{
					dna_ToolItems.Insert(toolsReserve.Get(j));
				}
				else
				{
					switch(dna_Tier)
					{
						case "yellow":
							dna_Tools_Yellow.Insert(toolsReserve.Get(j));
							break;
							
						case "green":
							dna_Tools_Green.Insert(toolsReserve.Get(j));
							break;
							
						case "blue":
							dna_Tools_Blue.Insert(toolsReserve.Get(j));
							break;
							
						case "purple":
							dna_Tools_Purple.Insert(toolsReserve.Get(j));
							break;
							
						case "red":
							dna_Tools_Red.Insert(toolsReserve.Get(j));
							break;
					}
				}
			}
			toolsReserve.Clear();
		}
	}
	
	void GiveMeds()
	{
		string med;
		int i, minTypes, maxTypes, minEach, maxEach, amount, amountPerType;
		if(DNA_ConfigIndex.CanSpawn(DNA_ConfigIndex.GetIndex(dna_Tier, "meds", "maxT"), dna_ContainerType))
		{
			array<int> medValues = GetMedicalValues();
			minTypes = medValues.Get(0);
			maxTypes = medValues.Get(1);
			minEach = medValues.Get(2);
			maxEach = medValues.Get(3);
			if(minTypes >= maxTypes)
			{
				amount = maxTypes;
			}
			else
			{
				amount = Math.RandomIntInclusive(minTypes, maxTypes);
			}
			if(minEach >= maxEach)
			{
				amountPerType = maxEach;
			}
			else
			{
				amountPerType = Math.RandomIntInclusive(minEach, maxEach);
			}
			for(i = 0; i < amount; i++)
			{
				med = GetMedicalType();
				SpawnLoop(med, amountPerType);
			}
		}
	}
	
	void GiveBuildMats()
	{
		string material;
		int i, minTypes, maxTypes, minEach, maxEach, amount, amountPerType;
		if(DNA_ConfigIndex.CanSpawn(DNA_ConfigIndex.GetIndex(dna_Tier, "build", "maxT"), dna_ContainerType))
		{
			array<int> materialValues = GetMaterialValues();
			minTypes = materialValues.Get(0);
			maxTypes = materialValues.Get(1);
			minEach = materialValues.Get(2);
			maxEach = materialValues.Get(3);
			if(minTypes >= maxTypes)
			{
				amount = maxTypes;
			}
			else
			{
				amount = Math.RandomIntInclusive(minTypes, maxTypes);
			}
			if(minEach >= maxEach)
			{
				amountPerType = maxEach;
			}
			else
			{
				amountPerType = Math.RandomIntInclusive(minEach, maxEach);
			}
			for(i = 0; i < amount; i++)
			{
				material = GetMaterialType();
				SpawnLoop(material, amountPerType);
			}
		}
	}

	void GiveOutfit() //! Edit to get new types  
	{
		string helm, shirt, vest, pants, shoes, back, gloves, belt, facewear, eyewear, armband, nvg;
		int i, min, max, count;
		DNA_Config_Clothing clothingSet;
		if(DNA_ConfigIndex.CanSpawn(DNA_ConfigIndex.GetIndex(dna_Tier, "clothing", "max"), dna_ContainerType))
		{
			array<int> clothingValues = GetClothingValues();
			min = clothingValues.Get(0);
			max = clothingValues.Get(1);
			if(min >= max)
			{
				count = max;
			}
			else
			{
				count = Math.RandomIntInclusive(min, max);
			}
			for(i = 0; i < count; i++)
			{
				switch(dna_Tier)
				{
					case "yellow":
					
						if(dna_YellowClothing)
							clothingSet = DNA_Config_Clothing.Cast(dna_YellowClothing.GetRandomElement());
						break;
						
					case "green":
					
						if(dna_GreenClothing)
							clothingSet = DNA_Config_Clothing.Cast(dna_GreenClothing.GetRandomElement());
						break;
						
					case "blue":
					
						if(dna_BlueClothing)
							clothingSet = DNA_Config_Clothing.Cast(dna_BlueClothing.GetRandomElement());
						break;
						
					case "purple":
					
						if(dna_PurpleClothing)
							clothingSet = DNA_Config_Clothing.Cast(dna_PurpleClothing.GetRandomElement());
						break;
						
					case "red":
					
						if(dna_RedClothing)
							clothingSet = DNA_Config_Clothing.Cast(dna_RedClothing.GetRandomElement());
						break;
				}
				helm = clothingSet.GetHelmet();
				shirt = clothingSet.GetShirt();
				vest = clothingSet.GetVest();
				pants = clothingSet.GetPants();
				shoes = clothingSet.GetShoes();
				back = clothingSet.GetBackpack();
				gloves = clothingSet.GetGloves();
				belt = clothingSet.GetBelt();
				facewear = clothingSet.GetFacewear();
				eyewear = clothingSet.GetEyewear();
				armband = clothingSet.GetArmband();
				nvg = clothingSet.GetNVG();
				
						
				if(helm && helm != "")
					GetInventory().CreateInInventory(helm);
				
				if(shirt && shirt != "")
					GetInventory().CreateInInventory(shirt);
				
				if(vest && vest != "")
					GetInventory().CreateInInventory(vest);
				
				if(pants && pants != "")
					GetInventory().CreateInInventory(pants);
				
				if(shoes && shoes != "")
					GetInventory().CreateInInventory(shoes);
				
				if(back && back != "")
					GetInventory().CreateInInventory(back);

				if(gloves && gloves != "")
					GetInventory().CreateInInventory(gloves);

				if(belt && belt != "")
					GetInventory().CreateInInventory(belt);

				if(facewear && facewear != "")
					GetInventory().CreateInInventory(facewear);

				if(eyewear && eyewear != "")
					GetInventory().CreateInInventory(eyewear);

				if(armband && armband != "")
					GetInventory().CreateInInventory(armband);

				if(nvg && nvg != "")
				{
					GetInventory().CreateInInventory(nvg);
					GetInventory().CreateInInventory("Battery9V");
				}
			}
		}	
	}
	
	void GiveValuables()
	{
		array<string> valuableReserve = {};
		string valuable;
		int i, minTypes, maxTypes, minEach, maxEach, amount, amountPerType, spawnChance;
		if(DNA_ConfigIndex.CanSpawn(DNA_ConfigIndex.GetIndex(dna_Tier, "value", "maxT"), dna_ContainerType)) 
		{
			array<int> valuableValues = GetValuableValues();
			minTypes = valuableValues.Get(0);
			maxTypes = valuableValues.Get(1);
			minEach = valuableValues.Get(2);
			maxEach = valuableValues.Get(3);
			if(minTypes >= maxTypes)
			{
				amount = maxTypes;
			}
			else
			{
				amount = Math.RandomIntInclusive(minTypes, maxTypes);
			}
			if(minEach >= maxEach)
			{
				amountPerType = maxEach;
			}
			else
			{
				amountPerType = Math.RandomIntInclusive(minEach, maxEach);
			}
			switch(dna_Tier)
			{
				case "yellow":
					if(amount > dna_Valuables_Yellow.Count())
						amount = dna_Valuables_Yellow.Count();
					break;
					
				case "green":
					if(amount > dna_Valuables_Green.Count())
						amount = dna_Valuables_Green.Count();
					break;
					
				case "blue":
					if(amount > dna_Valuables_Blue.Count())
						amount = dna_Valuables_Blue.Count();
					break;
					
				case "purple":
					if(amount > dna_Valuables_Purple.Count())
						amount = dna_Valuables_Purple.Count();
					break;
					
				case "red":
					if(amount > dna_Valuables_Red.Count())
						amount = dna_Valuables_Red.Count();
					break;
			}
			for(i = 0; i < amount; i++)
			{
				spawnChance = 100 - ValuableSpawnChance(); 
				if(Math.RandomIntInclusive(1, 100) > spawnChance)
				{
					valuable = GetValuableType();
					valuableReserve.Insert(valuable);
					SpawnLoop(valuable, amountPerType);
				}
			}
			ReplaceValuables(valuableReserve);
			valuableReserve.Clear();
		}
	}
	
	void GiveMiscellaneous() 
	{
		string miscItem;
		int i, minTypes, maxTypes, minEach, maxEach, amount, amountPerType, spawnChance;
		if(DNA_ConfigIndex.CanSpawn(DNA_ConfigIndex.GetIndex(dna_Tier, "value", "maxT"), dna_ContainerType))
		{
			array<int> miscValues = GetMiscValues();
			minTypes = miscValues.Get(0);
			maxTypes = miscValues.Get(1);
			minEach = miscValues.Get(2);
			maxEach = miscValues.Get(3);
			if(minTypes >= maxTypes)
			{
				amount = maxTypes;
			}
			else
			{
				amount = Math.RandomIntInclusive(minTypes, maxTypes);
			}
			if(minEach >= maxEach)
			{
				amountPerType = maxEach;
			}
			else
			{
				amountPerType = Math.RandomIntInclusive(minEach, maxEach);
			}
			for(i = 0; i < amount; i++)
			{
				miscItem = GetMiscType();
				SpawnLoop(miscItem, amountPerType);
			}
		}
	}
	
	void SpawnProprietaryItems()
	{
		int i;
		string itemToSpawn;
		switch(dna_Tier)
		{
			case "yellow":
				for(i = 0; i < dna_Proprietary_Yellow.Count(); i++)
				{
					itemToSpawn = dna_Proprietary_Yellow.Get(i);
					if(itemToSpawn && itemToSpawn != "")	
						GetInventory().CreateInInventory(itemToSpawn);
				}
				break;
				
			case "green":
				for(i = 0; i < dna_Proprietary_Green.Count(); i++)
				{
					itemToSpawn = dna_Proprietary_Green.Get(i);
					if(itemToSpawn && itemToSpawn != "")	
						GetInventory().CreateInInventory(itemToSpawn);
				}
				break;
				
			case "blue":
				for(i = 0; i < dna_Proprietary_Blue.Count(); i++)
				{
					itemToSpawn = dna_Proprietary_Blue.Get(i);
					if(itemToSpawn && itemToSpawn != "")	
						GetInventory().CreateInInventory(itemToSpawn);
				}
				break;
				
			case "purple":
				for(i = 0; i < dna_Proprietary_Purple.Count(); i++)
				{
					itemToSpawn = dna_Proprietary_Purple.Get(i);
					if(itemToSpawn && itemToSpawn != "")	
						GetInventory().CreateInInventory(itemToSpawn);
				}
				break;
				
			case "red":
				for(i = 0; i < dna_Proprietary_Red.Count(); i++)
				{
					itemToSpawn = dna_Proprietary_Red.Get(i);
					if(itemToSpawn && itemToSpawn != "")	
						GetInventory().CreateInInventory(itemToSpawn);
				}
				break;
		}
	}
	
	void DoTheDamnThing()
	{
		GiveMainWeapon();
		GiveOutfit();
		GiveSideArm();
		GiveSustenance();
		GiveTools();
		GiveMeds();
		GiveBuildMats();
		GiveMiscellaneous();
		GiveValuables();
		SpawnProprietaryItems();
		NotifyPlayers();
		
		Print("DNA Keycards: " + GetGame().GetTime() + ": - A " + dna_Tier + " tier " + dna_ContainerType +" has spawned loot at: " + GetPosition().ToString());
		Lock();
	}
	
	bool NeedsOpticFilter(string type)
	{	
		array<string> typesForOpticFilter = //Doesn't need all variants or full classname. Just enough to use Contains() accurately
		{
			"UMP45",
			"MP5K",
			"HoneyBadger"
		};
		
		for(int i = 0; i < typesForOpticFilter.Count(); i++)
		{
			if(type.Contains(typesForOpticFilter.Get(i)))
				return true;
		}
		return false;
	}

	string GetRandomAttachment(string type, string slotParam)//! Edit to get random guille wraps, and POSSIBLY to work with Morty's and SNAFU --FMLLLL!!!
	{
		string configPath, config_Path, childName, att_slot, inv_slot, attachment, rdmAttachment, filteredMag, badOptic;
		configPath = "CfgWeapons";
		int g, h, i, j, k, l, m, childCount, scope;
		bool check;
		
		
		if(GetGame().ConfigIsExisting(configPath + " " + type))
		{
			GetGame().ConfigGetTextArray(configPath + " " + type + " attachments", att_slots);
			GetGame().ConfigGetTextArray(configPath + " " + type + " magazines", magazineTypes);
			GetGame().ConfigGetTextArray(configPath + " " + type + " chamberableFrom", ammunitionTypes);
			array<string> pathing =
			{
				"CfgVehicles",
				"CfgWeapons",
				"CfgMagazines"
			};
			
			dna_Debugged = false;
			
			for(h = 0; h < pathing.Count(); h++)
			{
				config_Path = pathing.Get(h);
				childCount = GetGame().ConfigGetChildrenCount(config_Path);
				for(i = 0; i < childCount; i++)
				{					
					GetGame().ConfigGetChildName(config_Path, i, childName);
					scope = GetGame().ConfigGetInt(config_Path + " " + childName + " scope");
					check = 1;
					if(GetGame().ConfigIsExisting(config_Path + " " + childName + " inventorySlot"))
					{
						if(scope && config_Path == "CfgVehicles" && scope <= 1)
						{
							check = 0;
						}
						if(check)
						{
							GetGame().ConfigGetTextArray(config_Path + " " + childName + " inventorySlot", inv_slots);
							for(j = 0; j < att_slots.Count(); j++)
							{
								for(k = 0; k < inv_slots.Count(); k++)
								{
									att_slot = att_slots.Get(j);
									att_slot.ToLower();
									inv_slot = inv_slots.Get(k);
									inv_slot.ToLower();
									if(att_slot == inv_slot)
									{
										allAttachments.Insert(childName);
										continue;
									}
								}
							}
						}
					}
				}
			}
			for(l = 0; l < allAttachments.Count(); l++)
			{
				attachment = allAttachments.Get(l);
				if(attachment.Contains("Optic"))
					optics.Insert(attachment);
				
				if(NeedsOpticFilter(type))
				{
					for(m = 0; m < optics.Count(); m++)
					{
						badOptic = optics.Get(m);
						if(badOptic.Contains("CarryHandle") || badOptic.Contains("BUIS"))
						{
							optics.Remove(m);
							//Print("DNA KEYCARDS ARRAY DEBUG: Removing Bad Optic - " + badOptic);
						}
					}
				}
					
				if(attachment.Contains("Suppressor"))
					muzzles.Insert(attachment);
					
				if(attachment.Contains("Bayonet"))
					muzzles.Insert(attachment);
					
				if(attachment.Contains("Compensator"))
					muzzles.Insert(attachment);
					
				if(attachment.Contains("Light"))
					lights.Insert(attachment);
					
				if(attachment.Contains("ANPEQ15") && !attachment.Contains("Base") && !attachment.Contains("IR"))
					lights.Insert(attachment);
					
				if(attachment.Contains("Bttstck"))
					buttstocks.Insert(attachment);
					
				if(attachment.Contains("Hndgrd"))
					handguards.Insert(attachment);
				
				if(attachment.Contains("Handguard"))
					handguards.Insert(attachment);
				
				if(attachment.Contains("Ghillie"))
					wraps.Insert(attachment);
			}
			for(g = 0; g < magazineTypes.Count(); g++)
			{
				filteredMag = magazineTypes.Get(g);
				if(!filteredMag.Contains("SFC"))
				{
					magazineTypesFiltered.Insert(filteredMag);				
				}/*
				else
				{
					Print("DNA KEYCARDS ARRAY DEBUG: Removing Bad Mag - " + filteredMag);
				}*/
			}
			int indexToDelete;// = muzzles.Find("Groza_Barrel_Suppressor");
			array<string> badMuzzles =
			{
				"Groza_Barrel_Suppressor",
				"MakarovPBSuppressor"
			};
			for(indexToDelete = 0; indexToDelete < muzzles.Count(); indexToDelete++)
			{
				if(badMuzzles.Find(muzzles.Get(indexToDelete)) != -1)
				{
					//Print("DNA KEYCARDS ARRAY DEBUG: Broken Suppressor found, removing - " + muzzles.Get(indexToDelete));
					muzzles.Remove(indexToDelete);
				}
			}
			//DebugAttachmentArrays();
			switch(slotParam)
			{
				case "optic":
					rdmAttachment = optics.GetRandomElement();
					break;
				
				case "muzzle":
					rdmAttachment = muzzles.GetRandomElement();
					break;
					
				case "buttstock":
					rdmAttachment = buttstocks.GetRandomElement();
					break;
				
				case "handguard":
					rdmAttachment = handguards.GetRandomElement();
					break;
				
				case "light":
					rdmAttachment = lights.GetRandomElement();
					break;
				
				case "mags":
					rdmAttachment = magazineTypesFiltered.GetRandomElement();
					break;
				
				case "ammo":
					rdmAttachment = ammunitionTypes.GetRandomElement();
					break;
				
				case "wrap":
					rdmAttachment = wraps.GetRandomElement();
					break;
			}
		}
		ClearAttachmentArrays();
		dna_Debugged = false;
		return rdmAttachment;
	}
	
	void DebugAttachmentArrays()
	{
		if(!dna_Debugged)
		{
			Print("DNA KEYCARDS ARRAY DEBUG");
			//att_slots.Debug();
			//inv_slots.Debug();
			//Print("DNA KEYCARDS ALL ATTACHMENTS DEBUG");
			//allAttachments.Debug();
			//Print("DNA KEYCARDS UNFILTERED MAGS DEBUG");
			//magazineTypes.Debug();
			//Print("DNA KEYCARDS FILTERED MAGS DEBUG");
			//magazineTypesFiltered.Debug();
			//ammunitionTypes.Debug();
			//optics.Debug();
			//muzzles.Debug();
			//buttstocks.Debug();
			//handguards.Debug();
			//Print("DNA KEYCARDS UNDERBARREL DEBUG");
			//lights.Debug();
			//wraps.Debug();
			dna_Debugged = true;
		}
	}
	
	void ClearAttachmentArrays()
	{
		att_slots.Clear();
		inv_slots.Clear();
		allAttachments.Clear();
		magazineTypes.Clear();
		magazineTypesFiltered.Clear();
		ammunitionTypes.Clear();
		optics.Clear();
		muzzles.Clear();
		buttstocks.Clear();
		handguards.Clear();
		lights.Clear();
		wraps.Clear();
	}
	
	array<int> GetFoodValues()
	{
		int minTypes, minEach, maxTypes, maxEach;
		switch(dna_ContainerType)
		{
			case "strongroom":
				minTypes = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "food", "minT")).GetStrongroomSetting();
				maxTypes = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "food", "maxT")).GetStrongroomSetting();
				minEach = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "food", "minE")).GetStrongroomSetting();
				maxEach = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "food", "maxE")).GetStrongroomSetting();
				break;
				
			case "crate":
				minTypes = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "food", "minT")).GetCrateSetting();
				maxTypes = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "food", "maxT")).GetCrateSetting();
				minEach = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "food", "minE")).GetCrateSetting();
				maxEach = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "food", "maxE")).GetCrateSetting();
				break;
		}
		return {minTypes, maxTypes, minEach, maxEach};
	}
	
	array<int> GetDrinkValues()
	{
		int minTypes, minEach, maxTypes, maxEach;
		switch(dna_ContainerType)
		{
			case "strongroom":
				minTypes = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "drink", "minT")).GetStrongroomSetting();
				maxTypes = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "drink", "maxT")).GetStrongroomSetting();
				minEach = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "drink", "minE")).GetStrongroomSetting();
				maxEach = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "drink", "maxE")).GetStrongroomSetting();
				break;
				
			case "crate":
				minTypes = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "drink", "minT")).GetCrateSetting();
				maxTypes = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "drink", "maxT")).GetCrateSetting();
				minEach = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "drink", "minE")).GetCrateSetting();
				maxEach = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "drink", "maxE")).GetCrateSetting();
				break;
		}
		return {minTypes, maxTypes, minEach, maxEach};
	}
	
	array<int> GetToolValues()
	{
		int minTypes, minEach, maxTypes, maxEach;
		switch(dna_ContainerType)
		{
			case "strongroom":
				minTypes = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "tools", "minT")).GetStrongroomSetting();
				maxTypes = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "tools", "maxT")).GetStrongroomSetting();
				minEach = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "tools", "minE")).GetStrongroomSetting();
				maxEach = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "tools", "maxE")).GetStrongroomSetting();
				break;
				
			case "crate":
				minTypes = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "tools", "minT")).GetCrateSetting();
				maxTypes = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "tools", "maxT")).GetCrateSetting();
				minEach = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "tools", "minE")).GetCrateSetting();
				maxEach = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "tools", "maxE")).GetCrateSetting();
				break;
		}
		return {minTypes, maxTypes, minEach, maxEach};
	}
	
	array<int> GetMaterialValues()
	{
		int minTypes, minEach, maxTypes, maxEach;
		switch(dna_ContainerType)
		{
			case "strongroom":
				minTypes = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "build", "minT")).GetStrongroomSetting();
				maxTypes = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "build", "maxT")).GetStrongroomSetting();
				minEach = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "build", "minE")).GetStrongroomSetting();
				maxEach = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "build", "maxE")).GetStrongroomSetting();
				break;
				
			case "crate":
				minTypes = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "build", "minT")).GetCrateSetting();
				maxTypes = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "build", "maxT")).GetCrateSetting();
				minEach = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "build", "minE")).GetCrateSetting();
				maxEach = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "build", "maxE")).GetCrateSetting();
				break;
		}
		return {minTypes, maxTypes, minEach, maxEach};
	}
	
	array<int> GetValuableValues()
	{
		int minTypes, minEach, maxTypes, maxEach;
		switch(dna_ContainerType)
		{
			case "strongroom":
				minTypes = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "value", "minT")).GetStrongroomSetting();
				maxTypes = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "value", "maxT")).GetStrongroomSetting();
				minEach = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "value", "minE")).GetStrongroomSetting();
				maxEach = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "value", "maxE")).GetStrongroomSetting();
				break;
				
			case "crate":
				minTypes = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "value", "minT")).GetCrateSetting();
				maxTypes = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "value", "maxT")).GetCrateSetting();
				minEach = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "value", "minE")).GetCrateSetting();
				maxEach = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "value", "maxE")).GetCrateSetting();
				break;
		}
		return {minTypes, maxTypes, minEach, maxEach};
	}
	
	array<int> GetMedicalValues()
	{
		int minTypes, minEach, maxTypes, maxEach;
		switch(dna_ContainerType)
		{
			case "strongroom":
				minTypes = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "meds", "minT")).GetStrongroomSetting();
				maxTypes = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "meds", "maxT")).GetStrongroomSetting();
				minEach = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "meds", "minE")).GetStrongroomSetting();
				maxEach = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "meds", "maxE")).GetStrongroomSetting();
				break;
				
			case "crate":
				minTypes = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "meds", "minT")).GetCrateSetting();
				maxTypes = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "meds", "maxT")).GetCrateSetting();
				minEach = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "meds", "minE")).GetCrateSetting();
				maxEach = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "meds", "maxE")).GetCrateSetting();
				break;
		}
		return {minTypes, maxTypes, minEach, maxEach};
	}
	
	array<int> GetMiscValues()
	{
		int minTypes, minEach, maxTypes, maxEach;
		switch(dna_ContainerType)
		{
			case "strongroom":
				minTypes = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "misc", "minT")).GetStrongroomSetting();
				maxTypes = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "misc", "maxT")).GetStrongroomSetting();
				minEach = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "misc", "minE")).GetStrongroomSetting();
				maxEach = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "misc", "maxE")).GetStrongroomSetting();
				break;
				
			case "crate":
				minTypes = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "misc", "minT")).GetCrateSetting();
				maxTypes = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "misc", "maxT")).GetCrateSetting();
				minEach = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "misc", "minE")).GetCrateSetting();
				maxEach = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "misc", "maxE")).GetCrateSetting();
				break;
		}
		return {minTypes, maxTypes, minEach, maxEach};
	}
	
	array<int> GetClothingValues()
	{
		int minTypes, minEach, maxTypes, maxEach;
		switch(dna_ContainerType)
		{
			case "strongroom":
				minEach = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "clothing", "min")).GetStrongroomSetting();
				maxEach = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "clothing", "max")).GetStrongroomSetting();
				break;
				
			case "crate":
				minEach = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "clothing", "min")).GetCrateSetting();
				maxEach = dna_ContainerSystemConfig.Get(DNA_ConfigIndex.GetIndex(dna_Tier, "clothing", "max")).GetCrateSetting();
				break;
		}
		return {minEach, maxEach};
	}

	string GetFoodType()
	{
		string food;
		
		if(dna_MainSystemConfig && dna_MainSystemConfig.Get(18).GetSystemSetting() == 0)
		{
			food = dna_FoodItems.GetRandomElement();
		}
		else
		{
			switch(dna_Tier)
			{
				case "yellow":
					food = dna_Food_Yellow.GetRandomElement();
					break;
					
				case "green":
					food = dna_Food_Green.GetRandomElement();
					break;
					
				case "blue":
					food = dna_Food_Blue.GetRandomElement();
					break;
					
				case "purple":
					food = dna_Food_Purple.GetRandomElement();
					break;
					
				case "red":
					food = dna_Food_Red.GetRandomElement();
					break;
			}
		}
		return food;
	}

	string GetDrinkType()
	{
		string drink;
		
		if(dna_MainSystemConfig && dna_MainSystemConfig.Get(18).GetSystemSetting() == 0)
		{
			drink = dna_DrinkItems.GetRandomElement();
		}
		else
		{
			switch(dna_Tier)
			{
				case "yellow":
					drink = dna_Drink_Yellow.GetRandomElement();
					break;
					
				case "green":
					drink = dna_Drink_Green.GetRandomElement();
					break;
					
				case "blue":
					drink = dna_Drink_Blue.GetRandomElement();
					break;
					
				case "purple":
					drink = dna_Drink_Purple.GetRandomElement();
					break;
					
				case "red":
					drink = dna_Drink_Red.GetRandomElement();
					break;
			}
		}
		return drink;
	}

	string GetMaterialType()
	{
		string material;
		
		if(dna_MainSystemConfig && dna_MainSystemConfig.Get(21).GetSystemSetting() == 0)
		{
			material = dna_Materials.GetRandomElement();
		}
		else
		{
			switch(dna_Tier)
			{
				case "yellow":
					material = dna_Materials_Yellow.GetRandomElement();
					break;
					
				case "green":
					material = dna_Materials_Green.GetRandomElement();
					break;
					
				case "blue":
					material = dna_Materials_Blue.GetRandomElement();
					break;
					
				case "purple":
					material = dna_Materials_Purple.GetRandomElement();
					break;
					
				case "red":
					material = dna_Materials_Red.GetRandomElement();
					break;
			}
		}
		return material;
	}

	string GetMedicalType()
	{
		string medType;
		
		if(dna_MainSystemConfig && dna_MainSystemConfig.Get(20).GetSystemSetting() == 0)
		{
			medType = dna_MedicalItems.GetRandomElement();
		}
		else
		{
			switch(dna_Tier)
			{
				case "yellow":
					medType = dna_Medical_Yellow.GetRandomElement();
					break;
					
				case "green":
					medType = dna_Medical_Green.GetRandomElement();
					break;
					
				case "blue":
					medType = dna_Medical_Blue.GetRandomElement();
					break;
					
				case "purple":
					medType = dna_Medical_Purple.GetRandomElement();
					break;
					
				case "red":
					medType = dna_Medical_Red.GetRandomElement();
					break;
			}
		}
		return medType;
	}

	string GetMiscType()
	{
		string miscItem;
		
		if(dna_MainSystemConfig && dna_MainSystemConfig.Get(22).GetSystemSetting() == 0)
		{
			miscItem = dna_Miscellaneous.GetRandomElement();
		}
		else
		{
			switch(dna_Tier)
			{
				case "yellow":
					miscItem = dna_Miscellaneous_Yellow.GetRandomElement();
					break;
					
				case "green":
					miscItem = dna_Miscellaneous_Green.GetRandomElement();
					break;
					
				case "blue":
					miscItem = dna_Miscellaneous_Blue.GetRandomElement();
					break;
					
				case "purple":
					miscItem = dna_Miscellaneous_Purple.GetRandomElement();
					break;
					
				case "red":
					miscItem = dna_Miscellaneous_Red.GetRandomElement();
					break;
			}
		}
		return miscItem;
	}

	string GetValuableType()
	{
		int localIndex;
		string valuable;
		
		switch(dna_Tier)
		{
			case "yellow":
				valuable = dna_Valuables_Yellow.GetRandomElement();
				localIndex = dna_Valuables_Yellow.Find(valuable);
				dna_Valuables_Yellow.Remove(localIndex);
				break;
				
			case "green":
				valuable = dna_Valuables_Green.GetRandomElement();
				localIndex = dna_Valuables_Green.Find(valuable);
				dna_Valuables_Green.Remove(localIndex);
				break;
				
			case "blue":
				valuable = dna_Valuables_Blue.GetRandomElement();
				localIndex = dna_Valuables_Blue.Find(valuable);
				dna_Valuables_Blue.Remove(localIndex);
				break;
				
			case "purple":
				valuable = dna_Valuables_Purple.GetRandomElement();
				localIndex = dna_Valuables_Purple.Find(valuable);
				dna_Valuables_Purple.Remove(localIndex);
				break;
				
			case "red":
				valuable = dna_Valuables_Red.GetRandomElement();
				localIndex = dna_Valuables_Red.Find(valuable);
				dna_Valuables_Red.Remove(localIndex);
				break;
		}
		return valuable;
	}
	
	void ReplaceValuables(array<string> valuables)
	{
		for(int i = 0; i < valuables.Count(); i++)
		{
		
			switch(dna_Tier)
			{
				case "yellow":
					dna_Valuables_Yellow.Insert(valuables[i]);
					break;
					
				case "green":
					dna_Valuables_Green.Insert(valuables[i]);
					break;
					
				case "blue":
					dna_Valuables_Blue.Insert(valuables[i]);
					break;
					
				case "purple":
					dna_Valuables_Purple.Insert(valuables[i]);
					break;
					
				case "red":
					dna_Valuables_Red.Insert(valuables[i]);
					break;
			}
		}
		valuables.Clear();
	}
	
	int GetAlarmSettings()
	{
		int index;
		switch(dna_ContainerType)
		{
			case"crate":
				switch(dna_Tier)
				{
					case"yellow":
						index = 48;
						break;
						
					case"green":
						index = 50;
						break;
						
					case"blue":
						index = 52;
						break;
						
					case"purple":
						index = 54;
						break;
						
					case"red":
						index = 56;
						break;
				}
				break;
			
			case"strongroom":
				switch(dna_Tier)
				{
					case"yellow":
						index = 26;
						break;
						
					case"green":
						index = 31;
						break;
						
					case"blue":
						index = 36;
						break;
						
					case"purple":
						index = 41;
						break;
						
					case"red":
						index = 46;
						break;
				}
				break;
		}
		if(!index)
		{
			Print("DNA KEYCARDS - ERROR - GetAlarmSettings() == NO INDEX FOUND");
			return -1;
		}
		return dna_MainSystemConfig.Get(index).GetSystemSetting();
	}

	void SoundAlarm()
	{
		if(GetAlarmSettings() == 1)
			GetRPCManager().SendRPC("DNA_Keycards_Client", "SoundAlarmBreach", new Param1<vector> (GetPosition() + "0.0 3.0 0.0"), true);
	}
	
	int GetNotificationSettings()
	{
		int index;
		switch(dna_ContainerType)
		{
			case"crate":
				switch(dna_Tier)
				{
					case"yellow":
						index = 49;
						break;
						
					case"green":
						index = 51;
						break;
						
					case"blue":
						index = 53;
						break;
						
					case"purple":
						index = 55;
						break;
						
					case"red":
						index = 57;
						break;
				}
				break;
			
			case"strongroom":
				switch(dna_Tier)
				{
					case"yellow":
						index = 27;
						break;
						
					case"green":
						index = 32;
						break;
						
					case"blue":
						index = 37;
						break;
						
					case"purple":
						index = 42;
						break;
						
					case"red":
						index = 47;
						break;
				}
				break;
		}
		if(!index)
		{
			Print("DNA KEYCARDS - ERROR - GetNotificationSettings() == NO INDEX FOUND");
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
			return;
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
					}
					else if(distance < notificationRange && distance > 10)
					{
						SendRadiusNotification(player, distance);
					}
				}
			}
		}
	}
	
	void SendRadiusNotification(PlayerBase player, float distance)
	{
		NotificationSystem.SendNotificationToPlayerIdentityExtended(player.GetIdentity(), 15.0, "DNA Security", "A " + dna_Tier + " tier "  + dna_ContainerType + " has been opened " + Math.Round(distance) + " meters from your location.", "DNA_Keycards_Scripts/icons/KCB.edds");
	}
	
	void AssortArrays()
	{
		int i, j, k;
		if(dna_ClothingConfig)
		{
			for(i = 0; i < dna_ClothingConfig.Count(); i++)
			{
				if(dna_ClothingConfig.Get(i).GetClothingTier() == "yellow")
					dna_YellowClothing.Insert(dna_ClothingConfig.Get(i));
					
				if(dna_ClothingConfig.Get(i).GetClothingTier() == "green")
					dna_GreenClothing.Insert(dna_ClothingConfig.Get(i));
					
				if(dna_ClothingConfig.Get(i).GetClothingTier() == "blue")
					dna_BlueClothing.Insert(dna_ClothingConfig.Get(i));
					
				if(dna_ClothingConfig.Get(i).GetClothingTier() == "purple")
					dna_PurpleClothing.Insert(dna_ClothingConfig.Get(i));
					
				if(dna_ClothingConfig.Get(i).GetClothingTier() == "red")
					dna_RedClothing.Insert(dna_ClothingConfig.Get(i));
			}
		}
		
		if(dna_LootConfig)
		{
			for(j = 0; j < dna_LootConfig.Count(); j++)
			{
				if(dna_LootConfig.Get(j).GetLootCategory() == "medical")
					dna_MedicalItems.Insert(dna_LootConfig.Get(j).GetLootType());
				
				if(dna_LootConfig.Get(j).GetLootCategory() == "food")
					dna_FoodItems.Insert(dna_LootConfig.Get(j).GetLootType());
				
				if(dna_LootConfig.Get(j).GetLootCategory() == "drink")
					dna_DrinkItems.Insert(dna_LootConfig.Get(j).GetLootType());
				
				if(dna_LootConfig.Get(j).GetLootCategory() == "tools")
					dna_ToolItems.Insert(dna_LootConfig.Get(j).GetLootType());
				
				if(dna_LootConfig.Get(j).GetLootCategory() == "material")
					dna_Materials.Insert(dna_LootConfig.Get(j).GetLootType());
				
				if(dna_LootConfig.Get(j).GetLootCategory() == "misc")
					dna_Miscellaneous.Insert(dna_LootConfig.Get(j).GetLootType());
				
				if(dna_LootConfig.Get(j).GetLootTier() == "yellow")
				{
					if(dna_LootConfig.Get(j).GetLootCategory() == "proprietary")
						dna_Proprietary_Yellow.Insert(dna_LootConfig.Get(j).GetLootType());
					
					if(dna_LootConfig.Get(j).GetLootCategory() == "medical")
						dna_Medical_Yellow.Insert(dna_LootConfig.Get(j).GetLootType());
					
					if(dna_LootConfig.Get(j).GetLootCategory() == "food")
						dna_Food_Yellow.Insert(dna_LootConfig.Get(j).GetLootType());
					
					if(dna_LootConfig.Get(j).GetLootCategory() == "drink")
						dna_Drink_Yellow.Insert(dna_LootConfig.Get(j).GetLootType());
					
					if(dna_LootConfig.Get(j).GetLootCategory() == "tools")
						dna_Tools_Yellow.Insert(dna_LootConfig.Get(j).GetLootType());
					
					if(dna_LootConfig.Get(j).GetLootCategory() == "material")
						dna_Materials_Yellow.Insert(dna_LootConfig.Get(j).GetLootType());
					
					if(dna_LootConfig.Get(j).GetLootCategory() == "valuable")
						dna_Valuables_Yellow.Insert(dna_LootConfig.Get(j).GetLootType());
					
					if(dna_LootConfig.Get(j).GetLootCategory() == "misc")
						dna_Miscellaneous_Yellow.Insert(dna_LootConfig.Get(j).GetLootType());
				}
					
				if(dna_LootConfig.Get(j).GetLootTier() == "green")
				{
					if(dna_LootConfig.Get(j).GetLootCategory() == "proprietary")
						dna_Proprietary_Green.Insert(dna_LootConfig.Get(j).GetLootType());
					
					if(dna_LootConfig.Get(j).GetLootCategory() == "medical")
						dna_Medical_Green.Insert(dna_LootConfig.Get(j).GetLootType());
					
					if(dna_LootConfig.Get(j).GetLootCategory() == "food")
						dna_Food_Green.Insert(dna_LootConfig.Get(j).GetLootType());
					
					if(dna_LootConfig.Get(j).GetLootCategory() == "drink")
						dna_Drink_Green.Insert(dna_LootConfig.Get(j).GetLootType());
					
					if(dna_LootConfig.Get(j).GetLootCategory() == "tools")
						dna_Tools_Green.Insert(dna_LootConfig.Get(j).GetLootType());
					
					if(dna_LootConfig.Get(j).GetLootCategory() == "material")
						dna_Materials_Green.Insert(dna_LootConfig.Get(j).GetLootType());
					
					if(dna_LootConfig.Get(j).GetLootCategory() == "valuable")
						dna_Valuables_Green.Insert(dna_LootConfig.Get(j).GetLootType());
					
					if(dna_LootConfig.Get(j).GetLootCategory() == "misc")
						dna_Miscellaneous_Green.Insert(dna_LootConfig.Get(j).GetLootType());
				}
					
				if(dna_LootConfig.Get(j).GetLootTier() == "blue")
				{
					if(dna_LootConfig.Get(j).GetLootCategory() == "proprietary")
						dna_Proprietary_Blue.Insert(dna_LootConfig.Get(j).GetLootType());
					
					if(dna_LootConfig.Get(j).GetLootCategory() == "medical")
						dna_Medical_Blue.Insert(dna_LootConfig.Get(j).GetLootType());
					
					if(dna_LootConfig.Get(j).GetLootCategory() == "food")
						dna_Food_Blue.Insert(dna_LootConfig.Get(j).GetLootType());
					
					if(dna_LootConfig.Get(j).GetLootCategory() == "drink")
						dna_Drink_Blue.Insert(dna_LootConfig.Get(j).GetLootType());
					
					if(dna_LootConfig.Get(j).GetLootCategory() == "tools")
						dna_Tools_Blue.Insert(dna_LootConfig.Get(j).GetLootType());
					
					if(dna_LootConfig.Get(j).GetLootCategory() == "material")
						dna_Materials_Blue.Insert(dna_LootConfig.Get(j).GetLootType());
					
					if(dna_LootConfig.Get(j).GetLootCategory() == "valuable")
						dna_Valuables_Blue.Insert(dna_LootConfig.Get(j).GetLootType());
					
					if(dna_LootConfig.Get(j).GetLootCategory() == "misc")
						dna_Miscellaneous_Blue.Insert(dna_LootConfig.Get(j).GetLootType());
				}
					
				if(dna_LootConfig.Get(j).GetLootTier() == "purple")
				{
					if(dna_LootConfig.Get(j).GetLootCategory() == "proprietary")
						dna_Proprietary_Purple.Insert(dna_LootConfig.Get(j).GetLootType());
					
					if(dna_LootConfig.Get(j).GetLootCategory() == "medical")
						dna_Medical_Purple.Insert(dna_LootConfig.Get(j).GetLootType());
					
					if(dna_LootConfig.Get(j).GetLootCategory() == "food")
						dna_Food_Purple.Insert(dna_LootConfig.Get(j).GetLootType());
					
					if(dna_LootConfig.Get(j).GetLootCategory() == "drink")
						dna_Drink_Purple.Insert(dna_LootConfig.Get(j).GetLootType());
					
					if(dna_LootConfig.Get(j).GetLootCategory() == "tools")
						dna_Tools_Purple.Insert(dna_LootConfig.Get(j).GetLootType());
					
					if(dna_LootConfig.Get(j).GetLootCategory() == "material")
						dna_Materials_Purple.Insert(dna_LootConfig.Get(j).GetLootType());
					
					if(dna_LootConfig.Get(j).GetLootCategory() == "valuable")
						dna_Valuables_Purple.Insert(dna_LootConfig.Get(j).GetLootType());
					
					if(dna_LootConfig.Get(j).GetLootCategory() == "misc")
						dna_Miscellaneous_Purple.Insert(dna_LootConfig.Get(j).GetLootType());
				}
					
				if(dna_LootConfig.Get(j).GetLootTier() == "red") //!!! CONVERT TO STRINGS, ONLY SAVE CLASSNAME IN RESPECTIVE ARRAYS
				{
					if(dna_LootConfig.Get(j).GetLootCategory() == "proprietary")
						dna_Proprietary_Red.Insert(dna_LootConfig.Get(j).GetLootType());
					
					if(dna_LootConfig.Get(j).GetLootCategory() == "medical")
						dna_Medical_Red.Insert(dna_LootConfig.Get(j).GetLootType());
					
					if(dna_LootConfig.Get(j).GetLootCategory() == "food")
						dna_Food_Red.Insert(dna_LootConfig.Get(j).GetLootType());
					
					if(dna_LootConfig.Get(j).GetLootCategory() == "drink")
						dna_Drink_Red.Insert(dna_LootConfig.Get(j).GetLootType());
					
					if(dna_LootConfig.Get(j).GetLootCategory() == "tools")
						dna_Tools_Red.Insert(dna_LootConfig.Get(j).GetLootType());
					
					if(dna_LootConfig.Get(j).GetLootCategory() == "material")
						dna_Materials_Red.Insert(dna_LootConfig.Get(j).GetLootType());
					
					if(dna_LootConfig.Get(j).GetLootCategory() == "valuable")
						dna_Valuables_Red.Insert(dna_LootConfig.Get(j).GetLootType());
					
					if(dna_LootConfig.Get(j).GetLootCategory() == "misc")
						dna_Miscellaneous_Red.Insert(dna_LootConfig.Get(j).GetLootType());
				}
			}
		}
		
		if(dna_WeaponsConfig)
		{
			for(k = 0; k < dna_WeaponsConfig.Count(); k++)
			{				
				if(dna_WeaponsConfig.Get(k).GetWeaponCategory() == "side")
					dna_WeaponsSidearm.Insert(dna_WeaponsConfig.Get(k));
				
				if(dna_WeaponsConfig.Get(k).GetWeaponTier() == "yellow")
				{
					if(dna_WeaponsConfig.Get(k).GetWeaponCategory() == "main")
						dna_YellowWeaponsMain.Insert(dna_WeaponsConfig.Get(k));
						
					if(dna_WeaponsConfig.Get(k).GetWeaponCategory() == "side")
						dna_YellowSidearm.Insert(dna_WeaponsConfig.Get(k));
				}
					
				if(dna_WeaponsConfig.Get(k).GetWeaponTier() == "green")
				{
					if(dna_WeaponsConfig.Get(k).GetWeaponCategory() == "main")
						dna_GreenWeaponsMain.Insert(dna_WeaponsConfig.Get(k));
					
					if(dna_WeaponsConfig.Get(k).GetWeaponCategory() == "side")
						dna_GreenSidearm.Insert(dna_WeaponsConfig.Get(k));
				}
					
				if(dna_WeaponsConfig.Get(k).GetWeaponTier() == "blue")
				{
					if(dna_WeaponsConfig.Get(k).GetWeaponCategory() == "main")
						dna_BlueWeaponsMain.Insert(dna_WeaponsConfig.Get(k));
					
					if(dna_WeaponsConfig.Get(k).GetWeaponCategory() == "side")
						dna_BlueSidearm.Insert(dna_WeaponsConfig.Get(k));
				}
					
				if(dna_WeaponsConfig.Get(k).GetWeaponTier() == "purple")
				{
					if(dna_WeaponsConfig.Get(k).GetWeaponCategory() == "main")
						dna_PurpleWeaponsMain.Insert(dna_WeaponsConfig.Get(k));
					
					if(dna_WeaponsConfig.Get(k).GetWeaponCategory() == "side")
						dna_PurpleSidearm.Insert(dna_WeaponsConfig.Get(k));
				}
					
				if(dna_WeaponsConfig.Get(k).GetWeaponTier() == "red")
				{
					if(dna_WeaponsConfig.Get(k).GetWeaponCategory() == "main")
						dna_RedWeaponsMain.Insert(dna_WeaponsConfig.Get(k));
					
					if(dna_WeaponsConfig.Get(k).GetWeaponCategory() == "side")
						dna_RedSidearm.Insert(dna_WeaponsConfig.Get(k));
				}
			}
		}
	}
}