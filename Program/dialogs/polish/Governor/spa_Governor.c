// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    ref sld;
    int i, iTemp, iMoney, ShipType, Rank;
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = RandPhraseSimple("Jakie to pytania?","Czego potrzebujesz?");
			link.l1 = RandPhraseSimple("Nic ważnego, panie.","Nie mam nic do powiedzenia, przepraszam.");
		    link.l1.go = "exit";
		break;
		
		case "work_1":  // работа на благо короны - линейка нации
			if (CheckAttribute(npchar, "notQuestLine"))
			{
                dialog.text = "Niestety, nie mogę rozważyć cię na to stanowisko. Nie jesteś kimś, z kim chciałbym teraz współpracować. Żegnaj.";
                link.l1 = "Nie możesz być poważny... ale dobrze.";
                link.l1.go = "exit";
				break;
			}                   
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
