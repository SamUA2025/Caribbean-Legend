/// BOAL меню наций
#event_handler("Control Activation","ProcessInterfaceControls");// гуляем по меню кнопками Q и E
ref xi_refCharacter
int curNationIdx;

void InitInterface(string iniName)
{
	xi_refCharacter = pchar;
    InterfaceStack.SelectMenu_node = "LaunchNationRelation"; // запоминаем, что звать по Ф2
	GameInterface.title = "titleNationRelation";
	SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);
	// boal 18.12.2003 -->
	// делаем заточку под 5 или 6 наций и любую морду (64) гл. героя - универсальность залог успеха!
	// введем коэфф. для автопостроения матрицы
	int     i;
	int     dy=45;
    int     dx=45;
    int     sx=370;
    int     sy=120;
	int     sz=80;
	string  picName  = "pic";
	string  groupName;
	int     picCount = 1;
	int     deltaX = 545;
	int     deltaY = 320;
	int     max_nt = MAX_NATIONS;

	
	ref chref = GetMainCharacter();
    int j;
    
	if (bBettaTestMode)
	{   // со столбцом ГГ
		// SetNewPicture("ICON_1", "interfaces\le\PORTRAITS\128\face_" + chref.faceId+ ".tga");
		// SetNewPicture("ICON_2", "interfaces\le\PORTRAITS\128\face_" + chref.faceId+ ".tga");
		for (i=0; i< max_nt; i++)
		{
	        groupName = "NATIONS";
	        CreateImage(picName+picCount, groupName, Nations[i].Name, deltaX +dx+(dx+sz)*i, sy, deltaX + dx+ (dx+sz)*i+sz, sy+sz);
		    picCount++;
		}
		for (i=0; i< max_nt; i++)
		{
		    groupName = "NATIONS";
	        CreateImage(picName+picCount, groupName, Nations[i].Name,  sx, deltaY-45 +dy+(dy+sz)*i, sx+sz, deltaY-45 +dy+(dy+sz)*i+sz);
		    picCount++;
		}
		// Y
		for (i=0; i< max_nt; i++)
		{
	        CreateImage(picName+picCount, "relations", GetRelationName(GetNationRelation2MainCharacter(i)), deltaX -sz, deltaY +(dy+sz)*i, deltaX , deltaY +(dy+sz)*i+sz);
		    picCount++;
		}
		//X
		for (i=0; i< max_nt; i++)
		{
	        CreateImage(picName+picCount, "relations", GetRelationName(GetNationRelation2MainCharacter(i)), deltaX +dx+(dx+sz)*i, deltaY-sz-35, deltaX + dx+ (dx+sz)*i+sz, deltaY-35);
		    picCount++;
		}
		//GetNationRelation
		for (j=0; j< max_nt; j++)
		{
		    for (i=0; i< max_nt; i++)
		    {
		        if (i != j)
		        {
		            CreateImage(picName+picCount, "relations", GetRelationName(GetNationRelation(j, i)), deltaX +dx+(dx+sz)*i, deltaY +(dy+sz)*(j), deltaX + dx+ (dx+sz)*i+sz, deltaY+(dy+sz)*(j)+sz);
		            picCount++;
		        }
		    }
		}
	}
	else
	{// без столбца ГГ
     	// SetNewPicture("ICON_1", "");
		// SetNewPicture("ICON_2", "");
		sx=460;//шапка
    	sy=195;//шапка
		sz = 80;		

		deltaX = 545; // поля
		deltaY = 320; // поля
		for (i=0; i< max_nt; i++)
		{
	        groupName = "NATIONS";
	        CreateImage(picName+picCount, groupName, Nations[i].Name, deltaX +dx+(dx+sz)*i, sy, deltaX + dx+ (dx+sz)*i+sz, sy+sz);
		    picCount++;
		}
		for (i=0; i< max_nt; i++)
		{
		    groupName = "NATIONS";
	        // CreateImage(picName+picCount, groupName, Nations[i].Name,  sx, deltaY-10 +dy+(dy+sz)*i, sx+sz, deltaY-10 +dy+(dy+sz)*i+sz);
	        CreateImage(picName+picCount, groupName, Nations[i].Name,  sx, deltaY-45 +dy+(dy+sz)*i, sx+sz, deltaY-45 +dy+(dy+sz)*i+sz);
		    picCount++;
		}
  		for (j=0; j< max_nt; j++)
		{
		    for (i=0; i< max_nt; i++)
		    {
		        if (i != j)
		        {
		            CreateImage(picName+picCount, "relations", GetRelationName(GetNationRelation(j, i)), deltaX +dx+(dx+sz)*i, deltaY +(dy+sz)*(j), deltaX + dx+ (dx+sz)*i+sz, deltaY+(dy+sz)*(j)+sz);
		            picCount++;
		        }
		    }
		}
	}
    // boal 18.12.2003 <--
	SetEventHandler("InterfaceBreak","ProcessExitCancel",0);
	SetEventHandler("exitCancel","ProcessExitCancel",0);
    SetEventHandler("FlagsPress","FlagsProcess",0);
    SetEventHandler("ievnt_command","ProcessCommandExecute",0);
    SetEventHandler("MouseRClickUP","HideInfo",0);
	SetEventHandler("ShowInfoWindow","ShowInfoWindow",0);
    
	// доп инфа в шапку --->
	SetFormatedText("Weight", FloatToString(GetItemsWeight(xi_refCharacter), 1) + " / " + GetMaxItemsWeight(xi_refCharacter));
	SetFormatedText("Money", FindRussianMoneyString(sti(xi_refCharacter.money)));
	SetFormatedText("Dublon", FindRussianDublonString(sti(xi_refCharacter.dublon)));
	SetFormatedText("Rank", xi_refCharacter.rank);
	SetFormatedText("Rank_progress", GetCharacterRankRateCur(xi_refCharacter) + " / " + GetCharacterRankRate(xi_refCharacter));
	// порог уровня
	GameInterface.StatusLine.BAR_RANK.Max   = GetCharacterRankRate(xi_refCharacter);
	GameInterface.StatusLine.BAR_RANK.Min   = 0;
	GameInterface.StatusLine.BAR_RANK.Value = GetCharacterRankRateCur(xi_refCharacter);	
	SendMessage(&GameInterface,"lsl",MSG_INTERFACE_MSG_TO_NODE,"BAR_RANK",0);
	// <--- 	
    /////////////	
    CalculateHunter();
    

    curNationIdx = sti(chref.nation);
    SetNewNation(0);
    XI_RegistryExitKey("IExit_F2");
	SetAlertMarks(xi_refCharacter);
}

