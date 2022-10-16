modded class Hologram
{
	override string ProjectionBasedOnParent()
	{
		ItemBase item_in_hands = ItemBase.Cast(m_Player.GetHumanInventory().GetEntityInHands());	
		
		if (item_in_hands.IsInherited(DNA_Workbench_Kit))
			return "DNA_Workbench_Hologram";

		return super.ProjectionBasedOnParent();
	}
}