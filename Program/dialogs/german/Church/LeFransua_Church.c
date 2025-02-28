// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
            dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Welche Art von Fragen, "+GetSexPhrase("mein Sohn","meine Tochter")+"?","Frag nur, ich höre zu..."),"Ich höre zu, sprich jetzt, "+GetSexPhrase("mein Sohn","meine Tochter")+"..., Freund.","Zum dritten Mal, "+GetSexPhrase("mein Sohn","meine Tochter")+", fragen Sie nach dem, was Sie brauchen.","Ein Geistlicher hat viel Arbeit und Sie lenken mich ab, "+GetSexPhrase("mein Sohn","meine Tochter")+"...","Block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Ich habe meine Meinung geändert...","Nicht zu dieser Zeit, Padre..."),"Ich habe nichts zu sagen, entschuldigung.","Ich werde fragen, aber später. Verzeih mir, Vater.","Verzeihen Sie mir, heiliger Vater...",npchar,Dialog.CurrentNode);
		    link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
