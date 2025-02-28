// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Welche Art von Fragen?","Was willst du, "+GetAddress_Form(NPChar)+"?"),"Du hast schon versucht, mir eine Frage zu stellen "+GetAddress_Form(NPChar)+"...","Du sprichst heute zum dritten Mal über eine Frage...","Schau, wenn du mir nichts über die Angelegenheiten des Hafens zu erzählen hast, dann belästige mich nicht mit deinen Fragen.","Block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Ich habe meine Meinung geändert.","Ich habe nichts zu besprechen."),"Macht nichts.","In der Tat, schon das dritte Mal...","Entschuldigung, aber ich interessiere mich momentan nicht für die Angelegenheiten des Hafens.",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;

	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
