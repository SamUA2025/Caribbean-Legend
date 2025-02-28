void ProcessDialogEvent()
{
	ref sld, NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			dialog.text = "This is a bug. Let the devs know.";
			link.l1 = "I will!";
			link.l1.go = "exit";
			NextDiag.TempNode = "First time";
		break;
		
		case "RedChieftain":
			dialog.text = "How, paleface. I see that you are captain of big canoe. Me Kanauri. I am chief of Cayman - mighty Arawak tribe. Me want talk with you.";
			link.l1 = "I am listening, chief. What troubles have brought you to me?";
			link.l1.go = "RedChieftain_0";
			link.l2 = "What do you want from me, you foul red-skinned ape? Go back to your jungles and don't bother me with your requests.";
			link.l2.go = "RedChieftain_exit";
			DelLandQuestMark(npchar);
			DelMapQuestMarkCity(pchar.questTemp.RedChieftain.StartCity);
		break;
		
		case "RedChieftain_exit":
			dialog.text = "Gu-u! Wasn't white captain educated to be polite? I was give offer. You earn heap lot wampum but now I go. Farewell, paleface.";
			link.l1 = "Go, get lost...";
			link.l1.go = "RedChieftain_exit_1";
		break;
		
		case "RedChieftain_exit_1":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorRunToLocation(npchar, "reload", "reload4_back", "none", "", "", "", -1);
			npchar.lifeday = 0;
			DeleteAttribute(pchar, "questTemp.RedChieftain");
			chrDisableReloadToLocation = false;
			ChangeIndianRelation(-3.0);
		break;
		
		case "RedChieftain_0":
			dialog.text = "White brother insightful like owl, cunning like serpent. Trouble happening to Indian. Big-big canoe of white men come to my village. They take many Cayman, my people, put them on their canoe and take them out to Mother of All Waters...";
			link.l1 = "Wait... are you saying that your people were enslaved by white men from a ship?";
			if (sti(pchar.Basenation) == SPAIN) link.l1.go = "RedChieftain_2";
			else link.l1.go = "RedChieftain_1";
		break;
		
		case "RedChieftain_1":
			dialog.text = "You speak true, white brother. I know those paleface are no friends to you. These cruel white men of Spanish tribe. They take my people. But I find them. Spanish make Indian work from dawn to dusk, dive deep in Mother of Waters, find shells filled with tears of gods.";
			link.l1 = "Pearl diving... That is a brutal job.";
			link.l1.go = "RedChieftain_3";
			pchar.questTemp.RedChieftain.Spa = "true";
			pchar.questTemp.RedChieftain.AttackNation = SPAIN;
		break;
		
		case "RedChieftain_2":
			dialog.text = "You speak true, white brother. I know those people are not friends to you. They of English tribe. They take my people. But I find them. English make Indian work from dawn to dusk, dive deep in Mother of Waters, find shells filled with tears of gods.";
			link.l1 = "Pearl diving... This is a tough work.";
			link.l1.go = "RedChieftain_3";
			pchar.questTemp.RedChieftain.Eng = "true";
			pchar.questTemp.RedChieftain.AttackNation = ENGLAND;
		break;
		
		case "RedChieftain_3":
			dialog.text = "Indian sick and die from slavery. White man no pity for Indian. Lash and pistol is law of white for Indian. Me old. Have no men for fight. Cayman Arawaks peaceful people, we invent peace pipe. I ask you, white brother, to unsheathe lash and pistol against evil white, save Indian Arawak.";
			link.l1 = "Are you asking me to declare war? You have to understand chief, my resources are limited.";
			link.l1.go = "RedChieftain_4";
		break;
		
		case "RedChieftain_4":
			dialog.text = "No go on warpath. Free Indian. My people. We give you all tears of gods we have on canoes. Kill evil white, help Indian, get tears of gods, sell them for much-much wampum. Heap wampum";
			link.l1 = "Ah, I see now. No, Canauri, I can't help you. I can't do it now - my ship is in need of repair, no supplies left...";
			link.l1.go = "RedChieftain_wait";
			link.l2 = "In that case, it would be my pleasure. Let's discuss details. Where are your people? You said that you'd already found them...";
			link.l2.go = "RedChieftain_5";
		break;
		
		case "RedChieftain_wait":
			dialog.text = "Gu-u! I can wait, white brother... I be in this port one more moon, look for protector of my people. You find me here when you ready.";
			link.l1 = "...";
			link.l1.go = "RedChieftain_wait_1";
		break;
		
		case "RedChieftain_wait_1":
			DialogExit();
			//LAi_ActorGoToLocator(npchar, "quest", "quest1", "RedChieftainStay", -1);
			chrDisableReloadToLocation = false;
			bDisableFastReload = false;
			SetFunctionTimerCondition("RedChieftainDelete", 0, 0, 30, false);
			
			sld = CharacterFromID("RedChieftain");
            //LAi_SetStayType(sld);
			sld.dialog.currentnode = "RedChieftain_wait_2";
			AddLandQuestMark(sld, "questmarkmain");
			AddMapQuestMarkCity(pchar.questTemp.RedChieftain.StartCity, false);
		break;
		
		case "RedChieftain_wait_2":
			dialog.text = "You back, white brother? Will you help me to punish evil men and save Indian?";
			link.l1 = "Ready as I'll ever be.";
			link.l1.go = "RedChieftain_wait_4";
			link.l2 = "I still need to get prepared.";
			link.l2.go = "RedChieftain_wait_3";
		break;
		
		case "RedChieftain_wait_3":
			dialog.text = "I will be here, white brother.";
			link.l1 = "...";
			link.l1.go = "exit";
			NextDiag.Tempnode = "RedChieftain_wait_2";
		break;
		
		case "RedChieftain_wait_4":
			DelLandQuestMark(npchar);
			DelMapQuestMarkCity(pchar.questTemp.RedChieftain.StartCity);
			dialog.text = "I am very glad that you agreed, white brother!";
			link.l1 = "Let's talk about the details, Canauri. Where are your people? You said that you'd already found them...";
			link.l1.go = "RedChieftain_5";
			pchar.quest.RedChieftainDelete.over = "yes"; //снять таймер
		break;
		
		case "RedChieftain_5":
			if (CheckAttribute(pchar, "questTemp.RedChieftain.Spa"))
			{
				AddMapQuestMarkShore("Shore19", true);
				pchar.questTemp.RedChieftain.Island = "Cumana";
				pchar.questTemp.RedChieftain.Shore = "Shore19";
				pchar.questTemp.RedChieftain.Add1 = "Spanish";
				pchar.questTemp.RedChieftain.Add2 = "Carupano Cove, not far from Cumana";
				dialog.text = "They are in camp at Carupano Cove near Spanish camp called Cumana. Every day they sail on boats at the sea, dive water, deep-deep...";
				link.l1 = "I see. And the Spanish are watching over them while they dive?";
				link.l1.go = "RedChieftain_6";
			}
			else
			{
				AddMapQuestMarkShore("Shore54", true);
				pchar.questTemp.RedChieftain.Island = "SantaCatalina";
				pchar.questTemp.RedChieftain.Shore = "Shore54";
				pchar.questTemp.RedChieftain.Add1 = "English";
				pchar.questTemp.RedChieftain.Add2 = "Cape Perlas, not far from Blueweld";
				dialog.text = "They make camp at Cape Perlas near English camp called Blueweld. Every day they sail on boats at the sea, dive water, deep-deep...";
				link.l1 = "I see. And, of course, the English are watching over them?";
				link.l1.go = "RedChieftain_6";
			}
		break;
		
		case "RedChieftain_6":
			dialog.text = "Yes, two big canoe of palefaces with firesticks and big knives. Camp on shore also guarded - Indian can not escape.";
			link.l1 = "What kind of ships? Can you describe them? How big are they? What kind of sails?";
			link.l1.go = "RedChieftain_7";
		break;
		
		case "RedChieftain_7":
			dialog.text = "This canoe big, but Canauri has seen bigger. Front sail is very-very tilted, make three sides like this. (He draws three lateen sails and a trapazoidal sail in the dirt) Top is narrow, bottom is wide.";
			link.l1 = "Sounds and looks like a schooner...";
			link.l1.go = "RedChieftain_8";
		break;
		
		case "RedChieftain_8":
			dialog.text = "Canauri not know that word. Paleface very careful if they see other canoe - they land Indian and wait until other canoe sail away.";
			link.l1 = "Cautious sons of bitches...how can I get close to them?";
			link.l1.go = "RedChieftain_9";
		break;
		
		case "RedChieftain_9":
			dialog.text = "If paleface brother take small canoe then he can sneak near the shore. I show way. But bring only one small canoe or paleface dog see and drive Indian from boat into jungles...";
			link.l1 = "Got it. I'll need a lugger or a sloop for this operation. Great. A sloop against two schooners... God...and here I thought this was going to be easy!";
			link.l1.go = "RedChieftain_10";
		break;
		
		case "RedChieftain_10":
			dialog.text = "Do we go, white brother? We have less than a moon.";
			link.l1 = "Yes. Get on my ship, chief. Let's not waste time!";
			link.l1.go = "RedChieftain_11";
		break;
		
		case "RedChieftain_11":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorRunToLocation(npchar, "reload", "reload1_back", "none", "", "", "", -1);
			AddPassenger(pchar, npchar, false);
			SetCharacterRemovable(npchar, false);
			chrDisableReloadToLocation = false;
			bDisableFastReload = false;
			pchar.quest.Red_Chieftain_2.win_condition.l1 = "location";
			pchar.quest.Red_Chieftain_2.win_condition.l1.location = pchar.questTemp.RedChieftain.Island;
			pchar.quest.Red_Chieftain_2.function = "RedChieftain_CreateShooner";
			if(bImCasual) NewGameTip("Exploration mode: timer is not disabled. Meet the deadline!");
			SetFunctionTimerCondition("RedChieftainOver", 0, 0, 30, false);
			AddQuestRecord("RedChieftain", "1");
			AddQuestUserData("RedChieftain", "sText1", pchar.questTemp.RedChieftain.Add1);
			AddQuestUserData("RedChieftain", "sText2", pchar.questTemp.RedChieftain.Add2);
		break;
		
		case "RedChieftain_pearl":
			dialog.text = "Thank you, white brother! You save Cayman Arawak tribe! We owe you great debt. Path is free of paleface dog and Indian can run free in jungles. We give you all tears of gods left on boats.";
			link.l1 = "Well, let's see what you've got...";
			link.l1.go = "RedChieftain_pearl_1";
		break;
		
		case "RedChieftain_pearl_1":
			DialogExit();
			pchar.questTemp.RedChieftain.Ind = 1;
			AddDialogExitQuest("RedChieftain_Pearl");
		break;
		
		case "RedChieftain_pearl_give":
			int iSmallPearl = rand(200)+rand(250)+rand(200)+250;
			int iBigPearl = rand(100)+rand(100)+rand(50)+150;
			TakeNItems(pchar, "jewelry52", iBigPearl);
			TakeNItems(pchar, "jewelry53", iSmallPearl);
			PlaySound("interface\important_item.wav");
			Log_SetStringToLog("The Chief has given you "+iSmallPearl+" small and "+iBigPearl+" big pearls.");
			dialog.text = LinkRandPhrase("I glad that tears of gods are yours, brother of Arawak!","Indian thank you, brave paleface!","Take our catch, white brother!");
			link.l1 = LinkRandPhrase("Glad to help you!","Thanks, redskinned brother!","Great!");
			link.l1.go = "exit";
			pchar.questTemp.RedChieftain.Ind = sti(pchar.questTemp.RedChieftain.Ind)+1;
			AddDialogExitQuest("RedChieftain_Pearl");
		break;
		
		case "RedChieftain_final":
			chrDisableReloadToLocation = false;//открыть локацию
		// belamour legendary edition -->
			if(sti(pchar.questTemp.RedChieftain.Tartane) > 5)
			{
				dialog.text = "Canauri thank you again, paleface brother! You rescue all the canoes with the Indian! For Canauri it is very important to save all canoe because you also save grandson of Canauri, whom the evil paleface take into slavery. As child, my grandson love to swim very much, and Kanauri give him this charmed amulet so that grandson does not drown. Now the grandson no longer wants to swim and give the amulet to me so that I can give it to you, palefaced brother. I hope that tears of the gods and this gift will be a sufficient reward for life of Arawak. And now we say goodbye - it's time for us to return to our native village.";
				link.l1 = "Good luck, Cunauri! Glad your grandson survived! I pray this evil never befalls you again!";
				link.l1.go = "RedChieftain_final_1Obereg";
			}
			else
			{
				dialog.text = "Canauri thanks you again, paleface brother! I hope that tears of gods will be enough reward for life of Indians. Now goodbye, we go to native village.";
				link.l1 = "Good luck, Cunauri! Never fall into slavery again!";
				link.l1.go = "RedChieftain_final_1";
			}
			if(SandBoxMode)
			{
				//if(CheckAttribute(pchar,"questTemp.SanBoxTarget"))
				//{
					//if(makeint(pchar.questTemp.SanBoxTarget) == 2 ||  makeint(pchar.questTemp.SanBoxTarget) == 5)
					//{
						pchar.questTemp.SanBoxTarget.RedChieftain = true;
						ChangeCharacterComplexReputation(pchar, "fame", 25);
					//}
				//}
			}
		break;
		
		case "RedChieftain_final_1Obereg":
			DialogExit();
			RemovePassenger(Pchar, npchar);
			LAi_ActorRunToLocation(npchar, "reload", "reload1_back", "none", "", "", "", -1);
			npchar.lifeday = 0;
			int n1 = pchar.questTemp.RedChieftain.Tartane;
			for (i=1; i <=n1; i++)
			{
				sld = characterFromId("RC_Indian_"+i);
				LAi_ActorRunToLocation(sld, "reload", "reload1_back", "none", "", "", "", -1);
			}
			InterfaceStates.Buttons.Save.enable = true;//разрешить сохраняться
			TakeNItems(pchar, "talisman10", 1);
			PlaySound("interface\important_item.wav");
			Log_Info("You have received Seeker's obereg");
			locations[FindLocation(pchar.questTemp.RedChieftain.Shore)].DisableEncounters = false; //энкаутеры открыть
			AddComplexSelfExpToScill(50, 50, 50, 50);
			AddCharacterExpToSkill(pchar, "Fortune", 50);//везение
			AddQuestRecord("RedChieftain", "9");
			CloseQuestHeader("RedChieftain");
			DeleteAttribute(pchar, "questTemp.RedChieftain");
		break;
		// <-- legendary edition
		
		case "RedChieftain_final_1":
			DialogExit();
			RemovePassenger(Pchar, npchar);
			LAi_ActorRunToLocation(npchar, "reload", "reload1_back", "none", "", "", "", -1);
			npchar.lifeday = 0;
			int n = pchar.questTemp.RedChieftain.Tartane;
			for (i=1; i <=n; i++)
			{
				sld = characterFromId("RC_Indian_"+i);
				LAi_ActorRunToLocation(sld, "reload", "reload1_back", "none", "", "", "", -1);
			}
			InterfaceStates.Buttons.Save.enable = true;//разрешить сохраняться
			locations[FindLocation(pchar.questTemp.RedChieftain.Shore)].DisableEncounters = false; //энкаутеры открыть
			AddComplexSelfExpToScill(50, 50, 50, 50);
			AddCharacterExpToSkill(pchar, "Fortune", 50);//везение
			AddQuestRecord("RedChieftain", "8");
			CloseQuestHeader("RedChieftain");
			DeleteAttribute(pchar, "questTemp.RedChieftain");
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}
