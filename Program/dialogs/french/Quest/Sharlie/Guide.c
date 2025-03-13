// гид
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
			dialog.text = "Tu veux quelque chose ?";
			link.l1 = "Non, rien.";
			link.l1.go = "exit";			
			NextDiag.TempNode = "First time";
		break;
		
		case "guide_0":
			SetAchievement("Test_Ach");
			PlaySound("Voice\English\LE\Greguar\Greguar_01.wav");
			dialog.text = "Bienvenue aux Caraïbes, Monsieur ! Permettez-moi de me présenter, je suis "+GetFullName(npchar)+"Vous êtes nouveau dans notre colonie, n'est-ce pas ?";
			link.l1 = "Salutations, Monsieur. Mon nom est "+GetFullName(pchar)+". Oui, je viens de débarquer. Je ne crois pas vous avoir déjà vu... Vous vous connaissez?";
			link.l1.go = "guide_1";
		break;
		
		case "guide_1":
			DelLandQuestMark(npchar);
			dialog.text = "Non, Monsieur, vous ne le faites pas, mais je ne pouvais pas manquer l'occasion de me présenter à un noble homme comme vous.\nOh, je me souviens de mon premier jour ici, le jour de mon arrivée dans le Nouveau Monde. Les choses sont très différentes ici. Le mode de vie local peut ruiner votre santé et votre bourse.\nC'est pourquoi je vous offre mon humble aide. Gratuitement, ce qui est assez rare ici je vous assure, haha ! Je peux vous familiariser avec notre colonie et l'archipel. Considérez cela comme une petite visite.";
			link.l1 = "C'est très aimable de votre part, merci Monsieur ! Je serais ravi d'accepter votre offre. Le savoir, c'est le pouvoir après tout.";
			link.l1.go = "guide_2";
			link.l2 = "J'apprécie votre offre, Monsieur, vraiment, mais je vais décliner.";
			link.l2.go = "guide_exit";
		break;
		
		case "guide_exit":
			dialog.text = "Comme vous le souhaitez, Monsieur. Quoi qu'il en soit, ce fut un plaisir de vous rencontrer. Les gentilshommes honorables sont des invités rares ici. Je vous souhaite bonne chance !";
			link.l1 = "Toi aussi, "+GetFullName(npchar)+" !";
			link.l1.go = "guide_exit_1";			
		break;
		
		case "guide_exit_1":
			DialogExit();
			LAi_SetCitizenType(npchar);
			LAi_CharacterDisableDialog(npchar);
			npchar.lifeday = 0;
			DoQuestCheckDelay("NgtF3", 1.0);
			QuestPointerToLoc("FortFrance_town", "reload", "reload3_back");
		break;
		
		case "guide_2":
			dialog.text = "Je suis ravi de l'entendre. C'est mon plaisir. Eh bien, laissez-moi vous initier à quelques bases. La plupart des colonies sont construites selon un schéma similaire : une colonie sur le rivage, protégée par un fort et des murs de la ville avec des portes. Nobles, riches, soldats, marins, marchands, mercenaires et criminels - tous vivent ensemble à l'intérieur de ces murs.\nParfois, vous rencontrerez aussi des capitaines, des moines, des gitans et des mendiants. Vous ne trouverez cependant aucun Indien dans les rues, ces sauvages mettent les gens mal à l'aise. Si vous voulez voir des Indiens, vous devrez aller dans les jungles. Suivez-moi, je vais vous montrer quelques-uns de nos établissements locaux.";
			link.l1 = "Bonjour, mon ami.";
			link.l1.go = "guide_3";			
		break;
		
		case "guide_3": // идем в таверну
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(npchar, "officers", "reload4_3", "Guide_tavern", -1);
			LAi_ActorFollow(pchar, npchar, "", -1);
			chrDisableReloadToLocation = true;//закрыть локацию
		break;
		
		case "guide_4":
			dialog.text = "Voici l'endroit le plus important dans toute colonie - la taverne. Oui, en Europe, ces lieux peuvent être considérés comme des repaires de crapules et de vilenies, mais ici, dans le Nouveau Monde, c'est différent. Un barman peut vous offrir une chambre pour dormir, du rhum, des ragots juteux et un emploi.\nSi vous avez besoin d'informations, essayez de parler avec les clients ici. Offrez un autre verre à un ivrogne et vous pourriez obtenir quelque chose d'intéressant en retour...ou pas ! Le jeu est populaire ici mais méfiez-vous des tricheurs. Si vous attrapez quelqu'un en train de tricher, n'hésitez pas à le tuer sur-le-champ. Personne ne vous jugera pour cela.\nUne taverne est aussi un endroit où vous pouvez engager un équipage et des officiers pour votre navire, c'est-à-dire, si vous en possédez un. Souvenez-vous : la taverne possède des informations, du travail, un équipage, et du divertissement.";
			link.l1 = " ";
			link.l1.go = "guide_9";
			locCameraFromToPos(-2.08, 5.32, 68.88, false, -15.00, -0.60, 55.00);
		break;
		
		case "guide_5": // к магазину
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(npchar, "officers", "reload6_3", "Guide_store", -1);
			LAi_ActorFollow(pchar, npchar, "", -1);
		break;
		
		case "guide_6":
			dialog.text = "Le magasin est le centre névralgique du commerce de toute colonie. Les capitaines visitent cet endroit aussi souvent que le chantier naval. Ici, vous pouvez acheter des munitions, des fournitures ou des marchandises à échanger. Le commerce est assez compliqué.\nD'abord, il faut du temps pour trouver les meilleurs endroits pour acheter ou vendre. Ensuite, il vous faut de bonnes compétences en négociation pour marchander avec les commerçants locaux.\nC'est pourquoi la plupart des capitaines engagent des intendants pour conclure des affaires à leur place. Alors, n'oubliez pas d'embaucher un professionnel quand... ou si vous obtenez votre propre navire. C'est crucial, vous ne voulez pas gaspiller de l'argent ici. Une erreur et vous serez ruiné. Une dernière chose. Les marchands dans les magasins peuvent souvent vous proposer des contrats de livraison, cela pourrait vous être utile à l'avenir.";
			link.l1 = "Bonjour, mon ami.";
			link.l1.go = "guide_26";
			locCameraFromToPos(-21.10, 6.60, 45.21, false, -30.00, 3.70, 45.00);
		break;
		
		case "guide_7": // к тюрьме
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(npchar, "reload", "reload_jail", "Guide_prison", -1);
			LAi_ActorFollow(pchar, npchar, "", -1);
		break;
		
		case "guide_8":
			dialog.text = "Et voici la prison. Un endroit immonde. Les pires criminels finissent vite avec une corde autour du cou, donc principalement, ce sont les petites frappes qui sont gardées ici.\nSi tu veux bavarder avec eux, parle au gardien de la prison. Il te laissera entrer pour une petite somme, ou même gratuitement si tu es assez persuasif! Cela peut s'avérer utile, mais souviens-toi que les vauriens ne sont pas dignes de confiance, bien qu'ils parlent toujours doucement et protestent de leur innocence derrière les barreaux.";
			link.l1 = "";
			link.l1.go = "guide_9";
			locCameraFromToPos(-52.40, 7.63, 42.60, true, 15.00, -4.00, -30.00);
		break;
		
		case "guide_9": // на рынок
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(npchar, "merchant", "mrcActive4", "Guide_market", -1);
			LAi_ActorFollow(pchar, npchar, "", -1);
		break;
		
		case "guide_10":
			dialog.text = "C'est le marché. Les marchands vendent et achètent tout ce dont vous avez besoin. Un armurier peut vous fournir des lames, des armes à feu, des armures, des munitions, et ainsi de suite. Cependant, le bon équipement est rare, alors ne vous attendez pas à trouver des chefs-d'œuvre ici. De telles choses viennent à un grand prix et risque, mais vous pouvez trouver de bonnes lames et pistolets ici, à moins que quelqu'un ne les achète avant vous.\nUn herboriste peut offrir des potions de santé, des antidotes, des plantes, des ingrédients, des fioles, et si vous êtes chanceux, des recettes. Mais pourquoi même vous dire ça, vous n'êtes pas alchimiste, n'est-ce pas ? Les gitans offrent des amulettes païennes et des conneries inutiles comme des cadavres de chauve-souris. Certains disent connaître une utilisation pour de telles choses, mais c'est tout de la foutaise.\nLes moines vendent des bougies, des talismans sacrés et d'autres babioles bénies : croix, anneaux, outils d'écriture. Et les chiffonniers vendent des ordures ainsi que des articles divers, mais si vous avez les compétences nécessaires en artisanat, vous pouvez fabriquer quelque chose d'utile avec des peignes de tortue, des clous et des cordes.";
			link.l1 = "";
			link.l1.go = "guide_19";
			locCameraFromToPos(-13.58, 4.11, 69.06, false, -45.00, -6.00, 52.00);
		break;
		
		case "guide_11": // к резиденции
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(npchar, "officers", "reload3_1", "Guide_townhall", -1);
			LAi_ActorFollow(pchar, npchar, "", -1);
		break;
		
		case "guide_12":
			dialog.text = "Ah, voilà le palais du gouverneur ! C'est la demeure et le bureau de l'homme le plus important de la colonie. Les nobles visitent le palais pour des bals et des fêtes, les hommes d'affaires et les capitaines viennent ici pour résoudre des affaires tant officielles que personnelles. Il est toujours sage d'être sur la liste d'amis du gouverneur, il a beaucoup d'influence sur les citoyens de la nation qu'il représente.\nLes corsaires peuvent aussi gagner beaucoup d'argent en travaillant pour les gouverneurs, qui sont capables de racheter des prisonniers de guerre. Si vous êtes riche et souhaitez établir une bonne relation avec Son Excellence, il peut même vous honorer en jouant aux jeux d'argent avec vous pour des enjeux élevés.\nIl semble que vous soyez impatient, mon ami. Êtes-vous pressé ?";
			link.l1 = "Eh bien... oui. Monsieur, pour être franc, je suis venu ici pour trouver mon frère, on m'a dit qu'il devait être ici, à Saint-Pierre. C'est un homme important, le gouverneur doit le connaître.";
			link.l1.go = "guide_13";
			locCameraFromToPos(3.14, 7.39, 37.55, false, 1.06, 9.00, 14.14);
		break;
		
		case "guide_13":
			dialog.text = "Ah-ha, je vois. Donc, vous voulez rendre visite à Son Excellence et lui demander au sujet de votre frère ? Eh bien, je ne vais pas vous retarder davantage alors. Notre gouverneur s'appelle Jacques Dille du Parquet, je suis sûr qu'il fera ce qu'il peut.";
			link.l1 = "Dis-moi, qui d'autre pourrait m'aider ? Peut-être est-il imprudent de déranger Son Excellence pour une affaire si insignifiante ?";
			link.l1.go = "guide_14";
		break;
		
		case "guide_14":
			dialog.text = "Tu as dit que ton frère est bien connu ici. Demande autour dans les rues. Finalement, tu trouveras quelqu'un qui pourra t'aider. Comment s'appelle ton frère ?";
			link.l1 = "Michel de Monper.";
			link.l1.go = "guide_15";
		break;
		
		case "guide_15":
			dialog.text = "Michel de Monpe... Oui, j'ai déjà entendu ce nom, mais je n'ai jamais été présenté à cet homme, donc je ne peux pas vous aider. Bonne chance, Monsieur, je suis sûr que nous nous reverrons.";
			link.l1 = "Merci, "+GetFullName(npchar)+"!";
			link.l1.go = "guide_16";
		break;
		
		case "guide_16":
			DialogExit();
			LAi_SetCitizenType(npchar);
			LAi_CharacterDisableDialog(npchar);//запрет диалога
			LAi_group_MoveCharacter(npchar, "FRANCE_CITIZENS"); // пока идем заниматься Мишелем
			chrDisableReloadToLocation = false;//открыть локацию
			DoQuestCheckDelay("NgtF3", 1.0);
			QuestPointerToLoc("FortFrance_town", "reload", "reload3_back");
		break;
		
		case "guide_17": // к ростовщику
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(npchar, "officers", "reload8_1", "Guide_bank", -1);
			LAi_ActorFollow(pchar, npchar, "", -1);
		break;
		
		case "guide_18":
			dialog.text = "Voici la maison du prêteur sur gages, ou usurier, banquier, leur lot porte bien des noms différents, souvent très grossiers. Vous pouvez penser ce que vous voulez d'eux, mais leurs services peuvent vous être très utiles. Vous pouvez déposer de l'argent, échanger des doublons et des pesos, vendre ou acheter des bijoux. Si vous avez un honneur positif, vous pouvez même emprunter quelques pièces, mais soyez prudent.\nLes usuriers offrent les meilleurs prix pour les gemmes, bijoux et autres bibelots précieux, visitez-les toujours pour vendre de telles choses. Ce sont des gens puissants, alors ne les contrariez pas.";
			link.l1 = " ";
			link.l1.go = "guide_11";
			locCameraFromToPos(3.07, 7.64, 51.99, false, 45.00, -8.30, 4.50);
		break;
		
		case "guide_19": // к борделю
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(npchar, "officers", "reload9_1", "Guide_brothel", -1);
			LAi_ActorFollow(pchar, npchar, "", -1);
		break;
		
		case "guide_20":
			dialog.text = "Ah, un bordel. Tout homme visite de tels lieux, sinon ils feraient faillite ! Même les nobles le font, au détriment de leur honneur. Sois-en conscient. Sois gentil avec les filles et elles pourront te raconter des choses intéressantes, parfois les hommes ont tendance à leur dévoiler presque tout, et cela pourrait t'être utile.\nSi tu ne cherches pas à découvrir les secrets des autres, alors considère ceci : il n'y a pas de meilleur remède pour l'esprit et le corps que l'amour. Si ta vitalité est faible, fais une visite aux filles. Tu peux également boire une potion spéciale pour restaurer ta vitalité, mais elle est rare et beaucoup moins amusante. Oh, quand je parle de ta 'vitalité', je ne parle pas des égratignures sur ta peau. Tu vas te faire frapper, beaucoup. Mais si tu te fais frapper fort et souvent ou si tu bois trop de potions de santé fortes, tu finiras par ruiner ton corps. Surveille ta condition, repose-toi si nécessaire, ou subis les conséquences.";
			link.l1 = "";
			link.l1.go = "guide_17";
			locCameraFromToPos(-2.75, 7.07, 61.10, false, 60.00, -6.60, 42.65);
		break;
		
		case "guide_21":
			dialog.text = "Oh, toi encore, mon ami ! Je vois qu'ils t'ont laissé entrer dans le lieu saint de Saint-Pierre - le quartier général des Chevaliers de Malte ! Tu dois être important. As-tu retrouvé ton frère ?";
			link.l1 = "En effet, je l'ai fait...";
			link.l1.go = "guide_22";
		break;
		
		case "guide_22":
			dialog.text = "Pardonnez-moi, Monsieur, mais vous avez l'air bien morose...";
			link.l1 = "Putain de merde ! J'espérais foutre le camp de ce trou à rats et retourner en France, mais il semble que Dieu ait d'autres plans. Il paraît que je vais devoir rester ici pendant un sacré bout de temps ! Et le pire, c'est que je dois devenir un simple marin.";
			link.l1.go = "guide_23";
		break;
		
		case "guide_23":
			dialog.text = "C'est un changement assez soudain dans votre destin, Monsieur. Mais ne vous découragez pas, vous n'allez pas être un simple marin. Être le capitaine de votre propre navire est une position très respectée ici. Vous avez l'intention d'acheter un navire, n'est-ce pas ?";
			link.l1 = "Oui, c'est exactement ce que je dois faire... Tout ce dont j'ai besoin, c'est de trouver un chantier naval et de l'argent dès que possible. Le problème, c'est que je ne sais pas où diable se trouve un chantier naval, comment naviguer un navire, ou où trouver l'argent ! Ça me fait chier...";
			link.l1.go = "guide_24";
		break;
		
		case "guide_24":
			dialog.text = "J'aimerais pouvoir remplir vos poches d'or, mais je suis aussi fauché que vous. Cependant, je peux remplir votre tête du savoir dont vous avez tant besoin. Intéressé ?";
			link.l1 = "Ouais, ce serait formidable.";
			link.l1.go = "guide_25";
		break;
		
		case "guide_25":
			dialog.text = "Suis-moi alors. Commençons par l'essentiel - les navires.";
			link.l1 = "Bonjour, mon ami.";
			link.l1.go = "guide_5";
		break;
		
		case "guide_26": // на верфь
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(npchar, "reload", "reload5", "Guide_shipyard", -1);
			LAi_ActorFollow(pchar, npchar, "", -1);
			chrDisableReloadToLocation = true;//закрыть локацию
		break;
		
		case "guide_27":
			dialog.text = "L'arsenal. Chaque colonie en possède un. Un endroit pour vendre ou acheter un vaisseau de mer et aussi pour le réparer. Sachez que nos arsenaux n'ont rien en commun avec les grands chantiers navals de la bonne vieille Europe. Ce sont les colonies, ils ne construisent pas de galions ou de vaisseaux de ligne ici.\nLes maîtres locaux peuvent construire des lougres, des goélettes et des sloops. Très rarement, vous verrez des bricks et des barquentins. Mais parfois les corsaires apportent des navires-prises qu'ils ont capturés et les constructeurs navals les achètent à bon marché, les réparent et les vendent à profit.\nJ'ai vu une fois une frégate sur la liste des prix ! Les navires fabriqués localement ont également de mauvaises caractéristiques. Ne vous inquiétez pas, cependant, s'exercer sur de petits et bon marché navires vous permettra de progresser et de maîtriser éventuellement quelque chose de mieux.\nOh, et l'arsenal est aussi l'endroit pour acheter des canons. Il y a plusieurs types de pièces que vous pouvez faire installer sur votre navire, à condition, bien sûr, qu'il puisse les porter. Chaque navire a des limitations, vous ne pourrez jamais mettre des canons de 24 livres sur un lougre. Souvenez-vous que les gros calibres sont rares et chers. Le bon côté est que de tels canons peuvent littéralement vaporiser l'équipage ennemi, les voiles et la coque.\nUne dernière chose. Les arsenaux offrent aussi des services pour les esthètes : ils peuvent peindre vos voiles et l'extérieur de vos navires, dessiner des emblèmes ou des blasons. La peindre en rouge ne la fera peut-être pas aller plus vite, mais la rendra bien plus élégante.";
			link.l1 = "Intéressant...";
			link.l1.go = "guide_28";
			locCameraFromToPos(-26.74, 5.77, 49.03, false, -70.00, -25.00, 150.00);
		break;
		
		case "guide_28": // в порт
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(npchar, "quest", "quest1", "Guide_port", -1);
			LAi_ActorFollow(pchar, npchar, "", -1);
		break;
		
		case "guide_29":
			dialog.text = "Voici le quai, le cœur de tout port. Je naviguais autrefois, alors laissez-moi vous en dire plus sur la navigation.\nTout d'abord, rappelez-vous de la chose la plus importante : n'essayez même pas de diriger un navire si vous n'avez pas assez de points dans votre compétence de navigation ! Quand la condition n'est pas remplie, alors vos autres compétences en pâtiront, ainsi que celles de vos officiers.\nVous vous battrez moins bien, tirerez moins bien, commerçerez moins bien, et ainsi de suite.\nCela signifie que si vous essayez de piloter un vaisseau de ligne avec votre compétence de navigation actuelle, vous n'irez pas loin, en fait vous pourriez même ne pas être capable de faire un petit virage.";
			link.l1 = "Comment puis-je apprendre cela, la navigation ?";
			link.l1.go = "guide_30";
			locCameraFromToPos(-8.55, 4.06, 91.31, true, 40.00, -8.00, 0.00);
		break;
		
		case "guide_30":
			dialog.text = "Tu sais quoi, mon ami ? Voici cette petite note sur la gestion d'un navire. Lis-la quand tu auras le tien. Un document plutôt utile - il m'a beaucoup aidé à l'époque.";
			link.l1 = "Très bien, monsieur. En effet, je ne suis pas vraiment prêt à absorber autant de connaissances complexes pour l'instant.";
			link.l1.go = "guide_38";
			AddQuestRecordInfo("Guide_AtSea", "1");
		break;
		
		case "guide_31":
			dialog.text = "Le rang du navire le détermine. Par exemple, je suis assez expérimenté (45 points) pour contrôler un vaisseau de 4ème rang sans pénalités. Brigantins, barkentines, flûtes. Les chebecs et corvettes nécessitent plus, donc je ne pourrai pas les utiliser correctement. Ce ne sont même pas des navires de deuxième rang comme les frégates et les lourds galions. Quant aux géants de la ligne ou vaisseaux de guerre... seuls les experts en navigation peuvent contrôler de tels monstres, il faut des années pour maîtriser la compétence et n'oubliez pas l'argent. Un navire de guerre et son équipage peuvent vider votre bourse en un mois si vous n'êtes pas aussi riche que le roi Louis lui-même.";
			link.l1 = "Je vois...";
			link.l1.go = "guide_32";
		break;
		
		case "guide_32":
			dialog.text = "Faites attention aux postes de vos officiers. Un maître d'équipage entraîne votre équipage et rend l'abordage plus efficace, un intendant s'occupe des finances à votre place et débarrasse votre navire des rats. Un médecin soigne vos hommes blessés et réduit le nombre de morts au combat, un charpentier répare les dégâts subis par le navire, et les officiers d'abordage sauvent votre peau quand les pirates envahissent votre pont.\nFaites attention aux compétences des candidats et à leur réputation.";
			link.l1 = "Réputation ?";
			link.l1.go = "guide_33";
		break;
		
		case "guide_33":
			dialog.text = "Exactement. Chaque homme en a un. Cela montre ce qu'un homme est vraiment.\nSi vous êtes un homme honorable et essayez toujours de faire le bien, alors cherchez des officiers qui partagent vos idéaux. Et si vous souhaitez être un pirate... eh bien, vous avez compris.\nLes honnêtes gens ne travailleront pas pour la canaille, l'inverse est également vrai.";
			link.l1 = "D'accord.";
			link.l1.go = "guide_34";
		break;
		
		case "guide_34":
			dialog.text = "Parlons maintenant des types de navires. Il y en a deux types. Les navires marchands et les navires de guerre. Les navires marchands ou navires de commerce ont de grandes cales et tendent à être plus lents. Les navires de guerre sont rapides et ont de puissants canons, au détriment de la capacité de chargement. Les barques, flûtes et caraques sont de bons et solides navires de commerce. Les sloops, bricks et corvettes sont des navires de guerre. Il existe bien sûr des hybrides, des navires adaptés à la fois au commerce et au combat : les snows, goélettes et galions.\nLes navires ont également différents types de gréement, certains sont principalement gréés carrés et d'autres principalement gréés de l'avant à l'arrière, ce qui détermine le meilleur angle de cap du navire.";
			link.l1 = "Angle de cap ?";
			link.l1.go = "guide_35";
		break;
		
		case "guide_35":
			dialog.text = "Oui. Cela détermine comment votre gréement est affecté par le vent et sur quel cap votre navire atteindra sa vitesse maximale. Une fois en mer, trouvez la flèche sur la mini carte, ce sera votre angle de cap.";
			link.l1 = "C'est un peu confus pour moi. Mais je suppose que j'apprendrai avec le temps.";
			link.l1.go = "guide_36";
		break;
		
		case "guide_36":
			dialog.text = "Ensuite, ton équipage. Toi et ton navire n'êtes rien sans les hommes qui le contrôlent. Chaque marin doit savoir faire trois choses. Comment gérer le gréement, comment manier les canons et comment se battre. Chaque nation excelle seulement dans l'une de ces trois activités. Par exemple, l'Espagne a les meilleurs combattants du monde et leurs abordeurs portent des armures, donc les mitrailles, les tranchées et les coups d'épée ne sont pas vraiment efficaces contre eux. Je parle bien sûr des armes légères, les mitrailles de canon se moquent bien des armures corporelles. \nVisite les tavernes d'Espagne, d'Angleterre et de France si tu veux constituer un équipage de rêve, ou si tu veux prendre des risques, engage un équipage de pirates, autant qu'un homme puisse les haïr, ils restent l'équipage le plus mortel qu'on puisse avoir. Surveille le moral de tes hommes, fournis-leur régulièrement du rhum, des putains, et de la monnaie. Fais cela et tes hommes mourront pour toi. Échoue à le faire et ils créeront une mutinerie. Un professionnel motivé vaut dix novices dans un combat. De plus, n'oublie pas un médecin, ou développe tes propres compétences en médecine pour éviter des pertes supplémentaires.";
			link.l1 = "Je m'en souviendrai...";
			link.l1.go = "guide_37";
		break;
		
		case "guide_37":
			dialog.text = "Maintenant, quelques mots sur les batailles navales. Les Caraïbes sont dangereuses, grouillant de patrouilles espagnoles et de pirates, alors vous finirez par les affronter en pleine mer. Les canons des navires utilisent quatre types de munitions. Boulets de canon, mitraille, boulets enchaînés, et bombes.\nLes boulets de canon sont polyvalents et les moins chers à acheter, ils ont également la plus grande portée de tir efficace. Ils déchirent les voiles de l'ennemi, détruisent leur coque et tuent leur équipage.\nLes boulets enchaînés ont une portée de tir décente, leur but est d'éliminer le gréement de l'ennemi afin de les ralentir. Ils sont parfaits à utiliser si vous voulez poursuivre ou fuir. Si vous avez de la chance, vous pouvez même abattre un mât entier.\nBombes. Utilisez-les si vous voulez couler le navire de votre adversaire. Les bombes infligent les plus gros dégâts à la coque, mais elles ont la deuxième plus courte portée de tir, vous devez donc vous rapprocher d'abord, ce qui peut s'avérer fatal. Elles coûtent également le plus cher de toutes les munitions.\nLa mitraille est votre meilleur choix si vous voulez aborder et capturer un navire ennemi. Ces petites peste-là éliminent les gens, mais leur portée de tir la plus courte les rend risquées à utiliser. Mais cela peut en valoir la peine.\nRestez prudent si vous n'êtes pas sûr de pouvoir infliger suffisamment de dégâts. Chaque salve a un coût en poudre à canon, en temps, et en état des canons. Ils peuvent exploser parfois, surtout si vous tirez trop souvent. Manœuvrez toujours, essayez de prendre une meilleure position. Si l'ennemi est trop dangereux et que vous ne pouvez pas fuir, essayez de les provoquer pour qu'ils vous tirent constamment dessus à distance sans causer de dégâts. Ce stratagème videra éventuellement leurs réserves de poudre à canon. Cela peut prendre des jours, alors vous feriez mieux de trouver un abri comme des rochers ou une ligne côtière. Bien sûr, une telle tactique ne fonctionnera pas en pleine mer.\nMines. Aussi un bon moyen de les couler tous. Provoquez-les pour qu'ils vous poursuivent et larguez des mines. Chaque mine nécessite une bonne quantité de poudre, mais même une seule mine peut détruire un lougre.\nPrenez une longue-vue et utilisez-la pour observer votre ennemi. Une bonne longue-vue vous fournira une vue d'ensemble tactique, concernant par exemple la présence d'unités de mousquetaires sur le navire de votre adversaire. Les mousquetaires ennemis peuvent abattre beaucoup de vos hommes sur le pont, alors assurez-vous de leur donner une rafale de mitraille avant l'abordage.";
			link.l1 = "Sainte Marie... c'est effrayant... mais je suppose que je dois être prêt à tout.";
			link.l1.go = "guide_38";
		break;
		
		case "guide_38":
			dialog.text = "Tu apprendras, je n'en doute point. Puisque tu vas devenir capitaine et armateur, je te montrerai un autre endroit de grande importance. Le bureau du port. Suis-moi.";
			link.l1 = "";
			link.l1.go = "guide_39";
		break;
		
		case "guide_39": // к портовому управлению
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(npchar, "reload", "reload10", "Guide_portoffice", -1);
			LAi_ActorFollow(pchar, npchar, "", -1);
		break;
		
		case "guide_40":
			dialog.text = "Voilà. Au bureau du port, vous pouvez trouver des offres d'emploi. Des cargaisons pour de grands navires marchands et des missions d'escorte pour les navires de guerre. Si vous possédez un navire rapide, ils pourraient vous proposer un travail de courrier.\nJe recommande de gagner un peu de confiance ici. Si vous faites bien votre travail plusieurs fois, ils vous confieront des contrats plus compliqués et beaucoup mieux rémunérés.\nVous pouvez également vous renseigner sur d'autres capitaines et laisser vos navires excédentaires ici en stockage pour les mettre en sécurité. Stockage sans limite, n'oubliez juste pas de payer !";
			link.l1 = "Compris.";
			link.l1.go = "guide_41";
			locCameraFromToPos(48.38, 9.48, 43.95, true, -70.00, -55.00, 150.00);
		break;
		
		case "guide_41":
			dialog.text = "Eh bien, les portes de la ville sont proches, alors il y a un autre sujet dont j'aimerais te parler. Ces portes mènent aux jungles. Suis-moi et je te parlerai des actions furtives et de l'escrime. Ça te dérange ?";
			link.l1 = "Pas du tout. Vous m'avez déjà beaucoup aidé !";
			link.l1.go = "guide_42";
		break;
		
		case "guide_42":
			dialog.text = " Suivez-moi alors ! ";
			link.l1 = " ";
			link.l1.go = "guide_43";
		break;
		
		case "guide_43": // к воротам
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(npchar, "reload", "gate_back", "Guide_gate", -1);
			LAi_ActorFollow(pchar, npchar, "", -1);
		break;
		
		case "guide_44":
			dialog.text = "Alors, voici une porte de la ville menant directement dans la jungle... C'est embarrassant, mais j'ai encore une note pour vous à étudier plus tard. Cette fois, il s'agit des nuances de notre vie terrestre. Prenez le temps de la lire, car elle vous aidera à mieux comprendre comment infiltrer des villes hostiles et comment combattre sur terre. Mais pour l'instant, je suggère que nous sortions des portes et que nous nous amusions un peu - pratiquons l'escrime.";
			link.l1 = "Vous êtes une véritable encyclopédie, Monsieur. Allons-y! Cela semble amusant de pratiquer.";
			link.l1.go = "guide_48";
			locCameraFromToPos(50.58, 5.74, 23.21, false, 100.00, 0.00, 20.00);
			AddQuestRecordInfo("Guide_OnLand", "1");
		break;
		
		case "guide_45":
			dialog.text = "Un document que vous pouvez obtenir au siège de la Compagnie Néerlandaise des Indes Occidentales. Un signe de vos intentions pacifiques. Ce papier vous permettra d'entrer dans n'importe quel port jusqu'à l'expiration des conditions.\nMais il y a quelques inconvénients. Premièrement, la Compagnie a des règles spéciales et exige que tout capitaine désireux d'acheter la licence doit les suivre. Deuxièmement, cela coûte cher. Et enfin, le pire, vous avez toujours besoin d'une compétence de 'lever de drapeau' pour accoster dans les ports. Sinon, vous serez abattu à vue par les canons lourds du fort.";
			link.l1 = "Où se trouve le siège de la Compagnie ?";
			link.l1.go = "guide_46";
		break;
		
		case "guide_46":
			dialog.text = "Willemstad sur Curaçao. Si tu veux acheter une licence - va là-bas, ils te donneront les détails.";
			link.l1 = "Les choses sont tellement en désordre ici...";
			link.l1.go = "guide_47";
		break;
		
		case "guide_47":
			dialog.text = "Ne sois pas contrarié, mon ami. Tu apprendras. Maintenant, pratiquons l'escrime.";
			link.l1 = "Ça sonne bien. Allons-y !";
			link.l1.go = "guide_48";
		break;
		
		case "guide_48": // телепортируем за городские ворота
			DialogExit();
			LAi_SetActorType(npchar);
			DoQuestReloadToLocation("FortFrance_ExitTown", "goto", "goto19", "Guide_ExitTown");
		break;
		
		case "guide_49":
			dialog.text = "Mon ami, je crois que tu sais manier une épée?";
			link.l1 = "Ha ! Bien sûr que je sais. J'ai été formé par le meilleur maître d'escrime de Paris !";
			link.l1.go = "guide_50";
		break;
		
		case "guide_50":
			dialog.text = "Bien pour toi. Laisse-moi d'abord t'enseigner un peu de théorie.\nIl existe trois types d'armes blanches : légères, moyennes et lourdes. Chaque type nécessite des compétences et des capacités différentes pour être maîtrisé, donc tu devras les apprendre séparément.\nChaque classe a ses avantages et inconvénients. Les armes légères incluent les fleurets et les rapières, elles ont de faibles exigences de stamina, mais infligent le moins de dégâts. Une arme lourde, comme une hache, peut tuer d'un seul coup, bien qu'elle épuisera ta stamina très rapidement, et tu devras peut-être te reposer entre les frappes. Les armes moyennes, sabres ou coutelas, sont un juste milieu, combinant un bon poids et un potentiel de dégâts.\nIl y a plusieurs mouvements et astuces d'escrime à ta disposition : attaque en estoc, attaque de coupe, attaque lourde et attaque de groupe. Tu peux aussi parer, feinter et bloquer.\nL'attaque en estoc est le mouvement le plus rapide, nécessite la plus petite quantité de stamina pour être exécuté, et est excellente pour les longues rapières. C'est principalement inutile pour les haches. L'attaque de coupe est assez polyvalente, a une vitesse décente, une perte significative de stamina, c'est bon pour les sabres, épées larges et haches, mais pas très efficace avec les rapières. L'attaque lourde est portée d'en haut, un excellent choix pour les haches, fonctionnera bien pour les sabres courts et les coutelas, pourtant les rapières ne sont simplement pas conçues pour de tels mouvements. Cette attaque drainera une énorme quantité de stamina, elle est lente, mais infligera des dégâts dévastateurs et ignore les blocs de ton ennemi.\nBloquer est inutile contre les attaques lourdes et les adversaires expérimentés ont toujours une chance de briser ton blocage. Parer est bien mieux, cela ouvre ton adversaire aux attaques et le force à perdre de la stamina. Plusieurs parades réussies et ton adversaire perd complètement son initiative et est forcé de se défendre pendant que tu as l'avantage total.\nLes feintes sont délicates et risquées. Tromper ton adversaire et lui asséner immédiatement un rapide estoc ne nécessite qu'une petite perte de stamina, mais tu dois être concentré, attentif et dans le rythme du combat. Maîtriser ce mouvement te demandera beaucoup de pratique, mais c'est gratifiant - même les duellistes professionnels et les maîtres d'arme tomberont sous ta main.\nPour maximiser les dégâts de chaque type d'attaque, tu dois utiliser la bonne arme pour chacune. L'attaque en estoc sera plus performante avec de longues et légères rapières ou épées droites avec un équilibre de 0 à 0,5. De longs coutelas ou sabres courbes avec un équilibre de 1 à 2 sont excellents pour les attaques de coupe et lourdes. Une lourde hache avec un équilibre de 2 est parfaite pour les attaques lourdes, mais une telle arme nécessitera beaucoup de stamina et de compétence pour être utilisée. L'attaque de groupe ne vaut pas la peine d'être ton mouvement principal, elle est plutôt défensive, mais un coutelas courbe, léger et long avec un équilibre de 0,75 à 1,25 fera des merveilles contre des groupes d'ennemis autour de toi.\nEnfin, la meilleure arme pour feinter est une dague, envisage de faire de ce mouvement ta spécialité. Le poids d'une arme détermine combien de stamina elle nécessitera pour n'importe quel mouvement d'attaque et cela affecte également les dégâts. Souviens-toi, trouver ton arme parfaite peut prendre du temps et travailler sur ton style de combat prendra encore plus.";
			link.l1 = "Et que faire s'il y a plusieurs ennemis ?";
			link.l1.go = "guide_51";
		break;
		
		case "guide_51":
			dialog.text = "Ça complique les choses. Un bon combattant peut abattre quelques imbéciles mal formés ensemble en plein air, mais s'il y a une douzaine de vauriens qui vous attaquent - évitez d'être encerclé à tout prix, fuyez, trouvez-vous un coin ou des escaliers, des portes, n'importe quoi, forcez-les à vous combattre un par un, ou deux contre un. Ils vous découperont en une seconde si vous faites une erreur, alors forcez-les à jouer selon vos conditions, ne perdez pas l'initiative et surveillez votre endurance.\nCependant, j'ai entendu parler d'une potion indienne spéciale qui permettait aux maîtres de l'épée et de la hache de tuer cinq ou six ennemis à la fois avec quelques attaques de groupe.";
			link.l1 = "Une potion spéciale ?";
			link.l1.go = "guide_52";
		break;
		
		case "guide_52":
			dialog.text = "Mélange d'Ometochtli ou peu importe comment ils l'appellent. Une recette indienne ancienne. Demandez aux marchands, quelqu'un pourra vous le vendre un jour. Mais vous devez d'abord apprendre l'alchimie pour pouvoir utiliser la recette... Puisque nous parlons déjà de potions - laissez-moi vous parler de la guérison.\nSi vous avez besoin de soigner une petite blessure, utilisez des potions de guérison. Les coups sérieux peuvent être traités avec un élixir. Les mélanges de guérison, le rhum et le vin restaurent également votre santé.\nUn antidote et un mélange feront l'affaire si vous êtes empoisonné. Je recommande également une racine de gingembre, elle rafraîchit merveilleusement votre haleine. Elle guérit aussi sans aucun effet secondaire, contrairement aux essences et élixirs.";
			link.l1 = "Attends, des effets secondaires ?";
			link.l1.go = "guide_53";
		break;
		
		case "guide_53":
			dialog.text = "Essences, élixirs et mixtures nuisent à votre santé. Comme je l'ai mentionné au début de notre petite visite, c'est mauvais. Une mauvaise santé entraînera des baisses de vos niveaux de compétence, elle diminuera le montant total de vos points de santé et de votre endurance.\nDormir, le sexe, et une potion rare appelée les 'Larmes d'Ish-Chel', je ne suis pas sûr du nom, tout ce que je sais, c'est qu'il y a des larmes dedans, enfin ces choses-là restaureront la santé si elle n'est pas complètement ruinée. Si c'est trop tard, allez voir un prêtre, ils vous aideront contre rémunération.";
			link.l1 = "Je vois. Que pouvez-vous me dire sur les armes à feu?";
			link.l1.go = "guide_54";
		break;
		
		case "guide_54":
			dialog.text = "Pas grand-chose à dire. Vise et tire ! Utilise de la mitraille s'il y a plusieurs ennemis. Obtiens un mousquet ou un fusil, ils infligent des dégâts mortels et tu peux toujours frapper les gens avec la crosse. J'ai aussi entendu parler d'un mousquet à la tromblon qui tire des grenades, c'est une arme excellente et très belle aussi... mais je ne l'ai jamais vue.";
			link.l1 = "Je vois. Temps d'entraînement ?";
			if (FindCharacterItemByGroupWithout_knife_03(pchar, BLADE_ITEM_TYPE) == "") link.l1.go = "guide_55a";
			else link.l1.go = "guide_55";
		break;
		
		case "guide_55a":
			dialog.text = "Hm. Je viens de remarquer. Où est votre épée ? Je crains que notre leçon ne doive être différée. Comment vous êtes-vous retrouvé sans arme, "+pchar.name+" ?";
			link.l1 = "Un fils de pute royal en costume chic me l’a pris comme avance sur la dette de mon frère... As-tu une épée de rechange pour moi ? Je la rendrai une fois la leçon terminée...";
			link.l1.go = "guide_55b";
		break;
		
		case "guide_55b":
			GiveItem2Character(pchar, "blade_05");
			EquipCharacterByItem(Pchar, "blade_05");
			dialog.text = "Tu as de la chance. J'ai une épée supplémentaire. J'allais la vendre, mais, chanceux que tu es, j'ai été retardé.";
			link.l1 = "Merci. Allons-y?";
			link.l1.go = "guide_55";
		break;
		
		case "guide_55":
			dialog.text = "En garde ! Et ne gaspillez pas les potions que vous avez, nous n'allons pas nous entre-tuer.";
			link.l1 = "Comme tu dis.";
			link.l1.go = "guide_56";
			npchar.quest.guide_win = 0;
		break;
		
		case "guide_56": // махач
			LAi_SetPlayerType(pchar);
			LAi_SetCurHPMax(pchar); 
			LAi_GetCharacterMaxEnergy(pchar);
			LAi_SetCurHPMax(npchar); 
			LAi_GetCharacterMaxEnergy(npchar);
			LAi_SetImmortal(npchar, false);
			LAi_group_Delete("EnemyFight");
			if (MOD_SKILL_ENEMY_RATE <= 6)	// На первых трёх сложностях Валинье будет ослаблен
			{
				LAi_SetHP(npchar, LAi_GetCharacterMaxHP(npchar) * 0.7, LAi_GetCharacterMaxHP(npchar) * 0.7);
				npchar.rank = 1;
				SetSelfSkill(npchar, 1, 1, 1, 1, 1);
			}
			DialogExit();
			LAi_SetWarriorType(npchar);
			LAi_group_MoveCharacter(npchar, "EnemyFight");
			// ставим проверяльщики
			LAi_SetCheckMinHP(pchar, 1, true, "Guide_HeroFail");
			LAi_SetCheckMinHP(npchar, 1, true, "Guide_HeroWin");
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			AddDialogExitQuest("MainHeroFightModeOn");
			DoQuestCheckDelay("GuideFight_tutorial", 1.0);
		break;
		
		case "guide_57": // побил гида с первого раза
			dialog.text = "Vous... vous êtes un homme qui sait comment tenir son épée. Bien joué, Monsieur. Vous avez besoin de plus de pratique, mais vous avez le potentiel pour devenir un véritable maître d'épée.";
			link.l1 = "Merci beaucoup. Et maintenant ?";
			link.l1.go = "guide_62"; // нода на выход
			if (MOD_SKILL_ENEMY_RATE >= 6)
			{
				link.l2 = "Plus de pratique, dites-vous ? Vous êtes sérieux ? J'en ai assez de ce ton condescendant depuis que j'ai mis les pieds dans cet endroit misérable !";				//Пасхалка Корсары 2 для сложности СФ и выше
				link.l2.go = "guide_64";
			}
			AddComplexSelfExpToScill(50, 50, 50, 50);
			AddCharacterExpToSkill(pchar, "Leadership", 80);
		break;
		
		case "guide_58": // побил гида со второго или третьего раза
			dialog.text = "Beaucoup mieux ! Tu vois, il te suffit de te concentrer. Il te faut plus de pratique, un jour tu deviendras un escrimeur décent.";
			link.l1 = "Merci beaucoup. Que faire maintenant ?";
			link.l1.go = "guide_62"; // нода на выход
			AddComplexSelfExpToScill(20, 20, 20, 20);
			AddCharacterExpToSkill(pchar, "Leadership", 30);
		break;
		
		case "guide_59": // побили первый раз
			dialog.text = "J'ai gagné, Monsieur. Bougez plus vite, parez mes coups, sautez en arrière. Un autre duel ?";
			link.l1 = "Oui! Pas de quartier, Monsieur!";
			link.l1.go = "guide_56";
			link.l2 = "Non, j'en ai assez. Finissons la leçon. Que maintenant ?";
			link.l2.go = "guide_62"; // нода на выход
		break;
		
		case "guide_60": // побили второй раз
			dialog.text = "J'ai encore gagné, "+pchar.name+" ! Ne perds pas ton initiative. Attrape mes coups, feins-les. Si tu vois que je vais frapper fort - esquive ou pare, ne te contente pas de te défendre. Encore !";
			link.l1 = "Venez, Monsieur, je vais vous rosser cette fois-ci !";
			link.l1.go = "guide_56";
			link.l2 = "Non, j'en ai assez. Finissons la leçon. Et maintenant ?";
			link.l2.go = "guide_62"; // нода на выход
		break;
		
		case "guide_61": // побили третий раз
			dialog.text = "Tu as beaucoup à apprendre, "+pchar.name+"Ne t'inquiète pas, tu as encore beaucoup de temps pour maîtriser l'art de l'escrime. Mais fais attention, ne prends pas de risques tant que tu ne sais pas comment tenir une arme.";
			link.l1 = "Je vais y réfléchir, Monsieur, mais je dois dire que vous avez eu une sacrée chance ! Cette maudite chaleur... la seule raison pour laquelle je ne vous ai pas rossé. Merde, terminons notre leçon d'escrime. Que faire maintenant ?";
			link.l1.go = "guide_62"; // нода на выход
		break;
		
		case "guide_62":
			dialog.text = "Maintenant, il est temps de dire adieu, Monsieur. Ce fut un plaisir. J'espère que ma présentation et ma formation vous ont été bénéfiques et vous seront utiles à l'avenir. Peut-être nous reverrons-nous un jour. \nEt à propos de l'argent dont vous avez besoin - parlez aux personnes importantes de notre ville. Visitez tous les endroits que je vous ai montrés aujourd'hui et parlez à leurs propriétaires. Renseignez-vous. Faites une promenade dans la jungle et jusqu'au fort. Trouvez un emploi ou... eh bien, je ne suis ni prêtre ni juge, fouillez dans les maisons des gens et voyez quels bibelots vous pouvez trouver dans leurs coffres déverrouillés. Faites-le simplement quand ils ont le dos tourné ou les gardes vous attraperont. \nBonne chance, "+pchar.name+", J'ai le fort sentiment que tu as l'étincelle de la vraie grandeur en toi. Fais de ton mieux pour l'attiser en un feu ardent !";
			link.l1 = "Merci, Monsieur. Le plaisir était pour moi. Bon vent !";
			link.l1.go = "guide_63";
		break;
		
		case "guide_63":
			LAi_SetCurHPMax(pchar); 
			LAi_GetCharacterMaxEnergy(pchar);
			DialogExit();
			chrDisableReloadToLocation = false;//открыть локацию
			npchar.lifeday = 0;
			DoQuestReloadToLocation("FortFrance_Town", "quest", "quest2", "");
		break;
		
		case "guide_64": // решили убить Валинье
			dialog.text = "Tiens ta langue, Monsieur ! Je ne tolérerai plus une telle insolence. Cependant, je comprends ta réaction face à un nouvel environnement, donc je pardonne ton éclat cette fois-ci. Mais fais attention à tes paroles dorénavant. Adieu, Monsieur de Maure.";
			link.l1 = "Sans vouloir vous offenser, Monsieur Valinnie. Si nous étions au Louvre en ce moment, vous surveilleriez votre ton ! Il est temps de donner une leçon finale à cette province. Défendez-vous !";
			link.l1.go = "guide_65";
		break;
		
		case "guide_65":
			DialogExit();
			
			npchar.rank = 25;
			int iHp = MOD_SKILL_ENEMY_RATE*10+300;
			LAi_SetHP(npchar, iHp, iHp);
			SetSelfSkill(npchar, 80, 80, 80, 80, 50);
			SetShipSkill(npchar, 50, 80, 35, 30, 50, 20, 30, 20, 80);
			SetSPECIAL(npchar, 9, 5, 8, 6, 5, 10, 8);
			SetCharacterPerk(npchar, "Energaiser");
			SetCharacterPerk(npchar, "BasicDefense");
			SetCharacterPerk(npchar, "AdvancedDefense");
			SetCharacterPerk(npchar, "CriticalHit");
			SetCharacterPerk(npchar, "Tireless");
			SetCharacterPerk(npchar, "HardHitter");
			SetCharacterPerk(npchar, "Sliding");
			SetCharacterPerk(npchar, "BladeDancer");
			SetCharacterPerk(npchar, "SwordplayProfessional");
			SetCharacterPerk(npchar, "Gunman");
			SetCharacterPerk(npchar, "GunProfessional");
			GiveItem2Character(npchar, "blade_30");
			EquipCharacterbyItem(npchar, "blade_30");
			GiveItem2Character(npchar, "cirass7");
			GiveItem2Character(npchar, "obereg_7");
			GiveItem2Character(npchar, "talisman11");
			AddMoneyToCharacter(npchar, 10000);
			AddItems(npchar, "gold_dublon", 25);
			AddItems(npchar, "bullet", 5);
			AddItems(npchar, "grapeshot", 5);
			AddItems(npchar, "GunPowder", 10);
			TakeItemFromCharacter(npchar, "blade_12");
			npchar.cirassId = Items_FindItemIdx("cirass4");
			LAi_SetCurHPMax(npchar);
			LAi_GetCharacterMaxEnergy(npchar);
			LAi_SetCurHPMax(pchar); 
			LAi_GetCharacterMaxEnergy(pchar);
			LAi_SetImmortal(npchar, false);
			LAi_group_Delete("EnemyFight");
			LAi_SetWarriorType(npchar);
			LAi_group_MoveCharacter(npchar, "EnemyFight");
			npchar.SaveItemsForDead = true;
			npchar.DontClearDead = true;
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, false);
			LAi_group_SetCheck("EnemyFight", "Guide_HeroKill");
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}

string FindCharacterItemByGroupWithout_knife_03(ref chref, string groupID)
{
	ref refItm;
    string resultItemId;

	resultItemId  = "";
	for(i=TOTAL_ITEMS-1; i>=0; i--)
	{
		refItm = &Items[i];
		if( !CheckAttribute(refItm,"groupID") ) continue;
		if(refItm.groupID!=groupID) continue;
		if( !CheckAttribute(chref,"items."+refItm.id) ) continue;
		if(refItm.id == "knife_03") continue;
		if (groupID == BLADE_ITEM_TYPE)
		{
			resultItemId  = refItm.id;
		}
	}
	
	if (resultItemId != "")
	{
        return resultItemId;
	}

	return "";
}