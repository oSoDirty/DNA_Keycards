#define DNA_Keycards

class DNA_Config_Version
{
	protected string dna_WarningMessage;
	protected int dna_ConfigVersion;
	
	void DNA_Config_Version(string warning, int version)
	{
		dna_WarningMessage = warning;
		dna_ConfigVersion = version;
	}
	
	int GetConfigVersion()
	{
		return dna_ConfigVersion;
	}
}

class DNA_Config_Main_System
{	
	protected string dna_Option;
	protected int dna_Setting;
	
	void DNA_Config_Main_System(string option, int setting)
	{
		dna_Option = option;
		dna_Setting = setting;
	}
	
	int GetSystemSetting()
	{
		return dna_Setting;
	}
}

class DNA_Config_Container_System
{	
	protected string dna_Option;
	protected int dna_CrateSetting;
	protected int dna_StrongroomSetting;
	
	void DNA_Config_Container_System(string option, int c_setting, int sr_setting)
	{
		dna_Option = option;
		dna_CrateSetting = c_setting;
		dna_StrongroomSetting = sr_setting;
	}
	
	int GetCrateSetting()
	{
		return dna_CrateSetting;
	}
	
	int GetStrongroomSetting()
	{
		return dna_StrongroomSetting;
	}
}

class DNA_Config_Mob_System
{	
	protected string dna_DefaultMob;
	protected string dna_MobType;
	
	void DNA_Config_Mob_System(string defaultMob, string mobType)
	{
		dna_DefaultMob = defaultMob;
		dna_MobType = mobType;
	}
	
	string GetMobType()
	{
		return dna_MobType;
	}
	
	string GetDefaultMob()
	{
		return dna_DefaultMob;
	}
}

class DNA_Yellow_Crate_Locations
{
	protected string dna_Location;
	protected string dna_Rotation;
	
	void DNA_Yellow_Crate_Locations(string location, string rotation)
	{
		dna_Location = location;
		dna_Rotation = rotation;
	}
	
	string GetLocation()
	{
		return dna_Location;
	}
	
	string GetRotation()
	{
		return dna_Rotation;
	}
}

class DNA_Green_Crate_Locations
{
	protected string dna_Location;
	protected string dna_Rotation;
	
	void DNA_Green_Crate_Locations(string location, string rotation)
	{
		dna_Location = location;
		dna_Rotation = rotation;
	}
	
	string GetLocation()
	{
		return dna_Location;
	}
	
	string GetRotation()
	{
		return dna_Rotation;
	}
}

class DNA_Blue_Crate_Locations
{
	protected string dna_Location;
	protected string dna_Rotation;
	
	void DNA_Blue_Crate_Locations(string location, string rotation)
	{
		dna_Location = location;
		dna_Rotation = rotation;
	}
	
	string GetLocation()
	{
		return dna_Location;
	}
	
	string GetRotation()
	{
		return dna_Rotation;
	}
}

class DNA_Purple_Crate_Locations
{
	protected string dna_Location;
	protected string dna_Rotation;
	
	void DNA_Purple_Crate_Locations(string location, string rotation)
	{
		dna_Location = location;
		dna_Rotation = rotation;
	}
	
	string GetLocation()
	{
		return dna_Location;
	}
	
	string GetRotation()
	{
		return dna_Rotation;
	}
}

class DNA_Red_Crate_Locations
{
	protected string dna_Location;
	protected string dna_Rotation;
	
	void DNA_Red_Crate_Locations(string location, string rotation)
	{
		dna_Location = location;
		dna_Rotation = rotation;
	}
	
	string GetLocation()
	{
		return dna_Location;
	}
	
	string GetRotation()
	{
		return dna_Rotation;
	}
}

class DNA_Yellow_Strongroom_Locations
{
	protected string dna_Location;
	protected string dna_Rotation;
	
	void DNA_Yellow_Strongroom_Locations(string location, string rotation)
	{
		dna_Location = location;
		dna_Rotation = rotation;
	}
	
	string GetLocation()
	{
		return dna_Location;
	}
	
	string GetRotation()
	{
		return dna_Rotation;
	}
}

class DNA_Green_Strongroom_Locations
{
	protected string dna_Location;
	protected string dna_Rotation;
	
	void DNA_Green_Strongroom_Locations(string location, string rotation)
	{
		dna_Location = location;
		dna_Rotation = rotation;
	}
	
	string GetLocation()
	{
		return dna_Location;
	}
	
