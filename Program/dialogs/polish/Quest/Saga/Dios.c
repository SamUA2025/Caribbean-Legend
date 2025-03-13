// Хосе Диос - картограф
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
	int i;
	string sTemp;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			dialog.text = "Chcesz czegoś?";
			if (CheckAttribute(pchar, "questTemp.Saga.SharkHunt") && pchar.questTemp.Saga.SharkHunt == "dios")
			{
				link.l3 = TimeGreeting()+" ! Powiedz mi, czy jesteś Jose Dios, kartografem?";
				link.l3.go = "island";
			}
			link.l1 = "Nie, nic.";
			link.l1.go = "exit";	
			NextDiag.TempNode = "First time";
		break;
		
		case "island":
			dialog.text = "Tak, to ja. Nie znam cię, senor. Czego ode mnie chcesz?";
			link.l1 = "Nazywam się "+GetFullName(pchar)+" a ja zostałem wysłany przez Jana Svensona. Pamiętasz go?";
			link.l1.go = "island_1";
		break;
		
		case "island_1":
			dialog.text = "Ach, señor Svenson! Oczywiście, że go pamiętam! Proszę, rozgość się... Jak się miewa szanowny Jan?";
			link.l1 = "Dzięki, ma się dobrze. Senor Dios, potrzebuję twojej pomocy. Chcę się z tobą skonsultować w sprawie, którą musisz znać ze względu na swój zawód. Jan polecił cię jako eksperta od geografii regionu Karaibów...";
			link.l1.go = "island_2";
		break;
		
		case "island_2":
			dialog.text = "Słucham, Senor. Co chcesz wiedzieć o geografii archipelagu?";
			link.l1 = "Mówią, że na północny zachód od Hawany, pomiędzy Kubą a Zatoką Meksykańską, znajduje się wyspa lub inna formacja. Wyspa ta nigdy nie została uwzględniona na żadnej mapie. Chciałbym poznać wiarygodność tych plotek.";
			link.l1.go = "island_3";
		break;
		
		case "island_3":
			dialog.text = "Hm... Zapytałeś o coś, co nurtuje mnie od wielu lat. To miejsce, które wspomniałeś, od dawna przyciąga ciekawskie umysły geografów, ale nikt nigdy nie miał odwagi zbadać tego regionu.";
			link.l1 = "Dlaczego?";
			link.l1.go = "island_4";
		break;
		
		case "island_4":
			dialog.text = "Rzecz w tym, że to miejsce jest pewnego rodzaju anomalią naturalną. Prawdopodobieństwo burz w tym regionie jest znacznie wyższe niż gdziekolwiek indziej. Być może przyczyna leży w zimnym prądzie morskim, ale to tylko moja hipoteza. Wiele statków tam zniknęło i to wystarczyło, aby marynarze unikali tego miejsca, zresztą wszystkie główne trasy morskie i tak omijają ten region z daleka.";
			link.l1 = "Rozumiem, że ty również nie znasz prawdy...";
			link.l1.go = "island_5";
		break;
		
		case "island_5":
			dialog.text = "Dokładnie, Senor. Ale mam kilka dokumentów historycznych i pewne dowody rzeczowe, więc mam wszelkie prawa podejrzewać dużą prawdopodobieństwo istnienia tego miejsca.";
			link.l1 = "Czy możesz mi powiedzieć więcej?";
			link.l1.go = "island_6";
		break;
		
		case "island_6":
			dialog.text = "Z pewnością. Najważniejszym dowodem jest historyczny dokument z wyciągami z dziennika kapitana Alvarado, który odwiedził Wyspę w 1620 roku. Powiem ci, to całkiem interesująca historia!";
			link.l1 = "Kapitan Alvarado? Drugi raz słyszę to imię...";
			link.l1.go = "island_7";
		break;
		
		case "island_7":
			dialog.text = "Nie jestem zaskoczony. Opowieść o kapitanie Alvarado jest częścią folkloru od lat. Zmieniała się, wypełniała plotkami, kłamstwami i marzeniami, i oto jest - legenda o Wyspie Opuszczonych Statków.\nPlotki mogą się zmieniać, ale papier i atrament nie, pozostają nienaruszone przez setki lat. Oto, przeczytaj tę opowieść - być może pomoże ci odsłonić to, czego szukasz.";
			link.l1 = "Dzięki! Masz coś jeszcze?";
			link.l1.go = "island_8";
		break;
		
		case "island_8":
			dialog.text = "Jest teoria, że dno morza w tym rejonie wznosi się wystarczająco wysoko, by utworzyć rozległą mieliznę. I już wspomniałem o prądzie. Według opowieści żeglarzy występuje tam także duże zgromadzenie mew i innych ptaków morskich.\nAlvorado wspomniał nazwy okrętów, które były częścią eskadry admirała Francisco Betancourta, eskadry, która zaginęła ponad pięćdziesiąt lat temu. Wątpię, by to był przypadek...";
			link.l1 = "Powrócę na mój statek i dokładnie przeczytam notatki Alvarado. Dziękuję za pomoc, Senor Dios!";
			link.l1.go = "island_9";
		break;
		
		case "island_9":
			dialog.text = "Nie ma za co. W rzeczywistości wcale ci nie pomogłem, nie masz współrzędnych tego miejsca, a ja również ich nie mam. Nie mogę nawet udowodnić, że tam jest jakaś zamieszkana wyspa. Ale, o ile rozumiem, zamierzasz zbadać ten obszar?\nJeśli tak, to bądź świadomy, że będę naprawdę wdzięczny za wszelkie informacje, zwłaszcza jeśli będą poparte materialnym dowodem. Wydajesz się być zamożnym człowiekiem, ale znajdę sposób, by ci się odwdzięczyć.";
			link.l1 = "Dobrze. Zatem mamy umowę, Senor Dios. Być może ktoś w przyszłości przeczyta moje zapiski... A ktoś nawet może napisze legendę...";
			link.l1.go = "island_10";
		break;
		
		case "island_10":
			dialog.text = "Dlaczego nie? Señor "+pchar.name+", Widzę, że jesteś śmiałym człowiekiem, który wiele podróżuje, więc chcę cię o coś poprosić.";
			link.l1 = "Tak? Słucham.";
			link.l1.go = "island_11";
		break;
		
		case "island_11":
			dialog.text = "Wiesz, że jestem kartografem. Od dwóch lat rysuję mapy archipelagu Karaibów, tworząc atlas admirała na konkurs Wicekróla Nueva Granada. Ale wszystkie moje dwadzieścia cztery mapy zostały skradzione z mojego domu w najbardziej bezczelny sposób, gdy zostałem pojmany przez piratów, tych, od których senor Svenson mnie uratował.\nJestem pewien, że atak został zorganizowany przez jednego z moich konkurentów, aby zdobyć moje mapy. Minęło dużo czasu, ale nie widziałem ani jednej mapy z mojego zestawu ponownie.";
			link.l1 = "Rozumiem. Chcesz, żebym zwrócił twoje mapy.";
			link.l1.go = "island_12";
		break;
		
		case "island_12":
			dialog.text = "Dokładnie. Może znajdziesz je podczas swoich przyszłych przygód. Łatwo je rozpoznać - mój znak jest na każdej z nich. Hojnie cię nagrodzę, jeśli jakimś cudem uda ci się zebrać wszystkie dwadzieścia cztery mapy.";
			link.l1 = "Dobrze. Od tej chwili będę uważnie przyglądać się każdej mapie, jaką znajdę w archipelagu. Cóż, muszę już iść. Dziękuję za interesującą rozmowę i za dokument.";
			link.l1.go = "island_13";
		break;
		
		case "island_13":
			DialogExit();
			AddQuestRecordInfo("LSC_Alvorado", "1");
			AddQuestRecord("SharkHunt", "4");
			pchar.questTemp.Saga.SharkHunt = "LSC";
			NextDiag.CurrentNode = "Dios";
			AddCharacterExpToSkill(pchar, "Fortune", 50);//везение
			pchar.questTemp.AdmiralMap = "true";
		break;
		
		case "Dios":
			dialog.text = "A-ach, to ty, señor "+GetFullName(pchar)+"Masz coś ciekawego do opowiedzenia?";
			if (CheckAttribute(pchar, "questTemp.AdmiralMap") && CountAdmiralMapFromCharacter() > 0 && CountAdmiralMapFromCharacter() < 24 && !CheckAttribute(npchar, "quest.mapinfo"))
			{
				link.l3 = TimeGreeting()+"! Señor Dios, proszę, spójrz na mapę, którą znalazłem. To musi być jedna z twoich map według znaku.";
				link.l3.go = "map_info";
			}
			if (CheckAttribute(pchar, "questTemp.AdmiralMap") && CountAdmiralMapFromCharacter() > 23)
			{
				link.l3 = TimeGreeting()+"¡Señor Dios, mam dla ciebie dobre wieści. Udało mi się zebrać pełny zestaw twoich unikalnych map, dokładnie tak, jak chciałeś. Oto wszystkie dwadzieścia cztery mapy.";
				link.l3.go = "amap";
			}
			if (CheckAttribute(pchar, "questTemp.LSC.Dios")) // был в LSC
			{
				link.l4 = TimeGreeting()+"Tak, mam. Byłem w tym mistycznym miejscu, o którym rozmawialiśmy.";
				link.l4.go = "LSC";
			}
			link.l9 = "Nic dotąd, Senor. Chciałem tylko zobaczyć, jak się miewasz.";
			link.l9.go = "exit";
			NextDiag.TempNode = "Dios";
		break;
		
		case "map_info":
			dialog.text = "Pokaż mi... (spoglądając) Oczywiście! To jedna z moich map do atlasu admirała! Kapitanie, naprawdę proszę cię, abyś je wszystkie odnalazł! Rozumiem, że to prawie niemożliwe, ale mimo wszystko... Nie chcę tracić nadziei.";
			link.l1 = "Nie zgub tego, Senor. Znalazłem tę mapę, więc istnieje szansa, że znajdę także resztę. Oni wciąż są na Karaibach.";
			link.l1.go = "map_info_1";
		break;
		
		case "map_info_1":
			dialog.text = "Twój optymizm naprawdę mnie zachęca, Senor kapitanie. Być może wciąż będę miał okazję pokazać don Juanowi de Cordovie, kto jest najlepszym kartografem archipelagu!";
			link.l1 = "Zdołasz pokonać wszystkich swych konkurentów niedobrze życzących. Mapy są naprawdę cudowne... Żegnaj, Senor!";
			link.l1.go = "exit";
			npchar.quest.mapinfo = "true";
			NextDiag.TempNode = "Dios";
		break;
		
		case "amap":
			Achievment_Set("ach_CL_110");
			dialog.text = "Nie mogę uwierzyć własnym oczom! Czy naprawdę ich znalazłeś? Wszystkich?";
			link.l1 = "Tak. Nie było łatwo, ale miałem szczęście w tych poszukiwaniach. Weź swoje mapy. Są tak wspaniałe, że żal mi się z nimi rozstawać.";
			link.l1.go = "amap_1";
		break;
		
		case "amap_1":
			for(i=1; i<=24; i++)
			{
				sTemp = IdentifyAdmiralMapLast();
				if (sTemp != "") RemoveItems(pchar, sTemp, 1);
			}
			Log_Info("You have given the complete set of admiral's maps");
			PlaySound("interface\important_item.wav");
			dialog.text = "Niewiarygodne! To jest po prostu zbyt niewiarygodne! Szczerze mówiąc, nigdy nie wierzyłem, że ten moment nastąpi.";
			link.l1 = "Dum spiro, spero, Senor Dios. Możesz teraz stawić czoła donowi Cordovie. Jestem pewien, że wysoko oceni twoje talenty.";
			link.l1.go = "amap_2";
		break;
		
		case "amap_2":
			dialog.text = "Masz moje podziękowania, Kapitanie! Nawet nie zdajesz sobie sprawy, jak wielką przysługę mi wyświadczyłeś. I jak obiecałem - wynagrodzę cię. Mam też dla ciebie prezent. Myślę, że jako żeglarz uznasz go za bardzo przydatny.";
			link.l1 = "Zaintrygowałeś mnie, seniorze!";
			link.l1.go = "amap_3";
		break;
		
		case "amap_3":
			GiveItem2Character(pchar, "spyglass5"); 
			Log_Info("You have received a ship telescope");
			PlaySound("interface\important_item.wav");
			dialog.text = "Proszę bardzo! To luneta okrętowa mojego projektu. Jest unikalna i nigdzie indziej nie znajdziesz takiej samej. Soczewki zostały wykonane w Europie przez najzręczniejszego mistrza w Hiszpanii. Jej obudowę stworzył przyjazny rusznikarz. Specjalny statyw pomoże Ci skierować urządzenie mimo wszelkich kołysania. Możesz zobaczyć wszystko, czego potrzebujesz, czy to statek, czy fort.";
			link.l1 = "Jakże wspaniały prezent! Dziękuję, Señor Dios.";
			link.l1.go = "amap_4";
		break;
		
		case "amap_4":
			dialog.text = "Użyj tego, señor kapitanie. Mam nadzieję, że mój teleskop będzie ci dobrze służył.";
			link.l1 = "Bez wątpienia! Nie mogę się doczekać, aż postawię go na pokładzie mojego statku i spojrzę przez niego.";
			link.l1.go = "amap_5";
		break;
		
		case "amap_5":
			dialog.text = "Będziesz zaskoczony, zapewniam cię... Jeszcze raz dzięki za uratowanie moich map!";
			link.l1 = "Dziękuję również, señor. Myślę, że jeszcze się zobaczymy. Ale na razie, żegnam cię. Idę wypróbować twoje wspaniałe urządzenie. Żegnaj!";
			link.l1.go = "amap_6";
			link.l2 = "Dziękuję również, señor. Luneta morska to wyjątkowa i bardzo przydatna rzecz dla żeglarza. Mimo to, nie może być bardziej wartościowa niż zestaw twoich map. Łagodnie zazdroszczę Donowi de Cordova. Ach! Chciałbym mieć takie piękne mapy na biurku kapitana w mojej kajucie.";
			link.l2.go = "amapcopy_01";
		break;
		
		case "amap_6":
			DialogExit();
			NextDiag.CurrentNode = "Dios";
			AddCharacterExpToSkill(pchar, "Fortune", 1000);//везение
			AddCharacterExpToSkill(pchar, "Leadership", 1000); // харизма
			AddCharacterExpToSkill(pchar, "Sneak", 300);//скрытность (раз телескоп дали)
			ChangeCharacterComplexReputation(pchar, "nobility", 10);// репутация-известность
			ChangeCharacterComplexReputation(pchar, "authority", 5);// репутация-авторитет
			ChangeCharacterNationReputation(pchar, SPAIN, 20);
			ChangeOfficersLoyality("good_all", 5);
			DeleteAttribute(pchar, "questTemp.AdmiralMap");
		break;
		
		case "amapcopy_01":
			AddCharacterExpToSkill(pchar, "Fortune", 1000);//везение
			AddCharacterExpToSkill(pchar, "Leadership", 1000); // харизма
			AddCharacterExpToSkill(pchar, "Sneak", 300);//скрытность (раз телескоп дали)
			ChangeCharacterComplexReputation(pchar, "nobility", 10);// репутация-известность
			ChangeCharacterComplexReputation(pchar, "authority", 5);// репутация-авторитет
			ChangeCharacterNationReputation(pchar, SPAIN, 20);
			ChangeOfficersLoyality("good_all", 5);
			DeleteAttribute(pchar, "questTemp.AdmiralMap");
			dialog.text = "Ach, senor, lecz mapy są jedyne w swoim rodzaju. A gdybym zaczął robić kopie, unikalność tego atlasu zniknęłaby, gdy tylko Don Juan de Cordova dowiedziałby się, że ktoś inny ma takie same.";
			link.l1 = "Hmm... Senor Dios, czy jest jakiś sposób, byś zrobił wyjątek?";
			link.l1.go = "amapcopy_02";
		break;
		
		case "amapcopy_02":
			dialog.text = "Wyjątek?";
			link.l1 = "Both you and I are honest people; we had the opportunity to convince each other of that. If you would make a copy of your maps for me, I would swear that no one would ever know about it. Understand: your maps are truly magnificent, and for me, as a sailor, this atlas is a real treasure. Moreover, I would generously pay you for your work.";
			link.l1.go = "amapcopy_03";
		break;
		
		case "amapcopy_03":
			dialog.text = "Señor "+pchar.lastname+", nie wątpię ani przez chwilę, że dotrzymasz słowa. A biorąc pod uwagę, co dla mnie zrobiłeś, bardzo trudno mi odmówić twojej prośbie. Ponadto fakt, że ty, doskonały żeglarz, tak wysoko cenisz moje mapy, jest już dla mnie cennym komplementem jako kartografa.";
			link.l1 = "Wierz mi, ani trochę nie przesadzałem. A co ty na to?";
			link.l1.go = "amapcopy_04";
		break;
		
		case "amapcopy_04":
			dialog.text = "„Dobrze, zgadzam się zrobić dla ciebie kopię tego atlasu. Ale jest mały problem. Kiedy mój cenny atlas został skradziony, złodzieje zabrali także wszystkie moje narzędzia - może po to, aby upewnić się, że nigdy nie zrobię więcej map, albo by też zastawić je moim konkurentom. A jeśli mam robić mapy o takiej jakości, nie mogę używać zwykłych przyborów piśmienniczych.\nPróbowałem kupić materiały piśmiennicze na rynku, ale nie miałem szczęścia - nic nie jest na sprzedaż. Jeśli możesz zdobyć dla mnie potrzebne materiały, zrobię dla ciebie kopie tych map.”";
			link.l1 = "Nie ma sprawy, przyniosę ci wysokiej jakości przybory do pisania. A co z zapłatą?";
			link.l1.go = "amapcopy_05";
		break;
		
		case "amapcopy_05":
			dialog.text = "Nie chcę wydawać się skąpy, senor... Ale będę musiał poprosić cię o trzy skrzynie dublonów za tę robotę. Również będę potrzebował miesiąca na wykonanie zadania - takich map nie można stworzyć w parę godzin.";
			link.l1 = "Oczywiście, zgadzam się! Wartość twoich map znacznie przewyższa wspomnianą kwotę.";
			link.l1.go = "amapcopy_06";
		break;
		
		case "amapcopy_06":
			dialog.text = "W takim razie będę czekał na ciebie z potrzebnymi zapasami i uzgodnioną płatnością. Jak tylko wszystko przyniesiesz, zacznę pracę.";
			if(GetCharacterItem(pchar,"chest") >= 3 && GetCharacterItem(pchar,"mineral21") > 0)
			{
				link.l1 = "Nie będziesz musiał długo czekać: jak na szczęście, mam wszystko, czego potrzebujesz. Proszę bardzo.";
				link.l1.go = "amapcopy_07";
			}
			link.l2 = "Nie będziesz musiał długo czekać, señor!";
			link.l2.go = "amapcopy_exit";
		break;
		
		case "amapcopy_07":
			dialog.text = "Fantastyczne wieści! Wiesz, dla prawdziwego kartografa nie ma nic bardziej radosnego niż to, gdy jego praca jest tak wysoko ceniona. Muszę przyznać, że cieszę się, iż prawdziwy profesjonalny żeglarz będzie korzystał z mojej pracy. Teraz potrzebuję miesiąca, by je ukończyć. Następnie będę czekał na ciebie u siebie!";
			link.l1 = "Wracam za miesiąc, señor Dios. I jeszcze raz, bardzo dziękuję!";
			link.l1.go = "amapcopy_08";
		break;
		
		case "amapcopy_08":
			TakeNItems(pchar,"chest", -3);
			TakeNItems(pchar,"mineral21", -1);
			Log_info("You handed over writing supplies and three chests with doubloons.");
			PlaySound("interface\important_item.wav");
			SetTimerFunction("Amapcopy_comlete", 0, 0, 30);
			pchar.questTemp.AdmiralMapCopy = "wait";
			NextDiag.CurrentNode = "amapcopy_waitmonth";
			DialogExit();
		break;
		
		case "amapcopy_exit":
			DialogExit();
			NextDiag.CurrentNode = "amapcopy_waitchest";
		break;
		
		case "amapcopy_waitchest":
			dialog.text = "Witam, señor "+pchar.lastname+"! Przyniosłeś to, o co prosiłem?";
			link.l1 = "Jeszcze nie, señor Dios. Ale na pewno wszystko przyniosę!";
			link.l1.go = "amapcopy_exit";
			if(GetCharacterItem(pchar,"chest") >= 3 && GetCharacterItem(pchar,"mineral21") > 0)
			{
				link.l2 = "Tak, señor Dios. Oto twoje nowe przybory do pisania i uzgodniona zapłata.";
				link.l2.go = "amapcopy_07";
			}
		break;
		
		case "amapcopy_waitmonth":
			if(CheckAttribute(pchar,"questTemp.AdmiralMapCopy") && pchar.questTemp.AdmiralMapCopy == "complete")
			{
				dialog.text = "A oto i Ty, mój drogi przyjacielu! Mam nadzieję, że nie masz nic przeciwko, bym tak cię nazywał?";
				link.l1 = "Wcale nie, przyjacielu. Naprawdę cieszę się, że zostaliśmy przyjaciółmi.";
				link.l1.go = "amapcopy_09";
			}
			else
			{
				dialog.text = "Witaj, señor! Proszę o wybaczenie, ale mapy nie są jeszcze gotowe!";
				link.l1 = "Tak, pamiętam, że powiedziałeś, iż będziesz potrzebował miesiąc. Przyszedłem tylko sprawdzić, co u ciebie.";
				link.l1.go = "amapcopy_waitmonth_01";
			}
		break;
		
		case "amapcopy_waitmonth_01":
			NextDiag.CurrentNode = "amapcopy_waitmonth";
			DialogExit();
		break;
		
		case "amapcopy_09":
			dialog.text = "Mam dla ciebie wspaniałe wieści! W końcu skończyłem kopię atlasu admirała. Oryginał zachowam dla siebie, ponieważ nadal zamierzam uczestniczyć w służbie Wicekróla Nowej Grenady. Ale kopie są twoje! Mam nadzieję, że dobrze ci posłużą.";
			link.l1 = "Dziękuję bardzo, señor! Nie masz pojęcia, jak cenny jest twój atlas dla kogoś takiego jak ja! Przysięgam na mój honor: nikt nigdy nie dowie się, że zrobiłeś dla mnie tę kopię!";
			link.l1.go = "amapcopy_10";
		break;
		
		case "amapcopy_10":
			GiveAdmiralAtlasToCharacter(pchar);
			Log_Info("You received a set of admiral's maps.");
			PlaySound("interface\important_item.wav");
			dialog.text = "Cieszę się, że jesteś zadowolony. Co więcej, skoro wszystko tak się potoczyło, mam dla ciebie jeszcze jedną propozycję.";
			link.l1 = "Cóż to takiego? Słucham bardzo uważnie.";
			link.l1.go = "best_map";
		break;
		
		case "best_map":
			dialog.text = "Podczas gdy rysowałem te mapy dla ciebie, naszła mnie myśl, że choć są dobre dla odkrywcy, nie dostarczają wszystkiego, czego potrzebuje kapitan morski. Zobacz sam: wszystkie zatoki, przylądki i laguny są na nich przedstawione bardzo dokładnie, ale nie możesz ich użyć do wytyczenia kursu między wyspami.";
			link.l1 = "To prawda, nie można według nich wyznaczyć kursu. Ale w żadnym razie nie śmiem narzekać, senor Dios! Zrobiłeś dla mnie mapy dokładnie tak, jak się umówiliśmy, nic mniej.";
			link.l1.go = "best_map_01";
		break;
		
		case "best_map_01":
			dialog.text = "Ale mogę dla ciebie stworzyć także mapę archipelagu! I to nie taką, jaką można kupić od Holenderskiej Kompanii Zachodnioindyjskiej, ale unikalną, doskonałą mapę.";
			link.l1 = "Dziękuję, señor Dios, ale nie potrzebuję takiej mapy. Niemniej jednak, dziękuję bardzo za ofertę!";
			link.l1.go = "best_map_02";
			link.l2 = "Żartujesz sobie?! Señor Dios, jak mógłbym w ogóle odmówić? Po prostu powiedz mi, czego potrzebujesz - nie pożałuję ani pieniędzy, ani narzędzi!";
			link.l2.go = "best_map_04";
		break;
		
		case "best_map_02":
			dialog.text = "Cóż, musiałem zaproponować. W każdym razie, to była przyjemność robić z tobą interesy, señor "+pchar.lastname+"!";
			link.l1 = "Podobnie! Powodzenia!";
			link.l1.go = "best_map_03";
		break;
		
		case "best_map_03":
			DeleteAttribute(pchar, "questTemp.AdmiralMapCopy");
			DialogExit();
			NextDiag.CurrentNode = "Dios";
		break;
		
		case "best_map_04":
			dialog.text = "Już przyniosłeś mi narzędzia, dziękuję. Potrzebuję jeszcze zwykłej mapy archipelagu, a także proszę o busolę i działający chronometr: mapa musi być dokładna, w przeciwnym razie tylko ci przeszkodzi. Co do zapłaty - proszę o jedną skrzynię z dublonami.";
			link.l1 = "Zwykła mapa archipelagu, busola, działający chronometr i jedna skrzynia z dublonami... Po co ci to wszystko? Myślałem, że po prostu zrobisz kopię, tak jak z mapami wysp...";
			link.l1.go = "best_map_05";
		break;
		
		case "best_map_05":
			dialog.text = "Tak, podobnie jak w przypadku innych map, już zrobiłem kopię ogólnej mapy archipelagu. Klient był ten sam - wicekról Nowej Grenady, Don Juan de Cordova. Potrzebował tej mapy dla kapitana ogromnej eskadry, która żegluje między Starym a Nowym Światem przez Atlantyk. Ale mapa jest już w rękach jej właściciela.";
			link.l1 = "Teraz rozumiem. Będziesz musiał narysować tę mapę jeszcze raz?";
			link.l1.go = "best_map_06";
		break;
		
		case "best_map_06":
			dialog.text = "Dokładnie. Dlatego potrzebuję zwykłej mapy, aby się zorientować, oraz przyrządów nawigacyjnych do dokładniejszych pomiarów. Stworzenie tego zajmie mi około tygodnia - w końcu to nie pierwszy raz, kiedy rysuję taką mapę. Och, warunek jest taki sam jak wcześniej: to musi pozostać między nami. Wicekról może się rozgniewać, jeśli dowie się, że rysuję takie mapy nie tylko dla niego.";
			if(CheckAMapItems())
			{
				link.l1 = "Pamiętam to, Señor Dios. Nie martw się, nikt nie dowie się o tych mapach. I już mam wszystko, czego potrzebujesz, przy sobie. Proszę, weź to.";
				link.l1.go = "best_map_07";
			}
			link.l2 = "Pamiętam to, Senor Dios. Nie martw się, nikt się nie dowie o tych mapach. A ja przyniosę wszystko, czego potrzebujesz, po prostu poczekaj.";
			link.l2.go = "best_map_07e";
		break;
		
		case "best_map_07e":
			DialogExit();
			NextDiag.CurrentNode = "best_map_waititems";
		break;
		
		case "best_map_waititems":
			dialog.text = "Witaj, mój drogi przyjacielu! Czy przyniosłeś to, o co prosiłem?";
			link.l1 = "Jeszcze nie, Señor Dios. Ale na pewno to przyniosę!";
			link.l1.go = "best_map_07e";
			if(CheckAMapItems())
			{
				link.l2 = "Tak, Señor Dios. Oto wszystko, o co prosiłeś: regularna mapa archipelagu, busola, działający chronometr i uzgodniona zapłata.";
				link.l2.go = "best_map_07";
			}
		break;
		
		case "best_map_07":
		    Log_Info("You handed over a regular map of the archipelago, a boussole, a tariffed chronometer, and a chest with doubloons.");
			TakeNItems(pchar,"chest", -1);
			TakeNItems(pchar,"map_normal", -1);
			TakeNItems(pchar,"bussol", -1);
			TakeNItems(pchar,"clock2", -1);
			dialog.text = "Cóż, zabiorę się do roboty. Wróć do mnie za tydzień, a obiecuję, że nie pożałujesz!";
			link.l1 = "Nie mam wątpliwości, señor. Do zobaczenia za tydzień!";
			link.l1.go = "best_map_08";
		break;
		
		case "best_map_08":
			SetTimerFunction("AdmAtlas_comlete", 0, 0, 7);
			NextDiag.CurrentNode = "best_map_wait";
			pchar.questTemp.AdmiralAtlas = true;
			DialogExit();
		break;
		
		case "best_map_wait":
			if(CheckAttribute(pchar,"questTemp.AdmiralAtlas") && pchar.questTemp.AdmiralAtlas == "complete")
			{
				dialog.text = "Ach, oto jesteś, Senor "+pchar.lastname+" ! Miło mi poinformować, że ukończyłem mapę archipelagu! I mogę cię zapewnić, że jest tak samo dobra jak pierwszy rysunek, który zrobiłem dla Don Juana de Cordovy!";
				link.l1 = "Mój przyjacielu... Ta mapa jest zdumiewająca! To nic innego jak arcydzieło! Jak mogę ci podziękować za wszystko, co dla mnie zrobiłeś?";
				link.l1.go = "best_map_09";
			}
			else
			{
				dialog.text = "Witam, Senor! Muszę przeprosić, ale mapa jeszcze nie jest gotowa.";
				link.l1 = "Tak, pamiętam, że potrzebowałeś tygodnia. Właśnie przyszedłem zobaczyć, jak ci idzie.";
				link.l1.go = "best_map_wait_01";
			}
		break;
		
		case "best_map_wait_01":
			NextDiag.CurrentNode = "best_map_wait";
			DialogExit();
		break;
		
		case "best_map_09":
			dialog.text = "Och, no dalej, mój przyjacielu. To była przyjemność stworzyć takie mapy dla szlachetnego kapitana, który naprawdę je docenia. Ach tak, możesz odzyskać swoją kopię zwykłej mapy. Powodzenia na otwartym morzu!";
			link.l1 = "Dziękuję bardzo! Masz rację, te mapy są dla mnie bezcenne. Żegnaj, Senor Dios!";
			link.l1.go = "best_map_10";
		break;
		
		case "best_map_10":
			TakeNItems(pchar,"Map_Best", 1);
			TakeNItems(pchar,"map_normal", 1);
			Log_Info("You received an excellent archipelago map!");
			PlaySound("interface\important_item.wav");
			NextDiag.CurrentNode = "Dios";
			DialogExit();
		break;
		
		case "LSC":
			dialog.text = "Naprawdę?! Znalazłeś to? Rozgość się, myślę, że nasza rozmowa trochę potrwa, prawda?";
			link.l1 = "Naprawdę mam ci wiele do opowiedzenia o wyspie. Ale najpierw chcę, abyś mi coś obiecał. Widzę, że jesteś człowiekiem honoru, więc jestem pewien, że dotrzymasz słowa...";
			link.l1.go = "LSC_1";
		break;
		
		case "LSC_1":
			dialog.text = "O czym ty mówisz, kapitanie?";
			link.l1 = "Są tam ludzie... i nie będą zadowoleni, jeśli ktoś wtrąci się w ich życie. Nie sądzę, żeby możliwe przybycie jakiejś 'badawczej' eskadry zostało przyjęte z entuzjazmem.";
			link.l1.go = "LSC_1_1";
		break;
		
		case "LSC_1_1":
			dialog.text = "";
			link.l1 = "Chcę, abyś dał mi swoje słowo honoru, że nie opublikujesz żadnych informacji, które mogą zostać użyte do znalezienia Wyspy przez dziesięć lat po naszej rozmowie. Możesz publikować wszelkie informacje o miejscowych, ich życiu i tak dalej, ale nie ujawniaj lokalizacji wyspy.";
			link.l1.go = "LSC_2";
		break;
		
		case "LSC_2":
			dialog.text = "Zgadzam się, Kapitanie. Daję ci słowo szlachcica, że nikomu nie zdradzę ani położenia wyspy, ani żadnej informacji, która mogłaby zaszkodzić jej mieszkańcom przez następne dziesięć lat.";
			link.l1 = "Słuchaj zatem mej opowieści. Zapisz, jeśli chcesz. Otóż, wyspa składa się z wielu wraków statków, których kadłuby leżą na szerokiej mieliźnie...";
			link.l1.go = "LSC_3";
		break;
		
		case "LSC_3":
			DialogExit();
			SetLaunchFrameFormParam("Two hours later...", "LSC_FinalDiosStory", 0, 5);
			LaunchFrameForm();
			WaitDate("", 0, 0, 0, 2, 10); //крутим время
			RecalculateJumpTable();
		break;
		
		case "LSC_4":
			dialog.text = "Niebywałe! Przekazałeś mi bardzo cenne informacje, Kapitanie! Potomkowie admirała de Betancourt mieszkają na Wyspie! Teraz wiemy, co się stało z jego eskadrą. I jest o jedno białe miejsce mniej na mapie archipelagu Karaibów... Bardzo dziękuję za twoją opowieść, "+pchar.name+"!";
			link.l1 = "Widzisz teraz, dlaczego prosiłem cię, byś był naprawdę ostrożny w przekazywaniu moich informacji?";
			link.l1.go = "LSC_5";
		break;
		
		case "LSC_5":
			dialog.text = "Rozumiem. Możesz być pewien, że dotrzymam słowa. Powiedz mi... czy masz jakieś materialne atrybuty z Wyspy?";
			if (CheckCharacterItem(pchar, "LSC_navigation_map"))
			{
				link.l1 = "Mam wskazówki żeglarskie do Wyspy Porzuconych Statków. Spójrz, proszę. Pozwalają one na przepłynięcie małym statkiem przez rafy i wraki oraz na bezpieczne lądowanie na Wyspie. Bez tych wskazówek dotarcie na Wyspę jest niemożliwe.";
				link.l1.go = "LSC_6";
			}
			else
			{
				link.l1 = "Niestety, nie mam żadnego.";
				link.l1.go = "LSC_7_1";
			}
		break;
		
		case "LSC_6":
			Log_Info("You have given sailing directions");
			PlaySound("interface\important_item.wav");
			dialog.text = "(patrząc) Co za doskonały dokument! Został sporządzony przez człowieka biegłego w kartografii. Nawet ja nie mógłbym tego zrobić lepiej. Niewiarygodne! Kapitanie, dlaczego nie dasz mi tych wskazówek nawigacyjnych? Historia to historia, ale ten papier musi być pokazany najsłynniejszym geografom w Starym Świecie!";
			link.l1 = "Senor Dios, niestety, potrzebuję tego dokumentu dla siebie. Jak już mówiłem, bez niego niemożliwe jest przejście przez rafy otaczające Wyspę. Ale jeśli chcesz, możesz zrobić kopię wskazówek, i będę tylko zadowolony, jeśli również będziesz je posiadał.";
			link.l1.go = "LSC_10";
			//link.l2 = "Senor Dios, niestety, potrzebuję tego przedmiotu dla siebie. Jak już wspomniałem, niemożliwe jest ominięcie raf wokół Wyspy bez niego. Poświęciłbym go w imię nauki, ale... Jestem pewien, że rozumiesz.";
			//link.l2.go = "LSC_7";
		break;
		
		case "LSC_7":
			Log_Info("You received sailing directions");
			PlaySound("interface\important_item.wav");
			dialog.text = "Oczywiście. To twoje prawo, choć to szkoda... W każdym razie, dzięki za twoją opowieść! Wykonałeś wielką przysługę dla geografów, kartografów i innych ciekawskich ludzi.";
			link.l1 = "Proszę bardzo, señor. Cóż, muszę teraz iść. Żegnaj.";
			link.l1.go = "LSC_8";
		break;
		
		case "LSC_7_1":
			dialog.text = "Jaka szkoda... Tak czy inaczej, dzięki za twoją opowieść! Zrobiłeś wielką przysługę geografom, kartografom i innym ciekawskim ludziom.";
			link.l1 = "Witaj, señor. Cóż, muszę już iść. Żegnaj.";
			link.l1.go = "LSC_8";
		break;
		
		case "LSC_8":
			dialog.text = "Z pewnością, "+pchar.name+"   Poświęciłeś mi wiele swojego czasu. Przekaż moje pozdrowienia Señor Svensonowi!";
			link.l1 = "Żegnaj, Señor Dios.";
			link.l1.go = "LSC_9";
		break;
		
		case "LSC_9":
			DialogExit();
			NextDiag.CurrentNode = "Dios";
			AddCharacterExpToSkill(pchar, "Fortune", 400);//везение
			AddCharacterExpToSkill(pchar, "Leadership", 500); // харизма
			ChangeCharacterComplexReputation(pchar, "nobility", 5);// репутация-известность
			ChangeCharacterComplexReputation(pchar, "authority", 2);// репутация-авторитет
			ChangeCharacterComplexReputation(pchar, "fame", 3);
			ChangeCharacterNationReputation(pchar, SPAIN, 5);
			DeleteAttribute(pchar, "questTemp.LSC.Dios");
			LAi_SetOwnerType(npchar);
		break;
		
		case "LSC_10":
			Log_Info("You received sailing directions");
			PlaySound("interface\important_item.wav");
			dialog.text = "Dziękuję bardzo! To bardzo uprzejme z twojej strony. Daj mi trochę czasu...";
			link.l1 = "...";
			link.l1.go = "LSC_11";
		break;
		
		case "LSC_11":
			DialogExit();
			SetLaunchFrameFormParam("Two hours later", "", 0.1, 3.0);
			LaunchFrameForm();
			WaitDate("", 0, 0, 0, 2, 0);
			npchar.dialog.currentnode = "LSC_12";
			LAi_SetActorType(npchar);
			LAi_ActorDialogDelay(npchar, pchar, "", 4.0);
		break;
		
		case "LSC_12":
			//RemoveItems(pchar, "LSC_navigation_map", 1);
			dialog.text = "Dziękuję bardzo! Było to bardzo miłe z twojej strony. Teraz mamy nie tylko ustne dowody, ale i materialne... Nie zostawię cię bez nagrody, Kapitanie. Mam dla ciebie mały upominek.";
			link.l1 = "Jaki to rodzaj prezentu?";
			link.l1.go = "LSC_13";
		break;
		
		case "LSC_13":
			sld = characterFromId("Pirates_shipyarder");
			sld.quest.sextant = "true"; // атрибут Алексу на хронометр
			GiveItem2Character(pchar, "sextant1"); 
			PlaySound("interface\important_item.wav");
			dialog.text = " Interesuję się nie tylko kartografią i geografią, ale także matematyką i astronomią. Rok zajęło mi próbowanie stworzenia uniwersalnego narzędzia do określania szerokości i długości geograficznej. I poczyniłem pewne postępy. Oto, spójrz:\nTo jest mój sekstant. Zaprojektowałem go sam. Problem w tym, że nie działa. Wymaga niezwykle dokładnego chronometru. Nawet te, które zostały wykonane przez najlepszych rzemieślników, dają nieakceptowalne błędy z czasem. Dlatego moje narzędzie jest na razie bezużyteczne.\nAle skoro dużo podróżujesz, może znajdziesz chronometr wystarczająco dokładny, by sekstant działał. Gdy znajdziesz taki zegar - nie będziesz potrzebować już busoli, kompasu, astrolabium, klepsydr i innych kiepskich chronometrów - moje narzędzie zastąpi je wszystkie.";
			link.l1 = "Dziękuję, Señor Dios. Mam nadzieję, że znajdę chronometr, który sprawi, że twoje wynalazek zadziała. Chciałbym mieć takie urządzenie... w działającym stanie. Cóż, muszę teraz iść. Żegnaj.";
			link.l1.go = "LSC_8";
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		//--> блок реагирования на попытку залезть в сундук
		case "Man_FackYou":
			dialog.text = LinkRandPhrase("Jesteś "+GetSexPhrase("Złodziej, widzę! Straże, schwytajcie go","złodziejka, widzę! Strażnicy, chwyćcie ją")+"!!!","Nie mogę w to uwierzyć! Odwróciłem się na chwilę - a ty już grzebiesz w moich rzeczach! Złodziej!!!","Strażnicy! Kradzież! Zatrzymać złodzieja!!!");
			link.l1 = "Aaaah, diabeł!!!";
			link.l1.go = "fight";
		break;
		
		case "fight":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			LAi_SetOwnerTypeNoGroup(npchar);
			LAi_group_Attack(NPChar, Pchar);
			if (rand(3) != 1) SetNationRelation2MainCharacter(sti(npchar.nation), RELATION_ENEMY);
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		//<-- блок реагирования на попытку залезть в сундук
	}
}

bool CheckAMapItems()
{
	return GetCharacterItem(pchar,"chest")      && 
		   GetCharacterItem(pchar,"map_normal") &&
		   GetCharacterFreeItem(pchar,"bussol") &&
		   GetCharacterFreeItem(pchar,"clock2");
}