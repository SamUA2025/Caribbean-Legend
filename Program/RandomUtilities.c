// Движковые: frnd, rand, hrand, wrand_h

float frand(float _x)
{
	return rand(32768) / 32768.0 * _x;
}

float frandSmall(float _x)
{
	return rand(32) / 32.0 * _x;
}

float uniform(float x, float y)
{
  return x + frand(y - x);
}

float uniform_angle(float left, float right) 
{
  return uniform(PI * left / 180.0, PI * right / 180.0);
}

aref GetRandomAttr(aref Lottery)
{
    ref TEV = &Render;

    aref aError;
    makearef(aError, TEV.Error);
    int num = GetAttributesNum(Lottery);
    if (num == 0) return aError;
    return GetAttributeN(Lottery, rand(num-1));
}

string GetRandomAttrName(aref Lottery)
{
    return GetAttributeName(GetRandomAttr(Lottery));
}

//  Из Новых Горизонтов:
//  Return a normally distributed random number with specified mean and standard deviation
//  68% of samples will be within 1 stdev of mean, 95% within 2 stdev's, 99% within 3 stdev's.
//  100% should be within 4.56 stdev's due to frnd() and accuracy of math in this system
//  This is the standard "bell curve"
float RANDNORM2 = 9999.0;
float RandNorm(float mean, float stdev)
{
    float r, u;
    float RandNorm1;

	if (RANDNORM2 != 9999.0)
	{
		float rc = RANDNORM2 * stdev + mean;
		RANDNORM2 = 9999.0;
		return rc;
	}

	r = sqrt(-2.0 * logN(frnd()));	// .000030519 is lowest frnd() (besides zero, 1.2 occurences in 30,000), 4.5601 is largest r
	u = frnd();
	RandNorm1 = r * sin(PIm2 * u);
	RANDNORM2 = r * cos(PIm2 * u);

	return (RandNorm1 * stdev + mean);
}

////////////////////////////////////////////////////////////////////////
//  ROSARAK WEIGHT RANDON
////////////////////////////////////////////////////////////////////////

// Лотерея для целочисленных массивов (она же развесовка)
// Здесь нет проверки валидности, так как массив предварительно подготавливается в WeightRandom
int WeightRandomMethod(ref iMassive)
{
    int i, n;
    int Size = GetArraySize(iMassive);
    int Summ = -1; //чтобы рандомило от 0 до Summ-1
    for(i = 0; i < Size; i++) Summ += iMassive[i];
    /*if(CheckAttribute(&LTR, "WRM"))
    {
        n = hrand(Summ, sti(LTR.WRM.DAYS), LTR.WRM.TAG);
        DeleteAttribute(&LTR, "WRM");
    }
    else */
        n = rand(Summ);
    for(i = 0; n >= 0; i++) n -= iMassive[i]; //Определяем победителя
    return i-1; //После победителя был инкремент, поэтому -1
}

// Подготовка участников лотереи
int WeightRandom(aref Lottery)
{
    ref LTR = &Render;

    aref participant;
    string sNumber; //Для конвертации
    int num = GetAttributesNum(Lottery);
    if(num == 0) return -1; //Нет участников
    int iMassive[2]; //Меньше 2 нельзя!
    int k = 0;
    SetArraySize(&iMassive, num);
    for(int i = 0; i < num; i++)
    {
        participant = GetAttributeN(Lottery,i);
        if(CheckAttribute(participant, "weight") && sti(participant.weight) > 0)
        {
            sNumber = k;
            LTR.LotteryProcess.(sNumber) = i; //Общий номер участника
            iMassive[k] = sti(participant.weight); //Сколько билетов купил
            k++;
        }
    }
    if(k == 0) return -1; //Нет валидных участников
    SetArraySize(&iMassive, k); //Срезаем лишнее
    sNumber = WeightRandomMethod(&iMassive); //Проводим лотерею
    sNumber = LTR.LotteryProcess.(sNumber);
    DeleteAttribute(&LTR, "LotteryProcess");
    return sti(sNumber); //Победил атрибут под номером sNumber!
}

