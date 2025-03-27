// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    ref sld;
	switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Was für Fragen, "+GetSexPhrase("junger Mann","junge Dame")+"?","Was brauchen Sie, "+GetSexPhrase("schöner","hübsche")+"? Fragen Sie nur."),"Wieder Fragen?","Tee-hee, wenn es Ihnen recht ist - fragen Sie...",""+GetSexPhrase("Hm, warum suchen Sie sich nicht eine Schönheit aus? Ich fange an, Sie zu verdächtigen, dass Sie etwas im Schilde führen...","Hm, warum wählen Sie nicht eine Schönheit aus? Jungs haben wir hier leider nicht, hihi...")+"","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Ich habe es mir anders überlegt, entschuldigen Sie mich.","Eigentlich, ach vergessen Sie es..."),"Ich... Entschuldigung, ich habe im Moment keine Fragen.","Sie haben recht, es ist bereits das dritte Mal. Verzeihen Sie mir.","Vielleicht nächstes Mal, Madame.",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
