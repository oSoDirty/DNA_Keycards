class DNA_Crate_Smol_ColourBase: DNA_Crate_ColourBase
{
	bool m_UseConfig;
	bool m_SpawnMainWeapons;
	bool m_RandomizeWeapons;
	int m_WeaponCount;
	ref array<ref DNA_Config_Weapons_Smol> m_WeaponTypes;
	bool m_SpawnLootSet1;
	bool m_RandomizeLootSet1;
	int m_LootSet1Count;
	ref array<string> m_LootSet1 = {};
	bool m_SpawnLootSet2;
	bool m_RandomizeLootSet2;
	int m_LootSet2Count;
	ref array<string> m_LootSet2 = {};
	bool m_SpawnLootSet3;
	bool m_RandomizeLootSet3;
	int m_LootSet3Count;
	ref array<string> m_LootSet3 = {};
	bool m_SpawnLootSet4;
	bool m_RandomizeLootSet4;
	int m_LootSet4Count;
	ref array<string> m_LootSet4 = {};
	static ref array<DNA_Crate_Smol_ColourBase> m_SmolCrates = new array<DNA_Crate_Smol_ColourBase>;
	
	void DNA_Crate_Smol_ColourBase()
	{
		if(GetGame().IsDedicatedServer())
			m_UseConfig = DNA_CrateSmol_Data.GetSettingsDescription().dna_UseConfig;
	}
	
	override void EEInit()
	{
		super.EEInit();
			m_SmolCrates.Insert(this);
	}
	
	void ~DNA_Crate_Smol_ColourBase()
	{
		if(m_SmolCrates)
		{
			int localIndex = m_SmolCrates.Find(this);
			if(localIndex >=0)
				m_SmolCrates.Remove(localIndex);
		}
	}
	
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionOpenSmolCrate);
	}
	
	void SpawnStuffSmol(array<string> items) // for use in 3rd party addons  <-- Keep in case people have made use of it.
	{
		if(items)
		{
			int i, count;
			string itemType;
			count = items.Count();
			for(i = 0; i < count; i++)
			{
				itemType = items.Get(i);
				GetInventory().CreateInInventory(itemType);
			}
		}
	}
	
	void SpawnTheShit()
	{
		if(m_UseConfig)
		{
			SpawnWeapons();
			SpawnLoot();
		}
	}
	
	void SpawnWeapons()
	{
		if(m_SpawnMainWeapons)
		{
			int spareMags, spareAmmo, i, j;
			string mag, ammo, optic, suppressor, underBarrel, buttStock, handGuard, wrap, weaponType;
			bool opticBattery, canSpawnMag;
			opticBattery = false;
			
			Weapon_Base weapon;
			
			DNA_Config_Weapons_Smol weaponSet;
			
			if(m_RandomizeWeapons)
			{
				for(i = 0; i < m_WeaponCount; i++)
				{
					weaponSet = m_WeaponTypes.GetRandomElement();
					if(weaponSet)
					{
						weaponType = weaponSet.dna_TheChosenOne;
						mag = weaponSet.dna_Magazine;
						spareMags = weaponSet.dna_SpareMagCount;
						ammo = weaponSet.dna_Ammunition;
						spareAmmo = weaponSet.dna_SpareAmmoCount;
						optic = weaponSet.dna_OpticType;
						suppressor = weaponSet.dna_Suppressor;
						underBarrel = weaponSet.dna_UnderBarrel;
						buttStock = weaponSet.dna_ButtStock;
						handGuard = weaponSet.dna_HandGuard;
						wrap = weaponSet.dna_Wrap;
						weapon = Weapon_Base.Cast(GetGame().CreateObjectEx(weaponType, GetWorldPosition(), ECE_PLACE_ON_SURFACE));
						if(weapon)
						{
							if(mag && mag != "")
							{
								if(mag == "random")
									mag = GetRandomAttachment(weaponType, "mags");
								canSpawnMag = weapon.CF_SpawnMagazine(mag);
								if(spareMags > 0)
								{
									for(j = 0; j < spareMags; j++)
									{
										GetInventory().CreateInInventory(mag);
									}
								}
							}
							
							if(ammo && ammo != "")
							{
								if(ammo == "random")
									ammo = GetRandomAttachment(weaponType, "ammo");
								GetInventory().CreateInInventory(ammo);
								if(spareAmmo > 0)
								{
									for(j = 0; j < spareAmmo; j++)
									{
										GetInventory().CreateInInventory(ammo);
									}
								}
							}
							
							if(optic && optic != "")
							{
								if(optic == "random")
									optic = GetRandomAttachment(weaponType, "optic");
								weapon.GetInventory().CreateAttachment(optic);
								GetGame().ConfigGetTextArray("CfgVehicles " + optic + " attachments", opticBatteries);
								if(opticBatteries && opticBatteries.Count() > 0)
								{
									if(opticBatteries.Get(0) == "BatteryD")
										opticBattery = true;
								}
								opticBatteries.Clear();
								if(opticBattery)
									weapon.GetInventory().CreateInInventory("Battery9V");
								opticBattery = false;
							}
							
							if(suppressor && suppressor != "")
							{
								if(suppressor == "random")
									suppressor = GetRandomAttachment(weaponType, "muzzle");
								if(suppressor.Contains("Suppressor") || ("Compensator") || ("Bayonet"))
									weapon.GetInventory().CreateAttachment(suppressor);
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
							
							if(buttStock && buttStock != "")
							{
								if(buttStock == "random")
									buttStock = GetRandomAttachment(weaponType, "buttstock");
								if(buttStock != "")
									weapon.GetInventory().CreateAttachment(buttStock);
							}
							
							if(handGuard && handGuard != "")
							{
								if(handGuard == "random")
									handGuard = GetRandomAttachment(weaponType, "handguard");
								if(handGuard != "")
									weapon.GetInventory().CreateAttachment(handGuard);
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

							ServerTakeEntityToTargetCargo(this, weapon);
						}
					}
				}
			}
			else
			{
				for(i = 0; i < m_WeaponTypes.Count(); i++)
				{
					weaponSet = m_WeaponTypes[i];
					if(weaponSet)
					{
						weaponType = weaponSet.dna_TheChosenOne;
						mag = weaponSet.dna_Magazine;
						spareMags = weaponSet.dna_SpareMagCount;
						ammo = weaponSet.dna_Ammunition;
						spareAmmo = weaponSet.dna_SpareAmmoCount;
						optic = weaponSet.dna_OpticType;
						suppressor = weaponSet.dna_Suppressor;
						underBarrel = weaponSet.dna_UnderBarrel;
						buttStock = weaponSet.dna_ButtStock;
						handGuard = weaponSet.dna_HandGuard;
						wrap = weaponSet.dna_Wrap;
						weapon = Weapon_Base.Cast(GetGame().CreateObjectEx(weaponType, GetWorldPosition(), ECE_PLACE_ON_SURFACE));
						if(weapon)
						{
							if(mag && mag != "")
							{
								if(mag == "random")
									mag = GetRandomAttachment(weaponType, "mags");
								canSpawnMag = weapon.CF_SpawnMagazine(mag);
								if(spareMags > 0)
								{
									for(j = 0; j < spareMags; j++)
									{
										GetInventory().CreateInInventory(mag);
									}
								}
							}
							
							if(ammo && ammo != "")
							{
								if(ammo == "random")
									ammo = GetRandomAttachment(weaponType, "ammo");
								GetInventory().CreateInInventory(ammo);
								if(spareAmmo > 0)
								{
									for(j = 0; j < spareAmmo; j++)
									{
										GetInventory().CreateInInventory(ammo);
									}
								}
							}
							
							if(optic && optic != "")
							{
								if(optic == "random")
									optic = GetRandomAttachment(weaponType, "optic");
								weapon.GetInventory().CreateAttachment(optic);
								GetGame().ConfigGetTextArray("CfgVehicles " + optic + " attachments", opticBatteries);
								if(opticBatteries && opticBatteries.Count() > 0)
								{
									if(opticBatteries.Get(0) == "BatteryD")
										opticBattery = true;
								}
								opticBatteries.Clear();
								if(opticBattery)
									weapon.GetInventory().CreateInInventory("Battery9V");
								opticBattery = false;
							}
							
							if(suppressor && suppressor != "")
							{
								if(suppressor == "random")
									suppressor = GetRandomAttachment(weaponType, "muzzle");
								if(suppressor.Contains("Suppressor") || ("Compensator") || ("Bayonet"))
									weapon.GetInventory().CreateAttachment(suppressor);
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
							
							if(buttStock && buttStock != "")
							{
								if(buttStock == "random")
									buttStock = GetRandomAttachment(weaponType, "buttstock");
								if(buttStock != "")
									weapon.GetInventory().CreateAttachment(buttStock);
							}
							
							if(handGuard && handGuard != "")
							{
								if(handGuard == "random")
									handGuard = GetRandomAttachment(weaponType, "handguard");
								if(handGuard != "")
									weapon.GetInventory().CreateAttachment(handGuard);
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

							ServerTakeEntityToTargetCargo(this, weapon);
						}
					}
				}
			}
		}
	}
	
	void SpawnLoot()
	{		
		string loot;
		if(m_SpawnLootSet1)
		{
			if(m_RandomizeLootSet1)
			{
				for(int i = 0; i < m_LootSet1Count; i++)
				{
					loot = m_LootSet1.GetRandomElement();
					if(loot)
					{
						AddLoot(loot);
					}
				}				
			}
			else
			{
				for(i = 0; i < m_LootSet1.Count(); i++)
				{
					AddLoot(m_LootSet1[i]);
				}
			}
		}
		
		if(m_SpawnLootSet2)
		{
			if(m_RandomizeLootSet2)
			{
				for(i = 0; i < m_LootSet2Count; i++)
				{
					loot = m_LootSet2.GetRandomElement();
					if(loot)
					{
						AddLoot(loot);
					}
				}				
			}
			else
			{
				for(i = 0; i < m_LootSet2.Count(); i++)
				{
					AddLoot(m_LootSet2[i]);
				}
			}
		}
		
		if(m_SpawnLootSet3)
		{
			if(m_RandomizeLootSet3)
			{
				for(i = 0; i < m_LootSet3Count; i++)
				{
					loot = m_LootSet3.GetRandomElement();
					if(loot)
					{
						AddLoot(loot);
					}
				}				
			}
			else
			{
				for(i = 0; i < m_LootSet3.Count(); i++)
				{
					AddLoot(m_LootSet3[i]);
				}
			}
		}
		
		if(m_SpawnLootSet4)
		{
			if(m_RandomizeLootSet4)
			{
				for(i = 0; i < m_LootSet4Count; i++)
				{
					loot = m_LootSet4.GetRandomElement();
					if(loot)
					{
						AddLoot(loot);
					}
				}				
			}
			else
			{
				for(i = 0; i < m_LootSet4.Count(); i++)
				{
					AddLoot(m_LootSet4[i]);
				}
			}
		}
	}
	
	void AddLoot(string loot)
	{
		GetInventory().CreateInInventory(loot);
	}
}