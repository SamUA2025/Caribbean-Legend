// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Quelles questions avez-vous?","Comment puis-je vous aider, "+GetAddress_Form(NPChar)+"?"),"Tu as essayé de me poser une question il n'y a pas longtemps, "+GetAddress_Form(NPChar)+"...","Pendant toute cette journée, c'est la troisième fois que tu parles d'une question...","Encore des questions, je présume ?","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("J'ai changé d'avis...","Je n'ai rien à dire pour le moment."),"Oumph, où est passée ma mémoire...","Oui, c'est vraiment la troisième fois...","Non, quelles questions ?...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			if (pchar.questTemp.Slavetrader == "FindRatJamaica")
            {
                link.l1 = "Un homme nommé Francois Gontier est-il passé par votre ville ? J'ai vraiment besoin de lui.";
                link.l1.go = "Jamaica_ratF_1";
            }
			// Addon 2016-1 Jason пиратская линейка
			if (CheckAttribute(pchar, "questTemp.Mtraxx") && pchar.questTemp.Mtraxx == "silk_4")
            {
                link.l1 = "Ecoute, mon gars, il y a un navire au départ de Port Royal qui achète de la soie pour son chantier naval... une soie très spéciale, tu en as sûrement entendu parler. On dit qu'un vendeur de cette soie réside quelque part dans cette colonie. As-tu des indices sur comment le trouver ? J'ai une proposition d'affaires pour lui.";
                link.l1.go = "mtraxx";
			}
			if (CheckAttribute(pchar, "questTemp.Mtraxx") && pchar.questTemp.Mtraxx == "silk_5" && (PCharDublonsTotal() >= 50))
            {
                link.l1 = "J'ai cinquante doublons avec moi. Prends-les et commence à parler.";
                link.l1.go = "mtraxx_4_1";
			}
		break;

		case "Jamaica_ratF_1":
			dialog.text = "Il l'a fait. Il louait une chambre depuis quelques jours. Pas le type le plus agréable, je te le dis. En plus, il était obsédé par la peur d'être recherché. Il avait toujours peur et regardait autour de lui. Êtes-vous l'homme dont il avait si peur ?";
			link.l1 = "Non, ce n'est pas moi. Vous savez, les corsaires ont beaucoup d'ennemis cependant. Alors, où puis-je le trouver ? Lui et moi avons décidé de conclure un accord, mais on dirait que la terre l'a englouti.";
			link.l1.go = "Jamaica_ratF_2";
		break;
		
		case "Jamaica_ratF_2":
			dialog.text = "Il est parti en mer sur son propre navire. Je ne sais pas où. Il ne m'a pas informé de cela.";
			link.l1 = "Ah, quel dommage ! Où vais-je le chercher maintenant ?";
			link.l1.go = "Jamaica_ratF_3";
		break;
		
		case "Jamaica_ratF_3":
			dialog.text = "Je ne sais pas, camarade. Je te le dirais si je savais.";
			link.l1 = "D'accord, je vois. Je vais aller demander à d'autres personnes...";
			link.l1.go = "exit";
			AddQuestRecord("Slavetrader", "21_4");
			pchar.questTemp.Slavetrader = "FindRatJamaica_H";
		break;
		
		// Addon 2016-1 Jason пиратская линейка
		case "mtraxx":
            dialog.text = "Hé bien, si tu soupçonnes notre marchand, celui qui tient la boutique, je peux te dire que ce n'est pas lui, il ne trafique pas de toile de soie pour voiles. Les contrebandiers ne viennent pas ici non plus, pas besoin d'eux quand il n'y a pas de douanes. Et d'ailleurs, personne d'autre à part notre marchand ne fait du commerce ici de toute façon. Regarde autour de toi, nous ne sommes pas ce genre de gens, ha-ha !";
			link.l1 = "Mais quelqu'un fournit la soie à Port Royal - c'est irréfutable. As-tu le moindre indice sur qui pourrait être le fournisseur ?";
			link.l1.go = "mtraxx_1";
		break;
		
		case "mtraxx_1":
            dialog.text = "Des contrebandiers de Port Royal, peut-être ? Ou des pirates renégats ? Ils doivent décharger leur butin dans quelque crique cachée... Ha ! J'ai une idée, camarade. Il y a un local ici, il connaît tout ce qui se passe dans ces eaux. S'il n'a aucune supposition, alors il n'y a pas de marchands de soie.";
			link.l1 = "Splendide ! Comment s'appelle le gars ?";
			link.l1.go = "mtraxx_2";
		break;
		
		case "mtraxx_2":
            dialog.text = "Hm... J'essaie de me rappeler de son nom mais cela ne me revient pas pour une raison quelconque...";
			link.l1 = "Que diriez-vous de quelques pièces pour rafraîchir votre mémoire ?";
			link.l1.go = "mtraxx_3";
		break;
		
		case "mtraxx_3":
            dialog.text = "Je suppose que cela pourrait aider... Cinquante doublons d'or éclaireront sûrement cette vieille tête.";
			if (PCharDublonsTotal() >= 50) // Rebbebion, учёт количества дублонов из рундука
			{
				link.l1 = "Je vois. Tiens, prends les pièces.";
				link.l1.go = "mtraxx_4_1";
			}
			else
			{
				link.l1 = "Je vois. Je reviendrai...";
				link.l1.go = "mtraxx_4_2";
			}
		break;
		
		case "mtraxx_4_1":
			RemoveDublonsFromPCharTotal(50);
			PlaySound("interface\important_item.wav");
            dialog.text = "Le gars qu'il te faut, c'est Husky Billy. Il vit en Jamaïque depuis une éternité, il connaît chaque cabot dans les rues. C'était un pirate, une vraie plaie pour les Anglais jusqu'à ce qu'il soit blessé il y a environ trois ans. Maintenant, il pêche surtout, chasse les requins et collecte de l'ambre dans les baies de la Jamaïque. Il ne quitte son vieux longboat que pour acheter plus de rhum et de biscuits.\nTu devrais le chercher dans les eaux autour de la Jamaïque. On dit qu'il navigue du côté nord, tout le long jusqu'à la pointe la plus à l'est. Mais courir après un longboat, c'est une quête d'idiot, mieux vaut faire le guet vers le coin sud-ouest, on dit qu'on l'a vu près du Cap Negril environ une fois par semaine. Sa coquille de noix s'appelle 'Le Poisson Volant'.";
			link.l1 = "Merci, camarade. Tu as gagné ton or.";
			link.l1.go = "mtraxx_5";
		break;
		
		case "mtraxx_5":
            dialog.text = "Bonne chance, mate ! J'espère que tu trouveras ce que tu cherches !";
			link.l1 = "... -> ";
			link.l1.go = "mtraxx_6";
		break;
		
		case "mtraxx_4_2":
            DialogExit();
			AddQuestRecord("Roger_2", "6");
			pchar.questTemp.Mtraxx = "silk_5";
		break;
		
		case "mtraxx_6":
            DialogExit();
			AddQuestRecord("Roger_2", "7");
			pchar.questTemp.Mtraxx = "silk_6";
			/*pchar.quest.mtr_negril.win_condition.l1 = "Timer";
			pchar.quest.mtr_negril.win_condition.l1.date.hour  = 12+rand(12);
			pchar.quest.mtr_negril.win_condition.l1.date.day   = GetAddingDataDay(0, 0, 2+rand(3));
			pchar.quest.mtr_negril.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 2+rand(3));
			pchar.quest.mtr_negril.win_condition.l1.date.year  = GetAddingDataYear(0, 0, 2+rand(3));*/
			PChar.quest.mtr_negril.win_condition.l1 = "ExitFromLocation";
			PChar.quest.mtr_negril.win_condition.l1.location = PChar.location;
			pchar.quest.mtr_negril.function = "Mtraxx_CreateBilly";
			SetFunctionTimerCondition("Mtraxx_BillySeaTimeOver", 0, 0, 7, false);
			if(bImCasual) NewGameTip("Exploration mode: timer is not disabled. Meet the deadline!");
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
