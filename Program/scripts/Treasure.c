
// TO_DO: В следующем патче убираем Render и используем нормальные объекты
// object TreasureTiers[15]

extern void InitTreasureTiers();
extern void InitTreasureTiers_Additions(bool SandBoxMode);

void TreasureTiersInit(bool SandBoxMode)
{
	if(LoadSegment("scripts\Treasure_Init.c"))
	{
		InitTreasureTiers();
        InitTreasureTiers_Additions(SandBoxMode)
		UnloadSegment("scripts\Treasure_Init.c");
	}
}

string GetIslandForTreasure()
{
	int iNum, m;
	ref Itm;
	aref arDest, arImt;
	string sAttr;
	
	m = 0;
	string sCurIsland = GetCharacterCurrentIslandId(pchar);
	makearef(arDest, NullCharacter.TravelMap.Islands);
	iNum = GetAttributesNum(arDest);
	
	string sArray[50]; // динамические массивы в Шторме не организуешь :(
	for (int i = 0; i<iNum; i++)
	{
		arImt = GetAttributeN(arDest, i);
		sAttr = GetAttributeName(arImt);
		if(CheckAttribute(&NullCharacter,"TravelMap.Islands." + sAttr + ".Treasure"))
		{
			if(sCurIsland == sAttr || CheckTreasureMaps(sAttr)) continue;
			else
			{
				sArray[m] = sAttr;
				m++;		
			}	
		}
	}
	m = rand(m-1);
	return sArray[m];
}

bool CheckTreasureMaps(string sIsland)
{
	ref Itm;
	
	if(GetCharacterItem(pchar,"mapQuest") > 0)
	{
		itm = ItemsFromID("mapQuest");
		if(CheckAttribute(itm, "MapIslId") && itm.MapIslId == sIsland) return true;
	}		
	if(GetCharacterItem(pchar,"map_full") > 0)
	{
		itm = ItemsFromID("map_full");
		if(CheckAttribute(itm, "MapIslId") && itm.MapIslId == sIsland) return true;
	}
	return false;
}

string GetLocationForTreasure(string island)
{
    int iNum;
	aref arDest, arImt;
	string sAttr;

	makearef(arDest, NullCharacter.TravelMap.Islands.(island).Treasure);
	iNum = GetAttributesNum(arDest);
    iNum = rand(iNum-1);
    
    arImt = GetAttributeN(arDest, iNum);
	return GetAttributeName(arImt);
}

string GetBoxForTreasure(string island, string location)
{
    int iNum;
	aref arDest, arImt;
	string sAttr;

	makearef(arDest, NullCharacter.TravelMap.Islands.(island).Treasure.(location));
	iNum = GetAttributesNum(arDest);
    iNum = rand(iNum-1);
    
    arImt = GetAttributeN(arDest, iNum);
	return GetAttributeValue(arImt);
}

// TO_DO: DEL
void GenerateAdmiralMapsTreasure(ref item, int abl)
{
	if (!CheckAttribute(pchar, "questTemp.AdmiralMap")) return;
	if (rand(abl) == 1)
	{
		string amap = SelectAdmiralMaps();
		if (amap != "") item.BoxTreasure.(amap)	= 1;
	}
}

void FillMapForTreasure(ref item)
{
    item.MapIslId   = GetIslandForTreasure();
    item.MapLocId   = GetLocationForTreasure(item.MapIslId);
    item.MapBoxId   = GetBoxForTreasure(item.MapIslId, item.MapLocId);
    if (!CheckAttribute(Pchar, "GenQuest.TreasureBuild") && rand(15) == 1)
        item.MapTypeIdx = -1; // Подделка 6.25%
    else // TO_DO: Для TreasureBuild можно особые описания добавить
        item.MapTypeIdx = rand(2); // Описание из MapDescribe.txt
    DeleteAttribute(item, "BoxTreasure");

    // Legendary edition - Новая система кладов
    if (sti(item.MapTypeIdx) != -1)
    {
        FillBoxForTreasure(item); // Всё тут
        DeleteAttribute(Pchar, "GenQuest.TreasureBuild");
        Pchar.quest.SetTreasureFromMap.win_condition.l1          = "location";
        Pchar.quest.SetTreasureFromMap.win_condition.l1.location = item.MapLocId;
        Pchar.quest.SetTreasureFromMap.win_condition             = "SetTreasureFromMap";
		Pchar.GenQuest.Treasure.Vario = rand(5); // Определяем событие
		locations[FindLocation(item.MapLocId)].DisableEncounters = true;
    }
}

