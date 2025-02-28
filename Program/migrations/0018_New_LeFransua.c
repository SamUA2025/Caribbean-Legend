void ApplyMigration(ref migrationState) {
	
	colonies[FindColony("LeFransua")].from_sea   = "LeFransua_town";
	Islands[FindIsland("Martinique")].reload.l4.go = "LeFransua_town";
	locations[FindLocation("Martinique_jungle_02")].reload.l3.emerge = "reload2";
	// Выход из города Ле Франсуа
	int n = FindLocation("LeFransua_ExitTown");
	locations[n].image = "loading\outside\jungle_" + rand(3) + ".tga";
	locations[n].filespath.models = "locations\Outside\Jungles\jungle8\";
	Locations[n].models.always.jungle = "jungle8";	
	Locations[n].models.always.locators = "jungle8_locators";		
	Locations[n].models.always.grassPatch = "jungle8_grass";
	locations[n].models.day.charactersPatch = "jungle8_patch";
	locations[n].models.night.charactersPatch = "jungle8_patch";
	if(CheckAttribute(&locations[n],"models.day.fonars")) DeleteAttribute(&locations[n],"models.day.fonars");
	if(CheckAttribute(&locations[n],"models.night.fonars")) DeleteAttribute(&locations[n],"models.night.fonars");
	if(CheckAttribute(&locations[n],"models.always.smugglerLairExit")) DeleteAttribute(&locations[n],"models.always.smugglerLairExit");
	Locations[n].reload.l1.go = "LeFransua_town";
	Locations[n].reload.l1.emerge = "reload_2";
	locations[n].reload.l2.go = "Martinique_jungle_02";
	locations[n].reload.l2.emerge = "reload3";
	locations[n].reload.l2.label = "Jungle";
	locations[n].locators_radius.reload.reload2_back = 2.0;
	if(CheckAttribute(&locations[n],"reload.l3")) DeleteAttribute(&locations[n],"reload.l3");
	// Город Ле Франсуа
	n = FindLocation("LeFransua_town");
	if(CheckAttribute(&locations[n],"models.always.smugglerLairTown")) DeleteAttribute(&locations[n],"models.always.smugglerLairTown");
	if(CheckAttribute(&locations[n],"models.day.fonars")) DeleteAttribute(&locations[n],"models.day.fonars");
	if(CheckAttribute(&locations[n],"models.night.fonars")) DeleteAttribute(&locations[n],"models.night.fonars");
	if(CheckAttribute(&locations[n],"models.always.l1")) DeleteAttribute(&locations[n],"models.always.l1");
	if(CheckAttribute(&locations[n],"models.always.l2")) DeleteAttribute(&locations[n],"models.always.l2");
	if(CheckAttribute(&locations[n],"models.always.l3")) DeleteAttribute(&locations[n],"models.always.l3");
	//Models
	//Always
	Locations[n].filespath.models = "locations\Town_LeFransua";
	locations[n].models.always.town = "LeFransua";
	locations[n].models.always.town.sea_reflection = 1;
	locations[n].models.always.seabed = "LeFransua_sb";
	locations[n].models.always.locators = "LeFransua_locators";
	locations[n].models.always.grassPatch = "LeFransua_grass";
	locations[n].models.always.plan = "plan1";
	locations[n].models.always.plan.level = 9;
	//Day
	locations[n].models.day.fonar = "LeFransua_fd";
	locations[n].models.day.charactersPatch = "LeFransua_patch_day";
	locations[n].models.day.rinok = "LeFransua_rinok";
	//Night
	locations[n].models.night.fonar = "LeFransua_fn";
	locations[n].models.night.charactersPatch = "LeFransua_patch_night";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Martinique";
	locations[n].reload.l1.emerge = "reload_3";
	locations[n].reload.l1.label = "Sea";
	locations[n].locators_radius.reload.reload1_back = 2;
	Locations[n].reload.l2.name = "gate_back"; 
	Locations[n].reload.l2.go = "LeFransua_ExitTown";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "ExitTown";
	locations[n].locators_radius.reload.gate_back = 3;
	
	Locations[n].reload.l3.name = "reload3_back";
	Locations[n].reload.l3.go = "LeFransua_townhall";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Townhall";
	Locations[n].reload.l3.close_for_night = 1;
	
	Locations[n].reload.l4.name = "reload4_back";
	Locations[n].reload.l4.go = "LeFransua_tavern";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "Tavern";
	
	if(CheckAttribute(&locations[n],"reload.l5")) DeleteAttribute(&locations[n],"reload.l5");
	
	Locations[n].reload.l6.name = "reload6_back";
	Locations[n].reload.l6.go = "LeFransua_store";
	Locations[n].reload.l6.emerge = "reload1";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.label = "Store";
	
	locations[n].reload.l7.name = "houseH6";
	locations[n].reload.l7.go = "CommonHut";
	
	locations[n].reload.l8.name = "houseK4";
	locations[n].reload.l8.go = "CommonRoom_MH";
	locations[n].reload.l8.emerge = "reload1";
	locations[n].reload.l8.autoreload = "0";
	locations[n].reload.l8.label = "House";
	if(CheckAttribute(&locations[n],"reload.l8.close_for_night")) DeleteAttribute(&locations[n],"reload.l8.close_for_night");
	
	locations[n].reload.l9.name = "houseH2";
	locations[n].reload.l9.go = "CommonRoom_MH2";
	locations[n].reload.l9.emerge = "reload1";
	locations[n].reload.l9.autoreload = "0";
	locations[n].reload.l9.label = "House";
	//таверна Ле Франсуа
	n = FindLocation("LeFransua_tavern");
	locations[n].reload.l1.emerge = "reload4";
	// магазин Ле Франсуа
	n = FindLocation("LeFransua_store");
	locations[n].reload.l1.emerge = "reload6";
	// резиденция Ле Франсуа
	n = FindLocation("LeFransua_townhall");
	locations[n].reload.l1.emerge = "reload3";
	
	RecalculateJumpTable();
}
