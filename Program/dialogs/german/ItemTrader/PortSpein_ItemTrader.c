// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Welche Art von Fragen?","Was willst du, "+GetAddress_Form(NPChar)+"?"),"Wieder Fragen, "+GetAddress_Form(NPChar)+"...","Fragen, Fragen... Wie wäre es, wenn wir handeln, "+GetAddress_Form(NPChar)+"hä?","Hör zu, wie lange planst du zu reden?","Block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Keine Fragen für jetzt...","Entschuldigung, ich habe jetzt nichts zu sagen..."),"Nochmals Entschuldigung...","Vielleicht ist es wirklich Zeit zu handeln...","Es tut mir leid, lass uns handeln...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			//Цена чахотки
			if (!CheckAttribute(npchar, "quest.Consumption") && CheckAttribute(pchar, "questTemp.Consumption.AskJuan"))
			{
				link.l1 = "Hör mal, sagt dir der Name 'Juan' etwas?";
				link.l1.go = "Consumption";
			}			
		break;
		
		//Цена чахотки
		case "Consumption":
			dialog.text = "Nein, tut es nicht... Jetzt stör mich bitte nicht, ich bin ziemlich beschäftigt... Was für eine idiotische Frage...";
			link.l1 = "Ich verstehe. Entschuldigung für die Zeitverschwendung...";
			link.l1.go = "exit";
			npchar.quest.Consumption = "true";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
