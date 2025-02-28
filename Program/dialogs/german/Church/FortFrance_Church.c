// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Welche Art von Fragen, "+GetSexPhrase("mein Sohn","meine Tochter")+"?","Frag nur, ich höre zu..."),"Ich höre zu, sprich jetzt, "+GetSexPhrase("mein Sohn","meine Tochter")+"...","Zum dritten Mal, "+GetSexPhrase("mein Sohn","meine Tochter")+", fragen Sie nach dem, was Sie brauchen.","Ein Geistlicher hat viel Arbeit und Sie lenken mich ab, "+GetSexPhrase("mein Sohn","meine Tochter")+"...","Block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Ich habe meine Meinung geändert...","Nicht zu diesem Zeitpunkt, Padre..."),"Ich habe nichts zu sagen, meine Entschuldigung.","Ich werde fragen, aber später. Verzeih mir, Vater.","Verzeihen Sie mir, heiliger Vater...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			// Jason Долго и счастливо
			if (CheckAttribute(pchar, "questTemp.LongHappy") && pchar.questTemp.LongHappy == "choose" && !CheckAttribute(npchar, "quest.LongHappy"))
			{
				link.l1 = "Heiliger Vater, ich suche Abt Benoit, ich habe eine dringende Angelegenheit für ihn. Können Sie mir sagen, wo ich ihn finden kann?";
				link.l1.go = "LH_church";
			}
		break;
		
		// Jason Долго и счастливо
		case "LH_church":
			dialog.text = "Abt Benoit hat die Stadt hinsichtlich der Kirchenangelegenheiten mit Vertretern der spanischen katholischen Mission in der Neuen Welt verlassen. Ich kenne keine Einzelheiten, aber Abt Benoit ist lange genug abwesend, um anzunehmen, dass die Verhandlungen verlängert wurden, oder etwas auf dem Weg passiert ist. Wir sind alle beunruhigt, aber wir können nur beten und auf die Nachrichten warten.";
			link.l1 = "Man kann nicht davon ausgehen, dass alles einfach ist. Heiliger Vater, können Sie mir sagen, wo genau Abt Benoit hingegangen ist? Ich muss ihn so schnell wie möglich finden.";
			link.l1.go = "LH_church_1";
		break;
		
		case "LH_church_1":
			dialog.text = "Ich fürchte, ich kann nicht, mein Sohn. Soweit ich weiß, ging Abt Benoit, um mit dem Bischof von Neuspanien und dem Prälaten der Inquisition, Vater Vincento Palotti, zu verhandeln, aber er hat nicht angegeben, wo das Treffen stattfinden wird.";
			link.l1 = "Das sollte genügen, Heiliger Vater, danke. Ich kenne Vater Palotti irgendwie... Ich werde mich in Santiago umsehen.";
			link.l1.go = "LH_church_2";
		break;
		
		case "LH_church_2":
			DialogExit();
			npchar.quest.LongHappy = "true";
			LongHappy_GoToSantiago();
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