int GetTresuareTier(int iTier)
{
    ref LTR = &Render;

    aref Lottery;
    makearef(Lottery, LTR.TresuareMap);
    DeleteAttribute(Lottery, "");

    string sTemp = "T" + iTier;
    Lottery.(sTemp).weight = LTR.TresuareMapTier.(sTemp).weight;
    if(iTier != 1)
    {
        sTemp = "T" + (iTier-1);
        Lottery.(sTemp).weight = LTR.TresuareMapTier.(sTemp).weight;
    }
    if(iTier != 15)
    {
        sTemp = "T" + (iTier+1);
        Lottery.(sTemp).weight = LTR.TresuareMapTier.(sTemp).weight;
    }

    sTemp = wrand("TresuareMap");
    CorrectWeightParameters("TresuareMapTier", sTemp, "Treasure");
    return sti(LTR.TresuareMapTier.(sTemp));
}

// Выбрать вещь и выбросить её из пулла
string GetRandEnabledItem(aref aTier, string sType)
{
    ref TEV = &Render;

    string sItem, sTemp;
    aref aType, aItem;
    makearef(aType, aTier.(sType));
    int i, num = GetAttributesNum(aType);
    if(num == 0 && sType == "Quest") return ""; //не осталось квестовых
    DeleteAttribute(&TEV, "RandItem"); //типа динамический массив
    for(i = 0; i < num; i++)
    {
        aItem = GetAttributeN(aType, i);
        if(GetAttributeValue(aItem) == "On")
        {
            sTemp = i; //Safe moment
            TEV.RandItem.(sTemp) = GetAttributeName(aItem);
        }
    }
    makearef(aItem, TEV.RandItem);
    int numItems = GetAttributesNum(aItem);

    // Ни одной вещи не нашлось, нужен ресет пулла
    if(numItems == 0)
    {
        for(i = 0; i < num; i++)
        {
            sItem = GetAttributeName(GetAttributeN(aType, i));
            for(int j = 1; j <= 15; j++)
            {
                sTemp = "T" + j;
                if(CheckAttribute(&Render, sTemp + "." + sType + "." + sItem))
                    Render.(sTemp).(sType).(sItem) = "On";
            }
        }
        // Ещё раз рандомим
        return GetRandEnabledItem(aTier, sType);
    }

    // Рандомим и выкидываем из пулла
    sItem = GetAttributeValue(GetAttributeN(aItem, rand(numItems-1)));
    if(CheckAttribute(&Render, "SingleTreasure." + sItem))
    {
        for(i = 1; i <= 15; i++)
        {
            sTemp = "T" + i;
            DeleteAttribute(&Render, sTemp + "." + sType + "." + sItem);
        }
        DeleteAttribute(&Render, "SingleTreasure." + sItem);
    }
    else
    {
        for(i = 1; i <= 15; i++)
        {
            sTemp = "T" + i;
            if(CheckAttribute(&Render, sTemp + "." + sType + "." + sItem))
                Render.(sTemp).(sType).(sItem) = "Off";
        }
    }
    // Уникальные предметы, которые нужно генерировать
    if(sType == "Equip" && IsGenerableItem(sItem))
    {
        sItem = GetGeneratedItem(sItem);
    }
    return sItem;
}

