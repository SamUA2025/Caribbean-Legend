// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    ref sld;
	switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Jakiego rodzaju pytania, "+GetSexPhrase("młody człowieku","młoda dama")+"?","Czego potrzebujesz, "+GetSexPhrase("przystojniaku","ślicznotko")+"Proszę pytać."),"Znowu pytania?","He-he, jeśli to ci nie przeszkadza - pytania...",""+GetSexPhrase("Hm, czemu nie wybierzesz sobie jakiejś piękności? Zaczynam mieć podejrzenia co do ciebie...","Hm, czemu nie wybierzesz sobie piękności? Niestety, nie mamy tu chłopców, hi-hi...")+"","blokada",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Zmieniałem zdanie, przepraszam.","Właściwie, nieważne..."),"Ja... przepraszam, na razie nie mam pytań.","Masz rację, to już trzeci raz. Wybacz mi.","Może następnym razem, Madam.",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
