class ActionOpenKCCrate: ActionInteractBase
{
	void ActionOpenKCCrate()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_HUDCursorIcon = CursorIcons.OpenHood;
	}

	override string GetText()
	{
		return "#open";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object target_object = target.GetObject();
		if ( target_object.IsItemBase() )
		{
			KC_Crate_ColourBase ntarget = KC_Crate_ColourBase.Cast( target_object );
			if( ntarget )
			{
				if( !ntarget.IsLocked() && !ntarget.IsOpen() )
				{
					return true;
				}
			}
		}
		return false;
	}

	override void OnExecuteServer( ActionData action_data )
	{
		Object target_object = action_data.m_Target.GetObject();
		KC_Crate_ColourBase ntarget = KC_Crate_ColourBase.Cast( target_object );
		if( ntarget )
		{
			ntarget.Open();
		}
		KC_Crate_Yellow yellowCrate;
		if(CastTo(yellowCrate, target_object))
			yellowCrate.DoTheDamnThing("yellow");
				
		KC_Crate_Green greenCrate;
		if(CastTo(greenCrate, target_object))
			greenCrate.DoTheDamnThing("green");
				
		KC_Crate_Blue blueCrate;
		if(CastTo(blueCrate, target_object))
			blueCrate.DoTheDamnThing("blue");
		
				
		KC_Crate_Purple purpleCrate;
		if(CastTo(purpleCrate, target_object))
			purpleCrate.DoTheDamnThing("purple");
		
				
		KC_Crate_Red redCrate;
		if(CastTo(redCrate, target_object))
			redCrate.DoTheDamnThing("red");
		
	}
	
	override void OnEndServer( ActionData action_data )
	{
		Object target_object = action_data.m_Target.GetObject();
		KC_Crate_ColourBase ntarget = KC_Crate_ColourBase.Cast( target_object );
		if( ntarget )
		{
			ntarget.SoundSynchRemoteReset();
		}
	}
}