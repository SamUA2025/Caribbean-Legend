// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    ref sld;   
	switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Quelle sorte de questions, "+GetSexPhrase("jeune homme","jeune dame")+"?","Que désirez-vous, "+GetSexPhrase("beau","belle demoiselle")+"Demandez donc."),"Encore des questions","Tee-hee, si cela ne vous dérange pas - des questions...",""+GetSexPhrase("Hm, pourquoi ne pas choisir une beauté pour toi-même? Je commence à avoir des soupçons à ton sujet...","Hm, pourquoi ne choisis-tu pas une beauté pour toi-même ? Nous n'avons pas de garçons ici, je le crains, hi-hi...")+"","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("J'ai changé d'avis, excusez-moi.","En fait, laisse tomber."),"Je... pardon, je n'ai pas de questions, pour l'instant.","Tu as raison, c'est déjà la troisième fois. Pardonne-moi.","Peut-être la prochaine fois, Madame.",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			/* //--> Бремя гасконца
			if (CheckAttribute(pchar, "questTemp.Sharlie.Gigolo") && pchar.questTemp.Sharlie.Gigolo == "start")
			{
				DelLandQuestMark(npchar);
				link.l1 = "Ecoute, Aurora, j'ai besoin d'une fille pour la nuit. Et je veux l'emmener chez moi. Peux-tu arranger cela ?";
                link.l1.go = "Gigolo";
			}	
			//<-- Бремя гасконца */
		break;
		
		//--> Бремя гасконца
		case "Gigolo":
			dialog.text = "Bien sûr, cher. As-tu déjà trouvé une demoiselle convenable ou devrais-je le faire?";
			link.l1 = "En effet, je l'ai fait. J'ai des vues sur une fille nommée Lucille.";
			link.l1.go = "Gigolo_1";
		break;
		
		case "Gigolo_1":
			dialog.text = "Parlez-vous de Lucille Montaigne ?";
			link.l1 = "Pour dire la vérité, je ne lui ai pas demandé son nom de famille. Tout ce que je sais, c'est que c'est une jeune fille belle et aux cheveux blonds qui s'appelle Lucille.";
			link.l1.go = "Gigolo_2";
		break;
		
		case "Gigolo_2":
			dialog.text = "Oui, cela la décrit très bien. D'accord. Mais dis-moi, pourquoi elle ? Les autres filles ne te plaisent-elles pas ?";
			link.l1 = "Eh bien, voyez-vous... elle vient de commencer à travailler ici, donc je crois qu'elle n'est pas encore suffisamment expérimentée dans le 'Métier' pour être trop lourde pour ma bourse.";
			link.l1.go = "Gigolo_2_1";
			link.l2 = "Vous voyez, j'adore les blondes à la peau claire. Lucille fera parfaitement l'affaire à cet égard.";
			link.l2.go = "Gigolo_2_2";
		break;
		
		case "Gigolo_2_1":
			if (sti(pchar.questTemp.Sharlie.Gigolo.Rand1) == 0)
			{
				pchar.questTemp.Sharlie.Gigolo.Money = 5000;
				dialog.text = "Maintenant Monsieur, ce n'est pas vrai ! elle est jeune, jolie et expérimentée, mes clients ne font que l'admirer. elle te coûtera cher. Cinq mille pesos pour une nuit avec elle, pas un seul peso de moins.";
				if (sti(pchar.money) >= 5000)
				{
					link.l1 = "Cher, mais très bien. Prenez votre pièce.";
					link.l1.go = "Gigolo_3";
				}
				else
				{
					link.l1 = "  C'est cher ! Je n'ai pas autant. Je te parlerai plus tard.";
					link.l1.go = "exit";
				}
			}
			else
			{
				pchar.questTemp.Sharlie.Gigolo.Money = 2500;
				dialog.text = "Soupir, vous avez raison, Monsieur, elle est jolie et jeune mais manque d'expérience. Mes clients ne la remarquent généralement pas, c'est pourquoi j'ai demandé. Mais si vous aimez vraiment les filles modestes, je dis qu'elle est un bon choix. Elle vous coûtera deux mille cinq cents pesos.";
				if (sti(pchar.money) >= 2500)
				{
					link.l1 = "Hélas, elle fera l'affaire. Voici votre pièce.";
					link.l1.go = "Gigolo_3";
				}
				else
				{
					link.l1 = "C'est cher ! Je n'ai pas autant. Je te reparlerai plus tard.";
					link.l1.go = "exit";
				}
			}
		break;
		
		case "Gigolo_2_2":
			if (sti(pchar.questTemp.Sharlie.Gigolo.Rand2) == 0)
			{
				pchar.questTemp.Sharlie.Gigolo.Money = 4500;
				dialog.text = "Tu ne serais pas le premier, beau gosse. Parfois, mes clients font la queue pour attirer son attention, car elle se distingue des filles à la peau sombre de nos îles. Elle te coûtera quatre mille cinq cents pesos.";
				if (sti(pchar.money) >= 4500)
				{
					link.l1 = "Chère, mais très bien. Voici ta pièce.";
					link.l1.go = "Gigolo_3";
				}
				else
				{
					link.l1 = "C'est cher ! Je n'ai pas autant. Je te parlerai plus tard.";
					link.l1.go = "exit";
				}
			}
			else
			{
				pchar.questTemp.Sharlie.Gigolo.Money = 3000;
				dialog.text = "Vraiment, Monsieur ? Nostalgique déjà ? Mes créoles et surtout mes mulâtres sont plus passionnées que cette chatte de ruelle parisienne détendue. Mais hélas, c'est votre choix. Elle vous coûtera trois mille pesos.";
				if (sti(pchar.money) >= 3000)
				{
					link.l1 = "Chère, mais très bien. Voici ta pièce.";
					link.l1.go = "Gigolo_3";
				}
				else
				{
					link.l1 = "C'est cher ! Je n'ai pas autant. Je te parlerai plus tard.";
					link.l1.go = "exit";
				}
			}
		break;
		
		case "Gigolo_3":
			AddMoneyToCharacter(pchar, -sti(pchar.questTemp.Sharlie.Gigolo.Money));
			dialog.text = "Comme tu veux, cher. Lucille t'attendra impatiemment à onze heures du soir. De plus, elle ne doit pas revenir plus tard que sept heures du matin. Si tu n'arrives pas avant minuit, elle s'occupera d'un autre client, et alors tu devras attendre la prochaine soirée pour la prendre.\nEt ne pense même pas à... lui faire du mal de quelque manière que ce soit, sous peine de le regretter. Un avertissement juste, cher.";
			link.l1 = "Ne vous inquiétez pas, je la traiterai comme une amante, pas comme un rustre. Je la prendrai à onze heures. Que devrais-je faire d'ici là ?";
			link.l1.go = "Gigolo_4a";
		break;
		
		case "Gigolo_4a":
			dialog.text = "Eh bien, je ne sais même pas, cher. Passez à la taverne, discutez avec le barman...";
			link.l1 = "Pas une mauvaise idée. Je ferai juste cela. Passez une bonne journée !";
			link.l1.go = "Gigolo_4";
		break;
		
		case "Gigolo_4":
			//DeleteAttribute(pchar, "GenQuest.CannotWait");
			DialogExit();
			AddQuestRecord("SharlieC", "2");
			pchar.questTemp.Sharlie.Gigolo = "girl";
			Sharlie_CreateGigoloGirl();
			QuestPointerDelLoc("fortfrance_town", "reload", "reload9_back");
			QuestPointerDelLoc("fortfrance_brothel", "reload", "reload3");
			QuestPointerToLoc("fortfrance_town", "reload", "reload4_back");
			SetCurrentTime(17, 30);
			//NewGameTip("Доступна функция перемотки времени! Она доступна через опцию 'мысли вслух' в меню действий (ENTER).");
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
