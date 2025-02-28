void ApplyMigration(ref migrationState) {
	
	ref refShip;
	// Галеон в общем пуле кораблей
	makeref(refShip,ShipsTypes[SHIP_GALEON_SM]);
	refShip.CannonsQuantity				= 30;	// 2,2,13,13
	refShip.CannonsQuantityMin			= 30;
	
	// если корабль уже у игрока
	for (i = 0; i < REAL_SHIPS_QUANTITY; i++)
	{
		if(!CheckAttribute(&RealShips[i],"BaseType")) continue;
		if(RealShips[i].BaseType == SHIP_GALEON_SM)
		{
			RealShips[i].CannonsQuantity     = 30;	// 2,2,13,13
			RealShips[i].CannonsQuantityMin  = 30;
		}
	}
}
