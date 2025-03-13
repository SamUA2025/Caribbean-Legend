// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("¿Qué preguntas tienes?","¿Cómo puedo ayudarte?"),"Intentaste hacerme una pregunta hace un rato...","  Nunca he conocido gente con tanta curiosidad en mi astillero ni en ningún otro lugar de esta ciudad. ","¿Por qué tantas preguntas? Mi trabajo es construir barcos. Ocupémonos de eso.","bloque",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("He cambiado de opinión...","No tengo nada de qué hablar en este momento."),"Umph, ¿dónde se ha ido mi memoria...?","Mm, bueno...","Adelante...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			if (pchar.questTemp.Slavetrader == "FindRatPortobello")
            {
                link.l1 = "Escucha, un corsario llamado François Gontier no ha pasado por aquí para hablar contigo por случай, ¿verdad? Ha estado en Porto Bello recientemente, eso lo sé.";
                link.l1.go = "Portobello_ratS_1";
            }
		break;
		
		case "Portobello_ratS_1":
			dialog.text = "Lo ha hecho. Adquirió una corbeta de mí y pronto partió hacia el mar.";
			link.l1 = "¡Gracias! ¿Y tienes alguna idea de hacia dónde partió?";
			link.l1.go = "Portobello_ratS_2";
		break;
			
		case "Portobello_ratS_2":
			dialog.text = "No, camarada, no tengo ni idea. Reparo y vendo barcos, no hago seguimiento de adónde van. No es asunto mío.";
			link.l1 = "Bueno, entonces, gracias... Vamos a averiguar dónde has ido...";
			link.l1.go = "exit";
			pchar.questTemp.Slavetrader = "FindRatPortobello_1";
			AddQuestRecord("Slavetrader", "21_2");
		break;
			
			
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
