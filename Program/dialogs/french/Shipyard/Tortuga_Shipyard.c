// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Quelles questions avez-vous ?","Comment puis-je vous aider ?"),"Vous avez essayé de me poser une question il y a un moment...","Je n'ai jamais rencontré des gens avec une telle curiosité dans mon chantier naval ou ailleurs dans cette ville.","Pourquoi toutes ces questions ? Mon travail, c'est de construire des navires. Occupons-nous de cela.","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("J'ai changé d'avis...","Je n'ai rien à dire pour le moment."),"Oumph, oú est passée ma mémoire...","Eh bien...","Allez-y...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			if (CheckAttribute(pchar, "questTemp.Guardoftruth") && pchar.questTemp.Guardoftruth == "tortuga1")
			{
				link.l1 = "Je cherche un Gaius Marchais. La dernière chose que j'ai entendue sur lui, c'est qu'il a accosté son galion 'Santa Margarita' pour que vous le répariez...";
                link.l1.go = "guardoftruth";
			}
		break;
		
		case "guardoftruth":
			dialog.text = "Son propre galion ? Ho-ho, c'est une bonne blague, capitaine. Gaius Marchais ne possédait qu'un sloop à moitié mort... il a capturé un galion comme prise après avoir décidé de devenir corsaire. Sacré veinard, premier raid et un tel trophée\nJ'ai offert de bons sous pour elle, mais il a refusé, imaginez ça ! Au lieu de cela, il a vendu son sloop pathétique pour une petite somme et l'a utilisé pour réparer le galion ! De nouvelles voiles, de nouvelles couleurs et un nouveau nom, ce qui n'est généralement pas bon signe\nCertes, le nom était bien trop papiste, mais ma fille s'appelle aussi Margarita, donc je pense que c'était acceptable après tout... Il a dit qu'il en avait assez de la violence, alors il deviendrait marchand. Et il a eu la chance...";
			link.l1 = "Le commerce, je suppose, serait reposant, mais les galions papistes ne se font généralement pas capturer par des sloops. Et quel est le nouveau nom de son navire maintenant ?";
			link.l1.go = "guardoftruth_1";
		break;
		
		case "guardoftruth_1":
			dialog.text = "'Admirable'... Pas étonnant ! Il courait autour de sa nouvelle galion comme s'il poursuivait une mariée, il ne pouvait tout simplement pas arrêter de l'admirer.";
			link.l1 = "Je vois. Gaius est-il sur Tortuga en ce moment ?";
			link.l1.go = "guardoftruth_2";
		break;
		
		case "guardoftruth_2":
			dialog.text = "Non. Il a mis les voiles sur son nouveau navire et n'est toujours pas revenu à Tortuga. Je ne sais pas où il se dirigeait, donc je ne peux pas vous aider avec cette affaire.";
			link.l1 = "Quel désagrément... J'ai vraiment besoin de lui. Nous devrions même boire un coup pour son 'admirable' navire. Quoi qu'il en soit, merci pour l'information.";
			link.l1.go = "guardoftruth_3";
		break;
		
		case "guardoftruth_3":
			dialog.text = "Ah, pas de problème. Repassez quand vous voulez, capitaine. Et n'oubliez pas qu'il y a toujours de la place pour votre navire ici, si des réparations sont nécessaires !";
			link.l1 = "... ";
			link.l1.go = "exit";
			AddQuestRecord("Guardoftruth", "9");
			pchar.questTemp.Guardoftruth = "tortuga2";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
