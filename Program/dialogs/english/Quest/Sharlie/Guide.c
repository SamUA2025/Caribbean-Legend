// гид
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
			link.l1 = "No, nothing.";
			link.l1.go = "exit";			
			NextDiag.TempNode = "First time";
		break;
		
		case "guide_0":
			SetAchievement("Test_Ach");
			PlaySound("Voice\English\LE\Greguar\Greguar_01.wav");
			dialog.text = "Welcome to the Caribbean, Monsieur! Allow me to introduce myself, I am "+GetFullName(npchar)+". You are new to our colony, correct?";
			link.l1 = "Greetings, Monsieur. My name is "+GetFullName(pchar)+". Yes, I just disembarked. I don't think I have seen you before... Do I know you?";
			link.l1.go = "guide_1";
		break;
		
		case "guide_1":
			DelLandQuestMark(npchar);
			dialog.text = "No, Monsieur, you don't, but I couldn't miss an opportunity to introduce myself to a fine nobleman like yourself.\nOh, I remember my first day here, the day of my arrival to the New World. Things are very different here. The local lifestyle may ruin your health and wallet.\nThat's why I am offering you my modest help. Free of charge, which is quite rare here I assure you, haha! I can familiarize you with our colony and the archipelago. Consider it a little tour.";
			link.l1 = "That's very kind of you, merci Monsieur! I'd be glad to accept your offer. Knowledge is power after all.";
			link.l1.go = "guide_2";
			link.l2 = "I appreciate your offer, Monsieur, I really do, but I'll pass.";
			link.l2.go = "guide_exit";
		break;
		
		case "guide_exit":
			dialog.text = "As you wish, Monsieur. Anyway, it was nice meeting you. Honorable gentlemen are rare guests here. I wish you the best of luck!";
			link.l1 = "You too, "+GetFullName(npchar)+"!";
			link.l1.go = "guide_exit_1";			
		break;
		
		case "guide_exit_1":
			DialogExit();
			LAi_SetCitizenType(npchar);
			LAi_CharacterDisableDialog(npchar);
			npchar.lifeday = 0;
			DoQuestCheckDelay("NgtF3", 1.0);
			QuestPointerToLoc("FortFrance_town", "reload", "reload3_back");
		break;
		
		case "guide_2":
			dialog.text = "I am glad to hear that. It is my pleasure. Well, let me introduce you to some basics. Most colonies are built with a similar layout: a settlement on the shore, protected by a fort and city walls with gates. Nobles, rich folks, soldiers, sailors, merchants, mercenaries and criminals - all of them live together within these walls.\nSometimes you'll meet captains, monks, gypsies and beggars as well. You won't find any Indians on the streets though, those savages make people uneasy. If you want to see Indians you'll have to go out into the jungles. Follow me, I will show you some of our local establishments.";
			link.l1 = "";
			link.l1.go = "guide_3";			
		break;
		
		case "guide_3": // идем в таверну
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(npchar, "officers", "reload4_3", "Guide_tavern", -1);
			LAi_ActorFollow(pchar, npchar, "", -1);
			chrDisableReloadToLocation = true;//закрыть локацию
		break;
		
		case "guide_4":
			dialog.text = "This is the most important place in any colony - the tavern. Yes, in Europe, these places may be considered a den of scum and villainy, but here in the New World it's different. A bartender can offer you a room to sleep in, some rum, juicy gossip and a job.\nIf you need information, try talking with the patrons here. Buy a drunkard another drink and you may get something interesting in return...or not! Gambling is a popular here but beware of the cheaters. If you catch someone cheating, don't hesitate to kill him on the spot. Nobody will judge you for that.\nA tavern is also a place where you can hire crew and officers for your ship, that is, if you own one. Remember: the tavern has information, work, crew, and entertainment.";
			link.l1 = "";
			link.l1.go = "guide_9";
			locCameraFromToPos(-2.08, 5.32, 68.88, false, -15.00, -0.60, 55.00);
		break;
		
		case "guide_5": // к магазину
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(npchar, "officers", "reload6_3", "Guide_store", -1);
			LAi_ActorFollow(pchar, npchar, "", -1);
		break;
		
		case "guide_6":
			dialog.text = "The store is the trading center of any colony. Captains visit this place as often as the shipyard. Here, you can purchase munitions, supplies, or goods to trade. Commerce is quite tricky.\nFirst, it takes time to find the best places to buy or sell. Second, you need some decent trading skills to bargain with the local merchants.\nThat is why most captains hire pursers to conduct business in their stead. So don't forget to hire a professional when...or if you will get a ship of your own. This is crucial, you don't want to waste money out here. One mistake and you'll be ruined. One last thing. Merchants in stores often can offer you delivery contracts, you may find this useful in future.";
			link.l1 = "";
			link.l1.go = "guide_26";
			locCameraFromToPos(-21.10, 6.60, 45.21, false, -30.00, 3.70, 45.00);
		break;
		
		case "guide_7": // к тюрьме
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(npchar, "reload", "reload_jail", "Guide_prison", -1);
			LAi_ActorFollow(pchar, npchar, "", -1);
		break;
		
		case "guide_8":
			dialog.text = "And this is the prison. Filthy place. The worst of the criminals end up with a noose around their necks rather quickly, so mostly the small fry are kept here.\nIf you want to chat with them, speak to the prison guard. He will allow you to enter for a small fee, or even for free if you are persuasive enough! It can prove useful, but remember that lowlives can't be trusted, although they always talk sweetly and protest their innocence behind bars.";
			link.l1 = "";
			link.l1.go = "guide_9";
			locCameraFromToPos(-52.40, 7.63, 42.60, true, 15.00, -4.00, -30.00);
		break;
		
		case "guide_9": // на рынок
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(npchar, "merchant", "mrcActive4", "Guide_market", -1);
			LAi_ActorFollow(pchar, npchar, "", -1);
		break;
		
		case "guide_10":
			dialog.text = "This is the marketplace. Traders sell and buy everything you need. An armorer can provide you with blades, firearms, armors, munitions and so on. Good equipment is rare though, so don't expect to find masterpieces just lying about here. Such things come at a great price and risk, but you can find good blades and handguns here, unless someone buys them before you.\nA herbalist can offer health potions, antidotes, plants, ingredients, flasks, and if you are lucky, recipes. But why am I even telling you that, you are not an alchemist, right? The gypsies offer pagan amulets and useless crap like bat corpses. Some folks claim to know a use for such things, but it's all nonsense.\nMonks sell candles, holy talismans and other blessed trinkets: crosses, rings, writing tools. And the junkmen sell garbage as well as miscellaneous items, but if you have the necessary crafting skills, you can make something useful out of tortoise combs, nails and ropes.";
			link.l1 = "";
			link.l1.go = "guide_19";
			locCameraFromToPos(-13.58, 4.11, 69.06, false, -45.00, -6.00, 52.00);
		break;
		
		case "guide_11": // к резиденции
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(npchar, "officers", "reload3_1", "Guide_townhall", -1);
			LAi_ActorFollow(pchar, npchar, "", -1);
		break;
		
		case "guide_12":
			dialog.text = "Ah, behold the governor's palace! This is the home and the office of the most important man in the colony. Nobles visit the palace for balls and parties, businessmen and captains come here to solve both official and personal matters. It is always wise to be on the governor's friend list, he has a lot of influence on the citizens of the nation he represents.\nPrivateers can also earn good money working for governors, who are able to buy out prisoners of war. If you are wealthy and want to establish a good relationship with His Excellency, he may even honor you by gambling with you for some high stakes.\nIt seems that you are impatient, my friend. Are you in a hurry?";
			link.l1 = "Well... yes. Monsieur, to be frank, I came here to find my brother, I was told that he must be here, in Saint-Pierre. He is an important man, the governor must know him.";
			link.l1.go = "guide_13";
			locCameraFromToPos(3.14, 7.39, 37.55, false, 1.06, 9.00, 14.14);
		break;
		
		case "guide_13":
			dialog.text = "Ah-ha, I see. So you want to pay His Excellency a visit and ask him about your brother? Well, I won't delay you any further then. Our governor is called Jacques Dille du Parquet, I am sure he will do what he can.";
			link.l1 = "Tell me, who else might be able to help me? Perhaps it is unwise to trouble His Excellency about such a trifling matter?";
			link.l1.go = "guide_14";
		break;
		
		case "guide_14":
			dialog.text = "You said that your brother is well-known here. Ask around the streets. Eventually you will find someone who can help. What's your brother's name?";
			link.l1 = "Michel de Monper.";
			link.l1.go = "guide_15";
		break;
		
		case "guide_15":
			dialog.text = "Michel de Monper... Yes, I have heard this name before, but I have never been introduced to the man, so I can't help you. Good luck, Monsieur, I am sure we will meet again.";
			link.l1 = "Merci, "+GetFullName(npchar)+"!";
			link.l1.go = "guide_16";
		break;
		
		case "guide_16":
			DialogExit();
			LAi_SetCitizenType(npchar);
			LAi_CharacterDisableDialog(npchar);//запрет диалога
			LAi_group_MoveCharacter(npchar, "FRANCE_CITIZENS"); // пока идем заниматься Мишелем
			chrDisableReloadToLocation = false;//открыть локацию
			DoQuestCheckDelay("NgtF3", 1.0);
			QuestPointerToLoc("FortFrance_town", "reload", "reload3_back");
		break;
		
		case "guide_17": // к ростовщику
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(npchar, "officers", "reload8_1", "Guide_bank", -1);
			LAi_ActorFollow(pchar, npchar, "", -1);
		break;
		
		case "guide_18":
			dialog.text = "This is the house of the moneylender, or usurer, banker, their lot goes by many different names, often very rude ones. You may think whatever you want of them, but their services can help you a lot. You can deposit money, exchange doubloons and pesos, sell or buy jewellery. If you have a positive honor, you can even loan some coins, but be careful.\nUsurers offer the best prices for gems, jewels and other valuable trinkets, always visit them to sell such things. They are powerful people, so don't cross them.";
			link.l1 = "";
			link.l1.go = "guide_11";
			locCameraFromToPos(3.07, 7.64, 51.99, false, 45.00, -8.30, 4.50);
		break;
		
		case "guide_19": // к борделю
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(npchar, "officers", "reload9_1", "Guide_brothel", -1);
			LAi_ActorFollow(pchar, npchar, "", -1);
		break;
		
		case "guide_20":
			dialog.text = "Ah, a brothel. Every man visits such places, otherwise they'd be out of business! Even the noblemen do, at the cost to their honor. Be aware of that. Be nice to the girls and they can tell you some interesting things, sometimes men tend to blab about almost everything to them, and you might find this useful.\nIf you are not after someone else's secrets then consider this: there is no better cure for your mind and your body than love. If your vitality is poor - give the girls a visit. You may also drink a special potion to fix your vitality, yet it's rare and not nearly as fun. Oh, when I say your 'vitality', I don't mean scratches on your skin. You will get hit, a lot. But if they hit you hard and often or if you drink too many strong health potions, eventually you will ruin your body. Watch your condition, rest if needed, or suffer the consequences.";
			link.l1 = "";
			link.l1.go = "guide_17";
			locCameraFromToPos(-2.75, 7.07, 61.10, false, 60.00, -6.60, 42.65);
		break;
		
		case "guide_21":
			dialog.text = "Oh, you again, my friend! I see that they have let you inside Saint-Pierre's holy place - the headquarters of the Knights of Malta! You must be important. Found your brother?";
			link.l1 = "Indeed, I did...";
			link.l1.go = "guide_22";
		break;
		
		case "guide_22":
			dialog.text = "Forgive me, Monsieur, but you look quite morose...";
			link.l1 = "Putain de merde! I was hoping to get the hell out of this shithole and get back to France, yet it appears that God has other plans. It looks as if I will have to stay here for a damn long time! And the worst part is that I must become a common sailor.";
			link.l1.go = "guide_23";
		break;
		
		case "guide_23":
			dialog.text = "That is quite a sudden change in your fate, Monsieur. But don't be disheartened, you aren't going to be just any other sailor. To be the captain of your own ship is a very respected position here. You do intend to buy a ship, right?";
			link.l1 = "Oui, that's exactly what I must do... All I need is to find a shipyard and some money as soon as possible. The trouble is - I don't know where the hell a shipyard is to be found, how to sail a vessel, or where to get the money! Ca me fait chier...";
			link.l1.go = "guide_24";
		break;
		
		case "guide_24":
			dialog.text = "I wish I could fill your pockets with gold, but I am just as broke as you are. However, I can fill your head with the knowledge you so desperately need. Interested?";
			link.l1 = "Aye, that would be great.";
			link.l1.go = "guide_25";
		break;
		
		case "guide_25":
			dialog.text = "Follow me then. Let's start with the main thing - the ships.";
			link.l1 = "";
			link.l1.go = "guide_5";
		break;
		
		case "guide_26": // на верфь
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(npchar, "reload", "reload5", "Guide_shipyard", -1);
			LAi_ActorFollow(pchar, npchar, "", -1);
			chrDisableReloadToLocation = true;//закрыть локацию
		break;
		
		case "guide_27":
			dialog.text = "The shipyard. Every colony has one. A place to sell or buy a sea vessel and also to repair her. Be aware that our shipyards have nothing in common with the grand shipyards of good old Europe. These are the colonies, they don't build galleons or ships of the line here.\nLocal masters can build luggers, schooners, and sloops. Very rarely you'll see brigs and barkentines. But sometimes privateers bring prize ships they captured and shipbuilders buy them for cheap, repair them, and sell for a profit.\nI once saw a frigate on the price list! Locally made ships also have poor characteristics. Don't worry though, practicing on small and cheap vessels will allow you to progress and allow you to eventually master something better.\nOh, and the shipyard is also the place to buy cannons. There are several types of guns that you can get installed on your vessel, provided, of course, that she can carry them. Every vessel has limitations, you will never be able to put 24-pounders on a lugger. Remember that the big caliber guns are rare and expensive. On the bright side, such guns can literally vaporize the enemy's crew, sails and hull.\nOne last thing. Shipyards also provide services for aesthetes: they can paint your sails and your ships' exterior, draw emblems or coats of arms. Painting her red might not make her go faster, but will make her look much fancier.";
			link.l1 = "Interesting...";
			link.l1.go = "guide_28";
			locCameraFromToPos(-26.74, 5.77, 49.03, false, -70.00, -25.00, 150.00);
		break;
		
		case "guide_28": // в порт
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(npchar, "quest", "quest1", "Guide_port", -1);
			LAi_ActorFollow(pchar, npchar, "", -1);
		break;
		
		case "guide_29":
			dialog.text = "This is the pier, the heart of any port. I used to sail in the past, so let me tell you more about sailing.\nFirst, remember the most important thing: don't even try to steer a vessel if you haven't got enough points on your navigation skill! When the requirement is not met, then your other skills will suffer and so do your officers'.\nYou will fight worse, shoot worse, trade worse and so on.\nThat means that if you attempt to steer a man-of-war with your current navigation skill, you will not get far, in fact you might not even be capable of making a small turn.";
			link.l1 = "How do I learn this, navigation?";
			link.l1.go = "guide_30";
			locCameraFromToPos(-8.55, 4.06, 91.31, true, 40.00, -8.00, 0.00);
		break;
		
		case "guide_30":
			dialog.text = "You know what, my friend? Here's this little memo on running a ship. Read it when you get your own. A rather useful document - helped me a lot in my time.";
			link.l1 = "Very well, monsieur. Indeed, I'm not really ready to absorb so much complex knowledge right now.";
			link.l1.go = "guide_38";
			AddQuestRecordInfo("Guide_AtSea", "1");
		break;
		
		case "guide_31":
			dialog.text = "The ship's rank determines it. For example, I am experienced enough (45 points) to control a 4th rank vessel without penalties. Brigs, barkentines, fluyts. Xebecs and corvettes require more, so I won't be able to use them properly. These are not even second rank ships like frigates and heavy galleons.\nAs for giant ships of the line or man-o-war... only experts in navigation can control such monsters, it takes years to master the skill and don't forget the money. A battleship and her crew can empty your purse in a month if you are not as rich as King Louis himself.";
			link.l1 = "I see...";
			link.l1.go = "guide_32";
		break;
		
		case "guide_32":
			dialog.text = "Mind your officer positions. A boatswain trains your crew and makes boarding more effective, a purser will perform financial activities in your place and rids your ship from rats. A physician heals your wounded men and lowers the amount that die in battle, a ship joiner repairs any damage done to the ship, and boarding officers save your skin when pirates start swarming your deck.\nPay attention to the skills of candidates and their reputation.";
			link.l1 = "Reputation?";
			link.l1.go = "guide_33";
		break;
		
		case "guide_33":
			dialog.text = "Exactly. Every man has one. It shows a man for what he really is.\nIf you are an honorable man and always try to do good, then look for officers who share your ideals. And if you want to be a pirate... well, you get the idea.\nHonest folks will not work for scum, the opposite is also true.";
			link.l1 = "Got it.";
			link.l1.go = "guide_34";
		break;
		
		case "guide_34":
			dialog.text = "Now let's talk about types of ships. There are two types. Merchantmen and warships. Merchantmen or trade ships have large cargo holds and tend to be slower. Warships are fast and have strong guns, at the expense of cargo capacity. Barques, fluyts, and carracks are good, solid trade ships. Sloops, brigs, and corvettes are warships. There are hybrids of course, ships which are suitable for both trading and fighting: snows, schooners, and galleons.\nShips also have different rigging arrangements, some are mostly square rigged and some are mostly fore-and-aft rigged, which form the ship's best course angle.";
			link.l1 = "Course angle?";
			link.l1.go = "guide_35";
		break;
		
		case "guide_35":
			dialog.text = "Yes. It determines how your rigging is affected by the wind and on which course your vessel will make the best speed she is capable of. Once you are at sea, find the arrow on the mini map, that will be your course angle.";
			link.l1 = "That's a bit confusing to me. But I guess I shall learn in time.";
			link.l1.go = "guide_36";
		break;
		
		case "guide_36":
			dialog.text = "Next, your crew. You and your ship are nothing without the men who control it. Every sailor must know how to do three things. How to deal with rigging, how to operate cannons and how to fight. Every nation excels only in one of these three activities. For example, Spain has the best fighters in the world and their boarders wear armor, so grapeshots, slicing and stabbing are not quite as effective against them. I am talking about small arms of course, cannon grape shots don't give a damn about body armor.\nVisit the taverns of Spain, England and France if you want to make a dream crew, or if you want to risk it hire a pirate crew, as much as a man can hate them they are still the deadliest crew that one can have. Watch your men's morale, provide them with rum, whores, and coin on a regular basis. Do that and your men will die for you. Fail to do so and they'll create a mutiny. A motivated professional is worth ten rookies in a fight. Also, don't forget about a physician, or develop your own medicine skills in order to prevent extra casualties.";
			link.l1 = "I will remember this...";
			link.l1.go = "guide_37";
		break;
		
		case "guide_37":
			dialog.text = "Now a few words about naval battles. The Caribbean is dangerous, crawling with Spanish patrols and pirates, so eventually you will engage them in the open sea. Ship cannons use four types of ammo. Cannonballs, grape shot, chain shot, and bombs.\nCannonballs are all-purpose and the cheapest to buy, they also have the biggest effective firing range. They tear the enemy's sails, destroy their hull and kill their crew.\nChain shots have a decent range of fire, their purpose is to eliminate an enemy's rigging in order to slow them down. They are good to use when you want to chase or flee. If you are lucky, you may even take down a whole mast.\nBombs. Use them if you want to sink your opponent's vessel. Bombs do the biggest damage to the hull, but they have the second shortest range of fire, so you need to come closer first, which may prove fatal. They also cost the most of all shells.\nGrape shots are your best choice if you want to board and capture an enemy's ship. These nasty little buggers wipe out people, but have the shortest firing range makes them risky to use. But it can be worth it.\nHold your fire if you are not sure whether you can deal enough damage. Every volley comes at the price of gunpowder, time, and cannons' condition. They can explode sometimes, especially if you shoot too often. Always maneuver, try to take a better position. If the enemy is too dangerous and you can't flee, try to provoke them to shoot you constantly from a distance without taking damage. This trick will eventually empty their gunpowder supplies. It may take days, so you'd better find cover like rocks or a coastal line. Of course, such tactics will not work in the open sea.\nMines. Also a fine way to sink them all. Taunt them to chase you and drop mines. Every mine requires a decent amount of powder, but even one mine can destroy a lugger.\nGet a spyglass and use it to observe your enemy. A good spyglass will provide you with a fine tactical overview, regarding the presence of musketeer units on your opponent's vessel for instance. Enemy musketeers can mow down a lot of your men on deck, so be sure to give them a whiff of grape shot before boarding.";
			link.l1 = "Holy Jesus...that is frightening... but I guess I must be ready for anything.";
			link.l1.go = "guide_38";
		break;
		
		case "guide_38":
			dialog.text = "You'll learn, I have no doubt about that. Since you are going to be a captain and a ship owner, I will show you one more place of great importance. The harbor office. Follow me.";
			link.l1 = "";
			link.l1.go = "guide_39";
		break;
		
		case "guide_39": // к портовому управлению
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(npchar, "reload", "reload10", "Guide_portoffice", -1);
			LAi_ActorFollow(pchar, npchar, "", -1);
		break;
		
		case "guide_40":
			dialog.text = "There it is. At the harbor office you can find job offers. Freights for large merchantmen and convoy escort duty for warships. If you own a fast packet ship, they might offer you a courier job.\nI recommend earning some trust here. If you do your job well several times, they will trust you with more complicated and much better paying contracts.\nYou may also inquire about other captains and leave your excess ships here in storage for safekeeping. Open ended storage, just don't forget to pay!";
			link.l1 = "Got it.";
			link.l1.go = "guide_41";
			locCameraFromToPos(48.38, 9.48, 43.95, true, -70.00, -55.00, 150.00);
		break;
		
		case "guide_41":
			dialog.text = "Well, the city gates are close, so there is another topic I'd like to tell you about. These gates lead to the jungles. Follow me and I will tell you about stealth actions and fencing. Do you mind?";
			link.l1 = "Not at all. You have already helped me a great deal!";
			link.l1.go = "guide_42";
		break;
		
		case "guide_42":
			dialog.text = "Follow me then!";
			link.l1 = "";
			link.l1.go = "guide_43";
		break;
		
		case "guide_43": // к воротам
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(npchar, "reload", "gate_back", "Guide_gate", -1);
			LAi_ActorFollow(pchar, npchar, "", -1);
		break;
		
		case "guide_44":
			dialog.text = "So, here we have a city gate leading straight into the jungle... This is embarrassing, but I have one more memo for you to study later. This time, it's about the nuances of our land life. Take your time to read it, as it will help you better understand how to infiltrate hostile cities and how to fight on land. But for now, I suggest we step outside the gates and have a little fun - let's practice fencing.";
			link.l1 = "You're a true encyclopedia, Monsieur. Let's go! Practice sounds fun.";
			link.l1.go = "guide_48";
			locCameraFromToPos(50.58, 5.74, 23.21, false, 100.00, 0.00, 20.00);
			AddQuestRecordInfo("Guide_OnLand", "1");
		break;
		
		case "guide_45":
			dialog.text = "A document you can get at the headquarters of the Dutch West Indian Company. A sign of your peaceful intentions. This paper will allow you to enter any port until the terms have expired.\nBut there are some downsides. First, the Company has special rules and demands that any captain willing to buy the license must follow. Second, it costs a lot. And the last and the worst, you still need a 'raising flag' skill to land at ports. Otherwise you will be shot on sight by the fort's heavy cannons.";
			link.l1 = "Where is the Company's headquarters?";
			link.l1.go = "guide_46";
		break;
		
		case "guide_46":
			dialog.text = "Willemstad on Curacao. If you want to buy a license - go there, they will give you the details.";
			link.l1 = "Things are so messed up here...";
			link.l1.go = "guide_47";
		break;
		
		case "guide_47":
			dialog.text = "Don't be upset, my friend. You shall learn. Now, let's practice fencing.";
			link.l1 = "Sounds good. Let's move!";
			link.l1.go = "guide_48";
		break;
		
		case "guide_48": // телепортируем за городские ворота
			DialogExit();
			LAi_SetActorType(npchar);
			DoQuestReloadToLocation("FortFrance_ExitTown", "goto", "goto19", "Guide_ExitTown");
		break;
		
		case "guide_49":
			dialog.text = "My friend, I believe you know how to hold a sword?";
			link.l1 = "Ha! Of course I know. I was taught by the very best fencing master in Paris!";
			link.l1.go = "guide_50";
		break;
		
		case "guide_50":
			dialog.text = "Good for you. Let me teach you some theory first.\nThere are three types of cold steel: light, medium, and heavy. Every type requires different skills and abilities to master, so you will have to learn them separately.\nEvery class has it's benefits and drawbacks. Light weapons include foils and rapiers, have low stamina requirements, but deal the least amount of damage. A heavy weapon, such as an axe, can kill with a single blow, though it will exhaust your stamina very quickly, and you may have to rest in between strikes. Medium weapons, sabres or cutlasses, are the middle ground, combining good weight and damage potential.\nThere are several fencing moves and tricks at your disposal: thrust attack, chopping attack, heavy attack and group attack. You can also parry, feint and block.\nThrust attack is the fastest move, requires the smallest amount of stamina to perform, and is excellent for long rapiers. It's mostly useless for axes. The chopping attack is quite versatile, has decent speed, significant loss of stamina, it's good for sabres, broadswords and axes, but not that effective with rapiers. The heavy attack is dealt from above, an excellent choice for axes, will work fine for short sabres and cutlasses, yet rapiers are simply not designed for such moves. This attack will drain a huge amount of stamina, it is slow, but will deal crippling damage and ignores your enemy's blocks.\nBlocking is useless against heavy attacks and experienced opponents always have a chance to break your block. Parrying is much better, it opens up your opponent for attacks and forces him to lose stamina. Several successful parries and your opponent completely loses his initiative and is forced to defend himself while you have full advantage.\nFeints are tricky and risky. Fooling your opponent and immediately dealing him a quick thrust requires only a little loss of stamina, but you must be concentrated, attentive and in rhythm of the fight. Mastering this move will demand a lot of practice from you, but it is rewarding - even professional duellists and masters of sword will fall by your hand.\nIn order to maximize damage from every type of attack, you must use the right weapon for each. Thrust attack will perform best with long, light, straight rapiers or swords with a balance from 0 to 0.5. Long, curved cutlasses or sabres with a balance from 1 to 2 are excellent for chopping and heavy attacks. A heavy axe with a balance of 2 is perfect for heavy attacks, but such a weapon will require a lot of stamina and skill to use. The group attack isn't worth being your primary move, it's rather defensive, but a curved, light, long cutlass with a balance from 0.75 to 1.25 will work wonders against groups of enemies around you.\nFinally, the best weapon for feint is a dagger, consider making this move your speciality. The weight of a weapon determines how much stamina it will require for any attack move and it also affects the damage. Remember, that finding your perfect weapon may take some time and working on your fighting style will take even more.";
			link.l1 = "And what if there are several enemies?";
			link.l1.go = "guide_51";
		break;
		
		case "guide_51":
			dialog.text = "This complicates things. A decent fighter can take down a few poorly trained fools togther in the open, but if there are a dozen scondrels coming at you - avoid being surrounded at all costs, run away, find yourself a corner or some stairs, doorways, whatever, force them to fight you one by one, or two against one. They will slice you up in a second if you make a mistake, so force them to play on your terms, don't lose initiative and watch your stamina.\nThough, I have heard about a special Indian potion which allowed masters of sword and axe to kill five or six enemies at once with a few group attacks.";
			link.l1 = "A special potion?";
			link.l1.go = "guide_52";
		break;
		
		case "guide_52":
			dialog.text = "Ometochtli mixture or whatever they call it. An ancient Indian recipe. Ask merchants, someone may sell it to you someday. But you must learn alchemy first in order to use the recipe... Since we are already talking potions - let me tell you about healing.\nIf you need to fix a small wound, use a healing potions. Serious hits can be treated with an elixir. Healing mixtures, rum and wine also restore your health.\nAn antidote and mixture will do fine if you are poisoned. I also recommend a ginger root, it wonderfully freshens your breath. It also heals without any side effects, unlike essences and elixirs.";
			link.l1 = "Wait, side effects?";
			link.l1.go = "guide_53";
		break;
		
		case "guide_53":
			dialog.text = "Essences, elixirs and mixtures damage your health. As I mentioned in the beginning of our small tour, it's bad. Bad health will cause drops in your skill levels, it will decrease the total amount of your health points and stamina.\nSleeping, sex, and a rare potion called the 'Tears of Ish-Chel' I'm not exactly sure of the name, all I know is that it has some tears in it, anyway such things will restore health if it's not ruined completely. If it is too late, visit a priest, they will help for a fee.";
			link.l1 = "I see. What can you tell me about handguns?";
			link.l1.go = "guide_54";
		break;
		
		case "guide_54":
			dialog.text = "Not much to say. Point and shoot! Use grapeshot if there are several enemies. Get a musket or a rifle, they have a deadly damage and you can always hit people with a buttstock. I also heard about a blunderbuss-type musket which shoots grenades, it's an excellent weapon and very beautiful too... but I have never seen it.";
			link.l1 = "I see. Practice time?";
			if (FindCharacterItemByGroupWithout_knife_03(pchar, BLADE_ITEM_TYPE) == "") link.l1.go = "guide_55a";
			else link.l1.go = "guide_55";
		break;
		
		case "guide_55a":
			dialog.text = "Hm. I just noticed. Where is your sword? I fear that our lesson must be delayed. How did you end up without a weapon, "+pchar.name+"?";
			link.l1 = "A royal son of a bitch in a fancy suit took it from me as an advance on my brother's debt... Do you have an extra sword for me? I will return it after the lesson is over...";
			link.l1.go = "guide_55b";
		break;
		
		case "guide_55b":
			GiveItem2Character(pchar, "blade_05");
			EquipCharacterByItem(Pchar, "blade_05");
			dialog.text = "You are lucky. I do have an extra sword. I was going to sell it, but, lucky you, I was delayed.";
			link.l1 = "Merci. Shall we?";
			link.l1.go = "guide_55";
		break;
		
		case "guide_55":
			dialog.text = "En garde! And don't waste any potions that you have, we are not going to kill each other.";
			link.l1 = "As you say.";
			link.l1.go = "guide_56";
			npchar.quest.guide_win = 0;
		break;
		
		case "guide_56": // махач
			LAi_SetPlayerType(pchar);
			LAi_SetCurHPMax(pchar); 
			LAi_GetCharacterMaxEnergy(pchar);
			LAi_SetCurHPMax(npchar); 
			LAi_GetCharacterMaxEnergy(npchar);
			LAi_SetImmortal(npchar, false);
			LAi_group_Delete("EnemyFight");
			if (MOD_SKILL_ENEMY_RATE <= 6)	// На первых трёх сложностях Валинье будет ослаблен
			{
				LAi_SetHP(npchar, LAi_GetCharacterMaxHP(npchar) * 0.7, LAi_GetCharacterMaxHP(npchar) * 0.7);
				npchar.rank = 1;
				SetSelfSkill(npchar, 1, 1, 1, 1, 1);
			}
			DialogExit();
			LAi_SetWarriorType(npchar);
			LAi_group_MoveCharacter(npchar, "EnemyFight");
			// ставим проверяльщики
			LAi_SetCheckMinHP(pchar, 1, true, "Guide_HeroFail");
			LAi_SetCheckMinHP(npchar, 1, true, "Guide_HeroWin");
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			AddDialogExitQuest("MainHeroFightModeOn");
			DoQuestCheckDelay("GuideFight_tutorial", 1.0);
		break;
		
		case "guide_57": // побил гида с первого раза
			dialog.text = "You... you are a man who knows how to hold his sword. Well done, Monsieur. You need more practice, but you have the potential to become a true swordmaster.";
			link.l1 = "Merci beaucoup. What now?";
			link.l1.go = "guide_62"; // нода на выход
			if (MOD_SKILL_ENEMY_RATE >= 6)
			{
				link.l2 = "More practice you say? Are you serious? I'm tired of this patronizing tone ever since I set foot in this miserable place!";				//Пасхалка Корсары 2 для сложности СФ и выше
				link.l2.go = "guide_64";
			}
			AddComplexSelfExpToScill(50, 50, 50, 50);
			AddCharacterExpToSkill(pchar, "Leadership", 80);
		break;
		
		case "guide_58": // побил гида со второго или третьего раза
			dialog.text = "Much better! See, all you need is to concentrate. You need more practice, one day you will become a decent fencer.";
			link.l1 = "Merci beaucoup. What now?";
			link.l1.go = "guide_62"; // нода на выход
			AddComplexSelfExpToScill(20, 20, 20, 20);
			AddCharacterExpToSkill(pchar, "Leadership", 30);
		break;
		
		case "guide_59": // побили первый раз
			dialog.text = "I won, Monsieur. Move faster, parry my stabs, jump back. A rematch?";
			link.l1 = "Oui! No mercy, Monsieur!";
			link.l1.go = "guide_56";
			link.l2 = "No, I had enough. Let's finish the lesson. What now?";
			link.l2.go = "guide_62"; // нода на выход
		break;
		
		case "guide_60": // побили второй раз
			dialog.text = "I won again, "+pchar.name+"! Don't lose your initiative. Catch my hits, feint them. If you see that I am going to hit hard - jump away or parry, don't just guard. Again!";
			link.l1 = "Come, Monsieur, I shall thrash you this time!";
			link.l1.go = "guide_56";
			link.l2 = "No, I've had enough. Let's finish the lesson. What now?";
			link.l2.go = "guide_62"; // нода на выход
		break;
		
		case "guide_61": // побили третий раз
			dialog.text = "You have a lot to learn, "+pchar.name+". Don't worry, you still got a lot of time to master your fencing. But be careful, don't take any chances until you know how to hold a weapon.";
			link.l1 = "I will consider it, Monsieur, but I have to say that you were just too lucky! This blasted heat... the only reason why I didn't beat the hell out of you. Merde, let's end our fencing lesson. What now?";
			link.l1.go = "guide_62"; // нода на выход
		break;
		
		case "guide_62":
			dialog.text = "Now it's time to say farewell, Monsieur. It was a pleasure. I hope that my presentation and training did you some good and will prove useful in the future. Perhaps, we shall meet again one day.\nAnd about the money you need - talk to important people of our city. Visit all the places that I have shown you today and speak to their owners. Ask around. Take a walk to the jungle and to the fort. Find a job or... well, I am not a priest or a judge, check people's houses and see what trinkets you can find in their unlocked chests. Just do it when their backs are turned or the guards will catch you.\nGood luck, "+pchar.name+", I have a strong feeling that you have the spark of true greatness inside you. Do your best to kindle it into a roaring fire!";
			link.l1 = "Merci, Monsieur. The pleasure was mine. Godspeed!";
			link.l1.go = "guide_63";
		break;
		
		case "guide_63":
			LAi_SetCurHPMax(pchar); 
			LAi_GetCharacterMaxEnergy(pchar);
			DialogExit();
			chrDisableReloadToLocation = false;//открыть локацию
			npchar.lifeday = 0;
			DoQuestReloadToLocation("FortFrance_Town", "quest", "quest2", "");
		break;
		
		case "guide_64": // решили убить Валинье
			dialog.text = "Hold your tongue, Monsieur! I won't tolerate such insolence any further. However, I understand your reaction to a new environment, therefore I forgive your outburst this time. But mind your words from now on. Farewell, Monsieur de Maure.";
			link.l1 = "No offense, Monsieur Valinnie. If we were in the Louvre at this moment, you'd watch your tone! It's time to teach a province a final lesson. Defend yourself!";
			link.l1.go = "guide_65";
		break;
		
		case "guide_65":
			DialogExit();
			
			npchar.rank = 25;
			int iHp = MOD_SKILL_ENEMY_RATE*10+300;
			LAi_SetHP(npchar, iHp, iHp);
			SetSelfSkill(npchar, 80, 80, 80, 80, 50);
			SetShipSkill(npchar, 50, 80, 35, 30, 50, 20, 30, 20, 80);
			SetSPECIAL(npchar, 9, 5, 8, 6, 5, 10, 8);
			SetCharacterPerk(npchar, "Energaiser");
			SetCharacterPerk(npchar, "BasicDefense");
			SetCharacterPerk(npchar, "AdvancedDefense");
			SetCharacterPerk(npchar, "CriticalHit");
			SetCharacterPerk(npchar, "Tireless");
			SetCharacterPerk(npchar, "HardHitter");
			SetCharacterPerk(npchar, "Sliding");
			SetCharacterPerk(npchar, "BladeDancer");
			SetCharacterPerk(npchar, "SwordplayProfessional");
			SetCharacterPerk(npchar, "Gunman");
			SetCharacterPerk(npchar, "GunProfessional");
			GiveItem2Character(npchar, "blade_30");
			EquipCharacterbyItem(npchar, "blade_30");
			GiveItem2Character(npchar, "cirass7");
			GiveItem2Character(npchar, "obereg_7");
			GiveItem2Character(npchar, "talisman11");
			AddMoneyToCharacter(npchar, 10000);
			AddItems(npchar, "gold_dublon", 25);
			AddItems(npchar, "bullet", 5);
			AddItems(npchar, "grapeshot", 5);
			AddItems(npchar, "GunPowder", 10);
			TakeItemFromCharacter(npchar, "blade_12");
			npchar.cirassId = Items_FindItemIdx("cirass4");
			LAi_SetCurHPMax(npchar);
			LAi_GetCharacterMaxEnergy(npchar);
			LAi_SetCurHPMax(pchar); 
			LAi_GetCharacterMaxEnergy(pchar);
			LAi_SetImmortal(npchar, false);
			LAi_group_Delete("EnemyFight");
			LAi_SetWarriorType(npchar);
			LAi_group_MoveCharacter(npchar, "EnemyFight");
			npchar.SaveItemsForDead = true;
			npchar.DontClearDead = true;
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, false);
			LAi_group_SetCheck("EnemyFight", "Guide_HeroKill");
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}

string FindCharacterItemByGroupWithout_knife_03(ref chref, string groupID)
{
	ref refItm;
    string resultItemId;

	resultItemId  = "";
	for(i=TOTAL_ITEMS-1; i>=0; i--)
	{
		refItm = &Items[i];
		if( !CheckAttribute(refItm,"groupID") ) continue;
		if(refItm.groupID!=groupID) continue;
		if( !CheckAttribute(chref,"items."+refItm.id) ) continue;
		if(refItm.id == "knife_03") continue;
		if (groupID == BLADE_ITEM_TYPE)
		{
			resultItemId  = refItm.id;
		}
	}
	
	if (resultItemId != "")
	{
        return resultItemId;
	}

	return "";
}