class DNA_KeyCard_BlisterPackChipBase: ItemBase
{
	override void SetActions()
	{
		super.SetActions();
		RemoveAction(ActionUnpackBox);
		AddAction(ActionUnpackMicrochip);
	}
}

class DNA_KeyCard_BlisterPackChip_Yellow: DNA_KeyCard_BlisterPackChipBase {}
class DNA_KeyCard_BlisterPackChip_Green: DNA_KeyCard_BlisterPackChipBase {}
class DNA_KeyCard_BlisterPackChip_Blue: DNA_KeyCard_BlisterPackChipBase {}
class DNA_KeyCard_BlisterPackChip_Purple: DNA_KeyCard_BlisterPackChipBase {}
class DNA_KeyCard_BlisterPackChip_Red: DNA_KeyCard_BlisterPackChipBase {}