// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Preguntas, "+GetAddress_Form(NPChar)+"¿?","¿En qué puedo ayudarle, "+GetAddress_Form(NPChar)+"¿?"),"Пожалуйста, предоставьте текст на английском, который нужно перевести на испанский."+GetSexPhrase("Mm, ¿cuál es la gran idea, "+GetAddress_Form(NPChar)+"¿ ","¿Otra vez con las preguntas extrañas? Chiquilla, ve a tomar un poco de ron o algo...")+"Hola, Amigo.","Durante todo este día, esta es la tercera vez que hablas sobre alguna pregunta..."+GetSexPhrase(" ¿Son estos algunos signos de atención?","Entendido. Proporcione текст, который необходимо перевести.")+"Пожалуйста, предоставьте текст для перевода.","Más preguntas, supongo, "+GetAddress_Form(NPChar)+"¿?","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("He cambiado de opinión","No tengo nada de qué hablar en este momento."),"No, no hermosa...","No hay manera, querido, esclerosis...","No, ¿qué preguntas?...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;


	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
