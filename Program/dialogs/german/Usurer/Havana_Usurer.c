// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Welche Fragen haben Sie?","Wie kann ich Ihnen helfen?"),"Du hast versucht, mir diese Frage vor nicht allzu langer Zeit zu stellen...","Ja, lass mich raten... Wieder einmal im Kreis unterwegs?","Hör zu, ich mache hier die Finanzen, ich beantworte keine Fragen...","Block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Ich habe meine Meinung geändert...","Ich habe im Moment nichts zu besprechen."),"Umph, wo ist mein Gedächtnis hin...","Du hast es erraten, es tut mir Leid...","Ich verstehe...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			// калеуче
			if (CheckAttribute(pchar, "questTemp.Caleuche") && pchar.questTemp.Caleuche == "graveyard" && !CheckAttribute(npchar, "quest.caleuche"))
			{
				link.l1 = "Hören Sie, war hier ein Mann namens Joachim Merriman? Ein mittelalterlicher Senor, Portugiese, mit Schnurrbart, kaiserlichem Bart und durchdringenden Augen? Vielleicht wollte er einen Kredit aufnehmen?";
				link.l1.go = "caleuche";
			}
		break;
		
		// калеуче
		case "caleuche":
			dialog.text = "Ich fürchte, ich kann Ihnen nicht helfen, junger Mann. Ich habe keine Ahnung, von wem Sie sprechen.";
			link.l1 = "Ich verstehe. Schade. Ich werde meine Suche fortsetzen...";
			link.l1.go = "exit";
			npchar.quest.caleuche = "true";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
