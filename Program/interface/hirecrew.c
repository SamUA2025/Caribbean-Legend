////    boal 30.07.06 найм матросов
int	nCurScrollNum = 0;
ref refCharacter;
ref refTown;
ref refShipChar;
int iShipCapacity;
float fShipWeight;
int  BuyOrSell = 0; // 1-buy -1 sell
int  iPriceSailor;
int	 QtyMax = 0; 	 
int	 CrewQty = 0;

void InitInterface(string iniName)
{
 	StartAboveForm(true);
	LAi_SetActorType(pchar);
	refCharacter = pchar;
	GameInterface.title = "titleHireCrew";
	// город, где ГГ
	refTown = GetColonyByIndex(FindColony(loadedLocation.fastreload));
    FillShipsScroll();

	SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);

	CreateString(true,"ShipName","",FONT_NORMAL,COLOR_MONEY, 960,330,SCRIPT_ALIGN_CENTER,1.5);

	SetDescription();

	SetEventHandler("InterfaceBreak","ProcessBreakExit",0);
	SetEventHandler("exitCancel","ProcessCancelExit",0);
	SetEventHandler("ievnt_command","ProcCommand",0);
	SetEventHandler("evntDoPostExit","DoPostExit",0);

	SetEventHandler("ShowInfoWindow","ShowInfoWindow",0);
	SetEventHandler("MouseRClickUp","HideInfoWindow",0);
	SetEventHandler("frame","ProcessFrame",1);
	
	SetEventHandler("TransactionOK", "TransactionOK", 0);
	SetEventHandler("TransactionCancel", "TransactionCancel", 0);
	SetEventHandler("confirmChangeQTY_EDIT", "confirmChangeQTY_EDIT", 0);
	SetEventHandler("ADD_ALL_BUTTON", "ADD_ALL_BUTTON", 0);
	SetEventHandler("ADD_BUTTON","ADD_BUTTON",0);
	SetEventHandler("REMOVE_BUTTON", "REMOVE_BUTTON", 0);
	SetEventHandler("REMOVE_ALL_BUTTON", "REMOVE_ALL_BUTTON", 0);
	
	SetNewGroupPicture("CREW_PICTURE", "SHIP_STATE_ICONS", "Crew");
	SetNewGroupPicture("CREW_PICTURE2", "SHIP_STATE_ICONS", "Crew");
	SetBackupQty();
	SetCurrentNode("SHIPS_SCROLL");
	GameInterface.qty_edit.str = 0;
	QtyMax = GetCargoFreeSpace(refCharacter);
	
	
	if(CheckAttribute(refTown, "AdditionalCrew"))
	{
		if(!IsEquipCharacterByArtefact(pchar, "totem_07"))
		{
			CrewQty = GetCrewQuantity(refTown) - sti(refTown.AdditionalCrew);
			if(CrewQty < 0) CrewQty = 0;
			SetCrewQuantity(refTown, CrewQty);
		}
	}
	else
	{
		if(IsEquipCharacterByArtefact(pchar, "totem_07"))
		{
			CrewQty = GetCrewQuantity(refTown);						
			refTown.AdditionalCrew = makeint(CrewQty * 0.5);			
			CrewQty += sti(refTown.AdditionalCrew);
			SetCrewQuantity(refTown, CrewQty);
		}
	}
	// belamour legendary edition Орден Святого Людовика -->
	if(CheckAttribute(refTown, "AddCrewTalisman9"))
	{
		if(!IsEquipTalisman9())
		{
			CrewQty = GetCrewQuantity(refTown) - sti(refTown.AddCrewTalisman9);
			if(CrewQty < 0) CrewQty = 0;
			SetCrewQuantity(refTown, CrewQty);
		}
	}
	else
	{
		if(IsEquipTalisman9() && refTown.nation == FRANCE)
		{
			CrewQty = GetCrewQuantity(refTown);						
			refTown.AddCrewTalisman9 = makeint(CrewQty * 0.15);			
			CrewQty += sti(refTown.AddCrewTalisman9);
			SetCrewQuantity(refTown, CrewQty);
		}
	}
	// <-- legendary edition
}

void ProcessBreakExit()
{
	IDoExit( RC_INTERFACE_FOOD_INFO_EXIT );
}

