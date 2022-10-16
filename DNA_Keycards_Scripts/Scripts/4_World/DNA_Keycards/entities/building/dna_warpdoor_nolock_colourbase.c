class DNA_WarpDoor_NoLock_ColourBase: DNA_Lockout_ColourBase
{
	static ref array<DNA_WarpDoor_NoLock_ColourBase> m_WarpDoors = new array<DNA_WarpDoor_NoLock_ColourBase>;
	bool dna_HasLock;
	bool dna_IsLocked;
	
	void DNA_WarpDoor_NoLock_ColourBase()
	{
		RegisterNetSyncVariableBool("dna_IsLocked");
		dna_HasLock = false;
		dna_IsLocked = false;
	}
	
	override void EEInit()
	{
		super.EEInit();
		m_WarpDoors.Insert(this);
	}
	
	void ~DNA_WarpDoor_NoLock_ColourBase()
	{
		if(m_WarpDoors)
		{
			int localIndex = m_WarpDoors.Find(this);
			if(localIndex >=0)
				m_WarpDoors.Remove(localIndex);
		}
	}
	
	static ref array<DNA_WarpDoor_NoLock_ColourBase> GetWarpDoors()
	{
		return m_WarpDoors;
	}
	
	override void SetActions()
	{
		super.SetActions();
		RemoveAction(ActionUnlockWarpDoors);
		RemoveAction(ActionUnlockSecuredDoors);
		RemoveAction(ActionRequiresKeycard);
		AddAction(ActionUseWarpDoor);		//need to make	
	}
	
	override void TakeCardToSlot(PlayerBase player)
	{
		DNA_KeyCard_Orange keyCardOrange;
		if(player && CastTo(keyCardOrange, player.GetItemInHands()))
		{
			GetInventory().CreateAttachment(keyCardOrange.GetType());
			keyCardOrange.Delete();
		}
		else
		{
			super.TakeCardToSlot(player);
		}
	}
	
	override void ReturnCardToPlayer(PlayerBase player)
	{
		DNA_KeyCard_ColourBase keyCardOrange = DNA_KeyCard_ColourBase.Cast(FindAttachmentBySlotName("KeyCard"));
		if(keyCardOrange && keyCardOrange.GetType().Contains("Orange"))
		{
			keyCardOrange.Delete();
			player.GetHumanInventory().CreateInHands("DNA_KeyCard_Error");
		}
		else
		{
			super.ReturnCardToPlayer(player);
		}
	}
}

class DNA_WarpDoor_A_Red_NoLock: DNA_WarpDoor_NoLock_ColourBase
{
	void DNA_WarpDoor_A_Red_NoLock()
	{
		dna_Tier = "red";
	}
}
class DNA_WarpDoor_B_Red_NoLock: DNA_WarpDoor_NoLock_ColourBase
{
	void DNA_WarpDoor_B_Red_NoLock()
	{
		dna_Tier = "red";
	}
}

class DNA_WarpDoor_A_Purple_NoLock: DNA_WarpDoor_NoLock_ColourBase
{
	void DNA_WarpDoor_A_Purple_NoLock()
	{
		dna_Tier = "purple";
	}
}
class DNA_WarpDoor_B_Purple_NoLock: DNA_WarpDoor_NoLock_ColourBase
{
	void DNA_WarpDoor_B_Purple_NoLock()
	{
		dna_Tier = "purple";
	}
}

class DNA_WarpDoor_A_Blue_NoLock: DNA_WarpDoor_NoLock_ColourBase
{
	void DNA_WarpDoor_A_Blue_NoLock()
	{
		dna_Tier = "blue";
	}
}
class DNA_WarpDoor_B_Blue_NoLock: DNA_WarpDoor_NoLock_ColourBase
{
	void DNA_WarpDoor_B_Blue_NoLock()
	{
		dna_Tier = "blue";
	}
}

class DNA_WarpDoor_A_Green_NoLock: DNA_WarpDoor_NoLock_ColourBase
{
	void DNA_WarpDoor_A_Green_NoLock()
	{
		dna_Tier = "green";
	}
}
class DNA_WarpDoor_B_Green_NoLock: DNA_WarpDoor_NoLock_ColourBase
{
	void DNA_WarpDoor_B_Green_NoLock()
	{
		dna_Tier = "green";
	}
}

