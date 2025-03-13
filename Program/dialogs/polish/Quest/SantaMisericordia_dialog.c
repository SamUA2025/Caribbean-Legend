void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag, arTmp;
	int i, n;
	string sTemp, sStr;
	
	DeleteAttribute(&Dialog,"Links");
	
	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	switch(Dialog.CurrentNode)
	{
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		case "First time":
			dialog.text = "Czego ci potrzeba?";
			link.l1 = "Nic.";
			link.l1.go = "exit";
		break;
		
		case "fight":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			LAi_group_Attack(NPChar, Pchar);
			if (rand(3) != 1) SetNationRelation2MainCharacter(sti(npchar.nation), RELATION_ENEMY);
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		
		case "Alamida_church":
			dialog.text = "...i Ducha Świętego. Amen.";
			link.l1 = "Rzadko widuję wojskowych w kościołach.";
			link.l1.go = "Alamida_church_2";
		break;
		
		case "Alamida_church_2":
			dialog.text = "Wielu wierzy, że wiara i miecz są niezgodne. Ale czyż chirurg nie tnie, aby leczyć? Czyż ojciec nie karze, aby chronić?";
			link.l1 = "Brzmi jak usprawiedliwienie.";
			link.l1.go = "Alamida_church_3";
			link.l2 = "Jest w tym mądrość. Czasem okrucieństwo jest konieczne.";
			link.l2.go = "Alamida_church_4";
		break;
		
		case "Alamida_church_3":
			dialog.text = "Jesteś w błędzie. To nie jest usprawiedliwienie - to zrozumienie. Kiedy po raz pierwszy rozpocząłem służbę, każda śmierć była... trudna. Ale potem... moje oczy się otworzyły. 'Okrucieństwo jest manifestacją najwyższej miłości.'";
			link.l1 = "Zostawię cię z twoimi modlitwami.";
			link.l1.go = "Alamida_church_5";
		break;
		
		case "Alamida_church_4":
			dialog.text = "Tak... tak! Dokładnie to powiedział ten, który prowadził mnie tą ścieżką. 'Miłosierdzie bez siły jest bezużyteczne, jak miecz bez ręki.'";
			link.l1 = "Zostawię cię z twoimi modlitwami.";
			link.l1.go = "Alamida_church_5";
		break;
		
		case "Alamida_church_5":
			dialog.text = "Módl się za nas wszystkich. Za to, co robimy... i za to, co jeszcze musimy zrobić.";
			link.l1 = "...";
			link.l1.go = "Alamida_exit";
		break;
		
		case "Alamida_guber":
			dialog.text = "Siedem procent niedoboru. Ostatnim razem było pięć. Rosną jak chwasty w opuszczonym ogrodzie...";
			link.l1 = "Czy w mieście jest nowy gubernator?";
			link.l1.go = "Alamida_guber_2";
		break;
		
		case "Alamida_guber_2":
			dialog.text = "Co? Ach, nie. Jego Ekscelencja jest tam, w rogu. Jestem don Fernando de Alamida, królewski inspektor.";
			link.l1 = "To musi być ciężka praca.";
			link.l1.go = "Alamida_guber_3";
		break;
		
		case "Alamida_guber_3":
			dialog.text = "Wiesz, co jest najtrudniejsze w walce z korupcją? Winni niekoniecznie są złymi ludźmi. Mają dzieci, rodziny. I za każdym razem musisz sobie przypominać: trucizna pozostaje trucizną, nawet podana w złotym kielichu.";
			link.l1 = "Ale czy można sądzić tak surowo? Wszyscy jesteśmy ludźmi...";
			link.l1.go = "Alamida_guber_4";
			link.l2 = "Jesteś zbyt miękki. Tylko więzienie ich zreformuje.";
			link.l2.go = "Alamida_guber_5";
		break;
		
		case "Alamida_guber_4":
			dialog.text = "Miłosierdzie dla wilka jest okrucieństwem wobec owiec. Tak powiedział... mędrzec. I z każdym mijającym dniem, coraz bardziej rozumiem jego mądrość.";
			link.l1 = "Nie będę cię dłużej odciągał od pracy.";
			link.l1.go = "Alamida_guber_6";
		break;
		
		case "Alamida_guber_5":
			dialog.text = "Hm. Wiesz, kiedyś myślałem tak samo. Ale więzienie to zbyt proste. Potrzeba czegoś więcej... Oczyszczenia.";
			link.l1 = "Nie będę cię dłużej odciągać od pracy.";
			link.l1.go = "Alamida_guber_6";
		break;
		
		case "Alamida_guber_6":
			dialog.text = "Tak. Dokumenty nie będą czekać. Chociaż czasami wydaje mi się, że za każdą liczbą tutaj kryje się czyjś los.";
			link.l1 = "...";
			link.l1.go = "Alamida_exit";
		break;
		
		case "Alamida_city":
			dialog.text = "Słucham uważnie, "+GetAddress_Form(NPChar)+"? Co sprawiło, że podszedłeś do mnie tak po prostu, na ulicy?";
			link.l1 = "Wyróżniasz się spośród reszty.";
			link.l1.go = "Alamida_city_2";
		break;
		
		case "Alamida_city_2":
			dialog.text = "Don Fernando de Alamida, królewski inspektor. Jesteś dziś pierwszym takim ciekawskim. Wszyscy się ukrywają, wszyscy się mnie boją. A jednak uczciwy człowiek nie ma się czego obawiać. Co nam to mówi?";
			link.l1 = "Że twoja reputacja ich przeraża?";
			link.l1.go = "Alamida_city_3";
			link.l2 = "Że uczciwych ludzi jest niewielu?";
			link.l2.go = "Alamida_city_4";
		break;
		
		case "Alamida_city_3":
			dialog.text = "Zabawne. Też tak myślałem. Dopóki nie zrozumiałem - strach oczyszcza. Kiedy człowiek się boi, staje się bardziej szczery. Bliżej swojej prawdziwej natury. Do Boga.";
			link.l1 = "Interesująca myśl. Muszę iść. Dobrego dnia, don Fernando.";
			link.l1.go = "Alamida_city_5";
		break;
		
		case "Alamida_city_4":
			dialog.text = "Interesujące... Rozumujesz dokładnie jak ktoś, kogo znałem. Szkoda, że nie każdy potrafi zaakceptować tę prawdę.";
			link.l1 = "Interesująca myśl. Muszę iść. Dobrego dnia, don Fernando.";
			link.l1.go = "Alamida_city_5";
		break;
		
		case "Alamida_city_5":
			dialog.text = "Dobrze? Tak, może. O ile to jest słuszne.";
			link.l1 = "Nigdy się nie poddawaj.";
			link.l1.go = "Alamida_exit";
		break;
		
		case "Alamida_exit":
			DialogExit();
			
			sld = CharacterFromID("SantaMisericordia_clone_church");
			sld.dialog.filename = "Quest\SantaMisericordia_dialog.c";
			sld.dialog.currentnode = "Alamida_repeat";
			sld = CharacterFromID("SantaMisericordia_clone_city");
			sld.dialog.filename = "Quest\SantaMisericordia_dialog.c";
			sld.dialog.currentnode = "Alamida_repeat";
			sld = CharacterFromID("SantaMisericordia_clone_guber");
			sld.dialog.filename = "Quest\SantaMisericordia_dialog.c";
			sld.dialog.currentnode = "Alamida_repeat";
		break;
		
		case "Alamida_repeat":
			dialog.text = "Coś jeszcze, Kapitanie?";
			link.l1 = "Nie, don Fernando, tylko się witam, nic więcej.";
			link.l1.go = "exit";
			NextDiag.TempNode = "Alamida_repeat";
		break;
		
		case "Alamida_abordage":
			if (startHeroType == 4)
			{
				dialog.text = "Panienka z mieczem? Cóż, nigdy bym nie pomyślał, że dożyję takiego widoku. A kimże ty jesteś, señorita, by ośmielić się atakować 'Świętą Miłosierdzie'?";
				link.l1 = "Kapitan Hellen McArthur. A to zaskoczenie na twej twarzy jest mi dobrze znane.";
				link.l1.go = "Alamida_HelenaCaptain";
			}
			else
			{
				dialog.text = "Jak śmiesz?! Atakować 'Świętą Miłosierdzie'?! Statek, który niesie wolę króla i... Cóż. Skoro już tu jesteś, powiedz mi - dlaczego? Dlaczego wybrałeś to szaleństwo?";
				link.l1 = "Jestem piratem. A twój galeon z pewnością pełen jest skarbów.";
				link.l1.go = "Alamida_abordage_Gold";
				link.l2 = "Jaki piękny statek... Muszę go zdobyć.";
				link.l2.go = "Alamida_abordage_Ship";
				link.l3 = "Jestem wrogiem twojego kraju, don Fernando.";
				link.l3.go = "Alamida_abordage_Hater";
				link.l4 = "Po prostu dlatego. Czemu nie?";
				link.l4.go = "Alamida_abordage_Prikol";
			}
		break;
		
		case "Alamida_HelenaCaptain":
			dialog.text = "Jakże przypominasz Dziewicę Maryję, opiekunkę naszego statku... Tak samo piękna. Ale Ona chroni sprawiedliwych, podczas gdy ty...";
			link.l1 = "Przyszedłem po twój statek. A komplementy tu nie pomogą, don Fernando.";
			link.l1.go = "Alamida_HelenaCaptain_2";
		break;
		
		case "Alamida_HelenaCaptain_2":
			dialog.text = "Jakie to smutne. Będę musiał nauczyć cię pokory. Siłą, skoro nie ma innego sposobu.";
			link.l1 = "...";
			link.l1.go = "Alamida_abordage_SecondRound";
		break;
		
		case "Alamida_abordage_Gold":
			dialog.text = "Ach tak. Oczywiście. Złoto. Zawsze złoto. Trucizna, która koroduje dusze. Za nie zginiesz.";
			link.l1 = "Nie bądź taki dramatyczny. To tylko interesy.";
			link.l1.go = "Alamida_abordage_Gold_2";
		break;
		
		case "Alamida_abordage_Gold_2":
			dialog.text = "Każda moneta w ładowni to zapłata grzeszników za oczyszczenie. Chcesz ją? To podziel ich los.";
			link.l1 = "...";
			link.l1.go = "Alamida_abordage_SecondRound";
		break;
		
		case "Alamida_abordage_Ship":
			dialog.text = "Wielu pragnęło 'Świętej Łaski'. Jej piękno było zgubą niejednego kapitana.";
			link.l1 = "W takim razie będę pierwszym, który to zdobędzie.";
			link.l1.go = "Alamida_abordage_Ship_2";
		break;
		
		case "Alamida_abordage_Ship_2":
			dialog.text = "Miłosierdzie bez siły jest bezużyteczne, jak miecz bez ręki. Tę lekcję poznasz dzisiaj.";
			link.l1 = "...";
			link.l1.go = "Alamida_abordage_SecondRound";
		break;
		
		case "Alamida_abordage_Hater":
			dialog.text = "Więc to tyle. Kolejny zazdrośnik o wielkość Imperium.";
			link.l1 = "Jakie wielkości? Twoje sztywne sposoby powstrzymują ten świat.";
			link.l1.go = "Alamida_abordage_Hater_2";
		break;
		
		case "Alamida_abordage_Hater_2":
			dialog.text = "Nie okłamuj się. Strach przed Hiszpanią czyni cię bardziej uczciwym. Bliższym twojej prawdziwej naturze. Sam teraz zobaczysz.";
			link.l1 = "...";
			link.l1.go = "Alamida_abordage_SecondRound";
		break;
		
		case "Alamida_abordage_Prikol":
			dialog.text = "Wariat. A może zostałeś wysłany do mnie jako próba?";
			link.l1 = "Nie wszystko potrzebuje powodu, señor.";
			link.l1.go = "Alamida_abordage_Prikol_2";
		break;
		
		case "Alamida_abordage_Prikol_2":
			dialog.text = "Powiedział, że ludzie tacy jak ty są najbardziej niebezpieczni. Ale to tylko wzmocni moją rękę w bitwie.";
			link.l1 = "...";
			link.l1.go = "Alamida_abordage_SecondRound";
		break;
		
		case "Alamida_abordage_SecondRound":
			DialogExit();
			
			LAi_SetPlayerType(pchar);
			LAi_SetFightMode(pchar, true);
			LAi_SetImmortal(npchar, false);
			LAi_SetCurHPMax(npchar);
			LAi_GetCharacterMaxEnergy(npchar);
			LAi_SetWarriorType(npchar);
			LAi_group_MoveCharacter(npchar, LAI_GROUP_BRDENEMY);
			LAi_group_SetRelation(LAI_GROUP_BRDENEMY, LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups(LAI_GROUP_BRDENEMY, LAI_GROUP_PLAYER, false);
			LAi_SetCheckMinHP(npchar, 1, true, "SantaMisericordia_TrirdRound");
		break;
		
		case "Alamida_abordage_TrirdRound":
			if (startHeroType == 4)
			{
				dialog.text = "Taka siła ducha... Taka wola...";
				link.l1 = "Zaskoczony?";
			}
			else
			{
				dialog.text = "Nieźle. Minęło trochę czasu, odkąd spotkałem godnego przeciwnika.";
				link.l1 = "Nie dam ci czasu na odpoczynek.";
			}
			link.l1.go = "Alamida_abordage_TrirdRound_2";
		break;
		
		case "Alamida_abordage_TrirdRound_2":
			if (startHeroType == 4)
			{
				dialog.text = "Byłem ostrzeżony... o takim wyzwaniu. O pięknie, które mogłoby zachwiać wiarą wojownika.";
				link.l1 = "Czy zawsze tak bardzo komplikujesz proste rzeczy, don Fernando?";
			}
			else
			{
				dialog.text = "Pan daje siłę tym, którzy służą słusznej sprawie. Choć... czasami nie jestem już pewien, czemu służę.";
				link.l1 = "Miewasz wątpliwości?";
			}
			link.l1.go = "Alamida_abordage_TrirdRound_3";
		break;
		
		case "Alamida_abordage_TrirdRound_3":
			if (startHeroType == 4)
			{
				dialog.text = "Proste? Nie... To musi mieć głębsze znaczenie. To jest próba. Nie mogę się mylić.";
			}
			else
			{
				dialog.text = "Nie. Nauczył mnie nie wątpić. Nigdy.";
			}
			link.l1 = "...";
			link.l1.go = "Alamida_abordage_TrirdRound_4";
		break;
		
		case "Alamida_abordage_TrirdRound_4":
			DialogExit();
			
			LAi_SetPlayerType(pchar);
			LAi_SetFightMode(pchar, true);
			LAi_SetImmortal(npchar, false);
			LAi_SetCurHPMax(npchar);
			LAi_GetCharacterMaxEnergy(npchar);
			npchar.MultiFighter = 2.5;
			LAi_SetWarriorType(npchar);
			LAi_group_MoveCharacter(npchar, LAI_GROUP_BRDENEMY);
			LAi_group_SetRelation(LAI_GROUP_BRDENEMY, LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups(LAI_GROUP_BRDENEMY, LAI_GROUP_PLAYER, false);
			LAi_SetCheckMinHP(npchar, 1, true, "SantaMisericordia_Molitva");
			
			PlaySound("Ambient\Tavern\glotok_001.wav");
			PlaySound("Ambient\Horror\Fear_breath_01.wav");
		break;
		
		case "Alamida_abordage_Molitva":
			dialog.text = "Zaczekaj... Zaczekaj. Wygrałeś. Jestem ranny, wykrwawiam się. Pozwól mi się pomodlić przed śmiercią.";
			link.l1 = "Bardzo dobrze.";
			link.l1.go = "Alamida_abordage_Molitva_2";
		break;
		
		case "Alamida_abordage_Molitva_2":
			if (startHeroType == 4)
			{
				dialog.text = "Lord... wybacz mi moje grzechy i daj mi siłę w tej godzinie próby. Pobłogosław dusze moich poległych towarzyszy. Wierni żeglarze, zginęli wierząc, że niesieją sprawiedliwość\nOjciec, starałem się żyć według Twoich nauk, walczyć z niesprawiedliwością. Ale Twój syn splamił honor rodziny Alamida. Wybacz mi\nOjczyzno... przysięgałem Ci służyć wiernie i prawdziwie. Ale mój zapał, mój gniew... stałem się tym, z czym chciałem walczyć\nDiego... Może kłamał? Przez cały ten czas... Biada mi, jeśli tak\nI pobłogosław tę kobietę, Panie. Może w Twej ostatecznej łasce posłałeś mi ją... abym mógł zobaczyć, jak daleko zbłądziłem. Amen.";
			}
			else
			{
				dialog.text = "Boże... wybacz mi moje grzechy i daj mi siłę w tej godzinie próby. Pobłogosław dusze moich poległych towarzyszy. Wierni żeglarze, zginęli wierząc, że nieśli sprawiedliwość\nOjcze, starałem się żyć według Twoich nauk, walczyć z niesprawiedliwością. Ale Twój syn splamił honor rodziny Alamida. Wybacz mi\nOjczyzno... przysięgałem służyć Ci wiernie i prawdziwie. Ale mój zapał, mój gniew... Stałem się tym, z czym chciałem walczyć\nDiego... Może kłamał? Przez cały ten czas... Biada mi, jeśli tak\nŚwięta Maryjo Dziewico, módl się za nami do Boga i udziel nam swego miłosierdzia. Amen.";
			}
			link.l1 = "Nie rozpoznaję cię, don Fernando. Wydajesz się teraz inną osobą. A o kim mówiłeś?";
			link.l1.go = "Alamida_abordage_Molitva_3";
			LAi_SetActorType(npchar);
			LAi_ActorAnimation(npchar, "Church_Stay_1", "", 5.0);
		break;
		
		case "Alamida_BitvaEnd":
			DialogExit();
			
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload1", "none", "", "", "SantaMisericordia_CanLeaveCauta", 5);
		break;
			
		case "Alamida_abordage_Molitva_3":
			DialogExit();
			
			LAi_SetPlayerType(pchar);
			LAi_SetImmortal(npchar, false);
			LAi_KillCharacter(npchar);
			
			DoQuestFunctionDelay("Alamida_abordage_OfficerPodhodit", 2.0);
		break;
		
		//Элен
		case "Alamida_Helena":
			dialog.text = "Mój kapitanie, gratulacje! Co za zażarta bitwa. Ten kapitan był zdolny, o tak zdolny. Ale ty... ty okazałeś się jeszcze lepszy. Jakże jestem z ciebie dumny...";
			link.l1 = "Dziękuję, moja miłości. Czy jesteś ranny?";
			link.l1.go = "Alamida_Helena_2";
		break;
		
		case "Alamida_Helena_2":
			dialog.text = "Nie, nie. Chociaż myślałem, że byliśmy na krawędzi kilka razy - zarówno przed abordażem, jak i w trakcie. A ty, wszystko w porządku?";
			link.l1 = "U mnie dobrze, jeszcze raz dziękuję. Idź odpocznij w kajucie, wkrótce do ciebie dołączę.";
			link.l1.go = "Alamida_BitvaEnd";
		break;
		
		//Мэри
		case "Alamida_Mary":
			dialog.text = "Charles, wszystko w porządku? Przyszedłem, jak tylko mogłem, dobrze.";
			link.l1 = "U mnie w porządku, dziękuję, kochana. Choć to była niezła przeprawa.";
			link.l1.go = "Alamida_Mary_2";
		break;
		
		case "Alamida_Mary_2":
			dialog.text = "Cieszę się! Ale... Słuchaj, Charles? Dlaczego zaatakowaliśmy tych ludzi? Pan nam tego nie wybaczy, nie. Ten statek... jak wielka świątynia. Kiedy go zobaczyłem, moje serce zadrżało, tak samo jak wtedy, gdy po raz pierwszy zobaczyłem prawdziwy kościół, nie tylko w książkach. A teraz krwawi!";
			link.l1 = "Maryjo... Wiesz, pozory mogą mylić. A za maską pobożności kryli się ci, którzy brali pieniądze od prostych wiernych - tak jak ty. Rozumiesz?";
			link.l1.go = "Alamida_Mary_3";
		break;
		
		case "Alamida_Mary_3":
			dialog.text = "Ja... ja ci wierzę, Charles. Dobrze. Tylko... przekażmy przynajmniej część złota, które tu znaleźliśmy, tym, którzy naprawdę go potrzebują? Uspokoiłoby to moje serce.";
			link.l1 = "Zrobimy to, Mary. Obiecuję. Teraz zbierz myśli i spróbuj się uspokoić. To już koniec.";
			link.l1.go = "Alamida_BitvaEnd";
		break;
		
		//Томми
		case "Alamida_Tommi":
			dialog.text = "Ha, cóż, gratulacje z okazji zwycięstwa, kapitanie! To jest to, co nazywam interesem! Taki łup na tej galeonie!..";
			link.l1 = "Twój uśmiech jest dziś jeszcze szerszy niż zwykle, Tommy.";
			link.l1.go = "Alamida_Tommi_2";
		break;
		
		case "Alamida_Tommi_2":
			dialog.text = "Założę się! Takie łupy. I co za walka. Przypomniała mi Rewolucję. A także... heh.";
			link.l1 = "Co się stało, Tommy? No dalej, mów głośniej.";
			link.l1.go = "Alamida_Tommi_3";
		break;
		
		case "Alamida_Tommi_3":
			dialog.text = "Jak oni udekorowali cały statek jak pływającą katedrę. I zebrali tyle złota zewsząd. Prawdziwi papistowscy świętoszkowie! Hańba i śmieszność.";
			link.l1 = "To jest statek skarbowy, Tommy. Nie statek kościelny.";
			link.l1.go = "Alamida_Tommi_4";
		break;
		
		case "Alamida_Tommi_4":
			dialog.text = "Niewiele różnicy w naszym przypadku. Tak czy inaczej, cieszyłem się, że mogłem dać tym donsom i papistom porządną nauczkę! Nie znoszę żadnego z nich. Naprawdę cieszyłem się z tego dnia, ha-ha-ha!";
			link.l1 = "Ty się nigdy nie zmieniasz! Dobrze, wolne. Wszystko tutaj jest pod kontrolą.";
			link.l1.go = "Alamida_BitvaEnd";
		break;
		
		//Тичингиту
		case "Alamida_Tichingitu":
			if (startHeroType == 1)
			{
				dialog.text = "Kapitanie Charles, wygrywamy zwycięstwo. To była trudna walka. Nawet Tichingitu miał ciężko, a ja jestem jednym z najlepszych wojowników w wiosce.";
				link.l1 = "Racja, przyjacielu. Byli to godni przeciwnicy, bez wątpienia.";
			}
			if (startHeroType == 2)
			{
				dialog.text = "Señor de Montoya, statek jest nasz.";
				link.l1 = "Bardzo dobrze, Tichingitu. Ja też właśnie skończyłem tutaj.";
			}
			if (startHeroType == 3)
			{
				dialog.text = "Kapitanie Paterson, ostatni opór na statku zdławiony.";
				link.l1 = "Spóźniłeś się, Tich! Następnym razem lepiej trzymaj się mnie. Nie żebym nie mógł sobie poradzić sam, wiesz...";
			}
			if (startHeroType == 4)
			{
				dialog.text = "Kapitanie McArthur, wszystko w porządku?";
				link.l1 = "Tak, Tichingitu, mam się dobrze, dziękuję za troskę. I przestań wątpić w swojego kapitana - poradziłem sobie doskonale sam.";
			}
			link.l1.go = "Alamida_Tichingitu_2";
		break;
		
		case "Alamida_Tichingitu_2":
			if (startHeroType == 1)
			{
				dialog.text = "Duchy mówią mi to podczas walki. I pytają, czemu ich zabiłem. Teraz ja pytam ciebie o to samo. Tichingitu widzi w ich oczach, że nie są złoczyńcami. Jeszcze nie.";
				link.l1 = "Ach, cóż mogę ci powiedzieć? Nie mam odpowiedzi, Tichingitu.";
			}
			if (startHeroType == 2)
			{
				dialog.text = "Chcę zadać ci pytanie, kapitanie de Montoya.";
				link.l1 = "Słucham.";
			}
			if (startHeroType == 3)
			{
				dialog.text = "Tichingitu chce zadać ci pytanie, Kapitanie Williamie, jeśli pozwolisz.";
				link.l1 = "Przyznano.";
			}
			if (startHeroType == 4)
			{
				dialog.text = "Nie wątpię, martwię się o ciebie, kapitanie.";
				link.l1 = "Dobrze, dobrze. Widzę w twoich oczach, że chcesz mnie o coś jeszcze zapytać.";
			}
			link.l1.go = "Alamida_Tichingitu_3";
		break;
		
		case "Alamida_Tichingitu_3":
			if (startHeroType == 1)
			{
				dialog.text = "Hmm, jak mówisz, kapitanie. Kończymy tutaj?";
				link.l1 = "Tak. Rozejrzę się jeszcze trochę, a potem dołączę do innych.";
				link.l1.go = "Alamida_BitvaEnd";
			}
			if (startHeroType == 2)
			{
				dialog.text = "Ci ludzie, oni nie są z tego samego plemienia co ty? Oni nie są Hiszpanami? Dlaczego zdecydowałeś się zaatakować?";
				link.l1 = "To prawda. Ale czy plemiona indiańskie nie walczą ze sobą nawzajem? Albo czy nie ma kłótni i waśni w obrębie jednego plemienia?";
				link.l1.go = "Alamida_Tichingitu_4";
			}
			if (startHeroType == 3)
			{
				dialog.text = "Ten statek wygląda jak kościół. Nienawidzisz kościoła i białego boga?";
				link.l1 = "Skądże znowu. Ale to tylko dekoracja, rozumiesz? To jest statek skarbowy. Choć i tak byś nie zrozumiał - słyszałem, że twoi ludzie nawet nie wiedzą, co to są podatki. Szczęściarze.";
				link.l1.go = "Alamida_Tichingitu_4";
			}
			if (startHeroType == 4)
			{
				dialog.text = "Tak. Bądź szczery. Kapitanie MacArthur, dlaczego atakujemy ten pływający kościół?";
				link.l1 = "Pływający kościół, ha-ha-ha! Nie, nie. To jest statek skarbniczy. Hmm, widzę, że nie do końca rozumiesz. Cóż, przewozili złoto. Mogę sobie wyobrazić, jak dumny będzie Jan, kiedy powiem mu, że pokonałem Fernando de Alamida!";
				link.l1.go = "Alamida_Tichingitu_4";
			}
		break;
		
		case "Alamida_Tichingitu_4":
			if (startHeroType == 2)
			{
				dialog.text = "Hmm, masz rację, kapitanie. Ale z Indianami to się zdarza rzadziej niż z białym człowiekiem.";
				link.l1 = "Być może. Cóż, ten człowiek mi... przeszkadzał.";
				link.l1.go = "Alamida_Tichingitu_5";
			}
			if (startHeroType == 3)
			{
				dialog.text = "Być może, Maskogi nie mają zamków ani podatków.";
				link.l1 = "Dokładnie. Możesz iść, i tak jesteś spóźniony. Później zdecydujemy, co zrobić z tym pięknym galeonem. Nie lubię tych balii, ale do diabła, jest piękna.";
				link.l1.go = "Alamida_BitvaEnd";
			}
			if (startHeroType == 4)
			{
				dialog.text = "Tichingitu również jest z ciebie dumny, kapitanie. I gratuluje zwycięstwa w tej ciężkiej walce.";
				link.l1 = "Dziękuję. Teraz podzielmy łupy.";
				link.l1.go = "Alamida_BitvaEnd";
			}
		break;
		
		case "Alamida_Tichingitu_5":
			dialog.text = "Mieszasz się, Señor de Montoya?";
			link.l1 = "Dokładnie. Ten Archipelag jest zbyt mały dla nas obu. A ja jestem tu znacznie bardziej przydatny naszemu państwu. Pamiętaj o Liściu Kokosowym - wyrządził więcej szkody niż pożytku swoim braciom. Tutaj jest tak samo.";
			link.l1.go = "Alamida_Tichingitu_6";
		break;
		
		case "Alamida_Tichingitu_6":
			dialog.text = "Teraz rozumiem. Tichingitu może iść, kapitanie?";
			link.l1 = "Tak, idź. Wkrótce do was dołączę.";
			link.l1.go = "Alamida_BitvaEnd";
		break;
		
		case "Alamida_monah":
			dialog.text = "Ciekawe... Co sprowadza dziecko Boże do tego miejsca... odpoczynku?";
			link.l1 = "Ja...";
			link.l1.go = "Alamida_monah_2";
		break;
		
		case "Alamida_monah_2":
			dialog.text = "Czy wiesz, co jest szczególnego w tym grobowcu? Spoczywają tu dwie dusze, związane... więzami krwi. Ojciec i syn de Alamida. Jeden padł w ręce grzeszników, drugi... Hmm, znalazł swoją drogę do Pana.";
			link.l1 = "Dziennik don Fernanda doprowadził mnie tutaj.";
			link.l1.go = "Alamida_monah_3";
			link.l2 = "Po prostu szukam czegoś cennego w tej krypcie.";
			link.l2.go = "Alamida_monah_6";
		break;
		
		case "Alamida_monah_3":
			dialog.text = "Ah... Dziennik. Niezwykła rzecz - słowo pisane. To jak... ścieżka w ciemności. Prowadzi tam, gdzie... czeka objawienie. Naszą parafię często odwiedzał don Fernando. Zwłaszcza w ostatnim roku.";
			link.l1 = "Służysz w lokalnej parafii? Znałeś don Fernando?";
			link.l1.go = "Alamida_monah_4";
			ChangeCharacterComplexReputation(pchar, "nobility", 2);
		break;
		
		case "Alamida_monah_4":
			dialog.text = "...";
			link.l1 = "...";
			link.l1.go = "Alamida_monah_5";
		break;
		
		case "Alamida_monah_5":
			dialog.text = "Ja... obserwowałem jego ścieżkę. A tę książkę, którą zabrałeś. Wiesz, co czyni ją wyjątkową?";
			link.l1 = "Wygląda na stare.";
			link.l1.go = "Alamida_monah_5_1";
		break;
		
		case "Alamida_monah_5_1":
			dialog.text = "Stara? O nie. To... oświecona. Biblia don de Alamida Seniora. Każde słowo w niej - niczym latarnia w ciemności. Weź ją. Pomóż swym braciom w Chrystusie, a wtedy, być może... poprowadzi cię do czegoś... większego.";
			link.l1 = "...";
			link.l1.go = "Alamida_monah_9";
		break;
		
		case "Alamida_monah_6":
			dialog.text = "Jakże... przyziemne. A jednak... Czyż to nie jest niezwykłe? Spośród wszystkich krypt, przyszedłeś do tej. Przypadek?";
			link.l1 = "...";
			link.l1.go = "Alamida_monah_7";
			ChangeCharacterComplexReputation(pchar, "nobility", -2);
		break;
		
		case "Alamida_monah_7":
			dialog.text = "...";
			link.l1 = "...";
			link.l1.go = "Alamida_monah_8";
		break;
		
		case "Alamida_monah_8":
			dialog.text = "O nie. Pan zawsze znajduje sposób, nawet dla tych, którzy błądzą w ciemności.";
			link.l1 = "...";
			link.l1.go = "Alamida_monah_9";
		break;
		
		case "Alamida_monah_9":
			DialogExit();
			
			locCameraSleep(true);
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocator(npchar, "reload", "reload2", "", -1);
			DoQuestFunctionDelay("SantaMisericordia_HavanaCrypt_9", 2.4);
		break;
		
		case "Alamida_monah_10":
			dialog.text = "Czy wiesz, co jest najbardziej niezwykłego w losie don Fernanda?";
			link.l1 = "Co to jest?";
			link.l1.go = "Alamida_monah_11";
		break;
		
		case "Alamida_monah_11":
			dialog.text = "Że był zaledwie... pierwszym.";
			link.l1 = "...";
			link.l1.go = "Alamida_monah_12";
		break;
		
		case "Alamida_monah_12":
			DialogExit();
			
			sld = CharacterFromID("SantaMisericordia_priest");
			LAi_SetActorType(sld);
			LAi_ActorGoToLocation(sld, "reload", "reload2", "none", "", "", "SantaMisericordia_Final", 3);
			sld.lifeday = 0;
			LAi_CharacterDisableDialog(sld);
			LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS");
		break;
		
		//замечение по обнажённому оружию
		case "CitizenNotBlade":
			dialog.text = LinkRandPhrase("Hej, co to za machanie bronią?! Schowaj to natychmiast!","Rozkazuję ci natychmiast schować broń!","Hej, "+GetAddress_Form(NPChar)+", przestań straszyć ludzi! Schowaj swoją broń.");
			link.l1 = LinkRandPhrase("Dobrze, schowam to...","Już zrobione.","Jak powiadasz...");
			link.l1.go = "exit";
			link.l2 = LinkRandPhrase("Cholera jasna!","Chyba go użyję!","Odłożę to, gdy przyjdzie odpowiedni czas.");
			link.l2.go = "fight";
		break;
		
	}
} 