void ProcessCancelExit()
{
	IDoExit( RC_INTERFACE_FOOD_INFO_EXIT );
}

void IDoExit(int exitCode)
{
    EndAboveForm(true);
	LAi_SetPlayerType(pchar);
	RecalculateCargoLoad(refCharacter);
    GetBackupQty(); // если неожиданно вышли
	DelEventHandler("InterfaceBreak","ProcessBreakExit");
	DelEventHandler("exitCancel","ProcessCancelExit");
	DelEventHandler("ievnt_command","ProcCommand");
	DelEventHandler("evntDoPostExit","DoPostExit");

	DelEventHandler("ShowInfoWindow","ShowInfoWindow");
	DelEventHandler("MouseRClickUp","HideInfoWindow");
	DelEventHandler("frame","ProcessFrame");
	
	DelEventHandler("TransactionOK", "TransactionOK");
	DelEventHandler("TransactionCancel", "TransactionCancel");
	DelEventHandler("confirmChangeQTY_EDIT", "confirmChangeQTY_EDIT");
	DelEventHandler("ADD_ALL_BUTTON", "ADD_ALL_BUTTON");
	DelEventHandler("ADD_BUTTON","ADD_BUTTON");
	DelEventHandler("REMOVE_BUTTON", "REMOVE_BUTTON");
	DelEventHandler("REMOVE_ALL_BUTTON", "REMOVE_ALL_BUTTON");
	
	interfaceResultCommand = exitCode;
	EndCancelInterface(true);

}

void ProcCommand()
{
	string comName = GetEventData();
	string nodName = GetEventData();

	switch(nodName)
	{
		case "QTY_OK_BUTTON":
			if(comName=="leftstep")
			{
	            ADD_BUTTON();
			}
			if(comName=="rightstep")
			{
	            REMOVE_BUTTON();
			}
			if(comName=="speedleft")
			{
	      		ADD_ALL_BUTTON();
			}
			if(comName=="speedright")
			{
	            REMOVE_ALL_BUTTON();
			}
		break;

		case "QTY_CANCEL_BUTTON":
			if(comName=="leftstep")
			{
	            ADD_BUTTON();
			}
			if(comName=="rightstep")
			{
	            REMOVE_BUTTON();
			}
			if(comName=="speedleft")
			{
	      		ADD_ALL_BUTTON();
			}
			if(comName=="speedright")
			{
	            REMOVE_ALL_BUTTON();
			}
		break;	
	}
}

void DoPostExit()
{
	int exitCode = GetEventData();
	IDoExit(exitCode);
}

void FillShipsScroll()
{
	nCurScrollNum = -1;
	FillScrollImageWithCompanionShips("SHIPS_SCROLL", 5);

	if(!CheckAttribute(&GameInterface,"SHIPS_SCROLL.current"))
	{
		GameInterface.SHIPS_SCROLL.current = 0;
	}
}

