// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{

	switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat("Adelante, ¿qué deseas?","Acabábamos de hablar de eso. Debes haberlo olvidado...","Esta es la tercera vez hoy que hablas de alguna pregunta...","Escucha, esto es una tienda. La gente compra cosas aquí. ¡No me molestes!","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Sabes, "+NPChar.name+", tal vez la próxima vez.","Bien, lo he olvidado por alguna razón...","Sí, realmente es la tercera vez...","Hm, no lo haré...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			// калеуче
			if (CheckAttribute(pchar, "questTemp.Caleuche") && pchar.questTemp.Caleuche == "graveyard" && !CheckAttribute(npchar, "quest.caleuche"))
			{
				link.l1 = "Escucha, ¿alguna vez ha venido a tu tienda un hombre llamado Joachim Merriman? Un señor de mediana edad, portugués, con bigote, barba imperial y ojos penetrantes. ¿Quizás compró algo?";
				link.l1.go = "caleuche";
			}
		break;
		
		// калеуче
		case "caleuche":
			dialog.text = "No, ninguno de mis clientes se parece a la descripción que diste. Además, nunca he oído ese nombre antes. Lo siento, no puedo ayudarte más.";
			link.l1 = "Ya veo. Lástima. Bueno, continuaré mi búsqueda...";
			link.l1.go = "exit";
			npchar.quest.caleuche = "true";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);
}
