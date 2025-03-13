// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("¿Qué quieres? Pregunta.","Estoy escuchando, ¿cuál es la pregunta?"),"Esta es la segunda vez que intentas preguntar...","Esta es la tercera vez que intentas preguntar...","¿Cuándo va a terminar esto? ¡Soy un hombre ocupado, trabajando en asuntos de la colonia y aún me estás molestando!","bloque",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("He cambiado de opinión, lo siento.","Ahora no. Lugar y momento equivocados."),"Es cierto, no tengo nada que decir ahora, lo siento.","Preguntaré, más tarde.","Lo siento, "+GetAddress_FormToNPC(NPChar)+"... ",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
