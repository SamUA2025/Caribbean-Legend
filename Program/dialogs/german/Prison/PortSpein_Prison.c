// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
 	switch(Dialog.CurrentNode)
	{
        case "quests":
            dialog.text = "Sprechen Sie, ich höre zu";
			link.l1 = "Ich habe mich geirrt. Lebewohl.";
			link.l1.go = "Exit";
			//Цена чахотки
			if (!CheckAttribute(npchar, "quest.Consumption") && CheckAttribute(pchar, "questTemp.Consumption") && pchar.questTemp.Consumption == "begin")
			{
				link.l1 = "Ich habe gehört, dass hier eine Epidemie ausgebrochen ist, liege ich richtig?";
				link.l1.go = "Consumption";
			}
		break;
		
		//--> Цена чахотки
		case "Consumption":
			dialog.text = "Sie haben recht, also vermeiden Sie es, die Verliese ohne triftigen Grund zu besuchen. Warum interessieren Sie sich dafür?";
			link.l1 = "Nur neugierig. Also wenn meine Jungs zu betrunken werden, zu viel Lärm machen und hier landen, sollte ich dann etwas gelbes Leinen vorbereiten?";
			link.l1.go = "Consumption_1";
		break;
		
		case "Consumption_1":
			dialog.text = "Ach, Señor, ich verstehe den Scherz nicht, falls Sie einen gemacht haben. Die Verliese sind nass und kalt und Sie kennen das Klima. Schwindsucht ist ein häufiger Gast in diesen Verliesen. Ich muss sogar meine Jungs bezahlen, um Essen in die Kammern zu bringen. Dort zu patrouillieren wird als gleichwertig zur Zwangsarbeit betrachtet.";
			link.l1 = "Es tut mir leid, ich wollte nur wissen, wie ernst ist das?";
			link.l1.go = "Consumption_2";
		break;
		
		case "Consumption_2":
			dialog.text = "Viel zu ernst. Wir haben hier nicht mal einen Arzt, er ist auch an dieser verfluchten Schwindsucht gestorben. Jetzt untersucht nur ein Sanitäter der örtlichen Garnison einmal pro Woche die Gefangenen. Aber wen kümmern schon diese Landstreicher und Verbrecher?\nDie meisten Leute denken, dass sie ein solches Schicksal voll und ganz verdient haben und es ist schwer, darüber zu streiten.";
			link.l1 = "Meine Kenntnisse in Medizin sind bescheiden, aber soweit ich weiß, ist Schwindsucht gefährlich und tödlich, aber sie tötet Menschen nicht in wenigen Tagen, wie es hier der Fall ist. Sollten die Opfer nicht monatelang oder sogar jahrelang leiden?";
			link.l1.go = "Consumption_3";
		break;
		
		case "Consumption_3":
			dialog.text = "Wie Sie gerade erwähnt haben, sind Sie kein Arzt, daher könnte das Gespräch über die Merkmale der Krankheit einfach nur... eine erfundene Lüge sein. Ich habe nur wiederholt, was unser Arzt gesagt hatte, bevor die Krankheit auch ihn mitgenommen hat. Also verstehe ich Ihre Neugier und zynisches Verhalten nicht. Hier sterben Menschen!";
			link.l1 = "Hast du nicht gerade gesagt, dass sie es verdient haben?";
			link.l1.go = "Consumption_4";
		break;
		
		case "Consumption_4":
			dialog.text = "Genug, Senior! Ich glaube, dass Sie und ich andere Dinge zu tun haben, als uns in Witz zu messen. Die Tür ist direkt hinter Ihnen.";
			link.l1 = "Gut, vergib meine Taktlosigkeit, ich gehe schon.";
			link.l1.go = "Consumption_5";
		break;
		
		case "Consumption_5":
			DialogExit();
			npchar.quest.Consumption = "true";
			pchar.questTemp.Consumption.Commandant = "true";
			AddQuestRecord("Consumption", "3");
			pchar.quest.Consumption.win_condition.l1 = "location";
			pchar.quest.Consumption.win_condition.l1.location = "PortSpein_houseF2";
			pchar.quest.Consumption.function = "Consumption_CommandantHouse";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
