void ExternControlsInit(bool bFirst, bool bClassic)
{
	//Trace("ExternControlsInit");
	if(bFirst)
	{
		ExternInitKeyCodes();
		CI_CreateAndSetControls("", "ICancel", CI_GetKeyCode("VK_ESCAPE"), 0, false);
		CI_CreateAndSetControls("", "IAction", CI_GetKeyCode("VK_SPACE"), 0, false);

		ControlsTreeInit();
		return;
	}

	ExternInitKeyCodes();

	if(bClassic) CI_CreateAndSetControls("", "Map_Best", CI_GetKeyCode("KEY_N"), 0, true); // Отличная карта
	else
	{
		if (MOD_BETTATESTMODE == "On") CI_CreateAndSetControls("", "Map_Best", CI_GetKeyCode("KEY_N"), 0, true); // Отличная карта
	}
	
	CI_CreateAndSetControls("", "BOAL_Control", CI_GetKeyCode("VK_F11"), 0, false);
    CI_CreateAndSetControls("", "BOAL_Control2", CI_GetKeyCode("VK_F12"), 0, false);
    CI_CreateAndSetControls("", "BOAL_SetCamera", CI_GetKeyCode("VK_F10"), 0, false); // Здесь можно прописать команды дебагера для быстрого выполнения в реальном времени
    CI_CreateAndSetControls("", "BOAL_ControF7", CI_GetKeyCode("VK_F7"), 0, false); // убить ближайшего персонажа
    CI_CreateAndSetControls("", "BOAL_ControlDebug", CI_GetKeyCode("VK_INSERT"), 0, false);
    
    CI_CreateAndSetControls("", "TimeScaleFaster", CI_GetKeyCode("VK_ADD"), 0, false);
    CI_CreateAndSetControls("", "TimeScaleSlower", CI_GetKeyCode("VK_SUBTRACT"), 0, false);
	CI_CreateAndSetControls("", "VK_PAUSETimePause", CI_GetKeyCode("VK_PAUSE"), 0, false);
	
	CI_CreateAndSetControls("", "ChangeShowInterface", CI_GetKeyCode("VK_DIVIDE"), 0, true);
	// для тестовых нужд - пока не убирать !!
	CI_CreateAndSetControls("", "TestShipCurrentSea", CI_GetKeyCode("VK_DECIMAL"), 0, true);
	
	if (MOD_BETTATESTMODE == "On")
	{
		CI_CreateAndSetControls("", "BOAL_ControF5", CI_GetKeyCode("VK_F5"), 0, false); //Дамп аттрибутов ближайшего персонажа
		// weather
		CI_CreateAndSetControls("", "WhrPrevWeather", CI_GetKeyCode("VK_L_BREAKE"), 0, false);
		CI_CreateAndSetControls("", "WhrNextWeather", CI_GetKeyCode("VK_R_BREAKE"), 0, false);
		CI_CreateAndSetControls("", "WhrUpdateWeather", CI_GetKeyCode("VK_A_QUOTE"), 0, false);
		//CI_CreateAndSetControls("", "Tele", CI_GetKeyCode("VK_A_POINT"), 0, false);
		
		CI_CreateAndSetControls("", "CoastFoamLB", CI_GetKeyCode("VK_LBUTTON"), 0, true);
		CI_CreateAndSetControls("", "CoastFoamRB", CI_GetKeyCode("VK_RBUTTON"), 0, true);
		CI_CreateAndSetControls("", "CoastFoamINS", CI_GetKeyCode("VK_INSERT"), 0, true);
		CI_CreateAndSetControls("", "CoastFoamDEL", CI_GetKeyCode("VK_DELETE"), 0, true);
		CI_CreateAndSetControls("", "CoastFoamCopy", CI_GetKeyCode("KEY_C"), 0, true);
		CI_CreateAndSetControls("", "FreeCam", CI_GetKeyCode("KEY_0"), 0, true);
	}
	// boal <--

	CI_CreateAndSetControls("", "TimeScale", CI_GetKeyCode("KEY_R"), 0, false);

// Character ===================================================================
	CI_CreateAndSetControls("", "ChrTurnH", 256, 0, false);
	CI_CreateAndSetControls("PrimaryLand", "ChrForward", CI_GetKeyCode("KEY_W"), 0, true);
	CI_CreateAndSetControls("PrimaryLand", "ChrForward2", CI_GetKeyCode("VK_RBUTTON"), 0, true); // вторая команда
	//CI_CreateAndSetControls("PrimaryLand", "ChrJump", CI_GetKeyCode("KEY_T"), 0, true);
	AddControlToGroups("ChrForward", "FightModeControls", "BattleInterfaceControls", "", "");
	CI_CreateAndSetControls("PrimaryLand", "ChrBackward", CI_GetKeyCode("KEY_S"), 0, true);
	AddControlToGroups("ChrBackward", "FightModeControls", "BattleInterfaceControls", "", "");
	CI_CreateAndSetControls("PrimaryLand", "ChrStrafeLeft", CI_GetKeyCode("KEY_A"), 0, true);
	AddControlToGroups("ChrStrafeLeft", "FightModeControls", "BattleInterfaceControls", "", "");
	CI_CreateAndSetControls("PrimaryLand", "ChrStrafeRight", CI_GetKeyCode("KEY_D"), 0, true);
	AddControlToGroups("ChrStrafeRight", "FightModeControls", "BattleInterfaceControls", "", "");
	/* CI_CreateAndSetControls( "PrimaryLand", "ChrTurnHL", CI_GetKeyCode("KEY_A"), 0, true );
	AddControlToGroups("ChrTurnHL", "FightModeControls", "BattleInterfaceControls", "", "");
	CI_CreateAndSetControls( "PrimaryLand", "ChrTurnHR", CI_GetKeyCode("KEY_D"), 0, true );
	AddControlToGroups("ChrTurnHR", "FightModeControls", "BattleInterfaceControls", "", ""); */

    //CI_CreateAndSetControls("PrimaryLand", "ChrRun", CI_GetKeyCode("VK_SHIFT"), USE_AXIS_AS_BUTTON, true);
	//AddControlToGroups("ChrRun", "FightModeControls", "BattleInterfaceControls", "", "");
	CI_CreateAndSetControls("PrimaryLand", "ChrSwitchWalk", CI_GetKeyCode("VK_CAPSLOCK"), 0, true); // evganat - переключатель бега
	MapControlToGroup("ChrSwitchWalk","FightModeControls");
	MapControlToGroup("ChrSwitchWalk","BattleInterfaceControls");
	CI_CreateAndSetControls("PrimaryLand", "ChrSprint", CI_GetKeyCode("VK_SHIFT"), 0, true);
	MapControlToGroup("ChrSprint","FightModeControls");
	MapControlToGroup("ChrSprint","BattleInterfaceControls");

	CI_CreateAndSetControls("PrimaryLand", "ChrFightMode", CI_GetKeyCode("KEY_E"), 0, true);
	// evganat - мушкеты
    CI_CreateAndSetControls( "PrimaryLand", "ChrSwitchFightMode", CI_GetKeyCode("KEY_2"), 0, true );
	MapControlToGroup("ChrSwitchFightMode", "FightModeControls");
	
	// evganat - ПРИЦЕЛИВАНИЕ
	CI_CreateAndSetControls("FightModeControls", "ChrAiming", CI_GetKeyCode("KEY_Q"), 0, true);
	CI_CreateAndSetControls("FightModeControls", "ChrAimingShot", CI_GetKeyCode("VK_LBUTTON"), 0, true);
	
	// evganat - камера
	CI_CreateAndSetControls("PrimaryLand", "SwitchCameraOffset", CI_GetKeyCode("VK_TAB"), 0, true);
	MapControlToGroup("SwitchCameraOffset", "FightModeControls");

	CI_CreateAndSetControls("PrimaryLand", "CharacterCamera_Forward", CI_GetKeyCode("VK_MWHEEL_UP"), 0, true);
	MapControlToGroup("CharacterCamera_Forward", "FightModeControls");
	CI_CreateAndSetControls("PrimaryLand", "CharacterCamera_Backward", CI_GetKeyCode("VK_MWHEEL_DOWN"), 0, true);
	MapControlToGroup("CharacterCamera_Backward", "FightModeControls")

	// CI_CreateAndSetControls( "PrimaryLand", "ChrCamNormalize", CI_GetKeyCode("KEY_Y"), 0, true );
	// fight
	CI_CreateAndSetControls("FightModeControls", "ChrAltAttackBase", CI_GetKeyCode("VK_LBUTTON"), 0, true);   //2
	CI_CreateAndSetControls("FightModeControls", "ChrAttackBreakBase", CI_GetKeyCode("VK_MBUTTON"), 0, true); 
	CI_CreateAndSetControls("FightModeControls", "ChrAttackBase", CI_GetKeyCode("VK_RBUTTON"), 0, true);   //1
	CI_CreateAndSetControls("FightModeControls", "ChrAttackChoseBase", CI_GetKeyCode("VK_SHIFT"), 0, true);
	CI_CreateAndSetControls("FightModeControls", "ChrBlock", CI_GetKeyCode("VK_SPACE"), 0, true);
	//belamour альтернативные клавиши --->
	CI_CreateAndSetControls("FightModeControls", "ChrAttackFient", CI_GetKeyCode("KEY_Z"), 0, true);// финт
	CI_CreateAndSetControls("FightModeControls", "ChrParry", CI_GetKeyCode("KEY_C"), 0, true); //парирование
    //<--- belamour
	CI_CreateAndSetControls("FightModeControls", "ChrFightMode", CI_GetKeyCode("KEY_E"), 0, true);
	MapControlToGroup("ChrFightMode","BattleInterfaceControls");
	CI_CreateAndSetControls("FightModeControls", "ChrFire", CI_GetKeyCode("KEY_Q"), 0, true);
	MapControlToGroup("ChrFire","BattleInterfaceControls");	
    // boal -->
	CI_CreateAndSetControls("PrimaryLand", "BOAL_UsePotion", CI_GetKeyCode("KEY_X"), 0, true); // Warship 13.06.09 Дефолтом перевесил на "C" // belamour всё же на X
	MapControlToGroup("BOAL_UsePotion","FightModeControls");
	// боеприпасы и лечебные зелья
	CI_CreateAndSetControls("PrimaryLand", "BulletChanger", CI_GetKeyCode("KEY_B"), 0, true);
	MapControlToGroup("BulletChanger", "FightModeControls");
	CI_CreateAndSetControls("PrimaryLand", "PotionChanger", CI_GetKeyCode("KEY_X"), 0, true);
	MapControlToGroup("PotionChanger", "FightModeControls");
	MapControlToGroup("PotionChanger", "AltPressedGroup");
	
	// Warship 13.06.09 Выпить противоядие
	CI_CreateAndSetControls("PrimaryLand", "UseAntidote", CI_GetKeyCode("KEY_V"), 0, true);
	MapControlToGroup("UseAntidote", "FightModeControls");
	 // выпить зелье команчей
	if(bClassic) CI_CreateAndSetControls("PrimaryLand", "Ultimate_potion", CI_GetKeyCode("KEY_U"), 0, true);
	else CI_CreateAndSetControls("PrimaryLand", "Ultimate_potion", CI_GetKeyCode("KEY_3"), 0, true);
	MapControlToGroup("Ultimate_potion","BattleInterfaceControls");

    if(bClassic) CI_CreateAndSetControls("PrimaryLand", "BOAL_DeadSearch", CI_GetKeyCode("KEY_1"), 0, true);
    else CI_CreateAndSetControls("PrimaryLand", "BOAL_DeadSearch", CI_GetKeyCode("KEY_F"), 0, true);
	MapControlToGroup("BOAL_DeadSearch","FightModeControls");
	
	// мушкет и клинки
	/* if(bClassic) {
		CI_CreateAndSetControls("PrimaryLand", "HK_Musket",   CI_GetKeyCode("KEY_2"), 0, true);
		CI_CreateAndSetControls("PrimaryLand", "HK_FencingL", CI_GetKeyCode("KEY_3"), 0, true);
		CI_CreateAndSetControls("PrimaryLand", "HK_FencingS", CI_GetKeyCode("KEY_4"), 0, true);
		CI_CreateAndSetControls("PrimaryLand", "HK_FencingH", CI_GetKeyCode("KEY_5"), 0, true);
	} else {
		CI_CreateAndSetControls("PrimaryLand", "HK_Musket",   CI_GetKeyCode("KEY_3"), 0, true);
		CI_CreateAndSetControls("PrimaryLand", "HK_FencingL", CI_GetKeyCode("KEY_4"), 0, true);
		CI_CreateAndSetControls("PrimaryLand", "HK_FencingS", CI_GetKeyCode("KEY_5"), 0, true);
		CI_CreateAndSetControls("PrimaryLand", "HK_FencingH", CI_GetKeyCode("KEY_6"), 0, true);
	}	 */
	
	//  +/- для коротких клавиатур
	CI_CreateAndSetControls("", "TimeScaleFasterBA", CI_GetKeyCode("VK_A_PLUS"), 0, false);
	CI_CreateAndSetControls("", "TimeScaleSlowerBA", CI_GetKeyCode("VK_A_MINUS"), 0, false);
	// <-- belamour		
	
	if(bClassic) CI_CreateAndSetControls("FightModeControls", "BOAL_ActivateRush", CI_GetKeyCode("KEY_F"), 0, true); // boal ярость на суше
	else CI_CreateAndSetControls("FightModeControls", "BOAL_ActivateRush", CI_GetKeyCode("KEY_1"), 0, true);
	// boal <--
	
	//Jonathan A 2009-08-19 -->
	if(bClassic) CI_CreateAndSetControls("PrimaryLand", "OfficersCharge", CI_GetKeyCode("KEY_J"), 0, true);
	else CI_CreateAndSetControls("PrimaryLand", "OfficersCharge", CI_GetKeyCode("KEY_7"), 0, true);
	MapControlToGroup("OfficersCharge","FightModeControls");
	MapControlToGroup("OfficersCharge","BattleInterfaceControls");

	if(bClassic) CI_CreateAndSetControls("PrimaryLand", "OfficersHold", CI_GetKeyCode("KEY_H"), 0, true);
	else CI_CreateAndSetControls("PrimaryLand", "OfficersHold", CI_GetKeyCode("KEY_8"), 0, true);
	MapControlToGroup("OfficersHold","FightModeControls");
	MapControlToGroup("OfficersHold","BattleInterfaceControls");

	if(bClassic) CI_CreateAndSetControls("PrimaryLand", "OfficersFollow", CI_GetKeyCode("KEY_G"), 0, true);
	else CI_CreateAndSetControls("PrimaryLand", "OfficersFollow", CI_GetKeyCode("KEY_9"), 0, true);
	MapControlToGroup("OfficersFollow","FightModeControls");
	MapControlToGroup("OfficersFollow","BattleInterfaceControls");
	// <-- JA
	CI_CreateAndSetControls("", "LanternOnOff", CI_GetKeyCode("KEY_L"), 0, true); // включить/выключить фонарь
	
	CI_CreateAndSetControls("PrimaryLand", "Dolly", CI_GetKeyCode("KEY_T"), 0, true); // активировать телепортацию
	MapControlToGroup("Dolly","BattleInterfaceControls");
	
	//CI_CreateContainer("", "ChrTurnH1", 15.0);
	//MapControlToGroup("ChrTurnH1","FightModeControls");
	//MapControlToGroup("ChrTurnH1","BattleInterfaceControls");
	//AddToContainer("PrimaryLand", "ChrTurnH1", "TmpChrTurn1", CI_GetKeyCode("KEY_D"), 0, false);
	//MapControlToGroup("TmpChrTurn1","FightModeControls");
	//AddToContainer("PrimaryLand", "ChrTurnH1", "TmpChrTurn2", CI_GetKeyCode("KEY_A"), 0, true);
	//MapControlToGroup("TmpChrTurn2","FightModeControls");

	MapControlToGroup("ChrBlock","BattleInterfaceControls");
	

// Ship ========================================================================
	CI_CreateAndSetControls("Sailing3Pers", "Ship_SailUp", CI_GetKeyCode("KEY_W"), 0, true);
	AddControlToGroups("Ship_SailUp", "Sailing1Pers", "WorldMapControls", "", "");
	CI_CreateAndSetControls("Sailing3Pers", "Ship_SailDown", CI_GetKeyCode("KEY_S"), 0, true);
	AddControlToGroups("Ship_SailDown", "Sailing1Pers", "WorldMapControls", "", "");
	CI_CreateAndSetControls("Sailing3Pers", "Ship_TurnLeft", CI_GetKeyCode("KEY_A"), 0, true);
	AddControlToGroups("Ship_TurnLeft", "Sailing1Pers", "WorldMapControls", "", "");
	CI_CreateAndSetControls("Sailing3Pers", "Ship_TurnRight", CI_GetKeyCode("KEY_D"), 0, true);
	AddControlToGroups("Ship_TurnRight", "Sailing1Pers", "WorldMapControls", "", "");
	CI_CreateAndSetControls("Sailing3Pers", "Ship_Fire", CI_GetKeyCode("VK_LBUTTON"), 0, true);
	// MapControlToGroup("Ship_Fire","Sailing1Pers");
	MapControlToGroup("Ship_Fire","Sailing1Pers");
	// belamour дополнительные кнопки для перков и перехода в каюту -->
	// переход в каюту
	CI_CreateAndSetControls("Sailing3Pers","hk_Cabin", CI_GetKeyCode("KEY_C"), 0, true);
	AddControlToGroups("hk_Cabin", "Sailing1Pers", "BattleInterfaceControls", "PrimaryLand", "");
	// рендж пушек
	CI_CreateAndSetControls("Sailing3Pers", "CannonsRange", CI_GetKeyCode("KEY_Q"), 0, true);
	MapControlToGroup("CannonsRange","Sailing1Pers");
	MapControlToGroup("CannonsRange","BattleInterfaceControls");
	// ремонт в бою 
	CI_CreateAndSetControls("Sailing3Pers","hk_InstantRepair", CI_GetKeyCode("KEY_Z"), 0, true);
	MapControlToGroup("hk_InstantRepair","Sailing1Pers");
	MapControlToGroup("hk_InstantRepair","BattleInterfaceControls");
	// неотложный ремонт (10% корпуса)
	CI_CreateAndSetControls("Sailing3Pers","hk_LightRepair", CI_GetKeyCode("KEY_X"), 0, true);
	MapControlToGroup("hk_LightRepair","Sailing1Pers");
	MapControlToGroup("hk_LightRepair","BattleInterfaceControls");
	// манёвренный разворот
	CI_CreateAndSetControls("Sailing3Pers","hk_Turn180", CI_GetKeyCode("KEY_V"), 0, true);
	MapControlToGroup("hk_Turn180","Sailing1Pers");
	MapControlToGroup("hk_Turn180","BattleInterfaceControls");
	// предварительная перезарядка
	CI_CreateAndSetControls("Sailing3Pers","hk_ImmediateReload", CI_GetKeyCode("KEY_B"), 0, true);
	MapControlToGroup("hk_ImmediateReload","Sailing1Pers");
	MapControlToGroup("hk_ImmediateReload","BattleInterfaceControls");
	// hot keys for cannon charge reload
		// Balls
	CI_CreateAndSetControls("Sailing3Pers","hk_charge1", CI_GetKeyCode("KEY_1"), 0, true);
	MapControlToGroup("hk_charge1","Sailing1Pers");
	MapControlToGroup("hk_charge1","BattleInterfaceControls");
		// Grapes
	CI_CreateAndSetControls("Sailing3Pers","hk_charge2", CI_GetKeyCode("KEY_2"), 0, true);
	MapControlToGroup("hk_charge2","Sailing1Pers");
	MapControlToGroup("hk_charge2","BattleInterfaceControls");
		// Knippels
	CI_CreateAndSetControls("Sailing3Pers","hk_charge3", CI_GetKeyCode("KEY_3"), 0, true);
	MapControlToGroup("hk_charge3","Sailing1Pers");
	MapControlToGroup("hk_charge3","BattleInterfaceControls");
		// Bombs
	CI_CreateAndSetControls("Sailing3Pers","hk_charge4", CI_GetKeyCode("KEY_4"), 0, true);
	MapControlToGroup("hk_charge4","Sailing1Pers");
	MapControlToGroup("hk_charge4","BattleInterfaceControls");
	// Эскадре - зарядить ядрами
	CI_CreateAndSetControls("Sailing3Pers", "FLT_LoadBalls", CI_GetKeyCode("KEY_5"), 0, true);
	MapControlToGroup("FLT_LoadBalls","Sailing1Pers");
	MapControlToGroup("FLT_LoadBalls","BattleInterfaceControls");
	// Эскадре - зарядить картечью
	CI_CreateAndSetControls("Sailing3Pers", "FLT_LoadGrapes", CI_GetKeyCode("KEY_6"), 0, true);
	MapControlToGroup("FLT_LoadGrapes","Sailing1Pers");
	MapControlToGroup("FLT_LoadGrapes","BattleInterfaceControls");
	// Эскадре - зарядить книпелями
	CI_CreateAndSetControls("Sailing3Pers", "FLT_LoadChain", CI_GetKeyCode("KEY_7"), 0, true);
	MapControlToGroup("FLT_LoadChain","Sailing1Pers");
	MapControlToGroup("FLT_LoadChain","BattleInterfaceControls");
	// Эскадре - зарядить бомбами
	CI_CreateAndSetControls("Sailing3Pers", "FLT_LoadBombs", CI_GetKeyCode("KEY_8"), 0, true);
	MapControlToGroup("FLT_LoadBombs","Sailing1Pers");
	MapControlToGroup("FLT_LoadBombs","BattleInterfaceControls");
	// Эскадре - свалить
	CI_CreateAndSetControls("Sailing3Pers", "FLT_SailAway", CI_GetKeyCode("KEY_O"), 0, true);
	MapControlToGroup("FLT_SailAway","Sailing1Pers");
	MapControlToGroup("FLT_SailAway","BattleInterfaceControls");
	// Эскадре - паруса в боевое
	CI_CreateAndSetControls("Sailing3Pers", "FLT_LowerSails", CI_GetKeyCode("KEY_L"), 0, true);
	MapControlToGroup("FLT_LowerSails","Sailing1Pers");
	MapControlToGroup("FLT_LowerSails","BattleInterfaceControls");
	// Всем - защита флагмана
	CI_CreateAndSetControls("Sailing3Pers", "FLT_ProtFlagship", CI_GetKeyCode("KEY_P"), 0, true);
	MapControlToGroup("FLT_ProtFlagship","Sailing1Pers");
	MapControlToGroup("FLT_ProtFlagship","BattleInterfaceControls");

	CI_CreateAndSetControls("Sailing3Pers", "MiniMapZoomIn", CI_GetKeyCode("KEY_E"), 0, true);
	MapControlToGroup("MiniMapZoomIn","Sailing1Pers");
	if(bClassic) CI_CreateAndSetControls("Sailing3Pers", "MiniMapZoomOut", CI_GetKeyCode("KEY_F"), 0, true);
	else CI_CreateAndSetControls("Sailing3Pers", "MiniMapZoomOut", CI_GetKeyCode("KEY_T"), 0, true);
	MapControlToGroup("MiniMapZoomOut","Sailing1Pers");	
	if(!bClassic){
		CI_CreateAndSetControls("Sailing3Pers", "BI_MapEnter", CI_GetKeyCode("VK_SPACE"), 0, true);
		MapControlToGroup("BI_MapEnter","Sailing1Pers");
	}
	CI_CreateAndSetControls("Sailing3Pers", "Sea_CameraSwitch", CI_GetKeyCode("VK_TAB"), 0, true);
	MapControlToGroup("Sea_CameraSwitch","Sailing1Pers");

    // Rosarak Зум подзорки
	CI_CreateAndSetControls("Sailing1Pers", "TelescopeMode",    CI_GetKeyCode("VK_CONTROL"),     0, true);
	CI_CreateAndSetControls("Sailing1Pers", "TelescopeZoomIn",  CI_GetKeyCode("VK_MWHEEL_UP"),   0, true);
	CI_CreateAndSetControls("Sailing1Pers", "TelescopeZoomOut", CI_GetKeyCode("VK_MWHEEL_DOWN"), 0, true);
/*
	if (MOD_BETTATESTMODE == "On")
	{
		CI_CreateAndSetControls("Sailing3Pers", "Ship_SetRTime", CI_GetKeyCode("KEY_R"), 0, true);
	}
*/	
	// if (MOD_BETTATESTMODE == "On")
	// {
		// CI_CreateAndSetControls("", "Test_MastFall", CI_GetKeyCode("KEY_Y"), 0, true);
	// }
/*
	CI_CreateAndSetControls("Sailing3Pers", "Ship_GetPosition", CI_GetKeyCode("KEY_V"), 0, true);
	MapControlToGroup("Ship_GetPosition","Sailing1Pers");
*/
// World map ===================================================================
	CI_CreateAndSetControls("", "WMapTurnH", 256, 0, false);
	CI_CreateAndSetControls("", "WMapTurnV", 257, INVERSE_CONTROL, false);
	//SetControlForInverting("WMapTurnV",true);
	CI_CreateAndSetControls("WorldMapControls", "WMapCameraRotate", CI_GetKeyCode("VK_CONTROL"), 0, true);
	//CI_CreateAndSetControls("WorldMapControls", "WMapForward", CI_GetKeyCode("VK_LBUTTON"), 0, true);
	CI_CreateAndSetControls("WorldMapControls", "WMapForward", CI_GetKeyCode("VK_MWHEEL_UP"), 0, true);
	//CI_CreateAndSetControls("WorldMapControls", "WMapBackward", CI_GetKeyCode("VK_RBUTTON"), 0, true);
	CI_CreateAndSetControls("WorldMapControls", "WMapBackward", CI_GetKeyCode("VK_MWHEEL_DOWN"), 0, true);
	CI_CreateAndSetControls("WorldMapControls", "WMapCameraSwitch", CI_GetKeyCode("VK_TAB"), 0, true);
	//CI_CreateAndSetControls("WorldMapControls", "WMapPauseSwitch", CI_GetKeyCode("VK_PAUSE"), 0, true);
	
	// CI_CreateAndSetControls("WorldMapControls", "WMapShipSailUp", CI_GetKeyCode("KEY_W"), 0, true);
	// CI_CreateAndSetControls("WorldMapControls", "WMapShipSailDown", CI_GetKeyCode("KEY_S"), 0, true);
	// CI_CreateAndSetControls("WorldMapControls", "WMapShipTurnLeft", CI_GetKeyCode("KEY_A"), 0, true);
	// CI_CreateAndSetControls("WorldMapControls", "WMapShipTurnRight", CI_GetKeyCode("KEY_D"), 0, true);

	if(bClassic) CI_CreateAndSetControls("WorldMapControls", "WMapCancel", CI_GetKeyCode("VK_SPACE"), 0, true);
	else CI_CreateAndSetControls("WorldMapControls", "WMapCancel", CI_GetKeyCode("KEY_F"), 0, true);
	CI_CreateAndSetControls("WorldMapControls", "WMapSkipEncounter", CI_GetKeyCode("VK_RETURN"), 0, true);
	CI_CreateAndSetControls("WorldMapControls", "WMapGetCoords", CI_GetKeyCode("KEY_C"), 0, true);


// Interface ===================================================================
	// Main interface
	CI_CreateAndSetControls("", "ITurnH", 256, 0, false);
	CI_CreateAndSetControls("", "ITurnV", 257, INVERSE_CONTROL, false);
	CI_CreateAndSetControls("", "ILClick", CI_GetKeyCode("VK_LBUTTON"), 0, false);
	CI_CreateAndSetControls("", "IRClick", CI_GetKeyCode("VK_RBUTTON"), 0, false);
	if(!bClassic) {
		CI_CreateAndSetControls("PrimaryLand", "Interface", CI_GetKeyCode("VK_F2"), 0, false);
		AddControlToGroups("Interface", "Sailing3Pers", "Sailing1Pers", "WorldMapControls", "");
	}
	CI_CreateAndSetControls("Sailing1Pers", "MainMenu", CI_GetKeyCode("VK_ESCAPE"), 0, false);
	AddControlToGroups("MainMenu", "Sailing3Pers", "PrimaryLand", "WorldMapControls", "FightModeControls");
	CI_CreateAndSetControls("", "QuickSave", CI_GetKeyCode("VK_F6"), 0, false);
	CI_CreateAndSetControls("", "QuickLoad", CI_GetKeyCode("VK_F9"), 0, false);
	CI_CreateAndSetControls("", "IStartButton", CI_GetKeyCode("VK_RETURN"), 0, false);
	//CI_CreateAndSetControls("", "IAllCancel", CI_GetKeyCode("VK_BACK"), 0, false);
	CI_CreateAndSetControls("", "ICancel", CI_GetKeyCode("VK_ESCAPE"), 0, false);
	CI_CreateAndSetControls("", "IAction", CI_GetKeyCode("VK_SPACE"), 0, false);
	CI_CreateAndSetControls("", "ILeftShift", CI_GetKeyCode("VK_SHIFT"), 0, false);
	CI_CreateAndSetControls("", "IRightShift", CI_GetKeyCode("VK_SHIFT"), 0, false);
	CI_CreateAndSetControls("", "ShiftUp", CI_GetKeyCode("VK_SHIFT"), INVERSE_CONTROL, false);
	CI_CreateAndSetControls("", "IUp", CI_GetKeyCode("VK_UP"), 0, false);
	CI_CreateAndSetControls("", "IDown", CI_GetKeyCode("VK_DOWN"), 0, false);
	CI_CreateAndSetControls("", "IRight", CI_GetKeyCode("VK_RIGHT"), 0, false);
	CI_CreateAndSetControls("", "ILeft", CI_GetKeyCode("VK_LEFT"), 0, false);
	//CI_CreateAndSetControls("", "IContextHelp", CI_GetKeyCode("VK_CONTROL"), 0, false);
	CI_CreateAndSetControls("MainInterface", "InterfaceGoLeft", CI_GetKeyCode("KEY_Q"), 0, false);
	CI_CreateAndSetControls("MainInterface", "InterfaceGoRight", CI_GetKeyCode("KEY_E"), 0, false);
	CI_CreateAndSetControls("MainInterface", "InterfaceTabSwitch", CI_GetKeyCode("VK_TAB"), 0, false);
	CI_CreateAndSetControls("MainInterface", "InterfaceInfoSwitch", CI_GetKeyCode("KEY_S"), 0, false);

	// controls for instant exit from interface (used by function XI_RegistryExitKey() )
	CI_CreateAndSetControls("", "IExit_F2", CI_GetKeyCode("VK_F2"), 0, false);
	CI_CreateAndSetControls("", "IExit_Escape", CI_GetKeyCode("VK_ESCAPE"), 0, false);
	CI_CreateAndSetControls("", "IExit_F1", CI_GetKeyCode("VK_F1"), 0, false);

	// Battle interface
	CI_CreateAndSetControls("Sailing3Pers", "BICommandsActivate", CI_GetKeyCode("VK_RETURN"), 0, true);
	MapControlToGroup("BICommandsActivate","Sailing1Pers");
	MapControlToGroup("BICommandsActivate","WorldMapControls");
	CI_CreateAndSetControls("PrimaryLand", "LICommandsActivate", CI_GetKeyCode("VK_RETURN"), 0, true);
	MapControlToGroup("LICommandsActivate","FightModeControls");
	CI_CreateAndSetControls("BattleInterfaceControls", "BICommandsConfirm", CI_GetKeyCode("VK_RETURN"), 0, true);
	CI_CreateAndSetControls("BattleInterfaceControls", "BICommandsCancel", CI_GetKeyCode("VK_ESCAPE"), 0, false);
	CI_CreateAndSetControls("BattleInterfaceControls", "BICommandsUp", CI_GetKeyCode("VK_UP"), 0, true);
	AddControlToGroups("BICommandsUp", "PrimaryLand", "FightModeControls", "Sailing3Pers", "Sailing1Pers");
	CI_CreateAndSetControls("BattleInterfaceControls", "BICommandsDown", CI_GetKeyCode("VK_DOWN"), 0, true);
	AddControlToGroups("BICommandsDown", "PrimaryLand", "FightModeControls", "Sailing3Pers", "Sailing1Pers");
	CI_CreateAndSetControls("BattleInterfaceControls", "BICommandsLeft", CI_GetKeyCode("VK_LEFT"), 0, true);
	AddControlToGroups("BICommandsLeft", "PrimaryLand", "FightModeControls", "Sailing3Pers", "Sailing1Pers");
	CI_CreateAndSetControls("BattleInterfaceControls", "BICommandsRight", CI_GetKeyCode("VK_RIGHT"), 0, true);
	AddControlToGroups("BICommandsRight", "PrimaryLand", "FightModeControls", "Sailing3Pers", "Sailing1Pers");
	if(bClassic) CI_CreateAndSetControls("Sailing3Pers", "BIFastCommand", CI_GetKeyCode("VK_SPACE"), 0, true); //VK_F3
	else CI_CreateAndSetControls("Sailing3Pers", "BIFastCommand", CI_GetKeyCode("KEY_F"), 0, true);
	CI_CreateAndSetControls("PrimaryLand", "ChrAction", CI_GetKeyCode("VK_LBUTTON"), 0, true);
	AddControlToGroups("BIFastCommand", "Sailing1Pers", "PrimaryLand", "FightModeControls", "WorldMapControls");
	MapControlToGroup("BIFastCommand","BattleInterfaceControls");

	// <-- belamour
	
// Interface open controls for alternative layout =======================================
	CI_CreateAndSetControls("PrimaryLand", "Alchemy", CI_GetKeyCode("KEY_K"), 0, true); // Алхимия
	MapControlToGroup("Alchemy","BattleInterfaceControls");
	CI_CreateAndSetControls("PrimaryLand", "MapView", CI_GetKeyCode("KEY_M"), 0, true); // Атлас
	MapControlToGroup("MapView","Sailing3Pers");
	MapControlToGroup("MapView","WorldMapControls");

	// sith вкладки меню персонажа --->
	if(bClassic) {
		CI_CreateAndSetControls("PrimaryLand", "Inventory", CI_GetKeyCode("VK_F1"), 0, true); // Инвентарь
		CI_CreateAndSetControls("PrimaryLand", "ShipState", CI_GetKeyCode("VK_F2"), 0, true); // Корабли
		CI_CreateAndSetControls("PrimaryLand", "QuestBook", CI_GetKeyCode("VK_F3"), 0, true); // Журнал
		CI_CreateAndSetControls("PrimaryLand", "Abilities", CI_GetKeyCode("VK_F4"), 0, true); // Навыки
		CI_CreateAndSetControls("PrimaryLand", "Nations", CI_GetKeyCode("VK_F5"), 0, true); // Нации
	} else {
		CI_CreateAndSetControls("PrimaryLand", "Inventory", CI_GetKeyCode("KEY_I"), 0, true);
		CI_CreateAndSetControls("PrimaryLand", "ShipState", CI_GetKeyCode("KEY_H"), 0, true);
		CI_CreateAndSetControls("PrimaryLand", "QuestBook", CI_GetKeyCode("KEY_J"), 0, true);
		CI_CreateAndSetControls("PrimaryLand", "Abilities", CI_GetKeyCode("KEY_U"), 0, true);
		CI_CreateAndSetControls("PrimaryLand", "Nations", CI_GetKeyCode("KEY_N"), 0, true);
	}
	AddControlToGroups("Inventory", "Sailing3Pers", "Sailing1Pers", "WorldMapControls", "");
	AddControlToGroups("ShipState", "Sailing3Pers", "Sailing1Pers", "WorldMapControls", "");
	AddControlToGroups("QuestBook", "Sailing3Pers", "Sailing1Pers", "WorldMapControls", "");
	AddControlToGroups("Abilities", "Sailing3Pers", "Sailing1Pers", "WorldMapControls", "");
	AddControlToGroups("Nations", "Sailing3Pers", "Sailing1Pers", "WorldMapControls", "");
	// <--- sith

	// быстрый переход по заведениям
	CI_CreateAndSetControls("PrimaryLand", "Fast_port", CI_GetKeyCode("VK_NUMPAD1"), 0, true); // VK_BACK
	CI_CreateAndSetControls("PrimaryLand", "Fast_store", CI_GetKeyCode("VK_NUMPAD2"), 0, true);
	CI_CreateAndSetControls("PrimaryLand", "Fast_shipyard", CI_GetKeyCode("VK_NUMPAD3"), 0, true);
	CI_CreateAndSetControls("PrimaryLand", "Fast_tavern", CI_GetKeyCode("VK_NUMPAD4"), 0, true);
	CI_CreateAndSetControls("PrimaryLand", "Fast_townhall", CI_GetKeyCode("VK_NUMPAD5"), 0, true);
	CI_CreateAndSetControls("PrimaryLand", "Fast_bank", CI_GetKeyCode("VK_NUMPAD6"), 0, true);
	CI_CreateAndSetControls("PrimaryLand", "Fast_church", CI_GetKeyCode("VK_NUMPAD7"), 0, true);
	CI_CreateAndSetControls("PrimaryLand", "Fast_brothel", CI_GetKeyCode("VK_NUMPAD8"), 0, true);
	CI_CreateAndSetControls("PrimaryLand", "Fast_portoffice", CI_GetKeyCode("VK_NUMPAD9"), 0, true);
	CI_CreateAndSetControls("PrimaryLand", "Fast_prison", CI_GetKeyCode("VK_NUMPAD0"), 0, true);

	// Cameras =====================================================================
		// character camera
	CI_CreateAndSetControls("", "ChrCamTurnV", 257, 0, false);
	SetControlForInverting("ChrCamTurnV",false);
	CI_CreateAndSetControls("", "ChrCamTurnH", 256, 0, false);
	CI_CreateAndSetControls("", "ChrCamSpecMode", CI_GetKeyCode("VK_CONTROL"), 0, false);
	CI_CreateAndSetControls("", "Turn V", 257, INVERSE_CONTROL, false);
	SetControlForInverting("Turn V",true);
	CI_CreateAndSetControls("", "Turn H", 256, 0, false);
//	CI_CreateAndSetControls("PrimaryLand", "ChrCamCameraSwitch", CI_GetKeyCode("VK_TAB"), 0, true);
	//CI_CreateAndSetControls("PrimaryLand", "ChrCamCameraRadius", CI_GetKeyCode("VK_MWHEEL_UP"), 0, false);
//    MapControlToGroup("ChrCamCameraSwitch","FightModeControls"); // evganat - добавляем таб в бой
		// ship follow camera
	CI_CreateAndSetControls("Sailing3Pers", "ShipCamera_Forward", CI_GetKeyCode("VK_MWHEEL_UP"), 0, true);
	CI_CreateAndSetControls("Sailing3Pers", "ShipCamera_Backward", CI_GetKeyCode("VK_MWHEEL_DOWN"), 0, true);
	CI_CreateAndSetControls("Sailing3Pers", "ShipCamera_Turn_V", 257, INVERSE_CONTROL, false);
	MapControlToGroup("ShipCamera_Turn_V", "BattleInterfaceControls");
	DoControlInvisible("Sailing3Pers", "ShipCamera_Turn_V");
	DoControlInvisible("BattleInterfaceControls", "ShipCamera_Turn_V");	
	SetControlForInverting("ShipCamera_Turn_V",true);
	CI_CreateAndSetControls("Sailing3Pers", "ShipCamera_Turn_H", 256, 0, false);
	MapControlToGroup("ShipCamera_Turn_H", "BattleInterfaceControls");
	DoControlInvisible("Sailing3Pers", "ShipCamera_Turn_H");
	DoControlInvisible("BattleInterfaceControls", "ShipCamera_Turn_H");
		// deck camera
	//Trace("DeckCamera_Turn_V");
	CI_CreateAndSetControls("Sailing1Pers", "DeckCamera_Forward", CI_GetKeyCode("VK_RBUTTON"), 0, true);
	CI_CreateAndSetControls("Sailing1Pers", "DeckCamera_Backward", CI_GetKeyCode("VK_MBUTTON"), 0, true);
	CI_CreateAndSetControls("Sailing1Pers", "DeckCamera_Turn_V", 257, 0, false);
	SetControlForInverting("DeckCamera_Turn_V",false);
	DoControlInvisible("Sailing1Pers", "DeckCamera_Turn_V");
	CI_CreateAndSetControls("Sailing1Pers", "DeckCamera_Turn_H", 256, 0, false);
	DoControlInvisible("Sailing1Pers", "DeckCamera_Turn_H");

		// free camera
	CI_CreateAndSetControls("", "FreeCamera_Turn_V", 257, INVERSE_CONTROL, false);
	SetControlForInverting("FreeCamera_Turn_V",true);
	CI_CreateAndSetControls("", "FreeCamera_Turn_H", 256, 0, false);
	CI_CreateAndSetControls("", "FreeCamera_Forward", CI_GetKeyCode("VK_LBUTTON"), 0, false);  //VK_LBUTTON
	CI_CreateAndSetControls("", "FreeCamera_Backward", CI_GetKeyCode("VK_RBUTTON"), 0, false);   //VK_RBUTTON

// Dialog =====================================================================
	CI_CreateAndSetControls("DialogControls", "DlgAction", CI_GetKeyCode("VK_SPACE"), 0, false);
	CI_CreateAndSetControls("DialogControls", "DlgAction1", CI_GetKeyCode("VK_LBUTTON"), 0, false);   // boal new engine
	CI_CreateAndSetControls("DialogControls", "DlgAction2", CI_GetKeyCode("VK_RETURN"), 0, false);
	CI_CreateAndSetControls("", "DlgCancel", CI_GetKeyCode("VK_ESCAPE"), 0, false);
	CI_CreateAndSetControls("DialogControls", "DlgUp", CI_GetKeyCode("VK_UP"), 0, false);
	CI_CreateAndSetControls("DialogControls", "DlgDown", CI_GetKeyCode("VK_DOWN"), 0, false);
	CI_CreateAndSetControls("DialogControls", "DlgUp2", CI_GetKeyCode("VK_MWHEEL_UP"), 0, false);
	CI_CreateAndSetControls("DialogControls", "DlgDown2", CI_GetKeyCode("VK_MWHEEL_DOWN"), 0, false);
	CI_CreateAndSetControls("DialogControls", "DlgUp3", CI_GetKeyCode("KEY_W"), 0, false);
	CI_CreateAndSetControls("DialogControls", "DlgDown3", CI_GetKeyCode("KEY_S"), 0, false);
	CI_CreateAndSetControls("DialogControls", "DlgScrollUp", CI_GetKeyCode("VK_PRIOR"), 0, false);
	CI_CreateAndSetControls("DialogControls", "DlgScrollDown", CI_GetKeyCode("VK_NEXT"), 0, false);
	
	for (int i = 1; i <= 9; i++) {
		CI_CreateAndSetControls("DialogControls", "DlgActionSel" + i, CI_GetKeyCode("KEY_" + i), 0, false);
	}

	// Net Controls =====================================================================
	CI_CreateAndSetControls("NetShipControls", "Net_Menu", CI_GetKeyCode("VK_ESCAPE"), 0, true);
	CI_CreateAndSetControls("NetShipControls", "Say", CI_GetKeyCode("KEY_Y"), 0, true);
	CI_CreateAndSetControls("NetShipControls", "Team_Say", CI_GetKeyCode("KEY_O"), 0, true);
	CI_CreateAndSetControls("NetShipControls", "Person_Say", CI_GetKeyCode("KEY_T"), 0, true);
	CI_CreateAndSetControls("", "gamestat", CI_GetKeyCode("VK_F1"), 0, true);
	CI_CreateAndSetControls("", "toplist", CI_GetKeyCode("VK_F2"), 0, true);
	//CI_CreateAndSetControls("", "gamechat", CI_GetKeyCode("VK_F3"), 0, true);

	MapControlToGroup("ShipCamera_Turn_H", "NetShipControls");
	MapControlToGroup("ShipCamera_Turn_V", "NetShipControls");

	MapControlToGroup("DeckCamera_Turn_H", "NetShipControls");
	MapControlToGroup("DeckCamera_Turn_V", "NetShipControls");

	MapControlToGroup("BICommandsActivate", "NetShipControls");
	
	// temporary control
	CI_CreateAndSetControls("NetShipControls", "Ship_StartRepair", CI_GetKeyCode("KEY_L"), 0, true);
	
	MapControlToGroup("Ship_TurnLeft", "NetShipControls");
	MapControlToGroup("Ship_TurnRight", "NetShipControls");
	MapControlToGroup("Ship_SailUp", "NetShipControls");
	MapControlToGroup("Ship_SailDown", "NetShipControls");
	MapControlToGroup("Ship_Fire", "NetShipControls");

	MapControlToGroup("Sea_CameraSwitch", "NetShipControls");
	MapControlToGroup("TelescopeIn", "NetShipControls"); //Без зума (TODO)

	MapControlToGroup("hk_charge1", "NetShipControls");
	MapControlToGroup("hk_charge2", "NetShipControls");
	MapControlToGroup("hk_charge3", "NetShipControls");
	MapControlToGroup("hk_charge4", "NetShipControls");

	MapControlToGroup("ShipCamera_Forward", "NetShipControls");
	MapControlToGroup("ShipCamera_Backward", "NetShipControls");
	MapControlToGroup("DeckCamera_Forward", "NetShipControls");
	MapControlToGroup("DeckCamera_Backward", "NetShipControls");
}

