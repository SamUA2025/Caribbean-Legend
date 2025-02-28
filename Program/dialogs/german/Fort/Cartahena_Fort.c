// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Was halten Sie von unserem Fort? Sieht gut aus, ja? Und die Garnison ist noch nicht schlechter, ha...","Das Leben eines Fortsoldaten ist ziemlich langweilig... Wachen und Patrouillieren, Schlafen und Ausruhen und dann alles wieder von vorne. Aber in der Stadt ist es anders... Was wollen Sie, "+GetAddress_Form(NPChar)+"?"),"Es ist nicht willkommen, einen Soldaten mit dummen Fragen zu belästigen, "+GetAddress_Form(NPChar)+"...","Es ist das dritte Mal, dass du heute versuchst, mich zu fragen...","Es ist nicht einfach, ein Soldat zu sein, und dennoch bist du schon wieder hier"+GetSexPhrase(", Schuft,  "," ")+" versuchst mich zu verärgern. Sei vorsichtig oder du landest im Keller des Forts...","Block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Ich habe meine Meinung geändert, entschuldigen Sie die Störung.","Es tut mir leid, ich habe nichts zu sagen."),"Du hast recht, ich entschuldige mich.","Du hast recht, es ist schon das dritte Mal. Entschuldige mich.","Entschuldigung, es ist nichts.",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
