void ApplyMigration(ref migrationState) {
	
	ref loc;
	int n;
	
	// палуба 5 класс военный
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
	Locations[n].id = "BOARDING_5_WAR";
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
	Locations[n].models.always.locators = "boarding_5_war_locators";	
	//Day
	locations[n].models.day.charactersPatch = "boarding_5_war_patch";
	Locations[n].models.day.deckFonarsDay = "boarding_5_war_fd";
	//Night
	locations[n].models.night.charactersPatch = "boarding_5_war_patch";
	Locations[n].models.night.deckFonarsNigh = "boarding_5_war_fn";	
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";

	Locations[n].boarding = "true";
	Locations[n].boarding.locatorNum = 9;
	//Locations[n].boarding.nextdeck = "Boarding_InsideDeck";
	Locations[n].boarding.nextdeck = "Boarding_Cargohold";
	Locations[n].UpDeckType = true;
	
	// палуба 5 класс торговец
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
	Locations[n].id = "BOARDING_5_TRADE";
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
	Locations[n].models.always.locators = "boarding_5_trade_locators";	
	//Day
	locations[n].models.day.charactersPatch = "boarding_5_trade_patch";
	Locations[n].models.day.deckFonarsDay = "boarding_5_trade_fd";
	//Night
	locations[n].models.night.charactersPatch = "boarding_5_trade_patch";
	Locations[n].models.night.deckFonarsNigh = "boarding_5_trade_fn";	
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";

	Locations[n].boarding = "true";
	Locations[n].boarding.locatorNum = 7;
	//Locations[n].boarding.nextdeck = "Boarding_InsideDeck";
	Locations[n].boarding.nextdeck = "Boarding_Cargohold";
	Locations[n].UpDeckType = true;
	
	// палуба 4 класс военный
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
	Locations[n].id = "BOARDING_4_WAR";
	locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].type = "deck_fight";
	Locations[n].filespath.models = "locations\decks\boarding_4_war";
	Locations[n].image = "loading\Boarding_A" + rand(2) + ".tga";

	Locations[n].lockCamAngle = 0.2;
	Locations[n].camshuttle = 1;	
	//Models	
	//Always
	Locations[n].models.always.boarding_5_war = "boarding_4_war";
	Locations[n].models.always.locators = "boarding_4_war_locators";	
	//Day
	locations[n].models.day.charactersPatch = "boarding_4_war_patch";
	Locations[n].models.day.deckFonarsDay = "boarding_4_war_fd";
	//Night
	locations[n].models.night.charactersPatch = "boarding_4_war_patch";
	Locations[n].models.night.deckFonarsNigh = "boarding_4_war_fn";	
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";

	Locations[n].boarding = "true";
	Locations[n].boarding.locatorNum = 7;
	//Locations[n].boarding.nextdeck = "Boarding_InsideDeck";
	Locations[n].boarding.nextdeck = "Boarding_Cargohold";
	Locations[n].UpDeckType = true;
	
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
	locations[n].id = "Formosa";
	locations[n].id.label = "Zeelanda";
	
	locations[n].filespath.models = "locations\Town_Formosa\Town\";
	locations[n].image = "loading\Town.tga";
	locations[n].citizens = true;
	locations[n].soldiers = true;
	locations[n].carrier = true;
	//Sound
	locations[n].type = "town";
	//Models
	//Always
	locations[n].models.always.town = "Curacao";
	locations[n].models.always.town.sea_reflection = 1;
	locations[n].models.always.L1 = "Curacao_signsA";
	locations[n].models.always.L2 = "Curacao_signsB";
    locations[n].models.always.L2.tech = "DLightModel"
	locations[n].models.always.locators = "Curacao_locators";
	locations[n].models.always.grassPatch = "Curacao_grass";
	locations[n].models.always.seabed = "Curacao_sb";

	//River
	locations[n].models.always.Waterfall1 = "river1";
	locations[n].models.always.Waterfall1.uvslide.v0 = 0.2;
    locations[n].models.always.Waterfall1.uvslide.v1 = 0.0;
	locations[n].models.always.Waterfall1.tech = "LocationWaterFall";
	locations[n].models.always.Waterfall1.level = 50;
	
	locations[n].models.always.Waterfall2 = "river2";
	locations[n].models.always.Waterfall2.uvslide.v0 = 0.4;
    loc.models.always.Waterfall2.uvslide.v1 = 0.0;
	locations[n].models.always.Waterfall2.tech = "LocationWaterFall";
	locations[n].models.always.Waterfall2.level = 49;

	//WindMill Fan
	locations[n].models.always.MillFan = "MillFan";
	locations[n].models.always.MillFan.locator.group = "WindMill";
	locations[n].models.always.MillFan.locator.name ="Fan";	
	locations[n].models.always.MillFan.rotate.x = 0.0;
	locations[n].models.always.MillFan.rotate.y = 0.0;
	locations[n].models.always.MillFan.rotate.z = 0.3;

	locations[n].models.always.MillFan1 = "Flugger";
    locations[n].models.always.MillFan1.tech = "DLightModel";
    locations[n].models.always.MillFan1.locator.group = "WindMill";
    locations[n].models.always.MillFan1.locator.name ="Fan1";    
    locations[n].models.always.MillFan1.rotate.x = 0.0;
    locations[n].models.always.MillFan1.rotate.y = 0.3;
    locations[n].models.always.MillFan1.rotate.z = 0.0;
	
	//Day
	locations[n].models.day.fonar = "Curacao_fd";
	locations[n].models.day.charactersPatch = "Curacao_patch_day";
	locations[n].models.day.rinok = "Curacao_rinok";
	//Night
	locations[n].models.night.fonar = "Curacao_fn";
	locations[n].models.night.charactersPatch = "Curacao_patch_night";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	//Reload map
	
	// --> Типовые городские локации, четкая фиксация на 10 номеров.
	// В таверне
	locations[n].reload.l4.name = "reload4_back";
	locations[n].reload.l4.go = "Formosa_tavern";
	locations[n].reload.l4.emerge = "reload1";
	locations[n].reload.l4.autoreload = "0";
	locations[n].reload.l4.label = "Tavern";
	// В дом Йохана ван Мердена
	locations[n].reload.l21.name = "houseSp1";
	locations[n].reload.l21.go = "Formosa_houseSp1";
	locations[n].reload.l21.emerge = "reload1";
	locations[n].reload.l21.autoreload = "0";
	locations[n].reload.l21.label = "House"; 
	// За городские ворота
	locations[n].reload.l22.name = "gate_back";
	locations[n].reload.l22.go = "Formosa_ExitTown";
	locations[n].reload.l22.emerge = "reload4";
	locations[n].reload.l22.autoreload = "0";
	locations[n].reload.l22.label = "ExitTown"; 
	
	LAi_LocationFightDisable(&locations[n], true);
	
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Таверна, Остров Формоза
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
	locations[n].id = "Formosa_tavern";
	locations[n].id.label = "Tavern";
	locations[n].filespath.models = "locations\inside\tavern01\";
	locations[n].image = "loading\inside\tavern.tga";
	locations[n].habitues = 1;
	//Town sack
	//locations[n].townsack = "Villemstad";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "tavern";
	//locations[n].fastreload = "Villemstad";
	//Models
	//Always
	locations[n].models.always.tavern = "Tavern01";
	locations[n].models.always.tavern.level = 65538;
	locations[n].models.always.locators = "Tavern01_locators";
	locations[n].models.always.window = "tavern01_windows";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;
	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.window.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "tavern01_patch";
	//Night
	locations[n].models.night.charactersPatch = "tavern01_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Formosa";
	locations[n].reload.l1.emerge = "reload4";
	locations[n].reload.l1.autoreload = "0";
    locations[n].reload.l1.label = "Street";

	LAi_LocationFightDisable(&locations[n], true);
	
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Дом Йохана ван Мердена, Остров Формоза
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
	locations[n].id = "Formosa_houseSp1"; //с комнатой на втором этаже
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\largehouse01.tga";
	//Town sack
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\largehouse01";
	locations[n].models.always.largehouse01 = "largehouse01";
	locations[n].models.always.largehouse01.level = 65538;
	locations[n].models.day.locators = "largehouse01_locators";
	locations[n].models.night.locators = "largehouse01_Nlocators";

	locations[n].models.always.largehouse01windows = "largehouse01_windows";
	locations[n].models.always.largehouse01windows.tech = "LocationWindows";
	locations[n].models.always.largehouse01windows.level = 65539;

	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.largehouse01rand= "largehouse01_rand";
	locations[n].models.day.charactersPatch = "largehouse01_patch";
	//Night
	locations[n].models.night.charactersPatch = "largehouse01_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Formosa";
	locations[n].reload.l1.emerge = "houseSp1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	
	locations[n].box1.QuestClosed = true;
	LAi_LocationFightDisable(&locations[n], true);
	
	
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Выход из города, Остров Формоза
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
	locations[n].id = "Formosa_ExitTown";
	locations[n].id.label = "ExitTown";
	locations[n].image = "loading\Gate" + rand(1) + ".tga";
	//Sound
	locations[n].type = "jungle";
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Jungles\TownExitW";
	locations[n].models.always.townExit = "townExitW";
	locations[n].models.always.townWalls = "townExitW_wood";
	
	locations[n].models.always.locators = "townExitW_locators";
		
	locations[n].models.always.grassPatch = "townExitW_grass";
	locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";
	
	locations[n].models.always.l1 = "plan1";
	locations[n].models.always.l1.level = 9;
	locations[n].models.always.l1.tech = "LocationModelBlend";
	locations[n].models.always.l2 = "plan2";
	locations[n].models.always.l2.level = 8;
	locations[n].models.always.l2.tech = "LocationModelBlend";
	locations[n].models.always.l3 = "plan3";
	locations[n].models.always.l3.level = 7;
	locations[n].models.always.l3.tech = "LocationModelBlend";	
	//Day
	locations[n].models.day.charactersPatch = "townExitW_patch";
	locations[n].models.day.fonars = "townExitW_fd";
	//Night
	locations[n].models.night.charactersPatch = "townExitW_patch";
	locations[n].models.night.fonars = "townExitW_fn";	
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload4";
	locations[n].reload.l1.go = "Formosa";
	locations[n].reload.l1.emerge = "gate_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Zeelanda";
	
	
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Улицы поселения Батавии, Остров Ява
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
	locations[n].id = "Batavia";
	locations[n].id.label = "Batavia";
	
	locations[n].filespath.models = "locations\Town_Batavia\Town\";
	locations[n].image = "loading\Town.tga";
	locations[n].citizens = true;
	locations[n].soldiers = true;
	locations[n].carrier = true;
	//Sound
	locations[n].type = "town";
	//Models
	//Always
	locations[n].models.always.town = "Martinique";
	locations[n].models.always.town.sea_reflection = 1;
	locations[n].models.always.L1 = "Martinique_signsA";
	locations[n].models.always.L2 = "Malta_doors";
	locations[n].models.always.L2.tech = "DLightModel";
	locations[n].models.always.seabed = "Martinique_sb";
	locations[n].models.always.locators = "Martinique_locators";
	locations[n].models.always.grassPatch = "Martinique_grass";
	
	locations[n].models.always.plan = "plan1";
	locations[n].models.always.plan.level = 9;

	//Fontain
	locations[n].models.always.Waterfall1 = "fontain1";
	locations[n].models.always.Waterfall1.uvslide.v0 = 0.5;
    locations[n].models.always.Waterfall1.uvslide.v1 = 0.0;
	locations[n].models.always.Waterfall1.tech = "LocationWaterFall";
	locations[n].models.always.Waterfall1.level = 50;
	
	locations[n].models.always.Waterfall2 = "fontain2";
	locations[n].models.always.Waterfall2.uvslide.v0 = 0.2;
    locations[n].models.always.Waterfall2.uvslide.v1 = 0.0;
	locations[n].models.always.Waterfall2.tech = "LocationWaterFall";
	locations[n].models.always.Waterfall2.level = 49;

	//WindMill Fan
	locations[n].models.always.MillFan = "MillFan";
	locations[n].models.always.MillFan.locator.group = "WindMill";
	locations[n].models.always.MillFan.locator.name ="Fan";	
	locations[n].models.always.MillFan.rotate.x = 0.0;
	locations[n].models.always.MillFan.rotate.y = 0.0;
	locations[n].models.always.MillFan.rotate.z = 0.2;

	//Day
	locations[n].models.day.fonar = "Martinique_fd";
	locations[n].models.day.charactersPatch = "Martinique_patch_day";
	locations[n].models.day.rinok = "Martinique_rinok";
	//Night
	locations[n].models.night.fonar = "Martinique_fn";
	locations[n].models.night.charactersPatch = "Martinique_patch_night";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	//Reload map
	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "Batavia_townhall";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "Residence";
	locations[n].reload.l3.close_for_night = 1;
	
	locations[n].reload.l6.name = "reload6_back";
	locations[n].reload.l6.go = "Batavia_store";
	locations[n].reload.l6.emerge = "reload1";
	locations[n].reload.l6.autoreload = "0";
	locations[n].reload.l6.label = "Store";
	locations[n].reload.l6.close_for_night = 1;
	
	locations[n].reload.l11.name = "houseF3";
	locations[n].reload.l11.go = "Batavia_houseF3";
	locations[n].reload.l11.emerge = "reload1";
	locations[n].reload.l11.autoreload = "0";
	locations[n].reload.l11.label = "House";
	locations[n].reload.l11.close_for_night = 1;
	
	locations[n].reload.gate1.name = "gate_back";
	locations[n].reload.gate1.go = "Batavia_Plantation";
	locations[n].reload.gate1.emerge = "reload1";
	locations[n].reload.gate1.autoreload = "0";
	locations[n].reload.gate1.label = "Plantation";
	
	LAi_LocationFightDisable(&locations[n], true);
	
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Магазин, Батавия
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
	locations[n].id = "Batavia_store";
	locations[n].id.label = "Store";
	locations[n].filespath.models = "locations\inside\Store01\";
	locations[n].image = "loading\inside\shop.tga";
	//Town sack
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	//Models
	//Always
	locations[n].models.always.locators = "Store01_locators";
	locations[n].models.always.store = "Store01";
	locations[n].models.always.store.level = 65538;
	locations[n].models.always.window = "Store01_window";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;
	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "Store01_patch";
	//Night
	locations[n].models.night.charactersPatch = "Store01_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Batavia";
	locations[n].reload.l1.emerge = "reload6";
	locations[n].reload.l1.autoreload = "0";
    locations[n].reload.l1.label = "Street";
	LAi_LocationFightDisable(&locations[n], true);
	
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Резиденция, Батавия
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
	locations[n].id = "Batavia_townhall";
	locations[n].id.label = "Townhall";
	locations[n].filespath.models = "locations\inside\Residence01";
	locations[n].image = "loading\inside\residence.tga";
	//Town sack
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	//Models
	//Always
	locations[n].models.always.locators = "Residence01_locators";
	locations[n].models.always.l1 = "Residence01";
	locations[n].models.always.l1.level = 65538;
	locations[n].models.always.window = "residence01_window";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;	
	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "Residence01_patch";
	//Night
	locations[n].models.night.charactersPatch = "Residence01_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map

	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Batavia";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "0";
    locations[n].reload.l1.label = "Street";

	locations[n].reload.l3.name = "reload3";
	locations[n].reload.l3.go = "Batavia_townhallRoom";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "Room";
	
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Кабинет в резиденции, Батавия
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
	locations[n].id = "Batavia_townhallRoom";
	locations[n].id.label = "Room";
	locations[n].image = "loading\inside\BigHouse02.tga";
	//Town sack
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\BigHouse02\";
	locations[n].models.always.models = "BigHouse02";
	locations[n].models.always.models.level = 65538;
	locations[n].models.always.boxes = "BigHouse02_boxes";
	locations[n].models.always.boxes.level = 65539;
	locations[n].models.always.window = "BigHouse02_windows";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65540;

	locations[n].models.always.back = "..\inside_back";
	//Day
	locations[n].models.day.charactersPatch = "BigHouse02_patch";
	locations[n].models.day.locators = "BigHouse02_PrLocators";
	//Night
	locations[n].models.night.charactersPatch = "BigHouse02_patch";
	locations[n].models.night.locators = "BigHouse02_PrNlocators";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Batavia_townhall";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Townhall";
	
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Дом любовницы Димена, Батавия
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
	locations[n].id = "Batavia_houseF3";
	locations[n].filespath.models = "locations\inside\CobHouse";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\CobHouse.tga";
	//Town sack
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	//Models
	//Always
	locations[n].models.always.tavern = "CobHouse";
	locations[n].models.always.tavern.level = 65538;
	locations[n].models.always.window = "CobHouse_window";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;
	locations[n].models.day.locators = "CobHouse_locators";
	locations[n].models.night.locators = "CobHouse_Nlocators";

	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "CobHouse_patch";
	//Night
	locations[n].models.night.charactersPatch = "CobHouse_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Batavia";
	locations[n].reload.l1.emerge = "houseF3";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	LAi_LocationFightDisable(&locations[n], true);
	
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Плантация, Батавия
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
	locations[n].id = "Batavia_Plantation";
	locations[n].id.label = "Plantation";
	locations[n].image = "loading\jonny_load\quest\BarbadosPlantation_(Caiman).tga";
	//Town sack
	locations[n].citizens = true;    //homo жители
	locations[n].soldiers = true;    //homo солдаты
	locations[n].carrier = true;
	//Sound
	locations[n].type = "town";
	//Models
	//Always
	locations[n].filespath.models = "locations\BarbadosPlantation";
	locations[n].models.always.BarbadosPlantation = "BarbadosPlantation";
	locations[n].models.always.reflect = "BarbadosPlantation_reflect";
	locations[n].models.always.reflect.sea_reflection = 1;
	locations[n].models.always.gate = "BarbadosPlantation_gateopen";
	locations[n].models.always.locators = "BarbadosPlantation_locators";
	locations[n].models.always.grassPatch = "BarbadosPlantation_grass";
	locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";
	locations[n].models.always.Waterfall = "waterfall";
	locations[n].models.always.Waterfall.uvslide.v0 = 0.3;
    locations[n].models.always.Waterfall.uvslide.v1 = 0.0;
	locations[n].models.always.Waterfall.tech = "LocationWaterFall";
	locations[n].models.always.Waterfall.level = 99949;
	locations[n].models.always.plan1 = "plan1";
	locations[n].models.always.plan1.level = 9;
	locations[n].models.always.plan2 = "plan2";
	locations[n].models.always.plan2.level = 8;
	locations[n].models.always.plan3 = "plan3";
	locations[n].models.always.plan3.level = 7;
	locations[n].models.always.plan4 = "plan4";
	locations[n].models.always.plan4.level = 6;
	//Day
	locations[n].models.day.charactersPatch = "BarbadosPlantation_patchopen";
	locations[n].models.day.fonar = "BarbadosPlantation_fd";
	//Night
	locations[n].models.night.charactersPatch = "BarbadosPlantation_patchopen";
	locations[n].models.night.fonar = "BarbadosPlantation_fn";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Batavia";
	locations[n].reload.l1.emerge = "gate_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2;

    locations[n].locators_radius.quest.detector1 = 5.0; //homo
    
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Улицы поселения Капстервиля, квестовый для Лонгвея
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
	locations[n].id = "Kapstervil";
	locations[n].id.label = "Charles";

	locations[n].filespath.models = "locations\Town_Nevis\Town\";

	locations[n].image = "loading\Town.tga";
	//Sound
	locations[n].type = "town";
	//Models
	//Always
	locations[n].models.always.town = "Nevis";
	locations[n].models.always.town.sea_reflection = 1;
	locations[n].models.always.l1 = "Nevis_signsA";
	locations[n].models.always.locators = "Nevis_locators";
	locations[n].models.always.grassPatch = "Nevis_grass";
	locations[n].models.always.seabed = "Nevis_sb";
	locations[n].models.always.plan.level = 9;

	//WindMill Fan
	locations[n].models.always.MillFan = "MillFan";
	locations[n].models.always.MillFan.locator.group = "WindMill";
	locations[n].models.always.MillFan.locator.name ="Fan";	
	locations[n].models.always.MillFan.rotate.x = 0.0;
	locations[n].models.always.MillFan.rotate.y = 0.0;
	locations[n].models.always.MillFan.rotate.z = 0.3;

	//Day
	locations[n].models.day.fonar = "Nevis_fd";
	locations[n].models.day.charactersPatch = "Nevis_patch_day";
	locations[n].models.day.rinok = "Nevis_rinok";

	//Night
	locations[n].models.night.fonar = "Nevis_fn";
	locations[n].models.night.charactersPatch = "Nevis_patch_night";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	//Reload map

	locations[n].reload.l7.name = "reload7_back";
	locations[n].reload.l7.go = "Kapstervil_church";
	locations[n].reload.l7.emerge = "reload1";
	locations[n].reload.l7.autoreload = "0";
	locations[n].reload.l7.label = "Church";
	
	locations[n].reload.gate.name = "gate_back";
	locations[n].reload.gate.go = "Kapstervil_ExitTown";
	locations[n].reload.gate.emerge = "reload1";
	locations[n].reload.gate.autoreload = "0";
	locations[n].reload.gate.label = "ExitTown";
	locations[n].locators_radius.reload.gate_back = 2.0;
	
	locations[n].reload.l4.name = "reload4_back";
	locations[n].reload.l4.go = "Kapstervil_tavern";
	locations[n].reload.l4.emerge = "reload1";
	locations[n].reload.l4.autoreload = "0";
	locations[n].reload.l4.label = "Tavern";
	
	locations[n].reload.l6.name = "reload6_back";
	locations[n].reload.l6.go = "Kapstervil_store";
	locations[n].reload.l6.emerge = "reload1";
	locations[n].reload.l6.autoreload = "0";
	locations[n].reload.l6.label = "Store";
	locations[n].reload.l6.close_for_night = 1;
	
	LAi_LocationFightDisable(&locations[n], true);
	
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ЦЕРКОВЬ Капстервиля, квестовый для Лонгвея
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
	locations[n].id = "Kapstervil_church";
	locations[n].id.label = "Church";
	locations[n].filespath.models = "locations\inside\Church01";
	locations[n].image = "loading\inside\church.tga";
	//Town sack
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "church";
	//Models
	//Always
	locations[n].models.always.locators = "Church01_locators";
	locations[n].models.always.tavern = "Church01";
	locations[n].models.always.tavern.level = 65538;
	locations[n].models.always.window = "Church01_window";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;
	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "Church01_patch";
	//Night
	locations[n].models.night.charactersPatch = "Church01_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Kapstervil";
	locations[n].reload.l1.emerge = "reload7";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	LAi_LocationFightDisable(&locations[n], true);
	
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ТАВЕРНА Капстервиля, квестовый для Лонгвея
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
	locations[n].id = "Kapstervil_tavern";
	locations[n].id.label = "Tavern";
	locations[n].filespath.models = "locations\inside\tavern08\";
	locations[n].image = "loading\inside\tavern.tga";
	locations[n].habitues = 1;
	//Town sack
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "tavern";
	//Models
	locations[n].models.always.tavern = "Tavern08";
	locations[n].models.always.tavern.level = 65538;
	locations[n].models.always.locators = "Tavern08_locators";
	locations[n].models.always.window = "tavern08_window";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;
	locations[n].models.always.back = "..\inside_back3";
	locations[n].models.always.window.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "Tavern08_patch";
	//Night
	locations[n].models.night.charactersPatch = "Tavern08_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Kapstervil";
	locations[n].reload.l1.emerge = "reload4";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	LAi_LocationFightDisable(&locations[n], true);
	
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// МАГАЗИН Капстервиля, квестовый для Лонгвея
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
	locations[n].id = "Kapstervil_store";
	locations[n].id.label = "Store";
	locations[n].filespath.models = "locations\inside\Store05\";
	locations[n].image = "loading\inside\shop.tga";
	//Town sack
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "shop";
	//Models
	//Always
	locations[n].models.always.locators = "Store05_locators";
	locations[n].models.always.store = "Store05";
	locations[n].models.always.store.level = 65538;
	locations[n].models.always.window = "Store05_window";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;
	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "Store05_patch";
	//Night
	locations[n].models.night.charactersPatch = "Store05_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Kapstervil";
	locations[n].reload.l1.emerge = "reload6";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	locations[n].locators_radius.camdetector.camera1 = 5;
	LAi_LocationFightDisable(&locations[n], true);
	
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Городские ворота Капстервиля, квестовый для Лонгвея
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
	locations[n].id = "Kapstervil_ExitTown";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(3) + ".tga";
	//Sound
	locations[n].type = "jungle";
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Jungles\Jungle5";
	locations[n].models.always.jungle = "jungle5";	
	locations[n].models.always.locators = "jungle5_locators";		
	locations[n].models.always.grassPatch = "jungle5_grass";
	locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";	
	locations[n].models.always.l1 = "plan1";
	locations[n].models.always.l1.level = 9;
	locations[n].models.always.l1.tech = "LocationModelBlend";
	locations[n].models.always.l2 = "plan2";
	locations[n].models.always.l2.level = 8;
	locations[n].models.always.l2.tech = "LocationModelBlend";
	locations[n].models.always.l3 = "plan3";
	locations[n].models.always.l3.level = 7;
	locations[n].models.always.l3.tech = "LocationModelBlend";	
	//Day
	locations[n].models.day.charactersPatch = "jungle5_patch";
	//Night
	locations[n].models.night.charactersPatch = "jungle5_patch";	
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Kapstervil";
	locations[n].reload.l1.emerge = "gate_back";
	locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Charles";
	locations[n].locators_radius.reload.reload1_back = 2.0;
	
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Джунгли Капстервиля, квестовый для Лонгвея
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
	locations[n].id = "Kapstervil_Jungle";
	locations[n].id.label = "Jungle";
	locations[n].image = "loading\outside\jungle_" + rand(3) + ".tga";
	//Sound
	locations[n].type = "jungle";
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Jungles\Jungle6";
	locations[n].models.always.jungle = "jungle6";	
	locations[n].models.always.locators = "jungle6_locators";		
	locations[n].models.always.grassPatch = "jungle6_grass";
	locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";	
	locations[n].models.always.l1 = "plan1";
	locations[n].models.always.l1.level = 9;
	locations[n].models.always.l1.tech = "LocationModelBlend";
	locations[n].models.always.l2 = "plan2";
	locations[n].models.always.l2.level = 8;
	locations[n].models.always.l2.tech = "LocationModelBlend";
	locations[n].models.always.l3 = "plan3";
	locations[n].models.always.l3.level = 7;
	locations[n].models.always.l3.tech = "LocationModelBlend";	
	//Day
	locations[n].models.day.charactersPatch = "jungle6_patch";
	//Night
	locations[n].models.night.charactersPatch = "jungle6_patch";	
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Грот Капстервиля, квестовый для Лонгвея
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
	locations[n].id = "Kapstervil_Grot";
	locations[n].id.label = "Grot";
    locations[n].image = "loading\inside\cave.tga";
	//Sound
	locations[n].type = "cave";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\grotto2";
	locations[n].models.always.grotto2 = "grotto2";
	locations[n].models.always.grotto2.sea_reflection = 1;
	locations[n].models.always.grotto2alpha = "grotto2_alpha";
	locations[n].models.always.grotto2alpha.tech = "LocationWindows";	
	locations[n].models.always.grotto2alpha.level = 65532;	
	locations[n].models.always.locators = "grotto2_locators";

	locations[n].locators_radius.item.duhi1 = 0.0;
	//Day
	locations[n].models.day.charactersPatch = "grotto2_patch";
	//Night
	locations[n].models.night.charactersPatch = "grotto2_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	locations[n].environment.weather.rain = false;
	//Reload map
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Элитный бордель
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
	locations[n].id = "Tortuga_brothelElite";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\BigHouseBack.tga";
	//Town sack
	locations[n].townsack = "Tortuga";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Tortuga";
 	locations[n].islandId = "Tortuga";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\brothelElite";
	locations[n].models.always.house = "brothelElite";
	locations[n].models.always.house.level = 65538;
	locations[n].models.always.window = "brothelElite_windows";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;

	locations[n].models.always.back = "..\inside_back3";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "brothelElite_patch";
	locations[n].models.day.locators = "brothelElite_locators";
	//Night
	locations[n].models.night.charactersPatch = "brothelElite_patch";
	locations[n].models.night.locators = "brothelElite_Nlocators";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload2";
	locations[n].reload.l1.go = "Tortuga_brothelElite_room2";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Townhall";
	locations[n].reload.l1.disable = 1;

	locations[n].reload.l2.name = "reload3";
	locations[n].reload.l2.go = "Tortuga_brothelElite_room1";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "BedRoom";
	locations[n].reload.l2.disable = 1;

	locations[n].reload.l3.name = "reload1";
	locations[n].reload.l3.go = "Tortuga_town";
	locations[n].reload.l3.emerge = "houseS4";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "Street";
	LAi_LocationFightDisable(&locations[n], true);
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Элитный бордель, верхняя комната
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
	locations[n].id = "Tortuga_brothelElite_room1";
	locations[n].id.label = "Bedroom";
	locations[n].image = "loading\inside\Bedroom.tga";
	locations[n].Bedroom = true; //различаем типы локаций в резиденции, надо т.к. id.label затирается
	//Town sack
	locations[n].townsack = "Tortuga";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Tortuga";
 	locations[n].islandId = "Tortuga";
	//Always
	locations[n].filespath.models = "locations\inside\brothelElite_room1";
	locations[n].models.always.bedRoom1 = "brothelElite_room1";
	locations[n].models.always.bedRoom1.level = 65538;
	locations[n].models.always.bedRoom1windows = "brothelElite_room1_windows";
	locations[n].models.always.bedRoom1windows.tech = "LocationWindows";
	locations[n].models.always.bedRoom1windows.level = 65539;
	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.locators = "brothelElite_room1_locators";
	locations[n].models.day.bedRoom1rand = "brothelElite_room1_rand";
	locations[n].models.day.charactersPatch = "brothelElite_room1_patch";
	//Night
	locations[n].models.night.locators = "brothelElite_room1_Nlocators";
	locations[n].models.night.charactersPatch = "brothelElite_room1_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Tortuga_brothelElite";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "House";
	LAi_LocationFightDisable(&locations[n], true);
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Элитный бордель, нижняя комната
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
	locations[n].id = "Tortuga_brothelElite_room2";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\BigHouse01.tga";
	//Town sack
	locations[n].townsack = "Tortuga";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Tortuga";
	locations[n].islandId = "Tortuga";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\brothelElite_room2";
	locations[n].models.always.model = "brothelElite_room2";
	locations[n].models.always.model.level = 65538;
	locations[n].models.day.locators = "brothelElite_room2_locators";
	locations[n].models.night.locators = "brothelElite_room2_Nlocators";
	locations[n].models.always.window = "brothelElite_room2_windows";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;

	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "brothelElite_room2_patch";
	//Night
	locations[n].models.night.charactersPatch = "brothelElite_room2_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Tortuga_brothelElite";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "House";
	LAi_LocationFightDisable(&locations[n], true);
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Пыточная Левассера
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
	locations[n].id = "Tortuga_Torture_room";
	locations[n].id.label = "Torture room";
	locations[n].image = "loading\Crypt_" + rand(1) + ".tga";
	//Town sack
	locations[n].townsack = "Tortuga";
	locations[n].lockWeather = "Inside";
	//Sound
	//locations[n].type = "Dungeon";
	locations[n].type = "alcove";
	locations[n].islandId = "Tortuga";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\Torture_room";
	locations[n].models.always.cryptbig = "Torture_room";
	locations[n].models.always.locators = "Torture_room_locators";
	//Day
	locations[n].models.day.charactersPatch = "Torture_room_patch";
	//Night
	locations[n].models.night.charactersPatch = "Torture_room_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].lockWeather = "Inside";
	locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Tortuga_Cave";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Crypt";
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Квестовые покои Марселины
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
	locations[n].id = "Tortuga_townhallBedroom";
	locations[n].id.label = "Bedroom";
	locations[n].image = "loading\inside\Bedroom.tga";
	locations[n].MustSetReloadBack = true;
	locations[n].Bedroom = true; //различаем типы локаций в резиденции, надо т.к. id.label затирается
	//Town sack
	locations[n].townsack = "Tortuga";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Tortuga";
 	locations[n].islandId = "Tortuga";
	//Always
	locations[n].filespath.models = "locations\inside\bedRoom1";
	locations[n].models.always.bedRoom1 = "bedRoom1";
	locations[n].models.always.bedRoom1.level = 65538;
	locations[n].models.always.bedRoom1windows = "mediumhouse01_windows";
	locations[n].models.always.bedRoom1windows.tech = "LocationWindows";
	locations[n].models.always.bedRoom1windows.level = 65539;
	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.locators = "bedRoom1_locators";
	locations[n].models.day.bedRoom1rand = "bedRoom1_rand";
	locations[n].models.day.charactersPatch = "bedRoom1_patch";
	//Night
	locations[n].models.night.locators = "bedRoom1_Nlocators";
	locations[n].models.night.charactersPatch = "bedRoom1_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Tortuga_townhallRoom";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Room";
	
	LAi_LocationFightDisable(&locations[n], true);
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Дом Анри Тибо
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
	locations[n].id = "PortPax_houseF1";
	locations[n].filespath.models = "locations\inside\mediumhouse09";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\mediumhouse10.tga";
	//Town sack
	locations[n].townsack = "PortPax";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "PortPax";
	locations[n].islandId = "Hispaniola";
	//Models
	//Always
	locations[n].models.always.house = "mediumhouse09";
	locations[n].models.always.house.level = 65538;
	locations[n].models.day.locators = "mediumhouse09_locators";
	locations[n].models.night.locators = "mediumhouse09_Nlocators";

	locations[n].models.always.mediumhouse09windows = "mediumhouse09_windows";
	locations[n].models.always.mediumhouse09windows.tech = "LocationWindows";
	locations[n].models.always.mediumhouse09windows.level = 65539;

	locations[n].models.always.back = "..\inside_back3";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.mediumhouse09rand= "mediumhouse09_rand";
	locations[n].models.day.charactersPatch = "mediumhouse09_patch";
	//Night
	locations[n].models.night.charactersPatch = "mediumhouse09_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";//в город
	locations[n].reload.l1.go = "PortPax_town";
	locations[n].reload.l1.emerge = "houseF1";
	locations[n].reload.l1.autoreload = "0";
    locations[n].reload.l1.label = "Street";
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Квестовый дом
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
	locations[n].id = "PortPax_houseS2";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\TwoFloorHouse.tga";
	//Town sack
	locations[n].townsack = "PortPax";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "PortPax";
	locations[n].islandId = "Hispaniola";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\TwoFloorHouse";
	locations[n].models.always.house = "TwoFloorHouse";
	locations[n].models.always.house.level = 65538;
	locations[n].models.day.locators = "TwoFloorHouse_locators";
	locations[n].models.night.locators = "TwoFloorHouse_Nlocators";
	locations[n].models.always.window = "TwoFloorHouse_windows";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;

	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.TwoFloorHouseRand= "TwoFloorHouse_rand";
	locations[n].models.day.charactersPatch = "TwoFloorHouse_patch";
	//Night
	locations[n].models.night.charactersPatch = "TwoFloorHouse_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "PortPax_town";
	locations[n].reload.l1.emerge = "houseS2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	locations[n].locators_radius.item.item2 = 0.9;
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Квестовый дом в Порт-Рояле
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
	locations[n].id = "PortRoyal_houseSp3";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\largehouse01.tga";
 	//Town sack
	locations[n].townsack = "PortRoyal";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
 	locations[n].islandId = "Jamaica";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\largehouse01";
	locations[n].models.always.largehouse01 = "largehouse01";
	locations[n].models.always.largehouse01.level = 65538;
	locations[n].models.day.locators = "largehouse01_locators";
	locations[n].models.night.locators = "largehouse01_Nlocators";

	Locations[n].models.always.largehouse01windows = "largehouse01_windows";
	Locations[n].models.always.largehouse01windows.tech = "LocationWindows";
	locations[n].models.always.largehouse01windows.level = 65539;

	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	Locations[n].models.day.largehouse01rand= "largehouse01_rand";
	locations[n].models.day.charactersPatch = "largehouse01_patch";
	//Night
	locations[n].models.night.charactersPatch = "largehouse01_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "PortRoyal_town";
	locations[n].reload.l1.emerge = "houseSp3";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "PortRoyal_houseSp3Room";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Room";
	
	LAi_LocationFightDisable(&locations[n], true);
	
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Комната в доме
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
	locations[n].id = "PortRoyal_houseSp3Room";
	locations[n].id.label = "Room";
	locations[n].image = "loading\inside\mediumhouse10.tga";
	//Town sack
	locations[n].townsack = "PortRoyal";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
 	locations[n].islandId = "Jamaica";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\mediumhouse05";
	locations[n].models.always.mediumhouse05 = "mediumhouse05";
	locations[n].models.always.mediumhouse05.level = 65538;
	locations[n].models.day.locators = "mediumhouse05_locators";
	locations[n].models.night.locators = "mediumhouse05_Nlocators";

	Locations[n].models.always.mediumhouse05windows = "mediumhouse05_windows";
	Locations[n].models.always.mediumhouse05windows.tech = "LocationWindows";
	locations[n].models.always.mediumhouse05windows.level = 65539;

	locations[n].models.always.back = "..\inside_back2";
	locations[n].models.always.back.level = 65529;
	//Day
	Locations[n].models.day.mediumhouse05rand= "mediumhouse05_rand";
	locations[n].models.day.charactersPatch = "mediumhouse05_patch";
	//Night
	locations[n].models.night.charactersPatch = "mediumhouse05_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "PortRoyal_houseSp3";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "House";
	
	//Обновления reload
	sld = &Locations[FindLocation("PortPax_town")];
	sld.reload.l31.name = "houseF1";
	sld.reload.l31.go = "PortPax_houseF1";
	sld.reload.l31.emerge = "reload1";
	sld.reload.l31.autoreload = "0";
	sld.reload.l31.label = "House";
	
	sld.reload.l32.name = "houseS2";
	sld.reload.l32.go = "PortPax_houseS2";
	sld.reload.l32.emerge = "reload1";
	sld.reload.l32.autoreload = "0";
	sld.reload.l32.label = "House";
	
	sld = &Locations[FindLocation("Tortuga_town")];
	sld.reload.l22.name = "houseS4";
	sld.reload.l22.go = "Tortuga_brothelElite";
	sld.reload.l22.emerge = "reload1";
	sld.reload.l22.autoreload = "0";
	sld.reload.l22.label = "House";
	sld.reload.l22.disable = 1;
	
	sld = &Locations[FindLocation("Tortuga_townhallRoom")];
	sld.reload.l2.name = "reload2";
	sld.reload.l2.go = "Tortuga_townhallBedroom";
	sld.reload.l2.emerge = "reload1";
	sld.reload.l2.autoreload = "0";
	sld.reload.l2.label = "Bedroom";
	
	sld = &Locations[FindLocation("PortRoyal_town")];
	sld.reload.l22.name = "houseSp3";
	sld.reload.l22.go = "PortRoyal_houseSp3";
	sld.reload.l22.emerge = "reload1";
	sld.reload.l22.autoreload = "0";
	sld.reload.l22.label = "House";
	
	n = FindLocation("Mayak2");
	locations[n].models.day.winday.tech = "LocationWindows";
	locations[n].models.day.winday.level = 66530;
	locations[n].models.night.winnight.tech = "LocationWindows";
	locations[n].models.night.winnight.level = 66530;
	
	n = FindLocation("Mayak11");
	//Always
	locations[n].filespath.models = "locations\Outside\Shores\Lighthouse2";
	Locations[n].models.always.lighthouse = "lighthouse2";
	locations[n].models.always.lighthouse.sea_reflection = 1;
	Locations[n].models.always.lighthouseSeabed = "lighthouse2_sb";
	Locations[n].models.always.locators = "lighthouse2_locators";
	
	Locations[n].models.always.dooropen = "lighthouse2_dooropen";
	Locations[n].models.always.dooropen.tech = "DLightModel";	
	
	Locations[n].models.always.windows = "lighthouse2_windows";
	Locations[n].models.always.windows.tech = "LocationWindows";
	Locations[n].models.always.windows.level = 66530;
		
	Locations[n].models.always.grassPatch = "lighthouse2_grass";
	Locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";
	
	Locations[n].models.always.l1 = "plan1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";		
	Locations[n].models.always.l2 = "plan3";
	Locations[n].models.always.l2.level = 7;
	Locations[n].models.always.l2.tech = "LocationModelBlend";		
	//Day
	locations[n].models.day.winday = "lighthouse2_winday";
	Locations[n].models.day.winday.tech = "LocationWindows";
	Locations[n].models.day.winday.level = 66530;
	locations[n].models.day.fonar = "lighthouse2_fd";
	locations[n].models.day.charactersPatch = "lighthouse2_patch";
	Locations[n].models.day.jumpPatch = "lighthouse2_jamp";
	
	locations[n].models.day.glassinday = "lighthouse2_glassinday";
	Locations[n].models.day.glassinday.tech = "LocationWindows";
	locations[n].models.day.glassinday.level = 66531;
	
	locations[n].models.day.glassonday = "lighthouse2_glassonday";
	Locations[n].models.day.glassonday.tech = "LocationWindows";
	locations[n].models.day.glassonday.level = 66532;
	//Night
	locations[n].models.night.volumeLight= "lighthouse2_volumeLight";
	locations[n].models.night.volumeLight.tech = "LighthouseLight";
	locations[n].models.night.volumeLight.level = 66529;	
	
	locations[n].models.night.fonar = "lighthouse2_fn";
	locations[n].models.night.winnight = "lighthouse2_winnight";
	locations[n].models.night.winnight.tech = "LocationWindows";
	locations[n].models.night.winnight.level = 66530;
	locations[n].models.night.charactersPatch = "lighthouse2_patch";	
	Locations[n].models.night.jumpPatch = "lighthouse2_jamp";
	
	locations[n].models.night.glassinnight = "lighthouse2_glassinnight";
	Locations[n].models.night.glassinnight.tech = "LocationWindows";
	locations[n].models.night.glassinnight.level = 66531;
	
	locations[n].models.night.glassonnight = "lighthouse2_glassonnight";
	Locations[n].models.night.glassonnight.tech = "LocationWindows";
	locations[n].models.night.glassonnight.level = 66532;
	
	locations[n].models.night.fonaronnight = "lighthouse2_fonaronnight";
	
	n = FindLocation("Mayak4");
	//Always
	locations[n].filespath.models = "locations\Outside\Shores\Lighthouse2";
	Locations[n].models.always.lighthouse = "lighthouse2";
	locations[n].models.always.lighthouse.sea_reflection = 1;
	Locations[n].models.always.lighthouseSeabed = "lighthouse2_sb";
	Locations[n].models.always.locators = "lighthouse2_locators";
	
	Locations[n].models.always.dooropen = "lighthouse2_dooropen";
	Locations[n].models.always.dooropen.tech = "DLightModel";	
	
	Locations[n].models.always.windows = "lighthouse2_windows";
	Locations[n].models.always.windows.tech = "LocationWindows";
	Locations[n].models.always.windows.level = 66530;
		
	Locations[n].models.always.grassPatch = "lighthouse2_grass";
	Locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";
	
	Locations[n].models.always.l1 = "plan1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";		
	Locations[n].models.always.l2 = "plan3";
	Locations[n].models.always.l2.level = 7;
	Locations[n].models.always.l2.tech = "LocationModelBlend";		
	//Day
	locations[n].models.day.winday = "lighthouse2_winday";
	Locations[n].models.day.winday.tech = "LocationWindows";
	Locations[n].models.day.winday.level = 66530;
	locations[n].models.day.fonar = "lighthouse2_fd";
	locations[n].models.day.charactersPatch = "lighthouse2_patch";
	Locations[n].models.day.jumpPatch = "lighthouse2_jamp";
	
	locations[n].models.day.glassinday = "lighthouse2_glassinday";
	Locations[n].models.day.glassinday.tech = "LocationWindows";
	locations[n].models.day.glassinday.level = 66531;
	
	locations[n].models.day.glassonday = "lighthouse2_glassonday";
	Locations[n].models.day.glassonday.tech = "LocationWindows";
	locations[n].models.day.glassonday.level = 66532;
	//Night
	locations[n].models.night.volumeLight= "lighthouse2_volumeLight";
	locations[n].models.night.volumeLight.tech = "LighthouseLight";
	locations[n].models.night.volumeLight.level = 66529;	
	
	locations[n].models.night.fonar = "lighthouse2_fn";
	locations[n].models.night.winnight = "lighthouse2_winnight";
	locations[n].models.night.winnight.tech = "LocationWindows";
	locations[n].models.night.winnight.level = 66530;
	locations[n].models.night.charactersPatch = "lighthouse2_patch";	
	Locations[n].models.night.jumpPatch = "lighthouse2_jamp";
	
	locations[n].models.night.glassinnight = "lighthouse2_glassinnight";
	Locations[n].models.night.glassinnight.tech = "LocationWindows";
	locations[n].models.night.glassinnight.level = 66531;
	
	locations[n].models.night.glassonnight = "lighthouse2_glassonnight";
	Locations[n].models.night.glassonnight.tech = "LocationWindows";
	locations[n].models.night.glassonnight.level = 66532;
	
	locations[n].models.night.fonaronnight = "lighthouse2_fonaronnight";
	
	n = FindLocation("Mayak10");
	locations[n].models.day.winday.tech = "LocationWindows";
	locations[n].models.day.winday.level = 66530;
	locations[n].models.night.winnight.tech = "LocationWindows";
	locations[n].models.night.winnight.level = 66530;
	
	n = FindLocation("Mayak3");
	locations[n].models.day.winday.tech = "LocationWindows";
	locations[n].models.day.winday.level = 66530;
	locations[n].models.night.winnight.tech = "LocationWindows";
	locations[n].models.night.winnight.level = 66530;
	
	n = FindLocation("Mayak7");
	locations[n].models.day.winday.tech = "LocationWindows";
	locations[n].models.day.winday.level = 66530;
	locations[n].models.night.winnight.tech = "LocationWindows";
	locations[n].models.night.winnight.level = 66530;
	
	n = FindLocation("Mayak9");
	//Always
	locations[n].filespath.models = "locations\Outside\Shores\Lighthouse2";
	Locations[n].models.always.lighthouse = "lighthouse2";
	locations[n].models.always.lighthouse.sea_reflection = 1;
	Locations[n].models.always.lighthouseSeabed = "lighthouse2_sb";
	Locations[n].models.always.locators = "lighthouse2_locators";
	
	Locations[n].models.always.dooropen = "lighthouse2_dooropen";
	Locations[n].models.always.dooropen.tech = "DLightModel";	
	
	Locations[n].models.always.windows = "lighthouse2_windows";
	Locations[n].models.always.windows.tech = "LocationWindows";
	Locations[n].models.always.windows.level = 66530;
		
	Locations[n].models.always.grassPatch = "lighthouse2_grass";
	Locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";
	
	Locations[n].models.always.l1 = "plan1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";		
	Locations[n].models.always.l2 = "plan3";
	Locations[n].models.always.l2.level = 7;
	Locations[n].models.always.l2.tech = "LocationModelBlend";		
	//Day
	locations[n].models.day.winday = "lighthouse2_winday";
	Locations[n].models.day.winday.tech = "LocationWindows";
	Locations[n].models.day.winday.level = 66530;
	locations[n].models.day.fonar = "lighthouse2_fd";
	locations[n].models.day.charactersPatch = "lighthouse2_patch";
	Locations[n].models.day.jumpPatch = "lighthouse2_jamp";
	
	locations[n].models.day.glassinday = "lighthouse2_glassinday";
	Locations[n].models.day.glassinday.tech = "LocationWindows";
	locations[n].models.day.glassinday.level = 66531;
	
	locations[n].models.day.glassonday = "lighthouse2_glassonday";
	Locations[n].models.day.glassonday.tech = "LocationWindows";
	locations[n].models.day.glassonday.level = 66532;
	//Night
	locations[n].models.night.volumeLight= "lighthouse2_volumeLight";
	locations[n].models.night.volumeLight.tech = "LighthouseLight";
	locations[n].models.night.volumeLight.level = 66529;	
	
	locations[n].models.night.fonar = "lighthouse2_fn";
	locations[n].models.night.winnight = "lighthouse2_winnight";
	locations[n].models.night.winnight.tech = "LocationWindows";
	locations[n].models.night.winnight.level = 66530;
	locations[n].models.night.charactersPatch = "lighthouse2_patch";	
	Locations[n].models.night.jumpPatch = "lighthouse2_jamp";
	
	locations[n].models.night.glassinnight = "lighthouse2_glassinnight";
	Locations[n].models.night.glassinnight.tech = "LocationWindows";
	locations[n].models.night.glassinnight.level = 66531;
	
	locations[n].models.night.glassonnight = "lighthouse2_glassonnight";
	Locations[n].models.night.glassonnight.tech = "LocationWindows";
	locations[n].models.night.glassonnight.level = 66532;
	
	locations[n].models.night.fonaronnight = "lighthouse2_fonaronnight";
	
	n = FindLocation("Mayak8");
	locations[n].models.day.winday.tech = "LocationWindows";
	locations[n].models.day.winday.level = 66530;
	locations[n].models.night.winnight.tech = "LocationWindows";
	locations[n].models.night.winnight.level = 66530;
	
	n = FindLocation("Mayak6");
	locations[n].models.day.winday.tech = "LocationWindows";
	locations[n].models.day.winday.level = 66530;
	locations[n].models.night.winnight.tech = "LocationWindows";
	locations[n].models.night.winnight.level = 66530;
	
	n = FindLocation("Mayak1");
	locations[n].models.day.winday.tech = "LocationWindows";
	locations[n].models.day.winday.level = 66530;
	locations[n].models.night.winnight.tech = "LocationWindows";
	locations[n].models.night.winnight.level = 66530;
	loadedLocation = &locations[0];
	//ClearRef(loadedLocation);
}