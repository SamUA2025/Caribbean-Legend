// полковник Фокс - бравый командир морской пехоты 'морские лисы'.
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
			if (CheckAttribute(pchar, "questTemp.Terrapin_KathyReward"))
			{
				dialog.text = "What do you want, Sir? Oh... my... wait! You are the French Captain who has saved my daughter from the dirty hands of Levasseur's servants! ";
				link.l1 = "I see that Catherine has already told you about me...";
				link.l1.go = "terrapin";
				break;
			}
			if (CheckAttribute(pchar, "questTemp.Guardoftruth.Usurer") && !CheckAttribute(npchar, "quest.utensil"))
			{
				dialog.text = "What do you want, Sir?";
				link.l1 = "Good day, Colonel. I came to you regarding some 'uncommon' business. Could you spare a bit of time for me?";
				link.l1.go = "guardoftruth";
				break;
			}
			// Addon-2016 Jason, французские миниквесты (ФМК) Сент-Кристофер
			if (CheckAttribute(pchar, "questTemp.FMQN") && pchar.questTemp.FMQN == "eng_reward")
			{
				dialog.text = "As far as I understand you are the French Captain who had assisted my men on their mission on Sint-Maarten? "+TimeGreeting()+"!";
				link.l1 = TimeGreeting()+", Colonel. Yes, that would be me.";
				link.l1.go = "FMQN";
				break;
			}
			dialog.text = "What do you want, Sir?";
			link.l1 = "Nothing, Colonel. I'll take my leave.";
			link.l1.go = "exit";			
			NextDiag.TempNode = "First time";
		break;
		
		case "guardoftruth":
			dialog.text = "So spit it out already, since you have already come this far...";
			link.l1 = "You've recently boarded a Schooner under the command of Rollie the Cap, a Dutch pirate, and brought the Captain here, to St. John's.";
			link.l1.go = "guardoftruth_1";
		break;
		
		case "guardoftruth_1":
			dialog.text = "Captain? Oh, don't make me laugh! This criminal scum has no right to be called by this honorable rank. I have captured a damn pirate, the head of a wolf's herd, whom has robbed and murdered English traders and merchants. And I made sure that he and his degenerates got what they deserved - the whole of St. John's has watched their hanging on the pier!";
			link.l1 = "I guess I won't be able to question this scoundrel then... Colonel, perhaps you could help me? The pirate had something in his possession which didn't belong to him - the golden censer. Did you find anything on him that looks like that?";
			link.l1.go = "guardoftruth_2";
		break;
		
		case "guardoftruth_2":
			dialog.text = "No, we searched him and that rascal didn't possess any belongings, besides, all of them were surely taken from honest traders! And about your concern... hmm no, we have not found it. And what could a censer possibly do on a pirate vessel? Do you really think that there was a priest among them?";
			link.l1 = "No I don't. Rollie the Cap bought it from the usurer in Willemstad, who had bought it from another pirate. The censer is fine and expensive, and I am trying to return it to its rightful owners. I suppose that Rollie had his eyes on it like a magpie.";
			link.l1.go = "guardoftruth_3";
		break;
		
		case "guardoftruth_3":
			dialog.text = "In truth, Rollie had empty holds and a few chests with doubloons when we boarded and captured his ship. Nothing but rubbish. No valuables, no golden censer. I'd remember such an unfitting item for a pirate.\nI suspect that damn pirate has hidden his savings at Dominica. We even landed there and searched the area but found nothing. But we didn't stay on the island or explored its depths due to a large amount of savages there.";
			link.l1 = "Hm... The pirate could have stashed the censer with the rest of his stolen things somewhere at Dominica... Too bad. Have you interrogated the pirate, before the execution?";
			link.l1.go = "guardoftruth_4";
		break;
		
		case "guardoftruth_4":
			dialog.text = "I did... and he just started laughing in my face. But I didn't really care about his stashes. Rollie the Cap was hung and that's the most important thing.";
			link.l1 = "I see. Thanks for your story and your time, Colonel. Farewell...";
			link.l1.go = "guardoftruth_5";
		break;
		
		case "guardoftruth_5":
			DialogExit();
			npchar.quest.utensil = "true";
			AddQuestRecord("Guardoftruth", "24");
			Island_SetReloadEnableGlobal("Dominica", true);//patch-7
			// заполняем сундук
			pchar.GenQuestBox.Shore27 = true;
			pchar.GenQuestBox.Shore27.box1.money = 30000;
			pchar.GenQuestBox.Shore27.box1.items.gold_dublon = 100;
			pchar.GenQuestBox.Shore27.box1.items.chest = 1;
			pchar.GenQuestBox.Shore27.box1.items.icollection = 1;
			pchar.GenQuestBox.Shore27.box1.items.jewelry40 = 15;
			pchar.GenQuestBox.Shore27.box1.items.jewelry41 = 22;
			pchar.GenQuestBox.Shore27.box1.items.jewelry42 = 8;
			pchar.GenQuestBox.Shore27.box1.items.jewelry43 = 20;
			pchar.GenQuestBox.Shore27.box1.items.jewelry44 = 33;
			pchar.GenQuestBox.Shore27.box1.items.jewelry45 = 16;
			pchar.GenQuestBox.Shore27.box1.items.jewelry46 = 58;
			pchar.GenQuestBox.Shore27.box1.items.jewelry35 = 1; // кадило
			pchar.quest.GuardOT_finddominicachest.win_condition.l1 = "item";
			pchar.quest.GuardOT_finddominicachest.win_condition.l1.item = "jewelry35";
			pchar.quest.GuardOT_finddominicachest.function = "GuardOT_DominicaChest";
		break;
		
		case "terrapin":
			dialog.text = "Several times, captain! Your honorable and brave deed was hardly to be expected from a Frenchmen. I owe you my gratitude, as a soldier and as a father. There is nothing more valuable to me in this entire world than my daughter...";
			link.l1 = "I am glad that I could be of help, and I hope with my actions you'll have a change of heart for the French, in time.";
			link.l1.go = "terrapin_1";
		break;
		
		case "terrapin_1":
			dialog.text = "The presence of such a honorable and generous gentleman like yourself, who has risked his life for an unfamiliar English girl, will cause an essential warming of my relation to your compatriots!";
			link.l1 = "There are honest people among rats in any nation, colonel...";
			link.l1.go = "terrapin_2";
		break;
		
		case "terrapin_2":
			dialog.text = "And you have proven that! A reward is waiting for you, captain. Of course, the life of daughter is priceless, but Jonathan Fox always pays his debts, I swear it! You are a real soldier, therefore, my gift for you is a soldier's gift. Here, take a look.\nThis is a blunderbuss, an excellent navy musket, can be used by one hand. You can load it with special arrows which will always pierce even the most durable cuirass. It also shoots grapeshot and it's solid construction allows you to load it with charges of nails. Here, take it, it's yours now.";
			link.l1 = "Such an excellent gift for a soldier, I thank you, Colonel!";
			link.l1.go = "terrapin_3";
		break;
		
		case "terrapin_3":
			Log_Info("You have received a blunderbuss");
			Log_Info("You have received 10 arrows");
			Log_Info("You have received 10 charges of nails");
			Log_Info("You have received instructions for creating the harpoon arrows");
			Log_Info("You have received instructions for creating the charge of nails");
			GiveItem2Character(pchar, "pistol8");
			TakeNItems(pchar, "harpoon", 10);
			TakeNItems(pchar, "GunEchin", 10);
			GiveItem2Character(pchar, "recipe_harpoon"); 
			GiveItem2Character(pchar, "recipe_GunEchin"); 
			PlaySound("interface\important_item.wav");
			dialog.text = "I also hand to you a small batch of ammo and instructions for their creation. It would be a shame if you won't use its power at a maximum!";
			link.l1 = "Thank you, Colonel. I won't reject such a gift, but I want you to know that I did not save Catherine for a reward. I just could not have left the unprotected girl come to any harm.";
			link.l1.go = "terrapin_4";
		break;
		
		case "terrapin_4":
			dialog.text = "I know that, captain. It honors you in double. Catherine was really ravished by you and it's not an easy task to make a positive impression on her. Again, we owe you our gratitude for rescuing her. I owe you!";
			link.l1 = "Well I thank you for the gift, Colonel. Send Catherine my best regards, and I wish that she would listen her father next time.";
			link.l1.go = "terrapin_5";
		break;
		
		case "terrapin_5":
			dialog.text = "I will, Captain! Farewell, and safe travels!";
			link.l1 = "Farewell, Colonel.";
			link.l1.go = "exit";
			DeleteAttribute(pchar, "questTemp.Terrapin_KathyReward");
			ChangeCharacterComplexReputation(pchar, "nobility", 5);
			ChangeCharacterComplexReputation(pchar, "fame", 5);
			ChangeCharacterNationReputation(pchar, ENGLAND, 20);
		break;
		
		// Addon-2016 Jason, французские миниквесты (ФМК) Сент-Кристофер
		case "FMQN":
			DelLandQuestMark(npchar);
			dialog.text = "I've read the report. Your actions are highly evaluated, therefore you must be rewarded. Thirty thousand pesos for expedition services and weapons for heroism in soldiery. Accept this blade and this arquebus. They are all yours now!";
			link.l1 = "Thank you, Sir.";
			link.l1.go = "FMQN_1";
		break;
		
		case "FMQN_1":
			dialog.text = "By all means, Captain. You are also rewarded with love and respect of the British colonies, authorities and myself personally. Thank you for not abandoning my men and helping them on their mission!";
			link.l1 = "My pleasure, Colonel...";
			link.l1.go = "FMQN_2";
		break;
		
		case "FMQN_2":
			dialog.text = "Now, please excuse me - I have other business to attend to. Godspeed, Captain.";
			link.l1 = "Farewell, Sir.";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("FMQN_EnglandComplete");
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}
