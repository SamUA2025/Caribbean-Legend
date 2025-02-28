// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Welche Fragen haben Sie?","Wie kann ich Ihnen helfen?"),"Du hast versucht, mir vor einer Weile eine Frage zu stellen...","Ich habe noch nie Menschen mit solcher Neugier in meiner Werft oder sonst wo in dieser Stadt getroffen.","Was ist mit all den Fragen? Meine Aufgabe ist es, Schiffe zu bauen. Kümmern wir uns darum.","Block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Ich habe es mir anders überlegt...","Ich habe im Moment nichts zu besprechen."),"Umph, wo ist mein Gedächtnis hin...","Hm, nun ja...","Mach weiter...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			// калеуче
			if (CheckAttribute(pchar, "questTemp.Caleuche") && pchar.questTemp.Caleuche == "graveyard" && !CheckAttribute(npchar, "quest.caleuche"))
			{
				link.l1 = "Hör zu, war hier kürzlich ein Mann namens Joachim Merriman? Ein Mann mittleren Alters, Portugiese, mit Schnurrbart, kaiserlichem Bart und durchdringenden Augen? Vielleicht wollte er ein Schiff kaufen?";
				link.l1.go = "caleuche";
			}
		break;
		
		// калеуче
		case "caleuche":
			dialog.text = "Nein, Senor. Haben einen solchen Kunden nicht gesehen.";
			link.l1 = "Ich verstehe. Schade. Ich werde dann meine Suche fortsetzen...";
			link.l1.go = "exit";
			npchar.quest.caleuche = "true";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
