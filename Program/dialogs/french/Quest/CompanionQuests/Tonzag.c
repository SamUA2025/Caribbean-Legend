void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
	int i;
	string sTemp;
	
	DeleteAttribute(&Dialog,"Links");
	
	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	switch(Dialog.CurrentNode)
	{
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		case "First time":
			dialog.text = "Que voulez-vous ?";
			link.l1 = "Rien.";
			link.l1.go = "exit";
		break;
		
		case "startoff":
			dialog.text = "Capitaine de Mor ! Bienvenue à Tortuga !";
			link.l1 = "Bonne journée, Lieutenant. Profitez-vous de la vue sur la mer avec vos amis ?";
			link.l1.go = "startoff_joke";
			link.l2 = "Recule, Lieutenant.";
			link.l2.go = "startoff_silence";
			
			AddDialogExitQuestFunction("Tonzag_Arrested");
		break;
		
		case "startoff_joke":
			dialog.text = "Capitaine, votre réputation vous précède, et les hautes instances ont décidé d'organiser une petite visite des beautés de notre charmante île de la Tortue. Nous commençons dès maintenant - par les cellules de la prison de la ville. Vos officiers sont également invités.";
			link.l1 = "Lieutenant, je ne suis pas un contrebandier miteux que tu as attrapé sur la plage. Pas de plaisanteries, je te prie. Explique les affaires correctement.";
			link.l1.go = "startoff_joke_1";
			link.l2 = "Alors ne perdons pas de temps ! Montrez le chemin, Lieutenant !";
			link.l2.go = "startoff_joke_2";
		break;
		
		case "startoff_silence":
			dialog.text = "Je vois que traiter avec vous, marins, nécessite une approche différente. Soldats, préparez-vous au combat ! Capitaine de Maure, vous et vos officiers êtes en état d'arrestation. Rendez vos armes !";
			link.l1 = "Je peux te donner une balle - où la veux-tu, Lieutenant ? Avec vous, rats de terre, il n'y a pas d'autre moyen.";
			link.l1.go = "startoff_silence_1";
			link.l2 = "Par quelle loi ? Si vous voulez arrêter un groupe armé sans effusion de sang, Lieutenant, il vous faudra faire mieux.";
			link.l2.go = "startoff_silence_2";
		break;
		
		case "startoff_joke_1":
			dialog.text = "Pour moi, vous êtes tous les mêmes... Désolé mais il n'y aura pas d'explications, Capitaine. Ordres d'en haut. Rendez vos armes, si vous voulez bien.";
			link.l1 = "Je n'ai pas besoin d'ennuis... pas maintenant. Fais ce qu'ils disent.";
			link.l1.go = "exit";
			
			AddCharacterExpToSkill(pchar, "Leadership", 100);
			ChangeCharacterComplexReputation(pchar, "nobility", +5);
		break;
		
		case "startoff_joke_2":
			dialog.text = "Euh... Je suppose que vous ne m'avez pas bien compris. Capitaine, vous et vos officiers êtes en état d'arrestation ! Rendez vos armes et venez avec nous !";
			link.l1 = "Je n'ai pas besoin de problèmes... pas maintenant. Fais ce qu'ils disent.";
			link.l1.go = "exit";
			
			AddCharacterExpToSkill(pchar, "Fortune", 100);
		break;
		
		case "startoff_silence_1":
			dialog.text = "Encore un mot, Capitaine, et nous t'enterrerons ici-même. Armes à terre, tout de suite !";
			link.l1 = "Je n'ai pas besoin de problèmes... pas maintenant. Fais comme ils disent.";
			link.l1.go = "exit";
			
			AddComplexSelfExpToScill(100, 100, 100, 100);
			ChangeCharacterComplexReputation(pchar, "nobility", -5);
		break;
		
		case "startoff_silence_2":
			dialog.text = "Je n'ai pas peur du sang, Capitaine. Même si vous survivez miraculeusement, vous ne mettrez plus jamais les pieds à Tortuga. Et notre renseignement militaire croit que vous accordez une grande valeur à votre accès à cette île.";
			link.l1 = "Je n'ai pas besoin d'ennuis... pas maintenant. Fais comme ils disent.";
			link.l1.go = "exit";
			
			AddCharacterExpToSkill(pchar, "Leadership", 100);
			ChangeCharacterComplexReputation(pchar, "authority", 5);
		break;
		
		case "tonzag_after_boarding":
			dialog.text = "Capitaine, les choses sont merdiques ! L'ennemi a une prise ferme sur nous, j'ai peur qu'ils ne lâchent pas prise avant que nous soyons morts ! Nos hommes sont en grand danger en ce moment, et la plupart des équipages de canon sont hors combat !";
			link.l1 = "Je vais les aider. Prends le commandement et fais-nous sortir d'ici !";
			link.l1.go = "tonzag_after_boarding_1";
			DelLandQuestMark(npchar);
		break;
		
		case "tonzag_after_boarding_1":
			dialog.text = "Oui, monsieur !";
			link.l1 = "";
			link.l1.go = "exit";
			
			AddDialogExitQuestFunction("Tonzag_GoToGunDeck");
		break;
		
		case "tonzag_after_victory":
			dialog.text = "Victoire, Capitaine! Le groupe de débarquement a été détruit, l'ennemi a choisi de battre en retraite et s'est dirigé vers le sud. L'état du navire est acceptable. Équipage vivant: "+GetCrewQuantity(pchar)+" gens. Rapport terminé !";
			link.l1 = "Merci ! Du rhum pour tout le monde et renforcez la garde jusqu'à ce que nous atteignions le port !";
			link.l1.go = "tonzag_after_victory_1";
		break;
		
		case "tonzag_after_victory_1":
			dialog.text = "Hourra ! Oui chef !";
			link.l1 = "";
			link.l1.go = "exit";
			
			AddDialogExitQuestFunction("Tonzag_AlonsoBoardingDialog");
		break;
		
		case "killer":
			dialog.text = "Et voilà l'homme en personne ! As-tu vu le massacre sanglant dehors ? Tout cela est de ton fait, traître ! Mais tu répondras de tout : pour Porto Bello, pour Gruoh, et pour cette mine !";
			link.l1 = "Attends, qu'est-ce que c'est censé...";
			link.l1.go = "exit";
			
			AddDialogExitQuestFunction("Tonzag_FightInMine");
		break;
		
		case "mine_head":
			dialog.text = "";
			link.l1 = "Agh ! Ça ne présage rien de bon...";
			link.l1.go = "mine_head_1";
		break;
		
		case "mine_head_1":
			dialog.text = "San Santiago, garde-moi ! Infamie ! Quel monstre pourrait commettre un tel acte ? Répondez, señor !";
			link.l1 = "Calmez-vous, señor ! Présentez-vous d'abord ! Oui, un carnage monstrueux a eu lieu ici, mais les gens qui l'ont commis sont déjà morts. J'ai personnellement 'décoré' les mines avec leurs restes...";
			link.l1.go = "mine_head_2";
		break;
		
		case "mine_head_2":
			dialog.text = "Je suis "+GetFullName(npchar)+", ingenieur en chef de la mine royale de Los Teques. Je viens de rentrer d'une mission de plusieurs mois et...que vois-je ! Ce qui s'est passé ici est un crime contre Dieu et l'humanité, donc je vous demande de rendre vos armes immédiatement. Les autorités de Caracas enquêteront sur cette infamie !";
			link.l1 = " Je ne puis obtempérer, señor, et je jure que je n'ai rien à voir avec ce massacre ! Mais si vous persistez, votre propre corps s'ajoutera au tas.";
			link.l1.go = "mine_head_3";
		break;
		
		case "mine_head_3":
			dialog.text = "Je ne crains pas la mort, mais je sais toujours quand battre en retraite. Va, mais souviens-toi, je rapporterai ce qui s'est passé ici, et je n'omettrai pas un seul détail !";
			link.l1 = "Je ne puis accepter cela, señor. Je suis désolé que cela en soit arrivé là. A la bataille !";
			link.l1.go = "mine_head_fight";
			link.l2 = "Il semble que vous cherchez la mort, señor. Mais aujourd'hui, personne d'autre ne mourra. Nous partons, et j'espère que ce détail figurera également dans votre rapport !";
			link.l2.go = "mine_head_peace";
		break;
		
		case "mine_head_peace":
			DialogExit();
			
			AddDialogExitQuestFunction("Tonzag_LetMineHeadGo");
		break;
		
		case "mine_head_fight":
			DialogExit();
			
			AddDialogExitQuestFunction("Tonzag_FightMineHead");
		break;
		
		case "alonso":
			dialog.text = "Que devrions-nous faire du prisonnier, Capitaine ?";
			link.l1 = "Rien de spécial, assurez-vous simplement qu'il ne meure pas ou ne s'échappe pas.";
			link.l1.go = "alonso_1";
		break;
		
		case "alonso_1":
			dialog.text = "Oui oui ! Je suppose que je n'aurai pas besoin de participer à l'interrogatoire d'aujourd'hui, Capitaine ?";
			link.l1 = "Pourquoi pas ? Décidé de changer de métier, Alonso ?";
			link.l1.go = "alonso_2";
		break;
		
		case "alonso_2":
			dialog.text = "Ha-ha, non, Capitaine. J'adore ce métier, mais il semble que vous ayez un nouveau maître de la profession à bord !";
			link.l1 = "Hercule ? D'où t'est venue cette idée ?";
			link.l1.go = "alonso_3";
		break;
		
		case "alonso_3":
			dialog.text = "Eh bien, Capitaine, le vieil homme a apporté sa boîte à outils juste pour l'occasion et l'a mise à profit. Je n'aurai même pas besoin de sortir la mienne. Ha !";
			link.l1 = "Je vois... Repos ! ";
			link.l1.go = "exit";
			
			AddDialogExitQuestFunction("Tonzag_DrinkAgain");
		break;
		
		case "captive":
			dialog.text = "Ah... Charles de Maure. Permettez-moi de vous présenter mes excuses au nom de toute la Ligue. L'ordre de vous laisser tranquille nous est parvenu trop tard. Notre organisation n'a aucune revendication contre vous, Capitaine. Quant à cet animal chauve... Pouah ! Tant qu'il est à votre laisse, il est en sécurité, mais mon conseil est de ne pas le garder et de le laisser pourrir dans le caniveau où est sa place !";
			link.l1 = "Merci pour la recommandation, mais je suis plus intéressé par la raison pour laquelle quelqu'un me protège de vos mercenaires.";
			link.l1.go = "captive_1";
		break;
		
		case "captive_1":
			dialog.text = "Je ne peux pas savoir, Capitaine. Je suppose que les instructions viennent de notre nouveau patron. Tu as entendu parler de lui, traître ? La Ligue est de nouveau au sommet maintenant !";
			link.l1 = "Et qui est-il ?";
			link.l1.go = "captive_2";
		break;
		
		case "captive_2":
			dialog.text = "Je ne peux pas le savoir, Capitaine, et même si je le savais, de telles choses nous ne divulguons pas.";
			link.l1 = "Dans ce cas, dis-moi autre chose, et tu pourras aller où bon te semble. Tu as ma parole.";
			link.l1.go = "captive_3";
		break;
		
		case "captive_3":
			dialog.text = "Comme ça ? Très bien, Capitaine, posez vos questions et laissez-moi partir. Je promets de ne pas retourner à la Ligue, même si je le pouvais.";
			link.l1 = "Pourquoi es-tu si obsédé par Hercule ? Trop de problèmes pour un seul déserteur.";
			link.l1.go = "captive_4";
		break;
		
		case "captive_4":
			dialog.text = "Qu'est-ce que tu lui as dit, espèce de chien ? Tout n'est pas ce qu'il paraît, Capitaine ! La Ligue bouge constamment, les codes changent, les employeurs varient. Tu veux partir ? Bien sûr ! La sortie est fermée seulement pour les officiers supérieurs, et cette vermine n'en a jamais été un. Sa femme, certes, mais nous respections trop Madame Tonzag pour ne pas faire une exception pour elle.";
			link.l1 = "Alors pourquoi?";
			link.l1.go = "captive_5";
		break;
		
		case "captive_5":
			dialog.text = "Il y avait une affaire à Porto Bello... C'était quelque chose de grand. Voyez-vous, votre ami n'a pas seulement quitté, n'a pas seulement rompu le contrat, n'a pas seulement tué le groupe venu terminer son travail. Il a causé un véritable massacre dans les rues, compliquant considérablement notre relation avec les Castillans. Rare est le raid pirate qui sème autant de terreur que ce que les bons catholiques ont vécu ce jour-là. Diable, j'aurais même pu être impressionné si quelqu'un d'autre l'avait fait.";
			link.l1 = "Un autre massacre ? Comme c'est intéressant. Continuez.";
			link.l1.go = "captive_6";
		break;
		
		case "captive_6":
			dialog.text = "Le vice-directeur de la Compagnie de l'époque, Rodenburg, est intervenu. Il a d'une manière ou d'une autre réussi à étouffer toute l'affaire, mais pas avant que nous ayons perdu beaucoup de nos meilleurs hommes lors des opérations punitives espagnoles. Après un certain temps, cependant, nous faisions à nouveau des affaires avec eux... Ah ! Mais nous n'avons rien oublié, et dès que l'occasion s'est présentée, nous avons essayé de rendre la pareille. L'instigateur de tout cela, Tonzag, devait être tué.";
			link.l1 = "Vous n'y êtes pas parvenu. Qu'en est-il de la mine ?";
			link.l1.go = "captive_7";
		break;
		
		case "captive_7":
			dialog.text = "We were forced to do it. Getting rid of that scum required too much expense; we needed gold. All because of him... But the attempted assassination failed, and I returned to Los Teques to tidy up a bit... How did you figure out where to look?";
			link.l1 = "Peu importe. Je dois rencontrer votre chef. Je veux régler ce malentendu personnellement, car les garanties de votre mystérieux protecteur peuvent expirer à tout moment.";
			link.l1.go = "captive_8";
		break;
		
		case "captive_8":
			dialog.text = "Je suis sûr qu'ils t'attendent déjà à Caracas, Capitaine. Tu vois, je ne te cache rien.";
			link.l1 = "";
			link.l1.go = "exit";
			
			AddDialogExitQuestFunction("Tonzag_HoldDialog");
		break;
		
		case "captive_9":
			dialog.text = "Le commandant Arno est mort, Austin est aux commandes maintenant.";
			link.l1 = "";
			link.l1.go = "exit";
			
			AddDialogExitQuestFunction("Tonzag_HoldDialog2");
		break;
		
		case "captive_10":
			dialog.text = "J'ai répondu à toutes vos questions, Capitaine. Tenez votre parole.";
			link.l1 = "Je te laisse partir. Descends de mon navire, et prie pour qu'il n'y ait pas d'embuscade qui m'attend à Caracas.";
			link.l1.go = "captive_spare";
			link.l2 = "Merci pour cette conversation intéressante. Accuser Hercule d'avoir causé un massacre après ce que j'ai vu dans la mine, c'était un peu fort, quand même. En route pour l'enfer, là où tu appartiens.";
			link.l2.go = "captive_execute";
		break;
		
		case "captive_execute":
			DialogExit();
			
			AddDialogExitQuestFunction("Tonzag_ExecuteCaptive");
		break;
		
		case "captive_spare":
			DialogExit();
			
			AddDialogExitQuestFunction("Tonzag_ReturnToCabin2");
		break;
		
		case "cureer":
			dialog.text = "Messieurs, vous êtes conviés à une réunion. Ils vous attendent à l'église, donc la sécurité est garantie.";
			link.l1 = "Ça, c'était rapide...";
			link.l1.go = "exit";
			
			AddDialogExitQuestFunction("Tonzag_CureerGoAway");
		break;
		
		case "ostin":
			StartQuestMovie(true, false, true);
			PlaySound("VOICE\" + LanguageGetLanguage() + "\OliverTrast02.wav");
			dialog.text = "Charles de Maure. Hercule. Tu ne sortiras pas d'ici vivant.";
			link.l1 = "Toujours une belle façon de commencer une conversation. As-tu vraiment besoin de tout ça ?";
			link.l1.go = "ostin_1";
		break;
		
		case "ostin_1":
			dialog.text = "Avec vous, Capitaine, les choses ne sont pas simples. Voyez-vous, notre nouveau patron a insisté pour qu'on vous laisse tranquille...et il peut se fourrer ses demandes là où je pense ! Je hais votre espèce à en crever ! Vous naviguez sous vos jolies voiles blanches, en pensant que la glace ne fondra pas dans votre bouche. Mais quand la lame de mon épée vous transperce, vous hurlez tous comme des fillettes. J'adore ça, Charles, laissez-moi vous le dire ! Cela fait un moment que je ne l'ai pas fait...et maintenant je vous ai juste en face de moi, joli garçon.";
			link.l1 = "Tu es malade, l'ami.";
			link.l1.go = "ostin_2";
		break;
		
		case "ostin_2":
			dialog.text = "Non, je ne peux pas te laisser partir. Avec ton ami, par contre, c'est bien plus simple - mes gars n'ont pas besoin de lui, mais il reste quelques-uns de ses vieux camarades de la Ligue qui ne sont pas tout à fait convaincus de l'efficacité de mes méthodes... Trop habitués à travailler proprement, pour les doublons propres, de la Compagnie propre. Mais je sais exactement ce qui leur fera changer d'avis - la tête d'un pécheur audacieux sur un plateau, ha-ha !";
			link.l1 = "Tu as choisi le mauvais endroit pour ça, espèce de fou. Vas-tu vraiment commencer une bataille dans une église ?";
			link.l1.go = "ostin_3";
		break;
		
		case "ostin_3":
			dialog.text = "Bien sûr, pourquoi pas ? Tu te sens mal pour ces pauvres diables ? Ce ne sera peut-être pas aussi lucratif qu'à Los Teques, mais nous allons quand même bien nous amuser. Nous peindrons les murs de la maison de Dieu, ah-ha ! Capitaine, tu fourniras beaucoup de peinture.";
			link.l1 = "Je comprends. Tu nous envies, n'est-ce pas, sale rat enragé ? Tu envies notre liberté ? Que les filles soient heureuses de nous voir et que les pièces tintent dans nos poches ? Regarde-toi : où tes patrons t'ont-ils déterré, porc ? Qui t'a laissé entrer dans l'église ?";
			link.l1.go = "ostin_4";
		break;
		
		case "ostin_4":
			dialog.text = "Mange de la terre, petit salaud !";
			link.l1 = "";
			link.l1.go = "exit";
			
			AddDialogExitQuestFunction("Tonzag_ChurchVystrel");
		break;
		
	}
} 
