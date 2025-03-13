// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    ref sld;
	switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("¿Qué tipo de preguntas, "+GetSexPhrase("joven","jovencita")+"¿?","¿Qué necesitas, "+GetSexPhrase("guapo","preciosa")+"¿Pregunte lo que quiera?"),"¿Preguntas otra vez?","Tee-hee, si te da lo mismo - preguntas...","Hola, Capitán."+GetSexPhrase("Hum, ¿por qué no escoges una belleza para ti? Empiezo a sospechar de ti...","Mm, ¿por qué no eliges una belleza para ti? No tenemos chicos aquí, me temo, je-je...")+"","bloque",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("He cambiado de opinión, discúlpeme.","En realidad, olvídalo..."),"L... disculpas, no tengo preguntas, por ahora.","Tienes razón, es la tercera vez ya. Perdóname.","Tal vez la próxima vez, señora.",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