void SetVariable()
{
	string sText, sTextSecond;
	int iColor;
	int nShipType = sti(refCharacter.ship.type);
	
	if (nShipType == SHIP_NOTUSED)
	{
        GameInterface.strings.shipname = "";
		return;
	}
	
	QtyMax = GetCargoFreeSpace(refCharacter);
	
	ref refBaseShip = GetRealShip(nShipType);
	SetShipWeight();
	
	iShipCapacity = sti(refBaseShip.Capacity);
	sText  = iShipCapacity;
	sText  = makeint(fShipWeight) + " / " + sText;	
	SetFormatedText("CAPACITY", sText);	
	
	SetFormatedText("CHARACTER_NAME", GetFullName(refCharacter));	
	
    SetNewPicture("MAIN_CHARACTER_PICTURE", "interfaces\le\portraits\256\face_" + its(refCharacter.FaceId) + ".tga");

	sText = MakeMoneyShow(sti(pchar.Money), MONEY_SIGN,MONEY_DELIVER);		
	SetFormatedText("OUR_GOLD", sText);

	if (CheckAttribute(refCharacter, "ship.name"))
	{
		GameInterface.strings.shipname = refCharacter.ship.name;
	}
	else
	{
	    GameInterface.strings.shipname = "";
	}
	SetCrewExpTable(refCharacter, "TABLE_CREW", "BAR_Sailors", "BAR_Cannoners", "BAR_Soldiers");
	
	SetFormatedText("CREW_QTY", ""+GetCrewQuantity(refCharacter));
	if (GetCrewQuantity(refCharacter) > GetOptCrewQuantity(refCharacter) || GetCrewQuantity(refCharacter) < GetMinCrewQuantity(refCharacter))
	{
		iColor = argb(255,255,64,64);
	}
	else
	{
		iColor = argb(255,255,255,255);
	}
	SendMessage(&GameInterface,"lslll",MSG_INTERFACE_MSG_TO_NODE,"CREW_QTY", 8,-1,iColor);
	SetNewGroupPicture("CREW_MORALE_PIC", "MORALE_SMALL", GetMoraleGroupPicture(stf(refCharacter.ship.crew.morale)));
	SetFormatedText("CREW_MORALE_TEXT", XI_ConvertString("CrewMorale") + ": " + XI_ConvertString(GetMoraleName(sti(refCharacter.Ship.crew.morale))));
		
	//RecalculateCargoLoad(refCharacter);

	// на одном корабле
	SetFoodShipInfo(refCharacter, "FOOD_SHIP");
	SetRumShipInfo(refCharacter,"RUM_SHIP");
	SetFormatedText("MONEY_SHIP", XI_ConvertString("ShipUpkeep") + NewStr() + FindRussianMoneyString(GetSalaryForShip(refCharacter)));	
	SetFormatedText("INFO_SHIP", XI_ConvertString(refBaseShip.BaseName) + ", " + XI_ConvertString("ShipClass") + " " + refBaseShip.Class + ", " + XI_ConvertString("ShipCrew") + XI_ConvertString("CrewMin") + " " + GetMinCrewQuantity(refCharacter) + ", " + XI_ConvertString("CrewMax") + " " + GetOptCrewQuantity(refCharacter));

	////  заполнялка города
	SetCrewExpTable(refTown, "TABLE_CREW2", "BAR_Sailors2", "BAR_Cannoners2", "BAR_Soldiers2");
	
	SetFormatedText("CREW_QTY2", ""+GetCrewQuantity(refTown));
	SetNewGroupPicture("CREW_MORALE_PIC2", "MORALE_SMALL", GetMoraleGroupPicture(stf(refTown.ship.crew.morale)));
	SetFormatedText("CREW_MORALE_TEXT2", XI_ConvertString("CrewMorale") + ": " + XI_ConvertString(GetMoraleName(sti(refTown.Ship.crew.morale))));
	
	iPriceSailor = GetCrewPriceForTavern(refTown.id);
	
	if(IsEquipCharacterByArtefact(pchar, "totem_07")) iPriceSailor = makeint(iPriceSailor/2);
	
	SetFormatedText("TAVERN_PRICE", XI_ConvertString("HirePrice1") + " " + FindRussianMoneyString(iPriceSailor));
}

void ProcessFrame()
{
	if(GetCurrentNode() == "SHIPS_SCROLL")
	{
		if(sti(GameInterface.SHIPS_SCROLL.current)!=nCurScrollNum)
		{
			GetBackupQty(); // если неожиданно вышли
			nCurScrollNum = sti(GameInterface.SHIPS_SCROLL.current);
			SetDescription();
			GameInterface.qty_edit.str = 0;
			SetFormatedText("QTY_TypeOperation", "");
		    SetFormatedText("QTY_Result", "");
		}
	}
}

void SetDescription()
{
 	string sChrId;
 	 
	if(GetCurrentNode() == "SHIPS_SCROLL")
	{
		string attributeName = attributeName = "pic" + (nCurScrollNum+1);
		if(CheckAttribute(&GameInterface, "SHIPS_SCROLL." + attributeName))
		{
			int iCharacter = GameInterface.SHIPS_SCROLL.(attributeName).companionIndex;
			sChrId = characters[iCharacter].id;
			refCharacter = characterFromID(sChrId);
			QtyMax = GetCargoFreeSpace(refCharacter);
			SetBackupQty();
			if (GetRemovable(refCharacter))
			{
			    SetSelectable("QTY_OK_BUTTON", true);
			}
			else
			{
			    SetSelectable("QTY_OK_BUTTON", false);
			}
		}
	}
	SetVariable();
}

