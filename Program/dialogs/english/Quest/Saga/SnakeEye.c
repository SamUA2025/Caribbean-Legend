// шаман команчей Змеиный Глаз
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			if (CheckAttribute(pchar, "questTemp.Tieyasal") && pchar.questTemp.Tieyasal == "calendar")
			{
				dialog.text = "Greetings, my pale friend.";
				link.l2 = "I am glad to see you too, redskin brother. I have important business for you again.";
				link.l2.go = "calendar";
				break;
			}
			dialog.text = "Greetings, my pale friend.";
			link.l1 = "I am glad to see you too, Snake Eye.";
			link.l1.go = "exit";
			if (CheckAttribute(npchar, "quest.amulet") && CheckCharacterItem(pchar, pchar.questTemp.Saga.BaronReturn.Indian) && CheckCharacterItem(pchar, pchar.questTemp.Saga.BaronReturn.Amulet) && CheckCharacterItem(pchar, pchar.questTemp.Saga.BaronReturn.Obereg))
			{
				link.l2 = "I brought you the amulets you've asked for. Let's trade.";
				link.l2.go = "SnakeEye_potion";
			}
			if (CheckAttribute(pchar, "questTemp.LSC")) // был в LSC
			{
				if (CheckAttribute(npchar, "quest.LSC_hello") && CheckCharacterItem(pchar, "buben"))
				{
					link.l2 = "I have found your tambourine, Snake Eye. Take a look at it.";
					link.l2.go = "LSC_buben";
				}
				if (CheckAttribute(npchar, "quest.LSC_tube") && CheckCharacterItem(pchar, "smoking_tube"))
				{
					link.l2 = "I have found an interesting Indian pipe, Snake Eye. Have a look.";
					link.l2.go = "LSC_tube";
				}
				if (!CheckAttribute(npchar, "quest.LSC_hello"))
				{
					link.l2 = "Hello, shaman. I have used the statue and experienced an incredible journey. You were totally right. I found the ship's cemetery, the white captain and even the cargo hold with the supplies!";
					link.l2.go = "LSC_hello";
				}
				if (CheckAttribute(npchar, "quest.LSC_hello") && pchar.questTemp.Saga.BaronReturn == "shamane")
				{
					link.l3 = "Snake Eye, I need your help.";
					link.l3.go = "Saga_nathaniel";
				}
			}		
			NextDiag.TempNode = "First time";
		break;
		
	//---------------------------------------- первая встреча------------------------------------------------
		case "SnakeEye":
			dialog.text = "Greetings, my pale friend.";
			link.l1 = "Hello, shaman. why do you assume that I am your friend?";
			link.l1.go = "SnakeEye_1";
		break;
		
		case "SnakeEye_1":
			dialog.text = "I know a lot but I don't always know what exactly. You came here with purpose. Fate led you here and I help you.";
			link.l1 = "Good to know! I am indeed here for your help, my redskin friend. I'll be direct: what did you mean by telling Hawk's wife about Kukulcan?";
			link.l1.go = "SnakeEye_2";
		break;
		
		case "SnakeEye_2":
			dialog.text = "Even dead fish break adrift. And living man is led by fate from goal to goal. The goal of chained captain who was chased by bad people in selva was Kukulcan statue. If he sacrificed himself, he can be far away from here.";
			link.l1 = "I didn't understand a thing. What is the statue of your god about and how was Hawk able to go so far by foot that nobody can find him even now?";
			link.l1.go = "SnakeEye_3";
		break;
		
		case "SnakeEye_3":
			dialog.text = "If Kukulcan ate Hawk then it could spit him out anywhere. Perhaps even in other world. Kukulcan has eaten me three times. And each time I was in different places. Long ago I got here and decided no more risk. I did not go to Kukulcan's mouth and I do not know where he spits his victims out.";
			link.l1 = "Jesus, this is beyond my understanding! Are you telling me that the stone idol can teleport people far away?";
			link.l1.go = "SnakeEye_4";
		break;
		
		case "SnakeEye_4":
			dialog.text = "Not only that. Kukulcan rules not only space but also time. Or even more. I told chained captain about gold statue that eats people. Perhaps, he decided to risk it when he saw that chasers were close...";
			link.l1 = "Wait, the statue is made from stone. And you are talking about a golden one...";
			link.l1.go = "SnakeEye_5";
		break;
		
		case "SnakeEye_5":
			dialog.text = "At midnight idol begins life and becomes gold. In this moment Kukulcan spirit lives in it. Fear to come close to him or you can see sunrise in different place. Even stars can change their places in sky. You meet those who weren't born yet or see birth of those who died long ago or aren't born at all.";
			link.l1 = "What the... riddles and riddles again... You are intriguing me, Snake Eye. You said that you have survived three meetings with Kukulcan, the god that you believe in. So why don't I try my luck with the idol of the god I don't believe in?";
			link.l1.go = "SnakeEye_6";
		break;
		
		case "SnakeEye_6":
			dialog.text = "Pity. Pity that you don't believe. Perhaps, Kukulcan himself called you and made you leave land of your ancestors. But you don't hear him yet. Everything happens for good reason. If you decide to risk it, then you must know that I survived each time only because I had wonderful Comanche potions.";
			link.l1 = "Comanche? Is that another tribe?";
			link.l1.go = "SnakeEye_7";
		break;
		
		case "SnakeEye_7":
			dialog.text = "That is how enemies call my people who I will never see again. Potion restores strength and endurance, and also heals and saves you from strong poisons. You need several flasks but I have only three left.\nThere was four flasks but I lost one in strange place, it looks like cemetery of white men's ships. There I started my journey in this world. Perhaps Kukulcan spat captain out there. If so, I don't envy him.";
			link.l1 = "What is the place? The ship cemetery?";
			link.l1.go = "SnakeEye_8";
		break;
		
		case "SnakeEye_8":
			dialog.text = "Strange place... It should not exist but it exists. People who kill because of skin tone live there. They keep their supplies inside big ship where Kukulcan spat me out. I did not go inside its hold which they protect from thieves, they aren't trusting neighbors. If you get there - find another exit, don't go inside hold or trouble happens.\nWhite Boy helps you find another statue if he still lives. Give him this white bead. He likes them.";
			link.l1 = "Hm. My head is already spinning and this is just getting more and more interesting. Go on, redskin brother.";
			link.l1.go = "SnakeEye_9";
		break;
		
		case "SnakeEye_9":
			Log_Info("You have received a white pearl");
			PlaySound("interface\important_item.wav");
			GiveItem2Character(pchar, "jewelry52");
			dialog.text = "If you find captain alive, he might be very ill. I had no time to give him potion. Look for my tambourine there. I got it from my grandfather. There is lots of things in bag that I lost but I only need tambourine. It is difficult to talk to spirits without it.";
			link.l1 = "Well, this place sounds very interesting! Let's hope Hawk got teleported there... Will you give me your potion?";
			link.l1.go = "SnakeEye_10";
		break;
		
		case "SnakeEye_10":
			dialog.text = "I will give it to you. But, you will give me three local amulets in exchange: "+XI_ConvertString(pchar.questTemp.Saga.BaronReturn.Indian)+", "+XI_ConvertString(pchar.questTemp.Saga.BaronReturn.Amulet)+" and "+XI_ConvertString(pchar.questTemp.Saga.BaronReturn.Obereg)+". One flask for each amulet. So it is fair. Come back when you have all amulets. Then we will exchange them. Don't think that I am greedy. Or, maybe you rethink it while looking for amulets.";
			link.l1 = "I won't think that. Wait for me, Snake Eye, I'll be back soon.";
			link.l1.go = "SnakeEye_11";
		break;
		
		case "SnakeEye_11":
			DialogExit();
			NextDiag.CurrentNode = "First time";
			npchar.quest.amulet = "true";
			AddQuestRecord("BaronReturn", "3");
			AddQuestUserData("BaronReturn", "sItem1", XI_ConvertString(pchar.questTemp.Saga.BaronReturn.Indian));
			AddQuestUserData("BaronReturn", "sItem2", XI_ConvertString(pchar.questTemp.Saga.BaronReturn.Amulet));
			AddQuestUserData("BaronReturn", "sItem3", XI_ConvertString(pchar.questTemp.Saga.BaronReturn.Obereg));
			sld = characterFromId("Danielle");
			sld.quest.talk = "SnakeEye";
			pchar.quest.BaronReturn_out.win_condition.l1 = "ExitFromLocation";
			pchar.quest.BaronReturn_out.win_condition.l1.location = pchar.location;
			pchar.quest.BaronReturn_out.function = "Saga_DannyTalk";
			pchar.questTemp.HelenDrinking.GiveAmulets = true;
			
			//if (GetCharacterIndex("Longway") != -1 && CheckPassengerInCharacter(pchar, "Longway") && CheckAttribute(pchar, "questTemp.PZ_Etap4_Start"))
			if (GetCharacterIndex("Longway") != -1 && CheckPassengerInCharacter(pchar, "Longway"))	// Временно так
			{
				// Квест "Путеводная звезда", начало 4 этапа
				PChar.quest.PZ_Etap4_Start.win_condition.l1 = "location";
				PChar.quest.PZ_Etap4_Start.win_condition.l1.location = "Shore9";
				PChar.quest.PZ_Etap4_Start.win_condition = "PZ_Etap4_Start";
				locations[FindLocation("Shore9")].DisableEncounters = true;
			}
		break;
		
		// даёт зелья - идем на телепортацию
		case "SnakeEye_potion":
			dialog.text = "Good, my friend. Did you bring me amulets so you can go to Kukulcan?";
			link.l1 = "Yes. I am ready to do the same journey Nathaniel, the chained captain, did.";
			link.l1.go = "SnakeEye_potion_1";
		break;
		
		case "SnakeEye_potion_1":
			RemoveItems(pchar, pchar.questTemp.Saga.BaronReturn.Indian, 1);
			RemoveItems(pchar, pchar.questTemp.Saga.BaronReturn.Amulet, 1);
			RemoveItems(pchar, pchar.questTemp.Saga.BaronReturn.Obereg, 1);
			TakeNItems(pchar, "Ultimate_potion", 3);
			Log_Info("You have given amulets");
			Log_Info("You have received three versatile potions");
			PlaySound("interface\important_item.wav");
			dialog.text = "Take these potions. Remember that you have to drink one immediately after Kukulcan spat you out or else you die or stay very-very ill. Also remember not to go to cargo hold where palefaces keep their supplies. There is another way to leave ship. Two ways in fact. Find red woman on first night, it is very important. That is all I can say to you.";
			link.l1 = "I will remember that, redskin brother.";
			link.l1.go = "SnakeEye_potion_2";
		break;
		
		case "SnakeEye_potion_2":
			dialog.text = "Then go. Touch Kukulcan at midnight and it will eat you. I will call spirits to guide you.";
			link.l1 = "Thank you, Snake Eye. Don't worry about me, all will be going well. We will meet again!";
			link.l1.go = "SnakeEye_potion_3";
		break;
		
		case "SnakeEye_potion_3":
			DialogExit();
			NextDiag.CurrentNode = "First time";
			pchar.questTemp.Saga.BaronReturn = "first_teleport";
			pchar.questTemp.Dolly = true; // телепорты работают!
			LAi_LocationDisableOfficersGen("Pearl_jungle_03", true); // не пускать офицеров в локу телепорта
			DeleteAttribute(npchar, "quest.amulet");
			AddQuestRecord("BaronReturn", "4");
			sld = characterFromId("Danielle");
			sld.quest.talk = "teleport";
			pchar.quest.BaronReturn_out1.win_condition.l1 = "ExitFromLocation";
			pchar.quest.BaronReturn_out1.win_condition.l1.location = pchar.location;
			pchar.quest.BaronReturn_out1.function = "Saga_DannyTalk";
			QuestPointerToLoc("Pearl_Jungle_02", "reload", "reload1_back");
			QuestPointerToLoc("Pearl_Jungle_03", "camera", "dolly");
		break;
		
		// пришёл из LSC
		case "LSC_hello":
			dialog.text = "I am glad to see you, my friend. How did you return from ship cemetery?";
			link.l1 = "I've found the statue of Kukulcan there, just like you told me. White Boy has helped me - Ole Christiansen. The statue was sunk in the sea but I was able to reach it. It teleported me to an Indian village on Dominica.";
			link.l1.go = "LSC_hello_1";
			npchar.quest.LSC_hello = "true";
		break;
		
		case "LSC_hello_1":
			dialog.text = "Did Monkitekuvri meet you there?";
			link.l1 = "Hm. Monkitekuvri? Who is that?";
			link.l1.go = "LSC_hello_2";
		break;
		
		case "LSC_hello_2":
			dialog.text = "He is village chief.";
			link.l1 = "I didn't ask for his name. Perhaps he was Monkitekuvri, perhaps not.";
			link.l1.go = "LSC_hello_3";
		break;
		
		case "LSC_hello_3":
			dialog.text = "Did he have pompous headdress made of bird feathers on his head?";
			link.l1 = "Sure, he had. A lot of feathers... It seems that he plucked all parrots in the jungle.";
			link.l1.go = "LSC_hello_4";
		break;
		
		case "LSC_hello_4":
			dialog.text = "He is called Monkitekuvri. They aren't parrot feathers but eagle feathers. This headdress is my headdress. I presented it to Monkitekuvri when Kukulcan spat me back out. Then they took me to another statue...";
			link.l1 = "Isn't that something! They have also 'sacrificed me' to Kukulcan! And I have found myself here, near the first statue.";
			link.l1.go = "LSC_hello_5";
		break;
		
		case "LSC_hello_5":
			dialog.text = "Yes, my pale friend. My journey ended here too.";
			link.l1 = "The idols teleport in a circle... But what is the point of that? Have you got any ideas, Snake Eye?";
			link.l1.go = "LSC_hello_6";
		break;
		
		case "LSC_hello_6":
			dialog.text = "I suppose that statues don't work right. At the moment, they move people around but they should move them to one place. Something about them is broken.";
			link.l1 = "What makes you think this way?";
			link.l1.go = "LSC_hello_7";
		break;
		
		case "LSC_hello_7":
			dialog.text = "Because teleportation in circle has no point. Kukulcan must take all victims to one place and not move them around.";
			link.l1 = "And where could that one place be?";
			link.l1.go = "LSC_hello_8";
		break;
		
		case "LSC_hello_8":
			dialog.text = "This is great secret, white brother, even for me.";
			link.l1 = "I see. Fine, to hell with the idols. I won't ever come close to them again. I have found the chained captain, there is no need to travel trough the portals anymore.";
			link.l1.go = "LSC_hello_9";
			AddQuestRecord("BaronReturn", "12");
		break;
		
		case "LSC_hello_9":
			dialog.text = "When you were at ship cemetery. Did you find there my tambourine?";
			if (CheckCharacterItem(pchar, "buben"))
			{
				link.l1 = "I think so. Take a look.";
				link.l1.go = "LSC_buben";
			}
			else
			{
				link.l1 = "No. Unfortunately I haven't found it. But I know where the island is and I can reach it. I will look for your tambourine.";
				link.l1.go = "LSC_hello_10";
			}
		break;
		
		case "LSC_hello_10":
			dialog.text = "Look for it, my pale friend. I very much ask you. Without my tambourine I don't hear spirits well.";
			link.l1 = "All right, Snake Eye. See you!";
			link.l1.go = "exit";
		break;
		
		case "LSC_buben":
			RemoveItems(pchar, "buben", 1);
			PlaySound("interface\important_item.wav");
			dialog.text = "That's my tambourine. Thank you, my pale friend. I can repay you. I present to you this weapon, which your people will not have for a long time from now. This weapon is weapon of palefaces of my time.";
			link.l1 = "Interesting! Show it to me, redskin friend...";
			link.l1.go = "LSC_buben_1";
		break;
		
		case "LSC_buben_1":
			GiveItem2Character(pchar, "pistol7");
			Log_Info("You have received a Colt revolver");
			PlaySound("interface\important_item.wav");
			TakeNItems(pchar, "shotgun_cartridge", 3);
			TakeNItems(pchar, "GunCap_colt", 3);
			dialog.text = "Take it. There are only three charges in it, the rest I used. But perhaps you will learn to make charge for it. I lost few dozens of parts for charges at ship cemetery, you can find them there.";
			link.l1 = "Oho! That's a pistol! I've never seen anything like this before... what an odd machine? Some turning mechanism... five charges! Nice!";
			link.l1.go = "LSC_buben_2";
		break;
		
		case "LSC_buben_2":
			dialog.text = "It's called Colt revolver. No other pistol like this one in your time. Easy to use, raise the cock and pull trigger. It shoots good.";
			link.l1 = "Thank you! Thank you, Snake Eye! It will be a nice surprise for my enemies... Pity that there are only three charges...";
			link.l1.go = "LSC_buben_3";
		break;
		
		case "LSC_buben_3":
			dialog.text = "Try to teach yourself how to make charges for Colt revolver. Then you will be great warrior of your time. Ah, my pale brother, I forgot to ask you to find my pipe at ship cemetery. It was very pretty pipe.";
			if (CheckCharacterItem(pchar, "smoking_tube"))
			{
				link.l1 = "Ha! And, I have been thinking whose painted pipe this could be? Take a look.";
				link.l1.go = "LSC_tube";
			}
			else
			{
				link.l1 = "Fine. I will look for your pipe as well. See you!";
				link.l1.go = "exit";
			}
			npchar.quest.LSC_tube = "true";
		break;
		
		case "LSC_tube":
			RemoveItems(pchar, "smoking_tube", 1);
			PlaySound("interface\important_item.wav");
			dialog.text = "This is my pipe, my brother. I am glad you found it. And I can give you another present for it. This is clever book of palefaces from my time. I can't understand it. Try to find clever man who can read and understand this book.";
			link.l1 = "Thank you, Snake Eye. I think I know somebody who will be interested in this.";
			link.l1.go = "LSC_tube_1";
		break;
		
		case "LSC_tube_1":
			GiveItem2Character(pchar, "chemistry");
			Log_Info("You have received a Lavoisier's chemistry textbook");
			PlaySound("interface\important_item.wav");
			dialog.text = "Give it to him, white brother. This book has great secrets of paleface wisdom.";
			link.l1 = "Good. See you, Snake Eye!";
			link.l1.go = "exit";
		break;
		
		// лечение Натаниэля
		case "Saga_nathaniel":
			dialog.text = "I am listening to you, paleface brother.";
			link.l1 = "I have brought the chained captain, who I was looking for at the ship cemetry, with me. He is very ill. I know that only you can heal him...";
			link.l1.go = "Saga_nathaniel_1";
		break;
		
		case "Saga_nathaniel_1":
			dialog.text = "Kukulcan consumed his health. I think I can help him heal. But it takes no less than one full moon. Kukulcan ate captain long ago and illness spread deep inside him.";
			link.l1 = "Please heal him, shaman! I will bring you whatever you need!";
			link.l1.go = "Saga_nathaniel_2";
		break;
		
		case "Saga_nathaniel_2":
			dialog.text = "I will try, white brother. You don't have to bring me anything. I have everything. Time makes illness stronger but chained captain will be healthy again in one moon.";
			link.l1 = "Thank you, redskin brother. You are again my lifesaver.";
			link.l1.go = "Saga_nathaniel_3";
		break;
		
		case "Saga_nathaniel_3":
			dialog.text = "Leave chained captain at my hut, white brother, and walk without worry. Take his wife too, no one can see my rites.";
			link.l1 = "Fine, Snake Eye. I will take Danielle with me. See you!";
			link.l1.go = "Saga_nathaniel_4";
		break;
		
		case "Saga_nathaniel_4":
			DialogExit();
			pchar.questTemp.Saga.BaronReturn = "treatment";
			sld = characterFromId("Nathaniel");
			RemovePassenger(Pchar, sld);
			LAi_SetStayType(sld);
			sld.location = "none";
			pchar.quest.Saga_NatanTreatment1.win_condition.l1 = "ExitFromLocation";
			pchar.quest.Saga_NatanTreatment1.win_condition.l1.location = pchar.location;
			pchar.quest.Saga_NatanTreatment1.function = "Saga_NatanTreatment";
		break;
		
		case "calendar":
			dialog.text = "I listen, my friend.";
			link.l1 = "Remember our talk about the Kukulcan statues? You said 'they should move people to one special place'.";
			link.l1.go = "calendar_1";
		break;
		
		case "calendar_1":
			dialog.text = "I remember, white captain.";
			link.l1 = "I know where those statues must have moved the people who were eaten by Kukulcan.";
			link.l1.go = "calendar_2";
		break;
		
		case "calendar_2":
			dialog.text = "Where?";
			link.l1 = "To the old Maya city Tayasal. It is located deep in the jungle of Main.";
			link.l1.go = "calendar_3";
		break;
		
		case "calendar_3":
			dialog.text = "Very interesting. How do you know this?";
			link.l1 = "It's a long story, Snake Eye. I also understand how you got here. You are not even born yet, right?";
			link.l1.go = "calendar_4";
		break;
		
		case "calendar_4":
			dialog.text = "Even my father is not born in your time. But I live in your time and that is great mystery.";
			link.l1 = "It's actually explainable. An Itza priest named Kanek, who is living in Tayasal, called upon Kukulcan to be born as a mortal in this world and to absorb wisdom of the white race. He also created a time hole which teleported a few men from the future into our time...";
			link.l1.go = "calendar_5";
		break;
		
		case "calendar_5":
			dialog.text = "To let Kukulcan absorb wisdom of future people?";
			link.l1 = "Yes. And Kukulcan plans to go into the past to deliver the knowledge to the Mayan people who died long ago. History will be changed and the Maya will rule over America and maybe even more...";
			link.l1.go = "calendar_6";
		break;
		
		case "calendar_6":
			dialog.text = "";
			link.l1 = "But something has happened to the portals and they started teleporting people in a circle instead of Tayasal. And that is why I am here, I need your advice, Snake Eye.";
			link.l1.go = "calendar_7";
		break;
		
		case "calendar_7":
			dialog.text = "Why me, white captain?";
			link.l1 = "Because you have been eaten by Kukulcan. And because the Kukulcan statue near your village has a strange mark on this map, which is strongly connected to Kanek's rites.";
			link.l1.go = "calendar_8";
		break;
		
		case "calendar_8":
			dialog.text = "Show me this map?";
			link.l1 = "Here, take a look...";
			link.l1.go = "calendar_9";
		break;
		
		case "calendar_9":
			RemoveItems(pchar, "skinmap", 1);
			dialog.text = "(looking) This round sign, yes? And what it means?";
			link.l1 = "I don't know, shaman. I know that only one of the three Kukulcan statues has this mark. And that the statue with the mark is yours. I draw the conclusion that your statue is a special one. Got any ideas?";
			link.l1.go = "calendar_10";
		break;
		
		case "calendar_10":
			dialog.text = "Give me time until tomorrow morning, white brother. Leave me this leather map. I need to ask spirits. Come back tomorrow.";
			link.l1 = "Fine, redskin brother. I will be here tomorrow. Thank you for helping me.";
			link.l1.go = "calendar_11";
		break;
		
		case "calendar_11":
			DialogExit();
			SetFunctionTimerCondition("Tieyasal_CalendarThink", 0, 0, 1, false);
			pchar.questTemp.Tieyasal = "calendar_think";
			NextDiag.CurrentNode = "calendar_wait";
		break;
		
		case "calendar_wait":
			dialog.text = "Come later, white brother. Don't bother me now.";
			link.l1 = "Sure, shaman...";
			link.l1.go = "exit";
			NextDiag.TempNode = "calendar_wait";
		break;
		
		case "calendar_12":
			dialog.text = "I have something to tell you, white brother.";
			link.l1 = "Did you find anything? Or have you got a guess?";
			link.l1.go = "calendar_13";
		break;
		
		case "calendar_13":
			dialog.text = "Ancestor spirits gave me vision and I went to Kukulcan with map. I searched and found. It must be what you look for, white brother.";
			link.l1 = "What did you find?";
			link.l1.go = "calendar_14";
		break;
		
		case "calendar_14":
			dialog.text = "Kukulcan statue has two iron clamps and recess. Recess has round, smooth form. It orients to the round and flat item from your leather map.";
			link.l1 = "What is it?";
			link.l1.go = "calendar_15";
		break;
		
		case "calendar_15":
			dialog.text = "I don't know. I only know that it is round, flat, with size like small pumpkin and maybe thick like a finger. You can go and look at recess and clamps for yourself. Clamp needs to hold it.";
			link.l1 = "Do you have any idea? Or a guess what it might be?";
			link.l1.go = "calendar_16";
		break;
		
		case "calendar_16":
			dialog.text = "Stone has a trace of fire. I know what happened to it. Sky flame hit it.";
			link.l1 = "Lightning? Did lightning hit it?";
			link.l1.go = "calendar_17";
		break;
		
		case "calendar_17":
			dialog.text = "I am sure of that. I asked Miskito about this idol. One warrior said that long ago few pretty painted things were seen at statue. Very similar to rocks. He told me that they were very pretty red rocks. One white man from white village bought them.";
			link.l1 = "Hm. As far as I understand, it seems that lightning hit this round 'something', broke it into pieces and then these pieces were sold to some white guy?";
			link.l1.go = "calendar_18";
		break;
		
		case "calendar_18":
			dialog.text = "It seems so.";
			link.l1 = "And who was that white man? Did your warrior tell you?";
			link.l1.go = "calendar_19";
		break;
		
		case "calendar_19":
			dialog.text = "He told me. He was big friend of Miskito and he lives in Blueweld village. His name is Forest Devil. I know him, you must know him too.";
			link.l1 = "Jan Svenson? Wait a second... red painted rocks, you say? It looks like I just got very lucky. Look here, shaman, look at these red rocks I have! The Forest Devil gifted them to me.";
			link.l1.go = "calendar_20";
		break;
		
		case "calendar_20":
			Log_Info("You have given ornamental pattern fragments");
			RemoveItems(pchar, "splinter_js", 1);
			RemoveItems(pchar, "splinter_nh", 1);
			RemoveItems(pchar, "splinter_mt", 1);
			RemoveItems(pchar, "splinter_zm", 1);
			RemoveItems(pchar, "splinter_jb", 1);
			dialog.text = "It must be them. Five rocks. Take a look, white brother. If you place them like that... (putting together)";
			link.l1 = "...";
			link.l1.go = "calendar_21";
		break;
		
		case "calendar_21":
			dialog.text = "... then we have round item. Look! They match. It used to be one item before.";
			link.l1 = "Damn it! And these things have been in my pocket for so long... Listen, shaman, if I put the shards into the recess...";
			link.l1.go = "calendar_22";
		break;
		
		case "calendar_22":
			dialog.text = "Kukulcan will spit out the victim at old Indian city as you said.";
			link.l1 = "That would be great! I need to get there! Do you think the ornament will work, if it has been broken into shards?";
			link.l1.go = "calendar_23";
		break;
		
		case "calendar_23":
			dialog.text = "I think that we need to bring them together and then put ornament into recess.";
			link.l1 = "Bring them together? But how can we put them back together?";
			link.l1.go = "calendar_24";
		break;
		
		case "calendar_24":
			dialog.text = "Leave it to me and ancestor spirits, white brother. They are not simple rocks. It's miracle item. Come back in three nights, white brother. I call spirits, wisdom and skill of living and I try to unite shards.";
			link.l1 = "Incredible... How can I ever repay you, Snake Eye?";
			link.l1.go = "calendar_25";
		break;
		
		case "calendar_25":
			dialog.text = "Thank me later, white brother. Go now. Come back in three nights.";
			link.l1 = "Fine. I hope that you will succeed...";
			link.l1.go = "calendar_26";
		break;
		
		case "calendar_26":
			DialogExit();
			SetFunctionTimerCondition("Tieyasal_CalendarDone", 0, 0, 3, false);
			NextDiag.CurrentNode = "calendar_wait";
		break;
		
		case "calendar_28":
			dialog.text = "I can make you happy, white brother.";
			link.l1 = "Were you able to unite the shards?";
			link.l1.go = "calendar_29";
		break;
		
		case "calendar_29":
			dialog.text = "Yes. It was not easy and there are scars left on the calendar but it is complete now.";
			link.l1 = "Calendar? Why did you call it that?";
			link.l1.go = "calendar_30";
		break;
		
		case "calendar_30":
			dialog.text = "Because this round thing is calendar. I studied it carefully. There is time count on it. Indians from ancient city count nights, moons, years and ages.";
			link.l1 = "Incredible... Though, thinking about what Maya priests are able to do - the creation of this calendar doesn't seem to be anything special.";
			link.l1.go = "calendar_31";
		break;
		
		case "calendar_31":
			GiveItem2Character(pchar, "calendar_maya");
			sld = ItemsFromID("calendar_maya");
			sld.shown = "0";
			Log_Info("You have received a Maya calendar");
			dialog.text = "Take it, white captain. Put it into recess on statue. Then perhaps it will spit you out in Indian city.";
			link.l1 = "How can I repay you, Snake Eye?";
			link.l1.go = "calendar_32";
		break;
		
		case "calendar_32":
			dialog.text = "Say 'Thank you'. Gods guide you on your path even if you do not see it. White people say - fate. Kukulcan called you, gods guide you. Go now. Do your work and let good spirits guide you.";
			link.l1 = "Thank you, Snake Eye! I will never forget you.";
			link.l1.go = "calendar_33";
		break;
		
		case "calendar_33":
			TakeNItems(pchar, "Ultimate_potion", 4);
			Log_Info("You have received four versatile potions");
			PlaySound("interface\important_item.wav");
			dialog.text = "Wait. We almost forgot most important thing. Kukulcan eats man and consumes his life. I made you potions. Comanche potions. I give them to you. I made four flasks, so you can take three loyal and brave companions with you.";
			link.l1 = "You have done so much for me, redskin brother...";
			link.l1.go = "calendar_34";
		break;
		
		case "calendar_34":
			dialog.text = "Brother is not just word for Indians of Comanche tribe. When back from Kukulcan city, visit our village. We cook lots, lots of saraiaka. I will be glad to see you.";
			link.l1 = "Sure, redskin brother! I will certainly visit you!";
			link.l1.go = "calendar_35";
		break;
		
		case "calendar_35":
			DialogExit();
			pchar.questTemp.Tieyasal = "calendar_place";
			NextDiag.CurrentNode = "First time";
			AddQuestRecord("Tieyasal", "17");
			sld = ItemsFromID("skinmap");
			sld.price = 100; // кожаную карту можно выкладывать 270912 
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}
