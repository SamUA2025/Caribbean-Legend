// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Quel genre de questions ?","Que veux-tu, "+GetAddress_Form(NPChar)+"?"),"Vous avez déjà essayé de me poser une question "+GetAddress_Form(NPChar)+"...","Vous parlez de cette question pour la troisième fois aujourd'hui...","Ecoutez, si vous n'avez rien à me dire concernant les affaires du port, alors ne me dérangez pas avec vos questions.","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Je me suis ravisé.","Je n'ai rien à dire."),"Peu importe.","En effet, déjà la troisième fois...","Désolé, mais les affaires du port ne m'intéressent pas pour l'instant.",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;

	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
