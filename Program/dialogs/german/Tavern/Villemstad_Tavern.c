// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat("Alle Gerüchte von "+GetCityName(npchar.city)+" zu Ihren Diensten. Was möchten Sie herausfinden?","Wir haben gerade darüber gesprochen. Du musst es vergessen haben...","Das ist das dritte Mal heute, dass du von irgendeiner Frage sprichst...","Du plapperst immer das Gleiche wie ein Papagei...","Block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Weißt du, "+NPChar.name+", vielleicht nächstes Mal.","Richtig, ich habe aus irgendeinem Grund vergessen...","Ja, es ist wirklich das dritte Mal...","Ja...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			//работорговец
			if (pchar.questTemp.Slavetrader == "EscapeSlave_Villemstad")
            {
                link.l1 = "Ich habe gehört, dass es auf der Insel ein heilloses Durcheinander gab... Sklaven?";
                link.l1.go = "EscapeSlaveVillemstad_T1";
            }
			//Португалец
			if (CheckAttribute(pchar, "questTemp.Portugal") && pchar.questTemp.Portugal == "SeekPortVillemstad")
            {
                link.l1 = "Ich habe gehört, dass dieser verfluchte Schurke Bart der Portugiese endlich Gerechtigkeit getroffen hat! Ist er im Gefängnis? Wann wird seine Hinrichtung sein, weißt du das? Ich möchte zuschauen, ich habe eine Rechnung mit diesem Abschaum zu begleichen...";
                link.l1.go = "Portugal";
            }
 		break;

		//работорговец
		case "EscapeSlaveVillemstad_T1":
			dialog.text = "Ja, so ein Durcheinander gab es noch nie... Mehr als tausend Neger haben sich aufgelehnt. Zwei Plantagen wurden bis auf den Grund niedergebrannt und jeder ihrer Herren wurde ermordet. Der Kommandant befürchtet, dass die Sklaven die Stadt angreifen könnten, also hat er das Kriegsrecht durchgesetzt. Und das alles begann wegen zwei Negern, einem Bock namens Tamango und einer Hirschkuh namens Isauri...";
			link.l1 = "Klingt ziemlich dramatisch. Erzähl mir die ganze Geschichte, wer sind diese Schwarzen?";
			link.l1.go = "EscapeSlaveVillemstad_T2";
		break;
		
		case "EscapeSlaveVillemstad_T2":
				dialog.text = "Tamango und Izaura - Sklaven auf der Blenheim-Plantage, der ersten niedergebrannten Plantage. Diese beiden Neger liebten sich. Aber der Sohn des Pflanzers, Leonsio, kam aus Europa und verliebte sich in die Hirschkuh. Er wollte Izaura zu seiner persönlichen Konkubine machen. Der schwarze Hirsch Tamango mochte die Idee nicht und Izaura auch nicht, sie liebte wirklich den schwarzen Teufel\nDieser Tamango war eine Art Häuptling oder so in Afrika... Ein riesiger Hirsch - schwärzer als die Sünde und tödlich mit einer Axt, die anderen Neger fürchteten und respektierten ihn. Also führte dieser Neger die anderen Sklaven zu einem Aufstand. Sie griffen die Wachen in der Nacht an, töteten jeden Weißen außerhalb des großen Hauses, auch die Mulatten\nDann öffnete Izaura die Türen der Plantage und die wilden Affen mordeten jeden im Inneren. Blenburg wurde niedergebrannt. Dann flohen die Sklaven in die Dschungel und verschwanden...";
			link.l1 = "Nun, wie ist das für eine Geschichte, klingt wie die Handlung für einen Roman! Ein ordentlicher Sklavenaufstand, genau wie im alten Rom. Wie hast du das übrigens herausgefunden?";
			link.l1.go = "EscapeSlaveVillemstad_T3";
		break;
		
		case "EscapeSlaveVillemstad_T3":
			dialog.text = "Gerüchte, mein Herr, die Erde ist voll von ihnen. Rum löst die Zungen, Sie müssen nur zuhören...";
			link.l1 = "Und wie ist das alles ausgegangen? Haben sie diese Neger gefunden?";
			link.l1.go = "EscapeSlaveVillemstad_T4";
		break;
		
		case "EscapeSlaveVillemstad_T4":
				dialog.text = "Ha, keine Chance! Bis die Verstärkungen endlich eintrafen, hat niemand einen Schritt in den Dschungel gewagt. Dann kam ein Kriegsschiff der Kompanie mit einer Einheit Soldaten und sie durchsuchten die Insel. Sie fanden weder schwarze Haut noch lockiges Haar von einem einzigen entlaufenen Neger.";
			link.l1 = "Nun, wie wäre es damit! Tausend Neger sind einfach in Luft aufgelöst?";
			link.l1.go = "EscapeSlaveVillemstad_T5";
		break;
		
		case "EscapeSlaveVillemstad_T5":
			dialog.text = "Eigentlich ins Wasser.";
			link.l1 = "Wovon redest du, "+npchar.name+"? Sie wissen genauso gut wie ich, dass Negros nicht schwimmen können.";
			link.l1.go = "EscapeSlaveVillemstad_T6";
		break;
		
		case "EscapeSlaveVillemstad_T6":
			dialog.text = "He-he... oh nein, diese Schwarzen sind nicht so schnell Haifutter. Die Sache ist die, am nächsten Abend nach der Meuterei verschwand eine Bark von den Docks. Du kannst mich schwarz anmalen und ich spiele das Banjo und tanze für dich, wenn das nicht auf das Konto von diesem Burschen Tamango und seinen Negern geht! Deswegen sind sie nicht mehr auf der Insel.";
			link.l1 = "Ha, jetzt habe ich alles gehört, "+npchar.name+". Ihr erwartet von mir, dass ich glaube, dass eine Gruppe halbwilder Neger Segel handhaben und navigieren kann? Ich würde eher erwarten, dass ein Schiff voller Affen aus Guinea hereinstürzt.";
			link.l1.go = "EscapeSlaveVillemstad_T7";
		break;
		
		case "EscapeSlaveVillemstad_T7":
			dialog.text = "Ich habe es auch nicht geglaubt, Herr, aber der Beweis liegt im verschwundenen Schiff. Vielleicht hat einer dieser Neger als Steward auf einem Schiff gedient und einige Segeltechniken erlernt. Vielleicht haben sie schwarze Magie benutzt, wer weiß! Besuchen Sie mich wieder, "+pchar.name+", Ich werde das nächste Mal mehr Geschichten für dich haben.";
			link.l1 = "Danke! Nun, es ist Zeit für mich zu gehen.";
			link.l1.go = "exit";
			AddQuestRecord("Slavetrader", "22_2");
			pchar.questTemp.Slavetrader = "EscapeSlaveVillemstad_P";
		break;						

		case "Portugal":
			dialog.text = "Ja, das ist korrekt. Sie haben diesen Piraten gefangen. Und kannst du glauben, wie? Er wurde allein auf einem Beiboot mitten auf dem Meer aufgegriffen. Er hat keinen Mucks gemacht, bevor er in den Laderaum für die Ratten geschickt wurde. Es ist wirklich amüsant, weißt du, so ein gefährlicher Pirat wurde wie ein solcher Tölpel gefangen!";
			link.l1 = "Und warum war er ganz allein auf dem Meer?";
			link.l1.go = "Portugal_1";
		break;
		
		case "Portugal_1":
			dialog.text = "Er hat sich wahrscheinlich dazu entschieden, sich von seinen Schergen zu trennen, ohne Zweifel... Sie konnten die Beute nicht fair teilen. Jetzt ist er in den Händen der Kompanie selbst und diese Kerle verstehen keinen Spaß. Sie sagen, er habe sich eines der Boote der Kompanie bemächtigt, mit etwas Wertvollem darauf. Anscheinend hängt er nur deshalb noch nicht am Galgen, weil sie noch einige Informationen aus ihm herauspressen wollen.";
			link.l1 = "Also, wann wird seine Hinrichtung sein, weißt du das?";
			link.l1.go = "Portugal_2";
		break;
		
		case "Portugal_2":
			dialog.text = "Niemand weiß es. Ich denke, sobald die Kompanie herausfindet, was sie will, werden sie ihm eine Hanfkrawatte um den Hals legen. Der Portugiese sitzt gerade im Gefängnis unter zuverlässiger Bewachung\nKürzlich haben sie auch seinen Bootsmann hierher gebracht. Seine Geschichte war noch überraschender, er hat sich den Holländern in Philipsburg ergeben. Also, sie haben ihn in eine Zelle direkt neben seinem Ex-Kapitän gesteckt, sie sind jetzt also Nachbarn, he-he...";
			link.l1 = "Wunder geschehen doch! Na gut, ich werde nach den Neuigkeiten Ausschau halten. Ich will diese Hängung nicht verpassen. Tschüss, "+npchar.name+"!";
			link.l1.go = "Portugal_3";
		break;
		
		case "Portugal_3":
			DialogExit();
			pchar.questTemp.Portugal = "PortugalInPrison";
			AddQuestRecord("Portugal", "32");
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
