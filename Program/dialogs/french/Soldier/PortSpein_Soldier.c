// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Quelles questions as-tu pour un soldat ?","Le soldat a toute sa vie planifiee - garder, se demener... Comment puis-je vous aider, "+GetAddress_Form(NPChar)+"?"),"Tu ne devrais pas importuner un soldat avec des questions stupides, "+GetAddress_Form(NPChar)+"... ","C'est la troisième fois aujourd'hui que tu essaies de me poser une question...","Le destin d'un soldat n'est pas facile, et maintenant toi, racaille, tu me rends fou...","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("J'ai changé d'avis...","Je n'ai rien à dire pour le moment."),"Compris...","Oui, tu as raison, déjà la troisième fois...","Désolé...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			//Цена чахотки
			if (!CheckAttribute(npchar, "quest.Consumption") && CheckAttribute(pchar, "questTemp.Consumption.AskJuan"))
			{
				link.l1 = "Dis-moi, le nom de Juan te dit-il quelque chose ?";
				link.l1.go = "Consumption";
			}
		break;
		
		//Цена чахотки
		case "Consumption":
			dialog.text = "Non. C'est tout?";
			link.l1 = "Oui. Désolé de te déranger, soldat...";
			link.l1.go = "exit";
			npchar.quest.Consumption = "true";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
