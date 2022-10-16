class CfgPatches
{
	class DNA_Keycards_Scripts
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.25;
		requiredAddons[] = 
		{
			"JM_CF_Scripts",
			"DNA_Keycards_Icons"
		};
	};
};
class CfgMods
{
	class DNA_Keycards_Scripts
	{
		dir = "DNA_Keycards_Scripts";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "DNA_Keycards";
		credits = "Arrakis and Dirty";
		author = "Arrakis and Dirty";
		authorID = "0";
		version = "1.0";
		configVersion = 2;
		extra = 0;
		type = "mod";
		dependencies[] =
		{
			"Game",
			"World",
			"Mission"
		};
		class defs
		{
			class imageSets
			{
				files[]= {"DNA_Keycards_Scripts/icons/dna_icons_slots.imageset"};
			};
			class gameScriptModule
			{
				value = "";
				files[] = {"DNA_Keycards_Scripts/Scripts/3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"DNA_Keycards_Scripts/Scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"DNA_Keycards_Scripts/Scripts/5_Mission"};
			};
		};
	};
};

class cfgSlots
{
	class Slot_Plank_DNA
	{
		name="Plank_DNA";
		displayName="Planks";
		selection = "Planks";
		ghostIcon="set:dayz_inventory image:planks";
		stackMax=13;
	};
	class Slot_MetalSheet_DNA
	{
		name="MetalSheet_DNA";
		displayName="Metal Sheets";
		selection = "Metal Sheets";
		ghostIcon="set:dayz_inventory image:plates";
		stackMax=5;
	};
	class Slot_Wire_DNA
	{
		name="Wire_DNA";
		displayName="Metal Wire";
		selection = "Wire";
		ghostIcon="set:dayz_inventory image:metalwire";
	};
	class Slot_KeyCard
	{
		name="KeyCard";
		displayName="KeyCard";
		selection = "KeyCard";
		ghostIcon="set:dna_icons_slots image:keycard";
	};
	class Slot_Unlock
	{
		name="Unlock";
		displayName="Unlock";
		selection = "Unlock";
		ghostIcon="set:dna_icons_slots image:keycard";
	};
	class Slot_CardChip
	{
		name="CardChip";
		displayName="Microchip";
		selection = "CardChip";
		ghostIcon="set:dna_icons_slots image:chip";
	};
	class Slot_Solder
	{
		name="Solder";
		displayName="Solder";
		selection = "Solder";
		ghostIcon="set:dna_icons_slots image:solder";
	};
	class Slot_Flux
	{
		name="Flux";
		displayName="Flux";
		selection = "Flux";
		ghostIcon="set:dna_icons_slots image:flux";
	};
	class Slot_Bolts
	{
		name="Bolts";
		displayName="Bolts";
		selection = "Bolts";
		ghostIcon="set:dna_icons_slots image:bolts";
		stackMax=16;
	};
	class Slot_SolderIron
	{
		name="SolderIron";
		displayName="Soldering Iron";
		selection = "SolderIron";
		ghostIcon="set:dna_icons_slots image:iron";
	};
	class Slot_CardReader
	{
		name="CardReader";
		displayName="Card Reader";
		selection = "Card Reader";
		ghostIcon="set:dna_icons_slots image:reader";
	};
	class Slot_HelpingHands
	{
		name="HelpingHands";
		displayName="Helping Hands";
		selection = "Helping Hands";
		ghostIcon="set:dna_icons_slots image:hands";
	};
	class Slot_Laptop
	{
		name="Laptop";
		displayName="Laptop";
		selection = "Laptop";
		ghostIcon="set:dna_icons_slots image:laptop";
	};
	class Slot_BenchBattery
	{
		name="BenchBattery";
		displayName="40v Battery";
		selection = "BenchBattery";
		ghostIcon="set:dna_icons_slots image:batteryhv";
	};
	class Slot_KeyCardError
	{
		name="ErrorCard";
		displayName="ErrorCard";
		selection = "ErrorCard";
		ghostIcon="";
		show="false";
	};
	class Slot_KeyCardBlank
	{
		name="BlankCard";
		displayName="BlankCard";
		selection = "BlankCard";
		ghostIcon="";
		show="false";
	};
};

class CfgNonAIVehicles
{
	class ProxyAttachment;
	class ProxyKeyCard: ProxyAttachment
	{
		scope = 2;
		inventorySlot[] = 
		{
			"KeyCard"
		};
		model = "\DNA_Keycards_Objects_Keycard\Keycards\KeyCard.p3d";
	};
    class ProxyDNABattery40v: ProxyAttachment
    {
        model="\DNA_Keycards_Objects_Crafting\Assets\DNABattery40v.p3d";
        inventorySlot[] = 
        {
            "BenchBattery"
        };
    };
	class ProxyKeyCardError: ProxyAttachment
	{
		inventorySlot[] = 
		{
			"ErrorCard"
		};
		model = "\DNA_Keycards_Objects_Keycard\Keycards\KeyCardError.p3d";
	};
	class ProxyKeyCardBlank: ProxyAttachment
	{
		inventorySlot[] = 
		{
			"BlankCard"
		};
		model = "\DNA_Keycards_Objects_Keycard\Keycards\KeyCardBlank.p3d";
	};
};

