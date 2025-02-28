// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Was wollen Sie? Fragen Sie ruhig.","Ich höre Ihnen zu, was ist die Frage?"),"Dies ist das zweite Mal, dass Sie versuchen zu fragen...","Das ist das dritte Mal, dass Sie versuchen zu fragen...","Wann wird das enden?! Ich bin ein beschäftigter Mann, der an Kolonieangelegenheiten arbeitet und du belästigst mich immer noch!","Block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Ich habe meine Meinung geändert...","Nicht jetzt. Falscher Ort und Zeit."),"Wahr... Aber später, nicht jetzt...","Ich werde fragen... Aber ein bisschen später...","Es tut mir leid, "+GetAddress_FormToNPC(NPChar)+"...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			// Jason НСО
			if (CheckAttribute(pchar, "questTemp.Patria") && pchar.questTemp.Patria == "epizode_2" && !CheckAttribute(npchar, "quest.patria") && !CheckAttribute(pchar, "questTemp.Patria.Visiter_Late"))
			{
				link.l1 = TimeGreeting()+"Mein Herr. Ich bin hier auf Befehl des Generalgouverneurs Chevalier de Poincy. Meine Aufgabe besteht darin, einen Baron namens Noel Forget nach Tortuga zu bringen, der aus der Mutterkolonie kam, um die Kolonien zu inspizieren. Sein Hauptzweck ist die Gründung einer Französischen Westindien-Handelsgesellschaft. Erlauben Sie mir, ihn Ihnen vorzustellen... Er wird alle Einzelheiten selbst erklären.";
                link.l1.go = "patria_portpax";
			}
			// Rebbebion, квест "Путеводная звезда"
			if (CheckAttribute(pchar, "questTemp.PZ.PortPaxMayorTalk"))
			{
				link.l1 = "Eure Lordschaft, Ihr wolltet mich sehen?";
				link.l1.go = "PZ1";
			}
		break;

		case "Cupture_after":
            dialog.text = RandPhraseSimple("Sie haben bereits alles genommen. Was wollen Sie noch?","Gibt es noch etwas, was Sie nicht gegriffen haben?");
            link.l1 = RandPhraseSimple("Nur ein wenig umsehen...","Nur zur Kontrolle, ich könnte vergessen, etwas mitzunehmen...");
            link.l1.go = "exit";
            NextDiag.TempNode = "Cupture_after";
		break;
		
		// Jason НСО
		case "patria_portpax":
			dialog.text = "Es freut mich sehr, Sie kennenzulernen, Kapitän Charles de Maure, und der Baron. Ich werde alles tun, damit Monsieur Forgets Aufenthalt in unserer Kolonie so angenehm wie möglich ist. Und da ein so hochrangiger Monsieur mich besucht hat, werde ich Sie um eine Angelegenheit bitten.";
			link.l1 = "Sehr interessant! Erzählen Sie uns von Ihrer Angelegenheit, Euer Gnaden.";
			link.l1.go = "patria_portpax_1";
		break;
		
		case "patria_portpax_1":
			dialog.text = "In den letzten Monaten hat unsere Kolonie keinen Vertreter des Generalgouverneurs besucht, als hätten sie uns in Saint Kitts völlig vergessen! Und in der Zwischenzeit bereiten sich die Spanier, die bestrebt sind, ganz Hispaniola rein spanisch zu machen und für die die französischen Siedler und Freibeuter im Westen der Insel eine große Belästigung sind, auf einen Angriff vor! Meine Patrouillenoffiziere, unsere Handelskapitäne und sogar gewöhnliche Fischer haben berichtet, dass sich eine mächtige spanische Geschwader in Santiago versammelt und sich darauf vorbereitet, Port-au-Prince anzugreifen!";
			link.l1 = "Ist die Beweise klar genug, Eure Majestät?";
			link.l1.go = "patria_portpax_2";
		break;
		
		case "patria_portpax_2":
			dialog.text = "Ich habe keine genauen Informationen, aber so viele Informationen von völlig zufälligen Leuten können keine bloßen Gerüchte sein. Unsere Kolonie ist für Frankreich sehr wichtig, wir haben hier die besten Plantagen, die der Baron persönlich sehen kann. Diese Kolonie zu verlieren oder sogar das Risiko einzugehen, geplündert zu werden, ist inakzeptabel!";
			link.l1 = "Ich werde Ihre Beweise berücksichtigen und den Chevalier de Poincy informieren. Ich bin sicher, dass er sofort Maßnahmen ergreifen wird.";
			link.l1.go = "patria_portpax_3";
		break;
		
		case "patria_portpax_3":
			dialog.text = "Danke, Kapitän...";
			link.l1 = "";
			link.l1.go = "patria_portpax_4";
		break;
		
		case "patria_portpax_4":
			DialogExit();
			sld = characterFromId("Noel");
			sld.dialog.currentnode = "noel_9";
			ChangeCharacterAddressGroup(sld, pchar.location, "goto", "governor1");
			LAi_SetActorType(sld);
			LAi_ActorDialogDelay(sld, pchar, "", 1.0);
			npchar.quest.patria = "true";
		break;
		
		case "PZ1":
			DeleteAttribute(pchar, "questTemp.PZ.PortPaxMayorTalk");
			dialog.text = "Nein, ich habe Sie nicht gerufen, Monsieur. Wollten Sie etwas?";
			link.l1 = "How could I? But your messenger met us; he said you had prepared one of the houses in the town for me...";
			link.l1.go = "PZ2";
			DelLandQuestMark(npchar);
		break;
		
		case "PZ2":
			dialog.text = "Welches Haus, welcher Bote, was ist diese Unverschämtheit?!";
			link.l1 = "Was meinen Sie, welcher Bote... Sein Name ist Henri Thibaut, und...";
			link.l1.go = "PZ3";
		break;
		
		case "PZ3":
			dialog.text = "WAS? Kennen Sie überhaupt seine Identität? Anscheinend nicht. Aber das spielt keine Rolle. Was macht der Neffe von Levasseur in meiner Stadt?";
			link.l1 = "Oh, mein Gott...";
			link.l1.go = "PZ4";
		break;
		
		case "PZ4":
			dialog.text = "De Maure, kannst du mich hören? Herr?";
			link.l1 = "...";
			link.l1.go = "PZ5";
		break;
		
		case "PZ5":
			DialogExit();
			LAi_SetActorType(pchar);
			LAi_ActorRunToLocator(pchar, "reload", "reload1", "PZ_SharleBezhitObratno", -1);
			bDisableCharacterMenu = true;
			InterfaceStates.Buttons.Save.enable = false;
			SetMusic("music_teleport");
			pchar.questTemp.lockedMusic = true;
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
