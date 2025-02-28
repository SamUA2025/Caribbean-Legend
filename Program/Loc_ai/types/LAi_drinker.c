/*
Тип: пьяница, просто бухает

	Используемые шаблоны:
		stay
		sit
*/



#define LAI_TYPE_DRINKER		"drinker"


//Инициализация
void LAi_type_drinker_Init(aref chr)
{
	DeleteAttribute(chr, "location.follower");
	DeleteAttribute(chr, "chr_ai.type");
	chr.chr_ai.type = LAI_TYPE_DRINKER;
	LAi_tmpl_stay_InitTemplate(chr);
	//chr.chr_ai.type.SitState = true; //сидим
	//Установим анимацию персонажу
	if(CheckAttribute(chr, "drinkersit"))
	{
		LAi_SetDrinkerSitAnimation(chr);
	}
	else
	{
		if(CheckAttribute(chr, "drinkersitbench")) LAi_SetDrinkerSitBenchAnimation(chr);
		else LAi_SetDrinkerAnimation(chr);
	}
	//SendMessage(&chr, "lsl", MSG_CHARACTER_EX_MSG, "SetFightWOWeapon", false);
}

//Процессирование типа персонажа
void LAi_type_Drinker_CharacterUpdate(aref chr, float dltTime)
{	
	if(chr.chr_ai.tmpl != LAI_TMPL_DIALOG)
	{
		if(rand(1000) == 313)
		{
            // звук не прописан в алиасах
			LAi_CharacterPlaySound(chr, "drinker_sound");
		}
	}
}

//Загрузка персонажа в локацию
bool LAi_type_Drinker_CharacterLogin(aref chr)
{
	return true;
}

//Выгрузка персонажа из локацию
bool LAi_type_Drinker_CharacterLogoff(aref chr)
{
	return true;
}

//Завершение работы темплейта
void LAi_type_Drinker_TemplateComplite(aref chr, string tmpl)
{
	//LAi_tmpl_player_InitTemplate(chr);
}

//Сообщить о желании завести диалог
void LAi_type_Drinker_NeedDialog(aref chr, aref by)
{
}

//Запрос на диалог, если возвратить true то в этот момент можно начать диалог
bool LAi_type_Drinker_CanDialog(aref chr, aref by)
{
	/* //Если уже говорим, то откажем
	if(chr.chr_ai.tmpl == LAI_TMPL_DIALOG) return false;
	//Согласимся на диалог
	return true; */
	return false;
}

//Начать диалог
void LAi_type_Drinker_StartDialog(aref chr, aref by)
{
	//Если мы пасивны, запускаем шаблон без времени завершения
	//LAi_tmpl_stay_InitTemplate(chr);
	//LAi_tmpl_SetActivatedDialog(chr, by);
	//LAi_tmpl_dialog_NoAni(chr);
	//chr.chr_ai.tmpl.firstAnim = 1;
}

//Закончить диалог
void LAi_type_Drinker_EndDialog(aref chr, aref by)
{
	/* LAi_tmpl_stay_InitTemplate(chr);
	LAi_SetDrinkerSitAnimation(chr); */
}

//Персонаж выстрелил
void LAi_type_Drinker_Fire(aref attack, aref enemy, float kDist, bool isFindedEnemy)
{
}


//Персонаж атакован
void LAi_type_Drinker_Attacked(aref chr, aref by)
{
	
}

//Найти врага
int LAi_type_Drinker_FindEnemy(aref chr, int num)
{
	return -1;
}

void LAi_SetDrinkerAnimation(ref character)
{
	BeginChangeCharacterActions(character);
	character.actions.idle.i1 = "Drink_Stand_1";
	character.actions.idle.i2 = "Drink_Stand_2";
	character.actions.idle.i3 = "Drink_Stand_3";
	character.actions.idle.i4 = "Drink_Stand_4";
	character.actions.idle.i5 = "Drink_Stand_5";
	character.actions.idle.i6 = "Drink_Stand_6";
	character.actions.dead.d1 = "Drink_SitGround_Death";
	character.actions.dead.d2 = "Drink_SitGround_Death";
	character.actions.HitNoFight = "HitNoFightSit";
	EndChangeCharacterActions(character);
}

void LAi_SetDrinkerSitAnimation(ref character)
{
	BeginChangeCharacterActions(character);
	character.actions.idle.i1 = "Drink_SitGround_1";
	character.actions.idle.i2 = "Drink_SitGround_2";
	character.actions.idle.i3 = "Drink_SitGround_3";
	character.actions.idle.i4 = "Drink_SitGround_4";
	character.actions.idle.i5 = "Drink_SitGround_1";
	character.actions.dead.d1 = "Drink_SitGround_Death";
	character.actions.dead.d2 = "Drink_SitGround_Death";
	character.actions.HitNoFight = "HitNoFightSit";
	EndChangeCharacterActions(character);
}

void LAi_SetDrinkerSitBenchAnimation(ref character)
{
	BeginChangeCharacterActions(character);
	character.actions.idle.i1 = "Drink_SitBench_1";
	character.actions.idle.i2 = "Drink_SitBench_2";
	character.actions.idle.i3 = "Drink_SitBench_3";
	character.actions.idle.i4 = "Drink_SitBench_4";
	character.actions.dead.d1 = "Drink_SitBench_Death";
	character.actions.dead.d2 = "Drink_SitBench_Death";
	character.actions.HitNoFight = "HitNoFightSit";
	EndChangeCharacterActions(character);
}