// гуляем по меню кнопками Q и E
void ProcessInterfaceControls() 
{
    string controlName = GetEventData();
 
	if (controlName == "InterfaceGoLeft") {
        IDoExit(RC_INTERFACE_ABILITIES);
    }
	if (controlName == "InterfaceGoRight") {
        IDoExit(RC_INTERFACE_INVENTORY);
    }
}

void CalculateHunter()
{

    ref mc = GetMainCharacter();

    SetFormatedText("Eng_rep", GetNationReputation(pchar, ENGLAND));
    SetFormatedText("Fra_rep", GetNationReputation(pchar, FRANCE));
    SetFormatedText("Spa_rep", GetNationReputation(pchar, SPAIN));
    SetFormatedText("Hol_rep", GetNationReputation(pchar, HOLLAND));
	SendMessage( &GameInterface,"lsl",MSG_INTERFACE_MSG_TO_NODE,"Eng_rep", 5 );
	SendMessage( &GameInterface,"lsl",MSG_INTERFACE_MSG_TO_NODE,"Fra_rep", 5 );
	SendMessage( &GameInterface,"lsl",MSG_INTERFACE_MSG_TO_NODE,"Spa_rep", 5 );
	SendMessage( &GameInterface,"lsl",MSG_INTERFACE_MSG_TO_NODE,"Hol_rep", 5 );

	GameInterface.StatusLine.BAR_ENG.Max   = 100;
	GameInterface.StatusLine.BAR_ENG.Min   = -100;
	GameInterface.StatusLine.BAR_ENG.Value = -sti(pchar.reputation.enghunter);
	SendMessage(&GameInterface,"lsl",MSG_INTERFACE_MSG_TO_NODE, "BAR_ENG", 0);

	GameInterface.StatusLine.BAR_FRA.Max   = 100;
	GameInterface.StatusLine.BAR_FRA.Min   = -100;
	GameInterface.StatusLine.BAR_FRA.Value = -sti(pchar.reputation.frahunter);
	SendMessage(&GameInterface,"lsl",MSG_INTERFACE_MSG_TO_NODE, "BAR_FRA", 0);

	GameInterface.StatusLine.BAR_SPA.Max   = 100;
	GameInterface.StatusLine.BAR_SPA.Min   = -100;
	GameInterface.StatusLine.BAR_SPA.Value = -sti(pchar.reputation.spahunter);
	SendMessage(&GameInterface,"lsl",MSG_INTERFACE_MSG_TO_NODE, "BAR_SPA", 0);

	GameInterface.StatusLine.BAR_HOL.Max   = 100;
	GameInterface.StatusLine.BAR_HOL.Min   = -100;
	GameInterface.StatusLine.BAR_HOL.Value = -sti(pchar.reputation.holhunter);
	SendMessage(&GameInterface,"lsl",MSG_INTERFACE_MSG_TO_NODE, "BAR_HOL", 0);
	 
}

