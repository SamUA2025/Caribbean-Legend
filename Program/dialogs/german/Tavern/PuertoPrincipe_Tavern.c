// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Welche Fragen haben Sie?","Wie kann ich Ihnen helfen, "+GetAddress_Form(NPChar)+"?"),"Du hast versucht, mir vor kurzem eine Frage zu stellen, "+GetAddress_Form(NPChar)+"...","Über den ganzen Tag hinweg ist das das dritte Mal, dass du über irgendeine Frage sprichst...","Noch mehr Fragen, nehme ich an?","Block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Ich habe es mir anders überlegt...","Ich habe im Moment nichts zu besprechen."),"Hmpf, wo ist mein Gedächtnis hin...","Ja, es ist wirklich das dritte Mal...","Nein, welche Fragen?...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
