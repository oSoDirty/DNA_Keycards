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
		DNA_Crate_ColourBase crate = DNA_Crate_ColourBase.Cast( target_object );
		crate.Open();
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
