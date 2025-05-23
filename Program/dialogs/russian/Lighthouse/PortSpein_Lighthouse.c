// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Что вам угодно?", "Что вы хотели узнать?"), "Так скажите, что же вас интересует, " + GetAddress_Form(NPChar) + "?", "Третий раз за сегодня вы пытаетесь задать вопрос...", "Всё, вы меня утомили. Покиньте мой дом!", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Я передумал"+ GetSexPhrase("","а") +"...", "Сейчас мне не о чем говорить."), "Ох, что-то я запамятовал. Простите...",
                      "Да уж, действительно в третий раз...", "Извиняюсь...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			if (CheckAttribute(pchar, "questTemp.Guardoftruth.Trinidad") && pchar.questTemp.Guardoftruth.Trinidad == "begin")
			{
				link.l1 = "Послушай, в апреле 1654 года в порт Сан-Хосе заходил фрегат под командованием капитана Мигеля Дичозо. Он потом исчез. Ничего не расскажешь об этом фрегате? Может, видел, куда он отплыл, и что с ним произошло? Помнишь?";
				link.l1.go = "guardoftruth";
			}
		break;
		
		case "guardoftruth":
			dialog.text = "Охо-хо... Как же не помнить, сеньор, когда тут такое творилось!";
			link.l1 = "Рассказывай! Мне очень интересно послушать!";
			link.l1.go = "guardoftruth_1";
		break;
		
		case "guardoftruth_1":
			dialog.text = "Фрегат сеньора Дичозо отдал якорь в бухте Сан-Хосе. Я хорошо рассмотрел этот корабль. Скажу прямо - такой великолепный фрегат ещё поискать надо, строился он мастером корабельного дела, точно вам говорю! Матросики хвалились, что их 'Санта-Квитерия' развивает скорость до шестнадцати узлов - просто чудо какое-то\nТак вот, стояли они день в порту, а потом выбрали якорь, прошли мимо моего маяка и направились аккурат к острову Тобаго. Едва их паруса скрылись за горизонтом, как начали твориться странные вещи. Уже несколько дней кряду стояла спокойная погода, дул свежий бриз, на небе - ни облачка\nИ тут как из ниоткуда налетел жуткий шторм. Небо мгновенно затянулось чёрными тучами, стало темно, как поздним вечером, ветер резко изменил направление с северо-западного на южный, засверкали молнии, хлынул ливень, море поднялось так, что затопило мой пляж\nГудело и завывало так, словно сам Нептун пожаловал из морских пучин. Я поднялся наверх маяка, чтобы зажечь огонь, и тут я увидел её... 'Санта-Квитерия' стремительно неслась по волнам в сопровождении жуткого смерча, поднимавшего вокруг столб водяной пыли\nФрегат в мгновение ока пролетел мимо моего маяка и был унесён штормом на северо-северо-запад. Больше 'Санта-Квитерию' никто не видел. А через час ветер утих, тучи рассеялись, солнце засияло в небе - словно и не было никакого шторма! Я таких чудес до того не видывал! Зато сколько янтаря я собрал в тот день на своём пляже...";
			link.l1 = "Получается, шторм отнёс фрегат назад, в Карибское море?";
			link.l1.go = "guardoftruth_2";
		break;
		
		case "guardoftruth_2":
			dialog.text = "Ну да. И понёс в направлении Мартиники. Однако не думаю, что Дичозо смог пережить натиск стихии, хотя держался он молодцом - его фрегат даже в такой шторм уверенно держался на воде. Лежит скорее всего 'Санта-Квитерия' сейчас на дне среди кораллов... Кстати, вы не первый, кто спрашивал меня о Дичозо и его фрегате.";
			link.l1 = "Вот как? И кто же ещё интересовался Мигелем?";
			link.l1.go = "guardoftruth_3";
		break;
		
		case "guardoftruth_3":
			dialog.text = "Какой-то бравый капитан испанского флота. Он представился как... ох, вылетело из головы... А, вспомнил! Сеньор Диего. Его звали Диего, а вот фамилия... де Монтанья, или де Монтойя. Вроде так. Он выслушал мой рассказ, вот так как вы сейчас, поблагодарил и ушёл. Больше я его не видел.";
			if (sti(Pchar.money) >= 5000)
			{
				link.l1 = "Понятно. Спасибо тебе огромное за рассказ, ты мне очень помог. Вот, это тебе, моя благодарность в звонкой монете. Бывай!";
				AddMoneyToCharacter(pchar, -5000);
				AddCharacterExpToSkill(pchar, "Leadership", 250);
			}
			else
			{
				link.l1 = "Понятно. Спасибо тебе огромное за рассказ, ты мне очень помог. Бывай!";
			}
			link.l1.go = "guardoftruth_4";
		break;
		
		case "guardoftruth_4":
			DialogExit();
			AddQuestRecord("Guardoftruth", "41");
			pchar.questTemp.Guardoftruth.Trinidad = "mayak";
			pchar.quest.GuardOT_setDiego.win_condition.l1 = "ExitFromLocation";
			pchar.quest.GuardOT_setDiego.win_condition.l1.location = pchar.location;
			pchar.quest.GuardOT_setDiego.function = "GuardOT_SetDiegoOnMayak";
		break;
	}
	UnloadSegment(NPChar.FileDialog2); 
}