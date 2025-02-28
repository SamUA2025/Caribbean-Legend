// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Was halten Sie von unserer Festung? Sieht gut aus, ja? Und die Garnison ist noch nicht schlimmer, ha...","Das Leben eines Fortsoldaten ist ziemlich eintönig... Bewachen und Patrouillieren, Schlafen und Ausruhen und dann das Ganze von vorne. Aber in der Stadt ist es anders... Was wollen Sie, "+GetAddress_Form(NPChar)+"?"),"Es ist nicht erwünscht, einen Soldaten mit dummen Fragen zu belästigen, "+GetAddress_Form(NPChar)+"...","Es ist das dritte Mal, dass du heute versuchst, mich zu fragen...","Es ist nicht einfach, ein Soldat zu sein, und trotzdem bist du wieder hier"+GetSexPhrase(", Schurke,  "," ")+" versuchst mich zu ärgern. Sei vorsichtig, sonst landest du im Keller des Forts...","Blockieren",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Ich habe es mir anders überlegt, Entschuldigung für die Störung.","Ich habe nichts zu sagen, Entschuldigung."),"Du hast recht, ich entschuldige mich.","Du hast recht, es ist bereits das dritte Mal. Entschuldige mich.","Entschuldigung, es ist nichts.",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
