// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Welche Fragen haben Sie?","Wie kann ich Ihnen helfen, "+GetAddress_Form(NPChar)+"?"),"Du hast versucht, mir vor kurzem eine Frage zu stellen, "+GetAddress_Form(NPChar)+"...","Über den ganzen Tag hinweg ist das das dritte Mal, dass du von irgendeiner Frage sprichst...","Noch mehr Fragen, nehme ich an?","Block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Ich habe es mir anders überlegt...","Ich habe im Moment nichts zu besprechen."),"Hmm, wo ist mein Gedächtnis hin...","Ja, es ist wirklich das dritte Mal...","Nein, welche Fragen?...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			if (pchar.questTemp.Slavetrader == "FindRatJamaica")
            {
                link.l1 = "Hat ein Mann namens Francois Gontier in Ihrer Stadt Halt gemacht? Ich brauche ihn wirklich.";
                link.l1.go = "Jamaica_ratF_1";
            }
			// Addon 2016-1 Jason пиратская линейка
			if (CheckAttribute(pchar, "questTemp.Mtraxx") && pchar.questTemp.Mtraxx == "silk_4")
            {
                link.l1 = "Hör zu, Kumpel, es gibt ein Schiff aus Port Royal, das Seide für seine Werft kauft... sehr spezielle Seide, du hast sicherlich davon gehört. Man sagt, ein Verkäufer solcher Seide wohnt irgendwo in dieser Siedlung. Hast du irgendwelche Hinweise, wie man ihn finden kann? Ich habe ein Geschäftsangebot für ihn.";
                link.l1.go = "mtraxx";
			}
			if (CheckAttribute(pchar, "questTemp.Mtraxx") && pchar.questTemp.Mtraxx == "silk_5" && (PCharDublonsTotal() >= 50))
            {
                link.l1 = "Ich habe fünfzig Dublonen bei mir. Nimm sie und fang an zu reden.";
                link.l1.go = "mtraxx_4_1";
			}
		break;

		case "Jamaica_ratF_1":
			dialog.text = "Er hat. Er hatte ein paar Tage lang ein Zimmer gemietet. Nicht der angenehmste Kerl, sag ich dir. Außerdem war er obsessiv paranoid, gesucht zu werden. Er hatte immer Angst und schaute sich um. Bist du der Mann, vor dem er so Angst hatte?";
			link.l1 = "Nein, ich bin es nicht. Sie wissen, Freibeuter haben viele Feinde. Also, wo kann ich ihn finden? Er und ich haben beschlossen, eine Vereinbarung zu treffen, aber es sieht so aus, als hätte die Erde ihn verschluckt.";
			link.l1.go = "Jamaica_ratF_2";
		break;
		
		case "Jamaica_ratF_2":
			dialog.text = "Er ist mit seinem eigenen Schiff aufs Meer hinausgefahren. Ich weiß nicht wohin. Er hat mich darüber nicht informiert.";
			link.l1 = "Ach, was für ein Pech! Wo soll ich ihn jetzt suchen?";
			link.l1.go = "Jamaica_ratF_3";
		break;
		
		case "Jamaica_ratF_3":
			dialog.text = "Ich weiß es nicht, Kumpel. Ich würde es dir sagen, wenn ich es wüsste.";
			link.l1 = "In Ordnung, ich verstehe. Ich werde einige andere Leute fragen...";
			link.l1.go = "exit";
			AddQuestRecord("Slavetrader", "21_4");
			pchar.questTemp.Slavetrader = "FindRatJamaica_H";
		break;
		
		// Addon 2016-1 Jason пиратская линейка
		case "mtraxx":
            dialog.text = "Hmm, wenn du unseren Händler verdächtigst, denjenigen, der das Geschäft führt, kann ich dir sagen, dass er es nicht ist, er handelt nicht mit Seidensegeltuch. Schmuggler kommen auch nicht hierher, sie sind nicht nötig, wenn es kein Zollhaus gibt. Und außerdem handelt hier sowieso niemand anderes außer unserem Händler. Schau dich um, wir sind nicht diese Art von Leuten, ha-ha!";
			link.l1 = "Aber jemand liefert die Seide nach Port Royal - das ist unbestreitbar. Haben Sie eine Ahnung, wer der Lieferant sein könnte?";
			link.l1.go = "mtraxx_1";
		break;
		
		case "mtraxx_1":
            dialog.text = "Schmuggler aus Port Royal, vielleicht? Oder abtrünnige Piraten? Müssen ihre Beute in irgendeiner versteckten Bucht entladen... Ha! Ich habe eine Idee, Kumpel. Es gibt einen Einheimischen, der alles weiß, was in diesen Gewässern vor sich geht. Wenn er keine Vermutungen hat, dann gibt es keine Seidenhändler.";
			link.l1 = "Hervorragend! Wie heißt der Kerl?";
			link.l1.go = "mtraxx_2";
		break;
		
		case "mtraxx_2":
            dialog.text = "Hm... Ich versuche mich an seinen Namen zu erinnern, aber aus irgendeinem Grund fällt er mir einfach nicht ein...";
			link.l1 = "Wie wär's mit ein paar Münzen, um deine Erinnerung zu unterstützen?";
			link.l1.go = "mtraxx_3";
		break;
		
		case "mtraxx_3":
            dialog.text = "Ich vermute, das könnte helfen... Fünfzig Gold-Dublonen werden diesen alten Kopf sicherlich erhellen.";
			if (PCharDublonsTotal() >= 50) // Rebbebion, учёт количества дублонов из рундука
			{
				link.l1 = "Ich verstehe. Hier, nimm die Münzen.";
				link.l1.go = "mtraxx_4_1";
			}
			else
			{
				link.l1 = "Ich verstehe. Ich komme wieder...";
				link.l1.go = "mtraxx_4_2";
			}
		break;
		
		case "mtraxx_4_1":
			RemoveDublonsFromPCharTotal(50);
			PlaySound("interface\important_item.wav");
            dialog.text = "Husky Billy ist der Mann, den du brauchst. Er lebt schon ewig auf Jamaika, kennt jeden Hund auf den Straßen. War früher ein Pirat und ein Dorn im Auge der Briten, bis er vor etwa drei Jahren verwundet wurde. Jetzt fischt er hauptsächlich, jagt Haie und sammelt Bernstein in den Buchten von Jamaika. Er verlässt sein altes Langboot nur, um mehr Rum und Kracker zu kaufen\nDu solltest ihn in den Gewässern um Jamaika suchen. Man sagt, er segelt auf der Nordseite, ganz im Osten. Aber ein Langboot zu verfolgen, ist eine Narrenarbeit, du solltest dich besser in der Südwestecke verstecken, man sagt, er wurde etwa einmal pro Woche in der Nähe von Cape Negril gesehen. Sein Kutter heißt 'Der Fliegenfisch'.";
			link.l1 = "Danke, Kumpel. Du hast dein Gold verdient.";
			link.l1.go = "mtraxx_5";
		break;
		
		case "mtraxx_5":
            dialog.text = "Viel Glück, Kumpel! Ich hoffe, du findest, was du suchst!";
			link.l1 = "...";
			link.l1.go = "mtraxx_6";
		break;
		
		case "mtraxx_4_2":
            DialogExit();
			AddQuestRecord("Roger_2", "6");
			pchar.questTemp.Mtraxx = "silk_5";
		break;
		
		case "mtraxx_6":
            DialogExit();
			AddQuestRecord("Roger_2", "7");
			pchar.questTemp.Mtraxx = "silk_6";
			/*pchar.quest.mtr_negril.win_condition.l1 = "Timer";
			pchar.quest.mtr_negril.win_condition.l1.date.hour  = 12+rand(12);
			pchar.quest.mtr_negril.win_condition.l1.date.day   = GetAddingDataDay(0, 0, 2+rand(3));
			pchar.quest.mtr_negril.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 2+rand(3));
			pchar.quest.mtr_negril.win_condition.l1.date.year  = GetAddingDataYear(0, 0, 2+rand(3));*/
			PChar.quest.mtr_negril.win_condition.l1 = "ExitFromLocation";
			PChar.quest.mtr_negril.win_condition.l1.location = PChar.location;
			pchar.quest.mtr_negril.function = "Mtraxx_CreateBilly";
			SetFunctionTimerCondition("Mtraxx_BillySeaTimeOver", 0, 0, 7, false);
			if(bImCasual) NewGameTip("Exploration mode: timer is not disabled. Meet the deadline!");
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
