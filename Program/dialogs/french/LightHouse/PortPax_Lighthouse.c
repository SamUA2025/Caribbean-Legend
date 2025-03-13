// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Que veux-tu?","Que voulez-vous savoir ?"),"Que vous faut-il, "+GetAddress_Form(NPChar)+"?","C'est la troisième fois que tu essaies de me demander...","J'en ai assez de toi, fiche le camp !","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Désolé, j'ai changé d'avis.","Ce n'est rien, mes excuses."),"J'ai oublié, toutes mes excuses...","La troisième fois est la bonne, hein ? Excusez-moi...","Desole, desole! Je vais m'en aller alors...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2); 
}
