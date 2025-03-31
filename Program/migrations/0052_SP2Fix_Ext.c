void ApplyMigration(ref migrationState) {
	
	int i;
    string sTemp;

    if(!SandBoxMode)
    {
        if(!CheckAttribute(&Render, "SingleTreasure.chemistry") && CheckCharacterItem(pchar, "chemistry"))
        {
            RemoveItems(pchar, "chemistry", 1); // Взял из клада, надо забрать
        }
        for(i = 1; i <= 15; i++)
        {
            sTemp = "T" + i;
            DeleteAttribute(&Render, sTemp + ".Jewelry.recipe_GunEchin");
            DeleteAttribute(&Render, sTemp + ".Jewelry.Mineral32");
            DeleteAttribute(&Render, sTemp + ".Jewelry.Tigel");
            DeleteAttribute(&Render, sTemp + ".Jewelry.chemistry");
            DeleteAttribute(&Render, sTemp + ".Special.Map_Best");
        }
        DeleteAttribute(&Render, "SingleTreasure.recipe_GunEchin");
        DeleteAttribute(&Render, "SingleTreasure.Mineral32");
        DeleteAttribute(&Render, "SingleTreasure.Tigel");
        DeleteAttribute(&Render, "SingleTreasure.chemistry");
        DeleteAttribute(&Render, "SingleTreasure.Map_Best");
    }
}
