// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{

	switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat("Mach weiter, was willst du?","Wir haben gerade darüber gesprochen. Du musst es vergessen haben...","Das ist das dritte Mal heute, dass du von irgendeiner Frage sprichst...","Hör zu, das ist ein Laden. Die Leute kaufen hier Sachen. Stör mich nicht!","Block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Du weißt, "+NPChar.name+", vielleicht nächstes Mal.","Richtig, aus irgendeinem Grund habe ich vergessen...","Ja, es ist wirklich das dritte Mal...","Hm, ich werde nicht...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			//Цена чахотки
			if (!CheckAttribute(npchar, "quest.Consumption") && CheckAttribute(pchar, "questTemp.Consumption.AskJuan"))
			{
				link.l1 = "Sag mir, bedeutet der Name Juan dir etwas?";
				link.l1.go = "Consumption";
			}
			if (!CheckAttribute(npchar, "quest.Guardoftruth") && CheckAttribute(pchar, "questTemp.Guardoftruth.Trinidad") && pchar.questTemp.Guardoftruth.Trinidad == "begin")
			{
				link.l1 = "Im April 1654 legte eine Fregatte unter dem Kommando von Kapitän Miguel Dichoso in deinem Hafen an, danach verschwand er. Sagt dir sein Name etwas? Möglicherweise hat er bei dir etwas Ware gekauft oder etwas gesagt...";
				link.l1.go = "guardoftruth";
			}
		break;
		
		//Цена чахотки
		case "Consumption":
			dialog.text = "Ach, hör auf, Kapitän! Ich hatte heute schon zwei Juans in meinem Laden, und gestern noch einen. Was, soll ich mich an jeden erinnern?";
			link.l1 = "Gut. Entschuldigung für die Störung...";
			link.l1.go = "exit";
			npchar.quest.Consumption = "true";
		break;
		
		case "guardoftruth":
			dialog.text = "Oh, Kapitän, in dieser Zeit sind so viele Fregatten und Galeonen hier ein- und ausgegangen, Miguels und Carloses...";
			link.l1 = "Ich verstehe. Also, du kannst nicht helfen...";
			link.l1.go = "exit";
			npchar.quest.guardoftruth = "true";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);
}
