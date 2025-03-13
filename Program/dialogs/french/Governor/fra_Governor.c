// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    ref sld;
	switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = RandPhraseSimple("Quel genre de questions?","Que désirez-vous ?");
			link.l1 = RandPhraseSimple("Rien d'important, Monsieur.","Je n'ai rien à dire, mes excuses.");
		    link.l1.go = "exit";
		break;
		
		case "work_1":  // работа на благо короны - линейка нации
			if (CheckAttribute(npchar, "notQuestLine"))
			{
                dialog.text = "Malheureusement, je ne peux pas vous considérer pour un emploi. Vous n'êtes pas quelqu'un avec qui je veux travailler pour le moment. Adieu.";
                link.l1 = "Tu ne peux pas être sérieux.. mais très bien.";
                link.l1.go = "exit";
				break;
			}            
		break;		 		            
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
