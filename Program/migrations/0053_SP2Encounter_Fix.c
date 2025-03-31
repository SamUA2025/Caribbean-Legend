void ApplyMigration(ref migrationState) {
	
	if(CheckAttribute(pchar, "questTemp.LadyBeth") && CharacterIsAlive("LadyBeth_cap"))
	{
		ref sld = CharacterFromID("LadyBeth_cap")
		if(CheckAttribute(sld,"quest") && sld.quest == "InMap")
		{
			//проверяем на карте
			bool bAtMap = false;
			aref encs;

			makearef(encs, worldMap.encounters);

			int num = GetAttributesNum(encs);
			aref enc;
			
			for (int i = 0; i < num; i++)
			{
				enc = GetAttributeN(encs, i);
				if(CheckAttribute(enc, "quest.chrID") && enc.quest.chrID == "LadyBeth_cap")
				{
					bAtMap = true;
				}
			}
			// на карте нет, но и атрибут "в порту" отсутствует
			if(!bAtMap)
			{
				LadyBeth_ToCity("LadyBeth_cap");
			}
			else
			{
				if(sld.quest.targetCity == "charles")
				{
					Map_ReleaseQuestEncounter("LadyBeth_cap");
				}
			}
		}
	}
}