	string GetRotation()
	{
		return dna_Rotation;
	}
}

class DNA_Blue_Strongroom_Locations
{
	protected string dna_Location;
	protected string dna_Rotation;
	
	void DNA_Blue_Strongroom_Locations(string location, string rotation)
	{
		dna_Location = location;
		dna_Rotation = rotation;
	}
	
	string GetLocation()
	{
		return dna_Location;
	}
	
	string GetRotation()
	{
		return dna_Rotation;
	}
}

class DNA_Purple_Strongroom_Locations
{
	protected string dna_Location;
	protected string dna_Rotation;
	
	void DNA_Purple_Strongroom_Locations(string location, string rotation)
	{
		dna_Location = location;
		dna_Rotation = rotation;
	}
	
	string GetLocation()
	{
		return dna_Location;
	}
	
	string GetRotation()
	{
		return dna_Rotation;
	}
}

class DNA_Red_Strongroom_Locations
{
	protected string dna_Location;
	protected string dna_Rotation;
	
	void DNA_Red_Strongroom_Locations(string location, string rotation)
	{
		dna_Location = location;
		dna_Rotation = rotation;
	}
	
	string GetLocation()
	{
		return dna_Location;
	}
	
	string GetRotation()
	{
		return dna_Rotation;
	}
}

class DNA_Config_Loot
{
	protected string dna_Tier;
	protected string dna_Category;
	protected string dna_Type;
	
	void DNA_Config_Loot(string tier, string category, string type)
	{
		dna_Tier = tier;
		dna_Category = category;
		dna_Type = type;
	}
	
	string GetLootTier()
	{
		return dna_Tier;
	}
	
	string GetLootCategory()
	{
		return dna_Category;
	}
	
	string GetLootType()
	{
		return dna_Type;
	}
}

class DNA_Config_Clothing
{
	protected string dna_Tier;
	protected string dna_Helm;
	protected string dna_Shirt;
	protected string dna_Vest;
	protected string dna_Pants;
	protected string dna_Shoes;
	protected string dna_Backpack;
	protected string dna_Gloves;
	protected string dna_Belt;
	protected string dna_Facewear;
	protected string dna_Eyewear;
	protected string dna_Armband;
	protected string dna_NVG;
	
	void DNA_Config_Clothing(string tier, string helm, string shirt, string vest, string pants, string shoes, string backpack, string gloves, string belt, string facewear, string eyewear, string armband, string nvg)
	{
		dna_Tier = tier;
		dna_Helm = helm;
		dna_Shirt = shirt;
		dna_Vest = vest;
		dna_Pants = pants;
		dna_Shoes = shoes;
		dna_Backpack = backpack;
		dna_Gloves = gloves;
		dna_Belt = belt;
		dna_Facewear = facewear;
		dna_Eyewear = eyewear;
		dna_Armband = armband;
		dna_NVG = nvg;
	}
	
	string GetClothingTier()
	{
		return dna_Tier;
	}
	
	string GetHelmet()
	{
		return dna_Helm;
	}
	
	string GetShirt()
	{
		return dna_Shirt;
	}
	
	string GetVest()
	{
		return dna_Vest;
	}
	
	string GetPants()
	{
		return dna_Pants;
	}
	
	string GetShoes()
	{
		return dna_Shoes;
	}
	
	string GetBackpack()
	{
		return dna_Backpack;
	}
	
	string GetGloves()
	{
		return dna_Gloves;
	}
	
	string GetBelt()
	{
		return dna_Belt;
	}
	
	string GetFacewear()
	{
		return dna_Facewear;
	}
	
	string GetEyewear()
	{
		return dna_Eyewear;
	}
	
	string GetArmband()
	{
		return dna_Armband;
	}
	
	string GetNVG()
	{
		return dna_NVG;
	}
}


class DNA_Config_Weapons
{
	protected string dna_Tier;
	protected string dna_WeaponCategory;
	protected string dna_TheChosenOne;
	protected string dna_Magazine;
	protected string dna_Ammunition;
	protected string dna_OpticType;
	protected string dna_Suppressor;
	protected string dna_UnderBarrel;
	protected string dna_ButtStock;
	protected string dna_HandGuard;
	protected string dna_Wrap;
	
