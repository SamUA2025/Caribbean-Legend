// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Fragen, "+GetAddress_Form(NPChar)+"?","Wie kann ich Ihnen helfen, "+GetAddress_Form(NPChar)+"?"),""+GetSexPhrase("Hm, was ist die große Idee, "+GetAddress_Form(NPChar)+"? ","Wieder mit den seltsamen Fragen? Schnucki, geh doch etwas Rum trinken oder so...")+"","Über den ganzen Tag hinweg ist dies das dritte Mal, dass du über irgendeine Frage redest..."+GetSexPhrase("Sind das einige Zeichen von Aufmerksamkeit?","")+"","Mehr Fragen, nehme ich an, "+GetAddress_Form(NPChar)+"?","Block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Ich habe meine Meinung geändert","Ich habe im Moment nichts zu besprechen."),"Nein, nein schön...","Nein.","Nein, welche Fragen?...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;


	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
