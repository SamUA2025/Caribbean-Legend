void ApplyMigration(ref migrationState) {
	
	if(GetDLCenabled(DLC_APPID_4) && CheckAttribute(pchar, "questTemp.SantaMisericordia") && CharacterIsAlive("SantaMisericordia_cap"))
	{
		ref sld = characterFromId("SantaMisericordia_cap");
		
		if(CheckAttribute(sld,"quest") && sld.quest == "InMap")
		{
			DeleteQuestCondition("SantaMisericordia_ToMap");
			DeleteQuestCondition("SantaMisericordia_ToMap_2");
			
			//проверяем на карте
			bool bAtMap = false;
			aref encs;

			makearef(encs, worldMap.encounters);

			int num = GetAttributesNum(encs);
			aref enc;
			
			for (int i = 0; i < num; i++)
			{
				enc = GetAttributeN(encs, i);
				if(CheckAttribute(enc, "quest.chrID") && enc.quest.chrID == "SantaMisericordia_cap")
				{
					bAtMap = true;
				}
			}
			// на карте нет, но и атрибут "в порту" отсутствует
			if(!bAtMap)
			{
				SantaMisericordia_ToCity("SantaMisericordia_cap");
			}
		}
		//были случаи от неправильно проставленной ссылки на капитана галеона
		if(!GetCharacterFreeItem(sld,"amulet_8")) SantaMisericordia_init();
	}
}
