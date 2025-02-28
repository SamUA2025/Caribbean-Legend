void ApplyMigration(ref migrationState) {
	
	ref refShip;
	int i;
	
	// мираж в общем пуле кораблей
	makeref(refShip,ShipsTypes[SHIP_MIRAGE]);
	refship.WaterLine				= -0.75;
	
	// если корабль уже у игрока
	for (i = 0; i < REAL_SHIPS_QUANTITY; i++)
	{
		if(!CheckAttribute(&RealShips[i],"BaseType")) continue;
		if(RealShips[i].BaseType == SHIP_MIRAGE)
		{
			RealShips[i].WaterLine = -0.75;
			RealShips[i].maxHulls = 5;
		}
	}
	
	// Химера для старых сейвов
	makeref(refShip,ShipsTypes[SHIP_HIMERA]);
	refShip.Name				= "Himera";
	refship.Soundtype			= "lugger";
	refShip.Class				= 4;
	refShip.Cannon  			= CANNON_TYPE_CANNON_LBS24;
	refShip.MaxCaliber  		= 24;
	refShip.Weight				= Tonnes2CWT(290);
	refShip.Capacity   			= 3300;
	refShip.CannonsQuantity		= 26;	//	4,2,10,10
	refShip.CannonsQuantityMin	= 26;
	refShip.rcannon 			= 10;
	refShip.lcannon 			= 10
	refShip.fcannon 			= 4;
	refShip.bcannon 			= 2;	
	refShip.MaxCrew        		= 250;
	refShip.OptCrew        		= 200;
	refShip.MinCrew        		= 20;	
	refShip.SpeedRate      		= 15.25;
	refShip.TurnRate       		= 47.0;
	refShip.Price          		= 36900;
	refShip.HP             		= 3200;
	refShip.SP             		= 100;
	
	refship.CabinType          	= "Cabin_Medium2"; 
	refship.Type.Merchant		= false;
	refship.Type.War			= true;
	refship.QuestShip			= true; 
	refShip.lowpolycrew			= 12;

	refship.WindAgainstSpeed   	= 1.40;
	
	refship.Rocking.y			= 0.5;
	refship.Rocking.az			= 0.04;
	
	refship.WaterLine				= -0.75;
	refship.SpeedDependWeight		= 0.3;
	refship.SubSeaDependWeight		= 0.6;
	refship.TurnDependWeight		= 0.3;
	
	refship.InertiaAccelerationX	= 5.5;	refship.InertiaBrakingX	= 5.5;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY	= 8;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ	= 6.0;

	refShip.Height.Bombs.Y		= 1.2;		refShip.Height.Bombs.DY	= 0.6;
	refShip.Height.Grapes.Y		= 3.1;		refShip.Height.Grapes.DY	= 1.5;
	refShip.Height.Knippels.Y	= 17.7;		refShip.Height.Knippels.DY	= 16.7;
	refShip.Height.Balls.Y		= 1.2;		refShip.Height.Balls.DY	= 0.6;
	
	refShip.GeraldSails.rey_b2			= 1;
	refShip.GeraldSails.rey_b2.vscale	= 0.8;
	
	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 12;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "4.0, 6.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	refShip.cannonr  = refShip.rcannon;
	refShip.cannonl  = refShip.lcannon;
	refShip.cannonf  = refShip.fcannon;
	refShip.cannonb  = refShip.bcannon;
}
