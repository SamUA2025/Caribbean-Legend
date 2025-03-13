// шаман команчей Змеиный Глаз
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
			if (CheckAttribute(pchar, "questTemp.Tieyasal") && pchar.questTemp.Tieyasal == "calendar")
			{
				dialog.text = "Witaj, mój blady przyjacielu.";
				link.l2 = "Cieszę się, że cię widzę, czerwony bracie. Mam znów dla ciebie ważną sprawę.";
				link.l2.go = "calendar";
				break;
			}
			dialog.text = "Witaj, mój blady przyjacielu.";
			link.l1 = "Cieszę się, że cię widzę, Wężowe Oko.";
			link.l1.go = "exit";
			if (CheckAttribute(npchar, "quest.amulet") && CheckCharacterItem(pchar, pchar.questTemp.Saga.BaronReturn.Indian) && CheckCharacterItem(pchar, pchar.questTemp.Saga.BaronReturn.Amulet) && CheckCharacterItem(pchar, pchar.questTemp.Saga.BaronReturn.Obereg))
			{
				link.l2 = "Przyniosłem ci amulety, o które prosiłeś. Wymieńmy się.";
				link.l2.go = "SnakeEye_potion";
			}
			if (CheckAttribute(pchar, "questTemp.LSC")) // был в LSC
			{
				if (CheckAttribute(npchar, "quest.LSC_hello") && CheckCharacterItem(pchar, "buben"))
				{
					link.l2 = "Znalazłem twój tamburyn, Wężowe Oko. Spójrz na niego.";
					link.l2.go = "LSC_buben";
				}
				if (CheckAttribute(npchar, "quest.LSC_tube") && CheckCharacterItem(pchar, "smoking_tube"))
				{
					link.l2 = "Znalazłem ciekawą indiańską fajkę, Snake Eye. Rzuć okiem.";
					link.l2.go = "LSC_tube";
				}
				if (!CheckAttribute(npchar, "quest.LSC_hello"))
				{
					link.l2 = "Cześć, szamanie. Użyłem posążka i przeżyłem niesamowitą podróż. Miałeś całkowitą rację. Znalazłem cmentarzysko statków, białego kapitana, a nawet ładownię z zaopatrzeniem!";
					link.l2.go = "LSC_hello";
				}
				if (CheckAttribute(npchar, "quest.LSC_hello") && pchar.questTemp.Saga.BaronReturn == "shamane")
				{
					link.l3 = " Wężowe Oko, potrzebuję twojej pomocy.";
					link.l3.go = "Saga_nathaniel";
				}
			}		
			NextDiag.TempNode = "First time";
		break;
		
	//---------------------------------------- первая встреча------------------------------------------------
		case "SnakeEye":
			dialog.text = "Witaj, mój blady przyjacielu.";
			link.l1 = "Cześć, szamanie. Czemu zakładasz, że jestem twoim przyjacielem?";
			link.l1.go = "SnakeEye_1";
		break;
		
		case "SnakeEye_1":
			dialog.text = "Wiem wiele, ale nie zawsze wiem, co dokładnie. Przybyłeś tu z zamiarem. Los cię tu przywiódł, a ja ci pomogę.";
			link.l1 = "Dobrze wiedzieć! Rzeczywiście, jestem tu po twoją pomoc, mój czerwonoskóry przyjacielu. Powiem wprost: co miałeś na myśli, mówiąc żonie Hawka o Kukulcanie?";
			link.l1.go = "SnakeEye_2";
		break;
		
		case "SnakeEye_2":
			dialog.text = "Nawet martwe ryby dryfują. A żywy człek jest prowadzony przez los od celu do celu. Celem zakutego kapitana, ściganego przez złych ludzi w selva, był posąg Kukulkana. Jeśli się poświęcił, może być daleko stąd.";
			link.l1 = "Nie zrozumiałem niczego. O co chodzi z posągiem waszego boga i jak to możliwe, że Hawk zdołał odejść tak daleko pieszo, że nikt nie może go znaleźć nawet teraz?";
			link.l1.go = "SnakeEye_3";
		break;
		
		case "SnakeEye_3":
			dialog.text = "Jeśli Kukulcan zjadł Jastrzębia, to mógł go wypluć gdziekolwiek. Może nawet w innym świecie. Kukulcan zjadł mnie trzy razy. I za każdym razem byłem w innych miejscach. Dawno temu dotarłem tutaj i postanowiłem już nie ryzykować. Nie poszedłem do ust Kukulcana i nie wiem, gdzie wypluwa swoje ofiary.";
			link.l1 = "Jezu, to wykracza poza moje pojmowanie! Chcesz mi powiedzieć, że kamienny idol może teleportować ludzi daleko stąd?";
			link.l1.go = "SnakeEye_4";
		break;
		
		case "SnakeEye_4":
			dialog.text = "Nie tylko to. Kukulcan rządzi nie tylko przestrzenią, ale także czasem. A może nawet więcej. Powiedziałem skowanemu kapitanowi o złotym posągu, który zjada ludzi. Być może zdecydował się zaryzykować, gdy zobaczył, że pościg był blisko...";
			link.l1 = "Poczekaj, posąg jest z kamienia. A ty mówisz o złotym...";
			link.l1.go = "SnakeEye_5";
		break;
		
		case "SnakeEye_5":
			dialog.text = "O północy idol ożywa i staje się złotem. W tej chwili duch Kukulkana w nim mieszka. Strzeż się zbliżać do niego, bo możesz ujrzeć wschód słońca w innym miejscu. Nawet gwiazdy mogą zmienić swoje miejsca na niebie. Spotkasz tych, którzy jeszcze się nie narodzili lub zobaczysz narodziny tych, którzy dawno umarli albo wcale nie narodzili się.";
			link.l1 = "Co do... zagadki i znowu zagadki... Intrygujesz mnie, Wężowe Oko. Powiedziałeś, że przetrwałeś trzy spotkania z Kukulcanem, bogiem, w którego wierzysz. Dlaczego więc nie spróbuję swojego szczęścia z idolem boga, w którego nie wierzę?";
			link.l1.go = "SnakeEye_6";
		break;
		
		case "SnakeEye_6":
			dialog.text = "Szkoda. Szkoda, że nie wierzysz. Może sam Kukulkán cię wezwał i sprawił, że opuściłeś ziemię swoich przodków. Ale jeszcze go nie słyszysz. Wszystko dzieje się z jakiegoś dobrego powodu. Jeśli zdecydujesz się zaryzykować, musisz wiedzieć, że przetrwałem za każdym razem tylko dzięki wspaniałym miksturom Komanczów.";
			link.l1 = "Comanche? Czy to kolejna plemię?";
			link.l1.go = "SnakeEye_7";
		break;
		
		case "SnakeEye_7":
			dialog.text = "Tak moi wrogowie nazywają mój lud, którego już nigdy nie zobaczę. Mikstura przywraca siłę i wytrzymałość, a także leczy i chroni przed silnymi truciznami. Potrzebujesz kilku flakonów, ale mam tylko trzy.\nByło cztery flakony, ale jeden zgubiłem w dziwnym miejscu, które wygląda jak cmentarzysko statków białych ludzi. Tam rozpocząłem swoją podróż w tym świecie. Być może Kukulcan wypluł kapitana tam. Jeśli tak, to mu nie zazdroszczę.";
			link.l1 = "Co to za miejsce? Cmentarzysko statków?";
			link.l1.go = "SnakeEye_8";
		break;
		
		case "SnakeEye_8":
			dialog.text = "„Dziwne miejsce... Nie powinno istnieć, ale istnieje. Ludzie, którzy zabijają z powodu koloru skóry, tam żyją. Trzymają swoje zapasy wewnątrz dużego statku, gdzie Kukulcan mnie wypluł. Nie wszedłem do jego ładowni, którą chronią przed złodziejami, nie są to sąsiedzi godni zaufania. Jeśli tam dotrzesz - znajdź inne wyjście, nie wchodź do ładowni, bo kłopoty się zdarzą.\nBiałas pomoże ci znaleźć inny posąg, jeśli jeszcze żyje. Daj mu ten biały koralik. Lubi je.”";
			link.l1 = "Hm. Już mi się kręci w głowie, a to staje się coraz bardziej interesujące. Dalej, czerwonoskóry bracie.";
			link.l1.go = "SnakeEye_9";
		break;
		
		case "SnakeEye_9":
			Log_Info("You have received a white pearl");
			PlaySound("interface\important_item.wav");
			GiveItem2Character(pchar, "jewelry52");
			dialog.text = "Jeśli znajdziesz kapitana żywego, może być bardzo chory. Nie miałem czasu dać mu mikstury. Poszukaj tam mojego tamburynu. Dostałem go od dziadka. W torbie, którą zgubiłem, jest wiele rzeczy, ale potrzebuję tylko tamburynu. Trudno rozmawiać z duchami bez niego.";
			link.l1 = "Cóż, to miejsce brzmi bardzo interesująco! Miejmy nadzieję, że Hawk się tam przeniósł... Czy dasz mi swój eliksir?";
			link.l1.go = "SnakeEye_10";
		break;
		
		case "SnakeEye_10":
			dialog.text = "Dam ci to. Ale w zamian dasz mi trzy miejscowe amulety: "+XI_ConvertString(pchar.questTemp.Saga.BaronReturn.Indian)+", "+XI_ConvertString(pchar.questTemp.Saga.BaronReturn.Amulet)+" i "+XI_ConvertString(pchar.questTemp.Saga.BaronReturn.Obereg)+"Jedna flaszka za każdy amulet. Taki jest uczciwy układ. Wróć, gdy będziesz miał wszystkie amulety. Wtedy je wymienimy. Nie myśl, że jestem chciwy. Albo może zmienisz zdanie szukając amuletów.";
			link.l1 = "Nie będę tak myśleć. Czekaj na mnie, Wężowe Oko, wkrótce wrócę.";
			link.l1.go = "SnakeEye_11";
		break;
		
		case "SnakeEye_11":
			DialogExit();
			NextDiag.CurrentNode = "First time";
			npchar.quest.amulet = "true";
			AddQuestRecord("BaronReturn", "3");
			AddQuestUserData("BaronReturn", "sItem1", XI_ConvertString(pchar.questTemp.Saga.BaronReturn.Indian));
			AddQuestUserData("BaronReturn", "sItem2", XI_ConvertString(pchar.questTemp.Saga.BaronReturn.Amulet));
			AddQuestUserData("BaronReturn", "sItem3", XI_ConvertString(pchar.questTemp.Saga.BaronReturn.Obereg));
			sld = characterFromId("Danielle");
			sld.quest.talk = "SnakeEye";
			pchar.quest.BaronReturn_out.win_condition.l1 = "ExitFromLocation";
			pchar.quest.BaronReturn_out.win_condition.l1.location = pchar.location;
			pchar.quest.BaronReturn_out.function = "Saga_DannyTalk";
			pchar.questTemp.HelenDrinking.GiveAmulets = true;
			
			//if (GetCharacterIndex("Longway") != -1 && CheckPassengerInCharacter(pchar, "Longway") && CheckAttribute(pchar, "questTemp.PZ_Etap4_Start"))
			if (GetCharacterIndex("Longway") != -1 && CheckPassengerInCharacter(pchar, "Longway"))	// Временно так
			{
				// Квест "Путеводная звезда", начало 4 этапа
				PChar.quest.PZ_Etap4_Start.win_condition.l1 = "location";
				PChar.quest.PZ_Etap4_Start.win_condition.l1.location = "Shore9";
				PChar.quest.PZ_Etap4_Start.win_condition = "PZ_Etap4_Start";
				locations[FindLocation("Shore9")].DisableEncounters = true;
			}
		break;
		
		// даёт зелья - идем на телепортацию
		case "SnakeEye_potion":
			dialog.text = "Dobrze, mój przyjacielu. Czy przyniosłeś mi amulety, abyś mógł udać się do Kukulcan?";
			link.l1 = "Tak. Jestem gotów odbyć tę samą podróż, którą odbył Nathaniel, zakuty kapitan.";
			link.l1.go = "SnakeEye_potion_1";
		break;
		
		case "SnakeEye_potion_1":
			RemoveItems(pchar, pchar.questTemp.Saga.BaronReturn.Indian, 1);
			RemoveItems(pchar, pchar.questTemp.Saga.BaronReturn.Amulet, 1);
			RemoveItems(pchar, pchar.questTemp.Saga.BaronReturn.Obereg, 1);
			TakeNItems(pchar, "Ultimate_potion", 3);
			Log_Info("You have given amulets");
			Log_Info("You have received three versatile potions");
			PlaySound("interface\important_item.wav");
			dialog.text = "Weź te mikstury. Pamiętaj, że musisz wypić jedną natychmiast po tym, jak Kukulcan cię wypluje, w przeciwnym razie umrzesz albo będziesz bardzo, bardzo chory. Pamiętaj też, żeby nie iść do ładowni, gdzie bladzi twarze trzymają swoje zapasy. Jest inny sposób na opuszczenie statku. Właściwie są dwa sposoby. Znajdź czerwoną kobietę pierwszej nocy, to bardzo ważne. To wszystko, co mogę ci powiedzieć.";
			link.l1 = "Zapamiętam to, czerwony bracie.";
			link.l1.go = "SnakeEye_potion_2";
		break;
		
		case "SnakeEye_potion_2":
			dialog.text = "W takim razie idź. Dotknij Kukulkana o północy, a on cię pożre. Wezwę duchy, by cię prowadziły.";
			link.l1 = "Dziękuję, Wężowe Oko. Nie martw się o mnie, wszystko będzie dobrze. Spotkamy się ponownie!";
			link.l1.go = "SnakeEye_potion_3";
		break;
		
		case "SnakeEye_potion_3":
			DialogExit();
			NextDiag.CurrentNode = "First time";
			pchar.questTemp.Saga.BaronReturn = "first_teleport";
			pchar.questTemp.Dolly = true; // телепорты работают!
			LAi_LocationDisableOfficersGen("Pearl_jungle_03", true); // не пускать офицеров в локу телепорта
			DeleteAttribute(npchar, "quest.amulet");
			AddQuestRecord("BaronReturn", "4");
			sld = characterFromId("Danielle");
			sld.quest.talk = "teleport";
			pchar.quest.BaronReturn_out1.win_condition.l1 = "ExitFromLocation";
			pchar.quest.BaronReturn_out1.win_condition.l1.location = pchar.location;
			pchar.quest.BaronReturn_out1.function = "Saga_DannyTalk";
			QuestPointerToLoc("Pearl_Jungle_02", "reload", "reload1_back");
			QuestPointerToLoc("Pearl_Jungle_03", "camera", "dolly");
		break;
		
		// пришёл из LSC
		case "LSC_hello":
			dialog.text = "Miło mi cię widzieć, przyjacielu. Jak udało ci się wrócić z cmentarza statków?";
			link.l1 = "Znalazłem tam statuę Kukulkana, tak jak mi mówiłeś. Pomógł mi Biały Chłopak - Ole Christiansen. Statua była zatopiona w morzu, ale udało mi się ją dosięgnąć. Przeniosła mnie do indyjskiej wioski na Dominice.";
			link.l1.go = "LSC_hello_1";
			npchar.quest.LSC_hello = "true";
		break;
		
		case "LSC_hello_1":
			dialog.text = "Spotkał cię tam Monkitekuvri?";
			link.l1 = "Hm. Monkitekuvri? Kto to jest?";
			link.l1.go = "LSC_hello_2";
		break;
		
		case "LSC_hello_2":
			dialog.text = "On jest wodzem wioski.";
			link.l1 = "Nie pytałem o jego imię. Może był to Monkitekuvri, a może nie.";
			link.l1.go = "LSC_hello_3";
		break;
		
		case "LSC_hello_3":
			dialog.text = "Czy miał na głowie pompatyczne nakrycie z piór ptaków?";
			link.l1 = "Owszem, miał. Wiele piór... Wygląda na to, że oskubał wszystkie papugi w dżungli.";
			link.l1.go = "LSC_hello_4";
		break;
		
		case "LSC_hello_4":
			dialog.text = "On nazywa się Monkitekuvri. To nie są pióra papugi, lecz pióra orła. Ten pióropusz jest moim pióropuszem. Podarowałem go Monkitekuvri, kiedy Kukulcan mnie wypluł. Potem zabrali mnie do innej statuy...";
			link.l1 = "Cóż za niespodzianka! Oni również 'złożyli mnie w ofierze' Kukulcanowi! I znalazłem się tutaj, obok pierwszego posągu.";
			link.l1.go = "LSC_hello_5";
		break;
		
		case "LSC_hello_5":
			dialog.text = "Tak, mój blady przyjacielu. Moja podróż również się tutaj zakończyła.";
			link.l1 = "Idole teleportują się w kręgu... Ale jaki w tym sens? Masz jakieś pomysły, Oko Węża?";
			link.l1.go = "LSC_hello_6";
		break;
		
		case "LSC_hello_6":
			dialog.text = "Zakładam, że posągi nie działają prawidłowo. Obecnie przenoszą ludzi w różne miejsca, ale powinny przenosić ich w jedno miejsce. Coś z nimi jest nie tak.";
			link.l1 = "Co sprawia, że tak myślisz?";
			link.l1.go = "LSC_hello_7";
		break;
		
		case "LSC_hello_7":
			dialog.text = "Ponieważ teleportacja w kółku nie ma sensu. Kukulcan musi zabrać wszystkie ofiary w jedno miejsce, a nie przemieszczać je wokoło.";
			link.l1 = "A gdzież to może być to jedno miejsce?";
			link.l1.go = "LSC_hello_8";
		break;
		
		case "LSC_hello_8":
			dialog.text = "To wielki sekret, biały bracie, nawet dla mnie.";
			link.l1 = "Rozumiem. Dobrze, do diabła z idolami. Nigdy więcej się do nich nie zbliżę. Znalazłem zakutego kapitana, nie ma potrzeby już podróżować przez portale.";
			link.l1.go = "LSC_hello_9";
			AddQuestRecord("BaronReturn", "12");
		break;
		
		case "LSC_hello_9":
			dialog.text = "Kiedy byłeś na cmentarzysku statków. Czy znalazłeś tam mój tamburyn?";
			if (CheckCharacterItem(pchar, "buben"))
			{
				link.l1 = "Tak sądzę. Spójrz.";
				link.l1.go = "LSC_buben";
			}
			else
			{
				link.l1 = "Niestety, nie znalazłem go. Ale wiem, gdzie jest wyspa i mogę się tam dostać. Poszukam twojego tamburynu.";
				link.l1.go = "LSC_hello_10";
			}
		break;
		
		case "LSC_hello_10":
			dialog.text = "Szukaj tego, mój blady przyjacielu. Bardzo cię proszę. Bez mojego tamburynu słabo słyszę duchy.";
			link.l1 = "W porządku, Wężowe Oko. Do zobaczenia!";
			link.l1.go = "exit";
		break;
		
		case "LSC_buben":
			RemoveItems(pchar, "buben", 1);
			PlaySound("interface\important_item.wav");
			dialog.text = "To mój tamburyn. Dziękuję ci, mój blady przyjacielu. Mogę ci się odwdzięczyć. Przedstawiam ci tę broń, której twoi ludzie długo jeszcze nie będą mieli. To broń bladych twarzy z moich czasów.";
			link.l1 = "Interesujące! Pokaż mi to, czerwonoskóry przyjacielu...";
			link.l1.go = "LSC_buben_1";
		break;
		
		case "LSC_buben_1":
			GiveItem2Character(pchar, "pistol7");
			Log_Info("You have received a Colt revolver");
			PlaySound("interface\important_item.wav");
			TakeNItems(pchar, "shotgun_cartridge", 3);
			TakeNItems(pchar, "GunCap_colt", 3);
			dialog.text = "Weź to. Są tylko trzy ładunki, resztę zużyłem. Ale może nauczysz się robić ładunki do tego. Straciłem kilka tuzinów części do ładunków na cmentarzu statków, możesz je tam znaleźć.";
			link.l1 = "Oho! Toż to pistolet! Nigdy wcześniej czegoś takiego nie widziałem... cóż za dziwna machina? Jakiś mechanizm obrotowy... pięć nabojów! Wspaniałe!";
			link.l1.go = "LSC_buben_2";
		break;
		
		case "LSC_buben_2":
			dialog.text = "To się nazywa rewolwer Colt. Żaden inny pistolet w twoich czasach nie jest taki jak ten. Łatwy w użyciu, podnieś kurek i pociągnij za spust. Dobrze strzela.";
			link.l1 = "Dziękuję! Dziękuję, Wężowe Oko! To będzie miła niespodzianka dla moich wrogów... Szkoda, że są tylko trzy ładunki...";
			link.l1.go = "LSC_buben_3";
		break;
		
		case "LSC_buben_3":
			dialog.text = "Spróbuj nauczyć się robić ładunki do rewolweru Colt. Wtedy będziesz wielkim wojownikiem swoich czasów. Ach, mój blady bracie, zapomniałem poprosić cię o znalezienie mojej fajki na cmentarzysku statków. To była bardzo ładna fajka.";
			if (CheckCharacterItem(pchar, "smoking_tube"))
			{
				link.l1 = "Ha! A ja się zastanawiałem, czyja to może być pomalowana fajka? Spójrz.";
				link.l1.go = "LSC_tube";
			}
			else
			{
				link.l1 = "Dobrze. Poszukam także twojej fajki. Do zobaczenia!";
				link.l1.go = "exit";
			}
			npchar.quest.LSC_tube = "true";
		break;
		
		case "LSC_tube":
			RemoveItems(pchar, "smoking_tube", 1);
			PlaySound("interface\important_item.wav");
			dialog.text = "To moja fajka, bracie. Cieszę się, że ją znalazłeś. I mogę ci dać inny prezent za to. To sprytna książka bladolicych z moich czasów. Nie rozumiem jej. Spróbuj znaleźć mądrego człowieka, który potrafi czytać i zrozumieć tę książkę.";
			link.l1 = "Dziękuję, Wężowe Oko. Myślę, że znam kogoś, kto będzie tym zainteresowany.";
			link.l1.go = "LSC_tube_1";
		break;
		
		case "LSC_tube_1":
			GiveItem2Character(pchar, "chemistry");
			Log_Info("You have received a Lavoisier's chemistry textbook");
			PlaySound("interface\important_item.wav");
			dialog.text = "Daj mu to, biały bracie. Ta księga zawiera wielkie sekrety białej mądrości.";
			link.l1 = "Dobrze. Do zobaczenia, Wężowe Oko!";
			link.l1.go = "exit";
		break;
		
		// лечение Натаниэля
		case "Saga_nathaniel":
			dialog.text = "Słucham cię, blady bracie.";
			link.l1 = "Przyprowadziłem ze sobą skowanego kapitana, którego szukałem na cmentarzysku statków. Jest bardzo chory. Wiem, że tylko ty możesz go uleczyć...";
			link.l1.go = "Saga_nathaniel_1";
		break;
		
		case "Saga_nathaniel_1":
			dialog.text = "Kukulcan pochłonął jego zdrowie. Myślę, że mogę pomóc mu wyzdrowieć. Ale zajmie to co najmniej jedną pełnię księżyca. Kukulcan dawno temu pożarł kapitana, a choroba rozprzestrzeniła się głęboko w nim.";
			link.l1 = "Proszę, ulecz go, szamanie! Przyniosę ci, czego tylko potrzebujesz!";
			link.l1.go = "Saga_nathaniel_2";
		break;
		
		case "Saga_nathaniel_2":
			dialog.text = "Spróbuję, biały bracie. Nie musisz mi nic przynosić. Mam wszystko. Czas wzmacnia chorobę, ale uwięziony kapitan znów będzie zdrów za jeden księżyc.";
			link.l1 = "Dziękuję, czerwony bracie. Znowu uratowałeś mi życie.";
			link.l1.go = "Saga_nathaniel_3";
		break;
		
		case "Saga_nathaniel_3":
			dialog.text = "Zostaw zakutego kapitana w mojej chacie, biały bracie, i idź bez obaw. Zabierz też jego żonę, nikt nie może widzieć moich rytuałów.";
			link.l1 = "Dobrze, Wężowe Oko. Wezmę ze sobą Danielle. Do zobaczenia!";
			link.l1.go = "Saga_nathaniel_4";
		break;
		
		case "Saga_nathaniel_4":
			DialogExit();
			pchar.questTemp.Saga.BaronReturn = "treatment";
			sld = characterFromId("Nathaniel");
			RemovePassenger(Pchar, sld);
			LAi_SetStayType(sld);
			sld.location = "none";
			pchar.quest.Saga_NatanTreatment1.win_condition.l1 = "ExitFromLocation";
			pchar.quest.Saga_NatanTreatment1.win_condition.l1.location = pchar.location;
			pchar.quest.Saga_NatanTreatment1.function = "Saga_NatanTreatment";
		break;
		
		case "calendar":
			dialog.text = "Słucham, przyjacielu.";
			link.l1 = "Pamiętasz naszą rozmowę o posągach Kukulkana? Powiedziałeś, że 'powinny przenieść ludzi w jedno specjalne miejsce'.";
			link.l1.go = "calendar_1";
		break;
		
		case "calendar_1":
			dialog.text = "Pamiętam, biały kapitanie.";
			link.l1 = "Więc wiem, gdzie te posągi musiały przenieść ludzi, których pożarł Kukulcan.";
			link.l1.go = "calendar_2";
		break;
		
		case "calendar_2":
			dialog.text = "Gdzie?";
			link.l1 = "Do starego miasta Majów Tayasal. Znajduje się głęboko w dżungli Main.";
			link.l1.go = "calendar_3";
		break;
		
		case "calendar_3":
			dialog.text = "Bardzo interesujące. Skąd to wiesz?";
			link.l1 = "To długa historia, Wężowe Oko. Rozumiem też, jak tu trafiłeś. Jeszcze się nie urodziłeś, prawda?";
			link.l1.go = "calendar_4";
		break;
		
		case "calendar_4":
			dialog.text = "Nawet mój ojciec nie urodził się w waszych czasach. Ale ja żyję w waszych czasach i to jest wielka tajemnica.";
			link.l1 = "To jest właściwie wytłumaczalne. Kapłan Itza o imieniu Kanek, który mieszka w Tayasal, wezwał Kukulkana, by narodził się jako śmiertelnik w tym świecie i pochłonął mądrość białej rasy. Stworzył także dziurę czasową, która teleportowała kilku ludzi z przyszłości do naszych czasów...";
			link.l1.go = "calendar_5";
		break;
		
		case "calendar_5":
			dialog.text = "Pozwolić Kukulcanowi pochłonąć mądrość przyszłych ludzi?";
			link.l1 = "Tak. I Kukulcan planuje wrócić w przeszłość, by przekazać wiedzę Majom, którzy zmarli dawno temu. Historia zostanie zmieniona, a Majowie będą rządzić Ameryką, a może nawet więcej...";
			link.l1.go = "calendar_6";
		break;
		
		case "calendar_6":
			dialog.text = "";
			link.l1 = "Ale coś stało się z portalami i zaczęły teleportować ludzi w kółko zamiast do Tayasal. I dlatego jestem tutaj, potrzebuję twojej rady, Wężowe Oko.";
			link.l1.go = "calendar_7";
		break;
		
		case "calendar_7":
			dialog.text = "Dlaczego ja, biały kapitanie?";
			link.l1 = "Ponieważ zostałeś pożarty przez Kukulkana. I dlatego że posąg Kukulkana w pobliżu twojej wioski ma dziwny znak na tej mapie, który jest silnie związany z rytuałami Kaneka.";
			link.l1.go = "calendar_8";
		break;
		
		case "calendar_8":
			dialog.text = "Pokaż mi tę mapę?";
			link.l1 = "Proszę, spójrz...";
			link.l1.go = "calendar_9";
		break;
		
		case "calendar_9":
			RemoveItems(pchar, "skinmap", 1);
			dialog.text = "(patrząc) Ten okrągły znak, tak? I co to znaczy?";
			link.l1 = "Nie wiem, szamanie. Wiem tylko, że tylko jedna z trzech statuetek Kukulcana ma ten znak. I że statuetka ze znakiem należy do ciebie. Dochodzę do wniosku, że twoja statuetka jest wyjątkowa. Masz jakieś pomysły?";
			link.l1.go = "calendar_10";
		break;
		
		case "calendar_10":
			dialog.text = "Daj mi czas do jutra rano, biały bracie. Zostaw mi tę skórzaną mapę. Muszę zapytać duchów. Wróć jutro.";
			link.l1 = "Dobrze, czerwonoskóry bracie. Będę tu jutro. Dziękuję za pomoc.";
			link.l1.go = "calendar_11";
		break;
		
		case "calendar_11":
			DialogExit();
			SetFunctionTimerCondition("Tieyasal_CalendarThink", 0, 0, 1, false);
			pchar.questTemp.Tieyasal = "calendar_think";
			NextDiag.CurrentNode = "calendar_wait";
		break;
		
		case "calendar_wait":
			dialog.text = "Przyjdź później, biały bracie. Nie zawracaj mi teraz głowy.";
			link.l1 = "Jasne, szamanie...";
			link.l1.go = "exit";
			NextDiag.TempNode = "calendar_wait";
		break;
		
		case "calendar_12":
			dialog.text = "Mam ci coś do powiedzenia, biały bracie.";
			link.l1 = "Znalazłeś coś? A może masz jakieś przypuszczenia?";
			link.l1.go = "calendar_13";
		break;
		
		case "calendar_13":
			dialog.text = "Duchy przodków dały mi wizję i poszedłem do Kukulkana z mapą. Szukałem i znalazłem. To musi być to, czego szukasz, biały bracie.";
			link.l1 = "Co znalazłeś?";
			link.l1.go = "calendar_14";
		break;
		
		case "calendar_14":
			dialog.text = "Posąg Kukulkana ma dwa żelazne zaciski i wgłębienie. Wgłębienie ma okrągły, gładki kształt. Skierowane jest na okrągły i płaski przedmiot z twojej skórzanej mapy.";
			link.l1 = "Co to jest?";
			link.l1.go = "calendar_15";
		break;
		
		case "calendar_15":
			dialog.text = "Nie wiem. Wiem tylko, że jest okrągłe, płaskie, wielkości małej dyni i może grube jak palec. Możesz sam pójść i spojrzeć na wnęki i zaciski. Zacisk musi je trzymać.";
			link.l1 = "Masz jakiś pomysł? Albo przypuszczenie, co to może być?";
			link.l1.go = "calendar_16";
		break;
		
		case "calendar_16":
			dialog.text = "Kamień ma ślad ognia. Wiem, co się z nim stało. Płomień z nieba go trafił.";
			link.l1 = "Czy to piorun? Czy piorun w to uderzył?";
			link.l1.go = "calendar_17";
		break;
		
		case "calendar_17":
			dialog.text = "Jestem tego pewien. Pytałem Miskito o ten idol. Jeden wojownik powiedział, że dawno temu przy posągu widziano kilka ładnie pomalowanych rzeczy. Bardzo podobnych do kamieni. Powiedział mi, że to były bardzo ładne czerwone kamienie. Jeden biały człowiek z białej wioski je kupił.";
			link.l1 = "Hm. O ile rozumiem, wygląda na to, że piorun uderzył w to okrągłe 'coś', rozbił je na kawałki, a potem te kawałki sprzedano jakiemuś białemu facetowi?";
			link.l1.go = "calendar_18";
		break;
		
		case "calendar_18":
			dialog.text = "Wydaje się, że tak.";
			link.l1 = "A kim był ten biały człowiek? Czy twój wojownik ci powiedział?";
			link.l1.go = "calendar_19";
		break;
		
		case "calendar_19":
			dialog.text = "Opowiedział mi. Był wielkim przyjacielem Miskito i mieszka w wiosce Blueweld. Nazywa się Leśny Diabeł. Znam go, ty też musisz go znać.";
			link.l1 = "Jan Svenson? Poczekaj chwilę... mówisz o czerwonych, pomalowanych skałach? Wygląda na to, że miałem dużo szczęścia. Spójrz tutaj, szamanie, spójrz na te czerwone skały, które mam! Leśny Diabeł mi je podarował.";
			link.l1.go = "calendar_20";
		break;
		
		case "calendar_20":
			Log_Info("You have given ornamental pattern fragments");
			RemoveItems(pchar, "splinter_js", 1);
			RemoveItems(pchar, "splinter_nh", 1);
			RemoveItems(pchar, "splinter_mt", 1);
			RemoveItems(pchar, "splinter_zm", 1);
			RemoveItems(pchar, "splinter_jb", 1);
			dialog.text = "Musi to być oni. Pięć kamieni. Spójrz, biały bracie. Jeśli je tak ułożysz... (składając)";
			link.l1 = "... ";
			link.l1.go = "calendar_21";
		break;
		
		case "calendar_21":
			dialog.text = "... wtedy mamy okrągły przedmiot. Spójrz! Pasują do siebie. Kiedyś to był jeden przedmiot.";
			link.l1 = "Cholera! A te rzeczy były w mojej kieszeni tak długo... Słuchaj, szamanie, jeśli włożę odłamki do wnęki...";
			link.l1.go = "calendar_22";
		break;
		
		case "calendar_22":
			dialog.text = "Kukulcan wypluje ofiarę w starym mieście indiańskim, jak mówiłeś.";
			link.l1 = "To byłoby wspaniałe! Muszę się tam dostać! Czy myślisz, że ornament zadziała, jeśli został rozbity na kawałki?";
			link.l1.go = "calendar_23";
		break;
		
		case "calendar_23":
			dialog.text = "Myślę, że musimy ich zebrać razem, a potem umieścić ozdobę we wnęce.";
			link.l1 = "Sprowadzić ich razem? Ale jak możemy ich zjednoczyć?";
			link.l1.go = "calendar_24";
		break;
		
		case "calendar_24":
			dialog.text = "Zostaw to mnie i duchom przodków, biały bracie. To nie są zwykłe kamienie. To cudowny przedmiot. Wróć za trzy noce, biały bracie. Wezwę duchy, mądrość i umiejętności żyjących i spróbuję połączyć odłamki.";
			link.l1 = "Niesamowite... Jak mogę ci się kiedykolwiek odwdzięczyć, Wężowe Oko?";
			link.l1.go = "calendar_25";
		break;
		
		case "calendar_25":
			dialog.text = "Podziękuj mi później, biały bracie. Idź teraz. Wróć za trzy noce.";
			link.l1 = " Dobrze. Mam nadzieję, że ci się uda...";
			link.l1.go = "calendar_26";
		break;
		
		case "calendar_26":
			DialogExit();
			SetFunctionTimerCondition("Tieyasal_CalendarDone", 0, 0, 3, false);
			NextDiag.CurrentNode = "calendar_wait";
		break;
		
		case "calendar_28":
			dialog.text = "Mogę uczynić cię szczęśliwym, biały bracie.";
			link.l1 = "Udało ci się połączyć odłamki?";
			link.l1.go = "calendar_29";
		break;
		
		case "calendar_29":
			dialog.text = "Tak. To nie było łatwe i na kalendarzu pozostały blizny, ale teraz jest to zakończone.";
			link.l1 = "Kalendarz? Dlaczego tak to nazwałeś?";
			link.l1.go = "calendar_30";
		break;
		
		case "calendar_30":
			dialog.text = "Ponieważ ta okrągła rzecz to kalendarz. Studiowałem go uważnie. Jest na nim liczenie czasu. Indianie ze starożytnego miasta liczą noce, księżyce, lata i wieki.";
			link.l1 = "Niebywałe... Chociaż, myśląc o tym, do czego są zdolni kapłani Majów - stworzenie tego kalendarza nie wydaje się niczym szczególnym.";
			link.l1.go = "calendar_31";
		break;
		
		case "calendar_31":
			GiveItem2Character(pchar, "calendar_maya");
			sld = ItemsFromID("calendar_maya");
			sld.shown = "0";
			Log_Info("You have received a Maya calendar");
			dialog.text = "Weź to, biały kapitanie. Włóż to w zagłębienie na posągu. Wtedy może wyrzuci cię do indiańskiego miasta.";
			link.l1 = "Jak mogę ci się odwdzięczyć, Wężowe Oko?";
			link.l1.go = "calendar_32";
		break;
		
		case "calendar_32":
			dialog.text = "Powiedz 'Dziękuję'. Bogowie prowadzą cię na twojej drodze, nawet jeśli tego nie widzisz. Biali ludzie mówią - przeznaczenie. Kukulcan cię wezwał, bogowie cię prowadzą. Idź teraz. Wypełnij swą pracę i niech dobre duchy cię prowadzą.";
			link.l1 = "Dziękuję, Wężowe Oko! Nigdy cię nie zapomnę.";
			link.l1.go = "calendar_33";
		break;
		
		case "calendar_33":
			TakeNItems(pchar, "Ultimate_potion", 4);
			Log_Info("You have received four versatile potions");
			PlaySound("interface\important_item.wav");
			dialog.text = "Poczekaj. Prawie zapomnieliśmy o najważniejszej rzeczy. Kukulcan zjada człowieka i pochłania jego życie. Przygotowałem dla ciebie mikstury. Mikstury Komanczów. Dam je tobie. Zrobiłem cztery fiolki, więc możesz zabrać trzech lojalnych i odważnych towarzyszy ze sobą.";
			link.l1 = "Zrobiłeś dla mnie tak wiele, czerwonoskóry bracie...";
			link.l1.go = "calendar_34";
		break;
		
		case "calendar_34":
			dialog.text = "Brat to nie tylko słowo dla Indian z plemienia Komanczów. Kiedy wrócisz z miasta Kukulcan, odwiedź naszą wioskę. Ugotujemy dużo, dużo saraiaki. Będzie mi miło cię zobaczyć.";
			link.l1 = "Jasne, bracie czerwonoskóry! Na pewno cię odwiedzę!";
			link.l1.go = "calendar_35";
		break;
		
		case "calendar_35":
			DialogExit();
			pchar.questTemp.Tieyasal = "calendar_place";
			NextDiag.CurrentNode = "First time";
			AddQuestRecord("Tieyasal", "17");
			sld = ItemsFromID("skinmap");
			sld.price = 100; // кожаную карту можно выкладывать 270912 
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}
