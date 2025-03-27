// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("¿Qué quieres? Pregunta lo que quieras.","Te escucho, ¿cuál es la pregunta?"),"Esta es la segunda vez que intentas preguntar...","Esta es la tercera vez que intentas preguntar...","¿Cuándo va a terminar esto?! ¡Soy un hombre ocupado, trabajando en asuntos de la colonia y todavía me estás molestando!","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("He cambiado de opinión...","Ahora no. Lugar y momento equivocados"),"Verdad... Pero más tarde, no ahora...","Preguntaré... Pero un poco más tarde...","Lo siento, "+GetAddress_FormToNPC(NPChar)+"... ",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			// Jason Дороже золота
			if (CheckAttribute(pchar, "questTemp.GoldenGirl") && pchar.questTemp.GoldenGirl == "antigua")
			{
				link.l1 = "Su Excelencia, me gustaría informarle que poseo cierta información sobre la desaparición del Mercury.";
                link.l1.go = "G_Girl";
			}
		break;
		
		// Jason Дороже золота
		case "G_Girl":
			dialog.text = "¿Información? ¿Sobre qué, de nuevo?";
			link.l1 = "El bergantín, su Excelencia. Transportando correo. Documentos de gran importancia y tal. Escuché sobre la investigación y, obviamente, como un leal amigo de la Corona Británica, me gustaría ayudar.";
			link.l1.go = "G_Girl_1";
		break;
		
		case "G_Girl_1":
			dialog.text = "¡Espléndido! ¡El Baronet Cortney estará encantado de recibirle! Organizaré una reunión de inmediato.";
			link.l1 = "Gracias, Señor. Estoy apurado y agradecería que fuera rápido.";
			link.l1.go = "G_Girl_2";
		break;
		
		case "G_Girl_2":
			dialog.text = "No te preocupes, tendrás todo el tiempo del mundo. ¡Guardias! ¡Arrestenlo!";
			link.l1 = "Gracias... espera, ¿qué? ¿Es una broma?!";
			link.l1.go = "G_Girl_3";
		break;
		
		case "G_Girl_3":
			DialogExit();
			GoldenGirl_AntiguaArest();
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
