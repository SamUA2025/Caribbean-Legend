// официантка Наталия Бушелл
#include "DIALOGS\%language%\Rumours\Common_rumours.c"
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	ProcessCommonDialogRumors(NPChar, Link, NextDiag);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			if (pchar.questTemp.LSC == "return" && !CheckAttribute(npchar, "quest.return_isl"))
			{
				dialog.text = "O! A mówili mi, że się utopiłeś... Kłamcy!";
				link.l1 = "Pewnie, że tak zrobili! Ha! Czuję się dobrze!";
				link.l1.go = "exit";
				npchar.quest.return_isl = "true";
				break;
			}
			if (npchar.quest.meeting == "0")
			{
				dialog.text = "Dzień dobry, "+GetAddress_Form(NPChar)+"Pierwszy raz tutaj? Nie widziałam cię wcześniej... Mam nadzieję, że będziesz nas odwiedzać częściej, Sancho może zaoferować doskonały wybór napojów. Tak, a moje imię to Nathalie i pomagam Sanchowi w sprawach tawerny.";
				link.l1 = TimeGreeting()+". Nazywam się "+GetFullName(pchar)+"Miło mi cię poznać. I nie mogłeś mnie zobaczyć wcześniej. Przybyłem tu niedawno.";
				link.l1.go = "meeting";
				npchar.quest.meeting = "1";
			}
			else
			{
				dialog.text = "Ach, "+GetFullName(pchar)+"! "+TimeGreeting()+"Chcesz coś?";
				link.l1 = LinkRandPhrase("Masz coś ciekawego do powiedzenia?"," Czy coś nowego wydarzyło się na wyspie?","Czy opowiesz mi najnowsze plotki?");
				link.l1.go = "rumours_LSC";
				link.l2 = "Chcę zadać ci kilka pytań o wyspę.";
				link.l2.go = "int_quests"; //информационный блок
				link.l5 = "Chciałem tylko wiedzieć, jak się masz. Do zobaczenia!";
				link.l5.go = "exit";
			}
			NextDiag.TempNode = "First time";
		break;
		
		case "meeting": // первая встреча
			dialog.text = "Niedawno? Czy kolejny statek się rozbił? Nic nie słyszałam... A może nie przybyłeś tu tak jak monsieur Turam na wraku masztu? Och, wybacz mi moją ciekawość, to natura kobiet, wiesz.";
			link.l1 = "Nie, wszystko w porządku, Nathalie. Przybyłem tu na barku, ale zatonął. Miło było cię poznać. Do zobaczenia!";
			link.l1.go = "exit";
			link.l2 = "Nie, w porządku. Po prostu chciałem zadać ci kilka pytań o wyspę.";
			link.l2.go = "int_quests"; //информационный блок
			NextDiag.TempNode = "First time";
		break;
		
