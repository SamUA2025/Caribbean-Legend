// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Welche Fragen haben Sie?","Wie kann ich Ihnen helfen, "+GetAddress_Form(NPChar)+"?"),"Du hast versucht, mir vor kurzem eine Frage zu stellen, "+GetAddress_Form(NPChar)+"...","Über den ganzen Tag hinweg ist dies das dritte Mal, dass du über irgendeine Frage sprichst...","Noch mehr Fragen, nehme ich an?","Block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Ich habe es mir anders überlegt...","Ich habe im Moment nichts zu besprechen."),"Hmpf, wohin ist mein Gedächtnis verschwunden...","Ja, es ist wirklich das dritte Mal...","Nein, welche Fragen?...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			if (CheckAttribute(PChar, "questTemp.Guardoftruth.Archy") && pchar.questTemp.Guardoftruth.Archy == "islatesorotavern")
			{
				link.l1 = "Hör zu, "+npchar.name+", haben Sie etwas über einen Mann namens Miguel Dichoso gehört? Man sagt, sein Schiff sei in den Gewässern von Isla Tesoro gesehen worden...";
				link.l1.go = "guardoftruth";
			}
			if(CheckAttribute(pchar, "questTemp.Tieyasal") && pchar.questTemp.Tieyasal == "begin" && !CheckAttribute(npchar, "quest.Tieyasal"))
			{
				link.l1 = "Hör zu, "+npchar.name+", hast du Miguel Dichoso in letzter Zeit auf Isla Tesoro nicht gesehen?";
				link.l1.go = "tieyasal";
			}
		break;
		
		case "guardoftruth":
			dialog.text = "Ja, das habe ich. Dieser spanische Edelmann hat Shark Dodson ein bemerkenswertes Schiff verkauft, eine Fregatte, als er noch hier wohnte. Ah dieses Schiff... Sie war unglaublich...";
			link.l1 = "Lass mich raten: Sie hatte einen modernen schlanken Rahmen und war in der Lage, sechzehn Knoten zu erreichen? Und ihr Name war 'Santa Quitaria'?";
			link.l1.go = "guardoftruth_1";
		break;
		
		case "guardoftruth_1":
			dialog.text = "Was den Rahmen und die Geschwindigkeit betrifft, liegen Sie absolut richtig, aber sie hatte einen anderen Namen: 'San Martin'. Der Hai hat diesem Schurken einen ganzen Haufen Gold für dieses Schiff bezahlt.";
			link.l1 = "Bist du sicher, dass es 'San Martin' und nicht 'Santa Quiteria' war? Wann hat er es gekauft? Und warum nennst du Dichoso einen Schurken?";
			link.l1.go = "guardoftruth_2";
		break;
		
		case "guardoftruth_2":
			dialog.text = "Verdammt sollen meine Augen sein, ich bin absolut sicher, dass es 'San Martin' war, weil ich persönlich gesehen habe, wie Alexus' Arbeiter eine Platte mit diesem papistischen Unsinn vom Heck rissen. Shark Dodson nannte sie 'Fortune', ein weitaus passenderer Name für so eine Schönheit. (spuckt) Er kaufte sie im Winter '54, kurz bevor Blaze ermordet wurde\nWarum habe ich Don Miguel einen Schurken genannt? Weil er das verdammte Schiff aus der spanischen Marine in Providence gestohlen hat! Dodson inszenierte eine Vorstellung mit Feuer und Rauch für das Fort St. Juan und seine Garnison, wie er mir immer erzählte, wenn er betrunken war. Shark opferte zwei beschädigte Logger, um den Kampf mit der Fregatte echt aussehen zu lassen\nAls die Nacht kam, segelte er heimlich 'San Martin' zur Isla Tesoro. Shark bekam das Schiff und Dichoso bekam das Geld. Der schlauere Schurke erzählte später seinen Vorgesetzten, dass die Fregatte im Kampf mit der Piratenflotte versenkt wurde, der Kommandant des Forts St. Juan bestätigte es.";
			link.l1 = "Oh, wie diese spanischen Herren ihre Taschen füllen! Was für ein Schlitzohr! Sag mal, bist du sicher, dass das im Winter 1654 passiert ist? Könnte es nicht im Frühling gewesen sein? Und zeigte nicht diese Fregatte Verschleißspuren vom Sturm?";
			link.l1.go = "guardoftruth_3";
		break;
		
		case "guardoftruth_3":
			dialog.text = "Ich bin mir ziemlich sicher, es war Winter... Ach, wer weiß. Vielleicht war es Frühling. Ich erinnere mich nicht genau. Ich war wahrscheinlich betrunken. Die Fregatte war überhaupt nicht abgenutzt, sie war brandneu.";
			link.l1 = "Und wo ist diese Schönheit von einer Fregatte jetzt?";
			link.l1.go = "guardoftruth_4";
		break;
		
		case "guardoftruth_4":
			dialog.text = "Eine dunkle Geschichte, das ist es... Als Blaze ermordet wurde, verdächtigte jeder Shark, weil seine Halskette, ein Haifischzahn, auf der Leiche gefunden wurde. Außerdem sahen einige Leute Shark in Blazes Residenz in dieser Nacht\nShark entkam Isla Tesoro, bevor sie ihm das schwarze Zeichen gaben. Er besuchte den Dunklen Pastor und tauschte seine Fregatte gegen eine Brigg aus. Keine Ahnung, wo der Mann jetzt ist. Zachary verkaufte die Fregatte später an William Paterson.";
			link.l1 = "Wer ist dieser Paterson?";
			link.l1.go = "guardoftruth_5";
		break;
		
		case "guardoftruth_5":
			dialog.text = "Was, du hast noch nie von Willie Paterson gehört? Er ist ein Schotte, gerade in der Karibik angekommen. Hält sich selbst für den Kapitän der königlichen Flotte, Colonel Foxs Liebling selbst! Übrigens, er hat gerade angefangen, ein Geschäft mit Jackman zu drehen. Pattersons Flaggschiff ist die 'Fortune' selbst.";
			link.l1 = "Ich verstehe. Wissen Sie, wo Dichoso gerade ist?";
			link.l1.go = "guardoftruth_6";
		break;
		
		case "guardoftruth_6":
			dialog.text = "Ich habe keine Ahnung. Nach diesem Hokuspokus mit 'Fortune' habe ich ihn seitdem nicht mehr auf Isla Tesoro gesehen und nichts mehr über ihn gehört.";
			link.l1 = "In Ordnung, "+npchar.name+", danke für die ausführlichen Informationen! Du bist ein ausgezeichneter Wirt! Ich wünschte, es gäbe mehr Leute wie dich... Tschüss!";
			link.l1.go = "guardoftruth_7";
		break;
		
		case "guardoftruth_7":
			dialog.text = "Viel Glück, "+pchar.name+"!";
			link.l1 = "...";
			link.l1.go = "guardoftruth_8";
		break;
		
		case "guardoftruth_8":
			DialogExit();
			AddQuestRecord("Guardoftruth", "60_1");
			pchar.questTemp.Guardoftruth.Archy = "guadeloupe";
			// маленькая развлекуха
			pchar.quest.GuardOT_cabinattack.win_condition.l1 = "EnterToSea";
			pchar.quest.GuardOT_cabinattack.function = "GuardOT_PrepareCreateBandosInCabin";
		break;
		
		case "tieyasal":
			dialog.text = "Es sieht so aus, als ob ihr beide einander jagt, Kumpel. Ja, Dichoso war genau hier, wo du stehst. Und genau so hat er das letzte Mal über dich befragt, als du in Sharptown warst.";
			link.l1 = "Verdammt! Das sind die Neuigkeiten... Und wo ist Miguel gerade jetzt?";
			link.l1.go = "tieyasal_1";
		break;
		
		case "tieyasal_1":
			dialog.text = "Ich habe keine Ahnung. Er ist aufs Meer hinausgefahren, wo... er hat etwas über Blueweld gesagt. Er ist wahrscheinlich dorthin gefahren, nur um dich zu suchen.";
			link.l1 = "Bist du zufällig derjenige, der ihn nach Blueweld geschickt hat?";
			link.l1.go = "tieyasal_2";
		break;
		
		case "tieyasal_2":
			dialog.text = "Nein. Alles, was ich ihm sagte, war, dass ich dich lange nicht gesehen habe.";
			link.l1 = "Ich verstehe. Also gut, dann. Danke, Kumpel!";
			link.l1.go = "tieyasal_3";
		break;
		
		case "tieyasal_3":
			DialogExit();
			AddQuestRecord("Tieyasal", "3");
			npchar.quest.tieyasal = "true";
			pchar.quest.Tieyasal_ITAttack.win_condition.l1 = "location";
			pchar.quest.Tieyasal_ITAttack.win_condition.l1.location = "Bermudes";
			pchar.quest.Tieyasal_ITAttack.function = "Tieyasal_CreateITShips";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
