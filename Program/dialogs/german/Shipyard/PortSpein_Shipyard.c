// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Welche Fragen haben Sie?","Wie kann ich Ihnen helfen?"),"Du hast versucht, mir vor einer Weile eine Frage zu stellen...","Ich habe noch nie Menschen mit solcher Neugier in meiner Werft oder irgendwo anders in dieser Stadt getroffen.","Was ist mit all den Fragen? Meine Aufgabe ist es, Schiffe zu bauen. Kümmern wir uns darum.","Block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Ich habe meine Meinung geändert...","Ich habe im Moment nichts zu besprechen."),"Hmpf, wo ist mein Gedächtnis hin...","Hm, nun...","Mach weiter...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			//Цена чахотки
			if (!CheckAttribute(npchar, "quest.Consumption") && CheckAttribute(pchar, "questTemp.Consumption.AskJuan"))
			{
				link.l1 = "Sag mir, bedeutet der Name Juan dir etwas?";
				link.l1.go = "Consumption";
			}
			if (!CheckAttribute(npchar, "quest.Guardoftruth") && CheckAttribute(pchar, "questTemp.Guardoftruth.Trinidad") && pchar.questTemp.Guardoftruth.Trinidad == "begin")
			{
				link.l1 = "Herr, im April 1654 war hier eine Fregatte unter dem Kommando von Miguel Dichoso. Er ist gleich danach verschwunden. Erinnern Sie sich an nichts? Vielleicht hat Dichoso für eine Reparatur vorbeigeschaut und vielleicht hat er Ihnen etwas erzählt...";
				link.l1.go = "guardoftruth";
			}
		break;
		
		//Цена чахотки
		case "Consumption":
			dialog.text = "Nein. Überhaupt nichts.";
			link.l1 = "Gut. Entschuldigung für die Störung...";
			link.l1.go = "exit";
			npchar.quest.Consumption = "true";
		break;
		
		case "guardoftruth":
			dialog.text = "Hm. Nein. Er hat nicht für eine Reparatur vorbeigeschaut und mir überhaupt nichts erzählt. Und wenn irgendetwas davon passiert wäre, kann ich mich nicht daran erinnern. Es tut mir leid, dass ich Ihnen, Senor, nicht helfen kann.";
			link.l1 = "In Ordnung. Danke Freund...";
			link.l1.go = "exit";
			npchar.quest.guardoftruth = "true";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
