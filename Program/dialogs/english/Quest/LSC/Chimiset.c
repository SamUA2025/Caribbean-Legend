// колдун ривадос - Чимисет
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
	int i;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			dialog.text = "Want something?";
			link.l1 = "No, nevermind.";
			link.l1.go = "exit";			
			NextDiag.TempNode = "First time";
		break;
		
		//-------------------------------------в тюрьме на Тартарусе-----------------------------
		// вариант R
		case "KillChad":
			dialog.text = "Wait! Stop... I beg you to listen to me before you make a mistake.";
			link.l1 = "I am listening... I hope that you have a reasonable argument to stop me from...";
			link.l1.go = "KillChad_1";
			LAi_RemoveCheckMinHP(npchar); //убираем проверяльщик, если еще есть
		break;
		
		case "KillChad_1":
			dialog.text = "From killing me, right? I have heard you talking with Chad upstairs and I don't blame you - anyone would likely do the same. But you are wrong to think that Chad will let you go after killing me.";
			link.l1 = "Hm... Interesting, and why won't he? The only thing I know is that I will have to break a sweat to get out of here, if I don't simply kill you.";
			link.l1.go = "KillChad_2";
		break;
		
		case "KillChad_2":
			dialog.text = "You won't have any future at all if you kill me. Listen, Narwhals and Chad are willing to get rid of me, but they are too scared of me to do this themselves - my killer will be cursed forever. So they want you to do all the dirty work\nChad is aware that you are not Rivados, he is screwing you. Once you kill me - they will do the same thing to you and use your corpse to fool Shark.";
			link.l1 = "Shark? Steve Dodson? Is he actually here? And explain to me at last - who the hell are those Rivados?";
			link.l1.go = "KillChad_3";
		break;
		
		case "KillChad_3":
			dialog.text = "Heh, it looks like you don't live here, indeed... But it is not the right time for telling stories. We have to save ourselves. I have a plan.";
			link.l1 = "You know what, wizard, I have recently made a trip through some mystical portal and barely survived it, so your curses don't scare me. I have had enough - it's time to finish you off.";
			link.l1.go = "KillChad_fightfail";
			link.l2 = "Fine, I trust you. What is the plan?";
			link.l2.go = "KillChad_4";
		break;
		
		case "KillChad_fightfail":
			DialogExit();
			AddDialogExitQuest("MainHeroFightModeOn");
			LAi_SetActorType(npchar);
			LAi_ActorAnimation(npchar, "afraid", "", -1);
			LAi_SetImmortal(npchar, false);
			pchar.quest.LSC_fightfail.win_condition.l1 = "NPC_Death";
			pchar.quest.LSC_fightfail.win_condition.l1.character = "Chimiset";
			pchar.quest.LSC_fightfail.function = "LSC_Fightfail_Final";
		break;
		
		case "KillChad_4":
			dialog.text = "There is a chest over there. It contains decent weapons and potions. It is locked, but the lock is old and damaged, so find a crowbar to break it\nTake everything from the chest, arm yourself and go to the stairs. It is a good defensive position, they will be forced to fight you one by one, just watch out for the musketeers\nI hope that you are good with a blade, I am too old to help you fight. If you will manage to kill them all and survive in the process - I guarantee you the protection of Rivados, my family...";
			link.l1 = "Good. Pray to your gods for me - the fight is going to be tough. Those lads upstairs look really serious.";
			link.l1.go = "KillChad_5";
		break;
		
		case "KillChad_5":
			DialogExit();
			pchar.quest.LSC_fightfail.over = "yes"; //снять прерывание
			LAi_SetImmortal(npchar, true);
			ref location = &Locations[FindLocation(pchar.location)];
			location.private1.key = "crowbar";
			location.private1.key.delItem = true;
			NextDiag.CurrentNode = "KillChad_6";
		break;
		
		case "KillChad_6":
			dialog.text = "Don't waste time! Force the lock quickly...";
			link.l1 = "Yes, yes, I am on my way.";
			link.l1.go = "exit";
			NextDiag.TempNode = "KillChad_6";
		break;
		
		case "Chad_die":
			dialog.text = "Well done! You are really the master of fencing. I owe you, stranger. Tell me, what is your name?";
			link.l1 = ""+pchar.name+". "+GetFullName(pchar)+". And what's yours?";
			link.l1.go = "Chad_die_1";
		break;
		
		case "Chad_die_1":
			dialog.text = "My name is Chimiset, I am a Rivados shaman and advisor of our chief - Black Eddie. He will be glad to know that you had set me free and saved my life. You are a friend of Chimiset, Black Eddie and all Rivados. From now on you will always be a welcome guest on our Protector...";
			link.l1 = "Wait... Chimiset, in case you still didn't understand, it has been only a few hours since I got here. Can you explain me where I am, who the Rivados are, and where I can find Shark Dodson?";
			link.l1.go = "Chad_die_2";
		break;
		
		case "Chad_die_2":
			dialog.text = "This place is called the City of Abandoned Ships. Though it sounds more like mockery. It is not much of a city. This place is an island formed out of hundreds of dead ships. The center is suitable for dwelling space. It is inhabited by people who survived the inexplicable shipwrecks caused by storms that led them here\nRivados is a clan, a group of people who have been living together for a long time. There are also three other groups living here: the Narwhal clan, they are enemies of ours, pirates of Shark Dodson and common people. Shark is basically head of the island, he calls himself an admiral\nHe has arrived quite recently and seized power in a violent manner. He captured the 'San Augustine' where we were storing our food supplies. Now we have to buy provisions at the prices named by Shark. It seems, that you have already been in that warehouse\nChad Kapper was Shark's boatswain and a head of the prison. Layton Dexter used to be Shark's first mate, he has some influence too. These three and their pirates are a dominating force across the island facing both Rivados and Narwhals.";
			link.l1 = "Why did Chad Kapper want me to kill you?";
			link.l1.go = "Chad_die_3";
		break;
		
		case "Chad_die_3":
			dialog.text = "Chad had established contacts with Narwhals, our enemies. He was going to kill Shark with their help and take his place. Narwhals hold a grudge against the admiral for the death of Alan Milrow, their ex leader. They believe that Shark is responsible for his death, but they are wrong. I know who did it. Chad did. I am the only witness of this crime\nThat is why Chad couldn't let me go free, yet he feared to harm me too. Pirates are fearless in battles, but they are highly superstitious. So he wanted to use you. Chad and Narwhals would have Shark killed and blamed Rivados.";
			link.l1 = "Is that so? Tell me why...";
			link.l1.go = "Chad_die_4";
		break;
		
		case "Chad_die_4":
			dialog.text = ""+pchar.name+", my friend, let's talk later. We have to hurry, before Shark's pirates will show up. Search Chad's body and take his keys. But first, check his desk, he might have interesting papers there\nGo to Shark Dodson, you will find him in the 'San Augustine', a large ship, crashed at a distance from the others, there is a bridge leading to her from the ship named 'Pluto'. Tell him that Chad was plotting a betrayal, and say that Narwhals are behind all this, and we, Rivados, have nothing to do with it.\nI will gladly give you any information you need about this island, about my clan and others, once you arrive to our residence in the Protector. Let's get out of here!";
			link.l1 = "Fine, Chimiset. I will find you later at the... 'Protector'. Let's get out of here!";
			link.l1.go = "Chad_die_5";
		break;
		
		case "Chad_die_5":
			dialog.text = "One more thing. Our ships, including the 'Protector', are restricted to strangers. You must be Rivados or know a password in order to enter. I would tell you, but it changes every week and I've been here for too long, so I don't know the active password\n You should visit the 'San Augustine' first. I will tell our people who you are, while you are talking to Shark, they will expect you. But don't go to the 'Protector' now, first, talk to Shark, and let me meet my people first, otherwise Rivados will be hostile towards you";
			link.l1 = "I see. I am heading to 'San Augustine'. See you!";
			link.l1.go = "Chad_die_6";
		break;
		
		case "Chad_die_6":
			DialogExit();
			DeleteAttribute(pchar, "GenQuest.Notsearchbody");
			LAi_SetActorType(npchar);
			LAi_ActorFollow(npchar, pchar, "", -1);
			pchar.quest.LSC_LetterChad.win_condition.l1 = "item";
			pchar.quest.LSC_LetterChad.win_condition.l1.item = "letter_chad";
			pchar.quest.LSC_LetterChad.function = "LSC_LetterChad_Find";
			sld = characterFromId("SharkMush_17");
			sld.lifeday = 0;
			for (i=1; i<=2; i++)
			{
				sld = characterFromId("SharkSold_1"+(i+3));
				sld.lifeday = 0;
			}
			AddSimpleRumourCityTip("Ha, they say that you are a friend of clan Rivados. This is interesting. Congratulations...", "LostShipsCity", 5, 1, "LSC", "");
			AddSimpleRumourCityTip("They say that you have saved the Rivados wizard Chimiset from 'Tartarus'. Now you are a welcome guest on their ships.", "LostShipsCity", 5, 1, "LSC", "");
			AddSimpleRumourCityTip("So it was you who has set Chimiset free! Interesting. Now you are a friend of Rivados but an enemy of Narwhals. I am not sure whether to congratulate you or to sympathize...", "LostShipsCity", 5, 1, "LSC", "");
		break;
		
		// вариант N
		case "prisoner":
			dialog.text = "What do you want from me, stranger?";
			link.l1 = "Your name is Chimiset, right?";
			link.l1.go = "prisoner_1";
		break;
		
		case "prisoner_1":
			dialog.text = "Yes, it's me. Do you have business with me or you just want to talk?";
			link.l1 = "I have some business to discuss. I came here from the Admiral, Shark Dodson. I have brought an order to set you free, but on one condition: you must answer several of my questions.";
			link.l1.go = "prisoner_2";
		break;
		
		case "prisoner_2":
			dialog.text = "Has Dodson decided to release me? I am glad to hear that. Ask your questions. I hope that there is no trickery in it, otherwise my excitement will have been in vain.";
			link.l1 = "No tricks, I only need your help. Tell me, Chimiset, is there a strange stone idol on this island? It turns to gold at midnight. Do not think me crazy...";
			link.l1.go = "Friend_2";
		break;
		
		case "prisoner_3":
			dialog.text = "Any more questions?";
			link.l1 = "Yes. Do you know a man called the White Boy?";
			link.l1.go = "prisoner_4";
		break;
		
		case "prisoner_4":
			dialog.text = "White boy? Sure, I know him. This is the nickname of Olle Christiansen, our local idiot. He is an adult now and doesn't look like a boy anymore, though his mind is still childish.";
			link.l1 = "Is that so? Tell me, where can I find him?";
			link.l1.go = "prisoner_5";
		break;
		
		case "prisoner_5":
			dialog.text = "Anywhere in our city. He often could be found in the shop, tavern or walking in the streets. He has white hair, you will recognize him.";
			link.l1 = "Excellent! One more question: have you met here a man by the name of Nathaniel Hawk? He must have shown up here some time ago, and he might be seriously ill.";
			link.l1.go = "prisoner_6";
		break;
		
		case "prisoner_6":
			dialog.text = "I can't help you with that, stranger. I don't know a man with such a name. I can assure you that he is not on Rivados' ships, neither should he be in the neutral area. I can't say the same about Narwhals' territories, though, Rivados don't visit them.";
			link.l1 = "Well, thanks anyway... You have helped me a lot, Chimiset!";
			link.l1.go = "prisoner_7";
		break;
		
		case "prisoner_7":
			dialog.text = "That's it? Will Shark set me free now?";
			link.l1 = "Yes. I have nothing else to ask you. Chad Kapper will free you. Well, I have to go...";
			link.l1.go = "prisoner_8";
		break;
		
		case "prisoner_8":
			dialog.text = "Stop! Wait... Come back.";
			link.l1 = "Got anything more to tell me?";
			link.l1.go = "prisoner_9";
		break;
		
		case "prisoner_9":
			dialog.text = "Not exactly... (lowering voice) I see that you are not one of Kapper's men. Do not trust him. He is a filthy scum. Not long ago, he dispassionately killed unarmed Alan Milrow with a broadsword. He was leader of the Narwhal clan. I didn't see it coming, Chad just came close to his cell and executed him\Also, I have heard some rumours that Admiral's own men plan to assassinate him. Tell Shark about it. And tell him that I will say more when we talk face to face.";
			link.l1 = "Hm. Fine, I will tell Dodson about it. See you!";
			link.l1.go = "prisoner_10";
		break;
		
		case "prisoner_10":
			DialogExit();
			sld = characterFromId("Capper");
			sld.quest.chimiset_talk = "true"; // разговор с Чимисетом состоялся
			if (!CheckAttribute(npchar, "quest.capper_talk")) chrDisableReloadToLocation = true;//закрыть локацию
			else chrDisableReloadToLocation = false;//открыть локацию
			sld = characterFromId("Dodson");
			sld.dialog.currentnode = "entrance_10"; // ноду Акуле
			LSC_SetWhiteBoy(); // поставим белого мальчика
			NextDiag.CurrentNode = "prisoner_11";
			AddQuestRecord("SharkHunt", "20");
		break;
		
		case "prisoner_11":
			dialog.text = "Go to Shark and tell him everything I've told you. Eh, I hope they open this cage soon...";
			link.l1 = "Yeah, yeah. I am on my way.";
			link.l1.go = "exit";
			NextDiag.TempNode = "prisoner_11";
		break;
		
		//------------------------беседа на Протекторе, если был старт через Тартарус-----------------
		case "Friend":
			dialog.text = "There you are, my dear friend. Thanks again for saving me and trusting me, instead of Kapper. I will give you these amulets to reward you. I am sure that you'll find them useful.";
			link.l1 = "Thank you! I didn't expect that...";
			link.l1.go = "Friend_1";
		break;
		
		case "Friend_1":
			GiveItem2Character(pchar, "indian_1");
			GiveItem2Character(pchar, "indian_11");
			GiveItem2Character(pchar, "amulet_1");
			PlaySound("interface\important_item.wav");
			dialog.text = "And now I am ready to listen to you. You wanted to ask me something, am I right?";
			link.l1 = "You are right, Chimiset. I need your help. First, I need to know, is there a strange stone idol on this island? It turns into gold at midnight. Do  not think me crazy...";
			link.l1.go = "Friend_2";
		break;
		
		// нода пересечения
		case "Friend_2":
			dialog.text = "Aye, I see what you mean, my friend. I have seen this statue of Indian gods with my very eyes. Though it turns gold only under the beams of morning sun, and not the moon... many times we had sacrificed wicked Narwhals and the god devoured all of them. But it isn't on the Island anymore.";
			link.l1 = "How isn't it?! Are you saying that it disappeared all of a sudden?!";
			link.l1.go = "Friend_3";
		break;
		
		case "Friend_3":
			dialog.text = "Not exactly like that. This statue was inside the 'San Geronimo'. This ship sunk with the statue several years ago.";
			link.l1 = "Such bad luck! Seems that it is impossible to leave the island now... And where was that ship?";
			link.l1.go = "Friend_4";
		break;
		
		case "Friend_4":
			dialog.text = "Not far from the Narwhal territories, near the wrecks of the ship named 'Phoenix'. You can see the ship resting on the seabed on a good day.";
			link.l1 = "Ha! So is it lying at the shoal? I can swim to it, then...";
			link.l1.go = "Friend_5";
		break;
		
		case "Friend_5":
			dialog.text = "You can't, my friend. First, it's too deep down there; second, there are many giant crabs. They will tear you apart before you get to the 'San Geronimo'.";
			link.l1 = "Hm. Fine, I'll think about it. At least, I know that the statue exists, and that is the most important thing.";
			if (CheckAttribute(npchar, "quest.chimiset_die")) link.l1.go = "prisoner_3";
			else
			{	
				if (CheckAttribute(pchar, "questTemp.LSC.Mary")) link.l1.go = "freedom_1";
				else link.l1.go = "Friend_6";
			}
			AddQuestRecord("LSC", "4");
		break;
		// нода пересечения
		
		case "Friend_6":
			dialog.text = "I see that you have more questions. Feel free to ask, my friend.";
			link.l1 = "Shark Dodson asked me to find Chad's accomplices in crime. I have found a letter in Chad's chest. There is something about some sniper and a gun. It looks like they want to assassinate Shark from a distance. Do you have anything in mind?";
			link.l1.go = "Friend_7";
		break;
		
		case "Friend_7":
			dialog.text = "Hm. They are going to shoot the admiral? I need to think... Thing is, the admiral almost never leaves his residence, and when he does, he is protected by half a dozen pirates. But he has one habit, he likes to walk around the stern late in the evenings\nThere are two positions for a sniper to shoot into the Admiral's residence - bow of the 'Santa Florentina' and a mast of the 'Fury'. But a sniper still won't be able to kill the Admiral from those positions, he must be an eagle-eyed marksman to take such a shot. Also, he would need an excellent rifle. You should ask around the island about people who have access to such firearms.";
			link.l1 = "Heh, it looks like you are right, there is something about a gun in the letter... Have you seen anyone with such a gun?";
			link.l1.go = "Friend_8";
		break;
		
		case "Friend_8":
			dialog.text = "No. I haven't even seen a gun like that in my life. Ask people, perhaps, someone might tell you.";
			link.l1 = "Fine... Anyway, your information is valuable, thank you! Well, the last question now, though I don't expect you to answer... Have you heard about the White Boy?";
			link.l1.go = "Friend_9";
		break;
		
		case "Friend_9":
			dialog.text = "White boy? Sure, I know him. This is the nickname of Olle Christiansen, our local idiot. He is an adult now and he doesn't look like a boy anymore, though his mind is still childish.";
			link.l1 = "Is that so? Tell me where can I find him?";
			link.l1.go = "Friend_10";
		break;
		
		case "Friend_10":
			dialog.text = "Anywhere in our city. He can often be found in the shop, tavern or in the streets. He has white hair - you will surely recognize him.";
			link.l1 = "Great! Thanks, Chimiset, you have helped me a lot!";
			link.l1.go = "Friend_11";
		break;
		
		case "Friend_11":
			dialog.text = "I am always glad to help! Come and see me if you'll have more questions.";
			link.l1 = "Sure! I have to go now. See you!";
			if (CheckAttribute(pchar, "questTemp.LSC.Mary")) link.l1.go = "freedom_2";
			else link.l1.go = "Friend_12";
		break;
		
		case "Friend_12":
			DialogExit();
			NextDiag.CurrentNode = "Chimiset_wait";
			LSC_SetWhiteBoy(); // ставим Белого Мальчика в магазин
			pchar.questTemp.Saga.SharkHunt = "search_mush_1"; // флаг на магазин - поиск мушкета
			AddQuestRecord("SharkHunt", "11");
		break;
		
		case "freedom":
			dialog.text = "And there is my dear friend whom I owe my freedom and even my life, perhaps. Thank you for helping my brothers to save me from that filthy Kapper. I will give you these amulets to reward you. I am sure that you'll find them useful.";
			link.l1 = "Thank you! I didn't expect that...";
			link.l1.go = "Friend_1";
		break;
		
		case "freedom_1":
			dialog.text = "Have you got anything else to ask, white friend?";
			link.l1 = "Tell me, Chimiset, do you know the White Boy?";
			link.l1.go = "Friend_9";
		break;
		
		case "freedom_2":
			DialogExit();
			NextDiag.CurrentNode = "Chimiset_wait";
			LSC_SetWhiteBoy(); // ставим Белого Мальчика в магазин
		break;
		
		//--> информационный блок
		case "Chimiset_wait": // стал другом
			if (pchar.questTemp.LSC == "return" && !CheckAttribute(npchar, "quest.return_isl"))
			{
				dialog.text = "Oh! My white friend "+pchar.name+"! Didn't you drown? The spirits saved you, I know that...";
				link.l1 = "I am fine and alive, Chimiset. Spirits? Perhaps you are right, it all has happened because of Kukulcan...";
				link.l1.go = "exit";
				npchar.quest.return_isl = "true";
				break;
			}
			dialog.text = "What brings you here, my good friend?";
			/*if (!CheckAttribute(npchar, "quest.story"))
			{
				link.l1 = "Tell me how the leader of Narwhals died. You were the only one who saw that.";
				link.l1.go = "story";
			}*/
			if (!CheckAttribute(npchar, "quest.crab"))
			{
				link.l2 = "You have mentioned the crabs at the bottom near the 'San Geronimo'. Can you describe those monsters?";
				link.l2.go = "crab";
			}
			link.l9 = "Nothing special, Chimiset. Just wanted to see you.";
			link.l9.go = "exit";
			NextDiag.TempNode = "Chimiset_wait";
		break;
		
		case "story":
			dialog.text = "A story of the death of Alan Milrow will be written here.";
			link.l1 = "Fine!";
			link.l1.go = "exit";
			npchar.quest.story = "true";
			NextDiag.TempNode = "Chimiset_wait";
		break;
		
		case "crab":
			dialog.text = "No one knows from where they came from, and why they have reached such a gigantic size. We don't know much about these beasts. They exist, a lot of people saw them. Groups of them, can be found among ships' wrecks in shallow waters. They stalk at the bottom of the sea, hunting fish and eating all garbage we dump\nThey are a real threat. Their pincers can inflict serious wounds, also their jaws release a dangerous poison, similar to the poison of marine fish. If poisoned and left untreated, a man shall meet the maker. Fortunately, the toxin can be neutralized by an antidote made of local herbs\nThere was a crab hunter among us. He used to bring their meat, helluva delicious dish. But the most important thing: he often brought the claws of these monsters and jaws with poison. they were the main ingreedeients in some of my potions. Pity, it's been long since someone brought me any of those...";
			link.l1 = "And where is that hunter now?";
			link.l1.go = "crab_1";
		break;
		
		case "crab_1":
			dialog.text = "Take the hint. You have to be prepared to become prey yourself while hunting those beasts. One day he simply didn't return. That is why I am warning you to be careful and attentive around these creatures.";
			link.l1 = "I see...";
			link.l1.go = "exit";
			npchar.quest.crab = "true";
			NextDiag.TempNode = "Chimiset_wait";
		break;
		//<-- информационный блок
		
		case "":
			dialog.text = "";
			link.l1 = "";
			link.l1.go = "";
		break;
		
		case "":
			dialog.text = "";
			link.l1 = "";
			link.l1.go = "";
		break;
		
		case "":
			dialog.text = "";
			link.l1 = "";
			link.l1.go = "";
		break;
		
		case "":
			dialog.text = "";
			link.l1 = "";
			link.l1.go = "";
		break;
		
		case "":
			dialog.text = "";
			link.l1 = "";
			link.l1.go = "";
		break;
		
		case "":
			dialog.text = "";
			link.l1 = "";
			link.l1.go = "";
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
	}
}
