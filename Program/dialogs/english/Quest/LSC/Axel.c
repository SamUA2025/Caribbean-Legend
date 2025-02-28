// торговец Аксель Йост
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
			if (pchar.questTemp.LSC == "return" && !CheckAttribute(npchar, "quest.return_isl"))
			{
				dialog.text = "Would you look at that..."+GetFullName(pchar)+"! Are you back from the afterlife? How is it possible?";
				link.l1 = "People don't come back from the afterlife, Axel. It is simple - I haven't been dead, ha-ha!";
				link.l1.go = "exit";
				npchar.quest.return_isl = "true";
				break;
			}
			if (CheckAttribute(pchar, "GenQuest.NarvalConflict"))
			{
				dialog.text = "Heh, pal, I won't do business with you before you settle things down with Narwhals. I don't want troubles. Go to Fazio, he can handle this.";
				link.l1 = "Fine, I will do that immediately.";
				link.l1.go = "exit";
				break;
			}
			if (CheckAttribute(pchar, "GenQuest.CitizenConflict") && sti(pchar.GenQuest.CitizenConflict) > 3)
			{
				dialog.text = "I don't want to talk with you. You attack peaceful people for no reason and provoke them to fight. Get lost!";
				link.l1 = "Hm...";
				link.l1.go = "exit";
				break;
			}
			if (npchar.quest.meeting == "0")
			{
				dialog.text = "Oh! A new face! What brings you here? Though, it is not my business. Let me introduce myself: my name is Axel Yost and I own this shop. See anything you like?";
				link.l1 = TimeGreeting()+". My name is "+GetFullName(pchar)+". What kind of goods have you got?";
				link.l1.go = "meeting";
				npchar.quest.meeting = "1";
			}
			else
			{
				dialog.text = "Ah, "+pchar.name+"! Glad to see you. Do you want to buy or sell anything?";
				// квестовые ветки
				if (CheckAttribute(pchar, "questTemp.Saga.SharkHunt") && pchar.questTemp.Saga.SharkHunt == "search_mush_1")
				{
					link.l4 = "Listen, Axel, do you have a fine musket to sell? Not a casual soldier's handgun, but something for accurate and long-range?";
					link.l4.go = "adolf";
				}
				if (CheckAttribute(pchar, "questTemp.Saga.SharkHunt") && pchar.questTemp.Saga.SharkHunt == "trader_whiskey")
				{
					link.l4 = "Listen, Axel, did Chad Kapper ask you to get him a whiskey barrel? ";
					link.l4.go = "whiskey";
				}
				if (CheckAttribute(npchar, "quest.ole_pearl"))
				{
					link.l5 = "Listen, Axel, you must have heard my conversation with that local idiot. What bead did he ask for? I don't get it.";
					link.l5.go = "ole_pearl";
				}
				link.l1 = "Yes. Let's trade, Axel!";
				link.l1.go = "Trade_items";
				link.l2 = LinkRandPhrase("Got anything interesting to tell?", "What has happened on the Island recently?", "Any gossips?");
				link.l2.go = "rumours_LSC";
				link.l3 = "Not yet. Just wanted to greet you.";
				link.l3.go = "exit";
			}
			NextDiag.TempNode = "First time";
		break;
		
		case "meeting":
			dialog.text = "All kinds of stuff. Mixtures, blades, firearms, ammo, cuirasses, gems and minerals. Enchanted amulets and talismans. Garbage and everyday items. People bring me everything they find on the crashed ships, things they don't need themselves\nSo feel free to do the same. I must warn you, though. I do not offer provisions or ship wares.";
			link.l1 = "Fine, Axel. Let's see your goods.";
			link.l1.go = "Trade_items";
			link.l2 = "Thank you, Axel. I'll keep that in mind. I will see you as soon as I need your services.";
			link.l2.go = "exit";
			NextDiag.TempNode = "First time";
		break;
		
		case "Trade_items":
			DialogExit();
			if (!CheckAttribute(npchar, "trade_date") || GetNpcQuestPastDayParam(npchar, "trade_date") >= 5)
			{
				GiveItemToTrader(npchar);
				SaveCurrentNpcQuestDateParam(npchar, "trade_date");
			}
			LaunchItemsTrade(npchar, 0);
		break;
		
		// наводка на Адольфа
		case "adolf":
			dialog.text = "This must some kind of a joke. You are the third person to ask. I don't carry such weaponry here. But several months ago Adolf Barbier tried to sell me his hunting scoped stutzen. A wonderful weapon, I tell you. Exactly what you are looking for\nBut Barbier asked a hell of price for it. So, I had to reject his offer.";
			link.l1 = "Interesting! And where can I find Barbier?";
			link.l1.go = "adolf_1";
		break;
		
		case "adolf_1":
			dialog.text = "I have no idea. He's probably wandering around somewhere. He often visits Sancho's tavern, he likes to have a drink every evening.";
			link.l1 = "Thanks! I think, I will find him there. Tell me, Axel, who else has asked you about the rifle? You've mentioned others who were interested, who would they be?";
			link.l1.go = "adolf_2";
		break;
		
		case "adolf_2":
			dialog.text = "Mary Casper and Marcello, also known as Cyclops. I have no idea, why the girl would be in need of a rifle, but our Red Mary is a well-known madcap. A year ago, she bought out tons of gun powder to make mines, to stun crabs she said. Thank the Lord, she wasn't allowed to do so\nAnd Marcello wanted to buy a rifle for bird hunting, the man got tired of salted beef. I referred them both to Adolf, don't know if they bought the rifle from him or not\nAlso, that sly dog Giuseppe Fazio inquired about Adolf recently. Perhaps, he wants to buy this stutzen, too.";
			link.l1 = "Heh, I've got a lot of competitors. Fine, I'll go find Adolf - hopefully, he hasn't sold the gun yet.";
			link.l1.go = "adolf_3";
		break;
		
		case "adolf_3":
			DialogExit();
			pchar.questTemp.Saga.SharkHunt = "search_mush_2"; //флаг на таверну
			AddQuestRecord("SharkHunt", "12");
			sld = characterFromId("LSC_Adolf");
			sld.lifeday = 0; // убираем настоящего Адольфа
		break;
		
		// бусинка для Белого Мальчика - просто инфа
		case "ole_pearl":
			dialog.text = "Everybody knows that, mister! He asks everyone for these beads, that is what he calls the big pearls. Give him one, and you will be his best friend.";
			link.l1 = "Now I see. Thank you, Axel, I would never have guessed myself.";
			link.l1.go = "exit";
			DeleteAttribute(npchar, "quest.ole_pearl");
		break;
		
		// виски для Акулы
		case "whiskey":
			dialog.text = "Yes, pal, he did. But I will disappoint you in case you want to buy a barrel of Bushmills too. I had only one barrel and Chad bought it. I can offer you Scottish Whiskey - it's as good as Irish, and, actually, I like the taste much better.";
			link.l1 = "Perhaps, later. Has Chad bought anything else from you?";
			link.l1.go = "whiskey_1";
		break;
		
		case "whiskey_1":
			dialog.text = "No. He was interested in arsenic, he said that there are too many rats at the Tartarus and he wants to exterminate them. I haven't beeen in need of arsenic since I hired that idiot Olle to clean my shop, all rats have gone to the tavern of poor Sancho. I don't know why rats fear Olle so much...";
			link.l1 = "Perhaps, he's got cats in his family...";
			link.l1.go = "whiskey_2";
		break;
		
		case "whiskey_2":
			dialog.text = "Ha-ha! Perhaps... Sancho has arsenic - that's for sure.";
			link.l1 = "I see. Thanks for the information, then!";
			link.l1.go = "whiskey_3";
		break;
		
		case "whiskey_3":
			DialogExit();
			AddQuestRecord("SharkHunt", "36");
			pchar.questTemp.Saga.SharkHunt = "barmen_whiskey"; // флаг на таверну - поиск мышьяка
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
