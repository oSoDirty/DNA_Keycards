modded class ActionConstructor 
{
    override void RegisterActions(TTypenameArray actions)
    {
        super.RegisterActions(actions);
        actions.Insert(ActionHandleKeycard);
		actions.Insert(ActionOpenSmolCrate);
		actions.Insert(ActionRequiresKeycard);
		actions.Insert(ActionActivateKeycard);
		actions.Insert(ActionUnpackMicrochip);
		actions.Insert(ActionUnlockSecuredDoors);
    }
};