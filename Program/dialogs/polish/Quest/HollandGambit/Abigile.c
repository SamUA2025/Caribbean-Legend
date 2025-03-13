// Абигайль Шнеур
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			if (CheckAttribute(pchar, "questTemp.HWIC.Holl"))
			{
				if (pchar.questTemp.HWIC.Holl == "AbbyInHouse")
				{
					dialog.text = "Dzień dobry, panie. Co sprowadza cię do naszego domu?";
					link.l1 = "Dzień dobry, Abigail. Nazywam się "+GetFullName(pchar)+"Jestem kapitanem pracującym dla dobra Republiki i Holenderskiej Kompanii Zachodnioindyjskiej.";
					link.l1.go = "AbbyAndLucas";
					DelLandQuestMark(npchar);
					break;
				}
				if (pchar.questTemp.HWIC.Holl == "AbbyFindScull" && makeint(Pchar.money) >= 200000)
				{
					dialog.text = "Boże mój, czy znalazłeś pieniądze mojego ojca? To prawda? Ach, tak się cieszę! Szybko idź do mojego ojca, chce z tobą porozmawiać. Idź i zobacz go!";
					link.l1 = "Jestem w drodze, madame.";
					link.l1.go = "exit";
					DelLandQuestMark(npchar);
					break;
				}
				if (pchar.questTemp.HWIC.Holl == "AbbyLeavesMarried")
				{
					dialog.text = "Uratowałeś nas od całkowitej rozpaczy, kapitanie! Jestem ci tak wdzięczny! Teraz dobre imię rodziny Shneur może zostać przywrócone!";
					link.l1 = "Zaledwie spełniam swój obowiązek jako dżentelmen, madame. Mam nadzieję, że nie ma już niczego, co mogłoby powstrzymać cię przed poślubieniem mojego protektora.";
					link.l1.go = "AbbyAndLucas_8";
					DelLandQuestMark(npchar);
					break;
				}
				dialog.text = "Czy czegoś potrzebujesz, kapitanie?";
				link.l1 = "Nie teraz, madame.";
				link.l1.go = "exit";
				break;
			}
			if (CheckAttribute(pchar, "questTemp.HWIC.Eng"))
			{
				if (pchar.questTemp.HWIC.Eng == "AbigileInChurch")
				{
					dialog.text = "Witaj, Święta Królowo, nasza życie, nasza słodycz i nasza nadziejo. Do Ciebie wołamy, biedne wygnane dzieci Ewy. Do Ciebie wzdychamy, płacząc i lamentując w tej dolinie łez... oh mynheer, przestraszyłeś mnie! Co Cię tu sprowadza?";
					link.l1 = "Proszę o wybaczenie, Abigail, jak mniemam? Richard Fleetwood mnie przysłał...";
					link.l1.go = "Seek_Island";
					DelLandQuestMark(npchar);
					break;
				}
				dialog.text = "Czy chcesz czegoś, kapitanie?";
				link.l1 = "Nie teraz, madame.";
				link.l1.go = "exit";
				break;
			}
			if (CheckAttribute(pchar, "questTemp.HWIC.Self"))
			{
				if (pchar.questTemp.HWIC.Self == "toVillemstad")
				{
					dialog.text = "Co tu się dzieje? Co to za hałas? Tato, kim jest ten dziwny człowiek?";
					link.l1 = "Dzień dobry, madame. Abigail Schneur, jak mniemam? Cieszę się, że mogę cię zobaczyć. Musisz wybaczyć mi moją zuchwałość, ale mam tutaj pilny list adresowany do ciebie od... cóż, bardzo bym chciał ci powiedzieć, ale twój drogi ojciec odmawia nawet pozwolenia, bym stanął w środku waszego domu, nie mówiąc już o dostarczeniu tej wiadomości dla ciebie.";
					link.l1.go = "Abigile_kidnapping";
					break;
				}
				if (pchar.questTemp.HWIC.Self == "AbigileNextDay")
				{
					dialog.text = "Ach, oto jesteś, Charles. Jestem gotów podążać za tobą wszędzie!";
					link.l1 = "Idźmy zatem.";
					link.l1.go = "Abigile_kidnapping_7";
					break;
				}
				if (pchar.questTemp.HWIC.Self == "AbigileInCabin")
				{
					dialog.text = "Czy jesteśmy już w St. John's, Charles? Czy wkrótce zobaczę Richarda?";
					link.l1 = "Tak, madame, jesteśmy w St. John's. Niestety, Richard nie jest obecnie w mieście, dwa dni temu został wysłany na patrol w pobliże Barbadosu. Nie martw się, powinien wrócić za tydzień.";
					link.l1.go = "Abigile_kidnapping_8";
					break;
				}
				if (pchar.questTemp.HWIC.Self == "AbigileLie")
				{
					dialog.text = "Charles! Jakże się cieszę, że cię widzę! Czy są jakieś wieści od Richarda?";
					link.l1 = "Ach, moja droga madame. Richard musiał zostać w Bridgetown na jakiś czas z powodu tajnej i ważnej misji, coś związanego z Holendrami. Zakładam, że Richard powiedział ci, czym się zajmuje, prawda?";
					link.l1.go = "Abigile_kidnapping_13";
					break;
				}
				if (pchar.questTemp.HWIC.Self == "AbiReturnHome")
				{
					DelLandQuestMark(npchar);
					dialog.text = "Charles! To ty! W końcu wróciłeś!";
					link.l1 = "Witam, madame. Cieszę się, że cię widzę.";
					link.l1.go = "Abigile_return";
					break;
				}
				if (pchar.questTemp.HWIC.Self == "AbiReturnHomeGo")
				{
					dialog.text = "Ach, wreszcie jestem w domu! Tak się cieszę, że znów zobaczę tatę! Charles, dziękuję ci za wszystko, co dla mnie zrobiłeś!";
					link.l1 = "Proszę, nie ma potrzeby takiej rozmowy, madame. Po prostu spełniam swój obowiązek jako dżentelmen wobec damy w potrzebie.";
					link.l1.go = "Abigile_return_6";
					break;
				}
				if (pchar.questTemp.HWIC.Self == "SolomonHistoryNext")
				{
					dialog.text = "Tato, jeśli coś pamiętasz, proszę, powiedz to! Charles, on jest... można mu zaufać. Śmiem twierdzić, że jest jedynym, który może nam pomóc!";
					link.l1 = "";
					link.l1.go = "Abigile_return_12";
					pchar.questTemp.HWIC.Self = "SolomonHistoryAfter";
					break;
				}
				if (pchar.questTemp.HWIC.Self == "SolomonHistoryEnd")
				{
					dialog.text = "Będę się za ciebie modlić dniem i nocą! Powiedz mi... powiedz mi, że to zrobisz! Że znajdziesz wyspę!";
					link.l1 = "Zrobię, co w mojej mocy, madame.";
					link.l1.go = "Abigile_return_13";
					break;
				}
				if (pchar.questTemp.HWIC.Self == "final" || pchar.questTemp.HWIC.Self == "VanbergDestroyed")
				{
					DelLandQuestMark(npchar);
					dialog.text = "Ach, Charles! Wróciłeś! Powiedz mi szybko, czy znalazłeś wyspę? Ledwie mogę dłużej czekać!";
					if (makeint(Pchar.money) >= 200000)
					{
						link.l1 = "Tak, Abi. Znalazłem wyspę i pieniądze twojego ojca. Jestem tu, by je zwrócić tobie.";
						link.l1.go = "Abigile_GiveMoney";
					}
					link.l2 = "Niestety, madame. Nie udało mi się znaleźć ani kapitana Kellera, ani waszej wyspy. Zrobiłem, co mogłem, ale...";
					link.l2.go = "Abigile_NoMoney";
				break;
				}
				dialog.text = "Ach, to ty, Charles! Potrzebujesz czegoś? Mogę ci zaoferować kawę?";
				link.l1 = "Nie, nic. Proszę, nie kłopocz się.";
				link.l1.go = "exit";
				break;
			}
			dialog.text = "Dzień dobry, panie. Czego sobie życzysz?";
			link.l1 = "Nic, madame. Muszę prosić o wybaczenie. Żegnaj.";
			link.l1.go = "exit";
			NextDiag.TempNode = "First time";
		break;

		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

