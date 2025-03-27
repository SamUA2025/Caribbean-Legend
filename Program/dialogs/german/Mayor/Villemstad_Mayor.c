// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Was willst du? Frag nur.","Ich höre zu, was ist die Frage?"),"Das ist das zweite Mal, dass du versuchst zu fragen...","Das ist das dritte Mal, dass Sie versuchen zu fragen...","Wann wird das enden?! Ich bin ein beschäftigter Mann, der an Kolonialangelegenheiten arbeitet und Sie belästigen mich immer noch!","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Ich habe es mir anders überlegt, tut mir leid.","Nicht jetzt. Falscher Ort und Zeit."),"Wahrlich, ich habe jetzt nichts zu sagen, Entschuldigung.","Ich werde später fragen.","Es tut mir leid, "+GetAddress_FormToNPC(NPChar)+"...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			//Португалец
			if (CheckAttribute(pchar, "questTemp.Portugal.Villemstad"))
			{
				link.l1 = "Ich weiß, dass die Niederländische Westindien-Kompanie einen Preis für den Kopf eines bestimmten Piraten ausgesetzt hat - Bartolomeo der Portugiese. Ich konnte ihn gefangen nehmen. Er befindet sich derzeit in meinem Laderaum und ich bin bereit, ihn den Behörden zu übergeben.";
                link.l1.go = "Portugeze";
			}
		break;

		case "Cupture_after":
            dialog.text = RandPhraseSimple("Sie haben bereits alles genommen. Was wollen Sie noch?","Gibt es noch etwas, das Sie nicht ergriffen haben?");
            link.l1 = RandPhraseSimple("Nur mal umsehen...","Nur zur Kontrolle, könnte vergessen haben, etwas mitzunehmen...");
            link.l1.go = "exit";
            NextDiag.TempNode = "Cupture_after";
		break;
		
		//Португалец
		case "Portugeze":
			dialog.text = "Bart der Portugiese?! Habt Ihr ihn, lebendig?!";
			link.l1 = "Ich weiß, dass er dir tot nicht nützt. Er lebt und, verdammt seien die Götter, ich musste mich zurückhalten, um ihn am Leben zu halten!";
			link.l1.go = "Portugeze_1";
		break;
		
		case "Portugeze_1":
			dialog.text = "Vortrefflich! Jetzt wird er uns alles erzählen... Mynheer, bereiten Sie den Gefangenen für den Transfer vor. Wir werden sofort eine Militärbarke zu Ihrem Schiff schicken. ";
			link.l1 = "Ich würde gerne zuerst über meine Belohnung sprechen, Mynheer, wenn es Ihnen nichts ausmacht.";
			link.l1.go = "Portugeze_2";
		break;
		
		case "Portugeze_2":
			dialog.text = "Machen Sie sich keine Sorgen um Ihre Belohnung, Herr. Sie werden sie erhalten. Wir haben einen Preis für den Kopf von Bartolomeo dem Portugiesen festgesetzt - eintausend und fünfhundert Dublonen. Leutnant! Bringen Sie dem Kapitän seine Belohnung!";
			link.l1 = "Hm... Hugo hat mir gesagt, es wären zweitausend Dublonen... Na gut dann.";
			link.l1.go = "Portugeze_3";
		break;
		
		case "Portugeze_3":
			TakeNItems(pchar, "gold_dublon", 1500);
			Log_Info("You have received 1500 doubloons");
			PlaySound("interface\important_item.wav");
			dialog.text = "Und nun, Herr, wären Sie so freundlich, den Portugiesen an die Gesellschaft zu übergeben? Wir sind so begierig, mit ihm zu sprechen.";
			link.l1 = "Sicher, Mynheer, schicken Sie die Bark zu meinem Schiff.";
			link.l1.go = "Portugeze_4";
		break;
		
		case "Portugeze_4":
			DialogExit();
			DoQuestReloadToLocation("Villemstad_town", "reload", "reload1", "Portugal_Final");
			DeleteAttribute(pchar, "questTemp.Portugal.Villemstad");
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
