// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    ref sld;
    switch (Dialog.CurrentNode)
	{
		case "quests":
            dialog.text = RandPhraseSimple("Welche Art von Fragen?","Was benötigen Sie?");
			link.l1 = RandPhraseSimple("Nichts von Bedeutung, Herr.","Es tut mir leid, ich habe nichts zu sagen.");
		    link.l1.go = "exit";
		break;
		
		case "work_1":  // работа на благо короны - линейка нации
			if (CheckAttribute(npchar, "notQuestLine"))
			{
                dialog.text = "Leider kann ich Sie nicht für einen Job in Betracht ziehen. Sie sind im Moment nicht jemand, mit dem ich zusammenarbeiten möchte. Lebewohl.";
                link.l1 = "Du kannst nicht ernst sein.. aber sehr gut.";
                link.l1.go = "exit";
				break;
			}            
		break;		        
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
