// диалоги Уракана, Канека и прочих индейцев ица
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
	int i, iTemp;
	string sTemp;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			dialog.text = "Gibt es etwas, das Sie brauchen?";
			link.l1 = "Nein, nichts.";
			link.l1.go = "exit";			
			NextDiag.TempNode = "First time";
		break;
		
		// ица-горожане
		case "itza_ctz":
			dialog.text = LinkRandPhrase("Ein weiteres bleiches Gesicht... Großer Priester freut sich, dir das Herz herauszuschneiden...","Blasses Gesicht weiß, wie man nach Tayasal kommt, aber niemand verlässt die Stadt!","Ich bin überrascht, bleichgesicht: du bist noch nicht im Geisterland... Geh, solange du kannst, bald wirst du deine Vorfahren sehen.");
			link.l1 = LinkRandPhrase("Nun, nun. Wir werden sehen...","Versuch nicht, mir Angst zu machen, rothäutiger Krieger. Ich habe Schlimmeres gesehen als das.","Geh, geh. Versuch, die Kinder zu erschrecken.");
			link.l1.go = "exit";
			NextDiag.TempNode = "itza_ctz";
		break;
		
		case "itza_ctz_1":
			dialog.text = LinkRandPhrase("Segne mich für den Kampf mit dem Feind, großer Cavil!","Großer Cavil und großer Kukulcan ehren uns mit ihrer Anwesenheit. Selbst im alten Maya ist das nicht passiert!","Wir überliefern die Legende von der großen Schlacht zwischen Kukulcan und Cavil an unsere Kinder!");
			link.l1 = "...";
			link.l1.go = "exit";
			NextDiag.TempNode = "itza_ctz_1";
		break;
		
		// Уракан - вождь ица
		case "urakan":
			dialog.text = "Du bist großartiger Krieger, bleiches Gesicht. Wir bringen dein Blut zu den Göttern. Du stirbst mit Würde.";
			link.l1 = "Ruhig Brauner, rothäutiger Krieger. Ich werde nicht zulassen, dass dein Kanek mich als Opfer für Kukulcan oder sonst wen bringt. Deine Krieger konnten mich nicht fangen. Jeder einzelne von ihnen ist im Kampf gefallen.";
			link.l1.go = "urakan_1";
		break;
		
		case "urakan_1":
			dialog.text = "Ja, du gnädiger Krieger, bleiches Gesicht. Aber du widerstehst nicht hunderten Tayasal Itza Kriegern. Aber, du sagst interessantes Wort. Wie weißt du von großem Kanek und Kukulcan?";
			link.l1 = "Nun, lass mich raten... Da du nicht Kanek bist, muss dein Name Urakan sein und du bist der Sohn des Priesters Kanek?";
			link.l1.go = "urakan_2";
		break;
		
		case "urakan_2":
			dialog.text = "Deine Lippen sprechen die Wahrheit, bleiches Gesicht. Ich bin Urakan und ich bin überrascht.";
			link.l1 = "Du wirst noch mehr überrascht sein, wenn du dir das ansiehst... Schau.";
			link.l1.go = "urakan_3";
		break;
		
		case "urakan_3":
			dialog.text = "Oh, Götter! Wenn das bleiche Gesicht eine Maske hat, bedeutet das, die Zeit ist gekommen... Du bist derjenige, von dem Kukulcan erzählt hat. Er befahl, dich zu ihm zu bringen, wenn du in Tayasal ankommst. Er weiß, dass du kommst.";
			link.l1 = "Kukulcan?! Er ist hier in Tayasal?";
			link.l1.go = "urakan_4";
		break;
		
		case "urakan_4":
			dialog.text = "Ja, weißer Krieger. Quetzalcoatl kommt nach Tayasal. Bald geht er, um den Ahnen Licht zu bringen, der großen Stadt der Maya.";
			link.l1 = "Verdammt nochmal! Also, er ist schon hier...(leise) Urakan, ich weiß alles. Ich weiß, dass du es warst, der Ksatl Cha mit dem Hüter der Wahrheit geschickt hat, um nach Ksocheatem und der Maske von Kukulcan zu suchen...";
			link.l1.go = "urakan_5";
		break;
		
		case "urakan_5":
			dialog.text = "";
			link.l1 = "Ich sehe Überraschung in deinen Augen, aber auch Zweifel, großer Häuptling Urakan. Du bist nicht glücklich mit Kukulcan, habe ich recht?";
			link.l1.go = "urakan_6";
		break;
		
		case "urakan_6":
			dialog.text = "Jeder Itza-Krieger freut sich, dass der große Kukulcan kommt, weißer Krieger. Du musst vor Kukulcan stehen. Er wartet viele Nächte auf dich. Er ist ein großer Prophet. Er weiß alles im Voraus. Geh zur Fliegenden Schlange, du hast keinen anderen Weg. Wir erlauben dir nicht, Tayasal zu verlassen.";
			link.l1 = "Verstehst du nicht, dass sobald Kukulcan durch die Tore der Zeit geht, werdet ihr alle, sowie du persönlich, aufhören zu existieren? Und das Beste daran ist, dass du in einem anderen Bild, in einem anderen Körper wiedergeboren wirst... Vielleicht als einfacher Krieger, oder vielleicht sogar als Krüppel oder Bettler...";
			link.l1.go = "urakan_7";
		break;
		
		case "urakan_7":
			dialog.text = "Geh, bleichhäutiger Krieger. Du findest Kukulcan im großen Tempel der Itza-Krieger. Geh geradeaus auf die Brücke, bis du die große Pyramide siehst. Geh in die untere Tür des Tempels und nähere dich dem Heiligtum.";
			link.l1 = "Also gut. Ich werde zu Kukulcan gehen, denn ich sehe, dass wir diesem Aufeinandertreffen nicht entkommen können. Aber ich habe dich gewarnt.";
			link.l1.go = "urakan_8";
		break;
		
		case "urakan_8":
			DialogExit();
			LAi_SetPlayerType(pchar);
			LAi_SetWarriorType(npchar);
			LAi_warrior_SetStay(npchar, true);
			LAi_warrior_DialogEnable(npchar, true);
			NextDiag.CurrentNode = "urakan_9";
			DeleteAttribute(pchar, "GenQuest.Notsearchbody");
			AddQuestRecord("Tieyasal", "25");
			pchar.quest.Tieyasal_Templegreat.win_condition.l1 = "location";
			pchar.quest.Tieyasal_Templegreat.win_condition.l1.location = "Temple_great";
			pchar.quest.Tieyasal_Templegreat.function = "Tieyasal_InGreatTemple";
			// экспа за бой
			AddComplexSelfExpToScill(300, 300, 300, 300);
			AddCharacterExpToSkill(pchar, "Leadership", 500);
			AddCharacterExpToSkill(pchar, "Fortune", 300);
		break;
		
		case "urakan_9":
			dialog.text = "Geh, weißer Krieger. Kukulcan erwartet dich.";
			link.l1 = "Ich bin auf dem Weg...";
			link.l1.go = "exit";
			NextDiag.TempNode = "urakan_9";
		break;
		
		case "urakan_10":
			PlaySound("Voice\English\Complete.wav");
			dialog.text = "Es ist wahr geworden! Als ich sehe, wie du gegen Kukulcan kämpfst, weiß ich, dass du Cavil selbst bist. Du kommst nach Tayasal, um das Itza-Volk vor dem Tod durch den Vater und Kukulcan zu retten. Mein Vater, der große Priester Kanek, verurteilt das Itza-Volk im Ruhm der längst verstorbenen Maya-Vorfahren.\nIch bin der Kriegshäuptling Urakan, der das Itza-Volk viele Jahre lang beschützt hat. Kein bleiches Gesicht verlässt Tayasal lebend. Ich und die Krieger sorgen dafür, dass das Itza-Volk geschützt bleibt und noch viele, viele Jahre lebt. Ich will nicht mein ganzes Volk opfern.";
			link.l1 = "Ich wusste das, Urakan. Und ich bat dich, mir auf der Brücke zu helfen.";
			link.l1.go = "urakan_11";
		break;
		
		case "urakan_11":
			dialog.text = "Nichts verbirgt sich vor den Augen des großen Cavil. Verzeih Urakan, dass er nicht versteht, wer du bist.";
			link.l1 = "Mach dir keine Sorgen, Häuptling. Ich habe die sterbliche Verkörperung von Kukulcan besiegt, aber wir haben eine zweite wichtige Aufgabe vor uns - die Tore zur Vergangenheit zu schließen. Dieses unnatürliche Loch in der Zeit muss beseitigt werden. Wirst du mir helfen?";
			link.l1.go = "urakan_12";
		break;
		
		case "urakan_12":
			dialog.text = "Was kann Urakan dir helfen, oh Cavil?";
			link.l1 = "Du hast Ksatl Cha mit dem Hüter der Wahrheit losgeschickt, um nach Ksocheatem und der Maske von Kukulcan zu suchen. Also weißt du, dass sie verwendet werden kann, um die Tore der Zeit zu schließen. Hat dein Vater dir davon erzählt?";
			link.l1.go = "urakan_13";
		break;
		
		case "urakan_13":
			dialog.text = "Vater nicht sprechen. Ich studiere Schriften im Tempel des Wissens und der Weisheit. Aber vieles ist für Urakan unklar. Vielleicht kann Cavil verstehen?";
			link.l1 = "Was genau hast du herausgefunden?";
			link.l1.go = "urakan_14";
		break;
		
		case "urakan_14":
			dialog.text = "Ich lerne auswendig. Die Schrift verkündet: 'Wenn die Sonne gegen den Regen aufgeht und das Feuer zwischen ihnen in Dreieck steht, schlage Tohils Bein gegen Bein und verbrenne die Maske von Kukulcan auf dem Altar der Zeit. Und versiegle Itzamnas Tore der Zeit bis zum Ende aller Tage.'";
			link.l1 = "Was.";
			link.l1.go = "urakan_15";
		break;
		
		case "urakan_15":
			dialog.text = "Ja.";
			link.l1 = "Jesus... Zeige mir die Tore.";
			link.l1.go = "urakan_16";
		break;
		
		case "urakan_16":
			dialog.text = "Sie befinden sich im Tempel Kukulcan. Aber die Tür ist dort verschlossen. Nur mein Vater kann sie schließen und öffnen. Wenn er die Tür zum Tempel Kukulcan öffnet, sagt er: 'Die Sonne kommt und geht, das Wasser fällt und sinkt, das Feuer entzündet sich und erlischt, Krieg und Frieden wechseln sich ab, aber nur der Himmel ist für immer. Über der Zeit ist nur der Himmel.'";
			link.l1 = "Interessant... Lassen wir das im Gedächtnis und sehen, was wir tun können...";
			link.l1.go = "urakan_17";
		break;
		
		case "urakan_17":
			dialog.text = "Ich bleibe hier, unten, in der Nähe des Altars der Zeit. Sieh jede Pyramide und jedes Gebäude in Taysal von innen. Finde Schlüssel. Ich bleibe hier.";
			link.l1 = "Wenn ich wichtige Fragen habe, werde ich definitiv zu Ihnen kommen.";
			link.l1.go = "urakan_18";
		break;
		
		case "urakan_18":
			DialogExit();
			NextDiag.CurrentNode = "urakan_adv";
			DeleteAttribute(pchar, "GenQuest.Notsearchbody");
			pchar.quest.Tieyasal_UrakanTemple.win_condition.l1 = "location";
			pchar.quest.Tieyasal_UrakanTemple.win_condition.l1.location = "Tenochtitlan";
			pchar.quest.Tieyasal_UrakanTemple.function = "Tieyasal_UrakanInTemple";
			AddQuestRecord("Tieyasal", "26");
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocator(npchar, "quest", "urakan", "", -1);
			// экспа за бой
			AddComplexSelfExpToScill(1000, 1000, 1000, 1000);
			AddCharacterExpToSkill(pchar, "Leadership", 3000);
			AddCharacterExpToSkill(pchar, "Fortune", 1500);
		break;
		
		case "urakan_adv":
			dialog.text = "Kann Urakan dem großen Cavil mit Rat oder Tat helfen?";
			if (Tieyasal_CheckTablets() && !CheckAttribute(npchar, "quest.tablets"))
			{
				link.l1 = "Schau dir diese Tafel an, die ich gefunden habe. Nach dem Ort, an dem ich sie gefunden habe, muss sie etwas mit deinem Vater zu tun gehabt haben und es ist klar, dass es kein gewöhnlicher Gegenstand ist...";
				link.l1.go = "tablets";
			}
			if (CheckAttribute(npchar, "quest.treasureentrance"))
			{
				link.l1 = "Ich habe einen weiteren Eingang oben auf dem Großen Tempel gefunden, aber er ist versiegelt. Wie komme ich da rein? Vielleicht ist das, wonach ich suche, dort drinnen.";
				link.l1.go = "treasure";
			}
			link.l9 = "Nichts gerade jetzt, Urakan. Ich werde alleine zurechtkommen...";
			link.l9.go = "exit";
			NextDiag.TempNode = "urakan_adv";
		break;
		
		case "tablets":
			dialog.text = "Gottes Steinplatte. Vater hat mehrere verschiedene Stücke und sie sind ihm sehr wertvoll. Die alten Tayasal-Bauer verwenden die Platte, um verborgene Mechanismen zu aktivieren, Türen zu öffnen und zu schließen, sogar magische Rituale zu machen.\nSie funktionieren, wenn sie an der richtigen Stelle platziert werden - das macht mein Vater. Aber ich bin ein Krieger wie du, weiß nicht, wie man sie richtig benutzt. Vielleicht weiß Cavil?";
			link.l1 = "Wir werden dem definitiv auf den Grund gehen...";
			link.l1.go = "exit";
			npchar.quest.tablets = "true";
			NextDiag.TempNode = "urakan_adv";
			AddQuestRecord("Tieyasal", "31");
		break;
		
		case "treasure":
			dialog.text = "Dies ist die Tür zu den Schätzen von Tayasal. Dort liegen die Reichtümer der Itza-Indianer. Nur mein Vater öffnet und schließt die Tür von innen. Niemand wagt es, ohne ihn zu den Schätzen zu gelangen. Nicht einmal ich.";
			link.l1 = "Wie hat dein Vater den Eingang geöffnet?";
			link.l1.go = "treasure_1";
		break;
		
		case "treasure_1":
			dialog.text = "Mein Vater sagt: 'Jeder Reichtum hat zwei Seiten. Nur wer diese beiden Seiten kennt, betritt die Schätze von Tayasal.' Was das bedeutet - ich weiß es nicht. Vielleicht kann Cavil raten?";
			link.l1 = "Wir werden auch das hier herausfinden...";
			link.l1.go = "exit";
			NextDiag.TempNode = "urakan_adv";
			DeleteAttribute(npchar, "quest.treasureentrance");
			AddQuestRecord("Tieyasal", "32");
		break;
		
		case "urakan_19":
			PlaySound("Voice\English\Complete.wav");
			dialog.text = "Du machst es, oh großer Cavil! Die Menschen von Itza sind jetzt sicher. Ich, Urakan, Sohn von Kanek, versichere dir, dass ich die Ehre, die du mir gibst, nicht beschäme und ich Tayasal vor jeder Invasion von unehrenhaften bleichen Gesichtern in deinem Namen schütze.";
			link.l1 = "Ich kann es gut glauben, Chef. Nun, wir können jetzt feiern: wir haben den verräterischen Plänen von Kukulcan einen Riegel vorgeschoben. Er wird niemals wieder eine Zeitrevolution materialisieren können.";
			link.l1.go = "urakan_20";
		break;
		
		case "urakan_20":
			PlaySound("interface\abordage_wining.wav");
			dialog.text = "Ruhm dem großen Cavil! Mir und meiner Generation widerfährt große Ehre, in Tayasal zwei Götter zu sehen. Wir schreiben diese Geschichte für unsere Kinder. Sie wissen über die Schlacht der Götter in Tayasal! Ruhm Cavil! Ruhm!";
			link.l1 = "Ich brauche einen Drink...";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("Tieyasal_Win_IndianBead");
		break;
		
		// Канек - жрец ица
		case "kanek":
			dialog.text = "Du stehst vor der Geflügelten Schlange, bleiches Gesicht. Der Geist des mächtigen Kukulcan in menschlichem Fleisch. Du hast Glück, sein Bruder durch den Vater seiner Verkörperung zu sein, so wie ich das Glück habe, der Vater seiner Mutter zu sein, der Frau, die ihn geboren hat. Es ist eine große Ehre. Vielleicht ist das der Grund, warum du ein starker Krieger geworden bist und noch am Leben bist.\nAber deine Zeit wird ablaufen, bleiches Gesicht. Wir werden eine neue Zeit beginnen, die Zeit des großen Maya. Wir werden unsere eigene Macht etablieren und niemals zulassen, dass die bleichen Gesichter in unsere Welt kommen. Bald. Ich, Kanek der Priester, werde das Ritual beginnen!";
			link.l1 = "Wunderbar...";
			link.l1.go = "kanek_1";
		break;
		
		case "kanek_1":
			DialogExit();
			sld = characterFromId("Mishelle");
			sld.dialog.currentnode = "kukulkan_3";
			LAi_SetActorType(sld);
			LAi_ActorDialogDelay(sld, pchar, "", 0.7);
		break;
		
		case "kanek_2":
			dialog.text = "Urakan, du hast gehört, was unser Herr gesagt hat. Unterwerfe dich jetzt!";
			link.l1 = "Wenn die Großen miteinander kämpfen, ist es besser für uns einfache Sterbliche, beiseite zu stehen und von weitem zuzusehen, Vater...";
			link.l1.go = "kanek_3";
		break;
		
		case "kanek_3":
			dialog.text = "Was?! Komm zu Verstand, Sohn!";
			link.l1 = "Dieser Mann ist Kukulcans Bruder und ein großer Krieger. Ich sehe die Verkörperung von Cavil selbst in ihm! Niemand außer ihm widersteht einem Gott SO. Kein Kinderspiel im Duell der Götter, Vater! Und wenn du Kukulcan Opfergaben bringst, werden meine Krieger ihr Blut für Cavil geben!";
			link.l1.go = "kanek_4";
		break;
		
		case "kanek_4":
			dialog.text = "Bist du bei Verstand, Urakan?";
			link.l1 = "Viele Jahre lang habe ich, benannt nach Hurakan, erfolgreich unsere Länder im Namen Cavils vor der Invasion der Ausländer geschützt. Hunderte von ihnen fielen unter unseren Keulen und niemand verließ Tayasal. Aber niemals in meinem Leben habe ich einen Krieger so stark und flink gesehen wie dieses bleiche Gesicht. Wenn er in der Lage ist, Kukulcan zu besiegen, dann ist er die Verkörperung des Geistes von Cavil selbst!";
			link.l1.go = "kanek_5";
		break;
		
		case "kanek_5":
			DialogExit();
			sld = characterFromId("Mishelle");
			sld.dialog.currentnode = "kukulkan_win_5";
			LAi_SetActorType(sld);
			LAi_ActorDialogNow(sld, pchar, "", -1);
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}
