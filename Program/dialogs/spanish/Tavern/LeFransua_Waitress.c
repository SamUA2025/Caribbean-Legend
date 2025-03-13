// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Preguntas, "+GetAddress_Form(NPChar)+"¿?","¿En qué puedo ayudarte, "+GetAddress_Form(NPChar)+"¿?"),"Entendido. Я буду переводить только текст в кавычках, сохраняя форматирование и пробелы. Пожалуйста, предоставь текст для перевода."+GetSexPhrase("Mm, ¿cuál es la gran idea, "+GetAddress_Form(NPChar)+"¿ ","¿Otra vez con las preguntas extrañas? Chiquilla, ve a tomar un poco de ron o algo así...")+"Entendido. Por favor, предоставьте текст для перевода.","Durante todo este día, esta es la tercera vez que hablas de alguna pregunta..."+GetSexPhrase(" ¿Son estas algunas muestras de atención?","Пожалуйста, предоставьте текст, который вы хотите перевести.")+"¿Cómo estás, amigo?","Más preguntas, supongo, "+GetAddress_Form(NPChar)+"¿?","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("He cambiado de opinión","No tengo nada de qué hablar en este momento."),"No, no hermosa...","De ninguna manera, querida...","No, ¿qué preguntas?...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;


	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
