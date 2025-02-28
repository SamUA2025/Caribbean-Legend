// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Welche Art von Fragen?","Was willst du, "+GetAddress_Form(NPChar)+"?"),"Du hast mir bereits eine Frage gestellt "+GetAddress_Form(NPChar)+"...","Sie sprechen heute zum dritten Mal über eine bestimmte Frage...","Schau, wenn du mir nichts über die Angelegenheiten des Hafens zu erzählen hast, dann belästige mich nicht mit deinen Fragen.","Block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Ich habe meine Meinung geändert.","Ich habe nichts zu besprechen."),"Macht nichts.","Ja, bereits das dritte Mal...","Es tut mir leid, aber ich interessiere mich momentan nicht für die Angelegenheiten des Hafens.",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			if (pchar.questTemp.Slavetrader == "FindRatHavana")
            {
                link.l1 = "Guten Tag. Ich möchte etwas über eine Korvette namens ' erfahren."+pchar.questTemp.Slavetrader.ShipName+"' unter dem Kommando von Francois Gontier.";
                link.l1.go = "Havana_ratP_1";
			}
			// калеуче
			if (CheckAttribute(pchar, "questTemp.Caleuche") && pchar.questTemp.Caleuche == "graveyard" && !CheckAttribute(npchar, "quest.caleuche"))
			{
				link.l1 = "Entschuldigen Sie, ist ein Mann namens Joachim Merriman in Ihrem Hafen angekommen? Ein mittelalterlicher Senor, Portugiese, mit Schnurrbart, kaiserlichem Bart und durchdringenden Augen?";
				link.l1.go = "caleuche";
			}
			// Addon 2016-1 Jason пиратская линейка
			if (CheckAttribute(pchar, "questTemp.Mtraxx") && pchar.questTemp.Mtraxx == "jewelry_3" && !CheckAttribute(npchar, "quest.Mtraxx"))
			{
				link.l1 = "Ich interessiere mich für ein Schiff namens 'Cantavro'. Ich suche seinen Kapitän - Esberdo Cabanas, für eine private Angelegenheit. Könnten Sie mir helfen?";
				link.l1.go = "mtraxx";
			}
		break;
		
		case "Havana_ratP_1":
			dialog.text = NPCStringReactionRepeat("Ja, er war hier. Aber er ist schon gegangen. Frag unseren Wirt nach ihm, er hat ein Zimmer im Obergeschoss gemietet.","Sie haben bereits danach gefragt und ich habe geantwortet.","Ich sage Ihnen, dass Sie bereits nach diesem Gontier gefragt haben..","Ich bitte Sie, mich nicht zu belästigen!","Block",0,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Danke. Das werde ich tun.","Hm, nun ...","Ja, ich habe wirklich gefragt ...","Entschuldigung, "+npchar.name+"...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
		
		// калеуче
		case "caleuche":
			dialog.text = "Kann dir nichts über ihn erzählen. Selbst wenn er ankam, hat er sich nirgendwo registriert.";
			link.l1 = "Ich verstehe. Wie schade... Nun, ich werde meine Suche fortsetzen ...";
			link.l1.go = "exit";
			npchar.quest.caleuche = "true";
		break;
		
		// Addon 2016-1 Jason пиратская линейка
		case "mtraxx":
			dialog.text = "Lassen Sie uns sehen... die Schoner 'Cantavro' ist vor zwei Tagen zu einer Patrouille ausgelaufen... jedoch ist der Standort nicht aufgeführt. Es handelt sich um ein Militärschiff, daher ist das Ziel nur dem Kapitän und dem Kommandanten des Forts bekannt. Ich würde Ihnen vorschlagen, direkt mit dem Kommandanten zu sprechen, Sie können ihn im Fort finden, wenn Sie mehr wissen möchten. Leider ist das alles, was ich für Sie tun kann.";
			link.l1 = "Ich verstehe. Nun, danke für Ihre Zeit...";
			link.l1.go = "exit";
			npchar.quest.Mtraxx = "true";
			AddQuestRecord("Roger_1", "5");
			DelLandQuestMark(npchar);
			AddLandQuestMark(characterFromId("Havana_tavernkeeper"), "questmarkmain");
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
