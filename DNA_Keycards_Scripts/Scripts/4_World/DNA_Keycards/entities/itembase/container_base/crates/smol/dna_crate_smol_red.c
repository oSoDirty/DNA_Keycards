class DNA_Crate_Smol_Red: DNA_Crate_Smol_ColourBase
{
	void DNA_Crate_Smol_Red()
	{
		dna_Tier = "red";
		if(GetGame().IsDedicatedServer())
		{
			m_SpawnMainWeapons = DNA_CrateSmol_Data.GetSettingsRed().dna_SpawnMainWeapons;
			m_RandomizeWeapons = DNA_CrateSmol_Data.GetSettingsRed().dna_RandomizeWeapons;
			m_WeaponCount = DNA_CrateSmol_Data.GetSettingsRed().dna_WeaponCount;
			m_WeaponTypes = DNA_CrateSmol_Data.GetSettingsRed().weaponTypesRed;
			m_SpawnLootSet1 = DNA_CrateSmol_Data.GetSettingsRed().dna_SpawnLootSet1;
			m_RandomizeLootSet1 = DNA_CrateSmol_Data.GetSettingsRed().dna_RandomizeLootSet1;
			m_LootSet1Count = DNA_CrateSmol_Data.GetSettingsRed().dna_LootSet1Count;
			m_LootSet1 = DNA_CrateSmol_Data.GetSettingsRed().dna_LootSetR1;
			m_SpawnLootSet2 = DNA_CrateSmol_Data.GetSettingsRed().dna_SpawnLootSet2;
			m_RandomizeLootSet2 = DNA_CrateSmol_Data.GetSettingsRed().dna_RandomizeLootSet2;
			m_LootSet2Count = DNA_CrateSmol_Data.GetSettingsRed().dna_LootSet2Count;
			m_LootSet2 = DNA_CrateSmol_Data.GetSettingsRed().dna_LootSetR2;
			m_SpawnLootSet3 = DNA_CrateSmol_Data.GetSettingsRed().dna_SpawnLootSet3;
			m_RandomizeLootSet3 = DNA_CrateSmol_Data.GetSettingsRed().dna_RandomizeLootSet3;
			m_LootSet3Count = DNA_CrateSmol_Data.GetSettingsRed().dna_LootSet3Count;
			m_LootSet3 = DNA_CrateSmol_Data.GetSettingsRed().dna_LootSetR3;
			m_SpawnLootSet4 = DNA_CrateSmol_Data.GetSettingsRed().dna_SpawnLootSet4;
			m_RandomizeLootSet4 = DNA_CrateSmol_Data.GetSettingsRed().dna_RandomizeLootSet4;
			m_LootSet4Count = DNA_CrateSmol_Data.GetSettingsRed().dna_LootSet4Count;
			m_LootSet4 = DNA_CrateSmol_Data.GetSettingsRed().dna_LootSetR4;
		}
	}
}