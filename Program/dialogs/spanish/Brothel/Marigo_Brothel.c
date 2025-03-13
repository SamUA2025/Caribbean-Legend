// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    ref sld;
	switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("¿Qué clase de preguntas, "+GetSexPhrase("joven caballero","jovencita")+"¿?","¿Qué necesitas, "+GetSexPhrase("guapo","bonita")+"¿Pregunte lo que quiera?"),"¿Preguntas de nuevo?","Tee-hee, si te parece bien - preguntas...",""+GetSexPhrase("Mm, ¿por qué no escoges una belleza para ti mismo? Empiezo a sospechar de ti...","Mm, ¿por qué no escoges una belleza para ti? No tenemos muchachos aquí, me temo, je-je...")+"","bloqueo",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("He cambiado de opinión, disculpe.","En realidad, olvídalo..."),"Yo... disculpas, no tengo preguntas, por ahora.","Tienes razón, ya es la tercera vez. Discúlpame.","Tal vez la próxima vez, señora.",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
