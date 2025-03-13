// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Que veux-tu ?","Que voulez-vous savoir ?"),"Que voulez-vous, "+GetAddress_Form(NPChar)+"?","C'est la troisième fois que tu essaies de me demander...","J'en ai marre de toi, va-t'en !","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Désolé, j'ai changé d'avis.","Ce n'est rien, mes excuses."),"J'ai oublié, mes excuses...","La troisième fois est la bonne, hein? Excusez-moi...","Désolé, désolé ! Je vais m'en aller alors...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			// калеуче
			if (CheckAttribute(pchar, "questTemp.Caleuche") && pchar.questTemp.Caleuche == "graveyard" && !CheckAttribute(npchar, "quest.caleuche"))
			{
				link.l1 = "Ecoutez - un homme du nom de Joachim Merriman a-t-il été ici ? C'est un señor portugais d'âge moyen, avec une moustache, une barbe impériale et des yeux perçants. Peut-être a-t-il débarqué dans une crique ou près du phare ? Avez-vous vu quelqu'un comme lui ?";
				link.l1.go = "merriman";
			}
		break;
		
		// калеуче
		case "merriman":
			dialog.text = "Non, matelot, je n'ai vu personne comme lui. J'l'aurais remarqué, aye.";
			link.l1 = "Je vois, quel dommage. Merci pour votre temps, je vais continuer ma recherche alors.";
			link.l1.go = "exit";
			npchar.quest.caleuche = "true";
		break;
	}
	UnloadSegment(NPChar.FileDialog2); 
}
