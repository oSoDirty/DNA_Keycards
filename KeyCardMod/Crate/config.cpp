class CfgPatches
{
	class KeyCardMod
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
		author[] = {"Arrakis"};
	};
};
class CfgVehicles
{
	class Container_Base;
	class KC_Crate_ColourBase: Container_Base
	{
		scope = 1;
		displayName = "Red Keycard Crate";
		model = "\KeyCardMod\Crate\KCCrate.p3d";
        storageCategory=10;
        hiddenSelections[]=
        {
            "Camo"
        };
		hiddenSelectionsTextures[]=
		{
			"KeyCardMod\Crate\Data\KCCrateGlow_Red.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"KeyCardMod\Crate\Data\Glowred.rvmat"
		};
		heavyItem=1;
		weight=20000;
		itemSize[]={12,12};
		itemBehaviour=0;
		absorbency=0.1;
		physLayer="item_large";
        class Cargo
        {
            itemsCargoSize[] = {10,100};
            allowOwnedCargoManipulation = 1;
            openable = "true";
        };
		class AnimationSources
		{
			class Door1
			{
				source="user";
				initPhase=0;
				animPeriod=4;
			};
		};
		class Doors
		{
			class Door1
			{
				displayName = "Door1";
				component = "Door1";
				soundPos = "Door1_Button";
				animPeriod = 4;
				initPhase = 0.0;
				initOpened = 0.0;
				soundOpen = "DoorCarSmallOpen";
				soundClose = "DoorCarSmallClose";
				soundLocked = "DoorCarSmallRattle";
				soundOpenABit = "DoorCarSmallOpenABit";
			};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 750000;
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 0;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
				class Melee
				{
					class Health
					{
						damage = 0;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
			};
			class DamageZones
			{
				class Door1
				{
					class Health
					{
						hitpoints = 750000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"Door1"};
					fatalInjuryCoef = -1;
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 2;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
						class Melee
						{
							class Health
							{
								damage = 2.5;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
					};
				};
			};
		};
	};
	class KC_Crate_Red: KC_Crate_ColourBase
	{
		scope = 1;
		displayName = "Red Keycard Crate";
		model = "\KeyCardMod\Crate\KCCrate.p3d";
		hiddenSelectionsTextures[]=
		{
			"KeyCardMod\Crate\Data\KCCrateGlow_Red.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"KeyCardMod\Crate\Data\Glowred.rvmat"
		};
	};
	class KC_Crate_Green: KC_Crate_ColourBase
	{
		scope = 1;
		displayName = "Green Keycard Crate";
		model = "\KeyCardMod\Crate\KCCrate.p3d";
		hiddenSelectionsTextures[]=
		{
			"KeyCardMod\Crate\Data\KCCrateGlow_G.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"KeyCardMod\Crate\Data\GlowGreen.rvmat"
		};
	};
	class KC_Crate_Blue: KC_Crate_ColourBase
	{
		scope = 1;
		displayName = "Blue Keycard Crate";
		model = "\KeyCardMod\Crate\KCCrate.p3d";
		hiddenSelectionsTextures[]=
		{
			"KeyCardMod\Crate\Data\KCCrateGlow_B.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"KeyCardMod\Crate\Data\GlowBlue.rvmat"
		};
	};
	class KC_Crate_Purple: KC_Crate_ColourBase
	{
		scope = 1;
		displayName = "Purple Keycard Crate";
		model = "\KeyCardMod\Crate\KCCrate.p3d";
		hiddenSelectionsTextures[]=
		{
			"KeyCardMod\Crate\Data\KCCrateGlow_P.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"KeyCardMod\Crate\Data\GlowPurple.rvmat"
		};
	};
	class KC_Crate_Yellow: KC_Crate_ColourBase
	{
		scope = 1;
		displayName = "Yellow Keycard Crate";
		model = "\KeyCardMod\Crate\KCCrate.p3d";
		hiddenSelectionsTextures[]=
		{
			"KeyCardMod\Crate\Data\KCCrateGlow_Y.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"KeyCardMod\Crate\Data\GlowYellow.rvmat"
		};
	};
};
