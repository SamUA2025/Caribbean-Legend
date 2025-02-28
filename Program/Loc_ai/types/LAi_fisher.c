/*
Тип: рыбак, просто рыбачит

	Используемые шаблоны:
		stay
*/



#define LAI_TYPE_FISHER		"fisher"


//Инициализация
void LAi_type_fisher_Init(aref chr)
{
	DeleteAttribute(chr, "location.follower");
	DeleteAttribute(chr, "chr_ai.type");
	chr.chr_ai.type = LAI_TYPE_FISHER;
	LAi_tmpl_stay_InitTemplate(chr);
	//chr.chr_ai.type.SitState = true; //сидим
	//Установим анимацию персонажу
	if(CheckAttribute(chr, "fishersit"))
	{
		LAi_SetFisherSitAnimation(chr);
	}
	//SendMessage(&chr, "lsl", MSG_CHARACTER_EX_MSG, "SetFightWOWeapon", false);
}

//Процессирование типа персонажа
void LAi_type_fisher_CharacterUpdate(aref chr, float dltTime)
{	
	if(chr.chr_ai.tmpl != LAI_TMPL_DIALOG)
	{
		if(rand(1000) == 313)
		{
            // звук не прописан в алиасах
			//LAi_CharacterPlaySound(chr, "governor");
		}
	}
}

//Загрузка персонажа в локацию
bool LAi_type_fisher_CharacterLogin(aref chr)
{
	return true;
}

//Выгрузка персонажа из локацию
bool LAi_type_fisher_CharacterLogoff(aref chr)
{
	return true;
}

//Завершение работы темплейта
void LAi_type_fisher_TemplateComplite(aref chr, string tmpl)
{
	//LAi_tmpl_player_InitTemplate(chr);
}

//Сообщить о желании завести диалог
void LAi_type_fisher_NeedDialog(aref chr, aref by)
{
}

//Запрос на диалог, если возвратить true то в этот момент можно начать диалог
bool LAi_type_fisher_CanDialog(aref chr, aref by)
{
	/* //Если уже говорим, то откажем
	if(chr.chr_ai.tmpl == LAI_TMPL_DIALOG) return false;
	//Согласимся на диалог
	return true; */
	return false;
}

//Начать диалог
void LAi_type_fisher_StartDialog(aref chr, aref by)
{
	//Если мы пасивны, запускаем шаблон без времени завершения
	//LAi_tmpl_stay_InitTemplate(chr);
	//LAi_tmpl_SetActivatedDialog(chr, by);
	//LAi_tmpl_dialog_NoAni(chr);
	//chr.chr_ai.tmpl.firstAnim = 1;
}

//Закончить диалог
void LAi_type_fisher_EndDialog(aref chr, aref by)
{
	/* LAi_tmpl_stay_InitTemplate(chr);
	LAi_SetfisherSitAnimation(chr); */
}

//Персонаж выстрелил
void LAi_type_fisher_Fire(aref attack, aref enemy, float kDist, bool isFindedEnemy)
{
}


//Персонаж атакован
void LAi_type_fisher_Attacked(aref chr, aref by)
{
	
}

//Найти врага
int LAi_type_fisher_FindEnemy(aref chr, int num)
{
	return -1;
}

void SetFisherAnimation(ref character)
{
	character.actions.idle.i1 = "Sit_Fishing_Idle01";
	character.actions.idle.i2 = "Sit_Look_Around";
	character.actions.idle.i3 = "Sit_Scratches";
	character.actions.idle.i4 = "Sit_Look_Right";
	character.actions.idle.i5 = "Sit_Fishing_Idle01";
	character.actions.dead.d1 = "Ground_Death";
	character.actions.dead.d2 = "Ground_Death1";
	character.actions.HitNoFight = "HitNoFightSit";
}

void LAi_SetFisherSitAnimation(aref chr)
{
	BeginChangeCharacterActions(chr);
	SetFisherAnimation(chr);	
	EndChangeCharacterActions(chr);
}