void FillBoxForTreasure(ref item)
{
    string sTemp;
    int iTier = 0;
    aref aTier;

    if(!CheckAttribute(PChar, "Statistic.Treasure"))
        PChar.Statistic.Treasure = 0;

    // Определяем тир (15 отрезков в диапазоне от 3 до 680)
    iTier += GetCharacterSkill(PChar,SKILL_FORTUNE)*3;                //Везение (min 1)
    iTier += iClamp(0, 12, sti(PChar.Statistic.Treasure))*25;         //Количество найденных кладов
    if(CheckAttribute(PChar,"GenQuest.TreasureBuild")) iTier += 80;   //Сборная карта
    if(CheckCharacterPerk(PChar,"HT2")) iTier += MakeInt(iTier*0.25); //Счетовод
    iTier = iClamp(0, 14, iTier/46);    // Неполное частное от 0 до 14 (ниже +1 будет от 1 до 15)
    iTier = GetTresuareTier(iTier + 1); // Среди соседей взять рандомом по весу
    item.TreasureTier = iTier;

    sTemp = "T" + iTier;
    makearef(aTier, Render.(sTemp));

    // Заполняем
    int iBonus = 0;
    if(CheckCharacterPerk(PChar,"HT2")) iBonus = 25;
    FillBoxForNotes(item); //Записки
    //FillBoxForQuest(item, aTier, iBonus, true);   //Квестовое
    FillBoxForEquip(item, aTier, iBonus, true);   //Экипировка
    FillBoxForJewelry(item, aTier, iBonus, true); //Ценности
    FillBoxForSpecial(item, aTier, iBonus, true); //Специальные предметы
}

void FillBoxForEquip(ref item, aref aTier, int iBonus, bool bOtherSlots)
{
    string itmName = GetRandEnabledItem(aTier, "Equip");
    item.BoxTreasure.(itmName) = 1; // Весь эквип выдаётся штучно
    if(bOtherSlots)
    {
        if(50 + iBonus > rand(99)) FillBoxForEquip(item, aTier, iBonus, false);
        if(25 + iBonus > rand(99)) FillBoxForEquip(item, aTier, iBonus, false);
    }
}

void FillBoxForJewelry(ref item, aref aTier, int iBonus, bool bOtherSlots)
{
    if(bOtherSlots)
    {
        // Золото в первый слот
        item.BoxTreasure.gold = sti(aTier.gold.min) + rand(sti(aTier.gold.dif));
        // Остальные четыре слота
        if(75 + iBonus > rand(99)) FillBoxForJewelry(item, aTier, iBonus, false);
        if(65 + iBonus > rand(99)) FillBoxForJewelry(item, aTier, iBonus, false);
        if(50 + iBonus > rand(99)) FillBoxForJewelry(item, aTier, iBonus, false);
        if(35 + iBonus > rand(99)) FillBoxForJewelry(item, aTier, iBonus, false);
    }
    else
    {
        string itmName = GetRandEnabledItem(aTier, "Jewelry");
        item.BoxTreasure.(itmName) = sti(aTier.Jewelry.(itmName).min) + rand(sti(aTier.Jewelry.(itmName).dif));
    }
}

void FillBoxForSpecial(ref item, aref aTier, int iBonus, bool bOtherSlots)
{
    string itmName = GetRandEnabledItem(aTier, "Special");
    if(itmName == "map" || itmName == "map_a") // Подбор карты
    {
        if(!SandBoxMode && !CheckAttribute(pchar, "questTemp.AdmiralMap"))
            itmName = "map"; // Пока нельзя

        bool bExcellent = (itmName == "map_a");
        int qMiss = MAPS_IN_ATLAS - sti(PChar.MapsAtlasCount); // Сколько на момент генерации не хватало обычных карт
        int qTy = sti(aTier.Special.(itmName).min) + rand(sti(aTier.Special.(itmName).dif));
        for(int i = 0; i < qTy; i++)
        {
            if(bExcellent)
            {
                itmName = SelectAdmiralMaps();
                if(itmName != "")
                {
                    Render.map_a.(itmName) = ""; // Чтобы не генерило одинаковые адмиралки в клад
                    item.BoxTreasure.(itmName) = 1;
                }
                else
                {
                    bExcellent = false;
                    i = 0;
                    qTy = 1 + (qTy - i) * 2; // Адмиралки закончились, выдаём обычные в удвоенном количестве
                    if(qTy > 7) qTy = 7; // Но не более 6-ти (i начнёт с 1)
                }
            }
            else
            {
                itmName = SelectUsualMaps(item, &qMiss);
                if(CheckAttribute(item, "BoxTreasure." + itmName))
                    item.BoxTreasure.(itmName) = sti(item.BoxTreasure.(itmName)) + 1;
                else
                    item.BoxTreasure.(itmName) = 1;
            }
        }
        DeleteAttribute(&Render, "map_a");
    }
    else
    {
        item.BoxTreasure.(itmName) = sti(aTier.Special.(itmName).min) + rand(sti(aTier.Special.(itmName).dif));
    }

    if(bOtherSlots)
    {
        // Половинку карты во второй слот
        if(25 + iBonus > rand(99))
        {
            if (GetCharacterItem(PChar, "map_part1") == 0)
                item.BoxTreasure.map_part1 = 1;
            else if (GetCharacterItem(PChar, "map_part2") == 0)
                item.BoxTreasure.map_part2 = 1;
        }
        // Остальные три слота
        if(65 + iBonus > rand(99)) FillBoxForSpecial(item, aTier, iBonus, false);
        if(35 + iBonus > rand(99)) FillBoxForSpecial(item, aTier, iBonus, false);
        if(15 + iBonus > rand(99)) FillBoxForSpecial(item, aTier, iBonus, false);
    }
}

