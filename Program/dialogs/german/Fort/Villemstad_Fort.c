// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Was denken Sie über unser Fort? Sieht gut aus, ja? Und die Garnison ist noch nicht schlimmer, ha...","Das Leben eines Fortsoldaten ist ziemlich eintönig... Bewachen und patrouillieren, schlafen und ruhen und dann das Ganze immer wieder. Aber in der Stadt ist es anders... Was willst du, "+GetAddress_Form(NPChar)+"?"),"Einen Soldaten mit dummen Fragen zu belästigen, ist nicht willkommen, "+GetAddress_Form(NPChar)+"...","Es ist das dritte Mal, dass du heute versuchst, mich zu fragen...","Es ist nicht einfach, ein Soldat zu sein und doch bist du wieder hier"+GetSexPhrase(", Tölpel,  "," ")+" versuchst mich zu verärgern. Sei vorsichtig, sonst landest du im Keller des Forts...","Block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Ich habe es mir anders überlegt, Entschuldigung für die Störung.","Mir ist nichts zu sagen, Entschuldigungen."),"Du hast recht, ich entschuldige mich.","Du hast recht, es ist bereits das dritte Mal. Entschuldige mich.","Entschuldigung, es ist nichts.",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
