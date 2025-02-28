// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Welche Fragen haben Sie?","Wie kann ich Ihnen helfen?"),"Du hast versucht, mir diese Frage vor kurzem zu stellen...","Jawohl, lass mich raten... Wieder einmal im Kreis unterwegs?","Hör zu, ich mache hier die Finanzen, ich beantworte keine Fragen...","Block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Ich habe meine Meinung geändert...","Ich habe im Moment nichts zu besprechen."),"Umph, wo ist mein Gedächtnis hin...","Du hast es erraten, es tut mir leid...","Ich verstehe...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			// Addon-2016 Jason ФМК-Гваделупа
			if (CheckAttribute(pchar, "questTemp.FMQG") && pchar.questTemp.FMQG == "continue")
            {
                link.l1 = "Ich bin Kapitän "+GetFullName(pchar)+". Ihr Mann hat mir gesagt, dass Sie mich sehen wollten. Ich bin ganz Ohr.";
                link.l1.go = "FMQG";
            }
			if (CheckAttribute(pchar, "questTemp.FMQG") && pchar.questTemp.FMQG == "sucsess")
            {
                link.l1 = "Wieder ich, Monsieur "+GetFullName(pchar)+". Ich habe Ihnen Bertrand Pinette gebracht. Er ist in meinem Laderaum.";
                link.l1.go = "FMQG_14";
            }
			if (CheckAttribute(pchar, "questTemp.FMQG") && pchar.questTemp.FMQG == "letter")
            {
                link.l1 = "Ich schon wieder, Monsieur "+GetFullName(pchar)+". Lassen Sie uns ein Gespräch führen.";
                link.l1.go = "FMQG_17";
            }
			if (CheckAttribute(pchar, "questTemp.FMQG") && pchar.questTemp.FMQG == "killers")
            {
                link.l1 = "Ich bin's wieder, Monsieur "+GetFullName(pchar)+". Lass uns reden.";
                link.l1.go = "FMQG_17";
            }
			if (CheckAttribute(pchar, "questTemp.FMQG.Letter"))
            {
                link.l1 = "Wieder ich, Monsieur "+GetFullName(pchar)+". Ich nehme an, du hast nicht erwartet, mich wieder zu sehen.";
                link.l1.go = "FMQG_23";
            }
		break;
		
		// Addon-2016 Jason ФМК-Гваделупа
		case "FMQG":
			dialog.text = "A-ah, Kapitän "+GetFullName(pchar)+"! Ich bin so froh, Sie zu sehen! Ich habe schon eine Weile auf Sie gewartet... Gut. Ich habe eine Frage zu stellen. Vor einiger Zeit hat Sie ein Mann namens Bertrand Pinette im Hafen angesprochen, um an Bord Ihres Schiffes zu gelangen. Ein wohlhabend aussehender Kerl in einer luxuriösen Perücke. Erinnert Sie das an etwas?";
			link.l1 = "Ja, das tut er. Er hat mich wirklich mit diesem genauen Zweck angesprochen.";
			link.l1.go = "FMQG_1";
		break;
		
		case "FMQG_1":
			DelLandQuestMark(npchar);
			Log_Info("You have received a heavy purse");
			PlaySound("interface\important_item.wav");
			GiveItem2Character(pchar, "purse3");
			dialog.text = "Hat er Sie und Ihr Schiff anheuern wollen? Kapitän, Sie würden mir einen großen Gefallen tun, indem Sie mir alle Details dieses Falls erzählen. Ich werde es Ihnen wert machen. Hier, nehmen Sie diesen Beutel voller Münzen. Er gehört Ihnen, jetzt erzählen Sie mir bitte von Bertrand Pinette.";
			link.l1 = "Sehr gut. Monsieur Pinette hat mein Schiff gemietet, um ihn und zwei seiner Freunde von Guadeloupe nach Spanisch-Maine zu bringen. Genauer gesagt, zur Mückenbucht von Portobello. Ich habe den Job gemacht, sie haben mein Schiff verlassen und sind direkt in den Dschungel gelaufen.";
			link.l1.go = "FMQG_2";
		break;
		
		case "FMQG_2":
			dialog.text = "Ich verstehe. Und hat Monsieur Pinette sein endgültiges Ziel erwähnt? Und was ist mit seinen Begleitern?";
			link.l1 = "Laut seinen eigenen Worten, waren sie auf dem Weg nach Panama. Seine Freunde waren ziemlich interessant: zwei Offiziere, ein Spanier und ein Franzose. Ich kann immer noch nicht verstehen, was sie vereint hat, aber ich wurde nicht bezahlt, um Fragen zu stellen.";
			link.l1.go = "FMQG_3";
		break;
		
		case "FMQG_3":
			dialog.text = "Ein spanischer Offizier? Und ein französischer Offizier? Oh! Ist das nicht etwas! Gut gemacht, Monsieur Pinette! Was für ein schlauer Hund! Selbst hier hat er einen Weg gefunden, Geld zu verdienen! Panama, sagten Sie?";
			link.l1 = "Ja, und ich habe Ihnen alles erzählt, was ich wusste. Darf ich gehen?";
			link.l1.go = "FMQG_4";
		break;
		
		case "FMQG_4":
			dialog.text = "Warte, Kapitän. Ich habe ein Geschäftsvorschlag für dich. Hast du etwas dagegen, einige Münzen zu verdienen? Aber zuerst, lass mich dir etwas über deine Passagiere erzählen.";
			link.l1 = "Nun, lass hören.";
			link.l1.go = "FMQG_5";
		break;
		
		case "FMQG_5":
			dialog.text = "Herr Bertrand Pinette tauchte vor zwei Jahren in unserer Kolonie auf und begann sofort, Geschäfte mit Kapitänen zu machen. Das Geschäft ist, nun, auch ein dunkles ... Sie lieferten ihm Waren, die hier sehr knapp waren, Wertsachen, Schmuggelware, manchmal sogar Sklaven ... Er nahm systematisch Kredite für seine illegalen Operationen in meinem Büro auf, zahlte aber immer mit all den Zinsen zurück\nVor seiner Abreise von der Insel mit Ihrer guten Hilfe hatte er einen großen Kredit aufgenommen, viel größer als gewöhnlich. Er ist... war ein vertrauenswürdiger Kunde mit einer tadellosen Kreditgeschichte, deshalb hatte ich ihm einen Kredit gewährt. Großer Fehler. Monsieur Pinette ist geflohen und offensichtlich wird er meine Münzen nicht zurückzahlen.";
			link.l1 = "Wie groß ist die Summe, wenn ich fragen darf?";
			link.l1.go = "FMQG_6";
		break;
		
		case "FMQG_6":
			dialog.text = "Es ist groß. Etwa hundertfünfzigtausend Pesos in Dublonen. Zehn Kisten, jede mit hundertfünfzig Dublonen. Und das ist noch nicht einmal der Zinsen zu erwähnen.";
			link.l1 = "Hm... Er hat Ihnen zwei Jahre lang bezahlt, Sie sich daran gewöhnt, einen erheblichen Kredit aufgenommen und dann ist er abtrünnig geworden. Schlau.";
			link.l1.go = "FMQG_7";
		break;
		
		case "FMQG_7":
			dialog.text = "Genau, Kapitän. Deshalb möchte ich Sie für einen Job anheuern: Finden Sie den Abschaum und bringen Sie ihn hierher. Ich, der Gouverneur und der Kommandant werden einen Weg finden, ihn seine Schulden begleichen zu lassen. Sie haben diesen Mann gesehen, er war Ihr Passagier, das bedeutet, Sie haben bessere Chancen, Monsieur Pinette zu finden als jeder andere. Sicher, ich werde auch professionelle Kopfgeldjäger für seinen bedauernswerten Arsch anheuern, aber ich habe das Gefühl, dass Ihre Hilfe effektiver sein wird.";
			link.l1 = "Was ist mit einer Belohnung?";
			link.l1.go = "FMQG_8";
		break;
		
		case "FMQG_8":
			dialog.text = "Für die Erledigung des Auftrags gebe ich Ihnen eine Truhe voller Dublonen, hundertfünfzig Münzen.";
			link.l1 = "Ich sage, das wäre eine ziemlich armselige Belohnung für das Aufspüren und Entführen einer lebenden Seele in der spanischen Stadt.";
			link.l1.go = "FMQG_9";
		break;
		
		case "FMQG_9":
			dialog.text = "Kapitän, ich nehme an, dass Monsieur Pinette Sie mit meinem Geld gut bezahlt hat, da Sie meinen Vorschlag so gering bewerten. Ich versichere Ihnen, dass es die Mühe wert ist. Natürlich haben Sie jedes Recht abzulehnen... aber ich habe Ihnen etwas zu erzählen und das wird Sie sicherlich Ihre Meinung ändern.";
			link.l1 = "Und was ist es?";
			link.l1.go = "FMQG_10";
		break;
		
		case "FMQG_10":
			dialog.text = "Ein paar Tage bevor Pinette aus Guadeloupe entkam, ist ein Gefangener aus dem Gefängnis von Basse-Terre geflohen. Sein Name ist Don Carlos de Milyar, ein spanischer Grandee und Offizier. Er hat es dank des Verrats eines französischen Offiziers geschafft, eines Leutnants der Marines... Verstehen Sie, was ich meine?";
			link.l1 = "Hm... Und wie betrifft mich das? Ich habe nur einen Personenverkehr durchgeführt, nichts weiter.";
			link.l1.go = "FMQG_11";
		break;
		
		case "FMQG_11":
			dialog.text = "Sicher, das waren Sie! Persönlich habe ich keinen Zweifel daran, dass Sie nichts mit der Organisation der Flucht von Don de Milyar zu tun haben. Aber so denken unser Gouverneur und unser Kommandant vielleicht nicht darüber. Eine Anklage wegen Komplizenschaft, wenn Sie Glück haben, und wenn Sie kein Glück haben... Ich möchte wirklich nicht weitermachen. Sehen Sie selbst, Sie haben einen flüchtigen spanischen Offizier an Bord genommen, wahrscheinlich in einer versteckten Bucht... habe ich recht, Kapitän?";
			link.l1 = "Ich verstehe. Du erpresst mich. Ich habe einen Fehler gemacht, hierher zu kommen...";
			link.l1.go = "FMQG_12";
		break;
		
		case "FMQG_12":
			dialog.text = "Was sagst du dazu, Kapitän?! Ich erpresse dich nicht! Alles, was ich verlange, ist mir für eine gute Belohnung zu helfen. Wärst du so freundlich, Monsieur Pinette zu finden und ihn nach Basse-Terre zu bringen? Ich werde auf deine Rückkehr warten. Ich glaube, dass zwei Monate genug sind, um nach Panama zu segeln und zurück.";
			link.l1 = "Sie lassen mir keine Wahl. Obwohl ich bezweifle, dass solch eine Geschäftsstrategie uns zu Freunden machen wird. Auf Wiedersehen, Monsieur.";
			link.l1.go = "FMQG_13";
		break;
		
		case "FMQG_13":
			DialogExit();
			LocatorReloadEnterDisable("Baster_town", "reload1_back", false);
			LocatorReloadEnterDisable("Baster_town", "reload2_back", false);
			LocatorReloadEnterDisable("Baster_town", "gate_back", false);//открыть выходы из города
			pchar.questTemp.FMQG = "headhunter_panama";
			ReOpenQuestHeader("FMQ_Guadeloupe");
			AddQuestRecord("FMQ_Guadeloupe", "7");
			if(bImCasual)
			{
				NewGameTip("Exploration mode: quest duration doubled");
				SetFunctionTimerCondition("FMQG_UsurerTimeOut", 0, 0, 122, false);
			}
			else SetFunctionTimerCondition("FMQG_UsurerTimeOut", 0, 0, 61, false);
			AddMapQuestMarkCity("panama", false);
			AddLandQuestMark(characterFromId("Panama_tavernkeeper"), "questmarkmain");
			
			// Sinistra - Старт квеста "Мерзкий Божок"
			PChar.quest.ChickenGod_StartLoc.win_condition.l1 = "ExitFromLocation";
			PChar.quest.ChickenGod_StartLoc.win_condition.l1.location = PChar.location;
			PChar.quest.ChickenGod_StartLoc.function = "ChickenGod_BrothelCheck";
		break;
		
		case "FMQG_14":
			DelMapQuestMarkCity("baster");
			DelLandQuestMark(npchar);
			dialog.text = "Ausgezeichnete Nachrichten, Kapitän! Ich werde meine Männer sofort losschicken, um diesen Bastard von Ihrem Schiff abzuholen. Dieses Vögelchen wird mir diesmal nicht entkommen... Sie haben Ihre Belohnung verdient, nehmen Sie diese Truhe. Bitte, seien Sie nicht böse auf mich, hier ist ein Amulett für Sie. Es ist ein Geschenk.";
			link.l1 = "Dankbarkeit. Ich nehme an, dass auch dein Schweigen Teil meiner Belohnung ist?";
			link.l1.go = "FMQG_15";
		break;
		
		case "FMQG_15":
			Log_Info("You have received a chest full of doubloons");
			Log_Info("You have received a 'Fisherman' amulet");
			PlaySound("interface\important_item.wav");
			GiveItem2Character(pchar, "chest");
			GiveItem2Character(pchar, "obereg_7");
			dialog.text = "Schweigen? Über was? Ich würde mich freuen, Sie unter meinen Kunden zu sehen. Sie wissen, was sie über Schweigen und Gold sagen?";
			link.l1 = "Es ist manchmal viel mehr wert als Gold, Monsieur. Lektion gelernt. Auf Wiedersehen!";
			link.l1.go = "FMQG_16";
		break;
		
		case "FMQG_16":
			DialogExit();
			pchar.quest.FMQG_UsurerTimeOut.over = "yes";
			ref sld = characterFromId("FMQG_pass_1");
			RemovePassenger(pchar, sld);
			sld.lifeday = 0;
			pchar.questTemp.FMQG = "end";
			FMQ_Count();
			AddQuestRecord("FMQ_Guadeloupe", "23");
			CloseQuestHeader("FMQ_Guadeloupe");
			ChangeCharacterNationReputation(pchar, FRANCE, 5);
			ChangeCharacterComplexReputation(pchar, "nobility", 5);
			ChangeCharacterComplexReputation(pchar, "authority", 3);
			AddCharacterExpToSkill(pchar, "Leadership", 400);
			AddCharacterExpToSkill(pchar, "Sailing", 200);
		break;
		
		case "FMQG_17":
			DelLandQuestMark(npchar);
			DelMapQuestMarkCity("baster");
			dialog.text = "Ich höre zu. Ich nehme an, Bertrand Pinette ist auf Ihrem Schiff?";
			link.l1 = "Nein. Aber ich habe etwas viel Besseres für dich. Lies das.";
			link.l1.go = "FMQG_18";
		break;
		
		case "FMQG_18":
			RemoveItems(pchar, "letter_baker", 1);
			dialog.text = "Was ist das?";
			link.l1 = "Weiterlesen, Herr. Wir werden später weitermachen.";
			link.l1.go = "FMQG_19";
		break;
		
		case "FMQG_19":
			LAi_Fade("", "");
			dialog.text = "(liest) Ähm ... Was ist das für ein Unsinn von einem fiebrigen Patienten?";
			link.l1 = "Sind Sie ernsthaft? Gut, ich werde diesen 'Unsinn' zum Gouverneur bringen. Ich glaube, er wird großes Interesse daran haben, die Wahrheit über das Verschwinden der 'Courage' und ihrer Lieferung von Diamanten zu erfahren... Warum sind Sie so blass geworden?";
			if (CheckAttribute(pchar, "questTemp.FMQG.Letter")) link.l1.go = "FMQG_24";
			else link.l1.go = "FMQG_20";
		break;
		
		case "FMQG_20":
			dialog.text = "Also, du hast Pinette doch gefunden...";
			link.l1 = "Ja. Also schlage ich Ihnen einen Handel vor. Vergessen Sie Carlos de Milyar, Jean Deno und andere ehrenwerte Herren, tun Sie das und ich werde diesen Brief vergessen.";
			link.l1.go = "FMQG_21";
		break;
		
		case "FMQG_21":
			dialog.text = "Sehr gut, Kapitän... Ich stimme Ihren Bedingungen zu.";
			link.l1 = "Schön. Ich hoffe, du bist nicht böse auf mich, wir sind jetzt fertig, denke ich. Lebewohl.";
			link.l1.go = "FMQG_22";
		break;
		
		case "FMQG_22":
			DialogExit();
			pchar.quest.FMQG_UsurerTimeOut.over = "yes";
			pchar.questTemp.FMQG = "cave";
			bQuestDisableMapEnter = true;//закрыть карту
			pchar.GenQuest.MapClosedNoBattle = true;
			pchar.quest.FMQG_cave.win_condition.l1 = "location";
			pchar.quest.FMQG_cave.win_condition.l1.location = "Guadeloupe_Cave";
			pchar.quest.FMQG_cave.function = "FMQG_InCave";
			// заполним сундук
			pchar.GenQuestBox.Guadeloupe_Cave = true;
			pchar.GenQuestBox.Guadeloupe_Cave.box3.items.purse1 = 5;
			pchar.GenQuestBox.Guadeloupe_Cave.box3.items.purse2 = 2;
			pchar.GenQuestBox.Guadeloupe_Cave.box3.items.purse3 = 1;
			SetFunctionTimerCondition("FMQG_ClearBox", 0, 0, 3, false);
			if (CheckAttribute(pchar, "questTemp.FMQG.Letter"))
			{
				SetFunctionTimerCondition("FMQG_RemoveHunterScore", 0, 0, 1, false);
				AddQuestRecord("FMQ_Guadeloupe", "29");
				DeleteAttribute(pchar, "questTemp.FMQG.Letter");
			}
			else AddQuestRecord("FMQ_Guadeloupe", "25");
		break;
		
		case "FMQG_23":
			dialog.text = "Ha... Du hast recht, Kapitän.";
			link.l1 = "Ich habe etwas für dich. Nimm das und lies.";
			link.l1.go = "FMQG_18";
		break;
		
		case "FMQG_24":
			dialog.text = "Also, du hast Pinette doch gefunden...";
			link.l1 = "Ja. Also schlage ich Ihnen einen Deal vor. Stellen Sie meinen guten Namen in den französischen Kolonien wieder her und ich werde diesen Brief vergessen.";
			link.l1.go = "FMQG_25";
		break;
		
		case "FMQG_25":
			dialog.text = "Aber...";
			link.l1 = "Ich gebe einen Dreck darauf, wie Sie es tun werden. Wenn die Jagd nach meinem Kopf morgen nicht endet, wird der Gouverneur von allem erfahren.";
			link.l1.go = "FMQG_21";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
