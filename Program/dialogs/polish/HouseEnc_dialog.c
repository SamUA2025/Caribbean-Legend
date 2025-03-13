void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag, arRld, arDis;
	int i, Qty;
	ref rColony;
	
	int iTest;
	
	bool  ok; // лесник . спецпеременная.

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	iTest = FindColony(NPChar.City);
	if (iTest != -1)
	{
		rColony = GetColonyByIndex(iTest);
	}
	
	switch(Dialog.CurrentNode)
	{
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		case "exit_setOwner":
			LAi_SetOwnerTypeNoGroup(npchar);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		case "fight":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			LAi_SetOwnerTypeNoGroup(npchar);
			LAi_group_Attack(NPChar, Pchar);
			if (rand(3) != 1) SetNationRelation2MainCharacter(sti(npchar.nation), RELATION_ENEMY);
			AddDialogExitQuest("MainHeroFightModeOn");
		break;

		case "exit_GoOut":
			makearef(arRld, Locations[reload_cur_location_index].reload);
    		Qty = GetAttributesNum(arRld);
			for (i=0; i<Qty; i++)
    		{
    			arDis = GetAttributeN(arRld, i);
    			if (arDis.go == npchar.location)
    			{
					arDis.disable = true; //закрываем вход в дом
					break;
    			}
    		}
			DoQuestFunctionDelay("HouseEnc_TimerGoUot", 10.0);
			pchar.questTemp.HouseEncTimer = pchar.location;
			pchar.questTemp.HouseEncTimer.Id = npchar.id;
			LAi_SetOwnerTypeNoGroup(npchar);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		case "exit_close":
			makearef(arRld, Locations[reload_cur_location_index].reload);
    		Qty = GetAttributesNum(arRld);
			for (i=0; i<Qty; i++)
    		{
    			arDis = GetAttributeN(arRld, i);
    			if (arDis.go == npchar.location)
    			{
					arDis.disable = true; //закрываем вход в дом
					break;
    			}
    		}
			LAi_SetOwnerTypeNoGroup(npchar);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		//--------------------------------- мужик ---------------------------------
		case "HouseMan":
			NextDiag.TempNode = "HouseMan";
			if (LAi_grp_playeralarm > 0)
			{
       			dialog.text = PCharRepPhrase(LinkRandPhrase("Alarm został podniesiony w mieście. Wygląda na to, że nadszedł czas, bym też wziął broń do ręki...","Czy nie gonią za tobą przypadkiem strażnicy miasta?","Nie znajdziesz tutaj schronienia, ale możesz bardzo dobrze znaleźć kilka cali zimnej stali między żebrami!"),LinkRandPhrase("Czego potrzebujesz,"+GetSexPhrase("łotr","łotr")+"?! Strażnicy miasta już wywęszyli twój zapach, daleko nie uciekniesz, "+GetSexPhrase("brudny pirat","ty piracka wiedźma")+"!","Brudny morderca! Strażnicy!!!","Nie boję się ciebie, "+GetSexPhrase("paskuda","dziewczyna")+"! Wkrótce zostaniesz powieszony w naszym forcie, nie uciekniesz daleko..."));
				link.l1 = PCharRepPhrase(RandPhraseSimple("Widzę, że jesteś zmęczony życiem...","Wygląda na to, że nie ma spokojnego życia dla obywateli "+XI_ConvertString("Colonia"+npchar.city+"Gen")+"!"),RandPhraseSimple("Idź do diabła!","Heh, to będą ostatnie sekundy twojego życia..."));
				link.l1.go = PCharRepPhrase("exit_setOwner", "fight");
				break;
			}
			if (isBadReputation(pchar, 40))
			{
				if (CheckAttribute(pchar, "questTemp.HouseEncTimer"))
				{
					dialog.text = "Ostrzegałem cię. A potem sam zdecydujesz, czy chcesz wpakować się w kłopoty.";
					link.l1 = "Heh!";
					link.l1.go = "exit";
				}
				else
				{
					dialog.text = "Co ty potrzebujesz w moim domu, łajdaku?! Masz dziesięć sekund, żeby stąd wyjść!";
					link.l1 = LinkRandPhrase("Heh, wygląda na to, że też mnie tu znają!","Moja sława poprzedziła mnie...","Hmm, rozumiem.");
					link.l1.go = "exit_GoOut";
				}
			}
			else
			{
				if (IsDay())
				{
					dialog.text = NPCStringReactionRepeat("Cieszę się, że mogę powitać Cię w moim domu. Masz ze mną jakieś sprawy?","Co mogę dla ciebie zrobić?","Hmm... Co mogę dla ciebie zrobić?","Przykro mi, ale jeśli nie masz ze mną żadnych spraw, proszę, nie przeszkadzaj mi...","block",1,npchar,Dialog.CurrentNode);
					link.l1 = HeroStringReactionRepeat("Nie, tylko się rozejrzę, poznam nowych ludzi...","Nie, nic konkretnego...","Nic...","Dobrze, jak mówisz.",npchar,Dialog.CurrentNode);
					link.l1.go = DialogGoNodeRepeat("HouseMan_1", "exit_setOwner", "exit_setOwner", "exit_setOwner", npchar, Dialog.CurrentNode);
				}
				else
				{
					dialog.text = NPCStringReactionRepeat("Przykro mi, ale noc to nie najlepszy czas na odwiedziny, więc prosiłbym, abyś natychmiast opuścił mój dom!","Już ci powiedziałem, jest późno. Proszę, wyjdź.","Nie chcę wydawać się niegrzecznym, ale nalegam, abyś natychmiast opuścił mój dom!","Cholera, co się dzieje?! Strażnicy! Złodzieje!","block",1,npchar,Dialog.CurrentNode);
					link.l1 = HeroStringReactionRepeat("Dobrze, rozumiem...","Tak, tylko moment...","Dobrze, tylko nie denerwuj się tak.","Jakie złodzieje?! Zamknij się!",npchar,Dialog.CurrentNode);
					link.l1.go = DialogGoNodeRepeat("exit_close", "exit_setOwner", "exit_setOwner", "fight", npchar, Dialog.CurrentNode);
				}
			}
		break;

		case "HouseMan_1":
			dialog.text = "Oh, pozwól mi się przedstawić - "+GetFullName(npchar)+". Jesteśmy bardzo szczęśliwi, że możemy cię gościć. W tym mieście przestrzegane są prawa gościnności.";
			link.l1 = GetFullName(pchar)+", jeśli łaska...";
			link.l1.go = "exit_setOwner";
		break;
		case "Man_FackYou":
			dialog.text = LinkRandPhrase("Jesteś "+GetSexPhrase("złodziej, widzę! Strażnicy, chwytajcie go","złodziej, widzę! Strażnicy, chwytajcie ją")+"!!!","Nie mogę w to uwierzyć! Odwróciłem się na sekundę - i ty grzebiesz w moich rzeczach! Złodziej!!!","Stróże! Rabunek! Zatrzymajcie złodzieja!!!");
			link.l1 = "Aaaah, diabeł!!!";
			link.l1.go = "fight";
		break;
		// --------------------------------- баба ---------------------------------
		case "HouseWoman":
			NextDiag.TempNode = "HouseWoman";
			if (LAi_grp_playeralarm > 0)
			{
       			dialog.text = PCharRepPhrase(LinkRandPhrase("Ostrzegam cię, że mój mąż wróci wkrótce! Lepiej teraz opuść mój dom!","Nie sądzę, żeby ci się udało uciec! I miej na uwadze, że mój mąż wkrótce wróci do domu!","Mój mąż będzie wkrótce w domu! Musisz natychmiast odejść!"),LinkRandPhrase("Szkoda, że mój mąż nie jest w domu... Wynoś się! Teraz!!!","Brudny morderco, natychmiast wyjdź z mojego domu! Straż!",""+GetSexPhrase("Co za łotr","Co za brud")+"... Wkrótce mój mąż wróci, i zobaczy, jakiego koloru jest twoja krew!"));
				link.l1 = PCharRepPhrase(RandPhraseSimple("O, twój mąż... oooooh...Drżę...","Heh... Wiesz, dziewczyno, twój mąż to tylko jeden człowiek... nie chciałabyś, żeby umarł u twych stóp, prawda?"),RandPhraseSimple("Zamknij się, szmato, zanim cię podprę...","Pozostanę tutaj tak długo, jak tylko zechcę. A ty lepiej trzymaj język za zębami, jeśli wiesz, co jest dla ciebie dobre..."));
				link.l1.go = "exit_setOwner";
				break;
			}
			if (isBadReputation(pchar, 40))
			{
				if (CheckAttribute(pchar, "questTemp.HouseEncTimer"))
				{
					dialog.text = "Ostrzegałem cię. Wynoś się, albo pożałujesz!";
					link.l1 = "Co za głupia suka...";
					link.l1.go = "exit";
				}
				else
				{					
					dialog.text = "Co robisz w moim domu, "+GetSexPhrase("łotr","łotr")+"?! Jeśli nie znikniesz za dziesięć sekund, wołam straże!";
					link.l1 = "Co za głupia baba...";
					link.l1.go = "exit_GoOut";
				}
			}
			else
			{
				if (IsDay())
				{
					dialog.text = NPCStringReactionRepeat("Cieszę się, że widzę Cię w naszym domu. Nazywam się "+GetFullName(npchar)+". Co mogę dla ciebie zrobić?","Jeszcze tu jesteś?","Hm, przepraszam, ale czy nie uważasz, że to już czas dla ciebie, żeby opuścić to miejsce?","Uprzejmie proszę, abyś nie nadużywał naszej gościnności.","block",1,npchar,Dialog.CurrentNode);
					link.l1 = HeroStringReactionRepeat(GetFullName(pchar)+" do twojej usługi. Przybyłem tutaj bez konkretnego powodu, tylko aby nawiązać znajomość.","Wciąż tutaj.","Cóż, nie wiem...","Dobrze.",npchar,Dialog.CurrentNode);
					link.l1.go = DialogGoNodeRepeat("HouseWoman_1", "exit_setOwner", "exit_setOwner", "exit_setOwner", npchar, Dialog.CurrentNode);
				}
				else
				{
					dialog.text = NPCStringReactionRepeat("Ojej, dlaczego włamujesz się do mojego domu o takiej porze! Naprawdę mnie przestraszyłeś... Proszę, odwiedź nas jutro!","Proszę, opuść nasz dom!"+GetSexPhrase("","Jestem zamężną kobietą!")+"","Proszę cię po raz ostatni, opuść nasz dom!","Ale co się tu dzieje?!","block",1,npchar,Dialog.CurrentNode);
					link.l1 = HeroStringReactionRepeat("Nie bój się, nie zrobię ci krzywdy.","Dobrze, tylko się tak nie denerwuj.","Odchodzę.","Co u Ciebie słychać?",npchar,Dialog.CurrentNode);
					link.l1.go = DialogGoNodeRepeat("exit_close", "exit_setOwner", "exit_setOwner", "HouseWoman_2", npchar, Dialog.CurrentNode);
				}
			}
		break;

		case "HouseWoman_1":
			dialog.text = "Zawsze cieszymy się z gości. Tylko nie zostawaj tu na zbyt długo,"+GetSexPhrase(", skoro jestem mężatką..."," ponieważ mam dużo do zrobienia...")+"";
			link.l1 = "Och, tak, pewnie...";
			link.l1.go = "exit_setOwner";
		break;
		case "Woman_FackYou":
			dialog.text = "Czy tak to wygląda? Przyjąłem cię jako mojego gościa, a ty przeszukujesz nasze skrzynie?! Strażnicy!";
			link.l1 = "Zamknij się, suko!";
			link.l1.go = "exit_setOwner";
			LAi_group_Attack(NPChar, Pchar);
			if (rand(3) != 1) SetNationRelation2MainCharacter(sti(npchar.nation), RELATION_ENEMY);
		break;
		case "HouseWoman_2":
			dialog.text = "Prosiłem cię, abyś opuścił nasz dom w przyjazny sposób, ale ty po prostu nie chciałeś słuchać! Dość! Pomocy! Straże!";
			link.l1 = "Zamknij się, głupia kobieto! Czy ty zwariowała?!";
			link.l1.go = "exit_setOwner";
			LAi_group_Attack(NPChar, Pchar);
			if (rand(3) != 1) SetNationRelation2MainCharacter(sti(npchar.nation), RELATION_ENEMY);
		break; 
		//--------------------------------- завсклад ---------------------------------		
		case "SkladMan":
			NextDiag.TempNode = "SkladMan1";
			if (LAi_grp_playeralarm > 0)
			{
       			dialog.text = NPCharRepPhrase(pchar,LinkRandPhrase("Alarm został podniesiony w mieście. Wygląda na to, że nadszedł czas, abym również wziął do ręki broń...","Czy przypadkiem strażnicy miasta nie gonią za tobą?","Nie znajdziesz tu schronienia, ale możesz dobrze znaleźć kilka cali zimnej stali między swoimi żebrami!"),LinkRandPhrase("Na co masz ochotę,"+GetSexPhrase("łotr","łotr")+"?! Strażnicy miasta już znaleźli twój zapach, nie uciekniesz daleko, "+GetSexPhrase("brudny pirat","suka")+"!","Brudny morderca! Strażnicy!!!","Nie boję się ciebie, "+GetSexPhrase("paskuda","dziewczyna")+"! Wkrótce zostaniesz powieszony w naszym forcie, nie uciekniesz daleko..."));
				link.l1 = NPCharRepPhrase(pchar,RandPhraseSimple("Widzę, że jesteś zmęczony życiem...","Wygląda na to, że nie ma spokojnego życia dla obywateli "+XI_ConvertString("Colonia"+npchar.city+"Gen")+"!"),RandPhraseSimple("Idź do diabła!","Heh, to będą ostatnie sekundy twojego życia..."));
				link.l1.go = NPCharRepPhrase("exit_setOwner", "fight");
				break;
			}
				dialog.text = NPCStringReactionRepeat("Witaj! Nazywam się "+GetFullName(npchar)+". Tutaj, ja rządzę, więc nawet nie myśl o zabraniu czegokolwiek ze sobą...","Zachowuj się przyzwoicie i pamiętaj, że mam na ciebie oko.","Dopóki nie zaglądasz do skrzyń, możesz tu zostać. I tak mi jest nudno samemu...",RandPhraseSimple("O mój Boże, tak mi się nudzi!","Cholera, co tu robić? Bycie tutaj jest takie nudne!"),"block",3,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Dobrze, nie martw się.","Pewnie!","Widzę...","Tak, to brzmi jak problem.",npchar,Dialog.CurrentNode);
			link.l1.go = DialogGoNodeRepeat("exit", "exit", "exit", "exit", npchar, Dialog.CurrentNode);				
		break;
		
		case "SkladMan1":
			NextDiag.TempNode = "SkladMan1";
			if (LAi_grp_playeralarm > 0)
			{
       			dialog.text = NPCharRepPhrase(pchar,LinkRandPhrase("Alarm został podniesiony w mieście. Najwyraźniej, to czas dla mnie, aby również podjąć broń...","Czy przypadkiem strażnicy miasta nie gonią za tobą?","Nie znajdziesz tutaj schronienia, ale możesz dobrze znaleźć kilka cali zimnej stali między żebrami!"),LinkRandPhrase("Czego potrzebujesz,"+GetSexPhrase("łajdak","łotr")+"?! Strażnicy miasta już wywęszyli twój zapach, daleko nie uciekniesz, "+GetSexPhrase("brudny pirat","suka")+"!",""+GetSexPhrase("Brudny","Ohydny")+" morderca! Strażnicy!!!","Nie boję się ciebie, "+GetSexPhrase("gnida","wench")+"! Wkrótce zostaniesz powieszony w naszym forcie, nie uciekniesz daleko..."));
				link.l1 = NPCharRepPhrase(pchar,RandPhraseSimple("Widzę, że jesteś zmęczony życiem...","Wygląda na to, że nie ma spokojnego życia dla obywateli "+XI_ConvertString("Colony"+npchar.city+"Gen")+"!"),RandPhraseSimple("Idź do diabła!","Heh, to będą ostatnie sekundy twojego życia..."));
				link.l1.go = NPCharRepPhrase("exit_setOwner", "fight");
				break;
			}
			dialog.text = NPCStringReactionRepeat("Tutaj, to ja rządzę, więc nawet nie myśl o zabraniu czegokolwiek ze sobą...","Zachowuj się przyzwoicie i pamiętaj, że mam na ciebie oko.","Dopóki nie zerkasz do skrzyń, możesz tu zostać. I tak mi jest nudno samemu...",RandPhraseSimple("O mój Boże, tak się nudzę!","Cholera, co tu zrobić? Bycie tutaj jest takie nudne!"),"block",3,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("W porządku, nie martw się.","Pewnie!","Widzę...","Tak, to brzmi jak problem.",npchar,Dialog.CurrentNode);	
			link.l1.go = DialogGoNodeRepeat("exit", "exit", "exit", "exit", npchar, Dialog.CurrentNode);				
			//открывание двери верфи по квесту промышленного шпионажа
			if (CheckAttribute(pchar, "questTemp.different.ShipyardsMap") && pchar.questTemp.different.ShipyardsMap == "toTarget" && npchar.city == pchar.questTemp.different.ShipyardsMap.city && locations[reload_cur_location_index].type == "shipyard")
			{
				link.l2 = "Słuchaj, kumplu, chcę z tobą otwarcie porozmawiać.";
				link.l2.go = "ShipyardsMap_1";
				pchar.questTemp.different.ShipyardsMap = "toResult";					
			}
			// ugeen --> склад товаров для ГГ				
			if(CheckAttribute(NPChar,"Storage"))
			{
				if(!CheckAttribute(NPChar, "Storage.Speak"))
				{
					dialog.text = "Mam kuszącą ofertę dla ciebie. Być może, mogłoby cię to zainteresować.";
					link.l7 = "Naprawdę? Dobrze, słucham.";
					link.l7.go = "storage_rent";
				}
				else
				{
					if(CheckAttribute(NPChar,"Storage.Activate"))
					{
						link.l7 = "Zabierz mnie do magazynu. Chcę zobaczyć, w jakim jest stanie.";
						link.l7.go = "storage_0";
						link.l8 = "Zdecydowałem się opuścić magazyn. Nie potrzebuję go już więcej.";
						link.l8.go = "storage_04";
					}
					else
					{
						if(!CheckAttribute(NPChar,"Storage.NoActivate"))
						{
							link.l7 = "Wspomniałeś o magazynie. Czy nadal jest wolny?";
							link.l7.go = "storage_01";
						}						
					}
				}		
			// <-- ugeen
			}		
		break;
		
		//--------------------------------- Аренда склада ---------------------------------
		case "storage_rent":
			NPChar.Storage.Speak = true;
			dialog.text = "Mamy obszar odpowiedni na magazyn. Chciałbyś wynająć go za rozsądną cenę? Tylko pomyśl, miałbyś swój własny magazyn do przechowywania cennego ładunku...";
			link.l1 = "Magazyn, mówisz? Tak, kuszące, rzeczywiście... Czy jest wystarczająco duży? I ile wyniesie czynsz?";
			link.l1.go = "storage_rent1";
		break;
		
		case "storage_rent1":
			NPChar.MoneyForStorage = GetStoragePriceExt(NPChar, pchar); 
			dialog.text = "To dość przestronne nawet na magazyn portowy, może pomieścić, zobaczmy... 50000 cetnarów ładunku. Dla "+FindRussianMoneyString(sti(NPChar.MoneyForStorage))+"  za miesiąc mogę zapewnić bezpieczne przechowywanie twoich towarów. "+"To obejmuje ochronę za pomocą moich ludzi, ochronę przed zamoczeniem, walkę z szczurami. Co ty na to? O, i dyskrecja też, to jest oczywiste.";
			link.l1 = "Zrobię to. Mogę na to spojrzeć?";	
			link.l1.go = "storage_rent2";
			link.l2 = "To za dużo. I założę się, że jest zatopione i zaroiło się tam od szczurów.";
			link.l2.go = "storage_rent3";		
		break;
		
		case "storage_rent2":
			dialog.text = "Pewnie, pewnie. Ale... potrzebuję zapłaty za miesiąc z góry. ";
			if(sti(pchar.money) >= sti(NPChar.MoneyForStorage))
			{
				link.l1 = "Jesteś... dość kupiecki, muszę powiedzieć. Oto twoje pieniądze ... Wynajmę ten szopa.";
				link.l1.go = "storage_11";
			}
			else
			{	
				link.l1 = "Jesteś ... całkiem handlowy, muszę powiedzieć. Dobrze, przyniosę pieniądze.";
				link.l1.go = "exit";
			}	
		break;
		
		case "storage_rent3":
			dialog.text = "Jak sobie życzysz. Jeśli zmienisz zdanie, daj mi znać. I pamiętaj, że tak ładny magazyn raczej nie pozostanie długo pusty...";
			link.l1 = "Nie ma problemu. Dam ci znać, jeśli będę tego potrzebował.";
			link.l1.go = "exit";
		break;
		
		case "storage_0":
			NPChar.MoneyForStorage = GetNpcQuestPastMonthParam(NPChar, "Storage.Date") * sti(NPChar.Storage.MoneyForStorage); 
			if(sti(NPChar.MoneyForStorage) > 0) 
			{
				dialog.text = "I za czynsz, nadal mi jesteś winien  "+FindRussianMoneyString(sti(NPChar.MoneyForStorage))+".";
				if(sti(pchar.money) >= sti(NPChar.MoneyForStorage))
				{
					link.l1 = "Dobrze, teraz zapłacę za wynajem.";
					link.l1.go = "storage_3";
				}
				else
				{
					link.l1 = "Wrócę później.";
					link.l1.go = "exit";
				}
			}		
			else
			{ // лесник . если забыл с собой корабль то никак.
				ok = (rColony.from_sea == "") || (Pchar.location.from_sea == rColony.from_sea);
		        if (sti(Pchar.Ship.Type) != SHIP_NOTUSED && ok)
				{	
				dialog.text = "Proszę, kontynuuj.";
				link.l1 = "Dzięki.";
				link.l1.go = "storage_2";
				}
				else
				{
                dialog.text = RandPhraseSimple("Kapitanie, gdzie jest twój statek? Jak zamierzasz przewozić ładunek?","Nie widzę twojego statku przy nabrzeżu. Jak dokładnie zamierzasz go załadować?");
                link.l1 = RandPhraseSimple("Och.. Totalnie o tym zapomniałem!","Cholera, to prawda!");
			    link.l1.go = "exit";
				break;
                }			
			}
			link.l2 = "Nie, zmieniłem zdanie.";
			link.l2.go = "exit"; 						
		break;
		
		case "storage_01":
			dialog.text = "Nie, "+GetSexPhrase("panie","pani")+", nadal wolne i czeka na ciebie. Wiedziałem, że w końcu nie odrzucisz mojej oferty.";
			link.l1 = "Bardzo dobrze. Wynajmę to.";
			link.l1.go = "storage_1";
			link.l2 = "Nie, to właśnie przyszło mi do głowy...";
			link.l2.go = "exit";
		break;
		
		case "storage_1":
			NPChar.MoneyForStorage = GetStoragePriceExt(NPChar, pchar); 
			dialog.text = "Jak powinieneś pamiętać, potrzebuję miesięcznej zapłaty z góry.";
			if(sti(pchar.money) >= sti(NPChar.MoneyForStorage))
			{
				link.l1 = "Oczywiście, pamiętam. Proszę bardzo.";
				link.l1.go = "storage_11";
			}
			else
			{
				link.l1 = "Cholera. Dobrze, przyniosę pieniądze.";
				link.l1.go = "exit";
			}
		break;
		
		case "storage_11":
			AddMoneyToCharacter(pchar, -makeint(NPChar.MoneyForStorage)); 
			NPChar.Storage.MoneyForStorage = NPChar.MoneyForStorage;
			NPChar.Storage.Activate = true;
			Achievment_Set("ach_67"); // ugeen 2016
			SaveCurrentNpcQuestDateParam(NPChar, "Storage.Date");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			LaunchStorage(sti(rColony.StoreNum));			
		break;
				
		case "storage_2":			
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			LaunchStorage(sti(rColony.StoreNum));			
		break;
		
		case "storage_3":			
			AddMoneyToCharacter(pchar, -sti(NPChar.MoneyForStorage)); 
			NPChar.MoneyForStorage = GetStoragePriceExt(NPChar, pchar);
			NPChar.Storage.MoneyForStorage = NPChar.MoneyForStorage;
			SaveCurrentNpcQuestDateParam(NPChar, "Storage.Date");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			LaunchStorage(sti(rColony.StoreNum));			
		break;		

		case "storage_04":
			dialog.text = "Już odchodzisz? Jaka szkoda, to naprawdę doskonałe miejsce na świetnych warunkach. Zapewniam cię, że nie dostaniesz takiej oferty nigdzie na Karaibach.";
			link.l1 = "Powiedziałem, że go opuszczam. Czy proponujesz mi płacić za przechowywanie powietrza? Możesz szukać innego posiadacza.";
			link.l1.go = "storage_4";
			link.l2 = "Nigdzie na Karaibach, mówisz? Dobrze, zatrzymam go na jakiś czas. Ale muszę powiedzieć, że czynsz jest trochę za wysoki.";
			link.l2.go = "exit";
		break;
		
		case "storage_4":
			NPChar.MoneyForStorage = GetNpcQuestPastMonthParam(NPChar,"Storage.Date") * sti(NPChar.Storage.MoneyForStorage); 
			if(sti(NPChar.MoneyForStorage) > 0) 			
			{
				dialog.text = "A co do czynszu, nadal mi jesteś winien "+FindRussianMoneyString(sti(NPChar.MoneyForStorage))+".";
				if(sti(pchar.money) >= sti(NPChar.MoneyForStorage))			
				{
					link.l1 = "Dobrze.";
					link.l1.go = "storage_5";
				}
			}
			else
			{ // лесник . если нет корабля то и товар не забрать
				ok = (rColony.from_sea == "") || (Pchar.location.from_sea == rColony.from_sea);
		        if (sti(Pchar.Ship.Type) != SHIP_NOTUSED && ok)
				{	
				dialog.text = "Zbierz swoje towary, a ja zamknę magazyn.";
				link.l1 = "Dobrze.";
				link.l1.go = "storage_6";
				}
				else
				{
                dialog.text = RandPhraseSimple("Kapitanie, gdzie jest twój statek? Jak zamierzasz przewozić ładunek?","Nie widzę twojego statku w porcie. Jak dokładnie zamierzasz go załadować?");
                link.l1 = RandPhraseSimple("Och.. całkiem o tym zapomniałem!","Cholera, to prawda!");
			    link.l1.go = "exit";
				break;
                }				
			}
		break;
		
		case "storage_5":
			SetStorageGoodsToShip(&stores[sti(rColony.StoreNum)]);
			AddMoneyToCharacter(pchar, -sti(NPChar.MoneyForStorage)); 
			NPChar.Storage.NoActivate = true;
			DeleteAttribute(NPChar,"Storage.Activate");
			DialogExit();
		break;
		
		case "storage_6":
			SetStorageGoodsToShip(&stores[sti(rColony.StoreNum)]);
			DeleteAttribute(NPChar,"Storage.Activate");
			NPChar.Storage.NoActivate = true;
			DialogExit();
		break;		

		//--------------------------------- Аренда склада ---------------------------------
		
		case "ShipyardsMap_1":
			dialog.text = "Heh! Dobrze, porozmawiajmy.";
			link.l1 = "Muszę dostać się do stoczni w nocy, kiedy nikogo nie ma w pobliżu.";
			link.l1.go = "ShipyardsMap_2";
		break;
		case "ShipyardsMap_2":
			if (sti(pchar.questTemp.different.ShipyardsMap.skladFight))
			{
				dialog.text = "Spójrz na siebie! Hej, strażnicy, mamy tu złodzieja!!!";
				link.l1 = "Jaki złodziej? Chciałem tylko porozmawiać!";
				link.l1.go = "fight";
				AddCharacterExpToSkill(pchar, "FencingL", 5);
				AddCharacterExpToSkill(pchar, "FencingS", 5);
				AddCharacterExpToSkill(pchar, "FencingH", 5);
				ChangeCharacterComplexReputation(pchar,"nobility", -1);
			}
			else
			{
				dialog.text = "Oho! Spójrz na ciebie, "+GetSexPhrase("kumpel","dziewczyno")+". Przyjść do magazynu stoczni z takim żądaniem!";
				link.l1 = "Muszę dostać się do samej stoczni. Twoje magazyny mogą mi być obojętne.";
				link.l1.go = "ShipyardsMap_3";
				AddCharacterExpToSkill(pchar, "Fortune", 10);
			}
		break;
		case "ShipyardsMap_3":
			dialog.text = "Ale po co ci to jest potrzebne?";
			link.l1 = "Jest potrzeba. I jestem gotów za to zapłacić...";
			link.l1.go = "ShipyardsMap_4";
		break;
		case "ShipyardsMap_4":
			dialog.text = "Hmm, to lepiej... Dobrze! Podaj mi "+FindRussianMoneyString(sti(pchar.questTemp.different.ShipyardsMap.sklad)*1000)+", a ja zostawię otwarte drzwi do stoczni następnego dnia.";
			link.l1 = "To zbyt drogie. Będę musiał sobie bez tego poradzić, w takim razie...";
			link.l1.go = "exit";
			if (sti(pchar.money) >= (sti(pchar.questTemp.different.ShipyardsMap.sklad)*1000))
			{
				link.l2 = "Dobrze, zgadzam się. Weź swoje pieniądze i zrób jak się umówiliśmy.";
				link.l2.go = "ShipyardsMap_5";
			}
		break;
		case "ShipyardsMap_5":
			dialog.text = "Nie martw się, to zostanie zrobione.";
			link.l1 = "Mam nadzieję...";
			link.l1.go = "exit";
			AddMoneyToCharacter(pchar, -sti(pchar.questTemp.different.ShipyardsMap.sklad)*1000);
			AddQuestRecord("ShipyardsMap", "5");
			AddQuestUserData("ShipyardsMap", "sCity", XI_ConvertString("Colony" + npchar.city + "Gen"));
			//снимаем close_for_night
			string  sName;
			int location_index = FindLocation(npchar.city + "_town");
    		makearef(arRld, Locations[location_index].reload);
    		Qty = GetAttributesNum(arRld);
    		for (int a=0; a<Qty; a++)
    		{
    			arDis = GetAttributeN(arRld, a);
				sName = arDis.go;
    			if (findsubstr(sName, "_shipyard" , 0) != -1)
    			{
					DeleteAttribute(arDis, "close_for_night");
					break;
    			}
    		}
			LocatorReloadEnterDisable(npchar.city + "_shipyard", "reload2", true);
			//ставим таймер на возврат close_for_night
			SetTimerFunction("ShipyardsMap_returnCFN", 0, 0, 2);
		break;

	}
}
