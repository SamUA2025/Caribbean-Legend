// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("What do you want? Ask away.", "I'm listening, what's the question?"), "This is the second time you're trying to ask...", "This is the third time you are trying to ask...",
                          "When is this going to end?! I am a busy man, working on colony matters and you are still bothering me!", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("I changed my mind, sorry.", "Not now. Wrong place and time."), "True, I have nothing to say now, sorry.",
                      "I'll ask, later.", "I am sorry, " + GetAddress_FormToNPC(NPChar) + "...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			//Португалец
			if (CheckAttribute(pchar, "questTemp.Portugal.Villemstad"))
			{
				link.l1 = "I know that the Dutch West India Company has assigned a price for the head of a certain pirate - Bartolomeo the Portuguese. I was able to capture him. He is currently in my cargo hold and I am ready to hand him over to the authorities.";
                link.l1.go = "Portugeze";
			}
		break;

		case "Cupture_after":
            dialog.text = RandPhraseSimple("You have taken everything already. What else do you want?", "Is there anything left that you didn't grab?");
            link.l1 = RandPhraseSimple("Just taking a look around...", "Just checking, might've forgotten to take something...");
            link.l1.go = "exit";
            NextDiag.TempNode = "Cupture_after";
		break;
		
		//Португалец
		case "Portugeze":
			dialog.text = "Bart the Portuguese?! You have him, alive?!";
			link.l1 = "I know that he's of no use to you dead. He is alive and, gods be damned, I had to restrain myself to keep him that way!";
			link.l1.go = "Portugeze_1";
		break;
		
		case "Portugeze_1":
			dialog.text = "Most excellent! Now he will tell us everything... Mynheer, prepare the prisoner for transfer. We will send a military barque to your ship immediately. ";
			link.l1 = "I'd like to talk about my reward first, Mynheer, If you don't mind.";
			link.l1.go = "Portugeze_2";
		break;
		
		case "Portugeze_2":
			dialog.text = "Don't worry about your reward, Sir. You will get it. We have assigned a price for Bartolomeo the Portuguese's head - one thousand and five hundred doubloons. Lieutenant! Bring the captain his reward!";
			link.l1 = "Hm... Hugo told me it was two thousand doubloons... Fine then.";
			link.l1.go = "Portugeze_3";
		break;
		
		case "Portugeze_3":
			TakeNItems(pchar, "gold_dublon", 1500);
			Log_Info("You have received 1500 doubloons");
			PlaySound("interface\important_item.wav");
			dialog.text = "And now, Sir, would you be so kindly to transfer the Portuguese to the Company? We are so eager to have a talk with him.";
			link.l1 = "Sure, Mynheer, send the barque to my ship.";
			link.l1.go = "Portugeze_4";
		break;
		
		case "Portugeze_4":
			DialogExit();
			DoQuestReloadToLocation("Villemstad_town", "reload", "reload1", "Portugal_Final");
			DeleteAttribute(pchar, "questTemp.Portugal.Villemstad");
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
