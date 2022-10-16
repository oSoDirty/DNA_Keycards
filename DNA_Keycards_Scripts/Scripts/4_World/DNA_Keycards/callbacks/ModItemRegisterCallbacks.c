modded class ModItemRegisterCallbacks
{

	override void RegisterOneHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
	{	
		super.RegisterOneHanded( pType,  pBehavior);
				
		pType.AddItemInHandsProfileIK("DNA_KeyCard_Base", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior , "dz/anims/anm/player/ik/gear/bone_hook.anm");
		pType.AddItemInHandsProfileIK("DNA_KeyCard_Program_Base", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior , "dz/anims/anm/player/ik/gear/bone_hook.anm");
		pType.AddItemInHandsProfileIK("DNA_KeyCard_Error_Base", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior , "dz/anims/anm/player/ik/gear/bone_hook.anm");
		
		pType.AddItemInHandsProfileIK("DNA_KeyCard_BlisterPackChipEmpty", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior , "dz/anims/anm/player/ik/gear/bone_hook.anm");
		pType.AddItemInHandsProfileIK("DNA_KeyCard_BlisterPackChipBase", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior , "dz/anims/anm/player/ik/gear/bone_hook.anm");
		
		pType.AddItemInHandsProfileIK("DNA_KeyCard_KeyCardChip_Base", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior , "dz/anims/anm/player/ik/gear/bone_hook.anm");

		pType.AddItemInHandsProfileIK("DNA_Laptop", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior , "dz/anims/anm/player/ik/gear/machete.anm");
        pType.AddItemInHandsProfileIK("DNA_Solder", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior , "dz/anims/anm/player/ik/gear/compass.anm");
        pType.AddItemInHandsProfileIK("DNA_Flux", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior , "dz/anims/anm/player/ik/gear/compass.anm");
        pType.AddItemInHandsProfileIK("DNA_Bolts", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior , "dz/anims/anm/player/ik/gear/food_can.anm");
		pType.AddItemInHandsProfileIK("DNA_CardReader", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior , "dz/anims/anm/player/ik/gear/box_cereal.anm");
		
		pType.AddItemInHandsProfileIK("DNA_HelpingHands_Kit", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior , "dz/anims/anm/player/ik/gear/sewing_kit.anm");

	}
    
	override void RegisterHeavy(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
        super.RegisterHeavy(pType, pBehavior);
							
		pType.AddItemInHandsProfileIK("DNA_Workbench_Kit", "dz/anims/workspaces/player/player_main/player_main_heavy.asi", pBehavior , "dz/anims/anm/player/ik/heavy/sea_chest.anm");
	}

	override void RegisterTwoHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
	{	
		super.RegisterTwoHanded( pType,  pBehavior);
				
		pType.AddItemInHandsProfileIK("DNA_Solder_Kit", "dz/anims/workspaces/player/player_main/player_main_2h.asi", pBehavior , "dz/anims/anm/player/ik/vehicles/BatteryTruck.anm");
		pType.AddItemInHandsProfileIK("DNA_Battery40v", "dz/anims/workspaces/player/player_main/player_main_2h.asi", pBehavior , "dz/anims/anm/player/ik/vehicles/BatteryTruck.anm");
		
		pType.AddItemInHandsProfileIK("DNA_Medical_Box_Small", "dz/anims/workspaces/player/player_main/player_main_2h.asi", pBehavior , "dz/anims/anm/player/ik/vehicles/BatteryTruck.anm");
		pType.AddItemInHandsProfileIK("DNA_Medical_Box_Medium", "dz/anims/workspaces/player/player_main/player_main_2h.asi", pBehavior , "dz/anims/anm/player/ik/vehicles/BatteryTruck.anm");
		pType.AddItemInHandsProfileIK("DNA_Medical_Box_Large", "dz/anims/workspaces/player/player_main/player_main_2h.asi", pBehavior , "dz/anims/anm/player/ik/vehicles/BatteryTruck.anm");
		pType.AddItemInHandsProfileIK("DNA_Medical_Box_Special", "dz/anims/workspaces/player/player_main/player_main_2h.asi", pBehavior , "dz/anims/anm/player/ik/vehicles/BatteryTruck.anm");

	}
};