void SetShipWeight()
{
    if (CheckAttribute(refCharacter, "Ship.Cargo.RecalculateCargoLoad") && sti(refCharacter.Ship.Cargo.RecalculateCargoLoad))
	{   // остатки с моря
		RecalculateCargoLoad(refCharacter);
		refCharacter.Ship.Cargo.RecalculateCargoLoad = 0;
	}
	fShipWeight  = makeint(GetCargoLoad(refCharacter)+ 0.4);
}

void ShowInfoWindow()
{
	string sCurrentNode = GetCurrentNode();
	string sHeader, sText1, sText2, sText3, sPicture;
	string sGroup, sGroupPicture;
	int iItem;

	sPicture = "-1";
	string sAttributeName;
	int nChooseNum = -1;
	int iShip;
	ref refBaseShip;
	
	bool  bShowHint = true;
	switch (sCurrentNode)
	{
		case "TABLE_CREW":
			sHeader = GetConvertStr("Crew_Exp", "ShipsDescribe.txt");
			sText1  = GetConvertStr("Crew_Exp_hint", "ShipsDescribe.txt");
		break; 
		case "TABLE_CREW2":
			sHeader = GetConvertStr("Crew_Exp", "ShipsDescribe.txt");
			sText1  = GetConvertStr("Crew_Exp_hint", "ShipsDescribe.txt");
		break; 
	}
	if (bShowHint)
	{
		CreateTooltip("#" + sHeader, sText1, argb(255,255,255,255), sText2, argb(255,255,192,192), sText3, argb(255,192,255,192), "", argb(255,255,255,255), sPicture, sGroup, sGroupPicture, 64, 64);
	}
}

void HideInfoWindow()
{
	CloseTooltip();
}
// бакап значений, до применения
void SetBackupQty()
{
	aref    arTo, arFrom;
	NullCharacter.TavernBak.Hero = "";
	NullCharacter.TavernBak.Tavern = "";
	
	makearef(arTo,   NullCharacter.TavernBak.Hero);
	makearef(arFrom, refCharacter.Ship.Crew);
	CopyAttributes(arTo, arFrom);
	
	makearef(arTo,   NullCharacter.TavernBak.Tavern);
	makearef(arFrom, refTown.Ship.Crew);
	CopyAttributes(arTo, arFrom);
}

void GetBackupQty()
{
	aref    arTo, arFrom;
	
	makearef(arFrom,   NullCharacter.TavernBak.Hero);
	makearef(arTo, refCharacter.Ship.Crew);
	CopyAttributes(arTo, arFrom);
	
	makearef(arFrom,   NullCharacter.TavernBak.Tavern);
	makearef(arTo, refTown.Ship.Crew);
	CopyAttributes(arTo, arFrom);
}

void TransactionCancel()
{
	if (sti(GameInterface.qty_edit.str) == 0)
	{   // выход
		ProcessCancelExit();	
	}
	else
	{
		CancelQty();	
    }
}

void CancelQty()
{
	GetBackupQty();	
	SetVariable();
	GameInterface.qty_edit.str = 0;
	SetFormatedText("QTY_TypeOperation", "");
    SetFormatedText("QTY_Result", "");
}
void TransactionOK()
{
	int nTradeQuantity, moneyback;
	confirmChangeQTY_EDIT();
	nTradeQuantity = sti(GameInterface.qty_edit.str);
	if (BuyOrSell == 0)
	{
	    CancelQty();
		return;
	}

    if (!GetRemovable(refCharacter)) return;
    
 	if (BuyOrSell == 1) // BUY  нанять
	{
		moneyback = makeint(iPriceSailor*stf(GameInterface.qty_edit.str));
		pchar.money = sti(pchar.money)  - moneyback;
		RecalculateCargoLoad(refCharacter);
		QtyMax = GetCargoFreeSpace(refCharacter);
		Statistic_AddValue(Pchar, "Money", moneyback);
	}
 	else
	{ // SELL
		RecalculateCargoLoad(refCharacter);
	}
	SetBackupQty(); // применим и согласимся
	CancelQty();
	SetVariable();
}

