// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
            dialog.text = RandPhraseSimple("Welche Art von Fragen?","Was willst du?");
			link.l1 = RandPhraseSimple("Ich habe meine Meinung geändert.'","Ich habe jetzt nichts zu sagen.");
		    link.l1.go = "exit";
		break;
		
		case "info":
			dialog.text = LinkRandPhrase("Wen interessieren Sie?","Wen meinst du?","Nun, wer ist es?");
			link.l1 = "Ich möchte mehr über Fadey den Moskowiter erfahren.";
			link.l1.go = "fadey";
			link.l2 = "Niemand, vergiss das.";
			link.l2.go = "new question";
		break;
		
		case "town":
			dialog.text = LinkRandPhrase("Wohin möchtest du gehen?","Was suchen Sie?","Was brauchen Sie genau?");
            link.l1 = "Wo ist Fadeys Haus?";
			link.l1.go = "fadey_house";
			link.l2 = "Lassen wir uns über etwas anderes unterhalten...";
			link.l2.go = "new question";
		break;
		
		case "fadey":
			dialog.text = RandPhraseSimple("Ach, ein wichtiger Mann. Er besitzt die örtliche Fabrik und steht dem gehobenen Leben von Basse-Terre nahe. Er hat einen starken Akzent und trinkt sehr gerne... aber er wird nie betrunken.","Er ist ein hohes Tier und Freund des Gouverneurs. Fadey besitzt eine lokale Fabrik. Kam aus einem nördlichen Land weit, weit weg von hier... Ich kenne nicht mal den Namen davon. Er hat starke Hände und er kann ein ganzes Fass Rum trinken und wird nicht betrunken.");
			link.l1 = "Mein Dank.";
			link.l1.go = "exit";
		break;
		
		case "fadey_house":
			dialog.text = RandPhraseSimple("Gehen Sie geradeaus vom Pier, bis Sie den Platz sehen, das Haus links ist Fadeys Villa.","Gehen Sie durch den Platz von der Residenz des Gouverneurs zum Pier, das Haus rechts ist Fadeys Villa.");
			link.l1 = "Mein Dank.";
			link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
