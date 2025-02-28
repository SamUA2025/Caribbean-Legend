// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Welche Fragen haben Sie für einen Soldaten?","Ein Soldat hat sein ganzes Leben geplant - bewachen, schuften... Wie kann ich Ihnen helfen, "+GetAddress_Form(NPChar)+"?"),"Sie sollten einen Soldaten nicht mit dummen Fragen belästigen, "+GetAddress_Form(NPChar)+"...","Das ist das dritte Mal heute, dass du versuchst, mir eine Frage zu stellen...","Das Schicksal eines Soldaten ist nicht einfach, und nun treibst du, Abschaum, mich in den Wahnsinn...","Block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Ich habe es mir anders überlegt...","Ich habe im Moment nichts zu besprechen."),"Habs verstanden...","Ja, du hast recht, schon das dritte Mal...","Es tut mir Leid...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			//Цена чахотки
			if (!CheckAttribute(npchar, "quest.Consumption") && CheckAttribute(pchar, "questTemp.Consumption.AskJuan"))
			{
				link.l1 = "Sag mir, bedeutet der Name Juan dir etwas?";
				link.l1.go = "Consumption";
			}
		break;
		
		//Цена чахотки
		case "Consumption":
			dialog.text = "Nein. Ist das alles?";
			link.l1 = "Ja. Entschuldigung für die Störung, Soldat...";
			link.l1.go = "exit";
			npchar.quest.Consumption = "true";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
