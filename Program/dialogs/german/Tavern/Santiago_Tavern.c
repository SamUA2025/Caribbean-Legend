// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Welche Fragen haben Sie?","Wie kann ich Ihnen helfen, "+GetAddress_Form(NPChar)+"?"),"Du hast versucht, mir vor kurzem eine Frage zu stellen, "+GetAddress_Form(NPChar)+"...","Über den ganzen Tag hinweg ist dies das dritte Mal, dass du über eine Frage redest...","Noch mehr Fragen, nehme ich an?","Block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Ich habe es mir anders überlegt...","Ich habe im Moment nichts zu besprechen."),"Umph, wo ist mein Gedächtnis hin...","Ja, es ist wirklich das dritte Mal...","Nein, welche Fragen?...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			// Jason Долго и счастливо
			if (CheckAttribute(pchar, "questTemp.LongHappy.Santiago"))
			{
				link.l1 = "Ich habe gehört, dass die Heiligen Väter hier aus einer französischen Kolonie mit einer Delegation angekommen sind, um etwas zu vereinbaren? Wahrscheinlich, um Gefangene nach diesem blutigen Bad in Martinique auszutauschen?";
				link.l1.go = "LH_tavern";
			}
		break;
		
		// Jason Долго и счастливо
		case "LH_tavern":
			dialog.text = "Nein, senor, diese Geschichte wurde vor langer Zeit ohne Priester geklärt. Siehst du, du lebst völlig unter einer Palme, da du nicht gehört hast, dass Papst Innocent X. mit Kardinal Mazarin endlich übereingekommen ist. Europa mit seinen Kriegen ist eine Sache, aber alle Christen sollten gemeinsam gegen die heidnische Dunkelheit am Ende der Welt kämpfen\nUnd ja, die Froschfresser kamen zu uns. Aber sie konnten sich einfach auf nichts einigen - unser geehrter Gast sitzt in einer Gouverneursvilla, unter Bewachung, trinkt Kaffee und wärmt einen Sitz. Fast einen Monat schon! Die Leute haben getratscht, lange geredet und sich daran gewöhnt - sieh mal, der französische Abt hält abends in der Kirche einen Gebetsdienst. Fast wie eine Sehenswürdigkeit ahah!";
			link.l1 = "Interessant! Ich sollte mir diesen Franzosen ansehen, zumindest ist es lustiger als auf einen Krug zu starren.";
			link.l1.go = "LH_tavern_1";
		break;
		
		case "LH_tavern_1":
			DialogExit();
			LongHappy_SantiagoBenua();
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
