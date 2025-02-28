// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Was willst du?","Was möchten Sie wissen?"),"Was brauchen Sie, "+GetAddress_Form(NPChar)+"?","Das ist das dritte Mal, dass du versuchst, mich zu fragen...","Ich hab genug von dir, hau ab!","Block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Entschuldigung, ich habe meine Meinung geändert.","Es ist nichts, Entschuldigungen."),"Ich habe vergessen, meine Entschuldigung...","Drittes Mal ist Glück, hm? Entschuldigen Sie mich...","Entschuldigung, Entschuldigung! Ich werde dann gehen...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2); 
}
