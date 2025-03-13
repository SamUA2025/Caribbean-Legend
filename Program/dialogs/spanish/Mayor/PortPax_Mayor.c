// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("¿Qué quieres? Pregunta lo que quieras.","Te escucho, ¿cuál es la pregunta?"),"Esta es la segunda vez que intentas preguntar...","Esta es la tercera vez que intentas preguntar...","¿Cuándo va a terminar esto?! ¡Soy un hombre ocupado, trabajando en asuntos de la colonia y aún sigues molestándome!","bloqueo",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("He cambiado de opinión...","Ahora no. Lugar y momento equivocados."),"Verdad... Pero después, no ahora...","Preguntaré... Pero un poco más tarde...","Lo siento, "+GetAddress_FormToNPC(NPChar)+"...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			// Jason НСО
			if (CheckAttribute(pchar, "questTemp.Patria") && pchar.questTemp.Patria == "epizode_2" && !CheckAttribute(npchar, "quest.patria") && !CheckAttribute(pchar, "questTemp.Patria.Visiter_Late"))
			{
				link.l1 = TimeGreeting()+"Monsieur. Estoy aquí por orden del Gobernador General Chevalier de Poincy. Mi tarea es entregar a un barón llamado Noel Forget a Tortuga, quien llegó del estado padre con la misión de inspeccionar las colonias, su propósito principal es establecer una Compañía de Comercio de las Indias Occidentales Francesas. Permítame presentárselo... Él mismo explicará todos los detalles.";
                link.l1.go = "patria_portpax";
			}
			// Rebbebion, квест "Путеводная звезда"
			if (CheckAttribute(pchar, "questTemp.PZ.PortPaxMayorTalk"))
			{
				link.l1 = "Su Señoría, ¿quería verme?";
				link.l1.go = "PZ1";
			}
		break;

		case "Cupture_after":
            dialog.text = RandPhraseSimple("Ya lo has tomado todo. ¿Qué más quieres?","¿Queda algo que no hayas agarrado?");
            link.l1 = RandPhraseSimple("Solo estoy echando un vistazo...","Solo comprobando, podría olvidar llevarme algo...");
            link.l1.go = "exit";
            NextDiag.TempNode = "Cupture_after";
		break;
		
		// Jason НСО
		case "patria_portpax":
			dialog.text = "Me alegra mucho conoceros, Capitán Charles de Maure, y al Barón. Haré todo lo posible para que la estancia de Monsieur Forget en nuestra colonia sea lo más cómoda posible. Y aprovechando que un Monsieur de tan alto rango me ha visitado, os pediré por un asunto.";
			link.l1 = "¡Muy interesante! Cuéntenos sobre su asunto, su Gracia.";
			link.l1.go = "patria_portpax_1";
		break;
		
		case "patria_portpax_1":
			dialog.text = "En los últimos meses, nuestra colonia no ha sido visitada por ningún representante del Gobernador General, ¡como si nos hubieran olvidado por completo en Saint Kitts! Y mientras tanto, los españoles, deseando hacer de toda La Española un territorio puramente español y para quienes los colonos franceses y los bucaneros al oeste de la isla son una gran molestia, ¡están preparando un ataque! Mis oficiales de patrulla, nuestros capitanes mercantes e incluso los pescadores comunes han informado que una poderosa escuadra española se está reuniendo en Santiago y que se está preparando para atacar Puerto Príncipe.";
			link.l1 = "¿Es la evidencia lo suficientemente clara, su Majestad?";
			link.l1.go = "patria_portpax_2";
		break;
		
		case "patria_portpax_2":
			dialog.text = "No tengo información precisa, pero tanta información de personas completamente al azar no puede ser meros rumores. Nuestra colonia es muy importante para Francia, aquí tenemos las mejores plantaciones, que el Barón puede ver personalmente. ¡Perder esta colonia o incluso exponerla al riesgo de ser saqueada es inaceptable!";
			link.l1 = "Tendré en cuenta tus pruebas e informaré al Chevalier de Poincy. Estoy seguro de que tomará medidas inmediatas.";
			link.l1.go = "patria_portpax_3";
		break;
		
		case "patria_portpax_3":
			dialog.text = "Gracias, capitán...";
			link.l1 = "";
			link.l1.go = "patria_portpax_4";
		break;
		
		case "patria_portpax_4":
			DialogExit();
			sld = characterFromId("Noel");
			sld.dialog.currentnode = "noel_9";
			ChangeCharacterAddressGroup(sld, pchar.location, "goto", "governor1");
			LAi_SetActorType(sld);
			LAi_ActorDialogDelay(sld, pchar, "", 1.0);
			npchar.quest.patria = "true";
		break;
		
		case "PZ1":
			DeleteAttribute(pchar, "questTemp.PZ.PortPaxMayorTalk");
			dialog.text = "No, no te he convocado, monsieur. ¿Querías algo?";
			link.l1 = "How could I? But your messenger met us; he said you had prepared one of the houses in the town for me...";
			link.l1.go = "PZ2";
			DelLandQuestMark(npchar);
		break;
		
		case "PZ2":
			dialog.text = "¿Qué casa, qué mensajero, qué insolencia es esta?!";
			link.l1 = "¿Qué quieres decir, qué mensajero... Su nombre es Henri Thibaut, y...";
			link.l1.go = "PZ3";
		break;
		
		case "PZ3":
			dialog.text = "¿QUÉ? ¿Sabéis siquiera quién es él? Aparentemente no. Pero no importa. ¿Qué hace el sobrino de Levasseur en mi ciudad?";
			link.l1 = "¡Oh, Dios mío...";
			link.l1.go = "PZ4";
		break;
		
		case "PZ4":
			dialog.text = "De Maure, ¿puedes oírme? ¿Monsieur?";
			link.l1 = "...";
			link.l1.go = "PZ5";
		break;
		
		case "PZ5":
			DialogExit();
			LAi_SetActorType(pchar);
			LAi_ActorRunToLocator(pchar, "reload", "reload1", "PZ_SharleBezhitObratno", -1);
			bDisableCharacterMenu = true;
			InterfaceStates.Buttons.Save.enable = false;
			SetMusic("music_teleport");
			pchar.questTemp.lockedMusic = true;
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
