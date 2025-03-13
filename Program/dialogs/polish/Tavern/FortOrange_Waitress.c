// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Pytania, "+GetAddress_Form(NPChar)+"?","Jak mogę ci pomóc, "+GetAddress_Form(NPChar)+"?"),"Got it, I'll only provide the translation in quotes. Please give me the text to translate."+GetSexPhrase("Hm, co to za pomysł, "+GetAddress_Form(NPChar)+"? ","Znowu te dziwne pytania? Skarbie, idź się napić rumu czy coś...")+" ","Przez cały ten dzień, to już trzeci raz, kiedy mówisz o jakimś pytaniu..."+GetSexPhrase(" Czy to jakieś oznaki uwagi?"," ")+" ","Więcej pytań, jak przypuszczam, "+GetAddress_Form(NPChar)+"?","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Zmieniam zdanie","Nie mam teraz nic do powiedzenia."),"Nie, nie piękna...","Nie ma mowy, droga...","Nie, jakie pytania?...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			if (pchar.questTemp.Slavetrader == "FindRatJamaica_W")
            {
                link.l1 = "Słuchaj kobieto, mówią, że byłaś blisko z moim starym druhom Francois Gontier. Naprawdę blisko...";
                link.l1.go = "Jamaica_ratW_1";
            }
			
			if (pchar.questTemp.Slavetrader == "FindRatJamaica_WP")
            {
				if (CheckCharacterItem(pchar, "jewelry43"))
				{
					link.l1 = "Przyniosłem twój naszyjnik z klejnotami. Proszę bardzo. Boże, chroń mnie od chciwych kobiet takich jak ty w przyszłości.";
					link.l1.go = "Jamaica_ratW_5";
				}
				else
				{
					link.l1 = "Nic w tej chwili. Szukam twojego naszyjnika.";
					link.l1.go = "exit";
				}
            }
			
		break;
		
		case "Jamaica_ratW_1":
            dialog.text = "Tak, byliśmy. I co z tego? Nie jestem mężatką i spędzam czas z kim chcę. Francois jest bardzo szanowanym żeglarzem, nie jak nasi miejscowi rybacy i rolnicy. On jest taki... Och! I dał mi takie ładne prezenty!";
            link.l1 = "Dobrze, wystarczy! Wiem, jakie cechy posiada mój towarzysz, nie musisz ich wymieniać. Nie obchodzi mnie, co się wydarzyło między wami. Możecie się nawet pobrać, nie obchodzi mnie to. Muszę go natychmiast znaleźć, rozumiesz? Czy wiesz, dokąd się udał?";
            link.l1.go = "Jamaica_ratW_2";
        break;
		
		case "Jamaica_ratW_2":
            dialog.text = "Hee hee... Jesteś jego kamratem, a nie wiesz, dokąd się udał. To zabawne!";
            link.l1 = "To nie jest śmieszne, kobieto. Umówiliśmy się na spotkanie na Jamajce, a potem mieliśmy razem wypłynąć... jeśli rozumiesz, co mam na myśli. Sam nie dam rady, a on odpłynął Bóg wie dokąd!";
            link.l1.go = "Jamaica_ratW_3";
        break;
		
		case "Jamaica_ratW_3":
            dialog.text = "Widzę. Cóż, jeśli taka zyskowna podróż stoi przed tobą otworem, biorąc pod uwagę, że ty i Francois jesteście przyjaciółmi... Powiem ci, dokąd się udał, ale za małą nagrodą.";
            link.l1 = "Aj, znam zasady. Ile chcesz?";
            link.l1.go = "Jamaica_ratW_4";
        break;
		
		case "Jamaica_ratW_4":
            dialog.text = "O, jakże przekupny! Nie potrzebuję żadnych pieniędzy. Nie, chcę czegoś wyjątkowego. Francois obiecał dać mi piękny naszyjnik z klejnotami. Już się nim chwaliłam przed znajomymi, a on od razu zniknął... Przynieś mi wisiorek, a powiem ci, dokąd się udał, he-he!";
            link.l1 = "Ty bezczelna ladacznico! Wy, holenderskie dziewki, jesteście tak chciwe, jak tylko można! Dobrze, dostaniesz swój naszyjnik.";
            link.l1.go = "exit";
			AddQuestRecord("Slavetrader", "21_5");
			pchar.questTemp.Slavetrader = "FindRatJamaica_WP";
        break;
		
		case "Jamaica_ratW_5":
            dialog.text = "Ach, to piękne! Teraz moi przyjaciele zzielenieją z zazdrości!";
            link.l1 = "Przekaż im moje kondolencje. A teraz gadaj. Dokąd wyruszył Francois?";
            link.l1.go = "Jamaica_ratW_6";
			RemoveItems(PChar, "jewelry43", 1);
        break;
		
		case "Jamaica_ratW_6":
            dialog.text = "Tak, oczywiście, sir. Francois odpłynął w kierunku Kuby, do Hawany.";
            link.l1 = "Dzięki za tę drogą radę, dziewko. To wszystko, czego chciałem.";
            link.l1.go = "exit";
			AddQuestRecord("Slavetrader", "21_6");
			pchar.questTemp.Slavetrader = "FindRatHavana";
        break;
		
		
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
