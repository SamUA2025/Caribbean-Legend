// Алонсо де Мальдонадо
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
	int i;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			dialog.text = "Y a-t-il quelque chose dont vous avez besoin ?";
			link.l1 = "Non, rien.";
			link.l1.go = "exit";			
			NextDiag.TempNode = "First time";
		break;
		
		case "ksochitam":
			dialog.text = "Arrêtez, Capitaine "+GetFullName(pchar)+"...";
			link.l1 = "D'une manière ou d'une autre, je ne suis même pas surpris par la présence des soldats espagnols ici... Je suppose que je me suis habitué à ce que quelqu'un soit toujours à mes trousses. Que cherches-tu sur cette île maudite, Castillan ? Tu cherches un moyen rapide de passer l'arme à gauche ?";
			link.l1.go = "ksochitam_1";
		break;
		
		case "ksochitam_1":
			dialog.text = "Je m'appelle Alonso de Maldonado. Cela ne vous dit peut-être rien, mais Diego de Montoya pourrait éveiller des souvenirs. Il était mon meilleur ami. Il m'a sauvé la vie et maintenant son sang est sur vos mains.";
			link.l1 = "Je suppose que tu m'as suivi ici pour te venger ?";
			link.l1.go = "ksochitam_2";
		break;
		
		case "ksochitam_2":
			dialog.text = "Je ne cherche pas seulement à me venger. Si j'ai bien compris, tu as le masque de Kukulcan ?";
			link.l1 = "Eh bien, que le diable m'emporte ! Encore un chasseur de trésors ! Tu viens pour une affaire inachevée commencée par Don Diego ?";
			link.l1.go = "ksochitam_3";
		break;
		
		case "ksochitam_3":
			dialog.text = "Je ne suis pas intéressé par les trésors. J'ai vu les richesses à Tayasal. Miguel Dichoso n'a pas pu emporter beaucoup plus qu'une bouchée. C'est le masque que je veux.";
			link.l1 = "Tu es allé à Tayasal ? C'est difficile à croire. Autant que je me souvienne, Dichoso était le seul et unique survivant de l'expédition.";
			link.l1.go = "ksochitam_4";
		break;
		
		case "ksochitam_4":
			dialog.text = "Je suis allé à Tayasal vingt ans avant que Dichoso n'y arrive. À la même époque, ce sorcier fou Kanek a utilisé ce rituel abominable de sacrifice humain pour cacher le masque sur cette île.";
			link.l1 = "Je n'en crois pas mes oreilles ! Vous faites partie de la même bande de conquistadors qui a été amenée là pour être sacrifiée lorsque le Gardien de la Vérité était en train d'être créé ? Vous êtes tous morts !";
			link.l1.go = "ksochitam_5";
		break;
		
		case "ksochitam_5":
			dialog.text = "Pas tous. J'ai survécu.";
			link.l1 = "Pourquoi les Itza ont-ils décidé de t'épargner ? Qu'est-ce qui te rend si différent ?";
			link.l1.go = "ksochitam_6";
		break;
		
		case "ksochitam_6":
			dialog.text = "Tu ne comprendrais pas. Bon sang, moi non plus, je n'ai pas compris. Personne ne m'a épargné. Je m'en souviens comme si c'était hier... Juste après que ce sauvage ait pris un poignard et découpé un morceau de peau du dos de Casco avant de le mettre à mort et de commencer à hurler comme un fou, je pense que j'ai été aspiré dans l'idole. Je me suis réveillé loin de Tayasal vingt ans plus tard, ce qui m'a semblé être un simple instant !";
			link.l1 = "Un entonnoir espace-temps... Nom de Dieu, tout ce que Ksatl Cha a dit était pile-poil ! Comment as-tu découvert le masque ? Pourquoi en as-tu besoin ?";
			link.l1.go = "ksochitam_7";
		break;
		
		case "ksochitam_7":
			dialog.text = "Je dois arrêter la progéniture de l'enfer, invoquée par un sorcier indien fou. Cette abomination vise à faire un bûcher de notre monde !";
			link.l1 = "Hmm... Vous avez parlé au père Vincento, n'est-ce pas ? L'Inquisiteur court deux lièvres à la fois. Quelle surprise. Il vous a envoyé pour me traquer pour un combat royal ? Bien joué ! Vous avez accompli votre mission, Don Alonso !";
			link.l1.go = "ksochitam_8";
		break;
		
		case "ksochitam_8":
			dialog.text = "Le Seigneur fortifie ma main au combat contre le mal. Je retournerai à Tayasal et utiliserai le masque pour sceller à jamais les portes. Et aucun démon sous forme humaine ne franchira jamais notre monde.";
			link.l1 = "Il y a juste un petit problème dans votre plan, Don Alonso. Le démon est DÉJÀ parmi nous. Tout ce que nous devons faire, c'est de ne pas le laisser SORTIR par ces portes. Il ne pourra pas le faire tant que vous garderez le masque loin de lui.  ";
			link.l1.go = "ksochitam_9";
		break;
		
		case "ksochitam_9":
			dialog.text = "Il en faudra plus que ça. Peu importe qui d'entre nous a raison, une chose est sûre : les portes doivent être fermées pour toujours. Et il n'y a qu'une seule façon de le faire : détruire le masque sur l'autel de Tayasal. En faisant cela, le démon sera dépouillé de tout son pouvoir.";
			link.l1 = "Hm. Je suis d'accord que c'est notre meilleure chance... Comment comptez-vous vous rendre à Tayasal ? Connaissez-vous le chemin ?";
			link.l1.go = "ksochitam_10";
		break;
		
		case "ksochitam_10":
			dialog.text = "Le chemin facile que nous empruntions autrefois n'existe plus. Les routes sont ensevelies sous les pierres et perdues dans les jungles. Il y a un autre chemin vers la ville, mais il est long et dangereux. Le chemin commence à la baie la plus au nord du Yucatan.\nAvec l'aide du père Vincento et de don Ramon de Mendoza, je rassemblerai une escouade de soldats d'élite et nous nous frayerons un chemin à travers la selva protégée par les sauvages Itza. Ce ne sera pas facile, mais Dieu nous accordera force et bravoure pour notre combat au nom de notre foi.";
			link.l1 = "Don Alonso, il se trouve que mes aspirations coïncident avec les vôtres. N'est-il pas temps de mettre nos rancunes de côté un instant et de combiner nos forces ? Ensemble, nous aurons de meilleures chances de mener à bien cette croisade.";
			link.l1.go = "ksochitam_11";
		break;
		
		case "ksochitam_11":
			dialog.text = "Je suis un soldat espagnol. Je ne forme pas d'alliances avec des hérétiques ni ne fais de marchés avec des Français. De plus, j'ai déjà déclaré ma vendetta contre vous pour Don Diego. Une vie pour une vie !";
			link.l1 = "Vous êtes têtu comme un boeuf, Don Alonso ! Là vous êtes, prêchant que le monde est menacé par un grand mal, et pourtant vous refusez mon aide pour réussir une tâche si astronomique !";
			link.l1.go = "ksochitam_12";
		break;
		
		case "ksochitam_12":
			dialog.text = "Je prends les décisions maintenant, pas le père Vincento ! Dites vos prières et préparez-vous à mourir, capitaine français !..";
			link.l1 = "Oh, j'ai entendu ça tant de fois ces derniers mois ! En garde, caballero entêté !";
			link.l1.go = "ksochitam_13";
		break;
		
		case "ksochitam_13":
			DialogExit();
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
			LAi_SetWarriorType(npchar);
			LAi_group_MoveCharacter(npchar, "EnemyFight");
			for (i=1; i<=2; i++)
			{
				sld = characterFromId("Maldonado_soldier_"+i);
				LAi_SetWarriorType(sld);
				LAi_group_MoveCharacter(sld, "EnemyFight");
			}
			for (i=1; i<=2; i++)
			{
				sld = characterFromId("Maldonado_mushketer_"+i);
				LAi_SetWarriorType(sld);
				LAi_group_MoveCharacter(sld, "EnemyFight");
			}
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("EnemyFight", "Ksochitam_MaldonadoDie");
			AddDialogExitQuest("MainHeroFightModeOn");
			if (MOD_SKILL_ENEMY_RATE > 4) Ksochitam_CreateMaldonadoHelpers();
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}
