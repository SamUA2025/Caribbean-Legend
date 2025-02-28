// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Welche Fragen haben Sie?","Wie kann ich Ihnen helfen?"),"Du hast versucht, mir vor einiger Zeit eine Frage zu stellen...","Ich habe noch nie Leute mit so viel Neugier in meiner Werft oder sonst wo in dieser Stadt getroffen.","Was soll das ganze Fragen? Meine Arbeit ist es, Schiffe zu bauen. Kümmern wir uns darum.","Block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Ich habe es mir anders überlegt...","Ich habe im Moment nichts zu besprechen."),"Umph, wo ist mein Gedächtnis hin...","Hm, nun...","Mach weiter...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			// Addon-2016 Jason ”ЊЉ-Њартиника
			if (CheckAttribute(pchar, "questTemp.FMQM") && pchar.questTemp.FMQM == "begin")
            {
                link.l1 = "Ihr Mann hat mir gesagt, dass ihr mich sehen wollt. Ich bin ganz Ohr.";
                link.l1.go = "FMQM";
            }
			if (CheckAttribute(pchar, "questTemp.FMQM") && pchar.questTemp.FMQM == "oil" && GetSquadronGoods(pchar, GOOD_OIL) >= 50)
            {
                link.l1 = "Ich habe die Arbeit erledigt. "+FindRussianQtyString(GetSquadronGoods(pchar,GOOD_OIL))+" Fässer mit Harz befinden sich in meinen Laderäumen.";
                link.l1.go = "FMQM_9";
            }
		break;
		
		// Addon-2016 Jason ”ЊЉ-Њартиника
		case "FMQM":
			pchar.quest.FMQM_Denial.over = "yes";
			dialog.text = "Ja-ja, Kapitän "+GetFullName(pchar)+". Ich sah Ihr Schiff in unseren Hafen einlaufen und schickte sofort meinen Arbeiter zu Ihnen. Direkt zum Geschäft dann: Sie sind ein Neuling, aber man sagt, dass Sie bereits ein erfahrener Seemann geworden sind und das Glück auf Ihrer Seite ist. Deshalb habe ich ein Geschäftsangebot für Sie.";
			link.l1 = "Interessant! Mach weiter, erzähl mir.";
			link.l1.go = "FMQM_1";
			DelLandQuestMark(npchar);
		break;
		
		case "FMQM_1":
			dialog.text = "Haben Sie schon einmal von dem speziellen Harz gehört, das die Spanier auf der Insel Trinidad produzieren? Es ist eine seltene Ressource von strategischem Wert, die zur Verstärkung des Schiffsrumpfes verwendet wird. Jedes Fass kostet einen ordentlichen Betrag, da die Spanier das gesamte Harz für die Bedürfnisse ihrer Marine abzweigen. Jede Kolonialbehörde hat den Handel mit dieser Ware unter Kontrolle, um es einfach auszudrücken, es ist reiner Schmuggel.\nIch brauche dieses Harz für eine Sonderbestellung. Natürlich haben wir es nicht in unserem Laden, das Gleiche gilt für unsere örtlichen Militärlager oder sie wollten es einfach nicht verkaufen. Das ist eigentlich irrelevant. Was relevant ist, ist, dass ich das Harz brauche und ich weiß, wo ich es bekommen kann. Alles, was ich brauche, ist ein Kapitän, der mit Enterungen vertraut ist.";
			link.l1 = "Ich glaube, ich beginne Ihren Punkt zu sehen...";
			link.l1.go = "FMQM_2";
		break;
		
		case "FMQM_2":
			dialog.text = "Prächtig. Nun hören Sie zu, ein kleiner Handelskonvoi wurde in der Nähe von Trinidad oder genauer gesagt im Hafen von San Jose gefunden. Ein Schiff transportiert eine anständige Ladung des Harzes, genau das Harz, das ich dringend brauche. Ich werde Ihnen mehr erzählen, wenn Sie die Idee mögen, die Feinde unserer Nation zu plündern. Was sagen Sie dazu?";
			link.l1 = "Ich mag Ihren Vorschlag. Ich bin bereit, es zu versuchen.";
			link.l1.go = "FMQM_3";
			link.l2 = "Ich werde passieren, Monsieur. Mein Schiff und meine Mannschaft sind momentan nicht in ihrem besten Zustand.";
			link.l2.go = "FMQM_exit";
		break;
		
		case "FMQM_exit":
			dialog.text = "Gut, es ist Ihr Recht zu tun, was Sie wollen. Entschuldigung für die Zeitverschwendung, Kapitän.";
			link.l1 = "Auf Wiedersehen.";
			link.l1.go = "FMQM_exit_1";
		break;
		
		case "FMQM_exit_1":
			DialogExit();
			pchar.questTemp.FMQM = "fail";
			AddQuestRecord("FMQ_Martinique", "3");
			CloseQuestHeader("FMQ_Martinique");
		break;
		
		case "FMQM_3":
			string sTemp = "barquentine";
			if (MOD_SKILL_ENEMY_RATE < 7) sTemp = "barque";// Addon 2016-1 Jason пиратскаЯ линейка
			dialog.text = "Dann hör zu: Der Konvoi besteht aus drei Schiffen, das Harz wird unter anderem auf einem "+sTemp+"genannt 'Bensecho'. Das ist Ihr Hauptziel. Wie ich bereits gesagt habe, segeln die Spanier von San Jose - Trinidad, nach San Juan - Puerto Rico. Sie werden morgen in See stechen, also können Sie frei wählen, wo Sie sie angreifen wollen.";
			link.l1 = "Verstanden. Was ist mit einer Belohnung?";
			link.l1.go = "FMQM_4";
		break;
		
		case "FMQM_4":
			dialog.text = "Alles, was mich interessiert, ist das Harz. Ich werde fünfzehn goldene Dublonen für jedes Fass davon bezahlen. Nach meinen Informationen führt die 'Bensecho' etwa hundert Fässer mit sich.";
			link.l1 = "Heilige Kuh! Das ist eine große Summe!";
			link.l1.go = "FMQM_5";
		break;
		
		case "FMQM_5":
			dialog.text = "Ja. Ich habe Ihnen bereits gesagt, dass diese spezielle Ware sehr teuer und selten ist.";
			link.l1 = "Du hast mir auch gesagt, dass dies eine Schmuggelware ist.";
			link.l1.go = "FMQM_6";
		break;
		
		case "FMQM_6":
			dialog.text = "Mach dir keine Sorgen, es wird nicht nötig sein, dass du es zum Laden oder zu den Schmugglern bringst. Komm zu mir, wenn die Arbeit erledigt ist, wir werden dein Schiff in meiner Werft anlegen, um es zu reparieren und dann nachts heimlich die ganze Ladung ausladen. Niemand wird etwas vermuten.";
			link.l1 = "Sie denken vor mir, Meister. Sehr gut. Keine Zeitverschwendung. Ich bin auf dem Weg, in See zu stechen.";
			link.l1.go = "FMQM_7";
		break;
		
		case "FMQM_7":
			dialog.text = "Gute Fahrt, Kapitän.";
			link.l1 = "...";
			link.l1.go = "FMQM_8";
		break;
		
		case "FMQM_8":
			DialogExit();
			pchar.questTemp.FMQM = "convoy";
			AddQuestRecord("FMQ_Martinique", "4");
			SetFunctionTimerCondition("FMQM_ConvoyStart", 0, 0, 1, false);
		break;
		
		case "FMQM_9":
			dialog.text = "Ausgezeichnet! Lassen wir Ihr Schiff wie vereinbart in den Docks. Wir werden sie heute Nacht dort entladen. Geh zurück zu deinem Schiff und lass mich das Geld für dich vorbereiten.";
			link.l1 = "Lass uns das tun.";
			link.l1.go = "FMQM_10";
			DelLandQuestMark(npchar);
		break;
		
		case "FMQM_10":
			pchar.quest.FMQM_Late.over = "yes";
			DialogExit();
			InterfaceStates.Buttons.Save.enable = false;
			chrDisableReloadToLocation = true;
			pchar.GenQuest.FrameLockEsc = true;
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], true);
			pchar.questTemp.FMQM = "remove_oil";
			pchar.questTemp.FMQM.Oil = "true";
			pchar.questTemp.FMQM.Qty = GetSquadronGoods(pchar, GOOD_OIL);
			DoQuestFunctionDelay("FMQM_WaitTime", 1.0);
			RemoveCharacterGoods(pchar, GOOD_OIL, GetSquadronGoods(pchar, GOOD_OIL));
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
