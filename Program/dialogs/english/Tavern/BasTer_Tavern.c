// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("What questions do you have?", "How can I help you, " + GetAddress_Form(NPChar) + "?"), "What is it, " + GetAddress_Form(NPChar) + "...", "This is the third time you're bothering me now...",
                          "More questions, I presume?", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("I changed my mind...", "I've got nothing to talk about at the moment."), "Umph, where has my memory gone...",
                      "Yes, it really is the third time...", "No, what questions?...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			//Jason, суп из черепахи
			if (CheckAttribute(PChar, "questTemp.Terrapin") && pchar.questTemp.Terrapin == "baster" && !CheckAttribute(npchar, "quest.terrapin"))
			{
				link.l1 = "I'm looking for my old messmate Fernand Luc. I've got a couple of questions for him. I heard he really had a good time here a week ago...";
				link.l1.go = "terrapin";
			}
			//Sinistra Путеводная звезда
			if (CheckAttribute(pchar, "questTemp.PZ_BasTerTavern"))
			{
				link.l1 = "My friend and I agreed to meet here, but I don't see him anywhere. Do you know where he went? Is he still in town, or at least on the island? His name is Longway - he's Chinese.";
				link.l1.go = "PZ_BasTerTavern_1";
			}
		break;
		
		//суп из черепахи
		case "terrapin":
			dialog.text = "He might still be having a good time while he's in hell. Your mate's dead, so you're a tad late, captain. That man over there sitting at the farthest table paid for his funeral, although I get the feeling that he's the same man that caused it. He's got a hanging face, as they say. His name is Robert Martene. If you want, you can walk over and ask him yourself. ";
			link.l1 = "Thanks, mate. I'll go have a talk with monsieur Robert. We'll drink for the soul of poor old Luc that his soul may rest in peace...";
			link.l1.go = "terrapin_1";
			npchar.quest.terrapin = "true";
		break;
		
		case "terrapin_1":
			DialogExit();
			AddQuestRecord("Terrapin", "4");
			pchar.questTemp.Terrapin = "rober";
		break;
		
		// Sinistra - Квест "Длинные тени старых грехов" ==>
		case "DTSG_BasTerTavern_1":
			dialog.text = "What's there to discuss? He attacked you and your friend, you fought back, I see this almost every day. Good job. Now I just have to clean up the mess...";
			Link.l1 = "You'll clean it up, I'm sure you're used to it by now. What do you know about him?";
			Link.l1.go = "DTSG_BasTerTavern_2";
		break;
		
		case "DTSG_BasTerTavern_2":
			dialog.text = "Not much, really. He showed up a couple of days ago. Liked it here, even rented a house on the outskirts of town. Came by often, paid regularly. And, most importantly, he behaved himself well all this time, never saying a bad word to anyone. I'm still shocked he attacked you and your friend\nI thought he might settle down here for good.";
			Link.l1 = "In a way, he did. Well, that's not much, but thanks for that, my friend. See you around.";
			Link.l1.go = "DTSG_BasTerTavern_3";
		break;
		
		case "DTSG_BasTerTavern_3":
			DialogExit();
			DeleteAttribute(pchar, "questTemp.DTSG_BasTerTavern");
			LAi_LocationDisableOfficersGen("BasTer_tavern", false);
			SetQuestHeader("DTSG");
			AddQuestRecord("DTSG", "1");
			bDisableFastReload = false;
			chrDisableReloadToLocation = false;
			Return_KnippelOfficer();
			
			PChar.quest.DTSG_BasTerDom.win_condition.l1 = "locator";
			PChar.quest.DTSG_BasTerDom.win_condition.l1.location = "BasTer_town";
			PChar.quest.DTSG_BasTerDom.win_condition.l1.locator_group = "reload";
			PChar.quest.DTSG_BasTerDom.win_condition.l1.locator = "HutFish1";
			PChar.quest.DTSG_BasTerDom.win_condition = "DTSG_BasTerDom";
			
			SetTimerCondition("DTSG_BasTerDom_Timer", 0, 0, 7, false);
			SetTimerCondition("DTSG_Etap2", 0, 0, 14, false);
		break;
		// <== Квест "Длинные тени старых грехов" - Sinistra
		
		// Sinistra - Квест "Путеводная звезда" ==>
		
		case "PZ_BasTerTavern_1":
			dialog.text = "That name doesn't mean anything to me, and generally, I don't let people like him into my establishment, nor do I take any interest in them.";
			Link.l1 = "Fair enough. Alright, see you later.";
			Link.l1.go = "PZ_BasTerTavern_2";
		break;
		
		case "PZ_BasTerTavern_2":
			DialogExit();
			bDisableLandEncounters = true;
			DeleteAttribute(pchar, "questTemp.PZ_BasTerTavern");
			DeleteAttribute(pchar, "questTemp.PZ_BasTerAlkash");
			pchar.questTemp.PZ_BasTerTavern2 = true;
			DeleteQuestCondition("PZ_BasTer_Opozdal");
			DelMapQuestMarkIsland("Guadeloupe");
			
			PChar.quest.PZ_BasTer_Strazha.win_condition.l1 = "location";
			PChar.quest.PZ_BasTer_Strazha.win_condition.l1.location = "BasTer_town";
			PChar.quest.PZ_BasTer_Strazha.win_condition = "PZ_BasTer_Strazha";
		break;
		
		// <== Квест "Путеводная звезда" - Sinistra
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
