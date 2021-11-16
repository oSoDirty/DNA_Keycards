class CfgPatches
{
	class DNA_Keycards
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
		author[] = {"Arrakis"};  /* AND DIRTY! -.- */
	};
};

class cfgSlots
{
	class Slot_KeyCard
	{
		name="KeyCard";
		displayName="KeyCard";
		ghostIcon="crate";
	};
};

class CfgVehicles
{
	class Container_Base;
	class DBZ_MissionKeyBase;
	
	class KC_KeyCard_ColourBase:DBZ_MissionKeyBase
	{
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=10000;
		quantityShow=0;
	};
	
	class KC_KeyCard_Yellow: KC_KeyCard_ColourBase
	{
		hiddenSelectionsTextures[] = {"DBZMOD\Data\tools\key\KeyRed_co.paa"};
		displayName="Yellow KeyCard";
		descriptionShort="Test KeyCard";
		inventorySlot[]={"KeyCard"};
	};
	
	class KC_KeyCard_Green: KC_KeyCard_ColourBase
	{
		hiddenSelectionsTextures[] = {"DBZMOD\Data\tools\key\KeyRed_co.paa"};
		displayName="Green KeyCard";
		descriptionShort="Test KeyCard";
		inventorySlot[]={"KeyCard"};
	};
	
	class KC_KeyCard_Blue: KC_KeyCard_ColourBase
	{
		hiddenSelectionsTextures[] = {"DBZMOD\Data\tools\key\KeyRed_co.paa"};
		displayName="Blue KeyCard";
		descriptionShort="Test KeyCard";
		inventorySlot[]={"KeyCard"};
	};
	
	class KC_KeyCard_Purple: KC_KeyCard_ColourBase
	{
		hiddenSelectionsTextures[] = {"DBZMOD\Data\tools\key\KeyRed_co.paa"};
		displayName="Purple KeyCard";
		descriptionShort="Test KeyCard";
		inventorySlot[]={"KeyCard"};
	};
	
	class KC_KeyCard_Red: KC_KeyCard_ColourBase
	{
		hiddenSelectionsTextures[] = {"DBZMOD\Data\tools\key\KeyRed_co.paa"};
		displayName="Red KeyCard";
		descriptionShort="Test KeyCard";
		inventorySlot[]={"KeyCard"};
	};
	
	class KC_KeyCard_Error: KC_KeyCard_ColourBase
	{
		hiddenSelectionsTextures[] = {"DBZMOD\Data\tools\key\KeyRed_co.paa"};
		displayName="Malfunctioning KeyCard";
		descriptionShort="Test KeyCard";
		inventorySlot[]={"KeyCard"};
	};
		
	class KC_Crate_ColourBase: Container_Base
	{
		scope = 1;
		displayName = "Red Keycard Crate";
		model = "\DNA_Keycards\Crate\KCCrate.p3d";
        storageCategory=10;
        hiddenSelections[]=
        {
            "Camo"
        };
		hiddenSelectionsTextures[]=
		{
			"DNA_Keycards\Crate\Data\KCCrateGlow_Red.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"DNA_Keycards\Crate\Data\Glowred.rvmat"
		};
		heavyItem=1;
		weight=20000;
		itemSize[]={12,12};
		itemBehaviour=0;
		absorbency=0.1;
		physLayer="item_large";
		attachments[]={"KeyCard"};
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
		model = "\DNA_Keycards\Crate\KCCrate.p3d";
		hiddenSelectionsTextures[]=
		{
			"DNA_Keycards\Crate\Data\KCCrateGlow_Red.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"DNA_Keycards\Crate\Data\Glowred.rvmat"
		};
	};
	class KC_Crate_Green: KC_Crate_ColourBase
	{
		scope = 1;
		displayName = "Green Keycard Crate";
		model = "\DNA_Keycards\Crate\KCCrate.p3d";
		hiddenSelectionsTextures[]=
		{
			"DNA_Keycards\Crate\Data\KCCrateGlow_G.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"DNA_Keycards\Crate\Data\GlowGreen.rvmat"
		};
	};
	class KC_Crate_Blue: KC_Crate_ColourBase
	{
		scope = 1;
		displayName = "Blue Keycard Crate";
		model = "\DNA_Keycards\Crate\KCCrate.p3d";
		hiddenSelectionsTextures[]=
		{
			"DNA_Keycards\Crate\Data\KCCrateGlow_B.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"DNA_Keycards\Crate\Data\GlowBlue.rvmat"
		};
	};
	class KC_Crate_Purple: KC_Crate_ColourBase
	{
		scope = 1;
		displayName = "Purple Keycard Crate";
		model = "\DNA_Keycards\Crate\KCCrate.p3d";
		hiddenSelectionsTextures[]=
		{
			"DNA_Keycards\Crate\Data\KCCrateGlow_P.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"DNA_Keycards\Crate\Data\GlowPurple.rvmat"
		};
	};
	class KC_Crate_Yellow: KC_Crate_ColourBase
	{
		scope = 1;
		displayName = "Yellow Keycard Crate";
		model = "\DNA_Keycards\Crate\KCCrate.p3d";
		hiddenSelectionsTextures[]=
		{
			"DNA_Keycards\Crate\Data\KCCrateGlow_Y.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"DNA_Keycards\Crate\Data\GlowYellow.rvmat"
		};
	};
};
