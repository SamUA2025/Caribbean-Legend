void ApplyMigration(ref migrationState) {
	
	if (CharacterIsAlive("Irons"))
	{
		sld = CharacterFromID("Irons");
		LAi_SetHP(sld,LAi_GetCharacterMaxHP(sld)+86.0,LAi_GetCharacterMaxHP(sld)+86.0);
		SetSPECIAL(sld, 6, 9, 6, 3, 7, 6, 9);
	}
}
