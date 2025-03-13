// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Quelles questions avez-vous ?","Comment puis-je vous aider ?"),"Vous avez essayé de me poser cette question il n'y a pas longtemps...","Oui, laissez-moi deviner... Encore une fois, vous tournez en rond ?","Écoutez, je m'occupe des finances ici, je ne réponds pas aux questions...","bloc",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("J'ai changé d'avis...","Je n'ai rien à dire pour le moment."),"Oumph, où est passée ma mémoire...","Vous l'avez deviné, je suis désolé...","Je comprends...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			// Addon-2016 Jason ФМК-Гваделупа
			if (CheckAttribute(pchar, "questTemp.FMQG") && pchar.questTemp.FMQG == "continue")
            {
                link.l1 = "Je suis capitaine "+GetFullName(pchar)+". Votre homme m'a dit que vous vouliez me voir. Je suis tout ouïe.";
                link.l1.go = "FMQG";
            }
			if (CheckAttribute(pchar, "questTemp.FMQG") && pchar.questTemp.FMQG == "sucsess")
            {
                link.l1 = "Moi encore, monsieur "+GetFullName(pchar)+". Je vous ai amené Bertrand Pinette. Il est dans ma cale.";
                link.l1.go = "FMQG_14";
            }
			if (CheckAttribute(pchar, "questTemp.FMQG") && pchar.questTemp.FMQG == "letter")
            {
                link.l1 = "Moi encore, monsieur "+GetFullName(pchar)+"Discutons.";
                link.l1.go = "FMQG_17";
            }
			if (CheckAttribute(pchar, "questTemp.FMQG") && pchar.questTemp.FMQG == "killers")
            {
                link.l1 = "Moi encore, monsieur "+GetFullName(pchar)+"Allons discuter.";
                link.l1.go = "FMQG_17";
            }
			if (CheckAttribute(pchar, "questTemp.FMQG.Letter"))
            {
                link.l1 = "Moi encore, monsieur "+GetFullName(pchar)+"Je suppose que vous ne vous attendiez pas à me revoir.";
                link.l1.go = "FMQG_23";
            }
		break;
		
		// Addon-2016 Jason ФМК-Гваделупа
		case "FMQG":
			dialog.text = "A-ah, capitaine "+GetFullName(pchar)+"! Je suis si heureux de vous voir ! Je vous ai attendu pendant un bon moment... Bien. J'ai une question à vous poser. Il y a quelque temps, un homme nommé Bertrand Pinette vous a abordé au port pour monter à bord de votre navire. Un gars d'apparence riche avec une perruque de luxe. Cela vous dit quelque chose ?";
			link.l1 = "Oui, en effet. Il m'a vraiment approché dans ce but précis.";
			link.l1.go = "FMQG_1";
		break;
		
		case "FMQG_1":
			DelLandQuestMark(npchar);
			Log_Info("You have received a heavy purse");
			PlaySound("interface\important_item.wav");
			GiveItem2Character(pchar, "purse3");
			dialog.text = "A-t-il voulu vous engager, vous et votre navire ? Capitaine, vous me rendriez un grand service en me racontant tous les détails de cette affaire. Je vous récompenserai. Tenez, prenez cette bourse remplie de pièces. Elle est à vous, maintenant parlez-moi de Bertrand Pinette.";
			link.l1 = "Très bien. Monsieur Pinette a engagé mon navire pour le transporter, lui et deux de ses amis, de la Guadeloupe au continent espagnol. Plus précisément, à la baie des Moustiques de Portobello. J'ai fait le travail, ils ont quitté mon navire et se sont dirigés droit dans la jungle.";
			link.l1.go = "FMQG_2";
		break;
		
		case "FMQG_2":
			dialog.text = "Je vois. Et monsieur Pinette a-t-il mentionné sa destination finale? Et qu'en est-il de ses compagnons?";
			link.l1 = "Selon ses propres dires, ils se dirigeaient vers Panama. Ses amis étaient assez intrigants : deux officiers, un Espagnol et un Français. Je ne peux toujours pas comprendre ce qui les unissait, mais je n'étais pas payé pour poser des questions.";
			link.l1.go = "FMQG_3";
		break;
		
		case "FMQG_3":
			dialog.text = "Un officier espagnol ? Et un officier français ? Oh ! N'est-ce pas quelque chose ! Bravo, monsieur Pinette ! Quel renard rusé ! Même ici, il a trouvé un moyen de gagner de l'argent ! Panama, vous avez dit ?";
			link.l1 = "Oui, et je vous ai dit tout ce que je savais. Puis-je prendre congé?";
			link.l1.go = "FMQG_4";
		break;
		
		case "FMQG_4":
			dialog.text = "Attendez, capitaine. J'ai une proposition d'affaires pour vous. Cela ne vous dérange-t-il pas de gagner quelques pièces? Mais d'abord, laissez-moi vous dire quelque chose à propos de vos passagers.";
			link.l1 = "Eh bien, écoutons cela.";
			link.l1.go = "FMQG_5";
		break;
		
		case "FMQG_5":
			dialog.text = "Monsieur Bertrand Pinette est apparu dans notre colonie il y a deux ans et a immédiatement commencé à faire des affaires avec les capitaines. Les affaires sont, eh bien, sombres aussi... Ils lui livraient des marchandises en grande pénurie ici, des objets de valeur, de la contrebande, voire des esclaves parfois... Il prenait systématiquement des prêts pour ses opérations illégales dans mon bureau, mais remboursait toujours avec tous les intérêts.\nAvant de quitter l'île avec votre précieuse aide, il avait contracté un grand prêt, bien plus important que d'habitude. Il est... était un client de confiance avec un historique de crédit impeccable, c'est pourquoi je lui avais accordé un prêt. Grosse erreur. Monsieur Pinette s'est enfui et évidemment il ne compte pas me rendre mes pièces.";
			link.l1 = "Quelle est l'ampleur de la somme, si je puis demander?";
			link.l1.go = "FMQG_6";
		break;
		
		case "FMQG_6":
			dialog.text = "C'est énorme. Environ cent cinquante mille pesos en doublons. Dix coffres, chacun avec cent cinquante doublons. Et sans parler de tous les intérêts.";
			link.l1 = "Hm... Il vous payait depuis deux ans, vous a habitué à cela, a contracté un prêt substantiel, puis s'est enfui. Malin.";
			link.l1.go = "FMQG_7";
		break;
		
		case "FMQG_7":
			dialog.text = "Précisément, capitaine. C'est pourquoi je voudrais vous engager pour un travail : trouvez ce vaurien et amenez-le ici. Moi, le gouverneur et le commandant trouverons un moyen de l'obliger à effacer sa dette. Vous avez vu cet homme, il était votre passager, cela signifie que vous avez plus de chances de trouver monsieur Pinette que quiconque. Bien sûr, je vais aussi engager des chasseurs de primes professionnels pour son pauvre derrière, mais j'ai le sentiment que votre aide s'avérera plus efficace.";
			link.l1 = "Que diriez-vous d'une récompense ?";
			link.l1.go = "FMQG_8";
		break;
		
		case "FMQG_8":
			dialog.text = "Pour accomplir le travail, je vous donnerai un coffre plein de doublons, cent cinquante pièces.";
			link.l1 = "Je dis que ce serait une récompense bien pathétique pour traquer et kidnapper une âme vivante dans la ville espagnole.";
			link.l1.go = "FMQG_9";
		break;
		
		case "FMQG_9":
			dialog.text = "Capitaine, je suppose que monsieur Pinette vous a bien payé avec mon argent puisque vous évaluez ma proposition si bon marché. Je vous assure que cela vaut l'effort. Bien sûr, vous avez tout à fait le droit de refuser... mais j'ai quelque chose à vous dire et cela vous fera sûrement changer d'avis.";
			link.l1 = "Et qu'est-ce que c'est?";
			link.l1.go = "FMQG_10";
		break;
		
		case "FMQG_10":
			dialog.text = "Quelques jours avant l'évasion de Pinette de la Guadeloupe, un prisonnier s'était échappé de la prison de Basse-Terre. Son nom est don Carlos de Milyar, un grand d'Espagne et un officier. Il y est parvenu grâce à la trahison d'un officier français, un lieutenant des Marines... Comprenez-vous ce que je veux dire ?";
			link.l1 = "Hm... Et en quoi cela me concerne-t-il ? Je faisais un transport de passagers, rien de plus.";
			link.l1.go = "FMQG_11";
		break;
		
		case "FMQG_11":
			dialog.text = "Bien sûr, vous l'étiez ! Personnellement, je ne doute pas que vous n'ayez rien à voir avec l'organisation de l'évasion de don de Milyar. Mais ce n'est pas ce que notre gouverneur et notre commandant pourraient penser. Une accusation de complicité si vous avez de la chance, et si vous ne l'êtes pas... Je ne veux vraiment pas continuer. Voyez par vous-même, vous avez pris à bord un officier espagnol en fuite, probablement dans quelque crique cachée... ai-je raison, capitaine ?";
			link.l1 = "Je comprends. Tu me fais chanter. J'ai fait une erreur en venant ici...";
			link.l1.go = "FMQG_12";
		break;
		
		case "FMQG_12":
			dialog.text = "Que dites-vous, capitaine ?! Je ne vous fais pas chanter ! Tout ce que je demande, c'est de m'aider pour une bonne récompense. Auriez-vous l'amabilité de trouver monsieur Pinette et de le livrer à Basse-Terre ? Je vous attendrai à votre retour. Je crois que deux mois suffisent pour naviguer jusqu'à Panama et revenir.";
			link.l1 = "Vous ne me laissez pas le choix. Bien que je doute qu'une telle approche commerciale nous aide à devenir amis. Adieu, monsieur.";
			link.l1.go = "FMQG_13";
		break;
		
		case "FMQG_13":
			DialogExit();
			LocatorReloadEnterDisable("Baster_town", "reload1_back", false);
			LocatorReloadEnterDisable("Baster_town", "reload2_back", false);
			LocatorReloadEnterDisable("Baster_town", "gate_back", false);//открыть выходы из города
			pchar.questTemp.FMQG = "headhunter_panama";
			ReOpenQuestHeader("FMQ_Guadeloupe");
			AddQuestRecord("FMQ_Guadeloupe", "7");
			if(bImCasual)
			{
				NewGameTip("Exploration mode: quest duration doubled");
				SetFunctionTimerCondition("FMQG_UsurerTimeOut", 0, 0, 122, false);
			}
			else SetFunctionTimerCondition("FMQG_UsurerTimeOut", 0, 0, 61, false);
			AddMapQuestMarkCity("panama", false);
			AddLandQuestMark(characterFromId("Panama_tavernkeeper"), "questmarkmain");
			
			// Sinistra - Старт квеста "Мерзкий Божок"
			PChar.quest.ChickenGod_StartLoc.win_condition.l1 = "ExitFromLocation";
			PChar.quest.ChickenGod_StartLoc.win_condition.l1.location = PChar.location;
			PChar.quest.ChickenGod_StartLoc.function = "ChickenGod_BrothelCheck";
		break;
		
		case "FMQG_14":
			DelMapQuestMarkCity("baster");
			DelLandQuestMark(npchar);
			dialog.text = "Excellente nouvelle, capitaine ! J'enverrai mes hommes récupérer ce salaud de votre navire sur-le-champ. Ce petit oiseau ne va pas s'envoler loin de moi cette fois... Vous avez mérité votre récompense, prenez ce coffre. S'il vous plaît, ne m'en veuillez pas, voici un amulette pour vous. C'est un cadeau.";
			link.l1 = "Gratitude. Je suppose que votre silence fait également partie de ma récompense ?";
			link.l1.go = "FMQG_15";
		break;
		
		case "FMQG_15":
			Log_Info("You have received a chest full of doubloons");
			Log_Info("You have received a 'Fisherman' amulet");
			PlaySound("interface\important_item.wav");
			GiveItem2Character(pchar, "chest");
			GiveItem2Character(pchar, "obereg_7");
			dialog.text = "Silence ? A propos de quoi ? Je serais ravi de vous compter parmi mes clients. Vous savez ce qu'on dit du silence et de l'or ?";
			link.l1 = "Parfois, cela vaut bien plus que de l'or, monsieur. Leçon apprise. Adieu!";
			link.l1.go = "FMQG_16";
		break;
		
		case "FMQG_16":
			DialogExit();
			pchar.quest.FMQG_UsurerTimeOut.over = "yes";
			ref sld = characterFromId("FMQG_pass_1");
			RemovePassenger(pchar, sld);
			sld.lifeday = 0;
			pchar.questTemp.FMQG = "end";
			FMQ_Count();
			AddQuestRecord("FMQ_Guadeloupe", "23");
			CloseQuestHeader("FMQ_Guadeloupe");
			ChangeCharacterNationReputation(pchar, FRANCE, 5);
			ChangeCharacterComplexReputation(pchar, "nobility", 5);
			ChangeCharacterComplexReputation(pchar, "authority", 3);
			AddCharacterExpToSkill(pchar, "Leadership", 400);
			AddCharacterExpToSkill(pchar, "Sailing", 200);
		break;
		
		case "FMQG_17":
			DelLandQuestMark(npchar);
			DelMapQuestMarkCity("baster");
			dialog.text = "Je vous écoute. Bertrand Pinette est à bord de votre navire, je suppose ?";
			link.l1 = "Non. Mais j'ai quelque chose de bien meilleur pour vous. Lisez ceci.";
			link.l1.go = "FMQG_18";
		break;
		
		case "FMQG_18":
			RemoveItems(pchar, "letter_baker", 1);
			dialog.text = "Qu'est-ce que c'est ?";
			link.l1 = "Continuez à lire, monsieur. Nous poursuivrons plus tard.";
			link.l1.go = "FMQG_19";
		break;
		
		case "FMQG_19":
			LAi_Fade("", "");
			dialog.text = "(en train de lire) Hum... Quelle est cette absurdité d'un patient fébrile ?";
			link.l1 = "Êtes-vous sérieux ? Très bien, je vais porter ce 'non-sens' au gouverneur. Je crois qu'il sera très intéressé à découvrir la vérité sur la disparition du 'Courage' et sa cargaison de diamants... Pourquoi êtes-vous devenu si pâle ?";
			if (CheckAttribute(pchar, "questTemp.FMQG.Letter")) link.l1.go = "FMQG_24";
			else link.l1.go = "FMQG_20";
		break;
		
		case "FMQG_20":
			dialog.text = "Alors, vous avez finalement trouvé Pinette...";
			link.l1 = "Oui. Alors je vous propose un marché. Oubliez Carlos de Milyar, Jean Deno et autres bons messieurs, faites cela et j'oublierai cette lettre.";
			link.l1.go = "FMQG_21";
		break;
		
		case "FMQG_21":
			dialog.text = "Très bien, capitaine... J'accepte vos conditions.";
			link.l1 = "Charmant. J'espère que vous n'êtes pas en colère contre moi, nous avons terminé maintenant, je crois. Adieu.";
			link.l1.go = "FMQG_22";
		break;
		
		case "FMQG_22":
			DialogExit();
			pchar.quest.FMQG_UsurerTimeOut.over = "yes";
			pchar.questTemp.FMQG = "cave";
			bQuestDisableMapEnter = true;//закрыть карту
			pchar.GenQuest.MapClosedNoBattle = true;
			pchar.quest.FMQG_cave.win_condition.l1 = "location";
			pchar.quest.FMQG_cave.win_condition.l1.location = "Guadeloupe_Cave";
			pchar.quest.FMQG_cave.function = "FMQG_InCave";
			// заполним сундук
			pchar.GenQuestBox.Guadeloupe_Cave = true;
			pchar.GenQuestBox.Guadeloupe_Cave.box3.items.purse1 = 5;
			pchar.GenQuestBox.Guadeloupe_Cave.box3.items.purse2 = 2;
			pchar.GenQuestBox.Guadeloupe_Cave.box3.items.purse3 = 1;
			SetFunctionTimerCondition("FMQG_ClearBox", 0, 0, 3, false);
			if (CheckAttribute(pchar, "questTemp.FMQG.Letter"))
			{
				SetFunctionTimerCondition("FMQG_RemoveHunterScore", 0, 0, 1, false);
				AddQuestRecord("FMQ_Guadeloupe", "29");
				DeleteAttribute(pchar, "questTemp.FMQG.Letter");
			}
			else AddQuestRecord("FMQ_Guadeloupe", "25");
		break;
		
		case "FMQG_23":
			dialog.text = "Ha... Vous avez raison, capitaine.";
			link.l1 = "J'ai quelque chose pour vous. Prenez ceci et lisez.";
			link.l1.go = "FMQG_18";
		break;
		
		case "FMQG_24":
			dialog.text = "Alors, vous avez finalement trouvé Pinette...";
			link.l1 = "Oui. Donc je vous propose un marché. Rétablissez ma bonne réputation dans les colonies françaises et j'oublierai cette lettre.";
			link.l1.go = "FMQG_25";
		break;
		
		case "FMQG_25":
			dialog.text = "Mais...";
			link.l1 = "Je me fiche de comment tu vas le faire. Si la chasse à ma tête ne s'arrête pas demain, le gouverneur saura tout.";
			link.l1.go = "FMQG_21";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
