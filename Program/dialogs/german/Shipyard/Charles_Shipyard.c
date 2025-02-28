// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Welche Fragen haben Sie?","Wie kann ich Ihnen helfen?"),"Du hast versucht, mir vor einer Weile eine Frage zu stellen...","Ich habe noch nie Menschen mit solcher Neugier in meiner Werft oder sonstwo in dieser Stadt getroffen.","Was soll das mit all den Fragen? Meine Aufgabe ist es, Schiffe zu bauen. Lassen Sie uns uns darum kümmern.","Block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Ich habe meine Meinung geändert...","Ich habe im Moment nichts zu besprechen."),"Hmpf, wo ist mein Gedächtnis hin...","Hm, nun...","Mach weiter...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			// Addon 2016-1 Jason пиратскаЯ линейка
			if (CheckAttribute(pchar, "questTemp.Mtraxx") && pchar.questTemp.Mtraxx == "silk_2")
            {
                link.l1 = "Hör zu, Meister, du baust hier Schiffe, nicht wahr?.. Und wechselst auch die Segel... hast du jemals an... ein besseres Segeltuchmaterial gedacht?";
                link.l1.go = "mtraxx";
			}
		break;
		
		// Addon 2016-1 Jason пиратскаЯ линейка
		case "mtraxx":
            dialog.text = "Sie sprechen in Rätseln, Herr... Sprechen Sie offen, was hat Sie hierher gebracht? Keine Sorge, ich bin kein Bürokrat und hier ist kein Zollhaus.";
			link.l1 = "Ach, ich bin froh, dass wir uns einig sind! Seidenes Segeltuch, Herr. Soweit ich verstehe, gibt es kein besseres Material für die Segel, wenn Geschwindigkeit Ihre Sorge ist.";
			link.l1.go = "mtraxx_1";
		break;
		
		case "mtraxx_1":
            dialog.text = "Nicht nur die Geschwindigkeit, sondern auch ihre Fähigkeit, gegen den Wind zu segeln. Sie bieten Schiffsseide zum Verkauf an? Das ist in der Tat eine wertvolle Ladung. Aber es gibt ein Hindernis: Ich weiß einfach nicht, wie ich es in der Produktion verwenden kann. Verstehen Sie? Ein Material wie dieses erfordert sehr spezielle Fähigkeiten und Fertigkeiten, die mir fehlen. Um ehrlich zu sein, meine Werft hat eine ganz andere Spezialisierung, wenn Sie mir Seile aus dem Zarentum Russland angeboten hätten, würde ich sie alle kaufen, egal zu welchem Preis. Wir brauchen ständig Seile, jedoch ist Schiffsseide hier nicht gefragt, es tut mir leid!";
			link.l1 = "Hm. Ich verstehe. Danke für Ihre Zeit, Meister. Viel Glück!";
			link.l1.go = "mtraxx_2";
		break;
		
		case "mtraxx_2":
            DialogExit();
			AddQuestRecord("Roger_2", "4");
			pchar.questTemp.Mtraxx = "silk_3";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
