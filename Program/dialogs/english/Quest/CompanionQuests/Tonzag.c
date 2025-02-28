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
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		case "First time":
			dialog.text = "Что вам надо?";
			link.l1 = "Ничего.";
			link.l1.go = "exit";
		break;
		
		case "startoff":
			dialog.text = "Captain de Mor! Welcome to Tortuga!";
			link.l1 = "Good day, Lieutenant. Enjoying the sea view with your friends?";
			link.l1.go = "startoff_joke";
			link.l2 = "Back off, Lieutenant.";
			link.l2.go = "startoff_silence";
			
			AddDialogExitQuestFunction("Tonzag_Arrested");
		break;
		
		case "startoff_joke":
			dialog.text = "Captain, your reputation precedes you, and the higher-ups decided to arrange a little tour of the beauties of our lovely Tortuga Island. We're starting right now-with the prison cells of the town. Your officers are also invited.";
			link.l1 = "Lieutenant, I'm not some mangy smuggler you caught on the beach. No jests, please. Explain the matters properly.";
			link.l1.go = "startoff_joke_1";
			link.l2 = "Then let's not waste any time! Lead the way, Lieutenant!";
			link.l2.go = "startoff_joke_2";
		break;
		
		case "startoff_silence":
			dialog.text = "I see that dealing with you, sailors, requires a different approach. Soldiers, prepare for battle! Captain de Maure, you and your officers are under arrest. Surrender your weapons!";
			link.l1 = "I can give you a bullet-where do you want it, Lieutenant? With you, land rats, there's no other way.";
			link.l1.go = "startoff_silence_1";
			link.l2 = "By what law? If you want to arrest an armed group without bloodshed, Lieutenant, you'll have to try harder.";
			link.l2.go = "startoff_silence_2";
		break;
		
		case "startoff_joke_1":
			dialog.text = "To me, you're all the same... Sorry but there won't be any explanations, Captain. Orders from above. Surrender your weapons, if you would be so kind.";
			link.l1 = "I don't need any trouble... not now. Do as they say.";
			link.l1.go = "exit";
			
			AddCharacterExpToSkill(pchar, "Leadership", 100);
			ChangeCharacterComplexReputation(pchar, "nobility", +5);
		break;
		
		case "startoff_joke_2":
			dialog.text = "Uh... I guess you didn't quite understand me. Captain, you and your officers are under arrest! Surrender your weapons and come with us!";
			link.l1 = "I don't need any trouble... not now. Do as they say.";
			link.l1.go = "exit";
			
			AddCharacterExpToSkill(pchar, "Fortune", 100);
		break;
		
		case "startoff_silence_1":
			dialog.text = "One more word, Captain, and we'll bury you right here. Weapons on the ground, right now!";
			link.l1 = "I don't need any trouble... not now. Do as they say.";
			link.l1.go = "exit";
			
			AddComplexSelfExpToScill(100, 100, 100, 100);
			ChangeCharacterComplexReputation(pchar, "nobility", -5);
		break;
		
		case "startoff_silence_2":
			dialog.text = "I'm not afraid of blood, Captain. Even if you miraculously survive, you'll never set foot on Tortuga again. And our military intelligence believes you greatly value your access to this island.";
			link.l1 = "I don't need any trouble... not now. Do as they say.";
			link.l1.go = "exit";
			
			AddCharacterExpToSkill(pchar, "Leadership", 100);
			ChangeCharacterComplexReputation(pchar, "authority", 5);
		break;
		
		case "tonzag_after_boarding":
			dialog.text = "Captain, things are shit! The enemy has a tight grip on us, I'm afraid they won't let go until we're dead! Our people are in real trouble right now, and most of the gun crews are knocked out!";
			link.l1 = "I'll help them. Take command and get us out of here!";
			link.l1.go = "tonzag_after_boarding_1";
			DelLandQuestMark(npchar);
		break;
		
		case "tonzag_after_boarding_1":
			dialog.text = "Yes, sir!";
			link.l1 = "";
			link.l1.go = "exit";
			
			AddDialogExitQuestFunction("Tonzag_GoToGunDeck");
		break;
		
		case "tonzag_after_victory":
			dialog.text = "Victory, Captain! The landing party has been destroyed, the enemy chose to retreat and headed south. The condition of the ship is acceptable. Alive crew: " + GetCrewQuantity(pchar) + " people. Report completed!";
			link.l1 = "Thank you! Rum for everyone and strengthen the watch until we reach the port!";
			link.l1.go = "tonzag_after_victory_1";
		break;
		
		case "tonzag_after_victory_1":
			dialog.text = "Hooray! Aye aye!";
			link.l1 = "";
			link.l1.go = "exit";
			
			AddDialogExitQuestFunction("Tonzag_AlonsoBoardingDialog");
		break;
		
		case "killer":
			dialog.text = "And there's the man himself! Did you see the bloody massacre outside? It's all your doing, traitor! But you will answer for everything: for Porto Bello, for Gruoh, and for this mine!";
			link.l1 = "Wait, what's that supposed to...";
			link.l1.go = "exit";
			
			AddDialogExitQuestFunction("Tonzag_FightInMine");
		break;
		
		case "mine_head":
			dialog.text = "";
			link.l1 = "Agh! This doesn't bode well...";
			link.l1.go = "mine_head_1";
		break;
		
		case "mine_head_1":
			dialog.text = "San Santiago, keep me safe! Villainy! What monster could commit such an act? Answer, senor!";
			link.l1 = "Calm down, señor! Introduce yourself first! Yes, a monstrous carnage happened here, but the people who committed it are already dead. I personally 'decorated' the mines with their remains...";
			link.l1.go = "mine_head_2";
		break;
		
		case "mine_head_2":
			dialog.text = "I am " + GetFullName(npchar) + ", chief engineer of the royal Los Teques mine. I have just returned from a months-long assignment and...what do I see! What happened here is a crime against God and humanity, so I ask you to surrender your weapons immediately. The authorities of Caracas will investigate this villainy!";
			link.l1 = " I cannot comply, senor, and I swear I had nothing to do with this massacre! But if you persist, your own body will be added to the pile.";
			link.l1.go = "mine_head_3";
		break;
		
		case "mine_head_3":
			dialog.text = "I do not fear death, but I always know when to retreat. Go, but remember, I will report what happened here, and I won't leave out a single detail!";
			link.l1 = "I cannot agree to that, señor. I'm sorry it has come to this. To battle!";
			link.l1.go = "mine_head_fight";
			link.l2 = "It seems you're looking for death, señor. But today, no one else will die. We are leaving, and I hope this detail makes it into your report as well!";
			link.l2.go = "mine_head_peace";
		break;
		
		case "mine_head_peace":
			DialogExit();
			
			AddDialogExitQuestFunction("Tonzag_LetMineHeadGo");
		break;
		
		case "mine_head_fight":
			DialogExit();
			
			AddDialogExitQuestFunction("Tonzag_FightMineHead");
		break;
		
		case "alonso":
			dialog.text = "What should we do with the prisoner, Captain?";
			link.l1 = "Nothing special, just don't let him die or escape.";
			link.l1.go = "alonso_1";
		break;
		
		case "alonso_1":
			dialog.text = "Aye aye! I take it, I won't need to participate in today's interrogation, Captain?";
			link.l1 = "Why not? Decided to change your profession, Alonso?";
			link.l1.go = "alonso_2";
		break;
		
		case "alonso_2":
			dialog.text = "Ha-ha, no, Captain. I love this job, but it seems you've got a new master of the trade on board!";
			link.l1 = "Hercule? Where did you get that idea?";
			link.l1.go = "alonso_3";
		break;
		
		case "alonso_3":
			dialog.text = "Well, Captain, the old man brought his toolkit just for the occasion and put it to use. I won't even have to get mine out. Ha!";
			link.l1 = "I see... As you were!";
			link.l1.go = "exit";
			
			AddDialogExitQuestFunction("Tonzag_DrinkAgain");
		break;
		
		case "captive":
			dialog.text = "Ah... Charles de Maure. Allow me to offer my apologies on behalf of the entire League. The order to leave you alone reached us too late. Our organization has no claims against you, Captain. As for this bald animal... Ugh! As long as he's on your leash, he's safe, but my advice to you is not to keep him and let him rot in the gutter where he belongs!";
			link.l1 = "Thanks for the recommendation, but I'm more interested in why someone is protecting me from your mercenaries.";
			link.l1.go = "captive_1";
		break;
		
		case "captive_1":
			dialog.text = "I can't know, Captain. I suppose the instructions came from our new patron. Heard of him, traitor? The League is back on top now!";
			link.l1 = "And who is he?";
			link.l1.go = "captive_2";
		break;
		
		case "captive_2":
			dialog.text = "I can't know, Captain, and even if I did, such things we don't disclose.";
			link.l1 = "In that case, tell me something else, and you can go wherever you want. You have my word.";
			link.l1.go = "captive_3";
		break;
		
		case "captive_3":
			dialog.text = "Just like that? Fine, Captain, ask your questions and let me go. I promise I won't return to the League, even if I could.";
			link.l1 = "Why are you so fixated on Hercule? Too much trouble for just one deserter.";
			link.l1.go = "captive_4";
		break;
		
		case "captive_4":
			dialog.text = "What did you tell him, you dog? Everything is not as it seems, Captain! The League is constantly moving, codes change, employers vary. Want to leave? Sure thing! The exit is closed only for the top officers, and this scum has never been one. His wife, sure, but we respected Madame Tonzag too much not to make an exception for her.";
			link.l1 = "Then why?";
			link.l1.go = "captive_5";
		break;
		
		case "captive_5":
			dialog.text = "There was a thing Porto Bello... It was big. You see, your friend didn't just leave, didn't just break the contract, didn't just kill the group that came to finish his job. He caused a real massacre in the streets, significantly complicating our relationship with the Castilians. A rare pirate raid sows as much terror as that the good Catholics experienced on that day. Hell, I might have even been impressed if someone else had done it.";
			link.l1 = "Another massacre? How interesting. Keep going.";
			link.l1.go = "captive_6";
		break;
		
		case "captive_6":
			dialog.text = "The then Vice-Director of the Company, Rodenburg, intervened. He somehow managed to hush up the whole affair, but not before we lost many of our best men to the Spanish punitive operations. After some time passed, however, we were once again doing business with them... Ah! But we didn't forget anything, and as soon as the opportunity arose, we tried to get even. The instigator of it all, Tonzag, had to be killed.";
			link.l1 = "You didn't succeed in that. What about the mine?";
			link.l1.go = "captive_7";
		break;
		
		case "captive_7":
			dialog.text = "We were forced to do it. Getting rid of that scum required too much expense; we needed gold. All because of him... But the attempted assassination failed, and I returned to Los Teques to tidy up a bit... How did you figure out where to look?";
			link.l1 = "It doesn't matter. I need to meet with your leader. I want to settle the misunderstanding personally, as the guarantees from your mysterious patron can expire at any moment.";
			link.l1.go = "captive_8";
		break;
		
		case "captive_8":
			dialog.text = "I'm sure they're already waiting for you in Caracas, Captain. See, I'm hiding nothing from you.";
			link.l1 = "";
			link.l1.go = "exit";
			
			AddDialogExitQuestFunction("Tonzag_HoldDialog");
		break;
		
		case "captive_9":
			dialog.text = "Commander Arno died, Austin is in charge now.";
			link.l1 = "";
			link.l1.go = "exit";
			
			AddDialogExitQuestFunction("Tonzag_HoldDialog2");
		break;
		
		case "captive_10":
			dialog.text = "I've answered all your questions, Captain. Keep your word.";
			link.l1 = "I'm letting you go. Get off my ship, and pray that there's no ambush waiting for me in Caracas.";
			link.l1.go = "captive_spare";
			link.l2 = "Thanks for the interesting talk. Accusing Hercule of causing a massacre after what I saw in the mine was a bit much, though. Off to hell, where you belong.";
			link.l2.go = "captive_execute";
		break;
		
		case "captive_execute":
			DialogExit();
			
			AddDialogExitQuestFunction("Tonzag_ExecuteCaptive");
		break;
		
		case "captive_spare":
			DialogExit();
			
			AddDialogExitQuestFunction("Tonzag_ReturnToCabin2");
		break;
		
		case "cureer":
			dialog.text = "Gentlemen, you are invited to a meeting. They are waiting for you at the church, so security is guaranteed.";
			link.l1 = "That was quick...";
			link.l1.go = "exit";
			
			AddDialogExitQuestFunction("Tonzag_CureerGoAway");
		break;
		
		case "ostin":
			StartQuestMovie(true, false, true);
			PlaySound("VOICE\" + LanguageGetLanguage() + "\OliverTrast02.wav");
			dialog.text = "Charles de Maure. Hercule. You won't leave here alive.";
			link.l1 = "Always a nice way to start a conversation. Do you really need all this?";
			link.l1.go = "ostin_1";
		break;
		
		case "ostin_1":
			dialog.text = "With you, Captain, things are not quite simple. You see, our new patron insisted that you be left alone...and he can shove his requests up his ass! I hate your kind big time! You sail under your pretty, white sails, thinking that ice won't melt in your mouth. But when the steal of my blade enters you, you all scream like girls. Gotta love that, Charles, let me tell ya! It's been a while since I've done it...and now I have you right in front of me, pretty boy.";
			link.l1 = "You are sick, mate.";
			link.l1.go = "ostin_2";
		break;
		
		case "ostin_2":
			dialog.text = "No, I cannot let you go. With your friend, on the other hand, it's much even simpler - my boys have no need for him, but there are still some of his old measurable League palls who are not quite convinced of effectiveness of my methods...Too used to work clean, for the clean doubloons, from the clean Company. But I know just the thing that will change their minds - one bold sinner's head on a platter, ha-ha!";
			link.l1 = "You've chosen the wrong venue for that, you loon. Are you really going to start a battle in a church?";
			link.l1.go = "ostin_3";
		break;
		
		case "ostin_3":
			dialog.text = "Sure, why not? Feel bad for the folks? It might not be as lucrative as in Los Teques, but we'll still have a good time. We'll paint the walls of God's house, ah-ha! Captain, you'll provide plenty of paint.";
			link.l1 = "I get it. You envy of us, don't you, you mad rat? Envy our freedom? That the girls are happy to see us and that coins jingle in our pockets? Look at yourself: where did you patrons dig you up, pig? Who let you into the church?";
			link.l1.go = "ostin_4";
		break;
		
		case "ostin_4":
			dialog.text = "Eat dirt, you little shit!";
			link.l1 = "";
			link.l1.go = "exit";
			
			AddDialogExitQuestFunction("Tonzag_ChurchVystrel");
		break;
		
	}
} 
