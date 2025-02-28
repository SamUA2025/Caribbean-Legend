// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Was willst du?","Was möchten Sie wissen?"),"Was brauchen Sie, "+GetAddress_Form(NPChar)+"?","Das ist das dritte Mal, dass du versuchst, mich zu fragen...","Ich habe genug von dir, verschwinde!","Block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Entschuldigung, ich habe meine Meinung geändert.","Es ist nichts, Entschuldigungen."),"Ich habe vergessen, meine Entschuldigung...","Drittes Mal ist Glück, ey? Entschuldigung...","Entschuldigung, Entschuldigung! Ich werde dann gehen...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			// калеуче
			if (CheckAttribute(pchar, "questTemp.Caleuche") && pchar.questTemp.Caleuche == "graveyard" && !CheckAttribute(npchar, "quest.caleuche"))
			{
				link.l1 = "Hören Sie - war hier ein Mann namens Joachim Merriman? Er ist ein mittelalterlicher, portugiesischer Senor, mit einem Schnurrbart, einem kaiserlichen Bart und durchdringenden Augen? Vielleicht ist er in einer Bucht oder in der Nähe des Leuchtturms an Land gegangen? Haben Sie jemanden wie ihn gesehen?";
				link.l1.go = "merriman";
			}
		break;
		
		// калеуче
		case "merriman":
			dialog.text = "Nein, Kamerad, ich hab' niemanden wie ihn gesehen. Ich hätte es bemerkt, aye.";
			link.l1 = "Ich verstehe, was für eine Schande. Danke für Ihre Zeit, ich werde meine Suche dann fortsetzen.";
			link.l1.go = "exit";
			npchar.quest.caleuche = "true";
		break;
	}
	UnloadSegment(NPChar.FileDialog2); 
}
