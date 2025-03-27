// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Welche Art von Fragen?","Was willst du, "+GetAddress_Form(NPChar)+"?"),"Du hast mich schon einmal eine Frage gestellt "+GetAddress_Form(NPChar)+"..., Freund.","Sie sprechen heute zum dritten Mal über eine bestimmte Frage ...","Schau, wenn du mir nichts über die Angelegenheiten des Hafens zu erzählen hast, dann belästige mich nicht mit deinen Fragen.","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Ich habe meine Meinung geändert.","Ich habe nichts zum Reden."),"Macht nichts.","Gewiss, schon das dritte Mal...","Entschuldigung, aber ich interessiere mich momentan nicht für die Angelegenheiten des Hafens.",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
		
		// НСО пошив мундира Xenon-->
		case "Tailor":
			dialog.text = "Ja, ich verstehe Sie perfekt, schreien Sie nicht so. Aber ich habe bereits erklärt - diesmal gab es viel mehr Korrespondenz und Post als sonst. Machen Sie sich keine Sorgen, Ihre Materialien werden nicht verschwinden und werden mit dem nächsten Kurierschiff geliefert.";
			link.l1 = "...";
			link.l1.go = "Tailor_01";
		break;
		
		case "Tailor_01":
			DialogExit();
			sld = characterFromId("Patria_Tailor");
			sld.dialog.currentnode = "Tailor_02";
			Lai_SetPlayerType(pchar);
			LAi_SetActorType(sld);
			LAi_ActorDialogNow(sld, pchar, "", -1);
		break;
		
		case "Tailor_02":
			dialog.text = "Nun, offensichtlich gab es wichtigere Pakete. Und das Schiff kann nicht überladen werden. Allerdings bin ich nicht über die Verteilung der Post informiert. Ich bitte Sie, sich bitte zu beruhigen und nicht nervös zu werden. Ich wiederhole: Alle Ihre Materialien werden intakt ankommen, nur etwas später.";
			link.l1 = "...";
			link.l1.go = "Tailor_03";
		break;
		
		case "Tailor_03":
			npchar.dialog.currentnode = "First time";
			DialogExit();
			Lai_SetPlayerType(pchar);
			sld = characterFromId("Patria_Tailor");
			sld.dialog.currentnode = "Tailor_04";
			LAi_SetActorType(sld);
			LAi_ActorDialogNow(sld, pchar, "", -1);
		break;
		// <-- пошив мундира
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
