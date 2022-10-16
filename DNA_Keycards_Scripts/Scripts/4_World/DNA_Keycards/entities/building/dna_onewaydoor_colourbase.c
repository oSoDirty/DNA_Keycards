class DNA_Lockout_OneWayDoor_ColourBase: DNA_Lockout_ColourBase
{
	override void SetActions()
	{
		super.SetActions();
		RemoveAction(ActionRequiresKeycard);
		RemoveAction(ActionUnlockSecuredDoors);
		AddAction(ActionUseOneWayDoor);
	}
	
	override bool CanReceiveAttachment(EntityAI attachment, int slotId)
	{
		return GetType().Contains("Locked");
	}
	
	void MovePlayer(PlayerBase player)
	{
		vector mtwPos, memPointPos, playerPos, playerOrientation, newPos;
		if(player)
		{
			playerPos = player.GetPosition();
			playerOrientation = player.GetOrientation();
			memPointPos = GetMemoryPointPos("teleport");
			mtwPos = ModelToWorld(memPointPos);
			newPos = Vector(mtwPos[0], playerPos[1], mtwPos[2]);
			player.SetPosition(newPos);
			player.SetOrientation(playerOrientation);
		}
	}
}

class DNA_Lockout_OneWayDoor: DNA_Lockout_OneWayDoor_ColourBase
{
	void DNA_Lockout_OneWayDoor()
	{
		dna_Tier = "orange";
	}
}

class DNA_Lockout_OneWayDoor_Red: DNA_Lockout_OneWayDoor_ColourBase
{
	void DNA_Lockout_OneWayDoor_Red()
	{
		dna_Tier = "red";
	}
}

class DNA_Lockout_OneWayDoor_Purple: DNA_Lockout_OneWayDoor_ColourBase
{
	void DNA_Lockout_OneWayDoor_Purple()
	{
		dna_Tier = "purple";
	}
}

class DNA_Lockout_OneWayDoor_Blue: DNA_Lockout_OneWayDoor_ColourBase
{
	void DNA_Lockout_OneWayDoor_Blue()
	{
		dna_Tier = "blue";
	}
}

class DNA_Lockout_OneWayDoor_Green: DNA_Lockout_OneWayDoor_ColourBase
{
	void DNA_Lockout_OneWayDoor_Green()
	{
		dna_Tier = "green";
	}
}

class DNA_Lockout_OneWayDoor_Yellow: DNA_Lockout_OneWayDoor_ColourBase
{
	void DNA_Lockout_OneWayDoor_Yellow()
	{
		dna_Tier = "yellow";
	}
}