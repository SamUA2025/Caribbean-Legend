// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
            dialog.text = RandPhraseSimple("Welche Art von Fragen?","Was willst du?");
			link.l1 = RandPhraseSimple("Ich habe meine Meinung geändert.","Ich habe jetzt nichts zu sagen.");
		    link.l1.go = "exit";
		break;
		
		case "info":
			dialog.text = LinkRandPhrase("Wen interessieren Sie?","Wen meinst du?","Nun, wer ist es?");
			if (CheckAttribute(pchar, "questTemp.Saga"))
			{
				link.l1 = "Ich möchte mehr über Jan Svenson erfahren.";
				link.l1.go = "svenson";
			}
			link.l2 = "Lassen wir das Thema wechseln...";
			link.l2.go = "new question";
		break;
		
		case "town":
			dialog.text = LinkRandPhrase("Wohin möchtest du gehen?","Wonach suchst du?","Was brauchen Sie genau?");
			if (CheckAttribute(pchar, "questTemp.Saga"))
			{
				link.l1 = "Wo ist das Haus von Jan Svenson?";
				link.l1.go = "svenson_house";
			}
			link.l2 = "Lassen wir das Thema wechseln...";
			link.l2.go = "new question";
		break;
		
		case "svenson":
			dialog.text = RandPhraseSimple("Oh, unser Jan Svenson ist eine sehr wichtige Person. Früher war er der kühnste Pirat des Westlichen Mains und selbst jetzt hat er noch nicht angefangen zu rosten, ha! Aber diese Tage sind vorbei, er ist nicht mehr so aktiv wie früher. Er besitzt ein Herrenhaus und lebt dort mit seiner jungen Frau und er ist immer ein willkommener Gast in der Residenz des Gouverneurs. Viele Gäste kommen zu Jan, meistens Piraten.","Jan Svenson ist eine Legende von Western Main! Waldteufel, so nannten ihn die Spanier, als er sie von hier vertrieb. Er war ein berühmter Korsar, aber jetzt ist er ein angesehener Bürger unserer Kolonie\nObwohl er immer noch ein bisschen 'Geschäft' am Rande betreibt, aber nicht mehr mit seinen eigenen Händen. Seit er eine junge Schönheit geheiratet hat, verlässt er sein Haus nur selten.");
			link.l1 = "Mein Dank.";
			link.l1.go = "exit";
		break;
		
		case "svenson_house":
			dialog.text = RandPhraseSimple("Gehen Sie geradeaus vom Pier bis Sie den Platz sehen, das Haus rechts neben dem Brunnen ist Svensons Herrenhaus.","Gehen Sie durch den Platz von der Residenz des Gouverneurs zum Pier, das Haus links neben dem Brunnen ist Svensons Herrenhaus.");
			link.l1 = "Mein Dank.";
			link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
