// Вильям Патерсон
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
			dialog.text = "Y a-t-il quelque chose que vous voulez ?";
			link.l1 = "Non, rien.";
			link.l1.go = "exit";			
			NextDiag.TempNode = "First time";
		break;
		
		case "catoche":
			dialog.text = "Bonjour, Monsieur. Bon sang, c'est donc vous qui avez semé tout ce tumulte militaire ici?!";
			link.l1 = TimeGreeting()+", monsieur. Oui, c'était mon navire qui a effectué la descente. Qu'est-ce qui se passe, au fait ? Qui êtes-vous ? Un Anglais, je suppose ?";
			link.l1.go = "catoche_1";
		break;
		
		case "catoche_1":
			dialog.text = "Un Écossais, Monsieur. Capitaine de la Marine anglaise William Paterson, et voici mon premier lieutenant et bras droit, Archibald Calhoun. Le fait est qu'il y a un fort espagnol dans les jungles. Ma mission est de chasser ces salauds maudits du fort qu'ils ont construit dangereusement près du territoire anglais.\nRécemment, nous avons essayé de le prendre d'assaut, mais les salauds ont réussi à tenir bon malgré leurs pertes. Je suis parti chercher des renforts et...";
			link.l1 = "Pas besoin de cela maintenant. J'ai terminé votre affaire inachevée, le fort de la jungle est vide. Le commandant espagnol Diego de Montoya est mort, et son escadron a également été anéanti.";
			link.l1.go = "catoche_2";
		break;
		
		case "catoche_2":
			dialog.text = "Quelle sorte de vigilantisme est-ce là ? Quelle est votre motivation pour entreprendre une telle action militaire en territoire anglais ?";
			link.l1 = "J'ose vous rappeler Capitaine Paterson, que ceci n'est pas Belize. Quelle possession anglaise ? Tout ce remue-ménage a commencé à cause de Don Diego de Montoya et de sa décision risquée de m'attaquer moi et mes navires.";
			link.l1.go = "catoche_3";
		break;
		
		case "catoche_3":
			dialog.text = "Euh... et quelle raison avait Don Diego de t'attaquer, hein capitaine ?";
			link.l1 = "Entre lui et moi, c'est une vieille querelle... Depuis le jour où l'escadre qu'il dirigeait a attaqué Saint-Pierre et, peu de temps après, a été éliminée avec ma participation directe.";
			link.l1.go = "catoche_4";
		break;
		
		case "catoche_4":
			dialog.text = "Par tous les diables! J'avais besoin de ce vénérable caballero en vie! J'allais l'interroger sur la raison pour laquelle il a établi une base militaire dans la jungle. Cela ne pouvait pas être sans raison...";
			link.l1 = "Je suis désolé, mais il n'est pas en mesure de vous dire quoi que ce soit maintenant. Quoi qu'il en soit, le fort peut contenir des soldats blessés de la garnison. Y a-t-il une chance qu'ils puissent parler ?";
			link.l1.go = "catoche_5";
		break;
		
		case "catoche_5":
			dialog.text = "Soldats... Oh, à quoi bon ces têtus de première!... Où est le cadavre de Don Diego ? Il aurait pu avoir des documents importants sur lui !";
			link.l1 = "J'ai laissé Don Diego sur le terrain du fort des armes. Si tu as tant besoin de lui, tu peux le trouver là-bas. Je ne pense pas qu'il puisse s'enfuir.";
			link.l1.go = "catoche_6";
		break;
		
		case "catoche_6":
			dialog.text = "Eh... et qui t'a demandé de te mêler des affaires des autres... Tu m'as déjà causé assez de tracas...";
			link.l1 = "Capitaine, je ne comprends pas pourquoi vous me réprimandez. J'ai accompli votre tâche, envoyé mes propres hommes au combat, risqué ma propre vie, et pourtant vous êtes mécontent. Tout ce que vous avez à faire maintenant, c'est informer Port Royal de votre succès dans la mission et de toutes vos affaires. Je ne réclamerai aucun crédit pour votre gloire, je vous l'assure.";
			link.l1.go = "catoche_7";
		break;
		
		case "catoche_7":
			dialog.text = "Revendiquer le mérite ? Que veux-tu dire par gloire ?! Tu ne comprends rien du tout... Eh, soit. Adieu, monsieur.";
			link.l1 = "Tous mes voeux pour toi aussi !";
			link.l1.go = "catoche_8";
		break;
		
		case "catoche_8":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorRunToLocation(npchar, "reload", "reload1", "none", "", "", "GuardOT_OpenCatocheDoor", 10.0);
			sld = CharacterFromID("Archy");
			LAi_CharacterEnableDialog(sld);
			LAi_SetActorType(sld);
			LAi_ActorRunToLocation(sld, "reload", "reload1", "none", "", "", "", 7.0);
			AddQuestRecord("Guardoftruth", "57");
		break;
		
		case "isladevieques":
			PlaySound("Voice\English\sharlie\Willie Paterson.wav");
			dialog.text = "Mon gars, les rumeurs ne mentent pas en disant que tu as neuf vies comme un chat ! "+TimeGreeting()+", Monsieur de Maure. Vous n'avez pas l'air en forme...";
			link.l1 = TimeGreeting()+", M. Paterson. Je dois dire, vous et votre ami Archibald avez bien joué vos rôles et m'avez bien eu, Allez tous vous faire foutre ! Je n'ai rien vu venir...";
			link.l1.go = "isladevieques_1";
		break;
		
		case "isladevieques_1":
			dialog.text = "Eh bien, ne jure pas devant les portes de la Terre Sainte. Tu ne l'as pas vu venir? Je suis flatté : j'ai dupé l'un des intrigants les plus célèbres de l'archipel. L'idée du journal était brillante, tu ne trouves pas?\nJe devais t'attirer dans un endroit obscur, te tuer en plein jour serait un scandale, tu es un ami proche de Philippe de Poincy, n'est-ce pas? Maintenant, tu vas disparaître sans laisser de traces et personne ne saura jamais comment.";
			link.l1 = "Alors, tout ce que Calhoun m'a dit... était un mensonge ?";
			link.l1.go = "isladevieques_2";
		break;
		
		case "isladevieques_2":
			dialog.text = "Pas du tout. J'avais vraiment trouvé le pauvre Archibald à cet endroit. Il n'a pas écrit de mémoires, cependant, le journal que vous avez trouvé dans sa chambre a été écrit à ma demande spécialement pour vous, Monsieur de Maure.\nJe vous ai observé depuis notre rencontre au Cap Catoche. C'est vous qui avez pris la carte des Deux Apparitions sur le cadavre de don Diego ? Ne le niez pas, je sais que c'était vous.";
			link.l1 = "Vous connaissez aussi le Gardien de la Vérité ?";
			link.l1.go = "isladevieques_3";
		break;
		
		case "isladevieques_3":
			dialog.text = "C'est une question stupide. Bien sûr, je le sais. Et je sais aussi que tu as la Griffe du Chef sur toi. Et bientôt tu rendras ces objets qui ne t'appartiennent pas.";
			link.l1 = "Je suis heureux que tu ne chancelles pas comme Don Diego. J'apprécie l'honnêteté et la franchise. Si j'ai bien compris, tu as la boussole, la Flèche de la Voie ?";
			link.l1.go = "isladevieques_4";
		break;
		
		case "isladevieques_4":
			dialog.text = "Haw-haw ! Eh bien, nous serons honnêtes jusqu'à la fin... Croyez-vous vraiment, monsieur, que je suis un tel idiot, comme vous et Don Diego, que je porterais avec moi un objet aussi précieux ? La boussole est en Jamaïque et même pas à Port Royal, mais dans un endroit où personne ne penserait à chercher et sous une serrure sûre. Mais vous n'aurez pas besoin de cette information.";
			if (CheckAttribute(pchar, "questTemp.Guardoftruth.OfficerKill"))
			{
				link.l1 = "Si je comprends bien, vous m'avez déjà enterré, M. Paterson ? J'ose proclamer que le chat a encore une vie !.. Où sont mes officiers ?";
				link.l1.go = "isladevieques_5_1";
			}
			else
			{
				link.l1 = "Si je comprends bien, vous m'avez déjà enterré, Monsieur Paterson ? J'ose proclamer que le chat a encore une vie !..";
				link.l1.go = "isladevieques_5_2";
			}
		break;
		
		case "isladevieques_5_1":
			if (CheckAttribute(pchar, "questTemp.Guardoftruth.GirlKill"))
			{
				dialog.text = "Tu t'inquiètes pour ta dame, capitaine ? Ta femme est étendue là-bas dans les buissons avec un trou dans le front. Elle t'a tracé la route et tu la rejoindras bientôt. Je dois dire, quelle jolie fille elle était ! J'espère que tu l'as baisée plus d'une fois ?";
				link.l1 = "C'est un fils de pute! Tu paieras pour ça, enfoiré?!";
				link.l1.go = "isladevieques_6";
			}
			else
			{
				dialog.text = "Vos officiers vous ont tracé la route, Monsieur de Maure. Ils reposent là-bas dans les buissons. Bientôt vous les rejoindrez.";
				link.l1 = "Nous verrons bien cela !";
				link.l1.go = "isladevieques_6";
			}
		break;
		
		case "isladevieques_5_2":
			dialog.text = "Nous veillerons à ce que ce soit vraiment ta dernière.";
			link.l1 = "On verra bien ça !";
			link.l1.go = "isladevieques_6";
		break;
		
		case "isladevieques_6":
			dialog.text = "Tu me fais rire. Un contre toute une troupe ! Quoi qu'il en soit, assez bavardé... Visez vos mousquets ! Feu !";
			link.l1 = "... ";
			link.l1.go = "isladevieques_7";
		break;
		
		case "isladevieques_7":
			DialogExit();
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);//разрешить драться patch-8
			LAi_ActorRunToLocation(npchar, "quest", "teleport", "IslaDeVieques_HouseEntrance", "quest", "mushketer", "GuardOT_WillyGetReady", 10.0);
			for(i=1; i<=5; i++)
			{
				sld = CharacterFromID("GuardOT_willymushketer_"+i);
				LAi_group_MoveCharacter(sld, "EnemyFight");
			}
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("EnemyFight", "GuardOT_WillyMushketerDie");
			DoQuestFunctionDelay("Terrapin_SetMusic", 0.2);
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
	}
}
