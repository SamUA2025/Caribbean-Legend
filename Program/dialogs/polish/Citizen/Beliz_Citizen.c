// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
            dialog.text = RandPhraseSimple("Jakie pytania?","Czego chcesz?");
			link.l1 = RandPhraseSimple("Zmieniam zdanie.","Nie mam teraz nic do powiedzenia.");
		    link.l1.go = "exit";
			// Rebbebion, квест "Путеводная звезда" ==>
			if (CheckAttribute(pchar, "questTemp.Beliz.AskForLatterAndSotta") && !CheckAttribute(npchar, "questTemp.Sotta") && !CheckAttribute(npchar, "questTemp.Lutter"))
			{
				if (rand(1) == 0)
				{
					link.l1 = "Czy przypadkiem nie natknąłeś się na kapitana Edgardo Sottę? Możesz nam o nim coś opowiedzieć? Wydaje się być człowiekiem wartym poznania.";
					link.l1.go = "Sotta1";
					link.l2 = "Czy nie idziesz zobaczyć egzekucji Papli?";
					link.l2.go = "Lutter1";
				}
				else
				{
					link.l1 = "Powiedz mi, czy widziałeś bohatera dnia, kapitana Edgardo Sottę? Niestety, przegapiłem go. Jaki on jest? Nie mogę uwierzyć, że kupiec złapał niesławnego Gadający Wicher Matta!";
					link.l1.go = "Sotta1_1";
					link.l2 = "Widzę, że całe miasto świętuje pojmanie Luttera, nawet ci, którzy nigdy nie chodzą na morze."link.l2.go ="Lutter1_1";
				}
			}
			// <== квест "Путеводная звезда"
		break;
		
		case "info":
        // заменить на описание неких НПС, по квестам
			dialog.text = "Myślisz, że pracuję dla tajnej służby "+NationNameGenitive(sti(NPChar.nation))+"?";
			link.l1 = "Cóż... nie. Żegnaj zatem.";
			link.l1.go = "exit";
			link.l2 = "Jakieś inne pytanie?";
			link.l2.go = "new question";
		break;
		
		case "town":
        // заменить на описание как пройти, по квестам
			dialog.text = "Czy wyglądam jak biuro śledcze? Nie wiem, nie mam pojęcia.";

            link.l1 = "Jesteś takim bałaganiarzem! Precz.";
			link.l1.go = "exit";
			link.l2 = "Jakieś inne pytanie, zatem?";
			link.l2.go = "new question";
		break;
		
		// Квест "Путеводная звезда" ==>
		case "Sotta1":
			dialog.text = "Nie rozmawiałem z nim, ale widziałem jego statek - ciężki galeon. Niebezpiecznie jest żeglować samotnie po tych wodach, ale Sotta radzi sobie bez eskorty.";
			link.l1 = "Pewnie goni za każdym złotym dukatem i tnie koszty, gdzie tylko się da. Cóż, nie zatrzymuję cię. Dzień dobry.";
			link.l1.go = "Exit";
			
			npchar.questTemp.Sotta = true;
			pchar.questTemp.PZ_BelizAskCitizens = sti(pchar.questTemp.PZ_BelizAskCitizens) + 1;
			AddDialogExitQuest("PZ_LongwayBelizDialog");
		break;
		
		case "Sotta1_1":
			dialog.text = "Aye, trudno w to uwierzyć! Ale nie wierz we wszystko, co słyszysz, panie. Widziałem go, tak jasno, jak widzę cię teraz. Dobrze, że złapał Luttera, ale po co ta cała kupiecka maskarada? Zachowuje się jak żołnierz. Zawsze mogę to poznać - krewny mój służył przez lata.";
			link.l1 = "Interesujące. Cóż, każdy ma swoje tajemnice. Lepiej już pójdę. Dzięki za wgląd.";
			link.l1.go = "Exit";
			
			npchar.questTemp.Sotta = true;
			pchar.questTemp.PZ_BelizAskCitizens = sti(pchar.questTemp.PZ_BelizAskCitizens) + 1;
			AddDialogExitQuest("PZ_LongwayBelizDialog");
		break;
		
		case "Lutter1":
			dialog.text = "Widziałem już tego człowieka. Trudno uwierzyć, że to ten sam pirat, który przez lata terroryzował naszych kupców. Jak on w ogóle dostał własne dowództwo? Widziałem żołnierzy, którzy go eskortowali - krzyczących, płaczących, śmiejących się. Szaleniec.";
			link.l1 = "Może porażka i rzeczywistość jego nieuchronnej śmierci były dla niego zbyt wielkim ciężarem. Ale to nie ma znaczenia. Żegnaj!";
			link.l1.go = "Exit";
			
			npchar.questTemp.Lutter = true;
			pchar.questTemp.PZ_BelizAskCitizens = sti(pchar.questTemp.PZ_BelizAskCitizens) + 1;
			AddDialogExitQuest("PZ_LongwayBelizDialog");
		break;
		
		case "Lutter1_1":
			dialog.text = "Tak, i ja też świętuję - wielu moich rodaków zginęło z jego rąk. Nieszczęśnicy stracili ojca, brata, syna - rozumiesz, co mam na myśli. Ta barbarzyństwo trwało zbyt długo! Matt musiał być jednym z najszczęśliwszych piratów ostatnich lat, jeśli mnie pytasz.";
			link.l1 = "Prędzej czy później szczęście zawsze się kończy. Do zobaczenia.";
			link.l1.go = "Exit";
			
			npchar.questTemp.Lutter = true;
			pchar.questTemp.PZ_BelizAskCitizens = sti(pchar.questTemp.PZ_BelizAskCitizens) + 1;
			AddDialogExitQuest("PZ_LongwayBelizDialog");
		break;
		// <== Квест "Путеводная звезда"
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
