// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    ref sld;
	switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Quel genre de questions, "+GetSexPhrase("jeune homme","jeune demoiselle")+"?","Que désirez-vous, "+GetSexPhrase("beau","jolie créature")+"Pose ta question."),"Des questions à nouveau ?","Hi-hi, si cela vous convient - des questions...","Bonjour, mon ami."+GetSexPhrase("Hm, pourquoi ne choisis-tu pas une beauté pour toi-même ? Je commence à avoir des soupçons à ton sujet...","Hm, pourquoi ne pas choisir une beauté pour vous-même ? Nous n'avons pas de garçons ici, j'en ai bien peur, hihihi...")+"Bonjour, ami.","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("J'ai changé d'avis, excusez-moi.","En fait, peu importe..."),"Je... mes excuses, je n'ai pas de questions, pour l'instant.","Vous avez raison, c'est déjà la troisième fois. Pardonnez-moi.","Peut-être la prochaine fois, Madame.",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
