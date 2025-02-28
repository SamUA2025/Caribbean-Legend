void ApplyMigration(ref migrationState) {
	
	int n = FindLocation("BOARDING_4_WAR");
	Locations[n].models.night.jumpPatch = "boarding_4_war_jump";
}
