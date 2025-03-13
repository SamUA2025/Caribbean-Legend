// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("¿Qué preguntas tienes?","¿Cómo puedo ayudarte?"),"Intentaste hacerme una pregunta hace un rato...","Nunca he conocido a personas con tanta curiosidad en mi astillero ni en ningún otro lugar de esta ciudad.","¿Qué pasa con todas las preguntas? Mi trabajo es construir barcos. Ocupémonos de eso.","bloqueo",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("He cambiado de opinión...","No tengo nada de qué hablar en este momento."),"Umph, ¿a dónde se ha ido mi memoria...?","Mm, bueno...","Adelante...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			if (CheckAttribute(pchar, "questTemp.Guardoftruth") && pchar.questTemp.Guardoftruth == "tortuga1")
			{
				link.l1 = "Busco a un tal Gaius Marchais. Lo último que he oído sobre él es que atracó su galeón 'Santa Margarita' para que lo repararas...";
                link.l1.go = "guardoftruth";
			}
		break;
		
		case "guardoftruth":
			dialog.text = "¿Su propio galeón? ¡Ja-ja, qué buen chiste, capitán! Gaius Marchais sólo tenía un balandro medio muerto... capturó un galeón como premio después de decidir convertirse en corsario. ¡Diablo afortunado, primer saqueo y semejante trofeo! \nOfrecí buen dinero por ella, pero él rechazó, ¡imagínese eso! En su lugar, vendió su patético balandro por una suma pequeña y lo usó para reparar el galeón. ¡Nuevas velas, nuevos colores y un nuevo nombre, lo cual normalmente no es buena señal! \nPor supuesto, el nombre era demasiado papista, pero mi hija también se llama Margarita, así que supongo que al final estuvo bien... Dijo que ya había tenido suficiente de violencia, así que se convertiría en comerciante. Y tuvo la buena fortuna...";
			link.l1 = "El comercio, supongo, sería relajante, pero los galeones papistas no suelen ser capturados por balandros. ¿Y cómo se llama ahora su nuevo barco?";
			link.l1.go = "guardoftruth_1";
		break;
		
		case "guardoftruth_1":
			dialog.text = "'Admirable'... ¡No me extraña! Solo estaba corriendo alrededor de su nueva galeón como si estuviera persiguiendo a una novia, no podía dejar de admirarla.";
			link.l1 = "Ya veo. ¿Está Gaius en Tortuga ahora mismo?";
			link.l1.go = "guardoftruth_2";
		break;
		
		case "guardoftruth_2":
			dialog.text = "No. Ha zarpado en su nuevo barco y todavía no ha regresado a Tortuga. No sé hacia dónde se dirigía, así que no puedo echarte una mano con este asunto.";
			link.l1 = "Qué inconveniente... Realmente lo necesito. Incluso deberíamos tomarnos una ronda de tragos por su 'admirable' barco. De todos modos, gracias por la información.";
			link.l1.go = "guardoftruth_3";
		break;
		
		case "guardoftruth_3":
			dialog.text = "¡Oh, no hay problema! Pase de nuevo, capitán. Y no olvide que siempre hay un espacio libre para su barco aquí, si se necesitan reparaciones.";
			link.l1 = "...";
			link.l1.go = "exit";
			AddQuestRecord("Guardoftruth", "9");
			pchar.questTemp.Guardoftruth = "tortuga2";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
