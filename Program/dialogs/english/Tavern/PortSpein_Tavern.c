// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("What questions do you have?", "How can I help you, " + GetAddress_Form(NPChar) + "?"), "You tried to ask me some question not long ago, " + GetAddress_Form(NPChar) + "...", "Over this whole day, this is the third time you're talking about some question...",
                          "More questions, I presume?", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("I've changed my mind...", "I've got nothing to talk about at the moment."), "Umph, where has my memory gone...",
                      "Yes, it really is the third time...", "No, what questions?...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			//Цена чахотки
			if (!CheckAttribute(npchar, "quest.Consumption") && CheckAttribute(pchar, "questTemp.Consumption") && pchar.questTemp.Consumption == "begin" && sti(pchar.money) >= 3000)
			{
				link.l1 = "I've heard that consumption is running rampant in your fort. Do you think the epidemic is going to spread to the town?";
				link.l1.go = "Consumption";
			}
			if (CheckAttribute(npchar, "quest.Consumption") && CheckAttribute(pchar, "questTemp.Consumption.Commandant") && pchar.questTemp.Consumption == "begin")
			{
				link.l1 = "What can you say about the fort's commandant?";
				link.l1.go = "Consumption_8";
			}
			if (!CheckAttribute(npchar, "quest.Consumption_1") && CheckAttribute(pchar, "questTemp.Consumption.AskJuan"))
			{
				link.l1 = "Tell me, does the name 'Juan' mean anything to you?";
				link.l1.go = "Consumption_12";
			}
			if (!CheckAttribute(npchar, "quest.Guardoftruth") && CheckAttribute(pchar, "questTemp.Guardoftruth.Trinidad") && pchar.questTemp.Guardoftruth.Trinidad == "begin")
			{
				link.l1 = "Listen, in April 1654 a frigate docked in at your port under the command of Captain Miguel Dichoso and he disappeared after. Is there anything you can tell me about it?";
				link.l1.go = "guardoftruth";
			}
		break;
		
		//--> Цена чахотки
		case "Consumption":
			dialog.text = "The commandant states that there is no danger. Those who are too curious end up locked in the casemates. I'm not one of those, sorry.";
			link.l1 = "Is that so? A tavernkeeper has no desire to listen to rumors - that's something new! May it be that the clinking of pesos may return your curiosity?";
			link.l1.go = "Consumption_1";
		break;
		
		case "Consumption_1":
			dialog.text = "Silver is tempting of course, but my own skin is higher in value. Maybe I could tell you about something else, senor? I'm actually always glad to talk, just start the conversation!";
			link.l1 = "So that's how the issue unfolds... All right, in this purse is three thousand pieces of eight and we will have a nice little chat about the weather, deal?";
			link.l1.go = "Consumption_2";
		break;
		
		case "Consumption_2":
			AddMoneyToCharacter(pchar, -3000);
			dialog.text = "Oh, you are persistent, senor. Just, remember this conversation never happened. (whispering) I've heard several times already for a whole year that people were burning away in our prisons, dying of consumption. You can blame the authorities, you can blame God, or the Devil, but most of it is attributed to ill fortune. This damned disease steals lives so fast.  Sometimes they'll put a perfectly healthy man in there and in a week or two he's gone. Just like that...";
			link.l1 = "Wow... A whole year, you say? And what, nobody's taken it upon themselves to do anything about it?";
			link.l1.go = "Consumption_3";
		break;
		
		case "Consumption_3":
			dialog.text = "Who cares, senor? Who cares about prisoners? The scum of society - so the great men in silk say. There was a physician who worked in the dungeons. Tried to heal those poor souls. He didn't last long, it seems that the illness got rid of him too\nThe commandant doesn't let people in now, and our authorities don't pay attention to such matters, especially when they have to pay less for prison rations.";
			link.l1 = "Interesting, but what is it about this disease that scares you so much that, locked inside secure walls, we are whispering like nuns in the confessional?";
			link.l1.go = "Consumption_4";
		break;
		
		case "Consumption_4":
			dialog.text = "It's hard for me to tell you, but there was one fellow here. He was taken in for smuggling and was locked up for about half a year until his mates bought him out. Well, you know -they measured off gold for whoever needed it, they waited as much as they were told, and the fellow got out. But ever since then he's been quite mad.";
			link.l1 = "Crazier than a bilge rat?";
			link.l1.go = "Consumption_5";
		break;
		
		case "Consumption_5":
			dialog.text = "I guess. He was useless for his mates since then, spending whole day in here, drinking himself to death. Looked like he wanted to erase something from his head. Every time he got drunk, he told stories about the consumption which takes people in silence\nThat were his exact words. According to him, the 'consumption' is the worst thing that can happen to a man.";
			link.l1 = "A drunk's ramblings. What of it?";
			link.l1.go = "Consumption_6";
		break;
		
		case "Consumption_6":
			if (CheckAttribute(pchar, "questTemp.Consumption.Commandant"))
			{
				dialog.text = "Nothing, other than the fact that he found some liquid courage and started talking more and more and then just like that somebody slit his throat and tossed him in the gutter... and whoever did it and what for is all the same to me.";
				link.l1 = "What can you say about the commandant?";
				link.l1.go = "Consumption_8";
			}
			else
			{
				dialog.text = "Nothing, other than the fact that he got brave and started talking more and more and then just like that somebody slits his throat and tosses him in the gutter... and whoever did it and what for is all the same to me. (raises his voice) Yes, the bays and reefs are really dangerous here, senor. You have to be careful when the storms come crashing in from the Greater Antilles, miss the weather gage and you're gone! Have a nice rest, senor, thanks for stopping by!";
				link.l1 = "Storms... right. Thanks to you too.";
				link.l1.go = "Consumption_7";
			}
			pchar.questTemp.Consumption.Contra = "true";
		break;
		
		case "Consumption_7":
			DialogExit();
			npchar.quest.Consumption = "true";
			AddQuestRecord("Consumption", "2");
		break;
		
		case "Consumption_8":
			dialog.text = "What is there to say about him? He's a colonel, he arrived from Europe a couple of years ago having received this place. He was supposedly downgraded there in the Old World for some dirty deeds he was up to. I don't know if it's true, but there were rumors at first. But who doesn't have rumors about them, right?";
			link.l1 = "Dirty deeds, you say... That's interesting. Anything else?";
			link.l1.go = "Consumption_9";
		break;
		
		case "Consumption_9":
			dialog.text = "Well, what can I say... The colonel looks like a man who deeply cares about his own safety. Sure, these places aren't safe due to pirates, bandits, Indians and other scum, but Senor Commandant never leaves his house without several bodyguards\nThere is his mansion in this city and he has turned it into a small fortress - his servants are well-armed and keep the windows barred.";
			link.l1 = "But in the daytime he serves in the prison, doesn't he?";
			link.l1.go = "Consumption_10";
		break;
		
		case "Consumption_10":
			dialog.text = "Yes, but that mansion is basically waiting there for an ambush or an invasion. Anyway, Senor Commandant doesn't often actually return there apparently a true fortress is more his fort, he-he.";
			link.l1 = "Thank you, you've been a big help. See you later, "+npchar.name+"!";
			link.l1.go = "Consumption_11";
		break;
		
		case "Consumption_11":
			DialogExit();
			if (CheckAttribute(npchar, "quest.Consumption")) AddQuestRecord("Consumption", "4");
			else AddQuestRecord("Consumption", "5");
			DeleteAttribute(pchar, "questTemp.Consumption.Commandant");
			pchar.questTemp.Consumption = "current";
		break;
		
		case "Consumption_12":
			dialog.text = "Juan? Which one? There's a lot of them here, people usually have last names too... or at least a nickname...";
			link.l1 = "I was just thinking... Maybe his nickname is 'Consumption', ever heard that?";
			link.l1.go = "Consumption_13";
		break;
		
		case "Consumption_13":
			dialog.text = "Oh my God, you're talking about that again! No, thank God, I haven't heard. I swear! And now let's change the topic. Please!";
			link.l1 = "Fine alright, don't have a heart attack...";
			link.l1.go = "exit";
			pchar.questTemp.Consumption.AskJuan = sti(pchar.questTemp.Consumption.AskJuan)+1;
			if(sti(pchar.questTemp.Consumption.AskJuan) == 3)
			{
				pchar.quest.Consumption2.win_condition.l1 = "location";
				pchar.quest.Consumption2.win_condition.l1.location = "PortSpein_town";
				pchar.quest.Consumption2.function = "Consumption_CreateSergio";
			}
			npchar.quest.Consumption_1 = "true";
		break;
		//<-- Цена чахотки
		
		case "guardoftruth":
			dialog.text = "I remember him. Often stopped by my tavern, but didn't talk much. Had a few shots of rum, shared a whisper with some customers and left. Very gloomy and serious like everyone on that frigate. Dangerous looking mercenaries who kept their blades ready\nThere was a rumor that the frigate was full of treasure, but I don't believe in such tales. Valuable cargo is never transported on a single ship without a convoy. They spent a day here, then left. To Europe I heard. That's all I know.";
			link.l1 = "I see. Well, it's at least something...";
			link.l1.go = "exit";
			npchar.quest.guardoftruth = "true";
			AddQuestRecord("Guardoftruth", "40");
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
