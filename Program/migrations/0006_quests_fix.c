void ApplyMigration(ref migrationState) {
	if (GetCharacterIndex("Joruba") >= 0 && !CheckAttribute(pchar, "questTemp.ChickenGod.Tasks")) {
		sld = CharacterFromID("Joruba");
		sld.model = "Chavinavi_1";
		DeleteQuestCondition("ChickenGod_JorubaChangeModel");
	}
	
	if (CheckAttribute(pchar, "questTemp.ChickenGod.SelectedBrothel")) {
		sld = &locations[FindLocation(locations[FindLocation(pchar.questTemp.ChickenGod.SelectedBrothel)].fastreload + "_SecBrRoom")];
		DeleteAttribute(sld, "box1");
		sld.box1 = Items_MakeTime(0, 0, 0, 2024);
		sld.box1.items.totem_13 = 1;
	}
	
	if (CheckAttribute(pchar, "questTemp.ChickenGod.EnergyMod") && stf(pchar.questTemp.ChickenGod.EnergyMod) < 0.0) {
		ChickenGod_ModifyStats(5.0);
	}
	
	if(CheckAttribute(pchar,"questTemp.IslaMona.TownStage") && sti(pchar.questTemp.IslaMona.TownStage) > 2)
	{
		Achievment_Set("ach_CL_92");
	}
	
	//обновить таймер
	SetFunctionTimerCondition("TorrentEddy", 5, 0, 0, false);
	
	// фикс неправильного index склада виллемстада
	ref loc = &locations[FindLocation("Villemstad_Packhouse")];
	loc.index = FindLocation("Villemstad_Packhouse");
	// оберег ловца в подземелья
	loc = &locations[FindLocation("Judgement_dungeon_07")];
	loc.private1.items.talisman10 = 1;
}
