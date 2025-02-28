void ApplyMigration(ref migrationState) {
	
	sld = &Locations[FindLocation("PortRoyal_town")];
	sld.reload.l22.name = "houseSp3";
	sld.reload.l22.go = "PortRoyal_houseSp3";
	sld.reload.l22.emerge = "reload1";
	sld.reload.l22.autoreload = "0";
	sld.reload.l22.label = "House";
	//Дверь откроем
	LocatorReloadEnterDisable("PortRoyal_town", "houseSp3", false);
}
