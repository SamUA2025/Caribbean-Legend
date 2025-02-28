void ApplyMigration(ref migrationState) {
	//обновить таймер
	SetFunctionTimerCondition("TorrentEddy", 5, 0, 0, false);
	
	items[FindItem("talisman11")].price = 100;
	
	// 36 кулеврины только в 42 порт
	Cannon[CANNON_TYPE_CULVERINE_LBS36].caliber = 42;
	
	if (GetCharacterIndex("HelenDrinking_Poorman") >= 0) {
		sld = CharacterFromID("HelenDrinking_Poorman");
		sld.model = "panhandler_6";
		sld.FaceId = 500;
		SetSPECIAL(sld, 7, 7, 7, 7, 7, 7, 7);
		SetEnergyToCharacter(sld);
		ClearCharacterExpRate(sld);
		RefreshCharacterSkillExpRate(sld);
	}
	
	if (GetCharacterIndex("Helena") >= 0) {
		sld = CharacterFromID("Helena");
		if (sld.dialog.currentnode == "First time") {
			sld.dialog.currentnode = "Helena_officer";
		}
	}
	pchar.quest.FMQL_delete_guide.over = "yes";
}
