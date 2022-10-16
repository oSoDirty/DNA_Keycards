class DNA_WarpDoor_ColourBase: DNA_WarpDoor_NoLock_ColourBase
{
	void DNA_WarpDoor_ColourBase()
	{
		dna_HasLock = true;
		dna_IsLocked = true;
	}
	
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionRequiresKeycard);
		AddAction(ActionUnlockWarpDoors);
	}
	
	static DNA_WarpDoor_NoLock_ColourBase FindMatch(DNA_WarpDoor_NoLock_ColourBase warpDoor)
	{
		DNA_WarpDoor_NoLock_ColourBase warpDoorMatch;
		m_WarpDoors = DNA_WarpDoor_NoLock_ColourBase.GetWarpDoors();
		if(m_WarpDoors)
		{
			for(int i = 0; i < m_WarpDoors.Count(); i++)
			{
				warpDoorMatch = DNA_WarpDoor_NoLock_ColourBase.Cast(m_WarpDoors[i]);
				if(warpDoor.GetType() != warpDoorMatch.GetType() && warpDoorMatch.dna_Tier == warpDoor.dna_Tier)
				{
					if(warpDoorMatch.dna_HasLock && warpDoor.dna_HasLock  && warpDoorMatch.dna_IsLocked && warpDoor.dna_IsLocked)
						return warpDoorMatch;
					
					if(warpDoorMatch.dna_HasLock && warpDoor.dna_HasLock  && !warpDoorMatch.dna_IsLocked && !warpDoor.dna_IsLocked)
						return warpDoorMatch;
					
					if(!warpDoorMatch.dna_HasLock && !warpDoor.dna_HasLock)
						return warpDoorMatch;
				}			
			}
		}
		return NULL;
	}
}

class DNA_WarpDoor_A_Red: DNA_WarpDoor_ColourBase
{
	void DNA_WarpDoor_A_Red()
	{
		dna_Tier = "red";
	}
}

class DNA_WarpDoor_B_Red: DNA_WarpDoor_ColourBase
{
	void DNA_WarpDoor_B_Red()
	{
		dna_Tier = "red";
	}
}

class DNA_WarpDoor_A_Purple: DNA_WarpDoor_ColourBase
{
	void DNA_WarpDoor_A_Purple()
	{
		dna_Tier = "purple";
	}
}

class DNA_WarpDoor_B_Purple: DNA_WarpDoor_ColourBase
{
	void DNA_WarpDoor_B_Purple()
	{
		dna_Tier = "purple";
	}
}

class DNA_WarpDoor_A_Blue: DNA_WarpDoor_ColourBase
{
	void DNA_WarpDoor_A_Blue()
	{
		dna_Tier = "blue";
	}
}

class DNA_WarpDoor_B_Blue: DNA_WarpDoor_ColourBase
{
	void DNA_WarpDoor_B_Blue()
	{
		dna_Tier = "blue";
	}
}

class DNA_WarpDoor_A_Green: DNA_WarpDoor_ColourBase
{
	void DNA_WarpDoor_A_Green()
	{
		dna_Tier = "green";
	}
}

class DNA_WarpDoor_B_Green: DNA_WarpDoor_ColourBase
{
	void DNA_WarpDoor_B_Green()
	{
		dna_Tier = "green";
	}
}

class DNA_WarpDoor_A_Yellow: DNA_WarpDoor_ColourBase
{
	void DNA_WarpDoor_A_Yellow()
	{
		dna_Tier = "yellow";
	}
}

class DNA_WarpDoor_B_Yellow: DNA_WarpDoor_ColourBase
{
	void DNA_WarpDoor_B_Yellow()
	{
		dna_Tier = "yellow";
	}
}

class DNA_WarpDoor_A_Orange: DNA_WarpDoor_ColourBase
{
	void DNA_WarpDoor_A_Orange()
	{
		dna_Tier = "orange";
	}
}

class DNA_WarpDoor_B_Orange: DNA_WarpDoor_ColourBase
{
	void DNA_WarpDoor_B_Orange()
	{
		dna_Tier = "orange";
	}
}