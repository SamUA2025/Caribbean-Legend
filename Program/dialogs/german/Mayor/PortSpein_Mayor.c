// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Was wollen Sie? Fragen Sie los.","Ich höre zu, was ist die Frage?"),"Das ist das zweite Mal, dass Sie versuchen zu fragen...","Das ist das dritte Mal, dass Sie versuchen zu fragen...","Wann wird das enden?! Ich bin ein beschäftigter Mann, der sich mit Kolonieangelegenheiten beschäftigt und Sie stören mich immer noch!","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Ich habe meine Meinung geändert, Entschuldigung.","Nicht jetzt. Falscher Ort und Zeitpunkt."),"Wahrlich, ich habe jetzt nichts zu sagen, Entschuldigung.","Ich werde später fragen.","Es tut mir leid, "+GetAddress_FormToNPC(NPChar)+"...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			if (!CheckAttribute(npchar, "quest.Guardoftruth") && CheckAttribute(pchar, "questTemp.Guardoftruth.Trinidad") && pchar.questTemp.Guardoftruth.Trinidad == "begin")
			{
				link.l1 = "Eure Exzellenz, im April 1654 stand eine Fregatte unter dem Kommando von Miguel Dichoso. Seitdem ist er verschwunden. Erinnern Sie sich an ihn? Vielleicht hat er Sie besucht, hat gesprochen...";
				link.l1.go = "guardoftruth";
			}
		break;
		
		case "guardoftruth":
			dialog.text = "Ja, ich erinnere mich an diesen Mann. Aber ich erinnere mich nicht an irgendwelche Details über ihn. Er kam hierher und dann ging er einfach weg. Ich kann Ihnen nicht helfen.";
			link.l1 = "Ich verstehe. Entschuldigung für die Störung.";
			link.l1.go = "exit";
			npchar.quest.guardoftruth = "true";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
