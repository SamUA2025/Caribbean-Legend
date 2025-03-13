// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Que veux-tu?","Que voulez-vous savoir ?"),"Que désirez-vous, "+GetAddress_Form(NPChar)+"?","C'est la troisième fois que vous essayez de me demander...","J'en ai assez de toi, fiche le camp !","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Désolé, j'ai changé d'avis.","Ce n'est rien, pardonnez-moi."),"J'ai oublié, mes excuses...","Jamais deux sans trois, hein? Excusez-moi...","Désolé, désolé ! Je vais me retirer alors...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2); 
}
