#include "quests\Sharlie\HollandGambit.c"
#include "quests\Sharlie\SharlieTrial.c"
#include "quests\Sharlie\Saga.c"
#include "quests\Sharlie\SharlieFinal.c"
#include "quests\Sharlie\FMQ.c"
#include "quests\Sharlie\Roger.c"
#include "quests\Sharlie\Patria.c"
#include "quests\Sharlie\GoldenGirl.c"
#include "quests\Sharlie\LongHappy.c"
#include "quests\Sharlie\IslaMona.c"
#include "quests\Sharlie\HelenDrinking.c"
#include "quests\Common_Quests\ChickenGod.c"
#include "quests\Sharlie\CompanionQuests\Tonzag.c"
#include "quests\Sharlie\CompanionQuests\Longway.c"
#include "quests\Sharlie\CompanionQuests\Knippel.c"
#include "quests\Sharlie\CompanionQuests\Duran.c"
#include "quests\Common_Quests\BlackMark.c"
#include "quests\Common_Quests\Slavetrader.c"
#include "quests\Common_Quests\MiniQuests.c"
#include "quests\Common_Quests\DangerousCargo.c"
#include "quests\Common_Quests\RedChieftain.c"
#include "quests\Common_Quests\FalseTrace.c"
#include "quests\Common_Quests\Regatta.c"
#include "quests\Common_Quests\Portugal.c"
#include "quests\Common_Quests\Consumption.c"
#include "quests\Common_Quests\Caleuche.c"

ref		sld, rCharacter;
int     iTemp, i; // нужно для вычислений любых целых (нации)
float   locx, locy, locz;
string  sTemp; // любые строки для вычислений
bool    bOk;

/////////////////////////////////////////////////////////////////////////////////////////////////////////
////  разное с оптимизации   начало
/////////////////////////////////////////////////////////////////////////////////////////////////////////

//освободить флаг на дачу миниквестов
void SmallQuests_free(string qName)
{
	pchar.questTemp.different = "free";
}
//вернуть тип губернаторов обратно в sit после боевки
void MayorSitBack(string qName) 
{
	iTemp = GetCharacterIndex(Pchar.quest.MayorSitBack.mayorId)
	if (iTemp > 0)
	{
		sld = &characters[iTemp];
		sld.location = Pchar.quest.MayorSitBack.locationName;
		sld.location.group = "sit";
		sld.location.locator = Pchar.quest.MayorSitBack.locatorName;
		LAi_SetHuberTypeNoGroup(sld);
		RemoveCharacterEquip(sld, BLADE_ITEM_TYPE);
		RemoveCharacterEquip(sld, GUN_ITEM_TYPE);
	}
}

void SeekShip_Stay(string qName)
{
	sld = &characters[sti(pchar.quest.(qName).Idx)];
	LAi_SetStayType(sld);
}

// belamour legendary edition бессмертные офицеры -->
// снова в строю при смене локации
void RestoreInjOfficerInLoc(string _quest)
{
	ref chr;
	
	for(int n = 0; n < MAX_CHARACTERS; n++)
	{
		makeref(chr, Characters[n]);
		if(CheckAttribute(chr, "OfficerImmortal") && chr.OfficerImmortal == "Injury")
		{
			chr.OfficerImmortal = true;
			if(!IsEntity(&worldMap)) LoginCharacter(chr, pchar.location);
		}
	}
}
// прибавим здоровья, если не максимум
void AddOfficerHealth(string _quest)
{
	int chrindex = strcut(_quest, 14 , strlen(_quest)-1);
	ref chr = GetCharacter(chrindex);
	if(makefloat(chr.Health.HP) < 60.0)
	{
		chr.Health.HP = makefloat(chr.Health.HP) + 2.0;
		if(makefloat(chr.Health.HP) > 59.9) 
		{
			chr.Health.HP = 60.0;
			DeleteAttribute(Pchar, "quest."+_quest+".again");
		}
		else
		{
			PChar.quest.(_quest).win_condition.l1            = "Timer";
			PChar.quest.(_quest).win_condition.l1.date.day   = GetAddingDataDay(0, 0, 1);
			PChar.quest.(_quest).win_condition.l1.date.month = GetAddingDataMonth(0, 0, 1);
			PChar.quest.(_quest).win_condition.l1.date.year  = GetAddingDataYear(0, 0, 1);
			PChar.quest.(_quest).function					 = "AddOfficerHealth"; 
			PChar.quest.(_quest).again = true;
		}
	}
}
// <-- legendary edition

