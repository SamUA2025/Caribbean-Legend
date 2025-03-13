// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Quelles questions avez-vous?","Comment puis-je vous aider, "+GetAddress_Form(NPChar)+"?"),"Tu as tenté de me poser une question il n'y a pas longtemps, "+GetAddress_Form(NPChar)+"...","Au cours de cette journée, c'est la troisième fois que tu parles de cette question...","Encore des questions, je présume ?","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("J'ai changé d'avis...","Je n'ai rien à dire pour le moment."),"Oumph, ou est donc passe ma memoire...","Oui, c'est vraiment la troisième fois...","Non, quelles questions ?...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			//Jason, Сага, Тени прошлого
			if (CheckAttribute(PChar, "questTemp.Saga.Shadows") && pchar.questTemp.Saga.Shadows == "sentjons")
			{
				link.l1 = "Je cherche Raymond Baker, un ancien bourreau. Savez-vous s'il est en vie et où je peux le trouver ?";
				link.l1.go = "baker";
			}
			//Jason, суп из черепахи
			if (CheckAttribute(PChar, "questTemp.Terrapin") && pchar.questTemp.Terrapin == "baster" && !CheckAttribute(npchar, "quest.terrapin"))
			{
				link.l1 = "Je cherche Monsieur Jones. Peux-tu m'aider dans ma recherche, camarade?";
				link.l1.go = "terrapin";
			}
			// Страж Истины
			if (CheckAttribute(pchar, "questTemp.Guardoftruth") && pchar.questTemp.Guardoftruth == "merdok")
			{
				link.l1 = "Écoutez, y a-t-il un alchimiste qui est arrivé ici dans cette ville, un médecin ? Il est italien, environ trente ans, il s'appelle Gino Gvineili. Avez-vous entendu quelque chose à ce sujet ?";
				link.l1.go = "guardoftruth";
			}
		break;
		
		//Сага, Тени прошлого
		case "baker":
			dialog.text = "Notre cher gros lard est devenu plus populaire que le Colonel Fox ! Il est vivant, le pauvre. Mais il n'est pas en ville en ce moment. Après que Raymond a découvert que des gens sérieux comme vous s'intéressaient à lui, il s'est dépêché de vendre sa masure pour des cacahuètes et s'est envolé avec le vent.";
			link.l1 = "Où le vent l'a-t-il emporté?";
			link.l1.go = "baker_1";
		break;
		
		case "baker_1":
			dialog.text = "Oh, qui sait. Il est parti servir comme médecin de bord sur le premier navire qui passait. Seulement, ce navire vient tout juste de revenir aujourd'hui et personne n'a encore vu Baker débarquer.";
			link.l1 = "Comment puis-je trouver le capitaine ?";
			link.l1.go = "baker_2";
		break;
		
		case "baker_2":
			dialog.text = "Pourquoi crois-tu devoir le chercher ? Je suis sûr qu'il est déjà ivre comme d'habitude dans sa cabine. Son seau percé s'appelle 'Meggy l'Innocente'. Tel est le capitaine, tel est le nom...";
			link.l1 = "Merci pour l'aide, camarade !";
			link.l1.go = "baker_3";
		break;
		
		case "baker_3":
			DialogExit();
			AddQuestRecord("Shadows", "2");
			pchar.questTemp.Saga.Shadows = "baldmaggy";
			pchar.quest.Saga_ShadowsMaggy.win_condition.l1 = "location";
			pchar.quest.Saga_ShadowsMaggy.win_condition.l1.location = "Antigua";
			pchar.quest.Saga_ShadowsMaggy.function = "Saga_SetBaldMaggy";
		break;
		
		//суп из черепахи
		case "terrapin":
			dialog.text = "Monsieur Jones ? Vous me faites marcher, l'ami. Vous savez combien de fichus Jones il y a sur cette île ? Vous allez devoir être plus précis que ça.";
			link.l1 = "Il a une sœur adulte, Molly. On dit qu'elle est d'une beauté incroyable.";
			link.l1.go = "terrapin_1";
		break;
		
		case "terrapin_1":
			dialog.text = "Non. Rien de tel ne me vient à l'esprit. Désolé, l'ami...";
			link.l1 = "D'accord, si tu ne sais pas, tu ne sais pas...";
			link.l1.go = "exit";
			npchar.quest.terrapin = "true";
		break;
		
		case "guardoftruth":
			dialog.text = "Non, je n'ai pas entendu. Et nous n'avons qu'un seul alchimiste en ville, le pharmacien John Murdock. Il a des potions remarquables - elles guérissent tous les maux.";
			link.l1 = "Penses-tu qu'il brasse lui-même ces potions ?";
			link.l1.go = "guardoftruth_1";
		break;
		
		case "guardoftruth_1":
			dialog.text = "Bonne question. Je me le demande de temps en temps. John ne ressemble en rien à un connaisseur de verres médicinaux, d'herbes et de poudres. Il ressemble plutôt à un ancien soldat, un mercenaire... c'est plus proche de la vérité.";
			link.l1 = "Eh bien, je suppose que l'homme est surqualifié...";
			link.l1.go = "guardoftruth_2";
		break;
		
		case "guardoftruth_2":
			dialog.text = "Peut-être qu'il l'est. Mais il y a une chose dont je suis sûr, quelqu'un vit à l'étage. La fenêtre est constamment drapée. Même quand John est en bas, on entend un bruit de cliquetis comme des fioles en verre et des bouteilles, ainsi que l'odeur des herbes en ébullition, et la nuit, la lumière ne s'éteint pas. C'est pourquoi je soupçonne que l'habitant de cette pièce est celui qui prépare les médicaments de John pour la vente.";
			link.l1 = "Hm. Observation intéressante. Merci, matelot !";
			link.l1.go = "exit";
			pchar.questTemp.Guardoftruth = "merdok1";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
