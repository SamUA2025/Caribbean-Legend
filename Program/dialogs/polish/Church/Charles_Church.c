// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Jakie pytania, "+GetSexPhrase("mój synu","moja córko")+"?","Pytaj śmiało, słucham..."),"Słucham, mów teraz, "+GetSexPhrase("mój synu","moja córko")+"...","Po raz trzeci, "+GetSexPhrase("mój synu","moja córko")+"Proszę, pytaj o to, czego potrzebujesz.","Duchowny ma od groma pracy, "+GetSexPhrase("mój synu","moja córko")+" a ty mnie ewidentnie rozpraszasz...","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Już nieważne...","Nie tym razem, ojcze..."),"Nie mam nic do powiedzenia, przepraszam.","Zapytam później. Wybacz mi, ojcze.","Przepraszam, święty ojcze...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
		
		case "Gravel1":
			dialog.text = "Co mogę dla ciebie zrobić, mój synu?";
			link.l1 = "Szukam cię, Georges.";
			link.l1.go = "Gravel2";
			DelLandQuestMark(npchar);
		break;
		
		case "Gravel2":
			dialog.text = "Mnie? Ale dlaczego?";
			link.l1 = "Longway i Mynheer Van Merden potrzebują, abyś ponownie zbadał sprawę. Longway nie może się tu pokazywać po swojej... poprzedniej wizycie.";
			link.l1.go = "Gravel3";
		break;
		
		case "Gravel3":
			AddQuestRecord("PZ", "23");
			dialog.text = "Mów ciszej, na miłość boską! Ale rozumiem. Zrobię, co w mojej mocy.";
			link.l1 = "Doskonale, Georges. Jesteś jednym z naszych najcenniejszych sojuszników. Z Panem Bogiem.";
			link.l1.go = "Exit";
			DelMapQuestMarkCity("Charles");
			
			pchar.questTemp.PZ_Etap5_Start = true;
			
			if (CheckAttribute(pchar, "questTemp.LSC.Mary_officer") && GetCharacterIndex("Mary") != -1 && !CheckAttribute(pchar, "questTemp.PZ_ProvalFinal"))
			{
				PChar.quest.PZ_Etap5_Start.win_condition.l1 = "location";
				PChar.quest.PZ_Etap5_Start.win_condition.l1.location = "Pirates_town";
				PChar.quest.PZ_Etap5_Start.win_condition = "PZ_Etap5_Start";
				AddMapQuestMarkCity("Pirates", false);
			}
			if (CheckAttribute(pchar, "questTemp.Saga.Helena_officer") && GetCharacterIndex("Helena") != -1 && !CheckAttribute(pchar, "questTemp.PZ_ProvalFinal"))
			{
				PChar.quest.PZ_Etap5_Start.win_condition.l1 = "location";
				PChar.quest.PZ_Etap5_Start.win_condition.l1.location = "Pirates_town";
				PChar.quest.PZ_Etap5_Start.win_condition = "PZ_Etap5_Start";
				AddMapQuestMarkCity("Pirates", false);
			}
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
