// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat("Wszystkie plotki o "+GetCityName(npchar.city)+" do usług. Czego chciałbyś się dowiedzieć?","Rozmawialiśmy właśnie o tym. Musiałeś zapomnieć...","To już trzeci raz dzisiaj, gdy mówisz o jakimś pytaniu...","Powtarzasz to wszystko jak papuga...","blokada",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Wiesz, "+NPChar.name+", może następnym razem.","Racja, zapomniałem z jakiegoś powodu...","Tak, to naprawdę już trzeci raz...","Tak...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			if (CheckAttribute(pchar, "questTemp.Guardoftruth") && pchar.questTemp.Guardoftruth == "portprince")
			{
				link.l1 = "Powiedz mi, czy galeon o nazwie 'Santa Margarita' zatrzymał się ostatnio w twojej kolonii? Może jako zdobycz korsarza?";
                link.l1.go = "guardoftruth";
			}
		break;
		
		case "guardoftruth":
			dialog.text = "Kumplu, rzadko kiedy ktoś zahacza o naszą kolonię z łupami, a galionu o takiej nazwie tu nie widzieliśmy. Hispaniola to dzika wyspa, a my jesteśmy małą kolonią. Jest tu cicho. Handlujemy z bukanierami w górach skórami bydlęcymi i suszoną wołowiną. Kapersi zazwyczaj tu się nie kręcą, nie mamy tu burdeli, a Hiszpanie są blisko. Szukaj swojego galionu gdzie indziej.";
			link.l1 = "Rozumiem. Dzięki za radę!";
			link.l1.go = "exit";
			AddQuestRecord("Guardoftruth", "7");
			pchar.questTemp.Guardoftruth = "tortuga";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
