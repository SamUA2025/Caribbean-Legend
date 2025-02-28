void ApplyMigration(ref migrationState) {
	
	// бригант
	items[FindItem("cirass7")].price = 38500;
	// парадная кираса
	items[FindItem("cirass3")].price = 77000;
	
	if (GetCharacterIndex("Knippel") != -1 && CheckPassengerInCharacter(pchar, "Knippel") && !CheckAttribute(pchar, "questTemp.DTSG_Start") && pchar.questTemp.HWIC.Detector == "eng_win") DoQuestCheckDelay("DTSG_Start", 1.0);
}
