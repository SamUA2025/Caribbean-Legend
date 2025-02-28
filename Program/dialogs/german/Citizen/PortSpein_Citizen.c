// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
            dialog.text = RandPhraseSimple("Welche Art von Fragen?","Was willst du?");
			link.l1 = RandPhraseSimple("Ich habe meine Meinung geändert.","Ich habe jetzt nichts zu sagen.");
		    link.l1.go = "exit";
			//Цена чахотки
			if (!CheckAttribute(npchar, "quest.Consumption") && CheckAttribute(pchar, "questTemp.Consumption.AskJuan"))
			{
				link.l1 = "Sag mir, klingelt der Name 'Juan' bei dir?";
				link.l1.go = "Consumption";
			}
			if (!CheckAttribute(npchar, "quest.Guardoftruth") && CheckAttribute(pchar, "questTemp.Guardoftruth.Trinidad") && pchar.questTemp.Guardoftruth.Trinidad == "begin")
			{
				link.l1 = "Hör zu, Kumpel, eine Fregatte unter dem Kommando von Miguel Dichoso legte hier im April 1654 an. Er verschwand an diesem Tag. Erinnerst du dich an irgendetwas darüber?";
				link.l1.go = "guardoftruth";
			}
		break;
		
		case "info":
        // заменить на описание неких НПС, по квестам
			dialog.text = "Glauben Sie, ich arbeite für den Geheimdienst von "+NationNameGenitive(sti(NPChar.nation))+"?";
			link.l1 = "Nun... nein. Auf Wiedersehen dann.";
			link.l1.go = "exit";
			link.l2 = "Hast du noch eine Frage?";
			link.l2.go = "new question";
		break;
		
		case "town":
        // заменить на описание как пройти, по квестам
			dialog.text = "Sehe ich aus wie das Untersuchungsbüro? Ich weiß nicht, weiß nichts.";

            link.l1 = "Du bist so ein Wirrkopf! Verschwinde.";
			link.l1.go = "exit";
			link.l2 = "Gibt es noch eine andere Frage?";
			link.l2.go = "new question";
		break;
		
		//Цена чахотки
		case "Consumption":
			dialog.text = "Veräppelst du mich? Es gibt in jeder Kolonie zweimal ein Dutzend Juans!";
			link.l1 = "Ich verstehe. Entschuldigung für die Störung...";
			link.l1.go = "exit";
			npchar.quest.Consumption = "true";
		break;
		
		// Страж Истины
		case "guardoftruth":
			dialog.text = LinkRandPhrase("Komm schon, Kapitän! Glaubst du, dass ich mir so etwas merke?","Verzeihen Sie mir, Senor, ich kann Ihnen dabei nicht helfen.","Herr, glauben Sie wirklich, dass ich mir solchen Unsinn merke? Ich habe schon genug Probleme.");
			link.l1 = LinkRandPhrase("Ich verstehe. Entschuldigung für die Störung...","Wie schade, Lebewohl.","In Ordnung, leb wohl...");
			link.l1.go = "exit";
			npchar.quest.guardoftruth = "true";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
