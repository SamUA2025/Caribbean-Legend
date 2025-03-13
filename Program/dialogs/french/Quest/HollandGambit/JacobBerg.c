// Якоб ван Берг - злодей и пират, капитан Миража
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			if (CheckAttribute(pchar, "questTemp.HWIC.Holl") && pchar.questTemp.HWIC.Holl == "JacobInRoom")
			{
				dialog.text = "Argh ! Hic... Qui diable es-tu ? Où est ce maudit Chinois ? Je te parle, es-tu sourd ? Hic !";
				link.l1 = "Je t'entends fort et clair, alors ne crie pas. Aucun Chinois ne viendra. Je suis ici à sa place.";
				link.l1.go = "HollJacob_inRoom";
				DelLandQuestMark(npchar);
				break;
			}
			dialog.text = "Un bug. Informez les développeurs.";
			link.l1 = "Si vous le dites...";
			link.l1.go = "exit";
			NextDiag.TempNode = "First time";
		break;

		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		case "HollJacob_inRoom":
			dialog.text = "Quoi ? Qui es-tu ? Qu'est-ce que tu fous ici ? Je t'ai posé une question, vermine !";
			link.l1 = "Tu n'as pas besoin de savoir ça. J'ai besoin de ton navire.";
			link.l1.go = "HollJacob_inRoom_1";			
		break;
		
		case "HollJacob_inRoom_1":
			dialog.text = "Argh... Quoi?! Tu es foutrement... attends! Tu es un foutu chien anglais! Merde alors! Ils m'ont retrouvé après tout... Fin de la ligne pour toi ! Je ne vais pas me rendre !";
			link.l1 = "Eh bien, je n'ai pas besoin que tu te rendes...";
			link.l1.go = "HollJacob_inRoom_fight";			
		break;
		
		case "HollJacob_inRoom_fight":
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.questTemp.HWIC.Holl.JacobCity+"_tavern_upstairs")], false);
			pchar.quest.JacobOnMainOver.over = "yes";//снять таймер
			chrDisableReloadToLocation = true;
			LAi_group_MoveCharacter(npchar, "EnemyFight");
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
            LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
            LAi_group_SetCheck("EnemyFight", "HollJacob_dead");
			DialogExit();
			AddDialogExitQuest("MainHeroFightModeOn");	
		break;
		
		case "JacobBerg_abordage":
			if (CheckAttribute(pchar, "questTemp.HWIC.Eng"))
			{
				dialog.text = "Argh! Putain! Quel bordel! Tu n'es pas un marchand, n'est-ce pas?";
				link.l1 = "Un garçon si malin. Mon équipage est composé de marines anglais triés sur le volet, donc tu étais foutu dès le début. Richard Fleetwood et moi avions inventé l'histoire du marchand et te voilà. Tes aventures sont terminées, salaud !";
				link.l1.go = "JacobBerg_abordage_1";
			}
			else
			{
				dialog.text = "Enfin nous nous sommes rencontrés, capitaine. Vous êtes un gars astucieux... Cela fait trop longtemps que je n'ai rencontré un adversaire aussi sérieux.";
				link.l1 = "Et je suis ton dernier adversaire, Jacob. Tu ne quitteras pas cet endroit vivant.";
				link.l1.go = "JacobBerg_abordage_3";
			}
		break;
		
		case "JacobBerg_abordage_1":
			dialog.text = "On dirait bien. Ton équipage a capturé le navire et je ne compte pas être épargné. Mais je vais t'envoyer en enfer avant qu'ils ne viennent te secourir ! Van Berg va vendre sa peau à un prix élevé !";
			link.l1 = "C'est seulement ton opinion. Je pense que ta vie ne vaut pas un seul sou. Assez de ces mots, prépare-toi !";
			link.l1.go = "JacobBerg_abordage_2";			
		break;
		
		case "JacobBerg_abordage_2":
			LAi_SetCurHPMax(NPChar);
			LAi_GetCharacterMaxEnergy(NPChar);			
			QuestAboardCabinDialogExitWithBattle(""); 
			DialogExit();	
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		
		case "JacobBerg_abordage_3":
			dialog.text = "Oh vraiment ? J'ai fait en sorte que tu ne t'échappes pas. J'ai allumé une mèche menant à la soute à poudre. Bientôt nos navires seront réduits en miettes.";
			link.l1 = "Je pense que seul toi et ta vieille barcasse allez sauter. Je vais te vider, libérer mon navire, et admirer le feu d'artifice en m'éloignant à la voile.";
			link.l1.go = "JacobBerg_abordage_4";			
		break;
		
		case "JacobBerg_abordage_4":
			dialog.text = "Pas si je te tue d'abord, saute par la fenêtre, nage jusqu'au rivage et regarde les feux d'artifice moi-même !";
			link.l1 = "Mise ?";
			link.l1.go = "JacobBerg_abordage_5";			
		break;
		
		case "JacobBerg_abordage_5":
			LAi_SetCurHPMax(NPChar);
			LAi_GetCharacterMaxEnergy(NPChar);			
			QuestAboardCabinDialogExitWithBattle("PrepareToBoom2"); 
			DialogExit();	
			AddDialogExitQuest("MainHeroFightModeOn");
			pchar.GenQuest.Detonation = true; // patch-4
		break;
}
}
