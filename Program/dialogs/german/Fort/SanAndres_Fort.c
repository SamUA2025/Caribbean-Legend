// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Was halten Sie von unserer Festung? Sieht gut aus, ja? Und die Garnison ist noch nicht schlechter, ha...","Das Leben eines Fortsoldaten ist ziemlich langweilig... Bewachen und patrouillieren, schlafen und ausruhen und dann das Ganze von vorne. Aber in der Stadt ist es anders... Was willst du, "+GetAddress_Form(NPChar)+"?"),"Es ist nicht willkommen, einen Soldaten mit dummen Fragen zu belästigen, "+GetAddress_Form(NPChar)+"...","Das ist das dritte Mal, dass du mich heute zu fragen versuchst...","Es ist nicht einfach, ein Soldat zu sein und doch bist du schon wieder hier"+GetSexPhrase(", Schuft,  "," ")+" versuchst mich zu verärgern. Sei vorsichtig, sonst landest du im Keller des Forts...","Block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Ich habe meine Meinung geändert, entschuldigen Sie die Störung.","Es tut mir leid, ich habe nichts zu sagen."),"Du hast recht, ich entschuldige mich.","Du hast recht, es ist bereits das dritte Mal. Verzeih mir.","Entschuldigung, es ist nichts.",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
