// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Quelles questions avez-vous ?","Comment puis-je vous aider, "+GetAddress_Form(NPChar)+"?"),"Tu as essayé de me poser une question il n'y a pas longtemps, "+GetAddress_Form(NPChar)+"...","Tout au long de cette journée, c'est la troisième fois que tu parles d'une certaine question...","Encore des questions, je présume ?","bloc",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("J'ai changé d'avis...","Je n'ai rien à dire pour le moment."),"Oumph, ou est passe ma memoire...","Oui, c'est vraiment la troisième fois...","Non, quelles questions ?...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			if (CheckAttribute(PChar, "questTemp.Guardoftruth.Archy") && pchar.questTemp.Guardoftruth.Archy == "islatesorotavern")
			{
				link.l1 = "Ecoute, "+npchar.name+", avez-vous entendu parler d'un homme nommé Miguel Dichoso ? On dit que son navire a été aperçu dans les eaux de l'Isla Tesoro...";
				link.l1.go = "guardoftruth";
			}
			if(CheckAttribute(pchar, "questTemp.Tieyasal") && pchar.questTemp.Tieyasal == "begin" && !CheckAttribute(npchar, "quest.Tieyasal"))
			{
				link.l1 = "Ecoute, "+npchar.name+", n'avez-vous pas vu Miguel Dichoso récemment sur Isla Tesoro ?";
				link.l1.go = "tieyasal";
			}
		break;
		
		case "guardoftruth":
			dialog.text = "Oui, je l'ai fait. Ce don espagnol a vendu à Shark Dodson un navire remarquable, une frégate, quand il résidait encore ici. Ah ce navire... Elle était incroyable...";
			link.l1 = "Laissez-moi deviner : elle avait une coque moderne et élancée et pouvait atteindre seize nœuds ? Et son nom était 'Santa Quitaria' ?";
			link.l1.go = "guardoftruth_1";
		break;
		
		case "guardoftruth_1":
			dialog.text = "Quant à la charpente et à la vitesse, vous avez parfaitement raison, mais elle portait un autre nom : 'San Martin'. Shark a payé un tas d'or à ce gredin pour ce navire.";
			link.l1 = "Es-tu sûr que c'était 'San Martin' et non 'Santa Quiteria'? Quand l'a-t-il acheté? Et pourquoi as-tu traité Dichoso de vaurien?";
			link.l1.go = "guardoftruth_2";
		break;
		
		case "guardoftruth_2":
			dialog.text = "Que le diable m'emporte, je suis absolument sûr que c'était le 'San Martin', car j'ai personnellement vu les ouvriers d'Alexus arracher une plaque avec ces balivernes papistes de la poupe. Shark Dodson l'a nommée 'Fortune', un nom bien plus approprié pour une telle beauté. (crache) Il l'avait achetée en hiver '54, peu de temps avant que Blaze ne soit assassiné.\nPourquoi ai-je traité Don Miguel de fripouille ? Parce qu'il a volé ce satané navire de la marine espagnole hors de Providence ! Dodson a monté un spectacle avec feu et fumée pour le fort de St. Juan et sa garnison, comme il me le disait toujours quand il était ivre. Shark a sacrifié deux lougres endommagés pour rendre le combat avec la frégate plus réaliste.\nQuand la nuit est venue, il a secrètement navigué le 'San Martin' vers l'Isla Tesoro. Shark a pris le bateau et Dichoso a eu l'argent. Ce sacré filou a ensuite raconté à ses supérieurs que la frégate avait coulé lors du combat avec la flotte pirate, le commandant du fort de St. Juan l'a confirmé.";
			link.l1 = "Oh, comment ces dons espagnols se remplissent les poches ! Quel filou ! Dis-moi, es-tu sûr que cela s'est passé en hiver 1654 ? Cela ne pourrait-il pas avoir eu lieu au printemps ? Et ce frégate ne montrait-elle pas des signes d'usure après la tempête ?";
			link.l1.go = "guardoftruth_3";
		break;
		
		case "guardoftruth_3":
			dialog.text = "Je suis presque sûr que c'était l'hiver... Oh, qui sait. Peut-être que c'était le printemps. Je ne m'en souviens pas avec certitude. J'étais probablement ivre. La frégate n'était pas du tout usée, elle était flambant neuve.";
			link.l1 = "Et où se trouve maintenant cette beauté de frégate ?";
			link.l1.go = "guardoftruth_4";
		break;
		
		case "guardoftruth_4":
			dialog.text = "Une sombre histoire, c'est... Quand Blaze a été assassiné, tout le monde a soupçonné Shark parce que son collier, une dent de requin, a été trouvé sur le cadavre. De plus, certaines personnes ont vu Shark dans la résidence de Blaze cette nuit-là\nShark a échappé à Isla Tesoro avant qu'ils ne lui donnent la marque noire. Il a rendu visite au Pasteur Sombre et a échangé sa frégate contre un brick. Aucune idée d'où se trouve cet homme maintenant. Zachary a vendu la frégate à William Paterson plus tard.";
			link.l1 = "Qui est ce Paterson ?";
			link.l1.go = "guardoftruth_5";
		break;
		
		case "guardoftruth_5":
			dialog.text = "Quoi, tu n'as jamais entendu parler de Willie Paterson ? C'est un Écossais, tout juste arrivé aux Caraïbes. Il se prend pour le capitaine de la flotte royale, le favori du Colonel Fox lui-même ! Au fait, il vient de commencer à magouiller des affaires avec Jackman aussi. Le navire amiral de Paterson est 'Fortune' elle-même.";
			link.l1 = "Je vois. Savez-vous où se trouve Dichoso en ce moment ?";
			link.l1.go = "guardoftruth_6";
		break;
		
		case "guardoftruth_6":
			dialog.text = "Je n'ai aucune idée. Après cette magouille avec la 'Fortune', je ne l'ai plus vu sur Isla Tesoro depuis et je n'ai rien entendu à son sujet.";
			link.l1 = "D'accord, "+npchar.name+", merci pour ces informations détaillées ! Vous êtes un excellent tavernier ! J'aimerais qu'il y ait plus de gens comme vous... Adieu !";
			link.l1.go = "guardoftruth_7";
		break;
		
		case "guardoftruth_7":
			dialog.text = "Bonne chance, "+pchar.name+"!";
			link.l1 = "...";
			link.l1.go = "guardoftruth_8";
		break;
		
		case "guardoftruth_8":
			DialogExit();
			AddQuestRecord("Guardoftruth", "60_1");
			pchar.questTemp.Guardoftruth.Archy = "guadeloupe";
			// маленькая развлекуха
			pchar.quest.GuardOT_cabinattack.win_condition.l1 = "EnterToSea";
			pchar.quest.GuardOT_cabinattack.function = "GuardOT_PrepareCreateBandosInCabin";
		break;
		
		case "tieyasal":
			dialog.text = "On dirait que vous vous pourchassez mutuellement, camarade. Oui, Dichoso était ici juste là où vous vous tenez. Et exactement de la même manière il s'interrogeait sur vous la dernière fois que vous étiez à Sharptown.";
			link.l1 = "Sacrebleu! C'est la nouvelle... Et où est Miguel en ce moment?";
			link.l1.go = "tieyasal_1";
		break;
		
		case "tieyasal_1":
			dialog.text = "Je n'en ai aucune idée. Il est parti en mer où... il a dit quelque chose à propos de Blueweld. Il y est probablement allé juste pour te chercher.";
			link.l1 = "Serait-ce vous qui l'avez envoyé à Blueweld ?";
			link.l1.go = "tieyasal_2";
		break;
		
		case "tieyasal_2":
			dialog.text = "Non. Tout ce que je lui ai dit, c'est que je ne t'avais pas vu depuis longtemps.";
			link.l1 = "Je vois. Très bien, alors. Merci, l'ami !";
			link.l1.go = "tieyasal_3";
		break;
		
		case "tieyasal_3":
			DialogExit();
			AddQuestRecord("Tieyasal", "3");
			npchar.quest.tieyasal = "true";
			pchar.quest.Tieyasal_ITAttack.win_condition.l1 = "location";
			pchar.quest.Tieyasal_ITAttack.win_condition.l1.location = "Bermudes";
			pchar.quest.Tieyasal_ITAttack.function = "Tieyasal_CreateITShips";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
