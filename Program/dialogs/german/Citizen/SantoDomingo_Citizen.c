// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
            dialog.text = RandPhraseSimple("Welche Art von Fragen?","Was willst du?");
			link.l1 = RandPhraseSimple("Ich habe meine Meinung geändert.'","Ich habe jetzt nichts zu sagen.");
		    link.l1.go = "exit";
		break;
		
		case "info":
        // заменить на описание неких НПС, по квестам
			dialog.text = "Glauben Sie, ich arbeite für den Geheimdienst von "+NationNameGenitive(sti(NPChar.nation))+"?";
			link.l1 = "Nun... nein. Lebewohl dann.";
			link.l1.go = "exit";
			link.l2 = "Gibt es noch eine andere Frage, dann?";
			link.l2.go = "new question";
		break;
		
		case "town":
        // заменить на описание как пройти, по квестам
			dialog.text = "Sehe ich aus wie das Ermittlungsbüro? Ich weiß es nicht, ich weiß gar nichts.";

            link.l1 = "Du bist so ein Wirrkopf! Verschwinde.";
			link.l1.go = "exit";
			link.l2 = "Hast du noch eine andere Frage?";
			link.l2.go = "new question";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
