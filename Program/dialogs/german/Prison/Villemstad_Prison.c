// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
 	switch(Dialog.CurrentNode)
	{
        case "quests":
            dialog.text = "Sprechen Sie, ich höre zu";
			link.l1 = "Ich habe mich geirrt. Lebewohl.";
			link.l1.go = "Exit";
			//Португалец
			if (CheckAttribute(pchar, "questTemp.Portugal") && pchar.questTemp.Portugal == "PortugalInPrison")
            {
                link.l1 = "Offizier, Sie halten hier einen Gefangenen namens Bartolomeo der Portugiese...";
                link.l1.go = "Portugal";
            }
		break;
		
		//Португалец
		case "Portugal":
			dialog.text = "Wir tun es. Und warum interessiert es dich? Nur Gesandte der Niederländischen Westindien-Kompanie dürfen ihn sehen und nur auf schriftlichen Befehl des Gouverneurs. Einer der Offiziere der Kompanie verhört diesen Piraten gerade jetzt. Also wenn du nur hierher gekommen bist, um ihn zu sehen, solltest du besser gehen, du wirst ihn sehen, wenn er hängt, jetzt geh weg.";
			link.l1 = "Ich bin nicht hier, um ihn zu sehen.";
			link.l1.go = "Portugal_1";
		break;
		
		case "Portugal_1":
			dialog.text = "Warum dann, wenn ich fragen darf?";
			link.l1 = "Ich bin hierher gekommen... um ihn zu befreien!";
			link.l1.go = "fight";
			chrDisableReloadToLocation = true;
			//pchar.quest.InMarigoResidenceOver.over = "yes"; //снять таймер
			InterfaceStates.Buttons.Save.enable = false;//запретить сохраняться
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