void ProcessExitCancel()
{
	IDoExit(RC_INTERFACE_ANY_EXIT);
}

void IDoExit(int exitCode)
{
	DelEventHandler("InterfaceBreak","ProcessExitCancel");
	DelEventHandler("exitCancel","ProcessExitCancel");
    DelEventHandler("FlagsPress","FlagsProcess");
    DelEventHandler("ievnt_command","ProcessCommandExecute");
    DelEventHandler("MouseRClickUP","HideInfo");
	DelEventHandler("ShowInfoWindow","ShowInfoWindow");

	interfaceResultCommand = exitCode;
	if( CheckAttribute(&InterfaceStates,"ReloadMenuExit"))
	{
        DeleteAttribute(&InterfaceStates,"ReloadMenuExit");
		EndCancelInterface(false);
	}
	else
	{
		EndCancelInterface(true);
	}
}

void ShowInfoWindow()
{
	// string sHeader = "TEST";
	string sCurrentNode = GetCurrentNode();
	string sHeader, sText1, sText2, sText3, sPicture;
	string sGroup, sGroupPicture;

	switch(sCurrentNode)
	{
		case "FLAGPIC":
			sHeader = XI_ConvertString("Nation");
			sText1 = GetRPGText("Nation_hint");
		break;
		
		case "INFO_CLICK":
			sHeader = XI_ConvertString("Hunter_type");
			sText1 = GetRPGText("Hunter_hint");
		break;
		// sith --->
		case "WEIGHT":
		    sHeader = XI_ConvertString("Weight");
			sText1 = GetRPGText("Weight");
		break;
		case "MONEY":
		    sHeader = XI_ConvertString("Money");
			sText1 = GetRPGText("Money");
		break;		
		case "RANK":
		    sHeader = XI_ConvertString("Rank");
			sText1 = GetRPGText("Rank");
		break;
		//<--- sith
	}
	CreateTooltip("#" + sHeader, sText1, argb(255,255,255,255), sText2, argb(255,255,192,192), sText3, argb(255,255,255,255), "", argb(255,255,255,255), sPicture, sGroup, sGroupPicture, 64, 64);
}

