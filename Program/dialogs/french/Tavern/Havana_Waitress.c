// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
	switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Questions, "+GetAddress_Form(NPChar)+"?","Comment puis-je vous aider, "+GetAddress_Form(NPChar)+"?"),""+GetSexPhrase("Hm, quelle est la grande idée, "+GetAddress_Form(NPChar)+"? ","Encore avec les questions étranges ? Ma cocotte, va prendre du rhum ou quelque chose...")+"","Pendant toute cette journée, c'est la troisième fois que tu parles d'une certaine question..."+GetSexPhrase(" Sont-ce là des signes d'attention?","Got it! Please provide the text you want me to translate.")+"Bonjour, ami.","Plus de questions, je présume, "+GetAddress_Form(NPChar)+"?","bloc",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("J'ai changé d'avis","Je n'ai rien à discuter pour le moment."),"Non, non belle...","Pas question, ma chère...","Non, quelles questions ?...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
