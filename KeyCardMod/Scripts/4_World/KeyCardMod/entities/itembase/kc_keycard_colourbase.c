class KC_KeyCard_ColourBase: ItemBase
{
	protected int kcm_RemainingUses;
	
	void KC_KeyCard_ColourBase()
	{
		RegisterNetSyncVariableInt("kcm_RemainingUses", 1, int.MAX)
	}
	
	int GetRemainingUses()
	{
		return kcm_RemainingUses;
	}
	
	void SetRemainingUses(int remainingUses)
	{
		kcm_RemainingUses = remainingUses;
		SetSynchDirty();
	}
	
	bool IsMatchingTier(string typeName)
	{
		return GetType() == "KC_KeyCard_" + typeName.SubstringInverted(typeName, 0, 8);
	}

	override void OnStoreSave(ParamsWriteContext ctx)
	{
		super.OnStoreSave(ctx);

		ctx.Write(kcm_RemainingUses);
	}

	override bool OnStoreLoad(ParamsReadContext ctx, int version)
	{
		if (!super.OnStoreLoad(ctx, version))
			return false;

		if (!ctx.Read(kcm_RemainingUses))
			return false;

		return true;
	}
}

class KC_KeyCard_Yellow :KC_KeyCard_ColourBase {}
class KC_KeyCard_Green :KC_KeyCard_ColourBase {}
class KC_KeyCard_Blue :KC_KeyCard_ColourBase {}
class KC_KeyCard_Purple :KC_KeyCard_ColourBase {}
class KC_KeyCard_Red :KC_KeyCard_ColourBase {}