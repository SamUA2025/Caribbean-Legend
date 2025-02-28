// второй патч

void ApplyMigration(ref migrationState) {
	if (CheckAttribute(pchar,"TorrentEddy.location"))
	{
		DoQuestFunctionDelay("TorrentEddy_Freedom", 4.0);
	}
	else
	{
		SetFunctionTimerCondition("TorrentEddy", 8, 0, 0, false);
	}
	
	MOD_EXP_RATE = makeint(5 + MOD_SKILL_ENEMY_RATE);
	MOD_EXP_RATE =  makeint(MOD_EXP_RATE + MOD_SKILL_ENEMY_RATE * MOD_EXP_RATE / 1.666666666);
	if (MOD_EXP_RATE < 10) MOD_EXP_RATE = 10;
}
