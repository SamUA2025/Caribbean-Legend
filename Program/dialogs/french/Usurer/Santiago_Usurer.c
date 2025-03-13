// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Quelles questions avez-vous ?","Comment puis-je vous aider?"),"Vous avez essayé de me poser cette question il n'y a pas longtemps...","Oui, laissez-moi deviner... Encore en train de tourner en rond ?","Ecoutez, je m'occupe des finances ici, je ne reponds pas aux questions...","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("J'ai changé d'avis...","Je n'ai rien à dire pour le moment."),"Oumph, oú est passée ma mémoire...","Vous l'avez deviné, je suis désolé...","Je comprends...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			//Голландский гамбит, Голландия
			if (CheckAttribute(pchar, "questTemp.HWIC.Holl") && pchar.questTemp.HWIC.Holl == "SantiagoTripBegin")
			{
				link.l1 = "Sénior, je suis capitaine "+GetFullName(pchar)+", et je suis ici pour une course pour Lucas Rodenburg. J'ai un paquet de sa part pour vous.";
				link.l1.go = "SantiagoTripBank";	
			}
			if (CheckAttribute(pchar, "questTemp.HWIC.Holl") && pchar.questTemp.HWIC.Holl == "SantiagoTripReturn")
			{
				link.l1 = "Je suis venu pour la réponse de monsieur Lucas Rodenburg.";
				link.l1.go = "SantiagoTripBank_3";	
			}
			//Голландский гамбит, Голландия
		break;
		
		case "SantiagoTripBank":
			if (GetCharacterItem(pchar, "Chest") >= 5)
			{
			dialog.text = "Imaginez... un paquet ! Eh bien, donnez-le, señor.";
			link.l1 = "Aussi, Senior Rodenburg a demandé de vous transmettre ceci...";
			link.l1.go = "SantiagoTripBank_1";
			RemoveItems(PChar, "NPC_Letter", 1);
			RemoveItems(PChar, "Chest", 5);
			DelLandQuestMark(npchar);
			}
			else
			{
			dialog.text = "Autant que je sache, il y avait autre chose que je devais recevoir en plus du paquet, capitaine. Alors... où est-ce? Comprenez-vous de quoi je parle?";
			link.l1 = "Mais bien sûr ! Les coffres sont sous surveillance sécurisée sur mon navire. Je vous les livrerai immédiatement.";
			link.l1.go = "exit";
			}
		break;
		
		case "SantiagoTripBank_1":
			dialog.text = "Hm-m... intéressant. Ainsi, il 'présente ses regrets'. Eh bien, eh bien. Bien que les regrets de senior Rodenburg soient assez persuasifs, il est difficile de les nier. Senior, cela prendra un certain temps pour rédiger une réponse appropriée, pourriez-vous revenir me voir demain vers midi pour prendre une réponse ? Reposez-vous dans une taverne, promenez-vous en ville. Santiago a beaucoup à offrir.";
			link.l1 = "Très bien, je reviendrai demain vers midi. Je vous verrai alors, señor.";
			link.l1.go = "SantiagoTripBank_2";
		break;
		
		case "SantiagoTripBank_2":
			DialogExit();
			pchar.quest.SantiagoTripOver.over = "yes"; //снять таймер
			bDisableFastReload = true;
			pchar.quest.Santiago_Trip.win_condition.l1 = "location";
			pchar.quest.Santiago_Trip.win_condition.l1.location = "Santiago_town";
			pchar.quest.Santiago_Trip.function = "SantiagoTrip_Attack";
			pchar.questTemp.HWIC.Holl = "SantiagoTripAttack";
			LAi_LocationDisableOfficersGen("Santiago_town", true);//офицеров не пускать // 291112
		break;
		
		case "SantiagoTripBank_3":
			dialog.text = "Oui, bien sûr... mais je crois que nous pouvons nous passer des conventions écrites. Dites-lui simplement ces mots 'cet homme doit mourir'. Ce serait juste et nous n'aurons aucun problème à considérer la 'valeur' des excuses reçues. Et l'incident sera considéré comme entièrement réglé.";
			link.l1 = "Très bien, je m'en souviendrai, señor. Autre chose ?";
			link.l1.go = "SantiagoTripBank_4";
			DelLandQuestMark(npchar);
		break;
		
		case "SantiagoTripBank_4":
			dialog.text = "Oui, bien sûr. Ce que j'ai dit est la volonté de la famille Giraldi. Et vous pouvez, bien entendu, transmettre mes meilleurs vœux à Señor Lucas. Je vous souhaite bon vent, capitaine "+GetFullName(pchar)+".";
			link.l1 = "Je comprends. Adieu, cher monsieur "+npchar.name+".";
			link.l1.go = "SantiagoTripBank_5";
		break;
		
		case "SantiagoTripBank_5":
			DialogExit();
			pchar.questTemp.HWIC.Holl = "SantiagoTripFinal";
			LAi_LocationDisableOfficersGen("Santiago_town", false);//офицеров пускать // 291112
			AddLandQuestMark(characterFromId("Lucas"), "questmarkmain");
			AddMapQuestMarkCity("Villemstad", true);
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
