// Арчибальд Колхаун
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
		
		case "portroyal":
			dialog.text = "Ha, Monsieur de Maure !  Bienvenue à Port Royal !  Vous souvenez-vous encore de moi ?";
			link.l1 = "Hmm... Vous êtes M. Calhoun, n'est-ce pas ? Henry Calhoun ?";
			link.l1.go = "portroyal_1";
		break;
		
		case "portroyal_1":
			dialog.text = "Presque... Archibald Calhoun.";
			link.l1 = "Oh, pardonnez-moi, Monsieur. Oui, je me souviens de vous. Nous nous sommes rencontrés au Cap Catoche, sur la baie. Votre capitaine était avec vous aussi, William Patterson. J'ai reconnu son escadron.";
			link.l1.go = "portroyal_2";
		break;
		
		case "portroyal_2":
			dialog.text = "Absolument raison ! Pardonnez mon capitaine, je vous prie. Il est toujours grossier avec les gens qu'il ne connaît pas. Vous avez fait un excellent travail en foudroyant le fort de Diego de Montoya, sur lequel nous avons eu la chance d'aiguiser nos griffes...";
			link.l1 = "C'est pour la justice, je pourrais ajouter, que sans les préparatifs préliminaires affichés par votre capitaine, je doute fort que j'aurais même pu courir vers les gains sous le feu des canons espagnols. Votre commandant a-t-il trouvé ce qu'il cherchait ?";
			link.l1.go = "portroyal_3";
		break;
		
		case "portroyal_3":
			dialog.text = "Oui. Il s'est bien enfoncé dans les casemates sous le fort et a trouvé une sorte d'archive. Il était indescriptiblement satisfait. Au fait, si cela ne vous dérange pas que je demande, qu'est-ce qui vous a poussé à attaquer ce fort dans la jungle ?";
			link.l1 = "Après avoir été vaincu par moi à Saint-Pierre, Don Diego a commencé à élaborer un stratagème et a fini par organiser une attaque ouverte sur Cuba. Puis il a rompu le combat et s'est échappé vers les collines en direction de la terre ferme. Eh bien, j'ai décidé de me débarrasser de ce chien jaune une fois pour toutes, pour qu'il ne souille plus jamais les Français.";
			link.l1.go = "portroyal_4";
		break;
		
		case "portroyal_4":
			dialog.text = "Oui, j'ai entendu pas mal de récits légendaires sur les prouesses du capitaine Charles de Maure. Maintenant je l'ai vu de mes propres yeux...";
			link.l1 = "Oui, j'ai entendu quelques histoires sur la vaillance de William Paterson aussi. Vous avez de la chance d'avoir un capitaine comme lui.";
			link.l1.go = "portroyal_5";
		break;
		
		case "portroyal_5":
			dialog.text = "Quelle chance, c'est vrai. Bien qu'il soit devenu un homme si important de nos jours, un homme de haute société, audiences, bals, défilés et fêtes privées... Vous ne pouvez pas le faire sortir du palais du gouverneur chaque fois que nous arrivons à Port Royal. En fait, il y est encore en ce moment. \nCapitaine Charles de Maure, pouvez-vous rendre service à un Écossais ivrogne ? Rejoignez ma compagnie et discutons un peu ! J'en ai assez de voir toujours les mêmes visages et vous semblez être une bonne personne à qui parler. Venez chez moi, détendons-nous et dégustons un tonneau de whisky excellent. C'est moi qui offre !";
			link.l1 = "Hm... Tentant, mais...";
			link.l1.go = "portroyal_6";
		break;
		
		case "portroyal_6":
			dialog.text = "Oh arrête, Capitaine, vous devez aussi vous reposer de temps en temps. J'ai quelques bons hors d'oeuvres d'ailleurs, directement du magasin du marchand local. Je loue une chambre juste au-dessus de la boutique. Quand vous avez envie de grignoter ou de boire un coup, il suffit de descendre et c'est prêt, haha ! Pratique, n'est-ce pas ? Allez, allons-y !";
			link.l1 = "Tu m'as convaincu!";
			link.l1.go = "portroyal_7";
		break;
		
		case "portroyal_7":
			dialog.text = "Parfait. Suivez-moi !";
			link.l1 = "... ";
			link.l1.go = "portroyal_8";
		break;
		
		case "portroyal_8":
			DialogExit();
			NextDiag.CurrentNode = "portroyal_9";
			LAi_SetActorType(pchar);
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload6_back", "PortRoyal_store", "goto", "goto2", "GuardOT_ArchyIntoStore", -1);
			LAi_ActorFollow(pchar, npchar, "", -1);
		break;
		
		case "portroyal_9":
			LAi_SetSitType(Pchar);
			dialog.text = "Voyez comme c'est agréable ici ? Beau et frais... Voici quelques tonneaux de whisky ! À la vôtre, Capitaine !";
			link.l1 = "Eh bien, buvons à notre rencontre fortuite et à une agréable connaissance !";
			link.l1.go = "portroyal_10";
		break;
		
		case "portroyal_10":
			dialog.text = "Ravi !... Ah ! Vous êtes arrivé récemment aux Caraïbes, n'est-ce pas, Monsieur de Maure ?";
			link.l1 = "Relativement récemment... ou pas si récemment. Je ne sais pas vraiment comment le dire. J'ai l'impression d'avoir vécu ici la moitié de ma vie.";
			link.l1.go = "portroyal_11";
		break;
		
		case "portroyal_11":
			dialog.text = "Oh, je connais ce sentiment... Bien que je sois ici depuis longtemps moi-même. Et quand j'ai débarqué sur cette maudite île dont William m'a sauvé... Ohoo, c'est comme si j'avais dit adieu à la moitié de ma vie là-bas.";
			link.l1 = "Intéressant ! Quelle île était-ce ?";
			link.l1.go = "portroyal_12";
		break;
		
		case "portroyal_12":
			dialog.text = "Willy est un vieil ami à moi, nous nous connaissions depuis que je respirais encore l'air pur d'Écosse... De bons moments. J'ai été assez insensé pour me quereller avec ces maudits papistes et l'Inquisiteur lui-même, alors il a organisé un attentat contre moi. J'étais alors marchand, j'avais ma propre flute. Eh, ce jour maudit, mon navire a été attaqué par les Espagnols, déguisés en pirates. Nous nous sommes battus bravement mais ils ont réussi à nous coincer comme des rats ! Même alors, le vieux Colhaun n'a pas perdu la tête et a sauté par-dessus bord avec un tonneau d'eau et quelques planches. J'ai utilisé l'obscurité pour m'éloigner de mon navire, invisible aux soldats. Les chances de survie n'étaient pas très bonnes, mais rester sur le navire signifiait ne pas avoir de chance du tout. Deux jours plus tard, je me suis échoué sur le rivage d'une île déserte. J'avais vécu dans les Caraïbes pendant un certain temps à ce moment-là et pourtant je n'en avais jamais entendu parler jusqu'alors ! Elle est petite et complètement inhabitée... et j'y ai passé deux ans, qui ont semblé une éternité. Je ne sais toujours pas comment j'ai réussi à garder mon esprit intact.";
			link.l1 = "Vous avez vécu deux ans sur une île inhabitée ?";
			link.l1.go = "portroyal_13";
		break;
		
		case "portroyal_13":
			dialog.text = "Je l'ai bien fait, maudite île ! Heureusement, il y avait de l'eau douce. Je me suis nourri de crabes, de balanes, de poissons et d'oiseaux. C'est pourquoi je l'ai appelée l'île aux Crabes. Je n'avais aucune arme, alors j'ai maîtrisé le harpon, la lance et la flèche comme un sauvage ! Ohoo ! Bois, bois, Capitaine ! Je ne suis pas contre un peu d'humidité pour ma sifflet non plus...";
			link.l1 = "Oui... Je ne t'envie pas.";
			link.l1.go = "portroyal_14";
		break;
		
		case "portroyal_14":
			dialog.text = "Voilà! C'est exactement ce que j'ai dit en posant le pied sur cette grande étendue de sable pour la première fois : 'Vieux Archy, ta situation n'est pas enviable, mais elle n'est pas désespérée non plus!' Et vous savez ce qui m'a maintenu en vie, Capitaine?";
			link.l1 = "Un navire passant près de l'île ?";
			link.l1.go = "portroyal_15";
		break;
		
		case "portroyal_15":
			dialog.text = "Non ! Le travail m'a sauvé ! Le travail, la foi et le désir de vivre ! J'ai exploré toute l'île, chaque recoin, et j'ai été récompensé par un coffre rempli d'outils de charpentier, d'accessoires d'écriture et d'autres petites choses. Tu sais ce que je me suis dit à ce moment-là ? Verse encore, Capitaine, verse simplement !\nJ'ai dit : Archie, tu dois travailler pour garder l'esprit en place et Dieu t'a donné tout ce qu'il te faut pour commencer. Maintenant tu vois ! J'ai commencé à construire une maison près d'une baie et tu sais quoi ? Cela m'a sauvé des pensées sombres et m'a donné une raison de vivre !";
			link.l1 = "Vous êtes une inspiration vivante, M. Calhoun. Peu d'hommes seraient capables de faire quoi que ce soit, dans une situation pareille...";
			link.l1.go = "portroyal_16";
		break;
		
		case "portroyal_16":
			dialog.text = "Oui, le vieux Calhaun est né en Écosse pour une raison! C'est ça! Nous sommes les fils des montagnes - forts, courageux et robustes, bien meilleurs que ces poids plumes des marais. Versez encore... Bon, de quoi je parlais? Oui! J'ai travaillé dur et construit une maison décente pour moi. J'ai aussi commencé un journal pour écrire chaque jour mes infortunes. J'ai pris le journal avec moi quand Willy m'a sauvé.\nMaintenant, je le garde dans cette table ici et je le relis dans un lit chaud et doux chaque fois que nous restons à Port Royal.\nJ'ai tout noté dedans, tout ce qui m'est arrivé avant et après mon arrivée là-bas. C'est l'une des raisons pour lesquelles je garde encore toute ma tête.";
			link.l1 = "Alors, il s'avère que M. Paterson vous a récupéré sur l'île ? Mais comment a-t-il pu la trouver ? Vous disiez...";
			link.l1.go = "portroyal_17";
		break;
		
		case "portroyal_17":
			dialog.text = "Oui, oui, l'île n'est marquée sur aucune carte. Mais Willy, c'est le vieux Willy ! Il peut tout faire ! Et il a trouvé cette satanée île et m'a sauvé, et pour cela je lui serai reconnaissant jusqu'à la fin de ma vie. Ouais...";
			link.l1 = "Aimez-vous servir M. Paterson ? Aimeriez-vous repartir avec vos propres ressources ?";
			link.l1.go = "portroyal_18";
		break;
		
		case "portroyal_18":
			dialog.text = "J'en ai fini d'être indépendant. Willy est jeune et prospère, et je suis aussi un vieil ami à lui. Que me faut-il de plus ? Non, je resterai avec Willy jusqu'à la fin de mes jours, ou du moins jusqu'à ce qu'il me vire la prochaine fois que je me soûlerai, haha ! En parlant de se soûler, versez-en !";
			link.l1 = "Akh...(boire) Dites-moi, Monsieur Calhoun. J'ai entendu dire que vous étiez, euh, un chasseur de trésors. Est-ce vrai ou n'est-ce que des balivernes ?";
			link.l1.go = "portroyal_19";
		break;
		
		case "portroyal_19":
			dialog.text = "Qui te l'a dit ? Eh bien, il n'y a aucun sens à essayer de le cacher. J'étais l'un d'eux. Cela n'a pas bien tourné, cependant, c'est exactement cette chasse au trésor qui m'a conduit aux maudits jésuites et à l'île. Les saints pères ont torturé un homme à mort à cause de moi, et moi-même... oh, laissons le passé dans le passé.\nJ'ai assez payé pour mes péchés et j'espère ne jamais les répéter à l'avenir. Non, Willy ne laissera pas cela arriver, j'en suis sûr !";
			link.l1 = "Écoute, Archibald. As-tu déjà entendu parler d'un homme nommé Miguel Dichoso ?";
			link.l1.go = "portroyal_20";
		break;
		
		case "portroyal_20":
			dialog.text = "Je n'ai jamais entendu ce nom auparavant. Qui est-ce ?";
			link.l1 = "Oh, personne d'intéressant... juste un homme qui aime chercher des aventures et des trésors. Mais puisque tu n'as pas entendu parler de lui, nous n'en parlerons pas.";
			link.l1.go = "portroyal_21";
		break;
		
		case "portroyal_21":
			dialog.text = "Oui, ne le faisons pas ! Parlons plutôt de la vieille Europe ! Je me souviens d'il y a vingt ans en Écosse...";
			link.l1 = "Understood. Please provide the text you want translated.";
			link.l1.go = "portroyal_22";
		break;
		
		case "portroyal_22":
			DialogExit();
			AddDialogExitQuest("GuardOT_MCOutFromArchyRoom");
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}
