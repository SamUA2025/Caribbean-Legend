// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Welche Fragen haben Sie?","Wie kann ich Ihnen helfen?"),"Du hast versucht, mir vor einer Weile eine Frage zu stellen...","Ich habe noch nie Leute mit solcher Neugier in meiner Werft oder sonstwo in dieser Stadt getroffen.","Was soll das ganze Gefrage? Meine Arbeit ist es, Schiffe zu bauen. Kümmern wir uns darum.","Block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Ich habe es mir anders überlegt...","Ich habe im Moment nichts zu besprechen."),"Umph, wo ist mein Gedächtnis hin...","Hm, nun ja...","Mach weiter...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			if (pchar.questTemp.Slavetrader == "FindRatPortobello")
            {
                link.l1 = "Hör zu, hat zufällig ein Freibeuter namens Francois Gontier bei dir vorbeigeschaut? Er war kürzlich in Porto Bello, das weiß ich.";
                link.l1.go = "Portobello_ratS_1";
            }
		break;
		
		case "Portobello_ratS_1":
			dialog.text = "Er hat. Er hat eine Korvette von mir erworben und ist bald in See gestochen.";
			link.l1 = "Danke! Und haben Sie eine Ahnung, wohin er aufgebrochen ist?";
			link.l1.go = "Portobello_ratS_2";
		break;
			
		case "Portobello_ratS_2":
			dialog.text = "Nein, Kumpel, ich habe keine Ahnung. Ich repariere und verkaufe Schiffe, ich verfolge nicht, wohin sie gehen. Es geht mich nichts an.";
			link.l1 = "Nun, danke... Lass uns herausfinden, wohin du gegangen bist...";
			link.l1.go = "exit";
			pchar.questTemp.Slavetrader = "FindRatPortobello_1";
			AddQuestRecord("Slavetrader", "21_2");
		break;
			
			
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
