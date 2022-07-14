class DNA_Strongroom_ColourBase: BuildingSuper
{
	protected string dna_Tier;
	protected ref array<ref DNA_Config_Main_System> dna_MainSystemConfig;
	protected ref array<ref DNA_Config_Mob_System> dna_MobConfig;
	protected autoptr array<string> dna_Mob_Wolf = new array<string>;
	protected autoptr array<string> dna_Mob_Bear = new array<string>;
	protected autoptr array<string> dna_Mob_Infected = new array<string>;
	protected autoptr array<string> dna_Mob_BossYellow = new array<string>;
	protected autoptr array<string> dna_Mob_BossGreen = new array<string>;
	protected autoptr array<string> dna_Mob_BossBlue = new array<string>;
	protected autoptr array<string> dna_Mob_BossPurple = new array<string>;
	protected autoptr array<string> dna_Mob_BossRed = new array<string>;
	
	void DNA_Strongroom_ColourBase()
	{
		if(GetGame().IsDedicatedServer())
			dna_MainSystemConfig = DNA_Keycards_Main_System.GetInstance().GetConfig().GetConfigData().GetSystemArray();
			dna_MobConfig = DNA_Keycards_Mob_System.GetInstance().GetConfig().GetConfigData().GetSystemArray();
		
		AssortArrays();
	}
	
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionRequiresKeycard);
		AddAction(ActionHandleKeycard);
	}
	
	bool IsCardInserted()
	{
		return FindAttachmentBySlotName("KeyCard") != null;
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
		}
	}
	
	void ReturnCardToPlayer(PlayerBase player)
	{
		DNA_KeyCard_ColourBase keyCard = DNA_KeyCard_ColourBase.Cast(FindAttachmentBySlotName("KeyCard"));
		if(player && keyCard)
		{
			if(keyCard.GetRemainingUses() > 1 && keyCard.GetRemainingUses() < 11)
			{
				/*DNA_KeyCard_ColourBase cardInHand = DNA_KeyCard_ColourBase.Cast(player.GetHumanInventory().CreateInHands(keyCard.GetType()));
				cardInHand.SetRemainingUses(keyCard.GetRemainingUses() + -1);
				keyCard.Delete();*/
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
	
	int GetInfectedSpawnSettings()
	{
		int index;
		switch(dna_Tier)
		{
			case"yellow":
				index = 25;
				break;
			case"green":
				index = 30;
				break;
			case"blue":
				index = 35;
				break;
			case"purple":
				index = 40;
				break;
			case"red":
				index = 45;
				break;
		}
		if(!index)
		{
			Print("DNA KEYCARDS - ERROR - GetInfectedSpawnSettings() == NO INDEX FOUND");
			return 0;
		}
		return dna_MainSystemConfig.Get(index).GetSystemSetting();
	}
	
	void SpawnInfected()
	{
		vector spawnPos, memPointPos, mtwPos;
		float y_ground;
		int i, j, k;
		for(i = 0; i < GetInfectedSpawnSettings(); i++)
		{
			k = i - 19;
			if(i > 39) break; //Limit to 40 zombies
			if(i > 19)
				memPointPos = GetMemoryPointPos("z" + k);
			else
				memPointPos = GetMemoryPointPos("z" + i);
			mtwPos = ModelToWorld(memPointPos);
			y_ground = GetGame().SurfaceY(mtwPos[0], mtwPos[2]);
			spawnPos = Vector(mtwPos[0], y_ground, mtwPos[2]);
			GetGame().CreateObject(dna_Mob_Infected.GetRandomElement(), spawnPos, false, true);
		}
	}
	
	int GetWolfSpawnSettings()
	{
		int index;
		switch(dna_Tier)
		{
			case"yellow":
				index = 23;
				break;
			case"green":
				index = 28;
				break;
			case"blue":
				index = 33;
				break;
			case"purple":
				index = 38;
				break;
			case"red":
				index = 43;
				break;
		}
		if(!index)
		{
			Print("DNA KEYCARDS - ERROR - GetWolfSpawnSettings() == NO INDEX FOUND");
			return 0;
		}
		return dna_MainSystemConfig.Get(index).GetSystemSetting();
	}
	
	void SpawnWolves()
	{
		array<string> color = {"Grey", "White"};
		int i;
		for(i = 0; i < GetWolfSpawnSettings(); i++)
		{
			if(i > 9) break; //Limit to 10 wolves
			GetGame().CreateObject(dna_Mob_Wolf.GetRandomElement(), RandomizePosition(GetPosition()), false, true);
		}
	}
	
	int GetBearSpawnSettings()
	{
		int index;
		switch(dna_Tier)
		{
			case"yellow":
				index = 24;
				break;
			case"green":
				index = 29;
				break;
			case"blue":
				index = 34;
				break;
			case"purple":
				index = 39;
				break;
			case"red":
				index = 44;
				break;
		}
		if(!index)
		{
			Print("DNA KEYCARDS - ERROR - GetBearSpawnSettings() == NO INDEX FOUND");
			return 0;
		}
		return dna_MainSystemConfig.Get(index).GetSystemSetting();
	}
	
	void SpawnBears()
	{
		int i;
		for(i = 0; i < GetBearSpawnSettings(); i++)
		{
			if(i > 5) break; //Limit to 6 bears
			GetGame().CreateObject(dna_Mob_Bear.GetRandomElement(), RandomizePosition(GetPosition()), false, true);
		}
	}
	
	void SpawnBoss()
	{
		array<string> mobTypes;
		switch(dna_Tier)
		{
			case"yellow":
				mobTypes = dna_Mob_BossYellow;
				break;
				
			case"green":
				mobTypes = dna_Mob_BossGreen;
				break;
				
			case"blue":
				mobTypes = dna_Mob_BossBlue;
				break;
				
			case"purple":
				mobTypes = dna_Mob_BossPurple;
				break;
				
			case"red":
				mobTypes = dna_Mob_BossRed;
				break;
		}
		for(int i = 0; i < mobTypes.Count(); i++)
		{
			GetGame().CreateObject(mobTypes.Get(i), RandomizePosition(GetPosition()), false, true);
		}
	}
	
	vector RandomizePosition(vector position)
	{
		float x, y, z, x_n, x_p, z_n, z_p;
		int roll_x, roll_z;
		roll_x = Math.RandomIntInclusive(1,6);
		roll_z = Math.RandomIntInclusive(1,6);
		vector randomOffset;
		x = Math.RandomFloatInclusive(-15, -20);
		x_p = Math.RandomFloatInclusive(15, 20);
		z = Math.RandomFloatInclusive(-15, -20);
		z_p = Math.RandomFloatInclusive(15, 20);
		if(roll_x > 3)
			x = x_p;
		if(roll_z > 3)
			z = z_p;
		y = GetGame().SurfaceY(position[0], position[2]);
		randomOffset = Vector(x, y, z);
		return position + randomOffset;
	}
	
	void AssortArrays()
	{
		int i;
		if(dna_MobConfig)
		{
			for(i = 0; i < dna_MobConfig.Count(); i++)
			{
				if(dna_MobConfig.Get(i).GetDefaultMob() == "wolf")
					dna_Mob_Wolf.Insert(dna_MobConfig.Get(i).GetMobType());
				
				if(dna_MobConfig.Get(i).GetDefaultMob() == "bear")
					dna_Mob_Bear.Insert(dna_MobConfig.Get(i).GetMobType());
				
				if(dna_MobConfig.Get(i).GetDefaultMob() == "infected")
					dna_Mob_Infected.Insert(dna_MobConfig.Get(i).GetMobType());
				
				if(dna_MobConfig.Get(i).GetDefaultMob() == "bossYellow")
					dna_Mob_BossYellow.Insert(dna_MobConfig.Get(i).GetMobType());
				
				if(dna_MobConfig.Get(i).GetDefaultMob() == "bossGreen")
					dna_Mob_BossGreen.Insert(dna_MobConfig.Get(i).GetMobType());
				
				if(dna_MobConfig.Get(i).GetDefaultMob() == "bossBlue")
					dna_Mob_BossBlue.Insert(dna_MobConfig.Get(i).GetMobType());
				
				if(dna_MobConfig.Get(i).GetDefaultMob() == "bossPurple")
					dna_Mob_BossPurple.Insert(dna_MobConfig.Get(i).GetMobType());
				
				if(dna_MobConfig.Get(i).GetDefaultMob() == "bossRed")
					dna_Mob_BossRed.Insert(dna_MobConfig.Get(i).GetMobType());
			}
		}
	}
}

class DNA_Strongroom_Yellow: DNA_Strongroom_ColourBase
{
	void DNA_Strongroom_Yellow()
	{
		dna_Tier = "yellow";
	}
}

class DNA_Strongroom_Green: DNA_Strongroom_ColourBase
{
	void DNA_Strongroom_Green()
	{
		dna_Tier = "green";
	}
}

class DNA_Strongroom_Blue: DNA_Strongroom_ColourBase
{
	void DNA_Strongroom_Blue()
	{
		dna_Tier = "blue";
	}
}

class DNA_Strongroom_Purple: DNA_Strongroom_ColourBase
{
	void DNA_Strongroom_Purple()
	{
		dna_Tier = "purple";
	}
}

class DNA_Strongroom_Red: DNA_Strongroom_ColourBase
{
	void DNA_Strongroom_Red()
	{
		dna_Tier = "red";
	}
}