// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
	bool ok;
	int iTest;
	ref rColony;
	string sFrom_sea = "";
	switch (Dialog.CurrentNode)
	{
	case "quests":
		// регата
		if (CheckAttribute(pchar, "questTemp.Regata.Go") && !CheckAttribute(npchar, "quest.regatatalk"))
		{
			dialog.text = "¿Qué quieres? ¡Ajá, eres el participante de la regata! ¿Estoy en lo cierto?";
			link.l1 = "Exactamente, señor. Necesito registrarme aquí según las reglas.";
			link.l1.go = "Regata_check";
			break;
		}
		// регата
		dialog.text = NPCStringReactionRepeat(RandPhraseSimple("¿Qué preguntas son esas?", "¿Qué deseas, " + GetAddress_Form(NPChar) + "?"), "Ya has intentado hacerme una pregunta " + GetAddress_Form(NPChar) + "...", "Has estado hablando de alguna pregunta por tercera vez hoy...", "Mira, si no tienes nada que decirme sobre los asuntos del puerto, entonces no me molestes con tus preguntas.", "block", 1, npchar, Dialog.CurrentNode);
		link.l1 = HeroStringReactionRepeat(RandPhraseSimple("He cambiado de opinión.", "No tengo nada de qué hablar."), "Nunca mind.", "De hecho, ya es la tercera vez...", "Lo siento, pero no me interesan los asuntos del puerto por ahora.", npchar, Dialog.CurrentNode);
		link.l1.go = "exit";
		break;

	// регата
	case "Regata_check":
		iTest = FindColony(npchar.city);
		if (iTest != -1)
		{
			rColony = GetColonyByIndex(iTest);
			sFrom_sea = rColony.from_sea;
		}
		ok = (rColony.from_sea == "") || (Pchar.location.from_sea == rColony.from_sea);
		if (sti(Pchar.Ship.Type) != SHIP_NOTUSED && ok) // проверка на наличие корабля в порту
		{
			bool bRegLugger = sti(RealShips[sti(pchar.ship.type)].basetype) == SHIP_LUGGER || sti(RealShips[sti(pchar.ship.type)].basetype) == SHIP_CAREERLUGGER;
			if (CheckAttribute(pchar, "questTemp.Regata.Breach") || GetCompanionQuantity(pchar) > 1 || !bRegLugger || pchar.Ship.Name != "Saint Catherine")
			{
				dialog.text = "Hm... Has roto las reglas de la regata y tengo que descalificarte. Lo siento. No participarás en el próximo viaje. Ya he preparado un despacho para Port-Royal.";
				link.l1 = "¡Vaya... qué lástima! Pero no puedo hacer nada aquí, fuiste demasiado vigilante. ¡Adiós!";
				link.l1.go = "exit";
				DeleteAttribute(pchar, "questTemp.Regata");
				pchar.quest.Regata_PU.over = "yes"; // mitrokosta снимаем прерывание
				AddQuestRecord("Regata", "45");
				CloseQuestHeader("Regata");
			}
			else
			{
				pchar.questTemp.Regata.FirstTransitionTime = GetPastTime("hour", sti(pchar.questTemp.Regata.StartYear), sti(pchar.questTemp.Regata.StartMonth), sti(pchar.questTemp.Regata.StartDay), stf(pchar.questTemp.Regata.StartTime), GetDataYear(), GetDataMonth(), GetDataDay(), GetTime()); // истратил ГГ в часах на 1 переход
				dialog.text = "Vamos a registrarnos: capitán " + GetFullName(pchar) + ", el barco es " + pchar.Ship.Name + "... el tiempo de la regata en horas es " + sti(pchar.questTemp.Regata.FirstTransitionTime) + ". Listo, tu resultado está registrado, puedes continuar tu camino.";
				link.l1 = "Dime mi rango.";
				link.l1.go = "Regata_info";
			}
		}
		else
		{
			dialog.text = "Estás aquí, pero no veo tu barco. ¿Dónde está?";
			link.l1 = "Lo siento, señor. Transferiré mi barco al puerto de inmediato.";
			link.l1.go = "exit";
		}
		break;

	case "Regata_info":
		int n = 1;
		string sTemp, sName, sShip;
		for (int i = 1; i <= 5; i++)
		{
			if (i == 1)
				sTemp = "a";
			if (i == 2)
				sTemp = "b";
			if (i == 3)
				sTemp = "c";
			if (i == 4)
				sTemp = "d";
			if (i == 5)
				sTemp = "e";
			if (pchar.questTemp.Regata.AdversaryFirstTransition.Time.(sTemp) < sti(pchar.questTemp.Regata.FirstTransitionTime))
			{
				n++;
				sName = pchar.questTemp.Regata.AdversaryName.(sTemp);	  // имя ближайшего противника
				sShip = pchar.questTemp.Regata.AdversaryShipName.(sTemp); // его корабль
			}
		}
		if (n == 1)
		{
			dialog.text = "¡Vas a la cabeza! ¡Felicitaciones! ¡Sigue así!";
			link.l1 = "¡Gracias!";
			link.l1.go = "exit";
			AddQuestRecord("Regata", "4");
		}
		else
		{
			if (n == 6)
			{
				dialog.text = "Eres el último. Deberías darte prisa.";
				link.l1 = "¡Estoy en camino!";
				link.l1.go = "exit";
				AddQuestRecord("Regata", "9");
			}
			else
			{
				if (n == 2)
				{
					dialog.text = "Eres el segundo. El líder es " + sName + " en el barco " + sShip + "Supongo que aún puedes dejarlo atrás.";
					link.l1 = "¡Gracias! ¡Lo intentaré!";
					link.l1.go = "exit";
					AddQuestRecord("Regata", "5");
				}
				else
				{
					dialog.text = "Tu rango es " + n + ". Tu oponente más cercano es " + sName + " en el barco " + sShip + ".";
					link.l1 = "¡Gracias!";
					link.l1.go = "exit";
					if (n == 3)
						AddQuestRecord("Regata", "6");
					if (n == 4)
						AddQuestRecord("Regata", "7");
					if (n == 5)
						AddQuestRecord("Regata", "8");
				}
			}
		}
		AddCharacterExpToSkill(pchar, "Sailing", 50); // навигация
		npchar.quest.regatatalk = "true";
		pchar.questTemp.Regata.Beliz = "true"; // отметка Белиза
		pchar.quest.Regata_Check1.win_condition.l1 = "location";
		pchar.quest.Regata_Check1.win_condition.l1.location = "Cuba1";
		pchar.quest.Regata_Check1.function = "RegataCheck"; // проверка 1
		pchar.quest.Regata_Check2.win_condition.l1 = "location";
		pchar.quest.Regata_Check2.win_condition.l1.location = "Cuba2";
		pchar.quest.Regata_Check2.function = "RegataCheck"; // проверка 2
		pchar.quest.Regata_Check.win_condition.l1 = "location";
		pchar.quest.Regata_Check.win_condition.l1.location = "Hispaniola2";
		pchar.quest.Regata_Check.function = "RegataCheck"; // проверка 3
		pchar.questTemp.Regata.AttackIsland = "Cuba1";
		pchar.questTemp.Regata.AttackNation = SPAIN;
		pchar.quest.Regata_Attack.win_condition.l1 = "location";
		pchar.quest.Regata_Attack.win_condition.l1.location = "Cuba1";
		pchar.quest.Regata_Attack.function = "RegataAttack_Lugger"; // первая засада у Сантьяго
		pchar.quest.Regata_Hunter.win_condition.l1 = "location";
		pchar.quest.Regata_Hunter.win_condition.l1.location = "Cuba2";
		pchar.quest.Regata_Hunter.function = "RegataAttack_Hunter"; // ДУ у Гаваны
		pchar.questTemp.Regata.Town = "Portpax";
		pchar.quest.Regata_PU.win_condition.l1 = "locator";
		pchar.quest.Regata_PU.win_condition.l1.location = "Portpax_town";
		pchar.quest.Regata_PU.win_condition.l1.locator_group = "reload";
		pchar.quest.Regata_PU.win_condition.l1.locator = "reload10_back";
		pchar.quest.Regata_PU.win_condition.l2 = "Night";
		pchar.quest.Regata_PU.function = "RegataPU_Open"; // вход в ПУ ночью
		break;
		// регата
	}
	UnloadSegment(NPChar.FileDialog2); // если где-то выход внутри switch  по return не забыть сделать анлод
}
