// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    ref sld;
	switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Welche Art von Fragen, "+GetSexPhrase("junger Mann","junge Dame")+"?","Was benötigen Sie, "+GetSexPhrase("schön","hübscher")+"? Fragen Sie ruhig."),"Wieder Fragen?","Hihi, wenn es Ihnen nichts ausmacht - Fragen...",""+GetSexPhrase("Hm, warum suchst du dir nicht eine Schönheit aus? Ich fange an, Verdacht zu schöpfen...","Hm, warum wählst du dir nicht eine Schönheit aus? Fürchte, wir haben hier keine Jungs, hihi...")+"","Block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Ich habe meine Meinung geändert, entschuldigen Sie mich.","Eigentlich, vergiss es..."),"Ich... entschuldige mich, ich habe im Moment keine Fragen.","Du hast recht, es ist schon das dritte Mal. Verzeih mir.","Vielleicht nächstes Mal, Madame.",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
