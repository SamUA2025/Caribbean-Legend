void ApplyMigration(ref migrationState) {
	if (CheckAttribute(pchar, "questTemp.LSC.MaryWait") && !CheckPassengerInCharacter(pchar, "Helena")) {
		pchar.questTemp.LSC.Mary = "return";
	}
	
	items[FindItem("Totem_03")].time = 90;
}
