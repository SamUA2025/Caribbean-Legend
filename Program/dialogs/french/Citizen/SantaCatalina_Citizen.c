// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
            dialog.text = RandPhraseSimple("Quel genre de questions ?","Que voulez-vous ?");
			link.l1 = RandPhraseSimple("J'ai changé d'avis.'","Je n'ai rien à dire maintenant.");
		    link.l1.go = "exit";
		break;
		
		case "info":
			dialog.text = LinkRandPhrase("Qui vous intéresse ?","Qui voulez-vous dire ?","Eh bien, qui est-ce?");
			if (CheckAttribute(pchar, "questTemp.Saga"))
			{
				link.l1 = "Je veux en savoir plus sur Jan Svenson.";
				link.l1.go = "svenson";
			}
			link.l2 = "Changeons de sujet...";
			link.l2.go = "new question";
		break;
		
		case "town":
			dialog.text = LinkRandPhrase("Où veux-tu aller ?","Que cherches-tu ?","Que te faut-il exactement ?");
			if (CheckAttribute(pchar, "questTemp.Saga"))
			{
				link.l1 = "Où se trouve la maison de Jan Svenson ?";
				link.l1.go = "svenson_house";
			}
			link.l2 = "Changeons de sujet...";
			link.l2.go = "new question";
		break;
		
		case "svenson":
			dialog.text = RandPhraseSimple("Oh, notre Jan Svenson est une personne très importante. Autrefois, il était le pirate le plus audacieux de la Main Occidentale et même maintenant il n'a pas commencé à rouiller, ha ! Mais ces jours sont révolus, il n'est plus aussi actif qu'avant. Il possède un manoir et y vit avec sa jeune épouse, et il est toujours un invité de marque à la résidence du gouverneur. Beaucoup d'invités viennent chez Jan, des pirates, surtout.","Jan Svenson est une légende de la Grande-Terre occidentale ! Le Diable des Forêts, c'est ainsi que les Espagnols l'appelaient lorsqu'il les chassait d'ici. Il était autrefois un corsaire célèbre, mais maintenant il est un citoyen respecté de notre colonie.\nBien qu'il fasse encore quelques 'affaires' en parallèle, mais plus de ses propres mains. Il quitte rarement sa maison depuis qu'il a épousé une jeune beauté.");
			link.l1 = "Mes remerciements.";
			link.l1.go = "exit";
		break;
		
		case "svenson_house":
			dialog.text = RandPhraseSimple("Allez droit depuis le quai jusqu'à ce que vous voyiez la place, la maison à droite près de la fontaine est le manoir de Svenson.","Allez au quai en traversant la place depuis la résidence du gouverneur, la maison à gauche près de la fontaine est le manoir de Svenson.");
			link.l1 = "Je vous remercie.";
			link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
