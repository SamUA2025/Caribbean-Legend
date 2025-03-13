// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Comment puis-je vous aider ?","Que puis-je faire pour vous ?"),"Dis-moi, qu'est-ce qui te tracasse, "+GetAddress_Form(NPChar)+"?","Pour la troisième fois, "+GetAddress_Form(NPChar)+", que désirez-vous ?","J'en ai assez de toi. Sors d'ici !","bloque",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("J'ai changé d'avis, mes excuses.","Ce n'est rien, excusez-moi."),"Pardonne-moi, ce n'est rien.","Tu as raison, c'est déjà la troisième fois. Pardonne-moi...","Mes excuses.",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2); 
}
