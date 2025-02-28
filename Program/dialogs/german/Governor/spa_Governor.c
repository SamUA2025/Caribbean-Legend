// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    ref sld;
    int i, iTemp, iMoney, ShipType, Rank;
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = RandPhraseSimple("Welche Art von Fragen?","Was benötigen Sie?");
			link.l1 = RandPhraseSimple("Nichts von Bedeutung, Herr.","Ich habe nichts zu sagen, Entschuldigung.");
		    link.l1.go = "exit";
		break;
		
		case "work_1":  // работа на благо короны - линейка нации
			if (CheckAttribute(npchar, "notQuestLine"))
			{
                dialog.text = "Leider kann ich Sie nicht für einen Job in Betracht ziehen. Sie sind nicht jemand, mit dem ich im Moment arbeiten möchte. Lebewohl.";
                link.l1 = "Du kannst nicht ernst sein.. aber sehr gut.";
                link.l1.go = "exit";
				break;
			}                   
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
