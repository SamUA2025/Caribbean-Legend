// Натаниэль Хоук - пиратский барон Марун-Тауна
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
			dialog.text = "Chcesz czegoś?";
			link.l1 = "Nie, to nic.";
			link.l1.go = "exit";			
			NextDiag.TempNode = "First time";
		break;
		
		case "diffindoor":
			PlaySound("Voice\English\saga\Nataniel Hawk-02.wav");
			dialog.text = "Ach... kimżeś ty, do diabła?.. Khe... (ciężki kaszel z chrypką) Przeklęta słabość...";
			link.l1 = "Witaj, Nathanielu. Jesteś Nathaniel Hawk, prawda?";
			link.l1.go = "diffindoor_1";
		break;
		
		case "diffindoor_1":
			dialog.text = "Tak, to ja, jeśli wciąż mogę się tak nazywać. Kiedyś byłem Nathaniel Hawk, ale teraz jestem tylko smutnym workiem gówna. Pieprzyć ten posąg! Wyssał ze mnie całe życie.";
			link.l1 = "Znam to uczucie...";
			link.l1.go = "diffindoor_2";
		break;
		
		case "diffindoor_2":
			dialog.text = "Jakże mógłbyś, chłopcze, skoro nawet nie rozumiesz, o czym mówię? A-kha... Czy wiesz, jak to jest nagle stać się pół-martwym, starym człowiekiem, kiedy jeszcze chwilę temu byłem zdrowy i silny?\nWidziałem wiele rzeczy, myślałem, że ten stary indiański świątynia, którą odwiedziłem w młodości, zabiłaby moją zdolność do zdziwienia się, ale to... dlaczego tego nie przewidziałem! Ta przeklęta statua wyglądała tak samo jak stary idol, który otworzył drzwi do świątyni!";
			link.l1 = "Zgoda, Nathan, porozmawiajmy. Pozwól, że się przedstawię, jestem "+GetFullName(pchar)+"Po pierwsze, doskonale cię rozumiem, bo przybyłem tu w ten sam sposób, co ty - używając portalu Kukulkana.";
			link.l1.go = "diffindoor_3";
		break;
		
		case "diffindoor_3":
			dialog.text = "Naprawdę?! To czemu wyglądasz całkiem nieźle? Czyżby ten... Kukulcan skrzywdził tylko mnie?";
			link.l1 = "Wężowe Oko, szaman Miskito, który pomógł ci uciec, dał mi bardzo mocny eliksir. Wypiłem go, jak tylko obudziłem się w San Augustine. Całkowicie mnie wyleczył. Jestem pewien, że Wężowe Oko może ci też pomóc. Musimy cię tylko do niego zabrać.";
			link.l1.go = "diffindoor_4";
		break;
		
		case "diffindoor_4":
			dialog.text = "Ach, ten Indianin! Mikstura? A dlaczego mnie też jej nie dał?";
			link.l1 = "Powiedział, że nie było czasu. Byliście ścigani i jedyną rzeczą, jaką mógł zrobić, było pokazanie wam drogi ucieczki - portal.";
			link.l1.go = "diffindoor_5";
		break;
		
		case "diffindoor_5":
			PlaySound("Voice\English\saga\Nataniel Hawk-01.wav");
			dialog.text = "Ucieczka? Och... Nie widzisz mojego obecnego stanu? Nie mogę nawet utrzymać szabli. Jak można to nazwać ucieczką? Dzięki Bogu, że na tym świecie są jeszcze dobrzy ludzie. Ole, niech go Bóg błogosławi... Znasz Ole?";
			link.l1 = "Tak. Właściwie to on mi o tobie opowiedział, mówił, jak cię karmił szczurami i jak ciągle pijesz, butelka za butelką...";
			link.l1.go = "diffindoor_6";
		break;
		
		case "diffindoor_6":
			dialog.text = "Zgasnę szybciej niż zapalona świeca, jeśli nie napiję się rumu. To jedyna rzecz, która mnie przy życiu trzyma. Rum...";
			link.l1 = "Czy nadal czujesz się tak źle? Tak samo jak po teleportacji?";
			link.l1.go = "diffindoor_7";
		break;
		
		case "diffindoor_7":
			dialog.text = "Cóż, nie czuję się tak samo... Ale też nie naprawdę lepiej. Przyjacielu, powiedz mi, czemu musiałeś zobaczyć starego Nathana? Dlaczego, do diabła, przyszedłeś tutaj, na ten stary, zgniły statek? Żeby pogadać ze mną?";
			link.l1 = "Właściwie, tak. Nie uwierzysz mi, ale powodem, dla którego przeszedłem przez te wszystkie kłopoty z teleportacją, było znalezienie ciebie. Pracuję dla Braci Wybrzeża i reprezentuję Jana Svensona.";
			link.l1.go = "diffindoor_8";
		break;
		
		case "diffindoor_8":
			dialog.text = "Cholera... Leśny Diabeł? Argh... Przyszedłeś tu, żeby mnie dobić? A właściwie, nie? Jesteś zbyt rozmowny jak na zabójcę. Proszę - nie torturuj mnie. Jeśli ci kazano coś ze mnie wydobyć - powiem ci wszystko sam, nie mam nic do ukrycia.";
			link.l1 = "Co masz na myśli? A-ah, rozumiem. Ty, podobnie jak Danielle, myślisz, że to Svenson zorganizował tę zasadzkę na twoje życie w dżungli. Mogę cię zapewnić, że Jan tego nie zrobił. Wręcz przeciwnie, jest po twojej stronie i bardzo się martwi o twoje zniknięcie.";
			link.l1.go = "diffindoor_9";
		break;
		
		case "diffindoor_9":
			dialog.text = "Naprawdę? Do diabła, cieszę się to słyszeć. I już myślałem... ale kto to zrobił? Moja drużyna została zniszczona w kilka minut. Czekali na nas. Mieli nawet działa okrętowe! Zmietli połowę moich ludzi kartaczem, a potem wykończyli nas swoimi muszkietami...";
			link.l1 = "By być szczerym, nie znam szczegółów, ale jestem pewien, że za tym wszystkim stoi Jackman. Zbyt wiele zbiegów okoliczności, najpierw Blaze, potem ty... Jackman chce przejąć władzę i eliminuje każdego, kto stoi mu na drodze. Teraz rządzi Maroon Town zamiast ciebie.";
			link.l1.go = "diffindoor_10";
		break;
		
		case "diffindoor_10":
			dialog.text = "Jackman? Drań! Eh... Bractwo podzieliło się w ostatnich kilku latach, wcześniej wszystko było inaczej. Zachariasz zwariował na punkcie religii, Tyrex ma wszystko w nosie, a Barbazon interesują tylko dublony. Dwadzieścia lat temu było zupełnie inaczej...";
			link.l1 = "Jak cię pojmali? Opowiedz mi więcej.";
			link.l1.go = "diffindoor_11";
		break;
		
		case "diffindoor_11":
			dialog.text = "Nie ma nic ciekawego do opowiedzenia! Jak mówiłem, ci bandyci zaplanowali całą rzecz. Działali schludnie, byli skoordynowani i wyraźnie wykonywali czyjeś polecenia. Mogli mnie zabić sto razy, ale tego nie zrobili. Chcieli mnie żywego. Zabrali mnie do opuszczonej kopalni i zamknęli w jednej z chat. 'Aż przyjdzie szef', mówili. Myślałem, że to Svenson jest szefem, ale wydaje się, że Jackman rządzi. Nie wiem, czego mógłby ode mnie chcieć, ale jestem pewien, że nie przeżyłbym długo po rozmowie z nim.";
			link.l1 = "Nie mam co do tego wątpliwości. Svenson jest pewien, że Jackman zabił Blaze'a Sharpa... Jak udało ci się uciec?";
			link.l1.go = "diffindoor_12";
		break;
		
		case "diffindoor_12":
			dialog.text = "Ten indiański Wężowe Oko jakoś zdołał zakraść się do kopalni. Z tego co rozumiem, Miskito nie lubią bandytów. W każdym razie, Wężowe Oko zorganizował moją ucieczkę z jakiegoś powodu. Wykopał do mnie tunel, dostał się do środka, przeciął moje więzy i uciekliśmy do dżungli.\nChciał mnie zabrać do swojej wioski, do Miskito. Ale wygląda na to, że Jackman bardzo mnie chciał, bo zorganizowano wielkie polowanie. Byli tuż za naszymi piętami. Wężowe Oko starał się ich zmylić, ale zawsze udawało im się znaleźć nasz ślad. Mieli dobrych tropicieli, bez wątpienia.\nByliśmy blisko wioski Wężowego Oka, gdy w końcu nas znaleźli. W tym momencie mój żołądek był pusty od dwóch dni i byłem całkowicie wyczerpany, bo także mocno uszkodziłem nogę. Była północ i wciąż pamiętam, jak jasna była gwiazda nad posągiem... Wężowe Oko powiedział, że moją jedyną szansą było dotarcie do idola i dotknięcie go.\nMyślałem, że człowiek oszalał, ale wiesz, co mówią o chwytaniu się brzytwy. Kuśtykałem do posągu, dotknąłem go... i wtedy zaczęły się dziać szalone rzeczy!";
			link.l1 = "Nie musisz kontynuować, wiem, co się stało potem.";
			link.l1.go = "diffindoor_13";
		break;
		
		case "diffindoor_13":
			dialog.text = "Znalazłem się wewnątrz mokrego ładowni jakiegoś rozbitego statku. Byłem na wpół martwy. Nie mogłem chodzić, tylko czołgać się. Z każdą minutą mój stan się pogarszał. Ole pojawił się w samą porę. Wlał we mnie jakąś karaibską miksturę, która smakowała jak gówno, mieszankę antidotum i esencji leczniczej. Potem dał mi rum.\nOd razu mi się poprawiło. Potem znalazł i użył starego kłody, by mnie tu przenieść. Mieszkam tu już od jakiegoś czasu, nie wiem dokładnie jak długo, straciłem poczucie czasu.";
			link.l1 = " Wszystko będzie dobrze, Nathan. Ja i Svenson mamy wielkie plany, a twoja rola w nich jest bardzo znacząca. Musisz wrócić na swoje stanowisko w Maroon Town, a my zajmiemy się tym łajdakiem Jackmanem.";
			link.l1.go = "diffindoor_14";
		break;
		
		case "diffindoor_14":
			dialog.text = "Maroon Town? I jak wyobrażasz sobie, że to zadziała? Spójrz na mnie, jestem wrakiem nasiąkniętym rumem! Bezwartościowy... Nie, lata mojej władzy nad Maroon Town przeminęły na zawsze. Utknąłem na tym przeklętym cmentarzysku statków. Jak długo przetrwam? Miesiąc, dwa, rok?\nA potem skończę leżąc na tych zgniłych deskach i Ole wrzuci to, co zostało z Nathaniela Hawka, do morza. Najgorsze jest to, że nie zobaczę już mojej Dannie. Eh, to koniec, przyjacielu.";
			link.l1 = "Nie bądź tak pesymistyczny. Wyciągnę cię stąd.";
			link.l1.go = "diffindoor_15";
		break;
		
		case "diffindoor_15":
			dialog.text = "Jak mnie stąd wyciągniesz? I jak opuścimy to miejsce? Nie ma żadnych statków. Chcesz zbudować tratwę?";
			link.l1 = "Nie. Opuścić to miejsce tak, jak tu przybyłem. Wiem, gdzie jest posąg... no, mniej więcej. Znajdę go, a potem wrócę po ciebie i Shark Dodsona. Zabierzemy cię do Wężowego Oka później. On cię wyleczy.";
			link.l1.go = "diffindoor_16";
		break;
		
		case "diffindoor_16":
			dialog.text = "Co powiedziałeś? Rekin Dodson? Czy Steve też tu jest? Co za dziwne miejsce...";
			link.l1 = "Tak, jest tutaj. Jest 'gubernatorem' tej wyspy, że tak powiem. Pytałem go o ciebie, ale nic nie wie.";
			link.l1.go = "diffindoor_17";
		break;
		
		case "diffindoor_17":
			dialog.text = "I nie powinien. Nie chcę, żeby widział mnie w takim stanie. Mówiłeś, że szaman mnie wyleczy... Ledwo mogę w to uwierzyć. Wspomniałeś też o Dannie... Widziałeś ją?";
			link.l1 = "Tak. Ona sama mnie odnalazła w Blueweld. Podsłuchała moją rozmowę ze Svensonem i zrozumiała, że Jan nie miał zamiaru cię zabić i że działa przeciwko Jackmanowi. Dołączyła do mojego statku jako oficer, aby pomóc mi cię znaleźć.";
			link.l1.go = "diffindoor_18";
		break;
		
		case "diffindoor_18":
			dialog.text = "Eh, moja droga Dannie! Ona się nie zmieniła... tak samo lekkomyślna jak w młodości... Nawet sobie nie wyobrażasz, jak bardzo chcę ją teraz zobaczyć i przytulić! Dużo rozmyślałem, leżąc tutaj. Widzisz, przyjacielu, zaczynasz dostrzegać rzeczy w innym świetle, kiedy jesteś blisko śmierci. Tak mało czasu spędziłem z moją żoną!\nMorskie napady, oficjalne sprawy Bractwa, rządzenie Maroon Town. A ona zawsze mnie we wszystkim wspierała: pozostawała sama przez tygodnie, kłóciła się z innymi piratami, gdy byłem nieobecny, dowodziła naszym statkiem... Moja Dannie to najlepsza kobieta na świecie! A ja... Powinienem był częściej jej mówić, że ją kocham!\nPamiętam dzień, kiedy postanowiliśmy być razem! Właściwie to był dzień, kiedy po raz pierwszy spotkałem się i walczyłem z nadprzyrodzonymi rzeczami. Wszystko wydarzyło się z powodu tego przeklętego idola, który wyglądał jak posągi. Nie masz nic przeciwko, żeby posłuchać historii? Jest dość interesująca.";
			link.l1 = "Ani trochę! Powiedz mi!";
			link.l1.go = "story";
			link.l2 = "Nathan, nie mamy czasu na przyjemne wspomnienia. Opowiedz mi o tym później, gdy będziemy siedzieć w wiosce Miskito z butelką wina.";
			link.l2.go = "diffindoor_19";
		break;
		
		case "story":
			dialog.text = "To było dwadzieścia pięć lat temu... Byłem młody, żarliwy i niespokojny. Karaiby były moim placem zabaw. Znałem już wtedy Dannie. Lubiłem ją, naprawdę lubiłem, a uczucie było wzajemne. Ale często się kłóciliśmy, sprzeczaliśmy i dokuczaliśmy sobie nawzajem. Głupia młodość... Wierzę, że byliśmy wtedy wielką rozrywką dla szanowanych marynarzy!\nTak czy inaczej, jakoś tak się stało, że Dannie i ja wplątaliśmy się w tę samą historię. Znaleźliśmy mapę Khael Roa i powiedziano nam, że to było TO miejsce, gdzie można znaleźć indiańskie złoto. Znaleźliśmy też dziwnie wyglądający złoty idol, mniejszą kopię górnej części posągów.\nIdol był niebezpieczny, wysysał witalność z tych, którzy go nosili. Ale potrzebowaliśmy tego przeklętego przedmiotu, aby dostać się do skarbca wewnątrz świątyni. Jedynym problemem było to, że nie mieliśmy pojęcia, jak go prawidłowo używać. Dannie i ja popłynęliśmy na wyspę. Była tam starożytna świątynia, pokryta trawą i drzewami. Gdy weszliśmy, znaleźliśmy się w ogromnym labiryncie.\nUdało nam się znaleźć właściwą drogę i dotrzeć do centralnej części labiryntu. Myśleliśmy, że to ślepy zaułek, ale kiedy desperacja zaczęła nas pokonywać, zobaczyliśmy dziwną platformę z małym gniazdem i obrazkiem w nim. Włożyłem idola do gniazda i...";
			link.l1 = "...dość długo już cię szukałem.";
			link.l1.go = "exit";
			pchar.questTemp.LSC.Natanstory = "idol";
			AddDialogExitQuest("Video_story");
			NextDiag.TempNode = "story_1";
		break;
		
		case "story_1":
			dialog.text = "Kamienna platforma opadła o kilka cali i jedna ze ścian okazała się być tajnym przejściem. Posąg został wewnątrz platformy, nie udało mi się go wyciągnąć. W końcu dotarliśmy do olbrzymiej sali. Co za piękny widok!\nNajwspanialsza konstrukcja, jaką kiedykolwiek widziałem. Rzeźby na ścianach, ogromne posągi... Przeszukaliśmy całą salę, ale nie znaleźliśmy żadnych skarbów.";
			link.l1 = "Heh, to się zdarza dość często ludziom takim jak my. Dużo wysiłku, a na końcu żadnego rezultatu...";
			link.l1.go = "story_2";
		break;
		
		case "story_2":
			dialog.text = "To nie było na darmo. W końcu weszliśmy do sali tronowej z gigantycznym posągiem ptaka na jej końcu. Obok posągu było mistyczne światło, wyglądało dokładnie jak światło nad idolem o północy. Podeszliśmy bliżej i zobaczyliśmy piękną latającą kulę. Przysięgam, mówię ci czystą prawdę!\nTo było prawdziwe, ale jednocześnie czułem, jakby nie było. Kiedy myślałem, Dannie - och, ten lekkomyślny diabeł, dotknął kuli. Zaczęła świecić jeszcze jaśniej i ostatecznie zamieniła się w mały przedmiot w jej rękach...";
			link.l1 = "...";
			link.l1.go = "exit";
			pchar.questTemp.LSC.Natanstory = "temple";
			AddDialogExitQuest("Video_story");
			NextDiag.TempNode = "story_3";
		break;
		
		case "story_3":
			dialog.text = "Wydawało się, że popełniliśmy świętokradztwo. Świątynia ożyła: wszystko wokół nas zaczęło się ruszać, ściany się trzęsły i wszystko się rozpadało. To było jakbyśmy obudzili wszystkie indiańskie demony, a one rzucały na nas całą swoją wściekłość...";
			link.l1 = "Wow!";
			link.l1.go = "story_4";
		break;
		
		case "story_4":
			dialog.text = "Trudno w to uwierzyć, wiem. Ale...";
			link.l1 = "Pół roku temu nazwałbym cię kłamcą. Ale żyję na Karaibach już wystarczająco długo, by wiedzieć, że nie mam powodów, by ci nie ufać. Mów dalej. Jak przeżyłeś?";
			link.l1.go = "story_5";
		break;
		
		case "story_5":
			dialog.text = "Wybiegliśmy z świątyni i mieliśmy szczęście, że zdążyliśmy na nasz statek na czas. Rozkazałem podnieść kotwicę, chcieliśmy jak najszybciej odpłynąć z tego miejsca.";
			link.l1 = "Heh! Więc w końcu znalazłeś tylko jakiś dziwny artefakt zamiast skarbów? Co za miła i równoważna zamiana, he-he... A dowiedziałeś się, jak go używać? Czy był bezużyteczny?";
			link.l1.go = "story_6";
		break;
		
		case "story_6":
			dialog.text = "Poczekaj chwilę. Historia się jeszcze nie skończyła. Dannie miał artefakt, i gdy tylko zdecydowaliśmy się udać do kajuty, by go zbadać, niebo pociemniało, a na horyzoncie pojawił się statek. O Boże! To był...";
			link.l1 = "...";
			link.l1.go = "exit";
			pchar.questTemp.LSC.Natanstory = "blackpearl";
			AddDialogExitQuest("Video_story");
			NextDiag.TempNode = "story_7";
		break;
		
		// вот тут делаем развилку, в зависимости прошёл ли игрок Калеуче
		case "story_7":
			dialog.text = "... Sam Van der Decken!!";
			if (CheckAttribute(pchar, "questTemp.KhaelRoa"))
			{
				link.l1 = "Van der Decken? Hm...";
				link.l1.go = "story_8_1";
			}
			else
			{
				link.l1 = "I kto to jest?";
				link.l1.go = "story_8";
			}
		break;
		
		case "story_8":
			dialog.text = "Nie słyszałeś nigdy o Latającym Holendrze?";
			link.l1 = "Kto nie słyszał o Latającym Holendrze! Już spotkałem jednego Holendra i posłałem jego kapitana na dno morza. Był to zwykły pirat, który ozdobił swój statek jakimiś maskaradnymi śmieciami, jak wodorosty i podarte żagle.";
			link.l1.go = "story_9";
		break;
		
		case "story_8_1":
			dialog.text = "Tak, ale to był sam Van der Decken, kapitan Latającego Holendra!";
			link.l1 = "Interesujące. Proszę, kontynuuj. Jak udało ci się przetrwać?";
			link.l1.go = "story_11";
		break;
		
		case "story_9":
			dialog.text = "Eh-heh, przyjacielu... Zatopiłeś jakiegoś błazna, ale ja mówię o prawdziwym Latającym Holendrze. Ogromnym okręcie wojennym. Niech Bóg cię strzeże przed spotkaniem go na otwartym morzu. Jego kapitan Van der Decken i jego załoga zostali kiedyś przeklęci, by wiecznie żeglować po morzach bez wytchnienia.\nPamiętam jego podarte czarne żagle, załogę umarłych ludzi stojących na pokładzie z wyciągniętymi ostrzami i samego kapitana - przerażającego szkieleta w czarnym trójrożnym kapeluszu... Jezus...";
			link.l1 = "Czy mówisz prawdę?";
			link.l1.go = "story_10";
		break;
		
		case "story_10":
			dialog.text = "Przysięgam na Biblię, że nie kłamię... Spotkanie z 'Latającym Holendrem' oznacza tylko pewną śmierć. Jest potężna, bardzo potężna, jeden salwa z jej dział może zatopić nawet ciężką fregatę wraz z załogą... ale co gorsza, jak masz walczyć z nieumarłymi?";
			link.l1 = "Ale przetrwałeś ten koszmar!";
			link.l1.go = "story_11";
		break;
		
		case "story_11":
			dialog.text = "To wszystko dzięki mojej ukochanej Dannie i indiańskiemu artefaktowi, który zabraliśmy ze świątyni. Rozkazałem przygotować się do walki, ale wiedziałem, że to koniec drogi. 'Latający Holender' płynął w naszym kierunku, a ja widziałem jej przerażającą załogę i samego Van der Deckena na pokładzie. Statek zaczął celować w nas swoimi armatami, ale...";
			link.l1 = "...";
			link.l1.go = "exit";
			pchar.questTemp.LSC.Natanstory = "artefact";
			AddDialogExitQuest("Video_story");
			NextDiag.TempNode = "story_12";
		break;
		
		case "story_12":
			dialog.text = "Dannie uniosła artefakt i pozwoliła mu polecieć. Nie miałem pojęcia, dlaczego to zrobiła. Mówiła coś o swojej kobiecej intuicji... Artefakt zamienił się z powrotem w świecącą kulę i eksplodował, krytycznie uszkadzając statek widmo i demoralizując jego załogę. Rozkazałem otworzyć ogień do Holendra.\nPierwsza salwa sprawiła, że zadrżeli. Zaatakowaliśmy ponownie i ostrzelaliśmy ich zgniły kadłub po raz drugi, tuż zanim zdążyli się otrząsnąć z wpływu artefaktu i zaczęli odpowiadać ogniem...";
			link.l1 = "Więc musiałeś z nimi walczyć tak czy inaczej?";
			link.l1.go = "story_13";
		break;
		
		case "story_13":
			dialog.text = "Rzeczywiście. I przysięgam, że to była najcięższa walka w moim życiu. Ich przeklęta łajba ledwo trzymała się na wodzie, a mimo to zdołali zniszczyć połowę mojego kadłuba, zanim wysadziliśmy ich w powietrze, wysadzając ich przeklęty magazyn prochu.";
			link.l1 = "Zatopiłeś go? Zatopiłeś Latającego Holendra?";
			link.l1.go = "story_14";
		break;
		
		case "story_14":
			dialog.text = "Tak, do diabła! Zrobiłem to!..";
			link.l1 = "...";
			link.l1.go = "exit";
			pchar.questTemp.LSC.Natanstory = "ending";
			AddDialogExitQuest("Video_story");
			NextDiag.TempNode = "story_15";
		break;
		
		case "story_15":
			dialog.text = "Ten przeklęty statek poszedł na dno. Słońce znów zaczęło świecić, a niebo się przejaśniło. I wreszcie zaczęliśmy odczuwać szczęście... och, nawet sobie nie wyobrażasz, jak bardzo byliśmy szczęśliwi. Pokonaliśmy samą śmierć. Chwile takie jak ta zbliżają ludzi do siebie. I zrobiliśmy to, co powinniśmy byli zrobić już dawno przed tym spotkaniem - objęliśmy się, pocałowaliśmy, powiedzieliśmy, że się kochamy i przysięgliśmy być razem na zawsze.";
			link.l1 = "I nadal jesteście razem...";
			link.l1.go = "story_16";
		break;
		
		case "story_16":
			dialog.text = "Tak, jesteśmy. Ja i Dannie pobraliśmy się i nigdy tego nie żałowałem. Nie znajdziesz lepszej żony i towarzyszki broni.";
			if (CheckAttribute(pchar, "questTemp.KhaelRoa"))
			{
				link.l1 = "Więc teraz w końcu wiem, kim naprawdę jest ten tajemniczy kapitan, któremu udało się zatopić 'Latającego Holendra'... Jesteś prawdziwym bohaterem!";
				link.l1.go = "story_17_1";
			}
			else
			{
				link.l1 = "Więc, wy dwoje jesteście prawdziwymi bohaterami? Udało wam się zatopić słynny statek widmo. Czekaj! Powiedziałeś, że 'Latający Holender' wciąż lata... Jak to możliwe, skoro leży na dnie morza?";
				link.l1.go = "story_17";
			}
		break;
		
		case "story_17":
			dialog.text = "Eh, kumplu, nic nie wiesz... Możesz zatopić Van der Deckena, ale go nie zabijesz. Klątwa, która ciąży na nim i jego załodze, jest zbyt silna, o wiele silniejsza niż śmierć...";
			link.l1 = "...";
			link.l1.go = "exit";
			pchar.questTemp.LSC.Natanstory = "VDDrepair";
			AddDialogExitQuest("Video_story");
			NextDiag.TempNode = "story_18";
		break;
		
		case "story_17_1":
			dialog.text = "Bohaterem mogę być, ale Van der Decken nie może być zabity. Klątwa wisząca nad nim, jego załogą i jego okrętem jest silniejsza niż śmierć...";
			link.l1 = "... ";
			link.l1.go = "exit";
			pchar.questTemp.LSC.Natanstory = "VDDrepair";
			AddDialogExitQuest("Video_story");
			NextDiag.TempNode = "story_18";
		break;
		
		case "story_18":
			dialog.text = "Za każdym razem, gdy zatapiasz statek, jego załoga naprawia go, podnosi i kontynuuje swoją wieczną podróż.";
			if (CheckAttribute(pchar, "questTemp.KhaelRoa"))
			{
				link.l1 = "Wiem, Nathanielu, wiem. Niemniej jednak, Latający Holender nie będzie już nikogo niepokoić.";
				link.l1.go = "story_22";
			}
			else
			{
				link.l1 = "Cóż, wiesz, to brzmi jak bajka. Naprawić rozdzielony i zatopiony statek...";
				link.l1.go = "story_19";
			}
		break;
		
		case "story_19":
			dialog.text = "Ludzie widzieli okręt wiele razy po tym, jak go zatopiliśmy... Ty decydujesz, czy wierzyć tym doniesieniom.";
			link.l1 = "„A gdzie znajduje się ta wyspa ze świątynią, z której zdobyłeś artefakt?”";
			link.l1.go = "story_20";
		break;
		
		case "story_20":
			dialog.text = "To nieznaczone miejsce, położone gdzieś na wschodzie Morza Karaibskiego. Zostawiłem mapę wyspy w Maroon Town, ale jak dobrze wiesz, nie mogę tam teraz popłynąć. I szczerze mówiąc, nie chcę. Jedyne, co pamiętam, to jej nazwa - Khael Roa...";
			link.l1 = "Taka interesująca historia. Chciałbym odnaleźć tę wyspę!";
			link.l1.go = "story_21";
		break;
		
		case "story_21":
			dialog.text = "Och, nie polecam tego... Na pewno nie zamierzam odwiedzać tego miejsca ponownie.";
			link.l1 = "Chciałbym go odwiedzić mimo to... Dobrze, dziękuję za twoją interesującą opowieść! Teraz wiem więcej o twojej żonie. Oboje jesteście żywymi legendami!";
			link.l1.go = "diffindoor_19";
			DeleteAttribute(pchar, "questTemp.LSC.Natanstory");
			pchar.questTemp.NatanStory = "true";
		break;
		
		case "story_22":
			dialog.text = "Cóż insynuujesz, kumplu? Czyż nie mówiłem ci przed chwilą, że nie można go zabić?";
			link.l1 = "Nathaniel, popłynąłem do Khael Roa. Odwiedziłem świątynię Chavinów, gdzie ty, Danielle i jakiś stary człowiek byliście ćwierć wieku temu. Artefakt, który wtedy zabraliście ze świątyni, nazywał się 'kula wschodzącego słońca'. To właśnie ten artefakt przyciągnął uwagę 'Latającego Holendra' do was. Jego kapitan był zafascynowany artefaktami Chavinów.";
			link.l1.go = "story_23";
		break;
		
		case "story_23":
			dialog.text = "Byłeś na Khael Roa? Ale to po prostu niemożliwe! Mówisz prawdę?";
			link.l1 = "Przysięgam. Kiedy opowiedziałeś mi o labiryncie i posągu olbrzymiego ptaka, od razu zrozumiałem, gdzie to miejsce jest. Karaibski szaman Tuttuathapak opowiedział mi o twoich przygodach. To on skierował mnie na tę wyspę. Jest położona na wschód od St. Christophera. Jest bardzo mała, w kształcie pierścienia. Otaczają ją skały i w środku jest mała zatoka. I jest tylko jedna zarośnięta ścieżka prowadząca do świątyni, która jest zbudowana w formie piramidy.";
			link.l1.go = "story_24";
		break;
		
		case "story_24":
			dialog.text = "Tak! To jest Khael Roa. Ale dlaczego tam pojechałeś?";
			link.l1 = "By zdjąć klątwę z Caleuche... cóż, z 'Latającego Holendra'. Właściwie, jej nazwa brzmiała 'Latające Serce', a imię jej kapitana to 'Balthazar de Cordes'. Pięćdziesiąt lat temu został przeklęty przez Yum Cimil, indiańskiego boga śmierci. Wziąłem jadeitową czaszkę Yum Cimil, którą Balthazar ukradł z świątyni jakiś czas temu, i umieściłem ją z powrotem na piedestale przed tą statuą kondora...";
			link.l1.go = "story_25";
		break;
		
		case "story_25":
			dialog.text = " ";
			link.l1 = "...zwracając czaszkę, usunąłem klątwę z Caleuche. A ponieważ miałem przy sobie dwa inne amulety Chavinów, zaatakowała mnie blisko wyspy, dokładnie tak jak to się stało z tobą wtedy. Ale bez klątwy Balthazar nie był już nieśmiertelny, tak jak powiedział Tuttuathapak. Więc... 'Latający Holender' już nie istnieje. Osobiście się nią zająłem.";
			link.l1.go = "story_26";
		break;
		
		case "story_26":
			dialog.text = "Pioruny i błyskawice! Jestem zdumiony! Ty... Nie żartujesz sobie ze starego Nathana, prawda? Nie, widzę w twoich oczach, że mówisz prawdę! Jesteś prawdziwym bohaterem!";
			link.l1 = "Bohater czy nie, ale ja też przeżyłem sporo przygód, podobnie jak ty. Cóż, z pewnością jeszcze nie raz porozmawiamy o przeszłości, bo teraz mamy wspólny temat.";
			link.l1.go = "diffindoor_19";
			DeleteAttribute(pchar, "questTemp.LSC.Natanstory");
		break;
		
		case "diffindoor_19":
			dialog.text = "Czy zamierzasz mnie teraz opuścić, przyjacielu?";
			link.l1 = "Tak, Nathan. Proszę, trzymaj się do mojego powrotu. Dbaj o siebie. I co najważniejsze, pozostań przy życiu, aż wrócę, a wszystko będzie w porządku. Bractwo Wybrzeża cię potrzebuje, Danielle cię potrzebuje.";
			link.l1.go = "diffindoor_20";
		break;
		
		case "diffindoor_20":
			dialog.text = "Czy Dannie jest teraz w twojej załodze? Błagam cię, czuwaj nad nią. Nie zmieniła się ani trochę od młodości, wciąż jest śmiałkiem i nie zawaha się przejść przez piekło. Powiedz jej, że bardzo ją kocham...";
			link.l1 = "Na pewno to zrobię. Wrócimy razem po ciebie, obiecuję ci to, Nathan. Trzymaj się, i głowa do góry. Ole się tobą zaopiekuje. Do zobaczenia wkrótce!";
			link.l1.go = "diffindoor_21";
		break;
		
		case "diffindoor_21":
			DialogExit();
			LAi_SetGroundSitTypeNoGroup(npchar);
			NextDiag.CurrentNode = "diffindoor_wait";
			pchar.questTemp.LSC.NatanTalk = "true"; // атрибут - разговор с Натаном состоялся
			AddQuestRecord("BaronReturn", "10");
			npchar.greeting = "nathaniel_1";
		break;
		
		case "diffindoor_wait":
			dialog.text = "Ach, to ty, "+pchar.name+". Jeszcze nie opuściłeś wyspy?";
			link.l1 = "Nie martw się, Nathan, wszystko idzie zgodnie z planem. Odpocznij teraz.";
			link.l1.go = "exit";
			NextDiag.TempNode = "diffindoor_wait";
		break;
		
		case "danny":
			PlaySound("Voice\English\saga\Nataniel Hawk-03.wav");
			dialog.text = "Danielle!.. Dannie! Moja Dannie!..";
			link.l1 = "... ";
			link.l1.go = "danny_1";
		break;
		
		case "danny_1": // перекидываем pchar
			DialogExit();
			LAi_SetActorType(pchar);
			SetMainCharacterIndex(GetCharacterIndex("Nathaniel"));
			PChar = GetMainCharacter();			
			LAi_SetPlayerType(PChar);
			sld = characterFromId("Danielle");
			sld.dialog.currentnode = "nathaniel_6";
			LAi_SetActorType(sld);
			LAi_ActorDialog(sld, pchar, "", -1, 0);
			NextDiag.CurrentNode = "danny_2";
		break;
		
		case "danny_2":
			dialog.text = "Dziękuję, mój przyjacielu. Dziękuję za wszystko, a zwłaszcza za moją Dannie...";
			link.l1 = "Jesteś mile widziany, Nathan.";
			link.l1.go = "exit";
			NextDiag.TempNode = "danny_2";
		break;
		
		// в Марун-Тауне
		case "marun_town":
			dialog.text = "Patrzcie, kto tu właśnie wpadł! Toż to "+GetFullName(pchar)+"  sam sobie! Wejdź, wejdź, przyjacielu! Jak się masz?";
			link.l1 = "U mnie wszystko w porządku. A u ciebie, Nathan? Widzę, że zniknęła ponura mina. Wyglądasz dobrze. Wężowe Oko naprawdę się spisał!";
			link.l1.go = "marun_town_1";
		break;
		
		case "marun_town_1":
			ChangeCharacterComplexReputation(pchar, "fame", 3);
			dialog.text = "Tak, wasz szaman to cudotwórca. Czuję się nawet lepiej niż przed tym przeklętym teleportem! Czuję się, jakbym miał dziesięć lat mniej!"+pchar.name+", jestem ci ogromnie wdzięczny. I jestem pod wrażeniem: pomogłeś kompletnemu nieznajomemu, przechodząc przez przeklęty portal, wyrywając mnie z rąk śmierci, przywracając do mojej żony!\nI jeszcze więcej! Przywróciłeś nam nasz statek i dom. Teraz jesteś naszym najlepszym przyjacielem. Na zawsze. Jeśli kiedykolwiek będziesz czegoś potrzebował - wiesz, do kogo się zwrócić! Maroon Town zawsze zapewni ci ochronę, wsparcie i schronienie, jeśli tego potrzebujesz.\nCała wioska będzie za tobą walczyć, jeśli będziesz w niebezpieczeństwie. W czasach pokoju znajdziesz tu przyjaźń, najlepszy rum, miękkie łóżko i doskonałe miejsce na odpoczynek. Dannie i ja zadbamy o to.";
			link.l1 = "Dziękuję, baronie! Szczerze się cieszę, widząc cię w dobrym zdrowiu i... z Dannie.";
			link.l1.go = "marun_town_2";
		break;
		
		case "marun_town_2":
			dialog.text = "Spodziewałem się twojej wizyty, "+pchar.name+", a ja przygotowałem prezent - rzadką i potężną broń. Być może pewnego dnia będziesz musiał zlikwidować wielu wrogów jednym strzałem, a ta ręczna moździerz ci w tym pomoże. 'Sclopetta' wystrzeliwuje specjalne granaty, więc przygotowałem również instrukcje, jak je robić. Proszę, weź to.";
			link.l1 = "Co za wspaniała broń! Dzięki!";
			link.l1.go = "marun_town_3";
		break;
		
		case "marun_town_3":
			GiveItem2Character(pchar, "grape_mushket"); 
			GiveItem2Character(pchar, "recipe_grenade"); 
			Log_Info("You have received a hand mortar");
			Log_Info("You have received a grenade instruction");
			PlaySound("interface\important_item.wav");
			dialog.text = "Przybywaj do nas częściej, "+pchar.name+"! Dannie i ja zawsze będziemy się cieszyć z twojej wizyty o każdej porze.";
			link.l1 = "Będzie to dla mnie przyjemność. Spodziewaj się mnie wkrótce!";
			link.l1.go = "exit";
			NextDiag.TempNode = "marun_town_4";
		break;
		
		case "marun_town_4":
			dialog.text = "Ach, mój przyjacielu "+GetFullName(pchar)+" ! Wejdź, wejdź, Kapitanie! Jak się masz? Potrzebujesz pomocy?";
			// калеуче
			if (CheckAttribute(pchar, "questTemp.Caleuche.NatanInfo"))
			{
				link.l2 = "Natan, przyszedłem do ciebie w bardzo ważnej sprawie. Pamiętasz, kiedy powiedziałeś mi na Wyspie Porzuconych Statków, że ty i Dannie zakradliście się do indyjskiej świątyni i zatopiliście 'Latającego Holendra'?";
				link.l2.go = "caleuche";
			}
			link.l1 = "Dzięki, mam się dobrze. Po prostu chciałem was obu zobaczyć.";
			link.l1.go = "exit";
			NextDiag.TempNode = "marun_town_4";
		break;
		
		case "caleuche":
			dialog.text = "Naturalnie, że tak.";
			link.l1 = "Muszę dotrzeć na tę wyspę ze świątynią. Bardzo muszę ją znaleźć. Mówiłeś, że masz jej mapę. Czy możesz podać mi współrzędne?";
			link.l1.go = "caleuche_1";
		break;
		
		case "caleuche_1":
			dialog.text = "O, przyjacielu, to bardzo niebezpieczne przedsięwzięcie, wiesz... świątynia Khael Roa jest przeklęta. Gdybyś tylko wiedział, kto zamieszkuje jej korytarze...";
			link.l1 = "W tej chwili zamieszkują go potwory o wiele bardziej przerażające niż te, które widziałeś wtedy. A ja i tak tam pójdę.";
			link.l1.go = "caleuche_2";
		break;
		
		case "caleuche_2":
			dialog.text = "Nie wybaczę sobie, jeśli tam zginiesz. "+pchar.name+"  Błagam cię: porzuć tę wyprawę! Poza tym to tam najczęściej widziany jest 'Latający Holender'...";
			link.l1 = "Już się z tym zetknąłem i wiem, jak to prześcignąć. Nathan, proszę, podaj mi współrzędne Khael Roa i powiedz wszystko, co wiesz o tej świątyni, poza tym, że zamieszkują ją nieumarli Indianie.";
			link.l1.go = "caleuche_3";
		break;
		
		case "caleuche_3":
			dialog.text = "Och cóż... Nie mogę ci odmówić, ale... nie masz pojęcia, co my i Dannie tam przeżyliśmy! Khael Roa znajduje się na wschód od Antigui. Znalazłem jego mapę zaraz po powrocie do Maroon Town, jest na... (patrząc) współrzędne: 19 stopni 32' Północ, 62 stopni 25' Zachód.";
			link.l1 = "Zapiszę jego lokalizację w swoim dzienniku... Dzięki, Nathan!";
			link.l1.go = "caleuche_4";
		break;
		
		case "caleuche_4":
			dialog.text = "You can thank me later. Now the details. The island of Khael Roa is a ring of rocks with a cove inside. Seek for the passage between the crags - it's fairly deep there. In the cove, you should cast anchor and disembark at the beach. Look for an old path heading deeper into the island - there's only one there. It will lead you to an Indian pyramid - this is the temple you seek.\nThe island itself is quiet, but the temple is crawling with abominations of all sorts. The entrance is located at the top of the pyramid. There will be three passages inside; you should take the middle one. Then you walk down the corridor and you will find a platform with four entrances or exits. This is where the temple creatures attacked me for the first time, so you should be careful.\nThen there is a labyrinth. It's very complex, and I, for the life of me, can't remember the right route. There is a multitude of foul creatures in the labyrinth. You must kill them all, then walk up to a hall with two entrances, six columns and a platform with nine stone slabs. This is the vestibule of the sanctuary. Its stone wall is closed, and I have no idea how you're going to open it.\nThere is some kind of mechanism, but I swear to God that I have no clue how it functions! I used an idol as a key. I inserted it into the central slab, and the door opened. But you don't have such an idol, so you'll have to figure out how this mechanism functions.";
			link.l1 = "Dobrze, zrobię co w mojej mocy, by to rozgryźć. A co z sanktuarium?";
			link.l1.go = "caleuche_5";
		break;
		
		case "caleuche_5":
			dialog.text = " Sanktuarium to ogromna sala z bardzo wysokim sufitem i dużymi kamiennymi schodami. Nie możesz ich użyć - są zbyt stare i w większości się rozpadły. Ale budowniczowie świątyni, jak się zdaje, byli również wielkimi czarownikami. Są tam portale, jak te Kukulkana, i przeniosą cię z jednego miejsca na drugie.\nRozpoznasz je łatwo - wyglądają jak kolorowe wiry. Na pierwszym piętrze będą dwa portale, ale jeden z nich to pułapka, więc bądź ostrożny! Właściwy portal zabierze cię na drugie piętro. Tam musisz znaleźć kolejny portal, aby wejść jeszcze wyżej, a następnie prosto do serca świątyni!\nTam, przy wielkim posągu ptaka, został umieszczony ten magiczny artefakt, który ja i Dannie zabraliśmy ze sobą. I już ci opowiadałem, co się stało potem.";
			link.l1 = "Będę pamiętał, co mi właśnie powiedziałeś. Dziękuję, Nathanielu. Bardzo mi pomogłeś.";
			link.l1.go = "caleuche_6";
		break;
		
		case "caleuche_6":
			dialog.text = "Troszcz się o siebie, "+pchar.name+"Labirynt i korytarze świątyni pełne są niebezpieczeństw. Jeden fałszywy ruch, a zostaniesz tam na zawsze.";
			link.l1 = "Praemonitus praemunitus, przyjacielu. Byłem ostrzeżony, to znaczy, jestem przygotowany. Muszę teraz iść. Do zobaczenia!";
			link.l1.go = "caleuche_7";
		break;
		
		case "caleuche_7":
			dialog.text = "Powodzenia, "+pchar.name+"!";
			link.l1 = "Dzięki!";
			link.l1.go = "caleuche_8";
		break;
		
		case "caleuche_8":
			DialogExit();
			DeleteAttribute(pchar, "questTemp.NatanStory");
			DeleteAttribute(pchar, "questTemp.Caleuche.NatanInfo");
			AddQuestRecord("Caleuche", "35");
			NextDiag.CurrentNode = "marun_town_4";
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}
