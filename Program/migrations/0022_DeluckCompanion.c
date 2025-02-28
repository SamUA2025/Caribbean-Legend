void ApplyMigration(ref migrationState) {
	
	if (GetCharacterIndex("Folke") != -1 && CheckPassengerInCharacter(pchar, "Folke"))
	{
		sld = CharacterFromID("Folke");
		DeleteAttribute(sld, "CompanionDisable");
	}
	// корсет
	items[FindItem("cirass5")].price = 8000;
}
