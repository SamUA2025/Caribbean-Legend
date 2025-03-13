// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    ref sld;
    int i, iTemp, iMoney, ShipType, Rank;
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = RandPhraseSimple("Quel genre de questions?","Que désirez-vous ?");
			link.l1 = RandPhraseSimple("Rien d'important, Monsieur.","Je n'ai rien à dire, toutes mes excuses.");
		    link.l1.go = "exit";
		break;
		
		case "work_1":  // работа на благо короны - линейка нации
			if (CheckAttribute(npchar, "notQuestLine"))
			{
                dialog.text = "Malheureusement, je ne peux pas vous envisager pour un emploi. Vous n'êtes pas quelqu'un avec qui je souhaite travailler pour le moment. Adieu.";
                link.l1 = "Tu ne peux pas être sérieux.. mais soit.";
                link.l1.go = "exit";
				break;
			}                   
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
