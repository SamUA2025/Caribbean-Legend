// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Jak mogę ci pomóc?","Co mogę dla ciebie zrobić?"),"Powiedz mi, co cię trapi, "+GetAddress_Form(NPChar)+"?","Po raz trzeci, "+GetAddress_Form(NPChar)+"Czego potrzebujesz?","Dość już cie mam. Wynoś się!","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Zmieniam zdanie, przepraszam.","W sumie to nic, przepraszam."),"Przebacz mi, to jednak nic takiego.","Masz rację, to już trzeci raz. Wybacz mi...","Przepraszam.",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2); 
}
