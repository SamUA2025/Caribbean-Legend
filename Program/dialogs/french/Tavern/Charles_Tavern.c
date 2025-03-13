// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Quelles questions avez-vous?","Comment puis-je vous aider, "+GetAddress_Form(NPChar)+"?"),"Vous avez essayé de me poser une question il n'y a pas longtemps, "+GetAddress_Form(NPChar)+"...","Au cours de toute cette journée, c'est la troisième fois que tu parles d'une question...","Encore des questions, je présume ?","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("J'ai changé d'avis...","Je n'ai rien à dire pour le moment."),"Où diable est passée ma mémoire...","Oui, c'est vraiment la troisième fois...","Non, quelles questions?...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			// Сага
			if(CheckAttribute(pchar, "questTemp.Saga.BarbTemptation") && pchar.questTemp.Saga.BarbTemptation == "valet")
			{
				link.l1 = "Je cherche un homme surnommé Valet. Le connaissez-vous ?";
				link.l1.go = "valet_1";
				link.l2 = "Je cherche le capitaine d'une polacre nommée 'Marlin'. Pourriez-vous me dire où le trouver ?";
				link.l2.go = "valet_2";
			}
		break;
		
		case "valet_1":
			dialog.text = NPCStringReactionRepeat("Non, je ne sais pas, camarade. Donc, il n'y a rien avec quoi je puisse t'aider.","Je t'ai déjà dit que je ne sais pas !","Es-tu saoul ou fais-tu juste le pitre ?","Laisse-moi tranquille !","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Je vois. C'est bien dommage...","C'est bien dommage. Je pensais que tu te souviendrais...","Je suis sobre ! Je suis juste persévérant...","Hm...",npchar,Dialog.CurrentNode); 
			link.l1.go = DialogGoNodeRepeat("exit", "", "", "", npchar, Dialog.CurrentNode);
		break;
		
		case "valet_2":
			dialog.text = NPCStringReactionRepeat("Ah, M. David Fackman ! Il loue une maison non loin du chantier naval. Cherchez-le là-bas.","Je viens de te répondre. Comment m'as-tu écouté ?","Es-tu saoul ou fais-tu simplement l'imbécile?","Laisse-moi tranquille !","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Merci!","Oui. Je suis désolé.","Je suis sobre ! Je suis juste persistant...","Hm...",npchar,Dialog.CurrentNode); 
			link.l1.go = DialogGoNodeRepeat("exit", "", "", "", npchar, Dialog.CurrentNode);
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
