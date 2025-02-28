// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Was denkst du über unser Fort? Sieht gut aus, ja? Und die Garnison ist noch nicht schlimmer, ha...","Das Leben eines Festungssoldaten ist ziemlich langweilig... Bewachen und patrouillieren, schlafen und ausruhen und dann das Ganze von vorne. Aber in der Stadt ist es anders... Was willst du, "+GetAddress_Form(NPChar)+"?"),"Es ist nicht willkommen, einen Soldaten mit dummen Fragen zu belästigen, "+GetAddress_Form(NPChar)+"...","Es ist das dritte Mal, dass du mich heute zu fragen versuchst...","Es ist nicht leicht, ein Soldat zu sein und doch bist du wieder hier"+GetSexPhrase(", Tölpel,  "," ")+" versuchen, mich zu ärgern. Sei vorsichtig, sonst landest du im Keller des Forts...","Block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Ich habe es mir anders überlegt, Entschuldigung, dass ich Sie belästigt habe.","Mir fällt nichts ein, Entschuldigungen."),"Du hast recht, ich entschuldige mich.","Du hast recht, es ist bereits das dritte Mal. Verzeih mir.","Es tut mir leid, es ist nichts.",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
