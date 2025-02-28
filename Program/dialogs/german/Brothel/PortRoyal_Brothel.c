// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    ref sld;
	switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Welche Art von Fragen, "+GetSexPhrase("junger Mann","junge Dame")+"?","Was brauchen Sie, "+GetSexPhrase("schön","hübscher")+"? Frag ruhig."),"Schon wieder Fragen?","Hihi, wenn es Ihnen recht ist - Fragen...",""+GetSexPhrase("Hm, warum wählst du dir nicht eine Schönheit aus? Ich fange an, Verdächtigungen gegen dich zu hegen...","Hm, warum suchst du dir nicht eine Schönheit aus? Wir haben hier leider keine Jungs, hihi...")+"","Block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Ich habe es mir anders überlegt, entschuldigen Sie mich.","Eigentlich, vergiss es..."),"Ich ... Entschuldigung, ich habe im Moment keine Fragen.","Du hast recht, es ist schon das dritte Mal. Verzeih mir.","Vielleicht nächstes Mal, Madame.",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
