// гид
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
	int i;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			dialog.text = "Chcesz czegoś?";
			link.l1 = "Nie, nic.";
			link.l1.go = "exit";			
			NextDiag.TempNode = "First time";
		break;
		
		case "guide_0":
			SetAchievement("Test_Ach");
			PlaySound("Voice\English\LE\Greguar\Greguar_01.wav");
			dialog.text = "Witajcie na Karaibach, Monsieur! Pozwólcie, że się przedstawię, jestem "+GetFullName(npchar)+" .  Jesteś nowy w naszej kolonii, prawda?";
			link.l1 = "Witajcie, Monsieur. Nazywam się "+GetFullName(pchar)+". Tak, właśnie wysiadłem. Nie wydaje mi się, żebym cię wcześniej widział... Znam cię?";
			link.l1.go = "guide_1";
		break;
		
		case "guide_1":
			DelLandQuestMark(npchar);
			dialog.text = "Nie, Monsieur, nie znasz mnie, ale nie mogłem przegapić okazji, by się przedstawić tak szlachetnemu panu jak ty.\nOch, pamiętam mój pierwszy dzień tutaj, dzień przybycia do Nowego Świata. Rzeczy są tutaj bardzo różne. Lokalny styl życia może zrujnować twoje zdrowie i portfel.\nDlatego oferuję ci moją skromną pomoc. Bezpłatnie, co jest tutaj dość rzadkie, zapewniam cię, haha! Mogę zapoznać cię z naszą kolonią i archipelagiem. Uważaj to za małą wycieczkę.";
			link.l1 = "To bardzo miłe z waszej strony, merci Monsieur! Chętnie przyjmę waszą ofertę. Wiedza to w końcu potęga.";
			link.l1.go = "guide_2";
			link.l2 = "Doceniam pańską propozycję, monsieur, naprawdę, ale odmówię.";
			link.l2.go = "guide_exit";
		break;
		
		case "guide_exit":
			dialog.text = "Jak sobie życzysz, Monsieur. Tak czy inaczej, miło było cię poznać. Honorowi dżentelmeni to rzadcy goście tutaj. Życzę ci powodzenia!";
			link.l1 = "Ty też, "+GetFullName(npchar)+"!";
			link.l1.go = "guide_exit_1";			
		break;
		
		case "guide_exit_1":
			DialogExit();
			LAi_SetCitizenType(npchar);
			LAi_CharacterDisableDialog(npchar);
			npchar.lifeday = 0;
			DoQuestCheckDelay("NgtF3", 1.0);
			QuestPointerToLoc("FortFrance_town", "reload", "reload3_back");
		break;
		
		case "guide_2":
			dialog.text = "Cieszę się, że to słyszysz. To dla mnie przyjemność. Pozwól, że przedstawię ci kilka podstaw. Większość kolonii zbudowana jest według podobnego układu: osada na brzegu, chroniona przez fort i mury miejskie z bramami. Szlachta, bogacze, żołnierze, marynarze, handlarze, najemnicy i przestępcy - wszyscy oni żyją razem w tych murach.\nCzasem spotkasz kapitanów, mnichów, cyganów i żebraków. Nie znajdziesz jednak Indian na ulicach, ci dzikusy sprawiają ludziom niepokój. Jeśli chcesz zobaczyć Indian, musisz udać się do dżungli. Chodź za mną, pokażę ci kilka naszych lokalnych zakładów.";
			link.l1 = "";
			link.l1.go = "guide_3";			
		break;
		
		case "guide_3": // идем в таверну
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(npchar, "officers", "reload4_3", "Guide_tavern", -1);
			LAi_ActorFollow(pchar, npchar, "", -1);
			chrDisableReloadToLocation = true;//закрыть локацию
		break;
		
		case "guide_4":
			dialog.text = "To najważniejsze miejsce w każdej kolonii - tawerna. Tak, w Europie te miejsca mogą być uważane za siedlisko szumowin i złoczyńców, ale tutaj w Nowym Świecie jest inaczej. Barman może zaoferować ci pokój do spania, trochę rumu, soczyste plotki i pracę.\nJeśli potrzebujesz informacji, spróbuj porozmawiać z bywalcami tutaj. Kup pijakowi kolejny drink, a możesz dostać coś ciekawego w zamian... lub nie! Hazard jest tutaj popularny, ale uważaj na oszustów. Jeśli złapiesz kogoś na oszustwie, nie wahaj się zabić go na miejscu. Nikt cię za to nie osądzi.\nTawerna to także miejsce, gdzie możesz zatrudnić załogę i oficerów na swój statek, to jest, jeśli go posiadasz. Pamiętaj: tawerna ma informacje, pracę, załogę i rozrywkę.";
			link.l1 = "";
			link.l1.go = "guide_9";
			locCameraFromToPos(-2.08, 5.32, 68.88, false, -15.00, -0.60, 55.00);
		break;
		
		case "guide_5": // к магазину
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(npchar, "officers", "reload6_3", "Guide_store", -1);
			LAi_ActorFollow(pchar, npchar, "", -1);
		break;
		
		case "guide_6":
			dialog.text = "Sklep jest centrum handlowym każdej kolonii. Kapitanowie odwiedzają to miejsce równie często, co stocznię. Tutaj można zakupić amunicję, zapasy lub towary do handlu. Handel jest dość skomplikowany. \nPo pierwsze, znalezienie najlepszych miejsc do kupna czy sprzedaży zajmuje trochę czasu. Po drugie, potrzebujesz pewnych umiejętności handlowych, aby targować się z miejscowymi kupcami. \nDlatego większość kapitanów zatrudnia kwatermistrzów, aby prowadzili interesy w ich imieniu. Nie zapomnij więc zatrudnić profesjonalisty, kiedy... lub jeśli zdobędziesz własny statek. To kluczowe, nie chcesz tutaj marnować pieniędzy. Jeden błąd i będziesz zrujnowany. Jeszcze jedno. Kupcy w sklepach często mogą zaoferować ci kontrakty dostawcze, co może okazać się przydatne w przyszłości.";
			link.l1 = "";
			link.l1.go = "guide_26";
			locCameraFromToPos(-21.10, 6.60, 45.21, false, -30.00, 3.70, 45.00);
		break;
		
		case "guide_7": // к тюрьме
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(npchar, "reload", "reload_jail", "Guide_prison", -1);
			LAi_ActorFollow(pchar, npchar, "", -1);
		break;
		
		case "guide_8":
			dialog.text = "A to jest więzienie. Plugawa nora. Najgorsi z przestępców szybko kończą z pętlą na szyi, więc głównie drobnica jest tu trzymana.\nJeśli chcesz z nimi pogadać, porozmawiaj z strażnikiem więziennym. Pozwoli ci wejść za drobną opłatą, albo nawet za darmo, jeśli potrafisz być przekonujący! Może to się okazać przydatne, ale pamiętaj, że nie można ufać łotrom, chociaż zawsze słodko gadają i protestują swoją niewinność za kratami.";
			link.l1 = "";
			link.l1.go = "guide_9";
			locCameraFromToPos(-52.40, 7.63, 42.60, true, 15.00, -4.00, -30.00);
		break;
		
		case "guide_9": // на рынок
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(npchar, "merchant", "mrcActive4", "Guide_market", -1);
			LAi_ActorFollow(pchar, npchar, "", -1);
		break;
		
		case "guide_10":
			dialog.text = "To jest targowisko. Kupcy sprzedają i kupują wszystko, czego potrzebujesz. Zbrojmistrz może dostarczyć ci ostrza, broń palną, zbroje, amunicję i tak dalej. Jednak dobry sprzęt jest rzadki, więc nie spodziewaj się znaleźć tu arcydzieł. Takie rzeczy przychodzą z wielką ceną i ryzykiem, ale możesz znaleźć dobre ostrza i pistolety tutaj, chyba że ktoś je kupi przed tobą.\nZielarz może zaoferować mikstury zdrowotne, antidota, rośliny, składniki, fiolki, a jeśli masz szczęście, receptury. Ale po co ja ci to w ogóle mówię, nie jesteś alchemikiem, prawda? Cyganie oferują pogańskie amulety i bezużyteczne bzdury jak trupy nietoperzy. Niektórzy ludzie twierdzą, że znają zastosowanie takich rzeczy, ale to wszystko nonsens.\nMnisi sprzedają świece, święte talizmany i inne błogosławione drobiazgi: krzyże, pierścienie, przybory do pisania. A zbieracze śmieci sprzedają rupiecie oraz różne przedmioty, ale jeśli masz niezbędne umiejętności rzemieślnicze, możesz zrobić coś pożytecznego z grzebieni żółwi, gwoździ i lin.";
			link.l1 = "";
			link.l1.go = "guide_19";
			locCameraFromToPos(-13.58, 4.11, 69.06, false, -45.00, -6.00, 52.00);
		break;
		
		case "guide_11": // к резиденции
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(npchar, "officers", "reload3_1", "Guide_townhall", -1);
			LAi_ActorFollow(pchar, npchar, "", -1);
		break;
		
		case "guide_12":
			dialog.text = "Ach, spójrz na pałac gubernatora! To jest dom i biuro najważniejszego człowieka w kolonii. Szlachta odwiedza pałac na bale i przyjęcia, biznesmeni i kapitanowie przybywają tu, by rozwiązywać zarówno oficjalne, jak i osobiste sprawy. Zawsze jest mądrze być na liście przyjaciół gubernatora, ma on wiele wpływów na obywateli narodu, który reprezentuje.\nKorsarze mogą również zarobić dobre pieniądze, pracując dla gubernatorów, którzy są w stanie wykupywać jeńców wojennych. Jeśli jesteś zamożny i chcesz nawiązać dobrą relację z Jego Ekscelencją, może cię nawet zaszczycić, grając z tobą o wysokie stawki.\nZdaje się, że jesteś niecierpliwy, mój przyjacielu. Czy się spieszysz?";
			link.l1 = "No cóż... tak. Monsieur, szczerze mówiąc, przybyłem tutaj, aby odnaleźć mojego brata, powiedziano mi, że musi być tutaj, w Saint-Pierre. On jest ważnym człowiekiem, gubernator musi go znać.";
			link.l1.go = "guide_13";
			locCameraFromToPos(3.14, 7.39, 37.55, false, 1.06, 9.00, 14.14);
		break;
		
		case "guide_13":
			dialog.text = "Ah-ha, rozumiem. Chcesz więc odwiedzić Jego Ekscelencję i zapytać go o swego brata? Cóż, nie będę cię dłużej zatrzymywać. Nasz gubernator to Jacques Dille du Parquet, jestem pewien, że zrobi, co w jego mocy.";
			link.l1 = "Powiedz mi, kto jeszcze mógłby mi pomóc? Może to nierozsądne niepokoić Jego Ekscelencję z tak błahą sprawą?";
			link.l1.go = "guide_14";
		break;
		
		case "guide_14":
			dialog.text = "Powiedziałeś, że twój brat jest tutaj dobrze znany. Popytaj na ulicach. W końcu znajdziesz kogoś, kto może pomóc. Jak się nazywa twój brat?";
			link.l1 = "Michel de Monper.";
			link.l1.go = "guide_15";
		break;
		
		case "guide_15":
			dialog.text = "Michel de Monper... Tak, słyszałem to imię wcześniej, lecz nigdy nie miałem przyjemności poznać tego człowieka, więc nie mogę pomóc. Powodzenia, Monsieur, jestem pewien, że jeszcze się spotkamy.";
			link.l1 = "Merci, "+GetFullName(npchar)+"!";
			link.l1.go = "guide_16";
		break;
		
		case "guide_16":
			DialogExit();
			LAi_SetCitizenType(npchar);
			LAi_CharacterDisableDialog(npchar);//запрет диалога
			LAi_group_MoveCharacter(npchar, "FRANCE_CITIZENS"); // пока идем заниматься Мишелем
			chrDisableReloadToLocation = false;//открыть локацию
			DoQuestCheckDelay("NgtF3", 1.0);
			QuestPointerToLoc("FortFrance_town", "reload", "reload3_back");
		break;
		
		case "guide_17": // к ростовщику
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(npchar, "officers", "reload8_1", "Guide_bank", -1);
			LAi_ActorFollow(pchar, npchar, "", -1);
		break;
		
		case "guide_18":
			dialog.text = "To jest dom lichwiarza, lub bankiera, ich los bywa nazywany wieloma różnymi imionami, często bardzo nieprzyjemnymi. Możesz myśleć o nich, co chcesz, ale ich usługi mogą ci bardzo pomóc. Możesz zdeponować pieniądze, wymienić dublony i peso, sprzedać lub kupić biżuterię. Jeśli masz dobrą reputację, możesz nawet pożyczyć trochę monet, ale bądź ostrożny.\nLichwiarze oferują najlepsze ceny za klejnoty, biżuterię i inne cenne drobiazgi, zawsze odwiedzaj ich, aby sprzedać takie rzeczy. To potężni ludzie, więc nie zadzieraj z nimi.";
			link.l1 = "";
			link.l1.go = "guide_11";
			locCameraFromToPos(3.07, 7.64, 51.99, false, 45.00, -8.30, 4.50);
		break;
		
		case "guide_19": // к борделю
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(npchar, "officers", "reload9_1", "Guide_brothel", -1);
			LAi_ActorFollow(pchar, npchar, "", -1);
		break;
		
		case "guide_20":
			dialog.text = "Ach, burdel. Każdy mężczyzna odwiedza takie miejsca, inaczej już by zbankrutowały! Nawet szlachcice to robią, kosztem swojej honoru. Bądź tego świadom. Bądź miły dla dziewcząt, a mogą ci powiedzieć coś interesującego, czasem mężczyźni mają skłonność do paplaniny o prawie wszystkim w ich towarzystwie, co może się okazać przydatne.\nJeśli nie szukasz cudzych sekretów, to rozważ to: nie ma lepszego lekarstwa dla umysłu i ciała niż miłość. Jeśli twoja witalność jest niska - odwiedź dziewczęta. Możesz też wypić specjalną miksturę, aby poprawić swoją witalność, ale jest rzadka i nie tak zabawna. Och, kiedy mówię o twojej 'witalności', nie mam na myśli zadrapań na skórze. Będziesz obrywał, dużo. Ale jeśli obrywają cię mocno i często lub jeśli wypijasz zbyt wiele silnych mikstur zdrowotnych, w końcu zrujnujesz swoje ciało. Obserwuj swój stan, odpocznij, jeśli to konieczne, albo cierp konsekwencje.";
			link.l1 = "";
			link.l1.go = "guide_17";
			locCameraFromToPos(-2.75, 7.07, 61.10, false, 60.00, -6.60, 42.65);
		break;
		
		case "guide_21":
			dialog.text = "O, znowu ty, mój przyjacielu! Widzę, że pozwolili ci wejść do świętego miejsca Saint-Pierre - kwatery głównej Rycerzy Maltańskich! Musisz być ważny. Znalazłeś brata?";
			link.l1 = "Rzeczywiście, zrobiłem to...";
			link.l1.go = "guide_22";
		break;
		
		case "guide_22":
			dialog.text = "Wybacz mi, monsieur, ale wyglądasz na dość ponurego...";
			link.l1 = "Cholera jasna! Miałem nadzieję wyrwać się z tego pieprzonego zadupia i wrócić do Francji, ale wygląda na to, że Bóg ma inne plany. Wygląda na to, że będę musiał tu zostać na przeklęcie długi czas! A najgorsze jest to, że muszę stać się zwykłym marynarzem.";
			link.l1.go = "guide_23";
		break;
		
		case "guide_23":
			dialog.text = "To dość nagła zmiana w twoim losie, monsieur. Ale nie zniechęcaj się, nie będziesz zwyczajnym marynarzem. Bycie kapitanem własnego statku to tutaj bardzo szanowana pozycja. Zamierzasz kupić statek, prawda?";
			link.l1 = "Oui, to dokładnie to, co muszę zrobić... Wszystko, czego potrzebuję, to znaleźć stocznię i trochę pieniędzy tak szybko, jak to możliwe. Problem w tym, że nie mam bladego pojęcia, gdzie do cholery znaleźć stocznię, jak prowadzić statek, ani skąd wziąć pieniądze! Cholera jasna...";
			link.l1.go = "guide_24";
		break;
		
		case "guide_24":
			dialog.text = "Chciałbym napełnić twoje kieszenie złotem, ale jestem równie spłukany jak ty. Mogę jednak wypełnić twoją głowę wiedzą, której tak desperacko potrzebujesz. Zainteresowany?";
			link.l1 = "Tak, to by było świetne.";
			link.l1.go = "guide_25";
		break;
		
		case "guide_25":
			dialog.text = "Chodź za mną. Zacznijmy od najważniejszego - statków.";
			link.l1 = "";
			link.l1.go = "guide_5";
		break;
		
		case "guide_26": // на верфь
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(npchar, "reload", "reload5", "Guide_shipyard", -1);
			LAi_ActorFollow(pchar, npchar, "", -1);
			chrDisableReloadToLocation = true;//закрыть локацию
		break;
		
		case "guide_27":
			dialog.text = "Stocznia. Każda kolonia ma swoją. Miejsce, gdzie można sprzedać lub kupić statek morski, a także go naprawić. Pamiętaj, że nasze stocznie nie mają nic wspólnego z wielkimi stoczniami starej dobrej Europy. To są kolonie, tutaj nie budują galeonów ani okrętów liniowych.\nMiejscowi mistrzowie mogą budować lugry, szkunery i slupy. Bardzo rzadko zobaczycie brygi i barkentyny. Ale czasami korsarze przyprowadzają zdobyczne statki, które złapali, a stoczniowcy kupują je tanio, naprawiają i sprzedają z zyskiem.\nRaz widziałem fregatę na liście cen! Lokalne statki mają również słabe charakterystyki. Nie martw się jednak, ćwiczenie na małych i tanich jednostkach pozwoli ci się rozwijać i w końcu opanować coś lepszego.\nAch, a stocznia to także miejsce, gdzie można kupić działa. Jest kilka rodzajów armat, które można zainstalować na swoim statku, pod warunkiem, oczywiście, że może je utrzymać. Każda jednostka ma swoje ograniczenia, nigdy nie będziesz mógł zamontować 24-funtówek na lugrze. Pamiętaj, że działa dużego kalibru są rzadkie i drogie. Z drugiej strony, takie armaty mogą dosłownie zniszczyć załogę wroga, żagle i kadłub.\nOstatnia rzecz. Stocznie oferują także usługi dla estetów: mogą pomalować twoje żagle i zewnętrzną część statku, namalować emblematy lub herby. Pomalowanie jej na czerwono może nie sprawi, że popłynie szybciej, ale z pewnością będzie wyglądać o wiele bardziej efektownie.";
			link.l1 = "Interesujące...";
			link.l1.go = "guide_28";
			locCameraFromToPos(-26.74, 5.77, 49.03, false, -70.00, -25.00, 150.00);
		break;
		
		case "guide_28": // в порт
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(npchar, "quest", "quest1", "Guide_port", -1);
			LAi_ActorFollow(pchar, npchar, "", -1);
		break;
		
		case "guide_29":
			dialog.text = "To jest nabrzeże, serce każdego portu. Kiedyś żeglowałem, więc pozwól mi opowiedzieć Ci więcej o żeglowaniu.\nPo pierwsze, pamiętaj o najważniejszej rzeczy: nawet nie próbuj sterować statkiem, jeśli nie masz wystarczającej liczby punktów w umiejętności nawigacji! Gdy wymaganie nie jest spełnione, to Twoje inne umiejętności ucierpią, podobnie jak umiejętności Twoich oficerów.\nBędziesz gorzej walczył, gorzej strzelał, gorzej handlował i tak dalej.\nTo oznacza, że jeśli spróbujesz sterować okrętem wojennym z obecną umiejętnością nawigacji, nie zajdziesz daleko, w rzeczywistości możesz nawet nie być w stanie wykonać małego skrętu.";
			link.l1 = "Jak się tego nauczyć, nawigacji?";
			link.l1.go = "guide_30";
			locCameraFromToPos(-8.55, 4.06, 91.31, true, 40.00, -8.00, 0.00);
		break;
		
		case "guide_30":
			dialog.text = "Wiesz co, przyjacielu? Oto mała notatka o prowadzeniu statku. Przeczytaj ją, gdy zdobędziesz własny. Całkiem przydatny dokument - bardzo mi pomógł w swoim czasie.";
			link.l1 = "Bardzo dobrze, monsieur. Rzeczywiście, nie jestem teraz gotów przyswoić tak wiele skomplikowanej wiedzy.";
			link.l1.go = "guide_38";
			AddQuestRecordInfo("Guide_AtSea", "1");
		break;
		
		case "guide_31":
			dialog.text = "Ranga statku to określa. Na przykład, mam wystarczająco doświadczenia (45 punktów), by kontrolować statek 4. rangi bez kar. Brygi, barkentyny, fluyty. Dżonki i korwety wymagają więcej, więc nie będę w stanie używać ich właściwie. To nawet nie są statki drugiej rangi, jak fregaty i ciężkie galeony.\nCo do gigantycznych okrętów liniowych czy man-o-war... tylko eksperci w nawigacji mogą kontrolować takie potwory, trzeba lat, by opanować tę umiejętność, i nie zapominaj o pieniądzach. Okręt wojenny i jego załoga mogą opróżnić twoją sakiewkę w miesiąc, jeśli nie jesteś tak bogaty jak sam król Ludwik.";
			link.l1 = "Widzę...";
			link.l1.go = "guide_32";
		break;
		
		case "guide_32":
			dialog.text = "Pamiętaj o pozycjach oficerskich. Bosman szkoli twoją załogę i sprawia, że abordaż jest bardziej skuteczny, skarbnik wykona za ciebie operacje finansowe i uwolni twój statek od szczurów. Medyk leczy twoich rannych ludzi i zmniejsza liczbę ofiar w bitwie, cieśla naprawia wszelkie uszkodzenia statku, a oficerowie abordażowi ratują twoją skórę, gdy piraci zaczynają roić się na pokładzie. \nZwracaj uwagę na umiejętności kandydatów i ich reputację.";
			link.l1 = "Reputacja?";
			link.l1.go = "guide_33";
		break;
		
		case "guide_33":
			dialog.text = "Dokładnie. Każdy człowiek ma swoje. Pokazuje, kim człowiek naprawdę jest.\nJeśli jesteś honorowym człowiekiem i zawsze starasz się czynić dobro, to szukaj oficerów, którzy podzielają twoje ideały. A jeśli chcesz być piratem... cóż, rozumiesz, o co chodzi.\nUczciwi ludzie nie będą pracować dla łajdaków, odwrotnie także się zgadza.";
			link.l1 = "Zrozumiano.";
			link.l1.go = "guide_34";
		break;
		
		case "guide_34":
			dialog.text = "Teraz porozmawiajmy o rodzajach statków. Są dwa rodzaje. Handlowce i okręty wojenne. Handlowce lub statki handlowe mają duże ładownie i zazwyczaj są wolniejsze. Okręty wojenne są szybkie i mają silne działa, kosztem pojemności ładunkowej. Barki, flauty i karaki to dobre, solidne statki handlowe. Sloop, bryg i korweta to okręty wojenne. Oczywiście są hybrydy, statki odpowiednie zarówno do handlu, jak i walki: snows, szkunery i galeony. \nStatki mają również różne układy takielunku, niektóre są głównie ożaglowane rejowo, a niektóre głównie gaflowo, co wpływa na najlepszy kąt kursu statku.";
			link.l1 = "Kąt kursu?";
			link.l1.go = "guide_35";
		break;
		
		case "guide_35":
			dialog.text = "Tak. To określa, jak twoje olinowanie jest wpływane przez wiatr i przy jakim kursie twój statek osiągnie najlepszą możliwą prędkość. Kiedy będziesz na morzu, znajdź strzałkę na mini mapie, to będzie twój kąt kursu.";
			link.l1 = "To dla mnie trochę mylące. Ale przypuszczam, że z czasem się nauczę.";
			link.l1.go = "guide_36";
		break;
		
		case "guide_36":
			dialog.text = "Teraz twoja załoga. Ty i twój statek jesteście niczym bez ludzi, którzy nim kierują. Każdy marynarz musi znać trzy rzeczy. Jak radzić sobie z olinowaniem, jak obsługiwać działa i jak walczyć. Każdy naród wyróżnia się tylko w jednej z tych trzech czynności. Na przykład Hiszpania ma najlepszych wojowników na świecie, a ich abordażerzy noszą zbroje, więc śrut, cięcia i pchnięcia nie są przeciwko nim tak skuteczne. Mówię oczywiście o broni ręcznej, działowe śruty nie przejmują się pancerzami.\nOdwiedź tawerny Hiszpanii, Anglii i Francji, jeśli chcesz stworzyć załogę marzeń, lub jeśli chcesz zaryzykować, zatrudnij załogę piratów, mimo że człowiek może ich nienawidzić, to wciąż są najgroźniejszą załogą, jaką można mieć. Pilnuj morale swoich ludzi, regularnie dostarczaj im rumu, dziwek i monety. Zrób to, a twoi ludzie oddadzą za ciebie życie. Jeśli tego nie zrobisz, wywołają bunt. Zmotywowany profesjonalista jest wart dziesięciu nowicjuszy w walce. Nie zapominaj też o lekarzu lub rozwijaj własne umiejętności medyczne, aby zapobiec dodatkowym ofiarom.";
			link.l1 = "Zapamiętam to...";
			link.l1.go = "guide_37";
		break;
		
		case "guide_37":
			dialog.text = "Teraz kilka słów o bitwach morskich. Karaiby są niebezpieczne, pełne hiszpańskich patroli i piratów, więc prędzej czy później zetkniesz się z nimi na otwartym morzu. Armaty okrętowe używają czterech rodzajów amunicji. Kule armatnie, kartacz, łańcuchowy pocisk i bomby.\nKule armatnie są uniwersalne i najtańsze do zakupu, mają także największy skuteczny zasięg ognia. Rozrywają żagle wroga, niszczą kadłub i zabijają załogę.\nŁańcuchowe pociski mają przyzwoity zasięg, ich celem jest eliminacja olinowania wroga, aby ich spowolnić. Dobre, gdy chcesz ścigać lub uciec. Jeśli masz szczęście, możesz nawet zestrzelić cały maszt.\nBomby. Używaj ich, jeśli chcesz zatopić statek przeciwnika. Bomby zadają największe obrażenia kadłubowi, ale mają drugi najkrótszy zasięg ognia, więc musisz się najpierw zbliżyć, co może okazać się fatalne. Kosztują też najwięcej ze wszystkich pocisków.\nKartacze to najlepszy wybór, jeśli chcesz abordażować i przejąć statek wroga. Te małe draństwa wybijają ludzi, ale ich najkrótszy zasięg czyni ich użycie ryzykownym. Ale może się opłacić.\nWstrzymaj ogień, jeśli nie jesteś pewny, czy możesz zadać wystarczająco dużo obrażeń. Każda salwa kosztuje proch, czas i stan dział. Mogą czasem eksplodować, zwłaszcza jeśli strzelasz zbyt często. Zawsze manewruj, staraj się zająć lepszą pozycję. Jeśli wróg jest zbyt niebezpieczny i nie możesz uciec, spróbuj sprowokować go do ciągłego ostrzeliwania z dystansu, nie ponosząc obrażeń. Ta sztuczka ostatecznie wyczerpie ich zapasy prochu. Może to zająć dni, więc lepiej znajdź osłonę, jak skały lub linia brzegowa. Oczywiście taka taktyka nie zadziała na otwartym morzu.\nMiny. To również świetny sposób, aby ich wszystkich zatopić. Sprowokuj ich do pościgu i zrzucaj miny. Każda mina wymaga przyzwoitej ilości prochu, ale nawet jedna może zniszczyć lugger.\nZdobądź lunetę i użyj jej, aby obserwować wroga. Dobra luneta zapewni ci znakomity przegląd taktyczny, na przykład w kwestii obecności jednostek muszkieterów na statku przeciwnika. Wrodzy muszkieterzy mogą zdziesiątkować wielu twoich ludzi na pokładzie, więc upewnij się, że dasz im kartacz przed abordażem.";
			link.l1 = "Święty Jezu... to przerażające... ale chyba muszę być gotowy na wszystko.";
			link.l1.go = "guide_38";
		break;
		
		case "guide_38":
			dialog.text = "Dowiesz się, co do tego nie mam wątpliwości. Skoro masz zostać kapitanem i właścicielem statku, pokażę ci jeszcze jedno miejsce o wielkim znaczeniu. Biuro portowe. Chodź za mną.";
			link.l1 = "";
			link.l1.go = "guide_39";
		break;
		
		case "guide_39": // к портовому управлению
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(npchar, "reload", "reload10", "Guide_portoffice", -1);
			LAi_ActorFollow(pchar, npchar, "", -1);
		break;
		
		case "guide_40":
			dialog.text = "W porcie można znaleźć oferty pracy. Transporty dla dużych statków handlowych i eskortowanie konwojów dla okrętów wojennych. Jeśli posiadasz szybki statek pocztowy, mogą ci zaoferować pracę kuriera.\nPolecam zdobycie tu trochę zaufania. Jeśli dobrze wykonasz swoją pracę kilka razy, powierzą ci bardziej skomplikowane i znacznie lepiej płatne kontrakty.\nMożesz również zapytać o innych kapitanów i zostawić tu swoje nadmiarowe statki na przechowanie. Nieograniczone przechowywanie, tylko nie zapomnij zapłacić!";
			link.l1 = "Zrozumiałem.";
			link.l1.go = "guide_41";
			locCameraFromToPos(48.38, 9.48, 43.95, true, -70.00, -55.00, 150.00);
		break;
		
		case "guide_41":
			dialog.text = "Cóż, wrota miasta są blisko, więc jest jeszcze jeden temat, o którym chciałbym Ci opowiedzieć. Te bramy prowadzą do dżungli. Podążaj za mną, a opowiem Ci o działaniach skradania się i szermierce. Nie masz nic przeciwko?";
			link.l1 = "Wcale nie. Już bardzo mi pomogłeś!";
			link.l1.go = "guide_42";
		break;
		
		case "guide_42":
			dialog.text = "Podążaj za mną, zatem!";
			link.l1 = "";
			link.l1.go = "guide_43";
		break;
		
		case "guide_43": // к воротам
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(npchar, "reload", "gate_back", "Guide_gate", -1);
			LAi_ActorFollow(pchar, npchar, "", -1);
		break;
		
		case "guide_44":
			dialog.text = "Więc, oto mamy bramę miasta prowadzącą prosto do dżungli... To trochę żenujące, ale mam dla ciebie jeszcze jedną notatkę do przestudiowania później. Tym razem chodzi o niuanse naszego życia na lądzie. Poświęć czas na jej przeczytanie, ponieważ pomoże ci to lepiej zrozumieć, jak infiltrować wrogie miasta i jak walczyć na lądzie. Ale na razie proponuję, byśmy wyszli za bramy i trochę się zabawili - poćwiczmy fechtunek.";
			link.l1 = "Jesteś prawdziwą encyklopedią, Monsieur. Chodźmy! Ćwiczenia brzmią zabawnie.";
			link.l1.go = "guide_48";
			locCameraFromToPos(50.58, 5.74, 23.21, false, 100.00, 0.00, 20.00);
			AddQuestRecordInfo("Guide_OnLand", "1");
		break;
		
		case "guide_45":
			dialog.text = "Dokument możesz zdobyć w siedzibie Holenderskiej Kompanii Zachodnioindyjskiej. Znak twoich pokojowych zamiarów. Ten papier pozwoli ci wpłynąć do każdego portu, dopóki warunki nie wygasną.\nAle są pewne wady. Po pierwsze, Kompania ma specjalne zasady i wymaga, aby każdy kapitan chcący kupić licencję, musiał ich przestrzegać. Po drugie, to kosztuje dużo. I ostatnie, a zarazem najgorsze, nadal potrzebujesz umiejętności 'podnoszenia flagi', aby wpłynąć do portów. W przeciwnym razie zostaniesz zestrzelony na miejscu przez ciężkie działa fortu.";
			link.l1 = "Gdzie znajduje się siedziba Kompanii?";
			link.l1.go = "guide_46";
		break;
		
		case "guide_46":
			dialog.text = "Willemstad na Curaçao. Jeśli chcesz kupić patent - udaj się tam, oni podadzą ci szczegóły.";
			link.l1 = "Tu wszystko jest takie poplątane...";
			link.l1.go = "guide_47";
		break;
		
		case "guide_47":
			dialog.text = "Nie smuć się, przyjacielu. Nauczysz się. A teraz, poćwiczmy szermierkę.";
			link.l1 = "Brzmi dobrze. Ruszajmy!";
			link.l1.go = "guide_48";
		break;
		
		case "guide_48": // телепортируем за городские ворота
			DialogExit();
			LAi_SetActorType(npchar);
			DoQuestReloadToLocation("FortFrance_ExitTown", "goto", "goto19", "Guide_ExitTown");
		break;
		
		case "guide_49":
			dialog.text = "Mój przyjacielu, wierzę, że wiesz, jak trzymać miecz?";
			link.l1 = "Ha! Oczywiście, że wiem. Uczył mnie najlepszy mistrz szermierki w Paryżu!";
			link.l1.go = "guide_50";
		break;
		
		case "guide_50":
			dialog.text = "Dobrze dla ciebie. Pozwól, że najpierw nauczę cię trochę teorii.\nIstnieją trzy typy broni białej: lekka, średnia i ciężka. Każdy typ wymaga różnych umiejętności i zdolności, aby je opanować, więc musisz uczyć się ich oddzielnie.\nKażda klasa ma swoje zalety i wady. Lekkie bronie obejmują floret i rapier, mają niskie wymagania dotyczące wytrzymałości, ale zadają najmniejsze obrażenia. Ciężka broń, taka jak topór, może zabić jednym ciosem, choć szybko wyczerpuje twoją wytrzymałość, i możesz potrzebować odpoczynku pomiędzy uderzeniami. Średnie bronie, szable lub kordelasy, to coś pośredniego, łączące dobrą wagę i potencjał obrażeń.\nMasz do dyspozycji kilka ruchów i trików szermierczych: atak pchający, atak siekący, atak ciężki i atak grupowy. Możesz także parować, pozorować i blokować.\nAtak pchający jest najszybszym ruchem, wymaga najmniejszej ilości wytrzymałości, a jest doskonały dla długich rapierów. Jest prawie bezużyteczny dla toporów. Atak siekący jest dość wszechstronny, ma przyzwoitą szybkość, znaczną utratę wytrzymałości i jest dobry dla szabli, szerokich mieczy i toporów, ale nie tak skuteczny z rapierami. Atak ciężki jest wykonywany z góry, doskonały wybór dla toporów, sprawdzi się również przy krótkich szablach i kordelasach, jednak rapierów nie zaprojektowano do takich ruchów. Ten atak wyczerpie ogromną ilość wytrzymałości, jest powolny, ale zadaje miażdżące obrażenia i ignoruje bloki przeciwnika.\nBlokowanie jest bezużyteczne przeciwko ciężkim atakom, a doświadczeni przeciwnicy zawsze mają szansę przełamać twój blok. Parowanie jest znacznie lepsze, otwiera przeciwnika na ataki i zmusza go do utraty wytrzymałości. Kilka udanych parowań i przeciwnik całkowicie traci inicjatywę i jest zmuszony bronić się, podczas gdy ty masz pełną przewagę.\nPozorowanie jest trudne i ryzykowne. Oszukanie przeciwnika i natychmiastowe zadanie mu szybkiego pchnięcia wymaga tylko niewielkiej straty wytrzymałości, ale musisz być skoncentrowany, uważny i w rytmie walki. Opanowanie tego ruchu będzie wymagało od ciebie dużo praktyki, ale jest opłacalne - nawet zawodowi pojedynkowicze i mistrzowie miecza padną z twojej ręki.\nAby zmaksymalizować obrażenia z każdego rodzaju ataku, musisz używać odpowiedniej broni do każdego z nich. Atak pchający najlepiej wykonać z długimi, lekkimi, prostymi rapierami lub mieczami z balansem od 0 do 0,5. Długie, zakrzywione kordelasy lub szable z balansem od 1 do 2 są doskonałe do ataków siekących i ciężkich. Ciężki topór z balansem 2 jest idealny do ciężkich ataków, ale taka broń będzie wymagała dużo wytrzymałości i umiejętności do użycia. Atak grupowy nie jest wart bycia twoim głównym ruchem, jest raczej defensywny, ale zakrzywiona, lekka, długa kordelas z balansem od 0,75 do 1,25 sprawi cuda przeciwko grupom wrogów wokół ciebie.\nNa koniec, najlepszą bronią do pozorowania jest sztylet, rozważ uczynienie tego ruchu swoją specjalnością. Waga broni określa, ile wytrzymałości wymaga każde działanie ataku i wpływa również na obrażenia. Pamiętaj, że znalezienie idealnej broni może zająć trochę czasu, a praca nad stylem walki jeszcze więcej.";
			link.l1 = "A co, jeśli jest kilku wrogów?";
			link.l1.go = "guide_51";
		break;
		
		case "guide_51":
			dialog.text = "To komplikuje sprawy. Przyzwoity wojownik może pokonać kilku słabo wyszkolonych głupców razem na otwartej przestrzeni, ale jeśli atakuje cię tuzin łotrów - unikaj otoczenia za wszelką cenę, uciekaj, znajdź sobie róg lub schody, drzwi, cokolwiek, zmuszaj ich do walki jeden na jednego, albo dwóch na jednego. Pokroją cię w sekundę, jeśli popełnisz błąd, więc zmuszaj ich do gry na twoich zasadach, nie trać inicjatywy i pilnuj swojej wytrzymałości.\nSłyszałem jednak o specjalnym indiańskim eliksirze, który pozwalał mistrzom miecza i topora zabić pięciu czy sześciu wrogów naraz kilkoma atakami grupowymi.";
			link.l1 = "Specjalny eliksir?";
			link.l1.go = "guide_52";
		break;
		
		case "guide_52":
			dialog.text = "Ometochtli-mikstura czy jak to tam zwą. Starożytny przepis indiański. Zapytaj kupców, może ktoś ci to kiedyś sprzeda. Ale najpierw musisz nauczyć się alchemii, aby móc używać przepisu... Skoro już mówimy o miksturach - pozwól mi opowiedzieć ci o leczeniu.\nJeśli potrzebujesz naprawić małą ranę, użyj leczącej mikstury. Poważne obrażenia można leczyć eliksirem. Leczące mikstury, rum i wino również przywracają zdrowie.\nAntidotum i mikstura będą odpowiednie, jeśli zostaniesz otruty. Rekomenduję również korzeń imbiru, cudownie odświeża oddech. Leczy też bez skutków ubocznych, w przeciwieństwie do esencji i eliksirów.";
			link.l1 = "Czekać, skutki uboczne?";
			link.l1.go = "guide_53";
		break;
		
		case "guide_53":
			dialog.text = "Esencje, eliksiry i mikstury szkodzą twemu zdrowiu. Jak wspomniałem na początku naszej małej wycieczki, to źle. Złe zdrowie spowoduje spadki w poziomach twoich umiejętności, zmniejszy całkowitą ilość twoich punktów zdrowia i wytrzymałości.\nSen, seks i rzadki eliksir zwany 'Łzami Ish-Chel', nie jestem dokładnie pewien nazwy, wiem tylko, że mają w sobie jakieś łzy, w każdym razie takie rzeczy przywrócą zdrowie, jeśli nie jest całkiem zrujnowane. Jeśli jest już zbyt późno, odwiedź księdza, oni pomogą za opłatą.";
			link.l1 = "Rozumiem. Co możesz mi powiedzieć o pistoletach?";
			link.l1.go = "guide_54";
		break;
		
		case "guide_54":
			dialog.text = "Nie ma co dużo mówić. Celuj i strzelaj! Używaj kartaczy, jeśli jest kilku wrogów. Zdobądź muszkiet lub karabin, mają śmiertelne obrażenia, a zawsze możesz uderzyć ludzi kolbą. Słyszałem także o muszkiecie typu blunderbuss, który strzela granatami, to doskonała broń i bardzo piękna... ale nigdy jej nie widziałem.";
			link.l1 = "Rozumiem. Czas na ćwiczenia?";
			if (FindCharacterItemByGroupWithout_knife_03(pchar, BLADE_ITEM_TYPE) == "") link.l1.go = "guide_55a";
			else link.l1.go = "guide_55";
		break;
		
		case "guide_55a":
			dialog.text = "Hm. Właśnie zauważyłem. Gdzie jest twój miecz? Obawiam się, że nasza lekcja musi zostać opóźniona. Jak to się stało, że jesteś bez broni, "+pchar.name+"?";
			link.l1 = "Jakiś królewski skurwysyn w eleganckim stroju zabrał mi to jako zaliczkę na dług mojego brata... Masz dla mnie dodatkowy miecz? Oddam go po zakończeniu lekcji...";
			link.l1.go = "guide_55b";
		break;
		
		case "guide_55b":
			GiveItem2Character(pchar, "blade_05");
			EquipCharacterByItem(Pchar, "blade_05");
			dialog.text = "Masz szczęście. Mam dodatkowy miecz. Miałem go sprzedać, ale, szczęściarzu, zostałem opóźniony.";
			link.l1 = "Dziękuję. Ruszamy?";
			link.l1.go = "guide_55";
		break;
		
		case "guide_55":
			dialog.text = "En garde! I nie marnuj żadnych mikstur, które masz, nie zamierzamy się zabijać.";
			link.l1 = "Jak powiadasz.";
			link.l1.go = "guide_56";
			npchar.quest.guide_win = 0;
		break;
		
		case "guide_56": // махач
			LAi_SetPlayerType(pchar);
			LAi_SetCurHPMax(pchar); 
			LAi_GetCharacterMaxEnergy(pchar);
			LAi_SetCurHPMax(npchar); 
			LAi_GetCharacterMaxEnergy(npchar);
			LAi_SetImmortal(npchar, false);
			LAi_group_Delete("EnemyFight");
			if (MOD_SKILL_ENEMY_RATE <= 6)	// На первых трёх сложностях Валинье будет ослаблен
			{
				LAi_SetHP(npchar, LAi_GetCharacterMaxHP(npchar) * 0.7, LAi_GetCharacterMaxHP(npchar) * 0.7);
				npchar.rank = 1;
				SetSelfSkill(npchar, 1, 1, 1, 1, 1);
			}
			DialogExit();
			LAi_SetWarriorType(npchar);
			LAi_group_MoveCharacter(npchar, "EnemyFight");
			// ставим проверяльщики
			LAi_SetCheckMinHP(pchar, 1, true, "Guide_HeroFail");
			LAi_SetCheckMinHP(npchar, 1, true, "Guide_HeroWin");
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			AddDialogExitQuest("MainHeroFightModeOn");
			DoQuestCheckDelay("GuideFight_tutorial", 1.0);
		break;
		
		case "guide_57": // побил гида с первого раза
			dialog.text = "Ty... ty jesteś człowiekiem, który wie, jak trzymać swój miecz. Dobrze zrobione, Monsieur. Potrzebujesz więcej praktyki, ale masz potencjał, by stać się prawdziwym mistrzem szermierki.";
			link.l1 = "Dziękuję bardzo. Co teraz?";
			link.l1.go = "guide_62"; // нода на выход
			if (MOD_SKILL_ENEMY_RATE >= 6)
			{
				link.l2 = "Więcej ćwiczeń mówisz? Jesteś poważny? Mam dość tego protekcjonalnego tonu odkąd tylko postawiłem stopę w tym nędznym miejscu!";				//Пасхалка Корсары 2 для сложности СФ и выше
				link.l2.go = "guide_64";
			}
			AddComplexSelfExpToScill(50, 50, 50, 50);
			AddCharacterExpToSkill(pchar, "Leadership", 80);
		break;
		
		case "guide_58": // побил гида со второго или третьего раза
			dialog.text = "Znacznie lepiej! Widzisz, wystarczy się skoncentrować. Potrzebujesz więcej praktyki, pewnego dnia staniesz się przyzwoitym szermierzem.";
			link.l1 = "Dziękuję bardzo. Co teraz?";
			link.l1.go = "guide_62"; // нода на выход
			AddComplexSelfExpToScill(20, 20, 20, 20);
			AddCharacterExpToSkill(pchar, "Leadership", 30);
		break;
		
		case "guide_59": // побили первый раз
			dialog.text = "Wygrałem, Monsieur. Ruchy szybciej, paruj moje pchnięcia, odskocz. Rewanż?";
			link.l1 = "Oui! Bez litości, Monsieur!";
			link.l1.go = "guide_56";
			link.l2 = "Nie, wystarczy. Skończmy lekcję. Co teraz?";
			link.l2.go = "guide_62"; // нода на выход
		break;
		
		case "guide_60": // побили второй раз
			dialog.text = "Znowu wygrałem, "+pchar.name+"! Nie trać inicjatywy. Chwytaj moje uderzenia, zwódź je. Jeśli widzisz, że zamierzam uderzyć mocno - odskocz lub sparuj, nie tylko się broń. Jeszcze raz!";
			link.l1 = "Chodź, monsieur, tym razem cię zleję!";
			link.l1.go = "guide_56";
			link.l2 = "Nie, mam już dość. Zakończmy lekcję. Co teraz?";
			link.l2.go = "guide_62"; // нода на выход
		break;
		
		case "guide_61": // побили третий раз
			dialog.text = "Musisz się jeszcze wiele nauczyć, "+pchar.name+"Nie martw się, masz jeszcze dużo czasu, aby opanować szermierkę. Ale bądź ostrożny, nie ryzykuj, dopóki nie nauczysz się trzymać broni.";
			link.l1 = "Rozważę to, Monsieur, ale muszę przyznać, że miałeś po prostu za dużo szczęścia! To przeklęte upał... jedyny powód, dla którego nie obiłem cię po pysku. Merde, zakończmy naszą lekcję szermierki. Co teraz?";
			link.l1.go = "guide_62"; // нода на выход
		break;
		
		case "guide_62":
			dialog.text = "Teraz czas się pożegnać, Monsieur. To była przyjemność. Mam nadzieję, że moja prezentacja i szkolenie przyniosły ci trochę korzyści i okażą się przydatne w przyszłości. Być może, pewnego dnia znowu się spotkamy.\nA co do pieniędzy, których potrzebujesz - porozmawiaj z ważnymi ludźmi naszego miasta. Odwiedź wszystkie miejsca, które ci dziś pokazałem i porozmawiaj z ich właścicielami. Dopytuj się. Wybierz się na spacer do dżungli i do fortu. Znajdź pracę albo... cóż, nie jestem księdzem ani sędzią, sprawdź domy ludzi i zobacz, jakie błyskotki znajdziesz w ich niezamkniętych skrzyniach. Po prostu zrób to, gdy są odwróceni plecami, albo strażnicy cię złapią.\nPowodzenia, "+pchar.name+", Mam silne przeczucie, że masz w sobie iskrę prawdziwej wielkości. Zrób wszystko, co w twojej mocy, by rozniecić ją w płonący ogień!";
			link.l1 = "Dziękuję, Monsieur. Przyjemność po mojej stronie. Szczęśliwej drogi!";
			link.l1.go = "guide_63";
		break;
		
		case "guide_63":
			LAi_SetCurHPMax(pchar); 
			LAi_GetCharacterMaxEnergy(pchar);
			DialogExit();
			chrDisableReloadToLocation = false;//открыть локацию
			npchar.lifeday = 0;
			DoQuestReloadToLocation("FortFrance_Town", "quest", "quest2", "");
		break;
		
		case "guide_64": // решили убить Валинье
			dialog.text = "Trzymaj język za zębami, Monsieur! Nie będę dłużej tolerować takiej bezczelności. Jednakże, rozumiem twoją reakcję na nowe otoczenie, dlatego tym razem wybaczam twoje wybuchy. Ale od teraz pilnuj swoich słów. Żegnaj, Monsieur de Maure.";
			link.l1 = "Bez obrazy, Monsieur Valinnie. Gdybyśmy byli teraz w Luwrze, uważałbyś na swój ton! Czas nauczyć prowincję ostatniej lekcji. Broń się!";
			link.l1.go = "guide_65";
		break;
		
		case "guide_65":
			DialogExit();
			
			npchar.rank = 25;
			int iHp = MOD_SKILL_ENEMY_RATE*10+300;
			LAi_SetHP(npchar, iHp, iHp);
			SetSelfSkill(npchar, 80, 80, 80, 80, 50);
			SetShipSkill(npchar, 50, 80, 35, 30, 50, 20, 30, 20, 80);
			SetSPECIAL(npchar, 9, 5, 8, 6, 5, 10, 8);
			SetCharacterPerk(npchar, "Energaiser");
			SetCharacterPerk(npchar, "BasicDefense");
			SetCharacterPerk(npchar, "AdvancedDefense");
			SetCharacterPerk(npchar, "CriticalHit");
			SetCharacterPerk(npchar, "Tireless");
			SetCharacterPerk(npchar, "HardHitter");
			SetCharacterPerk(npchar, "Sliding");
			SetCharacterPerk(npchar, "BladeDancer");
			SetCharacterPerk(npchar, "SwordplayProfessional");
			SetCharacterPerk(npchar, "Gunman");
			SetCharacterPerk(npchar, "GunProfessional");
			GiveItem2Character(npchar, "blade_30");
			EquipCharacterbyItem(npchar, "blade_30");
			GiveItem2Character(npchar, "cirass7");
			GiveItem2Character(npchar, "obereg_7");
			GiveItem2Character(npchar, "talisman11");
			AddMoneyToCharacter(npchar, 10000);
			AddItems(npchar, "gold_dublon", 25);
			AddItems(npchar, "bullet", 5);
			AddItems(npchar, "grapeshot", 5);
			AddItems(npchar, "GunPowder", 10);
			TakeItemFromCharacter(npchar, "blade_12");
			npchar.cirassId = Items_FindItemIdx("cirass4");
			LAi_SetCurHPMax(npchar);
			LAi_GetCharacterMaxEnergy(npchar);
			LAi_SetCurHPMax(pchar); 
			LAi_GetCharacterMaxEnergy(pchar);
			LAi_SetImmortal(npchar, false);
			LAi_group_Delete("EnemyFight");
			LAi_SetWarriorType(npchar);
			LAi_group_MoveCharacter(npchar, "EnemyFight");
			npchar.SaveItemsForDead = true;
			npchar.DontClearDead = true;
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, false);
			LAi_group_SetCheck("EnemyFight", "Guide_HeroKill");
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}

string FindCharacterItemByGroupWithout_knife_03(ref chref, string groupID)
{
	ref refItm;
    string resultItemId;

	resultItemId  = "";
	for(i=TOTAL_ITEMS-1; i>=0; i--)
	{
		refItm = &Items[i];
		if( !CheckAttribute(refItm,"groupID") ) continue;
		if(refItm.groupID!=groupID) continue;
		if( !CheckAttribute(chref,"items."+refItm.id) ) continue;
		if(refItm.id == "knife_03") continue;
		if (groupID == BLADE_ITEM_TYPE)
		{
			resultItemId  = refItm.id;
		}
	}
	
	if (resultItemId != "")
	{
        return resultItemId;
	}

	return "";
}