// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Was denken Sie über unsere Festung? Sieht gut aus, ja? Und die Garnison ist noch nicht schlechter, ha...","Das Leben eines Fortsoldaten ist ziemlich langweilig... Wachen und patrouillieren, schlafen und ausruhen und dann das Ganze noch einmal. Aber in der Stadt ist es anders... Was wollen Sie, "+GetAddress_Form(NPChar)+"?"),"Es ist nicht willkommen, einen Soldaten mit dummen Fragen zu belästigen, "+GetAddress_Form(NPChar)+"...","Das ist das dritte Mal, dass du heute versuchst, mich etwas zu fragen...","Es ist nicht einfach, ein Soldat zu sein, und dennoch bist du wieder hier"+GetSexPhrase(", Tölpel,  "," ")+" versuche mich zu ärgern. Sei vorsichtig, sonst landest du im Keller des Forts...","Block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Es tut mir leid, ich habe meine Meinung geändert, es tut mir leid, Sie zu belästigen.","Es tut mir leid, ich habe nichts zu sagen."),"Du hast recht, ich entschuldige mich.","Du hast recht, es ist bereits das dritte Mal. Verzeih mir.","Entschuldigung, es ist nichts.",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
