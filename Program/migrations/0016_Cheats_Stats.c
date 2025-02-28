void ApplyMigration(ref migrationState) {
	
	if(CheckAttribute(pchar,"Statistic.Cheats.F5"))
		DeleteAttribute(pchar,"Statistic.Cheats.F5");
	if(CheckAttribute(pchar,"Statistic.Cheats.F7"))
		DeleteAttribute(pchar,"Statistic.Cheats.F7");
	if(CheckAttribute(pchar,"Statistic.Cheats.F10"))
		DeleteAttribute(pchar,"Statistic.Cheats.F10");
	
	int n = FindLocation("Mayak5");
	
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
}
