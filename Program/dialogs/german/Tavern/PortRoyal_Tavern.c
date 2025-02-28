// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat("Alle Gerüchte von "+GetCityName(npchar.city)+" zu Ihren Diensten. Was möchten Sie herausfinden?","Wir haben gerade darüber gesprochen. Du musst es vergessen haben...","Das ist das dritte Mal heute, dass du von irgendeiner Frage sprichst...","Du wiederholst dich wie ein Papagei...","Block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Weißt du, "+NPChar.name+", vielleicht nächstes Mal.","Stimmt, ich habe aus irgendeinem Grund vergessen...","Ja, es ist wirklich das dritte Mal...","Jawohl...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			if (pchar.questTemp.Slavetrader == "FindRatJamaica")
            {
                link.l1 = "Wissen Sie zufällig, wo ich Francois Gontier finden kann?";
                link.l1.go = "Jamaica_ratP_1";
            }
			// Страж Истины
			if (CheckAttribute(pchar, "questTemp.Guardoftruth") && pchar.questTemp.Guardoftruth == "merdok" && !CheckAttribute(npchar, "quest.jino"))
			{
				link.l1 = "Hör mal, ist hier in dieser Stadt ein Alchemist angekommen, ein Arzt? Er ist Italiener, etwa dreißig Jahre alt, sein Name ist Gino Gvineili. Haben Sie etwas darüber gehört?";
				link.l1.go = "guardoftruth";
			}
		break;

		case "Jamaica_ratP_1":
			dialog.text = NPCStringReactionRepeat("Ich habe nicht die geringste Ahnung. Ich habe diesen Namen noch nie gehört.","Du hast bereits danach gefragt und ich habe dir geantwortet.","Ich habe dir gesagt, du hast schon nach diesem Gontier gefragt.","Hör zu, geh weg und hör auf, mich zu belästigen! Hast du völlig den Verstand verloren?","Block",0,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Nun, dann werde ich weiter suchen.","Hm, ich denke schon...","Ja, richtig, das habe ich gefragt...","Entschuldigung, "+npchar.name+"...",npchar,Dialog.CurrentNode);
		break;
		
		case "guardoftruth":
			dialog.text = LinkRandPhrase("Nein, haben wir nicht. Wir haben Kräuterkundler und Ärzte, aber keinen mit einem solchen Namen.","Das ist das erste Mal, dass ich einen so seltsamen Namen höre. Nein, der Mann, von dem du sprichst, hat uns noch nie besucht.","Wir haben hier überhaupt keine Alchemisten. Wir haben Ärzte, aber keinen mit einem so seltsamen Namen.");
			link.l1 = "Ich verstehe. Das ist schade. Ich werde weiter suchen!";
			link.l1.go = "exit";
			npchar.quest.jino = "true";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
