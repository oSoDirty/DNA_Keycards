modded class ModItemRegisterCallbacks
{

	override void RegisterOneHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
	{	
		super.RegisterOneHanded( pType,  pBehavior);
				
		pType.AddItemInHandsProfileIK("KC_KeyCard_Red", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior , "dz/anims/anm/player/ik/gear/bone_hook.anm");
		pType.AddItemInHandsProfileIK("KC_KeyCard_Purple", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior , "dz/anims/anm/player/ik/gear/bone_hook.anm");
		pType.AddItemInHandsProfileIK("KC_KeyCard_Blue", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior , "dz/anims/anm/player/ik/gear/bone_hook.anm");
		pType.AddItemInHandsProfileIK("KC_KeyCard_Green", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior , "dz/anims/anm/player/ik/gear/bone_hook.anm");
		pType.AddItemInHandsProfileIK("KC_KeyCard_Yellow", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior , "dz/anims/anm/player/ik/gear/bone_hook.anm");
		pType.AddItemInHandsProfileIK("KC_KeyCard_Error", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior , "dz/anims/anm/player/ik/gear/bone_hook.anm");
		pType.AddItemInHandsProfileIK("KC_KeyCard_BlisterPackChip", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior , "dz/anims/anm/player/ik/gear/bone_hook.anm");
		pType.AddItemInHandsProfileIK("KC_KeyCard_BlisterPackChipEmpty", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior , "dz/anims/anm/player/ik/gear/bone_hook.anm");
		pType.AddItemInHandsProfileIK("KC_KeyCard_KeyCardChip", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior , "dz/anims/anm/player/ik/gear/bone_hook.anm");
	}
};