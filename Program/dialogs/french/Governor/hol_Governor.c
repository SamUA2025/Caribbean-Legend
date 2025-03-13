// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    ref sld;
    int i, tempQty, chComp, iShip, iBaseType;
    string tempStr;
    switch (Dialog.CurrentNode)
	{
		case "quests":
			//Португалец
			if (CheckAttribute(pchar, "questTemp.Portugal.Villemstad") && pchar.location == "villemstad_townhall")
			{
				dialog.text = RandPhraseSimple("Quel genre de questions ?","Que désirez-vous ?");
				link.l1 = "Je sais que la Compagnie néerlandaise des Indes occidentales a fixé un bon prix pour la tête du célèbre pirate - Bartolomeo le Portugais. J'ai réussi à le capturer. Il est actuellement dans la cale de mon navire et je suis prêt à le remettre aux autorités.";
				link.l1.go = "Portugal";
				break;
			}
            dialog.text = RandPhraseSimple("Quel genre de questions ?","Que voulez-vous ?");
			link.l1 = RandPhraseSimple("Rien d'important, Monsieur.","Je n'ai rien à dire, pardonnez-moi.");
		    link.l1.go = "exit";
		break;
		
		case "work_1":  // работа на благо короны - линейка нации
			if (CheckAttribute(npchar, "notQuestLine"))
			{
                dialog.text = "Malheureusement, je ne peux pas vous considérer pour un emploi. Vous n'êtes pas quelqu'un avec qui je veux travailler pour le moment. Adieu.";
                link.l1 = "Vous ne pouvez pas être sérieux.. mais très bien.";
                link.l1.go = "exit";
				break;
			}                   
		break;
		
		//Португалец
		case "Portugal":
			dialog.text = "Bart le Portugais ?! L'avez-vous ? Vivant ?";
			link.l1 = "Je sais que tu n'as pas besoin qu'il soit mort. Il est en vie. J'ai dû faire beaucoup d'efforts pour le garder ainsi !";
			link.l1.go = "Portugal_1";
		break;
		
		case "Portugal_1":
			dialog.text = "Excellente nouvelle ! Maintenant, il nous dira tout... Monsieur, préparez le prisonnier pour le transfert. Nous enverrons une barque militaire à votre navire immédiatement. ";
			link.l1 = "Je voudrais d'abord parler de ma récompense, monsieur... Si cela ne vous dérange pas.";
			link.l1.go = "Portugal_2";
		break;
		
		case "Portugal_2":
			dialog.text = "N'ayez crainte pour votre récompense, capitaine. Vous l'obtiendrez. Nous avons fixé un prix pour la tête de Bartolomeo le Portugais - mille cinq cents doublons. Lieutenant ! Apportez au capitaine sa récompense !";
			link.l1 = "Hm... Il semble que Hugo m'ait menti à propos de deux mille doublons... Fort bien.";
			link.l1.go = "Portugal_3";
		break;
		
		case "Portugal_3":
			TakeNItems(pchar, "gold_dublon", 1500);
			Log_Info("You have received 1500 doubloons");
			PlaySound("interface\important_item.wav");
			dialog.text = "Et maintenant, capitaine, seriez-vous assez aimable pour transférer le Portugais à la Compagnie. Nous avons hâte de lui parler.";
			link.l1 = "Bien sûr, monsieur, envoyez la barque à mon navire.";
			link.l1.go = "Portugal_4";
		break;
		
		case "Portugal_4":
			DialogExit();
			DoQuestReloadToLocation("Villemstad_town", "reload", "reload1", "Portugal_Final");
			DeleteAttribute(pchar, "questTemp.Portugal.Villemstad");
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
