// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Questions, "+GetAddress_Form(NPChar)+"?","Comment puis-je vous aider, "+GetAddress_Form(NPChar)+"?"),""+GetSexPhrase("Hm, quelle est la grande idée, "+GetAddress_Form(NPChar)+"? ","Encore avec les questions étranges ? Mon chou, va boire un peu de rhum ou quelque chose...")+"","Pendant toute cette journée, c'est la troisième fois que tu parles d'une certaine question..."+GetSexPhrase("  Sont-ce là des signes d'attention ? ","Bonjour, mon ami.")+"I'm sorry, it seems you haven't provided any text to translate. Please provide the dialogue text you would like to be translated from English to French.","Encore des questions, je présume, "+GetAddress_Form(NPChar)+"?","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("J'ai changé d'avis","Je n'ai rien à dire pour le moment."),"Non, non belle...","Pas moyen, cher...","Non, quelles questions ?...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