	void DNA_Config_Weapons(string tier, string weaponCategory, string theChosenOne, string magazine, string ammunition, string opticType, string suppressor, string underBarrel, string buttStock, string handGuard, string wrap)
	{
		dna_Tier = tier;
		dna_WeaponCategory = weaponCategory;
		dna_TheChosenOne = theChosenOne;
		dna_Magazine = magazine;
		dna_Ammunition = ammunition;
		dna_OpticType = opticType;
		dna_Suppressor = suppressor;
		dna_UnderBarrel = underBarrel;
		dna_ButtStock = buttStock;
		dna_HandGuard = handGuard;
		dna_Wrap = wrap;
	}
	
	string GetWeaponTier()
	{
		return dna_Tier;
	}
	
	string GetWeaponCategory()
	{
		return dna_WeaponCategory;
	}
	
	string GetTheChosenOne()
	{
		return dna_TheChosenOne;
	}	
		
	string GetOpticType()
	{
		return dna_OpticType;
	}
	
	string GetSuppressor()
	{
		return dna_Suppressor;
	}
	
	string GetButtStock()
	{
		return dna_ButtStock;
	}
	
	string GetHandGuard()
	{
		return dna_HandGuard;
	}
	
	string GetUnderBarrel()
	{
		return dna_UnderBarrel;
	}
	
	string GetMagazine()
	{
		return dna_Magazine;
	}
	
	string GetAmmunition()
	{
		return dna_Ammunition;
	}
	
	string GetWrap()
	{
		return dna_Wrap;
	}
}

class DNA_ConfigIndex
{
	protected static ref array<ref DNA_Config_Container_System> dna_ContainerSystemConfig;
	
	static void Init()
	{
		dna_ContainerSystemConfig = DNA_Keycards_Container_System.GetInstance().GetConfig().GetConfigData().GetSystemArray();
	}

	static bool CanSpawn(int index, string containerType)
	{
		if(dna_ContainerSystemConfig)
		{
			switch(containerType)
			{
				case "crate":
					return dna_ContainerSystemConfig.Get(index).GetCrateSetting() >= 1;
					break;
					
				case "strongroom":
					return dna_ContainerSystemConfig.Get(index).GetStrongroomSetting() >= 1;
					break;
			}
		}
		return false;
	}
	
