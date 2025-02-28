// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{

	switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat("Mach weiter, was willst du?","Wir haben gerade darüber gesprochen. Du musst es vergessen haben...","Das ist das dritte Mal heute, dass du über irgendeine Frage sprichst...","Hör zu, das ist ein Laden. Leute kaufen hier Sachen. Stör mich nicht!","Block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Du weißt, "+NPChar.name+", vielleicht nächstes Mal.","Stimmt, ich habe aus irgendeinem Grund vergessen...","Ja, es ist wirklich das dritte Mal...","Hm, ich werde nicht...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);
}
