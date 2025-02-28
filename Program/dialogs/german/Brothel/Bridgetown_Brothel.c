// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    ref sld;
	switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Welche Art von Fragen, "+GetSexPhrase("junger Mann","junge Dame")+"?","Was brauchen Sie, "+GetSexPhrase("schön","hübscher")+"? Frag nur."),"Wieder Fragen?","Tee-hee, wenn es Ihnen recht ist - Fragen...",""+GetSexPhrase("Hm, warum suchst du dir nicht eine Schönheit aus? Ich fange an, Verdächtigungen über dich zu haben...","Hm, warum wählst du dir nicht eine Schönheit aus? Jungs haben wir hier leider nicht, hihi...")+"","Block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Ich habe es mir anders überlegt, entschuldigen Sie mich.","Eigentlich, vergiss es..."),"Ich... Entschuldigung, ich habe im Moment keine Fragen.","Du hast recht, es ist bereits das dritte Mal. Verzeih mir.","Vielleicht nächstes Mal, Madame.",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			if (CheckAttribute(pchar, "questTemp.HWIC.Eng") && pchar.questTemp.HWIC.Eng == "GotoBridgetown" && !CheckAttribute(npchar, "quest.HWICTalked"))
            {
                link.l1 = "Ich habe eine Ladung Mahagoni für den Handel gekauft und bin auf dem Weg nach Blueweld. Es ist noch ein langer Weg, und meine Männer sind wenige und unruhig ... Was würde es kosten, fünfzig Matrosen hier die Nacht verbringen zu lassen?";
                link.l1.go = "BrothelDone";
            }
		break;
		
		case "BrothelDone":
			dialog.text = "Fünfzig Seeleute - fünfzehntausend.";
			link.l1 = "Eine große Summe... Ich muss darüber nachdenken.";
			link.l1.go = "exit";	
			npchar.quest.HWICTalked = "true";
			pchar.questTemp.HWIC.Eng.BridgeCounter = sti(pchar.questTemp.HWIC.Eng.BridgeCounter)+1;
			AddQuestRecord("Holl_Gambit", "2-7");
			DelLandQuestMark(npchar);
			if (sti(pchar.questTemp.HWIC.Eng.BridgeCounter) == 7) 
			{
			AddQuestRecord("Holl_Gambit", "2-6");
			pchar.quest.GotoBridgetownOver.over = "yes";//снять таймер
			DelMapQuestMarkCity("Bridgetown");
			pchar.questTemp.HWIC.Eng = "SeekVanBerg";
				pchar.quest.VanBergAttack_Check.win_condition.l1 = "MapEnter";
				pchar.quest.VanBergAttack_Check.function = "VanBergAttackCheck";
				//if(sti(RealShips[sti(pchar.ship.type)].basetype) != SHIP_VALCIRIA || GetCompanionQuantity(pchar) > 1) AddDialogExitQuestFunction("FailVanBergInWorld");
				//else AddDialogExitQuestFunction("CreateVanBergInWorld");
			}
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
