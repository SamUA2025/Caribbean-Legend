// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Was wünschen Sie? Fragen Sie nur.","Ich höre zu, was ist die Frage?"),"Das ist das zweite Mal, dass du versuchst zu fragen...","Das ist das dritte Mal, dass Sie versuchen zu fragen...","Wann wird das endlich vorbei sein?! Ich bin ein beschäftigter Mann, der an Kolonialangelegenheiten arbeitet und Sie stören mich immer noch!","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Ich habe meine Meinung geändert, tut mir leid.","Nicht jetzt. Falscher Ort und Zeit."),"Wahrlich, ich habe jetzt nichts zu sagen, Verzeihung.","Ich werde später fragen.","Es tut mir leid, "+GetAddress_FormToNPC(NPChar)+"...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;

		case "Cupture_after":
            dialog.text = RandPhraseSimple("Sie haben bereits alles genommen. Was wollen Sie noch?","Gibt es noch etwas, das Sie nicht gegriffen haben?");
            link.l1 = RandPhraseSimple("Nur mal umschauen...","Nur zur Kontrolle, ich könnte vergessen haben etwas mitzunehmen...");
            link.l1.go = "exit";
            NextDiag.TempNode = "Cupture_after";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
