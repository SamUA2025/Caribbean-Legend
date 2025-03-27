// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
	switch (Dialog.CurrentNode)
	{
	case "quests":
		dialog.text = NPCStringReactionRepeat(RandPhraseSimple("¿Qué preguntas son esas?", "¿Qué quieres, " + GetAddress_Form(NPChar) + "?"), "Ya has intentado hacerme una pregunta " + GetAddress_Form(NPChar) + "... ", "Has estado hablando de alguna pregunta por tercera vez hoy...", "Mira, si no tienes nada que decirme sobre los asuntos del puerto, entonces no me molestes con tus preguntas.", "block", 1, npchar, Dialog.CurrentNode);
		link.l1 = HeroStringReactionRepeat(RandPhraseSimple("He cambiado de opinión.", "No tengo nada de qué hablar."), "No importa.", "De hecho, ya es la tercera vez...", "Lo siento, pero no estoy interesado en los asuntos del puerto por ahora.", npchar, Dialog.CurrentNode);
		link.l1.go = "exit";
		break;

	// НСО пошив мундира Xenon-->
	case "Tailor":
		dialog.text = "Sí, te entiendo perfectamente, no grites así. Pero ya te he explicado: hubo mucho más correspondencia y correo de lo habitual esta vez. No te preocupes, tus materiales no desaparecerán y se entregarán en el próximo barco de mensajería.";
		link.l1 = "...";
		link.l1.go = "Tailor_01";
		break;

	case "Tailor_01":
		DialogExit();
		sld = characterFromId("Patria_Tailor");
		sld.dialog.currentnode = "Tailor_02";
		Lai_SetPlayerType(pchar);
		LAi_SetActorType(sld);
		LAi_ActorDialogNow(sld, pchar, "", -1);
		break;

	case "Tailor_02":
		dialog.text = "Bueno, obviamente, había paquetes más importantes. Y el barco no puede estar sobrecargado. Sin embargo, no estoy informado sobre cómo se distribuye el correo. Le pido que, por favor, se calme y no se ponga nervioso. Repito: todos sus materiales llegarán intactos, solo un poco más tarde.";
		link.l1 = "...";
		link.l1.go = "Tailor_03";
		break;

	case "Tailor_03":
		npchar.dialog.currentnode = "First time";
		DialogExit();
		Lai_SetPlayerType(pchar);
		sld = characterFromId("Patria_Tailor");
		sld.dialog.currentnode = "Tailor_04";
		LAi_SetActorType(sld);
		LAi_ActorDialogNow(sld, pchar, "", -1);
		break;
		// <-- пошив мундира
	}
	UnloadSegment(NPChar.FileDialog2); // если где-то выход внутри switch  по return не забыть сделать анлод
}
