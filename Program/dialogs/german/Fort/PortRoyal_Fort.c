// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Was denkst du über unsere Festung? Sieht gut aus, ja? Und die Garnison ist noch nicht schlechter, ha...","Das Leben eines Fortsoldaten ist ziemlich eintönig... Bewachen und Patrouillieren, Schlafen und Ausruhen und dann wieder das Gleiche. Aber in der Stadt ist es anders... Was willst du, "+GetAddress_Form(NPChar)+"?"),"Einen Soldaten mit dummen Fragen zu belästigen, ist nicht willkommen, "+GetAddress_Form(NPChar)+"...","Das ist das dritte Mal, dass du mich heute zu fragen versuchst ...","Es ist nicht einfach, ein Soldat zu sein und doch bist du wieder hier"+GetSexPhrase(", Tölpel,  "," ")+" versucht mich zu verärgern. Seien Sie vorsichtig oder Sie landen im Keller des Forts...","Block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Ich habe meine Meinung geändert, Entschuldigung für die Störung.","Es tut mir leid, ich habe nichts zu sagen."),"Du hast recht, ich entschuldige mich.","Du hast recht, es ist schon das dritte Mal. Entschuldige mich.","Entschuldigung, es ist nichts.",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
