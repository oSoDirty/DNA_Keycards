class DNA_Logging
{
	protected static ref DNA_Logging Logger;
	
	void DNA_Logging()
	{
		CreateLogDirectory();
	}
	
	static DNA_Logging InitLogger()
	{
		if(!Logger)
		{
			Logger = new DNA_Logging();
		}
		return Logger;
	}
	
	static void CreateLogDirectory()
	{
		if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) 
			return;
		
		if (!FileExist(dna_LoggingDirectory)) 
		{
			MakeDirectory(dna_LoggingDirectory);
		}
	}
	
	static string GetTime()
	{
		int hour, minute, second;
		string hr, min, sec, theTime;
		GetHourMinuteSecond(hour, minute, second);
        hr = hour.ToString().Trim();
        min = minute.ToString().Trim();
        sec = second.ToString().Trim();
        if (hr.Length() == 1) { hr = "0" + hr; }
        if (min.Length() == 1) { min = "0" + min; }
        if (sec.Length() == 1) { sec = "0" + sec; }
		theTime = hr + ":" + min + ":" + sec;
		return theTime;		
	}
	
	static string GetDate()
	{
		string y, m, d, theDate;
		int year, month, day;
		GetYearMonthDay(year, month, day);
        y = year.ToString().Trim();
        m = month.ToString().Trim();
        d = day.ToString().Trim();
        if (m.Length() == 1) { m = "0" + m; }
        if (d.Length() == 1) { d = "0" + d; }
		theDate = y + "-" + m + "-" + d;
		return theDate;
	}
	
	static string GetPlayerInfo(PlayerBase player)
	{
		if(player)
		{
			string playerName, playerId, playerInfo, playerPosConv;
			vector playerPos = player.GetPosition();
			playerPosConv = playerPos.ToString().Trim();
			playerId = player.GetIdentity().GetPlainId();
			playerName = player.GetIdentity().GetName();
			playerInfo = "Player: " + playerName + " with UID: " + playerId + " at postion: " + playerPosConv;
			return playerInfo;
		}
		return "No player found!!!";
	}	
	
	static void LogActivity(string logData) 
	{
		FileHandle logFile;
		string logPath = dna_LoggingDirectory;
		string fileName = logPath + GetDate() + dna_LogExtension;
		if (!FileExist(fileName))
		{
			string newLog = "Log file for " + GetDate() + "."; 
			logFile = OpenFile(fileName, FileMode.WRITE);
			FPrintln(logFile, newLog);
			CloseFile(logFile);
		}
		logFile = OpenFile(fileName, FileMode.APPEND);
		FPrintln(logFile, logData);
		CloseFile(logFile);
	}
}