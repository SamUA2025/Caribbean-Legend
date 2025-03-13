// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Preguntas, "+GetAddress_Form(NPChar)+"¿?","¿Cómo puedo ayudarle, "+GetAddress_Form(NPChar)+"¿?"),"Hola, Amigo."+GetSexPhrase("Mm, ¿cuál es la gran idea, "+GetAddress_Form(NPChar)+"? ","¿Otra vez con las preguntas extrañas? Chiquilla, ve a tomar un poco de ron o algo así...")+"","En todo este día, es la tercera vez que hablas de alguna pregunta..."+GetSexPhrase(" ¿Son estos algunos signos de atención?","Hola, amigo.")+"Hola, amigo.","Más preguntas, supongo, "+GetAddress_Form(NPChar)+"¿?","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("He cambiado de opinión","No tengo nada de qué hablar en este momento."),"No, no hermosa...","De ninguna manera, querida, la esclerosis...","No, ¿qué preguntas?...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;


	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
