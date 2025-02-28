// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Fragen, "+GetAddress_Form(NPChar)+"?","Wie kann ich Ihnen helfen, "+GetAddress_Form(NPChar)+"?"),""+GetSexPhrase("Hm, was ist die große Idee, "+GetAddress_Form(NPChar)+"? ","Wieder mit den seltsamen Fragen? Toots, geh und trink etwas Rum oder so...")+"","Über den ganzen Tag hinweg ist dies das dritte Mal, dass du von irgendeiner Frage sprichst..."+GetSexPhrase(" Sind das einige Zeichen der Aufmerksamkeit?","")+"","Noch mehr Fragen, nehme ich an, "+GetAddress_Form(NPChar)+"?","Block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Ich habe meine Meinung geändert","Ich habe im Moment nichts zu besprechen."),"Nein, nein Schöne...","Keine Chance, Liebchen...","Nein, welche Fragen?...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			if (pchar.questTemp.Slavetrader == "FindRatJamaica_W")
            {
                link.l1 = "Hör zu, Frau, sie sagen, du warst meinem alten Kumpel Francois Gontier sehr nahe. Wirklich nahe...";
                link.l1.go = "Jamaica_ratW_1";
            }
			
			if (pchar.questTemp.Slavetrader == "FindRatJamaica_WP")
            {
				if (CheckCharacterItem(pchar, "jewelry43"))
				{
					link.l1 = "Ich habe deine Halskette mit Edelsteinen gebracht. Hier, nimm sie. Gott schütze mich in Zukunft vor habgierigen Frauen wie dir.";
					link.l1.go = "Jamaica_ratW_5";
				}
				else
				{
					link.l1 = "Nichts im Moment. Ich suche nach deiner Halskette.";
					link.l1.go = "exit";
				}
            }
			
		break;
		
		case "Jamaica_ratW_1":
            dialog.text = "Ja, das waren wir. Was soll's? Ich bin keine verheiratete Frau und verbringe meine Zeit mit wem ich will. Francois ist ein sehr respektabler Seemann, nicht wie unsere lokalen Fischer und Bauern. Er ist so... Oh! Und er hat mir solch schöne Geschenke gemacht!";
            link.l1 = "In Ordnung, das reicht! Ich kenne die Qualitäten meines Kumpels, ihr braucht sie mir nicht aufzuzählen. Mir ist egal, was zwischen euch beiden passiert ist. Ihr könntet sogar heiraten, das ist mir egal. Ich muss ihn sofort finden, verstanden? Wisst ihr, wohin er aufgebrochen ist?";
            link.l1.go = "Jamaica_ratW_2";
        break;
		
		case "Jamaica_ratW_2":
            dialog.text = "Tee hee... Du bist sein Kamerad, und du weißt nicht, wohin er aufgebrochen ist. Das ist lustig!";
            link.l1 = "Es ist nichts zum Lachen, Frau. Wir hatten vereinbart, uns auf Jamaika zu treffen und dann wartete eine gemeinsame Reise auf uns... wenn du verstehst, was ich meine. Ich werde das alleine nicht schaffen und er ist Gott weiß wohin abgesetzt!";
            link.l1.go = "Jamaica_ratW_3";
        break;
		
		case "Jamaica_ratW_3":
            dialog.text = "Ich verstehe. Nun, wenn eine so profitable Reise für Sie vor der Tür steht, da Sie und Francois Freunde sind... Ich werde Ihnen sagen, wohin er aufgebrochen ist, aber für eine kleine Belohnung.";
            link.l1 = "Jawohl, ich kenne die Spielregeln. Wie viel willst du?";
            link.l1.go = "Jamaica_ratW_4";
        break;
		
		case "Jamaica_ratW_4":
            dialog.text = "Oh, wie käuflich! Ich brauche kein Geld. Nein, ich will etwas Besonderes. Francois hat versprochen, mir eine schöne Halskette mit Edelsteinen zu geben. Ich habe es bereits meinen Freunden vorgeprahlt und er ist gleich weggegangen... Bring mir den Anhänger und ich sage dir, wohin er aufgebrochen ist, he-he!";
            link.l1 = "Du freche Schlampe! Ihr niederländischen Weiber seid so gierig wie sie kommen! Gut, du bekommst deine Halskette.";
            link.l1.go = "exit";
			AddQuestRecord("Slavetrader", "21_5");
			pchar.questTemp.Slavetrader = "FindRatJamaica_WP";
        break;
		
		case "Jamaica_ratW_5":
            dialog.text = "Ach, es ist wunderschön! Jetzt können meine Freunde vor Neid ergrünen!";
            link.l1 = "Sende ihnen mein Beileid. Jetzt fang an zu reden. Wohin ist Francois aufgebrochen?";
            link.l1.go = "Jamaica_ratW_6";
			RemoveItems(PChar, "jewelry43", 1);
        break;
		
		case "Jamaica_ratW_6":
            dialog.text = "Ja, natürlich, Herr. Francois ist in Richtung Kuba, nach Havanna, gesegelt.";
            link.l1 = "Danke für den teuren Tipp, Dirne. Das ist alles, was ich wollte.";
            link.l1.go = "exit";
			AddQuestRecord("Slavetrader", "21_6");
			pchar.questTemp.Slavetrader = "FindRatHavana";
        break;
		
		
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
