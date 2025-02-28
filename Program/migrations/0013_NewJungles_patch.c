void ApplyMigration(ref migrationState) {
	
	int n = FindLocation("Martinique_jungle_04");
	
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Jungles\jungle13";
	Locations[n].models.always.jungle = "jungle13";	
	Locations[n].models.always.locators = "jungle13_locators";		
	Locations[n].models.always.grassPatch = "jungle13_grass";
	Locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";	
	Locations[n].models.always.l1 = "plan1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "plan3";
	Locations[n].models.always.l3.level = 7;
	Locations[n].models.always.l3.tech = "LocationModelBlend";
	//Day
	locations[n].models.day.charactersPatch = "jungle13_patch";
	//Night
	locations[n].models.night.charactersPatch = "jungle13_patch";	
	
	
	n = FindLocation("Marigo_jungle_01");
	
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Jungles\jungle13";
	Locations[n].models.always.jungle = "jungle13";	
	Locations[n].models.always.locators = "jungle13_locators";		
	Locations[n].models.always.grassPatch = "jungle13_grass";
	Locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";	
	Locations[n].models.always.l1 = "plan1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "plan3";
	Locations[n].models.always.l3.level = 7;
	Locations[n].models.always.l3.tech = "LocationModelBlend";
	//Day
	locations[n].models.day.charactersPatch = "jungle13_patch";
	//Night
	locations[n].models.night.charactersPatch = "jungle13_patch";
	
	n = FindLocation("PortoBello_Jungle_02");
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Jungles\jungle13";
	Locations[n].models.always.jungle = "jungle13";	
	Locations[n].models.always.locators = "jungle13_locators";		
	Locations[n].models.always.grassPatch = "jungle13_grass";
	Locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";	
	Locations[n].models.always.l1 = "plan1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "plan3";
	Locations[n].models.always.l3.level = 7;
	Locations[n].models.always.l3.tech = "LocationModelBlend";
	//Day
	locations[n].models.day.charactersPatch = "jungle13_patch";
	//Night
	locations[n].models.night.charactersPatch = "jungle13_patch";
	
	
	n = FindLocation("Tortuga_jungle_01");
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Jungles\jungle13";
	Locations[n].models.always.jungle = "jungle13";	
	Locations[n].models.always.locators = "jungle13_locators";		
	Locations[n].models.always.grassPatch = "jungle13_grass";
	Locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";	
	Locations[n].models.always.l1 = "plan1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "plan3";
	Locations[n].models.always.l3.level = 7;
	Locations[n].models.always.l3.tech = "LocationModelBlend";
	//Day
	locations[n].models.day.charactersPatch = "jungle13_patch";
	//Night
	locations[n].models.night.charactersPatch = "jungle13_patch";
	
	n = FindLocation("Jamaica_jungle_01");
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Jungles\jungle13";
	Locations[n].models.always.jungle = "jungle13";	
	Locations[n].models.always.locators = "jungle13_locators";		
	Locations[n].models.always.grassPatch = "jungle13_grass";
	Locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";	
	Locations[n].models.always.l1 = "plan1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "plan3";
	Locations[n].models.always.l3.level = 7;
	Locations[n].models.always.l3.tech = "LocationModelBlend";
	//Day
	locations[n].models.day.charactersPatch = "jungle13_patch";
	//Night
	locations[n].models.night.charactersPatch = "jungle13_patch";
	
	if(CheckAttribute(pchar,"questTemp.IslaMona.TownStage") && sti(pchar.questTemp.IslaMona.TownStage) > 2)
	{
		n = FindLocation("IslaMona_Jungle_01");
		
		locations[n].filespath.models = "locations\Outside\Jungles\jungle13";
		Locations[n].models.always.jungle = "jungle13";	
		Locations[n].models.always.locators = "jungle13L_locators";		
		Locations[n].models.always.grassPatch = "jungle13_grass";
		Locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";	
		Locations[n].models.always.l1 = "plan1";
		Locations[n].models.always.l1.level = 9;
		Locations[n].models.always.l1.tech = "LocationModelBlend";
		Locations[n].models.always.l2 = "plan2";
		Locations[n].models.always.l2.level = 8;
		Locations[n].models.always.l2.tech = "LocationModelBlend";
		Locations[n].models.always.l3 = "plan3";
		Locations[n].models.always.l3.level = 7;
		Locations[n].models.always.l3.tech = "LocationModelBlend";
		//Day
		locations[n].models.day.charactersPatch = "jungle13_patch";
		//Night
		locations[n].models.night.charactersPatch = "jungle13_patch";
	}
}
