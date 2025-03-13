// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Que voulez-vous? Demandez donc.","Je vous écoute, quelle est la question ?"),"C'est la deuxieme fois que vous essayez de demander...","C'est la troisième fois que vous essayez de demander...","Quand cela va-t-il finir ?! Je suis un homme occupé, travaillant sur les affaires de la colonie et vous continuez à me déranger !","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("J'ai changé d'avis...","Pas maintenant. Mauvais endroit et mauvais moment."),"Vrai... Mais plus tard, pas maintenant...","Je demanderai... Mais un peu plus tard...","Je suis désolé, "+GetAddress_FormToNPC(NPChar)+"... ",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			// Jason НСО
			if (CheckAttribute(pchar, "questTemp.Patria") && pchar.questTemp.Patria == "epizode_2" && !CheckAttribute(npchar, "quest.patria") && !CheckAttribute(pchar, "questTemp.Patria.Visiter_Late"))
			{
				link.l1 = TimeGreeting()+" Monsieur. Je suis ici sur ordre du Gouverneur Général Chevalier de Poincy. Ma tâche est de livrer un baron du nom de Noel Forget à la Tortue, qui est arrivé de la métropole avec pour mission d'inspecter les colonies, son but principal étant de créer une Compagnie française des Indes occidentales. Permettez-moi de vous le présenter... Il vous expliquera tous les détails lui-même.";
                link.l1.go = "patria_portpax";
			}
			// Rebbebion, квест "Путеводная звезда"
			if (CheckAttribute(pchar, "questTemp.PZ.PortPaxMayorTalk"))
			{
				link.l1 = "Votre Seigneurie, vous vouliez me voir ?";
				link.l1.go = "PZ1";
			}
		break;

		case "Cupture_after":
            dialog.text = RandPhraseSimple("Tu as déjà tout pris. Que veux-tu d'autre ?","Y a-t-il quelque chose que vous n'avez pas pris ?");
            link.l1 = RandPhraseSimple("Je jette juste un coup d'œil...","Je vérifie juste, je pourrais oublier de prendre quelque chose...");
            link.l1.go = "exit";
            NextDiag.TempNode = "Cupture_after";
		break;
		
		// Jason НСО
		case "patria_portpax":
			dialog.text = "Je suis très heureux de vous rencontrer, Capitaine Charles de Maure, ainsi que le Baron. Je ferai tout pour que le séjour de Monsieur Forget dans notre colonie soit aussi confortable que possible. Et profitant du fait qu'un Monsieur de si haut rang m'a rendu visite, je vous adresserai une requête pour une affaire.";
			link.l1 = "Très intéressant ! Parlez-nous de votre affaire, votre Grâce.";
			link.l1.go = "patria_portpax_1";
		break;
		
		case "patria_portpax_1":
			dialog.text = "Ces derniers mois, notre colonie n'a reçu la visite d'aucun représentant du Gouverneur-Général, comme s'ils nous avaient complètement oubliés à Saint-Kitts ! Et pendant ce temps, les Espagnols, désireux de rendre l'ensemble de l'Hispaniola purement espagnol et pour qui les colons français et les boucaniers à l'ouest de l'île sont une grande nuisance, préparent une attaque ! Mes officiers de patrouille, nos capitaines marchands et même de simples pêcheurs ont rapporté qu'une puissante escadre espagnole se rassemble à Santiago et qu'elle se prépare à attaquer Port-au-Prince !";
			link.l1 = "Les preuves sont-elles assez claires, votre Majesté ?";
			link.l1.go = "patria_portpax_2";
		break;
		
		case "patria_portpax_2":
			dialog.text = "Je n'ai pas de renseignements précis, mais une telle abondance d'informations provenant de personnes totalement aléatoires ne peut être de simples rumeurs. Notre colonie est très importante pour la France, nous avons ici les meilleures plantations, que le baron peut voir de ses propres yeux. Perdre cette colonie ou même l'exposer au risque d'être pillée est inacceptable !";
			link.l1 = "Je prendrai vos preuves en compte et informerai le Chevalier de Poincy. Je suis sûr qu'il prendra des mesures immédiates.";
			link.l1.go = "patria_portpax_3";
		break;
		
		case "patria_portpax_3":
			dialog.text = "Merci, capitaine...";
			link.l1 = "";
			link.l1.go = "patria_portpax_4";
		break;
		
		case "patria_portpax_4":
			DialogExit();
			sld = characterFromId("Noel");
			sld.dialog.currentnode = "noel_9";
			ChangeCharacterAddressGroup(sld, pchar.location, "goto", "governor1");
			LAi_SetActorType(sld);
			LAi_ActorDialogDelay(sld, pchar, "", 1.0);
			npchar.quest.patria = "true";
		break;
		
		case "PZ1":
			DeleteAttribute(pchar, "questTemp.PZ.PortPaxMayorTalk");
			dialog.text = "Non, je ne vous ai pas convoqué, monsieur. Vouliez-vous quelque chose?";
			link.l1 = "How could I? But your messenger met us; he said you had prepared one of the houses in the town for me...";
			link.l1.go = "PZ2";
			DelLandQuestMark(npchar);
		break;
		
		case "PZ2":
			dialog.text = "Quelle maison, quel messager, quelle est cette insolence?!";
			link.l1 = "Que voulez-vous dire, quel messager... Il s'appelle Henri Thibaut, et...";
			link.l1.go = "PZ3";
		break;
		
		case "PZ3":
			dialog.text = "QUOI ? Sais-tu seulement qui il est ? Apparemment non. Mais cela n'a pas d'importance. Que fait le neveu de Levasseur dans ma ville ?";
			link.l1 = "Oh, mon Dieu...";
			link.l1.go = "PZ4";
		break;
		
		case "PZ4":
			dialog.text = "De Maure, pouvez-vous m'entendre ? Monsieur ?";
			link.l1 = "...";
			link.l1.go = "PZ5";
		break;
		
		case "PZ5":
			DialogExit();
			LAi_SetActorType(pchar);
			LAi_ActorRunToLocator(pchar, "reload", "reload1", "PZ_SharleBezhitObratno", -1);
			bDisableCharacterMenu = true;
			InterfaceStates.Buttons.Save.enable = false;
			SetMusic("music_teleport");
			pchar.questTemp.lockedMusic = true;
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
