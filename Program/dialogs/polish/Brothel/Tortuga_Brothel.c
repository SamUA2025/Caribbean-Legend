// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    ref sld;
	switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Jakiego rodzaju pytania, "+GetSexPhrase("młody człowieku","młoda dama")+"?","Czego potrzebujesz, "+GetSexPhrase("przystojniaku","sliczna")+"Proszę pytać."),"Znowu pytania?","Hehe, jeśli to dla ciebie bez różnicy - pytania...",""+GetSexPhrase("Hm, czemużbyś sobie nie wybrał piękności? Zaczynam mieć co do ciebie podejrzenia...","Hm, czemuż nie wybierzesz sobie piękności? Obawiam się, że nie mamy tu chłopców, hihihi...")+" ","blokada",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Zmieniłem zdanie, wybacz mi.","Właściwie, nieważne..."),"Ja... przepraszam, nie mam pytań, na razie.","Masz rację, to już trzeci raz. Wybacz mi.","Może następnym razem, Madame.",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
