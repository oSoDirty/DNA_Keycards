class DNA_KeyCard_KeyCardChip_Base: ItemBase
{
	string GetSwitchClass()
	{
		return ConfigGetString("switchClass");
	}
}

class DNA_KeyCard_KeyCardChip_Yellow: DNA_KeyCard_KeyCardChip_Base {}
class DNA_KeyCard_KeyCardChip_Green: DNA_KeyCard_KeyCardChip_Base {}
class DNA_KeyCard_KeyCardChip_Blue: DNA_KeyCard_KeyCardChip_Base {}
class DNA_KeyCard_KeyCardChip_Purple: DNA_KeyCard_KeyCardChip_Base {}
class DNA_KeyCard_KeyCardChip_Red: DNA_KeyCard_KeyCardChip_Base {}