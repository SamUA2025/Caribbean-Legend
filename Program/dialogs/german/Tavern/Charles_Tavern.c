// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Welche Fragen haben Sie?","Wie kann ich Ihnen helfen, "+GetAddress_Form(NPChar)+"?"),"Du hast versucht, mir vor kurzem eine Frage zu stellen, "+GetAddress_Form(NPChar)+"...","Über den ganzen Tag hinweg ist dies das dritte Mal, dass du von irgendeiner Frage sprichst...","Noch mehr Fragen, nehme ich an?","Block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Ich habe es mir anders überlegt...","Ich habe im Moment nichts zu besprechen."),"Umph, wo ist mein Gedächtnis hin...","Ja, es ist wirklich das dritte Mal...","Nein, welche Fragen?...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			// Сага
			if(CheckAttribute(pchar, "questTemp.Saga.BarbTemptation") && pchar.questTemp.Saga.BarbTemptation == "valet")
			{
				link.l1 = "Ich suche einen Mann mit dem Spitznamen Valet. Kennen Sie ihn?";
				link.l1.go = "valet_1";
				link.l2 = "Ich suche den Kapitän einer Polacre namens 'Marlin'. Könnten Sie mir sagen, wo ich ihn finden kann?";
				link.l2.go = "valet_2";
			}
		break;
		
		case "valet_1":
			dialog.text = NPCStringReactionRepeat("Nein, ich weiß es nicht, Kumpel. Also gibt es nichts, womit ich dir helfen könnte.","Ich habe dir schon gesagt, dass ich es nicht weiß!","Bist du betrunken oder machst du nur Unsinn?","Lass mich in Ruhe!","Block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Ich verstehe. Das ist schade...","Das ist zu schade. Ich dachte, du würdest dich erinnern...","Ich bin nüchtern! Ich bin einfach hartnäckig...","Hm...",npchar,Dialog.CurrentNode); 
			link.l1.go = DialogGoNodeRepeat("exit", "", "", "", npchar, Dialog.CurrentNode);
		break;
		
		case "valet_2":
			dialog.text = NPCStringReactionRepeat("Ach, Herr David Fackman! Er mietet ein Haus nicht weit von der Werft. Suchen Sie ihn dort.","Ich habe dir gerade geantwortet. Wie hast du mir zugehört?","Bist du betrunken oder machst du nur Unsinn?","Lass mich in Ruhe!","Block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Danke dir!","Ja. Es tut mir leid.","Ich bin nüchtern! Ich bin einfach hartnäckig...","Hm...",npchar,Dialog.CurrentNode); 
			link.l1.go = DialogGoNodeRepeat("exit", "", "", "", npchar, Dialog.CurrentNode);
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
