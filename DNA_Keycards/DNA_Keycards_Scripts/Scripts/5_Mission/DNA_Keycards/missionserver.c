modded class MissionServer
{
	protected ref array<ref KCM_Config_Main_System> kcm_MainSystemConfig;
	protected ref array<ref KCM_Yellow_Crate_Locations> kcm_YellowCrateLocations;
	protected ref array<ref KCM_Green_Crate_Locations> kcm_GreenCrateLocations;
	protected ref array<ref KCM_Blue_Crate_Locations> kcm_BlueCrateLocations;
	protected ref array<ref KCM_Purple_Crate_Locations> kcm_PurpleCrateLocations;
	protected ref array<ref KCM_Red_Crate_Locations> kcm_RedCrateLocations;
	protected ref array<ref KCM_Yellow_Vault_Locations> kcm_YellowVaultLocations;
	protected ref array<ref KCM_Green_Vault_Locations> kcm_GreenVaultLocations;
	protected ref array<ref KCM_Blue_Vault_Locations> kcm_BlueVaultLocations;
	protected ref array<ref KCM_Purple_Vault_Locations> kcm_PurpleVaultLocations;
	protected ref array<ref KCM_Red_Vault_Locations> kcm_RedVaultLocations;	
	
	void MissionServer()
	{
		if(GetGame().IsServer())
		{
			KeyCard_Config_Main_System.CreateMainDirectory();	
			KeyCard_Config_Main_System.CheckForConfigUpdate();
			DNA_Keycards_Main_System.ClearInstance();
			DNA_Keycards_Crate_System.ClearInstance();
			DNA_Keycards_Vault_System.ClearInstance();
			DNA_Keycards_Base.ClearInstance();
			DNA_Keycards_Yellow.ClearInstance();
			DNA_Keycards_Green.ClearInstance();
			DNA_Keycards_Blue.ClearInstance();
			DNA_Keycards_Purple.ClearInstance();
			DNA_Keycards_Red.ClearInstance();
			
			DNA_Keycards_Main_System.GetInstance();
			DNA_Keycards_Crate_System.GetInstance();
			DNA_Keycards_Vault_System.GetInstance();
			DNA_Keycards_Base.GetInstance();
			DNA_Keycards_Yellow.GetInstance();
			DNA_Keycards_Green.GetInstance();
			DNA_Keycards_Blue.GetInstance();
			DNA_Keycards_Purple.GetInstance();
			DNA_Keycards_Red.GetInstance();
			
			kcm_MainSystemConfig = DNA_Keycards_Main_System.GetInstance().GetConfig().GetConfigData().GetSystemArray();
			kcm_YellowCrateLocations = DNA_Keycards_Main_System.GetInstance().GetConfig().GetConfigData().GetLocationsYArray();
			kcm_GreenCrateLocations = DNA_Keycards_Main_System.GetInstance().GetConfig().GetConfigData().GetLocationsGArray();
			kcm_BlueCrateLocations = DNA_Keycards_Main_System.GetInstance().GetConfig().GetConfigData().GetLocationsBArray();
			kcm_PurpleCrateLocations = DNA_Keycards_Main_System.GetInstance().GetConfig().GetConfigData().GetLocationsPArray();
			kcm_RedCrateLocations = DNA_Keycards_Main_System.GetInstance().GetConfig().GetConfigData().GetLocationsRArray();
			
			kcm_MainSystemConfig = DNA_Keycards_Main_System.GetInstance().GetConfig().GetConfigData().GetSystemArray();
			kcm_YellowCrateLocations = DNA_Keycards_Main_System.GetInstance().GetConfig().GetConfigData().GetLocationsYArray();
			kcm_GreenCrateLocations = DNA_Keycards_Main_System.GetInstance().GetConfig().GetConfigData().GetLocationsGArray();
			kcm_BlueCrateLocations = DNA_Keycards_Main_System.GetInstance().GetConfig().GetConfigData().GetLocationsBArray();
			kcm_PurpleCrateLocations = DNA_Keycards_Main_System.GetInstance().GetConfig().GetConfigData().GetLocationsPArray();
			kcm_RedCrateLocations = DNA_Keycards_Main_System.GetInstance().GetConfig().GetConfigData().GetLocationsRArray();
			
			CrateSpawnCheck();
			VaultSpawnCheck();
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
		Print("KCM DEBUG: " + type + " spawned at " + position + ".");
		
	}
	
	void CrateSpawnCheck()
	{
		int i, localIndex, crateSetting;
		string type;
		vector position, orientation;
		if(kcm_MainSystemConfig.Get(0).GetSystemSetting() == 1)
		{
			if(kcm_MainSystemConfig.Get(2).GetSystemSetting() != 0)   //yeller
			{			
				for(i = 0; i < kcm_MainSystemConfig.Get(2).GetSystemSetting(); i++)
				{
					type = "KC_Crate_Yellow";
					KCM_Yellow_Crate_Locations yellowLocations = kcm_YellowCrateLocations.GetRandomElement();
					localIndex = kcm_YellowCrateLocations.Find(yellowLocations);
					position = yellowLocations.GetLocation().ToVector();
					orientation = yellowLocations.GetRotation().ToVector();
					kcm_YellowCrateLocations.Remove(localIndex);
					SpawnEntity(type, position, orientation);
				}
			}
			else
			{
				Print("KCM DEBUG: System not spawning yellow crates!");
			}

			if(kcm_MainSystemConfig.Get(3).GetSystemSetting() != 0)
			{			
				for(i = 0; i < kcm_MainSystemConfig.Get(3).GetSystemSetting(); i++)
				{
					type = "KC_Crate_Green";
					KCM_Green_Crate_Locations greenLocations = kcm_GreenCrateLocations.GetRandomElement();
					localIndex = kcm_GreenCrateLocations.Find(greenLocations);
					position = greenLocations.GetLocation().ToVector();
					orientation = greenLocations.GetRotation().ToVector();
					kcm_GreenCrateLocations.Remove(localIndex);
					SpawnEntity(type, position, orientation);
				}
			}
			else
			{
				Print("KCM DEBUG: System not spawning green crates!");
			}

			if(kcm_MainSystemConfig.Get(4).GetSystemSetting() != 0)
			{			
				for(i = 0; i < kcm_MainSystemConfig.Get(4).GetSystemSetting(); i++)
				{
					type = "KC_Crate_Blue";
					KCM_Blue_Crate_Locations blueLocations = kcm_BlueCrateLocations.GetRandomElement();
					localIndex = kcm_BlueCrateLocations.Find(blueLocations);
					position = blueLocations.GetLocation().ToVector();
					orientation = blueLocations.GetRotation().ToVector();
					kcm_BlueCrateLocations.Remove(localIndex);
					SpawnEntity(type, position, orientation);
				}
			}
			else
			{
				Print("KCM DEBUG: System not spawning blue crates!");
			}
			
			if(kcm_MainSystemConfig.Get(5).GetSystemSetting() != 0)
			{			
				for(i = 0; i < kcm_MainSystemConfig.Get(5).GetSystemSetting(); i++)
				{
					type = "KC_Crate_Purple";
					KCM_Purple_Crate_Locations purpleLocations = kcm_PurpleCrateLocations.GetRandomElement();
					localIndex = kcm_PurpleCrateLocations.Find(purpleLocations);
					position = purpleLocations.GetLocation().ToVector();
					orientation = purpleLocations.GetRotation().ToVector();
					kcm_PurpleCrateLocations.Remove(localIndex);
					SpawnEntity(type, position, orientation);
				}
			}
			else
			{
				Print("KCM DEBUG: System not spawning purple crates!");
			}

			if(kcm_MainSystemConfig.Get(6).GetSystemSetting() != 0)
			{			
				for(i = 0; i < kcm_MainSystemConfig.Get(6).GetSystemSetting(); i++)
				{
					type = "KC_Crate_Red";
					KCM_Red_Crate_Locations redLocations = kcm_RedCrateLocations.GetRandomElement();
					localIndex = kcm_RedCrateLocations.Find(redLocations);
					position = redLocations.GetLocation().ToVector();
					orientation = redLocations.GetRotation().ToVector();
					kcm_RedCrateLocations.Remove(localIndex);
					SpawnEntity(type, position, orientation);
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
	
	void VaultSpawnCheck()
	{
		int i, localIndex, vaultSetting;
		string type;
		vector position, orientation;
		if(kcm_MainSystemConfig.Get(1).GetSystemSetting() == 1)
		{
			if(kcm_MainSystemConfig.Get(7).GetSystemSetting() != 0)   //yeller
			{			
				for(i = 0; i < kcm_MainSystemConfig.Get(7).GetSystemSetting(); i++)
				{
					type = "KC_Vault_Yellow";
					KCM_Yellow_Vault_Locations yellowLocations = kcm_YellowVaultLocations.GetRandomElement();
					localIndex = kcm_YellowVaultLocations.Find(yellowLocations);
					position = yellowLocations.GetLocation().ToVector();
					orientation = yellowLocations.GetRotation().ToVector();
					kcm_YellowVaultLocations.Remove(localIndex);
					SpawnEntity(type, position, orientation);
				}
			}
			else
			{
				Print("KCM DEBUG: System not spawning yellow vaults!");
			}

			if(kcm_MainSystemConfig.Get(8).GetSystemSetting() != 0)
			{			
				for(i = 0; i < kcm_MainSystemConfig.Get(8).GetSystemSetting(); i++)
				{
					type = "KC_Vault_Green";
					KCM_Green_Vault_Locations greenLocations = kcm_GreenVaultLocations.GetRandomElement();
					localIndex = kcm_GreenVaultLocations.Find(greenLocations);
					position = greenLocations.GetLocation().ToVector();
					orientation = greenLocations.GetRotation().ToVector();
					kcm_GreenVaultLocations.Remove(localIndex);
					SpawnEntity(type, position, orientation);
				}
			}
			else
			{
				Print("KCM DEBUG: System not spawning green vaults!");
			}

			if(kcm_MainSystemConfig.Get(9).GetSystemSetting() != 0)
			{			
				for(i = 0; i < kcm_MainSystemConfig.Get(9).GetSystemSetting(); i++)
				{
					type = "KC_Vault_Blue";
					KCM_Blue_Vault_Locations blueLocations = kcm_BlueVaultLocations.GetRandomElement();
					localIndex = kcm_BlueVaultLocations.Find(blueLocations);
					position = blueLocations.GetLocation().ToVector();
					orientation = blueLocations.GetRotation().ToVector();
					kcm_BlueVaultLocations.Remove(localIndex);
					SpawnEntity(type, position, orientation);
				}
			}
			else
			{
				Print("KCM DEBUG: System not spawning blue vaults!");
			}
			
			if(kcm_MainSystemConfig.Get(10).GetSystemSetting() != 0)
			{			
				for(i = 0; i < kcm_MainSystemConfig.Get(10).GetSystemSetting(); i++)
				{
					type = "KC_Vault_Purple";
					KCM_Purple_Vault_Locations purpleLocations = kcm_PurpleVaultLocations.GetRandomElement();
					localIndex = kcm_PurpleVaultLocations.Find(purpleLocations);
					position = purpleLocations.GetLocation().ToVector();
					orientation = purpleLocations.GetRotation().ToVector();
					kcm_PurpleVaultLocations.Remove(localIndex);
					SpawnEntity(type, position, orientation);
				}
			}
			else
			{
				Print("KCM DEBUG: System not spawning purple vaults!");
			}

			if(kcm_MainSystemConfig.Get(11).GetSystemSetting() != 0)
			{			
				for(i = 0; i < kcm_MainSystemConfig.Get(11).GetSystemSetting(); i++)
				{
					type = "KC_Vault_Red";
					KCM_Red_Vault_Locations redLocations = kcm_RedVaultLocations.GetRandomElement();
					localIndex = kcm_RedVaultLocations.Find(redLocations);
					position = redLocations.GetLocation().ToVector();
					orientation = redLocations.GetRotation().ToVector();
					kcm_RedVaultLocations.Remove(localIndex);
					SpawnEntity(type, position, orientation);
				}
			}
			else
			{
				Print("KCM DEBUG: System not spawning red vaults!");
			}
		}
		else
		{
			Print("KCM DEBUG: System not spawning any vaults!");
		}
	}
}