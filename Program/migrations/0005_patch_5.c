

void ApplyMigration(ref migrationState)
{
	// продлить таймер
	SetFunctionTimerCondition("TorrentEddy", 8, 0, 0, false);
	
	// локатор выхода с заднего двора Виллемстада
	ref loc = &locations[FindLocation("Villemstad_town")];
	loc.reload.lR1.go = "Villemstad_hall";
	//нода Локсли
	if(SandBoxMode)
	{
		ref sld = characterFromId("Loxly");
		if (sld.quest.meeting == "1")
		{
			sld.quest.meeting = "0";
		}
	}
	
}