	static int GetIndex(string color, string category, string subCategory)
	{
		if(color && category)
		{
			switch(category)
			{
				case "mainweapon":
				
					switch(color)				
					{
						case "yellow":
							switch(subCategory)
							{
								case "min":
									return 0;
								case "max":
									return 1;
							}
							break;
							
						case "green":
							switch(subCategory)
							{
								case "min":
									return 45;
								case "max":
									return 46;
							}
							break;
							
						case "blue":
							switch(subCategory)
							{
								case "min":
									return 90;
								case "max":
									return 91;
							}
							break;
							
						case "purple":
							switch(subCategory)
							{
								case "min":
									return 135;
								case "max":
									return 136;
							}
							break;
							
						case "red":
							switch(subCategory)
							{
								case "min":
									return 180;
								case "max":
									return 181;
							}
							break;
					}
					break;
					
				case "mainweaponmag":
				
					switch(color)
					{
						case "yellow":
							switch(subCategory)
							{
								case "min":
									return 5;
								case "max":
									return 6;
							}
							break;
							
						case "green":
							switch(subCategory)
							{
								case "min":
									return 50;
								case "max":
									return 51;
							}
							break;
							
						case "blue":
							switch(subCategory)
							{
								case "min":
									return 95;
								case "max":
									return 96;
							}
							break;
							
						case "purple":
							switch(subCategory)
							{
								case "min":
									return 140;
								case "max":
									return 141;
							}
							break;
							
						case "red":
							switch(subCategory)
							{
								case "min":
									return 185;
								case "max":
									return 186;
							}
							break;
					}
					break;
					
				case "mainweaponattachment":
				
					switch(color)
					{
						case "yellow":
							return 2;
							
						case "green":
							return 47;
							
						case "blue":
							return 92;
							
						case "purple":
							return 137;
							
						case "red":
							return 182;
					}
					break;
					
				case "mainweaponammo":
				
					switch(color)
					{
						case "yellow":
							switch(subCategory)
							{
								case "min":
									return 3;
								case "max":
									return 4;
							}
							break;
							
						case "green":
							switch(subCategory)
							{
								case "min":
									return 48;
								case "max":
									return 49;
							}
							break;
							
						case "blue":
							switch(subCategory)
							{
								case "min":
									return 93;
								case "max":
									return 94;
							}
							break;
							
						case "purple":
							switch(subCategory)
							{
								case "min":
									return 138;
								case "max":
									return 139;
							}
							break;
							
						case "red":
							switch(subCategory)
							{
								case "min":
									return 183;
								case "max":
									return 184;
							}
							break;
					}
					break;
				
				case "sidearm":
				
					switch(color)
					{
						case "yellow":
							switch(subCategory)
							{
								case "min":
									return 7;
								case "max":
									return 8;
							}
							break;
							
						case "green":
							switch(subCategory)
							{
								case "min":
									return 52;
								case "max":
									return 53;
							}
							break;
							
						case "blue":
							switch(subCategory)
							{
								case "min":
									return 97;
								case "max":
									return 98;
							}
							break;
							
						case "purple":
							switch(subCategory)
							{
								case "min":
									return 142;
								case "max":
									return 143;
							}
							break;
							
						case "red":
							switch(subCategory)
							{
								case "min":
									return 187;
								case "max":
									return 188;
							}
							break;
					}
					break;
				
				case "sidearmmag":
				
					switch(color)
					{
						case "yellow":
							switch(subCategory)
							{
								case "min":
									return 12;
								case "max":
									return 13;
							}
							break;
							
						case "green":
							switch(subCategory)
							{
								case "min":
									return 57;
								case "max":
									return 58;
							}
							break;
							
						case "blue":
							switch(subCategory)
							{
								case "min":
									return 102;
								case "max":
									return 103;
							}
							break;
							
						case "purple":
							switch(subCategory)
							{
								case "min":
									return 147;
								case "max":
									return 148;
							}
							break;
							
						case "red":
							switch(subCategory)
							{
								case "min":
									return 192;
								case "max":
									return 193;
							}
							break;
					}
					break;
					
				case "sidearmammo":
					switch(color)
					{
						case "yellow":
							switch(subCategory)
							{
								case "min":
									return 10;
								case "max":
									return 11;
							}
							break;
							
						case "green":
							switch(subCategory)
							{
								case "min":
									return 55;
								case "max":
									return 56;
							}
							break;
							
						case "blue":
							switch(subCategory)
							{
								case "min":
									return 100;
								case "max":
									return 101;
							}
							break;
							
						case "purple":
							switch(subCategory)
							{
								case "min":
									return 145;
								case "max":
									return 146;
							}
							break;
							
						case "red":
							switch(subCategory)
							{
								case "min":
									return 190;
								case "max":
									return 191;
							}
							break;
					}
					break;
				
				case "sidearmattachment":
					switch(color)
					{
						case "yellow":
							return 9;
							
						case "green":
							return 54;
							
						case "blue":
							return 99;
							
						case "purple":
							return 144;
							
						case "red":
							return 189;
					}
					break;
					
				case "clothing":
					switch(color)
					{
						case "yellow":
							switch(subCategory)
							{
								case "min":
									return 43;
								case "max":
									return 44;
							}
							break;
							
						case "green":
							switch(subCategory)
							{
								case "min":
									return 88;
								case "max":
									return 89;
							}
							break;
							
						case "blue":
							switch(subCategory)
							{
								case "min":
									return 133;
								case "max":
									return 134;
							}
							break;
							
						case "purple":
							switch(subCategory)
							{
								case "min":
									return 178;
								case "max":
									return 179;
							}
							break;
							
						case "red":
							switch(subCategory)
							{
								case "min":
									return 223;
								case "max":
									return 224;
							}
							break;
					}
					break;
				
				case "food":
					switch(color)
					{
						case "yellow":
							switch(subCategory)
							{
								case "minT":
									return 14;
									
								case "maxT":
									return 15;
									
								case "minE":
									return 16;
									
								case "maxE":
									return 17;
							}
							break;
							
						case "green":
							switch(subCategory)
							{
								case "minT":
									return 59;
									
								case "maxT":
									return 60;
									
								case "minE":
									return 61;
									
								case "maxE":
									return 62;
							}
							break;
							
						case "blue":
							switch(subCategory)
							{
								case "minT":
									return 104;
									
								case "maxT":
									return 105;
									
								case "minE":
									return 106;
									
								case "maxE":
									return 107;
							}
							break;
							
						case "purple":
							switch(subCategory)
							{
								case "minT":
									return 149;
									
								case "maxT":
									return 150;
									
								case "minE":
									return 151;
									
								case "maxE":
									return 152;
							}
							break;
							
						case "red":
							switch(subCategory)
							{
								case "minT":
									return 194;
									
								case "maxT":
									return 195;
									
								case "minE":
									return 196;
									
								case "maxE":
									return 197;
							}
							break;
					}
					break;
				
				case "drink":
					switch(color)
					{
						case "yellow":
							switch(subCategory)
							{
								case "minT":
									return 18;
									
								case "maxT":
									return 19;
									
								case "minE":
									return 20;
									
								case "maxE":
									return 21;
							}
							break;
							
						case "green":
							switch(subCategory)
							{
								case "minT":
									return 63;
									
								case "maxT":
									return 64;
									
								case "minE":
									return 65;
									
								case "maxE":
									return 66;
							}
							break;
							
						case "blue":
							switch(subCategory)
							{
								case "minT":
									return 108;
									
								case "maxT":
									return 109;
									
								case "minE":
									return 110;
									
								case "maxE":
									return 111;
							}
							break;
							
						case "purple":
							switch(subCategory)
							{
								case "minT":
									return 153;
									
								case "maxT":
									return 154;
									
								case "minE":
									return 155;
									
								case "maxE":
									return 156;
							}
							break;
							
						case "red":
							switch(subCategory)
							{
								case "minT":
									return 198;
									
								case "maxT":
									return 199;
									
								case "minE":
									return 200;
									
								case "maxE":
									return 201;
							}
							break;
					}
					break;
				
				case "tools":
					switch(color)
					{
						case "yellow":
							switch(subCategory)
							{
								case "minT":
									return 22;
									
								case "maxT":
									return 23;
									
								case "minE":
									return 24;
									
								case "maxE":
									return 25;
							}
							break;
							
						case "green":
							switch(subCategory)
							{
								case "minT":
									return 67;
									
								case "maxT":
									return 68;
									
								case "minE":
									return 69;
									
								case "maxE":
									return 70;
							}
							break;
							
						case "blue":
							switch(subCategory)
							{
								case "minT":
									return 112;
									
								case "maxT":
									return 113;
									
								case "minE":
									return 114;
									
								case "maxE":
									return 115;
							}
							break;
							
						case "purple":
							switch(subCategory)
							{
								case "minT":
									return 157;
									
								case "maxT":
									return 158;
									
								case "minE":
									return 159;
									
								case "maxE":
									return 160;
							}
							break;
							
						case "red":
							switch(subCategory)
							{
								case "minT":
									return 202;
									
								case "maxT":
									return 203;
									
								case "minE":
									return 204;
									
								case "maxE":
									return 205;
							}
							break;
					}
					break;
				
				case "build":
					switch(color)
					{
						case "yellow":
							switch(subCategory)
							{
								case "minT":
									return 30;
									
								case "maxT":
									return 31;
									
								case "minE":
									return 32;
									
								case "maxE":
									return 33;
							}
							break;
							
						case "green":
							switch(subCategory)
							{
								case "minT":
									return 75;
									
								case "maxT":
									return 76;
									
								case "minE":
									return 77;
									
								case "maxE":
									return 78;
							}
							break;
							
						case "blue":
							switch(subCategory)
							{
								case "minT":
									return 120;
									
								case "maxT":
									return 121;
									
								case "minE":
									return 122;
									
								case "maxE":
									return 123;
							}
							break;
							
						case "purple":
							switch(subCategory)
							{
								case "minT":
									return 165;
									
								case "maxT":
									return 166;
									
								case "minE":
									return 167;
									
								case "maxE":
									return 168;
							}
							break;
							
						case "red":
							switch(subCategory)
							{
								case "minT":
									return 210;
									
								case "maxT":
									return 211;
									
								case "minE":
									return 212;
									
								case "maxE":
									return 213;
							}
							break;
					}
					break;
				
				case "value":
					switch(color)
					{
						case "yellow":
							switch(subCategory)
							{
								case "minT":
									return 35;
									
								case "maxT":
									return 36;
									
								case "minE":
									return 37;
									
								case "maxE":
									return 38;
							}
							break;
							
						case "green":
							switch(subCategory)
							{
								case "minT":
									return 80;
									
								case "maxT":
									return 81;
									
								case "minE":
									return 82;
									
								case "maxE":
									return 83;
							}
							break;
							
						case "blue":
							switch(subCategory)
							{
								case "minT":
									return 125;
									
								case "maxT":
									return 126;
									
								case "minE":
									return 127;
									
								case "maxE":
									return 128;
							}
							break;
							
						case "purple":
							switch(subCategory)
							{
								case "minT":
									return 170;
									
								case "maxT":
									return 171;
									
								case "minE":
									return 172;
									
								case "maxE":
									return 173;
							}
							break;
							
						case "red":
							switch(subCategory)
							{
								case "minT":
									return 215;
									
								case "maxT":
									return 216;
									
								case "minE":
									return 217;
									
								case "maxE":
									return 218;
							}
							break;
					}
					break;
				
				case "meds":
					switch(color)
					{
						case "yellow":
							switch(subCategory)
							{
								case "minT":
									return 26;
									
								case "maxT":
									return 27;
									
								case "minE":
									return 28;
									
								case "maxE":
									return 29;
							}
							break;
							
						case "green":
							switch(subCategory)
							{
								case "minT":
									return 71;
									
								case "maxT":
									return 72;
									
								case "minE":
									return 73;
									
								case "maxE":
									return 74;
							}
							break;
							
						case "blue":
							switch(subCategory)
							{
								case "minT":
									return 116;
									
								case "maxT":
									return 117;
									
								case "minE":
									return 118;
									
								case "maxE":
									return 119;
							}
							break;
							
						case "purple":
							switch(subCategory)
							{
								case "minT":
									return 161;
									
								case "maxT":
									return 162;
									
								case "minE":
									return 163;
									
								case "maxE":
									return 164;
							}
							break;
							
						case "red":
							switch(subCategory)
							{
								case "minT":
									return 206;
									
								case "maxT":
									return 207;
									
								case "minE":
									return 208;
									
								case "maxE":
									return 209;
							}
							break;
					}
					break;
				
				case "misc":
					switch(color)
					{
						case "yellow":
							switch(subCategory)
							{
								case "minT":
									return 39;
									
								case "maxT":
									return 40;
									
								case "minE":
									return 41;
									
								case "maxE":
									return 42;
							}
							break;
							
						case "green":
							switch(subCategory)
							{
								case "minT":
									return 84;
									
								case "maxT":
									return 85;
									
								case "minE":
									return 86;
									
								case "maxE":
									return 87;
							}
							break;
							
						case "blue":
							switch(subCategory)
							{
								case "minT":
									return 129;
									
								case "maxT":
									return 130;
									
								case "minE":
									return 131;
									
								case "maxE":
									return 132;
							}
							break;
							
						case "purple":
							switch(subCategory)
							{
								case "minT":
									return 174;
									
								case "maxT":
									return 175;
									
								case "minE":
									return 176;
									
								case "maxE":
									return 177;
							}
							break;
							
						case "red":
							switch(subCategory)
							{
								case "minT":
									return 219;
									
								case "maxT":
									return 220;
									
								case "minE":
									return 221;
									
								case "maxE":
									return 222;
							}
							break;
					}
					break;
			}
		}
		Print("DNA KEYCARDS: CONFIG ERROR - NO INDEX FOUND!!!!");
		return 226; // last index in array
	}
}

