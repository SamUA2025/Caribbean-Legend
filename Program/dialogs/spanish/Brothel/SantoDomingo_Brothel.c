// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    ref sld;
	switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("¿Qué tipo de preguntas, "+GetSexPhrase("joven caballero","jovencita")+"¿?","¿Qué es lo que necesitas, "+GetSexPhrase("guapo","hermosa")+"¿ Pregúntame lo que quieras."),"¿Preguntas de nuevo?","Tee-hee, si te da lo mismo - preguntas...","Hola, capitán."+GetSexPhrase("Mm, ¿por qué no eliges una belleza para ti mismo? Estoy empezando a sospechar de ti...","Mm, ¿por qué no eliges una belleza para ti? Me temo que no tenemos chicos aquí, je-je...")+"Entendido, por favor, предоставьте текст, который нужно перевести.","bloqueo",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("He cambiado de opinión, discúlpame.","En realidad, no importa..."),"Yo... disculpas, no tengo preguntas, por ahora.","Tienes razón, ya es la tercera vez. Perdóname.","Quizás la próxima vez, señora.",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