//-------------------------------------------------за Голландию-----------------------------------------------
		case "AbbyAndLucas":
			dialog.text = "Zaszczycony jestem spotkaniem, Kapitanie "+GetFullName(pchar)+" Słyszałam różne opowieści o tobie od innych dam w mieście. Jesteś człowiekiem, który pojmał piracki statek widmo i przywiózł go jako nagrodę do Willemstad. Powiedz mi kapitanie... czy to prawda, że ten statek był pod dowództwem... Richarda Fleetwooda?";
			link.l1 = "Wszystko, co pani słyszała, to prawda, madame. Byłem równie zszokowany jak każdy inny, gdy dowiedziałem się prawdy. To skandal! Oficer marynarki Wspólnoty Angielskiej rabuje kupców własnego narodu jak zwykły pirat! Ten łajdak próbował ukryć swoje nikczemne czyny, udając renegacki 'statek widmo' wspierany przez Holenderską Kompanię Zachodnioindyjską. Używał tego przykrywki, by obwiniać Kompanię i atakować również holenderskie statki.";
			link.l1.go = "AbbyAndLucas_1";
		break;
		
		case "AbbyAndLucas_1":
			dialog.text = "Kręci mi się w głowie... Ciężko słuchać takich okropności, kapitanie. Znałem osobiście Richarda Fleetwooda, nigdy bym nie pomyślał, że on...";
			link.l1 = "Madame, zostałem poinformowany przez mego patrona Lucasa Rodenburga o waszej podróży do Curacao z Recife. Teraz wszystko jest jasne. Fleetwood zatopił wasz statek, a potem wrócił, by 'uratować' was i waszego ojca przed pozostaniem na tej zagubionej wyspie. Sam czytałem dziennik pirata, zapisał każdy szczegół w swoim dzienniku pokładowym.";
			link.l1.go = "AbbyAndLucas_2";
		break;
		
		case "AbbyAndLucas_2":
			dialog.text = "„Co za koszmar... Wygląda na to, że mój papa miał rację. Mówił mi, że Richard to ten pirat, który był źródłem wszystkich naszych nieszczęść. Powinnam się cieszyć, że prawda wyszła na jaw... ah, przepraszam, kapitanie. To po prostu za dużo dla mojej biednej głowy... czego taki ważny człowiek jak ty chce od zwykłej dziewczyny?”";
			link.l1 = "Abigail, jestem tu z powodu bardzo skomplikowanej i delikatnej sprawy. Czy mnie wysłuchasz?";
			link.l1.go = "AbbyAndLucas_3";
		break;
		
		case "AbbyAndLucas_3":
			dialog.text = "Oczywiście, mynheer. Zamieniam się w słuch.";
			link.l1 = "Jak już mówiłem, służę Kompanii. Lucas Rodenburg jest nie tylko moim dowódcą wojskowym, ale również dobrym przyjacielem. Wysłał mnie do ciebie z wiadomością. Byłoby największym szczęściem, gdybyś zgodziła się na jego propozycję małżeństwa. Jestem tu, aby poprosić cię o rękę mojego protektora. Jest gotów zrobić wszystko na świecie dla twojego szczęścia.";
			link.l1.go = "AbbyAndLucas_4";
		break;
		
		case "AbbyAndLucas_4":
			dialog.text = "O, kapitanie! Teraz rozumiem, dlaczego Mynheer Rodenburg nie chciał zrobić tego sam... Mój biedny papa byłby wniebowzięty, ale ja...";
			link.l1 = "Madame, widzę, że coś Panią trapi. Czy wątpi Pani w szczerość pana Rodenburga? Może mógłbym pomóc Pani zmienić zdanie?";
			link.l1.go = "AbbyAndLucas_5";
		break;
		
		case "AbbyAndLucas_5":
			dialog.text = "O nie, kapitanie, nie wątpię w szczerość Mynheera Rodenburga. Lucas zrobił dla mnie i mojego taty tak wiele, nie wiem, co by się z nami stało, gdyby się nami nie opiekował. Ale proszę, musisz zrozumieć moje położenie!\nMoja rodzina to nie Rothschildowie, ale nigdy nie byliśmy biedni. Rodzina Shneur jest dobrze znana wśród europejskich domów bankowych z naszego majątku... ale teraz ten okropny pirat nas zrujnował! Nie mogę znieść tych paskudnych plotek, które wiem, że krążą za naszymi plecami, już dłużej. Każda paplająca gospodyni i służąca w tym mieście myśli, że szukam tylko pieniędzy Mynheera Rodenburga. 'Jak bardzo jak Żydówka,' mówią. Okrutni nędznicy! Gdyby tylko mój ojciec pamiętał lokalizację wyspy! Ukrył tam resztki naszego rodzinnego majątku, aby uratować go przed rękami tych podłych piratów, którzy zamordowali moje siostry i brata!\nAle mój biedny ojciec nie jest żeglarzem, po prostu nie pamięta, gdzie ta wyspa i nasze rodzinne pieniądze są! Proszę, porozmawiaj z moim ojcem, kapitanie! Może przypomni sobie cokolwiek, co może być użyteczne dla twoich doświadczonych zmysłów. Proszę, znajdź tę wyspę i nasz majątek! Uratowałbyś biedną dziewczynę przed wstydem i hańbą!";
			link.l1 = "Bardzo dobrze, Abigail. Porozmawiam z twoim ojcem. Miej wiarę, dziewczyno, zrobię, co w mojej mocy.";
			link.l1.go = "AbbyAndLucas_6";
		break;
		
		case "AbbyAndLucas_6":
			dialog.text = "Dziękuję, panie. Będę modlić się za ciebie dniem i nocą. Niechaj Bóg naszych ojców będzie z tobą!";
			link.l1 = "Żegnaj, Abigail. Wrócę z dobrymi wieściami, przysięgam.";
			link.l1.go = "AbbyAndLucas_7";
		break;
		
		case "AbbyAndLucas_7":
			DialogExit();
			AddQuestRecord("Holl_Gambit", "1-27");
			pchar.questTemp.HWIC.Holl = "AbbyFather";
			AddLandQuestMark(characterFromId("Solomon"), "questmarkmain");
		break;
		
		case "AbbyAndLucas_8":
			dialog.text = "O, tak! Mynheer Rodenburg to honorowy i życzliwy człowiek. Bez wahania dam mu swoje błogosławieństwo i będę szczęśliwa, nazywając go moim mężem.";
			link.l1 = "W takim razie uważam moje zadanie za zakończone. Muszę teraz udać się do pana Rodenburga i przekazać mu dobre wieści. Szczerze życzę ci szczęścia, madame.";
			link.l1.go = "AbbyAndLucas_9";
		break;
		
		case "AbbyAndLucas_9":
			DialogExit();
			AddQuestRecord("Holl_Gambit", "1-33");
			pchar.questTemp.HWIC.Holl = "AbbyAgreeMarried";//теперь к Лукасу
			AddLandQuestMark(characterFromId("Lucas"), "questmarkmain");
		break;
		
