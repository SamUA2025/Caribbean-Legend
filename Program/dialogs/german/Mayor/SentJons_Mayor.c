// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Was willst du? Frag los.","Ich höre Ihnen zu, was ist die Frage?"),"Das ist das zweite Mal, dass Sie versuchen zu fragen...","Das ist das dritte Mal, dass Sie versuchen zu fragen...","Wann wird das endlich aufhören?! Ich bin ein beschäftigter Mann, arbeite an Kolonieangelegenheiten und Sie belästigen mich immer noch!","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Ich habe es mir anders überlegt...","Nicht jetzt. Falscher Ort und Zeit"),"Wahr... Aber später, nicht jetzt...","Ich werde fragen... Aber ein bisschen später...","Es tut mir leid, "+GetAddress_FormToNPC(NPChar)+"...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			// Jason Дороже золота
			if (CheckAttribute(pchar, "questTemp.GoldenGirl") && pchar.questTemp.GoldenGirl == "antigua")
			{
				link.l1 = "Eure Exzellenz, ich möchte Ihnen mitteilen, dass ich über eine bestimmte Information bezüglich des Verschwindens der Merkur verfüge.";
                link.l1.go = "G_Girl";
			}
		break;
		
		// Jason Дороже золота
		case "G_Girl":
			dialog.text = "Informationen? Über was nochmal?";
			link.l1 = "Die Brigantine, Eure Exzellenz. Transportiert Post. Dokumente von großer Bedeutung und so weiter. Ich habe von der Untersuchung gehört und, offensichtlich, als ein loyaler Freund der britischen Krone, möchte ich helfen.";
			link.l1.go = "G_Girl_1";
		break;
		
		case "G_Girl_1":
			dialog.text = "Prächtig! Baronet Cortney wird begeistert sein, Sie zu empfangen! Ich werde sofort ein Treffen arrangieren.";
			link.l1 = "Danke, Herr. Ich bin hier in Eile und würde es schätzen, wenn es schnell gehen würde.";
			link.l1.go = "G_Girl_2";
		break;
		
		case "G_Girl_2":
			dialog.text = "Macht euch keine Sorgen, ihr werdet alle Zeit der Welt haben. Wachen! Ergreift ihn!";
			link.l1 = "Danke... Moment, was? Ist das ein Scherz?!";
			link.l1.go = "G_Girl_3";
		break;
		
		case "G_Girl_3":
			DialogExit();
			GoldenGirl_AntiguaArest();
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
