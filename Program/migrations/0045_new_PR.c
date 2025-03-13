void ApplyMigration(ref migrationState) {
	
	ref loc;
	int n;
	
	// Изменяем Порт Ройал
	n = FindLocation("PortRoyal_town");
	
	locations[n].models.always.Waterfall2.uvslide.v0 = 0.1;
	if(CheckAttribute(&locations[n],"models.always.L2")) DeleteAttribute(&locations[n],"models.always.L2");
	locations[n].models.day.gates = "PortRoyal_gates_day";
	locations[n].models.day.charactersPatch = "PortRoyal_patch_day";
	locations[n].models.day.jumpPatch = "PortRoyal_jump_patch";
	locations[n].models.night.gates = "PortRoyal_gates_night";
	locations[n].models.night.jumpPatch = "PortRoyal_jump_patch";
	
	if(CheckAttribute(&locations[n],"reload.l20")) DeleteAttribute(&locations[n],"reload.l20");
	if(CheckAttribute(&locations[n],"reload.l21")) DeleteAttribute(&locations[n],"reload.l21");
	if(CheckAttribute(&locations[n],"reload.l22")) DeleteAttribute(&locations[n],"reload.l22");
	if(CheckAttribute(&locations[n],"reload.l23")) DeleteAttribute(&locations[n],"reload.l23");
	
	locations[n].reload.l13.name = "houseSp3";
	locations[n].reload.l13.go = "PortRoyal_houseSp3";
	locations[n].reload.l13.emerge = "reload1";
	locations[n].reload.l13.autoreload = "0";
	locations[n].reload.l13.label = "House";
	
	locations[n].reload.l14.name = "houseS1";
	locations[n].reload.l14.go = "PortRoyal_houseS1";
	locations[n].reload.l14.emerge = "reload1";
	locations[n].reload.l14.autoreload = "0";
	locations[n].reload.l14.label = "House";

	locations[n].reload.l15.name = "houseBH1";
	locations[n].reload.l15.go = "PortRoyal_houseBH1";
	locations[n].reload.l15.emerge = "reload2";
	locations[n].reload.l15.autoreload = "0";
	locations[n].reload.l15.label = "House";

	locations[n].reload.l16.name = "houseBH2";
	locations[n].reload.l16.go = "PortRoyal_houseBH1";
	locations[n].reload.l16.emerge = "reload1";
	locations[n].reload.l16.autoreload = "0";
	locations[n].reload.l16.label = "House";

	locations[n].reload.l18.name = "houseK3";
	locations[n].reload.l18.go = "PortRoyal_BigHouse6";
	locations[n].reload.l18.emerge = "reload1";
	locations[n].reload.l18.autoreload = "0";
	locations[n].reload.l18.label = "House";

	locations[n].reload.l19.name = "houseK2";
	locations[n].reload.l19.go = "PortRoyal_BigHouse6";
	locations[n].reload.l19.emerge = "reload2";
	locations[n].reload.l19.autoreload = "0";
	locations[n].reload.l19.label = "House";
	locations[n].reload.l19.disable = 1; //закроем
	
	locations[n].reload.l21.name = "houseSk4"; // винный погреб
	locations[n].reload.l21.go = "PortRoyal_WineCellar"; 
	locations[n].reload.l21.emerge = "reload1";
	locations[n].reload.l21.autoreload = "0";
	locations[n].reload.l21.label = "Wine Cellar";
	
	locations[n].reload.l30.name = "houseF1";
	locations[n].reload.l30.go = "CommonRoom_MH";
	locations[n].reload.l30.emerge = "reload1";
	locations[n].reload.l30.autoreload = "0";
	locations[n].reload.l30.label = "House";
	
	locations[n].reload.l31.name = "houseSp2";
	locations[n].reload.l31.go = "CommonStoneHouse";
	locations[n].reload.l31.emerge = "reload1";
	locations[n].reload.l31.autoreload = "0";
	locations[n].reload.l31.label = "House";

	locations[n].reload.l32.name = "houseH1";
	locations[n].reload.l32.go = "CommonRoom_MH3";
	locations[n].reload.l32.emerge = "reload1";
	locations[n].reload.l32.autoreload = "0";
	locations[n].reload.l32.label = "House";

	locations[n].reload.l33.name = "houseK1";
	locations[n].reload.l33.go = "CommonCobHouse";
	locations[n].reload.l33.emerge = "reload1";
	locations[n].reload.l33.autoreload = "0";
	locations[n].reload.l33.label = "House";

	locations[n].reload.l34.name = "houseH2";
	locations[n].reload.l34.go = "CommonRoom_MH9";
	locations[n].reload.l34.emerge = "reload1";
	locations[n].reload.l34.autoreload = "0";
	locations[n].reload.l34.label = "House";
	
	// Богатая резиденция
	ExpandLocationsArray();
	
	n = MAX_LOCATIONS - 1;
	
	locations[n].id = "PortRoyal_houseS1"; // c переходом в малую резиденцию
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\mediumhouse10.tga";
 	//Town sack
	locations[n].townsack = "PortRoyal";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "PortRoyal";
 	locations[n].islandId = "Jamaica";
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
	locations[n].reload.l1.go = "PortRoyal_town";
	locations[n].reload.l1.emerge = "houseS1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "CommonBedroom";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Room";
	
	
	// Большой дом с двумя входами
	ExpandLocationsArray();
	
	n = MAX_LOCATIONS - 1;
	
	locations[n].id = "PortRoyal_houseBH1";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\mediumhouse10.tga";
	locations[n].MustSetReloadBack = true;
 	//Town sack
	locations[n].townsack = "PortRoyal";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "PortRoyal";
 	locations[n].islandId = "Jamaica";
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
	locations[n].reload.l1.go = "PortRoyal_town";
	locations[n].reload.l1.emerge = "houseBH2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "house";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "PortRoyal_town";
	locations[n].reload.l2.emerge = "houseBH1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "house";

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
	
	
	// Дом с 3 дверьми
	ExpandLocationsArray();
	
	n = MAX_LOCATIONS - 1;
	
	locations[n].id = "PortRoyal_BigHouse6";
 	locations[n].id.label = "House";
	locations[n].image = "loading\inside\mediumhouse10.tga";
 	//Town sack
	locations[n].townsack = "PortRoyal";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "PortRoyal";
 	locations[n].islandId = "Jamaica";
	//Models
	locations[n].filespath.models = "locations\inside\BigHouse06\";
	//Always
	locations[n].models.always.house = "BigHouse06";
	locations[n].models.always.house.level = 65538;
	locations[n].models.always.window = "BigHouse06_windows";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;
	locations[n].models.always.locators = "BigHouse06_locators";

	locations[n].models.always.back = "..\inside_back3";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "BigHouse06_patch";
	//Night
	locations[n].models.night.charactersPatch = "BigHouse06_patch";
	locations[n].models.night.locators = "BigHouse06_Nlocators";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "PortRoyal_town";
	locations[n].reload.l1.emerge = "houseK3";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "PortRoyal_BigHouse6";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Room";
	locations[n].reload.l2.disable = 1; //закроем
	
	// Склад 02
	ExpandLocationsArray();
	
	n = MAX_LOCATIONS - 1;
	
	locations[n].id = "PortRoyal_sklad02";
	locations[n].id.label = "packhouse";
	locations[n].image = "loading\inside\sklad.tga";
	locations[n].MustSetReloadBack = true;
	locations[n].packhouse = true;
	//Town sack
	locations[n].townsack = "PortRoyal";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "PortRoyal";
	locations[n].islandId = "Jamaica";
	//Models
	locations[n].filespath.models = "locations\inside\Sklad02";
	//Always
	locations[n].models.always.locators = "sklad02_locators";
	locations[n].models.always.modelSklad = "sklad02";
	locations[n].models.always.modelSklad.level = 65538;
	//Day
	locations[n].models.day.charactersPatch = "sklad02_patch";
	//Night
	locations[n].models.night.charactersPatch = "sklad02_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "PortRoyal_town";
	locations[n].reload.l1.emerge = "houseSk5";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	
	//винный погреб
	ExpandLocationsArray();
	
	n = MAX_LOCATIONS - 1;
	
	locations[n].id = "PortRoyal_WineCellar";
	locations[n].image = "loading\inside\sklad.tga";
	locations[n].id.label = "Wine Cellar";
	//Sound
	locations[n].townsack = "PortRoyal";
	locations[n].type = "house";
	locations[n].fastreload = "PortRoyal";
	locations[n].islandId = "Jamaica";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\WineCellar";
	locations[n].models.always.WineCellar = "WineCellar";
	locations[n].models.always.WineCellar_parts = "WineCellar_parts";
	locations[n].models.always.WineCellar_Room = "WineCellar_RoomClosed";
	locations[n].models.always.locators = "WineCellar_locators";
	//Day
	//locations[n].models.day.charactersPatch = "WineCellar_RoomOpened_patch";
	locations[n].models.day.charactersPatch = "WineCellar_RoomClosed_patch";
	//Night
	//locations[n].models.night.charactersPatch = "WineCellar_RoomOpened_patch";
	locations[n].models.night.charactersPatch = "WineCellar_RoomClosed_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
 	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "PortRoyal_town";
	locations[n].reload.l1.emerge = "houseSk4";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "house";
	
	// Изменяем Сен Пьер
	n = FindLocation("FortFrance_town");
	
	locations[n].reload.l24.name = "houseS2";
	locations[n].reload.l24.go = "FortFrance_houseS2";
	locations[n].reload.l24.emerge = "reload1";
	locations[n].reload.l24.autoreload = "0";
	locations[n].reload.l24.label = "House";
	
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
	locations[n].reload.l1.emerge = "houseBH2";
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
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//  Винный погреб
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	ExpandLocationsArray();
	
	n = MAX_LOCATIONS - 1;
	
	locations[n].id = "FortFrance_WineCellar";
	locations[n].image = "loading\inside\sklad.tga";
	locations[n].id.label = "Wine Cellar";
	//Sound
	locations[n].townsack = "FortFrance";
	locations[n].type = "house";
	locations[n].fastreload = "FortFrance";
	locations[n].islandId = "Martinique";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\WineCellar";
	locations[n].models.always.WineCellar = "WineCellar";
	locations[n].models.always.WineCellar_parts = "WineCellar_parts";
	locations[n].models.always.WineCellar_Room = "WineCellar_RoomClosed";
	locations[n].models.always.locators = "WineCellar_locators";
	//Day
	//locations[n].models.day.charactersPatch = "WineCellar_RoomOpened_patch";
	locations[n].models.day.charactersPatch = "WineCellar_RoomClosed_patch";
	//Night
	//locations[n].models.night.charactersPatch = "WineCellar_RoomOpened_patch";
	locations[n].models.night.charactersPatch = "WineCellar_RoomClosed_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
 	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "FortFrance_houseS2";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "house";
	
	// Изменяем Виллемстад
	n = FindLocation("Villemstad_town");
	
	locations[n].reload.l23.name = "houseS2";
	locations[n].reload.l23.go = "Villemstad_houseS2";
	locations[n].reload.l23.emerge = "reload1";
	locations[n].reload.l23.autoreload = "0";
	locations[n].reload.l23.label = "House";
	
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
	locations[n].reload.l1.emerge = "houseBH2";
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
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//  Винный погреб
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	ExpandLocationsArray();
	
	n = MAX_LOCATIONS - 1;
	
	locations[n].id = "Villemstad_WineCellar";
	locations[n].image = "loading\inside\sklad.tga";
	locations[n].id.label = "Wine Cellar";
	//Sound
	locations[n].townsack = "Villemstad";
	locations[n].type = "house";
	locations[n].fastreload = "Villemstad";
	locations[n].islandId = "Curacao";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\WineCellar";
	locations[n].models.always.WineCellar = "WineCellar";
	locations[n].models.always.WineCellar_parts = "WineCellar_parts";
	locations[n].models.always.WineCellar_Room = "WineCellar_RoomClosed";
	locations[n].models.always.locators = "WineCellar_locators";
	//Day
	//locations[n].models.day.charactersPatch = "WineCellar_RoomOpened_patch";
	locations[n].models.day.charactersPatch = "WineCellar_RoomClosed_patch";
	//Night
	//locations[n].models.night.charactersPatch = "WineCellar_RoomOpened_patch";
	locations[n].models.night.charactersPatch = "WineCellar_RoomClosed_patch";
	//Environment
	locations[n].environment.weather = "true";
	Locations[n].lockWeather = "Inside";
	Locations[n].QuestlockWeather = "23 Hour";
	locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;
 	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Villemstad_houseS2";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "house";
	
	
	loadedLocation = &locations[0];
	
	// Расставляем записки
	SetItemInLocation("PR_Letter", "PortRoyal_town", "letter1");
	locations[FindLocation("PortRoyal_town")].locators_radius.item.letter1 = 1.0;
	QuestPointerToLoc("PortRoyal_town", "item", "letter1");
	
	SetItemInLocation("PR_Letter", "PortRoyal_town", "letter2");
	locations[FindLocation("PortRoyal_town")].locators_radius.item.letter2 = 1.2;
	QuestPointerToLoc("PortRoyal_town", "item", "letter2");
	
	SetItemInLocation("PR_Letter", "PortRoyal_town", "letter3");
	locations[FindLocation("PortRoyal_town")].locators_radius.item.letter3 = 1.0;
	QuestPointerToLoc("PortRoyal_town", "item", "letter3");
	
	SetItemInLocation("PR_Letter", "PortRoyal_town", "letter4");
	locations[FindLocation("PortRoyal_town")].locators_radius.item.letter4 = 1.0;
	QuestPointerToLoc("PortRoyal_town", "item", "letter4");
	
	locations[FindLocation("PortRoyal_town")].locators_radius.item.key1 = 1.0;
	
	SetItemInLocation("blade_12", "PortRoyal_town", "item1");
	locations[FindLocation("PortRoyal_town")].locators_radius.item.item1 = 1.0;
	//QuestPointerToLoc("PortRoyal_town", "item", "item1");
	
	SetItemInLocation("pistol3", "PortRoyal_town", "item2");
	locations[FindLocation("PortRoyal_town")].locators_radius.item.item2 = 1.0;
	//QuestPointerToLoc("PortRoyal_town", "item", "item2");
	
	SetItemInLocation("indian_10", "PortRoyal_town", "item3");
	locations[FindLocation("PortRoyal_town")].locators_radius.item.item3 = 1.0;
	//QuestPointerToLoc("PortRoyal_town", "item", "item3");
	
	SetItemInLocation("spyglass2", "PortRoyal_town", "item4");
	locations[FindLocation("PortRoyal_town")].locators_radius.item.item4 = 1.5;
	//QuestPointerToLoc("PortRoyal_town", "item", "item4");
	
	SetItemInLocation("purse1", "PortRoyal_town", "item5");
	locations[FindLocation("PortRoyal_town")].locators_radius.item.item5 = 1.0;
	//QuestPointerToLoc("PortRoyal_town", "item", "item5");
	
	n = FindLocation("Villemstad_town");
	
	SetItemInLocation("PR_Letter", "Villemstad_town", "letter1");
	locations[n].locators_radius.item.letter1 = 1.0;
	QuestPointerToLoc("Villemstad_town", "item", "letter1");
	
	locations[n].locators_radius.item.letter2 = 1.3;
	locations[n].locators_radius.item.letter3 = 1.0;
	locations[n].locators_radius.item.letter4 = 1.0;
	locations[n].locators_radius.item.key1 = 1.0;
}
