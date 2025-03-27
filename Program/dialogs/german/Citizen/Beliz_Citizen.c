// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
            dialog.text = RandPhraseSimple("Was für Fragen?","Was möchten Sie?");
			link.l1 = RandPhraseSimple("Ah, ich habe meine Meinung geändert.'","Ich habe im Moment nichts zu sagen.");
		    link.l1.go = "exit";
			// Rebbebion, квест "Путеводная звезда" ==>
			if (CheckAttribute(pchar, "questTemp.Beliz.AskForLatterAndSotta") && !CheckAttribute(npchar, "questTemp.Sotta") && !CheckAttribute(npchar, "questTemp.Lutter"))
			{
				if (rand(1) == 0)
				{
					link.l1 = "Sind Sie zufällig Kapitän Edgardo Sotta begegnet? Können Sie mir etwas über ihn erzählen? Er klingt wie ein Mann, den man kennen sollte.";
					link.l1.go = "Sotta1";
					link.l2 = "Gehen Sie nicht zur Hinrichtung dieses Windbeutels?";
					link.l2.go = "Lutter1";
				}
				else
				{
					link.l1 = "Sagen Sie, haben Sie den Helden des Tages, Kapitän Edgardo Sotta, gesehen? Ich habe ihn leider verpasst. Wie ist er so? Ich kann nicht glauben, dass ein Kaufmann den berüchtigten Schwätzer Matt gefangen hat!";
					link.l1.go = "Sotta1_1";
					link.l2 = "Ich sehe, die ganze Stadt feiert Lutters Gefangennahme, sogar diejenigen, die nie zur See fahren."link.l2.go ="Lutter1_1";
				}
			}
			// <== квест "Путеводная звезда"
		break;
		
		case "info":
        // заменить на описание неких НПС, по квестам
			dialog.text = "Glauben Sie, ich arbeite für den Geheimdienst von "+NationNameGenitive(sti(NPChar.nation))+"?";
			link.l1 = "Nun... nein. Leben Sie wohl.";
			link.l1.go = "exit";
			link.l2 = "Haben Sie noch eine andere Frage?";
			link.l2.go = "new question";
		break;
		
		case "town":
        // заменить на описание как пройти, по квестам
			dialog.text = "Sehe ich aus wie das Untersuchungsbüro? Ich weiß es nicht, ich weiß gar nichts.";

            link.l1 = "Sie sind ein Wirrkopf! Verschwinden Sie.";
			link.l1.go = "exit";
			link.l2 = "Haben Sie noch eine andere Frage?";
			link.l2.go = "new question";
		break;
		
		// Квест "Путеводная звезда" ==>
		case "Sotta1":
			dialog.text = "Ich habe nicht mit ihm gesprochen, aber ich habe sein Schiff gesehen - eine schwere Galeone. Es ist gefährlich, in diesen Gewässern alleine zu segeln, aber Sotta kommt ohne Eskorte aus.";
			link.l1 = "Wahrscheinlich jagt er jeder Goldmünze nach und spart Kosten, wo er kann. Nun, ich will Sie nicht aufhalten. Guten Tag.";
			link.l1.go = "Exit";
			
			npchar.questTemp.Sotta = true;
			pchar.questTemp.PZ_BelizAskCitizens = sti(pchar.questTemp.PZ_BelizAskCitizens) + 1;
			AddDialogExitQuest("PZ_LongwayBelizDialog");
		break;
		
		case "Sotta1_1":
			dialog.text = "Ja, es ist schwer zu glauben! Aber schenken Sie nicht allem, was Sie hören, Glauben, Herr. Ich habe ihn gesehen, so klar wie ich Sie jetzt sehe. Es ist gut, dass er Lutter gefangen hat, aber warum diese ganze Kaufmannsmasche? Er verhält sich wie ein Soldat. Ich erkenne das sofort - ein Verwandter von mir hat jahrelang gedient.";
			link.l1 = "Interessant. Nun, jeder hat seine Geheimnisse. Ich sollte besser gehen. Danke für die Informationen.";
			link.l1.go = "Exit";
			
			npchar.questTemp.Sotta = true;
			pchar.questTemp.PZ_BelizAskCitizens = sti(pchar.questTemp.PZ_BelizAskCitizens) + 1;
			AddDialogExitQuest("PZ_LongwayBelizDialog");
		break;
		
		case "Lutter1":
			dialog.text = "Ich habe den Mann bereits gesehen. Es ist schwer zu glauben, dass dies derselbe Pirat sein soll, der unsere Händler jahrelang terrorisierte. Wie hat er überhaupt das Kommando erhalten? Ich sah die Soldaten, die ihn eskortierten - schreiend, weinend, lachend. Ein Wahnsinniger.";
			link.l1 = "Vielleicht waren die Niederlage und die Realität seines bevorstehenden Todes zu viel für ihn. Aber das spielt keine Rolle. Auf Wiedersehen!";
			link.l1.go = "Exit";
			
			npchar.questTemp.Lutter = true;
			pchar.questTemp.PZ_BelizAskCitizens = sti(pchar.questTemp.PZ_BelizAskCitizens) + 1;
			AddDialogExitQuest("PZ_LongwayBelizDialog");
		break;
		
		case "Lutter1_1":
			dialog.text = "Ja, und ich feiere auch - eine gute Anzahl meiner Landsleute starb durch seine Hände. Die Unglücklichen verloren einen Vater, einen Bruder, einen Sohn - Sie verstehen, was ich meine. Diese Barbarei dauerte zu lange! Matt muss einer der Piraten mit der größten Glückssträhne der letzten Jahre gewesen sein, wenn Sie mich fragen.";
			link.l1 = "Früher oder später endet die Glückssträhne immer. Bis dann.";
			link.l1.go = "Exit";
			
			npchar.questTemp.Lutter = true;
			pchar.questTemp.PZ_BelizAskCitizens = sti(pchar.questTemp.PZ_BelizAskCitizens) + 1;
			AddDialogExitQuest("PZ_LongwayBelizDialog");
		break;
		// <== Квест "Путеводная звезда"
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
