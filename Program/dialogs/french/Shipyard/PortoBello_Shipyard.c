// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Quelles questions avez-vous ?","Comment puis-je vous aider ?"),"Vous avez essayé de me poser une question il y a un petit moment...","Je n'ai jamais rencontré de gens avec une telle curiosité dans mon chantier naval ou ailleurs dans cette ville.","Pourquoi toutes ces questions ? Mon metier est de construire des navires. Occupons-nous de cela.","bloc",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("J'ai changé d'avis...","Je n'ai rien à dire pour le moment."),"Où est donc passée ma mémoire...","Hm, eh bien...","Allez-y...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			if (pchar.questTemp.Slavetrader == "FindRatPortobello")
            {
                link.l1 = "Ecoutez, un corsaire nommé Francois Gontier n'est pas passé vous voir par hasard, n'est-ce pas ? Il était à Porto Bello récemment, je le sais.";
                link.l1.go = "Portobello_ratS_1";
            }
		break;
		
		case "Portobello_ratS_1":
			dialog.text = "Il l'a fait. Il a acquis une corvette de moi et est bientôt parti en mer.";
			link.l1 = "Merci! Et avez-vous une idée d'où il est parti?";
			link.l1.go = "Portobello_ratS_2";
		break;
			
		case "Portobello_ratS_2":
			dialog.text = "Non, camarade, je n'en ai pas la moindre idée. Je répare et je vends des navires, je ne traque pas où ils vont. Cela ne me regarde pas.";
			link.l1 = "Eh bien, gracias... Découvrons où tu es allé...";
			link.l1.go = "exit";
			pchar.questTemp.Slavetrader = "FindRatPortobello_1";
			AddQuestRecord("Slavetrader", "21_2");
		break;
			
			
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