//-------------------------------------------------за Англию-----------------------------------------
		case "Seek_Island":
			dialog.text = "Richard cię przysłał?! Błogosławiona Maryjo, dziękuję! Ach, panie! Słyszałem, że biedny Richard został ranny i jest bliski śmierci. Czy to prawda? Powiedz mi, czy on żyje?! Czy jest zdrowy?!";
			link.l1 = "Richard żyje i... w większości zdrowy. Oto najpierw złe wieści: jest trochę bardziej zużyty i tymczasowo oślepiony, ale wraca do zdrowia. A teraz dobre wieści: Richard chce, żebyś odpłynęła z nim do Anglii, gdzie się pobierzecie. Jego czas na Karaibach dobiegł końca i czeka na twoją odpowiedź.";
			link.l1.go = "Seek_Island_1";
		break;
		
		case "Seek_Island_1":
			dialog.text = "Ach, mój drogi posłańcu, powiedz Richardowi, że dla naszego szczęścia jestem gotowa iść z nim, gdzie tylko zechce. Ale obawiam się, że nasza ucieczka zabije mojego biednego ojca... Panie, jestem zrozpaczona i nie wiem, co robić. Chciałabym, aby Richard znalazł tę przeklętą wyspę i skrzynię z naszym rodzinnym złotem... Może to w jakiś sposób pocieszyłoby mojego tatę w mojej nieobecności.";
			link.l1 = "Widzę... Moja misja polegała na dostarczeniu cię na Antiguę, ale to trochę komplikuje sprawy. Jeśli znajdę wyspę i skrzynię, i przyniosę ją tobie, czy wtedy pojedziesz ze mną do St. John's i Richarda?";
			link.l1.go = "Seek_Island_2";
		break;
		
		case "Seek_Island_2":
			dialog.text = "O tak, panie, wspomnę o tobie w naszych rodzinnych modlitwach! Nazwiemy naszego pierworodnego syna twoim imieniem! Bardzo dziękuję, kapitanie! Będę się za ciebie modlić! Idź i niech Chrystus oraz Błogosławiona Matka będą z tobą!";
			link.l1 = "Nie każę ci długo na siebie czekać, madame. Wkrótce wrócę.";
			link.l1.go = "Seek_Island_3";
		break;
		
		case "Seek_Island_3":
			DialogExit();
			AddQuestRecord("Holl_Gambit", "2-18");
			pchar.questTemp.HWIC.Eng = "SeekIsland";
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload1", "Villemstad_houseSp2_bedroom", "goto", "goto1", "", -1);//Аби домой
			pchar.questTemp.HWIC_Coordinates = "true"; //атрибут координат на поиск острова через каюту
			DelMapQuestMarkCity("Villemstad");
		break;
		
