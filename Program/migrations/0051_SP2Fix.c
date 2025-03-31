void ApplyMigration(ref migrationState) {
	
	int i;
    string sTemp;

    // Зачистить старые записки и согласовать прочтение
    for(i = 1; i <= 18; i++)
    {
        sTemp = "treasure_note_" + i;
        FindRealItem(sTemp, "TakeItemFromCharacter");
        if(CheckAttribute(PChar, "questTemp.Treasure_Stories." + sTemp))
        {
            DeleteAttribute(PChar, "questTemp.Treasure_Stories." + i);
            DeleteAttribute(PChar, "questTemp.Treasure_Stories." + sTemp);
        }
    }

    // Убрать дубли FirearmStockPart
	if(CheckAttribute(&items[FindItem("mushket9")],"UpgradeStage"))
	{
		int iStage = sti(items[FindItem("mushket9")].UpgradeStage);
		for(i = 1; i <= 3; i++)
		{
			sTemp = "FirearmStockPart_" + i;
			if(iStage > i) FindRealItem(sTemp, "TakeItemFromCharacter");
		}
	}

    // Исправить описание старой карты
    ref rMap = &items[FindItem("map_full")];
    if(CheckAttribute(rMap, "MapTypeIdx") && sti(rMap.MapTypeIdx) == 0) rMap.MapTypeIdx = 7;
}