//--------------------------------------- блок вопросов и ответов ---------------------------------------------
		case "int_quests":
			dialog.text = "Słucham.";
			if (!CheckAttribute(npchar, "quest.answer_1"))
			{
				link.l1 = "Pracujesz w tawernie. Co możesz mi powiedzieć o właścicielu?";
				link.l1.go = "ansewer_1";
			}
			if (!CheckAttribute(npchar, "quest.answer_2"))
			{
				link.l2 = "Jak tu trafiłeś?";
				link.l2.go = "ansewer_2";
			}
			if (!CheckAttribute(npchar, "quest.answer_3"))
			{
				link.l3 = "Ilu ludzi tu mieszka?";
				link.l3.go = "ansewer_3";
			}
			if (!CheckAttribute(npchar, "quest.answer_4"))
			{
				link.l4 = "Czy nigdy nie dziwi cię widok nowych twarzy tutaj?";
				link.l4.go = "ansewer_4";
			}
			link.l10 = "Żadnych pytań. Jeśli pozwolisz...";
			link.l10.go = "exit";
		break;
		
		case "ansewer_1":
			dialog.text = "Tylko pozytywne rzeczy,  "+GetAddress_Form(NPChar)+"Sancho zawsze ma dużą różnorodność napojów - od starych win po prosty ale i rum. Kilka lat temu znalazł ogromny zapas win rocznikowych. Sancho spędził dwa miesiące przenosząc skrzynie z butelkami do swojego sklepu\nA teraz jesteśmy dobrze zaopatrzeni w wino, na które tylko gubernatorzy mogli sobie pozwolić tam, na archipelagu. Rum też nie stanowi problemu. Sancho może ci dostarczyć nie tylko napojów, ale także świeżych wiadomości, dobrą radę i ciepłe łóżko na noc.";
			link.l1 = "Widzę...";
			link.l1.go = "int_quests";
			npchar.quest.answer_1 = "true";
		break;
		
		case "ansewer_2":
			dialog.text = "Och, to smutna historia. Siedem lat temu uciekłam z moim zalotnikiem z domu rodziców i postanowiliśmy przeprowadzić się do Belize z Santiago. Nawigator popełnił błąd w pobliżu Main, więc popłynęliśmy w złym kierunku na północ i złapała nas burza. Nasz statek zatonął niedaleko zewnętrznego pierścienia\nMój zalotnik zginął tego dnia, podobnie jak większość innych. Ja i ocalali zaczęliśmy nowe życie tutaj, na Wyspie.";
			link.l1 = "Smętna historia...";
			link.l1.go = "int_quests";
			npchar.quest.answer_2 = "true";
		break;
		
		case "ansewer_3":
			dialog.text = "Całkiem sporo. Klany Rivados i Narwali są liczebnie silne, mieszkają tu od dziesięcioleci. Zwykłych ludzi nie ma zbyt wielu, ale tawerna co noc jest pełna. Ledwo nadążam z podawaniem napojów.";
			link.l1 = "Naprawdę? Interesujące.";
			link.l1.go = "int_quests";
			npchar.quest.answer_3 = "true";
		break;
		
		case "ansewer_4":
			dialog.text = "A dlaczego mielibyśmy? Pojawia się tu wiele nowych twarzy bardzo często. Nawet nie wiem, ilu z nas tu mieszka. Czasami widzę człowieka po raz pierwszy, a on mi mówi, że mieszka tu od roku.";
			link.l1 = "Cóż...";
			link.l1.go = "int_quests";
			npchar.quest.answer_4 = "true";
		break;
// <-- блок вопросов и ответов
		
//----------------------------------------- специальные реакции -----------------------------------------------
		//обнаружение ГГ в сундуках
		case "Man_FackYou":
			dialog.text = LinkRandPhrase("Co tam robisz, co? Złodzieju!","Spójrz tylko na to! Ledwie pogrążyłem się w rozmyślaniach, a ty postanowiłeś sprawdzić moją skrzynię!","Zdecydowałeś się sprawdzić moje skrzynie? Nie ujdzie ci to na sucho!");
			link.l1 = "Cholera jasna!";
			link.l1.go = "fight";
		break;
		
		case "Woman_FackYou":
			dialog.text = "Co?! Zdecydowałeś się sprawdzić moje skrzynie? Nie ujdziesz z tym na sucho!";
			link.l1 = " Głupia dziewka!";
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
		
		//замечание по обнажённому оружию
		case "LSCNotBlade":
			dialog.text = LinkRandPhrase("Słuchaj, lepiej schowaj broń. To mnie denerwuje.","Wiesz, bieganie z ostrzem nie jest tu tolerowane. Schowaj to.","Słuchaj, nie udawaj średniowiecznego rycerza biegającego z bronią. Odłóż ją, to do ciebie nie pasuje...");
			link.l1 = LinkRandPhrase("Dobrze.","Dobrze.","Jak powiadasz...");
			link.l1.go = "exit";
			NextDiag.TempNode = "First Time";
		break;	
		
		case "CitizenNotBlade":
			if (loadedLocation.type == "town")
			{
				dialog.text = NPCharSexPhrase(NPChar,"Słuchaj, jestem obywatelem miasta i proszę cię, schowaj swój miecz.","Słuchaj, jestem obywatelem miasta i proszę cię, abyś schował swój miecz.");
				link.l1 = LinkRandPhrase("Dobrze.","Dobrze.","Jak powiadasz...");
			}
			else
			{
				dialog.text = NPCharSexPhrase(NPChar,"Bądź ostrożny, kumplu, biegając z bronią. Mogę się zdenerwować...","Nie lubię, gdy ludzie chodzą przede mną z gotową bronią. To mnie przeraża...");
				link.l1 = RandPhraseSimple("Zrozumiano.","Zabieram to.");
			}
			link.l1.go = "exit";
			NextDiag.TempNode = "First Time";
		break;
// <-- специальные реакции
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}
