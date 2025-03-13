// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Quel genre de questions, "+GetSexPhrase("mon fils","ma fille")+"?","Demandez, je vous écoute..."),"Je t'écoute, parle maintenant, "+GetSexPhrase("mon fils","ma fille")+"...","Pour la troisième fois, "+GetSexPhrase("mon fils","mafille")+", demandez ce dont vous avez besoin.","Un ecclésiastique a beaucoup de travail et vous me distraisez, "+GetSexPhrase("mon fils","ma fille")+"... ","bloc",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("J'ai changé d'avis...","Pas pour le moment, padre..."),"Je n'ai rien à dire, mes excuses.","Je demanderai, mais plus tard. Pardonnez-moi, mon père.","Pardonnez-moi, saint père...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