// Получить ссылку на победителя лотереи
aref GetRandomAttrByWeight(aref Lottery)
{
    ref TEV = &Render;

    aref aError;
    makearef(aError, TEV.Error);
    int iWinner = WeightRandom(Lottery);
    if (iWinner == -1) return aError;
    return GetAttributeN(Lottery, iWinner);
}

// Получить имя победителя по названию конкурса
// GetRandomAttrNameByWeight
string wrand(string sLottery)
{
    ref LTR = &Render;

    aref Lottery;
    makearef(Lottery, LTR.(sLottery));
    aref aWinner = GetRandomAttrByWeight(Lottery);
    return GetAttributeName(aWinner);
}

// Для wrand_h, если тэг не указан отдельно, используется название конкурса
// В этом случае также можно добавлять спецсимволы @ и &
/*#event_handler("evntWeightHashRandom","WeightHashRandom");
string WeightHashRandom()
{
    LTR.WRM.DAYS = GetEventData();
    LTR.WRM.TAG  = GetEventData();
    string sLottery = GetEventData();

    if(LTR.WRM.TAG == "")
       LTR.WRM.TAG = sLottery;

    // Удаляем спецсимволы
    int i, iMax = strlen(sLottery);
	string s1, s2 = "";
	for (i = 0; i < iMax; i++)
	{
        s1 = GetSymbol(sLottery, i);
		if (s1 != "@" && s1 != "&")
			s2 += GetSymbol(sLottery, i);
	}
    sLottery = s2;

    return wrand(sLottery);
}*/

// Взятие наибольшего по весу
string GetMaxWeightAttr(string sLottery)
{
    ref LTR = &Render;

    aref Lottery, participant;
    makearef(Lottery, LTR.(sLottery));

    int i, iMax = 0;
    int num = GetAttributesNum(Lottery);
    if(num == 0) return "Error"; //Нет участников
    for(i = 0; i < num; i++)
    {
        participant = GetAttributeN(Lottery,i);
        if(sti(participant.weight) > iMax) iMax = sti(participant.weight);
    }
    if(iMax <= 0) return "Error"; //Нет валидных участников

    int k = 0;
    string sTemp;
    for(i = 0; i < num; i++)
    {
        participant = GetAttributeN(Lottery,i);
        if(sti(participant.weight) == iMax)
        {
            sTemp = k;
            LTR.LotteryProcess.(sTemp) = i; //Общий номер участника
            k++;
        }
    }

    sTemp = rand(k); //Рандом среди равных весов
    sTemp = LTR.LotteryProcess.(sTemp);
    DeleteAttribute(&LTR, "LotteryProcess");

    sTemp = GetAttributeName(GetAttributeN(Lottery, sti(sTemp)));
    CorrectWeightParameters(sLottery, sTemp, "GetMax");
    return sTemp;
}

// Корректировка весов
void CorrectWeightParameters(string sLottery, string Winner, string sCase)
{
    ref LTR = &Render;

    aref Lottery, participant;
    makearef(Lottery, LTR.(sLottery));
    string sTemp;
    int iTemp, i;
    int num = GetAttributesNum(Lottery);

    switch(sCase)
    {
        case "GetMax":
            for(i = 0; i < num; i++)
            {
                participant = GetAttributeN(Lottery,i);
                if(GetAttributeName(participant) == Winner)
                    iTemp = sti(participant.weight) - sti(participant.decrease);
                else
                    iTemp = sti(participant.weight) + sti(participant.increase);
                participant.weight = iClamp(0, sti(participant.weight_max), iTemp);
            }
            break;

        case "Treasure":
            // Выпавший тир
            i = sti(Lottery.(Winner).weight) - 3;
            Lottery.(Winner).weight = iClamp(0, 20, i);
            // Соседи
            iTemp = sti(Lottery.(Winner));
            if(iTemp != 1)
            {
                sTemp = "T" + (iTemp-1);
                i = sti(Lottery.(sTemp).weight) + 1;
                Lottery.(sTemp).weight = iClamp(0, 20, i);
            }
            if(iTemp != 15)
            {
                sTemp = "T" + (iTemp+1);
                i = sti(Lottery.(sTemp).weight) + 1;
                Lottery.(sTemp).weight = iClamp(0, 20, i);
            }
            break;

        case "Winner":
            break;

        case "Daily":
            break;
    }
}

