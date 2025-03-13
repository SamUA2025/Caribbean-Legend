// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Que pensez-vous de notre fort ? Il a fière allure, n'est-ce pas ? Et la garnison n'est pas pire pour autant, ha...","La vie d'un soldat de fort est plutôt monotone... Garder et patrouiller, dormir et se reposer, et puis rebelote. Mais c'est différent en ville... Que voulez-vous, "+GetAddress_Form(NPChar)+"?"),"Enquiquiner un soldat avec des questions stupides n'est pas apprécié, "+GetAddress_Form(NPChar)+"... ","C'est la troisième fois que vous essayez de me demander aujourd'hui...","Ce n'est pas facile d'être soldat et pourtant te revoilà."+GetSexPhrase(", crétin,  "," ")+" essaie de m'énerver. Fais attention ou tu finiras dans un cachot du fort...","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("J'ai changé d'avis, désolé de vous déranger.","Je n'ai rien à dire, désolé."),"Tu as raison, je m'excuse.","Vous avez raison, c'est déjà la troisième fois. Pardonnez-moi.","Désolé, ce n'est rien.",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
