void ProcessDialogEvent()
{
	ref NPChar, TempChar, sld;
	aref Link, Diag;
	
	int i, iTemp;
	string sTemp, sTemp1;
	string sGroup;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);

	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;

		case "First time":
			chrDisableReloadToLocation = false;
			//Lai_SetPlayerType(pchar);
			
			dialog.text = GetFullName(PChar)+"! "+"Śledziliśmy cię już od dłuższego czasu, i w końcu jesteś nasz.";
			Link.l1 = "Kim jesteś i czego ode mnie chcesz?";
			Link.l1.go = "meeting"; 
			
			PChar.GenQuest.HunterStart = true;
		break;

		case "meeting":
			dialog.text = XI_ConvertString(Nations[sti(NPChar.nation)].Name)+" postawił przyzwoitą nagrodę za twoją głowę, musimy cię dostarczyć do dowolnej z jego kolonii i dostaniemy zapłatę, bez względu na to, czy jesteś martwy, czy żywy.";
			Link.l1 = "Słuchaj, zapłacę ci, jeśli mnie zostawisz w spokoju.";
			Link.l1.go = "Cost_Head"; 
            // boal 08.04.04 -->
            if (GetSummonSkillFromNameToOld(PChar, SKILL_SNEAK) > 2 || bBettaTestMode)
            {
    			TempChar = characterFromID("Bug Fixer");
    			SetRandomNameToCharacter(TempChar);
    			Link.l2 = ""+GetSexPhrase("Przepraszam, ale chyba się pomyliłeś. Ja jestem "+GetFullName(TempChar)+" - dobrze znany kupiec na tych ziemiach.","Przepraszam, ale musisz się mylić. Jestem tylko prostą dziewczyną, a mój ojciec to "+GetFullName(TempChar)+" - dobrze znany kupiec na tych ziemiach.")+".";
    			Link.l2.go = "lier";
			}
            Link.l3 = "Dobrze, możesz spróbować swojego szczęścia, jeśli tak chcesz.";
			Link.l3.go = "battle";
		break;
        
        case "lier":
            if (GetSummonSkillFromName(pchar, SKILL_SNEAK) > rand(150) || bBettaTestMode)
            {
                dialog.text = "Och! Naprawdę możemy się mylić. Proszę, wybacz nam, "+GetAddress_Form(NPChar)+".";
                Link.l1 = "Dzieje się, nie martw się tym...";
                Link.l1.go = "lier_2";
                AddCharacterExpToSkill(pchar, SKILL_SNEAK, 100);
            }
            else
            {
                dialog.text = "Myslę, że kłamiesz!";
                Link.l1 = "Słuchaj, zapłacę ci, jeśli zostawisz mnie w spokoju.";
			    Link.l1.go = "Cost_Head";
			    Link.l2 = "Dobrze, możesz spróbować swojego szczęścia, jeśli tak chcesz.";
			    Link.l2.go = "battle";
			    AddCharacterExpToSkill(pchar, SKILL_SNEAK, 50);
            }
            
        break;
        
        case "lier_2":
            AddDialogExitQuest("GoAway_Hunters_Land");
            DialogExit();
        break;
        // boal <--
        
        case "battle":
            AddDialogExitQuest("Battle_Hunters_Land");    // BOAL Весь код я перенес сюда по всем нациям, просто не переименовал
            DialogExit();
        break;

        case "Cost_Head2":
            AddMoneyToCharacter(pchar, -sti(PChar.HunterCost));

            AddDialogExitQuest("GoAway_Hunters_Land"); 
            DialogExit();
        break;

        case "Cost_Head":
			dialog.text = "Myslę, że "+PChar.HunterCost+" pesos będzie nam pasować.";
            if(makeint(Pchar.money) < sti(PChar.HunterCost))
            {
                Link.l1 = "Ale ja nie mam takich pieniędzy.";
                Link.l1.go = "NoMoney";
            }else{
                Link.l1 = "Oto twoje pieniądze, weź je i znikaj.";
                Link.l1.go = "Cost_Head2";
                Link.l2 = "Dając taką sumę łotrzykom jak wy... chyba wolałbym was wszystkich tu zaraz pociąć!";
                Link.l2.go = "battle";
            }
		break;

        case "NoMoney":
			dialog.text = "W takim razie nasza rozmowa jest zakończona!";
			Link.l1 = "Nigdy mnie nie dostaniesz żywcem.";
			Link.l1.go = "battle"; 
		break;
		
		case "TreasureHunter":
			dialog.text = "Zaczekaj, "+GetSexPhrase("kumpel","dziewczyno")+"... Myślę, że masz coś interesującego przy sobie. Przyjaciele powinni dzielić się znalezionymi skarbami, nie sądzisz?";
            Link.l1 = "Słuchaj, zapłacę ci, jeśli zostawisz mnie w spokoju.";
			Link.l1.go = "Cost_Head";
            // boal 08.04.04 -->
            if (GetSummonSkillFromNameToOld(PChar, SKILL_SNEAK) > 3)
            {
    			TempChar = characterFromID("Bug Fixer");
    			SetRandomNameToCharacter(TempChar);
    			Link.l2 = ""+GetSexPhrase("Przepraszam, ale chyba się mylisz. Jestem "+GetFullName(TempChar)+"- dobrze znany mieszkaniec tych ziem, ale na pewno nie poszukiwacz skarbów.","Przepraszam, ale musisz się mylić. Jestem tylko prostą dziewczyną, a nie poszukiwaczką skarbów. A mój ojciec to "+GetFullName(TempChar)+" - dobrze znany obywatel na tych ziemiach")+"!";
    			Link.l2.go = "TreasureHunterLier";
			}
            Link.l3 = "Cóż, wygląda na to, że nadszedł czas, aby wasze głowy rozstały się z waszymi ciałami.";
			Link.l3.go = "battle";
		break;
		
		case "TreasureHunterLier":
            if (GetSummonSkillFromName(pchar, SKILL_SNEAK) > rand(150))
            {
                dialog.text = "Och! Naprawdę możemy się mylić, proszę nam wybaczyć, "+GetAddress_Form(NPChar)+".";
                Link.l1 = "Dzieje się, nie martw się o to...";
                Link.l1.go = "lier_2";
                AddCharacterExpToSkill(pchar, SKILL_SNEAK, 100);
            }
            else
            {
                dialog.text = "Myslę, że kłamiesz!";
			    Link.l1 = "Wtedy posłuchaj pieśni mojego ostrza.";
			    Link.l1.go = "battle";
			    AddCharacterExpToSkill(pchar, SKILL_SNEAK, 50);
            }
        break;
		
		case "TreasureCaptain":
			dialog.text = LinkRandPhrase("Więc ty jesteś tym, który zabrał moją mapę skarbów! Myślę, kumplu, że nadszedł czas, aby oddać wszystko, co zabrałeś...","Och, rywal! Nie zajdziesz daleko, jesteś spowolniony ciężarem moich skarbów...","Hej, w końcu cię dogoniłem! Wszystkie skarby w tej jaskini należą do mnie, rozumiesz? Teraz, opróżnij swoje kieszenie, kumplu!");
			Link.l1 = LinkRandPhrase("Czas, abyś spotkał się z moim ostrzem, kumplu!","Twoje skarby? Chciałeś powiedzieć, że były twoje, bo teraz są moje!","Wolałbym opróżnić twój żołądek moim ostrzem, kumplu.");
			Link.l1.go = "TreasureCaptain_fight"; 
		break;
		
		case "TreasureCaptain_fight":
			DialogExit();
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);//разрешить драться // patch-6
			for(i=1; i<=4; i++)
			{
				sld = characterFromId("Treasure_sailor_"+i);
				LAi_SetWarriorType(sld);
				LAi_group_MoveCharacter(sld, "EnemyFight");
			}
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("EnemyFight", "OpenTheDoors");
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		
		case "TreasureOfficer":
			dialog.text = LinkRandPhrase("Cóż, pułkownik miał rację, skarb był ukryty w tej jaskini... Opróżnij swoje kieszenie, marynarzu!","No więc wreszcie cię dopadliśmy, po całym tym śledzeniu przez te przeklęte dżungle, wśród cierni i bagien. Teraz, sukinsynu, oddasz nam wszystko...","Hej, żeglarzu! Skarby tego pirata należą do nas, więc zdejmij swoje brudne ręce od nich!");
			Link.l1 = LinkRandPhrase("Na pewno, nie spodziewałem się tego od oficera armii! Ale dobrze, nauczę cię jednak lekcji...","Popatrz na niego, pirata w mundurze oficera...","Rzeczywiście, żołnierze i piraci nie różnią się od siebie aż tak bardzo w dzisiejszych czasach...");
			Link.l1.go = "TreasureOfficer_fight"; 
		break;
		
		case "TreasureOfficer_fight":
			DialogExit();
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);//разрешить драться // patch-6
			for(i=1; i<=4; i++)
			{
				sld = characterFromId("Treasure_soldier_"+i);
				LAi_SetWarriorType(sld);
				LAi_group_MoveCharacter(sld, "EnemyFight");
			}
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("EnemyFight", "OpenTheDoors");
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		
		// генератор "A reason to hurry"
		case "ReasonToFast_THunter_1":
			if(CheckAttribute(pchar,"GenQuest.CannotWait"))	DeleteAttribute(pchar, "GenQuest.CannotWait");
			dialog.text = "I oto nadchodzi nasze złoto. Przynajmniej nasze czekanie nie było na próżno.";
			link.l1 = RandPhraseSimple("O czym mówicie, panowie? Jestem przedstawicielem Holenderskiej Kompanii Zachodnioindyjskiej i jestem tu tylko przejazdem! Zatrzymałem się, aby podziwiać widok na wybrzeże!","Obawiam się, że pomyliłeś mnie z kimś innym. Jestem "+GetSexPhrase("Francua Marie Paganel, ","Maria-Teresa, ")+"naturalista. Zbieram próbki lokalnej flory. Chcesz zobaczyć moją kolekcję liści juki? Mam kilka bardzo interesujących!");
			link.l1.go = "ReasonToFast_THunter_2";
			link.l2 = "Co chcesz?! Trzymaj się z dala od mnie!";
			link.l2.go = "ReasonToFast_THunter_2";
		break;
		
		case "ReasonToFast_THunter_2":
			ReasonToFast_ClearTreasureBox(pchar.questTemp.ReasonToFast.Treasure.Location);
			dialog.text = "O nie, "+GetSexPhrase("mój drogi przyjacielu","moja ładna dziewczyna")+". To nie zadziała. Wiemy na pewno, że posiadałeś mapę "+GetName(pchar.questTemp.ReasonToFast.mapIdx,pchar.questTemp.ReasonToFast.map,NAME_GEN)+". A on był taki skąpy, że jego skrzynie pękały od środka pełne pieniędzy. Więc nie zamierzamy wyjść z pustymi rękami.";
			link.l1 = "Masz rację. Skrzynie były rzeczywiście pełne. Ale ich nie dostaniesz. Możesz spróbować odwiedzić tamtą jaskinię, kilka przeszklonych wiader powinno tam jeszcze być.";
			link.l1.go = "ReasonToFast_THunter_3";
			if(ReasonToFast_CheckTreasureQty("icollection", sti(pchar.questTemp.ReasonToFast.p8)) >= sti(pchar.questTemp.ReasonToFast.p8) 
				&& ReasonToFast_CheckTreasureQty("Chest", sti(pchar.questTemp.ReasonToFast.p7)) >= sti(pchar.questTemp.ReasonToFast.p7))
			{
				link.l2 = "Masz rację. Możesz mieć swój skarb. Pamiętaj jednak, że nie przyniesie ci szczęścia, ponieważ jest poplamiony krwią.";
				link.l2.go = "ReasonToFast_THunter_4";
			}	
		break;
		
		case "ReasonToFast_THunter_3":
			dialog.text = ""+GetSexPhrase("Heh, kapitanie, jesteś zbyt młody, aby umierać, czyż nie...","Heh, dziewczyno, jesteś zbyt młoda, aby umierać, czyż nie...")+"...";
			link.l1 = "Właściwie, nie zamierzam umierać!";
			link.l1.go = "ReasonToFastTHunter_Fight";
		break;
		
		case "ReasonToFast_THunter_4":
			dialog.text = "Teraz to są słowa rozsądnej osoby!";
			link.l1 = "Przeklęstwo na ciebie i na wszystkie te skarby...";
			link.l1.go = "ReasonToFast_THunter_GoAway";
		break;
		
		case "ReasonToFast_THunter_GoAway":			
			iTemp = ReasonToFast_CheckTreasureQty("icollection", sti(pchar.questTemp.ReasonToFast.p8));
			if(iTemp > 0) 
			{
				ReasonToFast_GetTreasure("icollection", iTemp );
				Log_Info(XI_ConvertString("You give item"));
				PlayStereoSound("interface\important_item.wav");
			}	
			
			iTemp = ReasonToFast_CheckTreasureQty("Chest", sti(pchar.questTemp.ReasonToFast.p7));
			if(iTemp > 0) 
			{
				ReasonToFast_GetTreasure("Chest", iTemp);
				Log_Info(XI_ConvertString("You give item"));
				PlayStereoSound("interface\important_item.wav");
			}	
			if(pchar.questTemp.ReasonToFast == "GetTreasure")
			{
				AddQuestRecord("ReasonToFast", "24");
				AddQuestUserData("ReasonToFast", "sName", GetName( pchar.questTemp.ReasonToFast.mapIdx, pchar.questTemp.ReasonToFast.map, NAME_GEN));
				CloseQuestHeader("ReasonToFast");	
			}
			DialogExit();	
			AddDialogExitQuest("ReasonToFast_GoAway_Hunters_Land");
		break;
		
		case "ReasonToFastTHunter_Fight":
			sGroup = "LAND_HUNTER";
			sTemp = "LandHunter0";
			iTemp = sti(pchar.HunterCost.Qty);
			chrDisableReloadToLocation = true;
			LAi_SetPlayerType(pchar);
			LAi_SetFightMode(pchar, true);
			for(i = 1; i <= iTemp; i++)
			{
				sld = CharacterFromID(sTemp + i);
				LAi_SetWarriorType(sld);
				LAi_group_MoveCharacter(sld, sGroup);
			}
			
			LAi_group_SetRelation(sGroup, LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups(sGroup, LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck(sGroup, "OpenTheDoors"); 
			LAi_group_SetCheck(sGroup, "ReasonToFast_TrHuntersDied");	
			DialogExit();	
			AddDialogExitQuest("MainHeroFightModeOn");	
		break;
		
		case "ReasonToFast_HunterShore1":
			dialog.text = "Hej,"+GetSexPhrase("kumpel","dziewczyno")+"! "+GetName(NAMETYPE_MAIN,pchar.questTemp.ReasonToFast.p3,NAME_NOM)+" powiedział, że masz dla nas coś.";
			link.l1 = "Co masz na myśli?";
			link.l1.go = "ReasonToFast_HunterShore11";
			pchar.quest.ReasonToFast_SetHunterPort_1.over = "yes";
			pchar.quest.ReasonToFast_SetHunterPort_2.over = "yes";
		break;

		case "ReasonToFast_HunterShore11":
			if(pchar.questTemp.ReasonToFast == "GetMap") 
			{
				dialog.text = "Mapa "+GetName(pchar.questTemp.ReasonToFast.mapIdx,pchar.questTemp.ReasonToFast.map,NAME_GEN);
				link.l1 = "Weź to i pozdrów "+GetName(NAMETYPE_MAIN,pchar.questTemp.ReasonToFast.p3,NAME_DAT)+". Powiedz mu, że spotkamy się wkrótce...";
				link.l1.go = "ReasonToFast_HunterShore12_1";
				link.l2 = GetName(NAMETYPE_MAIN,pchar.questTemp.ReasonToFast.p3,NAME_NOM)+"jest ciężko w błędzie, jeśli myśli, że będę dla niego wyciągał kasztany z ognia.";
				link.l2.go = "ReasonToFast_HunterShore23";
			}
			if(pchar.questTemp.ReasonToFast == "LakeyExitSuccess")
			{
				dialog.text = "Biżuteria, którą ukradłeś gubernatorowi.";
				if(ReasonToFast_CheckTreasureQty("icollection", sti(pchar.questTemp.ReasonToFast.p8)) >= sti(pchar.questTemp.ReasonToFast.p8) 
					&& ReasonToFast_CheckTreasureQty("Chest", sti(pchar.questTemp.ReasonToFast.p7)) >= sti(pchar.questTemp.ReasonToFast.p7))
				{
					link.l1 = "Weź to i pozdrów "+GetName(NAMETYPE_MAIN,pchar.questTemp.ReasonToFast.p3,NAME_DAT)+". Powiedz mu, że spotkamy się wkrótce...";
					link.l1.go = "ReasonToFast_HunterShore12_2";
				}	
				link.l2 = GetName(NAMETYPE_MAIN,pchar.questTemp.ReasonToFast.p3,NAME_NOM)+"jest poważnie w błędzie, jeśli myśli, że będę dla niego wyciągał kasztany z ognia.";
				link.l2.go = "ReasonToFast_HunterShore23";				
			}
			pchar.quest.ReasonToFast_SetHunterPort_1.over = "yes";
			pchar.quest.ReasonToFast_SetHunterPort_2.over = "yes";
			chrDisableReloadToLocation = false;
		break;
		
		case "ReasonToFast_HunterShore12_1":
			TakeNItems(pchar, "mapQuest", -1); 
			AddQuestRecord("ReasonToFast", "20");
			AddQuestUserData("ReasonToFast", "sText", "a map of");
			AddQuestUserData("ReasonToFast", "sName", GetName( NAMETYPE_MAIN, pchar.questTemp.ReasonToFast.p3, NAME_GEN));
			CloseQuestHeader("ReasonToFast");
			DialogExit();	
			AddDialogExitQuest("ReasonToFast_GoAway_Hunters_Land");
		break;
		
		case "ReasonToFast_HunterShore12_2":
			iTemp = ReasonToFast_CheckTreasureQty("icollection", sti(pchar.questTemp.ReasonToFast.p8));
			if(iTemp > 0) 
			{
				ReasonToFast_GetTreasure("icollection", iTemp );
				Log_Info(XI_ConvertString("You give item"));
				PlayStereoSound("interface\important_item.wav");
			}	
			
			iTemp = ReasonToFast_CheckTreasureQty("Chest", sti(pchar.questTemp.ReasonToFast.p7));
			if(iTemp > 0) 
			{
				ReasonToFast_GetTreasure("Chest", iTemp);
				Log_Info(XI_ConvertString("You give item"));
				PlayStereoSound("interface\important_item.wav");
			}			
			AddQuestRecord("ReasonToFast", "20");
			AddQuestUserData("ReasonToFast", "sText", "treasures");
			AddQuestUserData("ReasonToFast", "sName", GetName( NAMETYPE_MAIN, pchar.questTemp.ReasonToFast.p3, NAME_GEN));
			CloseQuestHeader("ReasonToFast");
			DialogExit();	
			ReasonToFast_ClearTreasureBox(pchar.questTemp.ReasonToFast.city + "_townhall");
			ReasonToFast_ClearTreasureBox(pchar.questTemp.ReasonToFast.LakeyLocation);
			AddDialogExitQuest("ReasonToFast_GoAway_Hunters_Land");
		break;
		
		case "ReasonToFast_HunterShore2":
			dialog.text = "Hej,"+GetSexPhrase("kumpel","dziewczyno")+"! "+GetName(NAMETYPE_MAIN,pchar.questTemp.ReasonToFast.p3,NAME_GEN)+" ma kilka pytań do ciebie.";
			link.l1 = "A dlaczego sam nie zapytałby ich?";
			link.l1.go = "ReasonToFast_HunterShore21";
			chrDisableReloadToLocation = false;
		break;
		
		case "ReasonToFast_HunterShore21":
			dialog.text = "Nie według jego rangi. Zrujnowałeś naszą operację i straciliśmy "+sti(pchar.questTemp.ReasonToFast.p10)+" pesos przez ciebie. Więc teraz masz dług do spłacenia.";
			link.l1 = "Weź to i przywitaj się z "+GetName(NAMETYPE_MAIN,pchar.questTemp.ReasonToFast.p3,NAME_DAT)+". Powiedz mu, że spotkamy się wkrótce...";
			link.l1.go = "ReasonToFast_HunterShore22";
			link.l2 = GetName(NAMETYPE_MAIN,pchar.questTemp.ReasonToFast.p3,NAME_NOM)+" jest ciężko w błędzie, jeśli myśli, że będę dla niego wyjmował kasztany z ognia.";
			link.l2.go = "ReasonToFast_HunterShore23";
		break;
		
		case "ReasonToFast_HunterShore22":
			if(makeint(pchar.money) >= sti(pchar.questTemp.ReasonToFast.p10))
			{
				AddMoneyToCharacter(pchar, -makeint(sti(pchar.questTemp.ReasonToFast.p10)));
				AddQuestRecord("ReasonToFast", "20");
				AddQuestUserData("ReasonToFast", "sText", "money");
				AddQuestUserData("ReasonToFast", "sName", GetName( NAMETYPE_MAIN, pchar.questTemp.ReasonToFast.p3, NAME_GEN));
				DialogExit();	
				AddDialogExitQuest("ReasonToFast_GoAway_Hunters_Land");
			}
			else
			{
				dialog.text = "Och, nie masz takich pieniędzy! Cóż, dokonałeś swojego wyboru...";
				link.l1 = "Dawno temu...";
				link.l1.go = "ReasonToFastTHunter_Fight";	
				if(pchar.questTemp.ReasonToFast == "LakeyExitSuccess" || pchar.questTemp.ReasonToFast == "LakeyExitFail")
				{
					pchar.quest.ReasonToFast_SetPirateShip.win_condition.l1 = "MapEnter";
					pchar.quest.ReasonToFast_SetPirateShip.function = "ReasonToFast_PreparePirateShip";
				}
			}
		break;
		
		case "ReasonToFast_HunterShore23":
			dialog.text = "Cóż, dokonałeś swojego wyboru...";
			link.l1 = "Dawno temu...";
			link.l1.go = "ReasonToFastTHunter_Fight";
			if(pchar.questTemp.ReasonToFast == "LakeyExitSuccess" || pchar.questTemp.ReasonToFast == "LakeyExitFail")
			{
				pchar.quest.ReasonToFast_SetPirateShip.win_condition.l1 = "MapEnter";
				pchar.quest.ReasonToFast_SetPirateShip.function = "ReasonToFast_PreparePirateShip";
			}
		break;
		// генератор "A reason to hurry"
	}
}

string GetLocHunterName()
{
	int nLoc = FindLocation(Pchar.location);
	int nFile = LanguageOpenFile("LocLables.txt");
	string ret = "";
	
	if(nFile >= 0) 
	{
		if (CheckAttribute(&locations[nLoc],"islandId"))
		{
			if (locations[nLoc].islandId != "Mein")
			{
				ret = "island of " + LanguageConvertString(nFile, locations[nLoc].islandId);
			}
			else
			{
				ret = "mainland of ";
			}
		}
		//
        if (CheckAttribute(&locations[nLoc],"fastreload"))
		{
			ret += " (" +LanguageConvertString(nFile, locations[nLoc].fastreload + " Town") + ")";
		}
		//ret += LanguageConvertString(nFile, locations[nLoc].id.label);
		LanguageCloseFile( nFile );
	}
	return ret;	
}