class DNA_Crafting_Defines
{
	protected string dna_RecipeName;
	protected string dna_Tool_1;
	protected string dna_Tool_2;
	protected string dna_Tool_3;
	protected string dna_Ingredient_1;
	protected string dna_Ingredient_2;
	protected string dna_Ingredient_3;
	protected string dna_Ingredient_4;
	protected string dna_Result;
	
	void DNA_Crafting_Defines(string recipeName, string tool_1, string tool_2, string tool_3, string ingredient_1, string ingredient_2, string ingredient_3, string ingredient_4, string result)
	{
		dna_RecipeName = recipeName;
		dna_Tool_1 = tool_1;
		dna_Tool_2 = tool_2;
		dna_Tool_3 = tool_3;
		dna_Ingredient_1 = ingredient_1;
		dna_Ingredient_2 = ingredient_2;
		dna_Ingredient_3 = ingredient_3;
		dna_Ingredient_4 = ingredient_4;
		dna_Result = result;
	}
	
	string GetRecipeName()
	{
		return dna_RecipeName;
	}
	
	string GetToolOne()
	{
		return dna_Tool_1;
	}
	
	string GetToolTwo()
	{
		return dna_Tool_2;
	}
	
	string GetToolThree()
	{
		return dna_Tool_3;
	}
	
	string GetIngredientOne()
	{
		return dna_Ingredient_1;
	}
	
	string GetIngredientTwo()
	{
		return dna_Ingredient_2;
	}
	
	string GetIngredientThree()
	{
		return dna_Ingredient_3;
	}
	
	string GetIngredientFour()
	{
		return dna_Ingredient_4;
	}
	
	string GetResult()
	{
		return dna_Result;
	}
}