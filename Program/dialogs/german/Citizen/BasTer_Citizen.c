// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
            dialog.text = RandPhraseSimple("Was für Fragen?","Was möchten Sie?");
			link.l1 = RandPhraseSimple("Ah, ich habe meine Meinung geändert.'","Ich habe im Moment nichts zu sagen.");
		    link.l1.go = "exit";
		break;
		
		case "info":
			dialog.text = LinkRandPhrase("Wer interessiert Sie?","Wen meinen Sie?","Um wen geht es?");
			link.l1 = "Ich möchte mehr über Fadey den Moskowiter erfahren.";
			link.l1.go = "fadey";
			link.l2 = "Niemanden, vergessen Sie es.";
			link.l2.go = "new question";
		break;
		
		case "town":
			dialog.text = LinkRandPhrase("Wohin möchten Sie gehen?","Was suchen Sie?","Was brauchen Sie genau?");
            link.l1 = "Wo ist Fadeys Haus?";
			link.l1.go = "fadey_house";
			link.l2 = "Lassen Sie uns über etwas anderes sprechen...";
			link.l2.go = "new question";
		break;
		
		case "fadey":
			dialog.text = RandPhraseSimple("Ah, Fadey ist ein wichtiger Mann. Er besitzt die örtliche Fabrik und steht als hohes Tier und Freund des Gouverneurs dem gehobenen Leben von Basse-Terre nahe. Er hat einen starken Akzent und trinkt sehr gerne... aber er wird nie betrunken.","Er ist ein hohes Tier und Freund des Gouverneurs. Fadey besitzt die lokale Fabrik. Er kommt aus einem nördlichen Land, weit, weit weg von hier... Ich kenne nicht mal den Namen des Ortes. Er hat starke Hände und kann ein ganzes Fass Rum trinken ohne betrunken zu werden.");
			link.l1 = "Besten Dank.";
			link.l1.go = "exit";
		break;
		
		case "fadey_house":
			dialog.text = RandPhraseSimple("Folgen Sie dem Pier geradeaus richtig Hauptplatz. Das letzte Haus vor dem Hauptplatz auf der linken Seite ist Fadeys Villa.","Überqueren Sie von der Residenz des Gouvernours den Hauptplatz Richtung Pier, das erste Haus auf der rechten Seite ist Fadeys Villa.");
			link.l1 = "Besten Dank.";
			link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
