// Warship. Методы для работы с числами
// Большую часть попереносил из других файлов, чтобы все в одном месте было

#define PI 3.14159265
#define PIm2 6.28318530
#define PId2 1.57079632

// Warship 30.07.09. -->
// Рандом 0.0 ... 1.0
float Random()
{
	return rand(32768) / 32768.0; // 65536
}

// Љоммент - не нравится мне cRand() - он возвращает не псевдослучайное число,
// а зависящее от конкретного дня месяца, да ещё и подряд может быть несколько
// одинаковых числе, например, cRand(5) будет давать 5 дней подряд одно и тоже.
// Функция ниже вернет псевдослучайное число, потом запоминает его в PChar и пока не наступит
// новый день будет возвращать его-же. PChar.dayRandom устанавливается в первом шаге обновления дня
int dRand(int _max)
{
    if (_max == 0) { // mitrokosta увидел кучу использований drand(n) где n вполне может быть 0 в LSC_Q2Utilite...
        return 0;
    }

    float dayRandom;
    int dResult;

    if(CheckAttribute(PChar, "dayRandom"))
    {
        dayRandom = stf(PChar.dayRandom);
    } else {
        dayRandom = Random();
        PChar.dayRandom = dayRandom;
    }
	// Hovatham изменить вероятность крайних значений
    dResult = MakeInt(dayRandom * (_max + 1));
    if (dResult > _max) dResult = _max;
	
    return dResult;
}
// <-- Warship 30.07.09

// cRand() - античитовый рандом Эдди. Юзать не рекомендуется, за место него - dRand()
//античитовый рендом
int cRand(int num)
{
	if (num < 1) return 0;
	if (num > 30) return rand(num);
	int sResult = num;
	int iData = GetDataDay();

	int iDel = 30.0 / (num + 1) + 0.5; //делитель месяца
	int step = iDel; //шаг увеличения уровня сравнения в месяце

	for (i=0; i<num; i++)
	{
		if (iData < iDel) 
		{
			sResult = i;
			break;
		}
		else iDel += step;
	}
	return sResult;
}

// Радианы в градусы
float Radian2Degree(float _rad) 
{
	return 180 / PI * _rad;
}

int func_max(int a, int b)
{
	if (a > b) return a;
	return b;
}

int func_min(int a, int b)
{
	if (a > b) return b;
	return a;
}

float func_fmax(float a, float b)
{
	if (a > b) return a;
	return b;
}

float func_fmin(float a, float b)
{
	if (a > b) return b;
	return a;
}


int iClamp(int min, int max, int val)
{
	if(val < min) val = min;
	else
	{
		if(val > max) val = max;
	}
	return val;
}

float fClamp(float min, float max, float val)
{
	if(val < min) val = min;
	else
	{
		if(val > max) val = max;
	}
	return val;
}

int iabs(int num)
{
	if (num < 0)
		return -num;
	else
		return num;
}

// Код ниже взят из Новых Горизонтов с разрешения Питера Боелена, дабы самому не изобретать велосипед
// Natural logarithm
// Useful for normally distributed random numbers among other calcs
float logN(float num)
{
	float e = 2.71828;			// limit of accuracy to keep calcs reasonable
	if (num <= 0) return 0.0;	// can't do logs of negative numbers or zero
	float exp = 0.0;
	while (num > 1.6)			// optimize a bit, probably 1.6 is best here.  Near 2.5 it crashes.
	{
		num = num / e;
		exp = exp + 1.0;
	}
	while (num < 0.2)
	{
		num = num * e;
		exp = exp - 1.0;
	}
	float x = num - 1.0;
	float y = x;
	int i;
	float n = 2.0;
	float z;
	for ( i=1 ; i<100 ; i++ )		// arbitrarily high limit just for safety, normally never goes over 28
	{
		z = y;
		y = y - pow(x,n)/n;
		n = n + 1.0;
		y = y + pow(x,n)/n;
		n = n + 1.0;
		if (z == y) break;
	}
	return y + exp;
}

float log10(float num)
{
	return logN(num) / 2.302585093;	// for log base 10, divide by logN(10)
}

//Mett: универсальная функция для диапазона чисел
void wRange(ref _num, ref _min, ref _max)
{
    if(_num < _min) _num = _min; //мин порог
    if(_num > _max) _num = _max; //макс порог
}

//Mett: диапазон чисел для float
float wRangeFloat(float _num, float _min, float _max)
{
    if(_num < _min) _num = _min; //мин порог
    if(_num > _max) _num = _max; //макс порог
    return _num;
}

//Mett: диапазон чисел для int
int wRangeInt(int _num, int _min, int _max)
{
    if(_num < _min) _num = _min; //мин порог
    if(_num > _max) _num = _max; //макс порог
    return _num;
}

//Mett: расчёт процентов от числа для float
float wPercentFloat(float _num, float _percent)
{
    float _value = _num * _percent * 0.01;
    return _value;
}

//Mett: расчёт процентов от числа для int
int wPercentInt(int _num, int _percent)
{
    int _value = _num * _percent / 100;
    return _value;
}

// belamour Линейная интерполяция
// Bring2Range, Bring2RangeNoCheck
float linear_interpolate(float x, float x1, float y1, float x2, float y2)
{
	// если вдруг за пределами интерполяции
    if (x < x1) return y1;
    if (x > x2) return y2;
	
    return y1 + (x - x1) * (y2 - y1) / (x2 - x1);
}