void HideInfo()
{
	CloseTooltip();
	SetCurrentNode("OK_BUTTON");
}

void FlagsProcess()
{
	// boal 04.04.2004 -->
	bool bTmpBool = true;
	int i, cn;
	ref chref;
	
	if (CheckAttribute(pchar, "DisableChangeFlagMode")) return; // нефиг менять файл за 3 секунды сразу
	
	if (!bBettaTestMode)
	{
    	// if(LAi_group_IsActivePlayerAlarm()) bTmpBool = false;
    	// if(!LAi_IsCharacterControl(GetMainCharacter())) bTmpBool = false;
		// if(GetCharacterShipType(pchar) == SHIP_NOTUSED) bTmpBool = false;
    	if (bLandInterfaceStart)  bTmpBool = false; // на суше нельзя в принципе
    	if (bSeaActive && !CheckEnemyCompanionDistance2GoAway(false)) bTmpBool = false; // компаньон под ударом
        // проверка класса кораблей в эскадре -->
        /*for (i=0; i<4; i++)
    	{
    		cn = GetCompanionIndex(GetMainCharacter(), i);
    		if ( cn>=0 )
    		{
    			chref = GetCharacter(cn);
                if (GetCharacterShipClass(chref) <= 2) bTmpBool = false;
    		}
    	}  */
        // проверка класса кораблей в эскадре <--
	}
	if (bDisableMapEnter || !bTmpBool)
	{
        if (!bBettaTestMode)
        {
            PlaySound("interface\knock.wav");
            return;
        }
	}
	// смена флага
	Sea_ClearCheckFlag(); // сбросить всем в море проверку смотрения на флаг.
	pchar.DisableChangeFlagMode = true; //закрываем Флаг
	DoQuestFunctionDelay("FreeChangeFlagMode", 5.0); // ролик + запас
	
	switch (curNationIdx)
	{
    	case ENGLAND:	EnglandProcess();	break;
    	case FRANCE:	FranceProcess();	break;
    	case SPAIN:		SpainProcess();	break;
    	case PIRATE:	PirateProcess();	break;
    	case HOLLAND:	HollandProcess();	break;
	}
}

