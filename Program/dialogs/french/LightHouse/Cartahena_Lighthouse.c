// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Que veux-tu ?","Que voulez-vous savoir ?"),"Qu'est-ce qu'il vous faut, "+GetAddress_Form(NPChar)+"?","C'est la troisieme fois que tu essaies de me demander...","J'en ai assez de toi, va-t'en !","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Désolé, j'ai changé d'avis.","Ce n'est rien, pardonnez-moi."),"J'ai oublié, mes excuses...","La troisième fois est la bonne, hein ? Excusez-moi...","Désolé, désolé ! Je vais partir alors...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2); 
}
