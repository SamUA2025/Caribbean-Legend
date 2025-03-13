void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, Diag;
	int i;
	string sGroup;
	bool bOk, bOk1;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);
	int iTemp = sti(npchar.EncQty);
	string sTemp = "Gang" + locations[FindLocation(npchar.location)].index + "_";

	switch(Dialog.CurrentNode)
	{
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();			
		break;

		case "exit_Robbed":
			int iMoney = makeint(makeint(Pchar.money)/20)*10;
			AddMoneyToCharacter(pchar, -iMoney);
			AddSimpleRumour(LinkRandPhrase("Have you heard? The local robber " + GetFullName(npchar) + " found a new victim. One captain got scared and bought off. They say, he gave him " + FindRussianMoneyString(iMoney) + ", he-he... ", 
				"Yeah, captain " + GetFullName(pchar) + ", I already heard that you had to pay " + FindRussianMoneyString(iMoney) + ", to buy off a local bandit, " + GetFullName(npchar) + ". Now that's what I call bad luck! Ha-ha-ha!", 
				"Have you heard that the local bandits attacked one captain? He was totally robbed, he lost " + FindRussianMoneyString(iMoney) + "!"), sti(npchar.nation), 5, 1);
			for(i = 0; i < iTemp; i++)
			{
				sld = CharacterFromID(sTemp + i);
				sld.LifeDay = 0;
				LAi_SetWarriorTypeNoGroup(sld);
				sld.Dialog.CurrentNode = "OnceAgain";
				LAi_SetCheckMinHP(sld, LAi_GetCharacterHP(sld)-1, true, "LandEnc_RaidersBeforeDialog");
			}
			DialogExit();			
		break;

		case "exit_fight":
			sGroup = "RaidersGroup_" + locations[FindLocation(npchar.location)].index;
			for(i = 0; i < iTemp; i++)
			{
				sld = CharacterFromID(sTemp + i);
				LAi_SetWarriorTypeNoGroup(sld);
				LAi_group_MoveCharacter(sld, sGroup);
				LAi_RemoveCheckMinHP(sld);
				LAi_SetImmortal(sld, false);
			}
			LAi_group_SetRelation(sGroup, LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups(sGroup, LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck(sGroup, "LandEnc_RaidersAfrer");
			DialogExit();	
			AddDialogExitQuest("MainHeroFightModeOn");
		break;

		case "exit_RunFight":
			AddSimpleRumour(LinkRandPhrase(RandPhraseSimple("Have you heard? That bandit " + GetFullName(npchar) + " has finally found justice. He and his boys tried to rob "+ GetSexPhrase("some captain, but he turned out to be","some lady captain, but she turned out to be") +" a tough nut. So our dear robber shited his pants, ha-ha! That will be a lesson for him! Robbing the local farmers is one thing, but a brave captain is a different story!", 
				"Thank you, captain " + GetFullName(pchar) + ", for finally dealing with the gang of that bandit " + GetFullName(npchar) + ". Those rascals were really a pain in everyone's ass. We were scared to even send couriers to the farm for milk, they could have intercepted them and rob of all the money."), 
				"Have you heard, "+ GetSexPhrase("finally, some captain","finally, some lady captain") +" stopped that rascal " + GetFullName(npchar) + ", who was in 'charge' of the jungle, terrorizing all the local farmers. I do hope, it will stop them from their dirty deeds for long enough...", 
				"Have you heard that local bandit " + GetFullName(npchar) + " and his boys attempted to rob "+ GetSexPhrase("some captain","some lady captain") +"? Bah! Nothing of the sort! That captain turned out to be a tough nut. They say, he chased on these robbers over all the jungle like a shark chases flock of sardines. Thank God that there are still people who can stand up for us at time when the authorities do nothing, too busy with their dark deeds..."), sti(npchar.nation), 5, 1);
			for(i = 0; i < iTemp; i++)
			{
				sld = CharacterFromID(sTemp + i);
				LAi_type_actor_Reset(sld);
				LAi_ActorAfraid(sld, Pchar, true);
				sld.Dialog.CurrentNode = "GetTheHellOut";
			}
			DialogExit();
		break;

		case "exit_noFight":
			for(i = 0; i < iTemp; i++)
			{
				sld = CharacterFromID(sTemp + i);
				sld.LifeDay = 0;
				LAi_SetWarriorTypeNoGroup(sld);
				sld.Dialog.CurrentNode = "GetLost";
				LAi_SetCheckMinHP(sld, LAi_GetCharacterHP(sld)-1, true, "LandEnc_RaidersBeforeDialog");
			}		
			DialogExit();			
		break;

		case "First Time":
			for(i = 0; i < iTemp; i++)
			{
				sld = CharacterFromID(sTemp + i);
				LAi_type_actor_Reset(sld);
				LAi_RemoveCheckMinHP(sld);
				LAi_SetImmortal(sld, false);
			}
			dialog.text = LinkRandPhrase(LinkRandPhrase("Stań tam, gdzie jesteś i upuść broń! Twoje pieniądze albo twoje życie!","Stój tam, gdzie jesteś, "+GetSexPhrase("podróżnik","dziewczyno")+"!) Nie dotykaj swojej broni i żadnych gwałtownych ruchów!","Stój tam, gdzie jesteś, "+GetSexPhrase("podróżnik","dziewczyna")+"! To jest droga płatna. Jeśli chcesz przejść, płacisz myto."),LinkRandPhrase("Hej, "+GetSexPhrase("kumpel","dziewczyno")+"! Nie tak szybko! Chcę zobaczyć, jak ciężka jest twoja sakiewka.","Czy mógłbyś podejść bliżej, przyjacielu. Chcę usłyszeć brzęk złota w twoim sakiewce.","Zaczekaj, "+GetSexPhrase("kumpel","dziewczyno")+". Ja i moi kumple założyliśmy się, ile złota zmieści się w twoim portfelu. Musimy to teraz sprawdzić, zanim sytuacja stanie się brutalna."),"Nie śpiesz się, "+GetSexPhrase("podróżnik","kochanie")+"! Porozmawiajmy szczerze, dobrze?");				
			Link.l1 = LinkRandPhrase(LinkRandPhrase("Dlaczego wygadujesz te bzdury?","Co u ciebie słychać?","O czym ty mówisz?"),"Co masz na myśli?","Co właściwie sugerujesz?");
			Link.l1.go = "Node_2";
			Link.l2 = LinkRandPhrase(LinkRandPhrase("Rozbójnicy?! Świetnie, tęskniłem za walką!","O, wy jesteście bandytami! Ukrywacie się przed sprawiedliwością, tak? Cóż, wygląda na to, że sprawiedliwość właśnie przyszła po was...","Czy nikt ci nie nauczył, że przeszkadzanie obcym swoimi nonsensami to przejaw złych manier? Wygląda na to, że muszę cię tej lekcji nauczyć..."),LinkRandPhrase("Och, jesteś bezczelny, czyż nie?! Mam nadzieję, że twój miecz jest tak ostry jak twój język.","Widzę, że jesteś mistrzem swojego języka, mam nadzieję, że jesteś też mistrzem swojego miecza.","Oh, bandyci! Tylu z was powieszono, ale wciąż nie możecie przestać iść prosto na szubienicę."),LinkRandPhrase(RandPhraseSimple("O, bandyci! Wiesz, zazwyczaj nie marnuję słów na twojego rodzaju!","Co za bezczelny jegomość! Śmierdzi jak parująca gówniana góra i nadal ośmiela się zwracać do porządnego "+GetSexPhrase("gość","dziewczyna")+"."),"Nie będę marnować na ciebie słów, ale zobaczysz, że mój pistolet jest bardzo wymowny!","Znowu bandyci! Cóż, nie obiecuję ci szubienicy, ale na pewno mogę zrobić ci kilka dziur w brzuchu!"));
			Link.l2.go = "CheckSkills";	
			Link.l3 = LinkRandPhrase("A czy wiesz, że patrolująca grupa śledzi mnie blisko? Wystarczy, że zapiszczę i ty jesteś skończony.",RandPhraseSimple("Wiesz, mogę wezwać patrol, czyżbyś się tego nie bał? Są niedaleko. Przypuszczam, że szukają właśnie ciebie.","Patrol został niedawno wysłany, aby cię znaleźć, i będą tu za chwilę. Podejmujesz wielkie ryzyko."),RandPhraseSimple("Radziłbym ci uciekać jak najszybciej. Patrole idą w tym kierunku, właśnie rozmawiałem z ich oficerem.","Chętnie bym kontynuował naszą rozmowę, ale obawiam się, że patrol, na który właśnie natknąłem się, nie pozwoli naszej znajomości przerodzić się w bliską przyjaźń."));
			Link.l3.go = "Node_3";
		break;
		
		case "Node_2":
			dialog.text = LinkRandPhrase(LinkRandPhrase("Nie udawaj głupka! Gotówka na miejscu i może wtedy cię wypuszczę!","Czy nie słyszałeś o wędrownym opłacie? Jeśli nie rozstaniesz się ze swoim złotem, rozstaniesz się z głową!","Heh, ta zwyczajna przygoda będzie cię kosztować sakiewkę... jeśli się nie zezłocę."),RandPhraseSimple("To bardzo proste. Oddajesz nam całe swoje złoto, a potem możesz swobodnie odejść, albo zostajesz tutaj, a my i tak zabieramy całe twoje złoto. Ale myślę, że to drugie ci się nie spodoba, he-he.","Nie udawaj, że nie rozumiesz! Daj mi swój sakiewkę, jeśli nie chcesz, żebym zabrał go z twojego martwego ciała!"),"Wyjaśnię, jeśli jesteś takim tępakiem. Dasz mi wszystkie swoje pieniądze, jeśli cenisz swoje życie.");
			Link.l1 = "Cholera, łotr! Mam tylko "+makeint(makeint(Pchar.money)/20)*10+" pesos.";
			Link.l1.go = "CheckMoney";
			Link.l2 = LinkRandPhrase(LinkRandPhrase("Chcesz moje pieniądze? Przyjdź i weź je, a zobaczę, ile jesteś wart!","Jak śmiesz, chamie! Nauczę cię dobrych manier!","Jakie samozaparcie! No dobrze, zobaczymy, jak sobie poradzisz przeciwko prawdziwemu "+GetSexPhrase("morski wilk","Wilczyca mórz")+"!"),LinkRandPhrase("Powinieneś być chłostany za takie oburzenie!","Wy łotry! Módlcie się do swoich diabłów o ciepłe miejsce w piekle!","Dawno temu powinniście zostali powieszeni, szubrawcy! Cóż, wygląda na to, że będę musiał poplamić mój szablę waszą krwią!"),RandPhraseSimple("A co cię skłoniło myśleć, że dam ci moje pieniądze?","A czy nie zauważyłeś, że jestem dobrze uzbrojony i nie przyszedłem tutaj na prosty spacer?"));
			Link.l2.go = "CheckSkills";	
		break;

		case "Node_3":
			bOk = makeint(pchar.reputation.nobility) < 11 || makeint(pchar.reputation.nobility) > 90;  
			if(bOk || GetSummonSkillFromName(pchar, SKILL_LEADERSHIP) == 100 || CheckCharacterPerk(pchar, "Trustworthy") || CheckCharacterPerk(pchar, "SeaDogProfessional"))
			{
				dialog.text = RandPhraseSimple("Cholera! Dobrze, możesz iść. Ale nawet nie myśl o robieniu hałasu, kiedy tu jesteś!","Tym razem ci się poszczęściło, ale następnym razem będziesz nam dłużny dwukrotnie więcej! Nie zapomnij nas przypomnieć, he-he.");
				Link.l1 = RandPhraseSimple("Ależ oczywiście.","Uciekaj już, póki jeszcze możesz.");
				Link.l1.go = "Exit_NoFight";
			}
			else
			{
				bOk = makeint(pchar.reputation.nobility) < 51 && makeint(pchar.reputation.nobility) > 41; // Captain Beltrop, 23.01.21 - жесть!!! Надо было всего лишь убрать единичку!
				if(!bOk || GetSummonSkillFromName(pchar, SKILL_LEADERSHIP) < 35)
				{
					dialog.text = RandPhraseSimple("Zabijemy cię cicho, nawet nie pisniesz.","Cholera! Będziemy musieli cię szybko zabić, zanim podniesiesz alarm.");
					Link.l1 = "Cóż, to jest twój pogrzeb. Przestrzegałem cię.";
					Link.l1.go = "Exit_Fight";
				}
				else
				{
					dialog.text = RandPhraseSimple("I dlaczego miałbym się przejmować twoją patrolą? Ja im płacę. Więc daj mi swój portfel i przestań gadać.","Myślisz, że mnie przestraszysz? Sam jestem 'patrolem' dla takich jak ty w tej dżungli. Nikt jeszcze nie wyszedł bez opłaty!");
					Link.l1 = "Cholera, łotr! Mam tylko "+makeint(makeint(Pchar.money)/20)*10+" pesos.";
					Link.l1.go = "CheckMoney";	
					Link.l2 = RandPhraseSimple(LinkRandPhrase("He-h, nie zamierzam przestrzegać poleceń od takiego słabeusza jak ty.","Zrobię ci kilka nowych dziur w czaszce z powodu takiej bezczelności! Tylko aby trochę przewietrzyć twój mózg.","Taka bezczelność nie zostanie bez kary!"),"Nie powinieneś tego robić...");
					Link.l2.go = "CheckSkills";
				}
			}
		break;
		
		case "CheckSkills":
		    bool isStrong = (GetCharacterSkillToOld(Pchar, "FencingL") >= 7) || (GetCharacterSkillToOld(Pchar, "FencingS") >= 7) || (GetCharacterSkillToOld(Pchar, "FencingH") >= 7);
			bool z_ok = (isStrong) && (makeint(Pchar.Rank) >= 8) && (Makeint(PChar.reputation.nobility) <= 30); // Captain Beltrop & mitrokosta, 23.01.21 проверяем на оружие (новый вариант)
			if (z_ok || CheckCharacterPerk(pchar, "SeaDogProfessional"))
			{
				Diag.TempNode = "GetLost";
				dialog.text = LinkRandPhrase(RandPhraseSimple("Hej, nie denerwuj się tak, "+GetSexPhrase("kumpel","dziewczyno")+"! To był tylko żart! Możesz kontynuować swoją drogę!","Dobrze, zmieniłem zdanie. Możesz iść, jeśli jesteś tak groźny."),"Co, a "+GetSexPhrase("'dzielny kapitan'","'wojownicza dziewczyna'")+"? znowu? Dobrze, idź w pokoju...","Relaks, "+GetSexPhrase("kumpel","dziewczyno")+". Widzisz, myliśmy się, "+GetSexPhrase("myśleliśmy, że jesteś kupcem","myśleliśmy, że jesteś kupcem")+". Możesz iść.");
				Link.l1 = LinkRandPhrase(LinkRandPhrase("Dobrze, do zobaczenia!","Powinieneś przestać okradać ludzi, póki jeszcze możesz.","Dobrze, ale jeśli kiedykolwiek cię znowu zobaczę..."),RandPhraseSimple("Następnym razem zwracaj uwagę, komu grozisz, szczeniaku.","Dzięki Bogu, że dzisiaj jestem w dobrym humorze."),RandPhraseSimple("Ten kryminalny handel na pewno cię w końcu zabije. Żegnaj.","To mądra decyzja. No cóż, powodzenia!"));
				Link.l1.go = "Exit_NoFight";
				Link.l99 = LinkRandPhrase("Nie, kumpel. Teraz nauczę cię dobrych manier!","O, przestraszyłeś się? Cóż, powinno się odpowiadać za swoje czyny, prawda?","Nie! Teraz nie uspokoję się, dopóki nie obdzieję cię ze skóry na żywo!");
				Link.l99.go = "GetTheHellOut";
			}
			else 
			{
				dialog.text = LinkRandPhrase("I mógłbyś odejść w pokoju! Teraz możesz tylko obwiniać siebie!","Nie powinieneś tego zaczynać, łotrze! Teraz zginiesz jak pies!","Och, dobrze! Porwę cię na kawałki! Wytnę wątrobę i nakarmię psy!");
				Link.l1 = RandPhraseSimple("Zatłukę twoje słowa z powrotem w twoje gardło!","Komu grozisz, łotrzyku?!");
				Link.l1.go = "Exit_Fight";
			}
		break;

		case "CheckMoney":
			if(makeint(makeint(Pchar.money)/20)*10 >= makeint(Pchar.rank)*100)
			{
				Diag.TempNode = "OnceAgain";
				dialog.text = LinkRandPhrase(RandPhraseSimple("Dobrze! Daj mi to i znikaj!","Nie wiele, ale zawsze lepiej niż nic. Dobrze jest mieć do czynienia z mądrą osobą! Możesz iść."),"To już inna historia! Jak mówił mój przyjaciel 'zawsze dobrze jest słuchać mądrego człowieka, ale rozmowa z głupcem jest o wiele lepsza'! He-he!","W zamian za twoje złoto dam ci radę, nie powinieneś chodzić po dżungli, jeśli jesteś "+GetSexPhrase("taki tchórz. Pij swoje rum w tawernie, aby ty i twój portfel pozostali bezpieczni!","dziewczyna. Bycie okradzionym to nie najgorsze, co mogło ci się przytrafić.")+".");
				Link.l1 = "Przeklęty ty!";
				Link.l1.go = "Exit_Robbed";				
			}
			else
			{
				dialog.text = "Zgaduję, że próbujesz mnie oszukać! Bez obaw, pogłaskam cię moim nożem, może coś spadnie.";
				Link.l1 = "Cholera!";
				Link.l1.go = "Exit_Fight";				
			}				
		break;

		case "OnceAgain":
			Diag.TempNode = "OnceAgain";
			dialog.text = LinkRandPhrase("Ty znowu? Biegnij do swojej mamy, zanim się na ciebie zgniewam!","Co? Jeszcze nie dałeś mi całego swojego złota? Ha-ha!","Spójrz, "+GetSexPhrase("kumpel","dziewczyno")+", Mam dość ciebie! Znikaj mi z oczu, póki jeszcze żyjesz!");
			Link.l1 = "Tak, już odchodzę.";
			Link.l1.go = "Exit";
			Link.l2 = "Myślałem, że to nie byłoby sprawiedliwe. Dlatego postanowiłem naprawić rzeczy...";
			Link.l2.go = "Exit_Fight";
		break;
				
		case "GetLost":
			Diag.TempNode = "GetLost";
			dialog.text = LinkRandPhrase("Co jeszcze potrzebujesz? Już zgodziliśmy się, że odchodzisz!","Zostaw mnie w spokoju, "+GetSexPhrase("przyjacielu","dziewczyno")+". Zajmuję się swoimi sprawami, a ty swoimi i nie powinniśmy próbować dogadywać się!","Opuść teraz, "+GetSexPhrase("kumplu","dziewczyna")+"! Do cholery, naprawdę jesteś gotów oddać całe swoje pieniądze?");
			Link.l1 = "Tak, już wychodzę.";
			Link.l1.go = "Exit";
			Link.l2 = "Przypomniałem sobie, że nie pożegnałeś się! Więc pożegnajmy się jak należy...";
			Link.l2.go = "Exit_Fight";
		break;

		case "GetTheHellOut":
			Diag.TempNode = "GetTheHellOut";
			dialog.text = LinkRandPhrase("Zostaw mnie! Pomóż mi! Chcę żyć!","Pomóż mi! "+GetSexPhrase("On jest maniakiem","Ona jest maniaczka")+"! Nie zabijaj mnie!","Oszczędź mnie! Jestem tylko skromnym bandytą! Jestem zbyt młody, aby umierać!");
			Link.l1 = LinkRandPhrase(LinkRandPhrase("Gdybyś został w domu, nadal byś żył!","Powinieneś był o tym pomyśleć wcześniej!","Powinieneś wiedzieć, że zawsze są konsekwencje!"),"Wcześniej czy później, to musiało się wydarzyć.","Za późno na pokutę, teraz walcz, szumowino!");
			Link.l1.go = "exit_Fight";			
		break; 				
	}
}
