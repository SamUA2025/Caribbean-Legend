void ApplyMigration(ref migrationState) {
	
	if (GetCharacterIndex("Folke") != -1)
	{
		ref sld = characterFromId("Folke");
		if (CheckAttribute(sld, "HalfImmortal"))
		{
			DeleteAttribute(sld, "HalfImmortal");
			sld.OfficerImmortal = true;
			sld.Health.HP       = 60.0; 
			sld.Health.maxHP    = 60.0;
		}
	}
	
}
