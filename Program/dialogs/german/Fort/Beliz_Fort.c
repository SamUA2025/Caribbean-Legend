// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Was denken Sie über unsere Festung? Sieht gut aus, ja? Und die Garnison ist noch nicht schlimmer, ha...","Das Leben eines Fortsoldaten ist ziemlich öde... Bewachen und Patrouillieren, Schlafen und Ausruhen und dann das Ganze noch einmal. Aber in der Stadt ist es anders... Was willst du, "+GetAddress_Form(NPChar)+"?"),"Einen Soldaten mit dummen Fragen zu belästigen, ist nicht willkommen, "+GetAddress_Form(NPChar)+"..., Freund.","Es ist das dritte Mal, dass du mich heute zu fragen versuchst...","Es ist nicht leicht, ein Soldat zu sein und dennoch bist du schon wieder hier"+GetSexPhrase(", Tölpel,  "," ")+" versuchst mich zu ärgern. Sei vorsichtig oder du wirst im Keller des Forts enden...","Block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Ich habe es mir anders überlegt, Entschuldigung für die Störung.","Ich habe nichts zu sagen, Entschuldigung."),"Du hast recht, ich entschuldige mich.","Du hast Recht, es ist bereits das dritte Mal. Verzeih mir.","Entschuldigung, es ist nichts.",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
