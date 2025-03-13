// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    ref sld;
	switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Quel genre de questions, "+GetSexPhrase("jeune homme","jeune dame")+"?","Que désires-tu, "+GetSexPhrase("beau","belle demoiselle")+"Demandez donc."),"Encore des questions ?","Hi-hi, si cela vous convient - des questions...",""+GetSexPhrase("Hm, pourquoi ne choisis-tu pas une beauté pour toi-même ? Je commence à avoir des soupçons sur toi...","Hm, pourquoi ne pas choisir une beauté pour toi-même? Je crains que nous n'ayons pas de garçons ici, hihi...")+"Bonjour, mon brave.","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("J'ai changé d'avis, excusez-moi.","En fait, ne vous en faites pas..."),"Je... pardon, je n'ai pas de questions, pour l'instant.","Tu as raison, c'est déjà la troisième fois. Pardonne-moi.","Peut-être la prochaine fois, Madame.",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
