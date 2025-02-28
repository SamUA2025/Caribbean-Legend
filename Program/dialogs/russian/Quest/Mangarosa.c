// диалоги персонажей по квесту Мангароса
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
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
		
		// Амелия - знахарка-цыганка
		case "amelia":
			dialog.text = "Что тебе нужно в моём доме?";
			if (CheckAttribute(pchar, "questTemp.Mangarosa") && pchar.questTemp.Mangarosa == "amelia")
			{
				link.l1 = "Тебя зовут Амелия, верно? Я приш"+GetSexPhrase("ёл","ла")+" к тебе с вопросом, касательно одного растения. Мангаросы.";
				link.l1.go = "amelia_1";
			}
			else
			{
				link.l1 = "Пока, наверное, мне нечего тебе сказать. Но я ещё вернусь...";
				link.l1.go = "exit";
			}
			NextDiag.TempNode = "amelia";
		break;
		
		case "amelia_1":
			dialog.text = "Очень интересно! И кто же тебе обо мне понарассказывал, а, "+GetSexPhrase("соколик","голубушка")+"?";
			link.l1 = "Да одна из ваших. Сказала, что ты знаешь секреты этого растения и можешь научить готовить из него какие-то особенные зелья...";
			link.l1.go = "amelia_2";
		break;
		
		case "amelia_2":
			dialog.text = "Ну, давай начнём с того, что ты мне покажешь растение, о котором ведёшь речь. Может, ты просто наслушал"+GetSexPhrase("ся","ась")+" уличной болтовни, а теперь явился сюда и отвлекаешь меня от важных дел. Где твоя мангароса?";
			if (CheckCharacterItem(pchar, "cannabis7"))
			{
				link.l1 = "Вот она, смотри.";
				link.l1.go = "amelia_3";
			}
			else
			{
				link.l1 = "Гм...";
				link.l1.go = "amelia_exit";
			}
		break;
		
		case "amelia_exit":
			dialog.text = "Ну, и что ты тут мне пытаешься показать? Нет у тебя мангаросы. Так что топай отсюда, "+GetSexPhrase("парень","девочка")+", пока я не рассердилась. Разговор окончен.";
			link.l1 = "Но...";
			link.l1.go = "exit";
			NextDiag.TempNode = "amelia_wait";
		break;
		
		case "amelia_wait":
			dialog.text = "Опять ты? Не доводи до греха, "+GetSexPhrase("парень","девочка")+"...";
			if (CheckCharacterItem(pchar, "cannabis7"))
			{
				link.l1 = "Не ругайся, Амелия. В прошлый раз я просто её где-то выронил"+GetSexPhrase("","а")+". Вот, я прин"+GetSexPhrase("ёс","есла")+" мангаросу. Смотри.";
				link.l1.go = "amelia_3";
			}
			else
			{
				link.l1 = "...";
				link.l1.go = "amelia_exit";
			}
			NextDiag.TempNode = "amelia_wait";
		break;
		
		case "amelia_3":
			dialog.text = "Так... Похоже, ты всё-таки что-то знаешь. И ты хочешь, чтобы я рассказала тебе секреты своих зелий из этого растения?";
			link.l1 = "Именно так. Ну, конечно, не бесплатно, я понимаю...";
			link.l1.go = "amelia_4";
		break;
		
		case "amelia_4":
			dialog.text = "Ещё бы ты этого не понимал"+GetSexPhrase("","а")+", "+GetSexPhrase("соколик","голубушка")+"! На "+GetSexPhrase("дурня","дурочку")+" ты совсем не похож"+GetSexPhrase("","а")+". Ну что же, я не против поделиться знаниями с "+GetSexPhrase("человеком","девушкой")+", котор"+GetSexPhrase("ый","ая")+" сам"+GetSexPhrase("","а")+" за ними приш"+GetSexPhrase("ёл","ла")+", и котор"+GetSexPhrase("ый","ая")+" не переводит это редкое растение на дурманящее курево...";
			link.l1 = "Амелия, перед тем как торговаться, просвети меня хотя бы в общих чертах - что за зелья получаются из мангаросы?";
			link.l1.go = "amelia_5";
		break;
		
		case "amelia_5":
			dialog.text = "Торговаться, "+GetSexPhrase("парень","девочка")+", мы с тобой не будем. Я назначаю цену - а ты решишь, будешь её платить, или нет. Ни на какие скидки и торг даже не рассчитывай, чай, не на рынке. Что же касается твоего вопроса: из мангаросы получаются зелья, воздействующие на физические способности. Они могут сделать тебя более сильным, выносливым и быстрым, либо оказать комплексное воздействие на твоё тело.";
			link.l1 = "Очень интересно! Назови свою цену.";
			link.l1.go = "amelia_6";
		break;
		
		case "amelia_6":
			dialog.text = "Я могу научить тебя рецептам трёх зелий. За каждый рецепт я прошу один стебель мангаросы и пятьсот золотых монет.";
			link.l1 = "Расскажи об этих трёх зельях подробнее - что каждое делает?";
			link.l1.go = "amelia_7";
		break;
		
		case "amelia_7":
			dialog.text = "Чтобы изготовить любое зелье, ты должен владеть основами алхимии. Действие всех зелий временное и ограничивается приблизительно двумя днями\nПервое зелье придаёт тебе силы и выносливости. Ты становишься крепче, можешь успешнее противостоять врагам в бою и переносить больше тяжестей\nВторое зелье дарит тебе быстроту, ловкость, неутомимость, а также остроту глаза\nТретье зелье сочетает в себе эффекты первого и второго, но вдвое слабее. Однако оно также придаст тебе обаяния, уверенности в себе и сделает более удачливым\nТакже все зелья из мангаросы положительно влияют на здоровье. Употреблять их следует только по одному, и не раньше, чем закончится действие предыдущего - в противном случае не только не будет эффекта, но напротив - получишь отравление\nНу что, "+GetSexPhrase("соколик","голубушка")+", ты готов"+GetSexPhrase("","а")+" оплатить свои новые знания, или тебе нужно время на размышление?";
			if (CheckCharacterItem(pchar, "cannabis7") && PCharDublonsTotal() >= 500)
			{
				link.l1 = "Да, я готов"+GetSexPhrase("","а")+".";
				link.l1.go = "amelia_8";
			}
			link.l2 = "Я хочу немного подумать. Это непростое решение.";
			link.l2.go = "exit";
			NextDiag.TempNode = "amelia_next";
		break;
		
		case "amelia_next":
			if (!CheckAttribute(npchar, "quest.ChickenGod") && CheckCharacterItem(pchar, "talisman11")) {
				if (CheckAttribute(npchar, "quest.recipe_power") || CheckAttribute(npchar, "quest.recipe_fast") || CheckAttribute(npchar, "quest.recipe_total")) {
					link.chickengod = "Амелия, ты похоже разбираешься в таких вещах. Подскажи, пожалуйста, есть ли спрос на такие камушки у вашего народа? Нахожу их повсюду - будто помешались все на них!";
					link.chickengod.go = "chickengod";
				}
			}
			
			if (CheckAttribute(npchar, "quest.ChickenGod") && !CheckAttribute(npchar, "quest.ChickenGod.Complete") && GetCharacterItem(pchar, "talisman11") >= 113) {
				link.chickengod = "Вот, Амелия. Как заказывала: сто тринадцать камней. С дырками.";
				link.chickengod.go = "chickengod_collected";
			}
		
			if (CheckAttribute(npchar, "quest.recipe_all"))
			{
				dialog.text = "А-а, это ты, "+GetSexPhrase("соколик","голубушка")+"! Ну как, помогают тебе мои зелья?";
				link.l1 = "Даже очень, Амелия. Спасибо тебе!";
				link.l1.go = "exit";
			}
			else
			{
				dialog.text = "А-а, это ты, "+GetSexPhrase("соколик","голубушка")+"! Ты хочешь купить у меня рецептов зелий из мангаросы, так?";
				if (CheckCharacterItem(pchar, "cannabis7") && PCharDublonsTotal() >= 500)
				{
					link.l1 = "Именно. За этим я и приш"+GetSexPhrase("ёл","ла")+".";
					link.l1.go = "amelia_8";
				}
				
				link.l2 = "Пока нет, Амелия. Просто заглянул"+GetSexPhrase("","а")+" проведать.";
				link.l2.go = "exit";
			}
			NextDiag.TempNode = "amelia_next";
		break;
		
		case "amelia_8":
			dialog.text = "Очень хорошо. Какой рецепт ты хочешь приобрести?";
			if (!CheckAttribute(npchar, "quest.recipe_power"))
			{
				link.l1 = "Рецепт зелья силы и выносливости.";
				link.l1.go = "power";
			}
			if (!CheckAttribute(npchar, "quest.recipe_fast"))
			{
				link.l2 = "Рецепт зелья ловкости и неутомимости.";
				link.l2.go = "fast";
			}
			if (!CheckAttribute(npchar, "quest.recipe_total"))
			{
				link.l3 = "Рецепт комплексного зелья.";
				link.l3.go = "total";
			}
		break;
		
		case "power":
			dialog.text = "Хорошо. Я назвала его 'Удар прибоя'. Вот, возьми инструкцию приготовления. Следуй строго по рецепту. Не забывай о правилах применения!";
			link.l1 = "Спасибо, Амелия...";
			link.l1.go = "recipe_exit";
			AddQuestRecordInfo("Recipe", "mangarosapower");
			SetAlchemyRecipeKnown("mangarosapower");
			npchar.quest.recipe_power = true;
		break;
		
		case "fast":
			dialog.text = "Хорошо. Я назвала его 'Шквал'. Вот, возьми инструкцию приготовления. Следуй строго по рецепту. Не забывай о правилах применения!";
			link.l1 = "Спасибо, Амелия...";
			link.l1.go = "recipe_exit";
			AddQuestRecordInfo("Recipe", "mangarosafast");
			SetAlchemyRecipeKnown("mangarosafast");
			npchar.quest.recipe_fast = true;
		break;
		
		case "total":
			dialog.text = "Хорошо. Я назвала его 'Ласка моря'. Вот, возьми инструкцию приготовления. Следуй строго по рецепту. Не забывай о правилах применения!";
			link.l1 = "Спасибо, Амелия...";
			link.l1.go = "recipe_exit";
			AddQuestRecordInfo("Recipe", "mangarosatotal");
			SetAlchemyRecipeKnown("mangarosatotal");
			npchar.quest.recipe_total = true;
		break;
		
		case "recipe_exit":
			DialogExit();
			NextDiag.CurrentNode = "amelia_next";
			RemoveDublonsFromPCharTotal(500);
			RemoveItems(pchar, "cannabis7", 1);
			Log_Info("Вы отдали 500 дублонов и стебель мангаросы");
			PlaySound("interface\important_item.wav");
			if (CheckAttribute(npchar, "quest.recipe_power") && CheckAttribute(npchar, "quest.recipe_fast") && CheckAttribute(npchar, "quest.recipe_total"))
			{
				npchar.quest.recipe_all = true;
				CloseQuestHeader("mangarosa");
			}
		break;
		
		case "chickengod":
			dialog.text = "Bax de adder, как же! Ценности он невеликой, но знающим людям пригодится. Принеси мне сто тринадцать таких и я открою тебе один из своих сундуков.";
			link.l1 = "Это же целая куча камней! Может лучше сначала расскажешь, зачем тебе эти они?";
			link.l1.go = "chickengod_1";
		break;
		
		case "chickengod_1":
			dialog.text = "Нет, "+GetSexPhrase("соколик","голубушка")+", если спрашиваешь, то это знание тебе пока ни к чему.";
			link.l1 = "А что в сундуке, который ты так щедро посулила открыть?";
			link.l1.go = "chickengod_2";
		break;
		
		case "chickengod_2":
			dialog.text = "Великое множество вещиц, полезных для капитанов, не брезгующих ручным трудом. Не трать моё время, "+GetSexPhrase("соколик","голубушка")+", всё равно ведь не соберешь столько камушков.";
			link.l1 = "Посмотрим.";
			link.l1.go = "exit";
			
			npchar.quest.ChickenGod = true;
		break;
		
		case "chickengod_collected":
			dialog.text = "Ох, удивил"+GetSexPhrase("","а")+" ты меня! Думала, в шутку воспримешь!";
			link.l1 = "Чего?! Смешно будет, когда я сожгу тебя, ведьма, в твоей же лачуге! Так нужны тебе эти камни или нет?!";
			link.l1.go = "chickengod_collected_1";
		break;
		
		case "chickengod_collected_1":
			dialog.text = "Не такая у меня судьба, "+GetSexPhrase("соколик","голубушка")+"... А камушки давай сюда, ох порадовал"+GetSexPhrase("","а")+" ты цыганку! Держи, отдаю мой сундук тебе на разграбление.";
			link.l1 = "Надеюсь, там будет хоть что-то полезное, помимо твоего старого белья...";
			link.l1.go = "exit";
			
			TakeNItems(pchar, "talisman11", -113);
			npchar.quest.ChickenGod.Complete = true;
			AddDialogExitQuestFunction("ChickenGod_AmeliaOpenChest");
		break;
	}
} 
