// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Jakie pytania, "+GetSexPhrase("mój synu","moja córko")+"?","Pytaj śmiało, słucham..."),"Słucham, mów teraz, "+GetSexPhrase("mój synu","moja córko")+"...","Po raz trzeci, "+GetSexPhrase("mój synu","moja córko")+"Proszę, pytaj o co potrzebujesz.","Duchowny ma od groma pracy, "+GetSexPhrase("mój synu","moja córko")+" a ty mnie ewidentnie rozpraszasz...","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Już nieważne...","Nie teraz, ojcze..."),"Nie mam nic do powiedzenia, przepraszam.","Zapytam, ale później. Wybacz mi, ojcze.","Niech mi ksiądz wybaczy...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			// Jason Долго и счастливо
			if (CheckAttribute(pchar, "questTemp.LongHappy") && pchar.questTemp.LongHappy == "choose" && !CheckAttribute(npchar, "quest.LongHappy"))
			{
				link.l1 = "Prosze księdza, szukam opata Benoita, mam do niego pilną sprawę. Możesz mi powiedzieć, gdzie go znajde?";
				link.l1.go = "LH_church";
			}
		break;
		
		// Jason Долго и счастливо
		case "LH_church":
			dialog.text = "Opat Benoit opuścił miasto w związku z sprawami kościelnymi z przedstawicielami hiszpańskiej misji katolickiej w Nowym Świecie. Nie znam żadnych szczegółów, ale opat Benoit jest nieobecny wystarczająco długo. Zakładam, że albo negocjacje się przedłużyły, albo doszło podczas drogi do czegoś okropnego. Wszyscy jesteśmy niespokojni, niestety jedyne co na tą chwile możemy, to się modlić i czekać na wieści.";
			link.l1 = "Nie można zakładać, że wszystko będzie dobrze. Prosze księdza, czy może mi ksiądz powiedzieć, dokąd dokładnie udał się opat Benoit? Muszę go znaleźć jak najszybciej.";
			link.l1.go = "LH_church_1";
		break;
		
		case "LH_church_1":
			dialog.text = "Obawiam się, że nie mogę, mój synu. O ile mi wiadomo, opat Benoit udał się na negocjacje z biskupem Nowej Hiszpanii i prelatem Inkwizycji, ojcem Vincento Palottim, ale nie określił, gdzie odbędzie się spotkanie.";
			link.l1 = "To powinno wystarczyć, Ojcze, dziękuję. Znam ojca Palottiego z moich poprzednich przygód... Rozejrzę się w Santiago.";
			link.l1.go = "LH_church_2";
		break;
		
		case "LH_church_2":
			DialogExit();
			npchar.quest.LongHappy = "true";
			LongHappy_GoToSantiago();
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
