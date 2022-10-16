class ActionOpenSmolCrate: ActionInteractBase
{

	void ActionOpenSmolCrate()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_HUDCursorIcon = CursorIcons.CloseHood;
	}

	override string GetText()
	{
		return "Open";
	}
	
	override bool Can(PlayerBase player, ActionTarget target, ItemBase item)
	{
		return true;
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object target_object = target.GetObject();
		
		DNA_Crate_ColourBase crate = DNA_Crate_ColourBase.Cast( target_object );
		
		return !crate.IsOpen();
	}

	override void OnExecuteServer( ActionData action_data )
	{
		Object target_object = action_data.m_Target.GetObject();
		DNA_Crate_Smol_ColourBase crate = DNA_Crate_Smol_ColourBase.Cast( target_object );
		if(crate) crate.Open();
		DNA_Crate_Smol_Yellow crate_yellow;
		DNA_Crate_Smol_Green crate_green;
		DNA_Crate_Smol_Blue	crate_blue;
		DNA_Crate_Smol_Purple crate_purple;
		DNA_Crate_Smol_Red crate_red;
		if(CastTo(crate_yellow, crate))
			crate_yellow.SpawnTheShit();
		if(CastTo(crate_green, crate))
			crate_green.SpawnTheShit();
		if(CastTo(crate_blue, crate))
			crate_blue.SpawnTheShit();
		if(CastTo(crate_purple, crate))
			crate_purple.SpawnTheShit();
		if(CastTo(crate_red, crate))
			crate_red.SpawnTheShit();
	}
	
	override void OnExecuteClient( ActionData action_data )
	{
		Object target_object = action_data.m_Target.GetObject();
		DNA_Crate_Smol_ColourBase crate;
		if(CastTo(crate, target_object))
		{
			DNA_Sounds.SoundKCCrateSmolOpenPlay(crate.GetPosition());
		}
	}
	
	override void OnEndServer( ActionData action_data )
	{
		Object target_object = action_data.m_Target.GetObject();
		DNA_Crate_ColourBase crate = DNA_Crate_ColourBase.Cast( target_object );
		if( crate )
		{
			crate.SoundSynchRemoteReset();
		}
	}
}
