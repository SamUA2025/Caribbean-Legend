// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Questions, "+GetAddress_Form(NPChar)+"?","Comment puis-je vous aider, "+GetAddress_Form(NPChar)+"?"),"Bonjour, monami."+GetSexPhrase("Hm, quelle est la grande idée, "+GetAddress_Form(NPChar)+"? ","Encore avec les questions étranges ? Ma grande, va prendre du rhum ou quelque chose comme ça...")+"","Pendant toute cette journée, c'est la troisième fois que tu parles d'une question..."+GetSexPhrase(" Est-ce là quelques signes d'attention ?","")+" ","Plus de questions, je présume, "+GetAddress_Form(NPChar)+"?","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("J'ai changé d'avis","Je n'ai rien à dire pour le moment."),"Non, non belle...","Pas question, ma chère...","Non, quelles questions ?...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
