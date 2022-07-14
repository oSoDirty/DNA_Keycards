modded class ActionUnlockDoors
{
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		if( !target ) return false;
		Object target_object = target.GetObject();
		DNA_Strongroom_ColourBase strongRoom;
		DNA_Lockout_ColourBase lockout;
		if(CastTo(lockout, target_object)) return false;
		if(CastTo(strongRoom, target_object))
		{
			int x = strongRoom.GetDoorIndex(target.GetComponentIndex());
			if(x == 5)
				return false;
		}
		return super.ActionCondition(player, target, item);
	}
}