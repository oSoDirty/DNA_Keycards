class DNA_Battery_40v: TruckBattery
{
	override void OnEnergyConsumed()
	{
		super.OnEnergyConsumed();
		DNA_Workbench workbench;
		if(GetCompEM().GetEnergy() < 100 && CastTo(workbench, GetHierarchyParent()))
			GetRPCManager().SendRPC("DNA_Keycards_Client", "SoundBatteryDied", new Param1<vector> (workbench.GetPosition()), true);
	}
	
	override bool CanPutAsAttachment(EntityAI parent)
	{
		if(!super.CanPutAsAttachment(parent)) return false;
		DNA_Workbench workbench;
		BatteryCharger charger;
		return CastTo(workbench, parent) || CastTo(charger, parent);
	}
}