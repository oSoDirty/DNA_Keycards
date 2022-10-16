class DNA_Lockout_OneWayDoor_Locked_ColourBase: DNA_Lockout_OneWayDoor_ColourBase
{
	static ref array<DNA_Lockout_OneWayDoor_Locked_ColourBase> m_OneWayDoors = new array<DNA_Lockout_OneWayDoor_Locked_ColourBase>;
	
	override void EEInit()
	{
		super.EEInit();
		m_OneWayDoors.Insert(this);
	}
	
	void ~DNA_Lockout_OneWayDoor_Locked_ColourBase()
	{
		if(m_OneWayDoors)
		{
			int localIndex = m_OneWayDoors.Find(this);
			if(localIndex >=0)
				m_OneWayDoors.Remove(localIndex);
		}
	}
	
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionRequiresKeycard);
		AddAction(ActionUnlockOneWayDoors);
	}
}

class DNA_Lockout_OneWayDoor_Locked_Orange: DNA_Lockout_OneWayDoor_Locked_ColourBase
{
	void DNA_Lockout_OneWayDoor_Locked_Orange()
	{
		dna_Tier = "orange";
	}
}

class DNA_Lockout_OneWayDoor_Locked_Red: DNA_Lockout_OneWayDoor_Locked_ColourBase
{
	void DNA_Lockout_OneWayDoor_Locked_Red()
	{
		dna_Tier = "red";
	}
}

class DNA_Lockout_OneWayDoor_Locked_Purple: DNA_Lockout_OneWayDoor_Locked_ColourBase
{
	void DNA_Lockout_OneWayDoor_Locked_Purple()
	{
		dna_Tier = "purple";
	}
}

class DNA_Lockout_OneWayDoor_Locked_Blue: DNA_Lockout_OneWayDoor_Locked_ColourBase
{
	void DNA_Lockout_OneWayDoor_Locked_Blue()
	{
		dna_Tier = "blue";
	}
}

class DNA_Lockout_OneWayDoor_Locked_Green: DNA_Lockout_OneWayDoor_Locked_ColourBase
{
	void DNA_Lockout_OneWayDoor_Locked_Green()
	{
		dna_Tier = "green";
	}
}

class DNA_Lockout_OneWayDoor_Locked_Yellow: DNA_Lockout_OneWayDoor_Locked_ColourBase
{
	void DNA_Lockout_OneWayDoor_Locked_Yellow()
	{
		dna_Tier = "yellow";
	}
}