// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Welche Fragen haben Sie?","Wie kann ich Ihnen helfen, "+GetAddress_Form(NPChar)+"?"),"Was ist los, "+GetAddress_Form(NPChar)+"..., Freund.","Das ist jetzt das dritte Mal, dass du mich belästigst...","Noch mehr Fragen, nehme ich an?","Block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Ich habe meine Meinung geändert...","Ich habe im Moment nichts zu besprechen."),"Umph, wo ist mein Gedächtnis hin...","Ja, es ist wirklich das dritte Mal...","Nein, welche Fragen?...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			//Jason, суп из черепахи
			if (CheckAttribute(PChar, "questTemp.Terrapin") && pchar.questTemp.Terrapin == "baster" && !CheckAttribute(npchar, "quest.terrapin"))
			{
				link.l1 = "Ich suche meinen alten Kameraden Fernand Luc. Ich habe ein paar Fragen an ihn. Ich habe gehört, dass er vor einer Woche hier eine wirklich gute Zeit hatte ...";
				link.l1.go = "terrapin";
			}
			//Sinistra Путеводная звезда
			if (CheckAttribute(pchar, "questTemp.PZ_BasTerTavern"))
			{
				link.l1 = "Mein Freund und ich haben uns hier verabredet, aber ich sehe ihn nirgendwo. Weißt du, wo er hingegangen ist? Ist er noch in der Stadt, oder zumindest auf der Insel? Sein Name ist Longway - er ist Chinese.";
				link.l1.go = "PZ_BasTerTavern_1";
			}
		break;
		
		//суп из черепахи
		case "terrapin":
			dialog.text = "Er könnte immer noch Spaß haben, während er in der Hölle ist. Ihr Kumpel ist tot, also sind Sie ein klein wenig zu spät, Kapitän. Der Mann dort drüben am fernsten Tisch hat für seine Beerdigung bezahlt, obwohl ich das Gefühl habe, dass er derselbe Mann ist, der sie verursacht hat. Er hat ein Hängergesicht, wie man so sagt. Sein Name ist Robert Martene. Wenn Sie möchten, können Sie rübergehen und ihn selbst fragen. ";
			link.l1 = "Danke, Kumpel. Ich werde ein Gespräch mit Monsieur Robert führen. Wir werden auf die Seele des armen alten Luc trinken, damit seine Seele in Frieden ruhen kann...";
			link.l1.go = "terrapin_1";
			npchar.quest.terrapin = "true";
		break;
		
		case "terrapin_1":
			DialogExit();
			AddQuestRecord("Terrapin", "4");
			pchar.questTemp.Terrapin = "rober";
		break;
		
		// Sinistra - Квест "Длинные тени старых грехов" ==>
		case "DTSG_BasTerTavern_1":
			dialog.text = "Was gibt es da zu besprechen? Er hat dich und deinen Freund angegriffen, ihr habt zurückgeschlagen, ich sehe das fast jeden Tag. Gute Arbeit. Jetzt muss ich nur noch das Durcheinander aufräumen...";
			Link.l1 = "Du wirst es aufräumen, ich bin sicher, du bist es mittlerweile gewöhnt. Was weißt du über ihn?";
			Link.l1.go = "DTSG_BasTerTavern_2";
		break;
		
		case "DTSG_BasTerTavern_2":
			dialog.text = "Nicht viel, wirklich. Er ist vor ein paar Tagen aufgetaucht. Es gefiel ihm hier, er hat sogar ein Haus am Stadtrand gemietet. Kam oft vorbei, zahlte regelmäßig. Und, am wichtigsten, er hat sich die ganze Zeit gut benommen, hat nie ein böses Wort zu jemandem gesagt. Ich bin immer noch schockiert, dass er dich und deinen Freund angegriffen hat\nIch dachte, er könnte sich hier für immer niederlassen.";
			Link.l1 = "Auf eine Art hat er das getan. Nun, das ist nicht viel, aber danke dafür, mein Freund. Wir sehen uns.";
			Link.l1.go = "DTSG_BasTerTavern_3";
		break;
		
		case "DTSG_BasTerTavern_3":
			DialogExit();
			DeleteAttribute(pchar, "questTemp.DTSG_BasTerTavern");
			LAi_LocationDisableOfficersGen("BasTer_tavern", false);
			SetQuestHeader("DTSG");
			AddQuestRecord("DTSG", "1");
			bDisableFastReload = false;
			chrDisableReloadToLocation = false;
			Return_KnippelOfficer();
			
			PChar.quest.DTSG_BasTerDom.win_condition.l1 = "locator";
			PChar.quest.DTSG_BasTerDom.win_condition.l1.location = "BasTer_town";
			PChar.quest.DTSG_BasTerDom.win_condition.l1.locator_group = "reload";
			PChar.quest.DTSG_BasTerDom.win_condition.l1.locator = "HutFish1";
			PChar.quest.DTSG_BasTerDom.win_condition = "DTSG_BasTerDom";
			
			SetTimerCondition("DTSG_BasTerDom_Timer", 0, 0, 7, false);
			SetTimerCondition("DTSG_Etap2", 0, 0, 14, false);
		break;
		// <== Квест "Длинные тени старых грехов" - Sinistra
		
		// Sinistra - Квест "Путеводная звезда" ==>
		
		case "PZ_BasTerTavern_1":
			dialog.text = "Dieser Name bedeutet mir nichts, und im Allgemeinen lasse ich Leute wie ihn nicht in mein Etablissement, noch habe ich irgendein Interesse an ihnen.";
			Link.l1 = "Gut genug. Also dann, bis später.";
			Link.l1.go = "PZ_BasTerTavern_2";
		break;
		
		case "PZ_BasTerTavern_2":
			DialogExit();
			bDisableLandEncounters = true;
			DeleteAttribute(pchar, "questTemp.PZ_BasTerTavern");
			DeleteAttribute(pchar, "questTemp.PZ_BasTerAlkash");
			pchar.questTemp.PZ_BasTerTavern2 = true;
			DeleteQuestCondition("PZ_BasTer_Opozdal");
			DelMapQuestMarkIsland("Guadeloupe");
			
			PChar.quest.PZ_BasTer_Strazha.win_condition.l1 = "location";
			PChar.quest.PZ_BasTer_Strazha.win_condition.l1.location = "BasTer_town";
			PChar.quest.PZ_BasTer_Strazha.win_condition = "PZ_BasTer_Strazha";
		break;
		
		// <== Квест "Путеводная звезда" - Sinistra
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
