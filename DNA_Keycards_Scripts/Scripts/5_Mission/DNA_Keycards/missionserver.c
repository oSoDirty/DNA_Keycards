modded class MissionServer
{
	protected ref Timer m_DNAResetTimer = new Timer(CALL_CATEGORY_SYSTEM);
	protected ref array<ref DNA_Config_Main_System> dna_MainSystemConfig;
	protected ref array<ref DNA_Yellow_Crate_Locations> dna_YellowCrateLocations;
	protected ref array<ref DNA_Green_Crate_Locations> dna_GreenCrateLocations;
	protected ref array<ref DNA_Blue_Crate_Locations> dna_BlueCrateLocations;
	protected ref array<ref DNA_Purple_Crate_Locations> dna_PurpleCrateLocations;
	protected ref array<ref DNA_Red_Crate_Locations> dna_RedCrateLocations;
	protected ref array<ref DNA_Yellow_Strongroom_Locations> dna_YellowStrongroomLocations;
	protected ref array<ref DNA_Green_Strongroom_Locations> dna_GreenStrongroomLocations;
	protected ref array<ref DNA_Blue_Strongroom_Locations> dna_BlueStrongroomLocations;
	protected ref array<ref DNA_Purple_Strongroom_Locations> dna_PurpleStrongroomLocations;
	protected ref array<ref DNA_Red_Strongroom_Locations> dna_RedStrongroomLocations;
	protected ref array<ref DNA_Smol_Crate_Spawns> dna_SmolCrateSpawns;
	
	bool useResetTimer, spawnSmolCrates;
	
	ref DNA_Keycards_Client m_DNAKeycardsC;
	
	override void OnMissionStart()
	{
		super.OnMissionStart();
		
		DNA_Logging.InitLogger();
		m_DNAKeycardsC = new ref DNA_Keycards_Client();
		
		if(GetGame().IsDedicatedServer())
		{
			ConfigCheckAndRead();
			CrateSpawnCheck();
			StrongroomSpawnCheck();
		}
	}
	
	void ConfigCheckAndRead()
	{
		KeyCard_Config_Main_System.CreateMainDirectory();		
		//DNA_Crafting_Config.CreateDirectory();
		KeyCard_Config_Main_System.CheckForConfigUpdate();
		KeyCard_Config_Main_System.CheckForPreLoadedConfig();
		DNA_Keycards_Main_System.ClearInstance();
		DNA_Keycards_Container_System.ClearInstance();
		DNA_Keycards_Mob_System.ClearInstance();
		DNA_Keycards_Loot.ClearInstance();
		DNA_Keycards_Clothing.ClearInstance();
		DNA_Keycards_Weapons.ClearInstance();
		
		DNA_Keycards_Main_System.GetInstance();
		DNA_Keycards_Container_System.GetInstance();
		DNA_Keycards_Mob_System.GetInstance();
		DNA_Keycards_Loot.GetInstance();
		DNA_Keycards_Clothing.GetInstance();
		DNA_Keycards_Weapons.GetInstance();
		
		/* new container configs*/
		if(GetGame().IsDedicatedServer())
		{
			DNA_CrateSmol_Data.InitSettingsDescription();
			DNA_CrateSmol_Data.InitYellowSettings();
			DNA_CrateSmol_Data.InitGreenSettings();
			DNA_CrateSmol_Data.InitBlueSettings();
			DNA_CrateSmol_Data.InitPurpleSettings();
			DNA_CrateSmol_Data.InitRedSettings();
			DNA_CrateSmol_Data.InitSmolTimerSettings();
		
			
			/* Reset Timer Settings */
			DNA_ResetTimer_Settings_Data.InitTimerSettings();
		}
		
		dna_MainSystemConfig = DNA_Keycards_Main_System.GetInstance().GetConfig().GetConfigData().GetSystemArray();
		dna_YellowCrateLocations = DNA_Keycards_Main_System.GetInstance().GetConfig().GetConfigData().GetLocationsYArray();
		dna_GreenCrateLocations = DNA_Keycards_Main_System.GetInstance().GetConfig().GetConfigData().GetLocationsGArray();
		dna_BlueCrateLocations = DNA_Keycards_Main_System.GetInstance().GetConfig().GetConfigData().GetLocationsBArray();
		dna_PurpleCrateLocations = DNA_Keycards_Main_System.GetInstance().GetConfig().GetConfigData().GetLocationsPArray();
		dna_RedCrateLocations = DNA_Keycards_Main_System.GetInstance().GetConfig().GetConfigData().GetLocationsRArray();
		dna_SmolCrateSpawns = DNA_CrateSmol_Data.GetTimerSettings().dna_CrateSpawns;
		
		dna_YellowStrongroomLocations = DNA_Keycards_Main_System.GetInstance().GetConfig().GetConfigData().GetStrongroomLocationsYArray();
		dna_GreenStrongroomLocations = DNA_Keycards_Main_System.GetInstance().GetConfig().GetConfigData().GetStrongroomLocationsGArray();
		dna_BlueStrongroomLocations = DNA_Keycards_Main_System.GetInstance().GetConfig().GetConfigData().GetStrongroomLocationsBArray();
		dna_PurpleStrongroomLocations = DNA_Keycards_Main_System.GetInstance().GetConfig().GetConfigData().GetStrongroomLocationsPArray();
		dna_RedStrongroomLocations = DNA_Keycards_Main_System.GetInstance().GetConfig().GetConfigData().GetStrongroomLocationsRArray();
		
		useResetTimer = DNA_ResetTimer_Settings_Data.GetTimerSettings().dna_UseResetTimer;
		spawnSmolCrates = DNA_CrateSmol_Data.GetTimerSettings().dna_SpawnSmolCrates;
		
		DNA_ConfigIndex.Init();
		if(useResetTimer) StartTimer();
	}
	
	void CrateSpawnCheck()
	{
		int i, localIndex, crateSetting, count_yellow, count_green, count_blue, count_purple, count_red, fuckUpOmeter, aNumber;
		vector position, orientation;
		string posString;
		
		fuckUpOmeter = 0;
		count_yellow = dna_MainSystemConfig.Get(2).GetSystemSetting();
		if(count_yellow > dna_YellowCrateLocations.Count()) count_yellow = dna_YellowCrateLocations.Count();
		
		count_green = dna_MainSystemConfig.Get(3).GetSystemSetting();
		if(count_green > dna_GreenCrateLocations.Count()) count_green = dna_GreenCrateLocations.Count();
		
		count_blue = dna_MainSystemConfig.Get(4).GetSystemSetting();
		if(count_blue > dna_BlueCrateLocations.Count()) count_blue = dna_BlueCrateLocations.Count();
		
		count_purple = dna_MainSystemConfig.Get(5).GetSystemSetting();
		if(count_purple > dna_PurpleCrateLocations.Count()) count_purple = dna_PurpleCrateLocations.Count();
		
		count_red = dna_MainSystemConfig.Get(6).GetSystemSetting();
		if(count_red > dna_RedCrateLocations.Count()) count_red = dna_RedCrateLocations.Count();
		
		if(dna_MainSystemConfig.Get(0).GetSystemSetting() == 1)
		{
			if(count_yellow > 0) 
			{
				for(i = 0; i < count_yellow; i++)
				{
					if(fuckUpOmeter > 49)
					{
						for(aNumber = 0; aNumber < 25; aNumber++)
						{
							Print("[DNA DEBUG] - FUCK-UP-O-METER  ---->>>> YOU HAVE A CRITICAL ERROR IN YELLOW CRATE POSITIONS CONFIG!!!");
						}
						break;
					}
					DNA_Yellow_Crate_Locations yellowLocations = dna_YellowCrateLocations.GetRandomElement();
					localIndex = dna_YellowCrateLocations.Find(yellowLocations);
					posString = yellowLocations.GetLocation();
					position = yellowLocations.GetLocation().ToVector();
					orientation = yellowLocations.GetRotation().ToVector();
					dna_YellowCrateLocations.Remove(localIndex);
					if(posString != "0.0 0.0 0.0")
					{
						SpawnEntity("DNA_Crate_Yellow", position, orientation);
					}
					else
					{
						Filtered("yellow crates");
						i -= 1;
						fuckUpOmeter += 1;
					}
				}
				fuckUpOmeter = 0;
			}
			else
			{
				Print("[DNA DEBUG] - System not spawning yellow crates!");
			}

			if(count_green > 0)
			{			
				for(i = 0; i < count_green; i++)
				{
					if(fuckUpOmeter > 49)
					{
						for(aNumber = 0; aNumber < 25; aNumber++)
						{
							Print("[DNA DEBUG] - FUCK-UP-O-METER  ---->>>> YOU HAVE A CRITICAL ERROR IN GREEN CRATE POSITIONS CONFIG!!!");
						}
						break;
					}
					DNA_Green_Crate_Locations greenLocations = dna_GreenCrateLocations.GetRandomElement();
					localIndex = dna_GreenCrateLocations.Find(greenLocations);
					posString = yellowLocations.GetLocation();
					position = greenLocations.GetLocation().ToVector();
					orientation = greenLocations.GetRotation().ToVector();
					dna_GreenCrateLocations.Remove(localIndex);
					if(posString != "0.0 0.0 0.0")
					{
						SpawnEntity("DNA_Crate_Green", position, orientation);
					}
					else
					{
						Filtered("green crates");
						i -= 1;
						fuckUpOmeter += 1;
					}
				}
				fuckUpOmeter = 0;
			}
			else
			{
				Print("[DNA DEBUG] - System not spawning green crates!");
			}

			if(count_blue > 0)
			{			
				for(i = 0; i < count_blue; i++)
				{
					if(fuckUpOmeter > 49)
					{
						for(aNumber = 0; aNumber < 25; aNumber++)
						{
							Print("[DNA DEBUG] - FUCK-UP-O-METER  ---->>>> YOU HAVE A CRITICAL ERROR IN BLUE CRATE POSITIONS CONFIG!!!");
						}
						break;
					}
					DNA_Blue_Crate_Locations blueLocations = dna_BlueCrateLocations.GetRandomElement();
					localIndex = dna_BlueCrateLocations.Find(blueLocations);
					posString = yellowLocations.GetLocation();
					position = blueLocations.GetLocation().ToVector();
					orientation = blueLocations.GetRotation().ToVector();
					dna_BlueCrateLocations.Remove(localIndex);
					if(posString != "0.0 0.0 0.0")
					{
						SpawnEntity("DNA_Crate_Blue", position, orientation);
					}
					else
					{
						Filtered("blue crates");
						i -= 1;
						fuckUpOmeter += 1;
					}
				}
				fuckUpOmeter = 0;
			}
			else
			{
				Print("[DNA DEBUG] - System not spawning blue crates!");
			}
			
			if(count_purple > 0)
			{			
				for(i = 0; i < count_purple; i++)
				{
					if(fuckUpOmeter > 49)
					{
						for(aNumber = 0; aNumber < 25; aNumber++)
						{
							Print("[DNA DEBUG] - FUCK-UP-O-METER  ---->>>> YOU HAVE A CRITICAL ERROR IN PURPLE CRATE POSITIONS CONFIG!!!");
						}
						break;
					}
					DNA_Purple_Crate_Locations purpleLocations = dna_PurpleCrateLocations.GetRandomElement();
					localIndex = dna_PurpleCrateLocations.Find(purpleLocations);
					posString = yellowLocations.GetLocation();
					position = purpleLocations.GetLocation().ToVector();
					orientation = purpleLocations.GetRotation().ToVector();
					dna_PurpleCrateLocations.Remove(localIndex);
					if(posString != "0.0 0.0 0.0")
					{
						SpawnEntity("DNA_Crate_Purple", position, orientation);
					}
					else
					{
						Filtered("purple crates");
						i -= 1;
						fuckUpOmeter += 1;
					}
				}
				fuckUpOmeter = 0;
			}
			else
			{
				Print("[DNA DEBUG] - System not spawning purple crates!");
			}

			if(count_red > 0)
			{			
				for(i = 0; i < count_red; i++)
				{
					if(fuckUpOmeter > 49)
					{
						for(aNumber = 0; aNumber < 25; aNumber++)
						{
							Print("[DNA DEBUG] - FUCK-UP-O-METER  ---->>>> YOU HAVE A CRITICAL ERROR IN RED CRATE POSITIONS CONFIG!!!");
						}
						break;
					}
					DNA_Red_Crate_Locations redLocations = dna_RedCrateLocations.GetRandomElement();
					localIndex = dna_RedCrateLocations.Find(redLocations);
					posString = yellowLocations.GetLocation();
					position = redLocations.GetLocation().ToVector();
					orientation = redLocations.GetRotation().ToVector();
					dna_RedCrateLocations.Remove(localIndex);
					if(posString != "0.0 0.0 0.0")
					{
						SpawnEntity("DNA_Crate_Red", position, orientation);
					}
					else
					{
						Filtered("red crates");
						i -= 1;
						fuckUpOmeter += 1;
					}
				}
				fuckUpOmeter = 0;
			}
			else
			{
				Print("[DNA DEBUG] - System not spawning red crates!");
			}
		}
		else if(dna_MainSystemConfig.Get(0).GetSystemSetting() == 2)
		{
			for(i = 0; i < dna_YellowCrateLocations.Count(); i++)
			{
				yellowLocations = dna_YellowCrateLocations.Get(i);
				position = yellowLocations.GetLocation().ToVector();
				orientation = yellowLocations.GetRotation().ToVector();
				if(yellowLocations.GetLocation() != "0.0 0.0 0.0") SpawnEntity("DNA_Crate_Yellow", position, orientation); else Filtered("yellow crates");
			}
			for(i = 0; i < dna_GreenCrateLocations.Count(); i++)
			{
				greenLocations = dna_GreenCrateLocations.Get(i);
				position = greenLocations.GetLocation().ToVector();
				orientation = greenLocations.GetRotation().ToVector();
				if(greenLocations.GetLocation() != "0.0 0.0 0.0") SpawnEntity("DNA_Crate_Green", position, orientation); else Filtered("green crates");
			}
			for(i = 0; i < dna_BlueCrateLocations.Count(); i++)
			{
				blueLocations = dna_BlueCrateLocations.Get(i);
				position = blueLocations.GetLocation().ToVector();
				orientation = blueLocations.GetRotation().ToVector();
				if(blueLocations.GetLocation() != "0.0 0.0 0.0") SpawnEntity("DNA_Crate_Blue", position, orientation); else Filtered("blue crates");
			}
			for(i = 0; i < dna_PurpleCrateLocations.Count(); i++)
			{
				purpleLocations = dna_PurpleCrateLocations.Get(i);
				position = purpleLocations.GetLocation().ToVector();
				orientation = purpleLocations.GetRotation().ToVector();
				if(purpleLocations.GetLocation() != "0.0 0.0 0.0") SpawnEntity("DNA_Crate_Purple", position, orientation); else Filtered("purple crates");
			}
			for(i = 0; i < dna_RedCrateLocations.Count(); i++)
			{
				redLocations = dna_RedCrateLocations.Get(i);
				position = redLocations.GetLocation().ToVector();
				orientation = redLocations.GetRotation().ToVector();
				if(redLocations.GetLocation() != "0.0 0.0 0.0") SpawnEntity("DNA_Crate_Red", position, orientation); else Filtered("red crates");
			}
		}
		else
		{
			Print("[DNA DEBUG] - System not spawning any crates!");
		}
		
		if(spawnSmolCrates)
		{
			for(i = 0; i < dna_SmolCrateSpawns.Count(); i++)
			{
				string tier;
				tier = dna_SmolCrateSpawns[i].dna_Tier;
				position = dna_SmolCrateSpawns[i].dna_Location.ToVector();
				posString = dna_SmolCrateSpawns[i].dna_Location;
				orientation = dna_SmolCrateSpawns[i].dna_Rotation.ToVector();
				if(posString != "0.0 0.0 0.0")
					SpawnEntity("DNA_Crate_Smol_" + tier, position, orientation);
				else
					Filtered("smol crates");
			}
		}
		else
		{
			Print("[DNA DEBUG] - System not spawning any smol crates!");
		}
	}
	
	void StrongroomSpawnCheck()
	{
		int i, localIndex, strongroomSetting, count_yellow, count_green, count_blue, count_purple, count_red, fuckUpOmeter, aNumber;
		vector position, orientation;
		string posString;
		
		fuckUpOmeter = 0;
		count_yellow = dna_MainSystemConfig.Get(7).GetSystemSetting();
		if(count_yellow > dna_YellowStrongroomLocations.Count()) count_yellow = dna_YellowStrongroomLocations.Count();
		
		count_green = dna_MainSystemConfig.Get(8).GetSystemSetting();
		if(count_green > dna_GreenStrongroomLocations.Count()) count_green = dna_GreenStrongroomLocations.Count();
		
		count_blue = dna_MainSystemConfig.Get(9).GetSystemSetting();
		if(count_blue > dna_BlueStrongroomLocations.Count()) count_blue = dna_BlueStrongroomLocations.Count();
		
		count_purple = dna_MainSystemConfig.Get(10).GetSystemSetting();
		if(count_purple > dna_PurpleStrongroomLocations.Count()) count_purple = dna_PurpleStrongroomLocations.Count();
		
		count_red = dna_MainSystemConfig.Get(11).GetSystemSetting();
		if(count_red > dna_RedStrongroomLocations.Count()) count_red = dna_RedStrongroomLocations.Count();
		
		if(dna_MainSystemConfig.Get(1).GetSystemSetting() == 1)
		{
			if(count_yellow > 0)
			{			
				for(i = 0; i < count_yellow; i++)
				{
					if(fuckUpOmeter > 49)
					{
						for(aNumber = 0; aNumber < 25; aNumber++)
						{
							Print("[DNA DEBUG] - FUCK-UP-O-METER  ---->>>> YOU HAVE A CRITICAL ERROR IN YELLOW STRONGROOM POSITIONS CONFIG!!!");
						}
						break;
					}
					DNA_Yellow_Strongroom_Locations yellowLocations = dna_YellowStrongroomLocations.GetRandomElement();
					localIndex = dna_YellowStrongroomLocations.Find(yellowLocations);
					posString = yellowLocations.GetLocation();
					position = yellowLocations.GetLocation().ToVector();
					orientation = yellowLocations.GetRotation().ToVector();
					dna_YellowStrongroomLocations.Remove(localIndex);
					if(posString != "0.0 0.0 0.0")
					{
						SpawnEntity("DNA_Strongroom_Yellow", position, orientation);
					}
					else
					{
						Filtered("yellow strongrooms");
						i -= 1;
						fuckUpOmeter += 1;
					}
				}
				fuckUpOmeter = 0;
			}
			else
			{
				Print("[DNA DEBUG] - System not spawning yellow strongrooms!");
			}

			if(count_green > 0)
			{			
				for(i = 0; i < count_green; i++)
				{
					if(fuckUpOmeter > 49)
					{
						for(aNumber = 0; aNumber < 25; aNumber++)
						{
							Print("[DNA DEBUG] - FUCK-UP-O-METER  ---->>>> YOU HAVE A CRITICAL ERROR IN GREEN STRONGROOM POSITIONS CONFIG!!!");
						}
						break;
					}
					DNA_Green_Strongroom_Locations greenLocations = dna_GreenStrongroomLocations.GetRandomElement();
					localIndex = dna_GreenStrongroomLocations.Find(greenLocations);
					posString = greenLocations.GetLocation();
					position = greenLocations.GetLocation().ToVector();
					orientation = greenLocations.GetRotation().ToVector();
					dna_GreenStrongroomLocations.Remove(localIndex);
					if(posString != "0.0 0.0 0.0")
					{
						SpawnEntity("DNA_Strongroom_Green", position, orientation);
					}
					else
					{
						Filtered("green strongrooms");
						i -= 1;
						fuckUpOmeter += 1;
					}
				}
				fuckUpOmeter = 0;
			}
			else
			{
				Print("[DNA DEBUG] - System not spawning green strongrooms!");
			}

			if(count_blue > 0)
			{			
				for(i = 0; i < count_blue; i++)
				{
					if(fuckUpOmeter > 49)
					{
						for(aNumber = 0; aNumber < 25; aNumber++)
						{
							Print("[DNA DEBUG] - FUCK-UP-O-METER  ---->>>> YOU HAVE A CRITICAL ERROR IN BLUE STRONGROOM POSITIONS CONFIG!!!");
						}
						break;
					}
					DNA_Blue_Strongroom_Locations blueLocations = dna_BlueStrongroomLocations.GetRandomElement();
					localIndex = dna_BlueStrongroomLocations.Find(blueLocations);
					posString = blueLocations.GetLocation();
					position = blueLocations.GetLocation().ToVector();
					orientation = blueLocations.GetRotation().ToVector();
					dna_BlueStrongroomLocations.Remove(localIndex);
					if(posString != "0.0 0.0 0.0")
					{
						SpawnEntity("DNA_Strongroom_Blue", position, orientation);
					}
					else
					{
						Filtered("blue strongrooms");
						i -= 1;
						fuckUpOmeter += 1;
					}
				}
				fuckUpOmeter = 0;
			}
			else
			{
				Print("[DNA DEBUG] - System not spawning blue strongrooms!");
			}
			
			if(count_purple > 0)
			{			
				for(i = 0; i < count_purple; i++)
				{
					if(fuckUpOmeter > 49)
					{
						for(aNumber = 0; aNumber < 25; aNumber++)
						{
							Print("[DNA DEBUG] - FUCK-UP-O-METER  ---->>>> YOU HAVE A CRITICAL ERROR IN PURPLE STRONGROOM POSITIONS CONFIG!!!");
						}
						break;
					}
					DNA_Purple_Strongroom_Locations purpleLocations = dna_PurpleStrongroomLocations.GetRandomElement();
					localIndex = dna_PurpleStrongroomLocations.Find(purpleLocations);
					posString = purpleLocations.GetLocation();
					position = purpleLocations.GetLocation().ToVector();
					orientation = purpleLocations.GetRotation().ToVector();
					dna_PurpleStrongroomLocations.Remove(localIndex);
					if(posString != "0.0 0.0 0.0")
					{
						SpawnEntity("DNA_Strongroom_Purple", position, orientation);
					}
					else
					{
						Filtered("purple strongrooms");
						i -= 1;
						fuckUpOmeter += 1;
					}
				}
				fuckUpOmeter = 0;
			}
			else
			{
				Print("[DNA DEBUG] - System not spawning purple strongrooms!");
			}

			if(count_red > 0)
			{			
				for(i = 0; i < count_red; i++)
				{
					if(fuckUpOmeter > 49)
					{
						for(aNumber = 0; aNumber < 25; aNumber++)
						{
							Print("[DNA DEBUG] - FUCK-UP-O-METER  ---->>>> YOU HAVE A CRITICAL ERROR IN RED STRONGROOM POSITIONS CONFIG!!!");
						}
						break;
					}
					DNA_Red_Strongroom_Locations redLocations = dna_RedStrongroomLocations.GetRandomElement();
					localIndex = dna_RedStrongroomLocations.Find(redLocations);
					posString = redLocations.GetLocation();
					position = redLocations.GetLocation().ToVector();
					orientation = redLocations.GetRotation().ToVector();
					dna_RedStrongroomLocations.Remove(localIndex);
					if(posString != "0.0 0.0 0.0")
					{
						SpawnEntity("DNA_Strongroom_Red", position, orientation);
					}
					else
					{
						Filtered("red strongrooms");
						i -= 1;
						fuckUpOmeter += 1;
					}
				}
				fuckUpOmeter = 0;
			}
			else
			{
				Print("[DNA DEBUG] - System not spawning red strongrooms!");
			}
		}
		else if(dna_MainSystemConfig.Get(1).GetSystemSetting() == 2)
		{
			for(i = 0; i < dna_YellowStrongroomLocations.Count(); i++)
			{
				yellowLocations = dna_YellowStrongroomLocations.Get(i);
				position = yellowLocations.GetLocation().ToVector();
				orientation = yellowLocations.GetRotation().ToVector();
				if(yellowLocations.GetLocation() != "0.0 0.0 0.0") SpawnEntity("DNA_Strongroom_Yellow", position, orientation); else Filtered("yellow strongrooms");
			}
			for(i = 0; i < dna_GreenStrongroomLocations.Count(); i++)
			{
				greenLocations = dna_GreenStrongroomLocations.Get(i);
				position = greenLocations.GetLocation().ToVector();
				orientation = greenLocations.GetRotation().ToVector();
				if(greenLocations.GetLocation() != "0.0 0.0 0.0") SpawnEntity("DNA_Strongroom_Green", position, orientation); else Filtered("green strongrooms");
			}
			for(i = 0; i < dna_BlueStrongroomLocations.Count(); i++)
			{
				blueLocations = dna_BlueStrongroomLocations.Get(i);
				position = blueLocations.GetLocation().ToVector();
				orientation = blueLocations.GetRotation().ToVector();
				if(blueLocations.GetLocation() != "0.0 0.0 0.0") SpawnEntity("DNA_Strongroom_Blue", position, orientation); else Filtered("blue strongrooms");
			}
			for(i = 0; i < dna_PurpleStrongroomLocations.Count(); i++)
			{
				purpleLocations = dna_PurpleStrongroomLocations.Get(i);
				position = purpleLocations.GetLocation().ToVector();
				orientation = purpleLocations.GetRotation().ToVector();
				if(purpleLocations.GetLocation() != "0.0 0.0 0.0") SpawnEntity("DNA_Strongroom_Purple", position, orientation); else Filtered("purple strongrooms");
			}
			for(i = 0; i < dna_RedStrongroomLocations.Count(); i++)
			{
				redLocations = dna_RedStrongroomLocations.Get(i);
				position = redLocations.GetLocation().ToVector();
				orientation = redLocations.GetRotation().ToVector();
				if(redLocations.GetLocation() != "0.0 0.0 0.0") SpawnEntity("DNA_Strongroom_Red", position, orientation); else Filtered("red strongrooms");
			}
		}
		else
		{
			Print("[DNA DEBUG] - System not spawning any strongrooms!");
		}
	}
	
	void SpawnEntity(string type, vector position, vector orientation)
	{
		auto obj = GetGame().CreateObjectEx(type, position, ECE_SETUP | ECE_UPDATEPATHGRAPH | ECE_CREATEPHYSICS);
		obj.SetPosition(position);
		obj.SetOrientation(orientation);
		obj.SetOrientation(obj.GetOrientation());
		obj.SetFlags(EntityFlags.STATIC, false);
		obj.Update();
		obj.SetAffectPathgraph(true, false);
		if (obj.CanAffectPathgraph()) GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(GetGame().UpdatePathgraphRegionByObject, 100, false, obj);
		Print("[DNA DEBUG] - " + type + " spawned at " + position + ".");		
	}
	
	void StartTimer()
	{
		MagicTimerBox justToHaveAnObjectForTheFuckingTimer = MagicTimerBox.Cast(GetGame().CreateObjectEx("MagicTimerBox", "0.0 0.0 0.0", ECE_SETUP | ECE_UPDATEPATHGRAPH | ECE_CREATEPHYSICS));
		justToHaveAnObjectForTheFuckingTimer.DasBoot();
	}
	
	void Filtered(string type)
	{
		Print("[DNA DEBUG] - System filtered non location. (" + type + ")");
	}
}