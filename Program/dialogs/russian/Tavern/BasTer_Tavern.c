// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Какие вопросы?", "Что вам угодно, " + GetAddress_Form(NPChar) + "?"), "Совсем недавно вы пытались задать мне вопрос, " + GetAddress_Form(NPChar) + "...", "В течение этого дня вы уже третий раз говорите о каком-то вопросе...",
                          "Опять вопросы будем задавать?", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Я "+ GetSexPhrase("передумал","передумала") +"...", "Сейчас мне не о чем говорить."), "Хм, что-то с памятью моей стало...",
                      "Да уж, действительно в третий раз...", "Да нет, какие вопросы...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			//Jason, суп из черепахи
			if (CheckAttribute(PChar, "questTemp.Terrapin") && pchar.questTemp.Terrapin == "baster" && !CheckAttribute(npchar, "quest.terrapin"))
			{
				link.l1 = "Я ищу своего старого приятеля Фернана Люка. У меня к нему есть пара вопросов. Слышал, он тут неплохо проводил время неделю назад...";
				link.l1.go = "terrapin";
			}
			//Sinistra Путеводная звезда
			if (CheckAttribute(pchar, "questTemp.PZ_BasTerTavern"))
			{
				link.l1 = "Мы с другом договаривались здесь встретиться, но я его нигде не вижу. Может, ты знаешь, куда он пошёл? Он всё ещё в городе или хотя бы на острове? Его зовут Лонгвэй, он китаец.";
				link.l1.go = "PZ_BasTerTavern_1";
			}
		break;
		
		//суп из черепахи
		case "terrapin":
			dialog.text = "Возможно, он и сейчас его неплохо проводит, только в окружении чертей. Склеил ласты твой приятель. Так что ты малость припоздал, капитан. Вон тот господин, за самым дальним столиком, оплатил его похороны, хотя сдаётся мне, что он и стал их причиной. Уж больно рожа у него бандитская. Его зовут Робер Мартэн, если хочешь, можешь задать ему свои вопросы. ";
			link.l1 = "Спасибо, приятель. Пойду, потолкую с месье Робером. Выпьем за упокой души несчастного Люка...";
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
			dialog.text = "А что тут обсуждать? Он напал на вас с приятелем, вы отбились, чуть ли не каждый день такое вижу. Хорошая работа. Вот только залу теперь опять отмывать...";
			Link.l1 = "Отмоешь, думаю, к этому ты тоже уже привык. Что ты знаешь об этом человеке?";
			Link.l1.go = "DTSG_BasTerTavern_2";
		break;
		
		case "DTSG_BasTerTavern_2":
			dialog.text = "Да ничего особенного толком. Появился буквально пару-тройку дней назад. Нравилось ему у нас, даже дом снимал на окраине города. Частенько захаживал, исправно платил. И, что самое главное, всё это время он прилично себя вёл, никому и слова дурного не сказал. До сих дивлюсь тому, что он напал на вас с другом\nДумал уже, что он осядет здесь навсегда.";
			Link.l1 = "В каком-то смысле так оно и оказалось. Ну, негусто, конечно, но спасибо и на этом, приятель. До встречи.";
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
			dialog.text = "Это имя мне ни о чём не говорит, да и вообще я таких в своё заведение не пускаю и не интересуюсь подобными людьми, знаешь ли - себе дороже.";
			Link.l1 = "Справедливо. Ладно, до встречи.";
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