void confirmChangeQTY_EDIT()
{
	ChangeQTY_EDIT();
    SetCurrentNode("QTY_OK_BUTTON");
}

void ChangeQTY_EDIT()
{
	float fQty;
	GameInterface.qty_edit.str = sti(GameInterface.qty_edit.str); // приведение к целому
	GetBackupQty();	 // обновим как было до правок
	if (sti(GameInterface.qty_edit.str) == 0)
	{
	    SetFormatedText("QTY_TypeOperation", "");
	    SetFormatedText("QTY_Result", "");
	    BuyOrSell = 0;
	}
	else
	{
		if (sti(GameInterface.qty_edit.str) < 0 || BuyOrSell == -1)
		{  // уволить
			if (BuyOrSell != -1)
			{
		    	GameInterface.qty_edit.str = -sti(GameInterface.qty_edit.str);
		    }
            BuyOrSell = -1;
		    // проверка на колво доступное -->
		    if (sti(GameInterface.qty_edit.str) > GetCrewQuantity(refCharacter))
		    {
		        GameInterface.qty_edit.str = GetCrewQuantity(refCharacter);
		    }
			if(refTown.id == "IslaMona")
			{
				if(sti(GameInterface.qty_edit.str) + GetCrewQuantity(refTown) > 300)
				{
					GameInterface.qty_edit.str = 300 - GetCrewQuantity(refTown);
				}
			}
		    // проверка на колво доступное <--
		    SetFormatedText("QTY_TypeOperation", XI_ConvertString("Fire"));
		    SetFormatedText("QTY_Result", "");
		}
		else
		{  // нанять
			BuyOrSell = 1;
         	// проверка на колво доступное -->
		    if (sti(GameInterface.qty_edit.str) > GetCrewQuantity(refTown))
		    {
		        GameInterface.qty_edit.str = GetCrewQuantity(refTown);
		    }
		    if (sti(GameInterface.qty_edit.str) > (GetMaxCrewQuantity(refCharacter) -  GetCrewQuantity(refCharacter)))
		    {
		        GameInterface.qty_edit.str = (GetMaxCrewQuantity(refCharacter) -  GetCrewQuantity(refCharacter));
		    }
		    
		    if (makeint(iPriceSailor*stf(GameInterface.qty_edit.str)) > sti(pchar.money))
		    {
		        GameInterface.qty_edit.str = makeint(sti(pchar.money) / iPriceSailor);
		    }
			
			QtyMax = GetCargoFreeSpace(refCharacter);
			if(QtyMax > 0)
			{
				if(sti(GameInterface.qty_edit.str) >= QtyMax)
				{
					GameInterface.qty_edit.str = QtyMax;
				}
			}
			else GameInterface.qty_edit.str = 0;
						
		    // проверка на колво доступное <--

			SetFormatedText("QTY_TypeOperation", XI_ConvertString("Hire"));
			SetFormatedText("QTY_Result", XI_ConvertString("HirePrice") + " " + FindRussianMoneyString(makeint(iPriceSailor*stf(GameInterface.qty_edit.str))));
		}
		// если получили ноль
		if (sti(GameInterface.qty_edit.str) == 0)
		{
		    SetFormatedText("QTY_TypeOperation", "");
		    SetFormatedText("QTY_Result", "");
		    BuyOrSell = 0;
		}
	}
	if (sti(GameInterface.qty_edit.str) > 0)
	{ // применение кол-ва
		
		if (BuyOrSell == 1)
		{   // найм меняет опыт и мораль корабля
			fQty = stf(GetCrewQuantity(refCharacter) + sti(GameInterface.qty_edit.str));
			refCharacter.Ship.Crew.Exp.Sailors   = (stf(refCharacter.Ship.Crew.Exp.Sailors)*GetCrewQuantity(refCharacter) + 
			                                        stf(refTown.Ship.Crew.Exp.Sailors)*sti(GameInterface.qty_edit.str)) / fQty; 
			refCharacter.Ship.Crew.Exp.Cannoners   = (stf(refCharacter.Ship.Crew.Exp.Cannoners)*GetCrewQuantity(refCharacter) + 
			                                        stf(refTown.Ship.Crew.Exp.Cannoners)*sti(GameInterface.qty_edit.str)) / fQty;
			refCharacter.Ship.Crew.Exp.Soldiers   = (stf(refCharacter.Ship.Crew.Exp.Soldiers)*GetCrewQuantity(refCharacter) + 
			                                        stf(refTown.Ship.Crew.Exp.Soldiers)*sti(GameInterface.qty_edit.str)) / fQty;
			refCharacter.Ship.Crew.Morale   = (stf(refCharacter.Ship.Crew.Morale)*GetCrewQuantity(refCharacter) + 
			                                        stf(refTown.Ship.Crew.Morale)*sti(GameInterface.qty_edit.str)) / fQty;																													                                        
		}
		else
		{ // увольнение меняет таверну
			fQty = stf(GetCrewQuantity(refTown) + sti(GameInterface.qty_edit.str));
			refTown.Ship.Crew.Exp.Sailors   = (stf(refTown.Ship.Crew.Exp.Sailors)*GetCrewQuantity(refTown) + 
			                                        stf(refCharacter.Ship.Crew.Exp.Sailors)*sti(GameInterface.qty_edit.str)) / fQty;
			refTown.Ship.Crew.Exp.Cannoners   = (stf(refTown.Ship.Crew.Exp.Cannoners)*GetCrewQuantity(refTown) + 
			                                        stf(refCharacter.Ship.Crew.Exp.Cannoners)*sti(GameInterface.qty_edit.str)) / fQty;
			refTown.Ship.Crew.Exp.Soldiers   = (stf(refTown.Ship.Crew.Exp.Soldiers)*GetCrewQuantity(refTown) + 
			                                        stf(refCharacter.Ship.Crew.Exp.Soldiers)*sti(GameInterface.qty_edit.str)) / fQty;
			refTown.Ship.Crew.Morale   = (stf(refTown.Ship.Crew.Morale)*GetCrewQuantity(refTown) + 
			                                        stf(refCharacter.Ship.Crew.Morale)*sti(GameInterface.qty_edit.str)) / fQty;
		}
		SetCrewQuantity(refCharacter, GetCrewQuantity(refCharacter) + BuyOrSell*sti(GameInterface.qty_edit.str));
		refTown.Ship.Crew.Quantity = sti(refTown.Ship.Crew.Quantity) - BuyOrSell*sti(GameInterface.qty_edit.str));	
	}
    SetVariable(); // обновим экран
}

