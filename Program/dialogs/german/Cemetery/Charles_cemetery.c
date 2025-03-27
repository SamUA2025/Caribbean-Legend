// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Wie kann ich Ihnen helfen?","Was kann ich für Sie tun?"),"Erzählen Sie, was Sie bedrückt, "+GetAddress_Form(NPChar)+"?","Zum dritten Mal, "+GetAddress_Form(NPChar)+", was brauchen Sie?","Ich habe genug von Ihnen. Verschwinden Sie!","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Ich habe meine Meinung geändert, Entschuldigung.","Es gibt nichts, entschuldigen Sie mich."),"Verzeihen Sie, es gibt nichts.","Sie haben recht, es ist bereits das dritte Mal. Verzeihen Sie...","Entschuldigung.",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2); 
}