/////////////////////////////////////////////////////////////////////////////////////////////////////////
////  разное с оптимизации   конец
/////////////////////////////////////////////////////////////////////////////////////////////////////////

//---------------------------------- выходки Абрахама Нормана ---------------------------------------------
void Norman_ChangeFesivalFace()
{
	sld = characterFromId("Norman");
	ChangeCharacterAddressGroup(sld, "Pirates_town", "goto", "goto1"); // patch
	sld.model = "Norman_2";
	sld.dialog.currentnode = "norman_fes";
	sld.greeting = "Norman_2";
	SetFunctionTimerCondition("Norman_ChangeUsualFace", 0, 0, 1, false);
}

void Norman_ChangeUsualFace(string qName)
{
	sld = characterFromId("Norman");
	ChangeCharacterAddressGroup(sld, "Pirates_town", "goto", "goto1"); // patch
	sld.model = "Norman_1";
	sld.dialog.currentnode = "norman_us";
	sld.greeting = "Norman_1";
}

void ChangePIRATES()
{
	pchar.SystemInfo.ChangePIRATES = true;
	LaunchCharacter(pchar);
}

// ---------------------------- генератор торговли смолами через Сержио Сальдо -------------------------------
void Oil_PrepareSergio(string qName) // прерывание на Сержио
{
	pchar.quest.Oil_Trinidad.win_condition.l1 = "location";
	pchar.quest.Oil_Trinidad.win_condition.l1.location = "Portspein_town";
	pchar.quest.Oil_Trinidad.function = "Oil_SetSergioTrinidad";
}

void Oil_SetSergioTrinidad(string qName) // Сержио активирует начало
{
	chrDisableReloadToLocation = true;//закрыть локацию
	pchar.GenQuest.Hunter2Pause = true; 
	sld = characterFromId("Sergio");	
	sld.Dialog.currentnode = "Sergio_20";
	GetCharacterPos(pchar, &locx, &locy, &locz);
	ChangeCharacterAddressGroup(sld, "Portspein_town", "goto", LAi_FindNearestLocator("goto", locx, locy, locz));
	LAi_SetActorType(sld);
	LAi_ActorDialog(sld, pchar, "", -1, 0);
}

void Oil_SergioRuntoMayak(string qName) // 
{
	chrDisableReloadToLocation = false;
	sld = characterFromId("Sergio");	
	sld.Dialog.currentnode = "Sergio_26";
	LAi_SetActorType(sld);
	LAi_ActorRunToLocator(sld, "quest", "quest2", "", 10);
	DoQuestFunctionDelay("Oil_SetSergioToMayak", 10.0);
}

void Oil_SetSergioToMayak(string qName) // Сержио на маяке
{
	sld = characterFromId("Sergio");	
	if (CheckAttribute(pchar, "questTemp.OilTrade")) sld.Dialog.currentnode = "oil_trade";
	ChangeCharacterAddressGroup(sld, "Mayak1_Lighthouseroom", "goto", "goto2");
	LAi_SetGuardianType(sld);
	sld.protector = true;
	LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS");
	SetFunctionTimerCondition("Oil_SetSergioToMayakOver", 0, 0, 1, false); // таймер
}

void Oil_SetSergioToMayakOver(string qName) // не пришли - убираем Сержио
{
	if (GetCharacterIndex("Sergio") != -1)
	{
		sld = characterFromId("Sergio");	
		ChangeCharacterAddressGroup(sld, "none", "", "");
	}
}