void ProcessCommandExecute()
{
	string comName = GetEventData();
	string nodName = GetEventData();
    switch(nodName)
	{
        case "LEFTCHANGE_NATION":
    		if(comName=="activate" || comName=="click")
    		{
				if (!CheckAttribute(pchar, "DisableChangeFlagMode"))
				{
					SetNewNation(-1);
				}
    		}
    	break;

    	case "RIGHTCHANGE_NATION":
    		if(comName=="activate" || comName=="click")
    		{
                if (!CheckAttribute(pchar, "DisableChangeFlagMode"))
                {
					SetNewNation(1);
				}
    		}
    	break;
		/////////////////////// menu ///////////////
		case "I_INVENTORY_2":
			if(comName=="click")
			{
			    nodName = "I_INVENTORY";
			}
		break;
		case "I_SHIP_2":
			if(comName=="click")
			{
			    nodName = "I_SHIP";
			}
		break;
		case "I_QUESTBOOK_2":
			if(comName=="click")
			{
			    nodName = "I_QUESTBOOK";
			}
		break;
		case "I_JOURNAL_2":
			if(comName=="click")
			{
			    nodName = "I_JOURNAL";
			}
		break;
		case "I_ATLAS_2":
			if(comName=="click")
			{
			    nodName = "I_ATLAS";
			}
		break;
		case "I_ABILITIES_2":
			if(comName=="click")
			{
			    nodName = "I_ABILITIES";
			}
		break;
		case "I_NATIONS_2":
			if(comName=="click")
			{
			    nodName = "I_NATIONS";
			}
		break;
		case "I_ITEMS_2":
			if(comName=="click")
			{
			    nodName = "I_ITEMS";
			}
		break;
	}
	// boal new menu 31.12.04 -->
	if (nodName == "I_INVENTORY" || nodName == "I_SHIP" ||
	    nodName == "I_QUESTBOOK" || nodName == "I_JOURNAL" || nodName == "I_ATLAS" || nodName == "I_ABILITIES" ||
		nodName == "I_NATIONS" || nodName == "I_ITEMS")
	{
		if(comName=="click")
		{
            InterfaceStates.ReloadMenuExit = true;
			IDoExit(RC_INTERFACE_ANY_EXIT);
			PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
			return;
		}
	}
	// boal new menu 31.12.04 -->
}
void SetNewNation(int add)
{
    ref   mchar = GetMainCharacter();
    bool  ok, ok2, ok3;
    
    curNationIdx = curNationIdx + add;
    if (curNationIdx < 0) curNationIdx = 4;
    if (curNationIdx > 4) curNationIdx = 0;
    SetNewGroupPicture("FLAGPIC", "NATIONS", GetNationNameByType(curNationIdx));
    
    if (IsCharacterPerkOn(mchar,"FlagPir")  ||
	    IsCharacterPerkOn(mchar,"FlagEng")  ||
		IsCharacterPerkOn(mchar,"FlagFra")  ||
		IsCharacterPerkOn(mchar,"FlagSpa")  ||
		IsCharacterPerkOn(mchar,"FlagHol"))
    {
		SetNodeUsing("FLAGS",true);
		if (!bBettaTestMode)
		{
			ok3 = bSeaActive && !CheckEnemyCompanionDistance2GoAway(false);
			if (bDisableMapEnter || bLandInterfaceStart || ok3) SetSelectable("FLAGS",false);
		}
        ok  = !IsCharacterPerkOn(mchar,"Flag" + NationShortName(curNationIdx)) && (sti(mchar.nation) != curNationIdx);
        ok2 =  true;
        if (isMainCharacterPatented())
        {
            ok2 = (sti(Items[sti(mchar.EquipedPatentId)].Nation) != curNationIdx);
        }
        if (ok && ok2)
        {
            SetNewNation(add);
        }
        if (sti(mchar.nation) == curNationIdx)
        {
			SetNodeUsing("FLAGS",false);
        }
    }
    else
    {
        SetNodeUsing("FLAGS",false);
	    SetNodeUsing("RIGHTCHANGE_NATION",false);
	    SetNodeUsing("LEFTCHANGE_NATION",false);
    }
}
void PirateProcess()
{
    //DoQuestCheckDelay("pir_flag_rise", 1.0);
    PChar.GenQuest.VideoAVI        = "Pirate";
    PChar.GenQuest.VideoAfterQuest = "pir_flag_rise";

    DoQuestCheckDelay("PostVideo_Start", 0.2);
	ProcessExitCancel();
}

void EnglandProcess()
{
    //DoQuestCheckDelay("eng_flag_rise", 1.0);
    PChar.GenQuest.VideoAVI        = "England";
    PChar.GenQuest.VideoAfterQuest = "eng_flag_rise";

    DoQuestCheckDelay("PostVideo_Start", 0.2);
    ProcessExitCancel();
}

void FranceProcess()
{
    PChar.GenQuest.VideoAVI        = "France";
    PChar.GenQuest.VideoAfterQuest = "fra_flag_rise";

    DoQuestCheckDelay("PostVideo_Start", 0.2);
	ProcessExitCancel();
}

void SpainProcess()
{
    PChar.GenQuest.VideoAVI        = "Spain";
    PChar.GenQuest.VideoAfterQuest = "spa_flag_rise";

    DoQuestCheckDelay("PostVideo_Start", 0.2);
    ProcessExitCancel();
}

void HollandProcess()
{
    PChar.GenQuest.VideoAVI        = "Holland";
    PChar.GenQuest.VideoAfterQuest = "hol_flag_rise";

    DoQuestCheckDelay("PostVideo_Start", 0.2);
	ProcessExitCancel();
}