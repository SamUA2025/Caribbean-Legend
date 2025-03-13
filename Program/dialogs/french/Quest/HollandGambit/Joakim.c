// Жоаким Мерриман - португальский сумрачный гений
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			if (CheckAttribute(pchar, "questTemp.HWIC.Holl"))
			{
				if (pchar.questTemp.HWIC.Holl == "AbbySeekIsland" && !CheckAttribute(npchar, "quest.HWICHoll.Task"))
				{
					dialog.text = "Bonjour monsieur ! Je suis le Docteur Joachim Merriman. Ai-je le plaisir de m'adresser au Capitaine "+GetFullName(pchar)+"?";
					link.l1 = "Oui, c'est moi. Comment diable connaissez-vous mon nom? Je ne me souviens pas de vous avoir rencontré auparavant.";
					link.l1.go = "JoakimSeekSkull";
					break;
				}
				if (CheckCharacterItem(pchar, "SkullAztec"))
				{
					dialog.text = "Je suis heureux de vous voir, capitaine. À voir votre démarche légère, je devine que vous allez me rendre très heureux. Avez-vous le crâne de Yum Cimil ?";
					link.l1 = "J'ai le crâne dont vous parlez. Il crépite d'énergie, comme une fournaise rugissante.";
					link.l1.go = "JoakimFindSkull";
					break;
				}
				dialog.text = "As-tu autre chose à dire, capitaine ?";
				link.l1 = "Non, señor Merriman. Je m'en vais...";
				link.l1.go = "exit";
				break;
			}
			if (CheckAttribute(pchar, "questTemp.HWIC.Self"))
			{
				if (pchar.questTemp.HWIC.Self == "JoakimMeeting" && !CheckAttribute(npchar, "quest.HWICHoll.Task"))
				{
					dialog.text = "Bonjour monsieur ! Je suis le Docteur Joachim Merriman. Ai-je le plaisir de m'adresser au Capitaine "+GetFullName(pchar)+"?";
					link.l1 = "Aye, c'est moi. Comment diable connaissez-vous mon nom ? Je ne me souviens pas de vous avoir rencontré auparavant.";
					link.l1.go = "JoakimSeekSkull";
					break;
				}
				if (CheckCharacterItem(pchar, "SkullAztec"))
				{
					DelLandQuestMark(npchar);
					DelMapQuestMarkCity("Villemstad");
					dialog.text = "Je suis heureux de vous voir, capitaine. Je peux dire à votre démarche que vous allez me rendre très heureux. Avez-vous le crâne de Yum Cimil?";
					link.l1 = "J'ai le crâne dont tu parles. Il crépite d'énergie, tel un four rugissant.";
					link.l1.go = "JoakimFindSkull";
					break;
				}
				dialog.text = "As-tu autre chose à ajouter, capitaine?";
				link.l1 = "Non, Docteur Merriman. Je m'en vais.";
				link.l1.go = "exit";
				break;
			}
			dialog.text = "Bonjour. Voulez-vous quelque chose de moi?";
			link.l1 = "Non, désolé.";
			link.l1.go = "exit";
			NextDiag.TempNode = "First time";
		break;

		case "Landlady"://хозяйка дома
			dialog.text = "Si vous êtes venu voir le docteur Merriman, il n'est pas ici. Il ne vit plus ici.";
			link.l1 = "Je vois.";
			link.l1.go = "exit";
			NextDiag.TempNode = "Landlady";
		break;
		
		case "Landlady_1"://хозяйка дома
			dialog.text = "Si vous êtes venu voir le Docteur Merriman, alors je dois vous dire qu’il n’est pas à la maison. Il est en voyage en ce moment et je ne sais pas quand il reviendra.";
			link.l1 = "Je vois.";
			link.l1.go = "exit";
			NextDiag.TempNode = "Landlady_1";
		break;
		
		case "Landlady_2"://хозяйка дома
			dialog.text = "Si vous êtes venu voir le docteur Merriman, il n'est pas ici. Il ne vit plus ici.";
			link.l1 = "Je vois.";
			link.l1.go = "exit";
			NextDiag.TempNode = "Landlady_2";
		break;
		
		case "JoakimSeekSkull":
			PlaySound("Voice\English\hambit\Joakim Merriman-01.wav");
			dialog.text = "Vos affaires ne sont pas aussi privées que vous pourriez le croire, capitaine ! Mais ne vous alarmez pas, j'ai une proposition à vous faire ! Je suis un homme de science, une sorte de philosophe naturel étudiant la fascinante culture des païens indiens du Continent Espagnol et des Antilles. Auriez-vous l'amabilité de m'accompagner jusqu'à ma maison pour discuter des détails potentiellement très lucratifs dans mon salon ?";
			link.l1 = "Vous avez piqué ma curiosité et mon attention. Montrez-moi le chemin.";
			link.l1.go = "JoakimSeekSkull_1";
		break;
		
		case "JoakimSeekSkull_1":
			dialog.text = "Vous ne refuserez pas cela, monsieur ! Ma maison n'est pas loin d'ici. Suivez-moi !";
			link.l1 = "...";
			link.l1.go = "JoakimSeekSkull_2";
		break;
		
		case "JoakimSeekSkull_2":
			DialogExit();
			AddLandQuestMark(npchar, "questmarkmain");
			LAi_ActorGoToLocation(npchar, "reload", "houseSp1", "Villemstad_houseSp1_room", "goto", "goto1", "JoakimInRoom", -1);
		break;
		
		case "JoakimSeekSkull_3":
			PlaySound("Voice\English\hambit\Joakim Merriman-01.wav");
			dialog.text = "Nous pouvons parler ici sans craindre des oreilles indiscrètes. Vous avez récemment rendu visite à mon voisin Solomon Shneur. Je passais par là et, vous devez me pardonner capitaine, j'ai accidentellement surpris quelques détails de votre conversation avec Solomon. C'était si fascinant que j'ai dû écouter toute la discussion !";
			link.l1 = "Un espion qui a peur des autres espions, hein ?";
			link.l1.go = "JoakimSeekSkull_4";
		break;
		
		case "JoakimSeekSkull_4":
			dialog.text = "Allons, allons, capitaine ! Ce n'est pas du tout comme ça ! Salomon est mon voisin et il me rend souvent visite. Nous sommes de bons amis malgré nos différences religieuses ! Je connais ses mésaventures... comme tout le monde à Willemstad ! Salomon proclame ses ennuis à quiconque veut bien l'entendre matin, midi et soir. Mais assez parlé de ça. Le vieux Juif vous a sûrement déjà parlé d'un vieux crâne de jade caché avec son or sur quelque île inconnue. Vous en a-t-il parlé ?";
			link.l1 = "Il m'a parlé d'un crâne, mais il n'a pas mentionné qu'il était en jade. Il a aussi dit que c'était le crâne de son grand-père. Pour être honnête, je pensais que c'était soit une horreur kabbalistique, soit que le vieux fou avait des araignées au plafond.";
			link.l1.go = "JoakimSeekSkull_5";
		break;
		
		case "JoakimSeekSkull_5":
			dialog.text = "Non, capitaine, Salomon est tout à fait sain d'esprit, juste un peu excentrique. Le crâne existe bel et bien. C'est un ancien trésor indien, le crâne de jade de Yum Cimil ! Je n'ai aucune idée de comment ce vieux Juif a mis la main dessus. Je l'ai cherché pendant la moitié de ma vie\nCherchez cette île où Salomon a caché l'argent de sa famille. Le crâne doit être là, dans son coffre. Apportez-moi ce crâne de jade et je vous paierai un demi-million de pesos.";
			link.l1 = "Un demi-millier ? Cela ne vaut guère mon temps - attendez une minute... avez-vous dit un demi-million de pièces de huit ?! Vous plaisantez ? Je n'ai jamais vu tout cet argent réuni en un seul endroit de ma vie !";
			link.l1.go = "JoakimSeekSkull_6";
		break;
		
		case "JoakimSeekSkull_6":
			dialog.text = "Vous êtes encore un jeune capitaine... Alors, êtes-vous partant ? Vous me donnez le crâne de jade et je vous donne en retour cinq cent mille pièces de huit. Marché conclu ?";
			link.l1 = "Ha, une fortune pour un vieux crâne ? Bien sûr que je suis partant.";
			link.l1.go = "JoakimSeekSkull_7";
		break;
		
		case "JoakimSeekSkull_7":
			dialog.text = "Splendide. C'est toujours un plaisir de travailler avec un homme qui comprend le profit. Vous pouvez me trouver ici dans ma maison si vous avez besoin de moi. Bonne chance !";
			link.l1 = "Merci, Docteur Merriman. Je ne vous ferai pas attendre trop longtemps.";
			link.l1.go = "exit";
			npchar.quest.HWICHoll.Task = "true";
			LAi_SetOwnerType(npchar);
			AddDialogExitQuestFunction("CheckIslandCoordinates");//вот тут-то мы и проверим, есть ли у нас координаты острова, и далее будем исходить из результата.
		break;
		
		case "JoakimFindSkull":
			PlaySound("Voice\English\hambit\Joakim Merriman-02.wav");
			dialog.text = "Oh, oui ! Vous avez certainement raison quant à sa puissance... Mais assez de paroles, laissez-moi le voir, je tremble d'impatience.";
			link.l1 = "Voici, s'il vous plaît, prenez-le. J'espère que je ne me suis pas trompé ?";
			link.l1.go = "JoakimFindSkull_1";
			DelLandQuestMark(npchar);
		break;
		
		case "JoakimFindSkull_1":
			RemoveItems(PChar, "SkullAztec", 1);
			dialog.text = "Ah, incroyable ! Oui, c'est ça. Excellent, capitaine, très excellent ! Enfin ! Je l'ai avec moi, enfin ! J'ai attendu ce moment pendant tant d'années !";
			link.l1 = "Qu'en est-il de l'argent que vous avez promis, Docteur Merriman ?";
			link.l1.go = "JoakimFindSkull_2";
		break;
		
		case "JoakimFindSkull_2":
			AddMoneyToCharacter(pchar, 500000);
			dialog.text = "Oh, oui, bien sûr ! Un demi-million de pièces de huit. Prends-les, tu les as méritées.";
			link.l1 = "C'est un plaisir de faire affaire avec vous. Difficile de croire qu'une si petite chose puisse valoir autant...";
			link.l1.go = "JoakimFindSkull_3";
		break;
		
		case "JoakimFindSkull_3":
			dialog.text = "Petite chose ? Tu ne sais pas de quoi tu parles. C'est... bah, ton esprit philistin ne peut guère saisir l'ampleur de l'incroyable pouvoir derrière ce crâne précieux. À vrai dire, je n'ai pas de temps à perdre de toute façon\nMerci, capitaine, pour ce que vous avez fait. Il est maintenant temps de dire adieu. Je dois partir.";
			link.l1 = "Adieu, Docteur Merriman. Peut-être, nous nous reverrons.";
			link.l1.go = "JoakimFindSkull_4";
		break;
		
		case "JoakimFindSkull_4":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload1", "none", "", "", "", -1);
			sld = characterFromId("Landlady");
			sld.Dialog.Filename = "Quest\HollandGambit\Joakim.c";
			sld.dialog.currentnode = "Landlady_2";
			SetFunctionTimerCondition("Caleuche_StartTotal", 0, 0, 180, false); // таймер на Калеуче
		break;
		
		case "JoakimSeekSkull_8":
			PlaySound("Voice\English\hambit\Joakim Merriman-01.wav");
			DelLandQuestMark(npchar);
			dialog.text = "Nous pouvons parler ici, capitaine. Je sais que vous êtes un associé intime d'Abigail Shneur, la fille de mon voisin Solomon. Elle a navigué sur votre navire vers son amant... mais cela importe peu en réalité.";
			link.l1 = "Que voulez-vous dire, Docteur ?";
			link.l1.go = "JoakimSeekSkull_9";
		break;
		
		case "JoakimSeekSkull_9":
			dialog.text = "Si vous connaissez Solomon, alors vous devez connaître son histoire de naufrage et de ses trésors perdus qu'il a cachés sur quelque île inconnue. Il a déjà raconté cette histoire à tout le monde à Willemstad.";
			link.l1 = "Pourquoi supposes-tu que j'ai à la fois entendu parler de cela et que je me soucie des malheurs du vieux Juif ?";
			link.l1.go = "JoakimSeekSkull_10";
		break;
		
		case "JoakimSeekSkull_10":
			dialog.text = "N'aimes-tu pas Salomon ? Je t'assure qu'il n'est qu'un vieil excentrique inoffensif. Oublie-le. Parlons affaires\nJ'ai eu plusieurs longues conversations avec Salomon. Tu ne peux même pas imaginer comment je me suis senti en découvrant que ce vieux Juif possède un ancien artefact inestimable que je recherche depuis des années ! Le vieux fou l'a caché avec son argent misérable sur une île et il ne peut même pas se souvenir de son emplacement\nJ'ai besoin de cet artefact. Apporte-le-moi et je te paierai un demi-million de pièces de huit.";
			link.l1 = "Un demi-million de pièces de huit ? Vous plaisantez, docteur. Je n'ai jamais vu tout cet argent réuni en un seul endroit de ma vie !";
			link.l1.go = "JoakimSeekSkull_11";
		break;
		
		case "JoakimSeekSkull_11":
			dialog.text = "Tu es encore un jeune homme. Alors, es-tu partant ? Tu me donnes le crâne et je te donnerai cinq cent mille pièces de huit en retour. En plus de ça, tu peux prendre l'argent de Salomon aussi. Selon les dires du vieil homme, il doit y avoir environ deux cent mille pesos... Donc sept cent mille pièces de huit en tout pour toi. Marché conclu, capitaine ?";
			link.l1 = "Foudroie-moi! Bien sûr que c'est un marché! Mais comment suis-je censé trouver cette île?";
			link.l1.go = "JoakimSeekSkull_12";
		break;
		
		case "JoakimSeekSkull_12":
			dialog.text = "Parle avec Abigail. Peut-être qu'elle se souvient de quelque chose. Demande à Solomon. Tu vois, si je savais où trouver l'île, je ne te demanderais pas ton aide.";
			link.l1 = "Je vois. Désolé pour ma question idiote. Maintenant, il faut trouver cette île. Assurez-vous simplement d'attendre avec mon paiement.";
			link.l1.go = "JoakimSeekSkull_13";
		break;
		
		case "JoakimSeekSkull_13":
			dialog.text = "Exactement. Je suis heureux que nous nous comprenions, capitaine. Bonne chance pour votre recherche. Vous pouvez toujours me trouver ici, chez moi.";
			link.l1 = "Je ne vous ferai pas attendre trop longtemps, Docteur Merriman. Adieu !";
			link.l1.go = "JoakimSeekSkull_14";
		break;
		
		case "JoakimSeekSkull_14":
			DialogExit();
			pchar.questTemp.HWIC.Self = "SeekAbiIsland";
			AddQuestRecord("Holl_Gambit", "3-55");
			LocatorReloadEnterDisable("SentJons_HouseF3", "reload3", true);//закроем комнату Аби
			npchar.quest.HWICHoll.Task = "true";
			LAi_SetOwnerType(npchar);
			NextDiag.CurrentNode = "First time";
			AddLandQuestMark(characterFromId("Merdok"), "questmarkmain");
			AddMapQuestMarkCity("SentJons", false);
		break;
		
		// калеуче
		case "caleuche":
			PlaySound("Voice\English\LSC\Chymiset-03.wav");
			dialog.text = "Ouiiiiii. Les pierres sacrificielles ruissellent du sang de mes ennemis ! Yum Cimil m'a accordé son pouvoir de commander les morts ! Avec ce pouvoir, je régnerai bientôt sur les vivants !";
			link.l1 = "Très mélodramatique, Merriman. Que comptes-tu faire avec ton armée de cadavres ambulants ? Joues-tu à César, essayant de conquérir le monde ?";
			link.l1.go = "caleuche_1";
			CreateLocationParticles("large_smoke", "goto", "goto37", 0.5, 0, 0, "");
		break;
		
		case "caleuche_1":
			dialog.text = "Silence, imbécile ! T'attends-tu à ce que je révèle mon plan secret dans un monologue ?! Eh bien, je ne vois aucune raison de ne pas le faire, tu ne survivras pas à cette rencontre ! Mes légions de morts-vivants occuperont d'abord toutes les cavernes obscures et les donjons des Caraïbes. Mes avant-postes seront situés dans chaque village, attendant mon signal. Et quand le moment viendra, mes cadavres ambulants sortiront et couvriront les terres des vivants !\nDommage que tu ne vivras pas pour le voir, toi, petite âme bien-pensante, toi qui te prends pour un héros ! Tu es entré dans mon sanctuaire - et tu n'en sortiras pas vivant ! Je mènerai mon armée des ténèbres !";
			link.l1 = "Écoute, mon gars, tu ne mènes rien d'autre que du vent et du flan, et le vent vient de quitter la ville.";
			link.l1.go = "caleuche_2";
		break;
		
		case "caleuche_2":
			PlaySound("Types\warrior04.wav");
			dialog.text = "Oh ho ho ! Tu oserais me défier, moi et mes serviteurs squelettiques ?! Alors vois ce que je suis vraiment, et tremble de peur !";
			link.l1 = "Viens en prendre.";
			link.l1.go = "caleuche_3";
		break;
		
		case "caleuche_3":
			npchar.model = "Meriman_2";
			Characters_RefreshModel(npchar);
			PlaySound("Ambient\Teno_inside\teleporter.wav");
			dialog.text = " ";
			link.l1 = "Ahhh! Doux Jésus !";
			link.l1.go = "caleuche_4";
		break;
		
		case "caleuche_4":
			PlaySound("Voice\English\hambit\Joakim Merriman-04.wav");
			dialog.text = "Comprends-tu maintenant qui se tient devant toi, vermisseau geignard ?! J'ai un compte à régler avec toi ! Yum Cimil lui-même me favorise ! Je dévorerai ton âme !";
			link.l1 = "D'accord, tête de mule. Allons danser.";
			link.l1.go = "caleuche_5";
		break;
		
		case "caleuche_5":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorRunToLocation(npchar, "goto", "goto37", "none", "", "", "Caleuche_MerrimanTeleport", -1);
			LAi_SetActorType(pchar);
			LAi_ActorTurnToLocator(pchar, "goto", "goto37");
			pchar.questTemp.Caleuche.Merriman_hide = "true";
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		//--> блок реагирования на попытку залезть в сундук
		case "Man_FackYou":
			dialog.text = LinkRandPhrase("Tu es un "+GetSexPhrase("voleur, monsieur ! Gardes, attrapez-le","voleuse, fille! Gardes, prenez-la")+"!!!","Regardez-moi ça ! Dès que j'ai eu le dos tourné, vous avez décidé de fouiller dans mon coffre ! Attrapez le voleur !!!","Gardes ! Vol ! Attrapez le voleur !!!");
			link.l1 = "Merde!";
			link.l1.go = "exit";
			LAi_group_Attack(NPChar, Pchar);
		break;
		//<-- блок реагирования на попытку залезть в сундук
	}
}
