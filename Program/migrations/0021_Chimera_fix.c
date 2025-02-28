void ApplyMigration(ref migrationState) {
	
	ref refShip;
	int i;
	
	// Химера в общем пуле кораблей
	makeref(refShip,ShipsTypes[SHIP_HIMERA]);
	refShip.cannonr  = refShip.rcannon;
	refShip.cannonl  = refShip.lcannon;
	refShip.cannonf  = refShip.fcannon;
	refShip.cannonb  = refShip.bcannon;
	
	// если корабль уже у игрока
	for (i = 0; i < REAL_SHIPS_QUANTITY; i++)
	{
		if(!CheckAttribute(&RealShips[i],"BaseType")) continue;
		if(RealShips[i].BaseType == SHIP_HIMERA)
		{
			RealShips[i].cannonr  = RealShips[i].rcannon;
			RealShips[i].cannonl  = RealShips[i].lcannon;
			RealShips[i].cannonf  = RealShips[i].fcannon;
			RealShips[i].cannonb  = RealShips[i].bcannon;
		}
	}
}