void FillBoxForNotes(ref item)
{
    string itmName = "";

    string notes[TREASURE_NOTES];
	int i;
    for(i = 0; i < TREASURE_NOTES; i++) notes[i] = "treasure_note_" + (i+1);

    string storeArray[TREASURE_NOTES];
    int howStore = 0;
    string sTemp;

    for (i = 0; i < TREASURE_NOTES; i++)
    {
        sTemp = notes[i];
        if (!CheckAttribute(PChar, "questTemp.Treasure_Stories." + sTemp) && !CheckCharacterItem(PChar, sTemp))
        {
            storeArray[howStore] = sTemp;
            howStore++;
        }
    }

    if (howStore > 0)
        itmName = storeArray[rand(howStore - 1)];

    if(itmName != "")
        item.BoxTreasure.(itmName) = 1;
}

void FillBoxForQuest(ref item, aref aTier, int iBonus, bool bOtherSlots)
{
    string itmName = GetRandEnabledItem(aTier, "Quest");
    if(itmName == "") return;

    item.BoxTreasure.(itmName) = 1;
    /*if(bOtherSlots)
    {
       
    }*/
}

void SetTreasureBoxFromMap()
{
    aref   item;
    ref    loc;
    string box;
    aref   arToBox;
    aref   arFromBox;

    if (GetCharacterItem(Pchar, "map_full")>0 )
    {
        Log_Info(XI_ConvertString("TreasuresNear"));
        PlaySound("interface\notebook.wav");

        // немного веселой жизни
        if (rand(1) == 0) TraderHunterOnMap();
		else CoolTraderHunterOnMap();
        if( CheckAttribute(Pchar,"location.from_sea") )
        {
            if (rand(2) == 1) //33%
            {
                Pchar.quest.SetTreasureHunter.win_condition.l1          = "location";
                Pchar.quest.SetTreasureHunter.win_condition.l1.location = Pchar.location.from_sea;
                Pchar.quest.SetTreasureHunter.win_condition             = "";
                Pchar.quest.SetTreasureHunter.function    = "SetTreasureHunter";
            }
        }

        Items_FindItem("map_full", &item);

        box = item.MapBoxId;

        loc = &locations[FindLocation(item.MapLocId)];
        loc.(box).items = "";

        makearef(arToBox, loc.(box).items);
        makearef(arFromBox, item.BoxTreasure);
        CopyAttributes(arToBox, arFromBox);

        loc.(box) = Items_MakeTime(GetTime(), GetDataDay(), GetDataMonth(), GetDataYear());
        loc.(box).Treasure = sti(item.TreasureTier); // признак сокровища в сундуке; запоминаем тир для ачивки

        DeleteAttribute(item, "MapIslId");
        TakeNItems(Pchar, "map_full", -1);
    }
}

