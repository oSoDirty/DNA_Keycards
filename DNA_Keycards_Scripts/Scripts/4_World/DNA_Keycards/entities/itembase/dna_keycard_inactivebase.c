class DNA_KeyCard_InactiveBase: ItemBase
{
	protected string dna_PHFor;
	
	string GetSwitchType()
	{
		return dna_PHFor;
	}

	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionActivateKeycard);
	}
}

class DNA_KeyCard_Yellow_Inactive: DNA_KeyCard_InactiveBase
{
	void DNA_KeyCard_Yellow_Inactive()
	{
		dna_PHFor = "DNA_KeyCard_Yellow";
	}		
}

class DNA_KeyCard_Green_Inactive: DNA_KeyCard_InactiveBase
{
	void DNA_KeyCard_Green_Inactive()
	{
		dna_PHFor = "DNA_KeyCard_Green";
	}		
}

class DNA_KeyCard_Blue_Inactive: DNA_KeyCard_InactiveBase
{
	void DNA_KeyCard_Blue_Inactive()
	{
		dna_PHFor = "DNA_KeyCard_Blue";
	}		
}

class DNA_KeyCard_Purple_Inactive: DNA_KeyCard_InactiveBase
{
	void DNA_KeyCard_Purple_Inactive()
	{
		dna_PHFor = "DNA_KeyCard_Purple";
	}		
}

class DNA_KeyCard_Red_Inactive: DNA_KeyCard_InactiveBase
{
	void DNA_KeyCard_Red_Inactive()
	{
		dna_PHFor = "DNA_KeyCard_Red";
	}		
}
	