// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
            dialog.text = RandPhraseSimple("Welche Art von Fragen?","Was wollen Sie?");
			link.l1 = RandPhraseSimple("Ich habe meine Meinung geändert.'","Ich habe jetzt nichts zu sagen.");
		    link.l1.go = "exit";
		break;
		
		case "info":
        // заменить на описание неких НПС, по квестам
			dialog.text = "Glauben Sie, dass ich für den Geheimdienst arbeite von "+NationNameGenitive(sti(NPChar.nation))+"?";
			link.l1 = "Nun... nein. Dann leb wohl.";
			link.l1.go = "exit";
			link.l2 = "Gibt es noch eine andere Frage?";
			link.l2.go = "new question";
		break;
		
		case "town":
        // заменить на описание как пройти, по квестам
			dialog.text = "Sehe ich aus wie das Untersuchungsbüro? Ich weiß es nicht, weiß nichts.";

            link.l1 = "Du bist solch ein Wirrkopf! Verschwinde.";
			link.l1.go = "exit";
			link.l2 = "Gibt es noch eine andere Frage?";
			link.l2.go = "new question";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
