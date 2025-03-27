void ApplyMigration(ref migrationState) {
	
	ref loc;
	int n;
	
	// Изменяем Сен Пьер
	n = FindLocation("FortFrance_town");
	
	locations[n].reload.l24.name = "houseS2";
	locations[n].reload.l24.go = "FortFrance_houseS2";
	locations[n].reload.l24.emerge = "reload1";
	locations[n].reload.l24.autoreload = "0";
	locations[n].reload.l24.label = "House";
	locations[n].reload.l24.disable = false;
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Дом с винным погребом
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	ExpandLocationsArray();
	
	n = MAX_LOCATIONS - 1;
	
	locations[n].id = "FortFrance_houseS2";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\mediumhouse10.tga";
	locations[n].MustSetReloadBack = true;
 	//Town sack
	locations[n].townsack = "FortFrance";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "FortFrance";
 	locations[n].islandId = "Martinique";
	//Models
	locations[n].filespath.models = "locations\inside\FlamHouse";
	//Always
	locations[n].models.always.tavern = "FlamHouse";
	locations[n].models.always.tavern.level = 65538;
	locations[n].models.always.window = "FlamHouse_window";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;
	locations[n].models.day.locators = "FlamHouse_locators";
	locations[n].models.night.locators = "FlamHouse_Nlocators";

	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "FlamHouse_patch";
	//Night
	locations[n].models.night.charactersPatch = "FlamHouse_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "FortFrance_town";
	locations[n].reload.l1.emerge = "houseS2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "house";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "FortFrance_WineCellar";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Wine Cellar";

	locations[n].reload.l3.name = "reload4";
	locations[n].reload.l3.go = "CommonRoom_MH3";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "Room";
	
	locations[n].reload.l4.name = "reload3";
	locations[n].reload.l4.go = "CommonRoom_MH4";
	locations[n].reload.l4.emerge = "reload1";
	locations[n].reload.l4.autoreload = "0";
	locations[n].reload.l4.label = "Room";
	
	// Изменяем Виллемстад
	n = FindLocation("Villemstad_town");
	
	locations[n].reload.l23.name = "houseS2";
	locations[n].reload.l23.go = "Villemstad_houseS2";
	locations[n].reload.l23.emerge = "reload1";
	locations[n].reload.l23.autoreload = "0";
	locations[n].reload.l23.label = "House";
	locations[n].reload.l23.disable = false;
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Дом с винным погребом
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	ExpandLocationsArray();
	
	n = MAX_LOCATIONS - 1;
	
	locations[n].id = "Villemstad_houseS2";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\mediumhouse10.tga";
	locations[n].MustSetReloadBack = true;
 	//Town sack
	locations[n].townsack = "Villemstad";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Villemstad";
 	locations[n].islandId = "Curacao";
	//Models
	locations[n].filespath.models = "locations\inside\FlamHouse";
	//Always
	locations[n].models.always.tavern = "FlamHouse";
	locations[n].models.always.tavern.level = 65538;
	locations[n].models.always.window = "FlamHouse_window";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;
	locations[n].models.day.locators = "FlamHouse_locators";
	locations[n].models.night.locators = "FlamHouse_Nlocators";

	locations[n].models.always.back = "..\inside_back";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "FlamHouse_patch";
	//Night
	locations[n].models.night.charactersPatch = "FlamHouse_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Villemstad_town";
	locations[n].reload.l1.emerge = "houseS2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "house";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "Villemstad_WineCellar";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Wine Cellar";

	locations[n].reload.l3.name = "reload4";
	locations[n].reload.l3.go = "CommonRoom_MH3";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "Room";
	
	locations[n].reload.l4.name = "reload3";
	locations[n].reload.l4.go = "CommonRoom_MH4";
	locations[n].reload.l4.emerge = "reload1";
	locations[n].reload.l4.autoreload = "0";
	locations[n].reload.l4.label = "Room";
}
