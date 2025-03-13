// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("¿Qué tipo de preguntas, "+GetSexPhrase("mi hijo","mi hija")+"¿?","Pregunta, estoy escuchando..."),"Te escucho, habla ahora, "+GetSexPhrase("hijo mío","mi hija")+"...","Por tercera vez, "+GetSexPhrase("mi hijo","mi hija")+", pide lo que necesites.","Un clérigo tiene mucho trabajo y me estás distrayendo, "+GetSexPhrase("hijo mío","mi hija")+"...","bloqueo",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("He cambiado de opinión...","No en este momento, padre..."),"No tengo nada que decir, mis disculpas.","Preguntaré, pero más tarde. Perdóname, padre.","Perdóneme, santo padre...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			//Цена чахотки
			if (!CheckAttribute(npchar, "quest.Consumption") && CheckAttribute(pchar, "questTemp.Consumption.AskJuan"))
			{
				link.l1 = "Dime, santo padre, ¿te suena el nombre 'Juan'?";
				link.l1.go = "Consumption";
			}
		break;
		
		//Цена чахотки
		case "Consumption":
			dialog.text = "Hace que sí, hijo mío. Hay muchos feligreses en esta ciudad que se llaman Juan.";
			link.l1 = "Ya veo. Mis disculpas por molestarlo, padre...";
			link.l1.go = "exit";
			npchar.quest.Consumption = "true";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
