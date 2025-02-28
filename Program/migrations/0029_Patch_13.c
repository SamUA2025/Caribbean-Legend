void ApplyMigration(ref migrationState) {
	
	ChrPerksList.list.TannedLeather.HeroType = "HT1";
	ChrPerksList.list.Dragoon.HeroType = "HT3";
	ChrPerksList.list.FencingMaster.HeroType = "HT1";
	ChrPerksList.list.SecondWind.HeroType = "HT3";
	ChrPerksList.list.Jager.HeroType = "HT4";
	ChrPerksList.list.Sniper.HeroType = "HT4";
	ChrPerksList.list.TreasureHunter.HeroType = "HT2";
	ChrPerksList.list.Mimicry.HeroType = "HT2";
	ChrPerksList.list.RatsWolf.HeroType = "HT2";
	ChrPerksList.list.Bombardier.HeroType = "HT4";
	
	if (CheckAttribute(pchar, "questTemp.Mtraxx") && pchar.questTemp.Mtraxx == "fail_end")
	{
		if(CheckAttribute(pchar, "questTemp.Mtraxx.CharleePrince"))
		{
			DeleteAttribute(pchar, "questTemp.Mtraxx.CharleePrince");
		}
		DelCharleePrince("");
	}
	
	// пинк
	ref refShip;
	makeref(refShip,ShipsTypes[SHIP_PINK]);
	refShip.Name						= "Pink";
	refship.Soundtype					= "lugger";
	refShip.Class						= 5;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS6;
	refShip.MaxCaliber      			= 12;
	refShip.Weight						= Tonnes2CWT(170);
	refShip.Capacity        			= 1600;	
	refShip.CannonsQuantity				= 16; // 2,2,6,6
	refShip.CannonsQuantityMin			= 16;
	refShip.rcannon 					= 6;
	refShip.lcannon 					= 6;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 2;
	
	refShip.MaxCrew         			= 50;
	refShip.OptCrew         			= 40;
	refShip.MinCrew         			= 7;	
	refShip.SpeedRate					= 13.0;
	refShip.TurnRate        			= 55.0;
	refShip.Price           			= 23300;
	refShip.HP              			= 1800;
	refShip.SP              			= 100;

	refship.Type.Merchant			= true;
	refship.Type.War				= false;
	refship.QuestShip				= true; 
	refShip.lowpolycrew 				= 12;
	
	refship.Rocking.y 					= 0.45;
	refship.Rocking.az 					= 0.02;
	
	refship.WaterLine					= 0.0;

	refship.SpeedDependWeight			= 0.2;
	refship.SubSeaDependWeight			= 0.3;
	refship.TurnDependWeight			= 0.3;
	
	refship.WindAgainstSpeed   			= 0.30;

	refShip.Height.Bombs.Y				= 1.6;	refShip.Height.Bombs.DY		= 1.25;
	refShip.Height.Grapes.Y				= 2.75;	refShip.Height.Grapes.DY	= 0.6;
	refShip.Height.Knippels.Y			= 13.2;	refShip.Height.Knippels.DY	= 8.5;
	refShip.Height.Balls.Y				= 1.6;	refShip.Height.Balls.DY		= 1.25;
	
	refship.InertiaAccelerationX	= 8.0;	refship.InertiaBrakingX		= 8.0;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 8.0;	refship.InertiaBrakingZ		= 8.0;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 9;
	refship.Track1.Width	= "2.0, 2.5";
	refship.Track1.Speed	= "5.2, 6.2";

	refship.Track2.ZStart	= -0.05;
	refship.Track2.LifeTime = 7;
	refship.Track2.Width	= "3.0, 4.0";
	refship.Track2.Speed	= "0.15, 0.25";
}