class DNA_WarpDoor_A_Yellow_NoLock: DNA_WarpDoor_NoLock_ColourBase
{
	void DNA_WarpDoor_A_Yellow_NoLock()
	{
		dna_Tier = "yellow";
	}
}
class DNA_WarpDoor_B_Yellow_NoLock: DNA_WarpDoor_NoLock_ColourBase
{
	void DNA_WarpDoor_B_Yellow_NoLock()
	{
		dna_Tier = "yellow";
	}
}

class DNA_WarpDoor_A_Orange_NoLock: DNA_WarpDoor_NoLock_ColourBase
{
	void DNA_WarpDoor_A_Orange_NoLock()
	{
		dna_Tier = "orange";
	}
}
class DNA_WarpDoor_B_Orange_NoLock: DNA_WarpDoor_NoLock_ColourBase
{
	void DNA_WarpDoor_B_Orange_NoLock()
	{
		dna_Tier = "orange";
	}
}
	
class DNA_WarpDoor_A_Red_DO_NOT_USE: DNA_WarpDoor_A_Red_NoLock
{
	void DNA_WarpDoor_A_Red_DO_NOT_USE()
	{
		dna_HasLock = true;
	}
}
class DNA_WarpDoor_B_Red_DO_NOT_USE: DNA_WarpDoor_B_Red_NoLock
{
	void DNA_WarpDoor_B_Red_DO_NOT_USE()
	{
		dna_HasLock = true;
	}
}

class DNA_WarpDoor_A_Purple_DO_NOT_USE: DNA_WarpDoor_A_Purple_NoLock
{
	void DNA_WarpDoor_A_Purple_DO_NOT_USE()
	{
		dna_HasLock = true;
	}
}
class DNA_WarpDoor_B_Purple_DO_NOT_USE: DNA_WarpDoor_B_Purple_NoLock
{
	void DNA_WarpDoor_B_Purple_DO_NOT_USE()
	{
		dna_HasLock = true;
	}
}

class DNA_WarpDoor_A_Blue_DO_NOT_USE: DNA_WarpDoor_A_Blue_NoLock
{
	void DNA_WarpDoor_A_Blue_DO_NOT_USE()
	{
		dna_HasLock = true;
	}
}
class DNA_WarpDoor_B_Blue_DO_NOT_USE: DNA_WarpDoor_B_Blue_NoLock
{
	void DNA_WarpDoor_B_Blue_DO_NOT_USE()
	{
		dna_HasLock = true;
	}
}

class DNA_WarpDoor_A_Green_DO_NOT_USE: DNA_WarpDoor_A_Green_NoLock
{
	void DNA_WarpDoor_A_Green_DO_NOT_USE()
	{
		dna_HasLock = true;
	}
}
class DNA_WarpDoor_B_Green_DO_NOT_USE: DNA_WarpDoor_B_Green_NoLock
{
	void DNA_WarpDoor_B_Green_DO_NOT_USE()
	{
		dna_HasLock = true;
	}
}

class DNA_WarpDoor_A_Yellow_DO_NOT_USE: DNA_WarpDoor_A_Yellow_NoLock
{
	void DNA_WarpDoor_A_Yellow_DO_NOT_USE()
	{
		dna_HasLock = true;
	}
}
class DNA_WarpDoor_B_Yellow_DO_NOT_USE: DNA_WarpDoor_B_Yellow_NoLock
{
	void DNA_WarpDoor_B_Yellow_DO_NOT_USE()
	{
		dna_HasLock = true;
	}
}

class DNA_WarpDoor_A_Orange_DO_NOT_USE: DNA_WarpDoor_A_Orange_NoLock
{
	void DNA_WarpDoor_A_Orange_DO_NOT_USE()
	{
		dna_HasLock = true;
	}
}
class DNA_WarpDoor_B_Orange_DO_NOT_USE: DNA_WarpDoor_B_Orange_NoLock
{
	void DNA_WarpDoor_B_Orange_DO_NOT_USE()
	{
		dna_HasLock = true;
	}
}