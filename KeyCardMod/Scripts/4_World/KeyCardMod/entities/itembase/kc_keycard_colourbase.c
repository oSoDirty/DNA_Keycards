class KC_KeyCard_ColourBase: ItemBase
{
	protected int kcm_RemainingUses;
	
	protected ref array<ref KCM_Config_System> kcm_SystemConfig;
	
	void KC_KeyCard_ColourBase()
	{
		RegisterNetSyncVariableInt("kcm_RemainingUses", 1, int.MAX)
		kcm_SystemConfig = KeyCardMod_System.GetInstance().GetConfig().GetConfigData().GetSystemArray();
		SetInitialUsageAllotment();
	}
	
	int GetRemainingUses()
	{
		return kcm_RemainingUses;
	}
	
	void SetInitialUsageAllotment()
	{
		if(kcm_SystemConfig)
		{
			int remainingUses = GetRemainingUses();
			if(!remainingUses)
			{
				switch(GetType())
				{
					case "Kc_KeyCard_Yellow":
						kcm_RemainingUses = kcm_SystemConfig.Get(81).GetSystemSetting();
						break;
					case "Kc_KeyCard_Green":
						kcm_RemainingUses = kcm_SystemConfig.Get(82).GetSystemSetting();
						break;
					case "Kc_KeyCard_Blue":
						kcm_RemainingUses = kcm_SystemConfig.Get(83).GetSystemSetting();
						break;
					case "Kc_KeyCard_Purple":
						kcm_RemainingUses = kcm_SystemConfig.Get(84).GetSystemSetting();
						break;
					case "Kc_KeyCard_Red":
						kcm_RemainingUses = kcm_SystemConfig.Get(85).GetSystemSetting();
						break;
				}
				SetSynchDirty();
			}
		}
	}
	
	void SetRemainingUses(int remainingUses)
	{
		kcm_RemainingUses = remainingUses;
		SetSynchDirty();
	}
	
	bool IsMatchingTier(string typeName)
	{
		return GetType() == "KC_KeyCard" + typeName.SubstringInverted(typeName, 0, 8);
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