// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{

	switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat("Allez-y, que voulez-vous ?","Nous parlions justement de cela. Vous devez avoir oublié...","C'est la troisième fois aujourd'hui que vous parlez d'une question...","Écoutez, c'est un magasin. Les gens achètent des choses ici. Ne me dérangez pas !","bloc",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Tu sais, "+NPChar.name+"peut-être la prochaine fois.","D'accord, j'ai oublié pour une raison...","Oui, c'est vraiment la troisième fois...","Hm, je ne vais pas...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);
}
