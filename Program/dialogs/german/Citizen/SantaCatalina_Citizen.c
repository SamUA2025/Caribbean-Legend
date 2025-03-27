// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
            dialog.text = RandPhraseSimple("Was für Fragen?","Was möchten Sie?");
			link.l1 = RandPhraseSimple("Ich habe meine Meinung geändert.","Ich habe im Moment nichts zu sagen.");
		    link.l1.go = "exit";
		break;
		
		case "info":
			dialog.text = LinkRandPhrase("Wer interessiert Sie?","Wen meinen Sie?","Nun, um wen handelt es sich?");
			if (CheckAttribute(pchar, "questTemp.Saga"))
			{
				link.l1 = "Ich möchte mehr über Jan Svenson erfahren.";
				link.l1.go = "svenson";
			}
			link.l2 = "Lassen Sie uns das Thema wechseln...";
			link.l2.go = "new question";
		break;
		
		case "town":
			dialog.text = LinkRandPhrase("Wohin möchten Sie gehen?","Wonach suchen Sie?","Was brauchen Sie genau?");
			if (CheckAttribute(pchar, "questTemp.Saga"))
			{
				link.l1 = "Wo ist das Haus von Jan Svenson?";
				link.l1.go = "svenson_house";
			}
			link.l2 = "Lassen Sie uns das Thema wechseln...";
			link.l2.go = "new question";
		break;
		
		case "svenson":
			dialog.text = RandPhraseSimple("Oh, unser Jan Svenson ist eine sehr wichtige Person. Früher war er der kühnste Pirat der westlichen Karibik und selbst jetzt hat er noch keinen Flugrost angesetzt, ha! Aber seine Piratentage sind vorbei, er ist nicht mehr so aktiv wie früher. Er besitzt ein Herrenhaus in der Stadt und lebt dort mit seiner jungen Frau. Er ist immer ein willkommener Gast in der Residenz des Gouverneurs. Auch Jan empfängt viele Gäste, meistens sind es Piraten.","Jan Svenson ist eine Legende der westlichen Karibik! Waldteufel, so nannten ihn die Spanier, als er sie von hier vertrieb. Er war ein berühmter Korsar, aber jetzt ist er ein angesehener Bürger unserer Kolonie.\nEr macht immer noch ein bisschen 'Geschäft' am Rande, aber anders als früher nicht mehr mit seinen eigenen Händen. Seit er eine junge schöne Frau geheiratet hat, verlässt er sein Haus nur selten.");
			link.l1 = "Besten Dank.";
			link.l1.go = "exit";
		break;
		
		case "svenson_house":
			dialog.text = RandPhraseSimple("Folgen Sie dem Pier geradeaus bis Sie den Hauptplatz sehen, das Haus rechts neben dem Brunnen ist Svensons Herrenhaus.","Gehen Sie von der Residenz des Gouverneurs über den Hauptplatz Richtung Pier, das Haus links neben dem Brunnen ist Svensons Herrenhaus.");
			link.l1 = "Besten Dank.";
			link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
