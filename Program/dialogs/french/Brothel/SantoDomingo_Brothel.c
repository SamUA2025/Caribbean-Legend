// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    ref sld;
	switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Quel genre de questions, "+GetSexPhrase("jeune homme","jeune demoiselle")+" ?","Que désirez-vous, "+GetSexPhrase("bel étalon","jolie demoiselle")+" ? Demandez donc."),"Encore des questions ?","Hihi, si ça vous est égal - des questions...",""+GetSexPhrase("Hum, pourquoi vous ne choisissez pas une jolie fille ? Je commence à avoir des soupçons à votre sujet...","Hm, choisissez donc une fille par vous-même. Nous n'avons pas de garçons ici, j'en ai peur, hi-hi...")+"","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("J'ai changé d'avis, excusez-moi.","En fait, laissez tomber..."),"Je... m'excuse, je n'ai pas de questions, pour l'instant.","Vous avez raison, c'est déjà la troisième fois. Pardonnez-moi.","Peut-être la prochaine fois, Madame.",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
