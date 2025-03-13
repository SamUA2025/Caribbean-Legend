// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
            dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Quel genre de questions, "+GetSexPhrase("mon fils","ma fille")+"?","Demandez, je vous écoute..."),"Je vous écoute, parlez maintenant, "+GetSexPhrase("mon fils","ma fille")+"...","Pour la troisième fois, "+GetSexPhrase("mon fils","ma fille")+", demande ce dont tu as besoin.","Un ecclésiastique a beaucoup de travail et vous me distraitez, "+GetSexPhrase("mon fils","ma fille")+"...","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("J'ai changé d'avis...","Pas en ce moment, père..."),"Je n'ai rien à dire, je vous prie de m'excuser.","Je demanderai, mais plus tard. Pardonnez-moi, mon père.","Excusez-moi, saint père...",npchar,Dialog.CurrentNode);
		    link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
