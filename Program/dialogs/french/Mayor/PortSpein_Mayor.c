// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Que veux-tu? Demande ce que tu veux.","Je vous écoute, quelle est la question ?"),"C'est la deuxieme fois que vous essayez de demander...","C'est la troisième fois que tu essaies de demander...","Quand cela va-t-il se terminer ?! Je suis un homme occupé, travaillant sur les affaires de la colonie et tu continues à m'importuner !","bloc",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("J'ai changé d'avis, désolé.","Pas maintenant. Mauvais endroit et mauvais moment."),"Vrai, je n'ai rien à dire maintenant, désolé.","Je demanderai, plus tard.","Je suis désolé, "+GetAddress_FormToNPC(NPChar)+"...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			if (!CheckAttribute(npchar, "quest.Guardoftruth") && CheckAttribute(pchar, "questTemp.Guardoftruth.Trinidad") && pchar.questTemp.Guardoftruth.Trinidad == "begin")
			{
				link.l1 = "Votre Excellence, il y avait une frégate sous le commandement de Miguel Dichoso en avril 1654. Il a disparu depuis. Vous souvenez-vous de quelque chose à son sujet ? Peut-être vous a-t-il rendu visite, a-t-il eu une conversation...";
				link.l1.go = "guardoftruth";
			}
		break;
		
		case "guardoftruth":
			dialog.text = "Oui, je me souviens de cet homme. Mais je ne me rappelle aucun détail à son sujet. Il est venu ici puis il est simplement parti. Je ne peux pas vous aider.";
			link.l1 = "Je vois. Désolé de vous déranger.";
			link.l1.go = "exit";
			npchar.quest.guardoftruth = "true";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