void Oil_TradeFail(string qName) // прибили квестодателя - конец генератора
{
	DeleteAttribute(pchar, "questTemp.OilTrade");
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////
// Jason ---------------------------------------- Мангароса --------------------------------------------
//////////////////////////////////////////////////////////////////////////////////////////////////////////
void Mangarosa_Start(string qName) //нашли первую травку
{
	AddQuestRecord("Mangarosa", "1");
	pchar.questTemp.Mangarosa = "find";
	pchar.questTemp.Mangarosa.m_count = 0;
	pchar.questTemp.Mangarosa.g_count = 0;
}

void MangarosaEffect(string sEff)
{
	if (CheckAttribute(pchar, "questTemp.Mangarosa.Potion"))
	{
		DeleteAttribute(pchar, "questTemp.Mangarosa.Potion");
		Log_Info(StringFromKey("reaction_functions_1"));
		Log_Info(StringFromKey("reaction_functions_2"));
		Pchar.chr_ai.hp = stf(Pchar.chr_ai.hp)-50;
		LAi_CheckKillCharacter(pchar);
		AddCharacterHealth(pchar, -10); //сносим здоровье
		pchar.chr_ai.poison = 500; // травим
		if (stf(pchar.Health.HP) <= 1) LAi_KillCharacter(pchar);
	}
	else
	{
		Log_Info(StringFromKey("reaction_functions_3"));
		pchar.questTemp.Mangarosa.Potion.(sEff) = true;
		AddCharacterHealth(pchar, 4);
		pchar.quest.Mangarosa_del.win_condition.l1 = "Timer";
		pchar.quest.Mangarosa_del.win_condition.l1.date.hour  = rand(24); // 021012
		pchar.quest.Mangarosa_del.win_condition.l1.date.day   = GetAddingDataDay(0, 0, 1);
		pchar.quest.Mangarosa_del.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 1);
		pchar.quest.Mangarosa_del.win_condition.l1.date.year  = GetAddingDataYear(0, 0, 1);
		pchar.quest.Mangarosa_del.function = "Mangarosa_DeleteEffect";
	}
	RemoveItems(pchar, "mangarosa"+sEff, 1);
	//PlaySound("Ambient\Tavern\glotok_001.wav");
	PlaySound("Ambient\Horror\Fear_breath_01.wav");
}

void Mangarosa_DeleteEffect(string qName) //
{
	PlaySound("interface\notebook.wav");
	Log_Info(StringFromKey("reaction_functions_4"));
	DeleteAttribute(pchar, "questTemp.Mangarosa.Potion");
}

void Colt_Timer(string qName) //
{
	sld = characterFromId("Jino");	
	sld.quest.cartridge = true;
}

//------------------------------------------------ клады ---------------------------------------------------
void Treasure_SetCaribWarrior()
{
	chrDisableReloadToLocation = true;//закрыть локацию
	int iRank = 10+sti(pchar.rank)+makeint(MOD_SKILL_ENEMY_RATE)/2;
	for(int i=1; i<=4; i++)
	{
		sld = GetCharacter(NPC_GenerateCharacter("Treasure_carib_"+i, "canib_"+(rand(5)+1), "man", "man", iRank, PIRATE, 1, true, "native"));
		SetFantomParamFromRank(sld, iRank, true);
		sld.name = GetIndianName(MAN);
		sld.lastname = "";
		LAi_CharacterDisableDialog(sld);
		GetCharacterPos(pchar, &locx, &locy, &locz);
		ChangeCharacterAddressGroup(sld, pchar.location, "monsters", LAi_FindFarFreeLocator("monsters", locx, locy, locz));
		LAi_SetWarriorType(sld);
		LAi_group_MoveCharacter(sld, "EnemyFight");
		LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
		LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
		LAi_group_SetCheck("EnemyFight", "OpenTheDoors");
	}
}

