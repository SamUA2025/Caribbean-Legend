// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Jak mogę ci pomóc?","Co mogę dla ciebie zrobić?"),"Powiedz mi, co cię trapi, "+GetAddress_Form(NPChar)+"?","Po raz trzeci, "+GetAddress_Form(NPChar)+"Czego potrzebujesz?","Mam cię dosyć. Wynoś się!","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Zmieniłem zdanie, przepraszam.","To nic takiego, wybacz mi."),"Przebacz mi, o nic mi nie chodziło.","Masz rację, to już trzeci raz. Wybacz mi...","Przepraszam.",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2); 
}
