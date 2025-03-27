// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Was willst du? Frag nur.","Ich höre zu, was ist die Frage?"),"Das ist das zweite Mal, dass du versuchst zu fragen...","Dies ist das dritte Mal, dass Sie versuchen zu fragen...","Wann wird das endlich aufhören?! Ich bin ein beschäftigter Mann, der sich um Kolonialangelegenheiten kümmert und Sie belästigen mich immer noch!","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Ich habe meine Meinung geändert, es tut mir leid.","Nicht jetzt. Falscher Ort und Zeit."),"Wahrlich, ich habe jetzt nichts zu sagen, Verzeihung.","Ich werde später fragen.","Es tut mir leid, "+GetAddress_FormToNPC(NPChar)+"...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;

		case "Cupture_after":
            dialog.text = RandPhraseSimple("Du hast bereits alles genommen. Was willst du noch?","Gibt es noch etwas, das Sie nicht gegriffen haben?");
            link.l1 = RandPhraseSimple("Nur einen Blick herumwerfen...","Nur zur Überprüfung, ich könnte vergessen haben, etwas mitzunehmen...");
            link.l1.go = "exit";
            NextDiag.TempNode = "Cupture_after";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
