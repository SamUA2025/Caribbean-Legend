// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat("Todos los rumores de "+GetCityName(npchar.city)+" a su servicio. ¿Qué le gustaría saber?","Justo estábamos hablando de eso. Debes haberlo olvidado...","Esta es la tercera vez hoy que hablas de alguna pregunta...","Repites lo mismo como un loro...","bloqueo",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Sabes, "+NPChar.name+", tal vez la próxima vez.","Claro, lo he olvidado por alguna razón...","Sí, realmente es la tercera vez...","Sí...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			if (pchar.questTemp.Slavetrader == "FindRatJamaica")
            {
                link.l1 = "¿Sabes dónde puedo encontrar a Francois Gontier por casualidad?";
                link.l1.go = "Jamaica_ratP_1";
            }
			// Страж Истины
			if (CheckAttribute(pchar, "questTemp.Guardoftruth") && pchar.questTemp.Guardoftruth == "merdok" && !CheckAttribute(npchar, "quest.jino"))
			{
				link.l1 = "Escucha, ¿ha llegado aquí a esta ciudad un alquimista, un médico? Es italiano, tiene unos treinta años, se llama Gino Gvineili. ¿Has oído algo sobre eso?";
				link.l1.go = "guardoftruth";
			}
		break;

		case "Jamaica_ratP_1":
			dialog.text = NPCStringReactionRepeat("No tengo la menor idea. Ni siquiera he oído ese nombre antes.","Ya has preguntado sobre eso y te he respondido.","Te dije, ya has preguntado por ese Gontier.","¡Escucha, aléjate y deja de molestarme! ¿Has perdido completamente la chaveta?","bloque",0,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Entonces, seguiré buscando.","Mm, supongo que sí...","Sí, correcto, he preguntado eso...","Lo siento, "+npchar.name+"...",npchar,Dialog.CurrentNode);
		break;
		
		case "guardoftruth":
			dialog.text = LinkRandPhrase("No, no lo he hecho. Tenemos herbolarios y médicos, pero ninguno con un nombre así.","Es la primera vez que escucho un nombre tan raro. No, nunca hemos recibido una visita del hombre del que hablas.","No tenemos alquimistas aquí en absoluto. Tenemos médicos, pero ninguno con un nombre raro como ese.");
			link.l1 = "Ya veo. Qué lástima. ¡Seguiré buscando!";
			link.l1.go = "exit";
			npchar.quest.jino = "true";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
