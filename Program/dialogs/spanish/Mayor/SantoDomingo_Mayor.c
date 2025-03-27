// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
	switch (Dialog.CurrentNode)
	{
	case "quests":
		dialog.text = NPCStringReactionRepeat(RandPhraseSimple("¿Qué quieres?  Pregunta lo que quieras.", "Estoy escuchando, ¿cuál es la pregunta?"), "Esta es la segunda vez que intentas preguntar...", "Esta es la tercera vez que intentas preguntar...", "¿Cuándo va a terminar esto?! ¡Soy un hombre ocupado, trabajando en asuntos de la colonia y tú todavía me molestas!", "block", 1, npchar, Dialog.CurrentNode);
		link.l1 = HeroStringReactionRepeat(RandPhraseSimple("He cambiado de opinión, lo siento.", "Ahora no. Lugar y momento equivocados."), "Cierto, no tengo nada que decir ahora, lo siento.", "Preguntaré, más tarde.", "Lo siento, " + GetAddress_FormToNPC(NPChar) + "... ", npchar, Dialog.CurrentNode);
		link.l1.go = "exit";
		break;

	case "Cupture_after":
		dialog.text = RandPhraseSimple("Ya te has llevado todo. ¿Qué más quieres?", "¿Queda algo que no hayas cogido?");
		link.l1 = RandPhraseSimple("Solo echando un vistazo...", "Solo comprobando, podría haber olvidado tomar algo...");
		link.l1.go = "exit";
		NextDiag.TempNode = "Cupture_after";
		break;
	}
	UnloadSegment(NPChar.FileDialog2); // если где-то выход внутри switch  по return не забыть сделать анлод
}
