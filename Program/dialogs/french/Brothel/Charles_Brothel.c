// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    ref sld;
	switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Quel genre de questions, "+GetSexPhrase("jeune homme","jeune demoiselle")+"?","Que désirez-vous, "+GetSexPhrase("beau","jolie demoiselle")+"Posez votre question."),"Encore des questions ?","Tee-hee, si cela vous convient - des questions...",""+GetSexPhrase("Hm, pourquoi ne choisis-tu pas une beauté pour toi-même ? Je commence à avoir des soupçons à ton sujet...","Hm, pourquoi ne pas choisir une beauté pour vous-même ? Nous n'avons pas de garçons ici, je le crains, hi-hi...")+"","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("J'ai changé d'avis, excusez-moi.","En fait, laisse tomber..."),"Je... m'excuse, je n'ai pas de questions, pour l'instant.","Tu as raison, c'est déjà la troisième fois. Pardonnez-moi.","Peut-être la prochaine fois, Madame.",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