// Погоня за ГГ на карте
void  TraderHunterOnMap()
{
    // Немного веселой жизни
    ref  sld;
    int  i;

    string sCapId = "Follower0";
    string sGroup = "Sea_" + sCapId + "1";

	Group_DeleteGroup(sGroup);
	Group_FindOrCreateGroup(sGroup);
    for (i = 1; i <= GetCompanionQuantity(pchar); i++)
    {
        sld = GetCharacter(NPC_GenerateCharacter(sCapId + i, "off_hol_2", "man", "man", sti(PChar.rank) + 5, PIRATE, 15, true, "hunter"));
        SetShipHunter(sld);
        SetFantomParamHunter(sld); //крутые парни
        SetCaptanModelByEncType(sld, "war");
        sld.AlwaysEnemy = true;
        sld.DontRansackCaptain = true;
        sld.mapEnc.type = "war";
        sld.mapEnc.Name = XI_ConvertString("GentlemenOfFortune");
		sld.hunter = "pirate";
        Group_AddCharacter(sGroup, sCapId + i);
    }

    Group_SetGroupCommander(sGroup, sCapId+ "1");
    Group_SetTaskAttackInMap(sGroup, PLAYER_GROUP);
    Group_LockTask(sGroup);
    Map_CreateWarrior("", sCapId + "1", 8);
}

void CoolTraderHunterOnMap()//Jason, быстрые ДУ
{
    ref  sld;
    int  i;

    string sCapId = "Follower0";
    string sGroup = "Sea_" + sCapId + "1";

	Group_DeleteGroup(sGroup);
	Group_FindOrCreateGroup(sGroup);
    for (i = 1; i <= GetCompanionQuantity(pchar); i++)
    {
        sld = GetCharacter(NPC_GenerateCharacter(sCapId + i, "off_hol_2", "man", "man", sti(PChar.rank) + 8, PIRATE, 15, true, "hunter"));
        SetShipHunter(sld);
        SetFantomParamHunter(sld); //крутые парни
        SetCaptanModelByEncType(sld, "war");
        sld.AlwaysEnemy = true;
        sld.DontRansackCaptain = true;
        sld.mapEnc.type = "war";
        sld.mapEnc.Name = XI_ConvertString("GentlemenOfFortune");
		sld.hunter = "pirate";
        Group_AddCharacter(sGroup, sCapId + i);
    }

    Group_SetGroupCommander(sGroup, sCapId+ "1");
    Group_SetTaskAttackInMap(sGroup, PLAYER_GROUP);
    Group_LockTask(sGroup);
    Map_CreateCoolWarrior("", sCapId + "1", 8);
}

void SetTreasureHunter(string temp)
{
    int    j, i, k;
	string sTemp, sCapId;
	ref    sld;
	bool   ok;

	if (chrDisableReloadToLocation) return; // идёт некий другой квест с запретом выхода
	
    Pchar.GenQuest.Hunter2Pause            = true;
    
    j = GetOfficersQuantity(Pchar) + 2;
    
	sCapId = "LandHunter0";
    sTemp = "LAND_HUNTER";
	ok = true;
	arrayNPCModelHow = 0;
    for (i = 1; i <= j; i++)
    {
        sld = GetCharacter(NPC_GenerateCharacter(sCapId + i, "off_hol_2", "man", "man", sti(PChar.rank) + 5, PIRATE, 0, true, "hunter"));
        SetFantomParamHunter(sld); //крутые парни
        sld.Dialog.CurrentNode = "TreasureHunter";
        sld.dialog.filename = "Hunter_dialog.c";
        sld.greeting = "hunter";
        sld.location = "none"; // вот где порылась собака!!!!!!!!!!!

        SetModelPirate(sld);
        k = 0;
		while (!CheckNPCModelUniq(sld) && k < 10)
		{
		    k++;
			SetModelPirate(sld);
		}
		arrayNPCModel[arrayNPCModelHow] = sld.model;
		arrayNPCModelHow++;
		
        LAi_SetActorTypeNoGroup(sld);
        LAi_SetCheckMinHP(sld, (LAi_GetCharacterHP(sld) - 1), false, "Battle_Hunters_Land");
        if (PlaceCharacter(sld, "goto", "random_must_be_near") == "" && i == 1) // fix если вдруг нет в локации
        {
            ok = false;
            break;
        }
        LAi_ActorFollow(sld, pchar, "", 8.0);
        //LAi_Actor2WaitDialog(sld, pchar); // ждать диалог, но бежать
        LAi_group_MoveCharacter(sld, sTemp);
    }

	LAi_group_SetRelation(sTemp, LAI_GROUP_PLAYER, LAI_GROUP_NEITRAL);
	LAi_group_SetRelation(sTemp, LAI_GROUP_PLAYER_OWN, LAI_GROUP_NEITRAL);

	LAi_group_ClearAllTargets();
	LAi_SetFightModeForOfficers(false);
	if (ok)
    {
        PChar.HunterCost = makeint(sti(Pchar.money) / 5) + rand(20)*1000; //сразу генерим
        PChar.HunterCost.Qty = i;
        PChar.HunterCost.TempHunterType = "";
        sld = characterFromID(sCapId + "1");
        LAi_type_actor_Reset(sld);
        LAi_ActorDialog(sld, pchar, "", 4.0, 0);
		chrDisableReloadToLocation = true;
		DoQuestCheckDelay("OpenTheDoors", 5.0);
    }
}

