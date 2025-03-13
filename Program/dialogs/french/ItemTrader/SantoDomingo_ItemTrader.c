// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Quel genre de questions ?","Que voulez-vous, "+GetAddress_Form(NPChar)+"?"),"Encore des questions, "+GetAddress_Form(NPChar)+"... ","Des questions, des questions... Et si nous faisions du commerce, "+GetAddress_Form(NPChar)+"Hein ?","Écoute, combien de temps comptes-tu parler?","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Aucune question pour l'instant...","Désolé, je n'ai rien à dire pour le moment..."),"Encore une fois, désolé...","Peut-être qu'il est vraiment temps de faire du commerce...","Je suis désolé, faisons du commerce...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
