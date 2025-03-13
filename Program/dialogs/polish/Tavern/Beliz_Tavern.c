// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat("Wszystkie plotki o "+GetCityName(npchar.city)+" do usług. Czego chciałbyś się dowiedzieć?"," Właśnie o tym rozmawialiśmy. Musiałeś zapomnieć...","To już trzeci raz dzisiaj, kiedy mnie o to pytasz...","Powtarzasz to wszystko jak papuga...","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Wiesz, "+NPChar.name+"Może następnym razem.","Racja, zapomniałem z jakiegoś powodu...","Tak, to naprawdę już trzeci raz...","Aj...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			// Страж Истины
			if (CheckAttribute(pchar, "questTemp.Guardoftruth") && pchar.questTemp.Guardoftruth == "merdok" && !CheckAttribute(npchar, "quest.jino"))
			{
				link.l1 = "Słuchaj, czy do tego miasta przybył alchemik, lekarz? Jest Włochem, ma około trzydziestu lat, nazywa się Gino Gvineili?";
				link.l1.go = "guardoftruth";
			}
			// Калеуче
			if (CheckAttribute(pchar, "questTemp.Caleuche") && pchar.questTemp.Caleuche == "hunting" && !CheckAttribute(npchar, "quest.Caleuche"))
			{
				link.l1 = "Słuchaj, potrzebuję myśliwego o imieniu Fergus Hooper. Powiedziano mi, że mieszka tutaj. Gdzie mogę go znaleźć?";
				link.l1.go = "caleuche";
			}
		break;
		
		case "guardoftruth":
			dialog.text = LinkRandPhrase("Nie, nie słyszałem. Mamy zielarzy i lekarzy, ale żaden z nich nie ma takiego imienia.","To pierwszy raz, kiedy słyszę tak dziwne imię. Nie, nigdy nie odwiedził nas człowiek, o którym mówisz.","Nie mamy żadnych alchemików. Mamy lekarzy, ale żaden nie nosi takiego imienia.");
			link.l1 = "Widzę. To szkoda. Będę szukał dalej!";
			link.l1.go = "exit";
			npchar.quest.jino = "true";
		break;
		
		// Калеуче
		case "caleuche":
			dialog.text = "Fergus? Często odwiedza mnie. Ale od wczoraj jest w dżungli. Nie martw się, wróci za tydzień, pijąc rum i przechwalając się swoimi morskimi przygodami. Przyznaję jednak, że jest cholernie dobrym myśliwym. Nie znam nikogo, kto potrafi łapać węże tak dobrze jak on.";
			link.l1 = "Węże? Hm. Kiedy powinienem tu wrócić, żeby go znaleźć?";
			link.l1.go = "caleuche_1";
		break;
		
		case "caleuche_1":
			dialog.text = "Co najmniej trzy dni. Pamiętaj, że zawsze przychodzi tutaj nie wcześniej niż o szóstej wieczorem i wychodzi nie później niż o dziesiątej.";
			link.l1 = "Jak on wygląda? Nigdy go wcześniej nie widziałem.";
			link.l1.go = "caleuche_2";
		break;
		
		case "caleuche_2":
			dialog.text = "Brodaty, w średnim wieku, nosi brązowy płaszcz, kapelusz i długie buty.";
			link.l1 = "Dzięki! Bardzo mi pomogłeś, kamracie. Do zobaczenia wkrótce!";
			link.l1.go = "caleuche_3";
		break;
		
		case "caleuche_3":
			DialogExit();
			AddQuestRecord("Caleuche", "8");
			int iTerms = sti(pchar.questTemp.Caleuche.Belizterms);
			SetFunctionTimerCondition("Caleuche_FergusCome", 0, 0, iTerms, false);
			npchar.quest.Caleuche = "true";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
