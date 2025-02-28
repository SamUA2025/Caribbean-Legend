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
			
			// --> Sinistra Длинные тени старых грехов	
			if (CheckAttribute(pchar, "questTemp.DTSG_depozit"))
			{
				link.l1 = "Скажите, полковник к вам уже не заходил? Он сказал, что у вас приготовлена награда для меня.";
				link.l1.go = "DTSG_depozit_1";
			}
			// <-- Длинные тени старых грехов
		break;
		
		// --> Sinistra Длинные тени старых грехов	
		case "DTSG_depozit_1":
			dialog.text = "Какой полковник?";
			link.l1 = "Томас Линч.";
			link.l1.go = "DTSG_depozit_2";
		break;
		
		case "DTSG_depozit_2":
			dialog.text = "Говорите тише, я вас понял. Мало ли, кто-то подслушал или выведал - всякое бывает. И да, заходил. Ваша награда ждёт вас, капитан.";
			link.l1 = "И сколько же здесь?";
			link.l1.go = "DTSG_depozit_3";
		break;
		
		case "DTSG_depozit_3":
			dialog.text = "Ровно десять тысяч золотых. Ни одной монетой меньше, ни единого песо - лишь золото.";
			link.l1 = "Ну хоть не тридцать серебряников...";
			link.l1.go = "DTSG_depozit_4";
			AddItems(pchar, "chest", 70);
			//Log_Info("Вы получили 70 сундуков");
			PlaySound("interface\important_item.wav");
		break;
		
		case "DTSG_depozit_4":
			dialog.text = "Что-что?";
			link.l1 = "Да так, ничего... Благодарю. До свидания.";
			link.l1.go = "exit";
			DeleteAttribute(pchar, "questTemp.DTSG_depozit");
		break;
		// <-- Длинные тени старых грехов
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}

