// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat("Alle Gerüchte von "+GetCityName(npchar.city)+" zu Ihren Diensten. Was möchten Sie herausfinden?","Wir haben gerade darüber gesprochen. Du musst es vergessen haben...","Das ist jetzt das dritte Mal, dass du mich belästigst...","Du wiederholst dich wie ein Papagei...","Block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Du weißt, "+NPChar.name+", vielleicht nächstes Mal.","Richtig, ich habe aus irgendeinem Grund vergessen...","Ja, es ist wirklich das dritte Mal...","Jawohl...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			if(CheckAttribute(pchar, "questTemp.Saga") && pchar.questTemp.Saga == "cartahena" && !CheckAttribute(npchar, "quest.gonsales"))
			{
				link.l1 = "Ich suche Enrique Gonzales. Könnten Sie mir sagen, wie ich ihn finden kann?";
				link.l1.go = "saga";				
			}
		break;
			
		case "saga":
			dialog.text = "Jeder kennt Senor Gonzales! Sein Haus steht neben der Hafenbehörde.";
			link.l1 = "Wie alt ist er?";
			link.l1.go = "saga_1";
		break;
		
		case "saga_1":
			dialog.text = "Nun, ich weiß es nicht genau, aber er scheint mindestens fünfzig zu sein. Er lebt schon seit geraumer Zeit in diesem Haus. Er erzählt gerne allerlei Seemannsgarn über Piraten, die er wahrscheinlich nur in seinen Träumen getroffen hat.";
			link.l1 = "Sieht so aus, als wäre er der Mann, den ich brauche. Danke, "+npchar.name+", du warst eine große Hilfe!";
			link.l1.go = "saga_2";
		break;
		
		case "saga_2":
			DialogExit();
			npchar.quest.gonsales = "true";
			pchar.questTemp.Saga.Gonsales = "true";
			pchar.quest.Saga_Gonsales1.win_condition.l1 = "location";
			pchar.quest.Saga_Gonsales1.win_condition.l1.location = "Cartahena_houseF2";
			pchar.quest.Saga_Gonsales1.function = "Saga_CreateGonsalesA";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
