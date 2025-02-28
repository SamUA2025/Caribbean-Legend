// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{

	switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat("Geh voran, was willst du?","Wir haben gerade darüber gesprochen. Du musst es vergessen haben...","Das ist das dritte Mal heute, dass du von irgendeiner Frage redest...","Hör zu, das ist ein Laden. Leute kaufen hier Sachen. Stör mich nicht!","Block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Weißt du, "+NPChar.name+", vielleicht nächstes Mal.","Richtig, ich habe aus irgendeinem Grund vergessen...","Ja, es ist wirklich das dritte Mal...","Hm, ich will nicht...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);
}
