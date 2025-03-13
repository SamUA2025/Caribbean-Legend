// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat("Wszystkie plotki o "+GetCityName(npchar.city)+" do usług. Czego chciałbyś się dowiedzieć?"," Właśnie o tym rozmawialiśmy. Musiałeś zapomnieć...","To już trzeci raz dzisiaj, kiedy mówisz o jakimś pytaniu...","Powtarzasz to wszystko jak papuga...","blokada",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Wiesz, "+NPChar.name+"Może następnym razem.","Racja, z jakiegoś powodu zapomniałem...","Tak, to naprawdę już trzeci raz...","Tak...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			//работорговец
			if (pchar.questTemp.Slavetrader == "EscapeSlave_Villemstad")
            {
                link.l1 = "Słyszałem, że na wyspie był niezły bałagan... Niewolnicy?";
                link.l1.go = "EscapeSlaveVillemstad_T1";
            }
			//Португалец
			if (CheckAttribute(pchar, "questTemp.Portugal") && pchar.questTemp.Portugal == "SeekPortVillemstad")
            {
                link.l1 = "Słyszałem, że ten nędzny drań Bart Portugalczyk wreszcie spotkał się ze sprawiedliwością! Czy jest w więzieniu? Kiedy będzie jego egzekucja, wiesz może? Chcę to zobaczyć, mam z nim na pieńku...";
                link.l1.go = "Portugal";
            }
 		break;

		//работорговец
		case "EscapeSlaveVillemstad_T1":
			dialog.text = "Aye, nigdy nie było takiego bałaganu... Ponad tysiąc murzynów się zbuntowało. Dwie plantacje zostały spalone do cna, a każdy z ich panów został zamordowany. Komendant obawia się, że niewolnicy przyjdą zaatakować miasto, więc wprowadził stan wojenny. A wszystko zaczęło się z powodu dwóch murzynów, kozła imieniem Tamango i kozy imieniem Isauri...";
			link.l1 = "Brzmi to dość dramatycznie. Opowiedz mi całą historię, kim są ci murzyni?";
			link.l1.go = "EscapeSlaveVillemstad_T2";
		break;
		
		case "EscapeSlaveVillemstad_T2":
				dialog.text = "Tamango i Izaura - niewolnicy na plantacji Blenheim, pierwszej plantacji, która spłonęła. Ci dwaj Murzyni kochali się nawzajem. Jednak syn plantatora, Leonsio, przybył z Europy i upodobał sobie tę kozę. Chciał uczynić Izaurę swoją osobistą konkubiną. Czarny byk Tamango nie przepadał za tym pomysłem, a Izaura też nie, naprawdę kochała czarnego diabła\nTamango był jakimś naczelnikiem czy kimś takim w Afryce... Olbrzymi byk - czarny jak grzech i śmiertelny z toporem, inni Murzyni bali się go i szanowali. Więc ten Murzyn poprowadził innych niewolników do buntu. Zaatakowali strażników nocą, zabili wszystkich białych poza wielkim domem, mulatów też\nPotem Izaura otworzyła drzwi plantacji, a dzikie małpy zamordowały wszystkich w środku. Blenburg został spalony do ziemi. Następnie niewolnicy uciekli do dżungli i zniknęli...";
			link.l1 = "Cóż, cóż za historia, brzmi jak fabuła powieści! Prawdziwe powstanie niewolników, zupełnie jak w starożytnym Rzymie. Jak się o tym wszystkim dowiedziałeś, swoją drogą?";
			link.l1.go = "EscapeSlaveVillemstad_T3";
		break;
		
		case "EscapeSlaveVillemstad_T3":
			dialog.text = "Plotki, mój panie, ziemia jest nimi przepełniona. Rum rozwiązuje języki, wystarczy tylko słuchać...";
			link.l1 = "I jak to wszystko się skończyło? Czy znaleźli tych murzynów?";
			link.l1.go = "EscapeSlaveVillemstad_T4";
		break;
		
		case "EscapeSlaveVillemstad_T4":
				dialog.text = "Ha, nie ma mowy! Dopóki posiłki w końcu nie zdołały przybyć, nikt nie zrobił kroku do dżungli. Potem przypłynął okręt wojenny Kompanii z oddziałem żołnierzy i przeszukali wyspę. Nie znaleźli czarnego futra ani kręconego włosa żadnego zbiegłego murzyna.";
			link.l1 = "Cóż, co o tym sądzisz! Tysiąc czarnuchów po prostu wyparowało w powietrze?";
			link.l1.go = "EscapeSlaveVillemstad_T5";
		break;
		
		case "EscapeSlaveVillemstad_T5":
			dialog.text = "Właściwie to do wody.";
			link.l1 = "O czym ty mówisz, "+npchar.name+" ? Wiesz tak dobrze, jak ja, że murzyni nie potrafią pływać.";
			link.l1.go = "EscapeSlaveVillemstad_T6";
		break;
		
		case "EscapeSlaveVillemstad_T6":
			dialog.text = "He-he... o nie, ci czarni nie są tak szybko przynętą na rekiny. Rzecz w tym, że następnej nocy po buncie zniknęła z doków brygantyna. Możesz mnie pomalować na czarno, a ja zagram na banjo i zatańczę dla ciebie, jeśli to nie było rękami tego łajdaka Tamango i jego Murzynów! Dlatego nie ma ich już na wyspie.";
			link.l1 = "Ha, teraz słyszałem już wszystko, "+npchar.name+"Spodziewasz się, że uwierzę, iż grupa półdzikich Murzynów potrafi obsługiwać żagle i nawigować? Prędzej spodziewałbym się, że statek małp wpłynie tu z Gwinei.";
			link.l1.go = "EscapeSlaveVillemstad_T7";
		break;
		
		case "EscapeSlaveVillemstad_T7":
			dialog.text = "Ja też w to nie wierzyłem, mynheer, ale dowodem jest brakujący statek. Może któryś z tych murzynów kiedyś służył jako steward na statku i nauczył się jakiejś techniki żeglarskiej. Może użyli czarnej magii, kto wie! Wpadnij i odwiedź mnie ponownie, "+pchar.name+"Przy następnym razem przyniosę ci więcej opowieści.";
			link.l1 = "Dzięki! Cóż, czas, żebym ruszał w drogę.";
			link.l1.go = "exit";
			AddQuestRecord("Slavetrader", "22_2");
			pchar.questTemp.Slavetrader = "EscapeSlaveVillemstad_P";
		break;						

		case "Portugal":
			dialog.text = "Tak, to prawda. Złapali tego pirata. I możesz w to uwierzyć jak? Został schwytany na łodzi wiosłowej sam pośrodku morza. Nawet nie pisnął, zanim został wtrącony do ładowni dla szczurów. To naprawdę zabawne, wiesz, taki niebezpieczny pirat został złapany jak taki żółtodziób!";
			link.l1 = "A dlaczego był zupełnie sam na morzu?";
			link.l1.go = "Portugal_1";
		break;
		
		case "Portugal_1":
			dialog.text = "Zapewne postanowił rozstać się ze swymi zbójami, nie ma co... Nie mogli sprawiedliwie podzielić łupu. Teraz jest w rękach samej Kompanii, a ci nie mają poczucia humoru. Mówią, że przejął jeden z ich statków z czymś cennym. Najwyraźniej chcą tylko wydusić z niego trochę informacji, skoro jeszcze nie dynda na szubienicy.";
			link.l1 = "Kiedy będzie jego egzekucja, wiesz może?";
			link.l1.go = "Portugal_2";
		break;
		
		case "Portugal_2":
			dialog.text = "Nikt nie wie. Myślę, że gdy Kompania dowie się, czego chce, szybko zawiążą mu konopną pętlę na szyi. Portugalczyk jest teraz w więzieniu pod niezawodną strażą\nNiedawno przyprowadzili tu również jego bosmana. Jego historia była jeszcze bardziej zaskakująca, dobrowolnie oddał się w ręce Holendrów w Philipsburgu. Więc umieścili go w celi tuż obok jego byłego kapitana, teraz są sąsiadami, he-he...";
			link.l1 = "Cuda się zdarzają! Dobrze, będę wypatrywał wieści. Nie chcę przegapić tego wieszania. Do widzenia, "+npchar.name+"!";
			link.l1.go = "Portugal_3";
		break;
		
		case "Portugal_3":
			DialogExit();
			pchar.questTemp.Portugal = "PortugalInPrison";
			AddQuestRecord("Portugal", "32");
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
