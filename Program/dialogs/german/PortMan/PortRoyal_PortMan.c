// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Welche Art von Fragen?","Was willst du, "+GetAddress_Form(NPChar)+"?"),"Du hast bereits versucht, mir eine Frage zu stellen "+GetAddress_Form(NPChar)+"...","Sie sprechen heute zum dritten Mal über eine Frage...","Schau, wenn du mir nichts über die Angelegenheiten des Hafens zu erzählen hast, dann belästige mich nicht mit deinen Fragen.","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Ich habe meine Meinung geändert.","Ich habe nichts zu besprechen."),"Macht nichts.","Tatsächlich, schon das dritte Mal...","Entschuldigung, aber ich habe momentan kein Interesse an den Angelegenheiten des Hafens.",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			
			if (pchar.questTemp.Slavetrader == "FindRatJamaica")
            {
                link.l1 = "Guten Tag. Hat Kapitän Francois Gontier sich hier registriert? Er segelte von Porto Bello auf einer Korvette namens '"+pchar.questTemp.Slavetrader.ShipName+"'.";
                link.l1.go = "Jamaica_ratPP_1";
            }
			
		break;
		
		case "Jamaica_ratPP_1":
			dialog.text = NPCStringReactionRepeat("Nein, hat er nicht. Und die Korvette '"+pchar.questTemp.Slavetrader.ShipName+"' wurde in Port-Royal nicht gesehen.","Sie haben bereits danach gefragt und ich habe geantwortet.","Ich sage Ihnen, dass Sie bereits nach diesem Gontier Kerl gefragt haben.","Bitte, lenken Sie mich nicht von meiner Arbeit ab!","block",0,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Danke. Ich werde weiter suchen.","Hm, nun...","Ja, ich habe wirklich gefragt ...","Entschuldigung, "+npchar.name+"...",npchar,Dialog.CurrentNode);
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
