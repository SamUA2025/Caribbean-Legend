// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Questions, "+GetAddress_Form(NPChar)+"?","Comment puis-je vous aider, "+GetAddress_Form(NPChar)+"?"),"Bonjour, mon ami."+GetSexPhrase("Hum, quelle est cette grande idée, "+GetAddress_Form(NPChar)+"? ","Encore avec les questions étranges ? Ma belle, va boire un peu de rhum ou quelque chose...")+"Bonjour, mon ami.","Pendant toute cette journée, c'est la troisième fois que tu parles d'une question..."+GetSexPhrase(" Est-ce là des signes d'attention ?","Bonjour, mon ami.")+"","Plus de questions, je présume, "+GetAddress_Form(NPChar)+"?","bloc",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("J'ai changé d'avis","Je n'ai rien à discuter pour le moment."),"Non, non belle...","Non mon cher...","Non, quelles questions ?...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;


	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
