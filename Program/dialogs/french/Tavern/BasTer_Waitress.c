// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Questions, "+GetAddress_Form(NPChar)+"?","Comment puis-je vous aider, "+GetAddress_Form(NPChar)+"?"),"Bonjour, mon ami."+GetSexPhrase("Hm, quelle est cette grande idée, "+GetAddress_Form(NPChar)+"? ","Encore avec les questions étranges ? Ma cocotte, va prendre du rhum ou quelque chose...")+"Understood, please provide the text you would like translated.","Tout au long de cette journée, c'est la troisième fois que tu parles de quelque question..."+GetSexPhrase(" Sont-ce là des signes d'attention ?","")+"","Plus de questions, je suppose, "+GetAddress_Form(NPChar)+"?","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("J'ai changé d'avis","Je n'ai rien à dire pour le moment."),"Non, non belle...","Non, cher...","Non, quelles questions ?...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
