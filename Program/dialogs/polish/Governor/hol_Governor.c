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
				dialog.text = RandPhraseSimple("Jakie pytania?","Czego sobie życzysz?");
				link.l1 = "Wiem, że Holenderska Kompania Zachodnioindyjska wyznaczyła dobrą nagrodę za głowę słynnego pirata - Bartolomeo Portugalczyka. Udało mi się go schwytać. Obecnie znajduje się w ładowni mojego statku i jestem gotów przekazać go władzom.";
				link.l1.go = "Portugal";
				break;
			}
            dialog.text = RandPhraseSimple("Jakie pytania?","Czego potrzebujesz?");
			link.l1 = RandPhraseSimple("Nic ważnego, Sir.","Nie mam nic do powiedzenia, przepraszam.");
		    link.l1.go = "exit";
		break;
		
		case "work_1":  // работа на благо короны - линейка нации
			if (CheckAttribute(npchar, "notQuestLine"))
			{
                dialog.text = "Niestety, nie mogę zaoferować ci pracy. Nie jesteś osobą, z którą chciałbym teraz współpracować. Żegnaj.";
                link.l1 = "Nie możesz być poważny... ale dobrze.";
                link.l1.go = "exit";
				break;
			}                   
		break;
		
		//Португалец
		case "Portugal":
			dialog.text = "Bart Portugalczyk?! Masz go? Żywego?";
			link.l1 = "Wiem, że nie potrzebujesz go martwego. Jest żywy. Musiałem się bardzo postarać, aby tak pozostało!";
			link.l1.go = "Portugal_1";
		break;
		
		case "Portugal_1":
			dialog.text = "Najwspanialej! Teraz powie nam wszystko... Panie, przygotuj więźnia do transportu. Natychmiast wyślemy wojskową barkę na twój statek.";
			link.l1 = "Najpierw chciałbym porozmawiać o mojej nagrodzie, Mynheer... Jeśli nie masz nic przeciwko.";
			link.l1.go = "Portugal_2";
		break;
		
		case "Portugal_2":
			dialog.text = "Nie martw się o swoją nagrodę, kapitanie. Otrzymasz ją. Wyznaczyliśmy nagrodę za głowę Bartolomeo Portugalczyka - tysiąc pięćset dublonów. Poruczniku! Przynieś kapitanowi jego nagrodę!";
			link.l1 = "Hm... Wygląda na to, że Hugo skłamał mi o dwa tysiące dubloonów... Dobrze więc.";
			link.l1.go = "Portugal_3";
		break;
		
		case "Portugal_3":
			TakeNItems(pchar, "gold_dublon", 1500);
			Log_Info("You have received 1500 doubloons");
			PlaySound("interface\important_item.wav");
			dialog.text = "A teraz, kapitanie, bądź tak uprzejmy i przekaż Portugalczyka Kompanii. Nie możemy się doczekać, by z nim porozmawiać.";
			link.l1 = "Tak, panie, wyślij barka do mojego statku.";
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
