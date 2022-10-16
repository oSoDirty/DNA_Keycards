modded class ActionDeployObject
{
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		DNA_Workbench_Kit kit;
		if(CastTo(kit, item))
		{
			if(!kit.AreHelpingHandsAttached() || !kit.IsSolderIronAttached())
				return false;
		}
		return super.ActionCondition(player, target, item);
	}
}

modded class ActionTogglePlaceObject
{
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		DNA_Workbench_Kit kit;
		if(CastTo(kit, item))
		{
			if(!kit.AreHelpingHandsAttached() || !kit.IsSolderIronAttached())
				return false;
		}
		return super.ActionCondition(player, target, item);
	}
}