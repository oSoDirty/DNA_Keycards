modded class MissionServer
{
	protected ref array<ref KCM_Config_System> kcm_SystemConfig;
	protected ref array<ref KCM_Yellow_Locations> kcm_YellowLocations;
	protected ref array<ref KCM_Green_Locations> kcm_GreenLocations;
	protected ref array<ref KCM_Blue_Locations> kcm_BlueLocations;
	protected ref array<ref KCM_Purple_Locations> kcm_PurpleLocations;
	protected ref array<ref KCM_Red_Locations> kcm_RedLocations;	
	
	void MissionServer()
	{
		KeyCard_Config_System.CreateMainDirectory();	
		KeyCard_Config_System.CheckForConfigUpdate();
		DNA_Keycards_System.ClearInstance();
		DNA_Keycards_Base.ClearInstance();
		DNA_Keycards_Yellow.ClearInstance();
		DNA_Keycards_Green.ClearInstance();
		DNA_Keycards_Blue.ClearInstance();
		DNA_Keycards_Purple.ClearInstance();
		DNA_Keycards_Red.ClearInstance();
		
		DNA_Keycards_System.GetInstance();
		DNA_Keycards_Base.GetInstance();
		DNA_Keycards_Yellow.GetInstance();
		DNA_Keycards_Green.GetInstance();
		DNA_Keycards_Blue.GetInstance();
		DNA_Keycards_Purple.GetInstance();
		DNA_Keycards_Red.GetInstance();
		
		kcm_SystemConfig = DNA_Keycards_System.GetInstance().GetConfig().GetConfigData().GetSystemArray();
		kcm_YellowLocations = DNA_Keycards_System.GetInstance().GetConfig().GetConfigData().GetLocationsYArray();
		kcm_GreenLocations = DNA_Keycards_System.GetInstance().GetConfig().GetConfigData().GetLocationsGArray();
		kcm_BlueLocations = DNA_Keycards_System.GetInstance().GetConfig().GetConfigData().GetLocationsBArray();
		kcm_PurpleLocations = DNA_Keycards_System.GetInstance().GetConfig().GetConfigData().GetLocationsPArray();
		kcm_RedLocations = DNA_Keycards_System.GetInstance().GetConfig().GetConfigData().GetLocationsRArray();
		
		if(GetGame().IsServer())
			CrateSpawnCheck();
			//GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(CrateSpawnCheck, 30000, false);
	}
	
	void SpawnCrate(string type, vector position, vector orientation)
	{
		auto obj = GetGame().CreateObjectEx(type, position, ECE_SETUP | ECE_UPDATEPATHGRAPH | ECE_CREATEPHYSICS);
		obj.SetPosition(position);
		obj.SetOrientation(orientation);
		obj.SetOrientation(obj.GetOrientation());
		obj.SetFlags(EntityFlags.STATIC, false);
		obj.Update();
		obj.SetAffectPathgraph(true, false);
		if (obj.CanAffectPathgraph()) GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(GetGame().UpdatePathgraphRegionByObject, 100, false, obj);
		Print("KCM DEBUG: " + type + " spawned at " + position + ".");
		
	}
	
	void CrateSpawnCheck()
	{
		int i, localIndex, crateSetting;
		string type;
		vector position, orientation;
		if(kcm_SystemConfig.Get(0).GetSystemSetting() == 1)
		{
			if(kcm_SystemConfig.Get(13).GetSystemSetting() != 0)   //yeller
			{			
				for(i = 0; i < kcm_SystemConfig.Get(13).GetSystemSetting(); i++)
				{
					type = "KC_Crate_Yellow";
					KCM_Yellow_Locations yellowLocations = kcm_YellowLocations.GetRandomElement();
					localIndex = kcm_YellowLocations.Find(yellowLocations);
					position = yellowLocations.GetLocation().ToVector();
					orientation = yellowLocations.GetRotation().ToVector();
					kcm_YellowLocations.Remove(localIndex);
					SpawnCrate(type, position, orientation);
				}
			}
			else
			{
				Print("KCM DEBUG: System not spawning yellow crates!");
			}

			if(kcm_SystemConfig.Get(26).GetSystemSetting() != 0)
			{			
				for(i = 0; i < kcm_SystemConfig.Get(26).GetSystemSetting(); i++)
				{
					type = "KC_Crate_Green";
					KCM_Green_Locations greenLocations = kcm_GreenLocations.GetRandomElement();
					localIndex = kcm_GreenLocations.Find(greenLocations);
					position = greenLocations.GetLocation().ToVector();
					orientation = greenLocations.GetRotation().ToVector();
					kcm_GreenLocations.Remove(localIndex);
					SpawnCrate(type, position, orientation);
				}
			}
			else
			{
				Print("KCM DEBUG: System not spawning green crates!");
			}

			if(kcm_SystemConfig.Get(39).GetSystemSetting() != 0)
			{			
				for(i = 0; i < kcm_SystemConfig.Get(39).GetSystemSetting(); i++)
				{
					type = "KC_Crate_Blue";
					KCM_Blue_Locations blueLocations = kcm_BlueLocations.GetRandomElement();
					localIndex = kcm_BlueLocations.Find(blueLocations);
					position = blueLocations.GetLocation().ToVector();
					orientation = blueLocations.GetRotation().ToVector();
					kcm_BlueLocations.Remove(localIndex);
					SpawnCrate(type, position, orientation);
				}
			}
			else
			{
				Print("KCM DEBUG: System not spawning blue crates!");
			}
			
			if(kcm_SystemConfig.Get(52).GetSystemSetting() != 0)
			{			
				for(i = 0; i < kcm_SystemConfig.Get(52).GetSystemSetting(); i++)
				{
					type = "KC_Crate_Purple";
					KCM_Purple_Locations purpleLocations = kcm_PurpleLocations.GetRandomElement();
					localIndex = kcm_PurpleLocations.Find(purpleLocations);
					position = purpleLocations.GetLocation().ToVector();
					orientation = purpleLocations.GetRotation().ToVector();
					kcm_PurpleLocations.Remove(localIndex);
					SpawnCrate(type, position, orientation);
				}
			}
			else
			{
				Print("KCM DEBUG: System not spawning purple crates!");
			}

			if(kcm_SystemConfig.Get(65).GetSystemSetting() != 0)
			{			
				for(i = 0; i < kcm_SystemConfig.Get(65).GetSystemSetting(); i++)
				{
					type = "KC_Crate_Red";
					KCM_Red_Locations redLocations = kcm_RedLocations.GetRandomElement();
					localIndex = kcm_RedLocations.Find(redLocations);
					position = redLocations.GetLocation().ToVector();
					orientation = redLocations.GetRotation().ToVector();
					kcm_RedLocations.Remove(localIndex);
					SpawnCrate(type, position, orientation);
				}
			}
			else
			{
				Print("KCM DEBUG: System not spawning red crates!");
			}
		}
		else
		{
			Print("KCM DEBUG: System not spawning any crates!");
		}
	}
}