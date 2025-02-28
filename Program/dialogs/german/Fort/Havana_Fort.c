// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Was denken Sie über unsere Festung? Sieht gut aus, ja? Und die Garnison ist noch nicht schlechter, ha...","Das Leben eines Fortsoldaten ist ziemlich eintönig... Bewachen und Patrouillieren, Schlafen und Ausruhen und dann wieder von vorne. Aber in der Stadt ist es anders... Was willst du, "+GetAddress_Form(NPChar)+"?"),"Einen Soldaten mit dummen Fragen zu belästigen, ist nicht willkommen, "+GetAddress_Form(NPChar)+"...","Es ist das dritte Mal, dass du mich heute zu fragen versuchst...","Es ist nicht einfach, ein Soldat zu sein und doch bist du wieder hier"+GetSexPhrase(", Schuft,  "," ")+" versuchst mich zu verärgern. Sei vorsichtig oder du landest im Keller der Festung...","Blockieren",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Ich habe es mir anders überlegt, Entschuldigung für die Störung.","Ich habe nichts zu sagen, Entschuldigung."),"Du hast recht, ich entschuldige mich.","Du hast recht, es ist bereits das dritte Mal. Verzeih mir.","Es tut mir leid, es ist nichts.",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
