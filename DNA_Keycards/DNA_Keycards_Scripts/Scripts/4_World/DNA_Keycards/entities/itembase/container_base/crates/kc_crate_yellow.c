class KC_Crate_Yellow: KC_Crate_ColourBase
{
	protected ref array<ref KCM_Weapons_Yellow> kcm_Loadouts;
	protected ref array<ref KCM_Clothing_Y> kcm_Outfits;
	protected ref array<ref Weapon_Variables_Yellow> kcm_WeaponVars;
	
	void KC_Crate_Yellow()
	{
		kcm_Loadouts = DNA_Keycards_Yellow.GetInstance().GetConfig().GetConfigData().GetWeaponsArray();
		kcm_Outfits = DNA_Keycards_Yellow.GetInstance().GetConfig().GetConfigData().GetClothingArray();
		kcm_WeaponVars = DNA_Keycards_Yellow.GetInstance().GetConfig().GetConfigData().GetWeaponVarsArray();
	}

	void GiveMainWeapon()
	{
		EntityAI weapon;
		string color, weaponType, optic, suppressor, buttStock, handGuard, underBarrel, magazine, ammo, opticBattery;
		color = "yellow"; 
		int i, min, max, choice;
		min = kcm_WeaponVars.Get(0).GetWeaponVar();
		max = kcm_WeaponVars.Get(1).GetWeaponVar();
		choice = Math.RandomIntInclusive(min, max);
		if(CanSpawnMainWeapon(color))
		{
			for(i = 0; i < choice; i++)
			{
				KCM_Weapons_Yellow mainLoadout = kcm_Loadouts.GetRandomElement();
				weaponType = mainLoadout.GetTheChosenOne();
				if(weaponType && weaponType != "")
				{
					weapon = EntityAI.Cast(GetInventory().CreateInInventory(weaponType));
					magazine = mainLoadout.GetMagazine();
					if(magazine && magazine != "")
					{
						GetInventory().CreateInInventory(magazine);
						if(CanSpawnMainMagsExtra(color))
						{
							min = kcm_WeaponVars.Get(2).GetWeaponVar();
							max = kcm_WeaponVars.Get(3).GetWeaponVar(); 
							choice = Math.RandomIntInclusive(min, max);
							SpawnLoop(magazine, choice);
						}
					}
					ammo = mainLoadout.GetAmmunition();
					if(ammo && ammo != "")
					{
						if(CanSpawnMainAmmoExtra(color))
						{
							min = kcm_WeaponVars.Get(4).GetWeaponVar();
							max = kcm_WeaponVars.Get(5).GetWeaponVar();
							choice = Math.RandomIntInclusive(min, max);
							SpawnLoop(ammo, choice);
						}
					}
					if(CanSpawnMainAttachments(color))
					{
						optic = mainLoadout.GetOpticType();
						if(optic && optic != "")
						{
							weapon.GetInventory().CreateAttachment(optic);
							opticBattery = mainLoadout.GetOpticBattery();
							{
								if(opticBattery && opticBattery != "")
									weapon.GetInventory().CreateInInventory(opticBattery);
							}
						}
						
						suppressor = mainLoadout.GetSuppressor();
						if(suppressor && suppressor != "")
							weapon.GetInventory().CreateAttachment(suppressor);
						
						buttStock = mainLoadout.GetButtStock();
						if(buttStock && buttStock != "")
							weapon.GetInventory().CreateAttachment(buttStock);
						
						handGuard = mainLoadout.GetHandGuard();
						if(handGuard && handGuard != "")
							weapon.GetInventory().CreateAttachment(handGuard);
						
						underBarrel = mainLoadout.GetUnderBarrel();
						if(underBarrel && underBarrel != "")
							weapon.GetInventory().CreateAttachment(underBarrel);
						if(underBarrel && underBarrel == "UniversalFlashlight")
							weapon.GetInventory().CreateInInventory("Battery9V");
					}
				}
			}
		}
	}
	
	void GiveOutfit()
	{
		string helm, shirt, vest, pants, shoes, back, gloves;
		if(CanSpawnClothes("yellow"))
		{
			KCM_Clothing_Y clothingSet = kcm_Outfits.GetRandomElement();
			helm = clothingSet.GetHelmet();
			if(helm && helm != "")
				GetInventory().CreateInInventory(helm);
			
			shirt = clothingSet.GetShirt();
			if(shirt && shirt != "")
				GetInventory().CreateInInventory(shirt);
			
			vest = clothingSet.GetVest();
			if(vest && vest != "")
				GetInventory().CreateInInventory(vest);
			
			pants = clothingSet.GetPants();
			if(pants && pants != "")
				GetInventory().CreateInInventory(pants);
			
			shoes = clothingSet.GetShoes();
			if(shoes && shoes != "")
				GetInventory().CreateInInventory(shoes);
			
			back = clothingSet.GetBackpack();
			if(back && back != "")
				GetInventory().CreateInInventory(back);
			
			gloves = clothingSet.GetGloves();
			if(gloves && gloves != "")
				GetInventory().CreateInInventory(gloves);
		}	
	}
	
	override void DoTheDamnThing(string color)
	{
		GiveMainWeapon();
		GiveOutfit();
		
		super.DoTheDamnThing(color);
	}
}