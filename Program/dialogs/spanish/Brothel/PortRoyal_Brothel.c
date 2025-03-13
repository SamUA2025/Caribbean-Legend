// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    ref sld;
	switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("¿Qué tipo de preguntas, "+GetSexPhrase("joven caballero","jovencita")+"¿?","¿Qué necesitas, "+GetSexPhrase("guapo","bonita")+"¿Pregunta lo que quieras?"),"¿Preguntas de nuevo?","Tee-hee, si te da lo mismo - preguntas...","Hola, Amigo."+GetSexPhrase("Mm, ¿por qué no eliges una belleza para ti? Estoy empezando a tener sospechas sobre ti...","Mm, ¿por qué no eliges una belleza para ti? Me temo que no tenemos chicos aquí, je-je...")+"","bloqueo",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("He cambiado de opinión, discúlpame.","En realidad, olvídalo..."),"Yo... disculpas, no tengo preguntas, por ahora.","Tienes razón, ya es la tercera vez. Perdóname.","Quizás la próxima vez, Señora.",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
