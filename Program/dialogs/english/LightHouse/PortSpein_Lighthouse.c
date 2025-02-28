// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("What do you want?", "What would you like to know?"), "What is it you need, " + GetAddress_Form(NPChar) + "?", "That's the third time you try to ask me...", "I've had enough of you, get lost!", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Sorry, I've changed my mind.", "It's nothing, apologies."), "I forgot, my apologies...",
                      "Third time's the charm, ey? Excuse me...", "Sorry, sorry! I'll see myself out then...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			if (CheckAttribute(pchar, "questTemp.Guardoftruth.Trinidad") && pchar.questTemp.Guardoftruth.Trinidad == "begin")
			{
				link.l1 = "Listen, a frigate under the command of Miguel Dichoso was around here in April 1654, it disappeared then. Can you tell me more about his ship? Maybe you saw what happened to it or where it went? Do you remember anything?";
				link.l1.go = "guardoftruth";
			}
		break;
		
		case "guardoftruth":
			dialog.text = "Oh-ho... Aye, Senor, that was a sight to behold! Ye don't forget things like that, ha!";
			link.l1 = "Can you tell me what happened?";
			link.l1.go = "guardoftruth_1";
		break;
		
		case "guardoftruth_1":
			dialog.text = "Senior Dichoso's frigate cast anchor in the harbor of San Jose. I had a good view to see everything, aye. I tell you, it was an excellent frigate, a masterpiece, I swear on me bleedin' heart! The crew bragged about the speed, it could speed up to sixteen knots!\nThey spent a day here, then set sail right towards Tobago island. Then, you wouldn't believe, strange things started happening with the weather as soon as they had disappeared behind the horizon. The weather had been fine for days back then, not a single cloud!\nAnd yet this terrible storm came out from nowhere. Looked like Neptune himself paid us a visit, it did! I went up to the top of me lighthouse in order to light it, but then I saw her... Santa Quiteria! She was rushing upon huge waves accompanied by a giant tornado!\nThe frigate flew near my lighthouse like a spark and then was driven by the storm North West! No one has seen Santa Quiteria since then. Just an hour later the wind and the rain and the clouds were gone and the sun was shining, not a single sign of the storm! Never seen anything like it! Although I collected so much amber from my bay that day...";
			link.l1 = "So the storm has driven the frigate back to the Caribbean sea?";
			link.l1.go = "guardoftruth_2";
		break;
		
		case "guardoftruth_2":
			dialog.text = "It has! Way over yonder to Martinique. I doubt Dichoso could 'av survived that storm, he was doing his best though! The frigate wasn't sinking but Santa Quiteria must be on the bottom of the sea among corals by now... Actually, you are not the first person who has asked me about Dichoso and his frigate.";
			link.l1 = "Really? Who else was interested in Miguel?";
			link.l1.go = "guardoftruth_3";
		break;
		
		case "guardoftruth_3":
			dialog.text = "Some dashing captain of the Spanish fleet, no less! He has introduced himself as...oh... I done and forgotten it... Ah! Senor Diego. His name was Diego, but his surname... de Montagna or de Montoya. Something like that. He was listening to me just like you were, thanked me and gone away. Never seen him since then.";
			if (sti(Pchar.money) >= 5000)
			{
				link.l1 = "I see. Thank you very much for your story, you've helped me a lot. Have my gratitude in coins. Farewell.";
				AddMoneyToCharacter(pchar, -5000);
				AddCharacterExpToSkill(pchar, "Leadership", 250);
			}
			else
			{
				link.l1 = "I see. Thank you very much for your story, you've helped me a lot. Farewell.";
			}
			link.l1.go = "guardoftruth_4";
		break;
		
		case "guardoftruth_4":
			DialogExit();
			AddQuestRecord("Guardoftruth", "41");
			pchar.questTemp.Guardoftruth.Trinidad = "mayak";
			pchar.quest.GuardOT_setDiego.win_condition.l1 = "ExitFromLocation";
			pchar.quest.GuardOT_setDiego.win_condition.l1.location = pchar.location;
			pchar.quest.GuardOT_setDiego.function = "GuardOT_SetDiegoOnMayak";
		break;
	}
	UnloadSegment(NPChar.FileDialog2); 
}
