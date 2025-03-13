// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Que voulez-vous? Demandez donc.","Je vous écoute, quelle est la question ?"),"C'est la deuxième fois que vous essayez de demander...","C'est la troisième fois que vous essayez de demander...","Quand cela va-t-il se terminer ?! Je suis un homme occupé, travaillant sur les affaires de la colonie et vous continuez à me déranger !","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("J'ai changé d'avis...","Pas maintenant. Mauvais endroit et mauvais moment"),"Vrai... Mais plus tard, pas maintenant...","Je demanderai... Mais un peu plus tard...","Je suis désolé, "+GetAddress_FormToNPC(NPChar)+"...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			// Jason Дороже золота
			if (CheckAttribute(pchar, "questTemp.GoldenGirl") && pchar.questTemp.GoldenGirl == "antigua")
			{
				link.l1 = "Votre Excellence, je voudrais vous informer que je possède une certaine information concernant la disparition du Mercury.";
                link.l1.go = "G_Girl";
			}
		break;
		
		// Jason Дороже золота
		case "G_Girl":
			dialog.text = "Des informations ? Sur quoi, déjà ?";
			link.l1 = "La brigantine, votre Excellence. Transportant le courrier. Documents de grande importance et ainsi de suite. J'ai entendu parler de l'enquête et, évidemment, en tant qu'ami loyal de la Couronne britannique, j'aimerais aider.";
			link.l1.go = "G_Girl_1";
		break;
		
		case "G_Girl_1":
			dialog.text = "Splendide ! Le baronnet Cortney sera ravi de vous recevoir ! Je vais organiser une rencontre immédiatement.";
			link.l1 = "Merci, Monsieur. Je suis pressé ici et j'apprécierais si cela pouvait aller vite.";
			link.l1.go = "G_Girl_2";
		break;
		
		case "G_Girl_2":
			dialog.text = "Ne vous inquiétez pas, vous aurez tout le temps du monde. Gardes ! Saisissez-le !";
			link.l1 = "Merci... attendez, quoi? Est-ce une blague ?!";
			link.l1.go = "G_Girl_3";
		break;
		
		case "G_Girl_3":
			DialogExit();
			GoldenGirl_AntiguaArest();
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
