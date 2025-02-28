// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    ref sld;
	switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Welche Art von Fragen, "+GetSexPhrase("junger Mann","junge Dame")+"?","Was brauchen Sie, "+GetSexPhrase("schön","hübscher")+"? Frag nur."),"Wieder Fragen?","Hihi, wenn es Ihnen recht ist - Fragen...",""+GetSexPhrase("Hm, warum suchst du dir nicht eine Schönheit aus? Ich fange an, Verdacht zu schöpfen...","Hm, warum wählst du nicht eine Schönheit für dich aus? Ich fürchte, wir haben hier keine Jungs, hihi...")+"","Block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Ich habe meine Meinung geändert, entschuldigen Sie mich.","Eigentlich, vergiss es..."),"Ich... Entschuldigung, ich habe im Moment keine Fragen.","Du hast recht, es ist bereits das dritte Mal. Entschuldige mich.","Vielleicht beim nächsten Mal, Madame.",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
