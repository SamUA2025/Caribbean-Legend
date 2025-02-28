// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Welche Fragen haben Sie?","Wie kann ich Ihnen helfen?"),"Du hast versucht, mir vor einiger Zeit eine Frage zu stellen...","Ich habe noch nie Menschen mit solcher Neugier in meiner Werft oder anderswo in dieser Stadt getroffen.","Was ist mit all den Fragen? Meine Aufgabe ist es, Schiffe zu bauen. Kümmern wir uns darum.","Block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Ich habe meine Meinung geändert...","Ich habe im Moment nichts zu besprechen."),"Mmph, wohin ist mein Gedächtnis verschwunden...","Hm, nun...","Mach weiter...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
