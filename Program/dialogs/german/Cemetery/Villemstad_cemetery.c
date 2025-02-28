// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Wie kann ich Ihnen helfen?","Was kann ich für Sie tun?"),"Sag mir, was dich bedrückt, "+GetAddress_Form(NPChar)+"?","Zum dritten Mal, "+GetAddress_Form(NPChar)+", was brauchen Sie?","Ich habe genug von dir. Raus!","Blockieren",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Ich habe meine Meinung geändert, meine Entschuldigung.","Es ist nichts, entschuldigen Sie mich."),"Verzeih mir, es ist nichts.","Du hast recht, es ist bereits das dritte Mal. Entschuldige mich...","Entschuldigungen.",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2); 
}
