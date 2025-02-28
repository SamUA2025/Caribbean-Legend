// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat("Alle Gerüchte von "+GetCityName(npchar.city)+" zu Ihren Diensten. Was möchten Sie herausfinden?","Wir haben gerade darüber gesprochen. Du musst es vergessen haben...","Das ist das dritte Mal heute, dass du von irgendeiner Frage sprichst...","Du wiederholst dich wie ein Papagei...","Block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Du weißt, "+NPChar.name+", vielleicht nächstes Mal.","Richtig, ich habe aus irgendeinem Grund vergessen...","Ja, es ist wirklich das dritte Mal...","Jawohl...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			if (pchar.questTemp.Slavetrader == "FindRatPanama")
            {
                link.l1 = "Ich habe gehört, Sie haben einen Freibeuter namens Francois Gontier in Ihrer Stadt. Wüssten Sie zufällig, wo ich ihn finden kann?";
                link.l1.go = "Panama_rat_1";
            }
			// Addon-2016 Jason ”ЊЉ-ѓваделупа
			if (CheckAttribute(pchar, "questTemp.FMQG") && pchar.questTemp.FMQG == "headhunter_panama")
            {
                link.l1 = "Schau, ich suche einen Mann namens Bertrand Pinette, hast du von ihm gehört? Er kam vor nicht allzu langer Zeit in Panama an. Ein eindrucksvoller Gentleman in einer Perücke. Er könnte hier gewesen sein...";
                link.l1.go = "FMQG";
            }
		break;

		//-->работорговец
		case "Panama_rat_1":
			dialog.text = NPCStringReactionRepeat("Ja, wir hatten so einen Kerl in der Stadt. Er lungerte an dunklen Orten herum... Dann kamen einige seiner Kumpels und statteten ihm einen Besuch ab, sahen aus wie eine Bande von Halsabschneidern. Er hat die Stadt mit ihnen verlassen.","Du hast bereits danach gefragt und ich habe dir geantwortet.","Ich habe dir gesagt, du hast schon nach diesem Gontier gefragt.","Hör zu, geh weg und hör auf, mich zu belästigen! Hast du deinen Verstand völlig verloren?","Block",0,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Und wo ist er hingegangen, wissen Sie das?","Hm, ich denke schon...","Ja, richtig, ich habe das gefragt...","Entschuldigung, "+npchar.name+"..., Freund.",npchar,Dialog.CurrentNode);
			link.l1.go = "Panama_rat_2";
		break;
		
		case "Panama_rat_2":
			dialog.text = "Nun, es gibt nur einen Weg hier zu Fuß heraus - Portobello. Und er machte sich auf den Weg. Such ihn also dort.";
			link.l1 = "Danke, du warst eine große Hilfe!";
			link.l1.go = "exit";
			pchar.questTemp.Slavetrader = "FindRatPortobello";
			AddQuestRecord("Slavetrader", "21_1");
		break;
		//<--работорговец
		
		// Addon-2016 Jason ”ЊЉ-ѓваделупа
		case "FMQG":
			DelLandQuestMark(npchar);
			DelMapQuestMarkCity("panama");
			dialog.text = "Bertrand Pinette? Franzose? Hab noch nie von ihm gehört. Nein Kumpel, wir haben schon eine Weile keine Franzosen mehr gesehen.";
			link.l1 = "Wie schade... Bist du sicher? Er ist ein Freund eines wichtigen Hidalgo namens Don Carlos de Milyar. Sie sollten eigentlich zusammen hier ankommen.";
			link.l1.go = "FMQG_1";
		break;
		
		case "FMQG_1":
			dialog.text = "Herr de Milyar? Dieser Gentleman besuchte Panama vor einem Jahr. Tatsächlich lebt Don Carlos de Milyar in Portobello. Er ist ein großer Freund des örtlichen Gouverneurs.";
			link.l1 = "Ich verstehe. Es gab keinen Grund, Zeit und Atem im Dschungel zu verschwenden. Danke Kumpel.";
			link.l1.go = "FMQG_2";
		break;
		
		case "FMQG_2":
			DialogExit();
			pchar.questTemp.FMQG = "headhunter_portobello";
			AddQuestRecord("FMQ_Guadeloupe", "8");
			AddMapQuestMarkCity("PortoBello", true);
			AddLandQuestMark(characterFromId("PortoBello_tavernkeeper"), "questmarkmain");
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
