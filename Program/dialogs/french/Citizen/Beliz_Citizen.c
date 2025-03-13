// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
            dialog.text = RandPhraseSimple("Quel genre de questions?","Que veux-tu ?");
			link.l1 = RandPhraseSimple("J'ai changé d'avis.","Je n'ai rien à dire maintenant.");
		    link.l1.go = "exit";
			// Rebbebion, квест "Путеводная звезда" ==>
			if (CheckAttribute(pchar, "questTemp.Beliz.AskForLatterAndSotta") && !CheckAttribute(npchar, "questTemp.Sotta") && !CheckAttribute(npchar, "questTemp.Lutter"))
			{
				if (rand(1) == 0)
				{
					link.l1 = "Avez-vous, par hasard, croisé le capitaine Edgardo Sotta ? Pouvez-vous nous en dire quelque chose à son sujet ? Il semble être un homme qui mérite d'être connu.";
					link.l1.go = "Sotta1";
					link.l2 = "Ne vas-tu pas voir l'exécution du Ventru?";
					link.l2.go = "Lutter1";
				}
				else
				{
					link.l1 = "Dis-moi, as-tu vu le héros du jour, le capitaine Edgardo Sotta ? Je l'ai manqué, malheureusement. Comment est-il ? Je ne peux pas croire qu'un marchand ait attrapé le fameux Ventard Matt !";
					link.l1.go = "Sotta1_1";
					link.l2 = "Je vois que toute la ville fête la capture de Lutter, même ceux qui ne prennent jamais la mer."link.l2.go ="Lutter1_1";
				}
			}
			// <== квест "Путеводная звезда"
		break;
		
		case "info":
        // заменить на описание неких НПС, по квестам
			dialog.text = "Penses-tu que je travaille pour le service secret de "+NationNameGenitive(sti(NPChar.nation))+"?";
			link.l1 = "Eh bien... non. Adieu alors.";
			link.l1.go = "exit";
			link.l2 = "Une autre question, alors ?";
			link.l2.go = "new question";
		break;
		
		case "town":
        // заменить на описание как пройти, по квестам
			dialog.text = "Est-ce que j'ai l'air du bureau d'enquête ? Je ne sais pas, je ne sais rien.";

            link.l1 = "Tu es un vrai brouillon ! Va-t'en.";
			link.l1.go = "exit";
			link.l2 = "Une autre question, alors?";
			link.l2.go = "new question";
		break;
		
		// Квест "Путеводная звезда" ==>
		case "Sotta1":
			dialog.text = "Je n'ai pas eu l'occasion de lui parler, mais j'ai vu son navire - un lourd galion. C'est dangereux de naviguer seul dans ces eaux, mais Sotta le fait sans escorte.";
			link.l1 = "Probablement à la poursuite de chaque pièce d'or et réduisant les coûts où qu'il le puisse. Eh bien, je ne vais pas vous retenir. Bonne journée.";
			link.l1.go = "Exit";
			
			npchar.questTemp.Sotta = true;
			pchar.questTemp.PZ_BelizAskCitizens = sti(pchar.questTemp.PZ_BelizAskCitizens) + 1;
			AddDialogExitQuest("PZ_LongwayBelizDialog");
		break;
		
		case "Sotta1_1":
			dialog.text = "Hé bien, c'est difficile à croire ! Mais ne croyez pas tout ce que vous entendez, monsieur. Je l'ai vu, aussi clair que je vous vois maintenant. C'est bien qu'il ait attrapé Lutter, mais pourquoi toute cette comédie de marchand ? Il se comporte comme un soldat. Je peux toujours le dire - un de mes proches a servi pendant des années.";
			link.l1 = "Intéressant. Eh bien, chacun a ses secrets. Je ferais mieux de m'en aller. Merci pour l'éclaircissement.";
			link.l1.go = "Exit";
			
			npchar.questTemp.Sotta = true;
			pchar.questTemp.PZ_BelizAskCitizens = sti(pchar.questTemp.PZ_BelizAskCitizens) + 1;
			AddDialogExitQuest("PZ_LongwayBelizDialog");
		break;
		
		case "Lutter1":
			dialog.text = "J'ai déjà vu cet homme. Il est difficile de croire que c'est le même pirate qui a terrorisé nos marchands pendant des années. Comment a-t-il même obtenu son propre commandement au départ ? J'ai vu les soldats l'escorter - criant, pleurant, riant. Un fou.";
			link.l1 = "Peut-être que la défaite et la réalité de sa mort imminente étaient trop pour lui. Mais ça n'a pas d'importance. Adieu !";
			link.l1.go = "Exit";
			
			npchar.questTemp.Lutter = true;
			pchar.questTemp.PZ_BelizAskCitizens = sti(pchar.questTemp.PZ_BelizAskCitizens) + 1;
			AddDialogExitQuest("PZ_LongwayBelizDialog");
		break;
		
		case "Lutter1_1":
			dialog.text = "Oui, et je fête ça aussi - bon nombre de mes compatriotes sont morts de ses mains. Les malchanceux ont perdu un père, un frère, un fils - vous voyez le tableau. Cette barbarie a duré trop longtemps ! Matt devait être l'un des pirates les plus chanceux de ces dernières années, si vous voulez mon avis.";
			link.l1 = "La chance finit toujours par tourner. À la prochaine.";
			link.l1.go = "Exit";
			
			npchar.questTemp.Lutter = true;
			pchar.questTemp.PZ_BelizAskCitizens = sti(pchar.questTemp.PZ_BelizAskCitizens) + 1;
			AddDialogExitQuest("PZ_LongwayBelizDialog");
		break;
		// <== Квест "Путеводная звезда"
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
