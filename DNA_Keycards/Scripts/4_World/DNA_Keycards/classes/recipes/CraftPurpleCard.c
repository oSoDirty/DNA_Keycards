modded class PluginRecipesManagerBase
{
    override void RegisterRecipies()
    {
        super.RegisterRecipies();

        RegisterRecipe(new CraftPurpleCard);
    }
};
class CraftPurpleCard extends RecipeBase
{	
	override void Init()
	{
		m_Name = "Fit Chip Into Card & Downgrade to Tier 4 Purple KeyCard";
		m_IsInstaRecipe = false;
		m_AnimationLength = 5;
		m_Specialty = -0.02;
		
		
		//Crafting Conditions
		m_MinDamageIngredient[0] = -1;
		m_MaxDamageIngredient[0] = 3;
		m_MinQuantityIngredient[0] = 1;
		m_MaxQuantityIngredient[0] = -1;
		
		m_MinDamageIngredient[1] = -1;
		m_MaxDamageIngredient[1] = 3;
		m_MinQuantityIngredient[1] = -1;
		m_MaxQuantityIngredient[1] = -1;
		
		InsertIngredient(0,"KC_KeyCard_ColourBase");
		
		m_IngredientAddHealth[0] = 0;
		m_IngredientSetHealth[0] = -1; // -1 = do nothing
		m_IngredientAddQuantity[0] = 0;
		m_IngredientDestroy[0] = 1;
		m_IngredientUseSoftSkills[1] = false;// set 'true' to allow modification of the values by softskills on this ingredient
		
		InsertIngredient(1,"KC_KeyCard_KeyCardChip");//you can insert multiple ingredients this way

		m_IngredientAddHealth[1] = 0;
		m_IngredientSetHealth[1] = -1; // -1 = do nothing
		m_IngredientAddQuantity[1] = 0;
		m_IngredientDestroy[1] = 1;
		m_IngredientUseSoftSkills[1] = true;// set 'true' to allow modification of the values by softskills on this ingredient
		
		//Crafting Result
		AddResult("KC_KeyCard_");

		m_ResultSetFullQuantity[0] = false;
		m_ResultSetQuantity[0] = 0;
		m_ResultSetHealth[0] = -1;
		m_ResultInheritsHealth[0] = -1;
		m_ResultInheritsColor[0] = 0;
		m_ResultToInventory[0] = -2;
		m_ResultUseSoftSkills[0] = true;
		m_ResultReplacesIngredient[0] = -1;
	}

    override void Do(ItemBase ingredients[], PlayerBase player,array<ItemBase> results, float specialty_weight)//gets called upon recipe's completion
    {
		if(results)
		{
			ItemBase result = ItemBase.Cast(results.Get(0));
			if(result)
				result.SetQuantity(result.GetQuantity() + 1);
		}
        Debug.Log("Recipe Do method called","recipes");
    }
};