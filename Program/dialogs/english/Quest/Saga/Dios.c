// Хосе Диос - картограф
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
	int i;
	string sTemp;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			dialog.text = "Do you want something?";
			if (CheckAttribute(pchar, "questTemp.Saga.SharkHunt") && pchar.questTemp.Saga.SharkHunt == "dios")
			{
				link.l3 = TimeGreeting()+"! Tell me, are you Jose Dios, the cartographer?";
				link.l3.go = "island";
			}
			link.l1 = "No, nothing.";
			link.l1.go = "exit";	
			NextDiag.TempNode = "First time";
		break;
		
		case "island":
			dialog.text = "Yes, that's me. I don't know you, senor. What do you want from me?";
			link.l1 = "My name is "+GetFullName(pchar)+" and I was sent by Jan Svenson. Do you remember him?";
			link.l1.go = "island_1";
		break;
		
		case "island_1":
			dialog.text = "Ah, senor Svenson! Sure I remember him! Come, make yourself comfortable... How is the respected Jan doing?";
			link.l1 = "Thanks, he is doing fine. Senor Dios, I need your help. I want to consult with you about a matter which you must be familiar with due to your profession. Jan recommended you as a geography expert of the Caribbean region...";
			link.l1.go = "island_2";
		break;
		
		case "island_2":
			dialog.text = "I am listening, Senor. What do you want to know about the archipelago's geography?";
			link.l1 = "They say that there is an island or some other kind of formation North-West from Havana, between Cuba and the Gulf of Mexico. This island has never been plotted on any map. I'd like to know the trustworthiness of these gossips.";
			link.l1.go = "island_3";
		break;
		
		case "island_3":
			dialog.text = "Hm... You have asked about something that is stirring me since many years. This place you've mentioned has been attracting the inquisitive minds of geographers for a long time, but nobody has ever been brave enough to explore that region.";
			link.l1 = "Why?";
			link.l1.go = "island_4";
		break;
		
		case "island_4":
			dialog.text = "Thing is that the place is some sort of natural anomaly. The probability of storms in that region is much higher than anywhere else. Perhaps the reason lies in the cold sea current, but this is just my hypothesis. A lot of ships have disappeared there and that was enough to make sailors avoid that place, all of the main sea routes are passing far from that region anyway.";
			link.l1 = "I take it that you also don't know the truth...";
			link.l1.go = "island_5";
		break;
		
		case "island_5":
			dialog.text = "Exactly, Senor. But I have a couple of historical documents and some material evidence, so I have all rights to suspect a high probability of that place's existence.";
			link.l1 = "Can you tell me more?";
			link.l1.go = "island_6";
		break;
		
		case "island_6":
			dialog.text = "Sure. The most important evidence is the historical document with extracts from the journal of captain Alvarado who has visited the Island in 1620. Quite an interesting story I tell you!";
			link.l1 = "Captain Alvarado? It is the second time I hear that name...";
			link.l1.go = "island_7";
		break;
		
		case "island_7":
			dialog.text = "I am not surprised. The story of captain Alvarado has been part of folklore for years. It changed, got filled with rumors, lies and dreams, so here it is - the legend of the Island of the Abandoned Ships.\nGossip can change, but the paper and ink cannot, they stay intact for hundreds of years. Here, read this story - perhaps, it will help you unveil what you are looking for.";
			link.l1 = "Thanks! Got anything else?";
			link.l1.go = "island_8";
		break;
		
		case "island_8":
			dialog.text = "There is a theory that the bottom of the sea in that area rises high enough to form a vast shoal. And I have already mentioned the current. There is also a large accumulation of seagulls and other sea birds according to sailors' talks.\nAlvorado mentioned names of vessels which were part of admiral Francisco Betancourt's squadron, a squadron that was lost more than fifty years ago. I doubt that this is just a coincidence...";
			link.l1 = "I will return to my ship and read Alvarado's notes carefully. Thank you for your help, Senor Dios!";
			link.l1.go = "island_9";
		break;
		
		case "island_9":
			dialog.text = "You're welcome. Actually I didn't help you at all, you haven't got the coordinates of the place and neither do I. I can't even prove that there is an inhabited island out there. But as far as I understand, you intend to explore this area?\nIf so, then be aware that I will be really grateful for any information, especially if it is provided with material proof. It seems that you are a wealthy man, but I will find a way to repay you.";
			link.l1 = "Good. Then we got a deal, Senor Dios. Perhaps my notes will be read by someone in the future too... And someone might even write a legend...";
			link.l1.go = "island_10";
		break;
		
		case "island_10":
			dialog.text = "Why not? Senor "+pchar.name+", I see that you are an adventurous man who travels a lot, so I want to ask you to do something.";
			link.l1 = "Yes? I am listening.";
			link.l1.go = "island_11";
		break;
		
		case "island_11":
			dialog.text = "You know that I am a cartographer. So, I have been drawing maps of the Caribbean archipelago for two years, compiling the admiral's atlas for the Vice King's contest of Nueva Granada. But all of my twenty-four maps were stolen from my house in the most insolent way while I was captured by pirates, the ones senor Svenson saved me from.\nI am sure that the attack was organized by one of my competitors in order to acquire my maps. It has been a long time but I have not seen a single map from my set again.";
			link.l1 = "I see. You want me to return your maps.";
			link.l1.go = "island_12";
		break;
		
		case "island_12":
			dialog.text = "Exactly. Perhaps you will find them during your future adventures. It is easy to recognize them - my sign is on each and everyone of them. I will generously reward you if you are miraculously able to collect all twenty-four maps.";
			link.l1 = "Fine. I will attentively look at every map I'll find in the archipelago from now on. Well, I have to go now. Thank you for the interesting conversation and for the document.";
			link.l1.go = "island_13";
		break;
		
		case "island_13":
			DialogExit();
			AddQuestRecordInfo("LSC_Alvorado", "1");
			AddQuestRecord("SharkHunt", "4");
			pchar.questTemp.Saga.SharkHunt = "LSC";
			NextDiag.CurrentNode = "Dios";
			AddCharacterExpToSkill(pchar, "Fortune", 50);//везение
			pchar.questTemp.AdmiralMap = "true";
		break;
		
		case "Dios":
			dialog.text = "A-ah, it is you, senor "+GetFullName(pchar)+"? Got anything interesting to tell me?";
			if (CheckAttribute(pchar, "questTemp.AdmiralMap") && CountAdmiralMapFromCharacter() > 0 && CountAdmiralMapFromCharacter() < 24 && !CheckAttribute(npchar, "quest.mapinfo"))
			{
				link.l3 = TimeGreeting()+"! Senor Dios, please, take a look at the map I've found. It must be one of your maps according to the sign.";
				link.l3.go = "map_info";
			}
			if (CheckAttribute(pchar, "questTemp.AdmiralMap") && CountAdmiralMapFromCharacter() > 23)
			{
				link.l3 = TimeGreeting()+"! Senor Dios, I have good news for you. I was able to collect the complete set of your unique maps, just like you wanted. Here are all twenty-four maps.";
				link.l3.go = "amap";
			}
			if (CheckAttribute(pchar, "questTemp.LSC.Dios")) // был в LSC
			{
				link.l4 = TimeGreeting()+"! Yes, I have. I was at that mystic place we were talking about.";
				link.l4.go = "LSC";
			}
			link.l9 = "Nothing so far, Senor. Just wanted to see how you're doing.";
			link.l9.go = "exit";
			NextDiag.TempNode = "Dios";
		break;
		
		case "map_info":
			dialog.text = "Show me... (taking a look) Of course! This is one of my maps for the admiral's atlas! Captain, I really ask you to find all of them! I understand that it's almost impossible but still... I don't want to lose hope.";
			link.l1 = "Don't lose it, Senor. I have found this map, so there is a chance that I will also find the rest. They are still in the Caribbean.";
			link.l1.go = "map_info_1";
		break;
		
		case "map_info_1":
			dialog.text = "Your optimism really encourages me, Senor captain. Perhaps I will still be able to receive an opportunity to show don Juan de Cordova who the best cartographer of the archipelago is!";
			link.l1 = "You will be able to beat all your competing ill-wishers. The maps are really wonderful... Farewell, Senor!";
			link.l1.go = "exit";
			npchar.quest.mapinfo = "true";
			NextDiag.TempNode = "Dios";
		break;
		
		case "amap":
			Achievment_Set("ach_CL_110");
			dialog.text = "I can't believe my eyes! Have you really found them? All of them?";
			link.l1 = "Yes. It wasn't easy, but I was lucky in this search. Take your maps. They are so wonderful, that I am sorry to part with them.";
			link.l1.go = "amap_1";
		break;
		
		case "amap_1":
			for(i=1; i<=24; i++)
			{
				sTemp = IdentifyAdmiralMapLast();
				if (sTemp != "") RemoveItems(pchar, sTemp, 1);
			}
			Log_Info("You have given the complete set of admiral's maps");
			PlaySound("interface\important_item.wav");
			dialog.text = "Incredible! This is just too incredible! To be honest, I never believed that this moment would happen.";
			link.l1 = "Dum spiro, spero, Senior Dios. You may face don Cordova now. I am sure he will value your talents highly.";
			link.l1.go = "amap_2";
		break;
		
		case "amap_2":
			dialog.text = "You have my thanks, Captain! You don't even realize what a great service you have done for me. And as I have promised - I will reward you. I also have a gift for you. I think that as a sailor you will find it very useful.";
			link.l1 = "You have intrigued me, Senor!";
			link.l1.go = "amap_3";
		break;
		
		case "amap_3":
			GiveItem2Character(pchar, "spyglass5"); 
			Log_Info("You have received a ship telescope");
			PlaySound("interface\important_item.wav");
			dialog.text = "Here! This is a ship telescope of my design. It is unique and you won't find another one like that anywhere else. The lenses were made in Europe by the most skillful master in Spain. Its case was made by a friendly gunsmith. A special tripod will help you point the device despite of any rolling. You can see everything you need, be it of a ship or a fort.";
			link.l1 = "Such a wounderful a gift! Thank you, Senor Dios.";
			link.l1.go = "amap_4";
		break;
		
		case "amap_4":
			dialog.text = "Use it, Senor captain. I hope that my telescope will serve you well.";
			link.l1 = "No doubt! I am looking forward to planting it on the deck of my ship and looking through it.";
			link.l1.go = "amap_5";
		break;
		
		case "amap_5":
			dialog.text = "You will be surprised, I can assure you... Thanks again for saving my maps!";
			link.l1 = "Thank you as well, senor. I think we will see each other again. But for now, I bid you goodbye. I will go try out your magnificent device. Farewell!";
			link.l1.go = "amap_6";
			link.l2 = "Thank you as well, senor. A nautical telescope is a unique and very useful thing for a sailor. Still, it may be no more valuable than a set of your maps. I kindly envy Don de Cordova. Ah! I'd love to have such beautiful maps on my captain's desk in my cabin.";
			link.l2.go = "amapcopy_01";
		break;
		
		case "amap_6":
			DialogExit();
			NextDiag.CurrentNode = "Dios";
			AddCharacterExpToSkill(pchar, "Fortune", 1000);//везение
			AddCharacterExpToSkill(pchar, "Leadership", 1000); // харизма
			AddCharacterExpToSkill(pchar, "Sneak", 300);//скрытность (раз телескоп дали)
			ChangeCharacterComplexReputation(pchar, "nobility", 10);// репутация-известность
			ChangeCharacterComplexReputation(pchar, "authority", 5);// репутация-авторитет
			ChangeCharacterNationReputation(pchar, SPAIN, 20);
			ChangeOfficersLoyality("good_all", 5);
			DeleteAttribute(pchar, "questTemp.AdmiralMap");
		break;
		
		case "amapcopy_01":
			AddCharacterExpToSkill(pchar, "Fortune", 1000);//везение
			AddCharacterExpToSkill(pchar, "Leadership", 1000); // харизма
			AddCharacterExpToSkill(pchar, "Sneak", 300);//скрытность (раз телескоп дали)
			ChangeCharacterComplexReputation(pchar, "nobility", 10);// репутация-известность
			ChangeCharacterComplexReputation(pchar, "authority", 5);// репутация-авторитет
			ChangeCharacterNationReputation(pchar, SPAIN, 20);
			ChangeOfficersLoyality("good_all", 5);
			DeleteAttribute(pchar, "questTemp.AdmiralMap");
			dialog.text = "Alas, senor, but the maps are one of a kind. And if I started making copies, the uniqueness of this atlas would be lost as soon as Don Juan de Cordova found out that someone else had the same ones.";
			link.l1 = "Hmm... Senor Dios, is there any way you would make an exception?";
			link.l1.go = "amapcopy_02";
		break;
		
		case "amapcopy_02":
			dialog.text = "Exception?";
			link.l1 = "Both you and I are honest people; we had the opportunity to convince each other of that. If you would make a copy of your maps for me, I would swear that no one would ever know about it. Understand: your maps are truly magnificent, and for me, as a sailor, this atlas is a real treasure. Moreover, I would generously pay you for your work.";
			link.l1.go = "amapcopy_03";
		break;
		
		case "amapcopy_03":
			dialog.text = "Senor "+pchar.lastname+", I don't doubt for a moment that you would keep your word. And considering what you have done for me, it is very difficult for me to refuse your request. Moreover, the fact that you, an excellent sailor, so highly appreciate my maps is already a valuable compliment for me as a cartographer.";
			link.l1 = "Believe me, I did not exaggerate one bit. So what do you say?";
			link.l1.go = "amapcopy_04";
		break;
		
		case "amapcopy_04":
			dialog.text = "Very well, I agree to make you a copy of this atlas. But there is a small problem. When my precious atlas was stolen, the thieves took all my tools too - maybe to make sure that could I never make more maps or maybe to also pawn them to my competitors. And if I am to make more maps of such quality, I cannot use ordinary stationery equipment.\nI tried buying writing supplies at the market, but had no luck - there is nothing for sale. If you can get me the necessary supplies, I will make copies of these maps for you.";
			link.l1 = "No problem, I will bring you quality writing supplies. And what about payment?";
			link.l1.go = "amapcopy_05";
		break;
		
		case "amapcopy_05":
			dialog.text = "I don't want to seem stingy, senor... But I'll have to ask you for three chests of doubloons for this job. Also, I will need a month to finish the job - such maps cannot be made in a couple of hours.";
			link.l1 = "Of course, I agree! The value of your maps far exceeds the amount you mentioned.";
			link.l1.go = "amapcopy_06";
		break;
		
		case "amapcopy_06":
			dialog.text = "Then I'll be waiting for you with the supplies needed and with the agreed-upon payment. As soon as you bring everything, I will start working.";
			if(GetCharacterItem(pchar,"chest") >= 3 && GetCharacterItem(pchar,"mineral21") > 0)
			{
				link.l1 = "You won't have to wait long: as luck would have it, I happen to have everything you require. Here you go, please.";
				link.l1.go = "amapcopy_07";
			}
			link.l2 = "You won't have to wait long, senor!";
			link.l2.go = "amapcopy_exit";
		break;
		
		case "amapcopy_07":
			dialog.text = "Fantastic news! You know, for a true cartographer, there is nothing more joyful than when his work is so highly valued. I must admit, I am glad that a true professional sailor will use my work. Now I need a month to finish them. Afterwards, I will be waiting for you at my place!";
			link.l1 = "I'll be back in a month, senor Dios. And again, thank you very much!";
			link.l1.go = "amapcopy_08";
		break;
		
		case "amapcopy_08":
			TakeNItems(pchar,"chest", -3);
			TakeNItems(pchar,"mineral21", -1);
			Log_info("You handed over writing supplies and three chests with doubloons.");
			PlaySound("interface\important_item.wav");
			SetTimerFunction("Amapcopy_comlete", 0, 0, 30);
			pchar.questTemp.AdmiralMapCopy = "wait";
			NextDiag.CurrentNode = "amapcopy_waitmonth";
			DialogExit();
		break;
		
		case "amapcopy_exit":
			DialogExit();
			NextDiag.CurrentNode = "amapcopy_waitchest";
		break;
		
		case "amapcopy_waitchest":
			dialog.text = "Greetings, senor "+pchar.lastname+"! Did you bring what I asked for?";
			link.l1 = "Not yet, senor Dios. But I will definitely bring everything!";
			link.l1.go = "amapcopy_exit";
			if(GetCharacterItem(pchar,"chest") >= 3 && GetCharacterItem(pchar,"mineral21") > 0)
			{
				link.l2 = "Yes, senor Dios. Here are your new writing supplies and the agreed-upon payment.";
				link.l2.go = "amapcopy_07";
			}
		break;
		
		case "amapcopy_waitmonth":
			if(CheckAttribute(pchar,"questTemp.AdmiralMapCopy") && pchar.questTemp.AdmiralMapCopy == "complete")
			{
				dialog.text = "And here you are, my dear friend! I hope you don't mind me calling you that?";
				link.l1 = "Not at all, my friend. I am truely glad that we have become friends.";
				link.l1.go = "amapcopy_09";
			}
			else
			{
				dialog.text = "Welcome, senor! I beg your pardon, but the maps are not ready yet!";
				link.l1 = "Yes, I remember that you said that you would need a month. I merely stopped by to check on you.";
				link.l1.go = "amapcopy_waitmonth_01";
			}
		break;
		
		case "amapcopy_waitmonth_01":
			NextDiag.CurrentNode = "amapcopy_waitmonth";
			DialogExit();
		break;
		
		case "amapcopy_09":
			dialog.text = "I have wonderful news for you! I have finally finished a copy of the admiral's atlas. I will keep the original for myself, as I still intend to participate in the employment of the Vice-King of New Grenada. But the copies are yours! I hope they will serve you well.";
			link.l1 = "Thank you very much, senor! You have no idea how valuable your atlas is for someone like me! I swear on my honor: no one will ever know that you made this copy for me!";
			link.l1.go = "amapcopy_10";
		break;
		
		case "amapcopy_10":
			GiveAdmiralAtlasToCharacter(pchar);
			Log_Info("You received a set of admiral's maps.");
			PlaySound("interface\important_item.wav");
			dialog.text = "I'm glad you're satisfied. Moreover, since everything has turned out this way, I have one more offer for you.";
			link.l1 = "What is it? I'm listening very carefully.";
			link.l1.go = "best_map";
		break;
		
		case "best_map":
			dialog.text = "While I was drawing these maps for you, a thought occurred to me that while they are good for an explorer, they don't provide everything a sea captain needs. See for yourself: all the bays, capes, and lagoons on them are depicted very accurately, but you cannot use them to plot a course between the islands.";
			link.l1 = "That's true, you can't determine the course by them. But I by no means dare to complain, senor Dios! You have made the maps for me just like we agreed, nothing less.";
			link.l1.go = "best_map_01";
		break;
		
		case "best_map_01":
			dialog.text = "But I can also make an archipelago map for you! And not the kind you can buy from the Dutch West India Company, but an unique, excellent map.";
			link.l1 = "Thank you, senor Dios, but I don't need such a map. Still, thank you very much for the offer!";
			link.l1.go = "best_map_02";
			link.l2 = "Are you kidding?! Senor Dios, how could I possibly refuse? Just tell me what you require - I won't spare any money or tools!";
			link.l2.go = "best_map_04";
		break;
		
		case "best_map_02":
			dialog.text = "Well, I had to offer. In any case, it was a pleasure doing business with you, senor "+pchar.lastname+"!";
			link.l1 = "Likewise! Good luck to you!";
			link.l1.go = "best_map_03";
		break;
		
		case "best_map_03":
			DeleteAttribute(pchar, "questTemp.AdmiralMapCopy");
			DialogExit();
			NextDiag.CurrentNode = "Dios";
		break;
		
		case "best_map_04":
			dialog.text = "You've already brought me the tools, thank you. I'll need a regular archipelago map, and I also ask for a boussole and a working chronometer: the map must be accurate, otherwise it will only be a hindrance to you. And as for payment - I ask for one chest with doubloons.";
			link.l1 = "A regular archipelago map, a boussole, a working chronometer, and one chest with doubloons... Why do you need all this? I thought you would just make a copy, like with your island maps...";
			link.l1.go = "best_map_05";
		break;
		
		case "best_map_05":
			dialog.text = "Yes, just like with the other maps, I've already made a copy of the general archipelago map. The client was the same - the Vice-King of New Grenada, Don Juan de Cordova. He needed this map for the captain of a huge squadron that sails between the Old and New World through the Atlantic. But the map is already in the hands of its owner.";
			link.l1 = "Now I understand. You'll need to draw this map again?";
			link.l1.go = "best_map_06";
		break;
		
		case "best_map_06":
			dialog.text = "Exactly. That's why I need a regular map to orient myself by, as well as navigation instruments for more accurate measurements. It will take me about a week to create - after all, it's not the first time I'm drawing such a map. Oh, the condition is the same as before: this must remain between us. The Vice-King may get angry if he finds out that I'm drawing such maps not just for him.";
			if(CheckAMapItems())
			{
				link.l1 = "I remember that, Senor Dios. Don't worry, no one will find out about these maps. And I already have everything that you require with me. Here, take it.";
				link.l1.go = "best_map_07";
			}
			link.l2 = "I remember that, Senor Dios. Don't worry, no one will find out about these maps. And I will bring everything that you require, just wait.";
			link.l2.go = "best_map_07e";
		break;
		
		case "best_map_07e":
			DialogExit();
			NextDiag.CurrentNode = "best_map_waititems";
		break;
		
		case "best_map_waititems":
			dialog.text = "Greetings, my dear friend! Have you brought what I asked for?";
			link.l1 = "Not yet, Senor Dios. But I will definitely bring it!";
			link.l1.go = "best_map_07e";
			if(CheckAMapItems())
			{
				link.l2 = "Yes, Senor Dios. Here is everything you have asked for: a regular map of the archipelago, a boussole, a working chronometer, and the agreed-upon payment.";
				link.l2.go = "best_map_07";
			}
		break;
		
		case "best_map_07":
		    Log_Info("You handed over a regular map of the archipelago, a boussole, a tariffed chronometer, and a chest with doubloons.");
			TakeNItems(pchar,"chest", -1);
			TakeNItems(pchar,"map_normal", -1);
			TakeNItems(pchar,"bussol", -1);
			TakeNItems(pchar,"clock2", -1);
			dialog.text = "Well, then I'll get to work. Come back to me in a week, and I promise you won't regret it!";
			link.l1 = "I have no doubt, Senor. See you in a week!";
			link.l1.go = "best_map_08";
		break;
		
		case "best_map_08":
			SetTimerFunction("AdmAtlas_comlete", 0, 0, 7);
			NextDiag.CurrentNode = "best_map_wait";
			pchar.questTemp.AdmiralAtlas = true;
			DialogExit();
		break;
		
		case "best_map_wait":
			if(CheckAttribute(pchar,"questTemp.AdmiralAtlas") && pchar.questTemp.AdmiralAtlas == "complete")
			{
				dialog.text = "Ah, here you are, Senor "+pchar.lastname+"! I am pleased to inform you that I have completed the map of the archipelago! And I can assure you, it's just as good as the first drawing I made for Don Juan de Cordova!";
				link.l1 = "My friend... This map is astonishing! It's nothing short of a masterpiece! How can I thank you for everything you've done for me?";
				link.l1.go = "best_map_09";
			}
			else
			{
				dialog.text = "Greetings, Senor! I must apologize, but the map is not ready yet.";
				link.l1 = "Yes, I remember that you needed a week. I just came to check on you.";
				link.l1.go = "best_map_wait_01";
			}
		break;
		
		case "best_map_wait_01":
			NextDiag.CurrentNode = "best_map_wait";
			DialogExit();
		break;
		
		case "best_map_09":
			dialog.text = "Oh, come on now, my friend. It was a pleasure for me to create such maps for a noble captain who truly appreciates them. Ah yes, you can have your copy of the regular map back. Good luck on the high seas!";
			link.l1 = "Thank you so much! You're right, these maps are priceless to me. Farewell, Senor Dios!";
			link.l1.go = "best_map_10";
		break;
		
		case "best_map_10":
			TakeNItems(pchar,"Map_Best", 1);
			TakeNItems(pchar,"map_normal", 1);
			Log_Info("You received an excellent archipelago map!");
			PlaySound("interface\important_item.wav");
			NextDiag.CurrentNode = "Dios";
			DialogExit();
		break;
		
		case "LSC":
			dialog.text = "Really?! Have you found it? Make yourself comfortable, I think the coming conversation will take a while, am I right?";
			link.l1 = "I really have a lot to tell you about the island. But, first, I want you to promise me something. I see that you are a man of honor, so I am sure that you will keep your word...";
			link.l1.go = "LSC_1";
		break;
		
		case "LSC_1":
			dialog.text = "What are you talking about, Captain?";
			link.l1 = "There are people living there... and they won't be happy if someone meddles in their life. I don't think that a possible arrival of some 'research' squadron will be welcomed.";
			link.l1.go = "LSC_1_1";
		break;
		
		case "LSC_1_1":
			dialog.text = "";
			link.l1 = "So I want you to give me your word of honor that you won't publish any information which can be used to find the Island within ten years after our conversation. You are welcome to publish any information about the locals, their life and so on, just don't reveal the location of the island.";
			link.l1.go = "LSC_2";
		break;
		
		case "LSC_2":
			dialog.text = "I agree, Captain. I give you the word of a nobleman that I won't tell anyone neither the location of the Island nor any information which could harm its inhabitants within the next ten years.";
			link.l1 = "Listen to my story then. Write it down if you want. So, the Island is made of a lot of wrecked ships whose shells are lying on a wide shoal...";
			link.l1.go = "LSC_3";
		break;
		
		case "LSC_3":
			DialogExit();
			SetLaunchFrameFormParam("Two hours later...", "LSC_FinalDiosStory", 0, 5);
			LaunchFrameForm();
			WaitDate("", 0, 0, 0, 2, 10); //крутим время
			RecalculateJumpTable();
		break;
		
		case "LSC_4":
			dialog.text = "Incredible! You have told me very valuable information, Captain! Offsprings of admiral de Betancourt are living at the Island! Now we know what happened to his squadron. And there is one fewer blank spot on the map of the Caribbean archipelago now... Thank you very much for your story, "+pchar.name+"!";
			link.l1 = "See now why I have asked you to be really careful in retelling my information?";
			link.l1.go = "LSC_5";
		break;
		
		case "LSC_5":
			dialog.text = "I see. You can be sure that I will keep my word. Tell me... do you have any material attributes from the Island?";
			if (CheckCharacterItem(pchar, "LSC_navigation_map"))
			{
				link.l1 = "I have sailing directions to the Island of the Abandoned Ships. Here, take a look. They allow you to sail a small ship through the reefs and debris and to safely land at the Island. It is impossible to reach the Island without those directions.";
				link.l1.go = "LSC_6";
			}
			else
			{
				link.l1 = "Unfortunately, I don't have any.";
				link.l1.go = "LSC_7_1";
			}
		break;
		
		case "LSC_6":
			Log_Info("You have given sailing directions");
			PlaySound("interface\important_item.wav");
			dialog.text = "(looking) Such an excellent document! It was drawn by a man who is skilled in cartography. Even I couldn't do it better. Incredible! Captain, why don't you give me these sailing directions? A story is a story, but this paper must be shown to the most famous geographers in the Old World!";
			link.l1 = "Senor Dios, unfortunately, I need this document for myself. As I have said before, it is impossible to pass through the reefs surrounding the Island without it. But you can make a copy of the directions if you wish, and I shall be only glad if you also have them in your possession.";
			link.l1.go = "LSC_10";
			//link.l2 = "Senor Dios, unfortunately, I need this item for myself. As I have said, it is impossible to bypass the reefs around the Island without it. I'd sacrifice it in the name of science, but... I am sure that you understand.";
			//link.l2.go = "LSC_7";
		break;
		
		case "LSC_7":
			Log_Info("You received sailing directions");
			PlaySound("interface\important_item.wav");
			dialog.text = "Absolutely. It is your right, though it's a pity... Anyway, thanks for your story! You have done a great service for geographers, cartographers and other curious people.";
			link.l1 = "You're welcome, Senor. Well, I have to go now. Farewell.";
			link.l1.go = "LSC_8";
		break;
		
		case "LSC_7_1":
			dialog.text = "What a pity... Anyway, thanks for your story! You have done a great service for geographers, cartographers and other curious people.";
			link.l1 = "You're welcome, Senor. Well, I have to go now. Farewell.";
			link.l1.go = "LSC_8";
		break;
		
		case "LSC_8":
			dialog.text = "Sure, "+pchar.name+". You have spared a lot of your time for me. Send my regards to Senor Svenson!";
			link.l1 = "Goodbye, Senor Dios.";
			link.l1.go = "LSC_9";
		break;
		
		case "LSC_9":
			DialogExit();
			NextDiag.CurrentNode = "Dios";
			AddCharacterExpToSkill(pchar, "Fortune", 400);//везение
			AddCharacterExpToSkill(pchar, "Leadership", 500); // харизма
			ChangeCharacterComplexReputation(pchar, "nobility", 5);// репутация-известность
			ChangeCharacterComplexReputation(pchar, "authority", 2);// репутация-авторитет
			ChangeCharacterComplexReputation(pchar, "fame", 3);
			ChangeCharacterNationReputation(pchar, SPAIN, 5);
			DeleteAttribute(pchar, "questTemp.LSC.Dios");
			LAi_SetOwnerType(npchar);
		break;
		
		case "LSC_10":
			Log_Info("You received sailing directions");
			PlaySound("interface\important_item.wav");
			dialog.text = "Thank you so much! That is very kind of you. Give me some time...";
			link.l1 = "...";
			link.l1.go = "LSC_11";
		break;
		
		case "LSC_11":
			DialogExit();
			SetLaunchFrameFormParam("Two hours later", "", 0.1, 3.0);
			LaunchFrameForm();
			WaitDate("", 0, 0, 0, 2, 0);
			npchar.dialog.currentnode = "LSC_12";
			LAi_SetActorType(npchar);
			LAi_ActorDialogDelay(npchar, pchar, "", 4.0);
		break;
		
		case "LSC_12":
			//RemoveItems(pchar, "LSC_navigation_map", 1);
			dialog.text = "Thank you very much! It was very kind of you. Now we have got not only oral evidence but also material one... I won't leave you unrewarded, Captain. I have got a small gift for you.";
			link.l1 = "What kind of a gift?";
			link.l1.go = "LSC_13";
		break;
		
		case "LSC_13":
			sld = characterFromId("Pirates_shipyarder");
			sld.quest.sextant = "true"; // атрибут Алексу на хронометр
			GiveItem2Character(pchar, "sextant1"); 
			PlaySound("interface\important_item.wav");
			dialog.text = "I am fond not only of cartography and geography, but also of mathematics and astronomy. It took me a year of trying to create an universal tool for taking latitude and longitude. And I've made some progress. Here, take a look:\nThis is my sextant. I've designed it myself. Problem is, it doesn't work. It requires an extremely accurate chronometer. Even those which were made by the best craftsmen give unacceptable errors over time. Therefore, my tool is worthless for now.\nBut since you travel a lot, perhaps you will find a chronometer accurate enough for the sextant to work. Once you find such a clock - you won't need a Boussole, a compass, an astrolabe, sand clocks and other crappy chronometers - my tool will replace them all.";
			link.l1 = "Thank you, Senor Dios. Let's hope that I will find a chronometer which will make your invention work. I'd like to have such a device... in working condition. Well, I have to go now. Farewell.";
			link.l1.go = "LSC_8";
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		//--> блок реагирования на попытку залезть в сундук
		case "Man_FackYou":
			dialog.text = LinkRandPhrase("You're "+ GetSexPhrase("a thief, I see! Guards, seize him","a thief, I see! Guards, seize her") +"!!!", "I can't believe it! I turned away for a second - and you're diving into my belongings! Stop a thief!!!", "Guards! Robbery! Stop a thief!!!");
			link.l1 = "Aaaah, devil!!!";
			link.l1.go = "fight";
		break;
		
		case "fight":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			LAi_SetOwnerTypeNoGroup(npchar);
			LAi_group_Attack(NPChar, Pchar);
			if (rand(3) != 1) SetNationRelation2MainCharacter(sti(npchar.nation), RELATION_ENEMY);
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		//<-- блок реагирования на попытку залезть в сундук
	}
}

bool CheckAMapItems()
{
	return GetCharacterItem(pchar,"chest")      && 
		   GetCharacterItem(pchar,"map_normal") &&
		   GetCharacterFreeItem(pchar,"bussol") &&
		   GetCharacterFreeItem(pchar,"clock2");
}