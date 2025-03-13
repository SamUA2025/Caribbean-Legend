// Jason общий диалог смотрителей кладбищ
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;	

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

    // вызов диалога по городам -->
    NPChar.FileDialog2 = "DIALOGS\" + LanguageGetLanguage() + "\Cemetery\" + NPChar.City + "_cemetery.c";
    if (LoadSegment(NPChar.FileDialog2))
	{
        ProcessCommonDialog(NPChar, Link, NextDiag);
		UnloadSegment(NPChar.FileDialog2);
	}
    // вызов диалога по городам <--
	
    int iTemp;
	string sTemp;
	bool ok;
    
	switch(Dialog.CurrentNode)
	{
		case "First time":
			if (LAi_grp_playeralarm > 0)
			{
       			dialog.text = PCharRepPhrase(LinkRandPhrase("La ville est en alerte. Il semble que c'est le moment pour moi aussi de prendre les armes...","N'es-tu pas poursuivi par toute la garde de la ville?. A moi, soldats!!!","Tu ne trouveras pas d'abri ici. Mais tu trouveras quelques pouces d'acier froid sous une côte !"),LinkRandPhrase("Que voulez-vous, coquin?! Un garde municipal a déjà pris votre piste, vous n'échapperez pas trop loin, "+GetSexPhrase("sale pirate !","canaille")+"!","Arrêtez ! "+GetSexPhrase("Sale tueur ! Garde !!!","Je n'ai pas peur de toi! Bientôt tu seras pendu dans notre fort, il n'y a nulle part où se cacher...")));
				link.l1 = PCharRepPhrase(RandPhraseSimple("On dirait que tu en as marre de vivre...","Et pourquoi ne voulez-vous pas vivre calmement, citoyens..."+XI_ConvertString("Colonie"+npchar.city+"Gen")+"!"),RandPhraseSimple("Va en enfer !","Il vous reste quelques secondes à vivre dans ce monde..."));
				link.l1.go = PCharRepPhrase("exit_setOwner", "fight");
				break;
			}
			if(!CheckAttribute(pchar, "questTemp.Lantern"))
			{
				dialog.text = "A-a-ah! Ah, c'est toi... Qui es-tu? Pourquoi es-tu venu au cimetière?";
				link.l1 = "Mon nom est "+GetFullName(pchar)+". Et qui êtes-vous et que faites-vous ici? Et pourquoi avez-vous si peur?";
				link.l1.go = "Lantern_01";
				npchar.quest.meeting = "1";
				break;
			}
			if(CheckAttribute(pchar, "questTemp.Lantern") && pchar.questTemp.Lantern == "ToCrypt")
			{
				dialog.text = "Alors, comment c'était? Tu as vérifié? Tu me crois maintenant?";
				link.l1 = "Non, je ne suis pas encore descendu dans la crypte. Attends un peu plus longtemps, je vais tout vérifier.";
				link.l1.go = "exit";
				break;
			}
			
			if(CheckAttribute(pchar, "questTemp.Lantern") && pchar.questTemp.Lantern == "ToKeeper")
			{
				dialog.text = "Alors? Tu as jeté un coup d'oeil? Tu l'as vu?";
				link.l1 = "Oui, bien sûr! Tu avais raison!";
				link.l1.go = "Lantern_10";
				link.l2 = "Ce n'était pas tout à fait ce que vous pensiez.";
				link.l2.go = "Lantern_14";
				break;
			}
			if (npchar.quest.meeting == "0")
			{
				dialog.text = RandPhraseSimple("Bonjour, marin! Mon nom est "+GetFullName(npchar)+", et je suis la seule âme vivante ici. En fait, nous allons tous encore mourir, ha-ha-ha! Pourquoi es-tu venu?","Bonjour! Je n'ai pas vu un homme vivant depuis longtemps... Permettez-moi de me présenter - "+GetFullName(npchar)+", et ce cimetière est mon dernier refuge. Apparemment, je serai enterré ici. Comment puis-je vous aider?");
				link.l1 = "Bonjour, "+npchar.name+"! Mon nom est "+GetFullName(pchar)+", et je suis un capitaine. J'ai traversé la jungle et suis arrivé ici. Je pensais jeter un coup d'oeil à l'intérieur de cette maison confortable, pour voir qui n'a pas peur d'y vivre...";
				link.l1.go = "meeting";
				npchar.quest.meeting = "1";
			}
			else
			{
				dialog.text = "Ah, mon vieux ami, capitaine "+GetFullName(pchar)+"! Entrez, entrez !";
				link.l1 = "Bienvenue, ami ! Très heureux de te voir. Ne vois-tu pas des squelettes dansants la nuit et des morts avec des pièces de cuivre sur les yeux dans tes rêves ?";
				link.l1.go = "talk";
			}
			NextDiag.TempNode = "First time";
		break;
		
		case "meeting":
			dialog.text = "Et pourquoi devrais-je avoir peur, capitaine? Il faut craindre les vivants, les morts ne mordent pas. Eh! J'avais une vie bien différente autrefois, et maintenant je suis le gardien de ce cimetière. Je m'occupe des tombes. Et parfois je fais aussi du commerce avec quelques babioles...";
			link.l1 = "Et quels articles échangez-vous, dites-moi, s'il vous plaît?";
			link.l1.go = "trade_info";
		break;
		
		case "talk":
			dialog.text = "Qu'est-ce qui vous amène à moi cette fois ?";
			link.l1 = "Montrez-moi ce que vous avez à vendre aujourd'hui.";
			link.l1.go = "trade";
			link.l2 = "Je veux te poser une question...";
			link.l2.go = "quests";
			link.l3 = "Rien de sérieux. Je suis simplement venu vous saluer.";
			link.l3.go = "exit";
			NextDiag.TempNode = "First time";
		break;
		
		case "trade_info":
			dialog.text = "J'ai beaucoup de temps libre, donc j'aime me promener dans la jungle pour ramasser des plantes utiles et des pierres fantaisistes. Ensuite, je les vends en ville. Ils ne coûtent pas cher, mais - c'est mieux que rien. Et je reçois une variété de choses de mes amis...";
			link.l1 = "Des amis ? Vous voulez dire, vous revendez ce que les autres vous apportent ?";
			link.l1.go = "trade_info_1";
		break;
		
		case "trade_info_1":
			dialog.text = "O-ho-ho... Non, ils me donnent tout gratuitement. Qui peut être ami d'un gardien de cimetière, sinon des morts?";
			link.l1 = "Hein... Tu dépouilles les cadavres ?";
			link.l1.go = "trade_info_2";
		break;
		
		case "trade_info_2":
			dialog.text = "I don't rob; I just take things off those who don't need them anymore. Many different people are buried here-some unknown and not from our lands. The commandant brings a dead body from the town and says: 'This is for you, "+npchar.name+", send him on his final journey.' Homeless, hanged pirates, bandits killed by guardians-all are buried here. And old "+npchar.name+" buries their bodies on a Christian custom.";
			link.l1 = "Je vois. Eh bien, l'argent c'est de l'argent, montrez-moi ce que vous avez.";
			link.l1.go = "trade";
			link.l2 = "Compris. Je dois y aller. J'étais ravi de vous rencontrer.";
			link.l2.go = "exit";
		break;
		
		case "trade":
			DialogExit();
			if (!CheckAttribute(npchar, "trade_date") || GetNpcQuestPastDayParam(npchar, "trade_date") >= 10)
			{
				GiveItemToTrader(npchar);
				SaveCurrentNpcQuestDateParam(npchar, "trade_date");
			}
			LaunchItemsTrade(npchar, 0);
			NextDiag.TempNode = "First time";
		break;
		
		case "fight":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			LAi_group_Attack(NPChar, Pchar);
			if (rand(3) != 1) SetNationRelation2MainCharacter(sti(npchar.nation), RELATION_ENEMY);
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		case "exit_setOwner":
			LAi_SetOwnerTypeNoGroup(npchar);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		case "Man_FackYou"://реакция на попытку залезть в сундук
			dialog.text = LinkRandPhrase("Et toi, "+GetFullName(pchar)+", es un voleur! Gardes!!!","Que diable! Je me suis détourné un instant et tu essaies déjà de voler ce qui m'appartient! Attrapez le voleur!!!","Garde! Vol!!! Attrape le voleur!!!");
			link.l1 = "Oh merde!!!";
			link.l1.go = "fight";
		break;
		//belamour квест на получение фонаря -->
		case "Lantern_01":
			dialog.text = "Ouf, donc tu es juste un voyageur... Mon nom est "+GetFullName(npchar)+", je suis le gardien de cet endroit abandonne par Dieu.";
			link.l1 = "Pourquoi ressentez-vous cela à propos du cimetière? Au contraire, c'est d'ici que notre Seigneur prend les justes après l'enterrement.";
			link.l1.go = "Lantern_02";
		break;
		
		case "Lantern_02":
			dialog.text = "Mais les impies, apparemment, restent ici après l'enterrement ! Depuis quelques nuits, il y a du bruit qui vient de la crypte. Et les gémissements sont si glaçants que ça me donne des frissons... Il semble qu'une âme perdue ne peut pas trouver la paix ! Maintenant, je ne dors que pendant la journée - la nuit, je ne peux pas quitter mon poste ou fermer l'oeil...";
			link.l1 = "Bruits? Gémissements? Mais il n'y a personne là-bas sauf les défunts.";
			link.l1.go = "Lantern_03";
		break;
		
		case "Lantern_03":
			dialog.text = "C'est ce que je dis, tu sais? Tu ferais mieux de partir d'ici avant que le fantôme ne te sente... Sinon, tu ne pourras pas dormir, tout comme moi.";
			link.l1 = "Hm, ouais, je pense qu'il vaut mieux que je quitte cet endroit.";
			link.l1.go = "Lantern_04";
			link.l2 = "Peut-être puis-je vous aider? Laissez-moi enquêter sur ces bruits étranges ce soir.";
			link.l2.go = "Lantern_05";
		break;
		
		case "Lantern_04":
			pchar.questTemp.Lantern = "NoLantern";
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		case "Lantern_05":
			dialog.text = "Es-tu fou?! Je vois que tu as une arme, mais comment comptes-tu combattre les morts-vivants avec? Et si tu finis par passer l'arme à gauche là-bas, qu'arrivera-t-il ensuite? Le fantôme se promènera librement, et il pourrait même te ressusciter en tant que son serviteur!";
			link.l1 = "Eh bien, ce n'est que superstition...";
			link.l1.go = "Lantern_06";
		break;
		
		case "Lantern_06":
			dialog.text = "Quelle superstition ? Ce n'est pas la terre pieuse de l'Europe, bon sang... Les indigènes, ces gens au visage rouge, ils peuvent invoquer n'importe quoi - et maintenant nous devons vivre ici !";
			link.l1 = "Tout de même, laissez-moi essayer. J'attendrai jusqu'à la tombée de la nuit puis j'irai dans la crypte.";
			link.l1.go = "Lantern_07";
		break;
		
		case "Lantern_07":
			dialog.text = "D'accord, fais comme tu veux. Mais si tu ne reviens pas avant le lever du soleil, je fermerai tout, je barricaderai et je partirai d'ici par moi-même ! Que ce soit en lavant le pont en tant que marin ou en transportant des caisses en tant que docker - Je ne reviendrai pas ici de toute façon !";
			link.l1 = "Juste calme-toi... Tout ira bien.";
			link.l1.go = "Lantern_08";
		break;
		
		case "Lantern_08":
			dialog.text = "Attends... Prends cette lanterne. J'en ai une de rechange. Tu en auras besoin là-bas. C'est noir comme dans un four !";
			link.l1 = "Merci, une lanterne sera en effet utile dans un endroit comme celui-là.";
			link.l1.go = "Lantern_09";
		break;
		
		case "Lantern_09":
			GiveItem2Character(pchar, "lantern_belt");
			Log_Info("'Lantern' received");
			PlaySound("interface\important_item.wav");
			if(npchar.city == "Charles") SetFunctionLocationCondition("NoiseCemetery_toCrypt", "Charles_CryptBig2", true);
			if(npchar.city == "Havana") SetFunctionLocationCondition("NoiseCemetery_toCrypt", "Havana_CryptBig2", true);
			if(npchar.city == "Villemstad" || npchar.city == "PortRoyal") SetFunctionLocationCondition("NoiseCemetery_toCrypt", "Common_CryptBig2", true);
			pchar.quest.NoiseCemetery_SeaExit.win_condition.l1 = "EnterToSea";
			pchar.quest.NoiseCemetery_SeaExit.function = "NoiseCemetery_SeaExit";
			pchar.questTemp.Lantern = "ToCrypt";
			pchar.questTemp.Lantern.nation = npchar.nation;
			AddQuestRecord("NoiseCemetery", "1");
			AddQuestUserData("NoiseCemetery", "sCity", XI_ConvertString(loadedlocation.islandId)); 
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		case "Lantern_10":
			dialog.text = "C'est vrai? Qu'y avait-il? Dis-moi!";
			link.l1 = "Il y avait l'esprit inquiet d'une femme ! Heureusement, j'ai eu le pretre local pour benir mon epee pour chatier les mecreants, alors tout s'est bien passe. Cet esprit ne vous derangera plus.";
			link.l1.go = "Lantern_11";
		break;
		
		case "Lantern_11":
			dialog.text = "Oh Seigneur, sauve nos âmes pécheresses ! Je vous avais prévenu ! Et vous ne m'avez pas cru !";
			link.l1 = "Oui, et je le regrette sincèrement. Mais maintenant tout va bien - j'ai aspergé cet endroit d'eau bénite, et aucun esprit n'osera se lever de la tombe. Vous pouvez dormir en paix.";
			link.l1.go = "Lantern_12";
		break;
		
		case "Lantern_12":
			dialog.text = "Merci beaucoup ! Tu n'as aucune idée de ce que cela signifie pour moi ! Tiens, s'il te plaît prends ça. Ce n'est pas grand-chose, mais je ne peux pas te laisser partir sans une récompense.";
			link.l1 = "Merci, je ne peux pas refuser. Bonne chance à toi !";
			link.l1.go = "Lantern_13";
		break;
		
		case "Lantern_13":
			pchar.quest.NoiseCemetery_SeaExit.over = "yes";
			AddMoneyToCharacter(PChar, 1000);
			pchar.questTemp.Lantern = "Done";
			AddQuestRecord("NoiseCemetery", "3");
			CloseQuestHeader("NoiseCemetery");
			NextDiag.TempNode = "First time";
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		case "Lantern_14":
			dialog.text = "Non? Alors que le diable... Je veux dire, qu'est-ce qui s'est passé au nom de Dieu là-bas?";
			link.l1 = "Il n'y avait pas du tout de fantôme. Un jeune couple a choisi cette crypte comme lieu pour leurs rendez-vous. Leurs parents sont contre cette union, alors ils cherchaient un endroit pour être seuls.";
			link.l1.go = "Lantern_15";
		break;
		
		case "Lantern_15":
			dialog.text = "Seul ?.. Pourquoi ces jeunes ! Qu'ils essaient seulement de revenir ici ! Je les chasserai tous les deux avec un fouet ou je les enfermerai dans le crypte pour qu'ils y restent !!!";
			link.l1 = "Ils ne reviendront plus ici. Je leur ai dit que leurs petites escapades ont vraiment effrayé la garde locale. Ils ont l'intention de le faire. Et d'ailleurs, la serrure de la porte est de toute façon cassée.";
			link.l1.go = "Lantern_16";
		break;
		
		case "Lantern_16":
			dialog.text = "Aucun problème, je le remplacerai. Mais si jamais je les attrape...";
			link.l1 = "Ne sois pas si en colère. Nous avons tous été de cet âge. Ils ne sont pas venus ici parce que c'est le meilleur endroit pour se rencontrer.";
			link.l1.go = "Lantern_17";
		break;
		
		case "Lantern_17":
			dialog.text = "C'est juste... Eh bien, que le Seigneur soit avec eux. Merci de ne pas avoir laissé un vieil homme en difficulté. Tenez, prenez ceci. Ce n'est pas grand-chose, mais je ne peux pas vous laisser partir sans récompense.";
			link.l1 = "Merci, je ne peux pas refuser. Bonne chance à toi !";
			link.l1.go = "Lantern_18";
		break;
		
		case "Lantern_18":
			DialogExit();
			pchar.quest.NoiseCemetery_SeaExit.over = "yes";
			AddMoneyToCharacter(PChar, 1000);
			pchar.questTemp.Lantern = "Done";
			AddQuestRecord("NoiseCemetery", "4");
			CloseQuestHeader("NoiseCemetery");
			NextDiag.TempNode = "First time";
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
		// <-- квест на получение фонаря 
	}
}
