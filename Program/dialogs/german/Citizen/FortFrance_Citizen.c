// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
	switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = RandPhraseSimple("Welche Art von Fragen?","Was willst du?");
			link.l1 = RandPhraseSimple("Ich habe es mir anders überlegt.","Ich habe jetzt nichts zu sagen.");
			link.l1.go = "exit";
			//Бремя гасконца
			if (CheckAttribute(pchar, "questTemp.Sharlie.Citcount") && !CheckAttribute(npchar, "quest.Sharlie"))
			{
				link.l1 = "Entschuldigen Sie, "+GetAddress_FormToNPC(NPChar)+"könnten Sie mir sagen, wo ich Michel de Monper finden kann? Ich habe gehört, er ist in dieser Stadt.";
				link.l1.go = "Sharlie";
			}
			if (CheckAttribute(pchar, "questTemp.Sharlie") && pchar.questTemp.Sharlie == "findskiper" && !CheckAttribute(npchar, "quest.Sharlie1"))
			{
				link.l1 = "Hör zu, "+GetAddress_FormToNPC(NPChar)+", ich möchte Sie etwas fragen... Ich suche einen Navigator für mein Schiff, kennen Sie jemanden?";
				link.l1.go = "Sharlie_1";
			}
			//Бремя гасконца
		break;
		
		case "info":
        // заменить на описание неких НПС, по квестам
			dialog.text = "Glaubst du, ich arbeite für den Geheimdienst von "+NationNameGenitive(sti(NPChar.nation))+"?";
			link.l1 = "Nun... nein. Lebewohl dann.";
			link.l1.go = "exit";
			link.l2 = "Noch eine andere Frage, dann?";
			link.l2.go = "new question";
		break;
		
		case "town":
        // заменить на описание как пройти, по квестам
			dialog.text = "Sehe ich aus wie das Untersuchungsbüro? Ich weiß es nicht, weiß nichts.";

            link.l1 = "Du bist so ein Wirrkopf! Verschwinde.";
			link.l1.go = "exit";
			link.l2 = "Hast du noch eine andere Frage?";
			link.l2.go = "new question";
		break;
		
		//--> Бремя гасконца
		case "Sharlie":
			if (sti(pchar.questTemp.Sharlie.Citcount) == 3)
			{
				dialog.text = "Hmm... Ich vermute, du bist erst kürzlich hier angekommen, da du so furchtlos solche Fragen stellst... Ich rate dir aufzuhören, wenn du keine Schwierigkeiten willst. Sprich mit dem Abt, er kann dir vielleicht 'zur Besinnung verhelfen'. Du kannst ihn in der Kirche finden.";
				link.l1 = "Ich sehe...";
				link.l1.go = "exit";
				AddDialogExitQuest("Sharlie_SetBenua");
				DelLandQuestMark(characterFromId("FortFrance_Mayor"));
			}
			else
			{
				dialog.text = LinkRandPhrase("Nein, ich habe noch nie von ihm gehört.","Ich kann Ihnen nicht helfen, ich habe Arbeit zu erledigen.","Wer? Sagt mir nichts, nein. Ich gehe dann mal.");
				link.l1 = "Ich verstehe... Ich werde dann meinen Weg fortsetzen. ";
				link.l1.go = "exit";
				npchar.quest.Sharlie = "true";
			}
		break;
		
		case "Sharlie_1":
			dialog.text = LinkRandPhrase("Nein, ich kenne keine Navigatorinnen.","Ich habe Arbeit zu erledigen und nein, frag jemand anderen...","Leider kann ich Ihnen nicht helfen, ich kenne niemanden.");
			link.l1 = "Ich verstehe. Dann werde ich woanders fragen.";
			link.l1.go = "exit";
			npchar.quest.Sharlie1 = "true";
			npchar.dialog.currentnode = "first time";
		break;
		//<-- Бремя Гасконца
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
