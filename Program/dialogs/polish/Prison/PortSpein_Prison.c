// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
 	switch(Dialog.CurrentNode)
	{
        case "quests":
            dialog.text = "Mów, słucham";
			link.l1 = "Pomyliłem się. Żegnaj.";
			link.l1.go = "Exit";
			//Цена чахотки
			if (!CheckAttribute(npchar, "quest.Consumption") && CheckAttribute(pchar, "questTemp.Consumption") && pchar.questTemp.Consumption == "begin")
			{
				link.l1 = "Doszły mnie słuchy, że macie tu epidemię, czyż nie?";
				link.l1.go = "Consumption";
			}
		break;
		
		//--> Цена чахотки
		case "Consumption":
			dialog.text = "Masz rację, więc unikaj odwiedzania lochów bez poważnego powodu. Dlaczego cię to interesuje?";
			link.l1 = "Tak tylko z ciekawości. Więc jeśli moi chłopcy za bardzo się upiją, narobią za dużo hałasu i skończą tutaj, powinienem przygotować trochę żółtego płótna?";
			link.l1.go = "Consumption_1";
		break;
		
		case "Consumption_1":
			dialog.text = "Och, seniorze, nie łapię dowcipu, jeśli sobie żartowałeś. Lochy są wilgotne i zimne, a ty znasz klimat. Suchoty to częsty gość w tych lochach. Muszę nawet płacić moim chłopakom za dostarczanie jedzenia do cel. Patrolowanie tam jest uważane za to samo co katorga.";
			link.l1 = "Przepraszam, chciałem tylko wiedzieć, jak poważna jest ta sprawa?";
			link.l1.go = "Consumption_2";
		break;
		
		case "Consumption_2":
			dialog.text = "Za poważnie. Nawet nie mamy tu lekarza, też zmarł na cholerne suchoty. Teraz tylko medyk z lokalnego garnizonu bada więźniów raz na tydzień. Ale kogo obchodzą ci włóczędzy i przestępcy?\nWiększość ludzi uważa, że całkowicie zasłużyli na taki los i trudno z tym dyskutować.";
			link.l1 = "Moja wiedza na temat medycyny jest skromna, ale o ile mi wiadomo, suchoty są niebezpieczne i śmiertelne, jednak nie zabijają ludzi w ciągu kilku dni, jak to jest tutaj. Czyż ofiary nie powinny cierpieć miesiącami, a nawet latami?";
			link.l1.go = "Consumption_3";
		break;
		
		case "Consumption_3":
			dialog.text = "Jak właśnie wspomniałeś, nie jesteś medykiem, więc mówienie o cechach choroby mogłoby być po prostu... zmyśloną bajką. Powtórzyłem tylko, co nasz lekarz mówił, zanim choroba zabrała i jego. Więc nie rozumiem twojej ciekawości i cynicznego zachowania. Ludzie tu umierają!";
			link.l1 = "Czyż nie powiedziałeś właśnie, że na to zasłużyli?";
			link.l1.go = "Consumption_4";
		break;
		
		case "Consumption_4":
			dialog.text = "Wystarczy, seniorze! Wierzę, że mamy inne sprawy na głowie niż współzawodnictwo w dowcipie. Drzwi są tuż za tobą.";
			link.l1 = " Dobrze, wybacz moją nietaktowność, już odchodzę.";
			link.l1.go = "Consumption_5";
		break;
		
		case "Consumption_5":
			DialogExit();
			npchar.quest.Consumption = "true";
			pchar.questTemp.Consumption.Commandant = "true";
			AddQuestRecord("Consumption", "3");
			pchar.quest.Consumption.win_condition.l1 = "location";
			pchar.quest.Consumption.win_condition.l1.location = "PortSpein_houseF2";
			pchar.quest.Consumption.function = "Consumption_CommandantHouse";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
