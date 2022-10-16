class MagicTimerBox: ItemBase
{
	protected ref Timer m_DNAResetTimer;
	private ref Timer m_WBDrawerOpener;
	protected ref OpenableBehaviour m_Openable;
	protected bool m_IsInUse;
	
	bool resetCrates, resetSmolCrates, resetStrongrooms, resetLockouts, resetOneWayDoors, resetWarpDoors;
	
	float min_Distance_Between_Nearest_Player;
	
	int startDay, timeBetweenChecks, timeUntilYellowCrateResets, timeUntilGreenCrateResets, timeUntilBlueCrateResets, timeUntilPurpleCrateResets, timeUntilRedCrateResets, timeUntilYellowSmolCrateResets, timeUntilGreenSmolCrateResets, timeUntilBlueSmolCrateResets, timeUntilPurpleSmolCrateResets, timeUntilRedSmolCrateResets, timeUntilYellowSRoomResets, timeUntilGreenSRoomResets, timeUntilBlueSRoomResets, timeUntilPurpleSRoomResets, timeUntilRedSRoomResets, timeUntilYellowLockoutResets, timeUntilGreenLockoutResets, timeUntilBlueLockoutResets, timeUntilPurpleLockoutResets, timeUntilRedLockoutResets, timeUntilOrangeLockoutResets, timeUntilYellowOWDoorResets, timeUntilGreenOWDoorResets, timeUntilBlueOWDoorResets, timeUntilPurpleOWDoorResets, timeUntilRedOWDoorResets, timeUntilOrangeOWDoorResets, timeUntilYellowWarpDoorResets, timeUntilGreenWarpDoorResets, timeUntilBlueWarpDoorResets, timeUntilPurpleWarpDoorResets, timeUntilRedWarpDoorResets, timeUntilOrangeWarpDoorResets;
	
	void MagicTimerBox()
	{
		if(GetGame().IsDedicatedServer())
		{
			m_DNAResetTimer = new Timer(CALL_CATEGORY_GAMEPLAY);
		
			timeBetweenChecks = DNA_ResetTimer_Settings_Data.GetTimerSettings().dna_TimeBetweenChecks;
			min_Distance_Between_Nearest_Player = DNA_ResetTimer_Settings_Data.GetTimerSettings().dna_Min_Distance_Between_Nearest_Player;
			
			resetCrates = DNA_ResetTimer_Settings_Data.GetTimerSettings().dna_ResetCrates;
			timeUntilYellowCrateResets = DNA_ResetTimer_Settings_Data.GetTimerSettings().dna_TimeUntilYellowCrateResets * 60;
			timeUntilGreenCrateResets = DNA_ResetTimer_Settings_Data.GetTimerSettings().dna_TimeUntilGreenCrateResets * 60;
			timeUntilBlueCrateResets = DNA_ResetTimer_Settings_Data.GetTimerSettings().dna_TimeUntilBlueCrateResets * 60;
			timeUntilPurpleCrateResets = DNA_ResetTimer_Settings_Data.GetTimerSettings().dna_TimeUntilPurpleCrateResets * 60;
			timeUntilRedCrateResets = DNA_ResetTimer_Settings_Data.GetTimerSettings().dna_TimeUntilRedCrateResets * 60;
			
			resetSmolCrates = DNA_CrateSmol_Data.GetTimerSettings().dna_ResetSmolCrates;
			timeUntilYellowSmolCrateResets = DNA_CrateSmol_Data.GetTimerSettings().dna_TimeUntilYellowSmolCrateResets * 60;
			timeUntilGreenSmolCrateResets = DNA_CrateSmol_Data.GetTimerSettings().dna_TimeUntilGreenSmolCrateResets * 60;
			timeUntilBlueSmolCrateResets = DNA_CrateSmol_Data.GetTimerSettings().dna_TimeUntilBlueSmolCrateResets * 60;
			timeUntilPurpleSmolCrateResets = DNA_CrateSmol_Data.GetTimerSettings().dna_TimeUntilPurpleSmolCrateResets * 60;
			timeUntilRedSmolCrateResets = DNA_CrateSmol_Data.GetTimerSettings().dna_TimeUntilRedSmolCrateResets * 60;
			
			resetStrongrooms = DNA_ResetTimer_Settings_Data.GetTimerSettings().dna_ResetStrongrooms;
			timeUntilYellowSRoomResets = DNA_ResetTimer_Settings_Data.GetTimerSettings().dna_TimeUntilYellowSRoomResets * 60;
			timeUntilGreenSRoomResets = DNA_ResetTimer_Settings_Data.GetTimerSettings().dna_TimeUntilGreenSRoomResets * 60;
			timeUntilBlueSRoomResets = DNA_ResetTimer_Settings_Data.GetTimerSettings().dna_TimeUntilBlueSRoomResets * 60;
			timeUntilPurpleSRoomResets = DNA_ResetTimer_Settings_Data.GetTimerSettings().dna_TimeUntilPurpleSRoomResets * 60;
			timeUntilRedSRoomResets = DNA_ResetTimer_Settings_Data.GetTimerSettings().dna_TimeUntilRedSRoomResets * 60;
			
			resetLockouts = DNA_ResetTimer_Settings_Data.GetTimerSettings().dna_ResetLockouts;
			timeUntilYellowLockoutResets = DNA_ResetTimer_Settings_Data.GetTimerSettings().dna_TimeUntilYellowLockoutResets * 60;
			timeUntilGreenLockoutResets = DNA_ResetTimer_Settings_Data.GetTimerSettings().dna_TimeUntilGreenLockoutResets * 60;
			timeUntilBlueLockoutResets = DNA_ResetTimer_Settings_Data.GetTimerSettings().dna_TimeUntilBlueLockoutResets * 60;
			timeUntilPurpleLockoutResets = DNA_ResetTimer_Settings_Data.GetTimerSettings().dna_TimeUntilPurpleLockoutResets * 60;
			timeUntilRedLockoutResets = DNA_ResetTimer_Settings_Data.GetTimerSettings().dna_TimeUntilRedLockoutResets * 60;
			timeUntilOrangeLockoutResets = DNA_ResetTimer_Settings_Data.GetTimerSettings().dna_TimeUntilOrangeLockoutResets * 60;
			
			resetOneWayDoors = DNA_ResetTimer_Settings_Data.GetTimerSettings().dna_ResetOneWayDoors;
			timeUntilYellowOWDoorResets = DNA_ResetTimer_Settings_Data.GetTimerSettings().dna_TimeUntilYellowOWDoorResets * 60;
			timeUntilGreenOWDoorResets = DNA_ResetTimer_Settings_Data.GetTimerSettings().dna_TimeUntilGreenOWDoorResets * 60;
			timeUntilBlueOWDoorResets = DNA_ResetTimer_Settings_Data.GetTimerSettings().dna_TimeUntilBlueOWDoorResets * 60;
			timeUntilPurpleOWDoorResets = DNA_ResetTimer_Settings_Data.GetTimerSettings().dna_TimeUntilPurpleOWDoorResets * 60;
			timeUntilRedOWDoorResets = DNA_ResetTimer_Settings_Data.GetTimerSettings().dna_TimeUntilRedOWDoorResets * 60;
			timeUntilOrangeOWDoorResets = DNA_ResetTimer_Settings_Data.GetTimerSettings().dna_TimeUntilOrangeOWDoorResets * 60;
			
			resetWarpDoors = DNA_ResetTimer_Settings_Data.GetTimerSettings().dna_ResetWarpDoors;
			timeUntilYellowWarpDoorResets = DNA_ResetTimer_Settings_Data.GetTimerSettings().dna_TimeUntilYellowWarpDoorResets * 60;
			timeUntilGreenWarpDoorResets = DNA_ResetTimer_Settings_Data.GetTimerSettings().dna_TimeUntilGreenWarpDoorResets * 60;
			timeUntilBlueWarpDoorResets = DNA_ResetTimer_Settings_Data.GetTimerSettings().dna_TimeUntilBlueWarpDoorResets * 60;
			timeUntilPurpleWarpDoorResets = DNA_ResetTimer_Settings_Data.GetTimerSettings().dna_TimeUntilPurpleWarpDoorResets * 60;
			timeUntilRedWarpDoorResets = DNA_ResetTimer_Settings_Data.GetTimerSettings().dna_TimeUntilRedWarpDoorResets * 60;
			timeUntilOrangeWarpDoorResets = DNA_ResetTimer_Settings_Data.GetTimerSettings().dna_TimeUntilOrangeWarpDoorResets * 60;
		}
	}
	
	void CheckResetConditions() 
	{
		//Print("[DNA DEBUG] - Reset Timer: The start day is '" + startDay + "'.");
		vector sRoomProxyPos;
		int i, j, k, l, m, n, year, month, day, currentTime;
		GetYearMonthDay(year, month, day);
		//Print("[DNA DEBUG] - Reset Timer: The current day is '" + day + "'.");
		currentTime = DNA_Keycards_Main_System.GetTimeInSeconds();
		if(day != startDay)
			currentTime += 86400;
		if(resetCrates)
		{
			for(i=0; i<DNA_Crate_ColourBase.m_Crates.Count(); i++)
			{
				DNA_Crate_ColourBase crate = DNA_Crate_ColourBase.m_Crates[i];
				if(crate && crate.m_TimeOfOpening != -1 && DistanceCondition(crate)) 
				{
					switch(crate.dna_Tier)
					{
						case"yellow":
							if(currentTime - crate.m_TimeOfOpening >= timeUntilYellowCrateResets)
							{
								ReplaceEntity(crate);
							}
							break;
								
						case"green":
							if(currentTime - crate.m_TimeOfOpening >= timeUntilGreenCrateResets)
							{
								ReplaceEntity(crate);
							}
							break;
								
						case"blue":
							if(currentTime - crate.m_TimeOfOpening >= timeUntilBlueCrateResets)
							{
								ReplaceEntity(crate);
							}
							break;
								
						case"purple":
							if(currentTime - crate.m_TimeOfOpening >= timeUntilPurpleCrateResets)
							{
								ReplaceEntity(crate);
							}
							break;
								
						case"red":
							if(currentTime - crate.m_TimeOfOpening >= timeUntilRedCrateResets)
							{
								ReplaceEntity(crate);
							}
							break;
					}						
				}
			}
		}
		if(resetSmolCrates)
		{
			for(i=0; i<DNA_Crate_Smol_ColourBase.m_SmolCrates.Count(); i++)
			{
				DNA_Crate_Smol_ColourBase smolCrate = DNA_Crate_Smol_ColourBase.m_SmolCrates[i];
				if(smolCrate && smolCrate.m_TimeOfOpening != -1 && DistanceCondition(smolCrate)) 
				{
					switch(smolCrate.dna_Tier)
					{
						case"yellow":
							if(currentTime - smolCrate.m_TimeOfOpening >= timeUntilYellowSmolCrateResets)
							{
								ReplaceEntity(smolCrate);
							}
							break;
								
						case"green":
							if(currentTime - smolCrate.m_TimeOfOpening >= timeUntilGreenSmolCrateResets)
							{
								ReplaceEntity(smolCrate);
							}
							break;
								
						case"blue":
							if(currentTime - smolCrate.m_TimeOfOpening >= timeUntilBlueSmolCrateResets)
							{
								ReplaceEntity(smolCrate);
							}
							break;
								
						case"purple":
							if(currentTime - smolCrate.m_TimeOfOpening >= timeUntilPurpleSmolCrateResets)
							{
								ReplaceEntity(smolCrate);
							}
							break;
								
						case"red":
							if(currentTime - smolCrate.m_TimeOfOpening >= timeUntilRedSmolCrateResets)
							{
								ReplaceEntity(smolCrate);
							}
							break;
					}						
				}
			}
		}
		if(resetStrongrooms)
		{
			for(j=0; j<DNA_Strongroom_ColourBase.m_Strongrooms.Count(); j++)
			{
				DNA_Strongroom_ColourBase strongroom = DNA_Strongroom_ColourBase.m_Strongrooms[j];
				if(strongroom && strongroom.m_TimeOfOpening != -1 && DistanceCondition(strongroom))
				{
					switch(strongroom.dna_Tier)
					{
						case"yellow":
							if(currentTime - strongroom.m_TimeOfOpening >= timeUntilYellowSRoomResets)
							{
								sRoomProxyPos = strongroom.ModelToWorld(strongroom.GetMemoryPointPos("Crate"));
								ReplaceEntity(strongroom);
							}
							break;
								
						case"green":
							if(currentTime - strongroom.m_TimeOfOpening >= timeUntilGreenSRoomResets)
							{
								sRoomProxyPos = strongroom.ModelToWorld(strongroom.GetMemoryPointPos("Crate"));
								ReplaceEntity(strongroom);
							}
							break;
								
						case"blue":
							if(currentTime - strongroom.m_TimeOfOpening >= timeUntilBlueSRoomResets)
							{
								sRoomProxyPos = strongroom.ModelToWorld(strongroom.GetMemoryPointPos("Crate"));
								ReplaceEntity(strongroom);
							}
							break;
								
						case"purple":
							if(currentTime - strongroom.m_TimeOfOpening >= timeUntilPurpleSRoomResets)
							{
								sRoomProxyPos = strongroom.ModelToWorld(strongroom.GetMemoryPointPos("Crate"));
								ReplaceEntity(strongroom);
							}
							break;
								
						case"red":
							if(currentTime - strongroom.m_TimeOfOpening >= timeUntilRedSRoomResets)
							{
								sRoomProxyPos = strongroom.ModelToWorld(strongroom.GetMemoryPointPos("Crate"));
								ReplaceEntity(strongroom);
							}
							break;
					}
				
					for(k=0; k<DNA_Crate_ColourBase.m_Crates.Count(); k++)
					{
						crate = DNA_Crate_ColourBase.m_Crates[k];
						if(crate && vector.Distance(crate.GetPosition(), sRoomProxyPos) <3)
							crate.Delete();
					}
				}
			}
		}
		if(resetOneWayDoors)
		{			
			for(l=0; l<DNA_Lockout_OneWayDoor_Locked_ColourBase.m_OneWayDoors.Count(); l++)
			{
				DNA_Lockout_OneWayDoor_Locked_ColourBase oneWayDoor = DNA_Lockout_OneWayDoor_Locked_ColourBase.m_OneWayDoors[l];
				if(oneWayDoor && oneWayDoor.m_TimeOfOpening != -1 && DistanceCondition(oneWayDoor))
				{
					switch(oneWayDoor.dna_Tier)
					{
						case"yellow":
							if(currentTime - oneWayDoor.m_TimeOfOpening >= timeUntilYellowOWDoorResets)
							{
								ReplaceEntity(oneWayDoor);
							}
							break;
								
						case"green":
							if(currentTime - oneWayDoor.m_TimeOfOpening >= timeUntilGreenOWDoorResets)
							{
								ReplaceEntity(oneWayDoor);
							}
							break;
								
						case"blue":
							if(currentTime - oneWayDoor.m_TimeOfOpening >= timeUntilBlueOWDoorResets)
							{
								ReplaceEntity(oneWayDoor);
							}
							break;
								
						case"purple":
							if(currentTime - oneWayDoor.m_TimeOfOpening >= timeUntilPurpleOWDoorResets)
							{
								ReplaceEntity(oneWayDoor);
							}
							break;
								
						case"red":
							if(currentTime - oneWayDoor.m_TimeOfOpening >= timeUntilRedOWDoorResets)
							{
								ReplaceEntity(oneWayDoor);
							}
							break;
								
						case"orange":
							if(currentTime - oneWayDoor.m_TimeOfOpening >= timeUntilOrangeOWDoorResets)
							{
								ReplaceEntity(oneWayDoor);
							}
							break;
					}
				}
			}
		}
		if(resetLockouts)
		{			
			for(m=0; m<DNA_Lockout_ColourBase.m_LockoutDoors.Count(); m++)
			{
				DNA_Lockout_ColourBase lockout = DNA_Lockout_ColourBase.m_LockoutDoors[m];
				if(lockout && lockout.m_TimeOfOpening != -1 && DistanceCondition(lockout))
				{
					switch(lockout.dna_Tier)
					{
						case"yellow":
							if(currentTime - lockout.m_TimeOfOpening >= timeUntilYellowLockoutResets)
							{
								ReplaceEntity(lockout);
							}
							break;
								
						case"green":
							if(currentTime - lockout.m_TimeOfOpening >= timeUntilGreenLockoutResets)
							{
								ReplaceEntity(lockout);
							}
							break;
								
						case"blue":
							if(currentTime - lockout.m_TimeOfOpening >= timeUntilBlueLockoutResets)
							{
								ReplaceEntity(lockout);
							}
							break;
								
						case"purple":
							if(currentTime - lockout.m_TimeOfOpening >= timeUntilPurpleLockoutResets)
							{
								ReplaceEntity(lockout);
							}
							break;
								
						case"red":
							if(currentTime - lockout.m_TimeOfOpening >= timeUntilRedLockoutResets)
							{
								ReplaceEntity(lockout);
							}
							break;
								
						case"orange":
							if(currentTime - lockout.m_TimeOfOpening >= timeUntilOrangeLockoutResets)
							{
								ReplaceEntity(lockout);
							}
							break;
					}
				}
			}
		}
		if(resetWarpDoors)
		{
			for(n=0; n<DNA_WarpDoor_NoLock_ColourBase.m_WarpDoors.Count(); n++)
			{
				DNA_WarpDoor_NoLock_ColourBase warpDoor = DNA_WarpDoor_NoLock_ColourBase.m_WarpDoors[n];
				if(warpDoor && warpDoor.m_TimeOfOpening != -1 && DistanceCondition(warpDoor) && DistanceCondition(DNA_WarpDoor_ColourBase.FindMatch(warpDoor)))
				{
					switch(warpDoor.dna_Tier)
					{
						case"yellow":
							if(currentTime - warpDoor.m_TimeOfOpening >= timeUntilYellowWarpDoorResets)
							{
								ReplaceEntity(warpDoor);
							}
							break;
								
						case"green":
							if(currentTime - warpDoor.m_TimeOfOpening >= timeUntilGreenWarpDoorResets)
							{
								ReplaceEntity(warpDoor);
							}
							break;
								
						case"blue":
							if(currentTime - warpDoor.m_TimeOfOpening >= timeUntilBlueWarpDoorResets)
							{
								ReplaceEntity(warpDoor);
							}
							break;
								
						case"purple":
							if(currentTime - warpDoor.m_TimeOfOpening >= timeUntilPurpleWarpDoorResets)
							{
								ReplaceEntity(warpDoor);
							}
							break;
								
						case"red":
							if(currentTime - warpDoor.m_TimeOfOpening >= timeUntilRedWarpDoorResets)
							{
								ReplaceEntity(warpDoor);
							}
							break;
								
						case"orange":
							if(currentTime - warpDoor.m_TimeOfOpening >= timeUntilOrangeWarpDoorResets)
							{
								ReplaceEntity(warpDoor);
							}
							break;
					}
				}
			}
		}
	}
	
	bool DistanceCondition(Object object)
	{
		array<Man> players = new array<Man>;
		GetGame().GetWorld().GetPlayerList(players);
		for(int i = 0; i < players.Count(); i++)
		{
			if(vector.Distance(object.GetPosition(), players[i].GetPosition()) < min_Distance_Between_Nearest_Player)
				return false;
		}
		return true;
	}
	
	void ReplaceEntity(Object oldEntity)
	{
		Object newEntity;
		vector pos, ori;
		string entType;
		pos = oldEntity.GetPosition();
		ori = oldEntity.GetOrientation();
		entType = oldEntity.GetType();
		if(entType.Contains("Proxy"))
			return;
		switch(entType)
		{
			case"DNA_WarpDoor_A_Red_DO_NOT_USE":
				entType = "DNA_WarpDoor_A_Red";
				break;
				
			case"DNA_WarpDoor_B_Red_DO_NOT_USE":
				entType = "DNA_WarpDoor_B_Red";
				break;
				
			case"DNA_WarpDoor_A_Purple_DO_NOT_USE":
				entType = "DNA_WarpDoor_A_Purple";
				break;
				
			case"DNA_WarpDoor_B_Purple_DO_NOT_USE":
				entType = "DNA_WarpDoor_B_Purple";
				break;
				
			case"DNA_WarpDoor_A_Blue_DO_NOT_USE":
				entType = "DNA_WarpDoor_A_Blue";
				break;
				
			case"DNA_WarpDoor_B_Blue_DO_NOT_USE":
				entType = "DNA_WarpDoor_B_Blue";
				break;
				
			case"DNA_WarpDoor_A_Green_DO_NOT_USE":
				entType = "DNA_WarpDoor_A_Green";
				break;
				
			case"DNA_WarpDoor_B_Green_DO_NOT_USE":
				entType = "DNA_WarpDoor_B_Green";
				break;
				
			case"DNA_WarpDoor_A_Yellow_DO_NOT_USE":
				entType = "DNA_WarpDoor_A_Yellow";
				break;
				
			case"DNA_WarpDoor_B_Yellow_DO_NOT_USE":
				entType = "DNA_WarpDoor_B_Yellow";
				break;
				
			case"DNA_WarpDoor_A_Orange_DO_NOT_USE":
				entType = "DNA_WarpDoor_A_Orange";
				break;
				
			case"DNA_WarpDoor_B_Orange_DO_NOT_USE":
				entType = "DNA_WarpDoor_B_Orange";
				break;
				
		}
		oldEntity.Delete();
		newEntity = GetGame().CreateObjectEx(entType, pos, ECE_SETUP | ECE_UPDATEPATHGRAPH | ECE_CREATEPHYSICS);
		newEntity.SetPosition(pos);
		newEntity.SetOrientation(ori);
	}
	
	void DasBoot()
	{
		int year, month, day;
		GetYearMonthDay(year, month, day);
		startDay = day;
		m_DNAResetTimer.Run(timeBetweenChecks * 60, this, "CheckResetConditions", NULL, true);
		Print("[DNA DEBUG] - Reset Timer: Starting");
	}
}