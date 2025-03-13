// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("¿Qué tipo de preguntas, "+GetSexPhrase("hijo mío","mi hija")+"¿?","Pregunte, estoy escuchando..."),"Estoy escuchando, habla ahora, "+GetSexPhrase("hijo mío","mi hija")+"...","Por tercera vez, "+GetSexPhrase("mi hijo","mi hija")+", pide lo que necesites.","Un clérigo tiene mucho trabajo y me estás distrayendo, "+GetSexPhrase("hijo mío","mi hija")+"...","bloqueo",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("He cambiado de opinión...","No en este momento, padre..."),"No tengo nada que decir, mis disculpas.","Preguntaré, pero más tarde. Perdóname, padre.","Perdóname, santo padre...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			// калеуче
			if (CheckAttribute(pchar, "questTemp.Caleuche") && pchar.questTemp.Caleuche == "priest")
			{
				link.l1 = "Disculpe, padre, uno de los clérigos de su parroquia me pidió que investigara la casa en la que Joachim Merriman estaba alquilando una habitación...";
				link.l1.go = "caleuche";
			}
		break;
		
		// калеуче
		case "caleuche":
			dialog.text = "¿Entonces? ¿Has estado allí, hijo mío?";
			link.l1 = "Lo he hecho. Pero honestamente, hubiera sido mejor si no lo hubiera hecho. Fui atacado por un esqueleto con un hacha enorme en la habitación de arriba. Logré salir victorioso, aunque ciertamente no fue fácil.";
			link.l1.go = "caleuche_1";
		break;
		
		case "caleuche_1":
			dialog.text = "¡Señor, ten piedad de nuestras almas! ¡Mis peores temores se han hecho realidad!";
			link.l1 = "Eso no es todo, padre. Cuando finalmente lo derribé, chilló y sonó como una mujer. Al revisar los huesos, encontré algunas joyas, así que es seguro asumir que era la casera desaparecida.";
			link.l1.go = "caleuche_2";
		break;
		
		case "caleuche_2":
			dialog.text = "(se persigna)... Pobre sierva de Dios, que el Señor le conceda el descanso eterno...";
			link.l1 = "   Parece que Merriman es un brujo de verdad. No tengo idea de cómo alguien puede convertir a un hombre vivo en semejante abominación.";
			link.l1.go = "caleuche_3";
		break;
		
		case "caleuche_3":
			dialog.text = "Joachim Merriman es un brujo muy temible, hijo mío. Lo conocí en Europa, pero en aquel entonces no era capaz de algo así. Aquí, en el Caribe, logró hacerse con algo que le otorgó poderes sobrenaturales.";
			link.l1 = "¿Conocías a Merriman, Padre?";
			link.l1.go = "caleuche_4";
		break;
		
		case "caleuche_4":
			dialog.text = "That I did. Back then I was just a humble priest in one of Lisbon's parishes. Joachim Merriman was a wealthy nobleman, and at some point he became interested in old manuscripts and scrolls brought by sailors from distant lands. He also began to study alchemy, but after some time he went into seclusion.\nPeople saw flashes of light in his house; sometimes they could also smell something strange. Then they saw him in the cemetery at nights. Once they saw him digging out a fresh corpse and bringing it to his home. And when patience ran out, local father superior contacted the Inquisition.\nWhen the guards breached the door of Merriman's house, Joachim was not there - he had escaped through a secret passage. They found a lab in the basement, and even the seasoned soldiers were shocked and sickened by what they saw. Whole rotting and dismembered bodies, human and animal skeletons, strange things... Fear and hatred for Merriman was so significant that his house was demolished in an instant.\nMerriman disappeared without a trace. The Inquisition began to search for him, sentencing him in his absence to burn at a stake as a dangerous warlock. But they never found him. And now, after all these years, I saw him again on the streets of Willemstad.";
			link.l1 = "¿Por qué no se lo dijiste a los inquisidores?";
			link.l1.go = "caleuche_5";
		break;
		
		case "caleuche_5":
			dialog.text = "Hijo mío, ¿no sabes que nuestra iglesia está en desacuerdo con la Inquisición? Preferiría mantenerme alejado del Padre Vincento y sus matones.";
			link.l1 = "Entiendo. Padre, creo que sé de dónde Merriman obtuvo su poder. Se ha apoderado de un antiguo artefacto, una calavera de jade de Yum Cimil, un antiguo dios de la muerte adorado por los indios de la tribu Chavín.";
			link.l1.go = "caleuche_6";
		break;
		
		case "caleuche_6":
			dialog.text = "Hum, Merriman era conocido por realizar rituales hechiceros y experimentos con cadáveres, así que bien podría ser cierto. Doy gracias a Dios que este hombre terrible ha dejado Willemstad y que tú has destruido las semillas diabólicas que intentó plantar aquí. Estamos profundamente en deuda contigo, hijo mío. Por favor, acepta estos objetos santificados como tu recompensa.";
			link.l1 = "Gracias, Padre";
			link.l1.go = "caleuche_7";
		break;
		
		case "caleuche_7":
			Log_Info("You have received church amulets");
			PlaySound("interface\important_item.wav");
			GiveItem2Character(pchar, "amulet_2"); 
			GiveItem2Character(pchar, "amulet_6"); 
			GiveItem2Character(pchar, "amulet_8"); 
			GiveItem2Character(pchar, "amulet_10"); 
			ref sld = characterFromId("Havana_Priest");
			dialog.text = "Pero eso no fue el fin de nuestros problemas, hijo mío. Recientemente, he recibido una carta de "+sld.name+", padre superior de la iglesia en La Habana. Trae terribles noticias. En una cueva, en la selva de Cuba, los cazadores han visto abominaciones espantosas, los muertos vivientes. Y todo es más molesto considerando el hecho de que recientemente, personas han desaparecido después de adentrarse en la selva.";
			link.l1 = "Mm... ¿estás insinuando que esto también es obra de Merriman?";
			if (CheckCharacterItem(pchar, "HolTradeLicence") && GetDaysContinueNationLicence(HOLLAND) >= 30) link.l1.go = "caleuche_8_1";
			else link.l1.go = "caleuche_8";
		break;
		
		case "caleuche_8":
			sld = characterFromId("Havana_Priest");
			dialog.text = "No sé qué pensar, hijo mío. Pero si ese brujo negro se volvió tan poderoso, todos los habitantes del archipiélago están en grave peligro. Sólo Dios sabe qué podría tener en mente este siervo del diablo\nEspero que el Padre "+sld.name+" estaba equivocado, pero de todos modos - por favor, ve a La Habana y habla con él. He preparado una licencia de comercio para ti, que es válida por un mes. Con ella, podrás entrar al puerto de La Habana sin ninguna dificultad.";
			link.l1 = "Está bien, Padre. Me dirigiré a La Habana.";
			link.l1.go = "caleuche_9";
			npchar.quest.givelicence = true;
		break;
		
		case "caleuche_8_1":
			sld = characterFromId("Havana_Priest");
			dialog.text = "No sé qué pensar, hijo mío. Pero si ese brujo negro se ha vuelto tan poderoso, todos los habitantes del archipiélago están en grave peligro. Sólo Dios sabe qué podría tener en mente este siervo de los demonios.\nEspero que el Padre "+sld.name+" estaba equivocado, pero no importa - te pido que viajes a La Habana y hables con él.";
			link.l1 = "Por supuesto, Padre. Me dirigiré a La Habana de inmediato.";
			link.l1.go = "caleuche_9";
		break;
		
		case "caleuche_9":
			dialog.text = "Me alegra que seas un verdadero hijo de la Iglesia. Rezaré por tu salud y bienestar día y noche. Ve con mi bendición. Que el Señor te fortalezca en tu lucha contra estos poderes impíos.";
			link.l1 = "Gracias y adiós, Padre.";
			link.l1.go = "caleuche_10";
		break;
		
		case "caleuche_10":
			DialogExit();
			AddQuestRecord("Caleuche", "26");
			AddCharacterMaxHealth(pchar, 1);
			if (CheckAttribute(npchar, "quest.givelicence")) GiveNationLicence(HOLLAND, 30);
			ChangeCharacterComplexReputation(pchar, "nobility", 2);
			ChangeCharacterComplexReputation(pchar, "authority", 1);
			ChangeCharacterComplexReputation(pchar, "fame", 3);
			ChangeCharacterNationReputation(pchar, HOLLAND, 5);
			AddCharacterExpToSkill(pchar, "Leadership", 300);
			pchar.questTemp.Caleuche = "havana";
			Caleuche_PrepareCubaGrot();
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
