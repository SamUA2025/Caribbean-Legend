// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Welche Art von Fragen?","Was willst du, "+GetAddress_Form(NPChar)+"?"),"Fragen schon wieder, "+GetAddress_Form(NPChar)+"...","Fragen, Fragen... Wie wär's mit Handel, "+GetAddress_Form(NPChar)+"hä?","Hör zu, wie lange planst du zu reden?","Block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Keine Fragen für jetzt...","Entschuldigung, ich habe jetzt nichts zu sagen..."),"Noch einmal, Entschuldigung...","Vielleicht ist es wirklich Zeit zum Handeln...","Es tut mir leid, lass uns handeln...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