////////////////////////////////////////////////////////////////////////
//  ROSARAK HASH RANDON
////////////////////////////////////////////////////////////////////////
/*
void UpdateSeeds()
{
    aref CallId;
    int iHRands = GetAttributesNum(&HTBL), i;

    GlobalSeed = rand(100000);

    for(i = iHRands-1; i >= 0; i--)
    {
        CallId = GetAttributeN(&HTBL,i);
        if(!CheckAttribute(CallId, "Seed")) continue;
        CallId.dayCount = sti(CallId.dayCount) + 1;
        if(sti(CallId.dayCount) >= sti(CallId.Timer))
           DeleteAttributeN(&HTBL, i); //Оптимизация
    }
}

#event_handler("evntHashRandom","HashRandom");
int HashRandom()
{
    int n = GetEventData();
    int iTimer = GetEventData();
    string tag = GetEventData();
    string callID = GetEventData();

    bool bQueue = HasSubStr(tag, "@"); //Генерировать новое зерно по номеру вызова

    string HRAND_ID;
    if(HasSubStr(tag, "&")) HRAND_ID = tag; //Универсальный тэг
    else HRAND_ID = callID + "_" + tag;

    aref CurCall;
    makearef(CurCall, HTBL.(HRAND_ID));

    float fSeed;
    if(CheckAttribute(CurCall, "Seed"))
    {
        // Таймер не истёк
        if(bQueue) GetCurSeed(CurCall, &fSeed);
        else fSeed = stf(CurCall.Seed);
    }
    else
    {
        GetCurSeed(CurCall, &fSeed);
        CurCall.Seed = fSeed;
        CurCall.Timer = iTimer;
        CurCall.dayCount = 0;
        CurCall.callCount = 0; 
    }

    return MakeInt(fSeed * (n + 1));
}

void GetCurSeed(aref CurCall, ref fSeed)
{
    int iHash;
    if(!CheckAttribute(CurCall, "Seed"))
    {
        //Выбор первого зерна
        iHash = hash(GetAttributeName(CurCall) + GlobalSeed);
    }
    else
    {
        //Выбор нового зерна для очереди (bQueue) 
        CurCall.callCount = sti(CurCall.callCount) + 1;
        iHash = hash(CurCall.callCount + CurCall.Seed);
    }
    fSeed = GetFractionByHash(iHash);
    if(fSeed >= 1.0) fSeed -= 1.0;
}

float GetFractionByHash(int iHash)
{
    iHash = abs(iHash) % 100000; //Последние 5 цифр
    if(iHash < 1) return 0.0;

    string fResult = iHash;
    while(iHash < 10000)
    {
        fResult = "0" + fResult;
        iHash *= 10;
    }
    fResult = "0." + fResult;
    return stf(fResult);
}
*/
////////////////////////////////////////////////////////////////////////
//  ПОКУПКА ЛОТЕРЕЙНЫХ БИЛЕТОВ
////////////////////////////////////////////////////////////////////////

// Первичное выставление весовых параметров в начале игры
void InitWeightParameters()
{
    ref LTR = &Render;

    int i, j;
    string sTemp, sVar;

    // Карты сокровищ
    for(i = 1; i <= 15; i++)
    {
        sTemp = "T" + i;
        LTR.TresuareMapTier.(sTemp) = i;
        LTR.TresuareMapTier.(sTemp).weight = 10;
    }
    // Описания карт сокровищ (shuffle bag)
    for(i = 1; i <= 3; i++)
    {
        sTemp = "T" + i;
        for(j = 1; j <= 3; j++)
        {
            sVar = "v" + j;
            LTR.TresuareMapDescribe.(sTemp).(sVar) = j;
        }
    }
}
