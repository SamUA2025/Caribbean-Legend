// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Que pensez-vous de notre fort ? Il a fière allure, n'est-ce pas ? Et la garnison n'est pas encore pire, ha...","La vie de soldat de fort est bien monotone... Garder et patrouiller, dormir et se reposer puis recommencer. Mais c'est différent en ville... Que voulez-vous, "+GetAddress_Form(NPChar)+"?"),"Ennuyer un soldat avec des questions stupides n'est pas le bienvenu, "+GetAddress_Form(NPChar)+"...","C'est la troisième fois que tu essaies de me demander aujourd'hui...","Ce n'est pas facile d'être soldat et pourtant te voilà à nouveau"+GetSexPhrase(", connard,  "," ")+" essayer de m'énerver. Fais attention ou tu finiras dans les cachots du fort...","bloc",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("J'ai changé d'avis, désolé de vous déranger.","Je n'ai rien à dire, désolé."),"Tu as raison, je m'excuse.","Vous avez raison, c'est déjà la troisième fois. Pardonnez-moi.","Désolé, ce n'est rien.",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
