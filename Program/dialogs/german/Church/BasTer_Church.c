// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Welche Art von Fragen, "+GetSexPhrase("mein Sohn","meine Tochter")+"?","Frag nur, ich höre zu..."),"Ich höre zu, sprich jetzt, "+GetSexPhrase("mein Sohn","meine Tochter")+"...","Zum dritten Mal, "+GetSexPhrase("mein Sohn","meine Tochter")+", fragen Sie nach dem, was Sie brauchen.","Ein Geistlicher hat viel Arbeit und Sie lenken mich ab, "+GetSexPhrase("mein Sohn","meine Tochter")+"...","Block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Ich habe meine Meinung geändert...","Nicht zu dieser Zeit, Padre..."),"Ich habe nichts zu sagen, meine Entschuldigung.","Ich werde fragen, aber später. Verzeih mir, Vater.","Verzeihen Sie mir, heiliger Vater...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";		
			if (CheckAttribute(pchar, "questTemp.Guardoftruth") && pchar.questTemp.Guardoftruth == "utensil" && !CheckAttribute(npchar, "quest.utensil"))
			{
				link.l1 = "Ich komme zu Ihnen wegen einer ungewöhnlichen Angelegenheit, heiliger Vater. Ein Freibeuter namens Guy Marchais hat Ihrer Pfarrei vor nicht allzu langer Zeit einen sehr wertvollen Gegenstand überreicht. Es war ein goldenes, pectorales Kreuz mit eingebettetem Lazurit. Ist das wahr?";
                link.l1.go = "guardoftruth";
			}
		break;
		
		case "guardoftruth":
			dialog.text = "Oh ja, mein Sohn! Es ist das beste Stück in unserer Pfarrei. Ich habe in meinem ganzen Leben noch nie so eine Pracht gesehen! Aber warum fragst du, mein Sohn? Warum interessierst du dich für dieses Kreuz?";
			link.l1 = "Heiliger Vater, ich weiß, dass Ihnen das nicht gefallen wird, aber dieses Kreuz wurde aus einer anderen Gemeinde gestohlen und der Geistliche wurde während der Tat ermordet. Der Mann, der Ihnen diesen Gegenstand vorgelegt hat, ist ein Mörder.";
			link.l1.go = "guardoftruth_1";
		break;
		
		case "guardoftruth_1":
			dialog.text = "Wir alle sündigen, mein Sohn, und ein Geistlichenmord ist eine schwerwiegende Anschuldigung. Hast du einen Beweis? Aus welcher Pfarrei wurde dieses Kreuz gestohlen?";
			link.l1 = "Ist mein Wort nicht Beweis genug? Dieses Kreuz wurde aus der Pfarrei in Santiago gestohlen und es muss zurückgegeben werden.";
			link.l1.go = "guardoftruth_2";
		break;
		
		case "guardoftruth_2":
			dialog.text = "Santiago? Ist das nicht eine spanische Stadt? Mein Sohn, du überraschst mich...";
			link.l1 = "Heiliger Vater, vor Gott sind alle Menschen gleich. Die Spanier sind genauso Christen wie wir und Meinungsverschiedenheiten zwischen den Nationen dürfen sich nicht auf die Gefühle der Gläubigen auswirken. Ich bitte Sie, dieses Kreuz der Pfarrgemeinde Santiago zurückzugeben.";
			link.l1.go = "guardoftruth_3";
		break;
		
		case "guardoftruth_3":
			dialog.text = "Mein Sohn, verstehst du nicht, dass dieses Kreuz ein Geschenk von den liebenden Christen für unsere Pfarrei ist?! Nein, mein Sohn, ich kann nicht tun, was du verlangst.";
			link.l1 = "Macht es Ihnen nichts aus, dass Blut über dieses Kreuz vergossen wurde? Das Blut eines Geistlichen, ob Spanier oder nicht, das spielt keine Rolle.";
			link.l1.go = "guardoftruth_4";
		break;
		
		case "guardoftruth_4":
			dialog.text = "Mein Sohn, du hast keinen Beweis vorgelegt und ich kann dein Wort nicht blindlings akzeptieren. Das Kreuz bleibt in unserer Gemeinde. Das ist meine endgültige Entscheidung. Außerdem bereitet mir deine Bemühung, den Spaniern in dieser Angelegenheit zu helfen, große Sorgen.";
			link.l1 = "So sei es, Lebewohl dann, heiliger Vater...";
			link.l1.go = "guardoftruth_5";
		break;
		
		case "guardoftruth_5":
			DialogExit();
			npchar.quest.utensil = "true";
			pchar.questTemp.Guardoftruth.Baster_church = "seek";
			AddQuestRecord("Guardoftruth", "27");
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
