#include "DIALOGS\%language%\Rumours\Common_rumours.c"  //homo 25/06/06
#include "interface\ship.c"
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
    // вызов диалога по городам -->
    NPChar.FileDialog2 = "DIALOGS\" + LanguageGetLanguage() + "\Tavern\" + NPChar.City + "_Tavern.c";
    if (LoadSegment(NPChar.FileDialog2))
	{
        ProcessCommonDialog(NPChar, Link, NextDiag);
		UnloadSegment(NPChar.FileDialog2);
	}
    // вызов диалога по городам <--
	ProcessCommonDialogRumors(NPChar, Link, NextDiag);//homo 25/06/06
	
	int iTest, iTemp;
	string sTemp;
	string NPCCity = NPChar.City;
    iTest = FindColony(NPChar.City); // город 
    ref rColony;
	if (iTest != -1)
	{
		rColony = GetColonyByIndex(iTest);
	}
	bool ok;
	
	if(!CheckAttribute(pchar, "questTemp.TavernVisit."+(NPCCity) )) 
	{
		pchar.questTemp.TavernVisit.(NPCCity) = true;
		pchar.questTemp.TavernVisit.counter = sti(pchar.questTemp.TavernVisit.counter) + 1;
	}	
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			NextDiag.TempNode = "First time";
			if (LAi_grp_playeralarm > 0)
			{
       			dialog.text = NPCharRepPhrase(pchar,LinkRandPhrase("Podniesiono alarm w mieście, a wszyscy szukają ciebie. Gdybym był tobą, nie zostawałbym tutaj.","Wszyscy strażnicy miasta przeczesują miasto, szukając ciebie. Nie jestem głupcem i nie zamierzam z tobą rozmawiać!","Uciekaj, "+GetSexPhrase("kumpel","dziewczyno")+", zanim żołnierze zmienią cię w mielone mięso..."),LinkRandPhrase("Czego potrzebujesz, "+GetSexPhrase("łotr","smród")+"?! Strażnicy miejski mają twój zapach, nie uciekniesz daleko"+GetSexPhrase(", brudny piracie!","")+"","Morderca, natychmiast opuść mój lokal! Strażnicy!","Nie boję się ciebie, "+GetSexPhrase("łotr","szczur")+"! Wkrótce zostaniesz powieszony w naszym forcie, daleko nie uciekniesz..."));
				link.l1 = NPCharRepPhrase(pchar,RandPhraseSimple("Heh, alarm to dla mnie nigdy nie problem...","Oni nigdy mnie nie złapią."),RandPhraseSimple("Zamknij swoją gębę, "+GetWorkTypeOfMan(npchar,"")+", albo wyrwę ci język!","Heh, "+GetWorkTypeOfMan(npchar,"")+", a wszystko tam - aby złapać piratów! To ci mówię, kumplu: siedź cicho i nie umrzesz..."));
				link.l1.go = "exit";
				break;
			}
			if (sti(pchar.GenQuest.Piratekill) > 20 && sti(npchar.nation) == PIRATE)
			{
				dialog.text = RandPhraseSimple("I to ty, łajdaku! Myślisz, że tu dla ciebie rum lejemy? Ależ skąd! Chłopcy! Do broni! Zabijcie tego łotra!","Chcesz drinka, piracie? Ha! Nie! Teraz pokażemy ci, co i jak! Chłopcy, do broni!");
				link.l1 = RandPhraseSimple("He? Co?","Stop!");
				link.l1.go = "fight";
				bDisableFastReload = true;//закрыть переход
				pchar.quest.pirate_in_town.win_condition.l1 = "ExitFromLocation";
				pchar.quest.pirate_in_town.win_condition.l1.location = pchar.location;
				pchar.quest.pirate_in_town.function = "TownPirate_battle";
				break;
			}
			//Jason, Бремя гасконца
			if(NPChar.City == "FortFrance")
			{
				if (!CheckAttribute(npchar, "quest.Rum") && CheckAttribute(pchar, "questTemp.Sharlie.Lock") && pchar.questTemp.Sharlie == "ship" && makeint(environment.time) > 5.0 && makeint(environment.time) < 19.0)
				{
					link.l1 = "Panowie, szukam pracy. Macie jakieś zajęcia?";
					link.l1.go = "Sharlie_rum";
					break;
				}
				if (CheckAttribute(pchar, "questTemp.Sharlie.Rum") && pchar.questTemp.Sharlie.Rum == "regard")
				{
					link.l1 = "Wykonalem twoje zadanie. Długi łódź z rumem została dostarczona do zatoki Le Francois i przekazana twoim ludziom.";
					link.l1.go = "Sharlie_rum_5";
					break;
				}
			}
			if (CheckAttribute(pchar, "questTemp.Sharlie") && pchar.questTemp.Sharlie == "crew" && npchar.city == "FortFrance")
			{
				DelLandQuestMark(npchar);
				dialog.text = "Czy chciał pan coś, panie?";
				Link.l1 = "Witaj karczmarzu, potrzebuję załogi do mojego statku. Czy możesz mi w tym pomóc?";
				Link.l1.go = "Sharlie_crew";
				break;
			}
			
			if (CheckAttribute(pchar, "questTemp.Sharlie") && pchar.questTemp.Sharlie == "skiper" && npchar.city == "FortFrance")
			{
				DelLandQuestMark(npchar);
				dialog.text = "Witaj ponownie. Co tym razem, panie?";
				Link.l1 = ""+npchar.name+", Zdaję sobie sprawę, że przeszkadzam ci, ale tylko jeszcze jedno pytanie. Potrzebuję nawigatora - masz jakieś pomysły, gdzie mogę go znaleźć?";
				Link.l1.go = "Sharlie_skiper";
				break;
			}
			if (CheckAttribute(pchar, "questTemp.Sharlie.Lock"))
			{
    			dialog.text = "Co pan sobie życzy, monsieur?";
				Link.l1 = "Miałem nadzieję, że mógłbyś odpowiedzieć na kilka pytań.";
				Link.l1.go = "quests";
				if(!CheckAttribute(pchar,"questTemp.TimeLock"))
				{
					link.l2 = "Chciałbym wynająć pokój.";
					link.l2.go = "room";
				}
				break;
			}			
			//Бремя гасконца
			// Addon 2016-1 Jason пиратская линейка
			if (CheckAttribute(pchar, "questTemp.Mtraxx.Retribution") && pchar.questTemp.Mtraxx.Retribution == "tavern" && npchar.city == "Tortuga")
			{
				dialog.text = "Cieszę się, że cię widzę, panie! Jak mogę służyć? Rum, brandy, szkocka whisky?";
				Link.l1 = "Chciałbym butelkę waszego najlepszego francuskiego wina i klucz do pokoju.";
				Link.l1.go = "mtraxx_tortuga";
				break;
			}
			if (CheckAttribute(pchar, "questTemp.Mtraxx.Retribution") && pchar.questTemp.Mtraxx.Retribution == "room" && npchar.city == "Tortuga")
			{
				dialog.text = "Już zapłaciłeś panie, twój pokój jest na górze.";
				Link.l1 = "Dzięki.";
				Link.l1.go = "exit";
				break;
			}
			
			// Sinistra - Квест "Длинные тени старых грехов" ==>	
			if (CheckAttribute(pchar, "questTemp.DTSG_BasTerTavern") && npchar.city == "BasTer")
			{
				dialog.text = "Jak mogę służyć, Kapitanie? Pewnie chcesz się napić po tym, co się stało.";
				Link.l1 = "To może poczekać. Właściwie chciałbym omówić, co się stało.";
				Link.l1.go = "DTSG_BasTerTavern_1";
				DelLandQuestMark(npchar);
				break;
			}
			// <== Квест "Длинные тени старых грехов" - Sinistra
			
			if(NPChar.quest.meeting == "0")
			{
				dialog.Text = GetNatPhrase(npchar,LinkRandPhrase("Witaj w mojej skromnej karczmie '"+XI_ConvertString(NPChar.City+"TavernName")+"', panie. Cieszę się, że cię widzę.","Do usług, panie! W naszej karczmie '"+XI_ConvertString(NPChar.City+"TavernName")+"' zawsze cieszymy się z powitania nowych gości.","Pierwszy raz tutaj, panie? Nie wahaj się, tutaj w '"+XI_ConvertString(NPChar.City+"TavernName")+"' zawsze czujesz się jak w domu!"),LinkRandPhrase("Wejdź, panie kapitanie. Nie rozpoznaję cię, więc to musi być twoje pierwsze spotkanie w '"+XI_ConvertString(NPChar.City+"NazwaTawerny")+"'.'","Nigdy wcześniej cię nie spotkałem, panie. Poznajmy się: Jestem "+GetFullName(npchar)+", gospodarz 'a'"+XI_ConvertString(NPChar.City+"TavernName")+"'.'","Cieszę się, że mogę powitać naszego nowego gościa, Kapitanie Monsieur! W mojej tawernie '"+XI_ConvertString(NPChar.City+"TavernName")+"' pierwszy drink zawsze na koszt domu! Jestem właścicielem tego miejsca, "+GetFullName(npchar)+", witaj."),LinkRandPhrase("Señor Kapitanie! Witamy w tawernie '"+XI_ConvertString(NPChar.City+"NazwaKarczmy")+"'!","Oh, jaki błyszczący hidalgo odwiedził naszą tawernę '"+XI_ConvertString(NPChar.City+"Nazwa Karczmy")+"'! Czy to jest tu pan pierwszy raz?","Dzień dobry, panie! Jestem "+GetFullName(npchar)+", skromny właściciel '"+XI_ConvertString(NPChar.City+"NazwaKarczmy")+"', jesteśmy zadowoleni, że możemy cię tu powitać!"),LinkRandPhrase("Witaj, panie kapitanie. Jestem właścicielem karczmy '"+XI_ConvertString(NPChar.City+"NazwaKarczmy")+"'. Pierwszy raz z nami?","Dzień dobry, panie. Witamy w tawernie '"+XI_ConvertString(NPChar.City+"TavernName")+"'.'","Bardzo dobrze widzieć ciebie, mójneer kapitanie! Nasza własna karczma '"+XI_ConvertString(NPChar.City+"TavernName")+"' wita cię! Rum, wino, a może bym cię skusił, mamy tu nowy, psotny mały holenderski spirytus zwany ginem?"));
				Link.l1 = LinkRandPhrase("Przytulne miejsce tu masz... Pozwól, że się przedstawię - "+GetFullName(pchar)+", miło cię poznać.",""+GetFullName(pchar)+", miło cię spotkać. Więc, co możesz mi zaoferować?","Mam na imię "+GetFullName(pchar)+" a ja jestem nowy w tym porcie. Powiedz mi, z czego ta karczma jest najbardziej znana?");
				Link.l1.go = "meeting";
				NPChar.quest.meeting = "1";
				if(startHeroType == 4 && NPChar.location == "SantaCatalina_tavern")
				{
					dialog.text = "Hej, Rumba! Wróciłeś z podróży, czy wyruszasz w nową?";
					link.l1 = "Witaj, "+npchar.name+". Po prostu postanowiłem wpasc.";
					Link.l1.go = "Helen_meeting";
					NPChar.quest.meeting = "1";
					break;
				}
				NPChar.quest.meeting = "1";
			}
			else
			{
				// Квестовый генератор священника. Квест №1. Warship -->
				if(CheckAttribute(PChar, "GenQuest.ChurchQuest_1.NeedToDialogWithBarmen") && PChar.location == PChar.GenQuest.ChurchQuest_1.CurPortManColony + "_tavern")
		        {
		            if(CheckAttribute(PChar, "GenQuest.ChurchQuest_1.NoMoneyToBarmen"))
		            {
		            	iTemp = sti(PChar.GenQuest.ChurchQuest_1.MoneyToBarmen);
		            	dialog.Text = "No więc, kapitanie, przyniosłeś mi "+FindRussianMoneyString(iTemp)+".";
		            	if(sti(PChar.Money) >= iTemp)
		            	{
							link.l1 = "Tak, mam. Oto one...";
							link.l1.go = "Tavern_ChurchGenQuest1_Node_4_1";
						}
						else
						{
							link.l1 = "Nie, jeszcze nie...";
							link.l1.go = "exit";
						}
		            }
		            else
		            {
		            	dialog.Text = "Co byś chciał, dobry mój "+GetSexPhrase("panie","pani")+"?";
						link.l1 = "Butelka rumu dla mojego kumpla przy tamtym stole.";
						link.l1.go = "Tavern_ChurchGenQuest1_Node_1";
					}
					break;
				}
				// <-- Квестовый генератор священника. Квест №1.
				dialog.Text = pcharrepphrase(LinkRandPhrase(LinkRandPhrase("Oh, szanowni goście! Hej, ty - przesuń się i zrób miejsce dla dzielnego kapitana! I szybko, zanim cię wyrzucę, haha!","Litościwy Bóg nad nami! Jeśli to nie jest "+GetFullName(pchar)+"! Właśnie dostałem nową dostawę najwyborzystszych win, proszę wejdź!","Oh, "+GetAddress_Form(NPChar)+", masz jakieś kłopoty? Pozwolisz, że cię poczęstuję? Ta butelka jest za darmo. Ufaj mi, to najlepsze wino w okolicy..."),LinkRandPhrase("Oh, to Kapitan "+GetFullName(pchar)+"! Hej, ty! Okazuj szacunek dobremu kapitanowi! To nie jest stodoła! Przepraszam cię, kapitanie, ich matki najwyraźniej nie nauczyły ich manier.","Cóż, cóż, "+GetAddress_Form(NPChar)+" "+GetFullName(pchar)+"! Czeka nas długa noc, haha! Dziewczyny, lepiej miejcie na sobie swoje najlepsze sukienki!","Dobry wieczór, "+GetFullName(pchar)+", Cieszę się, że cię widzę! Proszę pana, mam prośbę. Właśnie kupiłem nowe stoły, więc proszę, dziś wieczorem bez walk."),LinkRandPhrase("Witaj, kapitanie. Czuj się jak u siebie w domu, ale pamiętaj, że nawet sam Kapitan Sharp zachowuje maniery w moim lokalu.","O-ho-ho! Kto tu jest? To "+GetFullName(pchar)+" sam w sobie! A my właśnie zaczynaliśmy się nudzić bez ciebie! Co powiesz na to, abyś rozbawił chłopaków przygodą, podczas gdy ja otworzę nową beczkę rumu, kapitanie?","O-ho-ho! To "+GetFullName(pchar)+" sam! Mam nadzieję, że nie zamierzasz znów zabierać moich klientów na otwarte morze opowieściami o swoich wielkich przygodach?")),LinkRandPhrase(LinkRandPhrase(""+GetFullName(pchar)+"! Ten stary soliak zawsze cieszy się na twój widok w swoim przybytku! Proszę panie, usiądź, a dziewczyny się tobą zajmą!","Proszę kapitanie, rozgość się! Zawsze cieszę się, kiedy mogę przywitać mego ulubionego gościa. Co podać?","Cieszę się, że znowu cię widzę, "+GetFullName(pchar)+"! Chciałbyś stolik dla siebie? Czy wolisz usiąść przy barze?"),LinkRandPhrase("Dzień dobry, kapitanie. W powietrzu czuć chłód, pozwól, że zaproponuję Ci doskonałe grzane wino, które właśnie zrobiłem, na koszt firmy!","Witaj, kapitanie "+GetFullName(pchar)+"! Cieszę się, że znów przyszedłeś w odwiedziny. Co byś chciał?","Cieszę się, że cię mam, "+GetAddress_Form(NPChar)+" "+GetFullName(pchar)+"! Cieszę się, że odwiedzasz mój skromny lokal! Robimy wszystko, co w naszej mocy, aby zadowolić."),LinkRandPhrase("Kapitanie! Witamy, witamy! Mam dla Ciebie coś wyjątkowego, d'Anjou godne samego Króla Ludwika! Specjalnie dla Ciebie zachowałem!",""+GetFullName(pchar)+"! Jak miło, że przyszedłeś. Czy mam przegonić wszystkie te morskie szczury, czy wolisz, żeby zostały? Wierz mi, z przyjemnością opróżniłbym dla ciebie całą tawernę!","Mój Boże, oto Kapitan "+GetFullName(pchar)+"! Hej, zalotnicy - przynieście najlepszą serwetę na stół kapitana!")));
				Link.l1 = pcharrepphrase(RandPhraseSimple(RandPhraseSimple("O, widzę, że tutaj mnie pamiętają... Do diabła, napełnij mój kielich kumplu, podczas gdy rozejrzę się dookoła...","Uspokój się, kumplu, dzisiaj jestem w dobrym humorze. Zacznijmy od rumu, co ty na to?..."),RandPhraseSimple("Oho... nie jesteś zbyt zadowolony, że jestem tutaj? Mam nadzieję, że źle cię usłyszałem, ha!","Ahoj. Mam nadzieję, że twoje wino jest lepsze niż twoje powitanie? Inaczej mogę się zezłościć, wiesz...")),RandPhraseSimple(RandPhraseSimple("Zawsze chętnie odwiedzam cię, kumplu. Co masz, żeby rozgrzać starych wilków morskich?","Ahoy kumplu, twoja knajpa staje się lepsza z każdym dniem! Odwiedzanie tutaj to zawsze przyjemność..."),RandPhraseSimple("Nie zapomniałeś o starym wędrowcu? Jestem zaszczycony, kolego.","Dobrze znowu widzieć starego przyjaciela... Czy jeszcze został ci jakiś rum?")));
				Link.l1.go = "step_node";
			}
			break;
				
			case "step_node":
				dialog.Text = LinkRandPhrase("Słucham, kapitanie.","Moja karczma '"+XI_ConvertString(NPChar.City+"TavernName")+"' do usług, Kapitanie!","Wszystko słyszę, Kapitanie! Czego dziś sobie życzysz?");
				Link.l1 = "Czy na wyspie są chłopcy gotowi spróbować swojego szczęścia na morzu?";
				Link.l1.go = "crew hire";
				Link.l2 = "Miałem nadzieję, że mógłbyś odpowiedzieć na kilka pytań.";
				Link.l2.go = "int_quests";
				if (CheckAttribute(pchar, "GenQuest.LoanChest.TakeChest") && sti(pchar.GenQuest.LoanChest.TargetIdx) == sti(NPChar.index))
				{
					link.l21 = "Chciałbym porozmawiać o sprawach finansowych.";
					link.l21.go = "LoanForAll";//(перессылка в кредитный генератор)
				}
				
				// Квестовый генератор священника. Квест №2. Warship -->
				if(CheckAttribute(PChar, "GenQuest.ChurchQuest_2.AskBarmen") && PChar.location == PChar.GenQuest.ChurchQuest_2.QuestTown + "_tavern")
		            	{
					link.l10 = LinkRandPhrase("Czy możesz mi coś powiedzieć o ostatnim rabunku w kościele?","Co wiesz o niedawnym rabunku w kościele?","Słyszałeś coś o niedawnym rabunku w kościele?");
					link.l10.go = "Tavern_GenQuest_Church_2_1";
				}
				// <-- Квестовый генератор священника. Квест №2.
				
				//Jason --> генератор Неудачливый вор
				if (CheckAttribute(pchar, "GenQuest.Device.Shipyarder") && NPChar.location == pchar.GenQuest.Device.Shipyarder.City + "_tavern" && pchar.GenQuest.Device.Shipyarder == "begin" && !CheckAttribute(npchar, "quest.Device"))
				{
					link.l16 = "Ludzie mówią, że wiesz prawie wszystko o tej kolonii. Chcę kupić "+pchar.GenQuest.Device.Shipyarder.Type+", a mi powiedziano, że to było sprzedawane w waszym mieście. Cóż, ktoś to sprzedawał na rynku. Czy możesz mi coś o tym powiedzieć?";
					link.l16.go = "Device_Tavern";
				}
				// <-- генератор Неудачливый вор
			
				//Jason --> генератор Место под солнцем
				if (CheckAttribute(pchar, "GenQuest.Sunplace.Trader") && pchar.GenQuest.Sunplace.Trader == "continue" && NPChar.location == pchar.GenQuest.Sunplace.Trader.CityT + "_tavern")
				{
					link.l17 = "Szukasz szwindlera o imieniu "+pchar.GenQuest.Sunplace.Trader.Enemyname+". Gdzie mogę go znaleźć?";
					link.l17.go = "Sunplace_Tavern";
				}
				// <-- генератор Место под солнцем
			
				// --> Голландский гамбит
				if (CheckAttribute(pchar, "questTemp.HWIC.Holl") && pchar.questTemp.HWIC.Holl == "JacobOnMain" && NPChar.location == pchar.questTemp.HWIC.Holl.JacobCity + "_tavern")
				{
					link.l18 = "Witaj, "+npchar.name+". Muszę znaleźć Jacoba van Berga - gdzie on jest? Nie widzę go w twojej karczmie...";
					link.l18.go = "HWICHollJacob_Tavern";
				}
				if (CheckAttribute(pchar, "questTemp.HWIC.Self") && pchar.questTemp.HWIC.Self == "start" && NPChar.nation == SPAIN && !CheckAttribute(npchar, "quest.HWICTalked"))
				{
					link.l18 = "Witaj, "+npchar.name+". Szukam kawalera o imieniu Fernando Rodriguez. Czy pokazał się w twoim mieście?";
					link.l18.go = "HWICSelfFernando_Tavern";
				}
				// <-- Голландский гамбит
			
				//Jason --> гонки на гидропланах
				if (CheckAttribute(pchar, "GenQuest.Racing.Go.Advantage") && NPChar.location == pchar.GenQuest.Racing.Go.StartCity + "_tavern")
				{
					link.l19 = "Przyszedłem odebrać moje wygrane, które bezpiecznie przechowywałeś u siebie."+npchar.name+".";
					link.l19.go = "Race_Advantage";
				}
				// <-- гонки на гидропланах
			
				//Jason --> захват пассажиров
				if (CheckAttribute(pchar, "GenQuest.Marginpassenger") && pchar.GenQuest.Marginpassenger == "take" && NPChar.location == pchar.GenQuest.Marginpassenger.Targetcity+"_tavern")
				{
					link.l20 = "Zastanawiałem się, gdzie mogę znaleźć człowieka o imieniu "+pchar.GenQuest.Marginpassenger.q2Name+"? Mieszka w twoim mieście.";
					link.l20.go = "Marginpassenger";
				}
				// <-- захват пассажиров
				if(!CheckAttribute(pchar,"questTemp.TimeLock"))
				{
					link.l3 = pcharrepphrase("Masz wolny pokój, kumplu?","Czy masz wolny pokój, chciałbym tu zostać na jakiś czas.");
					link.l3.go = "room";
				}
				Link.l4 = "Niestety, już odchodzę, "+NPChar.name+". Do zobaczenia.";
				Link.l4.go = "exit";
		break;
		
		case "Helen_meeting":
			dialog.Text = "Ach, no wejdź, wejdź. Zawsze jesteś tu mile widziany.";
			link.l1 = "Tak, dziękuję. Dobrze było cię zobaczyć. Do widzenia.";
			link.l1.go = "exit";
			Link.l2 = "Mogłabym użyć kilka nowych rąk. Tylko upewnij się, że są zdolni, dobrze?";
			Link.l2.go = "crew hire";
			link.l3 = "Chciałbym odpocząć na solidnym gruncie i zebrać myśli, nie gdy moja matka hasa po domu.";
			link.l3.go = "Helen_room";
			Link.l4 = "Mogę zadać ci pytanie? ";
			Link.l4.go = "quests";
			link.l5 = " Mam z tobą sprawę do omówienia, "+NPChar.name+".";
			link.l5.go = "Helen_rumours_tavern";
		break;
		
		case "Meeting":
			// Квестовый генератор священника. Квест №1. Warship -->
			if(CheckAttribute(PChar, "GenQuest.ChurchQuest_1.NeedToDialogWithBarmen") && PChar.location == PChar.GenQuest.ChurchQuest_1.CurPortManColony + "_tavern")
	        {
	            dialog.Text = "Czego sobie życzysz, łaskawy "+GetSexPhrase("panie","pani")+"?";
				link.l1 = "Butelka rumu dla mojego kompana przy tamtym stole.";
				link.l1.go = "Tavern_ChurchGenQuest1_Node_1";
				break;
			}
			// <-- Квестовый генератор священника. Квест №1.
			dialog.Text = LinkRandPhrase("Słucham, kapitanie.","Co mogę ci zaoferować, kapitanie?","Więc kapitanie, co podać?");
			Link.l1 = "Potrzebuję załogi, "+NPChar.name+".";
			Link.l1.go = "crew hire";
			Link.l2 = NPChar.name+", porozmawiajmy...";
			Link.l2.go = "int_quests";
			if (CheckAttribute(pchar, "GenQuest.LoanChest.TakeChest") && sti(pchar.GenQuest.LoanChest.TargetIdx) == sti(NPChar.index))
			{
				link.l21 = "Chciałbym porozmawiać o sprawach finansowych.";
				link.l21.go = "LoanForAll";//(перессылка в кредитный генератор)
			}
			// Квестовый генератор священника. Квест №2. Warship -->
			if(CheckAttribute(PChar, "GenQuest.ChurchQuest_2.AskBarmen") && PChar.location == PChar.GenQuest.ChurchQuest_2.QuestTown + "_tavern")
	        {
				link.l10 = LinkRandPhrase("Czy możesz mi coś powiedzieć o niedawnym rabunku w kościele?","Co wiesz o niedawnym rabunku w kościele?","Słyszałeś coś o niedawnym rabunku w kościele?");
				link.l10.go = "Tavern_GenQuest_Church_2_1";
			}
			// <-- Квестовый генератор священника. Квест №2.
			
			//Jason --> генератор Неудачливый вор
			if (CheckAttribute(pchar, "GenQuest.Device.Shipyarder") && NPChar.location == pchar.GenQuest.Device.Shipyarder.City + "_tavern" && pchar.GenQuest.Device.Shipyarder == "begin" && !CheckAttribute(npchar, "quest.Device"))
			{
   				link.l16 = "Ludzie mówią, że wiesz prawie wszystko o tej kolonii. Chcę kupić "+pchar.GenQuest.Device.Shipyarder.Type+", a mi powiedziano, że sprzedawano to w waszym mieście. No cóż, ktoś to sprzedawał na ulicach. Możesz mi o tym coś powiedzieć?";
				link.l16.go = "Device_Tavern";
			}
			// <-- генератор Неудачливый вор
			
			//Jason --> генератор Место под солнцем
			if (CheckAttribute(pchar, "GenQuest.Sunplace.Trader") && pchar.GenQuest.Sunplace.Trader == "continue" && NPChar.location == pchar.GenQuest.Sunplace.Trader.CityT + "_tavern")
			{
   				link.l17 = "Opowiedz mi o szwindlerze o imieniu "+pchar.GenQuest.Sunplace.Trader.Enemyname+". Gdzie mogę go znaleźć?";
				link.l17.go = "Sunplace_Tavern";
			}
			// <-- генератор Место под солнцем
			
			//--> Голландский гамбит
			if (CheckAttribute(pchar, "questTemp.HWIC.Holl") && pchar.questTemp.HWIC.Holl == "JacobOnMain" && NPChar.location == pchar.questTemp.HWIC.Holl.JacobCity + "_tavern")
				{
					link.l18 = "Witaj, "+npchar.name+". Muszę znaleźć Jacoba van Berga - gdzie on jest? Nie widzę go w twojej tawernie...";
					link.l18.go = "HWICHollJacob_Tavern";
				}
				if (CheckAttribute(pchar, "questTemp.HWIC.Self") && pchar.questTemp.HWIC.Self == "start" && NPChar.nation == SPAIN && !CheckAttribute(npchar, "quest.HWICTalked"))
				{
					link.l18 = "Cześć, "+npchar.name+". Szukam kawalera o imieniu Fernando Rodriguez. Czy pokazał się w waszym mieście?";
					link.l18.go = "HWICSelfFernando_Tavern";
				}
				//<-- Голландский гамбит
				
				//Jason --> гонки на гидропланах
				if (CheckAttribute(pchar, "GenQuest.Racing.Go.Advantage") && NPChar.location == pchar.GenQuest.Racing.Go.StartCity + "_tavern")
				{
					link.l19 = "Przyszedłem odebrać moje wygrane, które są u ciebie bezpieczne."+npchar.name+".";
					link.l19.go = "Race_Advantage";
				}
				// <-- гонки на гидропланах
				//Jason --> захват пассажиров
				if (CheckAttribute(pchar, "GenQuest.Marginpassenger") && pchar.GenQuest.Marginpassenger == "take" && NPChar.location == pchar.GenQuest.Marginpassenger.Targetcity+"_tavern")
				{
					link.l20 = "Zastanawiałem się, gdzie mogę znaleźć człowieka o imieniu "+pchar.GenQuest.Marginpassenger.q2Name+"? On mieszka w twoim mieście.";
					link.l20.go = "Marginpassenger";
				}
				// <-- захват пассажиров
			if(!CheckAttribute(pchar,"questTemp.TimeLock"))
			{
				link.l3 = pcharrepphrase("Masz wolny pokój, kolego?","Czy masz wolny pokój, chciałbym tu zostać na jakiś czas.");
				link.l3.go = "room";
			}
			Link.l4 = "Chyba wrócę później.";
			Link.l4.go = "exit";
		break;
		
		case "crew hire":
			ok = (rColony.from_sea == "") || (Pchar.location.from_sea == rColony.from_sea);
			ok = sti(Pchar.Ship.Type) != SHIP_NOTUSED && ok;
			
			if (!ok)
			{
				Dialog.text = "A co by ci marynarze byli potrzebni, kapitanie? Nie widzę twojego statku w porcie.";
				link.l1 = RandPhraseSimple("Dokładnie... Zawinąłem w złe miejsce.","Zapomniałem wejść do portu...");
				link.l1.go = "exit";
				break;
			}
			
            if (makeint(environment.time) > 22.0 || makeint(environment.time) < 7.0)
			{
				Dialog.text = "Zwykle jest wielu mężczyzn chętnych do zostania marynarzami, ale teraz jest za późno - zaczną pojawiać się rano. Może chciałbyś wynająć pokój i na nich poczekać?";
				link.l1 = "W porządku. Czy masz wolne pokoje?";
				link.l1.go = "room";
				link.l2 = "Nie jestem teraz zainteresowany pokojem. Do zobaczenia.";
				link.l2.go = "exit";
			}
			else
			{
                if (GetNationRelation2MainCharacter(sti(NPChar.nation)) == RELATION_ENEMY && sti(NPChar.nation) != PIRATE)
                {
                    Dialog.text = "Myślisz, że obsługujemy tu poszukiwanych przestępców? Bądź wdzięczny, że nie wołam straży.";
					link.l1 = "Dzięki.";
					link.l1.go = "exit";
                }
                else
                {
					if (CheckAttribute(NPChar, "CrewHired.PGGId") && GetNpcQuestPastDayParam(NPChar, "CrewHired") < 3 && GetCrewQuantity(rColony) == 0)
					{
						Dialog.text = "Ach, przepraszam kapitanie, jesteś tylko trochę za późno. Wszyscy chłopcy, którzy chcieli coś powiedzieć, właśnie wypłynęli z dzielnym kapitanem "+GetFullName(CharacterFromID(NPChar.CrewHired.PGGId))+".";
						link.l1 = "To szkoda!";
						link.l1.go = "exit_crew";
					}
					else
					{						
						if(bPartitionSet)
						{		
							if(GetPartitionAmount("CrewPayment") > 0)
							{
								if(IsEquipCharacterByArtefact(pchar, "totem_07"))
								{
									DeleteAttribute(NPChar, "CrewHired"); //на всяк случай.
									NextDiag.CurrentNode =  NextDiag.TempNode;
									DialogExit();
									LaunchHireCrew();							
								}
								else
								{
									dialog.text = "Kapitanie, ludzie mówią, że jesteś całkiem skąpy. Nie mamy tu nikogo, kto chciałby dołączyć do twojej załogi.";
									link.l1 = "Widzę...";
									link.l1.go = "exit";
								}
							}
							else
							{
								DeleteAttribute(NPChar, "CrewHired"); //на всяк случай.
								NextDiag.CurrentNode =  NextDiag.TempNode;
								DialogExit();
								LaunchHireCrew();	
							}
						}	
						else
						{
							DeleteAttribute(NPChar, "CrewHired"); //на всяк случай.
							NextDiag.CurrentNode =  NextDiag.TempNode;
							DialogExit();
							LaunchHireCrew();							
						}						
					}
				}
			}
		break;
		
		case "exit_crew" :
			DeleteAttribute(NPChar, "CrewHired"); //на всяк случай.
			NextDiag.CurrentNode =  NextDiag.TempNode;
			DialogExit();
			LaunchHireCrew();
		break;
	////////////////////////////////////////////////////////=============================================///////////////////////////////////////////////////////	
        case "int_quests":
			dialog.text = "Jestem cały uchem.";
			//link.l1 = "Szukam pracy. Możesz mi pomóc?";
			//link.l1.go = "work";
			//homo 15/06/06 слухи
			link.l2 = LinkRandPhrase("Czy możesz mi powiedzieć najnowsze wiadomości?","Co się dzieje w tych stronach?","Co nowego na lądzie?");
			link.l2.go = "rumours_tavern";
			//homo
			link.l3 = "Przyszedłem w innej sprawie.";
			link.l3.go = "quests";
			if(CheckAttribute(pchar,"GenQuest.EncGirl"))
			{
				if(pchar.GenQuest.EncGirl == "EncGirlFack_fighted")
				{
					link.l5 = "Czy wiesz, gdzie mogę znaleźć "+pchar.GenQuest.EncGirl.name+"?";
					link.l5.go = "EncGirl_1";
				}	
				if(pchar.GenQuest.EncGirl == "toParents" || pchar.GenQuest.EncGirl == "FindLover")
				{
					link.l6 = "Czy mógłbyś mi powiedzieć, gdzie mogę poszukać "+pchar.GenQuest.EncGirl.sLoverId+"?";
					link.l6.go = "EncGirl_3";
				}
				if(pchar.GenQuest.EncGirl == "toLoverFather" && pchar.GenQuest.EncGirl.LoverFather == "tavern_keeper" && pchar.GenQuest.EncGirl.LoverCity == npchar.city)
				{
					link.l7 = "Ahoy, przyszedłem na zaproszenie twojego syna."; 
					link.l7.go = "EncGirl_4";
					pchar.quest.EncGirl_GetLoverFather.over = "yes";
				}
			}
			if(CheckAttribute(pchar,"GenQuest.CaptainComission") && NPChar.city == pchar.GenQuest.CaptainComission.City && CheckAttribute(pchar,"GenQuest.CaptainComission.Speak_Tavern"))
			{
				if(pchar.GenQuest.CaptainComission.variant == "A0")
				{												
					if(pchar.GenQuest.CaptainComission.Speak_Tavern == true)
					{
						link.l9 = "A więc, widziałeś "+pchar.GenQuest.CaptainComission.Name+"?";
						link.l9.go = "CaptainComission_3";
					}
					else
					{
						link.l9 = "Czy możesz mi powiedzieć, gdzie powinienem szukać  "+pchar.GenQuest.CaptainComission.Name+"?";
						link.l9.go = "CaptainComission_1";
					}
				}	

				if(pchar.GenQuest.CaptainComission.variant == "A2" && pchar.GenQuest.CaptainComission == "Begin_1")
				{
					link.l9 = "Czy wiesz, gdzie mogę znaleźć kapitana patrolu "+GetStrSmallRegister(XI_ConvertString(GetBaseShipParamFromType(sti(pchar.GenQuest.CaptainComission.ShipType),"Nazwa")+"Acc"))+" "+pchar.GenQuest.CaptainComission.Name+"?";
					link.l9.go = "CaptainComission_Tavern7";					
				}				
				if(pchar.GenQuest.CaptainComission.variant == "A3" && pchar.GenQuest.CaptainComission == "Begin_1")
				{
					if(pchar.GenQuest.CaptainComission.Speak_Tavern == true)
					{
						link.l9 = "Czy widziałeś "+GetName(NAMETYPE_ORIG,pchar.GenQuest.CaptainComission.CanoneerName,NAME_NOM)+"?";
						link.l9.go = "CaptainComission_3";
					}
					else
					{					
						link.l9 = "Czy wiesz coś o kapitanie patrolu "+GetStrSmallRegister(XI_ConvertString(GetBaseShipParamFromType(sti(pchar.GenQuest.CaptainComission.ShipType),"Imię")+"Acc"))+" "+pchar.GenQuest.CaptainComission.Name+"?";
						link.l9.go = "CaptainComission_Tavern1";
						if(!CheckAttribute(pchar,"GenQuest.CaptainComission.GetRumour"))
						{
							pchar.GenQuest.CaptainComission.GetRumour = true;
							SaveCurrentQuestDateParam("GenQuest.CaptainComission.GetRumour");
						}	
					}	
				}					
			}
			if(CheckAttribute(pchar,"GenQuest.Hold_GenQuest") && NPChar.city == pchar.GenQuest.Hold_GenQuest.City && pchar.GenQuest.Hold_GenQuest.Speak_Tavern == false )
			{
				link.l10 = "Czy mógłbyś mi powiedzieć, gdzie znajdę człowieka o imieniu "+pchar.GenQuest.Hold_GenQuest.Name+"?";
				link.l10.go = "hold_genquest1";
			}
			if (CheckCharacterItem(pchar, "CaptainBook") && CheckAttribute(pchar, "questTemp.different.GiveShipLetters") && !CheckAttribute(pchar, "questTemp.different.GiveShipLetters.speakTavern") && (pchar.questTemp.different.GiveShipLetters.city == npchar.city))
			{
				link.l11 = "Przypadkowo znalazłem niedaleko stąd jakieś dokumenty statku....";
				link.l11.go = "ShipLetters_4";			
			}

			// Jason --> квест губера на поиск дезертира
			if(CheckAttribute(pchar, "GenQuest.FindFugitive") && pchar.GenQuest.FindFugitive != "Late" && sti(NPChar.nation) == PIRATE)
			{
				link.l12 = "Słuchaj, szukam swojego starego przyjaciela, "+pchar.GenQuest.FindFugitive.Name+" to jego imię. Jeden z kapitanów powiedział mi, że zmierza do twojego osiedla. Spotkałeś go może przypadkiem?";
				link.l12.go = "FindFugitiveTav";
			}
			//<-- поиск дезертира

			link.l15 = "Nic, dziękuję, .";
			link.l15.go = "exit";
		break;
		
		case "hold_genquest1":
			switch(sti(pchar.GenQuest.Hold_GenQuest.TavernVariant))
			{
				case 0:
					dialog.text = LinkRandPhrase("Co powiedziałeś?"+pchar.GenQuest.Hold_GenQuest.Name+"? Hmm... Nigdy o nim nie słyszałem.","Czy jesteś pewien, że on pochodzi z naszego miasta? Nigdy nie słyszałem o takiej osobie.","Nie było nikogo takiego w naszej małej kolonii. Nigdy o nim nie słyszałem przez cały mój czas tutaj.");
					link.l1 = "Czy jesteś pewien?";
					link.l1.go = "hold_genquest2";					
				break;
				
				case 1: 
					switch (drand(3))
					{
						case 0:
							pchar.GenQuest.Hold_GenQuest.foundStr = "the church";						
							pchar.GenQuest.Hold_GenQuest.found = "church";
						break;
						case 1:
							if (npchar.city != "Panama")
							{
							pchar.GenQuest.Hold_GenQuest.foundStr = "the shipyard";						
							pchar.GenQuest.Hold_GenQuest.found = "shipyard";
							}
							else
							{
								pchar.GenQuest.Hold_GenQuest.foundStr = "the church";						
								pchar.GenQuest.Hold_GenQuest.found = "church";
							}
						break;
						case 2:
							pchar.GenQuest.Hold_GenQuest.foundStr = "the usurer";												
							pchar.GenQuest.Hold_GenQuest.found = "bank";
						break;
						case 3:
							pchar.GenQuest.Hold_GenQuest.foundStr = "the shop";						
							pchar.GenQuest.Hold_GenQuest.found = "store";
						break;
					} 
					dialog.text = "Sprawdź "+pchar.GenQuest.Hold_GenQuest.foundStr+", często tam można go znaleźć.";
					link.l1 = "Dziękuję, właśnie tak zrobię.";
					link.l1.go = "hold_genquest3";				
				break;
				
				case 2:
					dialog.text = LinkRandPhrase(RandPhraseSimple("Co powiedziałeś?"+pchar.GenQuest.Hold_GenQuest.Name+"? Hmm... Nigdy o nim nie słyszałem. Jesteś pewien, że pochodzi z naszej wsi? Nigdy nie słyszałem o takiej osobie.","He-he... Cóż, teraz tylko Pan Bóg wie, gdzie go szukać - w piekle czy w niebie. Zmarł ponad rok temu, ale ludzie nadal o nim pytają... Nie ma spokoju dla biedaka..."),RandPhraseSimple("Nie znajdziesz go tam - przynajmniej nie wśród żywych. Zmarł nie tak dawno - żółta febra... Niech spoczywa w pokoju... Co to był za twardy mężczyzna! Kiedy był młody, był wielkim poszukiwaczem przygód! Ale kiedy śmierć idzie za tobą, niewiele możesz zrobić...","Och, czy tęsknisz za nim? Dawno opuścił te miejsca. Nikt nie wie, dokąd poszedł - może do kolonii północnoamerykańskich, może wrócił do domu, do Europy. Po prostu zebrał swoje rzeczy i zniknął."),"Oh, czy szukasz tego "+pchar.GenQuest.Hold_GenQuest.Name+" kto się wzbogacił i kupił sobie dom w Nowej Anglii? Wiesz, były czasy, kiedy sprzedałem mu rum na kredyt - on mi jeszcze dłużny. Ludzie są tak niewdzięczni, wiesz.");
					link.l1 = "Rozumiem. Cóż, dzięki i tak.";	
					link.l1.go = "hold_genquest4";
				break;
				
				case 3:
					dialog.text = "Cóż, gdzie indziej go szukać, jeśli nie w karczmie? Często tam bywa - zanurza swoje grzechy w winie, he-he. Wróć za chwilę - jeśli się pojawi, powiem mu, żeby na ciebie poczekał.";	
					link.l1 = "Dziękuję, zrobię to.";
					link.l1.go = "hold_genquest5";
				break;
			}
			pchar.GenQuest.Hold_GenQuest.Speak_Tavern = true;
		break;
		
		case "hold_genquest2":
			dialog.text = "Jak mogę nie być pewien, jeśli znam tutaj wszystkich osobiście. To nie pierwszy rok, kiedy prowadzę tutaj tawernę."+"Widziałem ich wszystkich we wszystkich możliwych stanach. Czasami żona przychodziła odebrać swojego męża, czasem wychodzili sami, a czasami musiałem ich wyrzucić. 'Czy jestem pewien?!' Oczywiście, że tak!";
			link.l1 = "Cóż, dzięki i tak...";	
			link.l1.go = "exit";
			pchar.GenQuest.Hold_GenQuest = "prisoner_escaped";
			AddQuestRecord("HoldQuest", "7");
			AddQuestUserData("HoldQuest", "sName", pchar.GenQuest.Hold_GenQuest.CapName);
			AddDialogExitQuestFunction("Hold_GenQuest_PrisonerEscaped");
		break;
		
		case "hold_genquest3":
			Hold_GenQuest_GenerateChar();		
			AddQuestRecord("HoldQuest", "8");
			AddQuestUserData("HoldQuest", "sCity", XI_ConvertString("Colony" + pchar.GenQuest.Hold_GenQuest.City + "Gen")); 			
			AddQuestUserData("HoldQuest", "sFoundChar", pchar.GenQuest.Hold_GenQuest.foundStr);
			AddQuestUserData("HoldQuest", "sName", pchar.GenQuest.Hold_GenQuest.Name);
			SetFunctionTimerConditionParam("Hold_GenQuest_FindCharTimeIsOver", 0, 0, 1, MakeInt(24 - GetHour()), false);
			DialogExit();
		break;
		
		case "hold_genquest4":
			AddQuestRecord("HoldQuest", "13");
			AddQuestUserData("HoldQuest", "sName", pchar.GenQuest.Hold_GenQuest.CapName);
			AddQuestUserData("HoldQuest", "sNameChar", pchar.GenQuest.Hold_GenQuest.Name);
			AddQuestUserData("HoldQuest", "sSex", GetSexPhrase("",""));
			CloseQuestHeader("HoldQuest");
			DeleteAttribute(pchar,"GenQuest.Hold_GenQuest");			
			DialogExit();
		break;
		
		case "hold_genquest5":
			SetFunctionTimerConditionParam("Hold_GenQuest_GetMapTimeIsOver", 0, 0, 1, MakeInt(24 - GetHour()), false);
			DialogExit();
			AddDialogExitQuestFunction("Hold_GenQuest_GenerateMapChar");			
		break;
		
		case "CaptainComission_1":
			dialog.text = LinkRandPhrase("Często tu bywa, ale teraz go nie ma. Wróć od czasu do czasu - powiem mu, żeby tu na ciebie czekał, jeśli się pojawi.","On często tu bywa. Jeśli wrócisz później, na pewno go tam znajdziesz.","Wróć od czasu do czasu - on często tu zagląda. Powiem mu, że go szukałeś.");
			link.l1 = "Dziękuję, wrócę później...";
			link.l1.go = "CaptainComission_2";
			pchar.GenQuest.CaptainComission.Speak_Tavern = true;
		break;
		
		case "CaptainComission_2":
			pchar.quest.CapComission_ExitFromTavern.win_condition.l1 = "ExitFromLocation";
			pchar.quest.CapComission_ExitFromTavern.win_condition.l1.location = pchar.location;
			pchar.quest.CapComission_ExitFromTavern.function = "CaptainComission_GenerateChar";

			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		case "CaptainComission_3":
			dialog.text = "On już tu przybył, więc powinien być gdzieś w pobliżu...";
			link.l1 = "Dzięki.";
			link.l1.go = "exit";
			DeleteAttribute(pchar,"GenQuest.CaptainComission.Speak_Tavern");
		break;
		
		case "CaptainComission_Tavern1":
			pchar.GenQuest.CaptainComission.Speak_Tavern = true;
			dialog.text = "Czy jest taki człowiek, który go nie zna? Całe osiedle mówi o nim już od kilku dni.";
			link.l1 = "Czy mógłbyś mi więcej opowiedzieć?";
			link.l1.go = "CaptainComission_Tavern2";
		break;
		
		case "CaptainComission_Tavern2":
			dialog.text = "Trochę, kapitan został stracony, to samo można powiedzieć o niektórych członkach jego załogi. Reszta została rozproszona po Karaibach, pozbawiona rangi i stanowiska... Za co? Według sędziego, zatopił pirata podczas patrolu i ukrył dla siebie łup\n"+"Oto rzecz, ani właściciel tego statku, ani towarów nie zostali odnalezieni... przeszukiwali lokalne zatoki i przystanie, ale na próżno.";
			link.l1 = "Co, żaden z załogi nie ujawnił lokalizacji skrytki?";	
			link.l1.go = "CaptainComission_Tavern3";	
		break;
		
		case "CaptainComission_Tavern3":
			dialog.text = "Ani jednego! Nawet pod torturami! Nadal nie mogę zrozumieć, dlaczego gubernator tak ochoczo uwierzył w te oszczerstwa. Kapitanie "+pchar.GenQuest.CaptainComission.Name+" miał dobrą reputację, a jego załoga była dobrze wyszkolona i zdyscyplinowana, że każdy admirał by mu zazdrościł.";
			link.l1 = "A gdzie powinienem szukać ocalałych członków załogi?";
			link.l1.go = "CaptainComission_Tavern4";
		break;
		
		case "CaptainComission_Tavern4":
			dialog.text = "Tego nie wiem - rozproszyli się po czterech wiatrach... Chociaż... jeden z nich nadal jest, ale wątpię, czy dowiesz się od niego wiele. Był mocno wstrząśnięty. Wiesz, służył jako artylerzysta pod "+pchar.GenQuest.CaptainComission.Name+". Znaleziono go nieprzytomnego w zatoce dwa dni po tym wypadku. Najpierw został wysłany do szpitala i traktowany jak bohater, ale kiedy fabuła się zagęszczała, wrzucili go do lochu i próbowali go przesłuchać, ale potem zdecydowali, że najpierw powinien być leczony medycznie, tak czy inaczej.";
			link.l1 = "Czy on jest tu teraz?";
			link.l1.go = "CaptainComission_Tavern5";
		break;
		
		case "CaptainComission_Tavern5":
			pchar.GenQuest.CaptainComission.CanoneerName = "l" + rand(GetNamesCount(NAMETYPE_ORIG) - 1);
			dialog.text = "Tak, "+GetName(NAMETYPE_ORIG,pchar.GenQuest.CaptainComission.CanoneerName,NAME_NOM)+" to jego imię. Przychodzi od czasu do czasu, wydaje grosze, które zarabia na żebractwie, na rum. Biedna dusza. Jeśli go zobaczę, powiem mu, żeby tu na ciebie czekał.";
			link.l1 = "Dziękuję, wrócę później.";
			link.l1.go = "CaptainComission_Tavern6";
		break;
		
		case "CaptainComission_Tavern6":
			AddQuestRecord("CaptainComission2", "39");
			AddQuestUserData("CaptainComission2", "sShipType", GetStrSmallRegister(XI_ConvertString(GetBaseShipParamFromType(sti(pchar.GenQuest.CaptainComission.ShipType),"Name") + "Gen"))); 
			AddQuestUserData("CaptainComission2", "sName", pchar.GenQuest.CaptainComission.Name);
			AddQuestUserData("CaptainComission2", "sCharName", GetName( NAMETYPE_ORIG, pchar.GenQuest.CaptainComission.CanoneerName, NAME_ABL));
			AddQuestUserData("CaptainComission2", "sShipName", pchar.GenQuest.CaptainComission.ShipTypeName);			
			SetFunctionExitFromLocationCondition("CaptainComission_GenerateCanoneer", pchar.location, false);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		case "CaptainComission_Tavern7":
			DeleteAttribute(pchar,"GenQuest.CaptainComission.Speak_Tavern");
			dialog.text = "Czy go znam? Oczywiście, że tak. A po co ci on potrzebny?";
			link.l1 = "Mam z nim interesy...";
			link.l1.go = "CaptainComission_Tavern8";
		break;
		
		case "CaptainComission_Tavern8":
			dialog.text = ""+GetAddress_Form(pchar)+", powinieneś być ostrożny z tym 'biznesem'. "+pchar.GenQuest.CaptainComission.Name+" jest zatrzymany pod zarzutem piractwa, a ludzie gubernatora teraz przeszukują wyspę w poszukiwaniu jego wspólników.";
			link.l1 = "Nie mów! A co on zrobił?";
			link.l1.go = "CaptainComission_Tavern9";
		break;
		
		case "CaptainComission_Tavern9":
			dialog.text = "Nie wiem, czy to prawda, czy nie, ale mówią, że schował konfiskowany ładunek z mijającego pirackiego statku i nie oddał go. I nadal nikt nie znalazł ani tego pirata, ani ładunku. Nadal nie mogę zrozumieć, dlaczego gubernator tak chętnie uwierzył w te oszczerstwa. Kapitanie "+pchar.GenQuest.CaptainComission.CapName+"  miał przyzwoitą reputację, i był wielkim żołnierzem, możesz mi zaufać, "+GetAddress_Form(pchar)+".";
			link.l1 = "No cóż, dzięki za ostrzeżenie. Do zobaczenia.";
			link.l1.go = "CaptainComission_Tavern10";
		break;
		
		case "CaptainComission_Tavern10":
			if(!CheckAttribute(pchar,"GenQuest.CaptainComission.GetRumour"))
			{
				pchar.GenQuest.CaptainComission.GetRumour = true;
				SaveCurrentQuestDateParam("GenQuest.CaptainComission.GetRumour");
				SetFunctionTimerConditionParam("CaptainComission_TimeIsOver", 0, 0, 2, MakeInt(24 - GetHour()), false);
				AddQuestRecord("CaptainComission2", "19");
				AddQuestUserData("CaptainComission2", "sShipType", GetStrSmallRegister(XI_ConvertString(GetBaseShipParamFromType(sti(pchar.GenQuest.CaptainComission.ShipType),"Name") + "Gen"))); // лесник окончание
				AddQuestUserData("CaptainComission2", "sName", pchar.GenQuest.CaptainComission.Name);
			}			
			DialogExit();
		break;
				
		case "EncGirl_1":
			dialog.text = "A po co ci ona potrzebna?";
			link.l1 = "Mam z nią interesy...";
			link.l1.go = "EncGirl_2";
		break;
		
		case "EncGirl_2":
			dialog.text = "Połowa mężczyzn w naszej osadzie zdaje się mieć z nią jakieś interesy. Gdyby nasze kobiety ją złapały, wyrzuciłyby ją za bramy miasta, nagą.";
			link.l1 = "Cóż... "+GetSexPhrase("Wygląda na to, że trafiłem w długą kolejkę. No cóż, jeśli ktoś inny przyjdzie szukać jej, powiedz im, żeby stali za mną w kolejce.","Widzę")+"...";
			link.l1.go = "exit";
			pchar.quest.EncGirl_SpeakTavernKeeper.over = "yes";
			DeleteAttribute(pchar, "GenQuest.EncGirl");
		break;
		
		case "EncGirl_3":
			dialog.text = "On często tu bywa - zazwyczaj przychodzi w poszukiwaniu pracy, ale teraz go tu nie ma. Wróć od czasu do czasu - powiem mu, żeby tu na ciebie poczekał, jeśli się pojawi.";
			link.l1 = "Dziękuję, wrócę później...";
			link.l1.go = "exit";
			pchar.GenQuest.EncGirl = "FindingLover";
			pchar.quest.EncGirl_ExitTavern.win_condition.l1 = "ExitFromLocation";
			pchar.quest.EncGirl_ExitTavern.win_condition.l1.location = pchar.location;
			pchar.quest.EncGirl_ExitTavern.function = "EncGirl_GenerateLover";
		break;
		
		case "EncGirl_4":
			if(sti(pchar.GenQuest.EncGirl.LoverFatherAngry) == 0)
			{
				dialog.text = "Ach, więc to ty jesteś "+GetSexPhrase("ten kapitan, który przyniósł","ta dziewczyna, która przyniosła")+" mój rozrzutny syn z młodą panną młodą?";
				link.l1 = "Tak, to ja pomogłem.";
				link.l1.go = "EncGirl_5";
			}
			else
			{
				dialog.text = "Oh, tam "+GetSexPhrase("on jest, nasz dobroczyńca","ona jest, nasza dobroczyńca")+". Oczekujesz nagrody, rozumiem?";
				link.l1 = "Cóż, jestem w porządku bez nagrody, ale wystarczy mi Twoje podziękowania.";
				link.l1.go = "EncGirl_6";			
			}
		break;
		
		case "EncGirl_5":
			dialog.text = "Bardzo jestem wdzięczny, że nie porzuciłeś mojego syna w trudnej sytuacji i pomogłeś mu znaleźć wyjście z delikatnej sytuacji. Pozwól mi podziękować ci i proszę przyjmij tę skromną sumę i prezent ode mnie osobiście.";
			link.l1 = "Dziękuję. Pomoc młodej parze była moją przyjemnością.";
			link.l1.go = "EncGirl_5_1";
		break;
		
		case "EncGirl_6":
			dialog.text = "Dzięki? Jakie dzięki?! Pół roku ten dureń błąkał się bez pracy - a patrz na niego, ma wystarczająco dużo czasu na romans! Kiedy byłem w jego wieku, już prowadziłem własny biznes! Pfft! Gubernator ma do wydania córkę - a ten idiota przywiózł do mojego domu jakąś dziwkę bez rodziny i ośmielił się prosić o moje błogosławieństwo!";
			link.l1 = "Chyba nie wierzysz w miłość od pierwszego wejrzenia?";
			link.l1.go = "EncGirl_6_1";		
		break;
		
		case "EncGirl_5_1":
			AddMoneyToCharacter(pchar, sti(pchar.GenQuest.EncGirl.sum));
			GiveItem2Character(pchar, pchar.GenQuest.EncGirl.item);
			AddQuestRecord("JungleGirl", "18");
			CloseQuestHeader("JungleGirl");
			DeleteAttribute(pchar, "GenQuest.EncGirl");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		case "EncGirl_6_1":
			dialog.text = "Miłość? Miłość!? Czy ty ze mnie drwisz, czy jesteś głupi? Wstyd ci nie jest pobłażać młodym w ich kaprysach i zachowywać się jak alfons! Nie tylko zabrałeś dziewczynę z jej domu, ale także zrujnowałeś życie mojego chłopca. Nie będzie ci za to dziękować. Żegnaj.";
			link.l1 = "Podobnie i tobie.";
			link.l1.go = "EncGirl_6_2";
		break;
		
		case "EncGirl_6_2":
			ChangeCharacterComplexReputation(pchar,"nobility", -1);
			AddQuestRecord("JungleGirl", "19");
			AddQuestUserData("JungleGirl", "sSex", GetSexPhrase("",""));
			AddQuestUserData("JungleGirl", "sSex1", GetSexPhrase("",""));
			CloseQuestHeader("JungleGirl");
			DeleteAttribute(pchar, "GenQuest.EncGirl");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();		
		break;
				
		case "ShipLetters_4":
			pchar.questTemp.different.GiveShipLetters.speakTavern = true;
			if(sti(pchar.questTemp.different.GiveShipLetters.variant) == 0)
			{
				dialog.text = "Daj mi się przyjrzeć! Hmm... Ale przecież sam jesteś kapitanem. Myślę, że powinieneś porozmawiać o tym z naczelnikiem portu.";
				link.l1 = "Dziękuję za twoją radę.";
				link.l1.go = "exit";
			}
			else
			{
				dialog.text = "Daj mi zobaczyć! O! Sądząc po imieniu, to należy do jednego z moich gości, dość szanowanego pana. Ja sam mogę przekazać te dokumenty właścicielowi. Czy dasz mi je?";
				link.l1 = "Po drugim myśleniu...";
				link.l1.go = "exit";
				link.l2 = "Weź je. Cieszę się, że mogłem służyć pomocą.";
				link.l2.go = "ShipLetters_end";				
			}	
		break;
		
		case "ShipLetters_end":
			TakeItemFromCharacter(pchar, "CaptainBook"); 
			pchar.questTemp.different = "free";
			pchar.quest.GiveShipLetters_null.over = "yes"; //снимаем таймер 
			AddQuestRecord("GiveShipLetters", "3");			
			CloseQuestHeader("GiveShipLetters");
			DeleteAttribute(pchar, "questTemp.different.GiveShipLetters"); 
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		//zagolski. переделка
		case "work":
			if (sti(NPChar.nation) != PIRATE && GetNationRelation2MainCharacter(sti(NPChar.nation)) == RELATION_ENEMY)
			{
				dialog.text = RandPhraseSimple("Nie obchodzi mnie, komu służyć, skoro pieniądze nie mają narodowości. Ale nie pomogę ci, ponieważ przyszedłeś pod flagą "+NationNameGenitive(sti(pchar.nation))+".","Jestem tylko prostym właścicielem karczmy, ale współpraca z "+NationNameAblative(sti(pchar.nation))+" nie wydaje mi się kuszące.");
				link.l1 = RandPhraseSimple("No cóż, jak sobie życzysz...","Cóż, jak wolisz...");
				link.l1.go = "exit";
				break;
			}
			if (isBadReputation(pchar, 40))
			{
				dialog.text = RandPhraseSimple("Zwykle mamy tu wielu pasażerów. Mimo to, nie sądzę, żeby choć jeden z nich zgodził się podróżować na twoim statku. Twoja zła reputacja cię poprzedza, tylko głupiec wszedłby na statek z takim łotrzykiem.","Dość często podchodzą do mnie kupcy, którzy potrzebują eskorty. Ale twoja zła reputacja cię poprzedza, i nie polecę cię nikomu. Dbam o swoją własną reputację, wiesz. Nikt nie chce zatrudniać wilka do strzeżenia swoich owiec.");
				link.l1 = RandPhraseSimple("Oj, naprawdę, nie powinieneś wierzyć we wszystkie te plotki...","Rozumiem. Trudno zmusić wszystkich do zamknięcia się.","Ludzie są dzisiaj po prostu zbyt delikatni...");
				link.l1.go = "exit";
				break;
			}
			if (sti(Pchar.Ship.Type) == SHIP_NOTUSED)
        	{
				dialog.text = "A gdzie jest twój statek? Czy zamierzasz nosić pasażerów na swoich plecach i pływać?";
				link.l1 = "Hej, masz rację...";
				link.l1.go = "exit";
				break;
			}
			dialog.text = "Mogę mieć dla ciebie robotę, jeśli nie boisz się przybywać do pirackich osad czy portów wrogich narodów. Szukasz czegoś konkretnego?";
			link.l1 = "To nie powinno być problemem. Myślę, że mogę zapewnić eskortę.";
			link.l1.go = "work_1";
			link.l2 = "Czy masz jacyś pasażerowie? Mogę ich zabrać, gdziekolwiek chcą, jeśli za to zapłacą.";
			link.l2.go = "work_2";
			link.l3 = "Nie, taka praca nie jest dla mnie. Dzięki.";
			link.l3.go = "exit";
		break;

		case "work_1":
				dialog.text = "Zazwyczaj nie pytają mnie o eskortę. Zapytaj kupców w tawernie - może potrzebują twoich usług.";
				link.l1 = "Dobrze, jak mówisz.";
                link.l1.go = "exit";
		break;

		case "work_2":
			if (!CheckAttribute(npchar, "work_date") || GetNpcQuestPastDayParam(npchar, "work_date") >= 2 || bBettaTestMode)
    		{					
				if (GetSummonSkillFromName(pchar, SKILL_LEADERSHIP) < 5)//при низком авторитете не даем
				{
					dialog.text = "Przykro mi, ale nie mam nikogo, kto chciałby podróżować z tobą.";
					link.l1 = "Widzę.";
					link.l1.go = "exit";
					break;
				}
		         // пассажир
				if (drand(6) > 1)
				{
					dialog.Text = "Jest tu jeden mężczyzna, który właśnie wchodził - niedawno pytał o przechodzący statek. Możesz z nim porozmawiać, jeśli chcesz.";
					link.l1 = RandPhraseSimple("Kim on jest? Może to łajdak? Albo, co gorsza, poszukiwany pirat?","A kim on jest? Czy będą z nim jakieś kłopoty?");
					Link.l1.go = "PassangerAreYouSure";
				}
				else
				{
					dialog.text = "Nie, dzisiaj nikt o tym nie pytał. Może innego dnia.";
					link.l1 = RandPhraseSimple("Cóż, jeśli tego tam nie ma, to nie ma...","Ale pech... No cóż, do zobaczenia, w takim razie.");
					link.l1.go = "exit";
				}
            }
    		else
    		{
				dialog.text = "Dziś nikogo nie ma. Wróć za kilka dni.";
				link.l1 = "Dobrze, jak mówisz.";
                link.l1.go = "exit";
    		}
        break;

        case "ConvoyAreYouSure":
		    dialog.text = LinkRandPhrase("Kto mógłby wiedzieć? Zapytałeś - odpowiedziałem.","Cóż, to dla ciebie do rozwiązania. Nie poręczę za nikogo tam.","Wszystkie sorty tu przychodzą. To jest karczma kapitanie, nie dwór gubernatora.");
			Link.l1 = "Dzięki, więc targujemy się.";
			Link.l1.go = "exit";
			pchar.quest.destination = findTraderCity(npchar);
			pchar.ConvoyQuest.City = npchar.city;
			AddDialogExitQuest("prepare_for_convoy_quest");
			SaveCurrentNpcQuestDateParam(npchar, "work_date");
        break;

        case "PassangerAreYouSure":
		    dialog.text = LinkRandPhrase("Kto mógłby wiedzieć? Pytałeś - odpowiedziałem.","Cóż, to dla ciebie do rozwiązania. Nie ręczyłbym za nikogo tam.","Wszystkie sorty tu przychodzą. To jest tawerna kapitanie, nie dwór gubernatora.");
			Link.l1 = "Rozumiem. Spróbujmy dowiedzieć się, kim jest ten człowiek...";
			Link.l1.go = "exit";
			sGlobalTemp = findPassangerCity(npchar);
			pchar.GenQuest.GetPassenger_City = npchar.city;
			AddDialogExitQuest("prepare_for_passenger_quest");
			SaveCurrentNpcQuestDateParam(npchar, "work_date");
        break;

		 case "fight":
			DialogExit();
            NextDiag.CurrentNode = NextDiag.TempNode;
			LAi_group_Attack(NPChar, Pchar);
		break;

		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		case "Helen_room":
			dialog.text = "Oczywiście, Helen. Jak długo zostajesz? A co, pokłóciłeś się ze starą Gladys?";
			if(!isDay())
			{
				link.l1 = "Tylko po to, aby przespać do rana. Jeśli teraz wrócę do domu, na pewno ją obudzę.";
				link.l1.go = "Helen_room_day";
			}
			else
			{
				link.l1 = "Nie, nie, muszę tylko wypłynąć nocą, a nie chcę jej budzić.";
				link.l1.go = "Helen_room_night";
				link.l2 = "Chcę dobrze, długo spać i nie spieszyć się z wstawaniem. Wezmę pokój na jeden dzień.";
				link.l2.go = "Helen_room_day_next";
			}
		break;

		case "room":
   			if (chrDisableReloadToLocation || CheckAttribute(pchar, "GenQuest.TavernClose")) //кто-то должен подойти к ГГ.
			{
				dialog.text = "Pokój jest zajęty, "+GetAddress_Form(NPChar)+", nie ma nic, co mogę dla ciebie zrobić.";
				link.l1 = "Cóż, to szkoda...";
				link.l1.go = "exit";
				break;
			}
			// суп из черепахи
			if (CheckAttribute(pchar, "questTemp.Terrapin.Room_close") && npchar.location == "Tortuga_tavern")
			{
				dialog.text = "Pan Henri Thibaut wynajmuje obecnie pokój i zapłacił za miesiąc z góry, więc nic nie mogę dla ciebie zrobić, kapitanie.";
				link.l1 = "Cóż, to szkoda...";
				link.l1.go = "exit";
				break;
			}
			if (CheckAttribute(pchar, "questTemp.Terrapin") && pchar.questTemp.Terrapin == "cave" && npchar.location == "Tortuga_tavern")
			{
				dialog.text = "Pokój jest zajęty, "+GetAddress_Form(NPChar)+", nie mogę ci pomóc.";
				link.l1 = "Cóż, to rzeczywiście szkoda...";
				link.l1.go = "exit";
				break;
			}
			if (CheckAttribute(pchar, "questTemp.Guardoftruth") && pchar.questTemp.Guardoftruth == "shore" && npchar.location == "Baster_tavern") // 070712
			{
				dialog.text = "Pokój jest zajęty, "+GetAddress_Form(NPChar)+", nie ma nic, co mogę dla ciebie zrobić.";
				link.l1 = "Cóż, to szkoda...";
				link.l1.go = "exit";
				break;
			}
			//-->> квест официантки
			if (pchar.questTemp.different == "FackWaitress_toRoom")
			{
				dialog.text = "Chcesz wynająć pokój? Żaden problem. 100 sztuk ośmiu i jest twój.";
				if (sti(pchar.money) >= 100)
				{
					link.l1 = "Oto twoje pieniądze.";
					link.l1.go = "exit";
					AddMoneyToCharacter(pchar, -100);
					LocatorReloadEnterDisable(npchar.city + "_tavern", "reload2_back", false);
					pchar.questTemp.different = "FackWaitress_toRoomUp";
				}
				else
				{
					link.l1 = "Hmm... Chyba wrócę później...";
					link.l1.go = "exit";
				}
				break;
			}
			if (pchar.questTemp.different == "FackWaitress_toRoomUp")//квест официантки
			{
				dialog.text = "Pokój jest cały twój. Wejdź i zrelaksuj się.";
				link.l1 = "Dzięki, kumple.";
				link.l1.go = "exit";
				break;
			}
			//<<-- квест официантки
			// --> квест "A damsel in the jungle"
			if(CheckAttribute(pchar,"GenQuest.EncGirl") && npchar.city == pchar.GenQuest.EncGirl.city)
			{
				if(pchar.GenQuest.EncGirl == "EncGirl_ToTavern")
				{
					dialog.text = "Chcesz wynająć pokój? Bez problemu. 100 sztuk ośmiu i jest twój.";
					if (sti(pchar.money) >= 100)
					{
						link.l1 = "Tu są twoje pieniądze.";
						link.l1.go = "exit";
						AddMoneyToCharacter(pchar, -100);
						LocatorReloadEnterDisable(npchar.city + "_tavern", "reload2_back", false);
						pchar.GenQuest.EncGirl = "EncGirl_toRoomUp";
					}
					else
					{
						link.l1 = "Hmm... Chyba wrócę później...";
						link.l1.go = "exit";
					}
					break;
				}
				if (pchar.GenQuest.EncGirl == "EncGirl_toRoomUp")//квест  по спасению тетки в пампасах
				{
					dialog.text = "Pokój jest cały twój. Wejdź i zrelaksuj się.";
					link.l1 = "Dzięki, kumplu.";
					link.l1.go = "exit";
					break;
				}
			}
			// <-- квест "A damsel in the jungle"

			// belamour постоялец -->
			if (CheckAttribute(pchar, "GenQuest.Unwantedpostor") && !CheckAttribute(pchar, "questTemp.Sharlie.Lock") && abs(50-sti(pchar.reputation.nobility)) > 20)
			{
				if(pchar.GenQuest.Unwantedpostor == "start")
				{
					SetFunctionTimerCondition("Unwantedpostor_OneDay", 0, 0, 1, false);
					pchar.GenQuest.Unwantedpostor = "timer";
				}
				dialog.text = "Przepraszam kapitanie, niestety nie ma wolnego pokoju. Gość nie chce wyjść. I nadal mi nie zapłacił...";
				link.l1 = "Wygląda na to, że będziemy musieli spędzić noc w gospodzie...";
				link.l1.go = "Unwantedpostor_hall_day_wait";
				link.l2 = "Przepraszam. Porozmawiajmy o czymś innym.";
				link.l2.go = "int_quests";
				if(pchar.GenQuest.Unwantedpostor != "Lose")
				{
					link.l3 = "Więc wezwij straże. Co za gość: nie płaci pieniędzy, nie chce się wyprowadzić...";
					link.l3.go = "Unwantedpostor";
				}
				break;
			}
			//<-- постоялец

			dialog.text = "Jak długo zamierzasz tu zostać?";
			if(!isDay())
			{
				link.l1 = "Do rana.";
				link.l1.go = "room_day";
			}
			else
			{
				link.l1 = "Do nocy.";
				link.l1.go = "room_night";
				link.l2 = "Do zobaczenia następnego ranka.";
				link.l2.go = "room_day_next";
			}
			
			if (CheckAttribute(pchar, "questTemp.LSC.Mary_officer") && GetCharacterIndex("Mary") != -1)
			{
				pchar.questTemp.MarySexBlock = true;
				SetTimerFunction("Mary_DeleteSexBlock", 0, 0, 1);
			}
		break;

		case "room_day":
			dialog.text = "To będzie cię kosztować 5 ósemek.";
			if (makeint(pchar.money) >= 5)
			{
				link.l1 = "Umowa. Proszę bardzo.";
				link.l1.go = "room_day_wait";
			}
			link.l2 = pcharrepphrase("Za tę cenę? Wynajmujesz królewskie komnaty? Wolę zatrzymać się w sali dla wszystkich za darmo.","Ach, luksus spania na łóżku wydaje się być poza moimi obecnymi środkami. Chyba będę musiał spać w sypialni na ławce.");
			link.l2.go = "hall_day_wait";
			if (!CheckAttribute(pchar, "questTemp.Sharlie.Lock"))
			{
				link.l3 = "Nie teraz. Zmieńmy temat.";
				link.l3.go = "int_quests";
			}
		break;

		case "room_day_next":
			dialog.text = "To będzie cię kosztować 10 sztuk ósemek.";
			if (makeint(pchar.money) >= 10)
			{
				link.l1 = "Zgoda. Proszę bardzo.";
				link.l1.go = "room_day_wait_next";
			}
			link.l2 = pcharrepphrase("Za tę cenę? Wynajmujesz królewskie komnaty? Wolę zostać w gminnej izbie za darmo.","Niestety, luksus spania na łóżku wydaje się być poza moimi obecnymi możliwościami. Chyba będę musiał spać w sali na ławce.");
			link.l2.go = "hall_day_wait";
			if (!CheckAttribute(pchar, "questTemp.Sharlie.Lock"))
			{
				link.l3 = "Nie teraz. Zmieńmy temat.";
				link.l3.go = "int_quests";
			}
		break;

		case "room_night":
			dialog.text = "To będzie cię kosztować 5 ósemek.";
			if (makeint(pchar.money) >= 5)
			{
				link.l1 = "Umowa. Proszę bardzo.";
				link.l1.go = "room_night_wait";
			}
			link.l2 = pcharrepphrase("Za tę cenę? Wynajmujesz królewskie komnaty? Wolę zostać w gospodzie za darmo.","Niestety, luksus spania na łóżku wydaje się być poza moimi obecnymi możliwościami. Chyba będę musiał spać w sali ogólnej na ławce.");
			link.l2.go = "hall_night_wait";
			if (!CheckAttribute(pchar, "questTemp.Sharlie.Lock"))
			{
				link.l3 = "Nie teraz. Zmieńmy temat.";
				link.l3.go = "int_quests";
			}
		break;

		case "room_night_wait":
			// belamour прерывание ночной приключенец -->
			if(CheckAttribute(pchar,"GenQuest.NightAdventureId"))
			{
				if(GetCharacterIndex(pchar.GenQuest.NightAdventureId) != -1)
				{
					sld = characterFromId(pchar.GenQuest.NightAdventureId);
					ChangeCharacterAddressGroup(sld, "none", "", "");
				}
				SetFunctionTimerCondition("NightAdventure_KillPhant", 0, 0, 0, false);
			}
			// <-- прерывание ночного приключенца 
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddMoneyToCharacter(pchar, -5);
			AddDialogExitQuest("sleep_in_tavern");
			TavernWaitDate("wait_night");
		break;

		case "hall_night_wait":
			if (cRand(3) == 1)
            {
                Dialog.text = "Zgredzie, wynoś się stąd do diabła! Mieszkanko może i za friko, ale oczekujemy porządnego zachowania!";
				link.l1 = "Dobrze, dobrze, wychodzę.";
				link.l1.go = "exit";
            }
            else
            {
				DialogExit();
				NextDiag.CurrentNode = NextDiag.TempNode;
				TavernWaitDate("wait_night");
			}
		break;

		case "room_day_wait":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddMoneyToCharacter(pchar, -5);
			AddDialogExitQuest("sleep_in_tavern");
			// belamour прерывание ночной приключенец -->
			if(CheckAttribute(pchar,"GenQuest.NightAdventureId"))
			{
				if(GetCharacterIndex(pchar.GenQuest.NightAdventureId) != -1)
				{
					sld = characterFromId(pchar.GenQuest.NightAdventureId);
					ChangeCharacterAddressGroup(sld, "none", "", "");
				}
				SetFunctionTimerCondition("NightAdventure_KillPhant", 0, 0, 0, false);
			}
			// <-- прерывание ночного приключенца 
			if (CheckAttribute(pchar, "GenQuest.LigaAttack") && drand(1) == 1)
			{
				TavernWaitDate("wait_night");
				pchar.GenQuest.LigaAttack.Go = "true"; //атака киллеров
			}
			else TavernWaitDate("wait_day");
		break;

		case "room_day_wait_next":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddMoneyToCharacter(pchar, -10);
			AddDialogExitQuest("sleep_in_tavern");
			// belamour прерывание ночной приключенец -->
			if(CheckAttribute(pchar,"GenQuest.NightAdventureId"))
			{
				if(GetCharacterIndex(pchar.GenQuest.NightAdventureId) != -1)
				{
					sld = characterFromId(pchar.GenQuest.NightAdventureId);
					ChangeCharacterAddressGroup(sld, "none", "", "");
				}
				SetFunctionTimerCondition("NightAdventure_KillPhant", 0, 0, 0, false);
			}
			// <-- прерывание ночного приключенца 
			if (CheckAttribute(pchar, "GenQuest.LigaAttack") && drand(1) == 1)
			{
				TavernWaitDate("wait_night");
				pchar.GenQuest.LigaAttack.Go = "true"; //атака киллеров
			}
			else TavernWaitDate("wait_day");
		break;

		case "hall_day_wait":
			if (drand(1) == 1)
            {
                Dialog.text = "Wypad stąd, łotrzyku! Sala może być dla wszystkich, ale oczekujemy przyzwoitego zachowania!";
				link.l1 = "W porządku, w porządku, już wychodzę.";
				link.l1.go = "exit";
            }
            else
            {
				// belamour прерывание ночной приключенец -->
				if(CheckAttribute(pchar,"GenQuest.NightAdventureId"))
				{
					sld = characterFromId(pchar.GenQuest.NightAdventureId);
					ChangeCharacterAddressGroup(sld, "none", "", "");
					SetFunctionTimerCondition("NightAdventure_KillPhant", 0, 0, 0, false);
				}
				// <-- прерывание ночного приключенца
				DialogExit();
				NextDiag.CurrentNode = NextDiag.TempNode;
				TavernWaitDate("wait_day");
			}
		break;
		
		case "tavern_keeper":
			NextDiag.TempNode = "First time";

			dialog.text = "Przerwij te skandaliczne zachowanie w mojej karczmie natychmiast, albo zawołam straże!";
			link.l1 = "Dobrze, dobrze, już wychodzę.";
			link.l1.go = "exit_sit";
		break;

		case "exit_sit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			AddDialogExitQuest("exit_sit");
		break;
		
		//******************* ноды квеста священника. поиск грабителей (квест № 2)**********************
		case "Tavern_GenQuest_Church_2_1":
			dialog.text = "Nie wiem o tym wiele... Lepiej zapytaj klientów.";
			link.l1 = "Rozumiem, dzięki.";
			link.l1.go = "exit";
			DeleteAttribute(PChar, "GenQuest.ChurchQuest_2.AskBarmen");
		break;
			
		//******************* ноды квеста священника. вернуть рукописи (квест № 1)**********************
		case "Tavern_ChurchGenQuest1_Node_1":
			dialog.text = "Nie udzielamy usług na kredyt, "+GetSexPhrase("panie","panienko")+".";
			link.l1 = "Płacę dobrą monetą. Czy już nie akceptujesz złota czy srebra?";
			link.l1.go = "Tavern_ChurchGenQuest1_Node_2";
		break;
			
		case "Tavern_ChurchGenQuest1_Node_2":
			dialog.text = "Przykro mi, "+GetSexPhrase("panie","panienko")+"kapitanie, ale twój przyjaciel miał dług, a ja myślałem...";
			link.l1 = "Mniej myśl i szybciej pracuj, kumplu. Teraz, ile mój dzielny przyjaciel jest ci winien?";
			link.l1.go = "Tavern_ChurchGenQuest1_Node_3";
		break;
			
		case "Tavern_ChurchGenQuest1_Node_3":
			iTemp = (rand(3)+1)*100;
			PChar.GenQuest.ChurchQuest_1.MoneyToBarmen = iTemp;
			if(rand(1) == 0) // "If he's a simple one and pays right away"
			{
				dialog.text = FindRussianMoneyString(iTemp)+", panie"+GetSexPhrase("ter","s")+"kapitanie, on także zastawił kilka ksiąg kościelnych - to wszystko, co miał przy sobie, co miało jakąś wartość.";
				if(sti(PChar.money) >= iTemp)
				{
					link.l1 = "Tu są twoje monety. Oddaj rękopisy. I ostrożnie z nimi - to nie jest księga sprośnych drzeworytów, ale Święta Księga!";
					link.l1.go = "Tavern_ChurchGenQuest1_Node_4_1";
				}
				else
				{
					link.l1 = "Poczekaj chwileczkę... Wrócę z pieniędzmi";
					link.l1.go = "exit";
					PChar.GenQuest.ChurchQuest_1.NoMoneyToBarmen = true;
				}
			}
			else // "If he's not a simple one"
			{
				dialog.text = FindRussianMoneyString(iTemp)+", panie"+GetSexPhrase("ter","s")+" kapitanie.";
				link.l1 = "Spłacę jego dług i wezmę wszystko, co zostawił w zabezpieczenie.";
				link.l1.go = "Tavern_ChurchGenQuest1_Node_4_2";
			}
		break;
			
		case "Tavern_ChurchGenQuest1_Node_4_1":
			DialogExit();
			AddMoneyToCharacter(PChar, -sti(PChar.GenQuest.ChurchQuest_1.MoneyToBarmen));
			AddItems(PChar, "Bible", 1);	// Даем рукописи
			items[FindItem("Bible")].Name = "itmname_ChurchGenQuest1Bible";	// Меняем имя. Потом поменять обратно!
			ChangeItemDescribe("Bible", "itmdescr_ChurchGenQuest1Bible"); // Меняем дескрайб. Потом поменять обратно!
			items[FindItem("Bible")].City = XI_ConvertString("Colony" + PChar.GenQuest.ChurchQuest_1.QuestTown + "Gen"); // Переменная. Потом удалить!
			DeleteAttribute(PChar, "GenQuest.ChurchQuest_1.NeedToDialogWithBarmen");
			sQuestTitle = PChar.GenQuest.ChurchQuest_1.QuestTown + "ChurchGenQuest1";
			AddQuestRecordEx(sQuestTitle, "ChurchGenQuest1", "8");
			AddQuestUserData(sQuestTitle, "sColony", XI_ConvertString("Colony" + PChar.GenQuest.ChurchQuest_1.QuestTown + "Gen"));
			AddQuestUserData(sQuestTitle, "sName", GetFullName(CharacterFromID("ChurchGenQuest1_Cap")));
			PChar.GenQuest.ChurchQuest_1.Complete = true; // Квест выполнен
			SetFunctionTimerCondition("Church_GenQuest1_DeleteCapitan", 0, 0, 2, false);
		break;
			
		case "Tavern_ChurchGenQuest1_Node_4_2":
			dialog.text = "Nie, pani"+GetSexPhrase("ter","s")+", to nie zadziała w ten sposób.";
			link.l1 = "Co masz na myśli mówiąc - 'to tak nie działa'? Dług kapitana jest spłacony - on jest spokojny. Masz swoje pieniądze z powrotem - jesteś spokojny. Biorę jego zastaw - jestem spokojny. Wszyscy są spokojni - więc dlaczego 'to tak nie działa'?";
			link.l1.go = "Tavern_ChurchGenQuest1_Node_4_2_1";
		break;
			
		case "Tavern_ChurchGenQuest1_Node_4_2_1":
			dialog.text = "Ponieważ, pani"+GetSexPhrase("ter","s")+"kapitanie, nie potrzebuję pieniędzy. Ponieważ znam tego kapitana aż za dobrze, więc nigdy naprawdę nie spodziewałem się, że zwróci mi i zabierze te rękopisy ode mnie.";
			link.l1 = "Co masz na myśli - nie potrzebujesz pieniędzy? Czyli planowałeś zatrzymać te książki od samego początku? Ale dlaczego, na miłość boską?!";
			link.l1.go = "Tavern_ChurchGenQuest1_Node_4_2_2";
		break;
			
		case "Tavern_ChurchGenQuest1_Node_4_2_2":
			dialog.text = "W imię Boga - dokładnie, dlatego, pani"+GetSexPhrase("ter","s")+". Mój mały chłopiec był bardzo chory, a ja i moja żona złożyliśmy ślubowanie, że złożymy dar kościołowi, jeśli nasz Błogosławiony Pan wyleczy dziecię z gorączki. Miłosierdzie naszego Pana jest nieskończone, mój chłopiec jest żywy i zdrowy, a teraz musimy dotrzymać naszego ślubowania. I to akurat na czas, kapitanie "+PChar.GenQuest.ChurchQuest_1.CapFullName+" pojawia się i zastawia te kościelne księgi. Nie mogłem pozwolić na taką obsceniczność - płacenie za drinki Słowem - i dlatego postanowiłem przekazać te książki proboszczowi naszej parafii.";
			link.l1 = "Cóż, oczywiście, to jest dobre uczynki, ale powinieneś również wiedzieć, że te książki tak naprawdę należą do innego księdza - a właściwie nie tylko księdza, ale biskupa i mojego duchowego pasterza. A on może się zezłościć, a nawet przekląć tych, którzy ośmieliby ofiarować skradzioną własność Kościoła. Chciałbym je od ciebie kupić i bezpiecznie zabrać do domu. Możesz ofiarować pieniądze swojej parafii, jestem pewien, że Bóg to doceni tak samo.";
			link.l1.go = "Tavern_ChurchGenQuest1_Node_4_2_3";
		break;
			
		case "Tavern_ChurchGenQuest1_Node_4_2_3":
			dialog.text = "Panie"+GetSexPhrase("ter","s")+"... Pomyłka"+GetSexPhrase("ter","s")+" kapitanie... Oczywiście, nie miałem pojęcia! Oddam je z powrotem i nie wymagam za to żadnych pieniędzy. Wystarczy, że wspomnisz o nas biskupowi - może nas pobłogosławić i uwolnić od naszej przysięgi...";
			link.l1 = "Oczywiście, twoja przysięga będzie uznana za dotrzymaną! Przecież zrezygnowałeś ze swojego zysku, aby zwrócić książki ich prawowitemu właścicielowi. Nie ma znaczenia, która to konkretne kościół, bo jest tylko jeden Bóg i jeden Święty Katolicki Kościół Apostolski, prawda? Dobrze, daj mi je, i powodzenia ci...";
			link.l1.go = "Tavern_ChurchGenQuest1_Node_4_2_4";
		break;
			
		case "Tavern_ChurchGenQuest1_Node_4_2_4":
			DialogExit();
			AddItems(PChar, "Bible", 1);	// Даем рукописи
			items[FindItem("Bible")].Name = "itmname_ChurchGenQuest1Bible";	// Меняем имя. Потом поменять обратно!
			ChangeItemDescribe("Bible", "itmdescr_ChurchGenQuest1Bible"); // Меняем дескрайб. Потом поменять обратно!
			items[FindItem("Bible")].City = XI_ConvertString("Colony" + PChar.GenQuest.ChurchQuest_1.QuestTown + "Gen"); // Переменная. Потом удалить!
			AddMoneyToCharacter(PChar, -sti(PChar.GenQuest.ChurchQuest_1.MoneyToBarmen));
			DeleteAttribute(PChar, "GenQuest.ChurchQuest_1.NeedToDialogWithBarmen");
			sQuestTitle = PChar.GenQuest.ChurchQuest_1.QuestTown + "ChurchGenQuest1";
			AddQuestRecordEx(sQuestTitle, "ChurchGenQuest1", "9");
			AddQuestUserData(sQuestTitle, "sColony", XI_ConvertString("Colony" + PChar.GenQuest.ChurchQuest_1.QuestTown)); // belamour gen
			PChar.GenQuest.ChurchQuest_1.Complete = true; // Квест выполнен
			SetFunctionTimerCondition("Church_GenQuest1_DeleteCapitan", 0, 0, 2, false);
		break;
		
		//Jason --> генератор Неудачливый вор
		case "Device_Tavern":
			dialog.text = "Hmm, "+pchar.GenQuest.Device.Shipyarder.Type+"? Nigdy o tym nie słyszałem... Co to właściwie jest? Nigdy nie słyszałem o takiej rzeczy przez cały mój czas.";
			link.l1 = "No cóż, to narzędzie stoczniowe, "+pchar.GenQuest.Device.Shipyarder.Describe+". Czy ktoś ci coś takiego proponował?";
			link.l1.go = "Device_Trader_1";
			npchar.quest.Device = "true";
		break;
		
		case "Device_Trader_1":
			if (sti(pchar.GenQuest.Device.Shipyarder.Chance1) == 6)
			{
				dialog.text = "Hmm... Tak, jeden dziwny typ rzeczywiście przyniósł mi to. Ale nie powiedział mi, co to jest, tylko próbował wymienić to na gorzałkę. Oczywiście, odmówiłem - nie potrzebowałem tego drobiazgu.";
				link.l1 = "A jak on wyglądał i gdzie poszedł? Bardzo potrzebuję tego instrumentu.";
				link.l1.go = "Device_Common";
			}
			else
			{
				dialog.text = "Nie, nic takiego. Przykro mi, nie mogę ci pomóc. Zapytaj dookoła.";
				link.l1 = "Rozumiem. Cóż - czas zapytać dookoła!";
				link.l1.go = "exit";
			}
		break;
		// <-- генератор Неудачливый вор
		
		//Jason --> генератор Место под солнцем
		case "Sunplace_Tavern":
			if (makeint(environment.time) > 12.0 && makeint(environment.time) < 17.0)//в магазине
			{
				dialog.text = ""+pchar.GenQuest.Sunplace.Trader.Enemyname+"? Był tam niedawno, a teraz powinien być u swojego towarzysza - sklepikarza. Spróbuj poszukać go w sklepie - na pewno tam musi być.";
				link.l1 = "Dzięki! Bardzo mi pomogłeś!";
				link.l1.go = "Sunplace_Tavern_1";
			}
			else//ушел на рыбалку
			{
				dialog.text = ""+pchar.GenQuest.Sunplace.Trader.Enemyname+"? Dzisiaj, wcześnie rano, wypłynął na swoim szkunerze na morze. Założę się, że teraz stoi na burcie, podziwiając widok. Jeśli go potrzebujesz, możesz spróbować go znaleźć na morzu lub poczekać, aż wróci za kilka dni...";
				link.l1 = "Dzięki! Chyba nie będę czekał - łatwiej będzie go znaleźć na morzu. Powodzenia!";
				link.l1.go = "Sunplace_Tavern_2";
			}
		break;
		
		case "Sunplace_Tavern_1"://магазин
			pchar.quest.Sunplace_Store.win_condition.l1 = "location";
			pchar.quest.Sunplace_Store.win_condition.l1.location = pchar.GenQuest.Sunplace.Trader.CityT + "_store";
			pchar.quest.Sunplace_Store.function = "Sunplace_CreateTrader";
			AddQuestRecord("Sunplace", "6");
			AddQuestUserData("Sunplace", "sName", pchar.GenQuest.Sunplace.Trader.Enemyname);
			AddQuestUserData("Sunplace", "sCity", XI_ConvertString("Colony"+pchar.GenQuest.Sunplace.Trader.CityT+"Gen"));
			DialogExit();
			pchar.GenQuest.Sunplace.Trader = "hunt";
		break;
		
		case "Sunplace_Tavern_2"://рыбалка
			pchar.GenQuest.Sunplace.Trader.IslandID = GetCharacterCurrentIslandId(npchar);
			pchar.GenQuest.Sunplace.Trader.EnemyNation = npchar.nation;
			pchar.quest.Sunplace_Sea.win_condition.l1 = "location";
			pchar.quest.Sunplace_Sea.win_condition.l1.location = pchar.GenQuest.Sunplace.Trader.IslandID;
			pchar.quest.Sunplace_Sea.function = "Sunplace_CreateTraderLugger";
			AddQuestRecord("Sunplace", "7");
			AddQuestUserData("Sunplace", "sName", pchar.GenQuest.Sunplace.Trader.Enemyname);
			AddQuestUserData("Sunplace", "sCity", XI_ConvertString("Colony"+pchar.GenQuest.Sunplace.Trader.CityT+"Gen"));
			DialogExit();
			pchar.GenQuest.Sunplace.Trader = "hunt";
		break;
		// <-- генератор Место под солнцем	
		
		// Jason --> Голландский гамбит
		case "HWICHollJacob_Tavern":
			dialog.text = "Psssst... Dlaczego krzyczysz? On czeka na ciebie już od dawna. Wypił już pełną kwartę rumu. Idź na górę do pokoju, tam go znajdziesz.";
			link.l1 = "O, rozumiem. Miejmy nadzieję, że wciąż jest na nogach.";
			link.l1.go = "exit";
			LocatorReloadEnterDisable(pchar.questTemp.HWIC.Holl.JacobCity+"_tavern", "reload2_back", false);
			pchar.questTemp.HWIC.Holl = "JacobInRoom";
			AddDialogExitQuestFunction("Create_JacobVanBerg");
			DelLandQuestMark(npchar);
		break;
		
		case "HWICSelfFernando_Tavern":
			if (NPChar.location == pchar.questTemp.HWIC.Self.SpainCity +"_tavern")
			{
				//DelMapTonzagAllQM();
				if (makeint(environment.time) > 10.0 && makeint(environment.time) < 18.0)//на улице
				{
					dialog.text = "Tak, znam tego pana. Powinien być gdzieś w mieście - właśnie niedawno widziałem go przechodzącego obok mojego okna.";
					link.l1 = "Dziękuję! Pójdę go szukać!";
					link.l1.go = "Fernando_Land";
				}
				else //в море
				{
					dialog.text = "Tak, teraz odwiedza nasze miasto. W tej chwili go tu nie ma - wypłynął na swojej brygandynie. Prawdopodobnie nie jest daleko stąd, na wodach naszej wyspy.";
					link.l1 = "Dzięki kumplu! Bardzo mi pomogłeś!";
					link.l1.go = "Fernando_Sea";
				}
				pchar.questTemp.HWIC.Self = "KillFernando";
			}
			else
			{
				dialog.text = "Fernando Rodriguez? Nigdy o nim nie słyszałem. Nie, nic o tym człowieku nie wiem.";
				link.l1 = "Rozumiem... Cóż, poszukiwania trwają...";
				link.l1.go = "exit";
			}
			npchar.quest.HWICTalked = "true";
		break;
		
		case "Fernando_Land":
			pchar.quest.HWIC_Fernando.win_condition.l1 = "location";
			pchar.quest.HWIC_Fernando.win_condition.l1.location = pchar.questTemp.HWIC.Self.SpainCity +"_town";
			pchar.quest.HWIC_Fernando.function = "CreateFernandoOnLand";
			AddQuestRecord("Holl_Gambit", "3-2");
			DialogExit();
		break;
		
		case "Fernando_Sea":
			pchar.questTemp.HWIC.Self.FernandoIslandID = GetCharacterCurrentIslandId(npchar);
			pchar.quest.HWIC_Fernando.win_condition.l1 = "location";
			pchar.quest.HWIC_Fernando.win_condition.l1.location = pchar.questTemp.HWIC.Self.FernandoIslandID;
			pchar.quest.HWIC_Fernando.function = "CreateFernandoOnSea";
			AddQuestRecord("Holl_Gambit", "3-3");
			DialogExit();
		break;
		//<-- Голландский гамбит
		
		//Jason --> гонки на гидропланах
		case "Race_Advantage":
			dialog.text = "Tak, oczywiście. Gratulacje kapitanie. Już wiem o twoim zwycięstwie. Oto twoje pieniądze.";
			link.l1 = "Dziękuję Ci, "+npchar.name+".";
			link.l1.go = "Race_Advantage_1";
		break;
		
		case "Race_Advantage_1":
			DialogExit();
			AddMoneyToCharacter(pchar, sti(pchar.GenQuest.Racing.Go.Money)*2);
			AddQuestRecord("Racing", "4");
			AddQuestUserData("Racing", "sStartCity", XI_ConvertString("Colony"+pchar.GenQuest.Racing.Go.StartCity+"Gen"));
			CloseQuestHeader("Racing");
			DeleteAttribute(pchar, "GenQuest.Racing.Go");
		break;
		//<-- гонки на гидропланах
		
		//Jason --> захват пассажиров
		case "Marginpassenger":
			if (CheckAttribute(pchar, "GenQuest.Marginpassenger.lose"))
			{
				dialog.text = "Errr, panie, "+pchar.GenQuest.Marginpassenger.q2Name+" umarł około "+LinkRandPhrase("miesiąc","trzy tygodnie","dwa miesiące")+" temu. "+LinkRandPhrase("Nagle poddał się gorączce","Zostali dźgnięci przy bramach miasta - bandyci czy ci czerwonoskórzy dzicy","Został zastrzelony w pojedynku")+". Niech Bóg odpoczywa jego duszę...";
				link.l1 = "Cholera!.. I co ja mam zrobić z jego... No cóż, cokolwiek. Dzięki za informację. Do zobaczenia, "+npchar.name+".";
				link.l1.go = "Marginpassenger_1";
			}
			else
			{
				dialog.text = ""+pchar.GenQuest.Marginpassenger.q2Name+"? Tak, powinien być gdzieś w mieście. Szukaj go na ulicach. Ale pamiętaj, że każdego dnia do południa jest w biurze gubernatora, a po dziewiątej wieczorem zamyka się w swoim domu.";
				link.l1 = "Dzięki! Pójdę go szukać...";
				link.l1.go = "Marginpassenger_2";
			}
		break;
		
		case "Marginpassenger_1":
			DialogExit();
			AddQuestRecord("Marginpassenger", "7");
			AddQuestUserData("Marginpassenger", "sName2", pchar.GenQuest.Marginpassenger.q2Name);
			AddQuestUserData("Marginpassenger", "sCity", XI_ConvertString("Colony"+pchar.GenQuest.Marginpassenger.City));
			// belamour gen: Добряку недолго осталось -->
			if(CheckAttribute(pchar, "questTemp.LongHappy"))
			{
				AddQuestUserData("Marginpassenger", "sBaron", "to Puerto Principe, to the Black Pastor");
			}
			else
			{
				AddQuestUserData("Marginpassenger", "sBaron", "to Le Francois, to Kindly Jacques");
			}
			// <-- belamour gen
			pchar.GenQuest.Marginpassenger = "cabin";
		break;
		
		case "Marginpassenger_2":
			DialogExit();
			AddQuestRecord("Marginpassenger", "8");
			AddQuestUserData("Marginpassenger", "sName2", pchar.GenQuest.Marginpassenger.q2Name);
			pchar.GenQuest.Marginpassenger = "street";
		break;
		//<-- захват пассажиров
		
		//Jason --> поиск дезертира
		case "FindFugitiveTav":
			if (NPChar.city == pchar.GenQuest.FindFugitive.City && sti(pchar.GenQuest.FindFugitive.Chance) == 0)
			{
				dialog.text = NPCStringReactionRepeat("Wygląda na to, że twój kapitan mówił prawdę. "+pchar.GenQuest.FindFugitive.Name+" rzeczywiście niedawno przybył do naszej osady. Szukaj go na ulicach w ciągu dnia - zazwyczaj marnuje swój czas.","Już mnie pytałeś o tego człowieka, i powiedziałem ci wszystko, co wiedziałem!","Żartujesz ze mnie, czy naprawdę jesteś idiotą?! Pytasz o to samo już trzeci raz!","Pomyśleć tylko, jak taki idiota mógł zostać kapitanem...","block",1,npchar,Dialog.CurrentNode);
				link.l1 = HeroStringReactionRepeat("Dziękuję, przyjacielu, bardzo mi pomogłeś!","Tak, tak, dobrze.","Ojej, ojej, nie denerwuj się tak. Po prostu zapomniałem.","Cóż, zrobił, jak widzisz...",npchar,Dialog.CurrentNode); 
				link.l1.go = DialogGoNodeRepeat("FindFugitiveTav_1", "exit", "", "", npchar, Dialog.CurrentNode);
			}
			else
			{
				dialog.text = NPCStringReactionRepeat("Nie, kumplu, nigdy nie słyszałem tego imienia. Zapytaj dookoła - może ktoś go zna...","Już pytałeś mnie o tego człowieka, i powiedziałem ci: nie wiem!","Czy żartujesz ze mnie, czy naprawdę jesteś idiotą?! Pytasz o to samo już trzeci raz!","Aby tylko pomyśleć, jak taki idiota mógł zostać kapitanem...","block",1,npchar,Dialog.CurrentNode);
				link.l1 = HeroStringReactionRepeat("Rozumiem. Cóż, dzięki mimo wszystko.","Tak, tak, dobrze.","Oj, oj, nie denerwuj się tak. Po prostu zapomniałem.","Cóż, zrobił, jak widzisz...",npchar,Dialog.CurrentNode); 
				link.l1.go = DialogGoNodeRepeat("exit", "", "", "", npchar, Dialog.CurrentNode);	
			}
		break;
		
		case "FindFugitiveTav_1":
			DialogExit();
			AddQuestRecord("MayorsQuestsList", "12-1");
			sld = characterFromId("Fugitive");
			LAi_SetWarriorType(sld);
			LAi_warrior_DialogEnable(sld, true);
			sld.dialog.currentnode = "Fugitive_city";
			LAi_SetLoginTime(sld, 11.0, 18.0);
			ChangeCharacterAddressGroup(sld, pchar.GenQuest.FindFugitive.City+"_town", "goto", "goto"+(rand(9)+1));
		break;
		//<-- поиск дезертира
		
		//--> Бремя гасконца
		case "Sharlie_crew":
			dialog.text = "Niestety, teraz nie mogę ci pomóc - nikt z ludzi, których znam, nie posłużyłby pod twoim dowództwem. Ale mogę ci dać radę - porozmawiaj z tym marynarzem, który właśnie zajął stół tuż za tobą. On i jego kumple właśnie opuścili jeden statek handlowy. Może zgodzą się pójść z tobą.";
			link.l1 = "W porządku, właśnie tak zrobię! Bardzo ci dziękuję!";
			link.l1.go = "exit";
			pchar.questTemp.Sharlie = "sailor";
			//усадим матроса
			sld = GetCharacter(NPC_GenerateCharacter("SharlieSailor" , "citiz_31", "man", "man", 10, FRANCE, -1, true, "quest"));
			FantomMakeCoolFighter(sld, 10, 20, 20, "blade_05", "", "", 10);
			sld.Dialog.Filename = "Quest\Sharlie\OtherNPC.c";
			sld.dialog.currentnode = "Sharlie_sailor";
			sld.greeting = "town_sailor";
			AddLandQuestMark(sld, "questmarkmain");
			LAi_SetSitType(sld);
			LAi_SetImmortal(sld, true);
			FreeSitLocator("FortFrance_tavern", "sit7");
			ChangeCharacterAddressGroup(sld, "FortFrance_tavern", "sit", "sit7");
			AddQuestRecord("Sharlie", "6-1"); // mitrokosta
		break;
		
		case "Sharlie_skiper":
			dialog.text = "Nie mogę ci powiedzieć nic konkretnego, przyjacielu. W tej chwili żadni nawigatorzy nie odwiedzają mojego miejsca. Spróbuj zapytać w porcie - być może, ludzie będą wiedzieli więcej.";
			link.l1 = "Rozumiem. Dobrze, pójdę porozmawiać z ludźmi.";
			link.l1.go = "exit";
			pchar.questTemp.Sharlie = "findskiper";
			//сгенерим наводчика
			sld = GetCharacter(NPC_GenerateCharacter("SharlieSkiperTalker", "citiz_"+(rand(19)+21), "man", "man", 10, FRANCE, -1, true, "marginal"));
			FantomMakeCoolFighter(sld, 10, 20, 20, RandPhraseSimple("blade_04","blade_06"), "", "", 10);
			sld.Dialog.Filename = "Quest\Sharlie\OtherNPC.c";
			sld.dialog.currentnode = "skipertalker";
			sld.greeting = "marginal";
			LAi_SetWarriorType(sld);
			LAi_SetImmortal(sld, true);
			LAi_group_MoveCharacter(sld, "FRANCE_CITIZENS");
			ChangeCharacterAddressGroup(sld, "FortFrance_town", "patrol", "patrol"+(rand(13)+1));
			LAi_SetLoginTime(sld, 6.0, 21.99);
			AddLandQuestMark(sld, "questmarkmain");
		break;
		//<-- Бремя гасконца
		
		// Addon 2016-1 Jason пиратская линейка
		case "mtraxx_tortuga":
			sld = characterFromId("Tortuga_waitress");
            dialog.text = "Natychmiast, panie!.. Najlepsze francuskie wino!"+sld.name+"! Przygotuj najlepszy pokój dla gości! To będzie 1000 pesos, panie.";
			link.l1 = "Tutaj.";
			link.l1.go = "mtraxx_tortuga_1";
		break;
		
		case "mtraxx_tortuga_1":
			AddMoneyToCharacter(pchar, -1000);
            DialogExit();
			pchar.questTemp.Mtraxx.Retribution = "room";
			pchar.quest.mtraxx_retribution_room.win_condition.l1 = "locator";
			pchar.quest.mtraxx_retribution_room.win_condition.l1.location = "Tortuga_tavern";
			pchar.quest.mtraxx_retribution_room.win_condition.l1.locator_group = "reload";
			pchar.quest.mtraxx_retribution_room.win_condition.l1.locator = "reload2_back";
			pchar.quest.mtraxx_retribution_room.function = "Mtraxx_RetributionToRoom";
		break;
		// belamour постоялец -->
		case "Unwantedpostor_hall_day_wait":
			if (drand(1) == 1)
            {
                Dialog.text = "Wyjdź, łotrzyku! Zajmujesz cenne miejsce dla płacących klientów!";
				link.l1 = "Dobrze, dobrze... Wychodzę.";
				link.l1.go = "exit";
            }
            else
            {
				DialogExit();
				NextDiag.CurrentNode = NextDiag.TempNode;
				TavernWaitDate("wait_day");
			}
		break;
		
		case "Unwantedpostor":
				dialog.text = "Tak - i przestraszyć wszystkich moich klientów tym, że moi strażnicy wyciągają ludzi z tawerny? A niektórzy z moich klientów nie lubią przebywać w pobliżu żołnierzy. To ich denerwuje, rozumiesz? Nie chcę zrujnować swojej reputacji...";
				link.l1 = "Hmm, a co jeśli rozwiążę twój problem?";
				link.l1.go = "Unwantedpostor_1";
		break;
		
		case "Unwantedpostor_1":
				dialog.text = "Podjąłeś decyzję? Jest uzbrojony, pewnego rodzaju zawodowy najemnik...";
				link.l1 = "Hmm, masz rację, nie chcę się kłócić z uzbrojonym najemnikiem...";
				link.l1.go = "Exit";
				link.l2 = "Cóż, ja też nie jestem skrytą zakonnicą... I nadal chcę wynająć pokój.";
				link.l2.go = "Unwantedpostor_2";
		break;
		
		case "Unwantedpostor_2":
				dialog.text = "No cóż, jeśli możesz, khem... przekonać go do wyprowadzenia się, to pokój jest twój aż do rana. Oczywiście za darmo.";
				link.l1 = "Wiesz, zmieniłem zdanie. Nie mam ochoty przekonywać nikogo.";
				link.l1.go = "Exit";
				link.l2 = "Chcesz to zobaczyć. Twój nieproszony gość zaraz poleci z twojej tawerny jak wielka mewa.";
				link.l2.go = "Unwantedpostor_kikcoff";
		break;
		
		case "Unwantedpostor_kikcoff":
				DialogExit();
				chrDisableReloadToLocation = true; //закрыть локацию
				LAi_LocationFightDisable(&Locations[FindLocation(pchar.location+"_upstairs")], true); //запретить драться
				iTemp = sti(pchar.rank) + rand(5);
				sld = GetCharacter(NPC_GenerateCharacter("Berglar_Unwantedpostor", "citiz_5"+(rand(3)+1), "man", "man", iTemp, PIRATE, -1, true, "quest")); // "mercen_"+(rand(14)+14)
				FantomMakeCoolFighter(sld, iTemp, 50 + rand(30), 50 + rand(30), "topor_04", "", "bullet", 50);
				sld.dialog.filename = "GenQuests_Dialog.c";
				sld.dialog.currentnode = "Unwantedpostor_room";	
				sld.greeting = "Enc_Raiders"; 
				if (findsubstr(locations[FindLocation(pchar.location)].id, "tavern_upstairs" , 0) == -1)
				{
					DoQuestReloadToLocation(pchar.location+"_upstairs", "quest", "quest4", "");
					ChangeCharacterAddressGroup(sld, pchar.location+"_upstairs", "quest", "quest3");
				} 
				LAi_SetActorType(sld);
				LAi_ActorDialogDelay(sld, pchar, "", 1.5);
		break;
		// <-- belamour постоялец
		
		case "Helen_room_night":
			dialog.text = "Rozumiem. To będzie pięć srebrników.";
			if (makeint(pchar.money) >= 5)
			{
				link.l1 = "Oczywiście, proszę bardzo.";
				link.l1.go = "room_night_wait";
			}
			link.l2 = "Właściwie, wiesz co... Może innym razem. Spędzę resztę dnia na nogach.";
			link.l2.go = "Helen_night_exit";
		break;
		
		case "Helen_room_day":
			dialog.text = "Mądra decyzja. To będzie pięć srebrników, i dobranoc dla ciebie.";
			if (makeint(pchar.money) >= 5)
			{
				link.l1 = "Proszę bardzo, a dziękuję - dobranoc.";
				link.l1.go = "room_day_wait";
			}
			link.l2 = "Przy drugim zastanowieniu, nie chce mi się spać. Poszwendam się po mieście, wdychając nocne powietrze.";
			link.l2.go = "Helen_day_exit";
		break;
		
		case "Helen_room_day_next":
			dialog.text = "Oczywiście, Ellen. To będzie dziesięć peso.";
			if (makeint(pchar.money) >= 10)
			{
				link.l1 = "Oczywiście, proszę bardzo.";
				link.l1.go = "room_day_wait_next";
			}
			link.l2 = "Właściwie... Mogłabym zrobić coś pożytecznego przez cały dzień. Może innym razem.";
			link.l2.go = "Helen_Next_day_exit";
		break;
		
		case "Helen_night_exit":
			dialog.text = "Jak sobie życzysz, Ellen.";
			link.l1 = "Mhm.";
			link.l1.go = "exit";
		break;
		
		case "Helen_day_exit":
			dialog.text = "Możesz nawet poczuć się senny po dobrym spacerze.";
			link.l1 = "Ha-ha, może.";
			link.l1.go = "exit";
		break;
		
		case "Helen_next_day_exit":
			dialog.text = "Jak uważasz za stosowne.";
			link.l1 = "Cóż, do następnego razu.";
			link.l1.go = "exit";
		break;
		
		case "Helen_rumours_tavern":
			dialog.text = "Oczywiście, Helen, jestem cały uchem.";
			link.l1 = "Jakie są najnowsze wiadomości czy ciekawe plotki w mieście?";
			link.l1.go = "rumours_tavern";
		break;
	}
}

