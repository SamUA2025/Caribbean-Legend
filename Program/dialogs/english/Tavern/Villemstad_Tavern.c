// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat("All the rumors of "+ GetCityName(npchar.city) +" at your service. What would you like to find out?",
                          "We were just talking about that. You must have forgotten...", "This is the third time today you're talking about some question...",
                          "You're repeating all the same like a parrot...", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("You know, " + NPChar.name + ", maybe next time.", "Right, I've forgotten for some reason...",
                      "Yes, it really is the third time...", "Yup...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			//работорговец
			if (pchar.questTemp.Slavetrader == "EscapeSlave_Villemstad")
            {
                link.l1 = "I heard that there was a serious mess on the island... Slaves?";
                link.l1.go = "EscapeSlaveVillemstad_T1";
            }
			//Португалец
			if (CheckAttribute(pchar, "questTemp.Portugal") && pchar.questTemp.Portugal == "SeekPortVillemstad")
            {
                link.l1 = "I've heard that wretched scoundrel Bart the Portuguese has finally met justice! Is he in prison? When will his execution be, do you know? I want to come watch, I have a bone to pick with that scum...";
                link.l1.go = "Portugal";
            }
 		break;

		//работорговец
		case "EscapeSlaveVillemstad_T1":
			dialog.text = "Aye, there ain't ever been such a mess... More than a thousand negros have revolted. Two plantations have been burnt down to the ground and each of their masters were murdered. The commandant is worried that the slaves would come attack the city, so he has enforced martial law. And it all started because of two negros, a buck named Tamango and a doe named Isauri...";
			link.l1 = "Sounds quite dramatic. Tell me the whole story, who are these negros?";
			link.l1.go = "EscapeSlaveVillemstad_T2";
		break;
		
		case "EscapeSlaveVillemstad_T2":
				dialog.text = "Tamango and Izaura - slaves at Blenheim plantation, the first plantation burnt. These two negros loved each other. But a son of planter, Leonsio, arrived from Europe and took a fancy to the doe. He wanted to make Izaura his personal concubine. The black buck Tamango didn't cotton to the idea and neither did Izaura, she really loved the black devil\nThat Tamango was some sort of chief or something back in Africa... A giant buck - blacker than sin and deadly with an axe, the other negros feared and respected him. So this negro leads the other slaves in an uprising. They attacked the guards at night, killed every white outside the big house, the mulattos too\nThen Izaura opened the doors of the plantation and the savage apes murdered everyone inside. Blenburg was burnt to the ground. Then the slaves fled into the jungles and disappeared...";
			link.l1 = "Well, how's that for a story, sounds like a plot for a novel! A proper slave revolt, just like Ancient Rome. How did you find all that out, by the way?";
			link.l1.go = "EscapeSlaveVillemstad_T3";
		break;
		
		case "EscapeSlaveVillemstad_T3":
			dialog.text = "Rumors, mynheer, the earth is teeming with them. Rum loosens tongues, all you have to do is listen...";
			link.l1 = "And how did that all end? Have they find those negros?";
			link.l1.go = "EscapeSlaveVillemstad_T4";
		break;
		
		case "EscapeSlaveVillemstad_T4":
				dialog.text = "Ha, not a chance! Until the reinforcements finally managed to arrive, nobody took a step into the jungle. Then a Company warship arrived with a unit of soldiers and they searched the island. Didn't find black hide or kinky hair of a single loose negro.";
			link.l1 = "Well, how about that! A thousand darkies all just vanished into thin air?";
			link.l1.go = "EscapeSlaveVillemstad_T5";
		break;
		
		case "EscapeSlaveVillemstad_T5":
			dialog.text = "Actually into the water.";
			link.l1 = "What are you talking about, " + npchar.name + "? You know as well as I do that negros can't swim.";
			link.l1.go = "EscapeSlaveVillemstad_T6";
		break;
		
		case "EscapeSlaveVillemstad_T6":
			dialog.text = "He-he... oh no those blacks aren't shark bait that quickly. The thing is the next night after the mutiny a barque went missing from the docks. You can paint me black and I'll play the banjo and dance for you if it wasn't at the hands of that buck Tamango and his negros! That's why they're not on the island anymore.";
			link.l1 = "Ha, now I've heard everything, " + npchar.name + ". You expecting me to believe that a bunch of half-wild negros can handle sails and navigate? I'd sooner expect a ship of monkeys to come careening in from Guinea.";
			link.l1.go = "EscapeSlaveVillemstad_T7";
		break;
		
		case "EscapeSlaveVillemstad_T7":
			dialog.text = "I didn't believe it either, mynheer but the proof is in the missing ship. Maybe one of those negros used to serve as a steward on a ship and picked up some sailing technique. Maybe they used black magic, who knows! Stop by and visit me again, " + pchar.name + ", I'll get some more stories for you next time.";
			link.l1 = "Thanks! Well, it's time for me to get going.";
			link.l1.go = "exit";
			AddQuestRecord("Slavetrader", "22_2");
			pchar.questTemp.Slavetrader = "EscapeSlaveVillemstad_P";
		break;						

		case "Portugal":
			dialog.text = "Yes, that's correct. They caught that pirate. And can you believe how? He was picked up on a cockboat alone in the middle of the sea. He didn't even make a peep before he was sent into the hold for the rats. It is really amusing, you know, such a dangerous pirate got caught like such a lubber!";
			link.l1 = "And why was he all alone in the sea?";
			link.l1.go = "Portugal_1";
		break;
		
		case "Portugal_1":
			dialog.text = "He probably decided to part ways with his lackies, no doubt... They couldn't split the plunder fairly. Now he's in the hands of the Company itself and those guys don't take well to jokes. They say he took possession of one of the Company's boats with something valuable. Apparently, it's just because they want to squeeze some information out of him, he's still not dangling on a noose already.";
			link.l1 = "So, when will his execution be, do you know?";
			link.l1.go = "Portugal_2";
		break;
		
		case "Portugal_2":
			dialog.text = "Nobody knows. I think once the Company finds out what it wants, they'll fasten a hemp tie around his neck. The Portuguese is in the prison right now under a reliable guard\nRecently they brought his boatswain over here as well. His story was even more surprising, he turned himself in to the Dutch in Philipsburg. So, they've set him up in a cell right next to his ex-captain, so they are neighbors now, he-he...";
			link.l1 = "Miracles do happen! All right, I'll be watching out for the news. I don't want to miss that hanging. Bye, "+npchar.name+"!";
			link.l1.go = "Portugal_3";
		break;
		
		case "Portugal_3":
			DialogExit();
			pchar.questTemp.Portugal = "PortugalInPrison";
			AddQuestRecord("Portugal", "32");
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
