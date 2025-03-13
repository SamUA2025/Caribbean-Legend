// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("¿Qué clase de preguntas?","¿Qué quieres, "+GetAddress_Form(NPChar)+"¿?"),"Ya has intentado hacerme una pregunta "+GetAddress_Form(NPChar)+"...","Has estado hablando de alguna cuestión por tercera vez hoy...","Mira, si no tienes nada que contarme sobre los asuntos del puerto, entonces no me molestes con tus preguntas.","bloque",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("He cambiado de opinión.","No tengo nada de qué hablar."),"Nunca mind.","De hecho, ya es la tercera vez...","Lo siento, pero no me interesan los asuntos del puerto por ahora.",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;

	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
