// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Quelles questions avez-vous ?","Comment puis-je vous aider ?"),"Vous avez essayé de me poser une question il y a un petit moment...","Je n'ai jamais rencontré des gens avec une telle curiosité dans mon chantier naval ou ailleurs dans cette ville.","Pourquoi toutes ces questions ? Mon métier, c'est de construire des navires. Occupons-nous de ça.","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("J'ai changé d'avis...","Je n'ai rien à dire pour le moment."),"Hum, où est donc passée ma mémoire...","Hm, eh bien...","Allez-y...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			// калеуче
			if (CheckAttribute(pchar, "questTemp.Caleuche") && pchar.questTemp.Caleuche == "graveyard" && !CheckAttribute(npchar, "quest.caleuche"))
			{
				link.l1 = "Ecoutez, un homme nommé Joachim Merriman est-il venu ici récemment ? Un seigneur d'âge moyen, portugais, avec moustache, barbe impériale et yeux perçants ? Peut-être voulait-il acheter un navire ?";
				link.l1.go = "caleuche";
			}
		break;
		
		// калеуче
		case "caleuche":
			dialog.text = "Non, Senor. Je n'ai pas vu un tel client.";
			link.l1 = "Je vois. Dommage. Je vais donc continuer ma recherche...";
			link.l1.go = "exit";
			npchar.quest.caleuche = "true";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
