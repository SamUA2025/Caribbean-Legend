// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Welche Art von Fragen?","Was willst du, "+GetAddress_Form(NPChar)+"?"),"Du hast bereits versucht, mir eine Frage zu stellen "+GetAddress_Form(NPChar)+"...","Sie sprechen heute zum dritten Mal über dieselbe Frage...","Sieh mal, wenn du mir nichts über die Angelegenheiten des Hafens zu erzählen hast, dann belästige mich nicht mit deinen Fragen.","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Ich habe meine Meinung geändert.","Ich habe nichts zu besprechen."),"Macht nichts.","Tatsächlich, schon das dritte Mal...","Entschuldigung, aber ich interessiere mich momentan nicht für die Angelegenheiten des Hafens.",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			if (CheckAttribute(pchar, "questTemp.Guardoftruth") && pchar.questTemp.Guardoftruth == "maarten1")
			{
				link.l1 = "Ich suche nach einer Galeone namens 'Admirable' unter französischer Flagge. Ihr Kapitän hieß Gaius Marchais. Können Sie mir sagen, wohin er als nächstes gesegelt ist? Vielleicht hat er sich hier registriert?";
                link.l1.go = "guardoftruth";
			}
		break;
		
		case "guardoftruth":
			dialog.text = "Hmmm, 'Bewundernswert'? Galeone? Ich erinnere mich. Lass mal sehen...wir haben sie gechartert, um Paprika nach Bridgetown auf Barbados zu liefern. Ist etwas passiert?";
			link.l1 = "Nein, aber Gaius ist mein Freund und ich freue mich darauf, ihn zu treffen.";
			link.l1.go = "guardoftruth_1";
		break;
		
		case "guardoftruth_1":
			dialog.text = "Dann segel nach Barbados. Aber ich bezweifle, dass du ihn dort finden wirst, es war vor langer Zeit. Zumindest kannst du den örtlichen Hafenmeister um Hilfe bitten.";
			link.l1 = "Weg bin ich wieder, schätze ich.";
			link.l1.go = "guardoftruth_2";
		break;
		
		case "guardoftruth_2":
			DialogExit();
			AddQuestRecord("Guardoftruth", "12");
			pchar.questTemp.Guardoftruth = "barbados";
		break;

	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
