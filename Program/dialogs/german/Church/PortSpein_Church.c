// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Welche Art von Fragen, "+GetSexPhrase("mein Sohn","meine Tochter")+"?","Frag nur, ich höre zu..."),"Ich höre zu, sprich jetzt, "+GetSexPhrase("mein Sohn","meine Tochter")+"..., Freund.","Zum dritten Mal, "+GetSexPhrase("mein Sohn","meine Tochter")+", fragen Sie nach dem, was Sie brauchen.","Ein Geistlicher hat viel Arbeit und Sie lenken mich ab, "+GetSexPhrase("mein Sohn","meine Tochter")+"...","Block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Ich habe meine Meinung geändert...","Nicht zu dieser Zeit, Padre..."),"Ich habe nichts zu sagen, entschuldigen Sie.","Ich werde fragen, aber später. Verzeih mir, Vater.","Verzeihen Sie mir, heiliger Vater...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			//Цена чахотки
			if (!CheckAttribute(npchar, "quest.Consumption") && CheckAttribute(pchar, "questTemp.Consumption.AskJuan"))
			{
				link.l1 = "Sagen Sie mir, heiliger Vater, klingt der Name 'Juan' Ihnen bekannt?";
				link.l1.go = "Consumption";
			}
		break;
		
		//Цена чахотки
		case "Consumption":
			dialog.text = "Das tut es, mein Sohn. Es gibt viele Gemeindemitglieder in dieser Stadt, die Juan heißen.";
			link.l1 = "Ich verstehe. Entschuldigung für die Störung, Padre...";
			link.l1.go = "exit";
			npchar.quest.Consumption = "true";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
