// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
 	switch(Dialog.CurrentNode)
	{
        case "quests":
            dialog.text = "Parle, je t'écoute";
			link.l1 = "Je me suis trompé. Adieu.";
			link.l1.go = "Exit";
			//Португалец
			if (CheckAttribute(pchar, "questTemp.Portugal") && pchar.questTemp.Portugal == "PortugalInPrison")
            {
                link.l1 = "Officier, vous détenez ici un prisonnier nommé Bartolomeo le Portugais...";
                link.l1.go = "Portugal";
            }
		break;
		
		//Португалец
		case "Portugal":
			dialog.text = "Nous le faisons. Et pourquoi cela vous intéresse-t-il ? Seuls les envoyés de la Compagnie néerlandaise des Indes occidentales sont autorisés à le voir et uniquement sur ordre écrit du gouverneur. Un des officiers de la Compagnie interroge ce pirate en ce moment. Donc, si vous êtes venu ici juste pour le voir, vous feriez mieux de partir, vous le verrez quand il sera pendu, maintenant partez.";
			link.l1 = "Je ne suis pas venu ici pour le voir.";
			link.l1.go = "Portugal_1";
		break;
		
		case "Portugal_1":
			dialog.text = "Pourquoi donc, si je puis me permettre ?";
			link.l1 = "Je suis venu ici... pour le libérer !";
			link.l1.go = "fight";
			chrDisableReloadToLocation = true;
			//pchar.quest.InMarigoResidenceOver.over = "yes"; //снять таймер
			InterfaceStates.Buttons.Save.enable = false;//запретить сохраняться
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
