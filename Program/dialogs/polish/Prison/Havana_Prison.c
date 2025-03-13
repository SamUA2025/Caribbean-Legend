// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
 	switch(Dialog.CurrentNode)
	{
        case "quests":
            dialog.text = "Mów, słucham";
			link.l1 = "Pomyliłem się. Żegnaj.";
			link.l1.go = "Exit";
			// Addon 2016-1 Jason пиратская линейка
			if (CheckAttribute(pchar, "questTemp.Mtraxx") && pchar.questTemp.Mtraxx == "jewelry_4")
			{
				link.l1 = "Oficerze, doszły mnie słuchy, że oficer ze statku 'Cantavro' jest tutaj przetrzymywany. Czy to prawda?";
                link.l1.go = "Mtraxx";
			}
			if (CheckAttribute(pchar, "questTemp.Mtraxx") && pchar.questTemp.Mtraxx == "jewelry_8")
			{
				link.l1 = "Powróciłem, by ponownie zapytać o don Lope, oficerze. Czy otrzymaliście już rozkazy o jego uwolnieniu?";
                link.l1.go = "Mtraxx_5";
			}
		break;
		
		// Addon 2016-1 Jason пиратская линейка
		case "Mtraxx":
            dialog.text = "Oficer z 'Cantavro'? Don Lope Montoro? Tak, jest tu zatrzymany. Co cię to obchodzi?";
			link.l1 = "Chciałbym uzyskać pozwolenie na wizytę u niego.";
			link.l1.go = "Mtraxx_1";
			DelLandQuestMark(npchar);
			AddLandQuestMark(characterFromId("Lope"), "questmarkmain");
		break;
		
		case "Mtraxx_1":
            dialog.text = "Proszę o wybaczenie, ale na jakiej podstawie?";
			link.l1 = "To tylko osobista sprawa. Znałem go jeszcze w Europie i byłem wstrząśnięty wiadomością o jego uwięzieniu oraz plotkami, które krążyły po całym mieście. Chciałbym z nim porozmawiać.";
			link.l1.go = "Mtraxx_2";
		break;
		
		case "Mtraxx_2":
            dialog.text = "Hm...";
			link.l1 = "Oficerze, może mógłbym... 'podziękować' ci za umożliwienie mi odwiedzenia go?";
			link.l1.go = "Mtraxx_3";
		break;
		
		case "Mtraxx_3":
            dialog.text = "Nie ma takiej potrzeby. Pozwalam ci spotkać się z don Montoro. Strażnicy cię przepuszczą.";
			link.l1 = "Dziękuję!";
			link.l1.go = "Mtraxx_4";
		break;
		
		case "Mtraxx_4":
			DialogExit();
            pchar.questTemp.jailCanMove = true;
			pchar.questTemp.Mtraxx = "jewelry_5";
		break;
		
		case "Mtraxx_5":
            dialog.text = "Rzeczywiście, moim rozkazem jest dostarczenie don Lope Montoro bezpośrednio do komendanta. Ale przypuszczam, że nie opuści celi przez kilka tygodni. Możesz jednak go odwiedzić, póki jeszcze tu jest.";
			link.l1 = "Dziękuję, oficerze, dlatego jestem tutaj.";
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