ref SetFantomSkeletForts(string group, string locator, string enemygroup, string _type)
// _type = "GhostShipCrew"   _type = "ParamHunter"  _type = "none"
{
    string emodel;
    ref    Cr;

    emodel = GetRandSkelModel();

    Cr = LAi_CreateFantomCharacterEx(emodel, "man", group, locator);

    if (Cr.location.locator != "")
    {
		if (_type == "GhostShipCrew" || _type == "ParamHunter")
		{
			SetFantomParamHunter(Cr);
		}
		else
		{
		    SetFantomParam(Cr);
		}
		LAi_SetWarriorType(Cr);
	    LAi_group_MoveCharacter(Cr, enemygroup);
	    LAi_NoRebirthEnable(Cr); //не показывать убитых при входе в локацию
	    LAi_LoginInCaptureTown(Cr, true); // для записи игры
	    if (_type == "GhostShipCrew")
	    {
		    // возможно даёт вылеты от многих трупов Cr.DontClearDead = true;
		    Cr.GhostShipCrew = true;
	    }
    }
    return Cr;
}

string SelectUsualMaps(ref item, ref qMiss) // Выбор обычной неповторяющейся карты
{	
    string sMap = "";
    string map[23];
    map[0] = "map_jam";
    map[1] = "map_cayman";
    map[2] = "map_barbados";
    map[3] = "map_trinidad";
    map[4] = "map_Curacao";
    map[5] = "map_martiniqua";
    map[6] = "map_dominica";
    map[7] = "map_puerto";
    map[8] = "map_cuba";
    map[9] = "map_hisp";
    map[10] = "map_nevis";
    map[11] = "map_guad";
    map[12] = "map_antigua";
    map[13] = "map_TORTUGA";
    map[14] = "map_terks";
    map[15] = "map_sm";
    map[16] = "map_bermudas";
    map[17] = "map_beliz";
    map[18] = "map_santa";
    map[19] = "map_maine_1";
    map[20] = "map_maine_2";
    map[21] = "map_panama";
    map[22] = "map_cumana";

    string storeArray[23];
    int howStore = 0;
    string sTemp;

    if(qMiss > 0)
    {
        for (int i = 0; i < 23; i++)
        {
            sTemp = map[i];
            if (!CheckMainHeroMap(sTemp) && !CheckAttribute(item, "BoxTreasure." + sTemp))
            {
                storeArray[howStore] = sTemp;
                howStore++;
            }
        }
        qMiss--;
    }
    else
        howStore = 23; // У игрока на пару с текущим кладом имеются все карты, теперь можно рандомить любую

    if (howStore > 0)
        sMap = storeArray[rand(howStore - 1)];

    return sMap;
}

void AddQuestItemToTreasures(string itemID,
                             int minTier, int maxTier,
                             int minQty,  int dif,
                             bool bSingle)
{
    if(GetItemIndex(itemID) == -1)
    {
        Log_Info("AddQuestItemToTreasures: BAD IDX FOR ITEM " + itemID + "!");
        return;
    }

    string sTemp;
    for(int i = minTier; i <= maxTier; i++)
    {
        sTemp = "T" + i;
        Render.(sTemp).Quest.(itemID) = "On";
        Render.(sTemp).Quest.(itemID).min = minQty;
        Render.(sTemp).Quest.(itemID).dif = dif;
    }
    if(bSingle) Render.SingleTreasure.(itemID) = "";
}

void RemoveQuestItemFromTreasures(string itemID)
{
    string sTemp;
    for(int i = 1; i <= 15; i++)
    {
        sTemp = "T" + i;
        DeleteAttribute(&Render, sTemp + ".Quest." + itemID);
    }
}
