// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    ref sld;
	switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Jakiego rodzaju pytania, "+GetSexPhrase("młody człowieku","młoda damo")+"?","Czego potrzebujesz, "+GetSexPhrase("przystojniaku","ślicznotko")+"Proszę, pytaj."),"Znowu pytania?","Tee-hee, jeśli to dla ciebie bez różnicy - jakie pytania..."," "+GetSexPhrase("Hm, dlaczego nie wybierzesz sobie jakiejś piękności? Zaczynam mieć wobec ciebie podejrzenia...","Hm, a czemuż by nie wybrać sobie piękności? Obawiam się, że chłopców tu nie mamy, hi-hi...")+"","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Zmieniłem zdanie, przepraszam.","Właściwie, nieważne..."),"Ja... przepraszam, na razie nie mam pytań.","Masz rację, to już trzeci raz. Wybacz mi.","Może następnym razem, Droga Pani.",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
