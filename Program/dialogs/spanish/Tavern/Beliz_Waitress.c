// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Preguntas, "+GetAddress_Form(NPChar)+"¿?","¿Cómo puedo ayudarte, "+GetAddress_Form(NPChar)+"¿?"),"Понял. Готов приступить к переводу. Пожалуйста, предоставьте текст для перевода."+GetSexPhrase("Mm, ¿cuál es la gran idea, "+GetAddress_Form(NPChar)+"¿ ","¿Otra vez con las preguntas extrañas? Chiquilla, ve a tomarte un ron o algo...")+"Hola, Amigo.","Durante todo este día, esta es la tercera vez que hablas de alguna pregunta..."+GetSexPhrase(" ¿Son estos algunos signos de atención?","Hola, Amigo.")+"Entendido. Пожалуйста, предоставьте текст, который необходимо перевести.","Más preguntas, supongo, "+GetAddress_Form(NPChar)+"¿?","bloqueo",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("He cambiado de opinión","No tengo nada de qué hablar en este momento."),"No, no hermosa...","De ninguna manera, querida...","No, ¿qué preguntas?...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
