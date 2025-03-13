// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Que pensez-vous de notre fort ? Il a fière allure, n'est-ce pas ? Et la garnison n'est pas pire pour l'instant, ha...","La vie de soldat de fort est assez ennuyeuse... Monter la garde et patrouiller, dormir et se reposer puis recommencer encore. Mais c'est différent en ville... Que veux-tu, "+GetAddress_Form(NPChar)+"?"),"Importuner un soldat avec des questions stupides n'est pas bienvenu, "+GetAddress_Form(NPChar)+"... ","C'est la troisième fois que vous essayez de me demander aujourd'hui...","Ce n'est pas facile d'être soldat et pourtant te revoilà."+GetSexPhrase(", crétin,  "," ")+" essayer de me mettre en colère. Fais attention ou tu pourrais finir dans les cachots du fort...","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("J'ai changé d'avis, désolé de vous déranger.","Je n'ai rien à dire, mes excuses."),"Vous avez raison, je m'excuse.","Tu as raison, c'est déjà la troisième fois. Pardonne-moi.","Désolé, ce n'est rien.",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