//--------------------------------------------против всех------------------------------------------------
		case "Abigile_kidnapping":
			dialog.text = "Och... Masz od niego list? Och, ojcze, nie bądź tak surowy dla naszych gości! Zawstydzasz mnie swoimi neurotycznymi fantazjami! Mynheer proszę, chodź ze mną, chcę z tobą porozmawiać.";
			link.l1 = "Dziękuję, panienko. Miło widzieć, że ktoś w tym domu mówi z sensem.";
			link.l1.go = "Abigile_kidnapping_1";
		break;
		
		case "Abigile_kidnapping_1":
			DialogExit();
			npchar.greeting = "abigile_3";
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload2", "Villemstad_houseSp2_bedroom", "goto", "goto1", "Abigile_Stay", -1);
			NextDiag.CurrentNode = "Abigile_kidnapping_2";
			pchar.questTemp.HWIC.Self = "AbigileTalk";
			AddLandQuestMark(npchar, "questmarkmain");
		break;
		
		case "Abigile_kidnapping_2":
			DelLandQuestMark(npchar);
			dialog.text = "Wybacz mojemu ojcu, panie. Jest naprawdę dobrym i życzliwym człowiekiem, ale nasze...nieszczęścia go złamały.";
			link.l1 = "  W porządku, pani, rozumiem. Pozwólcie, że się przedstawię, jestem Charlie... Knippel. Jestem tu z rozkazu Richarda Fleetwooda, chce, żebym cię do niego przyprowadził. Proszę, oto list.";
			link.l1.go = "Abigile_kidnapping_3";
		break;
		
		case "Abigile_kidnapping_3":
			RemoveItems(PChar, "NPC_Letter", 1);
			dialog.text = "O, Richard...(czyta). O, Boże! On postanowił... oddać mojemu ojcu wszystkie stracone pieniądze! Jaka hojność! Drogi, słodki Richard! Mynheer, przynosisz dobre wieści niczym sam Gabriel! Richard, gdzie on jest? Czy jest na Curaçao?";
			link.l1 = "Nie, panno. Była próba zamachu na jego życie i został ciężko ranny. Teraz jest na Antigui... nie skończyłaś czytać listu.";
			link.l1.go = "Abigile_kidnapping_4";
		break;
		
		case "Abigile_kidnapping_4":
			dialog.text = "Święta Maryjo, poczęta bez grzechu, módl się za nami, którzy się do Ciebie uciekamy! Powiedz mi, czy on jest bezpieczny? Czy jego rana jest poważna?";
			link.l1 = "Nie martw się tak, panno! Richard to nie jest człowiek, który pozwoliłby jakimś draniom tak po prostu go zabić. Teraz odpoczywa i dochodzi do siebie. Chce, żebym cię do niego zabrał. Potem wy dwoje popłyniecie do Londynu... proszę, dokończ list, panno, pospieszasz się.";
			link.l1.go = "Abigile_kidnapping_5";
		break;
		
		case "Abigile_kidnapping_5":
			dialog.text = "Ach, tak... Przepraszam (czytanie). Mój Panie Knippel, jestem gotów wypłynąć z tobą. Potrzebuję jednego dnia, aby spakować swoje rzeczy i porozmawiać z moim ojcem. Wróć jutro, a popłynę z tobą.";
			link.l1 = "Dobrze, pani. Będę tu jutro. Nie martw się, ja i moja załoga ochronimy cię przed wszelkimi niebezpieczeństwami podczas naszej podróży.";
			link.l1.go = "Abigile_kidnapping_6";
		break;
		
		case "Abigile_kidnapping_6":
			DialogExit();
			npchar.greeting = "abigile_2";
			NextDiag.CurrentNode = "First time";
			AddQuestRecord("Holl_Gambit", "3-22");
			pchar.quest.Abigile_Kidnap.win_condition.l1 = "Timer";
			pchar.quest.Abigile_Kidnap.win_condition.l1.date.hour  = 7.0;
			pchar.quest.Abigile_Kidnap.win_condition.l1.date.day   = GetAddingDataDay(0, 0, 1);
			pchar.quest.Abigile_Kidnap.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 1);
			pchar.quest.Abigile_Kidnap.win_condition.l1.date.year  = GetAddingDataYear(0, 0, 1);
			pchar.quest.Abigile_Kidnap.win_condition.l2 = "location";
			pchar.quest.Abigile_Kidnap.win_condition.l2.location = "Villemstad_houseSp2";
			pchar.quest.Abigile_Kidnap.function = "AbigileGoToShip";
			pchar.questTemp.HWIC.Self = "AbigileWaitNextDay";
			SetFunctionTimerCondition("AbigileGoToShipOver", 0, 0, 3, false);//таймер 3 дня, ибо нефиг
		break;
		
		case "Abigile_kidnapping_7":
			DialogExit();
			chrDisableReloadToLocation = true;
			AddPassenger(pchar, npchar, false);
			SetCharacterRemovable(npchar, false);
			LAi_SetActorType(sld);
			LAi_ActorGoToLocation(npchar, "reload", "reload1", "none", "", "", "SetAbigileToCabin", -1);//Аби в каюту к ГГ поставим
			AddQuestRecord("Holl_Gambit", "3-23");
			pchar.questTemp.HWIC.Self = "AbigileOnShip";
			pchar.quest.AbigileGoToShipOver.over = "yes";//снять таймер
			SetFunctionTimerCondition("RemoveAbigileOver", 0, 0, 30, false);//таймер на 1 месяц, ибо нефиг
			pchar.quest.Abigile_died.win_condition.l1 = "NPC_Death";
			pchar.quest.Abigile_died.win_condition.l1.character = "Abigile";
			pchar.quest.Abigile_died.function = "AbigileDied";//специально для особо упоротых
			AddMapQuestMarkCity("SentJons", false);
			AddLandQuestMark(characterFromId("Merdok"), "questmarkmain");
		break;
		
		case "Abigile_kidnapping_8":
			DelLandQuestMark(npchar);
			dialog.text = "Ach, co za szkoda. Ale myślę, że mogę poczekać jeszcze tydzień, jak czekałem wcześniej...";
			link.l1 = "Dobrze powiedziane, panno. A żeby umilić pani oczekiwanie, proponuję zamienić tę surową kajutę na dom mojego przyjaciela. Tam czeka na panią miękkie łóżko i wyśmienite jedzenie.";
			link.l1.go = "Abigile_kidnapping_9";
		break;
		
		case "Abigile_kidnapping_9":
			dialog.text = "Jesteś taki dobry, Charlie. Dziękuję. Dobrze będzie mieć ziemię pod stopami... Czuję się dość mdłości po tym całym kołysaniu na falach.";
			link.l1 = "Proszę za mną, panienko.";
			link.l1.go = "Abigile_kidnapping_10";
		break;
		
		case "Abigile_kidnapping_10":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorFollowEverywhere(npchar, "", -1);
			pchar.questTemp.HWIC.Self = "AbigileInHouse";
			AddLandQuestMark(characterFromId("Merdok"), "questmarkmain");
		break;
		
		case "Abigile_kidnapping_11":
			dialog.text = "Cieszę się, że mogę cię poznać, John. Dziękuję za waszą uprzejmą gościnność, panowie!";
			link.l1 = "... ";
			link.l1.go = "Abigile_kidnapping_12";
		break;
		
		case "Abigile_kidnapping_12":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload3", "SentJons_HouseF3_Room2", "barmen", "bar1", "ContinueWithMerdok", -1);
			pchar.questTemp.HWIC.Self = "AbigileInRoom";
			NextDiag.CurrentNode = "First time";
			RemovePassenger(Pchar, npchar);
			pchar.quest.RemoveAbigileOver.over = "yes";//снять таймер
			sld = characterFromId("Merdok");
			LAi_SetActorType(sld);//чтобы геймер сам с ним не заговорил
		break;
		
		case "Abigile_kidnapping_13":
			DelLandQuestMark(npchar);
			dialog.text = "O, Charlie, widziałem Richarda tylko kilka razy i nie powiedział mi wiele o tym, co robi.";
			link.l1 = "Jestem dość zaskoczony, że ukrywał tak wielką tajemnicę przed kobietą, którą kocha... Panna, Richard nie jest zwykłym kapitanem. Jest także specjalnym agentem angielskiej Tajnej Rady. Bardzo ważnym człowiekiem, który zajmuje się delikatnymi zadaniami bezpośrednio zleconymi przez samego Lorda Protektora. Obecnie jego obowiązkiem jest zniszczenie handlowej potęgi Holenderskiej Kompanii Zachodnioindyjskiej na Karaibach.";
			link.l1.go = "Abigile_kidnapping_14"
		break;
		
		case "Abigile_kidnapping_14":
			dialog.text = "Panie, o czym pan mówi?";
			link.l1 = "Tak, panienko. Twój ukochany Richard - mój przyjaciel - jest bardzo ważnym człowiekiem. Zawsze byłem dumny, że jestem jego przyjacielem, ale stał się bardzo tajemniczy nawet wobec mnie. Oczywiste jest, że jest na jakiejś tajnej misji. Bardzo mi przykro, że ta misja nie pozwala mu się z tobą spotkać.";
			link.l1.go = "Abigile_kidnapping_15";
		break;
		
		case "Abigile_kidnapping_15":
			dialog.text = "Charlie, przerażasz mnie. Czy jesteś pewien, że z nim wszystko w porządku?";
			link.l1 = "Jestem tego pewien. Tylko... Nie pochwalałem, jak cię teraz traktuje. Rozumiem, że jego zadanie jest kluczowe i nie może zdradzić swojego obowiązku, nawet dla ciebie.";
			link.l1.go = "Abigile_kidnapping_16";
		break;
		
		case "Abigile_kidnapping_16":
			dialog.text = "O mój drogi Charlie... Będę czekać na Richarda do Drugiego Przyjścia, jeśli zajdzie taka potrzeba. Może mogłabym zostać nad tawerną... Nie mogę wciąż tak długo korzystać z gościnności Johna.";
			link.l1 = "Przestań pleść bzdury, pani! Twoja obecność nas zaszczyca, a nie nazywam się Charlie Knipepel, jeśli wyrzucę narzeczoną mojej panny młodej, mojego drogiego przyjaciela Richarda Fleetwooda, z domu!";
			link.l1.go = "Abigile_kidnapping_17";
		break;
		
		case "Abigile_kidnapping_17":
			dialog.text = "Charlie... Jestem bardzo poruszona twoim stosunkiem do mnie. Jestem tylko zwykłą dziewczyną, i na dodatek Żydówką...";
			link.l1 = "Panienko! Wiem, że to zuchwałe gadanie, jesteś szlachetną, chrześcijańską kobietą! I nawet nie myśl o tawernach! Nigdy sobie nie wybaczę, jeśli zawiodłem cię w mojej służbie dla Richarda.";
			link.l1.go = "Abigile_kidnapping_18";
		break;
		
		case "Abigile_kidnapping_18":
			dialog.text = "Dziękuję, Charlie. Cieszę się, że jesteś takim... dobrym człowiekiem.";
			link.l1 = "To mój obowiązek, panienko. Teraz przepraszam, ale muszę iść. Możesz swobodnie spacerować po mieście, zapewne czujesz się dość samotna zamknięta w tym domu, prawda?";
			link.l1.go = "Abigile_kidnapping_19";
		break;
		
		case "Abigile_kidnapping_19":
			dialog.text = "Cóż... John jest bardzo interesującym towarzystwem. Potrafi godzinami opowiadać o swoich proszkach, mieszankach i różnych... chorobach. Jest również uprzejmym i łaskawym człowiekiem. Chodzę też regularnie do kościoła, miejscowy ksiądz jest całkiem miły... ale, oczywiście, naprawdę tęsknię za Richardem.";
			link.l1 = " Myślę, że wkrótce wróci. Charlie Knippel jest do twojej dyspozycji, jeśli czegoś potrzebujesz.";
			link.l1.go = "Abigile_kidnapping_20";
		break;
		
		case "Abigile_kidnapping_20":
			DialogExit();
			pchar.questTemp.HWIC.Self = "MeetTonzag";
			pchar.quest.Meet_Tonzag.win_condition.l1 = "location";
			pchar.quest.Meet_Tonzag.win_condition.l1.location = "SentJons_TownCave";
			pchar.quest.Meet_Tonzag.function = "TonzagMeetingInDange";
		break;
		
		case "Abigile_return":
			dialog.text = "Słyszałem plotki o Richardzie... że zniknął. Wiesz coś o tym, Charlie?";
			link.l1 = "Tak, Abigail. Przykro mi... Richard Fleetwood wyjechał do Anglii i nie wróci. Dostał awans lub przeniesienie, coś w tym stylu... w każdym razie, po tym, co ci zrobił, nie chcę go znać.";
			link.l1.go = "Abigile_return_1";
		break;
		
		case "Abigile_return_1":
			dialog.text = "Ach, wiedziałem, że to się tak skończy....(szlocha) Dlaczego nie posłuchałem taty! Przynajmniej byłby zadowolony, gdybym poślubił Lucasa Rodenburga.";
			link.l1 = "Przebacz mi znowu, panienko...";
			link.l1.go = "Abigile_return_2";
		break;
		
		case "Abigile_return_2":
			dialog.text = "Za co, Charlie? Wcale nie jesteś winny. Byłeś dla mnie tylko dobry!";
			link.l1 = "Dla mnie jeszcze gorsze wieści dla ciebie. Właśnie wróciłem z Curacao, Lucas Rodenburg został aresztowany za bunt i zdradę przeciwko Republice. Jest wysyłany z powrotem do Amsterdamu w kajdanach, by stanąć przed sądem. Próbował zamordować Petera Stuyvesanta, dyrektora Kompanii. Na dodatek usiłował obalić gubernatora Willemstad i jest podejrzewany o morderstwo co najmniej jednej innej osoby, więc wątpię, by Stadtholder go oszczędził.";
			link.l1.go = "Abigile_return_3";
		break;
		
		case "Abigile_return_3":
			dialog.text = "O Boże! Co za koszmar! Myślę, że zemdleję! Charles, czy to prawda? Nie, proszę, powiedz, że to nieprawda!";
			link.l1 = "Przepraszam, panno, sytuacja się pogarsza. W trakcie śledztwa dotyczącego działań Rodenburga ujawniono, że pirat, który zatopił twój fluit, działał na rozkaz Lucasa Rodenburga. Prowadził on swoją prywatną wojnę przeciwko angielskiej flocie. Bardzo mi przykro, Abigail. Wszyscy mężczyźni, z którymi miałaś tutaj do czynienia na Karaibach, to kłamcy, złodzieje i mordercy.";
			link.l1.go = "Abigile_return_4";
		break;
		
		case "Abigile_return_4":
			dialog.text = "Oh... jestem zgubiona. Charles... proszę... zabierz mnie z powrotem do Willemstad. Potrzebuję mojego taty...";
			link.l1 = "Oczywiście, droga panna. Niestety, nie ma tu dla ciebie nic w Bridgetown. Idź, spakuj swoje rzeczy, pożegnaj się z Johnem i natychmiast wyruszymy w morze.";
			link.l1.go = "Abigile_return_5";
		break;
		
		case "Abigile_return_5":
			DialogExit();
			AddQuestRecord("Holl_Gambit", "3-57");
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload1", "none", "", "", "", -1);
			LocatorReloadEnterDisable("SentJons_HouseF3", "reload4", false);//откроем комнату Аби
			AddPassenger(pchar, npchar, false);
			SetCharacterRemovable(npchar, false);
			pchar.questTemp.HWIC.Self = "AbiReturnHomeGo";
			pchar.quest.AbiReturn_Home.win_condition.l1 = "location";
			pchar.quest.AbiReturn_Home.win_condition.l1.location = "Villemstad_town";
			pchar.quest.AbiReturn_Home.function = "AbiGoInVillemstad";
			AddMapQuestMarkCity("Villemstad", true);
		break;
		
		case "Abigile_return_6":
			dialog.text = "Nie, Charlie, to ja muszę ci podziękować. Gdyby nie ty i John, nawet nie wiem, co by się ze mną stało. Jesteście jedynymi uczciwymi ludźmi, których spotkałem na archipelagu.";
			link.l1 = "Hm... sprawiasz, że się rumienię, Abigail. Byłem zadowolony, mogąc ci pomóc. I bardzo mi przykro z powodu całego tego bałaganu.";
			link.l1.go = "Abigile_return_7";
		break;
		
		case "Abigile_return_7":
			dialog.text = "Wiesz, Charlie, dużo myślałem podczas naszej podróży na Curacao. Wszystko jest teraz jasne - Richard Fleetwood, Mynheer Rodenburg - wszystko to wydaje się koszmarem, który wreszcie się skończył. Jestem znowu z ojcem i możemy wrócić do normalnego życia\nNie będzie to łatwe - nie mamy żadnych pieniędzy. Ale jakoś sobie poradzimy, wszystko będzie dobrze. Błogosławiona Matka się nami zajmie, ona nigdy nie zapomina o swoich dzieciach, nawet o moim upartym starym ojcu, który zaprzecza Jej Synowi.";
			link.l1 = "Panno Abigail, zamierzam ci pomóc.";
			link.l1.go = "Abigile_return_8";
		break;
		
		case "Abigile_return_8":
			dialog.text = "Pomóc nam? Ale jak, Charlie?";
			link.l1 = "Ryszard opowiedział mi historię twojego rozbicia i twojego ocalenia. Wiem też, że twój ojciec zdołał ukryć swoje rzeczy na niezbadanej wyspie. Zamierzam ją znaleźć i przywieźć z powrotem twoje pieniądze.";
			link.l1.go = "Abigile_return_9";
		break;
		
		case "Abigile_return_9":
			dialog.text = "O, Charlie... Ani ja, ani mój ojciec nie jesteśmy w stanie powiedzieć ci, gdzie znajduje się ta nieszczęsna wyspa... Nie jesteśmy żeglarzami. Na dodatek, byłem przerażony o swoje życie podczas ataku, nie pamiętam nic oprócz krwi i zapachu śmierci.";
			link.l1 = "Abigail, spróbuj sobie przypomnieć. Proszę, każdy szczegół może mi pomóc, nawet najmniejszy. Może coś się wydarzyło przed atakiem? Jak wygląda ta wyspa?";
			link.l1.go = "Abigile_return_10";
		break;
		
		case "Abigile_return_10":
			dialog.text = "Wyspa... Wygląda jak wyspa? Zatoka, dżungle. Nic naprawdę nie rzuciło mi się w oczy. Ach, pamiętam! Może to ci pomoże. Niedługo przed atakiem piratów spotkaliśmy fluitę i zawołaliśmy jej kapitana. Został zaproszony na nasz statek i zjadł kolację z naszym kapitanem. My też tam byliśmy. Może on wie o tej wyspie.";
			link.l1 = "To coś niesamowitego! Jakie były nazwy fluyty i jej kapitana?";
			link.l1.go = "Abigile_return_11";
		break;
		
		case "Abigile_return_11":
			dialog.text = "Nie pamiętam, Charlie. Naprawdę nie...";
			link.l1 = "Spróbuj sobie przypomnieć, Abi!";
			link.l1.go = "Abigile_return_12";
			pchar.questTemp.HWIC.Self = "SolomonHistory";
		break;
		
		case "Abigile_return_12":
			DialogExit();
			sld = characterFromId("Solomon");
			sld.greeting = "solomon_1";
			LAi_SetActorType(sld);
			LAi_ActorDialog(sld, pchar, "", -1, 0);
		break;
		
		case "Abigile_return_13":
			dialog.text = "Będziemy na ciebie czekać. Pomóż mi Charlie Knippel. Jesteś naszą jedyną nadzieją... Będę się za ciebie modlić! Niech Bóg cię prowadzi!";
			link.l1 = "Jestem w drodze. Żegnaj, Abi. Żegnaj, Solomon.";
			link.l1.go = "Abigile_return_14";
		break;
		
		case "Abigile_return_14":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload2", "Villemstad_houseSp2_bedroom", "goto", "goto1", "ReturnAbiNormal", -1);
			pchar.questTemp.HWIC.Self = "SeekFleut";
			AddQuestRecord("Holl_Gambit", "3-58");
			AddLandQuestMark(characterFromId("Villemstad_PortMan"), "questmarkmain");
		break;
		
		case "Abigile_NoMoney":
			dialog.text = "Och, drogi... jaka szkoda. Mieliśmy nadzieję, ale... dziękujemy mimo wszystko, Charlie, że próbowałeś nam pomóc, gdy nikt inny nie chciał. Wygląda na to, że to jest los, który Bóg mi przeznaczył.";
			link.l1 = "Żegnaj, Abigail. Mam nadzieję, że będziesz w porządku.";
			link.l1.go = "exit";
			npchar.dialog.currentnode = "Abigile_Poor";
		break;
		
		case "Abigile_GiveMoney":
			dialog.text = "Czy to... czy to prawda? Naprawdę przywiozłeś nam z powrotem nasze zgubione pieniądze? Och, Charlie!";
			link.l1 = "Tak, to prawda. Mam to. Proszę, weź to. To wszystko twoje.";
			link.l1.go = "Abigile_GiveMoney_1";
		break;
		
		case "Abigile_GiveMoney_1":
			AddMoneyToCharacter(pchar, -200000);
			pchar.quest.MakeAbiPoor.over = "yes"; //снять прерывание
			ChangeCharacterComplexReputation(pchar, "nobility", 10);
			dialog.text = "Jak mogę ci podziękować?! Jak?!";
			link.l1 = "Nie potrzebuję żadnych podziękowań, Abi. To najmniej, co mogłem dla ciebie zrobić. Teraz możesz zacząć nowe życie bez Rodenburgów, Fleetwoodów czy jakichkolwiek innych dziwnych mężczyzn próbujących cię wykorzystać. Jestem pewien, że twój ojciec znajdzie sposób, by te pieniądze pomnożyły się... wydaje się, że to cecha dziedziczna.";
			link.l1.go = "Abigile_GiveMoney_2";
		break;
		
		case "Abigile_GiveMoney_2":
			dialog.text = "Charlie, nie bądź taki bezczelny! Zrobiłeś tak wiele dla mnie, dla mnie i dla mojego biednego ojca. No cóż, przyzwyczaiłam się do twojej obecności w moim życiu. Modliłam się za ciebie niestrudzenie każdego dnia i będę nadal modliła się za ciebie i twoją załogę do Błogosławionej Matki każdego dnia, który nadejdzie! Jesteś naszym aniołem stróżem. Sam Pan cię do nas zesłał, wierz lub nie\nZanim odejdziesz, chcę, żebyś wiedział, że drzwi naszego domu zawsze będą dla ciebie otwarte o każdej porze. I... proszę, pozwól mi cię pocałować, mój drogi Charlie...";
			link.l1 = "Cóż... tak, oczywiście Abi... jeśli nalegasz.";
			link.l1.go = "Abigile_GiveMoney_3";
		break;
		
		case "Abigile_GiveMoney_3":
			DialogExit();
			npchar.greeting = "abigile_1";
			npchar.dialog.currentnode = "Abigile_AllRight";
			
			StartQuestMovie(true, false, true);
			LAi_SetActorType(pchar);
			LAi_Fade("AbiKiss", "");
		break;
		
		case "Abigile_Poor":
			dialog.text = "Niech cię Bóg błogosławi, Charles. Nic się dla nas nie zmieniło... Żebrzę o resztki przed kościołem.";
			link.l1 = "Trzymaj się mocno, panienko. Niech Bóg będzie z tobą.";
			link.l1.go = "exit";
			NextDiag.TempNode = "Abigile_Poor";
		break;
		
		case "Abigile_AllRight":
			dialog.text = "Charles, to ty! Tak się cieszę, że cię widzę! Proszę, usiądź! Zaparzę kawę!";
			link.l1 = "Też się cieszę, że cię widzę, Abi. I cieszę się, że u ciebie wszystko w porządku.";
			link.l1.go = "exit";
			NextDiag.TempNode = "Abigile_AllRight";
		break;
		
		//--> блок реагирования на попытку залезть в сундук
		case "Woman_FackYou":
			dialog.text = "Ach, więc to tak?! Przyjąłem cię jako mego gościa, a ty postanowiłeś mnie okraść?! Straże!!!";
			link.l1 = "Zamknij gębę, głupia dziewko.";
			link.l1.go = "exit";
			LAi_group_Attack(NPChar, Pchar);
		break;
		//<-- блок реагирования на попытку залезть в сундук
	}
}
