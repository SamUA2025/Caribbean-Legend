// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Was halten Sie von unserem Fort? Sieht gut aus, ja? Und die Garnison ist nicht schlechter, ha...","Das Leben eines Fortsoldaten ist ziemlich langweilig... Wache halten und Patrouillieren, Schlafen und Ruhen und dann das Ganze von vorne. Aber in der Stadt ist es anders... Was wollen Sie, "+GetAddress_Form(NPChar)+"?"),"Einen Soldaten mit dummen Fragen zu belästigen, ist nicht gern gesehen, "+GetAddress_Form(NPChar)+"...","Es ist das dritte Mal, dass Sie heute versuchen, mich zu belästigen...","Es ist nicht einfach, ein Soldat zu sein, und doch sind Sie schon wieder hier"+GetSexPhrase(", Sie Tölpel,  "," ")+" und versuchen, mich zu verärgern. Seid vorsichtig, sonst enden Sie im Kerker des Forts...","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Ich habe meine Meinung geändert, entschuldigen Sie die Störung.","Ich habe nichts zu sagen, Entschuldigung."),"Sie haben recht, ich entschuldige mich.","Sie haben recht, es ist bereits das dritte Mal. Entschuldigt mich.","Entschuldigung, es ist nichts.",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