void Treasure_SetBandosWarrior()
{
	chrDisableReloadToLocation = true;//закрыть локацию
	int iRank = 8+sti(pchar.rank)+makeint(MOD_SKILL_ENEMY_RATE)/2;
	for(int i=1; i<=4; i++)
	{
		sld = GetCharacter(NPC_GenerateCharacter("Treasure_bandos_"+i, "citiz_"+(rand(9)+41), "man", "man", iRank, PIRATE, 1, true, "marginal"));
		SetFantomParamFromRank(sld, iRank, true);
		LAi_CharacterDisableDialog(sld);
		GetCharacterPos(pchar, &locx, &locy, &locz);
		ChangeCharacterAddressGroup(sld, pchar.location, "monsters", LAi_FindFarFreeLocator("monsters", locx, locy, locz));
		LAi_SetWarriorType(sld);
		LAi_group_MoveCharacter(sld, "EnemyFight");
		LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
		LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
		LAi_group_SetCheck("EnemyFight", "OpenTheDoors");
	}
}

void Treasure_SetCaptainWarrior(string qName) //
{
	string model;
	int iRank = sti(pchar.rank)+MOD_SKILL_ENEMY_RATE;
	chrDisableReloadToLocation = true;//закрыть локацию
	LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], true);//запретить драться // patch-6
	for(int i=1; i<=4; i++)
	{
		model = "citiz_"+(rand(9)+51);
		if (i > 1) model = "mercen_"+(rand(29)+1);
		sld = GetCharacter(NPC_GenerateCharacter("Treasure_sailor_"+i, model, "man", "man", iRank, PIRATE, 1, true, "soldier"));
		SetFantomParamFromRank(sld, iRank, true);
		sld.Dialog.Filename = "Hunter_dialog.c";
		sld.Dialog.currentnode = "TreasureCaptain";
		sld.greeting = "hunter";
		if (i > 1) LAi_CharacterDisableDialog(sld);
		GetCharacterPos(pchar, &locx, &locy, &locz);
		ChangeCharacterAddressGroup(sld, pchar.location, "goto", LAi_FindFarLocator("goto", locx, locy, locz));
		LAi_SetActorType(sld);
		LAi_ActorDialog(sld, pchar, "", -1, 0);
	}
}

void Treasure_SetOfficerWarrior(string qName) //
{
	string model;
	int iRank = sti(pchar.rank)+MOD_SKILL_ENEMY_RATE;
	int iNation = sti(colonies[FindColony(GetCityNameByIsland(Pchar.curIslandId))].nation);
	if (iNation == "") iNation = drand(3);
	if (iNation > 3) iNation = drand(3); // patch-6
	chrDisableReloadToLocation = true;//закрыть локацию
	LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], true);//запретить драться // patch-6
	for(int i=1; i<=4; i++)
	{
		model = "off_"+NationShortName(iNation)+"_"+(rand(4)+1);
		if (i > 1) model = "sold_"+NationShortName(iNation)+"_"+(rand(7)+1);
		sld = GetCharacter(NPC_GenerateCharacter("Treasure_soldier_"+i, model, "man", "man", iRank, PIRATE, 1, true, "soldier"));
		SetFantomParamFromRank(sld, iRank, true);
		sld.Dialog.Filename = "Hunter_dialog.c";
		sld.Dialog.currentnode = "TreasureOfficer";
		sld.greeting = "patrol";
		if (i > 1) LAi_CharacterDisableDialog(sld);
		GetCharacterPos(pchar, &locx, &locy, &locz);
		ChangeCharacterAddressGroup(sld, pchar.location, "goto", LAi_FindFarLocator("goto", locx, locy, locz));
		LAi_SetActorType(sld);
		LAi_ActorDialog(sld, pchar, "", -1, 0);
	}
}

