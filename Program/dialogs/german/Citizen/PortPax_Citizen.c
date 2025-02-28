// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
            dialog.text = RandPhraseSimple("Welche Art von Fragen?","Was willst du?");
			link.l1 = RandPhraseSimple("Ich habe meine Meinung geändert.","Ich habe jetzt nichts zu sagen.");
		    link.l1.go = "exit";
			if (CheckAttribute(pchar, "questTemp.Guardoftruth") && pchar.questTemp.Guardoftruth == "portprince" && !CheckAttribute(npchar, "quest.Guardoftruth"))
			{
				link.l1 = "Sag mir, "+GetAddress_FormToNPC(NPChar)+", war nicht vor kurzem die Galeone 'Santa Margarita' hier? Vielleicht als Prisenschiff eines Freibeuters?";
                link.l1.go = "guardoftruth";
			}
		break;
		
		case "info":
        // заменить на описание неких НПС, по квестам
			dialog.text = "Glaubst du, ich arbeite für den Geheimdienst von "+NationNameGenitive(sti(NPChar.nation))+"?";
			link.l1 = "Nun... nein. Lebewohl dann.";
			link.l1.go = "exit";
			link.l2 = "Hast du noch eine andere Frage?";
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
		
		case "guardoftruth":
			dialog.text = LinkRandPhrase("Nein, ich erinnere mich nicht an eine Galeone mit diesem Namen. Wir sehen hier selten so große Schiffe.","Was? Eine Galeone? Hier? Ich habe keine Ahnung.","Nein Sir, dieses Schiff hat hier in letzter Zeit nicht angelegt, zumindest erinnere ich mich nicht daran.");
			link.l1 = LinkRandPhrase("In Ordnung...","Sehr gut...","Ich verstehe, schade...");
			link.l1.go = "exit";
			npchar.quest.Guardoftruth = "true";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
