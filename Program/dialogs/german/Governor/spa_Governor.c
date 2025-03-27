// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    ref sld;
    int i, iTemp, iMoney, ShipType, Rank;
    switch (Dialog.CurrentNode)
	{
		case "quests":
            dialog.text = RandPhraseSimple("Was wollen Sie wissen?","Was benötigen Sie?");
			link.l1 = RandPhraseSimple("Nichts von Bedeutung, Herr.","Es tut mir leid, ich habe nichts zu sagen.");
		    link.l1.go = "exit";
		break;
		
		case "work_1":  // работа на благо короны - линейка нации
			if (CheckAttribute(npchar, "notQuestLine"))
			{
                dialog.text = "Leider kann ich Sie nicht für einen Auftrag in Betracht ziehen. Sie sind im Moment nicht jemand, mit dem ich zusammenarbeiten möchte. Lebewohl.";
                link.l1 = "Das kann nicht Ihr Ernst sein.. aber gut.";
                link.l1.go = "exit";
				break;
			}                   
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