void TownPirate_battle(string qName) //
{
	bDisableFastReload = false;//открыть переход
	chrDisableReloadToLocation = true;
	for(int i=1; i<=12; i++)
	{
		sld = GetCharacter(NPC_GenerateCharacter("PirateTownAttack_"+i, "citiz_"+(rand(9)+41), "man", "man", 35, PIRATE, 0, true, "soldier"));
		sld.City = "Pirates";
		sld.CityType = "citizen";
		FantomMakeCoolFighter(sld, 35, 100, 100, "blade_10", "pistol1", "bullet", 250);
		LAi_SetWarriorType(sld);
		GetCharacterPos(pchar, &locx, &locy, &locz);
		ChangeCharacterAddressGroup(sld, pchar.location, "goto", LAi_FindNearestLocator("goto", locx, locy, locz));
		LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS");
	}
	SetNationRelation2MainCharacter(PIRATE, RELATION_ENEMY);
	LAi_group_Attack(sld, Pchar);
	DoQuestCheckDelay("OpenTheDoors", 120.0);
}

void ShowNewGameTip(string qName) {
	NewGameTip(pchar.quest.(qName).text);
}

void Verifier_Punishment() // наказание за украденную игру
{
	if (IsVerified()) return;
	DoQuestFunctionDelay("Verifier_Retry", 60.0);
}

void Verifier_Retry(string qName)
{
	if (IsVerified()) return;
	Verify();
	DoQuestFunctionDelay("Verifier_RetryAfter", 60.0);
}

void Verifier_RetryAfter(string qName)
{
	if (IsVerified()) return;
	pchar.quest.Verifier_Punisher.win_condition.l1 = "Location_Type";
	pchar.quest.Verifier_Punisher.win_condition.l1.location_type = "town";
	pchar.quest.Verifier_Punisher.function = "Verifier_Punisher_Delay";
}

void Verifier_Punisher_Delay(string qName)
{
	if (IsVerified()) return;
	ExitProgram();
	/* string sLoc = "FortFrance_";
	string sL = "quest";
	pchar.goldenfleet.loc = sLoc+"_Dungeon";
	pchar.goldenfleet.locat = sLoc+"_Dungeon";
	DoQuestFunctionDelay("Potratil_10_sec", 4.0); */
}

void Potratil_10_sec(string qName)
{
	if (IsVerified()) return;
	Log_Info("Вас осудили за пиратство. Совсем скоро вас ждёт казнь!");
	
	aref from, to;
	makearef(from, pchar.location);
	makearef(to, pchar.Verifier.location);
	CopyAttributes(to, from);
	
	pchar.Verifier.chrDisableReloadToLocation = chrDisableReloadToLocation;
	pchar.Verifier.CannotWait = CheckAttribute(pchar, "GenQuest.CannotWait");
	
	chrDisableReloadToLocation = true;
	pchar.GenQuest.CannotWait = true;
	DoQuestReloadToLocation(pchar.goldenfleet.loc, pchar.goldenfleet.locat, pchar.goldenfleet.locat+"4", "");
}

bool Verifier_OnLoad() {
	if (CheckAttribute(pchar, "Verifier") && IsVerified()) {
		aref from, to;
		makearef(to, pchar.location);
		makearef(from, pchar.Verifier.location);
		CopyAttributes(to, from);
		
		chrDisableReloadToLocation = sti(pchar.Verifier.chrDisableReloadToLocation);
		if (!sti(pchar.Verifier.CannotWait)) {
			DeleteAttribute(pchar, "GenQuest.CannotWait");
		}
		
		DeleteAttribute(pchar, "Verifier");
		return true;
	}
	
	return false;
}

// таймер для торрента
void TorrentEddy(string qName)
{
	//trace("chicken god complete");
	//ExitProgram();
	/* pchar.quest.Torrent_Eddy.win_condition.l1 = "Location_Type";
	pchar.quest.Torrent_Eddy.win_condition.l1.location_type = "town";
	pchar.quest.Torrent_Eddy.function = "TorrentEddy_Delay"; */
}

