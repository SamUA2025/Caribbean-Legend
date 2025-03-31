// диалог официантки
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
    // вызов диалога по городам -->
    NPChar.FileDialog2 = "DIALOGS\" + LanguageGetLanguage() + "\Tavern\" + NPChar.City + "_Waitress.c";
    if (LoadSegment(NPChar.FileDialog2))
	{
        ProcessCommonDialog(NPChar, Link, NextDiag);
		UnloadSegment(NPChar.FileDialog2);
	}
    // вызов диалога по городам <--
	switch(Dialog.CurrentNode)
	{
        case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		case "First time":
			//--> Jason Цена чахотки
			if (CheckAttribute(pchar, "questTemp.HWIC.Detector") || SandBoxMode)
			{
				bool bOk1 = (pchar.questTemp.HWIC.Detector == "holl_win") || (pchar.questTemp.HWIC.Detector == "eng_win") || (pchar.questTemp.HWIC.Detector == "self_win") || SandBoxMode;
				if (sti(pchar.rank) > 6 && npchar.location == "PortSpein_tavern" && !CheckAttribute(npchar, "quest.Consumption")  && bOk1)
				{
					dialog.text = "Co pan sobie życzy, senor? Przykro mi, że tylko...'szlocha'... oh... Przykro mi.";
					link.l1 = "Dlaczego jesteś tak zmartwiona, pani? Łzy na tak pięknej twarzy? Co się stało?";
					link.l1.go = "Consumption";
					break;
				}
			}
			//<-- Цена чахотки
			
			// Addon-2016 Jason, французские миниквесты (”ЊЉ) Џорт Џренс
			if (npchar.location == "PortPax_tavern" && CheckAttribute(pchar, "questTemp.FMQP") && pchar.questTemp.FMQP == "begin")
            {
				DelMapQuestMarkCity("PortPax");
				DelLandQuestMark(npchar);
				PlaySound("Voice\English\Enc_RapersGirl_1.wav");
				dialog.text = "Pan! Panie, pomóż! Mordują!";
				link.l1 = "Hę? Mordować kogo? Gdzie? To jakiś żart, droga?";
				link.l1.go = "FMQP";
				break;
			}
            NextDiag.TempNode = "First time";
			if (CheckAttribute(pchar, "questTemp.different.FackWaitress"))
			{
				if (pchar.questTemp.different == "FackWaitress_toRoom" || pchar.questTemp.different == "FackWaitress_toRoomUp")
				{
					dialog.text = "Poprosiłem cię, żebyś poszedł na górę. Nie stój tutaj i nie zwracaj na siebie uwagi.";
					link.l1 = "Dobrze, idę, nie chcę cię wrobić...";
					link.l1.go = "exit";
				}
				if (pchar.questTemp.different == "FackWaitress_noMoney" || pchar.questTemp.different == "FackWaitress_fighted")
				{
					dialog.text = "Jestem tu nowy, więc proszę, nie rozpraszaj mnie od mojej pracy. Nadal nie mogę się do tego przyzwyczaić...";
					link.l1 = "A gdzie jest kelnerka, która pracowała tu przed tobą?"+pchar.questTemp.different.FackWaitress.Name+", jak sobie przypominam...";
					link.l1.go = "Love_IDN";
				}
				if (pchar.questTemp.different == "FackWaitress_facking")
				{					
					dialog.text = "Przyjdź jeszcze raz, kochanie. Możemy znów się zabawić. Gdybym miała więcej wolnego czasu...";
					link.l1 = "Pewnie, byłeś wspaniały!";
					link.l1.go = "exit";
				}
				if (pchar.questTemp.different == "FackWaitress_fackNoMoney")
				{					
					dialog.text = "Nie znam cię, więc nie zawracaj mi głowy...";
					link.l1 = "Gdzie są moje pieniądze?!!";
					link.l1.go = "Love_IDN_1";
				}
				break;
			}
		    switch (Rand(4))
			{
				case 0:
					dialog.text = "Przykro mi, "+GetSexPhrase("przystojniak","ładniutki")+", Jestem teraz zbyt zajęty. To dobry czas na karczmę, ale nie na rozmowy!";
					link.l1 = "...";
					link.l1.go = "exit";
				break;

				case 1:
					dialog.text = "Proszę, kapitanie, nie walcz tutaj! To ciężka praca, aby posprzątać to miejsce.";
					link.l1 = ""+GetSexPhrase("Hm... Nawet nie zamierzałem.","Czy wyglądam na pijaka szukającego bójki? Jestem tylko dziewczyną, taką samą jak ty, nie martw się.")+"";
					link.l1.go = "exit";
				break;

				case 2:
					if (drand(1) == 0) // Addon-2016 Jason
					{
						dialog.text = ""+GetSexPhrase("Oh, kapitanie! Czy chciałbyś dziś podzielić ze mną łóżko? Nie lubię się chwalić, ale...","Usiądź, kapitanie. Zawsze jest przyjemnością spotkać prawdziwego wilka morskiego jak ty.")+"";
						link.l1 = "Szkoda, że teraz się spieszę. Do zobaczenia następnym razem!";
						link.l1.go = "exit";
						bool bOk = (CheckAttribute(pchar, "questTemp.Saga.Helena_officer")) || (CheckAttribute(pchar, "questTemp.LSC.Mary_officer")) || npchar.city == GetLadyBethCity(); // 291112
						if (pchar.questTemp.different == "free" && !CheckAttribute(pchar, "questTemp.different.FackWaitress") && PChar.sex != "woman" && pchar.GenQuest.EncGirl != "HorseToTavern" && !bOk)
						{
							link.l2 = "Z wielką przyjemnością, kochanie!";
							link.l2.go = "Love_1";
						}
					}
					else
					{
						dialog.text = "Usiądź, kapitanie. Spróbuj naszego rumu, zagraj w karty lub w kości. Czuj się jak u siebie w domu! Zawsze to przyjemność spotkać prawdziwego wilka morskiego jak ty.";
						link.l1 = "Dziękuję Ci, piękna.";
						link.l1.go = "exit";
					}
				break;

				case 3:
					dialog.text = "Porozmawiaj z mistrzem, jeśli chcesz coś zamówić. Jest za barem.";
					link.l1 = "Dzięki za radę.";
					link.l1.go = "exit";
				break;

				case 4:
					dialog.text = "Jeśli chcesz odpocząć i zadbać o swoje zdrowie - wynajmij sobie pokój. Spędzenie całej nocy w sali nie pomoże ci wiele.";
					link.l1 = "Dziękuję.";
					link.l1.go = "exit";
				break;
			}			
			link.l9 = "Chcę zadać ci kilka pytań.";
			link.l9.go = "quests";//(перессылка в файл города)
		break;
		
        case "Love_1":
			dialog.text = "Słuchaj więc. Wynajmij pokój tutaj w karczmie. Idź tam i na mnie poczekaj. Przemykam się tam nieco później...";
			link.l1 = "Ha! Zrobię to, kochanie! Będę na ciebie czekać!";
			link.l1.go = "exit";
			pchar.questTemp.different = "FackWaitress_toRoom";
			SetTimerFunction("WaitressFack_null", 0, 0, 1); //освобождаем разрешалку на миниквесты на след. день
			//Шанс, что ограбят, если рендом выпадет на 0. он же делитель сколько она вытащит из кармана
			pchar.questTemp.different.FackWaitress.Kick = dRand(2); 
			pchar.questTemp.different.FackWaitress.Name = GetFullName(npchar); //запомним имя официантки
			pchar.questTemp.different.FackWaitress.City = npchar.city;
			//делаем клона официантки
			sld = GetCharacter(NPC_GenerateCharacter("WairessQuest", npchar.model, "woman", npchar.model.animation, 5, sti(npchar.nation), 3, false, "citizen"));
			sld.name = npchar.name;
			sld.lastname = npchar.lastname;
			sld.dialog.Filename = "Quest\ForAll_dialog.c";
			sld.dialog.currentnode = "Waitress";	
			Pchar.quest.WaitressFack_inRoom.win_condition.l1 = "location";
			Pchar.quest.WaitressFack_inRoom.win_condition.l1.location = npchar.city + "_tavern_upstairs";
			Pchar.quest.WaitressFack_inRoom.function = "WaitressFack_inRoom";
			ChangeCharacterComplexReputation(pchar,"nobility", -1);
		break;
		
        case "Love_IDN":
			dialog.text = "Ona już tu nie pracuje, przeszła na emeryturę... Przykro mi, ale muszę wrócić do pracy.";
			link.l1 = "Dobrze...";
			link.l1.go = "exit";
		break;
		
        case "Love_IDN_1":
			dialog.text = "Słuchaj dobrze, pożądliwy idioto. Nie wiem, gdzie są twoje pieniądze! A jeśli będziesz na mnie naciskać, to zawołam strażników i znajdziesz się w więzieniu!";
			link.l1 = "Dobrze, nie potrzebujemy strażników... Taki dureń...";
			link.l1.go = "Love_IDN_2";
		break;
		
        case "Love_IDN_2":
			dialog.text = "Dokładnie, taki głupiec. Następnym razem będziesz mądrzejszy i przyzwoitszy.";
			link.l1 = "Spróbuję... (szeptem) Kurwa...";
			link.l1.go = "exit";
		break;

		case "without_money":
			NextDiag.TempNode = "first time";
			dialog.text = "Czy mnie słyszysz?";
			link.l1 = "Ughh...";
			link.l1.go = "without_money_2";
		break;

		case "without_money_2":
			dialog.text = "Czujesz się źle? Boli cię głowa?";
			link.l1 = "Cholera... gdzie ja jestem?";
			link.l1.go = "without_money_3";
		break;

		case "without_money_3":
			dialog.text = "Nie pamiętasz? Oni cię okradli.";
			link.l1 = "Co? Oh... Moja głowa... Kto by się odważył?!";
			link.l1.go = "without_money_4";
		break;

		case "without_money_4":
			dialog.text = "Skąd mogę wiedzieć? Wparowali, grozili śmiercią, sprawdzili twoje kieszenie i odeszli.";
			link.l2 = "Rozumiem... Cholera... Chciałbym trochę wody... Dziękuję.";
			link.l2.go = "exit";
		break;
		
		//--> Jason Цена чахотки
		case "Consumption":
			npchar.quest.Consumption = "true";
			dialog.text = "Nie, to nic, senorze... dziękuję za twoją życzliwość, ale ja... (płacze)";
			link.l1 = "Ktoś cię obraził? Uspokój się, piękna, opowiedz mi wszystko.";
			link.l1.go = "Consumption_1";
		break;
		
		case "Consumption_1":
			dialog.text = "Nie, nie, senor to nic. Przepraszam za brak opanowania, tylko... Chodzi o mojego brata, mówią, że nie żyje, ale ja w to nie wierzę. Nie wiem, w co wierzyć, ale czuję własnym sercem, że jest w wielkim kłopotie. A poza Angelo, po śmierci naszych rodziców, nie mam nikogo... (płacze)";
			link.l1 = "Rozumiem, ale proszę cię, uspokój się. Co się stało z twoim bratem?";
			link.l1.go = "Consumption_2";
		break;
		
		case "Consumption_2":
			dialog.text = "Seniorze... proszę mnie nie zrozumieć źle, ale dlaczego taki kapitan miałby się troszczyć o zwykłą i skromną dziewczynę z karczmy? Nawet nie mam nic, co mogłabym Ci obiecać za twoją pomoc...";
			link.l1 = "Właściwie, masz rację. Altruizm nie jest dla mnie, więc bądź silny, wszyscy tracimy naszych krewnych. C'est la vie jak mówimy we Francji...";
			link.l1.go = "exit";
			link.l2 = "Kobieta zawsze znajdzie sposób, aby podziękować mężczyźnie... Ha-ha. Teraz przestań już płakać i opowiedz mi o swoim problemie.";
			link.l2.go = "Consumption_3_1";
			link.l3 = "Młoda seniorko, czy nie wiesz, że nasz Kościół uczy nas pomagać sobie nawzajem? Spróbuję ci pomóc, jeśli będę w stanie, oczywiście.";
			link.l3.go = "Consumption_3_2";
		break;
		
		case "Consumption_3_1":
			if(sti(pchar.reputation.nobility) > 36)
			{
				dialog.text = "Czy to była 'aluzja'? Przepraszam, to był mój błąd rozmawiać z tobą! Do widzenia 'caballero'...";
				link.l1 = "Jak sobie życzysz, kochanie.";
				link.l1.go = "exit";
			}
			else
			{
				dialog.text = "Cóż... Przynajmniej jesteś szczery w swoich pragnieniach. Obiecuję, że jeśli znajdziesz Angelo lub powiesz mi, co naprawdę się z nim stało, dostaniesz to, o co prosiłeś...";
				link.l1 = "Droga senorito, to przyjemność robić z tobą interesy... Teraz przejdźmy od razu do historii twojego brata.";
				link.l1.go = "Consumption_4";
				npchar.quest.Consumption.sex = "true";
			}
		break;
		
		case "Consumption_3_2":
			dialog.text = "Czy żartujesz? Naprawdę chcesz mi pomóc za darmo?";
			link.l1 = "Tylko zły człowiek nie pomógłby płaczącej dziewczynie. Nie martw się, naprawdę chcę ci pomóc. Co dokładnie stało się z Angelo?";
			link.l1.go = "Consumption_4";
		break;
		
		case "Consumption_4":
			dialog.text = "Bardzo dobrze, senorze. Mój brat, on... och, nie jest łatwo powstrzymać łzy, jest mi tak przykro... Byliśmy naprawdę biedni z powodu mojej... skromności w pracy, być może... A Angelo zaczął pracować z lokalnymi przemytnikami. Myślał, że jego mała łódź rybacka przyniesie więcej pieniędzy, jeśli będzie przewozić coś, unikając cła.";
			link.l1 = "Aby to ująć prościej, twój brat stał się przestępcą, prawda?";
			link.l1.go = "Consumption_5";
		break;
		
		case "Consumption_5":
			dialog.text = "Nie, panie, nie rozumiesz... on nie jest taki! Zrobił to dla mnie! Aby uratować mnie przed zarabianiem dodatkowych pieniędzy tutaj... wiesz, co mam na myśli. Byliśmy zadłużeni i zrobił to dla mojej cześci i mojej duszy. A potem... został złapany. To nie był duży problem, nawet pożyczyłem więcej pieniędzy, aby zapłacić za jego zwolnienie... Ale powiedzieli, że umarł.";
			link.l1 = "Powiedzieli? Kto powiedział? I dlaczego im nie wierzysz? Zmarł w więzieniu?";
			link.l1.go = "Consumption_6";
		break;
		
		case "Consumption_6":
			dialog.text = "Tak. Kiedy przyniosłem pieniądze na jego zwolnienie, komendant powiedział mi, że Angelo umarł na suchoty. Tylko pomyśl! Dotarł tam w dobrym zdrowiu, a umarł dwa tygodnie później w tych komorach. Oni... oni nawet nie pozwolili mi zobaczyć ciała. Powiedzieli, że chowają więźniów w zatoce obok fortu, aby uniknąć epidemii.";
			link.l1 = "Epidemia? Brzmi bardzo prawdziwie. Więc po prostu nie chcesz w to uwierzyć, czy masz poważniejsze powody?";
			link.l1.go = "Consumption_7";
		break;
		
		case "Consumption_7":
			dialog.text = "Nie... Nie! (płacząc) Wiem, że to brzmi głupio, ale jestem pewien, że wiedziałbym, gdyby umarł. Wiesz, Angelo zawsze był silny - prawdziwy żeglarz. Ale jest jeszcze jedna rzecz\nMój dziadek zmarł na gruźlicę, kiedy byłem dzieckiem, a on, stary człowiek, walczył z nią przez lata! Wiem, jak to działa, gruźlica nie zabija ludzi w ciągu kilku dni, uwierz mi!";
			link.l1 = "Hm... Również mnie wzbudziłeś wątpliwości, coś jest tu bardzo nie tak. Nie mogę Ci niczego obiecać, ale postaram się dowiedzieć więcej.";
			link.l1.go = "Consumption_8";
		break;
		
		case "Consumption_8":
			dialog.text = "Nawet prosta obietnica to o wiele więcej, niż liczyłem! Jesteś tak uprzejmy, senorze! Będę tu czekać!";
			link.l1 = "Och, młodość! Tak niekonsekwentna w uczuciach... czy mógłbyś mi uprzejmie oddać moją rękę, piękności, nadal jej potrzebuję ha-ha... Dobrze, więc, pójdę i poszukam dookoła.";
			link.l1.go = "Consumption_9";
		break;
		
		case "Consumption_9":
			DialogExit();
			npchar.dialog.filename = "Quest\LineMiniQuests\Consumption.c";
			npchar.dialog.currentnode = "First time";
			pchar.questTemp.Consumption = "begin";
			AddQuestRecord("Consumption", "1");
		break;
		//<-- Цена чахотки
		
		// Addon-2016 Jason, французские миниквесты (”ЊЉ) Џорт Џренс
		case "FMQP":
			dialog.text = "Nie, to nie żart! Na górze! Dwaj rzezimieszkowie mordują szlachcica! Pomóż mu, kapitanie, jesteś jedynym uzbrojonym człowiekiem tutaj!";
			link.l1 = "Uciekaj na zewnątrz, wołaj strażników! Idę na górę!";
			link.l1.go = "FMQP_1";
			link.l2 = "Mój drogi, musiałeś pomylić mnie ze strażnikiem. Wezwij patrol w razie morderstwa.";
			link.l2.go = "FMQP_exit";
		break;
		
		case "FMQP_exit":
			dialog.text = "A-ah, straże! Pomóż mi!";
			link.l1 = "...";
			link.l1.go = "FMQP_exit_1";
		break;
		
		case "FMQP_exit_1":
			DialogExit();
			chrDisableReloadToLocation = false;
			DoQuestReloadToLocation("Portpax_town", "reload", "reload4", "");
			LocatorReloadEnterDisable("Portpax_town", "reload4_back", true);
			SetFunctionTimerCondition("FMQP_Remove", 0, 0, 1, false);
		break;
		
		case "FMQP_1":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorRunToLocation(npchar, "reload", "reload1_back", "none", "", "", "", 5.0);
			pchar.quest.FMQP_room.win_condition.l1 = "locator";
			pchar.quest.FMQP_room.win_condition.l1.location = "Portpax_tavern";
			pchar.quest.FMQP_room.win_condition.l1.locator_group = "reload";
			pchar.quest.FMQP_room.win_condition.l1.locator = "reload2_back";
			pchar.quest.FMQP_room.function = "FMQP_InRoom";
		break;
	}
}
