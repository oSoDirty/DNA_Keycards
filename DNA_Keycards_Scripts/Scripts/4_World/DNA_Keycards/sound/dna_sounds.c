class DNA_Sounds
{	
	static void SoundKCCrateSmolOpenPlay(vector pos)
	{
		EffectSound sound =	SEffectManager.PlaySound( "DNA_KeycardOpenSmol_SoundSet", pos );
		sound.SetSoundAutodestroy( true );
	}
	
	static void SoundKCCrateOpenPlay(vector pos)
	{
		EffectSound sound =	SEffectManager.PlaySound( "DNA_KeycardOpen_SoundSet", pos );
		sound.SetSoundAutodestroy( true );
	}
	
	static void SoundKCCrateOpenNoClickPlay(vector pos)
	{
		EffectSound sound =	SEffectManager.PlaySound( "DNA_KeycardOpenNoClick_SoundSet", pos );
		sound.SetSoundAutodestroy( true );
	}
	
	static void SoundKCCardScanPlay(vector pos)
	{
		EffectSound sound =	SEffectManager.PlaySound( "DNA_KeycardScan_SoundSet", pos );
		sound.SetSoundAutodestroy( true );
	}
	
	static void SoundKCCardRemovePlay(vector pos)
	{
		EffectSound sound =	SEffectManager.PlaySound( "DNA_KeycardRemove_SoundSet", pos );
		sound.SetSoundAutodestroy( true );
	}
	
	static void SoundKCAlarmBreachPlay(vector pos)
	{
		EffectSound sound =	SEffectManager.PlaySound( "DNA_BreachAlarm_SoundSet", pos );
		sound.SetSoundAutodestroy( true );
	}
}