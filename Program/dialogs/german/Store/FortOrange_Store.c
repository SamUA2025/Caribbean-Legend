// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
	switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Welche Fragen haben Sie?","Wie kann ich Ihnen helfen?"),"Du hast versucht, mir vor kurzem eine Frage zu stellen, als du im Laden warst...","Das ist die dritte Frage heute. Ich muss Geschäfte machen, nicht sinnlose Gespräche führen...","Noch mehr Fragen? Wie wäre es stattdessen mit einem Handel?","Block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Ich habe meine Meinung geändert...","Ich habe im Moment nichts zu besprechen."),"Ja, das stimmt. Ich habe es versucht... Während ich im Laden war...","Ja, es ist die dritte Frage...","Hm, vielleicht können wir einen Handel abschließen...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;				
	}
	UnloadSegment(NPChar.FileDialog2);
}