void TorrentEddy_Delay(string qName)
{
	DoQuestFunctionDelay("BermudQuestHandler", 4.0);
}

void BermudQuestHandler(string qName)
{
	Log_Info("Вас осудили за пиратство. Совсем скоро вас ждёт казнь!");
	
	aref from, to;
	makearef(from, pchar.location);
	makearef(to, pchar.TorrentEddy.location);
	CopyAttributes(to, from);
	
	pchar.TorrentEddy.chrDisableReloadToLocation = chrDisableReloadToLocation;
	pchar.TorrentEddy.CannotWait = CheckAttribute(pchar, "GenQuest.CannotWait");
	
	chrDisableReloadToLocation = true;
	pchar.GenQuest.CannotWait = true;
	DoQuestReloadToLocation("FortFrance_Dungeon", "quest", "quest4", "");
}

void TorrentEddy_Freedom(string qName)
{
	if (CheckAttribute(pchar,"TorrentEddy.CannotWait") && pchar.TorrentEddy.CannotWait == true)
	{
		pchar.GenQuest.CannotWait = true;
	}
	else
	{
		DeleteAttribute(pchar,"GenQuest.CannotWait");
	}
	
	chrDisableReloadToLocation = pchar.TorrentEddy.chrDisableReloadToLocation;
	DoQuestFunctionDelay("TorrentEddy_Restart", 3.0);
	DoQuestReloadToLocation(pchar.TorrentEddy.location, "goto", "goto1", "");
}

void TorrentEddy_Restart(string qName)
{
	DeleteAttribute(pchar,"TorrentEddy");
	SetFunctionTimerCondition("TorrentEddy", 8, 0, 0, false);
}

void mushket8_craft(string qName)
{
	SetAlchemyRecipeKnown("mushket8");
	SetAlchemyRecipeKnown("pistol12");
}

void StartInstantDialogNoType(string id, string node, string fileName)
{
	DialogExit();
	sld = CharacterFromId(id);
	sld.Dialog.Filename = fileName;
	sld.dialog.currentnode = node;
	pchar.InstantDialog = sld.id;
	DoQuestFunctionDelay("InstantDialogNoType", 0);
}

void InstantDialogNoType(string qName)
{
	sld.chr_ai.tmpl.dialog = "";
	sld.chr_ai.tmpl.time = "0";
	sld.chr_ai.tmpl.dlgtime = "-1";
	sld.chr_ai.tmpl.state = "wait";
	DeleteAttribute(sld, "chr_ai.tmpl.poklon");
	LAi_tmpl_dialog_StartDialog(sld, pchar, -1.0);
}

void StartInstantDialog(string id, string node, string fileName)
{
	DialogExit();
	sld = CharacterFromId(id);
	sld.Dialog.Filename = fileName;
	sld.dialog.currentnode = node;
	pchar.InstantDialog = sld.id;
	DoQuestFunctionDelay("InstantDialog", 0);
}

void InstantDialog(string qName)
{
	sld = CharacterFromID(pchar.InstantDialog);
	LAi_SetStayTypeNoGroup(sld);
	LAi_tmpl_SetDialog(sld, pchar, -1.0);
}

void DeleteAllOfficersFromLocation()
{
	int iOfficer = 0;
	if(GetOfficersQuantity(PChar) > 0)
	{
		for (i=1; i<=3; i++)
		{
			iOfficer = GetOfficersIndex(PChar, i);
			if(iOfficer != -1 && iOfficer != nMainCharacterIndex)
			{
				LogoffCharacter(&Characters[iOfficer]);
			}
		}
	}
}

void HideInterface(string qName)
{
	EndBattleLandInterface();
}

void Return_MaryOfficer()
{
	sld = characterFromId("Mary");
	sld.Dialog.Filename = "Quest\LSC\Mary.c";
	sld.Dialog.currentnode = "Mary_officer";
	LAi_SetActorType(sld);
	LAi_ActorFollow(sld, pchar, "", -1);
	LAi_SetOfficerType(sld);
	LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
}

