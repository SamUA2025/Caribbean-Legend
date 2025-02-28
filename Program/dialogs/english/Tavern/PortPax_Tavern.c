// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat("All the rumors of "+ GetCityName(npchar.city) +" at your service. What would you like to find out?",
                          "We were just talking about that. You must have forgotten...", "This is the third time today you're talking about some question...",
                          "You're repeating all the same like a parrot...", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("You know, " + NPChar.name + ", maybe next time.", "Right, I've forgotten for some reason...",
                      "Yes, it really is the third time...", "Yup...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			if (CheckAttribute(pchar, "questTemp.Guardoftruth") && pchar.questTemp.Guardoftruth == "portprince")
			{
				link.l1 = "Tell me, has a galleon by the name of 'Santa Margarita' stopped by at your colony lately? Maybe as the prize of a privateer?";
                link.l1.go = "guardoftruth";
			}
		break;
		
		case "guardoftruth":
			dialog.text = "Mate, it's pretty rare when anybody stops by our colony with prizes and we haven't seen a galleon with a name like that. Hispaniola is a wild island and we're a small colony. It's quiet here. We trade with the buccaneers in the highlands for cow hides and dried beef. Privateers don't usually hang around, we don't have any brothels here and we've got the Spanish in close proximity. Go search for your galleon some where else.";
			link.l1 = "I see. Thanks for an advice!";
			link.l1.go = "exit";
			AddQuestRecord("Guardoftruth", "7");
			pchar.questTemp.Guardoftruth = "tortuga";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
