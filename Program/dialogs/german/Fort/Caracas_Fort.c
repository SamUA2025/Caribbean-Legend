// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Was halten Sie von unserem Fort? Sieht gut aus, ja? Und die Garnison ist noch nicht schlechter, ha...","Das Leben eines Fortsoldaten ist ziemlich langweilig... Bewachen und Patrouillieren, Schlafen und Ausruhen und dann wieder von vorn. Aber in der Stadt ist es anders... Was wollen Sie, "+GetAddress_Form(NPChar)+"?"),"Einen Soldaten mit dummen Fragen zu belästigen, ist nicht willkommen, "+GetAddress_Form(NPChar)+"...","Das ist das dritte Mal, dass du mich heute zu fragen versuchst...","Es ist nicht leicht, ein Soldat zu sein und doch bist du schon wieder hier"+GetSexPhrase(", Tölpel,  "," ")+" versuche mich zu ärgern. Sei vorsichtig, sonst landest du im Keller der Festung...","Block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Ich habe meine Meinung geändert, Entschuldigung für die Störung.","Ich habe nichts zu sagen, Entschuldigungen."),"Du hast recht, ich entschuldige mich.","Sie haben recht, es ist bereits das dritte Mal. Entschuldigen Sie mich.","Entschuldigung, es ist nichts.",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
