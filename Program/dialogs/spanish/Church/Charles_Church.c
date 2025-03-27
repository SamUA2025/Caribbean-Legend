// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
	switch (Dialog.CurrentNode)
	{
	case "quests":
		dialog.text = NPCStringReactionRepeat(RandPhraseSimple("¿Qué tipo de preguntas, " + GetSexPhrase("hijo mío", "hija mía") + "?", "Pregunta, estoy escuchando..."), "Te escucho, habla ahora, " + GetSexPhrase("hijo mío", "hija mía") + "... ", "Por tercera vez, " + GetSexPhrase("hijo mío", "hija mía") + ", pide lo que necesites.", "Un clérigo tiene mucho trabajo y me estás distrayendo, " + GetSexPhrase("hijo mío", "hija mía") + "...", "block", 1, npchar, Dialog.CurrentNode);
		link.l1 = HeroStringReactionRepeat(RandPhraseSimple("He cambiado de opinión...", "No en este momento, padre..."), "No tengo nada que decir, mis disculpas.", "Preguntaré, pero más tarde. Perdóname, padre.", "Perdóneme, santo padre...", npchar, Dialog.CurrentNode);
		link.l1.go = "exit";
		break;

	case "Gravel1":
		dialog.text = "¿Qué puedo hacer por ti, hijo mío?";
		link.l1 = "Te estoy buscando, Georges.";
		link.l1.go = "Gravel2";
		DelLandQuestMark(npchar);
		break;

	case "Gravel2":
		dialog.text = "¿Yo? ¿Pero por qué?";
		link.l1 = "Longway y Mynheer Van Merden necesitan que investigues de nuevo. Longway no puede mostrar su cara aquí después de su... anterior recorrido.";
		link.l1.go = "Gravel3";
		break;

	case "Gravel3":
		AddQuestRecord("PZ", "23");
		dialog.text = "¡Baja la voz, por el amor de Dios! Pero lo entiendo. Haré todo lo posible.";
		link.l1 = "Excelente, Georges. Eres uno de nuestros aliados más valiosos. Hasta luego.";
		link.l1.go = "Exit";
		DelMapQuestMarkCity("Charles");

		pchar.questTemp.PZ_Etap5_Start = true;

		if (CheckAttribute(pchar, "questTemp.LSC.Mary_officer") && GetCharacterIndex("Mary") != -1 && !CheckAttribute(pchar, "questTemp.PZ_ProvalFinal"))
		{
			PChar.quest.PZ_Etap5_Start.win_condition.l1 = "location";
			PChar.quest.PZ_Etap5_Start.win_condition.l1.location = "Pirates_town";
			PChar.quest.PZ_Etap5_Start.win_condition = "PZ_Etap5_Start";
			AddMapQuestMarkCity("Pirates", false);
		}
		if (CheckAttribute(pchar, "questTemp.Saga.Helena_officer") && GetCharacterIndex("Helena") != -1 && !CheckAttribute(pchar, "questTemp.PZ_ProvalFinal"))
		{
			PChar.quest.PZ_Etap5_Start.win_condition.l1 = "location";
			PChar.quest.PZ_Etap5_Start.win_condition.l1.location = "Pirates_town";
			PChar.quest.PZ_Etap5_Start.win_condition = "PZ_Etap5_Start";
			AddMapQuestMarkCity("Pirates", false);
		}
		break;
	}
	UnloadSegment(NPChar.FileDialog2); // если где-то выход внутри switch  по return не забыть сделать анлод
}
