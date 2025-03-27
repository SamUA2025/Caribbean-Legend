void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag, arTmp;
	int i, n;
	string sTemp, sStr;
	
	DeleteAttribute(&Dialog,"Links");
	
	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	switch(Dialog.CurrentNode)
	{
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		case "First time":
			dialog.text = "¿Qué es lo que usted necesita?";
			link.l1 = "Nada.";
			link.l1.go = "exit";
		break;
		
		case "fight":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			LAi_group_Attack(NPChar, Pchar);
			if (rand(3) != 1) SetNationRelation2MainCharacter(sti(npchar.nation), RELATION_ENEMY);
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		
		case "AlonsoNaPalube":
			if (CheckAttribute(pchar, "questTemp.LadyBeth_AlonsoNaPalube"))
			{
				pchar.questTemp.LadyBeth_AlonsoNaPalube2 = true;
				dialog.text = "¿Su decisión, capitán? ¿Quizás no deberíamos hacerlo?";
				link.l1 = "¿Lograste reunir más voluntarios para esto?";
				link.l1.go = "AlonsoNaPalube_StrongGroup";
			}
			else
			{
				pchar.questTemp.LadyBeth_AlonsoNaPalube = true;
				dialog.text = "Capitán, unas palabras si me lo permite.";
				link.l1 = "Informa, Alonso.";
				link.l1.go = "AlonsoNaPalube_2";
			}
			locCameraFromToPos(0.71, 11.25, -21.73, true, 4.29, 9.18, -21.40);
		break;
		
		case "AlonsoNaPalube_2":
			dialog.text = "La tripulación se pregunta cuáles son sus planes para Caimán. Los hombres están preocupados.";
			link.l1 = "Aún no lo he decidido. ¿Y por qué están preocupados, Alonso?";
			link.l1.go = "AlonsoNaPalube_3";
		break;
		
		case "AlonsoNaPalube_3":
			dialog.text = "Esa isla es el dominio del capitán Blackwood. Los marineros dicen que la excava de cabo a rabo como un poseído. Que ha perdido a decenas de hombres en sus excavaciones... Y los que lo han abandonado cuentan cosas extrañas.";
			link.l1 = "¿Qué cosas?";
			link.l1.go = "AlonsoNaPalube_4";
		break;
		
		case "AlonsoNaPalube_4":
			dialog.text = "Que Blackwood ya no es el mismo hombre de antes. Que está obsesionado con encontrar algún tesoro de conquistadores. Que está dispuesto a sacrificarlo todo y a todos por él. Sabemos cuánto le gusta meterse en bonitas historias, desembarcar solo y caer en trampas... Pero de esta no saldrá.";
			link.l1 = "Gracias por el informe y la advertencia. Si aun así decido desembarcar, llevaré conmigo la vanguardia y un destacamento de nuestros mejores hombres.";
			link.l1.go = "AlonsoNaPalube_5";
		break;
		
		case "AlonsoNaPalube_5":
			dialog.text = "Eso puede ser complicado, capitán. El abordaje es una cosa, pero en tierra enfrentarse a balas de infantería de marina y a sables de toda la calaña que, dicen, Blackwood ha contratado en cada rincón de las Antillas Menores, es muy diferente. Y los rumores sobre Caimán no son nada buenos... No encontrará muchos voluntarios para esa tarea.";
			link.l1 = "Entonces tendremos que arreglárnoslas con los que tengamos. Tu participación es imprescindible, Alonso.";
			link.l1.go = "AlonsoNaPalube_LiteGroup";
			link.l2 = "En mi opinión, ya he demostrado todo lo que había que demostrar. Todos los buenos combatientes y tiradores vienen conmigo. Es una orden.";
			link.l2.go = "AlonsoNaPalube_StrongGroup";
			link.l3 = "Hmm... Necesito pensarlo. Es posible que volvamos a este asunto más tarde.";
			link.l3.go = "AlonsoNaPalube_Exit";
		break;
		
		case "AlonsoNaPalube_Exit":
			SetFunctionLocationCondition("LadyBeth_CaimanSea", "Caiman", false);
			EndQuestMovie();
			bQuestDisableMapEnter = false;
			chrDisableReloadToLocation = false;
			if(UnloadLocation(loadedLocation) == true)
			{
				pchar.Ship.Pos.x = 0;
				pchar.Ship.Pos.z = 0;
				pchar.Ship.Ang.y = 0;
				Land_MapLoad();
				pchar.location = "";
			}
		break;
		
		case "AlonsoNaPalube_LiteGroup":
			dialog.text = "Por supuesto, capitán.";
			link.l1 = "¿Y qué hay del barco de Blackwood? ¿No nos causará problemas?";
			link.l1.go = "AlonsoNaPalube_Vpered";
			pchar.questTemp.LadyBeth_LiteGroup = true;
		break;
		
		case "AlonsoNaPalube_StrongGroup":
			if (GetSummonSkillFromName(pchar, SKILL_Leadership) >= 50 || sti(pchar.rank) >= 17)
			{
				dialog.text = "Por supuesto, capitán.";
				link.l1 = "¿Y qué hay del barco de Blackwood? ¿No nos causará problemas?";
				link.l1.go = "AlonsoNaPalube_Vpered";
				pchar.questTemp.LadyBeth_StrongGroup = true;
				if (GetSummonSkillFromName(pchar, SKILL_Leadership) >= 50) notification("Comprobación superada", SKILL_Leadership);
				if (sti(pchar.rank) >= 17) notification("Chequeo de nivel superado", "None");
			}
			else
			{
				if (CheckAttribute(pchar, "questTemp.LadyBeth_AlonsoNaPalube2"))
				{
					dialog.text = "Me temo que no, capitán.";
				}
				else
				{
					dialog.text = "No tiene nada que demostrarme ni a mí ni a sus oficiales, y obedeceremos la orden y iremos adonde usted diga, pero un marinero común piensa de otra manera. Me temo que habrá problemas, capitán.";
				}
				link.l1 = "Entonces tendremos que arreglárnoslas con los que tengamos. Tu participación es imprescindible, Alonso.";
				link.l1.go = "AlonsoNaPalube_LiteGroup";
				link.l2 = "Hmm... Necesito pensarlo. Es posible que volvamos a este asunto más tarde.";
				link.l2.go = "AlonsoNaPalube_Exit";
				if (GetSummonSkillFromName(pchar, SKILL_Leadership) < 50) notification("Habilidad insuficientemente desarrollada (50)", SKILL_Leadership);
				if (sti(pchar.rank) < 17) notification("Se requiere nivel 17", "None");
			}
		break;
		
		case "AlonsoNaPalube_Vpered":
			dialog.text = "Una Galeota. Dicen que es una auténtica belleza con un temperamento feroz. Yo no me preocuparía por ella. Seguramente toda la tripulación trabaja como condenada en tierra, mientras el barco está bien escondido entre los pliegues de la línea costera. Cuando, y si ganamos, podremos tomarla como botín.";
			link.l1 = "Reúne a los hombres. Hoy es un buen día - la fortuna estará de nuestro lado.";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("LadyBeth_AlonsoNaPalube_Vpered");
		break;
		
		// Диалог в таверне с Блеквудом
		case "LadyBeth_DialogInCity": // главное меню
			if (CheckAttribute(pchar, "questTemp.LadyBeth_DialogInCity_Fourth"))
			{
				dialog.text = "Me alegra verlo, capitán. Creo que ya lo hemos discutido todo.";
				link.l1 = "En realidad. Adiós.";
				link.l1.go = "exit";
				NextDiag.TempNode = "LadyBeth_DialogInCity_again";
				break;
			}
			if (CheckAttribute(pchar, "questTemp.LadyBeth_DialogInCity_Third"))
			{
				dialog.text = "...";
				link.l1 = ""+TimeGreeting()+", Albert.";
				link.l1.go = "LadyBeth_DialogInCity_Third_2";
				break;
			}
			if (CheckAttribute(pchar, "questTemp.LadyBeth_DialogInCity_Second"))
			{
				dialog.text = "...";
				link.l1 = ""+TimeGreeting()+", capitán Blackwood.";
				link.l1.go = "LadyBeth_DialogInCity_Second_1";
				break;
			}
			if (startHeroType == 4)
			{
				dialog.text = "...";
				link.l1 = "Buenos días. ¿Es usted el capitán Blackwood?";
				link.l1.go = "LadyBeth_DialogInCity_First_Helena_1";
			}
			else
			{
				dialog.text = "...";
				link.l1 = ""+TimeGreeting()+". ¿Es usted el capitán Albert Blackwood, verdad?";
				link.l1.go = "LadyBeth_DialogInCity_First_1";
			}
		break;
		
		case "LadyBeth_DialogInCity_again": // повтор
			dialog.text = "Me alegra verlo, capitán. Creo que ya lo hemos discutido todo.";
			link.l1 = "Es cierto. Adiós.";
			link.l1.go = "exit";
			NextDiag.TempNode = "LadyBeth_DialogInCity_again";
		break;
		
		case "LadyBeth_DialogInCity_First_1": // первый диалог
			dialog.text = "Sí, el mismo. ¿Y usted?";
			link.l1 = "Capitán "+GetFullName(pchar)+". Comando el barco '" + PChar.Ship.Name + "'.";
			link.l1.go = "LadyBeth_DialogInCity_First_2";
		break;
		
		case "LadyBeth_DialogInCity_First_2":
			dialog.text = "Capitán... ¿Ha estado en las Caimán?";
			link.l1 = "Solo pasé de largo.";
			link.l1.go = "LadyBeth_DialogInCity_First_3";
		break;
		
		case "LadyBeth_DialogInCity_First_3":
			dialog.text = "¿Ha oído algo sobre tesoros allí?";
			link.l1 = "No, nada concreto.";
			link.l1.go = "LadyBeth_DialogInCity_First_4";
		break;
		
		case "LadyBeth_DialogInCity_First_4":
			dialog.text = "¿Huellas de los españoles? ¿Armas antiguas? ¿Monedas de la época de los conquistadores?";
			link.l1 = "No he encontrado nada de eso.";
			link.l1.go = "LadyBeth_DialogInCity_First_5";
		break;
		
		case "LadyBeth_DialogInCity_First_5":
			dialog.text = "¿Leyendas locales? ¿Historias sobre Cortés? ¿Algo sobre entierros?";
			link.l1 = "Lo siento, capitán, pero no dispongo de esa información. Y esto ya empieza a parecer un interrogatorio.";
			link.l1.go = "LadyBeth_DialogInCity_First_6";
		break;
		
		case "LadyBeth_DialogInCity_First_6":
			dialog.text = "Le pido disculpas... Mala costumbre de un exoficial. Es solo que... esto es extremadamente importante para mí.";
			link.l1 = "¿Por qué le interesa tanto precisamente Caimán?";
			link.l1.go = "LadyBeth_DialogInCity_First_7";
		break;
		
		case "LadyBeth_DialogInCity_First_7":
			dialog.text = "No importa. Una vez más, le pido disculpas.";
			link.l1 = "Entiendo. Buena suerte en su búsqueda.";
			link.l1.go = "LadyBeth_DialogInCity_First_8";
		break;
		
		case "LadyBeth_DialogInCity_First_8":
			if (GetHour() >= 23 || GetHour() < 6) sStr = "Buenas noches";
			else sStr = "Un buen día para usted";
			dialog.text = "Pase por aquí si aparece algo interesante. Sería un placer hablar con otro capitán... con alguien que entiende el mar. Que tenga un buen día. " + sStr + ".";
			link.l1 = ""+Goodbye()+".";
			link.l1.go = "LadyBeth_DialogInCity_First_9";
		break;
		
		case "LadyBeth_DialogInCity_First_9":
			DialogExit();
			
			NextDiag.CurrentNode = "LadyBeth_DialogInCity_again";
			pchar.questTemp.LadyBeth_DialogInCity_Second = true;
		break;
		
		case "LadyBeth_DialogInCity_First_Helena_1": // первый диалог с Элен
			dialog.text = "En persona. ¿Y usted... capitán Helen MacArthur? ¿Protegida de Jan Swenson, verdad? He oído hablar de usted.";
			link.l1 = "Está bien informado, capitán Blackwood. Pero no me sorprende que un oficial inglés sepa quién soy.";
			link.l1.go = "LadyBeth_DialogInCity_First_Helena_2";
		break;
		
		case "LadyBeth_DialogInCity_First_Helena_2":
			dialog.text = "Ex oficial. Y todos los casacas rojas conocen sus... privilegios únicos otorgados por la Corona. El dinero, como dicen, no huele. Y la historia de cómo su padre, Sean MacArthur, la llevó al mar desde pequeña y la hizo capitana se ha convertido en una especie de leyenda en la flota.";
			link.l1 = "¿Y qué siente al encontrarse con esta leyenda?";
			link.l1.go = "LadyBeth_DialogInCity_First_Helena_3";
		break;
		
		case "LadyBeth_DialogInCity_First_Helena_3":
			dialog.text = "Personalmente, estoy impresionado. Aunque muchos de mis antiguos colegas, lo admito, lo encuentran bastante irritante. Pero para ser capitán se necesita algo más que noble cuna o un título real, ¿no es así?";
			link.l1 = "Así es. Se necesitan conocimientos, experiencia y una disposición constante a demostrar la propia competencia. Especialmente en mi caso.";
			link.l1.go = "LadyBeth_DialogInCity_First_Helena_4";
		break;
		
		case "LadyBeth_DialogInCity_First_Helena_4":
			dialog.text = "¡Exactamente! En el mar, como en la vida, no importan los títulos, sino los resultados. Encantado de conocerla, capitán MacArthur. Espero que nos volvamos a ver. ¿Quizás pase por una copa de vino cuando regrese de mi expedición?";
			link.l1 = "Tal vez. Buena suerte en su búsqueda, capitán.";
			link.l1.go = "LadyBeth_DialogInCity_First_Helena_5_harizma";
			link.l2 = "No me interesa. Pero buena suerte en su búsqueda, capitán.";
			link.l2.go = "LadyBeth_DialogInCity_First_Helena_5_oruzhie";
		break;
		
		case "LadyBeth_DialogInCity_First_Helena_5_harizma":
			DialogExit();
			
			NextDiag.CurrentNode = "LadyBeth_DialogInCity_again";
			pchar.questTemp.LadyBeth_DialogInCity_Second = true;
			AddCharacterExpToSkill(pchar, "Leadership", 200);
		break;
		
		case "LadyBeth_DialogInCity_First_Helena_5_oruzhie":
			DialogExit();
			
			NextDiag.CurrentNode = "LadyBeth_DialogInCity_again";
			pchar.questTemp.LadyBeth_DialogInCity_Second = true;
			AddComplexSelfExpToScill(50, 50, 50, 50);
		break;
		
		case "LadyBeth_DialogInCity_Second_1": // второй диалог
			dialog.text = "Ah, capitán "+pchar.lastname+"! Me alegra verlo. ¿Se sienta?";
			link.l1 = "Con gusto.";
			link.l1.go = "LadyBeth_DialogInCity_Second_2";
		break;
		
		case "LadyBeth_DialogInCity_Second_2":
			dialog.text = "Capitán... dígame, ¿qué significan para usted los verdaderos tesoros?";
			link.l1 = "El verdadero tesoro es el amor. La persona adecuada está cerca. No hay nada peor que estar solo.";
			link.l1.go = "LadyBeth_DialogInCity_Second_3_love";
			link.l2 = "Dinero, por supuesto. ¿Qué otra cosa podría ser un tesoro?";
			link.l2.go = "LadyBeth_DialogInCity_Second_3_sokrovisha";
			link.l3 = "Equipo valioso y único. Una buena espada o pistola vale más que el oro.";
			link.l3.go = "LadyBeth_DialogInCity_Second_3_oruzhie";
			link.l4 = "El conocimiento. El tesoro más valioso es lo que tienes en la cabeza.";
			link.l4.go = "LadyBeth_DialogInCity_Second_3_znania";
		break;
		
		case "LadyBeth_DialogInCity_Second_3_love":
			if (startHeroType == 4)
			{
				dialog.text = "¿Amor? Hm... No esperaba esa respuesta de la hija de un pirata. Yo... estaba comprometido con Elizabeth. La hija de un plantador de Barbados. Pero su padre... pensaba que no tenía suficiente dinero. ¿Qué podía ofrecerle a su hija, aparte de mi amor? Usted tuvo suerte, capitana MacArthur. Tenía un padre que valoraba sus habilidades por encima de su dote.";
				link.l1 = "Quizás no sea cuestión de suerte, sino que el verdadero amor no se mide en oro. Mi padre lo entendía. ¿Y su prometida? ¿Comparte la opinión de su padre?";
				link.l1.go = "LadyBeth_DialogInCity_Second_3_love_Helena_1";
			}
			else
			{
				dialog.text = "¿Amor? Sí... Quizás tengas razón. Estaba... comprometido. En Barbados. Nos amábamos, pero... su padre pensó que no era un buen partido. ¡Ja! No lo suficientemente rico. Por eso estoy aquí - buscando tesoros para demostrarles a todos. ¿Quizás en vano?";
				link.l1 = "Quizás deberías simplemente hablar con ella. Al diablo con ese plantador.";
				link.l1.go = "LadyBeth_DialogInCity_Second_3_love_2";
			}
			AddComplexLandExpToScill(100, 100, 0);
		break;
		
		case "LadyBeth_DialogInCity_Second_3_love_2":
			dialog.text = "Hablar... Sí, tal vez. Pero ¿qué le diré? 'Perdón, no pude darte una vida digna'? No. Debo regresar como un vencedor. O no regresar en absoluto.";
			link.l1 = "...";
			link.l1.go = "LadyBeth_DialogInCity_Second_4";
		break;
		
		case "LadyBeth_DialogInCity_Second_3_love_Helena_1":
			dialog.text = "¿Elizabeth? No... ella me ama. Pero yo... no podía permitir que viviera en la pobreza. Ella merece algo mejor. Y debo demostrar que soy digno de ella.";
			link.l1 = "A veces, el orgullo impide la felicidad más que la pobreza, capitán.";
			link.l1.go = "LadyBeth_DialogInCity_Second_3_love_Helena_2";
		break;
		
		case "LadyBeth_DialogInCity_Second_3_love_Helena_2":
			dialog.text = "No puedo regresar con las manos vacías. Simplemente no puedo. Disculpe, tengo mucho trabajo. Ha sido un placer conversar con usted, capitana MacArthur.";
			link.l1 = "...";
			link.l1.go = "LadyBeth_DialogInCity_Second_5";
		break;
		
		case "LadyBeth_DialogInCity_Second_3_sokrovisha":
			dialog.text = "Qué respuesta tan banal. Pero es difícil discutirla. De verdad, cuando creces en los barrios bajos de Bristol, cuando tienes que pelear por las sobras... empiezas a entender el verdadero valor del dinero. No es un lujo. Es libertad. La posibilidad de no volver a esa miseria de la que saliste con tanto esfuerzo.";
			link.l1 = "Estoy de acuerdo. El dinero resuelve la mayoría de los problemas. Y si no los resuelve, es que no había suficiente.";
			link.l1.go = "LadyBeth_DialogInCity_Second_3_sokrovisha_2";
			AddCharacterExpToSkill(pchar, "Commerce", 200);
		break;
		
		case "LadyBeth_DialogInCity_Second_3_sokrovisha_2":
			dialog.text = "¡Exactamente! Usted lo entiende. El dinero no da la felicidad, pero su ausencia te hace infeliz con seguridad. Lo sé muy bien...";
			link.l1 = "...";
			link.l1.go = "LadyBeth_DialogInCity_Second_4";
		break;
		
		case "LadyBeth_DialogInCity_Second_3_oruzhie":
			dialog.text = "Interesante. Práctico. Tengo una arcabuz... auténtica, de la época de los conquistadores. Un regalo de un sacerdote. A veces pienso que vale más que todo el oro que he encontrado. Pero... eso no resolverá mis problemas.";
			link.l1 = "Un buen arma puede resolver muchos problemas. Y nunca te traicionará.";
			link.l1.go = "LadyBeth_DialogInCity_Second_3_oruzhie_2";
			AddComplexSelfExpToScill(50, 50, 50, 50);
		break;
		
		case "LadyBeth_DialogInCity_Second_3_oruzhie_2":
			dialog.text = "Hay algo de cierto en eso. Pero algunas batallas no se pueden ganar con armas.";
			link.l1 = "...";
			link.l1.go = "LadyBeth_DialogInCity_Second_4";
		break;
		
		case "LadyBeth_DialogInCity_Second_3_znania":
			dialog.text = "El conocimiento... Sí, lo entiendo. Estudié todo lo que pude sobre los conquistadores, sobre los tesoros. Redacté un reglamento completo de búsqueda. Inventé un sistema de entrenamientos regulares y recompensas materiales para la compañía de fusileros del barco\nCualquier capitán estaría encantado de tener mi reglamento. Pero todo ese conocimiento... es inútil si no lleva a un resultado. A un resultado real.";
			link.l1 = "Pero es el conocimiento el que permite alcanzar un resultado. Sin él, toda búsqueda es solo un vagar en la oscuridad.";
			link.l1.go = "LadyBeth_DialogInCity_Second_4";
			AddCharacterExpToSkill(pchar, "Sailing", 100);
			AddCharacterExpToSkill(pchar, "Sneak", 100);
		break;
		
		case "LadyBeth_DialogInCity_Second_4":
			if (GetHour() >= 23 || GetHour() < 6) sStr = "Bueno, ya es tarde y tengo mucho trabajo.";
			else sStr = "Bueno, tengo mucho trabajo.";
			dialog.text = "" + sStr + ". Gracias por la conversación, capitán. Ha sido realmente interesante.";
			link.l1 = "Gracias a usted también. "+Goodbye()+".";
			link.l1.go = "LadyBeth_DialogInCity_Second_5";
		break;
		
		case "LadyBeth_DialogInCity_Second_5":
			DialogExit();
			
			NextDiag.CurrentNode = "LadyBeth_DialogInCity_again";
			pchar.questTemp.LadyBeth_DialogInCity_Third = true;
		break;
		
		case "LadyBeth_DialogInCity_Third_2": // третий диалог
			dialog.text = "Ah, "+pchar.name+"! Me alegra verte. Tengo excelentes noticias: por fin encontré la solución a mis problemas. Pronto me embarcaré en una expedición, y esta vez regresaré con un verdadero tesoro. Un consejo de amigo: mantente alejado de Caimán. Ahora es mi territorio.";
			link.l1 = "Caimán no te pertenece, Albert. No tienes derechos de la Corona sobre él. Eso es piratería.";
			link.l1.go = "LadyBeth_DialogInCity_Third_3_harizma";
			link.l2 = "¿Me está amenazando, Blackwood?";
			link.l2.go = "LadyBeth_DialogInCity_Third_3_oruzhie";
		break;
		
		case "LadyBeth_DialogInCity_Third_3_harizma":
			dialog.text = "¿Derechos de la Corona? Si hubieras vivido en los barrios bajos de Bristol, "+pchar.name+", sabrías lo que valen esos papeles. Cuando tienes hambre, la ley no significa nada. Pero... tienes razón. Formalmente no tengo derechos sobre la isla\nPero allí encontré lo que busqué durante años. Y no permitiré que nadie me lo quite.";
			link.l1 = "Espero que sepa que está siguiendo un camino peligroso.";
			link.l1.go = "LadyBeth_DialogInCity_Third_3_harizma_2";
			AddCharacterExpToSkill(pchar, "Leadership", 200);
		break;
		
		case "LadyBeth_DialogInCity_Third_3_harizma_2":
			dialog.text = "Siempre supe que mi camino no sería fácil. Adiós, "+pchar.name+". Quizás nos volvamos a ver.";
			link.l1 = ""+Goodbye()+".";
			link.l1.go = "LadyBeth_DialogInCity_Third_4";
		break;
		
		case "LadyBeth_DialogInCity_Third_3_oruzhie":
			dialog.text = "¿Estoy amenazando? Por supuesto que no. Sólo consejos amistosos de un capitán a otro. Caimán es peligroso... especialmente para aquellos que interfieren en mis asuntos.";
			link.l1 = "Recordaré su 'consejo'. Buena suerte en Caimán.";
			link.l1.go = "LadyBeth_DialogInCity_Third_3_oruzhie_2";
			AddComplexSelfExpToScill(50, 50, 50, 50);
		break;
		
		case "LadyBeth_DialogInCity_Third_3_oruzhie_2":
			dialog.text = "Buena suerte también para usted, capitán. Espero que no la necesite. Adiós.";
			link.l1 = ""+Goodbye()+".";
			link.l1.go = "LadyBeth_DialogInCity_Third_4";
		break;
		
		case "LadyBeth_DialogInCity_Third_4":
			DialogExit();
			
			NextDiag.CurrentNode = "LadyBeth_DialogInCity_again";
			pchar.questTemp.LadyBeth_DialogInCity_Fourth = true;
		break;
		
		// Ловушка, абордаж в каюте
		case "LadyBeth_abordage":
			if (CheckAttribute(pchar, "questTemp.LadyBeth_DialogInCity_Second"))
			{
				dialog.text = "¿Ustedes? ¡¿Creen que me rendiré?! ¿Creen que volveré a la miseria? ¡Prefiero morir antes que volver a pasar hambre en los barrios bajos! ¡Ninguna piedad, ninguna recompensa, ninguna victoria! Hay un barril de pólvora bajo la litera... ¡Todos nos iremos al fondo!";
				link.l1 = "...";
				link.l1.go = "exit";
				AddDialogExitQuestFunction("LadyBeth_Lovushka");
			}
			else
			{
				dialog.text = "¿Quién es usted para atacarme?! ¿Cree que me rendiré? ¡No! Prefiero morir antes que volver a pasar hambre en los barrios bajos. ¡Ninguna piedad, ninguna recompensa, ninguna victoria! Hay un barril de pólvora bajo la litera... ¡Todos nos iremos al fondo!";
				link.l1 = "...";
				link.l1.go = "exit";
				AddDialogExitQuestFunction("LadyBeth_Lovushka");
			}
		break;
		
		// Блеквуд разговаривает с ГГ перед битвой на Каймане
		case "LadyBeth_BlackWood_Boss":
			if (CheckAttribute(pchar, "questTemp.LadyBeth_DialogInCity_Second"))
			{
				dialog.text = "¡Capitán! Le advertí. Ahora pagará por su curiosidad.";
			}
			else
			{
				dialog.text = "¿Quién es usted y cómo se atreve a invadir mi territorio? ¡Esta isla es mía!";
			}
			link.l1 = "Ya veremos, Blackwood. Hoy habrá un poseído menos en este mundo.";
			link.l1.go = "LadyBeth_BlackWood_Boss_oruzhie_1";
			link.l2 = "Resolvámoslo de forma pacífica, Blackwood. Puedo irme.";
			link.l2.go = "LadyBeth_BlackWood_Boss_torgovlya_1";
			link.l3 = "¡Blackwood, usted es un hombre razonable! ¡Es un oficial! ¡La bandera real ondea sobre su campamento, maldita sea! ¿De verdad no podemos llegar a un acuerdo?";
			link.l3.go = "LadyBeth_BlackWood_Boss_harizma_1";
		break;
		
		case "LadyBeth_BlackWood_Boss_oruzhie_1":
			dialog.text = "¿Poseído? ¡Ja! ¡Sólo soy un hombre que sabe lo que quiere!";
			link.l1 = "...";
			link.l1.go = "LadyBeth_BlackWood_Boss_2";
			AddComplexSelfExpToScill(50, 50, 50, 50);
		break;
		
		case "LadyBeth_BlackWood_Boss_torgovlya_1":
			dialog.text = "¿Irte? ¿Después de lo que has visto? ¡No, no, no! Nadie debe saber lo que he encontrado aquí. ¡Nadie!";
			link.l1 = "Le doy mi palabra de que no se lo diré a nadie. Lo juro por el honor de un capitán.";
			link.l1.go = "LadyBeth_BlackWood_Boss_torgovlya_2";
			AddCharacterExpToSkill(pchar, "Commerce", 200);
		break;
		
		case "LadyBeth_BlackWood_Boss_torgovlya_2":
			dialog.text = "No hay honor en este mundo, capitán. Sólo hay suciedad, miseria y desprecio. Lo siento, pero debe morir aquí.";
			link.l1 = "...";
			link.l1.go = "LadyBeth_BlackWood_Boss_2";
		break;
		
		case "LadyBeth_BlackWood_Boss_harizma_1":
			dialog.text = "He pensado. Mucho. Y entendí que esta es mi única oportunidad. O encuentro el oro de Cortés, o... nada. ¿Lo entiende? ¡Nada! ¡No volveré a mi antigua vida! ¡No volveré a la suciedad y la miseria! ¡Prefiero morir aquí!";
			link.l1 = "...";
			link.l1.go = "LadyBeth_BlackWood_Boss_2";
			AddCharacterExpToSkill(pchar, "Leadership", 200);
		break;
		
		case "LadyBeth_BlackWood_Boss_2":
			dialog.text = "¡Al combate! ¡Bullock, Fraser - disparen metralla si se acercan! ¡Hopkins, al ataque!";
			link.l1 = "...";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("LadyBeth_CaimanKino_11");
		break;
		
		// Диалоги с офицерами
		case "LadyBeth_Helena_1": // Элен
			dialog.text = "¿Estás bien?";
			link.l1 = "Sí, todo bien. ¿Y tú?";
			link.l1.go = "LadyBeth_Helena_2";
			DelLandQuestMark(npchar);
		break;
		
		case "LadyBeth_Helena_2":
			dialog.text = "Viva. Pero estas batallas en tierra no son para mí. Dame una cubierta bajo los pies y destruiré cualquier barco, pero aquí... es un lugar extraño. Hacer que un centenar de lobos marinos baje a tierra, con picos, construyendo fortificaciones... No podría hacerlo.";
			link.l1 = "Blackwood sabía cómo inspirar a su tripulación.";
			link.l1.go = "LadyBeth_Helena_3";
		break;
		
		case "LadyBeth_Helena_3":
			dialog.text = "Escuché sobre él en Blueveldt. Muchos marineros ingleses hablaban de él con respeto. El mejor oficial de la flota, una carrera brillante... y de repente lo dejó todo por buscar tesoros.";
			link.l1 = "¿Qué piensas de él?";
			link.l1.go = "LadyBeth_Helena_4";
		break;
		
		case "LadyBeth_Helena_4":
			dialog.text = "Creo que el ejemplo de Blackwood muestra claramente el peso de la responsabilidad que nosotros... o mejor dicho, tú, llevas por tu gente. Te lo ruego, no te conviertas en el mismo tipo de capitán que él.";
			link.l1 = "Haré lo posible, Helen.";
			link.l1.go = "LadyBeth_Helena_5";
		break;
		
		case "LadyBeth_Helena_5":
			dialog.text = "Gracias, mi capitán. Sé que lo lograrás.";
			link.l1 = "Nosotros.";
			link.l1.go = "LadyBeth_Helena_6";
		break;
		
		case "LadyBeth_Helena_6":
			dialog.text = "Nosotros.";
			link.l1 = "...";
			link.l1.go = "LadyBeth_Helena_7";
		break;
		
		case "LadyBeth_Helena_7":
			DialogExit();
			Return_HelenaOfficer();
		break;
		
		case "LadyBeth_Mary_1": // Мэри
			dialog.text = "Charles... qué lugar tan espeluznante.";
			link.l1 = "¿Estás bien, Mary? Te comportaste como una auténtica soldado.";
			link.l1.go = "LadyBeth_Mary_2";
			DelLandQuestMark(npchar);
		break;
		
		case "LadyBeth_Mary_2":
			dialog.text = "No, no estoy bien, sí, ¿eh? ¡Mira a estas personas! Trabajaron hasta el agotamiento, vivieron con hambre, murieron de enfermedades... ¿Y para qué? Por un oro que quizá ni siquiera exista.";
			link.l1 = "Blackwood creía que estaba aquí.";
			link.l1.go = "LadyBeth_Mary_3";
		break;
		
		case "LadyBeth_Mary_3":
			dialog.text = "Este uniforme rojo... igual que el mío. Oficial inglés... Sabes, de repente pensé en mis padres, sí, ¿eh?. En mis raíces... en lo que nunca conocí. ¿Quizá yo también soy así?";
			link.l1 = "¿Cómo cuáles?";
			link.l1.go = "LadyBeth_Mary_4";
		break;
		
		case "LadyBeth_Mary_4":
			dialog.text = "De los que buscan algo que tal vez ni siquiera exista. Y luego se pierden en esa búsqueda. Yo... me gustaría hablar de esto más tarde, sí, ¿eh?. Cuando hayamos dejado este lugar horrible.";
			link.l1 = "Por supuesto, Mary.";
			link.l1.go = "LadyBeth_Mary_5";
		break;
		
		case "LadyBeth_Mary_5":
			dialog.text = "Enterrémoslo primero, sí? Aunque no lo merezca. Por la persona que fue alguna vez.";
			link.l1 = "...";
			link.l1.go = "LadyBeth_Mary_6";
		break;
		
		case "LadyBeth_Mary_6":
			DialogExit();
			Return_MaryOfficer();
		break;
		
		case "LadyBeth_Tichingitu_1": // Тичингиту
			dialog.text = "Capitán, Tichingitu ve que este es un mal lugar. Muy mal lugar.";
			link.l1 = "¿Qué quieres decir?";
			link.l1.go = "LadyBeth_Tichingitu_2";
			DelLandQuestMark(npchar);
		break;
		
		case "LadyBeth_Tichingitu_2":
			dialog.text = "Esta isla ahora está maldita. La tierra ha absorbido demasiada sangre y lágrimas. Cualquiera que excave aquí respira esta maldición.";
			link.l1 = "¿Crees que Blackwood estaba poseído?";
			link.l1.go = "LadyBeth_Tichingitu_3";
		break;
		
		case "LadyBeth_Tichingitu_3":
			dialog.text = "No sólo poseído. Él era... cómo decirlo... un recipiente vacío. Algo entró en él y desplazó su alma. Ya vi algo así antes. Cuando el chamán de mi tribu ofrecía un sacrificio humano a los espíritus. Ese chamán tenía la misma mirada.";
			link.l1 = "Pero, ¿qué pudo causar tal posesión?";
			link.l1.go = "LadyBeth_Tichingitu_4";
		break;
		
		case "LadyBeth_Tichingitu_4":
			dialog.text = "Un hombre con vacío interior se llena fácilmente de pensamientos ajenos. Alguien encontró su debilidad y la aprovechó. Tichingitu casi siente lástima por ese hombre.";
			link.l1 = "¿Casi?";
			link.l1.go = "LadyBeth_Tichingitu_5";
		break;
		
		case "LadyBeth_Tichingitu_5":
			dialog.text = "Sí, casi. Cada guerrero es responsable de sus decisiones. Incluso si los demonios le susurran al oído.";
			link.l1 = "...";
			link.l1.go = "LadyBeth_Tichingitu_6";
		break;
		
		case "LadyBeth_Tichingitu_6":
			DialogExit();
			Return_TichingituOfficer();
		break;
		
		case "LadyBeth_Irons_1": // Томми
			dialog.text = "¡Maldita sea, capitán! ¡Mira eso! ¡Como en los viejos tiempos!";
			link.l1 = "Tú sí que sabes lo que es una guerra en tierra firme.";
			link.l1.go = "LadyBeth_Irons_2";
			DelLandQuestMark(npchar);
		break;
		
		case "LadyBeth_Irons_2":
			dialog.text = "Me recordó a la batalla de Naseby. Nuestro ala de caballería se topó con los jinetes de Rupert. Luchaban con la misma furia por su rey.";
			link.l1 = "¿Qué opinas de Blackwood?";
			link.l1.go = "LadyBeth_Irons_3";
		break;
		
		case "LadyBeth_Irons_3":
			dialog.text = "Ese Blackwood era o un genio o un loco de remate. Creo que ambas cosas. ¿Sabes qué me sorprende? Su gente. Muchos eran exmilitares. No escoria, sino profesionales de verdad. Y todos lo siguieron en esta locura\nIncluso la infantería de marina de Fox. ¡Ja! ¡Ese sí que estará feliz con la matanza de hoy! Nunca les perdonó la deserción.";
			link.l1 = "¿Quizá era por el dinero?";
			link.l1.go = "LadyBeth_Irons_4";
		break;
		
		case "LadyBeth_Irons_4":
			dialog.text = "No, había algo más. Ese tipo tenía poder sobre ellos. Poder real. Y escuché que estaba prometido con una rica joven de Barbados. Raro que no se casara con ella tras encontrar todos esos tesoros\nTípico soldado: no sabía cuándo terminar la guerra.";
			link.l1 = "Gracias, Tommy. Eres todo un pensador.";
			link.l1.go = "LadyBeth_Irons_5";
		break;
		
		case "LadyBeth_Irons_5":
			dialog.text = "¿Eh?";
			link.l1 = "Nada.";
			link.l1.go = "LadyBeth_Irons_6";
		break;
		
		case "LadyBeth_Irons_6":
			DialogExit();
			Return_IronsOfficer();
		break;
		
		case "LadyBeth_Knippel_1": // Книппель
			dialog.text = "Qué amargo es ver esto, capitán. ¡A lo que hemos llegado!";
			link.l1 = "¿Nosotros?";
			link.l1.go = "LadyBeth_Knippel_2";
			DelLandQuestMark(npchar);
		break;
		
		case "LadyBeth_Knippel_2":
			dialog.text = "¡La flota inglesa! Mire eso: pequeños puntos de chaquetas rojas tendidos entre esa chusma muerta.";
			link.l1 = "Algunos de esos ‘despojos’ son nuestros hombres, Charlie. Entiendo lo que sientes, pero...";
			link.l1.go = "LadyBeth_Knippel_3";
		break;
		
		case "LadyBeth_Knippel_3":
			dialog.text = "Al diablo con todo esto, sir.";
			link.l1 = "Entiendo lo que sientes, pero sería mejor que dirigieras tu ira y decepción hacia Blackwood. Fue él quien desertó de tu querida flota inglesa y los trajo aquí.";
			link.l1.go = "LadyBeth_Knippel_4";
			link.l2 = "Es verdad. Vamos, el día aún no ha terminado.";
			link.l2.go = "LadyBeth_Knippel_6";
		break;
		
		case "LadyBeth_Knippel_4":
			dialog.text = "¡Sólo seguían a su comandante!";
			link.l1 = "¿Como seguiste a Fleetwood?";
			link.l1.go = "LadyBeth_Knippel_5";
			link.l2 = "Es verdad. Vamos, el día aún no ha terminado.";
			link.l2.go = "LadyBeth_Knippel_6";
		break;
		
		case "LadyBeth_Knippel_5":
			dialog.text = "¡Como lo sigo a usted!";
			link.l1 = "Espero ser un mejor capitán que Blackwood y Fleetwood. Vamos, el día aún no ha terminado.";
			link.l1.go = "LadyBeth_Knippel_6";
		break;
		
		case "LadyBeth_Knippel_6":
			dialog.text = "Sí, capitán. Y cuando termine - beberé hasta que termine el siguiente.";
			link.l1 = "...";
			link.l1.go = "LadyBeth_Knippel_7";
		break;
		
		case "LadyBeth_Knippel_7":
			DialogExit();
			Return_KnippelOfficer();
		break;
		
		case "LadyBeth_Alonso_1": // Алонсо
			dialog.text = "¡Madre de Dios, capitán! ¿Está usted bien?";
			link.l1 = "Eso está por verse. ¿Cuántos hombres hemos perdido?";
			link.l1.go = "LadyBeth_Alonso_2";
			DelLandQuestMark(npchar);
		break;
		
		case "LadyBeth_Alonso_2":
			dialog.text = "¿Muertos? En esta aventura hemos perdido "+sti(pchar.SailorDiedInBattleInfo)+" hombres. No quiero ser insistente, capitán, pero... ¡le advertí!";
			link.l1 = "Ignoraré ese comentario porque hoy te has lucido, Alonso. ¿De dónde vienen tantos talentos?";
			link.l1.go = "LadyBeth_Alonso_3";
		break;
		
		case "LadyBeth_Alonso_3":
			dialog.text = "Algún día le contaré esa historia, capitán - si sobrevivimos, claro.";
			link.l1 = "¿Tienes más consejos para mí?";
			link.l1.go = "LadyBeth_Alonso_4";
		break;
		
		case "LadyBeth_Alonso_4":
			dialog.text = "Si hubiera un tesoro aquí, ya lo habrían encontrado. Pero aún así deberíamos registrar la isla y buscar supervivientes, y luego decidir qué hacer con ellos. Y no hay que olvidar el barco de Blackwood: he oído hablar muy bien de esa hermosa Galeota\nSería una pena dejar pasar ese botín, capitán. Por supuesto, solo transmito la opinión de la tripulación al respecto.";
			link.l1 = "Por supuesto. Vamos. ¡El botín nos espera!";
			link.l1.go = "LadyBeth_Alonso_5";
		break;
		
		case "LadyBeth_Alonso_5":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorFollow(npchar, pchar, "", -1);
			LAi_group_MoveCharacter(npchar, LAI_GROUP_PLAYER);
		break;
		
		// Диалог с матросом в гроте Каймана
		case "LadyBeth_MatrosyInGrot":
			dialog.text = "¡No disparen! ¡Nos rendimos!";
			link.l1 = "¿Quiénes son ustedes?";
			link.l1.go = "LadyBeth_MatrosyInGrot_2";
		break;
		
		case "LadyBeth_MatrosyInGrot_2":
			dialog.text = "Nosotros... somos de la 'Lady Beth'. La tripulación del capitán Blackwood. ¿Él... está vivo?No. Su capitán está muerto.";
			link.l1 = "No. Su capitán está muerto.";
			link.l1.go = "LadyBeth_MatrosyInGrot_3";
		break;
		
		case "LadyBeth_MatrosyInGrot_3":
			dialog.text = "Entonces se acabó... Gracias a Dios.";
			link.l1 = "No parecen lamentar la muerte de su capitán.";
			link.l1.go = "LadyBeth_MatrosyInGrot_4";
		break;
		
		case "LadyBeth_MatrosyInGrot_4":
			dialog.text = "No lo entiende. Blackwood era un gran hombre. El mejor capitán que he conocido. Pero en los últimos meses... cambió. Se volvió obsesivo, cruel. Nos obligaba a trabajar día y noche, buscando algo que quizás ni siquiera exista.";
			link.l1 = "Los acepto en mi tripulación. Necesitamos marineros con experiencia.";
			link.l1.go = "LadyBeth_MatrosyInGrot_PlusKomanda";
			link.l2 = "Ay de los vencidos, muchachos. Ahora están bajo mi poder. Tienen suerte. Si aguantan, acabarán en alguna plantación en Barbados.";
			link.l2.go = "LadyBeth_MatrosyInGrot_PlusRaby";
		break;
		
		case "LadyBeth_MatrosyInGrot_PlusKomanda":
			dialog.text = "¿De verdad? ¿No teme que... que algo esté mal con nosotros después de todo esto?";
			link.l1 = "Todos merecen una segunda oportunidad.";
			link.l1.go = "LadyBeth_MatrosyInGrot_PlusKomanda_1";
		break;
		
		case "LadyBeth_MatrosyInGrot_PlusKomanda_1":
			dialog.text = "Gracias, capitán. Le juro que no se arrepentirá. Somos buenos marineros. Y... tal vez ahora las pesadillas se detengan.";
			link.l1 = "...";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("LadyBeth_Grot_MatrosySdautsya_2");
			ChangeCharacterComplexReputation(pchar, "nobility", 2);
			pchar.Ship.Crew.Quantity = sti(pchar.ship.Crew.Quantity) + 30;
		break;
		
		case "LadyBeth_MatrosyInGrot_PlusRaby":
			dialog.text = "¡Gracias, gracias! Al menos estaremos vivos. Por favor, sáquenos de aquí. Esta isla... parece maldita.";
			link.l1 = "...";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("LadyBeth_Grot_MatrosySdautsya_2");
			ChangeCharacterComplexReputation(pchar, "nobility", -2);
			SetCharacterGoods(pchar, GOOD_SLAVES, GetCargoGoods(pchar, GOOD_SLAVES)+30);
		break;
		
		case "LadyBeth_MatrosyInGrot_exit":
			DialogExit();
			for (i=1; i<=8; i++)
			{
				sld = CharacterFromID("LadyBeth_MatrosyPryachutsya_"+i);
				LAi_SetActorType(sld);
				LAi_ActorRunToLocation(sld, "reload", "reload1", "none", "", "", "OpenTheDoors", 5);
				LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
			}
		break;
		
		// Диалог с матросом на Леди Бет
		case "LadyBeth_EnemyMatros_1":
			dialog.text = "¡¿Qué demonios?! ¿Cómo se atrevieron a atacar a la 'Lady' y matar a Jeremy? No saldrán vivos de aquí, malditos, el capitán volverá y...";
			link.l1 = "Su capitán está muerto. Jeremy disparó primero, y me llevo su 'Lady' como un premio legítimo pagado con sangre.";
			link.l1.go = "LadyBeth_EnemyMatros_2";
		break;
		
		case "LadyBeth_EnemyMatros_2":
			dialog.text = "¿El capitán... muerto? ¡Mientes, perro! ¡No vales ni un botón de su uniforme!";
			link.l1 = "Si ese uniforme significaba algo, era para el Blackwood que ya no existe. Ustedes deciden: luchar por un muerto o salvar sus vidas.";
			link.l1.go = "LadyBeth_EnemyMatros_3";
		break;
		
		case "LadyBeth_EnemyMatros_3":
			if (CharacterIsHere("Helena"))
			{
				StartInstantDialog("Helena", "LadyBeth_EnemyMatros_Helena_1", "Quest\LadyBeth_dialog.c");
				break;
			}
			if (CharacterIsHere("Knippel"))
			{
				StartInstantDialog("Knippel", "LadyBeth_EnemyMatros_Knippel_1", "Quest\LadyBeth_dialog.c");
				break;
			}
			if (CharacterIsHere("Irons"))
			{
				StartInstantDialog("Irons", "LadyBeth_EnemyMatros_Irons_1", "Quest\LadyBeth_dialog.c");
				break;
			}
			dialog.text = "¡No les entregaremos el barco sin luchar!";
			link.l1 = "...";
			link.l1.go = "LadyBeth_EnemyMatros_4";
		break;
		
		case "LadyBeth_EnemyMatros_Helena_1":
			dialog.text = "Escuchen, muchachos. Sé que son leales a su capitán. Eso es digno de respeto. Pero él está muerto, y ustedes están vivos. Y deben decidir cómo seguir viviendo. Les ofrecemos la oportunidad de empezar de nuevo.";
			link.l1 = "...";
			link.l1.go = "LadyBeth_EnemyMatros_5";
			CharacterTurnByChr(npchar, CharacterFromID("LadyBeth_CrewOfShip_7"));
		break;
		
		case "LadyBeth_EnemyMatros_Knippel_1":
			dialog.text = "Capitán, estos hombres no son enemigos. Sólo seguían órdenes. Muchos de ellos son antiguos marinos de la armada real, bien entrenados y disciplinados. Sería un desperdicio no aprovechar sus habilidades\nMuchachos, he estado en su lugar más de una vez durante mi largo servicio en la flota. Y tomé la decisión correcta. Háganlo ustedes también.";
			link.l1 = "...";
			link.l1.go = "LadyBeth_EnemyMatros_5";
		break;
		
		case "LadyBeth_EnemyMatros_Irons_1":
			dialog.text = "Bueno, marineros. La elección es sencilla: o viven, aunque sea como prisioneros en la bodega o con nosotros con buena ración y paga regular, o... (se pasa el dedo por el cuello) ¡Yo, en su lugar, elegiría lo primero!";
			link.l1 = "...";
			link.l1.go = "LadyBeth_EnemyMatros_10";
			CharacterTurnByChr(npchar, CharacterFromID("LadyBeth_CrewOfShip_7"));
		break;
		
		case "LadyBeth_EnemyMatros_5":
			StartInstantDialog("LadyBeth_CrewOfShip_7", "LadyBeth_EnemyMatros_6", "Quest\LadyBeth_dialog.c");
		break;
		
		case "LadyBeth_EnemyMatros_6":
			dialog.text = "...";
			link.l1 = "Serán parte de mi tripulación.";
			link.l1.go = "LadyBeth_EnemyMatros_7";
			link.l2 = "Ay de los vencidos, muchachos. Ahora están bajo mi poder. Tienen suerte. Si aguantan - acabarán en alguna plantación en Barbados.";
			link.l2.go = "LadyBeth_EnemyMatros_9";
		break;
		
		case "LadyBeth_EnemyMatros_7":
			dialog.text = "¿Nos acepta en su tripulación? ¿Después de todo?";
			link.l1 = "Los buenos marineros siempre son valiosos. Y el capitán Blackwood sabía elegir a su gente.";
			link.l1.go = "LadyBeth_EnemyMatros_8";
		break;
		
		case "LadyBeth_EnemyMatros_8":
			dialog.text = "Gracias, capitán. No lo decepcionaremos.";
			link.l1 = "...";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("LadyBeth_ShipInShore_Vnutri_1");
			ChangeCharacterComplexReputation(pchar, "nobility", 1);
			pchar.Ship.Crew.Quantity = sti(pchar.ship.Crew.Quantity) + 12;
		break;
		
		case "LadyBeth_EnemyMatros_9":
			dialog.text = "Bueno... al menos esta aventura sólo podía terminar así. Perdónanos, capitán Blackwood. No supimos protegerte.";
			link.l1 = "...";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("LadyBeth_ShipInShore_Vnutri_1");
			ChangeCharacterComplexReputation(pchar, "nobility", -1);
			SetCharacterGoods(pchar, GOOD_SLAVES, GetCargoGoods(pchar, GOOD_SLAVES)+12);
		break;
		
		case "LadyBeth_EnemyMatros_10":
			StartInstantDialog("LadyBeth_CrewOfShip_7", "LadyBeth_EnemyMatros_11", "Quest\LadyBeth_dialog.c");
		break;
		
		case "LadyBeth_EnemyMatros_11":
			dialog.text = "¡No les entregaremos el barco sin luchar!";
			link.l1 = "...";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("LadyBeth_ShipInShore_Bitva");
		break;
		
		// Диалог с Элизабет Бишоп
		case "LadyBeth_Elizabeth_1":
			dialog.text = "...";
			link.l1 = "Disculpe. ¿Es usted Elizabeth?";
			if (pchar.sex == "man") link.l1.go = "LadyBeth_Elizabeth_2";
			if (pchar.sex == "woman") link.l1.go = "LadyBeth_Elizabeth_Woman_2";
			DelLandQuestMark(npchar);
		break;
		
		case "LadyBeth_Elizabeth_2":
			dialog.text = "Sí, soy yo. ¿Y usted quién es?";
			link.l1 = "Capitán "+GetFullName(pchar)+". Yo... conocía a Albert Blackwood.";
			link.l1.go = "LadyBeth_Elizabeth_3";
		break;
		
		case "LadyBeth_Elizabeth_3":
			dialog.text = "¿Mi Albert? Dios mío... ¿Él... está bien?";
			link.l1 = "Por desgracia, no. Murió en combate. Luchó hasta el final.";
			link.l1.go = "LadyBeth_Elizabeth_4";
		break;
		
		case "LadyBeth_Elizabeth_4":
			dialog.text = "Yo... lo presentía. Tantos años sin noticias... ¿Sabe? Lo esperé. Lo esperé mucho tiempo. Mi padre decía que Albert sólo tenía que esperar su ascenso. El gobernador ya lo había decidido, era cuestión de unos meses\nPero Albert... él lo entendió de otra forma. Dijo que volvería rico, digno de mi mano. Y se fue. Simplemente... se fue.";
			link.l1 = "Pensó en usted hasta su último día.";
			link.l1.go = "LadyBeth_Elizabeth_5";
		break;
		
		case "LadyBeth_Elizabeth_5":
			dialog.text = "Qué tonto fue todo. No necesitaba sus tesoros. Lo amaba a él, no a su dinero. Estaba dispuesta a huir con él... pero era tan orgulloso. Esperé una carta, una señal... Y luego solo llegó ese extraño estatuto\nUn documento frío, calculado... nada parecido al Albert que conocía. Entonces supe que lo había perdido.";
			link.l1 = "Encontré esto entre sus pertenencias.";
			link.l1.go = "LadyBeth_Elizabeth_6";
		break;
		
		case "LadyBeth_Elizabeth_6":
			dialog.text = "¿Un mapa de mi casa? ¿Yo era su mayor tesoro? Qué ironía. Buscó riquezas por todo el Caribe, y lo único que realmente le importaba siempre estuvo aquí... Espere. Tengo algo para usted. Es el estatuto de Albert\nMe lo envió hace un año. Decía que le ayudaría a encontrar un tesoro y regresar conmigo. Ahora le será más útil a usted.";
			link.l1 = "Gracias, Elizabeth. Lamento que todo haya terminado así.";
			link.l1.go = "LadyBeth_Elizabeth_7";
			GiveItem2Character(PChar, "talisman18");
		break;
		
		case "LadyBeth_Elizabeth_7":
			dialog.text = "Y yo me casé, capitán. Con el señor Bishop. Mi padre insistió. No conoce a ese hombre... y mejor que no lo conozca. Todos los días pienso en cómo habría sido mi vida si Albert simplemente... hubiera regresado.";
			link.l1 = "Ahora yo también lo pensaré.";
			link.l1.go = "LadyBeth_Elizabeth_8";
		break;
		
		case "LadyBeth_Elizabeth_8":
			dialog.text = "Adiós, capitán. Y... cuídese. No persiga fantasmas.";
			link.l1 = ""+Goodbye()+".";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("LadyBeth_Barbados_Elizabeth_2");
		break;
		
		case "LadyBeth_Elizabeth_Woman_2":
			dialog.text = "Sí, soy yo.";
			link.l1 = "Capitán Helen MacArthur. Yo... conocí a Albert Blackwood.";
			link.l1.go = "LadyBeth_Elizabeth_Woman_3";
		break;
		
		case "LadyBeth_Elizabeth_Woman_3":
			dialog.text = "¿Mi Albert? Dios mío... ¿Él... Y usted quién es?";
			link.l1 = "Capitán Helen MacArthur, como ya le dije. Comando mi propio barco.";
			link.l1.go = "LadyBeth_Elizabeth_Woman_4";
		break;
		
		case "LadyBeth_Elizabeth_Woman_4":
			dialog.text = "¿Capitán? ¿Una mujer capitán? ¿Usted... estaba con Albert? ¿En qué sentido... lo conocía?";
			link.l1 = "Solo como capitán. Lo siento, pero Albert murió. Fui testigo de su última batalla.";
			link.l1.go = "LadyBeth_Elizabeth_Woman_5";
		break;
		
		case "LadyBeth_Elizabeth_Woman_5":
			dialog.text = "Entiendo. Perdone mis sospechas. Es que... el capitán Blackwood siempre atrajo la atención de las mujeres. Incluso aquí en Barbados. Especialmente aquí.";
			link.l1 = "Lo amaba usted.";
			link.l1.go = "LadyBeth_Elizabeth_Woman_6";
		break;
		
		case "LadyBeth_Elizabeth_Woman_6":
			dialog.text = "Con todo mi corazón. Mi padre decía que Albert solo debía esperar su ascenso. Era cuestión de unos meses. Pero Albert entendió esas palabras como un rechazo por su pobreza. Dijo que volvería con un tesoro. Y se fue.";
			link.l1 = "¡Los hombres y su orgullo!";
			link.l1.go = "LadyBeth_Elizabeth_Woman_7";
		break;
		
		case "LadyBeth_Elizabeth_Woman_7":
			dialog.text = "Tiene suerte, capitán MacArthur. Es libre. Navega adonde quiera. Sin plantadores, sin padres decidiendo su destino. Sin maridos que la consideren su propiedad.";
			link.l1 = "La libertad cuesta caro. Y hay que defenderla cada día.";
			link.l1.go = "LadyBeth_Elizabeth_Woman_8";
		break;
		
		case "LadyBeth_Elizabeth_Woman_8":
			dialog.text = "Tal vez tenga algo que pueda ayudarla. Tome. Es su estatuto de búsqueda de tesoros. Albert me lo envió hace un año. Dijo que era lo mejor que había hecho\nQue eso le ayudaría a hacerse rico y volver conmigo. Pero con cada página, se parecía menos al Albert que yo conocí.";
			link.l1 = "Gracias. Lo guardaré.";
			link.l1.go = "LadyBeth_Elizabeth_Woman_9";
			GiveItem2Character(PChar, "talisman18");
		break;
		
		case "LadyBeth_Elizabeth_Woman_9":
			dialog.text = "Por favor, capitán... valore su libertad. Me casé con el coronel Bishop. Un hombre al que incluso mi padre teme. Si yo hubiera sido tan libre como usted... Todo habría sido diferente.";
			link.l1 = "Lo sé.";
			link.l1.go = "LadyBeth_Elizabeth_Woman_10";
		break;
		
		case "LadyBeth_Elizabeth_Woman_10":
			dialog.text = "Adiós, capitán. Y que el viento le sea favorable.";
			link.l1 = ""+Goodbye()+".";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("LadyBeth_Barbados_Elizabeth_2");
		break;
		
		// диалог с Диего де Ланда
		case "LadyBeth_DiegoDeLanda_1":
			if (sti(pchar.questTemp.ISawDiegoDeLanda) == 1)
			{
				dialog.text = "¿Ha visto a la señora Bishop? Una historia triste, ¿verdad?";
				link.l1 = "¿Quién es usted?";
				link.l1.go = "LadyBeth_DiegoDeLanda_First_1";
			}
			else
			{
				dialog.text = "Buenos días, capitán.";
				link.l1 = "¡Un momento! ¡Ya nos hemos visto antes! ¿Qué hace usted en Barbados?";
				link.l1.go = "LadyBeth_DiegoDeLanda_Second_1";
			}
		break;
		
		case "LadyBeth_DiegoDeLanda_First_1":
			dialog.text = "\nSirvo en la parroquia de Santa María. Pocos católicos en Barbados encuentran consuelo en nuestra iglesia.";
			link.l1 = "¿Conoce a Elizabeth?";
			link.l1.go = "LadyBeth_DiegoDeLanda_First_2";
		break;
		
		case "LadyBeth_DiegoDeLanda_First_2":
			dialog.text = "Oh, sí. Pobre mujer. Su esposo... no es precisamente un buen hombre. Dicen que sus plantaciones son las más productivas de Barbados. Y también las más crueles. ¿Sabe cuántos esclavos mueren allí cada mes\nRecientemente mató a golpes a un verdadero médico inglés - un hombre de gran inteligencia y talento. Y el destino de ella no es mucho mejor, créame.";
			link.l1 = "Parece estar bien informado.";
			link.l1.go = "LadyBeth_DiegoDeLanda_First_3";
		break;
		
		case "LadyBeth_DiegoDeLanda_First_3":
			dialog.text = "La gente viene a mí para confesarse, capitán. Escucho lo que temen decir incluso a sus seres queridos. Sus miedos, sus pecados... su dolor.";
			link.l1 = "¿Y no teme ser perseguido? No es fácil ser sacerdote católico en tierras inglesas.";
			link.l1.go = "LadyBeth_DiegoDeLanda_First_4";
		break;
		
		case "LadyBeth_DiegoDeLanda_First_4":
			dialog.text = "Dígame... ¿usted buscaba a Blackwood a propósito? Curioso. Pero ¿por qué? Fue peligroso y necio. ¿Cuál es su fuego, capitán? ¿Qué lo impulsa?";
			link.l1 = "Eso no es asunto suyo.";
			link.l1.go = "LadyBeth_DiegoDeLanda_First_5";
		break;
		
		case "LadyBeth_DiegoDeLanda_First_5":
			dialog.text = "No puedo entenderlo. A los demás, sí. Pero a usted... aún no.";
			link.l1 = "¿A los demás?";
			link.l1.go = "LadyBeth_DiegoDeLanda_First_6";
		break;
		
		case "LadyBeth_DiegoDeLanda_First_6":
			dialog.text = "Uno, por ejemplo, busca justicia. Y otro... estaba obsesionado con las aguas oscuras de la muerte. Las personas se pierden fácilmente en sus deseos. ¿No es cierto?";
			link.l1 = "Es usted un sacerdote extraño, padre.";
			link.l1.go = "LadyBeth_DiegoDeLanda_First_7";
		break;
		
		case "LadyBeth_DiegoDeLanda_First_7":
			dialog.text = "...";
			link.l1 = "Me voy, creo.";
			link.l1.go = "LadyBeth_DiegoDeLanda_First_8";
		break;
		
		case "LadyBeth_DiegoDeLanda_First_8":
			dialog.text = "Por supuesto. Su trabajo apenas comienza, capitán.";
			link.l1 = "...";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("LadyBeth_Barbados_Diego_2");
		break;
		
		case "LadyBeth_DiegoDeLanda_Second_1":
			dialog.text = "Sirvo en la parroquia de Santa María. ¿Ha visto a la señora Bishop? Un destino triste. Pero me temo que merecido.";
			link.l1 = "La vez pasada hablaba en acertijos. ¿También lo hará ahora?";
			link.l1.go = "LadyBeth_DiegoDeLanda_Second_2";
		break;
		
		case "LadyBeth_DiegoDeLanda_Second_2":
			dialog.text = "\nEl verdadero enigma está frente a mí. Ha reunido muchas... reliquias interesantes. Una Biblia. Un estatuto. ¿Le gusta coleccionar cosas así? ¿Es usted coleccionista?";
			link.l1 = "¿Cómo sabe sobre el estatuto?";
			link.l1.go = "LadyBeth_DiegoDeLanda_Second_3";
		break;
		
		case "LadyBeth_DiegoDeLanda_Second_3":
			dialog.text = "¿Cazador de trofeos?";
			link.l1 = "Repito mi pregunta: ¿cómo sabe sobre el estatuto?";
			link.l1.go = "LadyBeth_DiegoDeLanda_Second_4";
		break;
		
		case "LadyBeth_DiegoDeLanda_Second_4":
			dialog.text = "¿Amante de las emociones fuertes?";
			link.l1 = "...";
			link.l1.go = "LadyBeth_DiegoDeLanda_Second_5";
		break;
		
		case "LadyBeth_DiegoDeLanda_Second_5":
			dialog.text = "\nAh. Por supuesto. Naturalmente. Bueno, capitán, no lo detendré más.";
			link.l1 = "Espere un momento, padre. Aún no ha respondido a mi pregunta.";
			link.l1.go = "LadyBeth_DiegoDeLanda_Second_6";
		break;
		
		case "LadyBeth_DiegoDeLanda_Second_6":
			dialog.text = "Oh, capitán. No puedo. A veces las respuestas duelen más que la ignorancia. Vaya en paz. Y cuide su colección... de trofeos. Podrían serle útiles en el viaje que le espera.";
			link.l1 = "...";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("LadyBeth_Barbados_Diego_2");
		break;
	}
} 