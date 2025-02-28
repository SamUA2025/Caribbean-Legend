void ApplyMigration(ref migrationState) {
	
	for(int n=0; n<MAX_CHARACTERS; n++)
	{
		if(CheckAttribute(&Characters[n],"chr_ai.priority_mode"))
		{
			trace("Character "+Characters[n].id+" chr_ai.priority_mode " + sti(Characters[n].chr_ai.priority_mode));
			Characters[n].PriorityMode = sti(Characters[n].chr_ai.priority_mode);
			DeleteAttribute(&Characters[n],"chr_ai.priority_mode");
		}
		
		if(and(CharacterIsAlive("Irons"), Characters[n].id == "Irons") 
		|| and(CharacterIsAlive("Tichingitu"), Characters[n].id == "Tichingitu")
		|| and(CharacterIsAlive("LongWay"), Characters[n].id == "LongWay"))
		{
			if(HasSubStr(Characters[n].model, "_mush")) 
			{
				Characters[n].model = FindStringBeforeChar(Characters[n].model, "_mush");
				Characters[n].model.animation = Characters[n].model;
				Characters[n].PriorityMode = 2;
			}
			else
			{
				Characters[n].model.animation = Characters[n].model;
				Characters[n].PriorityMode = 1;
			}
			if(!CheckAttribute(&Characters[n],"IsMushketer")) Characters[n].PriorityMode = 1;
		}
	}
}
