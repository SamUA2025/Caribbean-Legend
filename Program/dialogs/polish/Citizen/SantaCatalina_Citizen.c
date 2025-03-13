// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
            dialog.text = RandPhraseSimple("Jakie to pytania?","Czego chcesz?");
			link.l1 = RandPhraseSimple("Zmieniłem zdanie.","Nie mam teraz nic do powiedzenia.");
		    link.l1.go = "exit";
		break;
		
		case "info":
			dialog.text = LinkRandPhrase("Kim się interesujesz?","Kogo masz na myśli?","Kimże to jest?");
			if (CheckAttribute(pchar, "questTemp.Saga"))
			{
				link.l1 = "Chcę dowiedzieć się więcej o Janie Svensonie.";
				link.l1.go = "svenson";
			}
			link.l2 = "Zmieńmy temat...";
			link.l2.go = "new question";
		break;
		
		case "town":
			dialog.text = LinkRandPhrase("Dokąd chcesz się udać?","Czego szukasz?","Czego dokładnie potrzebujesz?");
			if (CheckAttribute(pchar, "questTemp.Saga"))
			{
				link.l1 = "Gdzie jest dom Jana Svensona?";
				link.l1.go = "svenson_house";
			}
			link.l2 = "Zmieńmy temat...";
			link.l2.go = "new question";
		break;
		
		case "svenson":
			dialog.text = RandPhraseSimple("Oh, nasz Jan Svenson to bardzo ważna persona. W przeszłości był najdzielniejszym piratem Zachodnich Mórz, a nawet teraz jeszcze nie zardzewiał, ha! Ale te dni już minęły, nie jest już tak aktywny jak kiedyś. Posiada posiadłość i mieszka tam ze swoją młodą żoną, a w rezydencji gubernatora zawsze jest mile widzianym gościem. Do Jana przychodzi wielu gości, głównie piraci.","Jan Svenson to legenda Zachodniego Main! Diabeł Lasu, tak go nazywali Hiszpanie, gdy ich stąd wypędzał. Był słynnym korsarzem, ale teraz jest szanowanym obywatelem naszej kolonii\nChociaż nadal zajmuje się 'biznesem' z boku, ale już nie własnymi rękami. Rzadko opuszcza swój dom, odkąd poślubił młodą piękność.");
			link.l1 = "Dzięki.";
			link.l1.go = "exit";
		break;
		
		case "svenson_house":
			dialog.text = RandPhraseSimple("Idź prosto od przystani, aż zobaczysz plac, dom po prawej stronie przy fontannie to rezydencja Svensona.","Idź na nabrzeże przez plac z rezydencji gubernatora, dom po lewej stronie koło fontanny to rezydencja Svensona.");
			link.l1 = "Dzięki.";
			link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
