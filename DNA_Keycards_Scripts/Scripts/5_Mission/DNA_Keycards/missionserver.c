modded class MissionServer
{
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
	
	ref DNA_Keycards_Client m_DNAKeycardsC;
	
	void MissionServer()
	{		
		DNA_Logging.InitLogger();
		m_DNAKeycardsC = new ref DNA_Keycards_Client();
		
		ConfigCheckAndRead();
	}
	
	void ConfigCheckAndRead()
	{
		if(GetGame().IsDedicatedServer())
		{
			KeyCard_Config_Main_System.CreateMainDirectory();		
			DNA_Crafting_Config.CreateDirectory();
			KeyCard_Config_Main_System.CheckForConfigUpdate();
			KeyCard_Config_Main_System.CheckForPreLoadedConfig();
			DNA_Keycards_Main_System.ClearInstance();
			DNA_Keycards_Container_System.ClearInstance();
			DNA_Keycards_Mob_System.ClearInstance();
			DNA_Keycards_Loot.ClearInstance();
			DNA_Keycards_Clothing.ClearInstance();
			DNA_Keycards_Weapons.ClearInstance();
			DNA_Crafting_Instance.ClearInstance();
			
			DNA_Keycards_Main_System.GetInstance();
			DNA_Keycards_Container_System.GetInstance();
			DNA_Keycards_Mob_System.GetInstance();
			DNA_Keycards_Loot.GetInstance();
			DNA_Keycards_Clothing.GetInstance();
			DNA_Keycards_Weapons.GetInstance();
			DNA_Crafting_Instance.GetInstance();
			
			dna_MainSystemConfig = DNA_Keycards_Main_System.GetInstance().GetConfig().GetConfigData().GetSystemArray();
			dna_YellowCrateLocations = DNA_Keycards_Main_System.GetInstance().GetConfig().GetConfigData().GetLocationsYArray();
			dna_GreenCrateLocations = DNA_Keycards_Main_System.GetInstance().GetConfig().GetConfigData().GetLocationsGArray();
			dna_BlueCrateLocations = DNA_Keycards_Main_System.GetInstance().GetConfig().GetConfigData().GetLocationsBArray();
			dna_PurpleCrateLocations = DNA_Keycards_Main_System.GetInstance().GetConfig().GetConfigData().GetLocationsPArray();
			dna_RedCrateLocations = DNA_Keycards_Main_System.GetInstance().GetConfig().GetConfigData().GetLocationsRArray();
			
			dna_YellowStrongroomLocations = DNA_Keycards_Main_System.GetInstance().GetConfig().GetConfigData().GetStrongroomLocationsYArray();
			dna_GreenStrongroomLocations = DNA_Keycards_Main_System.GetInstance().GetConfig().GetConfigData().GetStrongroomLocationsGArray();
			dna_BlueStrongroomLocations = DNA_Keycards_Main_System.GetInstance().GetConfig().GetConfigData().GetStrongroomLocationsBArray();
			dna_PurpleStrongroomLocations = DNA_Keycards_Main_System.GetInstance().GetConfig().GetConfigData().GetStrongroomLocationsPArray();
			dna_RedStrongroomLocations = DNA_Keycards_Main_System.GetInstance().GetConfig().GetConfigData().GetStrongroomLocationsRArray();
			
			CrateSpawnCheck();
			StrongroomSpawnCheck();
			DNA_ConfigIndex.Init();
		}
	}
	
	void CrateSpawnCheck()
	{
		int i, localIndex, crateSetting, count_yellow, count_green, count_blue, count_purple, count_red;
		vector position, orientation;
		
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
				for(i = 0; i < count_yellow; i++) //ADD LOGIC TO COUNT POSITIONS AND MAKE SURE IT DOESNT TRY TO SPAWN MORE THAN AVAILABLE
				{
					DNA_Yellow_Crate_Locations yellowLocations = dna_YellowCrateLocations.GetRandomElement();
					localIndex = dna_YellowCrateLocations.Find(yellowLocations);
					position = yellowLocations.GetLocation().ToVector();
					orientation = yellowLocations.GetRotation().ToVector();
					dna_YellowCrateLocations.Remove(localIndex);
					SpawnEntity("DNA_Crate_Yellow", position, orientation);
				}
			}
			else
			{
				Print("[DNA DEBUG] - System not spawning yellow crates!");
			}

			if(count_green > 0)
			{			
				for(i = 0; i < count_green; i++)
				{
					DNA_Green_Crate_Locations greenLocations = dna_GreenCrateLocations.GetRandomElement();
					localIndex = dna_GreenCrateLocations.Find(greenLocations);
					position = greenLocations.GetLocation().ToVector();
					orientation = greenLocations.GetRotation().ToVector();
					dna_GreenCrateLocations.Remove(localIndex);
					SpawnEntity("DNA_Crate_Green", position, orientation);
				}
			}
			else
			{
				Print("[DNA DEBUG] - System not spawning green crates!");
			}

			if(count_blue > 0)
			{			
				for(i = 0; i < count_blue; i++)
				{
					DNA_Blue_Crate_Locations blueLocations = dna_BlueCrateLocations.GetRandomElement();
					localIndex = dna_BlueCrateLocations.Find(blueLocations);
					position = blueLocations.GetLocation().ToVector();
					orientation = blueLocations.GetRotation().ToVector();
					dna_BlueCrateLocations.Remove(localIndex);
					SpawnEntity("DNA_Crate_Blue", position, orientation);
				}
			}
			else
			{
				Print("[DNA DEBUG] - System not spawning blue crates!");
			}
			
			if(count_purple > 0)
			{			
				for(i = 0; i < count_purple; i++)
				{
					DNA_Purple_Crate_Locations purpleLocations = dna_PurpleCrateLocations.GetRandomElement();
					localIndex = dna_PurpleCrateLocations.Find(purpleLocations);
					position = purpleLocations.GetLocation().ToVector();
					orientation = purpleLocations.GetRotation().ToVector();
					dna_PurpleCrateLocations.Remove(localIndex);
					SpawnEntity("DNA_Crate_Purple", position, orientation);
				}
			}
			else
			{
				Print("[DNA DEBUG] - System not spawning purple crates!");
			}

			if(count_red > 0)
			{			
				for(i = 0; i < count_red; i++)
				{
					DNA_Red_Crate_Locations redLocations = dna_RedCrateLocations.GetRandomElement();
					localIndex = dna_RedCrateLocations.Find(redLocations);
					position = redLocations.GetLocation().ToVector();
					orientation = redLocations.GetRotation().ToVector();
					dna_RedCrateLocations.Remove(localIndex);
					SpawnEntity("DNA_Crate_Red", position, orientation);
				}
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
				SpawnEntity("DNA_Crate_Yellow", position, orientation);
			}
			for(i = 0; i < dna_GreenCrateLocations.Count(); i++)
			{
				greenLocations = dna_GreenCrateLocations.Get(i);
				position = greenLocations.GetLocation().ToVector();
				orientation = greenLocations.GetRotation().ToVector();
				SpawnEntity("DNA_Crate_Green", position, orientation);
			}
			for(i = 0; i < dna_BlueCrateLocations.Count(); i++)
			{
				blueLocations = dna_BlueCrateLocations.Get(i);
				position = blueLocations.GetLocation().ToVector();
				orientation = blueLocations.GetRotation().ToVector();
				SpawnEntity("DNA_Crate_Blue", position, orientation);
			}
			for(i = 0; i < dna_PurpleCrateLocations.Count(); i++)
			{
				purpleLocations = dna_PurpleCrateLocations.Get(i);
				position = purpleLocations.GetLocation().ToVector();
				orientation = purpleLocations.GetRotation().ToVector();
				SpawnEntity("DNA_Crate_Purple", position, orientation);
			}
			for(i = 0; i < dna_RedCrateLocations.Count(); i++)
			{
				redLocations = dna_RedCrateLocations.Get(i);
				position = redLocations.GetLocation().ToVector();
				orientation = redLocations.GetRotation().ToVector();
				SpawnEntity("DNA_Crate_Red", position, orientation);
			}
		}
		else
		{
			Print("[DNA DEBUG] - System not spawning any crates!");
		}
	}
	
	void StrongroomSpawnCheck()
	{
		int i, localIndex, strongroomSetting, count_yellow, count_green, count_blue, count_purple, count_red;
		vector position, orientation;
		
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
					DNA_Yellow_Strongroom_Locations yellowLocations = dna_YellowStrongroomLocations.GetRandomElement();
					localIndex = dna_YellowStrongroomLocations.Find(yellowLocations);
					position = yellowLocations.GetLocation().ToVector();
					orientation = yellowLocations.GetRotation().ToVector();
					dna_YellowStrongroomLocations.Remove(localIndex);
					SpawnEntity("DNA_Strongroom_Yellow", position, orientation);
				}
			}
			else
			{
				Print("[DNA DEBUG] - System not spawning yellow strongrooms!");
			}

			if(count_green > 0)
			{			
				for(i = 0; i < count_green; i++)
				{
					DNA_Green_Strongroom_Locations greenLocations = dna_GreenStrongroomLocations.GetRandomElement();
					localIndex = dna_GreenStrongroomLocations.Find(greenLocations);
					position = greenLocations.GetLocation().ToVector();
					orientation = greenLocations.GetRotation().ToVector();
					dna_GreenStrongroomLocations.Remove(localIndex);
					SpawnEntity("DNA_Strongroom_Green", position, orientation);
				}
			}
			else
			{
				Print("[DNA DEBUG] - System not spawning green strongrooms!");
			}

			if(count_blue > 0)
			{			
				for(i = 0; i < count_blue; i++)
				{
					DNA_Blue_Strongroom_Locations blueLocations = dna_BlueStrongroomLocations.GetRandomElement();
					localIndex = dna_BlueStrongroomLocations.Find(blueLocations);
					position = blueLocations.GetLocation().ToVector();
					orientation = blueLocations.GetRotation().ToVector();
					dna_BlueStrongroomLocations.Remove(localIndex);
					SpawnEntity("DNA_Strongroom_Blue", position, orientation);
				}
			}
			else
			{
				Print("[DNA DEBUG] - System not spawning blue strongrooms!");
			}
			
			if(count_purple > 0)
			{			
				for(i = 0; i < count_purple; i++)
				{
					DNA_Purple_Strongroom_Locations purpleLocations = dna_PurpleStrongroomLocations.GetRandomElement();
					localIndex = dna_PurpleStrongroomLocations.Find(purpleLocations);
					position = purpleLocations.GetLocation().ToVector();
					orientation = purpleLocations.GetRotation().ToVector();
					dna_PurpleStrongroomLocations.Remove(localIndex);
					SpawnEntity("DNA_Strongroom_Purple", position, orientation);
				}
			}
			else
			{
				Print("[DNA DEBUG] - System not spawning purple strongrooms!");
			}

			if(count_red > 0)
			{			
				for(i = 0; i < count_red; i++)
				{
					DNA_Red_Strongroom_Locations redLocations = dna_RedStrongroomLocations.GetRandomElement();
					localIndex = dna_RedStrongroomLocations.Find(redLocations);
					position = redLocations.GetLocation().ToVector();
					orientation = redLocations.GetRotation().ToVector();
					dna_RedStrongroomLocations.Remove(localIndex);
					SpawnEntity("DNA_Strongroom_Red", position, orientation);
				}
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
				SpawnEntity("DNA_Strongroom_Yellow", position, orientation);
			}
			for(i = 0; i < dna_GreenStrongroomLocations.Count(); i++)
			{
				greenLocations = dna_GreenStrongroomLocations.Get(i);
				position = greenLocations.GetLocation().ToVector();
				orientation = greenLocations.GetRotation().ToVector();
				SpawnEntity("DNA_Strongroom_Green", position, orientation);
			}
			for(i = 0; i < dna_BlueStrongroomLocations.Count(); i++)
			{
				blueLocations = dna_BlueStrongroomLocations.Get(i);
				position = blueLocations.GetLocation().ToVector();
				orientation = blueLocations.GetRotation().ToVector();
				SpawnEntity("DNA_Strongroom_Blue", position, orientation);
			}
			for(i = 0; i < dna_PurpleStrongroomLocations.Count(); i++)
			{
				purpleLocations = dna_PurpleStrongroomLocations.Get(i);
				position = purpleLocations.GetLocation().ToVector();
				orientation = purpleLocations.GetRotation().ToVector();
				SpawnEntity("DNA_Strongroom_Purple", position, orientation);
			}
			for(i = 0; i < dna_RedStrongroomLocations.Count(); i++)
			{
				redLocations = dna_RedStrongroomLocations.Get(i);
				position = redLocations.GetLocation().ToVector();
				orientation = redLocations.GetRotation().ToVector();
				SpawnEntity("DNA_Strongroom_Red", position, orientation);
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
}