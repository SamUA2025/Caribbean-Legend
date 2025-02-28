void ApplyMigration(ref migrationState) {
	
	if (CheckAttribute(pchar, "questTemp.BlackMarkQuestCompleted") && CharacterIsAlive("Irons"))
	{
		sld = CharacterFromID("Irons");
		LAi_RemoveCheckMinHP(sld);
		LAi_SetImmortal(sld, false);
	}
}
