// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Какие имеете вопросы к солдату?", "У солдата жизнь расписана - караулы, разводы... Что вам угодно, " + GetAddress_Form(NPChar) + "?"), "Не пристало приставать к солдату с глупыми вопросами, " + GetAddress_Form(NPChar) + "...", "Третий раз за сегодня вы пытаетесь задать вопрос...",
                          "Солдатская доля и без того непроста, а тут ещё и ты,"+ GetSexPhrase(" недоносок, "," ") +"выводишь из себя...", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Я передумал"+ GetSexPhrase("","а") +"...", "Сейчас мне не о чем говорить."), "Не пристало...",
                      "Да уж, действительно в третий раз...", "Извиняюсь...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			//Цена чахотки
			if (!CheckAttribute(npchar, "quest.Consumption") && CheckAttribute(pchar, "questTemp.Consumption.AskJuan"))
			{
				link.l1 = "Скажи, имя 'Хуан' тебе что-нибудь говорит?";
				link.l1.go = "Consumption";
			}
		break;
		
		//Цена чахотки
		case "Consumption":
			dialog.text = "Нет. Это всё?";
			link.l1 = "Да. Извини за беспокойство, служивый...";
			link.l1.go = "exit";
			npchar.quest.Consumption = "true";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}

