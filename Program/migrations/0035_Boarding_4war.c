void ApplyMigration(ref migrationState) {
	
	int n = FindLocation("BOARDING_4_WAR");
	
	locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].type = "deck_fight";
	Locations[n].filespath.models = "locations\decks\boarding_4_war";
	Locations[n].image = "loading\Boarding_A" + rand(2) + ".tga";

	Locations[n].lockCamAngle = 0.2;
	Locations[n].camshuttle = 1;	
	//Models	
	//Always
	Locations[n].models.always.boarding_4_war = "boarding_4_war";
	Locations[n].models.always.locators = "boarding_4_war_locators";	
	Locations[n].models.always.windows = "boarding_4_war_decals";
	Locations[n].models.always.windows.tech = "Blood";
	//Day
	Locations[n].models.day.charactersPatch = "boarding_4_war_patch";
	Locations[n].models.day.deckFonarsDay = "boarding_4_war_fd";
	Locations[n].models.day.jumpPatch = "boarding_4_war_jump";
	//Night
	Locations[n].models.night.charactersPatch = "boarding_4_war_patch";
	Locations[n].models.night.deckMediumBigNight = "boarding_4_war_fn";	
	Locations[n].models.day.jumpPatch = "boarding_4_war_jump";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";

	Locations[n].boarding = "true";
	Locations[n].boarding.locatorNum = 7;
	//Locations[n].boarding.nextdeck = "Boarding_InsideDeck";
	Locations[n].boarding.nextdeck = "Boarding_Cargohold";
	Locations[n].UpDeckType = true;
	Locations[n].models.always.ropes = "boarding_4_war_ropes";
	
	if(CheckAttribute(&Locations[n],"models.night.deckFonarsNigh"))
		DeleteAttribute(&Locations[n],"models.night.deckFonarsNigh");
	if(CheckAttribute(&Locations[n],"models.always.boarding_5_war"))
		DeleteAttribute(&Locations[n],"models.always.boarding_5_war");
	
	n = FindLocation("BOARDING_5_WAR");
	
	locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].type = "deck_fight";
	Locations[n].filespath.models = "locations\decks\boarding_5_war";
	Locations[n].image = "loading\Boarding_A" + rand(2) + ".tga";

	Locations[n].lockCamAngle = 0.2;
	Locations[n].camshuttle = 1;	
	//Models	
	//Always
	Locations[n].models.always.boarding_5_war = "boarding_5_war";
	Locations[n].models.always.ropes = "boarding_5_war_ropes";
	Locations[n].models.always.locators = "boarding_5_war_locators";	
	Locations[n].models.always.windows = "boarding_5_war_decals";
	Locations[n].models.always.windows.tech = "Blood";
	//Day
	locations[n].models.day.charactersPatch = "boarding_5_war_patch";
	Locations[n].models.day.deckFonarsDay = "boarding_5_war_fd";
	//Night
	locations[n].models.night.charactersPatch = "boarding_5_war_patch";
	Locations[n].models.night.deckMediumBigNight = "boarding_5_war_fn";	
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";

	Locations[n].boarding = "true";
	Locations[n].boarding.locatorNum = 9;
	Locations[n].boarding.nextdeck = "Boarding_Cargohold";
	Locations[n].UpDeckType = true;
	
	if(CheckAttribute(&Locations[n],"models.night.deckFonarsNigh"))
		DeleteAttribute(&Locations[n],"models.night.deckFonarsNigh");
	
	n = FindLocation("BOARDING_5_TRADE");
	
	locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].type = "deck_fight";
	Locations[n].filespath.models = "locations\decks\boarding_5_trade";
	Locations[n].image = "loading\Boarding_A" + rand(2) + ".tga";

	Locations[n].lockCamAngle = 0.2;
	Locations[n].camshuttle = 1;	
	//Models	
	//Always
	Locations[n].models.always.boarding_5_trade = "boarding_5_trade";
	Locations[n].models.always.ropes = "boarding_5_trade_ropes";
	Locations[n].models.always.locators = "boarding_5_trade_locators";	
	Locations[n].models.always.windows = "boarding_5_trade_decals";
	Locations[n].models.always.windows.tech = "Blood";
	//Day
	locations[n].models.day.charactersPatch = "boarding_5_trade_patch";
	Locations[n].models.day.deckFonarsDay = "boarding_5_trade_fd";
	//Night
	locations[n].models.night.charactersPatch = "boarding_5_trade_patch";
	Locations[n].models.night.deckMediumBigNight = "boarding_5_trade_fn";	
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";

	Locations[n].boarding = "true";
	Locations[n].boarding.locatorNum = 7;
	Locations[n].boarding.nextdeck = "Boarding_Cargohold";
	Locations[n].UpDeckType = true;
	
	if(CheckAttribute(&Locations[n],"models.night.deckFonarsNigh"))
		DeleteAttribute(&Locations[n],"models.night.deckFonarsNigh");
	
	// Пинк команда
	ref refShip;
	int i;
	makeref(refShip,ShipsTypes[SHIP_PINK]);
	refShip.MaxCrew        		= 65;
	refShip.OptCrew        		= 52;
	// если корабль уже у игрока
	for (i = 0; i < REAL_SHIPS_QUANTITY; i++)
	{
		if(!CheckAttribute(&RealShips[i],"BaseType")) continue;
		if(RealShips[i].BaseType == SHIP_PINK)
		{
			RealShips[i].MaxCrew = 65;
			RealShips[i].OptCrew = 52;
			if(CheckAttribute(&RealShips[i], "Tuning.MaxCrew"))
			{
				RealShips[i].MaxCrew        = sti(RealShips[i].MaxCrew) + makeint(sti(RealShips[i].MaxCrew)/5);		
			}	
		}
	}
	
	// Клод Дюран снова смертный
	if (CharacterIsAlive("FMQT_mercen"))
	{
		sld = CharacterFromID("FMQT_mercen");
		LAi_SetImmortal(sld, false);
	}
}
