// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("¿Qué tipo de preguntas?","¿Qué quieres, "+GetAddress_Form(NPChar)+"?"),"Ya has intentado hacerme una pregunta "+GetAddress_Form(NPChar)+"... ","Has estado hablando de alguna cuestión por tercera vez hoy...","Mira, si no tienes nada que contarme sobre los asuntos del puerto, entonces no me molestes con tus preguntas.","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("He cambiado de opinión.","No tengo nada de qué hablar."),"No importa.","De hecho, ya es la tercera vez...","Lo siento, pero no estoy interesado en los asuntos del puerto por ahora.",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			
			if (pchar.questTemp.Slavetrader == "FindRatTortuga")
            {
                link.l1 = "Buen día. Estoy buscando a Francois Gontier. Su corbeta '"+pchar.questTemp.Slavetrader.ShipName+"debe haber estado aquí en tu puerto.";
                link.l1.go = "Tortuga_ratP_1";
            }
			
		break;

		case "Tortuga_ratP_1":
			dialog.text = NPCStringReactionRepeat("Hm... Tengo que decepcionarte. Corbeta '"+pchar.questTemp.Slavetrader.ShipName+" nunca ha estado aquí y Francois Gontier tampoco se ha registrado aquí.","Ya has preguntado sobre esto y te he respondido.","Te digo que ya has preguntado sobre este Gontier.","¡Por favor, no me distraigas de mi trabajo!","block",0,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Gracias. Seguiré buscando.","Mm, bueno...","Sí, realmente he preguntado ...","Perdón, "+npchar.name+"...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;

	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
