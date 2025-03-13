// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Que voulez-vous ? Demandez donc.","Je vous écoute, quelle est la question ?"),"C'est la deuxième fois que vous essayez de demander...","C'est la troisième fois que vous essayez de demander...","Quand cela va-t-il se terminer ?! Je suis un homme occupé, travaillant sur les affaires de la colonie et vous continuez de me déranger !","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("J'ai changé d'avis, désolé.","Pas maintenant. Mauvais endroit et mauvais moment."),"Vrai, je n'ai rien à dire pour l'instant, désolé.","Je demanderai, plus tard.","Je suis désolé, "+GetAddress_FormToNPC(NPChar)+"... ",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			//Португалец
			if (CheckAttribute(pchar, "questTemp.Portugal.Villemstad"))
			{
				link.l1 = "Je sais que la Compagnie néerlandaise des Indes occidentales a mis un prix sur la tête d'un certain pirate - Bartolomeo le Portugais. J'ai réussi à le capturer. Il est actuellement dans ma cale et je suis prêt à le remettre aux autorités.";
                link.l1.go = "Portugeze";
			}
		break;

		case "Cupture_after":
            dialog.text = RandPhraseSimple("Vous avez déjà tout pris. Que voulez-vous de plus ?","Y a-t-il quelque chose que vous n'avez pas pris ?");
            link.l1 = RandPhraseSimple("Je ne fais que jeter un oeil...","Je vérifie juste, j'ai peut-être oublié de prendre quelque chose...");
            link.l1.go = "exit";
            NextDiag.TempNode = "Cupture_after";
		break;
		
		//Португалец
		case "Portugeze":
			dialog.text = "Bart le Portugais ?! Vous l'avez, vivant ?!";
			link.l1 = "Je sais qu'il ne te servira à rien s'il est mort. Il est vivant et, par tous les diables, j'ai dû me retenir pour le garder ainsi !";
			link.l1.go = "Portugeze_1";
		break;
		
		case "Portugeze_1":
			dialog.text = "Excellentissime ! Maintenant, il nous dira tout... Monsieur, préparez le prisonnier pour le transfert. Nous enverrons une barque militaire à votre navire immédiatement. ";
			link.l1 = "Je voudrais d'abord parler de ma récompense, Mynheer, si cela ne vous dérange pas.";
			link.l1.go = "Portugeze_2";
		break;
		
		case "Portugeze_2":
			dialog.text = "Ne vous inquiétez pas pour votre récompense, Monsieur. Vous l'aurez. Nous avons fixé un prix pour la tête de Bartolomeo le Portugais - mille cinq cents doublons. Lieutenant ! Apportez la récompense au capitaine !";
			link.l1 = "Hm... Hugo m'a dit que c'était deux mille doublons... Très bien alors.";
			link.l1.go = "Portugeze_3";
		break;
		
		case "Portugeze_3":
			TakeNItems(pchar, "gold_dublon", 1500);
			Log_Info("You have received 1500 doubloons");
			PlaySound("interface\important_item.wav");
			dialog.text = "Et maintenant, Monsieur, auriez-vous l'amabilité de transférer le Portugais à la Compagnie ? Nous sommes si impatients de lui parler.";
			link.l1 = "Bien sûr, Monsieur, envoyez la barque à mon navire.";
			link.l1.go = "Portugeze_4";
		break;
		
		case "Portugeze_4":
			DialogExit();
			DoQuestReloadToLocation("Villemstad_town", "reload", "reload1", "Portugal_Final");
			DeleteAttribute(pchar, "questTemp.Portugal.Villemstad");
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
