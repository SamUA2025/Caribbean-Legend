// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Was wünscht Ihr? Fragt nur.","Ich höre zu, was ist die Frage?"),"Dies ist das zweite Mal, dass Sie versuchen zu fragen...","Das ist das dritte Mal, dass Sie versuchen zu fragen...","Wann wird das endlich vorbei sein?! Ich bin ein beschäftigter Mann, arbeite an Kolonialangelegenheiten und Sie belästigen mich immer noch!","Block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Ich habe meine Meinung geändert, Entschuldigung.","Nicht jetzt. Falscher Ort und Zeit."),"Wahrlich, ich habe jetzt nichts zu sagen, Entschuldigung.","Ich werde später fragen.","Es tut mir leid, "+GetAddress_FormToNPC(NPChar)+"...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
