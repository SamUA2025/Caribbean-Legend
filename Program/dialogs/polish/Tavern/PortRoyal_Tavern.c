// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat("Wszystkie plotki o "+GetCityName(npchar.city)+" do usług. Czego chciałbyś się dowiedzieć?"," Właśnie o tym rozmawialiśmy. Musiałeś zapomnieć...","To już trzeci raz dzisiaj, kiedy mówisz o jakimś pytaniu...","Powtarzasz wszystko jak papuga...","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Wiesz, "+NPChar.name+"Może następnym razem.","Racja, zapomniałem z jakiegoś powodu...","Tak, to naprawdę już trzeci raz...","Tak...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			if (pchar.questTemp.Slavetrader == "FindRatJamaica")
            {
                link.l1 = "Czy wiesz, gdzie mogę znaleźć François Gontiera?";
                link.l1.go = "Jamaica_ratP_1";
            }
			// Страж Истины
			if (CheckAttribute(pchar, "questTemp.Guardoftruth") && pchar.questTemp.Guardoftruth == "merdok" && !CheckAttribute(npchar, "quest.jino"))
			{
				link.l1 = "Słuchaj, czy przybył tu do miasta jakiś alchemik, lekarz? Jest Włochem, ma około trzydziestu lat, nazywa się Gino Gvineili. Słyszałeś coś o tym?";
				link.l1.go = "guardoftruth";
			}
		break;

		case "Jamaica_ratP_1":
			dialog.text = NPCStringReactionRepeat("Nie mam najmniejszego pojęcia. Nigdy wcześniej nie słyszałem tego imienia.","Już o to pytałeś, a ja ci odpowiedziałem.","Powiedziałem ci, już pytałeś o tego Gontiera.","Słuchaj, odejdź i przestań mnie dręczyć! Czy ty całkiem straciłeś rozum?","block",0,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Cóż, w takim razie będę szukać dalej.","Hm, chyba tak...","Tak, właśnie o to pytałem...","Przepraszam, "+npchar.name+"...",npchar,Dialog.CurrentNode);
		break;
		
		case "guardoftruth":
			dialog.text = LinkRandPhrase("Nie, nie znam. Mamy zielarzy i lekarzy, ale żaden nie nosi takiego imienia.","Pierwszy raz słyszę takie dziwaczne imię. Nie, nigdy nie mieliśmy wizyty od człowieka, o którym mówisz.","Nie mamy tu żadnych alchemików. Mamy lekarzy, ale żaden z nich nie ma tak dziwnego imienia.");
			link.l1 = "Widzę. To szkoda. Będę kontynuował poszukiwania!";
			link.l1.go = "exit";
			npchar.quest.jino = "true";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
