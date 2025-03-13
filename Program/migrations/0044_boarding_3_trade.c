void ApplyMigration(ref migrationState) {
	
	ref loc;
	int n;
	
	Locations[FindLocation("BOARDING_3_WAR")].filespath.models = "locations\decks\boarding_3_war";
	
	// палуба 3 класс военный Милосердие
	MAX_LOCATIONS++;
	SetArraySize(&locations, MAX_LOCATIONS);
	
	n = MAX_LOCATIONS - 1;
	
	makeref(loc, Locations[n]);
	DeleteAttribute(loc, "");
	loc.id = "";
	loc.index = n;
	loc.image = "loading\sea_0" + rand(2) + ".tga";
	loc.music = "enplav.ogg";
	loc.locators_radius.reload = 1.0;
	loc.locators_radius.rld = 1.0;
	loc.locators_radius.camdetector = 1.0;
	loc.locators_radius.camera = 0.3;
	loc.locators_radius.characters = 0.5;
	loc.locators_radius.goto = 0.5;		
	loc.locators_radius.sit = 0.5;		
	loc.locators_radius.item = 0.5;		
	loc.locators_radius.officers = 0.5;
	loc.locators_radius.merchant = 1.0;
	loc.locators_radius.box = 1.0;
	loc.locators_radius.candles = 0.1;
	loc.locators_radius.candles_medium = 0.2;
	loc.locators_radius.chandeliers = 0.5;
	loc.locators_radius.heaters = 1.0;
	loc.locators_radius.torchlightes = 0.3;
	loc.locators_radius.torchlightes_o = 0.3;
	loc.locators_radius.fonar = 0.4;
	loc.locators_radius.outside = 2.0;
	loc.locators_radius.incas_light = 0.8;
	loc.locators_radius.incas_sky = 1.0;
	loc.locators_radius.randitem = 1.5;
	loc.locators_radius.waitress = 1.0;
	loc.locators_radius.tables = 0.5;
	loc.locators_radius.barmen = 1.0;
	loc.locators_radius.lamp = 0.2;
	loc.locators_radius.blueteleport = 0.2;
	loc.locators_radius.redteleport = 0.2;
	loc.locators_radius.greenteleport = 0.2;
	loc.locators_radius.magsteleport = 0.2;
	loc.locators_radius.EncDetector = 8.0;
	loc.locators_radius.teleport = 1.0;
	loc.locators_radius.quest = 1.0;
	if (MOD_BETTATESTMODE == "On")
	{// чтоб было видно в отладке Boal 18.08.06
		loc.locators_radius.soldiers = 0.5;
		loc.locators_radius.patrol = 0.5;
		loc.locators_radius.Smugglers = 0.5;
		loc.locators_radius.monsters = 0.5;
	}
	
	//Day dynamic light
	loc.models.day.lights.candles = "candle";
	loc.models.day.lights.candles_medium = "candelabrum";
	loc.models.day.lights.chandeliers = "chandelier";
	loc.models.day.lights.heaters = "heater";
	loc.models.day.lights.torchlightes = "torchlight";		
	loc.models.day.lights.fireglows = "fireglow";		
	loc.models.day.lights.outside = "outside_day";
	loc.models.day.lights.incas_light = "incas";
	loc.models.day.lights.incas_sky = "incasskyday";
	loc.models.day.lights.lamp = "lamp";
	loc.models.day.lights.blueteleport = "blueteleport";
	loc.models.day.lights.redteleport = "redteleport";
	loc.models.day.lights.greenteleport = "greenteleport";
	loc.models.day.lights.magsteleport = "magsteleport";

	//Night dynamic light
	loc.models.night.lights.candles = "candle";
	loc.models.night.lights.candles_medium = "candelabrum";
	loc.models.night.lights.chandeliers = "chandelier";
	loc.models.night.lights.heaters = "heater";
	loc.models.night.lights.torchlightes = "torchlight";
	loc.models.night.lights.torchlightes_o = "torchlight";
	loc.models.night.lights.fireglows = "fireglow";		
	loc.models.night.lights.fonar = "lamp";
	loc.models.night.lights.outside = "outside_night";		
	loc.models.night.lights.incas_light = "incas";
	loc.models.night.lights.incas_sky = "incasskynight";
	loc.models.night.lights.lamp = "lamp";
	loc.models.night.lights.blueteleport = "blueteleport";
	loc.models.night.lights.redteleport = "redteleport";
	loc.models.night.lights.greenteleport = "greenteleport";
	loc.models.night.lights.magsteleport = "magsteleport";
	
	//ID
	Locations[n].id = "BOARDING_3_WAR_SM";
	locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].type = "deck_fight";
	Locations[n].filespath.models = "locations\decks\boarding_3_war_sm";
	Locations[n].image = "loading\Boarding_A" + rand(2) + ".tga";

	Locations[n].lockCamAngle = 0.2;
	Locations[n].camshuttle = 1;	
	//Models	
	//Always
	Locations[n].models.always.boarding_3_war = "boarding_3_war";
	Locations[n].models.always.parts = "boarding_3_war_parts";
	Locations[n].models.always.ropes = "boarding_3_war_ropes";
	Locations[n].models.always.locators = "boarding_3_war_locators";	
	Locations[n].models.always.decals = "boarding_3_war_decals";
	Locations[n].models.always.decals.tech = "Blood";
	Locations[n].models.always.windows = "boarding_3_war_windows";
	Locations[n].models.always.windows.tech = "LocationWindows";
	locations[n].models.always.windows.level = 65539;
	Locations[n].models.always.watermask = "boarding_3_war_watermask";
	Locations[n].models.always.watermask.tech = "WaterMask";
	//Day
	Locations[n].models.day.charactersPatch = "boarding_3_war_patch";
	Locations[n].models.day.deckFonarsDay = "boarding_3_war_fd";
	Locations[n].models.day.jumpPatch = "boarding_3_war_jump";
	//Night
	Locations[n].models.night.charactersPatch = "boarding_3_war_patch";
	Locations[n].models.night.deckMediumBigNight = "boarding_3_war_fn";	
	Locations[n].models.night.jumpPatch = "boarding_3_war_jump";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";

	Locations[n].boarding = "true";
	Locations[n].boarding.locatorNum = 11;
	Locations[n].boarding.nextdeck = "Boarding_Cargohold";
	Locations[n].UpDeckType = true;
	
	// палуба 3 класс торговый
	MAX_LOCATIONS++;
	SetArraySize(&locations, MAX_LOCATIONS);
	
	n = MAX_LOCATIONS - 1;
	
	makeref(loc, Locations[n]);
	DeleteAttribute(loc, "");
	loc.id = "";
	loc.index = n;
	loc.image = "loading\sea_0" + rand(2) + ".tga";
	loc.music = "enplav.ogg";
	loc.locators_radius.reload = 1.0;
	loc.locators_radius.rld = 1.0;
	loc.locators_radius.camdetector = 1.0;
	loc.locators_radius.camera = 0.3;
	loc.locators_radius.characters = 0.5;
	loc.locators_radius.goto = 0.5;		
	loc.locators_radius.sit = 0.5;		
	loc.locators_radius.item = 0.5;		
	loc.locators_radius.officers = 0.5;
	loc.locators_radius.merchant = 1.0;
	loc.locators_radius.box = 1.0;
	loc.locators_radius.candles = 0.1;
	loc.locators_radius.candles_medium = 0.2;
	loc.locators_radius.chandeliers = 0.5;
	loc.locators_radius.heaters = 1.0;
	loc.locators_radius.torchlightes = 0.3;
	loc.locators_radius.torchlightes_o = 0.3;
	loc.locators_radius.fonar = 0.4;
	loc.locators_radius.outside = 2.0;
	loc.locators_radius.incas_light = 0.8;
	loc.locators_radius.incas_sky = 1.0;
	loc.locators_radius.randitem = 1.5;
	loc.locators_radius.waitress = 1.0;
	loc.locators_radius.tables = 0.5;
	loc.locators_radius.barmen = 1.0;
	loc.locators_radius.lamp = 0.2;
	loc.locators_radius.blueteleport = 0.2;
	loc.locators_radius.redteleport = 0.2;
	loc.locators_radius.greenteleport = 0.2;
	loc.locators_radius.magsteleport = 0.2;
	loc.locators_radius.EncDetector = 8.0;
	loc.locators_radius.teleport = 1.0;
	loc.locators_radius.quest = 1.0;
	if (MOD_BETTATESTMODE == "On")
	{// чтоб было видно в отладке Boal 18.08.06
		loc.locators_radius.soldiers = 0.5;
		loc.locators_radius.patrol = 0.5;
		loc.locators_radius.Smugglers = 0.5;
		loc.locators_radius.monsters = 0.5;
	}
	
	//Day dynamic light
	loc.models.day.lights.candles = "candle";
	loc.models.day.lights.candles_medium = "candelabrum";
	loc.models.day.lights.chandeliers = "chandelier";
	loc.models.day.lights.heaters = "heater";
	loc.models.day.lights.torchlightes = "torchlight";		
	loc.models.day.lights.fireglows = "fireglow";		
	loc.models.day.lights.outside = "outside_day";
	loc.models.day.lights.incas_light = "incas";
	loc.models.day.lights.incas_sky = "incasskyday";
	loc.models.day.lights.lamp = "lamp";
	loc.models.day.lights.blueteleport = "blueteleport";
	loc.models.day.lights.redteleport = "redteleport";
	loc.models.day.lights.greenteleport = "greenteleport";
	loc.models.day.lights.magsteleport = "magsteleport";

	//Night dynamic light
	loc.models.night.lights.candles = "candle";
	loc.models.night.lights.candles_medium = "candelabrum";
	loc.models.night.lights.chandeliers = "chandelier";
	loc.models.night.lights.heaters = "heater";
	loc.models.night.lights.torchlightes = "torchlight";
	loc.models.night.lights.torchlightes_o = "torchlight";
	loc.models.night.lights.fireglows = "fireglow";		
	loc.models.night.lights.fonar = "lamp";
	loc.models.night.lights.outside = "outside_night";		
	loc.models.night.lights.incas_light = "incas";
	loc.models.night.lights.incas_sky = "incasskynight";
	loc.models.night.lights.lamp = "lamp";
	loc.models.night.lights.blueteleport = "blueteleport";
	loc.models.night.lights.redteleport = "redteleport";
	loc.models.night.lights.greenteleport = "greenteleport";
	loc.models.night.lights.magsteleport = "magsteleport";
	
	//ID
	Locations[n].id = "BOARDING_3_TRADE";
	locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].type = "deck_fight";
	Locations[n].filespath.models = "locations\decks\boarding_3_trade";
	Locations[n].image = "loading\Boarding_A" + rand(2) + ".tga";
	Locations[n].lockCamAngle = 0.2;
	Locations[n].camshuttle = 1;	
	//Models	
	//Always
	Locations[n].models.always.boarding_3_trade = "boarding_3_trade";
	Locations[n].models.always.parts = "boarding_3_trade_parts";
	Locations[n].models.always.ropes = "boarding_3_trade_ropes";
	Locations[n].models.always.locators = "boarding_3_trade_locators";	
	Locations[n].models.always.decals = "boarding_3_trade_decals";
	Locations[n].models.always.decals.tech = "Blood";
	Locations[n].models.always.windows = "boarding_3_trade_windows";
	Locations[n].models.always.windows.tech = "LocationWindows";
	locations[n].models.always.windows.level = 65539;
	Locations[n].models.always.watermask = "boarding_3_trade_watermask";
	Locations[n].models.always.watermask.tech = "WaterMask";
	//Day
	Locations[n].models.day.charactersPatch = "boarding_3_trade_patch";
	Locations[n].models.day.deckFonarsDay = "boarding_3_trade_fd";
	Locations[n].models.day.jumpPatch = "boarding_3_trade_jump";
	//Night
	Locations[n].models.night.charactersPatch = "boarding_3_trade_patch";
	Locations[n].models.night.deckMediumBigNight = "boarding_3_trade_fn";	
	Locations[n].models.night.jumpPatch = "boarding_3_trade_jump";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	Locations[n].boarding = "true";
	Locations[n].boarding.locatorNum = 11;
	Locations[n].boarding.nextdeck = "Boarding_Cargohold";
	Locations[n].UpDeckType = true;
	
	loadedLocation = &locations[0];
	
	ref refShip;
	makeref(refShip,ShipsTypes[SHIP_GALEON_L]);
	refship.Type.Merchant				= true;
}
