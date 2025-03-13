// диалоги прочих НПС по квесту LSC
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
			link.l1 = "Non, ce n'est rien.";
			link.l1.go = "exit";			
			NextDiag.TempNode = "First time";
		break;
		
		//-----------------------------------бандосы Акулы в трюме с припасами--------------------------------------
		case "PantryGuard":
			dialog.text = "Ho, ho, regardez-moi ça, les gars ! Qui vient nous rendre visite ! Un voleur pillant les coffres des gens ! Viens ici ! Et toi, camarade, ne fais même pas semblant d'être idiot et sors ta lame - je ne manquerai pas à une telle distance... Chad sera vraiment ravi de te voir !";
			link.l1 = "Mais je... je viens d'arriver !";
			link.l1.go = "PantryGuard_1";
		break;
		
		case "PantryGuard_1":
			dialog.text = "Tu as raison, ha-ha ! Tu viens de te fourrer dans un vrai pétrin, l'ami... Et tu ne t'en sortiras pas. Maintenant, rends tes armes et suis-moi ! La cage sur le 'Tartarus' t'attend depuis si longtemps, voleur !";
			link.l1 = "...";
			link.l1.go = "PantryGuard_2";
		break;
		
		case "PantryGuard_2":
			DialogExit();
			chrDisableReloadToLocation = false;
			SetLaunchFrameFormParam("Few hours later...", "", 0, 3);
			LaunchFrameForm();
			WaitDate("", 0, 0, 0, 7, 10); //крутим время
			RecalculateJumpTable();
			DoQuestFunctionDelay("LSC_GotoPrison", 3.0);
		break;
		
		case "CommonGuard":
			dialog.text = "N'essaie pas de voler quoi que ce soit d'ici. Je te surveillerai.";
			link.l1 = "Vous êtes le bienvenu.";
			link.l1.go = "exit";
			NextDiag.TempNode = "CommonGuard";
		break;
		
		case "ChadGuard":
			dialog.text = "Va et fais ce que Chad t'a dit. Ne parle pas trop !";
			link.l1 = "Oui, je suis en route...";
			link.l1.go = "exit";
			NextDiag.TempNode = "ChadGuard";
		break;
		
		case "ChadGuard_Attack":
			dialog.text = "Hé ! Que diable fais-tu là ? Salaud ! Maintenant, tu es fichu !";
			link.l1 = "... ";
			link.l1.go = "ChadGuard_Attack_1";
		break;
		
		case "ChadGuard_Attack_1":
			DialogExit();
			sld = characterFromId("Chimiset");
			LAi_SetActorType(sld);
			LAi_ActorAnimation(sld, "afraid", "", -1);
			for(i = 1; i <= 3; i++)
			{				
				sld = CharacterFromID("ChadGuard_"+i);
				LAi_RemoveCheckMinHP(sld);
				LAi_SetWarriorType(sld);
				LAi_group_MoveCharacter(sld, "EnemyFight");
			}
			sld = characterFromId("Capper");
			LAi_SetWarriorType(sld);
			ChangeCharacterAddressGroup(sld, "Tartarusprison", "goto", "goto8");
			LAi_group_MoveCharacter(sld, "EnemyFight");
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("EnemyFight", "LSC_ChadGuard_Die");
			AddDialogExitQuest("MainHeroFightModeOn");
			pchar.GenQuest.Notsearchbody = true; // запрет обыска трупов
		break;
		
		// ----------------------------------Марчелло Циклоп--------------------------------
		// если ждали в каюте
		case "Cabin":
			dialog.text = "Eh bien, que diable fais-tu ici, bon sang ? Où est Barbier ?";
			link.l1 = "Notre ami Adolfo est... malade. Il n'a pas pu venir à la réunion, alors il m'a demandé de m'asseoir un peu dans sa cabine et de vous attendre.";
			link.l1.go = "Cabin_1";
		break;
		
		case "Cabin_A":
			dialog.text = "Eh bien, qu'est-ce que tu fous ici, bon sang ?";
			link.l1 = "Notre ami Adolfo est... malade. Il n'a pas pu venir à la réunion, alors il m'a demandé de le remplacer. Pour ainsi dire.";
			link.l1.go = "Cabin_1";
		break;
		
		case "Cabin_1":
			dialog.text = "Ça paraît étrange... il allait bien ce matin et maintenant il est malade.";
			link.l1 = "Eh bien, vous savez comment les choses se passent. La soudaine attaque de fièvre...";
			link.l1.go = "Cabin_2";
		break;
		
		case "Cabin_2":
			dialog.text = "Oh, je n'aime pas ta tête. Tu mens. Barbier n'aurait jamais confié cette rencontre à quelqu'un d'autre. Parle, salaud, qui es-tu et qu'est-ce que tu lui as fait ?";
			link.l1 = "Tu sais, t'as pas une belle gueule non plus. Je t'ai déjà dit que Barbier est malade. T'as l'esprit lent ou faut-il que je me répète ? Il était censé te donner la clé et...";
			link.l1.go = "Cabin_3";
		break;
		
		case "Cabin_3":
			DialogExit();
			sld = characterFromId("Mary");
			LAi_SetActorType(sld);
			LAi_CharacterEnableDialog(sld);
			LAi_ActorDialog(sld, pchar, "", -1, 0);
		break;
		
		// на Церес Смити - спасаем Мэри
		case "mary":
			dialog.text = "Bon sang ! Vous m'avez retrouvé...";
			link.l1 = "Oui, racaille ! Tu ne la toucheras pas ! Prépare-toi à mourir !";
			link.l1.go = "mary_1";
		break;
		
		case "mary_1":
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);//разрешить драться
			DialogExit();
			LAi_SetWarriorType(npchar);
			LAi_group_MoveCharacter(npchar, "EnemyFight");
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("EnemyFight", "LSC_KillCyclop_CS");
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		
		// посланник от Акулы по варианту N
		case "SharkCureer":
			dialog.text = "Es-tu "+GetFullName(pchar)+"?";
			link.l1 = "Oui, c'est moi. Quel est le problème ?";
			link.l1.go = "SharkCureer_1";
		break;
		
		case "SharkCureer_1":
			dialog.text = "Requin m'a envoyé. Il vous demande de le voir dès que possible. Il a quelque chose d'important pour vous.";
			link.l1 = "Quelle est la hâte?.. Très bien, je vais au 'San Agustin' immédiatement.";
			link.l1.go = "SharkCureer_2";
		break;
		
		case "SharkCureer_2":
			// сюда можно поставить таймер на гибель Акулы, если не придёт до конца суток
			DialogExit();
			LAi_SetActorType(npchar);
			npchar.lifeday = 0;
			LAi_ActorGoToLocation(npchar, "reload", "reload1", "none", "", "", "", -1);
			sld = characterFromId("Dodson");
			sld.dialog.currentnode = "entrance_20"; // ноду Акуле
		break;
		
		// посланник от Акулы по варианту M
		case "SharkCureer_3":
			dialog.text = "Es-tu "+GetFullName(pchar)+"?";
			link.l1 = "Oui, c'est moi. Quel est le problème ?";
			link.l1.go = "SharkCureer_4";
		break;
		
		case "SharkCureer_4":
			if (!CheckAttribute(pchar, "questTemp.Saga.DodsonDie"))
			{
				dialog.text = "Ah, je suis fatigué de te chercher... Le Requin et Layton Dexter. Ils te demandent de les voir immédiatement. C'est une affaire très importante alors dépêche-toi.";
				link.l1 = "Vraiment ? Très bien, je vais à 'San Agustin' immédiatement.";
				link.l1.go = "SharkCureer_6";
			}
			else
			{
				dialog.text = "Ah, je suis fatigué de te chercher... L'amiral Layton Dexter te demande de le voir immédiatement. C'est une affaire très importante, alors dépêche-toi.";
				link.l1 = "Amiral ?";
				link.l1.go = "SharkCureer_5";
			}
		break;
		
		case "SharkCureer_5":
			dialog.text = "Oui. En tant que second en commande, il est devenu notre amiral après la mort du Requin.";
			link.l1 = "Je vois. Très bien, je vais au 'San Agustin' immédiatement.";
			link.l1.go = "SharkCureer_6";
		break;
		
		case "SharkCureer_6":
			DialogExit();
			LAi_SetActorType(npchar);
			npchar.lifeday = 0;
			LAi_ActorGoToLocation(npchar, "reload", "reload1", "none", "", "", "", -1);
		break;
		
		// тюремщик вместо Каппера
		case "Prisonboss":
			if (npchar.quest.meeting == "0")
			{
				dialog.text = "Ah, te voilà... Je me souviens de toi, tu es le dernier homme qui a parlé à Chimiset. L'as-tu tué ?";
				link.l1 = "Arrête tes conneries ! Tu sais parfaitement que ce n'était pas moi. Je pense que tu sais qui est le meurtrier.";
				link.l1.go = "meeting";
				npchar.quest.meeting = "1";
			}
			else
			{
				dialog.text = "Eh, c'est tellement ennuyeux de rester ici toute la journée ! Si seulement tu pouvais apporter du rhum et des cartes ici, l'ami, on pourrait jouer...";
				link.l1 = "Désolé, camarade, je n'ai pas le temps pour ça. Peut-être plus tard.";
				link.l1.go = "exit";
			}
			NextDiag.TempNode = "Prisonboss";
		break;
		
		case "meeting":
			dialog.text = "J'ai quelques suppositions, oui, mais je n'ai aucun fait. Personne n'a vu la mort du type noir. Il y a des rumeurs partout sur l'île que nous, les gens du Requin, sommes responsables et ils disent qu'un nouveau venu a fait cela sur ordre de l'amiral. Tu comprends maintenant ? Alors ne va pas chez les Rivados, surtout pas maintenant. Ils sont trop en colère.";
			link.l1 = "D'accord. J'ai compris.";
			link.l1.go = "exit";
			NextDiag.TempNode = "Prisonboss";
		break;
		
		case "Prisonboss_M":
			dialog.text = "Eh, c'est si ennuyeux de rester ici toute la journée ! Si seulement tu pouvais apporter du rhum et des cartes ici, l'ami, on pourrait jouer...";
			link.l1 = "Désolé, l'ami, je n'ai pas le temps pour ça. Peut-être plus tard.";
			link.l1.go = "exit";
			NextDiag.TempNode = "Prisonboss_M";
		break;
		
		// заместитель Акселя в магазине
		case "AxelHelper":
			dialog.text = "Que veux-tu, l'ami ?";
			link.l1 = "Hm. Et qu'est-ce qui vous amène ici? Où est Axel?";
			link.l1.go = "AxelHelper_1";
		break;
		
		case "AxelHelper_1":
			dialog.text = "Axel est occupé. Il a une réunion avec Donald Greenspen et il restera avec lui jusqu'à la fin de la journée. Alors, si tu veux acheter quelque chose - parle-lui demain matin. Et je surveille la boutique, donc n'essaie pas de voler quoi que ce soit...";
			link.l1 = "Je vois. Et pourquoi le fait-il aujourd'hui ? Très bien, je viendrai ici demain matin.";
			link.l1.go = "exit";
			NextDiag.TempNode = "AxelHelper_2";
		break;
		
		case "AxelHelper_2":
			dialog.text = NPCStringReactionRepeat("Je t'ai déjà tout dit. Reviens demain.","Ne me dérange pas, l'ami. Dégage !","Ne m'énerve pas, crétin !","Va-t'en !!","bloc",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("D'accord.","Je l'ai, je l'ai.","Tais-toi...","Quoi?!",npchar,Dialog.CurrentNode);
			link.l1.go = DialogGoNodeRepeat("exit", "", "", "", npchar, Dialog.CurrentNode);
		break;
		
		// мать Белого Мальчика - Агнес Кристиансен
		case "agnes":
			dialog.text = "Que voulez-vous, monsieur ?";
			link.l1 = "Hm... Je suis désolé, maîtresse. Pardonnez-moi pour mon impertinence et mes mauvaises manières, mais je veux vous demander quelque chose : connaissez-vous un homme nommé Ole Christiansen ?";
			link.l1.go = "agnes_1";
		break;
		
		case "agnes_1":
			dialog.text = "Répète encore ce que tu viens de dire... Ole Christiansen ? Ole ?!";
			link.l1 = "Oui. Ils l'appellent aussi le Garçon Blanc à cause de la couleur particulière de ses cheveux. Le connaissez-vous ?";
			link.l1.go = "agnes_2";
		break;
		
		case "agnes_2":
			dialog.text = "Le connais-je ?! C'est mon fils et il est porté disparu depuis une décennie ! Savez-vous où il est, monsieur ? Dites-moi déjà où il est, que lui est-il arrivé ?!";
			link.l1 = "Calmez-vous, maîtresse, ne vous inquiétez pas ainsi. Il va bien. Il est sur mon navire. Tout ce qu'il a besoin de faire, c'est d'accoster et de venir ici.";
			link.l1.go = "agnes_3";
		break;
		
		case "agnes_3":
			dialog.text = "Oh... Il semble que le Seigneur ait enfin entendu mes prières ! Tu ne peux pas imaginer à quel point je m'inquiétais quand il a disparu ! Et c'était ma faute, rien que ma faute ! Où l'as-tu trouvé ? Ce n'est pas un enfant ordinaire... eh bien, tu dois savoir de quoi je parle.";
			link.l1 = "Je le fais. Oui, il est spécial. Et il n'a pas changé. Il semble qu'il soit encore un enfant. Je l'ai trouvé sur une île. Nous nous sommes rencontrés par hasard. Il m'a demandé une perle blanche... bon sang !... Pour une perle.";
			link.l1.go = "agnes_4";
		break;
		
		case "agnes_4":
			dialog.text = "Une perle? Oh, Dieu! Les perles sont la raison pour laquelle mon garçon a disparu! C'est à cause de ce maudit collier!";
			link.l1 = "Est-il vrai qu'Ole... a quitté sa demeure à cause de la rupture de votre collier de perles ?... Calmez-vous, maîtresse, ne pleurez pas !";
			link.l1.go = "agnes_5";
		break;
		
		case "agnes_5":
			dialog.text = "Oui, c'est vrai. Ole a déchiré mon collier sur le quai et toutes les perles sont tombées à l'eau. Je l'ai tellement maudit, et feu mon mari... l'a puni. Ole a disparu le lendemain. Vous ne pouvez pas imaginer à quel point je me suis blâmée pour cela !";
			link.l1 = "Olé a récolté des perles pendant des années. Il les appelle les perles blanches. Il les a toutes collectées pour vous et m'a demandé de vous amener à lui. Je n'avais pour indice que la maison au toit rouge. Mais j'ai enfin réussi à vous trouver.";
			link.l1.go = "agnes_6";
		break;
		
		case "agnes_6":
			dialog.text = "Ramasser des perles?! Oh, mon Dieu ! Je suis si coupable envers mon pauvre garçon ! Moi... et il a ramassé des perles ! Oh!";
			link.l1 = "Je suppose que je ferais mieux d'appeler votre fils, maîtresse. Il était si impatient de vous voir. Il a dit que vous serez heureuse de voir des perles. Mais je pense que vous serez heureuse pas à cause d'elles...";
			link.l1.go = "agnes_7";
		break;
		
		case "agnes_7":
			dialog.text = "Monsieur... seriez-vous aimable. Apportez-moi mon Ole. Je veux le serrer dans mes bras et lui demander pardon...";
			link.l1 = "Bien sûr, maîtresse. Ils le ramèneront ici tout de suite.";
			link.l1.go = "agnes_8";
		break;
		
		case "agnes_8":
			DialogExit();
			SetLaunchFrameFormParam("One hour later", "", 0, 5);
			LaunchFrameForm();
			WaitDate("", 0, 0, 0, 1, 10); //крутим время
			RecalculateJumpTable();
			DoQuestFunctionDelay("LSC_OleGoHome", 5.0);
		break;
		
		case "agnes_9":
			dialog.text = "";
			link.l1 = "Eh bien, maîtresse, voici votre fils - Ole Christiansen. Le reconnaissez-vous?";
			link.l1.go = "agnes_10";
		break;
		
		case "agnes_10": // перекидываем pchar
			DialogExit();
			LAi_SetActorType(pchar);
			LAi_ActorTurnToCharacter(pchar, characterFromID("Agnes"));
			ChangeShowIntarface();
			SetMainCharacterIndex(GetCharacterIndex("Agnes"));
			PChar = GetMainCharacter();			
			LAi_SetPlayerType(PChar);
			sld = characterFromId("Ole");
			sld.dialog.currentnode = "home";
			LAi_SetActorType(sld);
			LAi_ActorDialog(sld, pchar, "", -1, 0);
		break;
		
		case "agnes_11":
			dialog.text = "Monsieur... Je suis désolé, je n'ai pas demandé votre nom... "+pchar.name+"?";
			link.l1 = "Bonjour, mon ami."+GetFullName(pchar)+", maîtresse. Capitaine "+GetFullName(pchar)+".";
			link.l1.go = "agnes_12";
		break;
		
		case "agnes_12":
			dialog.text = "Capitaine, vous ne pouvez pas imaginer à quel point je suis reconnaissant pour mon fils ! Vous l'avez aidé et l'avez amené ici. Vous m'avez fait revivre ! Je ferai tout pour mon garçon, je lui donnerai tout l'amour qui lui a manqué toutes ces années.";
			link.l1 = "Je suis heureux pour vous, maîtresse. Et pour Ole aussi. C'est un bon garçon et il m'a aidé dans une situation difficile. Il a un cœur généreux. Je connais un homme qu'Ole a sauvé de la mort.";
			link.l1.go = "agnes_13";
		break;
		
		case "agnes_13":
			dialog.text = "Mynheer, j'insiste pour que vous veniez ici demain ou à un moment où vous trouverez le temps. Je veux vous remercier pour mon fils. En ce moment, je suis juste un peu... eh bien, vous savez.";
			link.l1 = "Je le fais, maîtresse.";
			link.l1.go = "agnes_14";
		break;
		
		case "agnes_14":
			dialog.text = "Reviens ici demain. Je te récompenserai comme il se doit pour tout le bien que tu as fait à mon fils et à moi.";
			link.l1 = "D'accord. Je viendrai te voir, c'est certain !";
			link.l1.go = "agnes_15";
		break;
		
		case "agnes_15":
			DialogExit();
			bDisableCharacterMenu = false;//лоченые интерфейсы
			chrDisableReloadToLocation = false;//открыть локацию
			LAi_SetOwnerType(npchar);
			LocatorReloadEnterDisable("Marigo_town", "houseSp2", true);
			NextDiag.CurrentNode = "agnes_16";
			pchar.quest.LSC_Ole_return.win_condition.l1 = "Timer";
			pchar.quest.LSC_Ole_return.win_condition.l1.date.hour  = 8.0;
			pchar.quest.LSC_Ole_return.win_condition.l1.date.day   = GetAddingDataDay(0, 0, 1);
			pchar.quest.LSC_Ole_return.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 1);
			pchar.quest.LSC_Ole_return.win_condition.l1.date.year  = GetAddingDataYear(0, 0, 1);
			pchar.quest.LSC_Ole_return.function = "LSC_OleAgnesRegard";
			// удаляем Оле из пассажиров
			sld = characterFromId("Ole");
			RemovePassenger(Pchar, sld);
			DeleteAttribute(pchar, "GenQuest.Ole");
			DoQuestReloadToLocation("Marigo_town", "reload", "houseSp2", "");
		break;
		
		case "agnes_16":
			dialog.text = "Ah, vous voilà, monsieur "+GetFullName(pchar)+" ! Viens, prends place...";
			link.l1 = "Merci ! Comment va Ole ?";
			link.l1.go = "agnes_17";
		break;
		
		case "agnes_17":
			dialog.text = "Oh, vous ne pouvez pas imaginer ce que vous avez fait ! Vous étiez un baume pour le cœur d'une mère... Je vous dois beaucoup et je prierai pour vous à jamais.";
			link.l1 = "Tu me fais rougir, maîtresse...";
			link.l1.go = "agnes_18";
		break;
		
		case "agnes_18":
			dialog.text = "J'ai toujours su que la modestie est ce qui rend les gens nobles nobles... J'ai préparé des présents pour ce que tu as fait. Oui-oui! Et n'ose même pas décliner! Tiens, prends ça... D'abord, il y a un coffre rempli de doublons. Ensuite, prends cet amulette enchantée, ils l'appellent un Scarabée\nMon mari le possédait, et je suis sûre qu'il aurait été heureux de savoir que son trésor appartiendra à un capitaine aussi noble, qui a ramené mon fils à moi. Mon mari était charpentier, il disait que le Scarabée accélérait son travail\nJ'espère que cette bague te servira bien. Tu mérites de la porter, sans aucun doute! Et enfin, prends mes outils de couture. C'est un bel ensemble. Tu pourras confectionner beaucoup de bonnes choses avec.";
			link.l1 = "Oh ! Ce sont vraiment des cadeaux précieux pour n'importe quel capitaine ! Merci, maîtresse.";
			link.l1.go = "agnes_19";
		break;
		
		case "agnes_19":
			PlaySound("interface\important_item.wav");
			Log_Info("You have received a chest with doubloons");
			Log_Info("You have received the 'Scarab' amulet");
			Log_Info("You have received a sartorial set");
			GiveItem2Character(pchar, "chest");
			GiveItem2Character(pchar, "talisman7");
			GiveItem2Character(pchar, "tailor_tool");
			dialog.text = "Et je veux que tu saches que les portes de ma maison te sont toujours ouvertes à tout moment. Tu trouveras toujours ici de la nourriture, une bouteille de bon vin et tout ce que tu désires.";
			link.l1 = "Merci pour vos aimables paroles, maîtresse. Je serai heureux de vous revoir lors de ma prochaine visite dans cette ville.";
			link.l1.go = "agnes_20";
		break;
		
		case "agnes_20":
			dialog.text = "N'oublie pas de venir !";
			link.l1 = "Et maintenant je dois partir. Adieu et bonne chance !";
			link.l1.go = "agnes_21";
		break;
		
		case "agnes_21":
			DialogExit();
			NextDiag.CurrentNode = "agnes_22";
			AddCharacterExpToSkill(pchar, "Fortune", 350);
			AddCharacterExpToSkill(pchar, "Leadership", 500);
			ChangeCharacterComplexReputation(pchar, "nobility", 10);
			ChangeCharacterComplexReputation(pchar, "authority", 4);
		break;
		
		case "agnes_22":
			dialog.text = "Ah, capitaine "+GetFullName(pchar)+" ! Je suis si heureux de te voir ! Viens t'asseoir, je vais te servir un verre...";
			link.l1 = "Merci ! Je voulais juste te saluer et savoir comment tu allais. Je suis content que toi et Ole alliez bien.";
			link.l1.go = "exit";
			NextDiag.TempNode = "agnes_22";
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		//----------------------------------------- специальные реакции -----------------------------------------------
		//обнаружение ГГ в сундуках
		case "Man_FackYou":
			dialog.text = LinkRandPhrase("Que fais-tu là, hein? Voleur!","Regardez-moi ça ! Dès que je me suis perdu dans mes pensées, vous avez décidé de fouiller dans mon coffre !","Décidé à fouiller mes coffres? Tu ne t'en tireras pas comme ça !");
			link.l1 = "Merde !";
			link.l1.go = "fight";
		break;
		
		case "Woman_FackYou":
			dialog.text = "Quoi ?! Vous avez décidé de fouiller mes coffres ? Vous ne vous en tirerez pas comme ça !";
			link.l1 = "Folle fille !";
			link.l1.go = "exit_setOwner";
			LAi_group_Attack(NPChar, Pchar);
		break;
		
		case "fight":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			LAi_SetOwnerTypeNoGroup(npchar);
			LAi_group_Attack(NPChar, Pchar);
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		
		case "exit_setOwner":
			LAi_SetOwnerTypeNoGroup(npchar);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}
