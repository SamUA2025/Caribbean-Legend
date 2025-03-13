// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("¿Qué quieres? Pregunta lo que desees.","Estoy escuchando, ¿cuál es la pregunta?"),"Esta es la segunda vez que estás intentando preguntar...","Esta es la tercera vez que intentas preguntar...","¿Cuándo va a terminar esto?! ¡Soy un hombre ocupado, trabajando en asuntos de la colonia y todavía me estás molestando!","bloque",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("He cambiado de opinión, lo siento.","Ahora no. Lugar y momento equivocados."),"Es cierto, no tengo nada que decir ahora, lo siento.","Preguntaré, más tarde.","Lo siento, "+GetAddress_FormToNPC(NPChar)+"...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			if (!CheckAttribute(npchar, "quest.Guardoftruth") && CheckAttribute(pchar, "questTemp.Guardoftruth.Trinidad") && pchar.questTemp.Guardoftruth.Trinidad == "begin")
			{
				link.l1 = "Su Excelencia, había una fragata bajo el mando de Miguel Dichoso en abril de 1654. Ha desaparecido desde entonces. ¿Recuerda algo sobre él? Tal vez le visitó, tuvo una conversación...";
				link.l1.go = "guardoftruth";
			}
		break;
		
		case "guardoftruth":
			dialog.text = "Sí, recuerdo a ese hombre. Pero no recuerdo ningún detalle sobre él. Vino aquí y luego simplemente se fue. No puedo ayudarte.";
			link.l1 = "Ya veo. Perdón por molestarte.";
			link.l1.go = "exit";
			npchar.quest.guardoftruth = "true";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
