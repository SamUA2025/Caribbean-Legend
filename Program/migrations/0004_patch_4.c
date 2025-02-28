

void ApplyMigration(ref migrationState)
{
	// продлить таймер
	SetFunctionTimerCondition("TorrentEddy", 8, 0, 0, false);
	
	ref loc = &locations[FindLocation("Villemstad_Shipyard")];
	loc.reload.l2.go = "Villemstad_Packhouse";
	loc.reload.l2.label = "packhouse";
	
	loc = &locations[FindLocation("Villemstad_town")];
	loc.locators_radius.reload.reload33 = 0.0;
	
	MAX_LOCATIONS++;
	SetArraySize(&locations, MAX_LOCATIONS);
	
	int n = MAX_LOCATIONS - 1;
	
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
	
	locations[n].id = "Villemstad_Packhouse";
	locations[n].id.label = "packhouse";
	locations[n].image = "loading\inside\sklad.tga";
	//Town sack
	locations[n].townsack = "Villemstad";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Villemstad";
	locations[n].islandId = "Curacao";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\sklad03";
	locations[n].models.always.locators = "sklad03_locators";
	locations[n].models.always.modelSklad = "sklad03";
	locations[n].models.always.modelSklad.level = 65538;
	
	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "sklad03_patch";
	//Night
	locations[n].models.night.charactersPatch = "sklad03_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Villemstad_Shipyard";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "shipyard";
	
	if(CheckAttribute(pchar, "questTemp.Sharlie.Ship"))
	{
		ref sld = characterFromId("Benua");
		if(sld.dialog.currentnode == "Benua_meeting")
			sld.dialog.currentnode = "First time";
	}
	
	// init sails color
	SailsColors[0].icon = "interfaces\sails\blue.tga";
	SailsColors[0].texture = "parus_blue";
	SailsColors[0].name  = "White";
	SailsColors[0].color = argb(255, 255, 255, 255);

	SailsColors[1].icon = "interfaces\sails\green.tga";
	SailsColors[1].texture = "parus_green";
	SailsColors[1].name  = "Red";
	SailsColors[1].color = argb(255, 255, 60, 60);

	SailsColors[2].icon = "interfaces\sails\red.tga";
	SailsColors[2].texture = "parus_red";
	SailsColors[2].name  = "Orange";
	SailsColors[2].color = argb(255, 255, 128, 60);

	SailsColors[3].icon = "interfaces\sails\yellow.tga";
	SailsColors[3].texture = "parus_yellow";
	SailsColors[3].name  = "Yellow";
	SailsColors[3].color = argb(255, 255, 255, 60);

	SailsColors[4].icon = "interfaces\sails\lilo.tga";
	SailsColors[4].texture = "parus_lilo";
	SailsColors[4].name  = "Green";
	SailsColors[4].color = argb(255, 60, 255, 60);

	SailsColors[5].icon = "interfaces\sails\gray.tga";
	SailsColors[5].texture = "parus_gray";
	SailsColors[5].name  = "LightBlue";
	SailsColors[5].color = argb(255, 128, 190, 255);

	SailsColors[6].icon = "interfaces\sails\white.tga";
	SailsColors[6].texture = "parus_white";
	SailsColors[6].name  = "DarkBlue";
	SailsColors[6].color = argb(255, 60, 60, 255);

	SailsColors[7].icon = "interfaces\sails\black.tga";
	SailsColors[7].texture = "parus_black";
	SailsColors[7].name  = "Purple";
	SailsColors[7].color = argb(255, 255, 60, 255);
	
	SailsColors[8].icon = "interfaces\sails\black.tga";
	SailsColors[8].texture = "parus_black";
	SailsColors[8].name  = "Black";
	SailsColors[8].color = argb(255, 60, 60, 60);
}