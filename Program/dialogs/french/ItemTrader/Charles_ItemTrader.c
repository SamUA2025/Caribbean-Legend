// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Quel genre de questions ?","Que voulez-vous, "+GetAddress_Form(NPChar)+"?"),"Encore des questions, "+GetAddress_Form(NPChar)+"... ","Des questions, des questions... Que diriez-vous de commercer, "+GetAddress_Form(NPChar)+"hein ?","Écoute, combien de temps comptes-tu parler ?","bloc",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Pas de questions pour l'instant...","Désolé, je n'ai rien à dire pour l'instant..."),"Désolé encore une fois...","Peut-être qu'il est vraiment temps de commercer...","Je suis désolé, faisons du troc...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
