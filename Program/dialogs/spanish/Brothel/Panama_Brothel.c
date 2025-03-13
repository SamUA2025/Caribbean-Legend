// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    ref sld;
	switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("¿Qué tipo de preguntas, "+GetSexPhrase("joven","jovencita")+"¿?","¿Qué necesitas, "+GetSexPhrase("guapo","hermosa")+"¿Pregunta lo que quieras?"),"¿Preguntas de nuevo?","Tee-hee, si te da lo mismo - preguntas..."," "+GetSexPhrase("Mm, ¿por qué no eliges una belleza para ti? Empiezo a tener sospechas sobre ti...","Mm, ¿por qué no eliges una belleza para ti? Me temo que no tenemos muchachos aquí, je-je...")+"Entendido. Proporciona исходные тексты для перевода.","bloqueo",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("He cambiado de opinión, discúlpame.","En realidad, no importa..."),"Yo... disculpas, no tengo preguntas, por ahora.","Tienes razón, es la tercera vez ya. Perdóname.","Quizás la próxima vez, señora.",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
