// Чад Каппер - боцман Акулы и тюремщик
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
			dialog.text = "Want something?";
			link.l1 = "No, it's nothing.";
			link.l1.go = "exit";			
			NextDiag.TempNode = "First time";
		break;
		
		// вариант R
		case "Chimiset":
			dialog.text = "Well-well... So you are the mysterious thief? Hm... You don't look like a miserable pilferer.";
			link.l1 = "Listen, mister, you are mistaken. I am a newcomer here, so how could I know that the cargo hold where your people caught me, was your private zone?";
			link.l1.go = "Chimiset_1";
		break;
		
		case "Chimiset_1":
			dialog.text = "Oh really? Nice try pal... Where did you come here from then?";
			link.l1 = "From Main... Through a strange statue. I myself don't know how to explain what has happened.";
			link.l1.go = "Chimiset_2";
		break;
		
		case "Chimiset_2":
			dialog.text = "Statue? Ha-ha! You are a funny lad, aren't you... Fine, I will explain it all to you myself: you swam through the hole in the ship and wanted to sneak into our storehouse. How come I do not recognize your face? I know all the Rivados...";
			link.l1 = "What Rivados? I don't know what you are talking about! Listen, I came here about an hour ago...";
			link.l1.go = "Chimiset_3";
		break;
		
		case "Chimiset_3":
			dialog.text = "Don't shout, I am not an idiot. Aye, I have heard enough of your bollocks about the statue and I find it quite amusing. I find it fucking hilarious. How about we laugh about it together? Ha-ha-ha!... Why aren't you laughing? It was a nice joke... Rivados. But the jokes are over now. I will leave you to rot in jail, pal.";
			link.l1 = "I am not Rivados! My name is Charles de Maure!";
			link.l1.go = "Chimiset_4";
		break;
		
		case "Chimiset_4":
			dialog.text = "First time, huh? Hm... maybe you are speaking the truth. Answer me, are you one of them?!";
			link.l1 = "I swear to you, I have never heard the name before, I am not one of them!";
			link.l1.go = "Chimiset_5";
		break;
		
		case "Chimiset_5":
			dialog.text = "Really? Fine. Prove it. Go downstairs, there is a Rivados sitting in a cage. He is a dangerous wizard. Kill him, only then will I be convinced. I will also forget about your illegal intrusion in our warehouse\nSo? Are you ready? Don't be scared, the wizard is unarmed and weak. Well, he might turn you to dust with some spell, like the one that delivered you to San Augustine's hold...";
			link.l1 = "If you'd seen that spell in action then you would not be so skeptical. I doubt that you would have even survived it...";
			link.l1.go = "Chimiset_6";
		break;
		
		case "Chimiset_6":
			dialog.text = "Enough talking! Are you doing this or not? If so, then take this machete and deal with the wizard. Otherwise you will spend the rest of your life in a cage. Understood?";
			link.l1 = "Of two evils I choose the lesser one. Give me the machete.";
			link.l1.go = "Chimiset_7";
		break;
		
		case "Chimiset_7":
			PlaySound("interface\important_item.wav");
			GiveItem2Character(pchar, "slave_02");
			EquipCharacterbyItem(pchar, "slave_02");
			dialog.text = "Good boy. Take it, go and kill the black man. His cage is unlocked. Don't you try anything stupid now, we wont hesitate to finish you off if you as much as think of it! Now go!";
			link.l1 = "Why? Are you afraid that I will gut you lads with this rusty piece of metal crap?";
			link.l1.go = "Chimiset_8";
		break;
		
		case "Chimiset_8":
			dialog.text = "My patience is running dry. Head to the cargo hold and do as you are told!";
			link.l1 = "Fine, fine, relax. I am leaving...";
			link.l1.go = "exit";
			NextDiag.TempNode = "Chimiset_9";
			LAi_SetPlayerType(pchar);
			bDisableCharacterMenu = false;//разлочим Ф2
		break;
		
		case "Chimiset_9":
			dialog.text = "You are testing my patience, bastard! You do not want to irritate me...";
			link.l1 = "Fine, fine, relax.";
			link.l1.go = "exit";
			NextDiag.TempNode = "Chimiset_9";
		break;
		
		case "Fightfail_Final":
			dialog.text = "Have you killed that negro wizard? Good... I am glad. You have proven that you are not Rivados.";
			link.l1 = "When am I finally going to be released from this damn tub? I need to meet Shark immediately.";
			link.l1.go = "Fightfail_Final_1";
		break;
		
		case "Fightfail_Final_1":
			dialog.text = "You'll meet him, sure... You will meet him on the road to hell!";
			link.l1 = "What?!";
			link.l1.go = "Fightfail_Final_2";
		break;
		
		case "Fightfail_Final_2":
			DialogExit();
			DoQuestCheckDelay("LSC_ChadGuardAttack_Fail", 0.1);
		break;
		
		// вариант N
		case "prisoner":
			dialog.text = "Ha! Just look at this. What are you doing here in my prison?";
			link.l1 = "Your name is Chad Kapper, right? My name is "+GetFullName(pchar)+" and I am here on behalf of Shark Dodson. He gave me the keys.";
			link.l1.go = "prisoner_1";
		break;
		
		case "prisoner_1":
			dialog.text = "From the admiral? Hm, I see. Are you his new errand boy?";
			link.l1 = "Show some respect, mister. I am not serving anyone, neither Shark nor you, and I am not going to tolerate such language.";
			link.l1.go = "prisoner_2";
		break;
		
		case "prisoner_2":
			dialog.text = "Ha-ha, I like you, pal! Forget I said anything... So, what's your business here?";
			link.l1 = "Shark has given an order to free Chimiset, he is imprisoned here.";
			link.l1.go = "prisoner_3";
		break;
		
		case "prisoner_3":
			dialog.text = "The Rivados wizard? Hm. That is strange, I am really surprised to hear that...";
			link.l1 = "Shark gave an order. He wants to make peace with Rivados.";
			link.l1.go = "prisoner_4";
		break;
		
		case "prisoner_4":
			dialog.text = "A-ah, I see now. Fine, I will send a man to Rivados. They will come here and take their jester.";
			link.l1 = "Why can't you just let him go?";
			link.l1.go = "prisoner_5";
		break;
		
		case "prisoner_5":
			dialog.text = "I could, but this would be too dangerous for him. Chimiset is known around here, his life will be worth nothing once he steps on the 'Esmeralda' - a territory of his enemies, Narwhals. There is no other way from the Tartarus, we can not let the old man swim around the island!\nAnd if someone kills him, Rivados will blame us, me to be specific! See, I don't want problems that can be avoided. So I will let him out only under the protection of his clan's fighters. Perhaps, you wish to speak with Chimiset yourself? He is a funny type...";
			if (CheckAttribute(npchar, "quest.chimiset_talk")) link.l1 = "I've spoken with him already, he really is a strange man. Whatever, I have to go. See you, Chad!";
			else link.l1 = "That is what I intended. I'll go and talk to him.";
			link.l1.go = "prisoner_6";
		break;
		
		case "prisoner_6":
			DialogExit();
			sld = characterFromId("Chimiset");
			sld.quest.capper_talk = "true"; // разговор с Каппером состоялся
			if (!CheckAttribute(npchar, "quest.chimiset_talk")) chrDisableReloadToLocation = true;//закрыть локацию
			else chrDisableReloadToLocation = false;//открыть локацию
			NextDiag.CurrentNode = "prisoner_7";
		break;
		
		case "prisoner_7":
			dialog.text = "I will send a courier to Rivados and they will take their wizard. Don't worry, pal, you can go.";
			link.l1 = "Fine.";
			link.l1.go = "exit";
			NextDiag.TempNode = "prisoner_7";
		break;
		
		// вариант M
		case "Aeva_attack":
			dialog.text = "...he must have already opened the barrel, I am sure. This is his favorite whiskey, damn Irish. It will be over soon, I've put enough arsenic in it to kill a herd...";
			link.l1 = "";
			link.l1.go = "Aeva_attack_1";
			CharacterTurnToLoc(npchar, "quest", "quest2");
		break;
		
		case "Aeva_attack_1":
			dialog.text = "Ah? Damn it, what are you doing here? Get lost!";
			link.l1 = "I'd been looking for you for a long time... poisoner. That is odd, I don't see the Cyclops. You wanted to take Shark's position, right?";
			link.l1.go = "Aeva_attack_2";
			CharacterTurnByChr(npchar, pchar);
		break;
		
		case "Aeva_attack_2":
			dialog.text = "Ha-ha, Shark must be dead by now! And you will follow him soon, spy!";
			link.l1 = "...";
			link.l1.go = "Aeva_attack_fight";
		break;
		
		case "Aeva_attack_fight":
			DialogExit();
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
			LAi_SetWarriorType(npchar);
			LAi_group_MoveCharacter(npchar, "EnemyFight");
			for (i=1; i<=3; i++)
			{
				sld = CharacterFromID("ChadNarval_"+i);
				LAi_SetWarriorType(sld);
				LAi_group_MoveCharacter(sld, "EnemyFight");
			}
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("EnemyFight", "LSC_CapperDieAeva");
			AddDialogExitQuest("MainHeroFightModeOn");	
		break;
		
		case "Aeva_attack_2":
			dialog.text = "... this is going to be a hell of a drink. Damn Irishman has been dreaming of this whiskey for a long time, so he will guzzle it all in a second. Where is the arsenic? Pour more of it, just to be sure... And then our friend Fazio will deliver this barrel to the admiral as a present from Narwhals, ha-ha! Am I right, dear Giuseppe? Do you want to live?\nArgh! Look, we have guests! What do you want, jackass? Get lost before we nail you!";
			link.l1 = "Your plan has failed, Kapper. I was following in the tracks of yours and I know what you and your pal Cyclops are going to do. Toss the arsenic! You will not poison Shark!";
			link.l1.go = "Aeva_attack_3";
		break;
		
		case "Aeva_attack_3":
			dialog.text = "Ah, sleuth! Well, you die first then! Lads, to arms!";
			link.l1 = "...";
			link.l1.go = "Aeva_attack_fight";
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
	}
}
