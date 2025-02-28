// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat("Alle Gerüchte von "+GetCityName(npchar.city)+" zu Ihren Diensten. Was möchten Sie herausfinden?","Wir haben gerade darüber gesprochen. Du musst es vergessen haben...","Das ist das dritte Mal heute, dass du mich fragst...","Du wiederholst alles wie ein Papagei...","Block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Weißt du, "+NPChar.name+", vielleicht nächstes Mal.","Stimmt, ich habe aus irgendeinem Grund vergessen...","Ja, es ist wirklich das dritte Mal...","Jawohl...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			// Страж Истины
			if (CheckAttribute(pchar, "questTemp.Guardoftruth") && pchar.questTemp.Guardoftruth == "merdok" && !CheckAttribute(npchar, "quest.jino"))
			{
				link.l1 = "Hör mal, ist hier in dieser Stadt ein Alchemist angekommen, ein Arzt? Er ist Italiener, ungefähr dreißig Jahre alt, sein Name ist Gino Gvineili?";
				link.l1.go = "guardoftruth";
			}
			// Калеуче
			if (CheckAttribute(pchar, "questTemp.Caleuche") && pchar.questTemp.Caleuche == "hunting" && !CheckAttribute(npchar, "quest.Caleuche"))
			{
				link.l1 = "Hör zu, ich brauche einen Jäger namens Fergus Hooper. Mir wurde gesagt, dass er hier lebt. Wo kann ich ihn finden?";
				link.l1.go = "caleuche";
			}
		break;
		
		case "guardoftruth":
			dialog.text = LinkRandPhrase("Nein, haben wir nicht. Wir haben Kräuterkundige und Ärzte, aber keiner von ihnen trägt diesen Namen.","Das ist das erste Mal, dass ich einen so seltsamen Namen höre. Nein, wir hatten nie Besuch von dem Mann, von dem du sprichst.","Wir haben überhaupt keine Art von Alchemisten. Wir haben Ärzte, aber keinen mit einem solchen Namen.");
			link.l1 = "Ich verstehe. Das ist schade. Ich werde weiter suchen!";
			link.l1.go = "exit";
			npchar.quest.jino = "true";
		break;
		
		// Калеуче
		case "caleuche":
			dialog.text = "Fergus? Er besucht oft mein Platz. Aber er ist seit gestern im Dschungel. Mach dir keine Sorgen, er wird in einer Woche zurück sein, Rum trinken und mit seinen Seefahrten prahlen. Obwohl, ich gebe zu, er ist ein verdammter guter Jäger. Ich kenne niemanden, der so gut Schlangen fangen kann wie er.";
			link.l1 = "Schlangen? Hm. Wann sollte ich hierher zurückkommen, um ihn zu finden?";
			link.l1.go = "caleuche_1";
		break;
		
		case "caleuche_1":
			dialog.text = "Drei Tage mindestens. Sei dir bewusst, dass er immer erst nach sechs Uhr abends hierher kommt und nicht später als zehn geht.";
			link.l1 = "Wie sieht er aus? Habe ihn noch nie gesehen.";
			link.l1.go = "caleuche_2";
		break;
		
		case "caleuche_2":
			dialog.text = "Bärtig, mittleren Alters, trägt braunen Mantel, Hut und lange Stiefel.";
			link.l1 = "Danke! Du hast mir sehr geholfen, Kumpel. Wir sehen uns!";
			link.l1.go = "caleuche_3";
		break;
		
		case "caleuche_3":
			DialogExit();
			AddQuestRecord("Caleuche", "8");
			int iTerms = sti(pchar.questTemp.Caleuche.Belizterms);
			SetFunctionTimerCondition("Caleuche_FergusCome", 0, 0, iTerms, false);
			npchar.quest.Caleuche = "true";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
