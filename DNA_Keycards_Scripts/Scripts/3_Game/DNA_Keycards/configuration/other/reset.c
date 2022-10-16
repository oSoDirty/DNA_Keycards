class DNA_ResetTimer_Settings
{
	string dna_WARNING;
	string dna_WARNING_CONTINUED;
	string dna_WARNING_CONTINUED_;
	
	bool dna_UseResetTimer;
	
	int dna_TimeBetweenChecks;
	
	float dna_Min_Distance_Between_Nearest_Player;
	
	bool dna_ResetCrates;
	int dna_TimeUntilYellowCrateResets;
	int dna_TimeUntilGreenCrateResets;
	int dna_TimeUntilBlueCrateResets;
	int dna_TimeUntilPurpleCrateResets;
	int dna_TimeUntilRedCrateResets;
	
	bool dna_ResetStrongrooms;
	int dna_TimeUntilYellowSRoomResets;
	int dna_TimeUntilGreenSRoomResets;
	int dna_TimeUntilBlueSRoomResets;
	int dna_TimeUntilPurpleSRoomResets;
	int dna_TimeUntilRedSRoomResets;
	
	bool dna_ResetLockouts;
	int dna_TimeUntilYellowLockoutResets;
	int dna_TimeUntilGreenLockoutResets;
	int dna_TimeUntilBlueLockoutResets;
	int dna_TimeUntilPurpleLockoutResets;
	int dna_TimeUntilRedLockoutResets;
	int dna_TimeUntilOrangeLockoutResets;
	
	bool dna_ResetOneWayDoors;
	int dna_TimeUntilYellowOWDoorResets;
	int dna_TimeUntilGreenOWDoorResets;
	int dna_TimeUntilBlueOWDoorResets;
	int dna_TimeUntilPurpleOWDoorResets;
	int dna_TimeUntilRedOWDoorResets;
	int dna_TimeUntilOrangeOWDoorResets;
	
	bool dna_ResetWarpDoors;
	int dna_TimeUntilYellowWarpDoorResets;
	int dna_TimeUntilGreenWarpDoorResets;
	int dna_TimeUntilBlueWarpDoorResets;
	int dna_TimeUntilPurpleWarpDoorResets;
	int dna_TimeUntilRedWarpDoorResets;
	int dna_TimeUntilOrangeWarpDoorResets;
}

class DNA_ResetTimer_Settings_Data
{
	private static ref DNA_ResetTimer_Settings dna_TimerSettings = NULL;
	
	static DNA_ResetTimer_Settings GetTimerSettings()
	{
		if(dna_TimerSettings == NULL && GetGame().IsDedicatedServer())
			InitTimerSettings();
		
		return dna_TimerSettings;
	}
	
	static void InitTimerSettings()
	{
		if(GetGame().IsDedicatedServer())
			dna_TimerSettings = LoadTimerSettings();
	}
	
	private static DNA_ResetTimer_Settings LoadTimerSettings()
	{
		DNA_ResetTimer_Settings config = new DNA_ResetTimer_Settings;
		if(!FileExist(DNATimerSettings))
		{
			if(GetGame().IsDedicatedServer())
			{
				Print("[DNA DEBUG] - Timer Settings not found.... Creating now.");
				CreateDefaultSettings(config);
			}
		}
		else
		{
			if(GetGame().IsDedicatedServer())
				Print("[DNA DEBUG] - Timer Settings found.... Loading.");
		}
		JsonFileLoader<DNA_ResetTimer_Settings>.JsonLoadFile(DNATimerSettings, config);
		return config;
	}
	
	private static void CreateDefaultSettings(DNA_ResetTimer_Settings config)
	{
		//config.WholeLottaShite
		config.dna_WARNING = "You must turn on and configure all types and tiers individually, distance to nearsest player is the only shared value.";
		config.dna_WARNING_CONTINUED = "Distance is in meters, and all time is in whole minutes. To turn off a tier, just set to longer than intended uptime.";
		config.dna_WARNING_CONTINUED_ = "THE RESET TIMER BREAKS AT MIDNIGHT... YOU MUST RESTART AT MIDNIGHT IF USING THE RESET TIMER";
		
		config.dna_UseResetTimer = false;
		
		config.dna_TimeBetweenChecks = 5;
		
		config.dna_Min_Distance_Between_Nearest_Player = 500.0;
		
		config.dna_ResetCrates = false;
		config.dna_TimeUntilYellowCrateResets = 30;
		config.dna_TimeUntilGreenCrateResets = 30;
		config.dna_TimeUntilBlueCrateResets = 30;
		config.dna_TimeUntilPurpleCrateResets = 30;
		config.dna_TimeUntilRedCrateResets = 30;
		
		config.dna_ResetStrongrooms = false;
		config.dna_TimeUntilYellowSRoomResets = 30;
		config.dna_TimeUntilGreenSRoomResets = 30;
		config.dna_TimeUntilBlueSRoomResets = 30;
		config.dna_TimeUntilPurpleSRoomResets = 30;
		config.dna_TimeUntilRedSRoomResets = 30;
		
		config.dna_ResetLockouts = false;
		config.dna_TimeUntilYellowLockoutResets = 30;
		config.dna_TimeUntilGreenLockoutResets = 30;
		config.dna_TimeUntilBlueLockoutResets = 30;
		config.dna_TimeUntilPurpleLockoutResets = 30;
		config.dna_TimeUntilRedLockoutResets = 30;
		config.dna_TimeUntilOrangeLockoutResets = 30;
		
		config.dna_ResetOneWayDoors = false;
		config.dna_TimeUntilYellowOWDoorResets = 30;
		config.dna_TimeUntilGreenOWDoorResets = 30;
		config.dna_TimeUntilBlueOWDoorResets = 30;
		config.dna_TimeUntilPurpleOWDoorResets = 30;
		config.dna_TimeUntilRedOWDoorResets = 30;
		config.dna_TimeUntilOrangeOWDoorResets = 30;
		
		config.dna_ResetWarpDoors = false;
		config.dna_TimeUntilYellowWarpDoorResets = 30;
		config.dna_TimeUntilGreenWarpDoorResets = 30;
		config.dna_TimeUntilBlueWarpDoorResets = 30;
		config.dna_TimeUntilPurpleWarpDoorResets = 30;
		config.dna_TimeUntilRedWarpDoorResets = 30;
		config.dna_TimeUntilOrangeWarpDoorResets = 30;
		
		if(!FileExist(SecondaryConfigRoot))
		{
			Print("[KEYCARDS] - Secondary Config Root not found.... Creating.");
			MakeDirectory(SecondaryConfigRoot);
		}
		JsonFileLoader<DNA_ResetTimer_Settings>.JsonSaveFile(DNATimerSettings, config);
	}
}