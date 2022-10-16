class DNA_Keycards_Client
{	
	void DNA_Keycards_Client()
	{
		GetRPCManager().AddRPC("DNA_Keycards_Client", "SoundCrateOpen", this, SingleplayerExecutionType.Client);
		GetRPCManager().AddRPC("DNA_Keycards_Client", "SoundCardReader", this, SingleplayerExecutionType.Client);
		GetRPCManager().AddRPC("DNA_Keycards_Client", "SoundAlarmBreach", this, SingleplayerExecutionType.Client);
		GetRPCManager().AddRPC("DNA_Keycards_Client", "SoundBatteryDied", this, SingleplayerExecutionType.Client);
	}
	
	void SoundCrateOpen( CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
	{
		Param1<vector> data;
		if(!ctx.Read(data)) return;
		
		DNA_Sounds.SoundKCCrateOpenNoClickPlay(data.param1);
	}
	
	void SoundCardReader( CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
	{
		Param2<string, vector> data;
		if(!ctx.Read(data)) return;
		switch(data.param1)
		{
			case "in":
				DNA_Sounds.SoundKCCardScanPlay(data.param2);
				break;				
			case "out":
				DNA_Sounds.SoundKCCardRemovePlay(data.param2);
				break;
		}
	}
	
	void SoundAlarmBreach( CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
	{
		Param1<vector> data;
		if(!ctx.Read(data)) return;
		
		DNA_Sounds.SoundKCAlarmBreachPlay(data.param1);
	}
	
	void SoundBatteryDied( CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
	{
		Param1<vector> data;
		if(!ctx.Read(data)) return;
		
		DNA_Sounds.SoundKC40vBatteryDiedPlay(data.param1);
	}
}