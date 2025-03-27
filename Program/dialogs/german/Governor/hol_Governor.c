// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    ref sld;
    int i, tempQty, chComp, iShip, iBaseType;
    string tempStr;
    switch (Dialog.CurrentNode)
	{
		case "quests":
			//Португалец
			if (CheckAttribute(pchar, "questTemp.Portugal.Villemstad") && pchar.location == "villemstad_townhall")
			{
				dialog.text = RandPhraseSimple("Was wollen Sie wissen?","Was möchten Sie?");
				link.l1 = "Ich weiß, dass die Niederländische Westindia-Company einen guten Preis für den Kopf des berühmten Piraten - Bartolomeo der Portugiese - ausgesetzt hat. Ich konnte ihn fangen. Er befindet sich derzeit in meinem Schiffsladeraum und ich bin bereit, ihn den Behörden zu übergeben.";
				link.l1.go = "Portugal";
				break;
			}
            dialog.text = RandPhraseSimple("Was wollen Sie wissen??","Was benötigen Sie?");
			link.l1 = RandPhraseSimple("Nichts von Bedeutung, Herr.","Ich habe nichts zu sagen, Entschuldigung.");
		    link.l1.go = "exit";
		break;
		
		case "work_1":  // работа на благо короны - линейка нации
			if (CheckAttribute(npchar, "notQuestLine"))
			{
                dialog.text = "Leider kann ich Sie nicht für einen Auftrag in Betracht ziehen. Sie sind im Moment nicht jemand, mit dem ich zusammenarbeiten möchte. Lebewohl.";
                link.l1 = "Das kann nicht Ihr ernst sein.. aber gut.";
                link.l1.go = "exit";
				break;
			}                   
		break;
		
		//Португалец
		case "Portugal":
			dialog.text = "Bartolomeo der Portugiese?! Haben Sie ihn? Lebendig?";
			link.l1 = "Ich weiß, dass Sie ihn nicht tot brauchen. Er lebt. Ich musste mich sehr anstrengen, um ihn am Leben zu halten!";
			link.l1.go = "Portugal_1";
		break;
		
		case "Portugal_1":
			dialog.text = "Ausgezeichnet! Jetzt wird er uns alles erzählen... Mynheer, bereiten Sie den Gefangenen für den Transfer vor. Wir werden sofort eine Militärbarke zu Ihrem Schiff schicken. ";
			link.l1 = "Ich möchte zuerst über meine Belohnung sprechen, Mynheer...Wenn es Ihnen nichts ausmacht.";
			link.l1.go = "Portugal_2";
		break;
		
		case "Portugal_2":
			dialog.text = "Machen Sie sich keine Sorgen um Ihre Belohnung, Kapitän. Sie werden sie bekommen. Wir haben einen Preis für den Kopf von Bartolomeo dem Portugiesen festgesetzt - 1.500 Dublonen. Leutnant! Bringen Sie dem Kapitän seine Belohnung!";
			link.l1 = "Hm... Es scheint, dass Hugo mich um 2.000 Dublonen belogen hat... Nun gut.";
			link.l1.go = "Portugal_3";
		break;
		
		case "Portugal_3":
			TakeNItems(pchar, "gold_dublon", 1500);
			Log_Info("Sie haben 1.500 Dublonen erhalten");
			PlaySound("interface\important_item.wav");
			dialog.text = "Und nun, Kapitän, wären Sie so freundlich, den Portugiesen zur Company zu überführen. Wir können es kaum erwarten, mit ihm zu sprechen.";
			link.l1 = "Sicher, Mynheer, schicken Sie die Barke zu meinem Schiff.";
			link.l1.go = "Portugal_4";
		break;
		
		case "Portugal_4":
			DialogExit();
			DoQuestReloadToLocation("Villemstad_town", "reload", "reload1", "Portugal_Final");
			DeleteAttribute(pchar, "questTemp.Portugal.Villemstad");
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
