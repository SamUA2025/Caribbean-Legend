// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Jakie masz pytania?","Jak mogę ci pomóc, "+GetAddress_Form(NPChar)+"?"),"Czego chcesz, "+GetAddress_Form(NPChar)+"...","To już trzeci raz, kiedy mnie niepokoisz...","Więcej pytań, jak mniemam?","blokada",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Zmieniłem zdanie...","Nie mam w tej chwili nic do omówienia."),"Gdzież to moja pamięć się podziała...","Tak, to naprawdę trzeci raz...","Nie, o co chodzi?...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			//Jason, суп из черепахи
			if (CheckAttribute(PChar, "questTemp.Terrapin") && pchar.questTemp.Terrapin == "baster" && !CheckAttribute(npchar, "quest.terrapin"))
			{
				link.l1 = "Szukam mojego starego kamrata Fernanda Luca. Mam do niego kilka pytań. Słyszałem, że miał tu naprawdę niezłą zabawę tydzień temu...";
				link.l1.go = "terrapin";
			}
			//Sinistra Путеводная звезда
			if (CheckAttribute(pchar, "questTemp.PZ_BasTerTavern"))
			{
				link.l1 = "Mój przyjaciel i ja umówiliśmy się tutaj spotkać, ale nigdzie go nie widzę. Wiesz, dokąd poszedł? Czy nadal jest w mieście, czy przynajmniej na wyspie? Nazywa się Longway - jest Chińczykiem.";
				link.l1.go = "PZ_BasTerTavern_1";
			}
		break;
		
		//суп из черепахи
		case "terrapin":
			dialog.text = "Może nadal dobrze się bawi, będąc w piekle. Twój kumpel nie żyje, więc jesteś trochę spóźniony, kapitanie. Tamten człowiek, który siedzi przy najdalszym stole, zapłacił za jego pogrzeb, chociaż mam wrażenie, że to on sam go spowodował. Ma wisielczy wyraz twarzy, jak mówią. Nazywa się Robert Martene. Jeśli chcesz, możesz podejść i zapytać go sam.";
			link.l1 = "Dzięki, kumplu. Pójdę pogadać z monsieur Robertem. Napijemy się za duszę biednego starego Luca, niech jego dusza spoczywa w pokoju...";
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
			dialog.text = "Co tu omawiać? On zaatakował ciebie i twojego przyjaciela, ty się broniłeś, widzę to prawie codziennie. Dobra robota. Teraz muszę tylko posprzątać bałagan...";
			Link.l1 = "Posprzątasz to, jestem pewien, że już się do tego przyzwyczaiłeś. Co o nim wiesz?";
			Link.l1.go = "DTSG_BasTerTavern_2";
		break;
		
		case "DTSG_BasTerTavern_2":
			dialog.text = "Nie za wiele, naprawdę. Pojawił się parę dni temu. Spodobało mu się tutaj, nawet wynajął dom na obrzeżach miasta. Odwiedzał często, płacił regularnie. I, co najważniejsze, przez cały ten czas zachowywał się dobrze, nigdy nie mówiąc złego słowa nikomu. Nadal jestem w szoku, że zaatakował ciebie i twojego przyjaciela\nMyślałem, że może tu osiedli się na stałe.";
			Link.l1 = "Poniekąd tak zrobił. Cóż, to niewiele, ale dzięki za to, przyjacielu. Do zobaczenia.";
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
			
			sld = CharacterFromID("Knippel");
			LAi_SetOfficerType(sld);
			sld.Dialog.Filename = "Quest\HollandGambit\Knippel.c";
			sld.Dialog.CurrentNode = "Knippel_officer";
			sld.location = "None";
			
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
			dialog.text = "To imię nic dla mnie nie znaczy, a generalnie nie wpuszczam takich ludzi do mojego przybytku, ani się nimi nie interesuję.";
			Link.l1 = "Zgoda. Dobrze, do zobaczenia później.";
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
