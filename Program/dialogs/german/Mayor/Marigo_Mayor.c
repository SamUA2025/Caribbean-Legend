// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Was willst du? Frag nur.","Ich höre Ihnen zu, was ist die Frage?"),"Das ist das zweite Mal, dass Sie versuchen zu fragen...","Das ist das dritte Mal, dass Sie versuchen zu fragen...","Wann wird das endlich aufhören?! Ich bin ein beschäftigter Mann, der sich um Kolonieangelegenheiten kümmert und du belästigst mich immer noch!","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Ich habe meine Meinung geändert...","Nicht jetzt. Falscher Ort und Zeit."),"Wahr... Aber später, nicht jetzt...","Ich werde fragen... Aber ein bisschen später...","Es tut mir leid, "+GetAddress_FormToNPC(NPChar)+"...",npchar,Dialog.CurrentNode);			  
			link.l1.go = "exit";
			//Jason, Португалец
			if (CheckAttribute(PChar, "questTemp.Portugal") && pchar.questTemp.Portugal == "ToGovernor")
			{
				link.l1 = "Eure Gnaden, ich habe absolut exzellente und dringende Neuigkeiten für Sie! Ich habe Bartolomeo den Portugiesen gefangen genommen, der Bastard ist unter Bewachung und sucht ein faires Gerichtsverfahren! Und ich suche nach etwas bescheidener Dankbarkeit der Kompanie...";
				link.l1.go = "Portugal";
			}
			//Португалец
			
			// Addon-2016 Jason ФМК-Сент-Кристофер
			if (CheckAttribute(PChar, "questTemp.FMQN") && pchar.questTemp.FMQN == "governor")
			{
				link.l1 = "Sie bestanden darauf, mich zu sehen, Mynheer Gouverneur...";
				link.l1.go = "FMQN";
			}
			if (CheckAttribute(PChar, "questTemp.FMQN") && pchar.questTemp.FMQN == "hol_battle_complete")
			{
				link.l1 = "Ich bin hier in der Angelegenheit der englischen Spione, Herr Gouverneur...";
				link.l1.go = "FMQN_7";
			}
		break;

		case "Cupture_after":
            dialog.text = RandPhraseSimple("Du hast bereits alles genommen. Was willst du noch?","Gibt es noch etwas, das Sie nicht geschnappt haben?");
            link.l1 = RandPhraseSimple("Nur mal umsehen...","Nur zur Kontrolle, ich könnte vergessen, etwas mitzunehmen...");
            link.l1.go = "exit";
            NextDiag.TempNode = "Cupture_after";
		break;
		
		//Jason, Португалец
		case "Portugal":
			dialog.text = "Bartolomeo... Bart der Portugiese ist in meiner Stadt?! Lebendig?!!";
			link.l1 = "Er ist es, Eure Gnaden, und er befindet sich unter zuverlässiger Bewachung. Ich werde ihn Ihnen übergeben, nachdem ich den versprochenen Schein für Barts Kopf von der Kompanie erhalten habe. Goldene Dublonen wären auch in Ordnung...";
			link.l1.go = "Portugal_1";
		break;
		
		case "Portugal_1":
			dialog.text = "Bill, Dublonen? Bist du verrückt?! Was hast du dir gedacht, dieses Biest in meine Stadt zu bringen?! Wenn er hier ist, dann ist seine Fregatte nicht weit von der Insel und seine Mannschaft könnte gerade jetzt in der Stadt sein!";
			link.l1 = "Ich habe diejenigen getötet, die bei ihm waren, von anderen weiß ich nichts, aber ich nehme an, es spielt keine Rolle, weil Bartolomeo ist...";
			link.l1.go = "Portugal_2";
		break;
		
		case "Portugal_2":
			dialog.text = "Das tut es! Verstehen Sie wirklich nicht, was Sie getan haben?! Die 'Albatros' ist in der Nähe der Insel und Sie haben den Piraten gefangen genommen, dessen Brutalität selbst sein eigenes blutrünstiges Volk erschreckt! Verschwinden Sie von hier! Verlassen Sie die Insel! Und nehmen Sie dieses Monster mit Ihnen!";
			link.l1 = "Aber hören Sie, was ist mit der versprochenen Belohnung und...";
			link.l1.go = "Portugal_3";
		break;
		
		case "Portugal_3":
			dialog.text = "Ich will nicht zusehen, wie meine Stadt wegen deiner Gier und der Rachsucht der Kompanie brennt! In meiner Festung sind nur frische Rekruten und die Hälfte von ihnen wird fliehen, sobald sie erfahren, wer und warum ihre Ravelins angreift! Und dann wird das Gemetzel beginnen... Ich werde das Risiko nicht eingehen, hörst du mich?! Verschwinde und bring ihn selbst nach Curacao, wenn die Kompanie seinen Kopf so sehr will!\nMach es sofort, bevor es zu spät ist! Und du kannst mit ihm machen, was du willst, ihn sogar von deinem Schiffsdeck werfen, nur nicht in meiner Stadt!\nHans! Hans, wo bist du, du fauler Idiot! Hol mir einen Baldriantrunk oder so etwas und jemand, um Gottes willen, werfe diesen Abenteurer aus meiner Residenz!";
			link.l1 = "Aber Eure Gnaden...";
			link.l1.go = "Portugal_4";
		break;
		
		case "Portugal_4":
			DialogExit();
			DoQuestReloadToLocation("Marigo_town", "reload", "reload3_back", "PortugalOutResidence");
		break;
		
		// Addon-2016 Jason ФМК-Сент-Кристофер
		case "FMQN":
			DelLandQuestMark(npchar);
			dialog.text = "Sehr gut! Sagen Sie mir, Kapitän, haben Sie auf Ihrem Weg zu unserer Insel irgendwelche englischen Militär- oder Handelsschiffe getroffen?";
			link.l1 = "Nein, Mynheer. Ich habe weder militärische noch Handelsschiffe unter englischer Flagge in Ihren Gewässern gesehen.";
			link.l1.go = "FMQN_1";
		break;
		
		case "FMQN_1":
			dialog.text = "Ich verstehe. Wie lange planen Sie hier zu bleiben?";
			link.l1 = "Drei Tage oder so...";
			link.l1.go = "FMQN_2";
		break;
		
		case "FMQN_2":
			dialog.text = "In diesem Fall habe ich ein Angebot für Sie. Laut unseren Informationen besteht hier die Gefahr englischer Spione. Ich werde zehntausend Pesos als Belohnung für Informationen über verdächtige Schiffe und Personen auf der Insel, in der Stadt, in ihrer Umgebung, an den Küsten, etc. geben. Die Belohnung wird im Falle einer Unterstützung der Behörden bei der Festnahme oder Eliminierung eines Feindes erheblich erhöht.\nJeder zivile Kapitän ist willkommen, an der Untersuchung teilzunehmen und die örtlichen Küsten und den Dschungel nach den Spionen zu durchsuchen.\nEs ist möglich, dass Sie auf unsere Militärkorvette, die Zeepard, treffen, haben Sie keine Angst, sie ist auf Patrouille. Sie können sich jederzeit an ihren Kapitän wenden, wenn Sie die Briten finden.";
			link.l1 = "Ach, Eure Exzellenz, aber ich bin nur mit friedlichen Handelsabsichten hier. Ich werde diese Insel verlassen müssen, sobald ich meine Vorräte aufgefüllt und meine Geschäfte hier abgeschlossen habe.";
			link.l1.go = "FMQN_3";
			link.l2 = "Ein verlockendes Angebot! Ich glaube, ich werde teilnehmen und die Gewässer und Ufer Ihrer Insel überfallen. Ich könnte sogar für eine Weile hier bleiben.";
			link.l2.go = "FMQN_5";
		break;
		
		case "FMQN_3":
			dialog.text = "Es ist nur kostenlose Information, Kapitän. Kein Druck. Sie wissen, an wen Sie sich wenden müssen, falls Ihnen etwas Verdächtiges auffällt.";
			link.l1 = "Sehr gut, Mynheer, ich habe es verstanden. Auf Wiedersehen!";
			link.l1.go = "FMQN_4";
		break;
		
		case "FMQN_4":
			DialogExit();
			pchar.questTemp.FMQN = "way_eng_1";
			AddQuestRecord("FMQ_Nevis", "8");
			chrDisableReloadToLocation = false;
			FMQN_SetSoldiersInCave();
		break;
		
		case "FMQN_5":
			dialog.text = "Herrlich, Kapitän! Da Sie so ernst sind, stellen Sie sicher, dass Sie auch mit unserem Kommandanten sprechen. Er ist verantwortlich für die Ergreifung der Spione und könnte Ihnen zusätzliche Informationen geben.";
			link.l1 = "Gut, Mynheer. Ich werde ihn besuchen.";
			link.l1.go = "FMQN_6";
		break;
		
		case "FMQN_6":
			DialogExit();
			pchar.questTemp.FMQN = "way_div";
			AddQuestRecord("FMQ_Nevis", "9");
			chrDisableReloadToLocation = false;
			AddLandQuestMarkToPhantom("marigo_prison", "marigoJailOff");
		break;
		
		case "FMQN_7":
			DelLandQuestMark(npchar);
			dialog.text = "Wir haben auf Sie gewartet, Mynheer "+GetFullName(pchar)+". Lassen Sie mich unseren Dank für Ihre Handlungen bei der Beseitigung der gefährlichen englischen Plünderungspartei ausdrücken. Nehmen Sie diese zehntausend Pesos an. Zusätzlich: 200 Schiffsseide wird in den Laderaum Ihres Schiffes geladen und eine ganz besondere Belohnung - eine dreijährige Lizenz der Niederländischen Westindischen Handelsgesellschaft. Dies ist ein äußerst wertvolles Dokument, ich hoffe, Sie wissen das?";
			link.l1 = "Natürlich! Eine Lizenz für drei Jahre - das ist sicher groß.";
			link.l1.go = "FMQN_8";
		break;
		
		case "FMQN_8":
			dialog.text = "Bitte, nehmen Sie Ihre Belohnung. Darüber hinaus können Sie auf die Dankbarkeit aller niederländischen Bürger und Behörden zählen. Sie sind eine Sensation in Philipsburg, wir würden uns freuen, Sie wieder zu sehen.";
			link.l1 = "Solch warme Worte zu hören ist wertvoller als die Lizenz. Danke, es war mir ein Vergnügen. Und nun sollte ich mich auf den Weg machen. Auf Wiedersehen!";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("FMQN_HollandBattleComplete");
		break;
		
		// Jason НСО
		case "tomas":
			dialog.text = "Wir kapitulieren! Im Namen alles Heiligen, ich flehe Sie an, plündern und verwüsten Sie nicht Philipsburg und seine Bürger! Ich bin bereit, Ihre Forderungen anzuhören!";
			link.l1 = "Machen Sie sich keine Sorgen um die Bürger, Mynheer. Untertanen der französischen Krone sollten keine Angst vor französischen Soldaten haben.";
			link.l1.go = "tomas_1";
		break;
		
		case "tomas_1":
			dialog.text = "Die französische Krone?";
			link.l1 = "Genau. Diese Insel gehört Frankreich, und ihr seid hier nur Mieter. Unverschämte Mieter, die glaubten, diese Insel könnte ihr Eigentum sein. Ab heute ist die niederländische Autorität in Saint Maarten beendet. Ist das klar?";
			link.l1.go = "tomas_2";
		break;
		
		case "tomas_2":
			dialog.text = "Aber ... Aber was wird mit uns geschehen, mit den holländischen Soldaten, die sich Ihnen ergeben haben, und den Verwundeten? Und was...";
			link.l1 = "Das wird nur von Ihnen abhängen, Mynheer Thomas. Wenn Sie mir einen Gefallen tun, dann werde ich allen, die aufgegeben haben, erlauben, ihre Verwundeten zu nehmen und von hier auf einem oder mehreren Schiffen, die wir in den Docks finden, nach Curacao, zu Mynheer Stuyvesant zu fahren.";
			link.l1.go = "tomas_2_1";
		break;
		
		case "tomas_2_1":
			dialog.text = "";
			link.l1 = "Andernfalls werdet ihr in den Laderäumen meiner Schiffe und den Kasematten von Saint Kitts gehalten. Außerdem müssen einige wichtige niederländische Beamte gehängt werden, nur um sicherzustellen, dass Stuyvesant sein Interesse an der Eroberung unserer Kolonien verliert...";
			link.l1.go = "tomas_3";
		break;
		
		case "tomas_3":
			dialog.text = "(stotternd) Wa... Was... über we...elche A-Art von G-Gefe... lligkeit?";
			link.l1 = "In den Tiefen der Insel liegt ein Zankapfel - eine Salzmine. Ich weiß, dass es dort nicht nur Bergleute und Sklaven gibt, sondern auch holländische Soldaten, bis an die Zähne bewaffnet. Sie müssen von der Kompaniegarde sein, nicht wahr, Mynheer? Ich werde ihnen anbieten, sich zu ergeben, oder ich werde Gewalt anwenden, im Falle ihrer Weigerung. Ich brauche einen Führer, der mir den Weg zur Mine zeigt. Finden Sie mir einen solchen Führer.";
			link.l1.go = "tomas_4";
		break;
		
		case "tomas_4":
			dialog.text = "S-Salz....m-mein?";
			link.l1 = "Genau. Haben Sie keine Angst, Mynheer Thomas, wenn die Wachen der Mine klug genug sind, ihre Waffen aufzugeben, werde ich ihnen die Möglichkeit geben, die Insel zu verlassen. Ich brauche kein unnötiges Blutvergießen. Machen Sie sich keine Sorgen, Ihr Gewissen wird rein sein: Selbst wenn Sie mir nicht sagen, wo die Mine ist, ist die Insel Saint Maarten klein genug, dass ich die Mine auch ohne Ihre Hilfe finden kann, ich möchte nur nicht meine Zeit verschwenden, durch Dickicht und Sümpfe zu streifen. Also ist dieses Geschäft für Sie profitabler als für mich.";
			link.l1.go = "tomas_5";
		break;
		
		case "tomas_5":
			dialog.text = "F-fi...ne, ich werde Ihnen sagen, wie Sie zur Mine gelangen, a-aber Sie müssen mir I-Ihr... Wort geben, dass wir alle... alle diese Insel verlassen werden!";
			link.l1 = "Ich gebe Ihnen mein Wort als Offizier und Adeliger.";
			link.l1.go = "tomas_6";
		break;
		
		case "tomas_6":
			dialog.text = "In der Grand Case Bucht... an ihrem weitesten Rand, nahe dem Wasser, gibt es... es gibt Steine. Dort... dort, hinter ihnen, entlang der Küste, gibt es einen Weg am Wasser entlang, dort... es ist dort flach, hüfthoch oder weniger. Du musst um den Felsen herumgehen und du kommst zu einem großen Strand, wo... wo du dein Schiff wegen der Riffe drumherum nicht anlegen kannst. Von diesem Strand aus führt ein Weg direkt... zu... zur Mine.";
			link.l1 = "Ausgezeichnet. Ich mache mich auf den Weg. Und Sie, Mynheer, bleiben hier unter sorgfältiger Beobachtung meiner Soldaten, bis ich zurückkehre.";
			link.l1.go = "tomas_7";
		break;
		
		case "tomas_7":
			DialogExit();
			SetReturn_Gover_Dialog_Exit(NPChar);
			LAi_SetActorType(npchar);
			pchar.quest.Patria_BastionGate.win_condition.l1 = "location";
			pchar.quest.Patria_BastionGate.win_condition.l1.location = "Shore40";
			pchar.quest.Patria_BastionGate.function = "Patria_BastionShore";
			AfterTownBattle();
			AddQuestRecord("Patria", "50_1");
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
