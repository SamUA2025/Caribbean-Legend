// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Какие вопросы?", "Что вам угодно?"), "Совсем недавно вы пытались задать мне вопрос...", "М-да, позвольте угадаю... Опять ничего существенного?",
                          "Послушайте, я финансами оперирую, а не на вопросы отвечаю...", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Я "+ GetSexPhrase("передумал","передумала") +"...", "Сейчас мне не о чем говорить."), "Хм, что-то с памятью моей стало...",
                      "Вы угадали, простите...", "Я понимаю...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
		
		// Реакция ростовщика Панамы на репутацию ГГ или на разграбление Картахены по сюжету
		case "Panama_Deposit_NoReputation":
			dialog.text = "Так-то оно так... Человеку чести, которого любят подданные Короля, мой банк никогда не откажет - какой бы национальности он"+GetSexPhrase("","а")+" ни был"+GetSexPhrase("","а")+".";
			link.l1 = "Я вас понял"+GetSexPhrase("","а")+". До свидания.";
			link.l1.go = "exit";
		break;
		
		case "Panama_Deposit_Cartahena":
			dialog.text = "Зато она, к несчастью, была у моей дочери и тестя... Они жили в Картахене. Уходите, "+GetAddress_Form(NPChar)+". Вам тут не рады.";
			if (pchar.questTemp.Mtraxx.Retribution.Choice == "good")
			{
				link.l1 = "Простите меня. Прощайте.";
				link.l1.go = "exit";
			}
			else
			{
				link.l1 = "Вам же хуже. До свидания.";
				link.l1.go = "exit";
			}
			NextDiag.TempNode = "NeHochuRazgovarivat";
		break;
		
		case "Panama_Deposit_SgorelVklad":
			dialog.text = "Средства были изъяты Короной для оказания помощи пострадавшим при разграблении славного города Картахены. Ничем не могу помочь. Попрошу вас немедленно покинуть мой банк, пока я не кликнул сюда стражу!";
			link.l1 = "Вы об этом пожалеете...";
			link.l1.go = "exit";
			NextDiag.TempNode = "NeHochuRazgovarivat";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}