string findTraderCity(ref NPChar)
{
	int n, nation;
    int storeArray[2];
	SetArraySize(&storeArray, MAX_COLONIES); 
    int howStore = 0;

	for(n=0; n<MAX_COLONIES; n++)
	{
		nation = GetNationRelation(sti(npchar.nation), sti(colonies[n].nation));
		if (colonies[n].id != "Panama" && colonies[n].nation != "none" && GetIslandByCityName(npchar.city) != colonies[n].islandLable) //не на свой остров
		{
			if (nation == RELATION_ENEMY || sti(npchar.nation) == PIRATE)
			{
				storeArray[howStore] = n;
				howStore++;
			}
		}
	}
	if (howStore == 0) return "none";
	nation = storeArray[cRand(howStore-1)];
	return colonies[nation].id;
}

string findPassangerCity(ref NPChar)
{
	int n, nation;
    int storeArray[2];
	SetArraySize(&storeArray, MAX_COLONIES);
    int howStore = 0;

	for(n=0; n<MAX_COLONIES; n++)
	{
		nation = GetNationRelation(sti(npchar.nation), sti(colonies[n].nation));
		if (colonies[n].nation != "none" && colonies[n].id != "Panama" && GetIslandByCityName(npchar.city) != colonies[n].islandLable) //не на свой остров
		{
			if (nation == RELATION_ENEMY || sti(npchar.nation) == PIRATE)
			{
			storeArray[howStore] = n;
			howStore++;
		}
	}
	}
	if (howStore == 0) return "none";
	nation = storeArray[cRand(howStore-1)];
	return colonies[nation].id;
}