void Return_HelenaOfficer()
{
	sld = characterFromId("Helena");
	sld.Dialog.Filename = "Quest\Saga\Helena.c";
	sld.Dialog.CurrentNode = "Helena_officer";
	LAi_SetActorType(sld);
	LAi_ActorFollow(sld, pchar, "", -1);
	LAi_SetOfficerType(sld);
	LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
}

void Return_TichingituOfficer()
{
	sld = characterFromId("Tichingitu");
	sld.Dialog.Filename = "Quest\Sharlie\Tichingitu.c";
	sld.Dialog.CurrentNode = "Tichingitu_officer";
	LAi_SetActorType(sld);
	LAi_ActorFollow(sld, pchar, "", -1);
	LAi_SetOfficerType(sld);
	LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
}

void Return_TonzagOfficer()
{
	sld = CharacterFromID("Tonzag");
	sld.Dialog.Filename = "Quest\HollandGambit\Tonzag.c";
	sld.dialog.currentnode = "Tonzag_officer";
	LAi_SetActorType(sld);
	LAi_ActorFollow(sld, pchar, "", -1);
	LAi_SetOfficerType(sld);
	LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
}

void Return_KnippelOfficer()
{
	sld = characterFromId("Knippel");
	sld.Dialog.Filename = "Quest\HollandGambit\Knippel.c";
	sld.Dialog.CurrentNode = "Knippel_officer";
	LAi_SetActorType(sld);
	LAi_ActorFollow(sld, pchar, "", -1);
	LAi_SetOfficerType(sld);
	LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
}

void Return_LongwayOfficer()
{
	sld = characterFromId("Longway");
	sld.Dialog.Filename = "Quest\HollandGambit\Longway.c";
	sld.Dialog.CurrentNode = "Longway_officer";
	LAi_SetActorType(sld);
	LAi_ActorFollow(sld, pchar, "", -1);
	LAi_SetOfficerType(sld);
	LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
}

void Return_FolkeOfficer()
{
	sld = characterFromId("Folke");
	sld.Dialog.Filename = "Enc_Officer_dialog.c";
	sld.Dialog.CurrentNode = "hired";
	LAi_SetActorType(sld);
	LAi_ActorFollow(sld, pchar, "", -1);
	LAi_SetOfficerType(sld);
	LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
}

void Return_DurandOfficer()
{
	sld = CharacterFromID("FMQT_mercen");
	sld.Dialog.Filename = "Enc_Officer_dialog.c";
	sld.Dialog.CurrentNode = "hired";
	LAi_SetActorType(sld);
	LAi_ActorFollow(sld, pchar, "", -1);
	LAi_SetOfficerType(sld);
	LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
}

void Return_AvendelOfficer()
{
	sld = CharacterFromID("Avendel");
	sld.Dialog.Filename = "Enc_Officer_dialog.c";
	sld.Dialog.CurrentNode = "hired";
	LAi_SetActorType(sld);
	LAi_ActorFollow(sld, pchar, "", -1);
	LAi_SetOfficerType(sld);
	LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
}

void Return_BakerOfficer()
{
	sld = CharacterFromID("Baker");
	sld.Dialog.Filename = "Quest\Saga\Baker.c";
	sld.dialog.currentnode = "Baker_officer";
	LAi_SetActorType(sld);
	LAi_ActorFollow(sld, pchar, "", -1);
	LAi_SetOfficerType(sld);
	LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
}

void Return_IronsOfficer()
{
	sld = CharacterFromID("Irons");
	sld.dialog.filename = "Quest\BlackMark.c";
	sld.Dialog.CurrentNode = "Irons_officer";
	LAi_SetActorType(sld);
	LAi_ActorFollow(sld, pchar, "", -1);
	LAi_SetOfficerType(sld);
	LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
}