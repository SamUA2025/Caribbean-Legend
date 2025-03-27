// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
	switch (Dialog.CurrentNode)
	{
	case "quests":
		dialog.text = NPCStringReactionRepeat(RandPhraseSimple("¿Qué quieres? Pregunta lo que desees.", "Te escucho, ¿cuál es la pregunta?"), "Esta es la segunda vez que intentas preguntar...", "Esta es la tercera vez que intentas preguntar...", "¿Cuándo va a terminar esto?! ¡Soy un hombre ocupado, trabajando en asuntos de la colonia y todavía me estás molestando!", "block", 1, npchar, Dialog.CurrentNode);
		link.l1 = HeroStringReactionRepeat(RandPhraseSimple("He cambiado de opinión, lo siento.", "No ahora. Lugar y momento equivocados."), "Es cierto, ahora no tengo nada que decir, lo siento.", "Preguntaré, más tarde.", "Lamento, " + GetAddress_FormToNPC(NPChar) + "... ", npchar, Dialog.CurrentNode);
		link.l1.go = "exit";
		break;

	case "Cupture_after":
		dialog.text = RandPhraseSimple("Ya lo has tomado todo. ¿Qué más quieres?", "¿Queda algo que no hayas agarrado?");
		link.l1 = RandPhraseSimple("Solo echando un vistazo...", "Solo comprobando, podría haber olvidado tomar algo...");
		link.l1.go = "exit";
		NextDiag.TempNode = "Cupture_after";
		break;
	}
	UnloadSegment(NPChar.FileDialog2); // если где-то выход внутри switch  по return не забыть сделать анлод
}
