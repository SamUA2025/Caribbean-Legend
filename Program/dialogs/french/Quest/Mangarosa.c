// диалоги персонажей по квесту Мангароса
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
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
			dialog.text = "Que veux-tu ?";
			link.l1 = "Rien.";
			link.l1.go = "exit";
		break;
		
		// Амелия - знахарка-цыганка
		case "amelia":
			dialog.text = "Que veux-tu dans ma maison ?";
			if (CheckAttribute(pchar, "questTemp.Mangarosa") && pchar.questTemp.Mangarosa == "amelia")
			{
				link.l1 = "Ton nom est Amelia, n'est-ce pas? Je suis venu te demander à propos d'une plante. Manga Rosa.";
				link.l1.go = "amelia_1";
			}
			else
			{
				link.l1 = "Je n'ai rien à te dire pour l'instant. Mais je reviendrai un jour...";
				link.l1.go = "exit";
			}
			NextDiag.TempNode = "amelia";
		break;
		
		case "amelia_1":
			dialog.text = "Intéressant ! Et qui t'a parlé de moi, jeune homme courageux ?";
			link.l1 = "Une de vos gens. Elle a dit que vous connaissez les secrets de cette plante et que vous pouvez m'apprendre à faire des potions spéciales avec elle...";
			link.l1.go = "amelia_2";
		break;
		
		case "amelia_2":
			dialog.text = "Tout d'abord, montre-moi la plante dont tu parles. Peut-être que tu n'en sais rien et que tu ne fais que perdre mon temps. Où est ta Manga Rosa ?";
			if (CheckCharacterItem(pchar, "cannabis7"))
			{
				link.l1 = "Tiens, jette un oeil.";
				link.l1.go = "amelia_3";
			}
			else
			{
				link.l1 = "Hm...";
				link.l1.go = "amelia_exit";
			}
		break;
		
		case "amelia_exit":
			dialog.text = "Et qu'allais-tu me montrer? Tu n'as pas de Manga Rosa. Alors dégage, mon gars, avant que je ne me fâche. Cette conversation est terminée.";
			link.l1 = "Mais...";
			link.l1.go = "exit";
			NextDiag.TempNode = "amelia_wait";
		break;
		
		case "amelia_wait":
			dialog.text = "Toi encore ? Ne cherche pas d'ennuis, garçon...";
			if (CheckCharacterItem(pchar, "cannabis7"))
			{
				link.l1 = "Calme-toi, Amelia. Je l'ai laissé tomber quelque part la dernière fois. Tiens, je t'ai apporté la Manga Rosa. Jette un œil.";
				link.l1.go = "amelia_3";
			}
			else
			{
				link.l1 = "... ";
				link.l1.go = "amelia_exit";
			}
			NextDiag.TempNode = "amelia_wait";
		break;
		
		case "amelia_3":
			dialog.text = "Voyons voir... Il semble que tu en saches quelque chose. Et veux-tu que je te révèle les secrets de mes potions ?";
			link.l1 = "Exactement. Et pas gratuitement, si je comprends bien...";
			link.l1.go = "amelia_4";
		break;
		
		case "amelia_4":
			dialog.text = "Tu as bien compris, jeune homme ! Tu n'as pas l'air d'un idiot complet. Eh bien, je peux enseigner à un homme qui cherche le savoir et qui ne gaspille pas cette plante rare en fumant inutilement...";
			link.l1 = "Amelia, avant que nous commencions à marchander... pourrais-tu avoir l'amabilité de me donner quelques connaissances de base sur les potions que je peux fabriquer avec la Manga Rosa ?";
			link.l1.go = "amelia_5";
		break;
		
		case "amelia_5":
			dialog.text = "Pas de marchandage, mon pote. Je te dirai le prix et ce sera ta décision de le payer ou non. Ne compte sur aucune négociation ou remise, ce n'est pas un marché. Et concernant ta question... Tu peux préparer des potions spéciales de Manga Rosa qui renforceront tes capacités physiques. Elles peuvent te rendre plus fort, plus endurant ou plus rapide, ou elles peuvent complètement transformer ton corps, te rendant plus fort dans tous les aspects, mais une telle potion aurait un effet plus faible que les deux précédentes.";
			link.l1 = "Très intéressant. Nommez votre prix.";
			link.l1.go = "amelia_6";
		break;
		
		case "amelia_6":
			dialog.text = "Je peux t'apprendre trois recettes. Pour chaque recette, je demande une plante et cinq cents pièces d'or.";
			link.l1 = "Parle-moi davantage de ces potions. Que fait chacune d'elles ?";
			link.l1.go = "amelia_7";
		break;
		
		case "amelia_7":
			dialog.text = "Vous devez être un maître dans l'art de l'alchimie si vous voulez préparer une seule potion. Chaque potion dure deux jours ou moins, cela dépend de quand vous la buvez; si vous la buvez à minuit, elle durera presque deux jours entiers.\nLa première potion vous ajoute force et endurance. Vous combattrez mieux, subirez moins de dégâts et pourrez porter plus de poids.\nLa deuxième potion vous rendra plus rapide, agile, infatigable et améliorera aussi votre précision.\nLa troisième potion a des effets deux fois moins puissants que les deux potions précédentes. Mais elle vous donne aussi du charme, de la confiance en vous et de la chance.\nToutes les potions à base de Manga Rosa ont un effet positif sur votre santé. Vous devez boire une seule potion à la fois, ne les mélangez jamais, sinon elles ne vous feront aucun bien, au contraire, vous serez gravement empoisonné.\nAlors, beau gosse, êtes-vous prêt à payer pour ce savoir dès maintenant, ou avez-vous besoin de temps pour réfléchir?";
			if (CheckCharacterItem(pchar, "cannabis7") && PCharDublonsTotal() >= 500)
			{
				link.l1 = "Oui, je suis prêt.";
				link.l1.go = "amelia_8";
			}
			link.l2 = "Je dois réfléchir un peu. C'est une décision importante à prendre.";
			link.l2.go = "exit";
			NextDiag.TempNode = "amelia_next";
		break;
		
		case "amelia_next":
			if (!CheckAttribute(npchar, "quest.ChickenGod") && CheckCharacterItem(pchar, "talisman11")) {
				if (CheckAttribute(npchar, "quest.recipe_power") || CheckAttribute(npchar, "quest.recipe_fast") || CheckAttribute(npchar, "quest.recipe_total")) {
					link.chickengod = "Amelia, you seem to have a knack for such things. Can you tell me if there is a demand for such stones among your people? I find them everywhere - it's like everyone is obsessed with them!";
					link.chickengod.go = "chickengod";
				}
			}
			
			if (CheckAttribute(npchar, "quest.ChickenGod") && !CheckAttribute(npchar, "quest.ChickenGod.Complete") && GetCharacterItem(pchar, "talisman11") >= 113) {
				link.chickengod = "Here you go, Amelia. Just as you ordered: one hundred and thirteen adder stones.";
				link.chickengod.go = "chickengod_collected";
			}
		
			if (CheckAttribute(npchar, "quest.recipe_all"))
			{
				dialog.text = "Ah, c'est toi, jeune homme ! Alors, mes potions t'ont-elles aidé ?";
				link.l1 = "Ils l'ont vraiment fait, Amelia. Merci !";
				link.l1.go = "exit";
			}
			else
			{
				dialog.text = "Ah, c'est toi, jeune homme ! Veux-tu acheter quelques recettes ?";
				if (CheckCharacterItem(pchar, "cannabis7") && PCharDublonsTotal() >= 500)
				{
					link.l1 = "Exactement. C'est pourquoi je suis ici.";
					link.l1.go = "amelia_8";
				}
				
				link.l2 = "Pas encore, Amelia. Je vous rends juste visite.";
				link.l2.go = "exit";
			}
			NextDiag.TempNode = "amelia_next";
		break;
		
		case "amelia_8":
			dialog.text = "Très bien. Quel genre de recette veux-tu acheter ?";
			if (!CheckAttribute(npchar, "quest.recipe_power"))
			{
				link.l1 = "La recette de la potion de force et d'endurance.";
				link.l1.go = "power";
			}
			if (!CheckAttribute(npchar, "quest.recipe_fast"))
			{
				link.l2 = "La recette de la potion d'agilité et d'endurance.";
				link.l2.go = "fast";
			}
			if (!CheckAttribute(npchar, "quest.recipe_total"))
			{
				link.l3 = "La recette d'une potion complexe.";
				link.l3.go = "total";
			}
		break;
		
		case "power":
			dialog.text = "Très bien. Je l'ai nommé 'Vague de Marée'. Tiens, prends une instruction. Lis-la attentivement. Et n'oublie pas comment l'utiliser correctement !";
			link.l1 = "Merci, Amelia...";
			link.l1.go = "recipe_exit";
			AddQuestRecordInfo("Recipe", "mangarosapower");
			SetAlchemyRecipeKnown("mangarosapower");
			npchar.quest.recipe_power = true;
		break;
		
		case "fast":
			dialog.text = "Très bien. Je l'ai nommé le 'Rafale'. Tiens, prends une instruction. Lis-la attentivement. Et n'oublie pas comment l'utiliser correctement !";
			link.l1 = "Merci, Amelia...";
			link.l1.go = "recipe_exit";
			AddQuestRecordInfo("Recipe", "mangarosafast");
			SetAlchemyRecipeKnown("mangarosafast");
			npchar.quest.recipe_fast = true;
		break;
		
		case "total":
			dialog.text = "Bien. Je l'ai nommé le 'Câlin des Mers'. Tiens, prends une instruction. Lis-la attentivement. Et n'oublie pas comment l'utiliser correctement !";
			link.l1 = "Merci, Amelia...";
			link.l1.go = "recipe_exit";
			AddQuestRecordInfo("Recipe", "mangarosatotal");
			SetAlchemyRecipeKnown("mangarosatotal");
			npchar.quest.recipe_total = true;
		break;
		
		case "recipe_exit":
			DialogExit();
			NextDiag.CurrentNode = "amelia_next";
			RemoveDublonsFromPCharTotal(500);
			RemoveItems(pchar, "cannabis7", 1);
			Log_Info("You have given 500 doubloons and one Manga Rosa");
			PlaySound("interface\important_item.wav");
			if (CheckAttribute(npchar, "quest.recipe_power") && CheckAttribute(npchar, "quest.recipe_fast") && CheckAttribute(npchar, "quest.recipe_total"))
			{
				npchar.quest.recipe_all = true;
				CloseQuestHeader("mangarosa");
			}
		break;
		
		case "chickengod":
			dialog.text = "Bax de serpent, en effet ! Cela a peu de valeur, mais cela peut être utile à ceux qui savent. Apportez-m'en cent treize, et j'ouvrirai un de mes coffres pour vous.";
			link.l1 = "C'est tout un tas de cailloux ! Pourquoi ne me dis-tu pas d'abord pourquoi tu en as besoin ?";
			link.l1.go = "chickengod_1";
		break;
		
		case "chickengod_1":
			dialog.text = "Non, ma chère, si tu dois demander, alors cette connaissance ne te sert encore à rien.";
			link.l1 = "Et qu'y a-t-il dans le coffre que tu as si généreusement promis d'ouvrir ?";
			link.l1.go = "chickengod_2";
		break;
		
		case "chickengod_2":
			dialog.text = "Bien des choses, utiles pour les capitaines qui ne dédaignent pas le travail manuel. Ne me fais pas perdre mon temps, ma chère, tu ne peux de toute façon pas ramasser autant de cailloux.";
			link.l1 = "On verra cela!";
			link.l1.go = "exit";
			
			npchar.quest.ChickenGod = true;
		break;
		
		case "chickengod_collected":
			dialog.text = "Ha-ha-ha! C'était une blague, ma chère!";
			link.l1 = "La plaisanterie sera sur toi quand ils te brûleront, sorcière, dans ta propre masure !";
			link.l1.go = "chickengod_collected_1";
		break;
		
		case "chickengod_collected_1":
			dialog.text = "Cela n'est pas mon destin, cher... Vous avez rendu cette gitane fière ! Voici, ce coffre est à vous pour le piller.";
			link.l1 = "Merci, Amelia. Mais j'espere vraiment qu'il y a quelque chose d'utile la-dedans a part tes vieux sous-vetements...";
			link.l1.go = "exit";
			
			TakeNItems(pchar, "talisman11", -113);
			npchar.quest.ChickenGod.Complete = true;
			AddDialogExitQuestFunction("ChickenGod_AmeliaOpenChest");
		break;
	}
} 
