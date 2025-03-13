// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Czego chcesz? Pytaj śmiało.","Słucham cię, jakie masz pytanie?"),"To już drugi raz, gdy próbujesz zapytać...","To już trzeci raz, kiedy próbujesz znowu zapytać...","Kiedy to się skończy?! Jestem zajętym człowiekiem, pracującym nad sprawami kolonii, a ty wciąż próbujesz o coś pytać!","blokada",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Zmieniam zdanie...","Nie teraz. Złe miejsce i czas."),"Prawda... Ale później, nie teraz...","Zapytam... Ale trochę później...","Przykro mi, "+GetAddress_FormToNPC(NPChar)+"...",npchar,Dialog.CurrentNode);			  
			link.l1.go = "exit";
			if (CheckAttribute(pchar, "questTemp.Guardoftruth.Baster_church") && !CheckAttribute(npchar, "quest.utensil"))
			{
				link.l1 = "Mam do ciebie delikatną sprawę. Niedawno pewien kaper przekazał złoty krzyż z lazurytem parafii w Basse-Terre. Problem w tym, że krzyż został skradziony z parafii w Santiago, a podczas kradzieży zamordowano duchownego...";
                link.l1.go = "guardoftruth";
			}
			// Jason НСО
			if (CheckAttribute(pchar, "questTemp.Patria") && pchar.questTemp.Patria == "epizode_9_continue" && !CheckAttribute(npchar, "quest.frigate"))
			{
				link.l1 = "Przybyłem z rozkazu gubernatora generalnego Philippe'a de Poincy, aby przejąć dowodzenie nad waszą uzbrojoną fregatą.";
                link.l1.go = "patria";
			}
			if (CheckAttribute(npchar, "quest.frigate.wait") && GetCompanionQuantity(pchar) < 5)
			{
				link.l1 = "Jestem gotów wziąć fregatę do eskadry.";
                link.l1.go = "patria_2";
			}
			// Jason Дороже золота
			if (CheckAttribute(pchar, "questTemp.GoldenGirl") && pchar.questTemp.GoldenGirl == "baster")
			{
				link.l1 = "Mam tu spotkanie z jedną osobą...";
                link.l1.go = "baster_goldengirl";
			}
		break;
		//************************** Квестовые штрумы ************************
		case "Cupture_after":
            dialog.text = RandPhraseSimple("Zabrałeś już wszystko. Czego jeszcze chcesz?","Czy zostało coś, czego nie zagrabiłeś?");
            link.l1 = RandPhraseSimple("Po prostu się rozglądam...","Sprawdzam tylko, mogę zapomnieć coś zabrać...");
            link.l1.go = "exit";
            NextDiag.TempNode = "Cupture_after";
		break;
		
		case "guardoftruth":
			dialog.text = "Hm. To całkiem interesujące. Ale dlaczego myślisz, że obchodzą mnie problemy Hiszpanów?";
			link.l1 = "Nie chodzi o Hiszpanów, Monsieur. Religia nie dzieli ludzi według narodowości. W twojej parafii znajduje się przedmiot pokryty krwią świętego sługi i doszło do zbezczeszczenia parafii Santiago...";
			link.l1.go = "guardoftruth_1";
		break;
		
		case "guardoftruth_1":
			dialog.text = "";
			link.l1 = "Proszę cię o okazanie sprawiedliwości i nakazanie ojcu świętemu zwrotu krzyża jego właścicielom.";
			link.l1.go = "guardoftruth_2";
		break;
		
		case "guardoftruth_2":
			dialog.text = "A odkąd to stałeś się takim prawdziwym i gorliwym wierzącym, ha, "+pchar.name+"? Hiszpanie nie są naszymi przyjaciółmi i nie widzę powodu, by naciskać na świętego ojca w tej sprawie. Krzyż był darem i to dobrze. Nasz ksiądz nie ma żadnego związku z tą kradzieżą i morderstwem, więc...";
			link.l1 = "I ty nie możesz mi pomóc, prawda?";
			link.l1.go = "guardoftruth_3";
		break;
		
		case "guardoftruth_3":
			dialog.text = "Szczerze mówiąc, "+pchar.name+", nie czuję, że muszę. Nie mam miłości do tych fanatyków papistów.";
			link.l1 = "Rozumiem. Przepraszam, że cię niepokoję, monsieur...";
			link.l1.go = "guardoftruth_4";
		break;
		
		case "guardoftruth_4":
			DialogExit();
			npchar.quest.utensil = "true";
			AddQuestRecord("Guardoftruth", "28");
		break;
		
		// Jason НСО
		case "patria":
			if (GetCompanionQuantity(pchar) > 4)
			{
				dialog.text = "Okręt jest gotowy, ale nie masz wolnego miejsca na niego w swojej eskadrze. Kapitanie, zmniejsz swoją eskadrę i wróć, wtedy od razu dam ci fregatę.";
				link.l1 = "Dobrze.";
				link.l1.go = "patria_1";
			}
			else
			{
				dialog.text = "Tak, oczywiście, statek jest gotowy do żeglugi. Jego kapitan jest poinformowany i będzie wykonywał wszystkie twoje rozkazy.";
				link.l1 = "Wyruszamy zatem. Żegnaj, Wasza Łaskawość.";
				link.l1.go = "patria_3";
			}
		break;
		
		case "patria_1":
			DialogExit();
			npchar.quest.frigate.wait = "true";
		break;
		
		case "patria_2":
			DeleteAttribute(npchar, "quest.frigate.wait");
			dialog.text = "Doskonale. Przygotuj się na powitanie swojego nowego statku. Kapitan jest świadomy i będzie przestrzegać wszystkich twoich rozkazów.";
			link.l1 = "W takim razie wyruszamy. Żegnaj, Wasza Łaskawość.";
			link.l1.go = "patria_3";
		break;
		
		case "patria_3":
			DialogExit();
			npchar.quest.frigate = "true";
			Patria_BastionFrigateGlp(); // присоединяем фрегат
		break;
		
		// Jason Дороже золота
		case "baster_goldengirl":
			dialog.text = "Ach, Monsieur Charles de Maure, w samą porę! Mój stary przyjaciel bardzo pragnie cię poznać i poprosił, bym dał mu znać o twoim przybyciu. Proszę, wejdź do mojego salonu, natychmiast powiadomię Angerrana. A tak przy okazji, jak się poznaliście?";
			link.l1 = "Graliśmy razem w karty. On przegrał, mieliśmy małą sprzeczkę. Przypuszczam, że monsieur de Chievous chciałby to między nami naprawić.";
			link.l1.go = "baster_goldengirl_1";
		break;
		
		case "baster_goldengirl_1":
			dialog.text = "Bez wątpienia! Mam nadzieję, że uda ci się wszystko wyjaśnić między wami. Angerran może nie jest najprzyjemniejszą osobą do współpracy, ale jest sprytny i honorowy, tak jak ty. To rzadki gatunek.";
			link.l1 = "Schlebiasz mi, Ekscelencjo. Poczekam na niego w salonie, jeśli nie masz nic przeciwko.";
			link.l1.go = "baster_goldengirl_2";
		break;
		
		case "baster_goldengirl_2":
			dialog.text = "Ależ oczywiście, czuj się jak u siebie w domu. Być może będziesz musiał chwilę poczekać. Każę przynieść coś do picia.";
			link.l1 = "Dziękuję, Ekscelencjo, ale odmówię. Po prostu usiądę i poczekam na naszego wspólnego... przyjaciela.";
			link.l1.go = "baster_goldengirl_3";
		break;
		
		case "baster_goldengirl_3":
			DialogExit();
			pchar.questTemp.GoldenGirl = "baster1";
			DoQuestReloadToLocation("CommonResidence_3", "reload", "reload1", "GoldenGirl_AngerranInResidence");
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
