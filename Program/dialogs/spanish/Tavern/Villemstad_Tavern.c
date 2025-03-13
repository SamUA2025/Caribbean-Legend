// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat("Todos los rumores de "+GetCityName(npchar.city)+" a su servicio. ¿Qué le gustaría saber?","Justo estábamos hablando de eso. Debes haberlo olvidado...","Esta es la tercera vez hoy que hablas de alguna pregunta...","Repetís todo como un loro...","bloqueo",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Sabes, "+NPChar.name+", tal vez la próxima vez.","Correcto, lo he olvidado por alguna razón...","Sí, realmente es la tercera vez...","Sí...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			//работорговец
			if (pchar.questTemp.Slavetrader == "EscapeSlave_Villemstad")
            {
                link.l1 = "He oído que hubo un gran lío en la isla... ¿Esclavos?";
                link.l1.go = "EscapeSlaveVillemstad_T1";
            }
			//Португалец
			if (CheckAttribute(pchar, "questTemp.Portugal") && pchar.questTemp.Portugal == "SeekPortVillemstad")
            {
                link.l1 = "¡He oído que ese miserable canalla Bart el Portugués finalmente ha encontrado justicia! ¿Está en prisión? ¿Cuándo será su ejecución, lo sabes? Quiero venir a verlo, tengo una cuenta pendiente con esa escoria...";
                link.l1.go = "Portugal";
            }
 		break;

		//работорговец
		case "EscapeSlaveVillemstad_T1":
			dialog.text = "Ay, nunca ha habido tal desorden... Más de mil negros se han rebelado. Dos plantaciones han sido reducidas a cenizas y cada uno de sus amos fue asesinado. El comandante está preocupado de que los esclavos vayan a atacar la ciudad, así que ha impuesto la ley marcial. Y todo comenzó por dos negros, un macho llamado Tamango y una hembra llamada Isauri...";
			link.l1 = "Parece bastante dramático. Cuéntame toda la historia, ¿quiénes son esos negros?";
			link.l1.go = "EscapeSlaveVillemstad_T2";
		break;
		
		case "EscapeSlaveVillemstad_T2":
				dialog.text = "Tamango e Izaura - esclavos en la plantación de Blenheim, la primera plantación quemada. Estos dos negros se amaban. Pero un hijo del plantador, Leonsio, llegó de Europa y se encaprichó con la mulata. Quería convertir a Izaura en su concubina personal. Al negro Tamango no le gustaba la idea y a Izaura tampoco, ella realmente amaba al diablo negro.\nEse Tamango era una especie de jefe o algo así en África... Un negro gigante - más negro que el pecado y mortal con un hacha, los otros negros le temían y respetaban. Así que este negro lidera a los otros esclavos en un levantamiento. Atacaron a los guardias por la noche, mataron a todos los blancos fuera de la gran casa, a los mulatos también\nEntonces Izaura abrió las puertas de la plantación y los simios salvajes asesinaron a todos dentro. Blenburg fue reducido a cenizas. Luego los esclavos huyeron a las selvas y desaparecieron...";
			link.l1 = "Bueno, ¡qué historia, suena como la trama de una novela! Una verdadera revuelta de esclavos, como en la Antigua Roma. ¿Cómo te enteraste de todo eso, por cierto?";
			link.l1.go = "EscapeSlaveVillemstad_T3";
		break;
		
		case "EscapeSlaveVillemstad_T3":
			dialog.text = "Rumores, señor, la tierra está llena de ellos. El ron suelta lenguas, todo lo que tienes que hacer es escuchar...";
			link.l1 = "¿Y cómo terminó todo eso? ¿Han encontrado a esos negros?";
			link.l1.go = "EscapeSlaveVillemstad_T4";
		break;
		
		case "EscapeSlaveVillemstad_T4":
				dialog.text = "¡Ja, ni lo sueñes! Hasta que los refuerzos finalmente lograron llegar, nadie puso un pie en la jungla. Luego llegó un barco de guerra de la Compañía con una unidad de soldados y registraron la isla. No encontraron ni piel negra ni cabello rizado de un solo negro suelto.";
			link.l1 = "¡Vaya, cómo lo ves! ¿Mil negros desaparecieron en el aire como por arte de magia?";
			link.l1.go = "EscapeSlaveVillemstad_T5";
		break;
		
		case "EscapeSlaveVillemstad_T5":
			dialog.text = "En realidad al agua.";
			link.l1 = "¿De qué estás hablando, "+npchar.name+"¿Sabes tan bien como yo que los negros no pueden nadar?";
			link.l1.go = "EscapeSlaveVillemstad_T6";
		break;
		
		case "EscapeSlaveVillemstad_T6":
			dialog.text = "He-he... oh no esos negros no son cebo de tiburón tan rápido. La cosa es que la noche siguiente al motín un bergantín desapareció de los muelles. ¡Puedes pintarme de negro y tocaré el banjo y bailaré para ti si no fue obra de ese bribón Tamango y sus negros! Por eso ya no están en la isla.";
			link.l1 = "Ja, ahora lo he oído todo, "+npchar.name+". ¿Esperas que crea que un grupo de negros medio salvajes puede manejar velas y navegar? Antes esperaría que un barco de monos llegara a toda velocidad desde Guinea.";
			link.l1.go = "EscapeSlaveVillemstad_T7";
		break;
		
		case "EscapeSlaveVillemstad_T7":
			dialog.text = "Yo tampoco lo creía, señor, pero la prueba está en el barco desaparecido. Tal vez uno de esos negros solía servir como mayordomo en un barco y aprendió alguna técnica de navegación. ¡Quizás usaron magia negra, quién sabe! Pasa a visitarme de nuevo, "+pchar.name+",   la próxima vez   conseguiré más historias para ti.";
			link.l1 = "¡Gracias! Bueno, es hora de que me ponga en marcha.";
			link.l1.go = "exit";
			AddQuestRecord("Slavetrader", "22_2");
			pchar.questTemp.Slavetrader = "EscapeSlaveVillemstad_P";
		break;						

		case "Portugal":
			dialog.text = "Sí, eso es correcto. Atraparon a ese pirata. ¿Y puedes creer cómo? Lo recogieron en un bote pequeño solo en medio del mar. Ni siquiera hizo un ruido antes de ser enviado a la bodega para los ratones. Es realmente divertido, ¿sabes?, ¡un pirata tan peligroso fue atrapado como un novato!";
			link.l1 = "¿Y por qué estaba él solo en el mar?";
			link.l1.go = "Portugal_1";
		break;
		
		case "Portugal_1":
			dialog.text = "Probablemente decidió separarse de sus compinches, sin duda... No pudieron dividir el botín de manera justa. Ahora está en manos de la Compañía misma y esos tipos no se toman bien las bromas. Dicen que se apoderó de uno de los barcos de la Compañía con algo valioso. Aparentemente, es solo porque quieren sacarle algo de información, todavía no está colgando de una soga.";
			link.l1 = "Entonces, ¿cuándo será su ejecución, lo sabes?";
			link.l1.go = "Portugal_2";
		break;
		
		case "Portugal_2":
			dialog.text = "Nadie lo sabe. Creo que una vez que la Compañía descubra lo que quiere, le atarán un lazo de cáñamo alrededor del cuello. El portugués está en la prisión ahora mismo bajo guardia confiable. Recientemente trajeron aquí a su contramaestre también. Su historia fue aún más sorprendente, se entregó a los holandeses en Philipsburg. Así que lo han puesto en una celda justo al lado de su ex-capitán, ahora son vecinos, je-je...";
			link.l1 = "¡Milagros suceden! Muy bien, estaré atento a las noticias. No quiero perderme esa ejecución. Adiós, "+npchar.name+"¡";
			link.l1.go = "Portugal_3";
		break;
		
		case "Portugal_3":
			DialogExit();
			pchar.questTemp.Portugal = "PortugalInPrison";
			AddQuestRecord("Portugal", "32");
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
