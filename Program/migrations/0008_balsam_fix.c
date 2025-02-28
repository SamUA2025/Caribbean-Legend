void ApplyMigration(ref migrationState) {
	//обновить таймер
	SetFunctionTimerCondition("TorrentEddy", 5, 0, 0, false);
	
	items[FindItem("Totem_3")].time = 90;
	
	int i, j;
	for (i = 0; i < REAL_SHIPS_QUANTITY; i++)
	{
		if(!CheckAttribute(&RealShips[i],"BaseType")) continue;
		if(RealShips[i].BaseType == SHIP_RENOVATED_FDM)
		{
			RealShips[i].CannonsQuantity = 56
			RealShips[i].CannonsQuantityMax = 56;
			RealShips[i].CannonsQuantityMin = 56;
			RealShips[i].rcannon = 23;
			RealShips[i].lcannon = 23;
			RealShips[i].fcannon = 6;
			RealShips[i].bcannon = 4;
			RealShips[i].Capacity  = 7200;
		}
		if(RealShips[i].BaseType == SHIP_CURSED_FDM)
		{
			RealShips[i].Capacity  = 7200;
		}
	}
	ref refShip;
	makeref(refShip,ShipsTypes[SHIP_CURSED_FDM]);
	refShip.Capacity  = 7200;
	
	for(j = 0; j < MAX_CHARACTERS; j++)
	{
		if(!CheckAttribute(&characters[j],"Ship.Cannons.borts")) continue;
		if(!CheckAttribute(&characters[j],"Ship.Type")) continue;
		if(sti(characters[j].Ship.Type) > 899) continue;
		if(RealShips[sti(characters[j].Ship.Type)].BaseType != SHIP_RENOVATED_FDM) continue;
		
		for (i = 0; i < 24; i++)
		{
			string attr2 = "c" + i;
			characters[j].Ship.Cannons.borts.cannonr.damages.(attr2) = 1.0;
			characters[j].Ship.Cannons.borts.cannonl.damages.(attr2) = 1.0; 
		}
		
		for (i = 0; i < 23; i++)
		{
			string attr1 = "c" + i;
			characters[j].Ship.Cannons.borts.cannonr.damages.(attr1) = 0.0;
			characters[j].Ship.Cannons.borts.cannonl.damages.(attr1) = 0.0;
		}
		//RecalculateCargoLoad(&characters[j]);
	}
}
