// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Fragen, "+GetAddress_Form(NPChar)+"?","Wie kann ich Ihnen helfen, "+GetAddress_Form(NPChar)+"?"),""+GetSexPhrase("Hm, was soll das Große, "+GetAddress_Form(NPChar)+"? ","Wieder mit den seltsamen Fragen? Toots, geh und trink etwas Rum oder so...")+"","Im Laufe des ganzen Tages ist dies das dritte Mal, dass du über irgendeine Frage sprichst..."+GetSexPhrase("Sind das einige Zeichen der Aufmerksamkeit?","")+"","Noch mehr Fragen, nehme ich an, "+GetAddress_Form(NPChar)+"?","Block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Ich habe meine Meinung geändert","Ich habe im Moment nichts zu besprechen."),"Nein, nein, schönes...","Keine Chance, Liebchen...","Nein, welche Fragen?...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;


	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
