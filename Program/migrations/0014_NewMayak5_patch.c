void ApplyMigration(ref migrationState) {
	
	int n = FindLocation("Mayak5");
	
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
	//Day
	locations[n].models.day.winday = "lighthouse2_winday";
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
	locations[n].models.night.winnight.tech = "LighthouseLight";
	locations[n].models.night.winnight.level = 66529;
	locations[n].models.night.charactersPatch = "lighthouse2_patch";	
	Locations[n].models.night.jumpPatch = "lighthouse2_jamp";
	
	locations[n].models.night.glassinnight = "lighthouse2_glassinnight";
	Locations[n].models.night.glassinnight.tech = "LocationWindows";
	locations[n].models.night.glassinnight.level = 66531;
	
	locations[n].models.night.glassonnight = "lighthouse2_glassonnight";
	Locations[n].models.night.glassonnight.tech = "LocationWindows";
	locations[n].models.night.glassonnight.level = 66532;
	
	locations[n].models.night.fonaronnight = "lighthouse2_fonaronnight";
	
	if(!CheckAttribute(PChar, "IsMushketer") && startHeroType == 1) 
	{
		PChar.model.animation = PChar.model;
	}
}
