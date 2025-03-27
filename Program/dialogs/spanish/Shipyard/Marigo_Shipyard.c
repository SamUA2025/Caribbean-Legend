// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("¿Qué preguntas tienes?","¿Cómo puedo ayudarle?"),"Intentaste hacerme una pregunta hace un rato...","Jamás he conocido gente con tanta curiosidad en mi astillero ni en ningún otro lugar de esta ciudad.","¿A qué vienen tantas preguntas? Mi trabajo es construir barcos. Ocupémonos de eso.","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("He cambiado de opinión...","No tengo nada de qué hablar en este momento."),"Umph, ¿adónde se ha ido mi memoria...?","Mm, bueno...","Adelante...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
