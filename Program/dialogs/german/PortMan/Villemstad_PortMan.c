// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Welche Art von Fragen?","Was willst du, "+GetAddress_Form(NPChar)+"?"),"Du hast bereits versucht, mir eine Frage zu stellen "+GetAddress_Form(NPChar)+"...","Sie sprechen heute zum dritten Mal über eine Frage...","Schau, wenn du mir nichts über die Angelegenheiten des Hafens zu erzählen hast, dann belästige mich nicht mit deinen Fragen.","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Ich habe meine Meinung geändert.","Ich habe nichts zu besprechen."),"Macht nichts.","Tatsächlich, schon das dritte Mal...","Es tut mir leid, aber ich bin momentan nicht an den Angelegenheiten des Hafens interessiert.",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";

			//работорговец
			if (pchar.questTemp.Slavetrader == "EscapeSlaveVillemstad_P")
            {
    			link.l1 = "Ich möchte mehr über die Bark erfahren, die nach dem Sklavenaufstand verschwunden ist.";
    			link.l1.go = "EscapeSlave_Villemstad_P1";
            }
			//Голландский гамбит, против всех
			if (CheckAttribute(pchar, "questTemp.HWIC.Self") && pchar.questTemp.HWIC.Self == "SeekFleut")
            {
    			link.l1 = "Ich möchte einen Kapitän namens Toff Keller finden. Er besitzt eine Fluyt namens 'Leiden'. Mir wurde gesagt, dass er oft Willemstad besucht, also wird es für Sie nicht schwierig sein, mir zu helfen.";
    			link.l1.go = "SeekTradeFleut";
            }
		break;

		//работорговец
		case "EscapeSlave_Villemstad_P1":
				dialog.text = "Hm... Und warum interessiert es dich? Sind Neger deine Spezialität?";
				link.l1 = "Ich bin hier auf Befehl von Mathias Beck, dem Gouverneur. Ich habe allen Grund zu der Annahme, dass die entflohenen Schwarzen dieses Schiff gestohlen und damit abgehauen sind. Deshalb bitte ich Sie, mir bei meiner Suche in jeder möglichen Weise zu helfen.";
				link.l1.go = "EscapeSlave_Villemstad_P2";
		break;
		
		case "EscapeSlave_Villemstad_P2":
				dialog.text = "Ich verstehe. Nun, ich kann Ihnen nicht helfen. Die Bark '"+pchar.questTemp.Slavetrader.ShipName+"' war bis zum Morgen verschwunden, niemand hat etwas gesehen. Ich war zu Hause und schlief. Der Hafenwächter ist auch verschwunden und hat keine Spur hinterlassen.\nDer Gouverneur hat eine Schaluppe losgeschickt um sie zu verfolgen, während die Spur noch heiß war, aber sie kamen mit leeren Händen zurück. Kein Zeichen von den Negern oder dem '"+pchar.questTemp.Slavetrader.ShipName+"'. Um ehrlich zu sein, die Schaluppe suchte nicht allzu genau nach ihnen, jeder war noch in Panik und dachte, dass Kafirs mit Mistgabeln und Macheten aus dem Dschungel hervorbrechen würden - hungrig nach weißem Blut.";
				link.l1 = "Das war nicht sehr hilfreich, aber trotzdem danke. Auf Wiedersehen.";
				link.l1.go = "exit";
				AddQuestRecord("Slavetrader", "22_3");
				AddQuestUserData("Slavetrader", "sShipName", pchar.questTemp.Slavetrader.ShipName);
				pchar.questTemp.Slavetrader = "EscapeSlaveVillemstad_H";
		break;				
		//Голландский гамбит
		case "SeekTradeFleut":
			DelLandQuestMark(npchar);
			dialog.text = "Toff Keller? Sicher, ich kenne ihn! Er segelt regelmäßig nach San Jose, das auf Trinidad liegt, und nach Cumana. Er ist kürzlich nach Trinidad gesegelt. Ich vermute, dass Sie ihn dort finden können.";
			link.l1 = "Danke!";
			link.l1.go = "SeekTradeFleut_1";
		break;
		
		case "SeekTradeFleut_1":
			DialogExit();
			AddMapQuestMarkIsland("Trinidad", true);
			pchar.questTemp.HWIC.Self = "FleutOnTrinidad";
			AddQuestRecord("Holl_Gambit", "3-59");
			pchar.quest.Seek_Fleut.win_condition.l1 = "location";
			pchar.quest.Seek_Fleut.win_condition.l1.location = "Trinidad";
			pchar.quest.Seek_Fleut.function = "CreateTradeFleut";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
