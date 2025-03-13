// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Quel genre de questions ?","Que voulez-vous, "+GetAddress_Form(NPChar)+"?"),"Des questions encore, "+GetAddress_Form(NPChar)+"...","Des questions, des questions... Que diriez-vous d'un échange, "+GetAddress_Form(NPChar)+"hein ?","Écoute, combien de temps comptes-tu parler ?","blocage",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Pas de questions pour l'instant...","Désolé, je n'ai rien à dire pour l'instant..."),"Encore une fois, désolé...","Peut-être qu'il est vraiment temps de commercer...","Je suis désolé, échangeons...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			//Цена чахотки
			if (!CheckAttribute(npchar, "quest.Consumption") && CheckAttribute(pchar, "questTemp.Consumption.AskJuan"))
			{
				link.l1 = "Ecoute, est-ce que le nom 'Juan' te dit quelque chose ?";
				link.l1.go = "Consumption";
			}			
		break;
		
		//Цена чахотки
		case "Consumption":
			dialog.text = "Non, ça ne le fait pas... Maintenant, s'il vous plaît, ne me dérangez pas, je suis assez occupé... Quelle question idiote...";
			link.l1 = "Je vois. Désolé de vous avoir fait perdre votre temps...";
			link.l1.go = "exit";
			npchar.quest.Consumption = "true";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
