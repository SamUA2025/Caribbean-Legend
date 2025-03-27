// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
	switch (Dialog.CurrentNode)
	{
	case "quests":
		dialog.text = NPCStringReactionRepeat(RandPhraseSimple("¿Qué preguntas tienes?", "¿Cómo puedo ayudarte?"), "Intentaste hacerme una pregunta hace un rato...", "Jamás he conocido a personas con tanta curiosidad en mi astillero ni en ningún otro lugar de esta ciudad.", "¿Qué pasa con todas las preguntas? Mi trabajo es construir barcos. Ocupémonos de eso.", "block", 1, npchar, Dialog.CurrentNode);
		link.l1 = HeroStringReactionRepeat(RandPhraseSimple("He cambiado de opinión...", "No tengo nada de qué hablar en este momento."), "Umph, ¿dónde se ha ido mi memoria...?", "Mm, bueno...", "Adelante...", npchar, Dialog.CurrentNode);
		link.l1.go = "exit";
		// Addon 2016-1 Jason пиратскаЯ линейка
		if (CheckAttribute(pchar, "questTemp.Mtraxx") && pchar.questTemp.Mtraxx == "silk_2")
		{
			link.l1 = "Escucha, maestro, aquí construyes barcos, ¿verdad?.. Y también cambias velas... ¿alguna vez has pensado en... un material mejor para la lona de las velas?";
			link.l1.go = "mtraxx";
		}
		break;

	// Addon 2016-1 Jason пиратскаЯ линейка
	case "mtraxx":
		dialog.text = "Hablas en acertijos, señor... Habla francamente, ¿qué te trae por aquí? No te preocupes, no soy un burócrata y aquí no es una aduana.";
		link.l1 = "¡Ah, me alegra que estemos de acuerdo! Tela de seda para velas, señor. Según entiendo, no hay mejor material para las velas si la velocidad es su preocupación.";
		link.l1.go = "mtraxx_1";
		break;

	case "mtraxx_1":
		dialog.text = "No solo velocidad, sino también su capacidad para navegar con el viento. ¿Está ofreciendo seda para barcos a la venta? Es un cargamento valioso, sin duda. Pero hay un obstáculo: simplemente no sé cómo usarlo en la producción. ¿Entiende? Un material como este requiere un conjunto muy especial de capacidades y habilidades que me faltan. Para ser honesto, mi astillero tiene una especialización muy diferente, si me hubiera ofrecido algunas cuerdas del Zarato de Rusia, las compraría todas con gusto sin importar el precio. Siempre necesitamos cuerdas, sin embargo, la seda para barcos no tiene demanda aquí, ¡lo siento!";
		link.l1 = "Hum. Ya veo. ¡Gracias por tu tiempo, maestro. ¡Buena suerte!";
		link.l1.go = "mtraxx_2";
		break;

	case "mtraxx_2":
		DialogExit();
		AddQuestRecord("Roger_2", "4");
		pchar.questTemp.Mtraxx = "silk_3";
		break;
	}
	UnloadSegment(NPChar.FileDialog2); // если где-то выход внутри switch  по return не забыть сделать анлод
}
