// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Welche Fragen haben Sie?","Wie kann ich Ihnen helfen, "+GetAddress_Form(NPChar)+"?"),"Du hast versucht, mir vor kurzem eine Frage zu stellen, "+GetAddress_Form(NPChar)+"...","Den ganzen Tag über ist dies das dritte Mal, dass du von irgendeiner Frage sprichst...","Noch Fragen, nehme ich an?","Block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Ich habe meine Meinung geändert...","Ich habe im Moment nichts zu besprechen."),"Umph, wo ist mein Gedächtnis hin...","Ja, es ist wirklich das dritte Mal...","Nein, welche Fragen?...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			//Jason, Сага, Тени прошлого
			if (CheckAttribute(PChar, "questTemp.Saga.Shadows") && pchar.questTemp.Saga.Shadows == "sentjons")
			{
				link.l1 = "Ich suche Raymond Baker, einen ehemaligen Henker. Wissen Sie, ob er noch lebt und wo ich ihn finden kann?";
				link.l1.go = "baker";
			}
			//Jason, суп из черепахи
			if (CheckAttribute(PChar, "questTemp.Terrapin") && pchar.questTemp.Terrapin == "baster" && !CheckAttribute(npchar, "quest.terrapin"))
			{
				link.l1 = "Ich suche Herrn Jones. Können Sie mir bei meiner Suche helfen, Kumpel?";
				link.l1.go = "terrapin";
			}
			// Страж Истины
			if (CheckAttribute(pchar, "questTemp.Guardoftruth") && pchar.questTemp.Guardoftruth == "merdok")
			{
				link.l1 = "Hör zu, ist hier in dieser Stadt ein Alchemist angekommen, ein Arzt? Er ist Italiener, etwa dreißig Jahre alt, sein Name ist Gino Gvineili. Haben Sie davon etwas gehört?";
				link.l1.go = "guardoftruth";
			}
		break;
		
		//Сага, Тени прошлого
		case "baker":
			dialog.text = "Unser lieber Dicke ist beliebter geworden als Oberst Fuchs! Er lebt noch, der arme Kerl. Aber er ist gerade nicht in der Stadt. Nachdem Raymond herausfand, dass ernsthafte Leute wie du sich für ihn interessieren, hat er schnell seine Bruchbude für einen Appel und ein Ei verkauft und ist mit dem Wind davon.";
			link.l1 = "Wohin mit dem Wind?";
			link.l1.go = "baker_1";
		break;
		
		case "baker_1":
			dialog.text = "Oh, wer weiß. Er ging als Schiffsarzt auf das erste Schiff, das vorbeikam. Nur kam dieses Schiff heute gerade zurück und niemand hat gesehen, dass Baker an Land gegangen ist.";
			link.l1 = "Wie finde ich den Kapitän?";
			link.l1.go = "baker_2";
		break;
		
		case "baker_2":
			dialog.text = "Warum glaubst du, ihn suchen zu müssen? Ich bin sicher, er ist wie gewohnt in seiner Kajüte betrunken. Sein löchriges Eimerchen heißt 'Schwache Meggy'. Wie der Kapitän, so der Name...";
			link.l1 = "Danke für die Hilfe, Kumpel!";
			link.l1.go = "baker_3";
		break;
		
		case "baker_3":
			DialogExit();
			AddQuestRecord("Shadows", "2");
			pchar.questTemp.Saga.Shadows = "baldmaggy";
			pchar.quest.Saga_ShadowsMaggy.win_condition.l1 = "location";
			pchar.quest.Saga_ShadowsMaggy.win_condition.l1.location = "Antigua";
			pchar.quest.Saga_ShadowsMaggy.function = "Saga_SetBaldMaggy";
		break;
		
		//суп из черепахи
		case "terrapin":
			dialog.text = "Herr Jones? Du nimmst mich auf den Arm, Kumpel. Weißt du, wie viele verfluchte Joneses auf dieser Insel sind? Du musst schon etwas genauer sein als das.";
			link.l1 = "Er hat eine erwachsene Schwester namens Molly. Man sagt, sie sei erstaunlich schön.";
			link.l1.go = "terrapin_1";
		break;
		
		case "terrapin_1":
			dialog.text = "Nein. Mir fällt nichts dergleichen ein. Entschuldigung, Kumpel...";
			link.l1 = "Also gut, wenn du es nicht weißt, weißt du es nicht...";
			link.l1.go = "exit";
			npchar.quest.terrapin = "true";
		break;
		
		case "guardoftruth":
			dialog.text = "Nein, habe ich nicht gehört. Und wir haben nur einen Alchemisten in der Stadt, Apotheker John Murdock. Er hat bemerkenswerte Tränke - sie heilen alle Beschwerden.";
			link.l1 = "Glauben Sie, dass er diese Tränke selbst braut?";
			link.l1.go = "guardoftruth_1";
		break;
		
		case "guardoftruth_1":
			dialog.text = "Gute Frage. Ich frage mich das auch hin und wieder. John sieht überhaupt nicht aus wie ein Kenner von Medizingläsern, Kräutern und Pulvern. Er erinnert eher an einen Ex-Soldaten, einen Söldner... das trifft eher auf die Wahrheit zu.";
			link.l1 = "Nun, ich vermute, der Mann ist überqualifiziert...";
			link.l1.go = "guardoftruth_2";
		break;
		
		case "guardoftruth_2":
			dialog.text = "Vielleicht ist er es. Aber eins weiß ich sicher, jemand lebt in seiner zweiten Etage. Das Fenster ist ständig verhängt. Selbst wenn John unten ist, hört man ein klirrendes Geräusch wie von Glasfläschchen und Flaschen, dazu der Geruch von kochenden Kräutern, und nachts geht das Licht nicht aus. Deshalb habe ich den Verdacht, dass der Bewohner dieses Zimmers derjenige ist, der Johns Medikamente zum Verkauf vorbereitet.";
			link.l1 = "Hm. Interessante Beobachtung. Danke, Kumpel!";
			link.l1.go = "exit";
			pchar.questTemp.Guardoftruth = "merdok1";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
