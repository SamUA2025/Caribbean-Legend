void ApplyMigration(ref migrationState) {
	
	if (CheckAttribute(pchar, "questTemp.PZ_LevasserPobezhden"))
	{
		sld = &Locations[FindLocation("Tortuga_Cave")];
		sld.locators_radius.reload.reload3_back = 0;
		
		Tortuga_DeleteShipGuard();
	}
}
