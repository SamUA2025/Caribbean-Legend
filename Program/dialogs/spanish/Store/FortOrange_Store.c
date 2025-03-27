// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
	switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("¿Qué preguntas tienes?","¿Cómo puedo ayudarle?"),"Intentaste hacerme una pregunta hace poco mientras estabas en la tienda...","Esa es la tercera pregunta de hoy. Necesito hacer negocios, no participar en conversaciones sin sentido...","¿Más preguntas? ¿Qué tal si hacemos un trato en su lugar?","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("He cambiado de opinión...","No tengo nada de qué hablar en este momento."),"Sí, así es. Lo intenté... Mientras estaba en la tienda...","Sí, es la tercera pregunta...","Mm, tal vez podamos llegar a un acuerdo...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;				
	}
	UnloadSegment(NPChar.FileDialog2);
}
