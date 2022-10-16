modded class ActionInteractBase
{
	ref array<DNA_WarpDoor_NoLock_ColourBase> m_WarpDoors = new array<DNA_WarpDoor_NoLock_ColourBase>;
	
	void UnlockArea(DNA_WarpDoor_NoLock_ColourBase warpDoor, DNA_WarpDoor_NoLock_ColourBase warpDoorMatch)
	{
		string newType, newMatchType;
		vector newPos, newMatchPos, newOri, newMatchOri;
		Object newObject, newObjectMatch;
		DNA_WarpDoor_NoLock_ColourBase newWarpDoor, newWarpDoorMatch;
		if(warpDoor && warpDoorMatch)
		{
			newType = warpDoor.GetType() + "_DO_NOT_USE";
			newMatchType = warpDoorMatch.GetType() + "_DO_NOT_USE";
			newPos = warpDoor.GetPosition();
			newMatchPos = warpDoorMatch.GetPosition();
			newOri = warpDoor.GetOrientation();
			newMatchOri = warpDoorMatch.GetOrientation();
			warpDoor.Delete();
			warpDoorMatch.Delete();
			newObject = GetGame().CreateObjectEx(newType, newPos, ECE_SETUP | ECE_UPDATEPATHGRAPH | ECE_CREATEPHYSICS);
			if(CastTo(newWarpDoor, newObject))
			{
				newWarpDoor.SetPosition(newPos);
				newWarpDoor.SetOrientation(newOri);
				newWarpDoor.m_TimeOfOpening = DNA_Keycards_Main_System.GetTimeInSeconds();
				newWarpDoor.SetSynchDirty();
			}
			newObjectMatch = GetGame().CreateObjectEx(newMatchType, newPos, ECE_SETUP | ECE_UPDATEPATHGRAPH | ECE_CREATEPHYSICS);
			if(CastTo(newWarpDoorMatch, newObjectMatch))
			{
				newWarpDoorMatch.SetPosition(newMatchPos);
				newWarpDoorMatch.SetOrientation(newMatchOri);
				newWarpDoorMatch.m_TimeOfOpening = DNA_Keycards_Main_System.GetTimeInSeconds();
				newWarpDoorMatch.SetSynchDirty();
			}
			
		}
	}
}
