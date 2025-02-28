// belamour Caribbean Legend окна туториала 03.08.2024

void Tutorial_firstfight1_SandBox(string qName)
{
	LaunchTutorial("GuideFight", 1);
	pchar.quest.Tutorial_firstfight1_SandBox_AlarmOff.win_condition.l1 = "Alarm";
	pchar.quest.Tutorial_firstfight1_SandBox_AlarmOff.win_condition.l1.value = 1;
	pchar.quest.Tutorial_firstfight1_SandBox_AlarmOff.win_condition.l1.operation = "<";
	pchar.quest.Tutorial_firstfight1_SandBox_AlarmOff.function = "Tutorial_firstfight1_SandBox_AlarmOff";
	pchar.systeminfo.tutorial.firstboarding1 = true;
	if(bSeaActive && bAbordageStarted)
	{
		if(CheckAttribute(pchar, "systeminfo.tutorial.firstboarding1"))
		{
			DoQuestFunctionDelay("Tutorial_firstboarding1", 5.0);
			DeleteAttribute(pchar, "systeminfo.tutorial.firstboarding1");
		}
	}
}

void Tutorial_firstboarding1(string qName)
{
	LaunchTutorial("OneToOneBoarding", 1);
	pchar.systeminfo.tutorial.secondboarding1 = true;
}

void Tutorial_secondboarding1(string qName)
{
	LaunchTutorial("Collision", 1);
}

void Tutorial_firstfight1_SandBox_AlarmOff(string qName)
{
	pchar.systeminfo.tutorial.secondfight_SandBox = true;
}

void Tutorial_secondfight_SandBox(string qName)
{
	LaunchTutorial("LandTimeScaleDown", 1);
}

void Tutorial_WorldMap(string qName)
{
	DoQuestFunctionDelay("Tutorial_WorldMap2", 1.0);
}

void Tutorial_WorldMap2(string qName)
{
	LaunchTutorial("WorldMap" + LanguageGetLanguage(), 1);
}

void Tutorial_Navigator(string qName)
{
	DoQuestFunctionDelay("Tutorial_Navigator2", 1.0);
}

void Tutorial_Navigator2(string qName)
{
	if(CheckAttribute(pchar,"systeminfo.tutorial.navigatorNoShow")) return;
	int sailSkill;
	int needSkill;
	
	sailSkill = GetSummonSkillFromNameSimple(pchar, SKILL_SAILING);
	
	int shipClass = GetCharacterShipClass(pchar);
	needSkill = GetShipClassNavySkill(shipClass);
	
	if(GetCharacterShipType(pchar) != SHIP_NOTUSED)
	{
		if (sti(RealShips[sti(pchar.ship.type)].basetype) == SHIP_RENOVATED_FDM || sti(RealShips[sti(pchar.ship.type)].basetype) == SHIP_FDM) needSkill = 100;
	}
	if (CheckAttribute(pchar, "NoNavyPenalty")) needSkill = 1;
	
	if (sailSkill >= needSkill) return;
	pchar.systeminfo.tutorial.navigatorNoShow = true;
	if(SandBoxMode) SetFunctionTimerCondition("DelNavigatorNoShow", 0, 0, 180, false);
	else
	{
		if(CheckAttribute(pchar,"systeminfo.tutorial.navigatorTrial"))
		{
			SetFunctionTimerCondition("DelNavigatorNoShow", 0, 0, 180, false);
		}
	}
	LaunchTutorial("Navigator" + LanguageGetLanguage(), 1);
	if(GetCharacterShipClass(pchar) < 5) 
	{
		DeleteAttribute(pchar,"systeminfo.tutorial.navigator");
		if(CheckAttribute(pchar,"systeminfo.tutorial.navigatorNoShow"))
		{
			DeleteAttribute(pchar,"systeminfo.tutorial.navigatorNoShow");
		}
		if(CheckAttribute(pchar,"systeminfo.tutorial.navigatorTrial"))
		{
			DeleteAttribute(pchar,"systeminfo.tutorial.navigatorTrial");
		}
		PChar.Quest.DelNavigatorNoShow.over = "yes";
	}
}

void DelNavigatorNoShow(string qName)
{
	if(CheckAttribute(pchar,"systeminfo.tutorial.navigatorNoShow"))
	{
		DeleteAttribute(pchar,"systeminfo.tutorial.navigatorNoShow");
	}
}

void Tutorial_Alchemy(string qName)
{
	LaunchTutorial("Alchemy" + LanguageGetLanguage(), 1);
}

void Tutorial_Salary(string qName)
{
	if (!dialogRun && !bQuestCheckProcessFreeze && !bAbordageStarted)
	{
		DeleteAttribute(Pchar, "quest.Tutorial_Salary.again");
		pchar.quest.Tutorial_Salary.over = "yes";//снять таймер
		LaunchTutorial("Salary" + LanguageGetLanguage(), 1);
	}
	else
	{
		return;
	}
}

