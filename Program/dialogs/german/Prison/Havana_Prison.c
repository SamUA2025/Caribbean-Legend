// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
 	switch(Dialog.CurrentNode)
	{
        case "quests":
            dialog.text = "Sprechen Sie, ich höre zu";
			link.l1 = "Ich habe mich geirrt. Lebewohl.";
			link.l1.go = "Exit";
			// Addon 2016-1 Jason пиратская линейка
			if (CheckAttribute(pchar, "questTemp.Mtraxx") && pchar.questTemp.Mtraxx == "jewelry_4")
			{
				link.l1 = "Offizier, es ist mir zu Ohren gekommen, dass ein Offizier des Schiffes 'Cantavro' hier festgehalten wird. Ist das korrekt?";
                link.l1.go = "Mtraxx";
			}
			if (CheckAttribute(pchar, "questTemp.Mtraxx") && pchar.questTemp.Mtraxx == "jewelry_8")
			{
				link.l1 = "Ich bin zurück, um mich erneut nach Don Lope zu erkundigen, Offizier. Haben Sie bereits seine Entlassungsbefehle erhalten?";
                link.l1.go = "Mtraxx_5";
			}
		break;
		
		// Addon 2016-1 Jason пиратская линейка
		case "Mtraxx":
            dialog.text = "Der Offizier von 'Cantavro'? Don Lope Montoro? Ja, er wird hier festgehalten. Was geht es dich an?";
			link.l1 = "Ich möchte eine Erlaubnis, ihn zu besuchen.";
			link.l1.go = "Mtraxx_1";
			DelLandQuestMark(npchar);
			AddLandQuestMark(characterFromId("Lope"), "questmarkmain");
		break;
		
		case "Mtraxx_1":
            dialog.text = "Verzeihung, aber aus welchem Grund?";
			link.l1 = "Es ist nur eine persönliche Angelegenheit. Ich kannte ihn schon in Europa und war schockiert über die Nachricht von seiner Inhaftierung und über das Gerede, das sich in der Stadt verbreitete. Ich würde gerne mit ihm sprechen.";
			link.l1.go = "Mtraxx_2";
		break;
		
		case "Mtraxx_2":
            dialog.text = "Hm...";
			link.l1 = "Offizier, vielleicht könnte ich... Ihnen 'danken', dass Sie mich ihn besuchen lassen?";
			link.l1.go = "Mtraxx_3";
		break;
		
		case "Mtraxx_3":
            dialog.text = "Es besteht keine Notwendigkeit dafür. Ich erlaube Ihnen, sich mit Don Montoro zu treffen. Die Wachen werden Sie durchlassen.";
			link.l1 = "Danke dir!";
			link.l1.go = "Mtraxx_4";
		break;
		
		case "Mtraxx_4":
			DialogExit();
            pchar.questTemp.jailCanMove = true;
			pchar.questTemp.Mtraxx = "jewelry_5";
		break;
		
		case "Mtraxx_5":
            dialog.text = "Allerdings ist meine Anweisung, don Lope Montoro direkt zum Kommandanten zu bringen. Aber ich vermute, er wird die Zelle ein paar Wochen lang nicht verlassen. Sie können ihn allerdings besuchen, solange er noch hier ist.";
			link.l1 = "Danke, Offizier, deshalb bin ich hier.";
			link.l1.go = "Mtraxx_6";
			DelLandQuestMark(npchar);
		break;
		
		case "Mtraxx_6":
            DialogExit();
            pchar.questTemp.jailCanMove = true;
			pchar.questTemp.Mtraxx = "jewelry_9";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
