// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Welche Fragen haben Sie?","Wie kann ich Ihnen helfen?"),"Du hast versucht, mir diese Frage vor nicht allzu langer Zeit zu stellen...","Jawohl, lass mich raten... Wieder einmal im Kreis unterwegs?","Hör zu, ich mache hier die Finanzen, ich beantworte keine Fragen...","Block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Ich habe meine Meinung geändert...","Ich habe im Moment nichts zu besprechen."),"Hmm, wo ist mein Gedächtnis hin...","Du hast es erraten, es tut mir leid...","Ich verstehe...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
		
		// Реакция ростовщика Панамы на репутацию ГГ или на разграбление Картахены по сюжету
		case "Panama_Deposit_NoReputation":
			dialog.text = "Das ist richtig... Ein Mann von Ehre, der von den Untertanen des Königs geliebt wird, wird von meiner Bank nie abgelehnt, egal welche Nationalität er hat.";
			link.l1 = "Ich verstehe. Auf Wiedersehen.";
			link.l1.go = "exit";
		break;
		
		case "Panama_Deposit_Cartahena":
			dialog.text = "Aber meine Tochter und Schwiegervater hatten es, leider. Sie lebten in Cartagena. Geh weg, "+GetAddress_Form(NPChar)+". Du bist hier nicht willkommen.";
			if (pchar.questTemp.Mtraxx.Retribution.Choice == "good")
			{
				link.l1 = "Verzeih mir. Auf Wiedersehen.";
				link.l1.go = "exit";
			}
			else
			{
				link.l1 = "Dein Verlust. Auf Wiedersehen.";
				link.l1.go = "exit";
			}
			NextDiag.TempNode = "NeHochuRazgovarivat";
		break;
		
		case "Panama_Deposit_SgorelVklad":
			dialog.text = "Die Gelder wurden von der Krone beschlagnahmt, um den Opfern der Plünderung der Stadt Cartagena zu helfen. Ich kann Ihnen nicht helfen. Ich bitte Sie, meine Bank sofort zu verlassen, bevor ich die Wachen rufe!";
			link.l1 = "Du wirst das bereuen...";
			link.l1.go = "exit";
			NextDiag.TempNode = "NeHochuRazgovarivat";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
