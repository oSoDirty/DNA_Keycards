class DNA_Crate_Keyed_ColourBase: DNA_Crate_ColourBase
{
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionRequiresKeycard);
		AddAction(ActionHandleKeycard);
	}
}