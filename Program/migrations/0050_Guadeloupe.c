void ApplyMigration(ref migrationState) {
	
	int n;
	
	n = FindLocation("BasTer_town");
	locations[n].models.always.parts = "Guadeloupe_parts";
}
