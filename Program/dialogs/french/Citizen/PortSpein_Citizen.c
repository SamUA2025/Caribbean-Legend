// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
            dialog.text = RandPhraseSimple("Quel genre de questions ?","Que veux-tu?");
			link.l1 = RandPhraseSimple("J'ai changé d'avis.","Je n'ai rien à dire maintenant.");
		    link.l1.go = "exit";
			//Цена чахотки
			if (!CheckAttribute(npchar, "quest.Consumption") && CheckAttribute(pchar, "questTemp.Consumption.AskJuan"))
			{
				link.l1 = "Dis-moi, le nom 'Juan' te dit-il quelque chose ?";
				link.l1.go = "Consumption";
			}
			if (!CheckAttribute(npchar, "quest.Guardoftruth") && CheckAttribute(pchar, "questTemp.Guardoftruth.Trinidad") && pchar.questTemp.Guardoftruth.Trinidad == "begin")
			{
				link.l1 = "Ecoute, matelot, une frégate sous le commandement de Miguel Dichoso a accosté ici en avril 1654. Il a disparu ce jour-là. Te souviens-tu de quelque chose à ce sujet ?";
				link.l1.go = "guardoftruth";
			}
		break;
		
		case "info":
        // заменить на описание неких НПС, по квестам
			dialog.text = "Penses-tu que je travaille pour les services secrets de "+NationNameGenitive(sti(NPChar.nation))+" ?";
			link.l1 = "Eh bien... non. Adieu alors.";
			link.l1.go = "exit";
			link.l2 = "Une autre question, alors ?";
			link.l2.go = "new question";
		break;
		
		case "town":
        // заменить на описание как пройти, по квестам
			dialog.text = "J'ai l'air d'un bureau d'investigation ? Je ne sais pas, je ne sais rien.";

            link.l1 = "T'es vraiment un écervelé ! Va-t'en.";
			link.l1.go = "exit";
			link.l2 = "Avez-vous d'autres questions, alors ?";
			link.l2.go = "new question";
		break;
		
		//Цена чахотки
		case "Consumption":
			dialog.text = "Tu te moques de moi ? Il y a des douzaines de Juans dans chaque colonie !";
			link.l1 = "Je vois. Désolé de vous importuner...";
			link.l1.go = "exit";
			npchar.quest.Consumption = "true";
		break;
		
		// Страж Истины
		case "guardoftruth":
			dialog.text = LinkRandPhrase("Allons, capitaine ! Pensez-vous que je me souvienne de ces choses-là ?"," Pardonnez-moi Senor, je ne peux pas vous aider avec ça.","Señor, pensez-vous vraiment que je me souvienne de telles bêtises ? J'ai déjà assez de problèmes.");
			link.l1 = LinkRandPhrase("Je vois. Pardonnez-moi de vous avoir dérangé...","Quel dommage, Adieu.","D'accord, adieu...");
			link.l1.go = "exit";
			npchar.quest.guardoftruth = "true";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
