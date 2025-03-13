// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Quelles questions avez-vous?","Comment puis-je vous aider, "+GetAddress_Form(NPChar)+"?"),"Tu as essayé de me poser une question il n'y a pas longtemps, "+GetAddress_Form(NPChar)+"...","Durant toute cette journée, c'est la troisième fois que tu parles de quelque question...","Encore des questions, je présume ?","bloc",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("J'ai changé d'avis...","Je n'ai rien à dire pour le moment."),"Oumph, ou est passée ma mémoire...","Oui, c'est vraiment la troisième fois...","Non, quelles questions ?...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			// Jason Долго и счастливо
			if (CheckAttribute(pchar, "questTemp.LongHappy.Santiago"))
			{
				link.l1 = "J'ai entendu dire que les saints pères sont arrivés ici d'une colonie française avec une délégation, pour s'entendre sur quelque chose ? Probablement, pour échanger des prisonniers après ce bain de sang en Martinique ?";
				link.l1.go = "LH_tavern";
			}
		break;
		
		// Jason Долго и счастливо
		case "LH_tavern":
			dialog.text = "Non monsieur, cette histoire a été réglée il y a longtemps sans aucun clerc. Vous voyez, vous vivez complètement sous un cocotier, puisque vous n'avez pas entendu que le Pape Innocent X avec le Cardinal Mazarin ont finalement convenu. L'Europe avec ses guerres est une chose, mais tous les chrétiens devraient lutter ensemble contre l'obscurité païenne au bout du monde\nEt oui, les mangeurs de grenouilles sont venus chez nous. Mais ils ne se sont simplement mis d'accord sur rien - nos honorables invités restent dans le manoir du gouverneur, sous garde, boivent du café et réchauffent un siège. Presque un mois déjà ! Les gens ont bavardé, parlé longtemps et s'y sont habitués - regardez, l'abbé français fait un service de prière le soir à l'église. Presque comme un spectacle ahah !";
			link.l1 = "Intéressant! Je devrais jeter un oeil à ce Français, au moins c'est plus drôle que de fixer une chope.";
			link.l1.go = "LH_tavern_1";
		break;
		
		case "LH_tavern_1":
			DialogExit();
			LongHappy_SantiagoBenua();
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
