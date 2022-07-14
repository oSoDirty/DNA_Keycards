modded class ModItemRegisterCallbacks
{

	override void RegisterOneHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
	{	
		super.RegisterOneHanded( pType,  pBehavior);
				
		pType.AddItemInHandsProfileIK("DNA_KeyCard_Red", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior , "dz/anims/anm/player/ik/gear/bone_hook.anm");
		pType.AddItemInHandsProfileIK("DNA_KeyCard_Purple", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior , "dz/anims/anm/player/ik/gear/bone_hook.anm");
		pType.AddItemInHandsProfileIK("DNA_KeyCard_Blue", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior , "dz/anims/anm/player/ik/gear/bone_hook.anm");
		pType.AddItemInHandsProfileIK("DNA_KeyCard_Green", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior , "dz/anims/anm/player/ik/gear/bone_hook.anm");
		pType.AddItemInHandsProfileIK("DNA_KeyCard_Yellow", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior , "dz/anims/anm/player/ik/gear/bone_hook.anm");
		pType.AddItemInHandsProfileIK("DNA_KeyCard_Error", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior , "dz/anims/anm/player/ik/gear/bone_hook.anm");
		pType.AddItemInHandsProfileIK("DNA_KeyCard_BlisterPackChip", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior , "dz/anims/anm/player/ik/gear/bone_hook.anm");
		pType.AddItemInHandsProfileIK("DNA_KeyCard_BlisterPackChipEmpty", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior , "dz/anims/anm/player/ik/gear/bone_hook.anm");
		pType.AddItemInHandsProfileIK("DNA_KeyCard_KeyCardChip", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior , "dz/anims/anm/player/ik/gear/bone_hook.anm");

		pType.AddItemInHandsProfileIK("DNA_KeyCard_Red_Inactive", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior , "dz/anims/anm/player/ik/gear/bone_hook.anm");
		pType.AddItemInHandsProfileIK("DNA_KeyCard_Purple_Inactive", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior , "dz/anims/anm/player/ik/gear/bone_hook.anm");
		pType.AddItemInHandsProfileIK("DNA_KeyCard_Blue_Inactive", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior , "dz/anims/anm/player/ik/gear/bone_hook.anm");
		pType.AddItemInHandsProfileIK("DNA_KeyCard_Green_Inactive", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior , "dz/anims/anm/player/ik/gear/bone_hook.anm");
		pType.AddItemInHandsProfileIK("DNA_KeyCard_Yellow_Inactive", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior , "dz/anims/anm/player/ik/gear/bone_hook.anm");
		pType.AddItemInHandsProfileIK("DNA_KeyCard_Error_Inactive", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior , "dz/anims/anm/player/ik/gear/bone_hook.anm");

	}
};