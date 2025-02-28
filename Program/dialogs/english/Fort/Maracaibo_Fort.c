// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("What do you think about our fort? Looking good, yes? And the garrison is not worse yet, ha...", "The fort soldier's life is quite dull... Guarding and patrolling, sleeping and resting and then the same all over again. But it's different in town... What do you want, " + GetAddress_Form(NPChar) + "?"), "Bothering a soldier with stupid questions is not welcome, " + GetAddress_Form(NPChar) + "...", "It's the third time you're trying to ask me today...",
                          "It's not easy being a soldier and yet here you are again"+ GetSexPhrase(", jerk,  "," ") +" trying to piss me off. Be careful or you will end up in a basement of the fort...", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("I've changed my mind, sorry for bothering you.", "I've got nothing to say, apologies."), "You're right, i apologize.",
                      "You're right, it's the third time already. Pardon me.", "Sorry, it's nothing.", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
