class DNA_KeyCard_BlisterPackChip: ItemBase
{
	override void SetActions()
	{
		super.SetActions();
		RemoveAction(ActionUnpackBox);
		AddAction(ActionUnpackMicrochip);
	}
}