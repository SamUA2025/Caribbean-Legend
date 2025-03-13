// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Jakie masz pytania?","Jak mogę ci pomóc, "+GetAddress_Form(NPChar)+"?"),"Próbowałeś zadać mi pytanie niedawno, "+GetAddress_Form(NPChar)+"...","Przez cały ten dzień, to już trzeci raz, gdy mówisz o jakimś pytaniu...","Więcej pytań, jak mniemam?","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Zmieniam zdanie...","Nie mam teraz nic do powiedzenia."),"Umph, gdzież moja pamięć uleciała...","Tak, to naprawdę już trzeci raz...","Nie, jakie pytania?...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			//Jason, Сага, Тени прошлого
			if (CheckAttribute(PChar, "questTemp.Saga.Shadows") && pchar.questTemp.Saga.Shadows == "sentjons")
			{
				link.l1 = "Poszukuję Raymonda Bakera, byłego kata. Wiesz, czy żyje i gdzie mogę go znaleźć?";
				link.l1.go = "baker";
			}
			//Jason, суп из черепахи
			if (CheckAttribute(PChar, "questTemp.Terrapin") && pchar.questTemp.Terrapin == "baster" && !CheckAttribute(npchar, "quest.terrapin"))
			{
				link.l1 = "Szukam pana Jonesa. Czy możesz mi pomóc w moich poszukiwaniach, kumpel?";
				link.l1.go = "terrapin";
			}
			// Страж Истины
			if (CheckAttribute(pchar, "questTemp.Guardoftruth") && pchar.questTemp.Guardoftruth == "merdok")
			{
				link.l1 = "Słuchaj, czy do tego miasta zawitał jakiś alchemik, medyk? Jest Włochem, ma około trzydziestu lat, nazywa się Gino Gvineili. Słyszałeś coś o tym?";
				link.l1.go = "guardoftruth";
			}
		break;
		
		//Сага, Тени прошлого
		case "baker":
			dialog.text = "Nasz drogi grubas stał się bardziej popularny niż pułkownik Fox! Żyje, biedaczysko. Ale nie ma go teraz w mieście. Gdy Raymond dowiedział się, że poważni ludzie, tacy jak Ty, interesują się nim, pospieszył się, sprzedał swoją ruderę za bezcen i zniknął z wiatrem.";
			link.l1 = "Dokąd poniósł wiatr?";
			link.l1.go = "baker_1";
		break;
		
		case "baker_1":
			dialog.text = "Oh, kto wie. Poszedł służyć jako lekarz okrętowy na pierwszym statku, który się pojawił. Tyle że ten statek właśnie dziś wrócił, a nikt nie widział, żeby Baker wyszedł na ląd.";
			link.l1 = "Jak mogę znaleźć kapitana?";
			link.l1.go = "baker_2";
		break;
		
		case "baker_2":
			dialog.text = "Dlaczego myślisz, że musisz go szukać? Jestem pewien, że już jest pijany jak zwykle w swojej kajucie. Jego przeciekający wiadro nazywa się 'Nieśmiała Meggy'. Jaki kapitan, taka nazwa...";
			link.l1 = "Dzięki za pomoc, kumplu!";
			link.l1.go = "baker_3";
		break;
		
		case "baker_3":
			DialogExit();
			AddQuestRecord("Shadows", "2");
			pchar.questTemp.Saga.Shadows = "baldmaggy";
			pchar.quest.Saga_ShadowsMaggy.win_condition.l1 = "location";
			pchar.quest.Saga_ShadowsMaggy.win_condition.l1.location = "Antigua";
			pchar.quest.Saga_ShadowsMaggy.function = "Saga_SetBaldMaggy";
		break;
		
		//суп из черепахи
		case "terrapin":
			dialog.text = "Pan Jones? Żartujesz sobie ze mnie, kumplu. Wiesz, ilu cholernych Jonesów jest na tej wyspie? Musisz być bardziej precyzyjny.";
			link.l1 = "Ma dorosłą siostrę Molly. Mówią, że jest niesamowicie piękna.";
			link.l1.go = "terrapin_1";
		break;
		
		case "terrapin_1":
			dialog.text = "Nie. Nic takiego nie przychodzi mi do głowy. Przepraszam, kumplu...";
			link.l1 = "Dobrze, jeśli nie wiesz, to nie wiesz...";
			link.l1.go = "exit";
			npchar.quest.terrapin = "true";
		break;
		
		case "guardoftruth":
			dialog.text = "Nie, nie słyszałem. A w mieście mamy tylko jednego alchemika, aptekarza Johna Murdocka. Ma niezwykłe mikstury - leczą wszelkie dolegliwości.";
			link.l1 = "Czy myślisz, że sam warzy te mikstury?";
			link.l1.go = "guardoftruth_1";
		break;
		
		case "guardoftruth_1":
			dialog.text = "Dobre pytanie. Zadaję je sobie od czasu do czasu. John nie wygląda ani trochę na znawcę medycznych flakonów, ziół i proszków. Raczej przypomina byłego żołnierza, najemnika... to bliższe prawdy.";
			link.l1 = "No cóż, chyba ten człowiek jest zbyt wykwalifikowany...";
			link.l1.go = "guardoftruth_2";
		break;
		
		case "guardoftruth_2":
			dialog.text = "Może i tak, ale jedno wiem na pewno, ktoś mieszka na jego drugim piętrze. Okno jest stale zasłonięte. Nawet gdy John jest na dole, słychać brzęk szklanych fiolek i butelek oraz czuć zapach gotujących się ziół, a w nocy światło się nie gasi. Dlatego podejrzewam, że lokator tego pokoju to ten, kto przygotowuje lekarstwa Johna na sprzedaż.";
			link.l1 = "Hm. Interesujące spostrzeżenie. Dzięki, kumplu!";
			link.l1.go = "exit";
			pchar.questTemp.Guardoftruth = "merdok1";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
