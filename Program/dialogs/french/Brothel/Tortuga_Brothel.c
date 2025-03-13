// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    ref sld;
	switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Quel genre de questions, "+GetSexPhrase("jeune homme","jeune demoiselle")+"?","Que désirez-vous, "+GetSexPhrase("beau","belle demoiselle")+"Posez vos questions."),"Encore des questions ?","Hi-hi, si cela ne te dérange pas - des questions...","Bonjour, mon ami."+GetSexPhrase("Hm, pourquoi ne te choisis-tu pas une beauté pour toi-même ? Je commence à avoir des soupçons à ton sujet...","Hm, pourquoi ne pas choisir une beauté pour vous-même ? Nous n'avons pas de garçons ici, j'en ai bien peur, hi-hi...")+"","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("J'ai changé d'avis, excusez-moi.","En fait, peu importe..."),"Je... pardonnez-moi, je n'ai pas de questions, pour le moment.","Vous avez raison, c'est déjà la troisième fois. Pardonnez-moi.","Peut-être la prochaine fois, Madame.",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
