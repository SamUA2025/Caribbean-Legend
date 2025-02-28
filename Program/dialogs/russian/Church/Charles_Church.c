// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Какие вопросы, "+ GetSexPhrase("сын мой","дочь моя") +"?", "Спрашивай, я слушаю тебя..."), "Я слушаю тебя, говори, "+ GetSexPhrase("сын мой","дочь моя") +"...", "И в третий раз говорю тебе, "+ GetSexPhrase("сын мой","дочь моя") +": задавай свой вопрос.",
                          "Столько обязанностей у церковнослужителя, а тут ещё и ты донимаешь, "+ GetSexPhrase("сын мой","дочь моя") +"...", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Я "+ GetSexPhrase("передумал","передумала") +"...", "Не сейчас, падре..."), "Да, пока особо и нечего сказать...",
                      "Задам, задам... Только позже...", "Простите, святой отец...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
		
		case "Gravel1":
			dialog.text = "Чем могу помочь вам, "+GetSexPhrase("сын мой","дочь моя")+"?";
			link.l1 = "Всё верно - я искал именно вас, Жорж.";
			link.l1.go = "Gravel2";
			DelLandQuestMark(npchar);
		break;
		
		case "Gravel2":
			dialog.text = "Меня? Но почему?";
			link.l1 = "Лонгвэю и господину ван Мердену снова нужно, чтобы вы кое-что разузнали. Сам он не может появиться здесь лично после своего... предыдущего визита сюда.";
			link.l1.go = "Gravel3";
		break;
		
		case "Gravel3":
			AddQuestRecord("PZ", "23");
			dialog.text = "Говорите тише, Бога ради! Но я вас понял, "+GetSexPhrase("сын мой","дочь моя")+". Сделаю всё в лучшем виде.";
			link.l1 = "Прекрасно, Жорж. Без сомнения, вы один из наших самых ценных работников. До встречи.";
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



