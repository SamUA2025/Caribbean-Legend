// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Quelles questions as-tu ?","Comment puis-je vous aider?"),"Tu as essayé de me poser une question il y a peu de temps...","Je n'ai jamais rencontré de gens avec une telle curiosité dans mon chantier naval ou ailleurs dans cette ville.","Pourquoi toutes ces questions ? Mon métier, c'est de construire des navires. Occupons-nous de cela.","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("J'ai changé d'avis...","Je n'ai rien à discuter pour le moment."),"Oumph, où est passée ma mémoire...","Hum, eh bien...","Vas-y...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