void REMOVE_ALL_BUTTON()  // продать все (уволить)
{
	GetBackupQty();	// вернём все как было
	if (!GetRemovable(refCharacter)) return;
	GameInterface.qty_edit.str = -GetCrewQuantity(refCharacter);
	BuyOrSell = 0;
	ChangeQTY_EDIT();
}

void ADD_ALL_BUTTON()  // купить все
{
	GetBackupQty();	// вернём все как было
	if (!GetRemovable(refCharacter)) return;
	GameInterface.qty_edit.str = GetCrewQuantity(refTown);
	BuyOrSell = 0;
	ChangeQTY_EDIT();
}

void REMOVE_BUTTON()  // продать
{
	if (!GetRemovable(refCharacter)) return;
	if (BuyOrSell == 0)
    {
        GameInterface.qty_edit.str = -1;
    }
    else
    {
		if (BuyOrSell == -1)
		{
			GameInterface.qty_edit.str = -(sti(GameInterface.qty_edit.str) + 1);
		}
		else
		{
			GameInterface.qty_edit.str = (sti(GameInterface.qty_edit.str) - 1);
		}
		BuyOrSell = 0;
	}
	ChangeQTY_EDIT();
}

void ADD_BUTTON()  // купить
{
	if (!GetRemovable(refCharacter)) return;
	if (BuyOrSell == 0)
    {
        GameInterface.qty_edit.str = 1;
    }
    else
    {
  		if (BuyOrSell == 1)
		{
			GameInterface.qty_edit.str = (sti(GameInterface.qty_edit.str) + 1);
		}
		else
		{
			GameInterface.qty_edit.str = -(sti(GameInterface.qty_edit.str) - 1);
		}
		BuyOrSell = 0;
	}
	ChangeQTY_EDIT();
}