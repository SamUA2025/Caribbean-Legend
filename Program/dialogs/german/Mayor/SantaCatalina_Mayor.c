// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Was wünschen Sie? Fragen Sie los.","Ich höre zu, was ist die Frage?"),"Das ist das zweite Mal, dass Sie versuchen zu fragen...","Dies ist das dritte Mal, dass Sie versuchen zu fragen...","Wann wird das endlich aufhören?! Ich bin ein beschäftigter Mann, der sich um Kolonialangelegenheiten kümmert und Sie belästigen mich immer noch!","Block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Ich habe meine Meinung geändert, Entschuldigung.","Nicht jetzt. Falscher Ort und Zeit."),"Wahrlich, ich habe jetzt nichts zu sagen, Entschuldigung.","Ich werde später fragen.","Es tut mir leid, "+GetAddress_FormToNPC(NPChar)+"...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;

		case "Cupture_after":
            dialog.text = RandPhraseSimple("Du hast bereits alles genommen. Was willst du noch?","Gibt es noch etwas, das du nicht geschnappt hast?");
            link.l1 = RandPhraseSimple("Nur mal umsehen...","Nur zur Kontrolle, ich könnte vergessen haben, etwas mitzunehmen...");
            link.l1.go = "exit";
            NextDiag.TempNode = "Cupture_after";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
