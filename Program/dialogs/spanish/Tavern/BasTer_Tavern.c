// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("¿Qué preguntas tienes?","¿Cómo puedo ayudarte, "+GetAddress_Form(NPChar)+"¿?"),"¿Qué es, "+GetAddress_Form(NPChar)+"...","Esta es la tercera vez que me molestas ahora...","Más preguntas, supongo?","bloqueo",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Cambié de opinión...","No tengo nada de qué hablar en este momento."),"Umph, ¿dónde se ha ido mi memoria...","Sí, realmente es la tercera vez...","No, ¿qué preguntas?...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			//Jason, суп из черепахи
			if (CheckAttribute(PChar, "questTemp.Terrapin") && pchar.questTemp.Terrapin == "baster" && !CheckAttribute(npchar, "quest.terrapin"))
			{
				link.l1 = "Estoy buscando a mi viejo camarada Fernand Luc. Tengo un par de preguntas para él. Escuché que se lo pasó muy bien aquí hace una semana...";
				link.l1.go = "terrapin";
			}
			//Sinistra Путеводная звезда
			if (CheckAttribute(pchar, "questTemp.PZ_BasTerTavern"))
			{
				link.l1 = "Mi amigo y yo acordamos encontrarnos aquí, pero no lo veo por ninguna parte. ¿Sabes a dónde fue? ¿Sigue en el pueblo, o al menos en la isla? Su nombre es Longway - es chino.";
				link.l1.go = "PZ_BasTerTavern_1";
			}
		break;
		
		//суп из черепахи
		case "terrapin":
			dialog.text = "Puede que todavía se lo esté pasando bien mientras está en el infierno. Tu compañero está muerto, así que llegas un poco tarde, capitán. Ese hombre allá sentado en la mesa más lejana pagó por su funeral, aunque tengo la sensación de que es el mismo hombre que lo causó. Tiene cara de horca, como dicen. Se llama Robert Martene. Si quieres, puedes acercarte y preguntárselo tú mismo. ";
			link.l1 = "Gracias, camarada. Iré a hablar con monsieur Robert. Beberemos por el alma del pobre viejo Luc para que su alma descanse en paz...";
			link.l1.go = "terrapin_1";
			npchar.quest.terrapin = "true";
		break;
		
		case "terrapin_1":
			DialogExit();
			AddQuestRecord("Terrapin", "4");
			pchar.questTemp.Terrapin = "rober";
		break;
		
		// Sinistra - Квест "Длинные тени старых грехов" ==>
		case "DTSG_BasTerTavern_1":
			dialog.text = "¿Qué hay que discutir? Él te atacó a ti y a tu amigo, tú te defendiste, veo esto casi todos los días. Buen trabajo. Ahora solo tengo que limpiar el desastre...";
			Link.l1 = "Lo limpiarás, estoy seguro de que ya estás acostumbrado. ¿Qué sabes de él?";
			Link.l1.go = "DTSG_BasTerTavern_2";
		break;
		
		case "DTSG_BasTerTavern_2":
			dialog.text = "No mucho, en realidad. Apareció hace un par de días. Le gustó aquí, incluso alquiló una casa en las afueras del pueblo. Venía a menudo, pagaba con regularidad. Y, lo más importante, se comportó bien todo este tiempo, nunca dijo una mala palabra a nadie. Todavía estoy sorprendido de que te haya atacado a ti y a tu amigo. Pensé que podría establecerse aquí para siempre.";
			Link.l1 = "En cierto modo, lo hizo. Bueno, no es mucho, pero gracias por eso, mi amigo. Nos vemos.";
			Link.l1.go = "DTSG_BasTerTavern_3";
		break;
		
		case "DTSG_BasTerTavern_3":
			DialogExit();
			DeleteAttribute(pchar, "questTemp.DTSG_BasTerTavern");
			LAi_LocationDisableOfficersGen("BasTer_tavern", false);
			SetQuestHeader("DTSG");
			AddQuestRecord("DTSG", "1");
			bDisableFastReload = false;
			chrDisableReloadToLocation = false;
			
			sld = CharacterFromID("Knippel");
			LAi_SetOfficerType(sld);
			sld.Dialog.Filename = "Quest\HollandGambit\Knippel.c";
			sld.Dialog.CurrentNode = "Knippel_officer";
			sld.location = "None";
			
			PChar.quest.DTSG_BasTerDom.win_condition.l1 = "locator";
			PChar.quest.DTSG_BasTerDom.win_condition.l1.location = "BasTer_town";
			PChar.quest.DTSG_BasTerDom.win_condition.l1.locator_group = "reload";
			PChar.quest.DTSG_BasTerDom.win_condition.l1.locator = "HutFish1";
			PChar.quest.DTSG_BasTerDom.win_condition = "DTSG_BasTerDom";
			
			SetTimerCondition("DTSG_BasTerDom_Timer", 0, 0, 7, false);
			SetTimerCondition("DTSG_Etap2", 0, 0, 14, false);
		break;
		// <== Квест "Длинные тени старых грехов" - Sinistra
		
		// Sinistra - Квест "Путеводная звезда" ==>
		
		case "PZ_BasTerTavern_1":
			dialog.text = " Ese nombre no significa nada para mí, y generalmente, no dejo entrar a mi establecimiento a personas como él, ni me interesan.";
			Link.l1 = "Está bien. De acuerdo, nos vemos más tarde.";
			Link.l1.go = "PZ_BasTerTavern_2";
		break;
		
		case "PZ_BasTerTavern_2":
			DialogExit();
			bDisableLandEncounters = true;
			DeleteAttribute(pchar, "questTemp.PZ_BasTerTavern");
			DeleteAttribute(pchar, "questTemp.PZ_BasTerAlkash");
			pchar.questTemp.PZ_BasTerTavern2 = true;
			DeleteQuestCondition("PZ_BasTer_Opozdal");
			DelMapQuestMarkIsland("Guadeloupe");
			
			PChar.quest.PZ_BasTer_Strazha.win_condition.l1 = "location";
			PChar.quest.PZ_BasTer_Strazha.win_condition.l1.location = "BasTer_town";
			PChar.quest.PZ_BasTer_Strazha.win_condition = "PZ_BasTer_Strazha";
		break;
		
		// <== Квест "Путеводная звезда" - Sinistra
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
