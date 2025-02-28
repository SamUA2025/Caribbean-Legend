// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Welche Art von Fragen?","Was willst du, "+GetAddress_Form(NPChar)+"?"),"Du hast schon versucht, mir eine Frage zu stellen "+GetAddress_Form(NPChar)+"..., Freund.","Du sprichst heute zum dritten Mal über dieselbe Frage...","Schau, wenn du mir nichts über die Angelegenheiten des Hafens zu erzählen hast, dann belästige mich nicht mit deinen Fragen.","Block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Ich habe meine Meinung geändert.","Ich habe nichts zu besprechen."),"Macht nichts.","Tatsächlich, schon das dritte Mal...","Es tut mir leid, aber ich bin im Moment nicht an den Angelegenheiten des Hafens interessiert.",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			
			if (pchar.questTemp.Slavetrader == "FindRatTortuga")
            {
                link.l1 = "Guten Tag. Ich suche nach Francois Gontier. Seine Korvette '"+pchar.questTemp.Slavetrader.ShipName+"' muss hier in eurem Hafen gewesen sein.";
                link.l1.go = "Tortuga_ratP_1";
            }
			
		break;

		case "Tortuga_ratP_1":
			dialog.text = NPCStringReactionRepeat("Hm... Ich muss Sie enttäuschen. Die Korvette '"+pchar.questTemp.Slavetrader.ShipName+" war noch nie hier und Francois Gontier hat sich hier auch nicht registriert.","Sie haben bereits danach gefragt und ich habe geantwortet.","Ich sage Ihnen, dass Sie bereits nach diesem Gontier gefragt haben.","Bitte, lenken Sie mich nicht von meiner Arbeit ab!","Block",0,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Danke. Ich werde weiter suchen.","Hm, nun...","Ja, ich habe wirklich gefragt ...","Entschuldigung, "+npchar.name+"...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;

	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