void Tutorial_Dubloons(string qName)
{
	if (!dialogRun && !bQuestCheckProcessFreeze && pchar.chr_ai.type == "player")
	{
		DoQuestFunctionDelay("Tutorial_Dubloons2", 1.0);
	}
	else
	{
		DoQuestFunctionDelay("Tutorial_Dubloons2", 2.0);
	}
}

void Tutorial_Dubloons2(string qName)
{
	if (!dialogRun && !bQuestCheckProcessFreeze && pchar.chr_ai.type == "player")
	{
		LaunchTutorial("Dubloons" + LanguageGetLanguage(), 1);
	}
	else
	{
		DoQuestFunctionDelay("Tutorial_Dubloons", 1.0);
	}
}

void Tutorial_Box(string qName)
{
	DoQuestFunctionDelay("Tutorial_Box2", 1.0);
}

void Tutorial_Box2(string qName)
{
	LaunchTutorial("Box" + LanguageGetLanguage(), 1);
}

void Tutorial_Amulet(string qName)
{
	if (!dialogRun && !bQuestCheckProcessFreeze && pchar.chr_ai.type == "player")
	{
		DoQuestFunctionDelay("Tutorial_Amulet2", 1.0);
	}
	else
	{
		DoQuestFunctionDelay("Tutorial_Amulet2", 2.0);
	}
}

void Tutorial_Amulet2(string qName)
{
	if (!dialogRun && !bQuestCheckProcessFreeze && pchar.chr_ai.type == "player")
	{
		DeleteAttribute(pchar,"systeminfo.tutorial.Amulet");
		LaunchTutorial("Amulet" + LanguageGetLanguage(), 1);
	}
	else
	{
		DoQuestFunctionDelay("Tutorial_Amulet", 1.0);
	}
}

void Tutorial_Perk(string qName)
{
	if (!dialogRun && !bQuestCheckProcessFreeze && pchar.chr_ai.type == "player")
	{
		DoQuestFunctionDelay("Tutorial_Perk2", 1.0);
	}
	else
	{
		DoQuestFunctionDelay("Tutorial_Perk2", 2.0);
	}
}

void Tutorial_Perk2(string qName)
{
	if (!dialogRun && !bQuestCheckProcessFreeze && pchar.chr_ai.type == "player")
	{
		LaunchTutorial("Perk" + LanguageGetLanguage(), 1);
	}
	else
	{
		DoQuestFunctionDelay("Tutorial_Perk", 1.0);
	}
}

void Tutorial_Rest_Delay(string qName)
{
	DoQuestFunctionDelay("Tutorial_Rest", 1.0);
}

void Tutorial_Rest(string qName)
{
	LaunchTutorial("Rest" + LanguageGetLanguage(), 1);
}

void Tutorial_Mushket(string qName)
{
	if (!dialogRun && !bQuestCheckProcessFreeze && pchar.chr_ai.type == "player")
	{
		DoQuestFunctionDelay("Tutorial_Mushket2", 1.0);
	}
	else
	{
		DoQuestFunctionDelay("Tutorial_Mushket2", 2.0);
	}
}

void Tutorial_Mushket2(string qName)
{
	if (!dialogRun && !bQuestCheckProcessFreeze && pchar.chr_ai.type == "player")
	{
		LaunchTutorial("Mushket" + LanguageGetLanguage(), 1);
	}
	else
	{
		DoQuestFunctionDelay("Tutorial_Mushket", 1.0);
	}
}

void Tutorial_Stealth(string qName)
{
	DoQuestFunctionDelay("Tutorial_Stealth2", 5.0);
}

void Tutorial_Stealth2(string qName)
{
	LaunchTutorial("Stealth" + LanguageGetLanguage(), 1);
}

void Tutorial_BoardingTactics(string qName)
{
	LaunchTutorial("BoardingTactics", 1);
}

void Tutorial_CameraControl(string qName)
{
	LaunchTutorial("CameraControl", 1);
}

void Tutorial_CameraControlFP(string qName)
{
	LaunchTutorial("CameraControlFP", 1);
}

void Ngt_CaptiveRus(string qName)
{
	NewGameTip("Вы в меньшинстве. Не дайте себя окружить - найдите лучшую позицию в скалах!");
}

void Ngt_CaptiveEng(string qName)
{
	NewGameTip("You're outnumbered! Don't get surrounded - seek safety in the rocks!");
}

void Ngt_FolkeRus(string qName)
{
	NewGameTip("У вас новый офицер! Назначьте его своим штурманом в окне персонажа (F4).");
}

void Ngt_FolkeEng(string qName)
{
	NewGameTip("Welcome aboard your new officer! Press F4 to assign him as your Navigator.");
}
