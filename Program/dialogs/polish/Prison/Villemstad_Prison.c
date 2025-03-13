// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
 	switch(Dialog.CurrentNode)
	{
        case "quests":
            dialog.text = "Mów, słucham.";
			link.l1 = "Pomyliłem się. Żegnaj.";
			link.l1.go = "Exit";
			//Португалец
			if (CheckAttribute(pchar, "questTemp.Portugal") && pchar.questTemp.Portugal == "PortugalInPrison")
            {
                link.l1 = "Oficerze, trzymacie tu więźnia o imieniu Bartolomeo Portugalczyk...";
                link.l1.go = "Portugal";
            }
		break;
		
		//Португалец
		case "Portugal":
			dialog.text = "Tak jest. A dlaczego ci to obchodzi? Tylko wysłannicy Holenderskiej Kompanii Zachodnioindyjskiej mogą go zobaczyć i to tylko na pisemny rozkaz gubernatora. Jeden z oficerów Kompanii przesłuchuje teraz tego pirata. Więc jeśli przyszedłeś tu tylko po to, by go zobaczyć, lepiej się oddal, zobaczysz go, gdy będzie wisiał, teraz odejdź.";
			link.l1 = "Przyszedłem tu nie po to, aby go zobaczyć.";
			link.l1.go = "Portugal_1";
		break;
		
		case "Portugal_1":
			dialog.text = "Dlaczego więc, jeśli mogę zapytać?";
			link.l1 = "Przyszedłem tutaj... by go uwolnić!";
			link.l1.go = "fight";
			chrDisableReloadToLocation = true;
			//pchar.quest.InMarigoResidenceOver.over = "yes"; //снять таймер
			InterfaceStates.Buttons.Save.enable = false;//запретить сохраняться
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
