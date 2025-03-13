// Диего де Монтойя
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
			dialog.text = "Y a-t-il quelque chose que tu désires ?";
			link.l1 = "Non, rien.";
			link.l1.go = "exit";			
			NextDiag.TempNode = "First time";
		break;
		
		case "patrol":
			dialog.text = TimeGreeting()+", "+GetFullName(npchar)+", Chef de la patrouille de San Jose. Nous avons reçu un message concernant un comportement suspect dans les environs de cette ville. Auriez-vous l'amabilité de nous expliquer qui vous êtes et ce que vous faites?";
			link.l1 = "Capitaine "+GetFullName(pchar)+", senor officier. Je suis ici sous l'autorité et les instructions directes de l'Inquisiteur Père Vincento. Voici un document confirmant mon autorisation.";
			link.l1.go = "patrol_1";
		break;
		
		case "patrol_1":
			dialog.text = "D'accord... Tout semble en ordre. C'est bien rempli avec la signature de l'inquisiteur. Mes excuses pour mes soupçons. Que faites-vous au phare ?";
			link.l1 = "Je ne suis pas autorisé à répondre à de telles questions. Si vous êtes vraiment intéressé par le but de mon travail pour l'inquisiteur, je vous recommande de vous adresser directement à lui à Santiago pour des éclaircissements. Vous êtes un officier, vous avez sûrement connaissance de secrets militaires et de service. La seule chose que je peux vous dire, c'est que j'enquête sur les circonstances d'un naufrage d'un navire espagnol.";
			link.l1.go = "patrol_2";
		break;
		
		case "patrol_2":
			dialog.text = "Mes excuses encore une fois, Monsieur. Je n'oserai plus vous retarder... ah, un instant ! Est-ce que je viens de voir la lame d'un acier froid ou était-ce juste mon imagination ? Quelle dague intéressante vous avez là ! Pouvez-vous me la montrer ?";
			link.l1 = "Assure-toi de ne pas oublier de le rendre. C'est très important pour moi.";
			link.l1.go = "patrol_3";
		break;
		
		case "patrol_3":
			dialog.text = "Dios mio! Je connais ce poignard, je l'ai vu dans l'un des livres de la bibliothèque! C'est le poignard de Cortes lui-même! Il est marqué juste ici... Monsieur, s'il vous plaît, ne refusez pas. Laissez-moi avoir ce poignard! Je collectionne les armes anciennes et personnalisées et c'est tout simplement un spécimen incroyable. Je paierai bien pour cela.";
			link.l1 = "Señor, ce poignard n'est pas à vendre. Je l'ai reçu en cadeau et je ne suis pas disposé à le vendre à qui que ce soit. Rendez-le, je vous prie.";
			link.l1.go = "patrol_4";
		break;
		
		case "patrol_4":
			dialog.text = "Tu ne serais même pas satisfait avec cinq cents doublons d'or ? C'est une sacrée somme. Tu pourrais t'acheter un navire avec ça !";
			link.l1 = "Non. J'ai déjà un navire et ce poignard est unique en son genre. Je ne le vendrai pas.";
			link.l1.go = "patrol_5";
		break;
		
		case "patrol_5":
			dialog.text = "Hé, c'est bien dommage... Très bien, prends ton précieux. Je n'oserai plus te déranger. Bonne chance !";
			link.l1 = "Tout le meilleur, officier.";
			link.l1.go = "patrol_6";
		break;
		
		case "patrol_6":
			DialogExit();
			AddQuestRecord("Guardoftruth", "42");
			LAi_ActorGoToLocation(npchar, "reload", "reload2", "none", "", "", "GuardOT_ClearMayakPatrol", 12.0);
			for(i=1; i<=3; i++)
			{
				sld = characterFromId("GOT_spamayaksold_"+i);
				sld.lifeday = 0;
				LAi_SetActorType(sld);
				LAi_ActorGoToLocation(sld, "reload", "reload2", "none", "", "", "", 10.0);
			}
		break;
		
		case "shore":
			PlaySound("Voice\English\Sharlie\Diego De Montoya.wav");
			dialog.text = "Assez ! Je veux lui parler...";
			link.l1 = "Alors, je vois Diego de Montoya en personne juste devant moi... Mais pardonnez-moi, señor. Nous nous sommes déjà rencontrés, n'est-ce pas ? Ah oui, c'est vrai. À Trinidad, au phare local. Mais je suis sûr que vous vous appeliez autrement là-bas...";
			link.l1.go = "shore_1";
		break;
		
		case "shore_1":
			dialog.text = "Votre mémoire vous sert bien, monsieur. Eh bien, vous n'êtes pas le seul capable de susciter l'intrigue et de mener des guerres en coulisses. Je suis bien informé de votre désir ardent de me voir. Eh bien, on dirait que votre souhait s'est réalisé.";
			link.l1 = "Ce n'était pas exactement le genre de rencontre que j'espérais, señor.";
			link.l1.go = "shore_2";
		break;
		
		case "shore_2":
			dialog.text = "Eh bien, c'est comme ça. Mais je te donnerai une chance de sortir d'ici vivant si tu me donnes ton poignard.";
			link.l1 = "Votre passion pour la collection de raretés vous a-t-elle vraiment conduit si bas, caballero, au point de préparer un piège si bien conçu pour moi?  Oh, je ne pense pas. Est-ce que le Gardien de la Vérité vous garde en haleine ou suis-je loin du compte?";
			link.l1.go = "shore_3";
		break;
		
		case "shore_3":
			dialog.text = "Je n'ai aucune idée de ce dont tu parles. Le poignard doit retourner là où il appartient et c'est tout ce que tu as besoin de savoir. Tu n'as pas voulu le céder pour de l'or, alors maintenant tu vas le céder pour ta propre vie.";
			link.l1 = "Croyez-vous vraiment, señor, que je vais croire ce que vous venez de me dire ? Vous avez déjà décidé que je ne quitterai pas cette baie, n'est-ce pas ?";
			link.l1.go = "shore_4";
		break;
		
		case "shore_4":
			dialog.text = "Et que dirais-tu si je te donnais ma parole ?";
			link.l1 = "Le mot pour un 'mangeur de grenouilles'? Hm...";
			link.l1.go = "shore_5";
		break;
		
		case "shore_5":
			dialog.text = "Monsieur, je vous donne une dernière chance. Soit vous me remettez la dague qui m'intéresse, soit je pillerai votre cadavre dans quelques minutes. Résistance est futile, nous avons un avantage écrasant en nombre.";
			if (CheckAttribute(pchar, "questTemp.Guardoftruth.SanAntonio")) link.l1 = "Vous m'avez surpris, señor, c'est certain. Vous pensez vraiment que je suis un imbécile aussi borné que je mettrais juste ma tête dans les mâchoires d'un requin sans prendre la peine de saisir mon harpon ? Les gars, tuez-les !";
			else link.l1 = "Le vrai pouvoir ne réside pas dans le nombre, mais dans l'habileté, señor !";
			link.l1.go = "shore_6";
		break;
		
		case "shore_6":
			DialogExit();
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
			LAi_SetActorType(npchar);
			LAi_ActorRunToLocation(npchar, "goto", "goto5", "none", "", "", "", 10.0);
			if (CheckAttribute(pchar, "questTemp.Guardoftruth.SanAntonio"))
			{
				PlaySound("interface\abordage_wining.wav");
				PlaySound("interface\abordage_wining.wav");
				for(i=1; i<=10; i++)
				{
					sld = characterFromId("GuardOT_Oursoldier_"+i);
					LAi_SetWarriorType(sld);
					ChangeCharacterAddressGroup(sld, "Shore15", "reload", "reload1_back");
					LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
				}
			}
			sld = CharacterFromID("spa_baseprisoner");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, "EnemyFight");
			for(i=1; i<=13; i++)
			{
				sld = characterFromId("GOT_spashore_"+i);
				LAi_SetWarriorType(sld);
				LAi_group_MoveCharacter(sld, "EnemyFight");
			}
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("EnemyFight", "GuardOT_DiegoShoreGuardDie");
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
	}
}
