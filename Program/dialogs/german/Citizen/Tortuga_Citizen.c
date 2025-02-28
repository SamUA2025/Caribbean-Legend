// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
            dialog.text = RandPhraseSimple("Welche Art von Fragen?","Was willst du?");
			link.l1 = RandPhraseSimple("Ich habe meine Meinung geändert.","Ich habe jetzt nichts zu sagen.");
		    link.l1.go = "exit";
			
			// Rebbebion, "Путеводная звезда"
			if (CheckAttribute(pchar, "questTemp.PZ.TortugaCitizensAsk") && npchar.sex == "man")
			{
				link.l1 = "Sie würden nicht zufällig einen gewissen Joep van der Vink kennen, oder?";
				link.l1.go = "PZ1";
			}
		break;
		
		case "info":
        // заменить на описание неких НПС, по квестам
			dialog.text = "Denken Sie, dass ich für den Geheimdienst arbeite von "+NationNameGenitive(sti(NPChar.nation))+"?";
			link.l1 = "Nun... nein. Lebewohl dann.";
			link.l1.go = "exit";
			link.l2 = "Haben Sie noch eine Frage?";
			link.l2.go = "new question";
		break;
		
		case "town":
        // заменить на описание как пройти, по квестам
			dialog.text = "Sehe ich aus wie das Untersuchungsbüro? Ich weiß nicht, weiß nichts.";

            link.l1 = "Du bist so ein Wirrkopf! Verschwinde.";
			link.l1.go = "exit";
			link.l2 = "Hast du noch eine andere Frage?";
			link.l2.go = "new question";
		break;
		
		case "PZ1":
			dialog.text = "Nun, ich kenne ihn nicht persönlich, aber ich sehe ihn hier von Zeit zu Zeit. Warum fragst du?";
			link.l1 = "Ich wurde beauftragt, ihm persönlich ein Paket zu überbringen. Aber niemand will über ihn sprechen, und ich weiß nicht warum. Kennst du ihn? Ist er ein schlechter Mensch? Ich würde deine ehrliche Meinung schätzen.";
			link.l1.go = "PZ2";
		break;
		
		case "PZ2":
			dialog.text = "Wiederum, wir kennen uns nicht persönlich, also weiß ich fast nichts. Aber er hat einen engen Freund in der Stadt, und sie werden oft zusammen gesehen. Geh zu ihm - er wird entscheiden, ob er dir mehr erzählt oder nicht. Der Name seines Kumpels ist Rober Martene.";
			link.l1 = "Rober Martene, sagst du... Und wer ist er? Wo kann ich ihn finden?";
			link.l1.go = "PZ3";
		break;
		
		case "PZ3":
			dialog.text = "An verschiedenen Orten, aber gerade jetzt ist er an unserem Leuchtturm - repariert seine Galeone nach einem schrecklichen Sturm. Sie heißt 'Voltigeur'.";
			link.l1 = "Vielen Dank! Sie haben keine Ahnung, wie sehr Sie mir geholfen haben.";
			link.l1.go = "Exit";
			AddDialogExitQuest("PZ_CreateRobertMartin");
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
