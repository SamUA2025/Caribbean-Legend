// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    ref sld;
	switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("What kind of questions, "+ GetSexPhrase("young man","young lady") +"?", "What is it you need, "+ GetSexPhrase("handsome","pretty one") +"? Ask away."), "Questions again?", "Tee-hee, if it's all the same to you - questions...",
                          ""+ GetSexPhrase("Hm, why don't you pick a beauty for yourself? I am starting to get suspicions about you...","Hm, why don't you pick a beauty for yourself? We don't have boys here I'm afraid, tee-hee...") +"", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("I've changed my mind, excuse me.", "Actually, nevermind..."), "I... apologies, I have no questions, for now.",
                      "You're right, it's the third time already. Pardon me.", "Maybe next time, Madam.", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
