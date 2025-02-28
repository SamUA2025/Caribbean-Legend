// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Welche Fragen haben Sie?","Wie kann ich Ihnen helfen?"),"Du hast versucht, mir vor einiger Zeit eine Frage zu stellen...","Ich habe noch nie Menschen mit solcher Neugier in meiner Schiffswerft oder anderswo in dieser Stadt getroffen.","Was soll das ganze Fragen? Meine Arbeit ist es, Schiffe zu bauen. Kümmern wir uns darum.","Block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Ich habe meine Meinung geändert...","Ich habe im Moment nichts zu besprechen."),"Umph, wo ist mein Gedächtnis hin...","Hm, nun ja...","Mach weiter...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			if (CheckAttribute(pchar, "questTemp.Guardoftruth") && pchar.questTemp.Guardoftruth == "tortuga1")
			{
				link.l1 = "Ich suche nach einem Gaius Marchais. Das Letzte, was ich von ihm gehört habe, war, dass er seine Galeone 'Santa Margarita' bei Ihnen zur Reparatur angelegt hat...";
                link.l1.go = "guardoftruth";
			}
		break;
		
		case "guardoftruth":
			dialog.text = "Sein eigener Galeone? Ho-ho, das ist ein guter Witz, Kapitän. Gaius Marchais besaß nur eine halbtote Schaluppe... er hat eine Galeone als Preis erobert, nachdem er beschlossen hat, ein Freibeuter zu werden. Glücklicher Teufel, erster Überfall und so eine Trophäe\nIch habe gutes Geld für sie geboten, aber er hat abgelehnt, stellen Sie sich das vor! Stattdessen verkaufte er seine erbärmliche Schaluppe für eine kleine Summe und benutzte sie, um die Galeone zu reparieren! Neue Segel, neue Farben und ein neuer Name, was normalerweise kein gutes Zeichen ist\nSicher, der Name war viel zu papistisch, aber meine Tochter heißt auch Margarita, also denke ich, war es letztendlich in Ordnung... Er sagte, dass er genug von Gewalt hatte, also würde er ein Händler werden. Und er hatte das gute Glück...";
			link.l1 = "Handel, nehme ich an, würde erholsam sein, aber päpstliche Galeonen werden normalerweise nicht von Schaluppen erobert. Und wie heißt sein Schiff jetzt?";
			link.l1.go = "guardoftruth_1";
		break;
		
		case "guardoftruth_1":
			dialog.text = "'Bewundernswert'... Kein Wunder! Er lief einfach um seine neue Galeone herum, als ob er eine Braut jagen würde, er konnte einfach nicht aufhören, sie zu bewundern.";
			link.l1 = "Ich verstehe. Ist Gaius gerade jetzt auf Tortuga?";
			link.l1.go = "guardoftruth_2";
		break;
		
		case "guardoftruth_2":
			dialog.text = "Nein. Er hat mit seinem neuen Schiff abgelegt und ist immer noch nicht nach Tortuga zurückgekehrt. Ich weiß nicht, wohin er unterwegs war, also kann ich Ihnen in dieser Angelegenheit nicht helfen.";
			link.l1 = "Welch ein Ärgernis... Ich brauche ihn wirklich. Wir sollten sogar auf sein 'bewundernswertes' Schiff anstoßen. Wie auch immer, danke für die Information.";
			link.l1.go = "guardoftruth_3";
		break;
		
		case "guardoftruth_3":
			dialog.text = "Ach, kein Problem. Kommen Sie wieder vorbei, Kapitän. Und vergessen Sie nicht, dass hier immer ein freier Platz für Ihr Schiff ist, wenn Reparaturen benötigt werden!";
			link.l1 = "...";
			link.l1.go = "exit";
			AddQuestRecord("Guardoftruth", "9");
			pchar.questTemp.Guardoftruth = "tortuga2";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
