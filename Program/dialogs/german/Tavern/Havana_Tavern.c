// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat("Alle die Gerüchte von "+GetCityName(npchar.city)+" zu Ihren Diensten. Was möchten Sie erfahren?","Wir haben gerade darüber gesprochen. Du musst es vergessen haben...","Das ist das dritte Mal heute, dass du von irgendeiner Frage sprichst...","Du wiederholst dich wie ein Papagei...","Block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Weißt du, "+NPChar.name+", vielleicht nächstes Mal.","Richtig, ich habe aus irgendeinem Grund vergessen...","Ja, es ist wirklich das dritte Mal...","Jawohl...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			if (CheckAttribute(pchar, "questTemp.Slavetrader") && pchar.questTemp.Slavetrader == "FindRatHavana")
            {
                link.l1 = "Hat Francois Gontier zufällig in Ihrer Stadt angehalten? Er hat eine Korvette '"+pchar.questTemp.Slavetrader.ShipName+"', nur für den Fall... ";
                link.l1.go = "Havana_ratT_1";
            }
			if (CheckAttribute(npchar, "quest.batabano"))
            {
                link.l1 = "Sag mir, Kumpel, wo könnte ich Don Diego de Montoya finden? Bin ich zu spät dran? Ist er schon nach Main aufgebrochen?";
                link.l1.go = "guardoftruth";
            }
			// калеуче
			if (CheckAttribute(pchar, "questTemp.Caleuche") && pchar.questTemp.Caleuche == "graveyard" && !CheckAttribute(npchar, "quest.caleuche"))
			{
				link.l1 = "Hör zu, ist ein Mann namens Joachim Merriman hier vorbeigekommen? Ein mittelalterlicher Arzt, Portugiese, mit Schnurrbart, kaiserlichem Bart und durchdringenden Augen? Vielleicht wollte er ein Zimmer mieten?";
				link.l1.go = "caleuche";
			}
		break;

		case "Havana_ratT_1":
			dialog.text = "Aha, dieser düstere Kerl? Ja, er hat bei mir vorbeigeschaut. Ich sag dir was: er hatte ein Treffen mit Oregon-und-Haskon. Er hat sich beworben, um ein Patent zu erhalten. Aber es hat für ihn nicht geklappt und er ist von dort verschwunden.";
			Link.l1 = "Und wo ist er hingefahren, wissen Sie das? Ich habe ihn seit Porto Bello verfolgt und kann ihn einfach nicht finden.";
			Link.l1.go = "Havana_ratT_2";
		break;
		
		case "Havana_ratT_2":
			dialog.text = "Was brauchen Sie von ihm? Er hat Angst vor Fremden, er versteckt sich immer vor jedem, sobald er einen bewaffneten Fremden sieht, greift er nach einem Schwert. Er geht nur umgeben von vier Wächtern herum. Sind Sie zufällig der Mann, vor dem er auf der Hut ist?";
			Link.l1 = "Herr, die Leute sagen das immer wieder! Was, sehe ich aus wie ein Mörder? Er ist mein alter Kumpel, ich bin in Eile, ihm einige Neuigkeiten zu überbringen, er wird ganz erfreut sein zu wissen, dass er sich nicht länger verstecken muss, niemand sucht ihn.";
			Link.l1.go = "Havana_ratT_3";
		break;
		
		case "Havana_ratT_3":
			dialog.text = "Er muss sich nicht verstecken? Ha-ha-ha! Nur einen Tag vor seiner Abreise aus Havanna versuchte eine ganze Bande von Halunken, ihn im Dschungel umzubringen... Natürlich hatte er seine eigenen Leute und sie haben sie in Sekundenschnelle in Hackfleisch verwandelt. Und du sagst hier...";
			Link.l1 = "Ach komm schon. Es waren wahrscheinlich nur einige lokale Banditen, die versuchten, seine Brieftasche zu bekommen. Du weißt selbst, wie viele Schurken durch den Dschungel laufen. Also, wo ist er hin?";
			Link.l1.go = "Havana_ratT_4";
		break;
		
		case "Havana_ratT_4":
			dialog.text = "Nun, nachdem er weit und lange von der Residenz geschickt wurde, beharrte er darauf, dass er sich den Froschfressern, seinen Landsleuten, stellen würde. Er ist nach Tortuga aufgebrochen, zu einem gewissen d'Ogeron... Er murmelte auch etwas über seine Geliebte, aber ich konnte ihn nicht ganz verstehen.";
			Link.l1 = "Also, Tortuga? Großartig! Ich hoffe, ich erwische ihn dort. Danke, "+npchar.name+", du warst eine große Hilfe. Tschüss.";
			Link.l1.go = "exit";
			AddQuestRecord("Slavetrader", "21_7");
			pchar.questTemp.Slavetrader = "FindRatTortuga";
			pchar.quest.Slavetrader_findTortugaRat.win_condition.l1 = "location";
            pchar.quest.Slavetrader_findTortugaRat.win_condition.l1.location = "Tortuga_HouseHut";
            pchar.quest.Slavetrader_findTortugaRat.win_condition = "Slavetrader_findTortugaRat";
		break;

		case "guardoftruth":
			dialog.text = "Hm...Und warum sollte ein Franzose sich für Don Diego interessieren, hm?";
			link.l1 = "Die Tatsache, dass ich Franzose bin, ist irrelevant. Was zählt, ist dieses vom Inquisitor unterzeichnete Dokument. Schau mal... siehst du jetzt? Ich habe eine dringende Nachricht für Diego.";
			link.l1.go = "guardoftruth_1";
		break;
		
		case "guardoftruth_1":
			dialog.text = "A-ha, also arbeitest du für Seine Ehrwürdigkeit, Vater Vincento? Das ändert die Dinge. Don Diego de Montoya ist vor zwei Tagen mit seiner Staffel abgereist, aber bald auf seinem Kurierlugger zurückgekehrt. Eines seiner Schiffe ist auf den Riffen südlich von Kuba gestrandet, also hat er gerade heute Reparaturmaterial gekauft\nÜberprüfe die Bucht im Süden, du wirst dort ein Schiff und den Mann selbst finden. Ich bezweifle, dass sie es bereits geschafft haben, die Löcher zu reparieren.";
			link.l1 = "Danke, Kumpel! Du warst eine große Hilfe!";
			link.l1.go = "guardoftruth_2";
		break;
		
		case "guardoftruth_2":
			dialog.text = "Überhaupt nicht, jederzeit. Ich helfe immer gerne einem Jesuitenbruder.";
			link.l1 = "Ja, pax vobiscum und all das.";
			link.l1.go = "guardoftruth_3";
		break;
		
		case "guardoftruth_3":
			DialogExit();
			DeleteAttribute(npchar, "quest.batabano");
			AddQuestRecord("Guardoftruth", "47");
			pchar.quest.GuardOT_Batabano.win_condition.l1 = "location";
			pchar.quest.GuardOT_Batabano.win_condition.l1.location = "Shore13";
			pchar.quest.GuardOT_Batabano.function = "GuardOT_SanAntonioPrepare";
		break;
		
		// калеуче
		case "caleuche":
			dialog.text = "Der Teufel weiß es, Kumpel. Er könnte angekommen sein, aber ich weiß nichts davon. Es tut mir leid.";
			link.l1 = "Ich verstehe. Schade. Ich werde meine Suche fortsetzen...";
			link.l1.go = "exit";
			npchar.quest.caleuche = "true";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
