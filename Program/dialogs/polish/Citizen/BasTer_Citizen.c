// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
            dialog.text = RandPhraseSimple("Jakie pytania?","Czego chcesz?");
			link.l1 = RandPhraseSimple("Zmieniłem zdanie.","Nie mam teraz nic do powiedzenia.");
		    link.l1.go = "exit";
		break;
		
		case "info":
			dialog.text = LinkRandPhrase("Kim się interesujesz?","Kogo masz na myśli?","Cóż, kto to jest?");
			link.l1 = "Chcę dowiedzieć się więcej o Fadeju Moskalu.";
			link.l1.go = "fadey";
			link.l2 = "Nie ma nikogo, nieważne.";
			link.l2.go = "new question";
		break;
		
		case "town":
			dialog.text = LinkRandPhrase("Gdzie chcesz się udać?","Czego szukasz?","Czego dokładnie potrzebujesz?");
            link.l1 = "Gdzie jest dom Fadeya?";
			link.l1.go = "fadey_house";
			link.l2 = "Porozmawiajmy o czymś innym...";
			link.l2.go = "new question";
		break;
		
		case "fadey":
			dialog.text = RandPhraseSimple("Ach, ważny człowiek. Posiada lokalną fabrykę i jest blisko z elitą Basse-Terre. Ma silny akcent i bardzo lubi pić... ale nigdy się nie upija.","On jest ważną szychą i przyjacielem gubernatora. Fadey jest właścicielem miejscowej fabryki. Przybył z północnego kraju, daleko, daleko stąd... Nawet nie znam jego nazwy. Ma silne ręce i potrafi wypić całą beczkę rumu i się nie upije.");
			link.l1 = "Moje podziękowania.";
			link.l1.go = "exit";
		break;
		
		case "fadey_house":
			dialog.text = RandPhraseSimple("Idź prosto od nabrzeża, aż zobaczysz plac, dom po lewej to rezydencja Fadeya.","Idź na molo przez plac od rezydencji gubernatora, dom po prawej to rezydencja Fadeya.");
			link.l1 = "Dzięki.";
			link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
