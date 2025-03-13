// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
            dialog.text = RandPhraseSimple("Quelle sorte de questions ?","Que veux-tu ?");
			link.l1 = RandPhraseSimple("J'ai changé d'avis.","Je n'ai rien à dire maintenant.");
		    link.l1.go = "exit";
			
			// Rebbebion, "Путеводная звезда"
			if (CheckAttribute(pchar, "questTemp.PZ.TortugaCitizensAsk") && npchar.sex == "man")
			{
				link.l1 = "Vous ne connaîtriez pas un certain Joep van der Vink, par hasard ?";
				link.l1.go = "PZ1";
			}
		break;
		
		case "info":
        // заменить на описание неких НПС, по квестам
			dialog.text = "Penses-tu que je travaille pour les services secrets de "+NationNameGenitive(sti(NPChar.nation))+"?";
			link.l1 = "Eh bien... non. Adieu donc.";
			link.l1.go = "exit";
			link.l2 = "As-tu d'autres questions, alors ?";
			link.l2.go = "new question";
		break;
		
		case "town":
        // заменить на описание как пройти, по квестам
			dialog.text = "Ai-je l'air du bureau d'enquête? Je ne sais pas, je ne sais rien.";

            link.l1 = "Tu es vraiment un tête de linotte ! Ouste.";
			link.l1.go = "exit";
			link.l2 = "Une autre question, alors ?";
			link.l2.go = "new question";
		break;
		
		case "PZ1":
			dialog.text = "Eh bien, je ne le connais pas personnellement, mais je le vois ici de temps en temps. Pourquoi demandes-tu ?";
			link.l1 = "On m'a assigné la mission de lui livrer un paquet personnellement. Mais personne ne veut parler de lui, et je ne sais pas pourquoi. Le savez-vous ? Est-ce un homme mauvais ? J'apprécierais votre opinion honnête.";
			link.l1.go = "PZ2";
		break;
		
		case "PZ2":
			dialog.text = "Encore une fois, nous ne nous connaissons pas personnellement, donc je ne sais presque rien. Mais il a un ami proche en ville, et on les voit souvent ensemble. Allez le voir - il décidera s'il vous en dira plus ou non. Son copain s'appelle Rober Martene.";
			link.l1 = "Rober Martene, dites-vous... Et qui est-il ? Où puis-je le trouver ?";
			link.l1.go = "PZ3";
		break;
		
		case "PZ3":
			dialog.text = "Différents endroits, mais en ce moment, il est à notre phare - à réparer son galion après une terrible tempête. Il s'appelle le 'Voltigeur'.";
			link.l1 = "Merci beaucoup ! Tu n'as pas idée à quel point tu m'as aidé.";
			link.l1.go = "Exit";
			AddDialogExitQuest("PZ_CreateRobertMartin");
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
