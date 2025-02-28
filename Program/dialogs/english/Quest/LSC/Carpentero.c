// Санчо Карпентеро - бармен
#include "DIALOGS\%language%\Rumours\Common_rumours.c"
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	ProcessCommonDialogRumors(NPChar, Link, NextDiag);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			if (CheckAttribute(pchar, "GenQuest.CitizenConflict") && sti(pchar.GenQuest.CitizenConflict) > 3)
			{
				dialog.text = "I don't want to talk with you. You attack peaceful people for no reason and provoke them to fight. Get lost from my tavern!";
				link.l1 = "Hm...";
				link.l1.go = "exit";
				break;
			}
			if (pchar.questTemp.LSC == "return" && !CheckAttribute(npchar, "quest.return_isl"))
			{
				dialog.text = ""+pchar.name+"! I am so glad to see you! I knew, I knew that the gossips were a lie! Damn it, we absolutely have to drink to it now!";
				link.l1 = "Well, let's drink, pal! I am also damn glad to see you!";
				link.l1.go = "exit";
				npchar.quest.return_isl = "true";
				break;
			}
			// пей до дна
			if (CheckAttribute(npchar, "quest.drink") && npchar.quest.drink == "fail")
			{
				dialog.text = ""+pchar.name+", I am sorry about your failure. Few are able to outdrink the fat man. How is your head?";
				link.l1 = "Yeah, pal, you've got some good strong rum there. I owe you for the drinks... how much?";
				link.l1.go = "drunk_fail";
				break;
			}
			if (CheckAttribute(npchar, "quest.drink") && npchar.quest.drink == "win")
			{
				dialog.text = "You have beaten Fazio, "+pchar.name+"! I am surprised, only a few were able to outdrink him. Here, take your two hundred doubloons.";
				link.l1 = "Thank you for kind words, pal!";
				link.l1.go = "drunk_win";
				break;
			}
			// крабовый салат
			if (CheckAttribute(npchar, "quest.crab") && npchar.quest.crab == "begin")
			{
				dialog.text = ""+pchar.name+"? They say that you dove to the bottom in a suit made by a Narwhal mechanic. Is it true or just gossips, as usual?";
				link.l1 = "It's true, pal. I dove there for real.";
				link.l1.go = "crab";
				break;
			}
			if (npchar.quest.meeting == "0")
			{
				dialog.text = "Greetings to the new man in my tavern! Welcome! You will always find drinks in my tavern, my wine stores are filled, can't say the the same about food, though, ha-ha... Joking. My name is Sancho Carpentero and I own this place.";
				link.l1 = TimeGreeting()+", Sancho. My name is "+GetFullName(pchar)+". Nice to meet you.";
				link.l1.go = "meeting";
				npchar.quest.meeting = "1";
			}
			else
			{
				dialog.text = "Ah, my friend "+pchar.name+"! Glad to see you in my tavern! Want to drink something?";
				// квестовые ветки
				if (CheckAttribute(pchar, "questTemp.Saga.SharkHunt") && pchar.questTemp.Saga.SharkHunt == "search_mush_1" && !CheckAttribute(npchar, "quest.mushket"))
				{
					link.l6 = "Listen, Sancho, do you know where can I get a good musket? Not a casual soldier's sidearm, but something accurate, for hunting maybe?";
					link.l6.go = "mushket";
				}
				if (CheckAttribute(pchar, "questTemp.Saga.SharkHunt") && pchar.questTemp.Saga.SharkHunt == "search_mush_2")
				{
					link.l6 = "Listen, Sancho, I've got a few questions for you. I am looking for a man named Adolf Barbier. They say that he often visits this place...";
					link.l6.go = "adolf";
				}
				if (CheckAttribute(pchar, "questTemp.Saga.SharkHunt") && pchar.questTemp.Saga.SharkHunt == "barmen_whiskey")
				{
					link.l6 = "Listen, Sancho, they say that Chad Kapper bought some arsenic from you...";
					link.l6.go = "whiskey";
				}
				if (CheckCharacterItem(pchar, "talisman1") && CheckAttribute(npchar, "quest.rat"))
				{
					link.l7 = "Sancho, do you want me to show you something interesting? Is this the bat mask you wanted to get your hands on so much?";
					link.l7.go = "rat";
				}
				if (CheckCharacterItem(pchar, "talisman1") && CheckAttribute(npchar, "quest.ratmoney") && GetCharacterItem(pchar, "gold_dublon") >= 1)
				{
					if (GetCharacterItem(pchar, "gold_dublon") >= sti(npchar.quest.ratmoney))
					{
						if(!CheckAttribute(npchar, "quest.ratmoneyagain")) ChangeCharacterComplexReputation(pchar, "fame", 5);
						link.l7 = "Sancho, I've come for my cuirass. Here's the money.";
						link.l7.go = "rat_3";
					}
					else
					{
						npchar.quest.ratmoneyagain = true;
						link.l7 = "Sancho, I've come for my cuirass. Here's the money.";
						link.l7.go = "rat_take_money_not_all";
					}
				}
				if (makeint(pchar.money) >= 25)
				{
					link.l1 = "Serve me some rum, Sancho.";
					link.l1.go = "drink";
				}
				if (makeint(pchar.money) >= 20)
				{
					link.l2 = "I want to stay over.";
					link.l2.go = "room";
				}
				if (stf(environment.time) >= 6.0 && stf(environment.time) <= 18.0 && makeint(pchar.money) >= 300)
				{
					link.l9 = "Bored... Sancho, I want to spend time here with a bottle of wine until evening...";
					link.l9.go = "drink_sit";
				}
				link.l3 = LinkRandPhrase("Got anything interesting to tell?", "What has happened on the island recently?", "Any gossips?");
				link.l3.go = "rumours_LSC";
				if (CheckAttribute(npchar, "quest.crab") && npchar.quest.crab == "current" && CheckCharacterItem(pchar, "crab_pincers"))
				{
					link.l10 = "Sancho, I want to sell you crab's claws.";
					link.l10.go = "crab_trade";
				}
				link.l4 = "Sancho, I want to ask you something about the Island.";
				link.l4.go = "int_quests"; //информационный блок
				link.l5 = "No, pal. Just wanted to check how you're doing here.";
				link.l5.go = "exit";
			}
			NextDiag.TempNode = "First time";
		break;
		
		case "meeting":
			dialog.text = "So am I. I hope I will see you at least every other day or even every evening, ha-ha! I am sincerely happy to have any visitor in my tavern.";
			if (makeint(pchar.money) >= 25)
			{
				link.l1 = "Serve me some rum, Sancho.";
				link.l1.go = "drink";
			}
			if (makeint(pchar.money) >= 20)
			{
				link.l2 = "I want to stay over.";
				link.l2.go = "room";
			}
			link.l3 = "Sancho, I want to ask you something about the island.";
			link.l3.go = "int_quests"; //информационный блок
			link.l4 = "See you, Sancho!";
			link.l4.go = "exit";
			NextDiag.TempNode = "First time";
		break;
		
		case "mushket":
			dialog.text = "No, friend, I can't help you. You know, I am a specialist in beer glasses and wine bottles - but not in muskets, ha-ha! Go to the shop, I heard that Axel sells interesting weapons sometimes. You might find what you need there.";
			link.l1 = "Thank you for the advice.";
			link.l1.go = "exit";
			npchar.quest.mushket = "true";
		break;
		
		case "adolf":
			dialog.text = "Adolf? Yes, he visits me occasionally, though I have not seen him in the past few days. He has been missing ever since he had a chat with that fat man Giuseppe.";
			link.l1 = "Giuseppe? You mean Giuseppe Fazio?";
			link.l1.go = "adolf_1";
		break;
		
		case "adolf_1":
			dialog.text = "Ha, pal, there is only one Giuseppe on the Island - Giuseppe Fazio. Aye, that's him. They were sitting down for a few hours drinking rum, having a very lively conversation.";
			link.l1 = "Were they arguing?";
			link.l1.go = "adolf_2";
		break;
		
		case "adolf_2":
			dialog.text = "No. It seemed as if they were old buddies. Look, just visit Fazio at the 'Caroline' and ask him about Adolf.";
			link.l1 = "Fine, I'll do that.";
			link.l1.go = "adolf_3";
		break;
		
		case "adolf_3":
			dialog.text = "Is that all? You said that you had a few questions...";
			link.l1 = "Yes. Tell me, who is Red Mary and Cyclops Marcello?";
			link.l1.go = "adolf_4";
		break;
		
		case "adolf_4":
			dialog.text = "Red Mary is one of Narwhals. Young and beautiful girl, but she is completely wild, yes. She knows how use her blade and a handgun as good as any man. Used to be the girlfriend of Alan Milrow, an ex leader of Narwhal clan, before the admiral killed him\nAlan's death hit her hard, most of the time she is crying and cursing Shark in her cabin on the 'Ceres Smithy'... But she will get over it, life continues after all\nI don't know much about Marcello, saw him only couple of times. Suspicious guy. They say that he used to be a royal hunter, lost an eye in a fight and went sailing as a boarding officer\nHates pirates, looks like he has a grudge on them. Not surprising, given his previous service in boarding parties of trade ships.";
			link.l1 = "I see. Thanks a lot, Sancho, you helped out a lot!";
			link.l1.go = "adolf_5";
		break;
		
		case "adolf_5":
			dialog.text = "You are welcome, pal, come see me again, and we will have some ale together...";
			link.l1 = "Sure!";
			link.l1.go = "adolf_6";
		break;
		
		case "adolf_6":
			DialogExit();
			pchar.questTemp.Saga.SharkHunt = "search_mush_3"; //флаг на Джузеппе
			AddQuestRecord("SharkHunt", "13");
		break;
		
		// виски для Акулы
		case "whiskey":
			dialog.text = "Kapper? No. He haven't visited the tavern recently. Marcello Cyclops bought a flask of arsenic just fifteen minutes ago - he is also plagued by rats. I perfectly understand him... Damn rats.";
			link.l1 = "Marcello Cyclops?!";
			link.l1.go = "whiskey_1";
		break;
		
		case "whiskey_1":
			dialog.text = "Well, yes. Is that strange?";
			link.l1 = "No, of course not! I have been looking for him for a few days and turns out that he has been here recently. Could you tell me where he went?";
			link.l1.go = "whiskey_2";
		break;
		
		case "whiskey_2":
			dialog.text = "He was with Adolf Barbier who lives at the 'Santa Florentina'. Perhaps, they were heading there.";
			link.l1 = "Thanks!";
			link.l1.go = "whiskey_3";
		break;
		
		case "whiskey_3":
			dialog.text = "If you need some arsenic, then I can sell a flask for twenty doubloons.";
			link.l1 = "Fine. We'll talk about it later, Sancho. See you!";
			link.l1.go = "whiskey_4";
		break;
		
		case "whiskey_4":
			DialogExit();
			pchar.questTemp.Saga.SharkHunt = "whiskey_poison"; // флаг - виски травят
			AddQuestRecord("SharkHunt", "37");
			sld = CharacterFromID("LSC_Adolf");
			LAi_SetActorType(sld);
			ChangeCharacterAddressGroup(sld, "SantaFlorentinaShipInside4", "goto", "goto2");
			sld = CharacterFromID("Dodson");
			sld.dialog.currentnode = "whiskey"; // ноду Акуле
			// важный момент! От дальнейшего поведения геймера зависит результат
			pchar.quest.LSC_Whiskeypoison_SF.win_condition.l1 = "location";
			pchar.quest.LSC_Whiskeypoison_SF.win_condition.l1.location = "SantaFlorentinaShipInside4";
			pchar.quest.LSC_Whiskeypoison_SF.function = "LSC_WhiskeyPoison_SF"; // прерывание на Санта-Флорентину
			pchar.quest.LSC_Whiskeypoison_AE.win_condition.l1 = "location";
			pchar.quest.LSC_Whiskeypoison_AE.win_condition.l1.location = "AvaShipInside3";
			pchar.quest.LSC_Whiskeypoison_AE.function = "LSC_WhiskeyPoison_AE"; // прерывание на Эву
			pchar.quest.LSC_Whiskeypoison_exit.win_condition.l1 = "location";
			pchar.quest.LSC_Whiskeypoison_exit.win_condition.l1.location = "LostShipsCity_town";
			pchar.quest.LSC_Whiskeypoison_exit.function = "LSC_Whiskeypoison_exit"; // прерывание на выход из таверны
			// закрываем вход к Фацио
			LocatorReloadEnterDisable("LostShipsCity_town", "reload20", true);
			LocatorReloadEnterDisable("LostShipsCity_town", "reload24", true);
		break;
		
		// пей до дна
		case "drunk_fail":
			dialog.text = "Come on, pal! You don't owe me a thing.  You've already lost a hundred doubloons. It was a mistake to deal with Fazio...";
			if (sti(pchar.money) >= 500)
			{
				link.l1 = "No-no, Sancho! Thank you and please take these five hundred pesos. That should cover the cost of the drinks as far as I remember. I don't want to be in your debt.";
				AddMoneyToCharacter(pchar, -500);
			}
			else link.l1 = "Eh, thanks, Sancho. You are right.";
			link.l1.go = "exit";
			DeleteAttribute(npchar, "quest.drink");
		break;
		
		case "drunk_win":
			DialogExit();
			TakeNItems(pchar, "gold_dublon", 200);
			Log_Info("You have received 200 doubloons");
			PlaySound("interface\important_item.wav");
			DeleteAttribute(npchar, "quest.drink");
		break;
		
		// крабовый салат
		case "crab":
			dialog.text = "Hm... then I have a proposal for you. Have you seen giant crabs there?";
			link.l1 = "Have I seen crabs? There were hordes of them! And what proposal are you talking about?";
			link.l1.go = "crab_1";
		break;
		
		case "crab_1":
			dialog.text = "If you kill some crabs, be sure to bring the claws to me. I will pay you well in doubloons - five coins for each. Axel Yost won't pay that much, trust me. I am not asking that you hunt crabs for this task - but if you come across some, please keep this in mind...";
			link.l1 = "Why claws? What about the other parts of a crab? What do you do with those?";
			link.l1.go = "crab_2";
		break;
		
		case "crab_2":
			dialog.text = "Why claws? Because most of the meat is on them. Crabs don't have much meat on their legs and the bodies are covered with a solid shell. Crab meat is a delicacy here, it has an exquisite taste and is very nourishing\nI also have a unique recipe for it, so I will pay you five doubloons for each nipper.";
			link.l1 = "Fine. I will keep that in mind.";
			link.l1.go = "crab_3";
		break;
		
		case "crab_3":
			DialogExit();
			npchar.quest.crab = "current";
		break;
		
		case "crab_trade":
			iTotalTemp = GetCharacterItem(pchar, "crab_pincers")
			dialog.text = "Splendid! How many do you have?";
			link.l1 = ""+FindRussianQtyString(iTotalTemp)+".";
			link.l1.go = "crab_trade_1";
			link.l2 = "I've changed my mind.";
			link.l2.go = "exit";
		break;
		
		case "crab_trade_1":
			dialog.text = "Deal. Here, take your doubloons - "+FindRussianQtyString(iTotalTemp*5)+". Thanks, pal, if you get more, bring them to me.";
			link.l1 = "Sure, friend.";
			link.l1.go = "crab_trade_2";
		break;
		
		case "crab_trade_2":
			DialogExit();
			RemoveItems(pchar, "crab_pincers", iTotalTemp);
			TakeNItems(pchar, "gold_dublon", iTotalTemp*5);
			PlaySound("interface\important_item.wav");
			Log_Info("You have received "+iTotalTemp*5+" doubloons");
		break;
		
		// крыс
		case "rat":
			dialog.text = "What?! Show me! Let me see it!";
			link.l1 = "Sure.";
			link.l1.go = "rat_1";
		break;
		
		case "rat_1":
			PlaySound("interface\important_item.wav");
			dialog.text = "This is it... It really is! It is exactly the same as the one on the picture that a sailor had drawn for me! Friend, there must be a reason you brought this to me, what do you want for it? How much?";
			link.l1 = "Of course I brought it to you for a reason. But as for the reward, what can you offer? As far as I remember, you promised me a royal reward for this thing...";
			link.l1.go = "rat_2";
			link.l2 = "Sorry, pal, it's not for sale. I need it for myself. Just wanted to make sure that this is the talisman you've been talking about.";
			link.l2.go = "rat_exit";
		break;
		
		case "rat_exit":
			PlaySound("interface\important_item.wav");
			dialog.text = "Eh, what a shame... Yes, lad, this is exactly that talisman. Lucky devil! Now the rats will not cause you any more trouble. And I will have to keep exterminating them with arsenic...";
			link.l1 = "I am sorry for teasing you, Sancho. I haven't ever seen it before, so I needed a consultation. I am sorry.";
			link.l1.go = "exit";
			DeleteAttribute(npchar, "quest.rat");
		break;
		
		case "rat_2":
			dialog.text = "For this,"+pchar.name+", I'll offer you the chance to purchase the finest and most valuable item I possess. It would be an excellent exchange for this charm, especially for a brave warrior like yourself. Let me fetch it for you.\nTake a look: here is a unique, splendid Milano Cuirass, meticulously crafted! It provides exceptional protection in battle, allowing for unrestricted movement, and it's lightweight and comfortable. Armor of this quality is rare in both the Caribbean and Europe.\nI stumbled upon this cuirass in the captain's quarters of a Spanish warship several years ago and kept it precisely for an occasion like this. I'm willing to sell it to you for two thousand gold coins and the Rat God!";
			link.l1 = "Hmm... This IS an excellent cuirass! I think this exchange suits me. I'll figure out the rat situation, but finding another cuirass like this would be next to impossible. I've never seen one quite like it before. Truly, it's a unique piece of armor.";
			link.l1.go = "rat_yes";
			link.l2 = "How much? Sancho, have your rats already bitten you a few times this morning? What do you mean, two thousand? Do you even know what it took for me to get you this idol? Drop the price right now!";
			link.l2.go = "rat_torg";
			link.l3 = "How much?! You're a shark, you know that, Sancho? 'Offer a chance to purchase!' Ha! For that kind of money, I could order myself armor on the mainland that would deflect bullets and heal me to boot! And what would you need so much gold? To have Jurgen cast your own statue for you and display it in full height on 'San Agustin'?";
			link.l3.go = "rat_no";
		break;
		
		case "rat_yes":
			dialog.text = "I'm glad you're on board, my friend. Thanks for not forgetting about my problem! So, I'll be expecting my doubloons. The armor will be waiting for you.";
			link.l1 = "I'll bring them over shortly!";
			link.l1.go = "rat_yes_1";
		break;
		
		case "rat_yes_1":
			DialogExit();
			DeleteAttribute(npchar, "quest.rat");
			npchar.quest.ratmoney = 2000;
		break;
		
		case "rat_torg":
			if(GetSummonSkillFromName(pchar, SKILL_COMMERCE) < 60)
			{
				notification("Skill Check Failed (60)", SKILL_COMMERCE);
				dialog.text = ""+pchar.name+", under different circumstances, I would demand five thousand. The admiral himself has shown interest, and he is not alone, believe me. Take your time to decide. The armor will be waiting for you for as long as you need. I'll only sell it to you.";
				link.l1 = "I'll think about it, Sancho. I'll think long and hard.";
				link.l1.go = "rat_yes_1";
				AddCharacterExpToSkill(pchar, "Commerce", 400);
			}
			else
			{
				notification("Skill Check Passed", SKILL_COMMERCE);
				dialog.text = ""+pchar.name+", under different circumstances, I would demand five thousand. The admiral himself has shown interest, and he is not alone, believe me. Fine, I'll knock off five hundred, considering you haven't forgotten about me and my problem. It seems there have been some adventures along the way.";
				link.l1 = "That's better. But I still don't get why I should pay extra in this trade of equally unique items. Maybe you should be the one paying me, eh Sancho?";
				link.l1.go = "rat_yes_1500";
				AddCharacterExpToSkill(pchar, "Commerce", 100);
			}
		break;
		
		case "rat_yes_1500":
			if(GetSummonSkillFromName(pchar, SKILL_COMMERCE) < 90)
			{
				notification("Skill Check Failed (90)", SKILL_COMMERCE);
				dialog.text = "No, "+pchar.name+", not gonna happen. I can deal with rats with poison, but this armor could save your life one day. And you'll look like an Italian duke wearing it. One thousand five hundred, that's my final offer. Take your time to think about it, and let me know. The armor will be waiting for you as long as you need, I'll sell it only to you.";
				link.l1 = "Sancho, if you weren't the only tavern keeper in this dreary graveyard... I'll think about your offer.";
				link.l1.go = "rat_yes_1500exit";
				AddCharacterExpToSkill(pchar, "Commerce", 600);
			}
			else
			{
				notification("Skill Check Passed", SKILL_COMMERCE);
				dialog.text = "For a military captain and a pirate, you sure know how to negotiate! Remember Jost? He once managed to buy all my arsenic at a discount, while the rats were already tormenting me. Alright, "+pchar.name+", you win. I'll knock off another five hundred for you! But that's my final offer!";
				link.l1 = "This still feels like a rip-off, but at least now I won't feel like a typical damsel in distress in the jungle. Wait for the money; I'll bring it soon.";
				link.l1.go = "rat_yes_1000exit";
				AddCharacterExpToSkill(pchar, "Commerce", 200);
			}
		break;
		
		case "rat_no":
			dialog.text = "Calm down, "+pchar.name+". From someone else, I would demand five thousand! The admiral himself has shown interest, and he is not alone, believe me. The armor will await you for as long as necessary. That's also included in the price of the idol.";
			link.l1 = "What an honor! Keep on wiping your glasses, and I'll be on my way. Two thousand!";
			link.l1.go = "rat_yes_1";
		break;
		
		case "rat_yes_1500exit":
			DialogExit();
			DeleteAttribute(npchar, "quest.rat");
			npchar.quest.ratmoney = 1500;
		break;
		
		case "rat_yes_1000exit":
			Achievment_SetStat(106, 1);
			DialogExit();
			DeleteAttribute(npchar, "quest.rat");
			npchar.quest.ratmoney = 1000;
		break;
		case "rat_3":
			dialog.text = "Done! I'm glad you agreed, mate. Thanks for not forgetting about my problem! Take the cuirass, and may it serve you well in battle.";
			link.l1 = "Here, take your talisman too - looks like dark days are coming for the rats in your tavern!";
			link.l1.go = "rat_4";
		break;
		
		case "rat_4":
			DialogExit();
			GiveItem2Character(pchar, "cirass4");
			RemoveItems(pchar, "talisman1", 1);
			RemoveItems(pchar, "gold_dublon", sti(npchar.quest.ratmoney));
			Log_Info("You have given away the talisman 'God of rats'");
			Log_Info("You have received a Milanese armor");
			Log_Info("You gave "+FindRussianDublonString(sti(npchar.quest.ratmoney))+"");
			PlaySound("interface\important_item.wav");
			DeleteAttribute(npchar, "quest.ratmoney");
			if(CheckAttribute(npchar, "quest.ratmoneyagain"))
				DeleteAttribute(npchar, "quest.ratmoneyagain");
		break;
		
		case "rat_take_money_not_all":
			npchar.quest.ratmoney = sti(npchar.quest.ratmoney) - GetCharacterItem(pchar, "gold_dublon");
			Log_Info("You gave "+FindRussianDublonString(GetCharacterItem(pchar, "gold_dublon"))+"");
			RemoveItems(pchar, "gold_dublon", GetCharacterItem(pchar, "gold_dublon"));
			PlaySound("interface\important_item.wav");
			dialog.text = "You still awe me "+FindRussianDublonString(sti(npchar.quest.ratmoney))+", "+pchar.name+".";
			link.l1 = "Don't remind me!";
			link.l1.go = "exit";
		break;
		
		//--> информационный блок
		case "int_quests":
			dialog.text = "I am listening.";
			if (!CheckAttribute(npchar, "quest.answer_1"))
			{
				link.l1 = "What is this place? Can you tell me more about it?";
				link.l1.go = "ansewer_1";
			}
			if (!CheckAttribute(npchar, "quest.answer_2"))
			{
				link.l2 = "How can I leave the Island?";
				link.l2.go = "ansewer_2";
			}
			if (!CheckAttribute(npchar, "quest.answer_3"))
			{
				link.l3 = "What should I know about the Island?";
				link.l3.go = "ansewer_3";
			}
			if (!CheckAttribute(npchar, "quest.answer_4"))
			{
				link.l4 = "And how are you doing here? How is your tavern?";
				link.l4.go = "ansewer_4";
			}
			link.l10 = "I have no questions, never mind...";
			link.l10.go = "exit";
		break;
		
		case "ansewer_1":
			dialog.text = "This place? Well, they call it the Justice Island, the Island of the Abandoned Ships, or City of the Abandoned Ships - but we just call it the Island. It's formed out of ships' wrecks, which are stuck on a shoal among the reefs. The central part of the Island is a living area and the outer ring is uninhabited. There has been no connection with the outer world for ten years.";
			link.l1 = "Got it...";
			link.l1.go = "int_quests";
			npchar.quest.answer_1 = "true";
		break;
		
		case "ansewer_2":
			dialog.text = "Build a long boat or a raft. But it won't end well for you. There is an anomaly storm area around the Island, you will not pass the outer ring without risking your life. Plus, the Island is being circled by a strong current\nYou need a team in order to get even a slim chance of survival. And very few locals are willing to leave this place. Even fewer are willing to take any risks. People like the way of living here. Ask around if you don't believe me.";
			link.l1 = "I see...";
			link.l1.go = "int_quests";
			npchar.quest.answer_2 = "true";
		break;
		
		case "ansewer_3":
			dialog.text = "First, you should remember that there are several restricted areas on the Island. Two clans - Narwhals and Rivados, they have been living here for a long time, fighting each other and fearlessly protecting territories they consider their own. Try to pay them a visit uninvited and you are a dead man\nYou must know the current password if you want to enter their territory. Don't worry about getting there on accident, guards will give you several warnings before they start shooting.";
			link.l1 = "I'll keep that in mind...";
			link.l1.go = "int_quests";
			npchar.quest.answer_3 = "true";
		break;
		
		case "ansewer_4":
			dialog.text = "You know, my friend, it's fine. I used to work with food and drinks: I worked as a cook a long time ago in Europe, as an intendant in a garrison, a tavern keeper, and a cook on a ship; so the first thing I did here was establishing a tavern\nI like my job and my life is oddly satisfying. Folks are friendly here, mostly. At least they don't kill each other frequently. Clans don't interfere with my activities. All in all, this the best place I've had my life. I'm free here and no one tells me what to do\nThe only thing driving me mad are rats. They torture me, eating my provisions and ruining my tableware. I have trouble getting rid of them.";
			link.l1 = "Rats? Yeah, they are everyone's trouble...";
			link.l1.go = "ansewer_4_1";
		break;
		
		case "ansewer_4_1":
			dialog.text = "Alas, I am the most unfortunate person here when it comes up to rats. Other ships are not so terrorized by rats and Axel Yost somehow managed to deal with them once and for all. As for me, I have got armies of rats crawling here. Eh, they told me that there is a special amulet called the Rat God.\nIt looks like bat face mask. They say that this amulet scares rats shitless. I guess someone has sold Axel this amulet, he buys and re-sells every piece of garbage they find on the outer ring\nI wish someone brought the amulet to me, I offer that person a royal reward!";
			link.l1 = "Interesting...";
			link.l1.go = "int_quests";
			npchar.quest.answer_4 = "true";
			npchar.quest.rat = "true";
		break;
		//<-- информационный блок
		
		//--> выпивка
		case "drink":
			if (CheckAttribute(pchar, "questTemp.Rum") && sti(pchar.questTemp.Rum) > 4)
			{
				dialog.text = ""+pchar.name+", I think that you should stop. God forbid you get in trouble or fall overboard to become crabs' meal... It's not a good idea to drink too much around here, a lot of people died because of it.";
				link.l1 = "Hm... I suppose you are right, Sancho - I have had enough already. Thanks for your concern!";			
				link.l1.go = "exit";
			}
			else
			{
				AddMoneyToCharacter(pchar, -25);
				if(!IsEquipCharacterByArtefact(pchar, "totem_01"))
				{
					if (CheckAttribute(pchar, "questTemp.Rum"))
					{
						pchar.questTemp.Rum = sti(pchar.questTemp.Rum) + 1;
					}
					else pchar.questTemp.Rum = 1;
				}
				else 
				{
					if(CheckAttribute(pchar, "questTemp.Rum")) DeleteAttribute(pchar, "questTemp.Rum");
				}				
				WaitDate("",0,0,0, 0, 30);
				
				dialog.text = "You are welcome, pal. Only twenty five pesos for the pint of my best rum!";
				link.l1 = RandPhraseSimple(LinkRandPhrase("Well, to your health and to your tavern's prosperity, pal!","Well, to those who are at sea!","Well, to inhabitants of your Island!"), LinkRandPhrase("Well, to the Island, and may it be around forever!","Well, may the wind always be favorable in all our deeds!","Well, to luck, happiness and... women!"));		
				link.l1.go = "drink_1";
			}
		break;
		
		case "drink_1":
			DialogExit();
			LAi_Fade("", "");
			if (CheckAttribute(pchar, "questTemp.Rum"))
			{
				if (sti(pchar.questTemp.Rum) < 3) LAi_AlcoholSetDrunk(pchar, 51, 5600);
				else LAi_AlcoholSetDrunk(pchar, 71, sti(pchar.questTemp.Rum)*2800);
			}
		break;
		
		case "drink_sit":
			if (chrDisableReloadToLocation || pchar.questTemp.Saga.SharkHunt == "barmen_whiskey" || pchar.questTemp.Saga.SharkHunt == "whiskey_poison") //идёт квест
			{
				dialog.text = "I dont think its a good idea for you to drink now. Trust me...";
				link.l1 = "Fine.";
				link.l1.go = "exit";
				break;
			}
			if (CheckAttribute(pchar, "questTemp.LSC.MaryBye") || CheckAttribute(pchar, "questTemp.LSC.MaryWait")) // подружился с Мэри
			{
				dialog.text = "Heh, you are a strange man... Don't you have no one to pass the time with here, on the Island? Mate, Mary will kill me if I let you stay here and get drunk alone. Come here together in the evening and have fun until dawn, if you wish.";
				link.l1 = "Fine...";
				link.l1.go = "exit";
			}
			else
			{
				dialog.text = "No problem, mate. For just three hundred pesos you will get a fine bottle of "+LinkRandPhrase("Spanish","Italian","French")+" wine - and have fun as long as you want.";
				link.l1 = "Thanks!";
				link.l1.go = "drink_sit_1";
			}
		break;
		
		case "drink_sit_1":
			DialogExit();
			sld = ItemsFromID("potionrum");
			sld.shown = true;
			sld.startLocation = "FleuronTavern";
			sld.startLocator = "bottle";
			DoQuestReloadToLocation("FleuronTavern", "quest", "sit2", "LSC_DrinkSit");
		break;
		//<-- выпивка
		
		//--> сон в таверне
		case "room":
   			if (chrDisableReloadToLocation || pchar.questTemp.Saga.SharkHunt == "barmen_whiskey" || pchar.questTemp.Saga.SharkHunt == "whiskey_poison") //идёт квест
			{
				dialog.text = "I dont think you should sleep right now. Trust me...";
				link.l1 = "Fine.";
				link.l1.go = "exit";
				break;
			}
			if (CheckAttribute(pchar, "questTemp.LSC.MaryBye") || CheckAttribute(pchar, "questTemp.LSC.MaryWait")) // подружился с Мэри
			{
				if(!isDay())
				{
					dialog.text = "I have never met such a strange man. There is a beautiful girl waiting for him in the 'Ceres Smithy' and he is going to spend the night at the tavern. Don't even think that I will let you sleep here. Mary will kill me for that.";
					link.l1 = "Fine...";
					link.l1.go = "exit";
				}
				else
				{
					dialog.text = "You can rest upstairs until the evening. But I won't let you spend a night here - Mary will kill me for that. I am sorry...";
					link.l1 = "Fine. I'll stay here until the evening...";
					link.l1.go = "hall_night_wait";
					link.l2 = "Fine... I will manage without sleeping.";
					link.l2.go = "exit";
				}
				break;
			}
			dialog.text = "You can sleep in the bed upstairs for just twenty pesos. When should I wake you up?";
			if(!isDay())
			{
				link.l1 = "In the morning.";
				link.l1.go = "hall_day_wait";
			}
			else
			{
				link.l1 = "Before the nightfall.";
				link.l1.go = "hall_night_wait";
				link.l2 = "Next morning.";
				link.l2.go = "hall_day_wait";
			}
			link.l3 = "I have changed my mind. I don't want to sleep.";
			link.l3.go = "exit";
		break;
		
		case "hall_night_wait":
			AddMoneyToCharacter(pchar, -20);
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			TavernWaitDate_LSC("wait_night");
		break;
		
		case "hall_day_wait":
			AddMoneyToCharacter(pchar, -20);
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			TavernWaitDate_LSC("wait_day");
		break;
		//<-- сон в таверне
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
	}
}
