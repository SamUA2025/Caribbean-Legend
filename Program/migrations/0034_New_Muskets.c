void ApplyMigration(ref migrationState) {
	
	ref rItem;
	for(int i = 0; i < TOTAL_ITEMS; i++) 
	{
			rItem = &Items[i];
			if(!CheckAttribute(rItem, "groupID")) continue;
			if(rItem.groupID != GUN_ITEM_TYPE) continue;
			if(HasSubStr(rItem.id, "mushket")) 
			{
				rItem.groupID = MUSKET_ITEM_TYPE;
			}
	}
	if(startHeroType == 2)
	{
		pchar.HeroModel 			= "Diego_1,Diego_2,Diego_3,Diego_4,Diego_5,protocusto,Diego_6,Diego_8,Diego_1,Diego_9,Diego_1,Diego_11,Diego_12,Diego_13,Diego_14";
	}
	if(startHeroType == 3)
	{
		pchar.HeroModel 			= "Willy_1,Willy_2,Willy_3,Willy_4,Willy_5,protocusto,Willy_6,Willy_8,Willy_1,Willy_9,Willy_1,Willy_11,Willy_12,Willy_13,Willy_14";
	}
	if(HasSubStr(pchar.model, "_mush")) 
	{
		pchar.model = FindStringBeforeChar(pchar.model, "_mush");
		//SetMainCharacterToMushketer("", false);
	}
	pchar.Model.animation = pchar.Model;
	
	for(int n=0; n<MAX_CHARACTERS; n++)
	{
		if(!CheckAttribute(&Characters[n],"equip.gun")) continue;
		if(CheckAttribute(&Characters[n],"IsMushketer")) 
		{
			if(and(CharacterIsAlive("Irons"), Characters[n].id == "Irons") 
			|| and(CharacterIsAlive("Tichingitu"), Characters[n].id == "Tichingitu")
			|| and(CharacterIsAlive("LongWay"), Characters[n].id == "LongWay")
			|| Characters[n].id == "Blaze")
			{
				/* log_info("CharID "+Characters[n].id);
				log_info("gun "+Characters[n].equip.gun); */
				if(HasSubStr(Characters[n].equip.qun, "mushket"))
				{
					Characters[n].equip.musket = Characters[n].equip.gun;
					trace("У персонажа "+Characters[n].id+" Musket "+Characters[n].equip.musket);
				} 
				if(CheckAttribute(&Characters[n],"IsMushketer.LastGunID"))
				{
					Characters[n].equip.gun = Characters[n].IsMushketer.LastGunID;
					RemoveCharacterEquip(&Characters[n], MUSKET_ITEM_TYPE);
					EquipCharacterByItem(&Characters[n], Characters[n].IsMushketer.LastGunID);
				}
			}
		}
	}
	/* object opt;
	ReadSavedOptionsEx(&opt, "options");
	InterfaceStates.mouse.x_sens = 0.15;
	opt.mouse.x_sensitivity=0.1500000
	InterfaceStates.mouse.y_sens = 0.36;
	opt.mouse.y_sensitivity=0.3600000
	SaveSavedOptionsEx(&opt, "options"); */
	ref loc;
	string marksToDelete[128];
	for(i=0; i<MAX_LOCATIONS; i++)
	{
		loc = &locations[i];
		if(!CheckAttribute(loc, "QuestPointer.item")) continue;
		
		aref itemsGroup;
		makearef(itemsGroup, loc.QuestPointer.item);
		int itemMarksQty = GetAttributesNum(itemsGroup);
		for (n = 0; n < itemMarksQty; n++) {
			aref itemLoc = GetAttributeN(itemsGroup, n);
			marksToDelete[n] = GetAttributeName(itemLoc);
		}
		
		for (n = 0; n < itemMarksQty; n++) {
			QuestPointerDelLoc(loc.id, "item", marksToDelete[n]);
		}
	}
}