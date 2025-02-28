void ApplyMigration(ref migrationState) {
	
	if (GetCharacterIndex("Patria_SiegeCap_1") != -1)
	{
		ref sld = characterFromId("Patria_SiegeCap_1");
		sld.DontClearDead = true;
		sld.SaveItemsForDead = true;
	}
	
	if (CheckAttribute(pchar, "questTemp.Tieyasal_WinEnd") && !CheckAttribute(pchar, "questTemp.LongHappy"))
	{
		SetFunctionTimerCondition("LongHappy_Prepare", 0, 0, 1, false);
	}
}
