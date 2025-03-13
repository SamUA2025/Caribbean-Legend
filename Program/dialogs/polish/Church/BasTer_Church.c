// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Jakie pytania, "+GetSexPhrase("mój synu","moja córka")+"?","Pytaj, słucham cię..."),"Słucham, mów teraz, "+GetSexPhrase("mój synu","moja córka")+"...","Po raz trzeci, "+GetSexPhrase("mój synu","moja córka")+", poproś o to, czego potrzebujesz.","Duchowny ma dużo pracy, a ty mnie rozpraszasz, "+GetSexPhrase("mój synu","moja córka")+"...","blokada",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Zmieniłem zdanie...","Nie teraz, ojcze..."),"Nie mam nic do powiedzenia, przepraszam.","Zapytam, ale później. Wybacz mi, ojcze.","Proszę mi wybaczyć, święty ojcze...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";		
			if (CheckAttribute(pchar, "questTemp.Guardoftruth") && pchar.questTemp.Guardoftruth == "utensil" && !CheckAttribute(npchar, "quest.utensil"))
			{
				link.l1 = "Przychodzę do ciebie w sprawie niezwykłej, święty ojcze. Kaper imieniem Guy Marchais niedawno przekazał twojej parafii bardzo cenną rzecz. Był to złoty krzyż piersiowy z lazurytem osadzonym w nim. Czy to prawda?";
                link.l1.go = "guardoftruth";
			}
		break;
		
		case "guardoftruth":
			dialog.text = "O tak, mój synu! To najlepszy przedmiot w naszej parafii. Nigdy w życiu nie widziałem takiego przepychu! Ale dlaczego pytasz, mój synu? Dlaczego interesujesz się tym krzyżem?";
			link.l1 = "Ojcze święty, wiem, że to Ci się nie spodoba, ale ten krzyż został skradziony z innej parafii, a duchowny został zamordowany podczas tego czynu. Człowiek, który przedstawił Ci ten przedmiot, jest mordercą.";
			link.l1.go = "guardoftruth_1";
		break;
		
		case "guardoftruth_1":
			dialog.text = "Wszyscy grzeszymy, mój synu, a zabójstwo duchownego to poważne oskarżenie. Masz jakieś dowody? Z której parafii został skradziony ten krzyż?";
			link.l1 = "Czy moje słowo nie jest wystarczającym dowodem? Ten krzyż został skradziony z parafii w Santiago i musi zostać zwrócony.";
			link.l1.go = "guardoftruth_2";
		break;
		
		case "guardoftruth_2":
			dialog.text = "Santiago? Czyż to nie jest hiszpańskie miasto? Mój synu, zaskakujesz mnie...";
			link.l1 = "Ojcze święty, wszyscy są równi przed Bogiem. Hiszpanie są chrześcijanami tak jak my, a nieporozumienia między narodami nie powinny dotyczyć uczuć wierzących. Błagam cię, abyś zwrócił ten krzyż parafii Santiago.";
			link.l1.go = "guardoftruth_3";
		break;
		
		case "guardoftruth_3":
			dialog.text = "Mój synu, czyż nie rozumiesz, że ten krzyż to dar od miłujących chrześcijan dla naszej parafii?! Nie, mój synu, nie mogę uczynić tego, o co prosisz.";
			link.l1 = "Nie obchodzi cię, że nad tym krzyżem rozlano krew? Krew duchownego, hiszpańskiego czy nie, to bez znaczenia.";
			link.l1.go = "guardoftruth_4";
		break;
		
		case "guardoftruth_4":
			dialog.text = "Mój synu, nie pokazałeś żadnych dowodów i nie mogę ślepo zaufać twemu słowu. Krzyż pozostanie w naszej parafii. To moja ostateczna decyzja. Poza tym, twój wysiłek w pomaganiu Hiszpanom w tej sprawie mocno mnie niepokoi.";
			link.l1 = "Niech tak będzie, Żegnaj więc, święty ojcze...";
			link.l1.go = "guardoftruth_5";
		break;
		
		case "guardoftruth_5":
			DialogExit();
			npchar.quest.utensil = "true";
			pchar.questTemp.Guardoftruth.Baster_church = "seek";
			AddQuestRecord("Guardoftruth", "27");
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
