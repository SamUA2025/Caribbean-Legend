// гид
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
	int i;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			dialog.text = "¿Quieres algo?";
			link.l1 = "No, nada.";
			link.l1.go = "exit";			
			NextDiag.TempNode = "First time";
		break;
		
		case "guide_0":
			SetAchievement("Test_Ach");
			PlaySound("Voice\English\LE\Greguar\Greguar_01.wav");
			dialog.text = "¡Bienvenido al Caribe, Monsieur! Permítame presentarme, soy "+GetFullName(npchar)+"¿Eres nuevo en nuestra colonia, correcto?";
			link.l1 = "Saludos, Monsieur. Mi nombre es "+GetFullName(pchar)+"Sí, acabo de desembarcar. No creo haberte visto antes... ¿Te conozco?";
			link.l1.go = "guide_1";
		break;
		
		case "guide_1":
			DelLandQuestMark(npchar);
			dialog.text = "No, Monsieur, no lo hace, pero no podía perder la oportunidad de presentarme a un noble caballero como usted.\nOh, recuerdo mi primer día aquí, el día de mi llegada al Nuevo Mundo. Las cosas son muy diferentes aquí. El estilo de vida local puede arruinar su salud y su billetera.\nPor eso le ofrezco mi modesta ayuda. Gratis, lo cual es bastante raro aquí, se lo aseguro, ¡jaja! Puedo familiarizarlo con nuestra colonia y el archipiélago. Considérelo un pequeño tour.";
			link.l1 = "¡Eso es muy amable de su parte, merci Monsieur! Me alegraría aceptar su oferta. El conocimiento es poder, después de todo.";
			link.l1.go = "guide_2";
			link.l2 = "Aprecio su oferta, Monsieur, de verdad, pero la rechazaré.";
			link.l2.go = "guide_exit";
		break;
		
		case "guide_exit":
			dialog.text = "Como desees, Monsieur. De todos modos, fue un placer conocerte. Los caballeros honorables son raros invitados aquí. ¡Te deseo la mejor de las suertes!";
			link.l1 = "Tú también, "+GetFullName(npchar)+"¡";
			link.l1.go = "guide_exit_1";			
		break;
		
		case "guide_exit_1":
			DialogExit();
			LAi_SetCitizenType(npchar);
			LAi_CharacterDisableDialog(npchar);
			npchar.lifeday = 0;
			DoQuestCheckDelay("NgtF3", 1.0);
			QuestPointerToLoc("FortFrance_town", "reload", "reload3_back");
		break;
		
		case "guide_2":
			dialog.text = "Me alegra oír eso. Es un placer. Bueno, permíteme presentarte algunos conceptos básicos. La mayoría de las colonias están construidas con un diseño similar: un asentamiento en la costa, protegido por un fuerte y murallas de la ciudad con puertas. Nobles, ricos, soldados, marineros, mercaderes, mercenarios y criminales - todos viven juntos dentro de estas murallas.\nA veces te encontrarás con capitanes, monjes, gitanos y mendigos también. Sin embargo, no encontrarás indios en las calles, esos salvajes ponen nerviosa a la gente. Si quieres ver indios tendrás que adentrarte en la jungla. Sígueme, te mostraré algunos de nuestros establecimientos locales.";
			link.l1 = "";
			link.l1.go = "guide_3";			
		break;
		
		case "guide_3": // идем в таверну
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(npchar, "officers", "reload4_3", "Guide_tavern", -1);
			LAi_ActorFollow(pchar, npchar, "", -1);
			chrDisableReloadToLocation = true;//закрыть локацию
		break;
		
		case "guide_4":
			dialog.text = "Este es el lugar más importante en cualquier colonia: la taberna. Sí, en Europa, estos lugares pueden considerarse un antro de escoria y villanía, pero aquí en el Nuevo Mundo es diferente. Un tabernero puede ofrecerte una habitación para dormir, algo de ron, jugosos chismes y un trabajo.\nSi necesitas información, intenta hablar con los parroquianos aquí. Compra otra bebida a un borracho y podrías obtener algo interesante a cambio... ¡o no! El juego es popular aquí, pero cuidado con los tramposos. Si atrapas a alguien haciendo trampa, no dudes en matarlo en el acto. Nadie te juzgará por eso.\nUna taberna es también un lugar donde puedes contratar tripulación y oficiales para tu barco, es decir, si tienes uno. Recuerda: la taberna tiene información, trabajo, tripulación y entretenimiento.";
			link.l1 = "";
			link.l1.go = "guide_9";
			locCameraFromToPos(-2.08, 5.32, 68.88, false, -15.00, -0.60, 55.00);
		break;
		
		case "guide_5": // к магазину
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(npchar, "officers", "reload6_3", "Guide_store", -1);
			LAi_ActorFollow(pchar, npchar, "", -1);
		break;
		
		case "guide_6":
			dialog.text = " La tienda es el centro de comercio de cualquier colonia. Los capitanes visitan este lugar tan a menudo como el astillero. Aquí, puedes comprar municiones, suministros o mercancías para comerciar. El comercio es bastante complicado.\nPrimero, se necesita tiempo para encontrar los mejores lugares para comprar o vender. Segundo, necesitas algunas habilidades comerciales decentes para negociar con los mercaderes locales.\nEs por eso que la mayoría de los capitanes contratan intendentes para llevar a cabo los negocios en su lugar. Así que no olvides contratar a un profesional cuando... o si consigues un barco propio. Esto es crucial, no querrás desperdiciar dinero aquí. Un error y estarás arruinado. Una última cosa. Los mercaderes en las tiendas a menudo pueden ofrecerte contratos de entrega, esto podría serte útil en el futuro.";
			link.l1 = "";
			link.l1.go = "guide_26";
			locCameraFromToPos(-21.10, 6.60, 45.21, false, -30.00, 3.70, 45.00);
		break;
		
		case "guide_7": // к тюрьме
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(npchar, "reload", "reload_jail", "Guide_prison", -1);
			LAi_ActorFollow(pchar, npchar, "", -1);
		break;
		
		case "guide_8":
			dialog.text = "Y esta es la prisión. Lugar asqueroso. Los peores criminales terminan con una soga alrededor del cuello bastante rápido, así que aquí se mantienen principalmente los peces pequeños.\nSi quieres charlar con ellos, habla con el guardia de la prisión. Te permitirá entrar por una pequeña tarifa, ¡o incluso gratis si eres lo suficientemente persuasivo! Puede resultar útil, pero recuerda que no se puede confiar en los malvivientes, aunque siempre hablen dulcemente y protesten su inocencia tras las rejas.";
			link.l1 = "";
			link.l1.go = "guide_9";
			locCameraFromToPos(-52.40, 7.63, 42.60, true, 15.00, -4.00, -30.00);
		break;
		
		case "guide_9": // на рынок
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(npchar, "merchant", "mrcActive4", "Guide_market", -1);
			LAi_ActorFollow(pchar, npchar, "", -1);
		break;
		
		case "guide_10":
			dialog.text = "Este es el mercado. Los mercaderes venden y compran todo lo que necesitas. Un armero puede proporcionarte espadas, armas de fuego, armaduras, municiones y demás. Aunque el buen equipo es raro, así que no esperes encontrar obras maestras simplemente tiradas aquí. Tales cosas vienen a un gran precio y riesgo, pero puedes encontrar buenas espadas y pistolas aquí, a menos que alguien las compre antes que tú. Un herborista puede ofrecer pociones de salud, antídotos, plantas, ingredientes, frascos, y si tienes suerte, recetas. Pero por qué siquiera te digo eso, ¿no eres alquimista, verdad? Los gitanos ofrecen amuletos paganos y porquerías inútiles como cadáveres de murciélagos. Algunos dicen conocer un uso para tales cosas, pero son tonterías. Los monjes venden velas, talismanes sagrados y otros objetos benditos: cruces, anillos, herramientas de escritura. Y los traperos venden basura así como artículos diversos, pero si tienes las habilidades de artesanía necesarias, puedes hacer algo útil con peines de tortuga, clavos y cuerdas.";
			link.l1 = "";
			link.l1.go = "guide_19";
			locCameraFromToPos(-13.58, 4.11, 69.06, false, -45.00, -6.00, 52.00);
		break;
		
		case "guide_11": // к резиденции
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(npchar, "officers", "reload3_1", "Guide_townhall", -1);
			LAi_ActorFollow(pchar, npchar, "", -1);
		break;
		
		case "guide_12":
			dialog.text = "¡Ah, contempla el palacio del gobernador! Esta es la residencia y la oficina del hombre más importante de la colonia. Los nobles visitan el palacio para bailes y fiestas, los hombres de negocios y capitanes vienen aquí para resolver asuntos tanto oficiales como personales. Siempre es prudente estar en la lista de amigos del gobernador, pues tiene mucha influencia sobre los ciudadanos de la nación que representa.\nLos corsarios también pueden ganar buen dinero trabajando para los gobernadores, quienes son capaces de rescatar prisioneros de guerra. Si eres adinerado y deseas establecer una buena relación con Su Excelencia, incluso podría honrarte jugando contigo por apuestas altas.\nParece que estás impaciente, mi amigo. ¿Tienes prisa?";
			link.l1 = "Bueno... sí. Monsieur, para ser franco, vine aquí para encontrar a mi hermano, me dijeron que debe estar aquí, en Saint-Pierre. Es un hombre importante, el gobernador debe conocerlo.";
			link.l1.go = "guide_13";
			locCameraFromToPos(3.14, 7.39, 37.55, false, 1.06, 9.00, 14.14);
		break;
		
		case "guide_13":
			dialog.text = "¡Ah-ja, ya veo! ¿Entonces quieres visitar a Su Excelencia y preguntarle por tu hermano? Bueno, no te retrasaré más. Nuestro gobernador se llama Jacques Dille du Parquet, estoy seguro de que hará lo que pueda.";
			link.l1 = "  Dime, ¿quién más podría ayudarme? Tal vez sea imprudente molestar a Su Excelencia por un asunto tan trivial. ";
			link.l1.go = "guide_14";
		break;
		
		case "guide_14":
			dialog.text = "Dijiste que tu hermano es bien conocido aquí. Pregunta por las calles. Eventualmente encontrarás a alguien que pueda ayudar. ¿Cómo se llama tu hermano?";
			link.l1 = "Michel de Monper.";
			link.l1.go = "guide_15";
		break;
		
		case "guide_15":
			dialog.text = "Michel de Monper... Sí, he oído este nombre antes, pero nunca me han presentado al hombre, así que no puedo ayudarte. Buena suerte, Monsieur, estoy seguro de que nos volveremos a encontrar.";
			link.l1 = "Merci, "+GetFullName(npchar)+"¡";
			link.l1.go = "guide_16";
		break;
		
		case "guide_16":
			DialogExit();
			LAi_SetCitizenType(npchar);
			LAi_CharacterDisableDialog(npchar);//запрет диалога
			LAi_group_MoveCharacter(npchar, "FRANCE_CITIZENS"); // пока идем заниматься Мишелем
			chrDisableReloadToLocation = false;//открыть локацию
			DoQuestCheckDelay("NgtF3", 1.0);
			QuestPointerToLoc("FortFrance_town", "reload", "reload3_back");
		break;
		
		case "guide_17": // к ростовщику
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(npchar, "officers", "reload8_1", "Guide_bank", -1);
			LAi_ActorFollow(pchar, npchar, "", -1);
		break;
		
		case "guide_18":
			dialog.text = "Esta es la casa del prestamista, o usurero, banquero, su gremio es conocido por muchos nombres diferentes, a menudo muy despectivos. Puedes pensar lo que quieras de ellos, pero sus servicios pueden ayudarte mucho. Puedes depositar dinero, cambiar doblones y pesos, vender o comprar joyas. Si tienes un honor positivo, incluso puedes pedir prestadas algunas monedas, pero ten cuidado.\nLos usureros ofrecen los mejores precios por gemas, joyas y otros objetos de valor, siempre visítalos para vender tales cosas. Son personas poderosas, así que no te enfrentes a ellos.";
			link.l1 = "";
			link.l1.go = "guide_11";
			locCameraFromToPos(3.07, 7.64, 51.99, false, 45.00, -8.30, 4.50);
		break;
		
		case "guide_19": // к борделю
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(npchar, "officers", "reload9_1", "Guide_brothel", -1);
			LAi_ActorFollow(pchar, npchar, "", -1);
		break;
		
		case "guide_20":
			dialog.text = "Ah, un burdel. Todo hombre visita tales lugares, ¡de lo contrario estarían fuera del negocio! Incluso los nobles lo hacen, a costa de su honor. Tenlo en cuenta. Sé amable con las chicas y ellas pueden contarte cosas interesantes, a veces los hombres tienden a balbucear casi todo con ellas, y esto podría serte útil. Si no estás tras los secretos de otros, considera esto: no hay mejor cura para tu mente y tu cuerpo que el amor. Si tu vitalidad es pobre, visita a las chicas. También puedes beber una poción especial para arreglar tu vitalidad, aunque es rara y no tan divertida. Oh, cuando digo 'vitalidad', no me refiero a los rasguños en tu piel. Te golpearán, mucho. Pero si te golpean fuerte y a menudo o si bebes demasiadas pociones fuertes de salud, eventualmente arruinarás tu cuerpo. Vigila tu estado, descansa si es necesario, o sufre las consecuencias.";
			link.l1 = "";
			link.l1.go = "guide_17";
			locCameraFromToPos(-2.75, 7.07, 61.10, false, 60.00, -6.60, 42.65);
		break;
		
		case "guide_21":
			dialog.text = "¡Oh, tú de nuevo, mi amigo! Veo que te han dejado entrar en el lugar sagrado de Saint-Pierre, ¡la sede de los Caballeros de Malta! Debes ser importante. ¿Has encontrado a tu hermano?";
			link.l1 = "De hecho, lo hice...";
			link.l1.go = "guide_22";
		break;
		
		case "guide_22":
			dialog.text = "Perdóname, Monsieur, pero pareces bastante taciturno...";
			link.l1 = "¡Maldita sea! Esperaba salir de este maldito agujero y regresar a Francia, pero parece que Dios tiene otros planes. ¡Parece que tendré que quedarme aquí por un maldito largo tiempo! Y lo peor de todo es que debo convertirme en un simple marinero.";
			link.l1.go = "guide_23";
		break;
		
		case "guide_23":
			dialog.text = "Ese es un cambio bastante repentino en tu destino, Monsieur. Pero no te desanimes, no vas a ser cualquier otro marinero. Ser el capitán de tu propio barco es una posición muy respetada aquí. Tienes la intención de comprar un barco, ¿verdad?";
			link.l1 = "Oui, eso es exactamente lo que debo hacer... Todo lo que necesito es encontrar un astillero y algo de dinero lo antes posible. El problema es que no sé dónde diablos se encuentra un astillero, cómo navegar un barco, ¡o de dónde sacar el dinero! ¡Esto me saca de quicio...";
			link.l1.go = "guide_24";
		break;
		
		case "guide_24":
			dialog.text = "Desearía poder llenar tus bolsillos de oro, pero estoy tan arruinado como tú. Sin embargo, puedo llenar tu cabeza con el conocimiento que tanto necesitas. ¿Interesado?";
			link.l1 = "¡Aye, eso sería estupendo!";
			link.l1.go = "guide_25";
		break;
		
		case "guide_25":
			dialog.text = "Sígueme entonces. Empecemos con lo principal: los barcos.";
			link.l1 = "";
			link.l1.go = "guide_5";
		break;
		
		case "guide_26": // на верфь
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(npchar, "reload", "reload5", "Guide_shipyard", -1);
			LAi_ActorFollow(pchar, npchar, "", -1);
			chrDisableReloadToLocation = true;//закрыть локацию
		break;
		
		case "guide_27":
			dialog.text = "El astillero. Cada colonia tiene uno. Un lugar para vender o comprar un navío y también repararlo. Ten en cuenta que nuestros astilleros no tienen nada en común con los grandes astilleros de la vieja Europa. Estas son las colonias, aquí no construyen galeones ni navíos de línea. \nLos maestros locales pueden construir lanchas, goletas y balandras. Muy raramente verás bergantines y barquentinas. Pero a veces los corsarios traen barcos capturados como premio y los constructores los compran baratos, los reparan y los venden con ganancia. \n¡Una vez vi una fragata en la lista de precios! Los barcos hechos localmente también tienen malas características. No te preocupes, practicar con naves pequeñas y baratas te permitirá progresar y dominar eventualmente algo mejor. \nOh, y el astillero también es el lugar para comprar cañones. Hay varios tipos de cañones que puedes instalar en tu navío, siempre y cuando, por supuesto, pueda llevarlos. Cada navío tiene limitaciones, nunca podrás poner cañones de 24 libras en una lancha. Recuerda que los cañones de gran calibre son raros y caros. En el lado positivo, tales cañones pueden literalmente vaporizar la tripulación enemiga, las velas y el casco. \nUna última cosa. Los astilleros también ofrecen servicios para estetas: pueden pintar tus velas y el exterior de tus barcos, dibujar emblemas o escudos de armas. Pintarla de rojo tal vez no la haga ir más rápido, pero la hará lucir mucho más elegante.";
			link.l1 = "Interesante...";
			link.l1.go = "guide_28";
			locCameraFromToPos(-26.74, 5.77, 49.03, false, -70.00, -25.00, 150.00);
		break;
		
		case "guide_28": // в порт
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(npchar, "quest", "quest1", "Guide_port", -1);
			LAi_ActorFollow(pchar, npchar, "", -1);
		break;
		
		case "guide_29":
			dialog.text = "Este es el muelle, el corazón de cualquier puerto. Solía navegar en el pasado, así que déjame contarte más sobre la navegación.\nPrimero, recuerda lo más importante: ¡ni siquiera intentes dirigir una embarcación si no tienes suficientes puntos en tu habilidad de navegación! Cuando no se cumple el requisito, tus otras habilidades sufrirán y también las de tus oficiales.\nPelearás peor, dispararás peor, comerciarás peor y así sucesivamente.\nEso significa que si intentas dirigir un navío de guerra con tu actual habilidad de navegación, no llegarás lejos, de hecho, puede que ni siquiera seas capaz de hacer un pequeño giro.";
			link.l1 = "¿Cómo aprendo esto, navegación?";
			link.l1.go = "guide_30";
			locCameraFromToPos(-8.55, 4.06, 91.31, true, 40.00, -8.00, 0.00);
		break;
		
		case "guide_30":
			dialog.text = "¿Sabes qué, mi amigo? Aquí tienes esta pequeña nota sobre cómo manejar un barco. Léela cuando consigas el tuyo. Un documento bastante útil, me ayudó mucho en mi tiempo.";
			link.l1 = "Muy bien, monsieur. En verdad, no estoy realmente listo para absorber tanto conocimiento complejo en este momento.";
			link.l1.go = "guide_38";
			AddQuestRecordInfo("Guide_AtSea", "1");
		break;
		
		case "guide_31":
			dialog.text = "La jerarquía del barco lo determina. Por ejemplo, tengo suficiente experiencia (45 puntos) para controlar un navío de 4ª categoría sin penalizaciones. Bergantines, barquentinas, fluyts. Xebecs y corbetas requieren más, así que no podré usarlos adecuadamente. Ni siquiera son barcos de segunda categoría como fragatas y galeones pesados.\nEn cuanto a los gigantescos navíos de línea o los man-o-war... solo los expertos en navegación pueden controlar tales monstruos, se necesitan años para dominar la habilidad y no olvides el dinero. Un acorazado y su tripulación pueden vaciar tu bolsa en un mes si no eres tan rico como el propio Rey Luis.";
			link.l1 = "Ya veo...";
			link.l1.go = "guide_32";
		break;
		
		case "guide_32":
			dialog.text = "Cuida las posiciones de tus oficiales. Un contramaestre entrena a tu tripulación y hace más efectivo el abordaje, un intendente realizará actividades financieras en tu lugar y librará a tu barco de ratas. Un médico cura a tus hombres heridos y reduce la cantidad que muere en batalla, un carpintero repara cualquier daño hecho al barco, y los oficiales de abordaje te salvan el pellejo cuando los piratas comienzan a invadir tu cubierta.\nPresta atención a las habilidades de los candidatos y su reputación.";
			link.l1 = "¿Reputación?";
			link.l1.go = "guide_33";
		break;
		
		case "guide_33":
			dialog.text = "Exactamente. Todo hombre tiene uno. Muestra a un hombre por lo que realmente es.\nSi eres un hombre honorable y siempre tratas de hacer el bien, entonces busca oficiales que compartan tus ideales. Y si quieres ser un pirata... bueno, ya entiendes la idea.\nLa gente honesta no trabajará para escoria, lo contrario también es cierto.";
			link.l1 = "Entendido.";
			link.l1.go = "guide_34";
		break;
		
		case "guide_34":
			dialog.text = "Ahora hablemos sobre los tipos de barcos. Hay dos tipos. Los mercantes y los buques de guerra. Los mercantes o barcos de comercio tienen grandes bodegas de carga y tienden a ser más lentos. Los buques de guerra son rápidos y tienen cañones fuertes, a expensas de la capacidad de carga. Barcas, fluyts y carracas son buenos y sólidos barcos de comercio. Balandras, bergantines y corbetas son buques de guerra. Hay híbridos, por supuesto, barcos que son adecuados tanto para el comercio como para la lucha: snows, goletas y galeones.\nLos barcos también tienen diferentes disposiciones de aparejo, algunos están aparejados principalmente de velas cuadradas y otros principalmente de velas cangrejas, lo que forma el mejor ángulo de curso del barco.";
			link.l1 = "¿Ángulo del rumbo?";
			link.l1.go = "guide_35";
		break;
		
		case "guide_35":
			dialog.text = "Sí. Determina cómo el aparejo se ve afectado por el viento y en qué rumbo tu navío alcanzará la mejor velocidad de la que es capaz. Una vez en el mar, encuentra la flecha en el mini mapa, ese será tu ángulo de rumbo.";
			link.l1 = "Eso me resulta un poco confuso. Pero supongo que lo aprenderé con el tiempo.";
			link.l1.go = "guide_36";
		break;
		
		case "guide_36":
			dialog.text = "Ahora, tu tripulación. Tú y tu barco no son nada sin los hombres que lo manejan. Cada marinero debe saber hacer tres cosas. Cómo manejar las jarcias, cómo operar los cañones y cómo luchar. Cada nación se destaca solo en una de estas tres actividades. Por ejemplo, España tiene los mejores luchadores del mundo y sus abordadores llevan armadura, por lo que los metrallas, cortes y puñaladas no son tan efectivos contra ellos. Estoy hablando, por supuesto, de armas pequeñas, los disparos de metralla de cañón no se preocupan por las armaduras corporales.\nVisita las tabernas de España, Inglaterra y Francia si quieres formar una tripulación de ensueño, o si quieres arriesgarte contrata una tripulación pirata, por mucho que un hombre pueda odiarlos, siguen siendo la tripulación más mortal que uno puede tener. Vigila la moral de tus hombres, proporciónales ron, mujeres y monedas regularmente. Haz eso y tus hombres morirán por ti. Si fallas en hacerlo, crearán un motín. Un profesional motivado vale por diez novatos en una pelea. Además, no te olvides de un médico, o desarrolla tus propias habilidades de medicina para evitar bajas adicionales.";
			link.l1 = "Recordaré esto...";
			link.l1.go = "guide_37";
		break;
		
		case "guide_37":
			dialog.text = "Ahora unas pocas palabras sobre las batallas navales. El Caribe es peligroso, lleno de patrullas españolas y piratas, así que eventualmente te encontrarás con ellos en mar abierto. Los cañones del barco usan cuatro tipos de munición. Balas de cañón, metralla, disparos de cadena y bombas.\nLas balas de cañón son para todo propósito y las más baratas de comprar, además tienen el mayor alcance efectivo de disparo. Desgarran las velas del enemigo, destruyen su casco y matan a su tripulación.\nLos disparos de cadena tienen un alcance de fuego decente, su propósito es eliminar el aparejo del enemigo para ralentizarlos. Son buenos de usar cuando quieres perseguir o huir. Si tienes suerte, incluso puedes derribar un mástil completo.\nBombas. Úsalas si quieres hundir el buque de tu oponente. Las bombas hacen el mayor daño al casco, pero tienen el segundo alcance de fuego más corto, así que necesitas acercarte primero, lo que puede resultar fatal. También son las más costosas de todas las municiones.\nLa metralla es tu mejor opción si quieres abordar y capturar un barco enemigo. Estos pequeños y desagradables bichos eliminan a las personas, pero tienen el alcance de disparo más corto, lo que los hace arriesgados de usar. Pero puede valer la pena.\nDetén tu fuego si no estás seguro de poder causar suficiente daño. Cada andanada tiene el precio de pólvora, tiempo y la condición de los cañones. A veces pueden explotar, especialmente si disparas demasiado a menudo. Siempre maniobra, intenta tomar una mejor posición. Si el enemigo es demasiado peligroso y no puedes huir, intenta provocarlos para que te disparen constantemente desde una distancia sin recibir daño. Este truco eventualmente vaciará sus suministros de pólvora. Puede llevar días, así que es mejor que encuentres cobertura como rocas o una línea costera. Por supuesto, tales tácticas no funcionarán en mar abierto.\nMinas. También son una buena manera de hundirlos a todos. Provócalos para que te persigan y suelta minas. Cada mina requiere una cantidad decente de pólvora, pero incluso una mina puede destruir un lugre.\nConsigue un catalejo y úsalo para observar a tu enemigo. Un buen catalejo te proporcionará una buena visión táctica, respecto a la presencia de unidades de mosqueteros en el buque de tu oponente, por ejemplo. Los mosqueteros enemigos pueden abatir a muchos de tus hombres en cubierta, así que asegúrate de darles una buena ración de metralla antes de abordar.";
			link.l1 = "Santo Jesús... eso es aterrador... pero supongo que debo estar preparado para cualquier cosa.";
			link.l1.go = "guide_38";
		break;
		
		case "guide_38":
			dialog.text = "Aprenderás, de eso no tengo duda. Ya que vas a ser capitán y propietario de un barco, te mostraré otro lugar de gran importancia. La oficina del puerto. Sígueme.";
			link.l1 = "";
			link.l1.go = "guide_39";
		break;
		
		case "guide_39": // к портовому управлению
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(npchar, "reload", "reload10", "Guide_portoffice", -1);
			LAi_ActorFollow(pchar, npchar, "", -1);
		break;
		
		case "guide_40":
			dialog.text = "Ahí está. En la oficina del puerto puedes encontrar ofertas de trabajo. Cargas para grandes mercantes y escolta de convoyes para buques de guerra. Si posees un barco rápido, podrían ofrecerte un trabajo de mensajería.\nTe recomiendo ganarte algo de confianza aquí. Si haces bien tu trabajo varias veces, te confiarán contratos más complicados y mucho mejor pagados.\nTambién puedes preguntar sobre otros capitanes y dejar tus barcos sobrantes aquí en almacenamiento para su seguridad. Almacenamiento indefinido, solo no olvides pagar.";
			link.l1 = "Entendido.";
			link.l1.go = "guide_41";
			locCameraFromToPos(48.38, 9.48, 43.95, true, -70.00, -55.00, 150.00);
		break;
		
		case "guide_41":
			dialog.text = "Bueno, las puertas de la ciudad están cerca, así que hay otro tema del que me gustaría hablarte. Estas puertas conducen a las junglas. Sígueme y te contaré sobre acciones furtivas y esgrima. ¿Te importa?";
			link.l1 = "¡En absoluto! ¡Ya me has ayudado mucho!";
			link.l1.go = "guide_42";
		break;
		
		case "guide_42":
			dialog.text = "¡Sígueme entonces!";
			link.l1 = "";
			link.l1.go = "guide_43";
		break;
		
		case "guide_43": // к воротам
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(npchar, "reload", "gate_back", "Guide_gate", -1);
			LAi_ActorFollow(pchar, npchar, "", -1);
		break;
		
		case "guide_44":
			dialog.text = "Entonces, aquí tenemos una puerta de la ciudad que lleva directo a la jungla... Esto es embarazoso, pero tengo un memorándum más para que estudies más tarde. Esta vez, se trata de las sutilezas de nuestra vida en tierra. Tómate tu tiempo para leerlo, ya que te ayudará a comprender mejor cómo infiltrarte en ciudades hostiles y cómo pelear en tierra. Pero por ahora, sugiero que salgamos por las puertas y nos divirtamos un poco - practiquemos esgrima.";
			link.l1 = "Eres una verdadera enciclopedia, Monsieur. ¡Vamos! Practicar suena divertido.";
			link.l1.go = "guide_48";
			locCameraFromToPos(50.58, 5.74, 23.21, false, 100.00, 0.00, 20.00);
			AddQuestRecordInfo("Guide_OnLand", "1");
		break;
		
		case "guide_45":
			dialog.text = "Un documento que puedes obtener en la sede de la Compañía Neerlandesa de las Indias Occidentales. Una señal de tus intenciones pacíficas. Este papel te permitirá entrar en cualquier puerto hasta que los términos hayan expirado.\nPero hay algunos inconvenientes. Primero, la Compañía tiene reglas especiales y exige que cualquier capitán dispuesto a comprar la licencia debe seguirlas. Segundo, cuesta mucho. Y lo último y lo peor, todavía necesitas una habilidad de 'izar la bandera' para desembarcar en los puertos. De lo contrario, serás disparado al instante por los pesados cañones del fuerte.";
			link.l1 = "¿Dónde están las oficinas centrales de la Compañía?";
			link.l1.go = "guide_46";
		break;
		
		case "guide_46":
			dialog.text = "Willemstad en Curazao. Si quieres comprar una patente, ve allí, te darán los detalles.";
			link.l1 = "Las cosas están tan desordenadas aquí...";
			link.l1.go = "guide_47";
		break;
		
		case "guide_47":
			dialog.text = "No te molestes, mi amigo. Aprenderás. Ahora, practiquemos esgrima.";
			link.l1 = "Suena bien. ¡Vamos!";
			link.l1.go = "guide_48";
		break;
		
		case "guide_48": // телепортируем за городские ворота
			DialogExit();
			LAi_SetActorType(npchar);
			DoQuestReloadToLocation("FortFrance_ExitTown", "goto", "goto19", "Guide_ExitTown");
		break;
		
		case "guide_49":
			dialog.text = "Amigo mío, ¿creo que sabes cómo empuñar una espada?";
			link.l1 = "¡Ja! Por supuesto que lo sé. ¡Fui enseñado por el mejor maestro de esgrima de París!";
			link.l1.go = "guide_50";
		break;
		
		case "guide_50":
			dialog.text = "Bien por ti. Déjame enseñarte algo de teoría primero.\nHay tres tipos de acero frío: ligero, medio y pesado. Cada tipo requiere diferentes habilidades y destrezas para dominar, así que tendrás que aprenderlos por separado.\nCada clase tiene sus beneficios e inconvenientes. Las armas ligeras incluyen floretes y espadas, requieren poca resistencia, pero causan el menor daño. Un arma pesada, como un hacha, puede matar de un solo golpe, aunque agotará tu resistencia muy rápidamente, y es posible que tengas que descansar entre los golpes. Las armas medianas, sables o cimitarras, son el punto intermedio, combinando buen peso y potencial de daño.\nTienes a tu disposición varios movimientos y trucos de esgrima: ataque de estocada, ataque de corte, ataque pesado y ataque grupal. También puedes parar, fintar y bloquear.\nEl ataque de estocada es el movimiento más rápido, requiere la menor cantidad de resistencia para realizarse, y es excelente para espadas largas. Es mayormente inútil para hachas. El ataque de corte es bastante versátil, tiene una velocidad decente, una pérdida significativa de resistencia, es bueno para sables, espadas anchas y hachas, pero no tan efectivo con espadas largas. El ataque pesado se realiza desde arriba, una excelente elección para hachas, funcionará bien para sables cortos y cimitarras, pero las espadas largas simplemente no están diseñadas para tales movimientos. Este ataque drenará una gran cantidad de resistencia, es lento, pero causará un daño devastador e ignora los bloqueos de tu enemigo.\nBloquear es inútil contra ataques pesados y los oponentes experimentados siempre tienen la oportunidad de romper tu bloqueo. Parar es mucho mejor, abre a tu oponente para ataques y lo obliga a perder resistencia. Varias paradas exitosas y tu oponente pierde completamente la iniciativa y se ve obligado a defenderse mientras tú tienes toda la ventaja.\nLas fintas son complicadas y arriesgadas. Engañar a tu oponente e inmediatamente darle una rápida estocada requiere solo una pequeña pérdida de resistencia, pero debes estar concentrado, atento y en el ritmo de la pelea. Dominar este movimiento te exigirá mucha práctica, pero es gratificante: incluso duelistas profesionales y maestros de la espada caerán por tu mano.\nPara maximizar el daño de cada tipo de ataque, debes usar el arma correcta para cada uno. El ataque de estocada se desempeñará mejor con espadas largas, ligeras y rectas con un equilibrio de 0 a 0.5. Las cimitarras o sables largos y curvados con un equilibrio de 1 a 2 son excelentes para ataques de corte y pesados. Un hacha pesada con un equilibrio de 2 es perfecta para ataques pesados, pero tal arma requerirá mucha resistencia y habilidad para usar. El ataque grupal no vale la pena ser tu movimiento principal, es más bien defensivo, pero una cimitarra larga, ligera y curvada con un equilibrio de 0.75 a 1.25 hará maravillas contra grupos de enemigos a tu alrededor.\nFinalmente, la mejor arma para fintar es una daga, considera hacer de este movimiento tu especialidad. El peso de un arma determina cuánta resistencia requerirá para cualquier movimiento de ataque y también afecta el daño. Recuerda que encontrar tu arma perfecta puede tomar algo de tiempo y trabajar en tu estilo de lucha tomará aún más.";
			link.l1 = "¿Y qué si hay varios enemigos?";
			link.l1.go = "guide_51";
		break;
		
		case "guide_51":
			dialog.text = "Esto complica las cosas. Un luchador decente puede derribar a unos cuantos tontos mal entrenados juntos al aire libre, pero si hay una docena de bribones viniendo hacia ti - evita ser rodeado a toda costa, huye, busca un rincón o unas escaleras, puertas, lo que sea, fuerza a que te enfrenten uno por uno, o dos contra uno. Te harán pedazos en un segundo si cometes un error, así que fuerza a que jueguen bajo tus términos, no pierdas la iniciativa y vigila tu resistencia.\nAunque, he oído hablar de una poción india especial que permitía a los maestros de la espada y el hacha matar a cinco o seis enemigos a la vez con unos cuantos ataques grupales.";
			link.l1 = "¿Una poción especial?";
			link.l1.go = "guide_52";
		break;
		
		case "guide_52":
			dialog.text = "La mezcla de Ometochtli o como sea que la llamen. Una receta antigua india. Pregunta a los comerciantes, alguien puede vendértela algún día. Pero primero debes aprender alquimia para poder usar la receta... Ya que estamos hablando de pociones, déjame contarte sobre la curación.\nSi necesitas curar una herida pequeña, usa pociones curativas. Los golpes serios pueden tratarse con un elixir. Las mezclas curativas, el ron y el vino también restauran tu salud.\nUn antídoto y una mezcla estarán bien si estás envenenado. También recomiendo una raíz de jengibre, refresca maravillosamente el aliento. También cura sin efectos secundarios, a diferencia de las esencias y elixires.";
			link.l1 = "¿Espera, efectos secundarios?";
			link.l1.go = "guide_53";
		break;
		
		case "guide_53":
			dialog.text = "Esencias, elixires y mezclas dañan tu salud. Como mencioné al principio de nuestro pequeño recorrido, es malo. Mala salud causará descensos en tus niveles de habilidad, disminuirá la cantidad total de tus puntos de salud y tu resistencia.\nDormir, el sexo y una rara poción llamada 'Lágrimas de Ish-Chel' no estoy completamente seguro del nombre, todo lo que sé es que tiene algunas lágrimas, de todos modos, tales cosas restaurarán la salud si no está completamente arruinada. Si es demasiado tarde, visita a un sacerdote, ellos ayudarán por una tarifa.";
			link.l1 = "Ya veo. ¿Qué puedes decirme sobre las pistolas?";
			link.l1.go = "guide_54";
		break;
		
		case "guide_54":
			dialog.text = "No hay mucho que decir. ¡Apunta y dispara! Usa metralla si hay varios enemigos. Consigue un mosquete o un rifle, tienen un daño mortal y siempre puedes golpear a la gente con la culata. También oí hablar de un mosquete tipo trabuco que dispara granadas, es un arma excelente y muy hermosa también... pero nunca la he visto.";
			link.l1 = "Ya veo. ¿Hora de practicar?";
			if (FindCharacterItemByGroupWithout_knife_03(pchar, BLADE_ITEM_TYPE) == "") link.l1.go = "guide_55a";
			else link.l1.go = "guide_55";
		break;
		
		case "guide_55a":
			dialog.text = "Mm. Acabo de darme cuenta. ¿Dónde está tu espada? Me temo que nuestra lección debe ser pospuesta. ¿Cómo terminaste sin un arma, "+pchar.name+"¿?";
			link.l1 = "Un hijo de la gran puta real con un traje elegante me lo quitó como adelanto de la deuda de mi hermano... ¿Tienes una espada extra para mí? La devolveré cuando termine la lección...";
			link.l1.go = "guide_55b";
		break;
		
		case "guide_55b":
			GiveItem2Character(pchar, "blade_05");
			EquipCharacterByItem(Pchar, "blade_05");
			dialog.text = "Tienes suerte. Tengo una espada extra. Iba a venderla, pero, afortunado tú, me retrasé.";
			link.l1 = "Merci. ¿Vamos?";
			link.l1.go = "guide_55";
		break;
		
		case "guide_55":
			dialog.text = "¡En guardia! Y no desperdicies ninguna poción que tengas, no vamos a matarnos.";
			link.l1 = "Como usted diga.";
			link.l1.go = "guide_56";
			npchar.quest.guide_win = 0;
		break;
		
		case "guide_56": // махач
			LAi_SetPlayerType(pchar);
			LAi_SetCurHPMax(pchar); 
			LAi_GetCharacterMaxEnergy(pchar);
			LAi_SetCurHPMax(npchar); 
			LAi_GetCharacterMaxEnergy(npchar);
			LAi_SetImmortal(npchar, false);
			LAi_group_Delete("EnemyFight");
			if (MOD_SKILL_ENEMY_RATE <= 6)	// На первых трёх сложностях Валинье будет ослаблен
			{
				LAi_SetHP(npchar, LAi_GetCharacterMaxHP(npchar) * 0.7, LAi_GetCharacterMaxHP(npchar) * 0.7);
				npchar.rank = 1;
				SetSelfSkill(npchar, 1, 1, 1, 1, 1);
			}
			DialogExit();
			LAi_SetWarriorType(npchar);
			LAi_group_MoveCharacter(npchar, "EnemyFight");
			// ставим проверяльщики
			LAi_SetCheckMinHP(pchar, 1, true, "Guide_HeroFail");
			LAi_SetCheckMinHP(npchar, 1, true, "Guide_HeroWin");
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			AddDialogExitQuest("MainHeroFightModeOn");
			DoQuestCheckDelay("GuideFight_tutorial", 1.0);
		break;
		
		case "guide_57": // побил гида с первого раза
			dialog.text = "Vos... vos sois un hombre que sabe cómo empuñar su espada. Bien hecho, Monsieur. Necesitáis más práctica, pero tenéis el potencial de convertiros en un verdadero maestro de la espada.";
			link.l1 = "Merci beaucoup. ¿Y ahora qué?";
			link.l1.go = "guide_62"; // нода на выход
			if (MOD_SKILL_ENEMY_RATE >= 6)
			{
				link.l2 = "¿Más práctica dices? ¿Hablas en serio? ¡Estoy cansado de este tono condescendiente desde que puse un pie en este miserable lugar!";				//Пасхалка Корсары 2 для сложности СФ и выше
				link.l2.go = "guide_64";
			}
			AddComplexSelfExpToScill(50, 50, 50, 50);
			AddCharacterExpToSkill(pchar, "Leadership", 80);
		break;
		
		case "guide_58": // побил гида со второго или третьего раза
			dialog.text = "¡Mucho mejor! Mira, todo lo que necesitas es concentrarte. Necesitas más práctica, un día te convertirás en un espadachín decente.";
			link.l1 = "Merci beaucoup. ¿Y ahora qué?";
			link.l1.go = "guide_62"; // нода на выход
			AddComplexSelfExpToScill(20, 20, 20, 20);
			AddCharacterExpToSkill(pchar, "Leadership", 30);
		break;
		
		case "guide_59": // побили первый раз
			dialog.text = "Gan é, Monsieur. Muévete más rápido, para mis estocadas, salta hacia atrás. ¿Una revancha?";
			link.l1 = "¡Oui! ¡Sin piedad, Monsieur!";
			link.l1.go = "guide_56";
			link.l2 = "No, he tenido suficiente. Terminemos la lección. ¿Qué ahora?";
			link.l2.go = "guide_62"; // нода на выход
		break;
		
		case "guide_60": // побили второй раз
			dialog.text = "He ganado de nuevo, "+pchar.name+"¡No pierdas tu iniciativa! Atrapa mis golpes, fintéalos. Si ves que voy a golpear fuerte, salta o para, no te limites a defenderte. ¡Otra vez!";
			link.l1 = "¡Ven, monsieur, esta vez te daré una paliza!";
			link.l1.go = "guide_56";
			link.l2 = "No, he tenido suficiente. Terminemos la lección. ¿Qué ahora?";
			link.l2.go = "guide_62"; // нода на выход
		break;
		
		case "guide_61": // побили третий раз
			dialog.text = "Tienes mucho que aprender, "+pchar.name+". No te preocupes, todavía tienes mucho tiempo para dominar la esgrima. Pero ten cuidado, no te arriesgues hasta que sepas cómo sostener un arma.";
			link.l1 = "Lo consideraré, Monsieur, pero debo decir que tuviste demasiada suerte. Este maldito calor... la única razón por la que no te di una paliza. ¡Merde, terminemos nuestra lección de esgrima! ¿Y ahora qué?";
			link.l1.go = "guide_62"; // нода на выход
		break;
		
		case "guide_62":
			dialog.text = "Ahora es el momento de despedirse, Monsieur. Fue un placer. Espero que mi presentación y entrenamiento le hayan sido de alguna utilidad y le resulten útiles en el futuro. Tal vez, nos volvamos a encontrar algún día.\nY acerca del dinero que necesita - hable con las personas importantes de nuestra ciudad. Visite todos los lugares que le he mostrado hoy y hable con sus dueños. Pregunte por ahí. Dé un paseo por la jungla y el fuerte. Encuentre un trabajo o... bueno, no soy sacerdote ni juez, eche un vistazo a las casas de la gente y vea qué baratijas puede encontrar en sus cofres sin cerradura. Solo hágalo cuando les den la espalda o los guardias lo atraparán.\nBuena suerte, "+pchar.name+", Tengo una fuerte corazonada de que tienes la chispa de la verdadera grandeza dentro de ti. ¡Haz todo lo posible por avivarla hasta convertirla en un fuego rugiente!";
			link.l1 = "Merci, Monsieur. El placer fue mío. ¡Buen viento y buena mar!";
			link.l1.go = "guide_63";
		break;
		
		case "guide_63":
			LAi_SetCurHPMax(pchar); 
			LAi_GetCharacterMaxEnergy(pchar);
			DialogExit();
			chrDisableReloadToLocation = false;//открыть локацию
			npchar.lifeday = 0;
			DoQuestReloadToLocation("FortFrance_Town", "quest", "quest2", "");
		break;
		
		case "guide_64": // решили убить Валинье
			dialog.text = "¡Cierra el pico, Monsieur! No toleraré tal insolencia por más tiempo. Sin embargo, entiendo tu reacción ante un nuevo entorno, por lo tanto, perdono tu arrebato esta vez. Pero cuida tus palabras de ahora en adelante. Adiós, Monsieur de Maure.";
			link.l1 = "Sin ofender, Monsieur Valinnie. ¡Si estuviéramos en el Louvre en este momento, cuidarías tu tono! Es hora de enseñar una lección final a una provincia. ¡Defiéndete!";
			link.l1.go = "guide_65";
		break;
		
		case "guide_65":
			DialogExit();
			
			npchar.rank = 25;
			int iHp = MOD_SKILL_ENEMY_RATE*10+300;
			LAi_SetHP(npchar, iHp, iHp);
			SetSelfSkill(npchar, 80, 80, 80, 80, 50);
			SetShipSkill(npchar, 50, 80, 35, 30, 50, 20, 30, 20, 80);
			SetSPECIAL(npchar, 9, 5, 8, 6, 5, 10, 8);
			SetCharacterPerk(npchar, "Energaiser");
			SetCharacterPerk(npchar, "BasicDefense");
			SetCharacterPerk(npchar, "AdvancedDefense");
			SetCharacterPerk(npchar, "CriticalHit");
			SetCharacterPerk(npchar, "Tireless");
			SetCharacterPerk(npchar, "HardHitter");
			SetCharacterPerk(npchar, "Sliding");
			SetCharacterPerk(npchar, "BladeDancer");
			SetCharacterPerk(npchar, "SwordplayProfessional");
			SetCharacterPerk(npchar, "Gunman");
			SetCharacterPerk(npchar, "GunProfessional");
			GiveItem2Character(npchar, "blade_30");
			EquipCharacterbyItem(npchar, "blade_30");
			GiveItem2Character(npchar, "cirass7");
			GiveItem2Character(npchar, "obereg_7");
			GiveItem2Character(npchar, "talisman11");
			AddMoneyToCharacter(npchar, 10000);
			AddItems(npchar, "gold_dublon", 25);
			AddItems(npchar, "bullet", 5);
			AddItems(npchar, "grapeshot", 5);
			AddItems(npchar, "GunPowder", 10);
			TakeItemFromCharacter(npchar, "blade_12");
			npchar.cirassId = Items_FindItemIdx("cirass4");
			LAi_SetCurHPMax(npchar);
			LAi_GetCharacterMaxEnergy(npchar);
			LAi_SetCurHPMax(pchar); 
			LAi_GetCharacterMaxEnergy(pchar);
			LAi_SetImmortal(npchar, false);
			LAi_group_Delete("EnemyFight");
			LAi_SetWarriorType(npchar);
			LAi_group_MoveCharacter(npchar, "EnemyFight");
			npchar.SaveItemsForDead = true;
			npchar.DontClearDead = true;
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, false);
			LAi_group_SetCheck("EnemyFight", "Guide_HeroKill");
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}

string FindCharacterItemByGroupWithout_knife_03(ref chref, string groupID)
{
	ref refItm;
    string resultItemId;

	resultItemId  = "";
	for(i=TOTAL_ITEMS-1; i>=0; i--)
	{
		refItm = &Items[i];
		if( !CheckAttribute(refItm,"groupID") ) continue;
		if(refItm.groupID!=groupID) continue;
		if( !CheckAttribute(chref,"items."+refItm.id) ) continue;
		if(refItm.id == "knife_03") continue;
		if (groupID == BLADE_ITEM_TYPE)
		{
			resultItemId  = refItm.id;
		}
	}
	
	if (resultItemId != "")
	{
        return resultItemId;
	}

	return "";
}