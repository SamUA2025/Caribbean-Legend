// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Jakie masz pytania?","Jak mogę ci pomóc?"),"Próbowałeś zadać mi pytanie jakiś czas temu...","Jeszcze nigdy nie spotkałem ludzi z taką ciekawością na mojej stoczni ani nigdzie indziej w tym mieście.","Co z tymi wszystkimi pytaniami? Moim zadaniem jest budowanie statków. Zajmijmy się tym.","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Zmieniam zdanie...","Nie mam teraz nic do omówienia."),"Umph, gdzież podziała się moja pamięć...","Hm, cóż...","Śmiało...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			if (CheckAttribute(pchar, "questTemp.Guardoftruth") && pchar.questTemp.Guardoftruth == "tortuga1")
			{
				link.l1 = "Szukam Gaiusa Marchaisa. Ostatnie, co o nim słyszałem, to że zadokował swoją galeon 'Santa Margarita' u ciebie do naprawy...";
                link.l1.go = "guardoftruth";
			}
		break;
		
		case "guardoftruth":
			dialog.text = "Jego własna galeon? Ho-ho, to dobry żart, kapitanie. Gaius Marchais miał tylko półmartwy szalupę... zdobył galeon jako łup, gdy postanowił zostać korsarzem. Szczęściarz, pierwszy najazd i taki trofeum\nOferowałem dobre pieniądze za nią, ale odmówił, wyobraź sobie to! Zamiast tego sprzedał swoją żałosną szalupę za małą sumę i użył jej do naprawy galeonu! Nowe żagle, nowe barwy i nowe imię, co zazwyczaj nie jest dobrym znakiem\nPewnie, imię było zbyt papieskie, ale moja córka też ma na imię Margarita, więc chyba było w porządku... Powiedział, że ma dość przemocy, więc zostanie handlowcem. I miał szczęście...";
			link.l1 = "Handel, przypuszczam, byłby spokojniejszy, ale papieskie galeony zazwyczaj nie są przechwytywane przez slupy. A jak się teraz nazywa jego nowy statek?";
			link.l1.go = "guardoftruth_1";
		break;
		
		case "guardoftruth_1":
			dialog.text = "'Wspaniała'... Nic dziwnego! Biegał wokół swojego nowego galeonu, jakby gonił za narzeczoną, nie mógł przestać się nią zachwycać.";
			link.l1 = "Rozumiem. Czy Gaius jest teraz na Tortudze?";
			link.l1.go = "guardoftruth_2";
		break;
		
		case "guardoftruth_2":
			dialog.text = "Nie. Wypłynął na nowym statku i wciąż nie wrócił na Tortugę. Nie wiem, dokąd się udał, więc nie mogę ci pomóc w tej sprawie.";
			link.l1 = "Co za niedogodność... Naprawdę go potrzebuję. Powinniśmy nawet wypić rundkę za jego 'godną podziwu' łajbę. W każdym razie, dzięki za informację.";
			link.l1.go = "guardoftruth_3";
		break;
		
		case "guardoftruth_3":
			dialog.text = "O, nie ma problemu. Wpadnij ponownie, kapitanie. I nie zapomnij, że zawsze jest tu wolne miejsce dla twojego statku, jeśli potrzebne są jakieś naprawy!";
			link.l1 = "... ";
			link.l1.go = "exit";
			AddQuestRecord("Guardoftruth", "9");
			pchar.questTemp.Guardoftruth = "tortuga2";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
