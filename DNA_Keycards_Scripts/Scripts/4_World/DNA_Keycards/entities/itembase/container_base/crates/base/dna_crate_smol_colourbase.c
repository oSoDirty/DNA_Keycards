class DNA_Crate_Smol_ColourBase: DNA_Crate_ColourBase
{
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionOpenSmolCrate);
	}

	/*override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
		
		if ( IsOpen() )
		{
			SoundKCCrateSmolOpenPlay();
			UpdateVisualState();	
		}
	}*/
	
	void SpawnStuffSmol(array<string> items) // for use in 3rd party addons
	{
		if(items)
		{
			int i, count;
			string itemType;
			count = items.Count();
			for(i = 0; i < count; i++)
			{
				itemType = items.Get(i);
				GetInventory().CreateInInventory(itemType);
			}
		}
	}
}