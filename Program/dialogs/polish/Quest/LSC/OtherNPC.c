// диалоги прочих НПС по квесту LSC
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
			link.l1 = "Nie, to nic takiego.";
			link.l1.go = "exit";			
			NextDiag.TempNode = "First time";
		break;
		
		//-----------------------------------бандосы Акулы в трюме с припасами--------------------------------------
		case "PantryGuard":
			dialog.text = "Ho, ho, spójrzcie tylko na to, chłopcy! Kto nas odwiedził! Złodziej, co rabuje skrzynie ludzi! Chodź tutaj! A ty, kumplu, nawet nie próbuj udawać głupiego i wyciągnąć miecza - nie chybię z tak bliskiej odległości... Chad będzie naprawdę zadowolony, że cię zobaczy!";
			link.l1 = "Ale ja... Ja dopiero co tu przybyłem!";
			link.l1.go = "PantryGuard_1";
		break;
		
		case "PantryGuard_1":
			dialog.text = "Masz rację, ha-ha! Właśnie wpadłeś w prawdziwe bagno, kamracie... I nie uciekniesz od tego. Teraz, oddaj broń i chodź za mną! Klatka na 'Tartarze' czekała na ciebie tak długo, złodzieju!";
			link.l1 = "...";
			link.l1.go = "PantryGuard_2";
		break;
		
		case "PantryGuard_2":
			DialogExit();
			chrDisableReloadToLocation = false;
			SetLaunchFrameFormParam("Few hours later...", "", 0, 3);
			LaunchFrameForm();
			WaitDate("", 0, 0, 0, 7, 10); //крутим время
			RecalculateJumpTable();
			DoQuestFunctionDelay("LSC_GotoPrison", 3.0);
		break;
		
		case "CommonGuard":
			dialog.text = "Nie próbuj niczego stąd ukraść. Będę cię obserwował.";
			link.l1 = "Jesteś bardzo mile widziany.";
			link.l1.go = "exit";
			NextDiag.TempNode = "CommonGuard";
		break;
		
		case "ChadGuard":
			dialog.text = "Idź i zrób, co ci Chad powiedział. Nie gadaj za dużo!";
			link.l1 = "Tak, jestem w drodze...";
			link.l1.go = "exit";
			NextDiag.TempNode = "ChadGuard";
		break;
		
		case "ChadGuard_Attack":
			dialog.text = "Hej! Co, do diabła, tam robisz? Drań! Teraz masz przechlapane!";
			link.l1 = "...";
			link.l1.go = "ChadGuard_Attack_1";
		break;
		
		case "ChadGuard_Attack_1":
			DialogExit();
			sld = characterFromId("Chimiset");
			LAi_SetActorType(sld);
			LAi_ActorAnimation(sld, "afraid", "", -1);
			for(i = 1; i <= 3; i++)
			{				
				sld = CharacterFromID("ChadGuard_"+i);
				LAi_RemoveCheckMinHP(sld);
				LAi_SetWarriorType(sld);
				LAi_group_MoveCharacter(sld, "EnemyFight");
			}
			sld = characterFromId("Capper");
			LAi_SetWarriorType(sld);
			ChangeCharacterAddressGroup(sld, "Tartarusprison", "goto", "goto8");
			LAi_group_MoveCharacter(sld, "EnemyFight");
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("EnemyFight", "LSC_ChadGuard_Die");
			AddDialogExitQuest("MainHeroFightModeOn");
			pchar.GenQuest.Notsearchbody = true; // запрет обыска трупов
		break;
		
		// ----------------------------------Марчелло Циклоп--------------------------------
		// если ждали в каюте
		case "Cabin":
			dialog.text = "Hej, co do cholery tu robisz, do diabła? Gdzie jest Barbier?";
			link.l1 = "Nasz przyjaciel Adolfo jest... chory. Nie mógł przyjść na spotkanie, więc poprosił mnie, bym usiadł trochę w jego kajucie i czekał na ciebie.";
			link.l1.go = "Cabin_1";
		break;
		
		case "Cabin_A":
			dialog.text = "Hej, co tu do cholery robisz, psiakrew?";
			link.l1 = "Nasz przyjaciel Adolfo jest... chory. Nie mógł przyjść na spotkanie, więc poprosił mnie, żebym go zastąpił. Tak to ujmując.";
			link.l1.go = "Cabin_1";
		break;
		
		case "Cabin_1":
			dialog.text = "Brzmi dziwnie... rano był w porządku, a teraz jest chory.";
			link.l1 = "Cóż, wiesz, jak to bywa. Nagły atak gorączki...";
			link.l1.go = "Cabin_2";
		break;
		
		case "Cabin_2":
			dialog.text = "O, nie podoba mi się twoja twarz. Kłamiesz. Barbier nigdy nie powierzyłby tego spotkania nikomu innemu. Mów, łajdaku, kim jesteś i co mu zrobiłeś?";
			link.l1 = "Wiesz, ty też nie jesteś zbyt urodziwy. Już ci mówiłem, że Barbier jest chory. Jesteś wolno myślącym typem czy mam się powtórzyć? Miał ci dać klucz i...";
			link.l1.go = "Cabin_3";
		break;
		
		case "Cabin_3":
			DialogExit();
			sld = characterFromId("Mary");
			LAi_SetActorType(sld);
			LAi_CharacterEnableDialog(sld);
			LAi_ActorDialog(sld, pchar, "", -1, 0);
		break;
		
		// на Церес Смити - спасаем Мэри
		case "mary":
			dialog.text = "Cholera! Wytropiłeś mnie...";
			link.l1 = "Tak, łotrze! Nie tkniesz jej nawet palcem! Szykuj się na śmierć!";
			link.l1.go = "mary_1";
		break;
		
		case "mary_1":
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);//разрешить драться
			DialogExit();
			LAi_SetWarriorType(npchar);
			LAi_group_MoveCharacter(npchar, "EnemyFight");
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("EnemyFight", "LSC_KillCyclop_CS");
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		
		// посланник от Акулы по варианту N
		case "SharkCureer":
			dialog.text = "Jesteś "+GetFullName(pchar)+"? ";
			link.l1 = "Tak, to ja. Cóż się stało?";
			link.l1.go = "SharkCureer_1";
		break;
		
		case "SharkCureer_1":
			dialog.text = "Rekin mnie przysłał. Prosi, byś jak najszybciej go odwiedził. Ma dla ciebie coś ważnego.";
			link.l1 = "Co za pośpiech?.. Dobrze, idę natychmiast do 'San Agustin'.";
			link.l1.go = "SharkCureer_2";
		break;
		
		case "SharkCureer_2":
			// сюда можно поставить таймер на гибель Акулы, если не придёт до конца суток
			DialogExit();
			LAi_SetActorType(npchar);
			npchar.lifeday = 0;
			LAi_ActorGoToLocation(npchar, "reload", "reload1", "none", "", "", "", -1);
			sld = characterFromId("Dodson");
			sld.dialog.currentnode = "entrance_20"; // ноду Акуле
		break;
		
		// посланник от Акулы по варианту M
		case "SharkCureer_3":
			dialog.text = "Jesteś "+GetFullName(pchar)+"?";
			link.l1 = "Tak, to ja. Co się stało?";
			link.l1.go = "SharkCureer_4";
		break;
		
		case "SharkCureer_4":
			if (!CheckAttribute(pchar, "questTemp.Saga.DodsonDie"))
			{
				dialog.text = "Uh, jestem zmęczony szukaniem ciebie... Rekin i Layton Dexter. Proszą, żebyś natychmiast się z nimi zobaczył. To bardzo ważna sprawa, więc pospiesz się.";
				link.l1 = "Czyżby? Dobrze, natychmiast idę na 'San Agustin'.";
				link.l1.go = "SharkCureer_6";
			}
			else
			{
				dialog.text = "Uh, mam dość szukania ciebie... Admirał Layton Dexter prosi, abyś natychmiast się z nim spotkał. To bardzo ważna sprawa, więc się pospiesz.";
				link.l1 = "Admirał?";
				link.l1.go = "SharkCureer_5";
			}
		break;
		
		case "SharkCureer_5":
			dialog.text = "Tak. Jako drugi w dowodzeniu, stał się naszym admirałem po śmierci Rekina.";
			link.l1 = "Rozumiem. Dobrze, natychmiast udaję się na 'San Agustin'.";
			link.l1.go = "SharkCureer_6";
		break;
		
		case "SharkCureer_6":
			DialogExit();
			LAi_SetActorType(npchar);
			npchar.lifeday = 0;
			LAi_ActorGoToLocation(npchar, "reload", "reload1", "none", "", "", "", -1);
		break;
		
		// тюремщик вместо Каппера
		case "Prisonboss":
			if (npchar.quest.meeting == "0")
			{
				dialog.text = "Ach, oto jesteś... Pamiętam cię, jesteś ostatnim człowiekiem, który rozmawiał z Chimisetem. Czy go zabiłeś?";
				link.l1 = "Przestań pieprzyć bzdury! Doskonale wiesz, że to nie byłem ja. Myślę, że wiesz, kto jest zabójcą.";
				link.l1.go = "meeting";
				npchar.quest.meeting = "1";
			}
			else
			{
				dialog.text = "Eh, tak nudno tu siedzieć cały dzień! Gdybyś tylko przyniósł rum i karty, kumplu, moglibyśmy zagrać w hazard...";
				link.l1 = "Przepraszam, kumplu, nie mam teraz na to czasu. Może później.";
				link.l1.go = "exit";
			}
			NextDiag.TempNode = "Prisonboss";
		break;
		
		case "meeting":
			dialog.text = "Mam kilka domysłów, tak, ale nie mam żadnych faktów. Nikt nie widział śmierci tego czarnoskórego. Na całej wyspie krążą plotki, że to my, ludzie Rekina, jesteśmy odpowiedzialni i mówią, że jakiś nowicjusz zrobił to na rozkaz admirała. Widzisz teraz? Więc nie idź do Rivadów, zwłaszcza teraz. Są zbyt wściekli.";
			link.l1 = "Dobrze. Zrozumiałem.";
			link.l1.go = "exit";
			NextDiag.TempNode = "Prisonboss";
		break;
		
		case "Prisonboss_M":
			dialog.text = "Eh, tak nudno spędzać tu cały dzień! Gdybyś tylko przyniósł rum i karty, przyjacielu, moglibyśmy zagrać w hazard...";
			link.l1 = "Przepraszam, kumplu, nie mam na to czasu. Może później.";
			link.l1.go = "exit";
			NextDiag.TempNode = "Prisonboss_M";
		break;
		
		// заместитель Акселя в магазине
		case "AxelHelper":
			dialog.text = "Czego chcesz, przyjacielu?";
			link.l1 = "Hm. A co cię tu sprowadza? Gdzie jest Axel?";
			link.l1.go = "AxelHelper_1";
		break;
		
		case "AxelHelper_1":
			dialog.text = "Aksel jest zajęty. Ma spotkanie z Donaldem Greenspenem i będzie z nim do końca dnia. Więc jeśli chcesz coś kupić - porozmawiaj z nim jutro rano. A ja pilnuję sklepu, więc nie próbuj niczego ukraść...";
			link.l1 = "Rozumiem. A dlaczego robi to dzisiaj? Dobrze, przyjdę tu jutro rano.";
			link.l1.go = "exit";
			NextDiag.TempNode = "AxelHelper_2";
		break;
		
		case "AxelHelper_2":
			dialog.text = NPCStringReactionRepeat("Już ci wszystko powiedziałem. Przyjdź tutaj jutro.","Nie zawracaj mi głowy, kolego. Zgub się!","Nie denerwuj mnie, łajdaku!","Precz!!","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Dobrze.","Mam to, mam to.","Zamknij się...","Co?!",npchar,Dialog.CurrentNode);
			link.l1.go = DialogGoNodeRepeat("exit", "", "", "", npchar, Dialog.CurrentNode);
		break;
		
		// мать Белого Мальчика - Агнес Кристиансен
		case "agnes":
			dialog.text = "Czego chcesz, panie?";
			link.l1 = "Hm... Przepraszam, pani. Wybacz mi moją bezczelność i złe maniery, ale chciałbym zapytać o coś: czy znasz człowieka imieniem Ole Christiansen?";
			link.l1.go = "agnes_1";
		break;
		
		case "agnes_1":
			dialog.text = "Powtórz jeszcze raz, co powiedziałeś... Ole Christiansen? Ole?!";
			link.l1 = "Tak. Nazywają go także Białym Chłopcem ze względu na szczególny kolor jego włosów. Znasz go?";
			link.l1.go = "agnes_2";
		break;
		
		case "agnes_2":
			dialog.text = "Czy ja go znam?! On jest moim synem i zaginął już dekadę temu! Czy wiesz, gdzie on jest, panie? Powiedz mi natychmiast, gdzie on jest, co się z nim stało?!";
			link.l1 = "Spokojnie, pani, nie martw się tak. On ma się dobrze. Jest na moim statku. Wszystko, czego potrzebuje, to zejść na ląd i przybyć tutaj.";
			link.l1.go = "agnes_3";
		break;
		
		case "agnes_3":
			dialog.text = "Och... Wydaje się, że Pan w końcu usłyszał moje modlitwy! Nie wyobrażasz sobie, jak się martwiłem, gdy zaginął! I to była tylko i wyłącznie moja wina! Gdzie go znalazłeś? On nie jest zwykłym dzieciakiem... cóż, musisz wiedzieć, o czym mówię.";
			link.l1 = "Tak, rzeczywiście, on jest wyjątkowy. I nie zmienił się. Wydaje się, że wciąż jest dzieckiem. Znalazłem go na jednej z wysp. Spotkaliśmy się przypadkiem. Poprosił mnie o białą koralik... cholera!... O perłę.";
			link.l1.go = "agnes_4";
		break;
		
		case "agnes_4":
			dialog.text = "Perła? O Boże! Perły były powodem, dla którego mój chłopak zniknął! To wszystko przez ten przeklęty naszyjnik!";
			link.l1 = "Czy to prawda, że Ole... opuścił swój dom z powodu zerwania twojego naszyjnika z pereł?... Uspokój się, panienko, nie płacz!";
			link.l1.go = "agnes_5";
		break;
		
		case "agnes_5":
			dialog.text = "Tak, to prawda. Ole zerwał mój naszyjnik na molo i wszystkie perły wpadły do wody. Tak go przeklinałam, a mój nieżyjący mąż... ukarał go. Ole zniknął następnego dnia. Nie możesz sobie wyobrazić, jak bardzo się za to obwiniałam!";
			link.l1 = "Ole zbiera perły od lat. Nazywa je białymi paciorkami. Zebrał je wszystkie dla ciebie i poprosił mnie, bym cię do niego zabrał. Nie miałem innych szczegółów oprócz domu z czerwonym dachem. Ale w końcu udało mi się cię znaleźć.";
			link.l1.go = "agnes_6";
		break;
		
		case "agnes_6":
			dialog.text = "Zbieranie pereł?! O, Boże! Jestem tak winny wobec mojego biednego chłopca! Ja... a on zbierał perły! O!";
			link.l1 = "Przypuszczam, że lepiej zawołam twojego syna, pani. Był tak chętny, aby cię zobaczyć. Powiedział, że będziesz szczęśliwa, widząc perły. Ale myślę, że będziesz szczęśliwa nie z ich powodu...";
			link.l1.go = "agnes_7";
		break;
		
		case "agnes_7":
			dialog.text = "Mynheer... czy byłbyś tak uprzejmy. Przyprowadź mi mojego Ole. Chcę go przytulić i poprosić o wybaczenie...";
			link.l1 = "Oczywiście, pani. Przyprowadzą go tutaj natychmiast.";
			link.l1.go = "agnes_8";
		break;
		
		case "agnes_8":
			DialogExit();
			SetLaunchFrameFormParam("One hour later", "", 0, 5);
			LaunchFrameForm();
			WaitDate("", 0, 0, 0, 1, 10); //крутим время
			RecalculateJumpTable();
			DoQuestFunctionDelay("LSC_OleGoHome", 5.0);
		break;
		
		case "agnes_9":
			dialog.text = "";
			link.l1 = "Cóż, pani, oto twój syn - Ole Christiansen. Rozpoznajesz go?";
			link.l1.go = "agnes_10";
		break;
		
		case "agnes_10": // перекидываем pchar
			DialogExit();
			LAi_SetActorType(pchar);
			LAi_ActorTurnToCharacter(pchar, characterFromID("Agnes"));
			ChangeShowIntarface();
			SetMainCharacterIndex(GetCharacterIndex("Agnes"));
			PChar = GetMainCharacter();			
			LAi_SetPlayerType(PChar);
			sld = characterFromId("Ole");
			sld.dialog.currentnode = "home";
			LAi_SetActorType(sld);
			LAi_ActorDialog(sld, pchar, "", -1, 0);
		break;
		
		case "agnes_11":
			dialog.text = "Mynheer... Przepraszam, nie zapytałem o twoje imię... "+pchar.name+"?";
			link.l1 = ""+GetFullName(pchar)+", pani kapitan. Kapitan "+GetFullName(pchar)+".";
			link.l1.go = "agnes_12";
		break;
		
		case "agnes_12":
			dialog.text = "Kapitana, nie możesz sobie wyobrazić, jak jestem wdzięczny za mojego syna! Pomogłeś mu i przyprowadziłeś go tutaj. Sprawiłeś, że znowu żyję! Zrobię wszystko dla mojego chłopca, dam mu całą miłość, której brakowało mu przez te wszystkie lata.";
			link.l1 = "Cieszę się dla ciebie, pani. I dla Ole także. To dobry chłopak i pomógł mi w trudnej sytuacji. Ma dobre serce. Znam człowieka, którego Ole ocalił od śmierci.";
			link.l1.go = "agnes_13";
		break;
		
		case "agnes_13":
			dialog.text = "Panie, nalegam, abyś przyszedł tutaj jutro lub kiedykolwiek znajdziesz czas. Chcę ci podziękować za mojego syna. W tej chwili jestem trochę... cóż, wiesz.";
			link.l1 = "Tak, pani.";
			link.l1.go = "agnes_14";
		break;
		
		case "agnes_14":
			dialog.text = "Wracaj tu jutro. Należycie cię wynagrodzę za wszystko dobre, co zrobiłeś dla mojego syna i dla mnie.";
			link.l1 = " Dobrze. Na pewno cię odwiedzę!";
			link.l1.go = "agnes_15";
		break;
		
		case "agnes_15":
			DialogExit();
			bDisableCharacterMenu = false;//лоченые интерфейсы
			chrDisableReloadToLocation = false;//открыть локацию
			LAi_SetOwnerType(npchar);
			LocatorReloadEnterDisable("Marigo_town", "houseSp2", true);
			NextDiag.CurrentNode = "agnes_16";
			pchar.quest.LSC_Ole_return.win_condition.l1 = "Timer";
			pchar.quest.LSC_Ole_return.win_condition.l1.date.hour  = 8.0;
			pchar.quest.LSC_Ole_return.win_condition.l1.date.day   = GetAddingDataDay(0, 0, 1);
			pchar.quest.LSC_Ole_return.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 1);
			pchar.quest.LSC_Ole_return.win_condition.l1.date.year  = GetAddingDataYear(0, 0, 1);
			pchar.quest.LSC_Ole_return.function = "LSC_OleAgnesRegard";
			// удаляем Оле из пассажиров
			sld = characterFromId("Ole");
			RemovePassenger(Pchar, sld);
			DeleteAttribute(pchar, "GenQuest.Ole");
			DoQuestReloadToLocation("Marigo_town", "reload", "houseSp2", "");
		break;
		
		case "agnes_16":
			dialog.text = "Ah, tutaj jesteś, panie "+GetFullName(pchar)+" ! Chodź, usiądź... ";
			link.l1 = "Dzięki! Jak się ma Ole?";
			link.l1.go = "agnes_17";
		break;
		
		case "agnes_17":
			dialog.text = "Och, nie możesz sobie wyobrazić, co zrobiłeś! Byłeś widokiem dla zmęczonego serca matki... Jestem ci dłużna i będę się za ciebie modlić na zawsze.";
			link.l1 = "Sprawiasz, że się rumienię, pani...";
			link.l1.go = "agnes_18";
		break;
		
		case "agnes_18":
			dialog.text = "Zawsze wiedziałem, że skromność to to, co czyni szlachetnych ludzi szlachetnymi... Przygotowałem prezenty za to, co zrobiłeś. Tak-tak! I nawet nie waż się odmówić! Proszę, weź to... Po pierwsze, jest tu skrzynia pełna dublonów. Po drugie, weź ten zaczarowany amulet, nazywają go Skarabeuszem\nMoim mężem był, i jestem pewna, że byłby zadowolony wiedząc, że jego skarb trafi do tak szlachetnego kapitana, który zwrócił mi syna. Mój mąż był cieślą, zwykł mówić, że Skarabeusz przyspieszał jego pracę\nMam nadzieję, że ten pierścień dobrze ci posłuży. Zasługujesz, by go nosić, bez wątpienia! I na koniec, weź moje narzędzia krawieckie. To świetny zestaw. Będziesz mógł stworzyć wiele dobrych rzeczy z nim.";
			link.l1 = "O! To naprawdę cenne dary dla każdego kapitana! Dziękuję, pani.";
			link.l1.go = "agnes_19";
		break;
		
		case "agnes_19":
			PlaySound("interface\important_item.wav");
			Log_Info("You have received a chest with doubloons");
			Log_Info("You have received the 'Scarab' amulet");
			Log_Info("You have received a sartorial set");
			GiveItem2Character(pchar, "chest");
			GiveItem2Character(pchar, "talisman7");
			GiveItem2Character(pchar, "tailor_tool");
			dialog.text = "Chcę, żebyś wiedział, że drzwi mojego domu są dla ciebie zawsze otwarte. Zawsze znajdziesz tu jedzenie, butelkę wybornego wina i cokolwiek innego zapragniesz.";
			link.l1 = "Dzięki za twoje miłe słowa, pani. Będę rad cię zobaczyć, gdy znów odwiedzę to miasteczko.";
			link.l1.go = "agnes_20";
		break;
		
		case "agnes_20":
			dialog.text = "Nie zapomnij przyjść!";
			link.l1 = "I teraz muszę iść. Żegnaj i powodzenia!";
			link.l1.go = "agnes_21";
		break;
		
		case "agnes_21":
			DialogExit();
			NextDiag.CurrentNode = "agnes_22";
			AddCharacterExpToSkill(pchar, "Fortune", 350);
			AddCharacterExpToSkill(pchar, "Leadership", 500);
			ChangeCharacterComplexReputation(pchar, "nobility", 10);
			ChangeCharacterComplexReputation(pchar, "authority", 4);
		break;
		
		case "agnes_22":
			dialog.text = "Ah, kapitanie "+GetFullName(pchar)+"! Tak się cieszę, że cię widzę! Chodź i usiądź, podam ci drinka...";
			link.l1 = "Dzięki! Chciałem tylko Cię przywitać i dowiedzieć się, jak się masz. Cieszę się, że Ty i Ole macie się dobrze.";
			link.l1.go = "exit";
			NextDiag.TempNode = "agnes_22";
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		//----------------------------------------- специальные реакции -----------------------------------------------
		//обнаружение ГГ в сундуках
		case "Man_FackYou":
			dialog.text = LinkRandPhrase("Co tam robisz, co? Złodzieju!","Spójrz tylko na to! Jak tylko pogrążyłem się w zadumie, postanowiłeś sprawdzić moją skrzynię!","Postanowiłeś sprawdzić moje skrzynie? Nie ujdzie ci to na sucho!");
			link.l1 = "Cholera jasna!";
			link.l1.go = "fight";
		break;
		
		case "Woman_FackYou":
			dialog.text = "Co?! Zdecydowałeś się sprawdzić moje skrzynie? Nie ujdzie ci to na sucho!";
			link.l1 = "Nierozważna dziewczyno!";
			link.l1.go = "exit_setOwner";
			LAi_group_Attack(NPChar, Pchar);
		break;
		
		case "fight":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			LAi_SetOwnerTypeNoGroup(npchar);
			LAi_group_Attack(NPChar, Pchar);
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		
		case "exit_setOwner":
			LAi_SetOwnerTypeNoGroup(npchar);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}
