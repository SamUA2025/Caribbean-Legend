// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Quel genre de questions, "+GetSexPhrase("mon fils","ma fille")+"?","Demandez, je vous écoute..."),"Je suis à l'écoute, parlez maintenant, "+GetSexPhrase("mon fils","ma fille")+"... ","Pour la troisième fois, "+GetSexPhrase("mon fils","mafille")+", demande ce dont tu as besoin.","Un homme d'église a beaucoup de travail et vous me distrayez, "+GetSexPhrase("mon fils","mafille")+"... ","bloc",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("J'ai changé d'avis...","Pas en ce moment, padre..."),"Je n'ai rien à dire, je vous prie de m'excuser.","Je demanderai, mais plus tard. Pardonnez-moi, mon père.","Pardonnez-moi, saint père...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			// Jason Долго и счастливо
			if (CheckAttribute(pchar, "questTemp.LongHappy") && pchar.questTemp.LongHappy == "choose" && !CheckAttribute(npchar, "quest.LongHappy"))
			{
				link.l1 = "Saint Père, je cherche l'Abbé Benoit, j'ai une affaire urgente pour lui. Pouvez-vous me dire où je peux le trouver ?";
				link.l1.go = "LH_church";
			}
		break;
		
		// Jason Долго и счастливо
		case "LH_church":
			dialog.text = "L'abbé Benoit a quitté la ville pour des affaires ecclésiastiques avec des représentants de la mission catholique espagnole dans le Nouveau Monde. Je n'en connais pas les détails, mais l'abbé Benoit est absent depuis assez longtemps pour supposer que les négociations se sont prolongées, ou que quelque chose s'est passé en chemin. Nous sommes tous inquiets, mais nous ne pouvons que prier et attendre des nouvelles.";
			link.l1 = "Ne peux pas tout supposer être facile. Saint père, pouvez-vous me dire où exactement l'abbé Benoit est allé ? J'ai besoin de le trouver aussi vite que possible.";
			link.l1.go = "LH_church_1";
		break;
		
		case "LH_church_1":
			dialog.text = "J'ai bien peur de ne pouvoir le faire, mon fils. Autant que je sache, l'abbé Benoit est allé négocier avec l'évêque de la Nouvelle-Espagne et le prélat de l'Inquisition, le Père Vincento Palotti, mais il n'a pas précisé où se tiendra la réunion.";
			link.l1 = "Ça devrait suffire, Saint Père, merci. Je connais d'une certaine manière le père Palotti... Je vais jeter un oeil à Santiago.";
			link.l1.go = "LH_church_2";
		break;
		
		case "LH_church_2":
			DialogExit();
			npchar.quest.LongHappy = "true";
			LongHappy_GoToSantiago();
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
