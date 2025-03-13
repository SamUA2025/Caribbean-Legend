// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
	switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Quelles questions avez-vous ?","Comment puis-je vous aider ?"),"Vous avez essayé de me poser une question il n'y a pas longtemps alors que vous étiez dans le magasin...","C'est la troisième question aujourd'hui. J'ai besoin de faire des affaires, pas de m'engager dans des conversations futiles...","Encore des questions ? Que diriez-vous de conclure un marché à la place ?","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("J'ai changé d'avis...","Je n'ai rien à dire pour le moment."),"Oui, c'est exact. J'ai essayé... Pendant que j'étais dans le magasin...","Oui, c'est la troisième question...","Hm, peut-être que nous pouvons conclure un marché...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;				
	}
	UnloadSegment(NPChar.FileDialog2);
}
