// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{

	switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat("Mach weiter, was willst du?","Wir haben gerade darüber gesprochen. Du musst es vergessen haben...","Das ist das dritte Mal heute, dass du von irgendeiner Frage sprichst...","Hör zu, das ist ein Laden. Leute kaufen hier Sachen. Stör mich nicht!","Block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Du weißt, "+NPChar.name+", vielleicht nächstes Mal.","Richtig, aus irgendeinem Grund habe ich vergessen...","Ja, es ist wirklich das dritte Mal...","Hm, ich werde nicht...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			// калеуче
			if (CheckAttribute(pchar, "questTemp.Caleuche") && pchar.questTemp.Caleuche == "graveyard" && !CheckAttribute(npchar, "quest.caleuche"))
			{
				link.l1 = "Hör zu, ist jemals ein Mann namens Joachim Merriman hier in deinem Geschäft gewesen? Ein mittelalterlicher Senor, Portugiese, mit Schnurrbart, kaiserlichem Bart und durchdringenden Augen? Vielleicht etwas gekauft?";
				link.l1.go = "caleuche";
			}
		break;
		
		// калеуче
		case "caleuche":
			dialog.text = "Nein, keiner meiner Kunden sieht so aus, wie Sie es beschrieben haben. Außerdem habe ich diesen Namen noch nie gehört. Es tut mir leid, ich kann Ihnen nicht weiterhelfen.";
			link.l1 = "Ich verstehe. Schade. Nun, ich werde meine Suche fortsetzen...";
			link.l1.go = "exit";
			npchar.quest.caleuche = "true";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);
}
