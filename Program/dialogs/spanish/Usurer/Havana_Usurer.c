// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("¿Qué preguntas tienes?","¿Cómo puedo ayudarle?"),"Intentaste hacerme esa pregunta no hace mucho...","Sí, déjame adivinar... ¿Otra vez dando vueltas en círculos?","Escuche, yo manejo las finanzas aquí, no respondo preguntas...","bloqueo",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("He cambiado de opinión...","No tengo nada de qué hablar en este momento."),"Umph, ¿dónde se ha ido mi memoria...?","Lo has adivinado, lo siento...","Entiendo...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			// калеуче
			if (CheckAttribute(pchar, "questTemp.Caleuche") && pchar.questTemp.Caleuche == "graveyard" && !CheckAttribute(npchar, "quest.caleuche"))
			{
				link.l1 = "Escucha, ¿ha estado aquí un hombre llamado Joachim Merriman? Un señor de mediana edad, portugués, con bigote, barba imperial y ojos penetrantes. ¿Quizás quería pedir un préstamo?";
				link.l1.go = "caleuche";
			}
		break;
		
		// калеуче
		case "caleuche":
			dialog.text = "Me temo que no puedo ayudarte, joven. No tengo idea de quién estás hablando.";
			link.l1 = "Ya veo. Lástima. Continuaré mi búsqueda...";
			link.l1.go = "exit";
			npchar.quest.caleuche = "true";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
