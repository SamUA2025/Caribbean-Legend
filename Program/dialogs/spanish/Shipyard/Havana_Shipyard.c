// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("¿Qué preguntas tienes?","¿Cómo puedo ayudarle?"),"Intentaste hacerme una pregunta hace un rato...","Jamás he conocido a personas con tanta curiosidad en mi astillero ni en ningún otro lugar de esta ciudad.","¿Qué pasa con todas las preguntas? Mi trabajo es construir barcos. Ocupémonos de eso.","bloqueo",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("He cambiado de opinión...","No tengo nada de qué hablar en este momento."),"Umph, ¿dónde se ha ido mi memoria...?","Mm, bueno...","Adelante...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			// калеуче
			if (CheckAttribute(pchar, "questTemp.Caleuche") && pchar.questTemp.Caleuche == "graveyard" && !CheckAttribute(npchar, "quest.caleuche"))
			{
				link.l1 = "Escucha, ¿ha estado aquí recientemente un hombre llamado Joachim Merriman? Un señor de mediana edad, portugués, con bigote, barba imperial y ojos penetrantes. ¿Quizás quería comprar un barco?";
				link.l1.go = "caleuche";
			}
		break;
		
		// калеуче
		case "caleuche":
			dialog.text = "No, señor. No he visto a tal cliente.";
			link.l1 = "Ya veo. Lástima. Continuaré mi búsqueda entonces...";
			link.l1.go = "exit";
			npchar.quest.caleuche = "true";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