void ExternInitKeyCodes()
{
	objControlsState.key_codes.VK_LBUTTON	= 1;
	objControlsState.key_codes.VK_LBUTTON.img = "q";
	objControlsState.key_codes.VK_RBUTTON	= 2;
	objControlsState.key_codes.VK_RBUTTON.img = "w";
	objControlsState.key_codes.VK_BACK		= 8;
	objControlsState.key_codes.VK_BACK.img = "b";
	objControlsState.key_codes.VK_TAB		= 9;
	objControlsState.key_codes.VK_TAB.img = "t";
	objControlsState.key_codes.VK_RETURN	= 13;
	objControlsState.key_codes.VK_RETURN.img = "n";
	objControlsState.key_codes.VK_SHIFT		= 16;
	objControlsState.key_codes.VK_SHIFT.img = "i";
	objControlsState.key_codes.VK_CONTROL	= 17;
	objControlsState.key_codes.VK_CONTROL.img = "c";
	objControlsState.key_codes.VK_ESCAPE	= 27;
	objControlsState.key_codes.VK_ESCAPE.img = "e";
	objControlsState.key_codes.VK_SPACE		= 32;
	objControlsState.key_codes.VK_SPACE.img = "s";
	objControlsState.key_codes.VK_PRIOR		= 33;
	objControlsState.key_codes.VK_PRIOR.img = "p";
	objControlsState.key_codes.VK_NEXT		= 34;
	objControlsState.key_codes.VK_NEXT.img = "j";
	objControlsState.key_codes.VK_LEFT		= 37;
	objControlsState.key_codes.VK_LEFT.img = "l";
	objControlsState.key_codes.VK_UP		= 38;
	objControlsState.key_codes.VK_UP.img = "u";
	objControlsState.key_codes.VK_RIGHT		= 39;
	objControlsState.key_codes.VK_RIGHT.img = "r";
	objControlsState.key_codes.VK_DOWN		= 40;
	objControlsState.key_codes.VK_DOWN.img = "d";
	objControlsState.key_codes.VK_INSERT	= 45;
	objControlsState.key_codes.VK_INSERT.img = "r";
	objControlsState.key_codes.VK_DELETE	= 46;
	objControlsState.key_codes.VK_DELETE.img = "d";

	objControlsState.key_codes.KEY_0 = 48;
	objControlsState.key_codes.KEY_0.img = "0";
	objControlsState.key_codes.KEY_1 = 49;
	objControlsState.key_codes.KEY_1.img = "1";
	objControlsState.key_codes.KEY_2 = 50;
	objControlsState.key_codes.KEY_2.img = "2";
	objControlsState.key_codes.KEY_3 = 51;
	objControlsState.key_codes.KEY_3.img = "3";
	objControlsState.key_codes.KEY_4 = 52;
	objControlsState.key_codes.KEY_4.img = "4";
	objControlsState.key_codes.KEY_5 = 53;
	objControlsState.key_codes.KEY_5.img = "5";
	objControlsState.key_codes.KEY_6 = 54;
	objControlsState.key_codes.KEY_6.img = "6";
	objControlsState.key_codes.KEY_7 = 55;
	objControlsState.key_codes.KEY_7.img = "7";
	objControlsState.key_codes.KEY_8 = 56;
	objControlsState.key_codes.KEY_8.img = "8";
	objControlsState.key_codes.KEY_9 = 57;
	objControlsState.key_codes.KEY_9.img = "9";

	objControlsState.key_codes.KEY_A = 65;
	objControlsState.key_codes.KEY_A.img = "A";
	objControlsState.key_codes.KEY_B = 66;
	objControlsState.key_codes.KEY_B.img = "B";
	objControlsState.key_codes.KEY_C = 67;
	objControlsState.key_codes.KEY_C.img = "C";
	objControlsState.key_codes.KEY_D = 68;
	objControlsState.key_codes.KEY_D.img = "D";
	objControlsState.key_codes.KEY_E = 69;
	objControlsState.key_codes.KEY_E.img = "E";
	objControlsState.key_codes.KEY_F = 70;
	objControlsState.key_codes.KEY_F.img = "F";
	objControlsState.key_codes.KEY_G = 71;
	objControlsState.key_codes.KEY_G.img = "G";
	objControlsState.key_codes.KEY_H = 72;
	objControlsState.key_codes.KEY_H.img = "H";
	objControlsState.key_codes.KEY_I = 73;
	objControlsState.key_codes.KEY_I.img = "I";
	objControlsState.key_codes.KEY_J = 74;
	objControlsState.key_codes.KEY_J.img = "J";
	objControlsState.key_codes.KEY_K = 75;
	objControlsState.key_codes.KEY_K.img = "K";
	objControlsState.key_codes.KEY_L = 76;
	objControlsState.key_codes.KEY_L.img = "L";
	objControlsState.key_codes.KEY_M = 77;
	objControlsState.key_codes.KEY_M.img = "M";
	objControlsState.key_codes.KEY_N = 78;
	objControlsState.key_codes.KEY_N.img = "N";
	objControlsState.key_codes.KEY_O = 79;
	objControlsState.key_codes.KEY_O.img = "O";
	objControlsState.key_codes.KEY_P = 80;
	objControlsState.key_codes.KEY_P.img = "P";
	objControlsState.key_codes.KEY_Q = 81;
	objControlsState.key_codes.KEY_Q.img = "Q";
	objControlsState.key_codes.KEY_R = 82;
	objControlsState.key_codes.KEY_R.img = "R";
	objControlsState.key_codes.KEY_S = 83;
	objControlsState.key_codes.KEY_S.img = "S";
	objControlsState.key_codes.KEY_T = 84;
	objControlsState.key_codes.KEY_T.img = "T";
	objControlsState.key_codes.KEY_U = 85;
	objControlsState.key_codes.KEY_U.img = "U";
	objControlsState.key_codes.KEY_V = 86;
	objControlsState.key_codes.KEY_V.img = "V";
	objControlsState.key_codes.KEY_W = 87;
	objControlsState.key_codes.KEY_W.img = "W";
	objControlsState.key_codes.KEY_X = 88;
	objControlsState.key_codes.KEY_X.img = "X";
	objControlsState.key_codes.KEY_Y = 89;
	objControlsState.key_codes.KEY_Y.img = "Y";
	objControlsState.key_codes.KEY_Z = 90;
	objControlsState.key_codes.KEY_Z.img = "Z";

	objControlsState.key_codes.VK_NUMPAD0	= 96;
	objControlsState.key_codes.VK_NUMPAD0.img = ")";
	objControlsState.key_codes.VK_NUMPAD1	= 97;
	objControlsState.key_codes.VK_NUMPAD1.img = "!";
	objControlsState.key_codes.VK_NUMPAD2	= 98;
	objControlsState.key_codes.VK_NUMPAD2.img = "@";
	objControlsState.key_codes.VK_NUMPAD3	= 99;
	objControlsState.key_codes.VK_NUMPAD3.img = "#";
	objControlsState.key_codes.VK_NUMPAD4	= 100;
	objControlsState.key_codes.VK_NUMPAD4.img = "$";
	objControlsState.key_codes.VK_NUMPAD5	= 101;
	objControlsState.key_codes.VK_NUMPAD5.img = "%";
	objControlsState.key_codes.VK_NUMPAD6	= 102;
	objControlsState.key_codes.VK_NUMPAD6.img = "^";
	objControlsState.key_codes.VK_NUMPAD7	= 103;
	objControlsState.key_codes.VK_NUMPAD7.img = "&";
	objControlsState.key_codes.VK_NUMPAD8	= 104;
	objControlsState.key_codes.VK_NUMPAD8.img = "*";
	objControlsState.key_codes.VK_NUMPAD9	= 105;
	objControlsState.key_codes.VK_NUMPAD9.img = "(";
	objControlsState.key_codes.VK_MULTIPLY	= 106;
	objControlsState.key_codes.VK_MULTIPLY.img = "m";
	objControlsState.key_codes.VK_ADD		= 107;
	objControlsState.key_codes.VK_ADD.img = "+";
	objControlsState.key_codes.VK_SEPARATOR	= 108;
	objControlsState.key_codes.VK_SEPARATOR.img = "_";
	objControlsState.key_codes.VK_SUBTRACT	= 109;
	objControlsState.key_codes.VK_SUBTRACT.img = "-";
	objControlsState.key_codes.VK_DECIMAL	= 110;
	objControlsState.key_codes.VK_DECIMAL.img = ".";
	objControlsState.key_codes.VK_DIVIDE	= 111;
	objControlsState.key_codes.VK_DIVIDE.img = "/";
	objControlsState.key_codes.VK_F1		= 112;
	objControlsState.key_codes.VK_F1.img = "z";
	objControlsState.key_codes.VK_F2		= 113;
	objControlsState.key_codes.VK_F2.img = "x";
	objControlsState.key_codes.VK_F3		= 114;
	objControlsState.key_codes.VK_F3.img = "v";
	objControlsState.key_codes.VK_F4		= 115;
	objControlsState.key_codes.VK_F4.img = "<";
	objControlsState.key_codes.VK_F5		= 116;
	objControlsState.key_codes.VK_F5.img = "f";
	objControlsState.key_codes.VK_F6		= 117;
	objControlsState.key_codes.VK_F6.img = "";
	objControlsState.key_codes.VK_F7		= 118;
	objControlsState.key_codes.VK_F7.img = "";
	objControlsState.key_codes.VK_F8		= 119;
	objControlsState.key_codes.VK_F8.img = "";
	objControlsState.key_codes.VK_F9		= 120;
	objControlsState.key_codes.VK_F9.img = "";

	objControlsState.key_codes.VK_TURN_H	= 256;
	objControlsState.key_codes.VK_TURN_H.img = ">";
	objControlsState.key_codes.VK_TURN_V	= 257;
	objControlsState.key_codes.VK_TURN_V.img = ">";
	objControlsState.key_codes.VK_MWHEEL_UP		= 258;
	objControlsState.key_codes.VK_MWHEEL_UP.img = ">";
	objControlsState.key_codes.VK_MWHEEL_DOWN	= 259;
	objControlsState.key_codes.VK_MWHEEL_DOWN.img = ">";
	
	// boal -->
	objControlsState.key_codes.VK_MBUTTON	= 4;
	objControlsState.key_codes.VK_MBUTTON.img = ">";
	objControlsState.key_codes.VK_F10		= 121;
	objControlsState.key_codes.VK_F10.img = "z";
    objControlsState.key_codes.VK_F11		= 122;
	objControlsState.key_codes.VK_F11.img = "z";
    objControlsState.key_codes.VK_F12		= 123;
	objControlsState.key_codes.VK_F12.img = "z";
	objControlsState.key_codes.VK_PAUSE	= 19;
	objControlsState.key_codes.VK_PAUSE.img = "z";
	
	objControlsState.key_codes.VK_L_BREAKE		= 219;   //[ {
	objControlsState.key_codes.VK_L_BREAKE.img = "s";
	objControlsState.key_codes.VK_R_BREAKE		= 221;   //[ {
	objControlsState.key_codes.VK_R_BREAKE.img = "s";
	objControlsState.key_codes.VK_A_POINT		= 186;  //; :
	objControlsState.key_codes.VK_A_POINT.img = "s";
	objControlsState.key_codes.VK_A_QUOTE		= 222;  //' "
	objControlsState.key_codes.VK_A_QUOTE.img = "s";
	objControlsState.key_codes.VK_A_SMALL		= 188;  //, <
	objControlsState.key_codes.VK_A_SMALL.img = "s";
	objControlsState.key_codes.VK_A_BIG		= 190;  //. >
	objControlsState.key_codes.VK_A_BIG.img = "s";
	objControlsState.key_codes.VK_A_QWS	    = 191;  //?/
	objControlsState.key_codes.VK_A_QWS.img = "s";
	objControlsState.key_codes.VK_A_PLUS	    = 187;  //= +
	objControlsState.key_codes.VK_A_PLUS.img = "s";
	objControlsState.key_codes.VK_A_MINUS	    = 189;  //- _
	objControlsState.key_codes.VK_A_MINUS.img = "s";
	objControlsState.key_codes.VK_A_SLUSH	    = 220;  // \ |
	objControlsState.key_codes.VK_A_SLUSH.img = "s";

	objControlsState.key_codes.VK_A_TILDA	    = 192;  // ` ~
	objControlsState.key_codes.VK_A_TILDA.img = ">";
	
	objControlsState.key_codes.VK_CAPSLOCK	    = 20;
	objControlsState.key_codes.VK_CAPSLOCK.img = "|";
	objControlsState.key_codes.VK_MENU	    = 18; // belamour ALT
	objControlsState.key_codes.VK_MENU.img = "."; 	

	// boal <--

	// Key groups for controls remapping
	objControlsState.grouplist.Sailing1Pers = true;
	objControlsState.grouplist.Sailing3Pers = true;
	objControlsState.grouplist.FightModeControls = true;
	objControlsState.grouplist.PrimaryLand = true;
	objControlsState.grouplist.WorldMapControls = true;   // boal
	objControlsState.grouplist.AltPressedGroup = true;
}