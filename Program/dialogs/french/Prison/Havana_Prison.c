// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
 	switch(Dialog.CurrentNode)
	{
        case "quests":
            dialog.text = "Parle, j'écoute";
			link.l1 = "Je me suis trompé. Adieu.";
			link.l1.go = "Exit";
			// Addon 2016-1 Jason пиратская линейка
			if (CheckAttribute(pchar, "questTemp.Mtraxx") && pchar.questTemp.Mtraxx == "jewelry_4")
			{
				link.l1 = "Officier, il m'est parvenu que l'un des officiers du navire 'Cantavro' est détenu ici. Est-ce exact ?";
                link.l1.go = "Mtraxx";
			}
			if (CheckAttribute(pchar, "questTemp.Mtraxx") && pchar.questTemp.Mtraxx == "jewelry_8")
			{
				link.l1 = "Je suis revenu pour m'informer à nouveau au sujet de don Lope, officier. Avez-vous déjà reçu ses ordres de libération ?";
                link.l1.go = "Mtraxx_5";
			}
		break;
		
		// Addon 2016-1 Jason пиратская линейка
		case "Mtraxx":
            dialog.text = "L'officier de 'Cantavro'? Don Lope Montoro? Oui, il est détenu ici. Qu'est-ce que cela vous apporte?";
			link.l1 = "Je voudrais une permission pour lui rendre visite.";
			link.l1.go = "Mtraxx_1";
			DelLandQuestMark(npchar);
			AddLandQuestMark(characterFromId("Lope"), "questmarkmain");
		break;
		
		case "Mtraxx_1":
            dialog.text = "Je vous demande pardon, mais sur quelle base?";
			link.l1 = "C'est juste une affaire personnelle. Je l'ai connu en Europe, et j'ai été choqué par la nouvelle de son emprisonnement, et par les ragots qui ont circulé dans toute la ville. J'aimerais lui parler.";
			link.l1.go = "Mtraxx_2";
		break;
		
		case "Mtraxx_2":
            dialog.text = "Hm...";
			link.l1 = "Officier, peut-être pourrais-je... vous 'remercier' pour me laisser lui rendre visite ?";
			link.l1.go = "Mtraxx_3";
		break;
		
		case "Mtraxx_3":
            dialog.text = "Ce n'est pas nécessaire. Je vous permets de rencontrer don Montoro. Les gardes vous laisseront passer.";
			link.l1 = "Merci!";
			link.l1.go = "Mtraxx_4";
		break;
		
		case "Mtraxx_4":
			DialogExit();
            pchar.questTemp.jailCanMove = true;
			pchar.questTemp.Mtraxx = "jewelry_5";
		break;
		
		case "Mtraxx_5":
            dialog.text = "En effet, mon ordre est de livrer don Lope Montoro directement au commandant. Mais je suppose qu'il ne quittera pas la cellule pendant quelques semaines. Tu peux aller le voir cependant, tant qu'il est encore ici.";
			link.l1 = "Merci, officier, c'est pourquoi je suis ici.";
			link.l1.go = "Mtraxx_6";
			DelLandQuestMark(npchar);
		break;
		
		case "Mtraxx_6":
            DialogExit();
            pchar.questTemp.jailCanMove = true;
			pchar.questTemp.Mtraxx = "jewelry_9";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
