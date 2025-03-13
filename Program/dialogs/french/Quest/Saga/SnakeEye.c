// шаман команчей Змеиный Глаз
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
			if (CheckAttribute(pchar, "questTemp.Tieyasal") && pchar.questTemp.Tieyasal == "calendar")
			{
				dialog.text = "Salutations, mon ami pâle.";
				link.l2 = "Je suis aussi heureux de te voir, frère peau-rouge. J'ai encore des affaires importantes pour toi.";
				link.l2.go = "calendar";
				break;
			}
			dialog.text = "Salutations, mon ami pâle.";
			link.l1 = "Je suis aussi content de te voir, Œil de Serpent.";
			link.l1.go = "exit";
			if (CheckAttribute(npchar, "quest.amulet") && CheckCharacterItem(pchar, pchar.questTemp.Saga.BaronReturn.Indian) && CheckCharacterItem(pchar, pchar.questTemp.Saga.BaronReturn.Amulet) && CheckCharacterItem(pchar, pchar.questTemp.Saga.BaronReturn.Obereg))
			{
				link.l2 = "Je t'ai apporté les amulettes que tu as demandées. Faisons un échange.";
				link.l2.go = "SnakeEye_potion";
			}
			if (CheckAttribute(pchar, "questTemp.LSC")) // был в LSC
			{
				if (CheckAttribute(npchar, "quest.LSC_hello") && CheckCharacterItem(pchar, "buben"))
				{
					link.l2 = "J'ai trouvé ton tambourin, Œil de Serpent. Jette un œil dessus.";
					link.l2.go = "LSC_buben";
				}
				if (CheckAttribute(npchar, "quest.LSC_tube") && CheckCharacterItem(pchar, "smoking_tube"))
				{
					link.l2 = "J'ai trouvé une pipe indienne intéressante, Œil de Serpent. Jette un œil.";
					link.l2.go = "LSC_tube";
				}
				if (!CheckAttribute(npchar, "quest.LSC_hello"))
				{
					link.l2 = "Bonjour, chaman. J'ai utilisé la statue et vécu un voyage incroyable. Tu avais complètement raison. J'ai trouvé le cimetière des navires, le capitaine blanc et même la cale avec les provisions !";
					link.l2.go = "LSC_hello";
				}
				if (CheckAttribute(npchar, "quest.LSC_hello") && pchar.questTemp.Saga.BaronReturn == "shamane")
				{
					link.l3 = "Snake Eye, j'ai besoin de ton aide.";
					link.l3.go = "Saga_nathaniel";
				}
			}		
			NextDiag.TempNode = "First time";
		break;
		
	//---------------------------------------- первая встреча------------------------------------------------
		case "SnakeEye":
			dialog.text = "Salutations, mon ami pâle.";
			link.l1 = "Bonjour, chaman. Pourquoi présumes-tu que je suis ton ami ?";
			link.l1.go = "SnakeEye_1";
		break;
		
		case "SnakeEye_1":
			dialog.text = "Je sais beaucoup de choses mais je ne sais pas toujours quoi exactement. Vous êtes venu ici avec un but. Le destin vous a conduit ici et je vous aide.";
			link.l1 = "Bon à savoir ! Je suis effectivement ici pour ton aide, mon ami peau-rouge. Je serai direct : que voulais-tu dire en parlant de Kukulcan à la femme de Hawk ?";
			link.l1.go = "SnakeEye_2";
		break;
		
		case "SnakeEye_2":
			dialog.text = " Même les poissons morts dérivent. Et l'homme vivant est mené par le destin d'un but à l'autre. Le but du capitaine enchaîné, poursuivi par de mauvaises gens dans la selve, était la statue de Kukulcan. S'il se sacrifiait, il pourrait être loin d'ici.";
			link.l1 = "Je n'ai rien compris. Quelle est l'histoire de la statue de votre dieu et comment Faucon a-t-il pu aller si loin à pied que personne ne peut le trouver même maintenant ?";
			link.l1.go = "SnakeEye_3";
		break;
		
		case "SnakeEye_3":
			dialog.text = "Si Kukulcan a mangé Hawk, alors il pourrait le recracher n'importe où. Peut-être même dans un autre monde. Kukulcan m'a mangé trois fois. Et chaque fois, j'étais dans des endroits différents. Il y a longtemps, je suis arrivé ici et j'ai décidé de ne plus prendre de risques. Je ne suis pas allé dans la gueule de Kukulcan et je ne sais pas où il recrache ses victimes.";
			link.l1 = "Jesus, cela dépasse mon entendement ! Me dis-tu que l'idole de pierre peut téléporter les gens loin d'ici ?";
			link.l1.go = "SnakeEye_4";
		break;
		
		case "SnakeEye_4":
			dialog.text = "Non seulement cela. Kukulcan ne gouverne pas seulement l'espace mais aussi le temps. Ou même plus. J'ai parlé au capitaine enchaîné de la statue d'or qui dévore les gens. Peut-être a-t-il décidé de prendre le risque en voyant que les poursuivants étaient proches...";
			link.l1 = "Attends, la statue est faite de pierre. Et tu parles d'une en or...";
			link.l1.go = "SnakeEye_5";
		break;
		
		case "SnakeEye_5":
			dialog.text = "A minuit, l'idole prend vie et devient or. En cet instant, l'esprit de Kukulcan y réside. Craignez de vous approcher de lui ou vous pourriez voir le lever du soleil dans un endroit différent. Même les étoiles peuvent changer de place dans le ciel. Vous rencontrerez ceux qui ne sont pas encore nés ou assisterez à la naissance de ceux qui sont morts depuis longtemps ou ne sont pas du tout nés.";
			link.l1 = "Quoi... des énigmes et encore des énigmes... Tu m'intrigues, Œil de Serpent. Tu as dit que tu as survécu à trois rencontres avec Kukulcan, le dieu en lequel tu crois. Alors pourquoi ne pas tenter ma chance avec l'idole du dieu en lequel je ne crois pas ?";
			link.l1.go = "SnakeEye_6";
		break;
		
		case "SnakeEye_6":
			dialog.text = "Dommage. Dommage que tu ne croies pas. Peut-être que Kukulcan lui-même t'a appelé et t'a fait quitter la terre de tes ancêtres. Mais tu ne l'entends pas encore. Tout arrive pour une bonne raison. Si tu décides de tenter ta chance, alors tu dois savoir que j'ai survécu à chaque fois uniquement grâce à de merveilleuses potions comanches.";
			link.l1 = "Comanche ? Est-ce une autre tribu ?";
			link.l1.go = "SnakeEye_7";
		break;
		
		case "SnakeEye_7":
			dialog.text = "C'est ainsi que les ennemis appellent mon peuple que je ne reverrai jamais. La potion restaure la force et l'endurance, et guérit aussi et vous sauve des poisons puissants. Vous avez besoin de plusieurs flacons mais il ne m'en reste que trois.\nIl y avait quatre flacons mais j'en ai perdu un dans un endroit étrange, cela ressemble à un cimetière de navires d'hommes blancs. C'est là que j'ai commencé mon voyage dans ce monde. Peut-être que Kukulcan a recraché le capitaine là-bas. Si c'est le cas, je ne l'envie pas.";
			link.l1 = "Quel est cet endroit ? Le cimetière des navires ?";
			link.l1.go = "SnakeEye_8";
		break;
		
		case "SnakeEye_8":
			dialog.text = "Endroit étrange... Il ne devrait pas exister mais il existe. Des gens qui tuent à cause de la couleur de peau y vivent. Ils gardent leurs provisions à l'intérieur d'un grand navire où Kukulcan m'a craché. Je ne suis pas allé dans sa cale qu'ils protègent des voleurs, ce ne sont pas des voisins de confiance. Si tu y vas - trouve une autre sortie, n'entre pas dans la cale ou des ennuis se produiront.\nLe Garçon Blanc t'aide à trouver une autre statue s'il est encore en vie. Donne-lui cette perle blanche. Il les aime.";
			link.l1 = "Hm. Ma tête tourne déjà et cela devient de plus en plus intéressant. Continue, frère peau-rouge.";
			link.l1.go = "SnakeEye_9";
		break;
		
		case "SnakeEye_9":
			Log_Info("You have received a white pearl");
			PlaySound("interface\important_item.wav");
			GiveItem2Character(pchar, "jewelry52");
			dialog.text = "Si vous trouvez le capitaine vivant, il pourrait être très malade. Je n'ai pas eu le temps de lui donner la potion. Cherchez mon tambourin là-bas. Je l'ai reçu de mon grand-père. Il y a beaucoup de choses dans le sac que j'ai perdu, mais je n'ai besoin que du tambourin. Il est difficile de parler aux esprits sans lui.";
			link.l1 = "Eh bien, cet endroit semble très intéressant ! Espérons que Hawk y ait été téléporté... Me donneras-tu ta potion ?";
			link.l1.go = "SnakeEye_10";
		break;
		
		case "SnakeEye_10":
			dialog.text = "Je te le donnerai. Mais tu me donneras trois amulettes locales en échange : "+XI_ConvertString(pchar.questTemp.Saga.BaronReturn.Indian)+", "+XI_ConvertString(pchar.questTemp.Saga.BaronReturn.Amulet)+" et "+XI_ConvertString(pchar.questTemp.Saga.BaronReturn.Obereg)+"Une fiole pour chaque amulette. C'est équitable. Reviens quand tu auras toutes les amulettes. Alors nous les échangerons. Ne pense pas que je suis avide. Ou peut-être reconsidéreras-tu cela en cherchant des amulettes.";
			link.l1 = "Je ne le penserai pas. Attends-moi, Oeil de Serpent, je reviendrai bientôt.";
			link.l1.go = "SnakeEye_11";
		break;
		
		case "SnakeEye_11":
			DialogExit();
			NextDiag.CurrentNode = "First time";
			npchar.quest.amulet = "true";
			AddQuestRecord("BaronReturn", "3");
			AddQuestUserData("BaronReturn", "sItem1", XI_ConvertString(pchar.questTemp.Saga.BaronReturn.Indian));
			AddQuestUserData("BaronReturn", "sItem2", XI_ConvertString(pchar.questTemp.Saga.BaronReturn.Amulet));
			AddQuestUserData("BaronReturn", "sItem3", XI_ConvertString(pchar.questTemp.Saga.BaronReturn.Obereg));
			sld = characterFromId("Danielle");
			sld.quest.talk = "SnakeEye";
			pchar.quest.BaronReturn_out.win_condition.l1 = "ExitFromLocation";
			pchar.quest.BaronReturn_out.win_condition.l1.location = pchar.location;
			pchar.quest.BaronReturn_out.function = "Saga_DannyTalk";
			pchar.questTemp.HelenDrinking.GiveAmulets = true;
			
			//if (GetCharacterIndex("Longway") != -1 && CheckPassengerInCharacter(pchar, "Longway") && CheckAttribute(pchar, "questTemp.PZ_Etap4_Start"))
			if (GetCharacterIndex("Longway") != -1 && CheckPassengerInCharacter(pchar, "Longway"))	// Временно так
			{
				// Квест "Путеводная звезда", начало 4 этапа
				PChar.quest.PZ_Etap4_Start.win_condition.l1 = "location";
				PChar.quest.PZ_Etap4_Start.win_condition.l1.location = "Shore9";
				PChar.quest.PZ_Etap4_Start.win_condition = "PZ_Etap4_Start";
				locations[FindLocation("Shore9")].DisableEncounters = true;
			}
		break;
		
		// даёт зелья - идем на телепортацию
		case "SnakeEye_potion":
			dialog.text = "Bien, mon ami. M'as-tu apporté des amulettes pour que tu puisses aller à Kukulcan ?";
			link.l1 = "Oui. Je suis prêt à faire le même voyage que Nathaniel, le capitaine enchaîné, a fait.";
			link.l1.go = "SnakeEye_potion_1";
		break;
		
		case "SnakeEye_potion_1":
			RemoveItems(pchar, pchar.questTemp.Saga.BaronReturn.Indian, 1);
			RemoveItems(pchar, pchar.questTemp.Saga.BaronReturn.Amulet, 1);
			RemoveItems(pchar, pchar.questTemp.Saga.BaronReturn.Obereg, 1);
			TakeNItems(pchar, "Ultimate_potion", 3);
			Log_Info("You have given amulets");
			Log_Info("You have received three versatile potions");
			PlaySound("interface\important_item.wav");
			dialog.text = "Prends ces potions. Souviens-toi que tu dois en boire une immédiatement après que Kukulcan t'ait recraché, sinon tu meurs ou tu restes très-très malade. Rappele-toi aussi de ne pas aller dans la cale où les visages pâles gardent leurs provisions. Il y a un autre moyen de quitter le navire. Deux moyens en fait. Trouve la femme rouge la première nuit, c'est très important. C'est tout ce que je peux te dire.";
			link.l1 = "Je m'en souviendrai, frère peau-rouge.";
			link.l1.go = "SnakeEye_potion_2";
		break;
		
		case "SnakeEye_potion_2":
			dialog.text = "Alors va. Touche Kukulcan à minuit et il te dévorera. J'appellerai les esprits pour te guider.";
			link.l1 = "Merci, Œil de Serpent. Ne t'inquiète pas pour moi, tout ira bien. Nous nous reverrons!";
			link.l1.go = "SnakeEye_potion_3";
		break;
		
		case "SnakeEye_potion_3":
			DialogExit();
			NextDiag.CurrentNode = "First time";
			pchar.questTemp.Saga.BaronReturn = "first_teleport";
			pchar.questTemp.Dolly = true; // телепорты работают!
			LAi_LocationDisableOfficersGen("Pearl_jungle_03", true); // не пускать офицеров в локу телепорта
			DeleteAttribute(npchar, "quest.amulet");
			AddQuestRecord("BaronReturn", "4");
			sld = characterFromId("Danielle");
			sld.quest.talk = "teleport";
			pchar.quest.BaronReturn_out1.win_condition.l1 = "ExitFromLocation";
			pchar.quest.BaronReturn_out1.win_condition.l1.location = pchar.location;
			pchar.quest.BaronReturn_out1.function = "Saga_DannyTalk";
			QuestPointerToLoc("Pearl_Jungle_02", "reload", "reload1_back");
			QuestPointerToLoc("Pearl_Jungle_03", "camera", "dolly");
		break;
		
		// пришёл из LSC
		case "LSC_hello":
			dialog.text = "Je suis ravi de te voir, mon ami. Comment es-tu revenu du cimetière des navires ?";
			link.l1 = "J'ai trouvé la statue de Kukulcan là-bas, comme tu me l'avais dit. Le Garçon Blanc m'a aidé - Ole Christiansen. La statue était coulée en mer, mais j'ai pu l'atteindre. Elle m'a téléporté dans un village indien sur la Dominique.";
			link.l1.go = "LSC_hello_1";
			npchar.quest.LSC_hello = "true";
		break;
		
		case "LSC_hello_1":
			dialog.text = "Monkitekuvri vous a-t-il rencontré là-bas ?";
			link.l1 = "Hm. Monkitekuvri? Qui est-ce ?";
			link.l1.go = "LSC_hello_2";
		break;
		
		case "LSC_hello_2":
			dialog.text = "Il est chef du village.";
			link.l1 = "Je n'ai pas demandé son nom. Peut-être était-il Monkitekuvri, peut-être pas.";
			link.l1.go = "LSC_hello_3";
		break;
		
		case "LSC_hello_3":
			dialog.text = "A-t-il une coiffe pompeuse faite de plumes d'oiseau sur la tête ?";
			link.l1 = "Bien sûr, il en avait. Beaucoup de plumes... On dirait qu'il a déplumé tous les perroquets de la jungle.";
			link.l1.go = "LSC_hello_4";
		break;
		
		case "LSC_hello_4":
			dialog.text = "Il est appelé Monkitekuvri. Ce ne sont pas des plumes de perroquet mais des plumes d'aigle. Ce couvre-chef est mon couvre-chef. Je l'ai offert à Monkitekuvri lorsque Kukulcan m'a recraché. Puis ils m'ont emmené à une autre statue...";
			link.l1 = "N'est-ce pas quelque chose ! Ils m'ont aussi 'sacrifié' à Kukulcan ! Et je me suis retrouvé ici, près de la première statue.";
			link.l1.go = "LSC_hello_5";
		break;
		
		case "LSC_hello_5":
			dialog.text = "Oui, mon ami pâle. Mon voyage s'est également terminé ici.";
			link.l1 = "Les idoles se téléportent en cercle... Mais quel est le but de cela? As-tu une idée, Œil-de-Serpent?";
			link.l1.go = "LSC_hello_6";
		break;
		
		case "LSC_hello_6":
			dialog.text = "Je suppose que les statues ne fonctionnent pas correctement. Pour le moment, elles déplacent les gens, mais elles devraient les amener à un seul endroit. Il y a quelque chose qui ne va pas avec elles.";
			link.l1 = "Qu'est-ce qui te fait penser ainsi ?";
			link.l1.go = "LSC_hello_7";
		break;
		
		case "LSC_hello_7":
			dialog.text = "Parce que la téléportation en cercle n'a aucun sens. Kukulcan doit emmener toutes les victimes à un seul endroit et ne pas les déplacer partout.";
			link.l1 = "Et où pourrait bien être cet endroit ?";
			link.l1.go = "LSC_hello_8";
		break;
		
		case "LSC_hello_8":
			dialog.text = "C'est un grand secret, frère blanc, même pour moi.";
			link.l1 = "Je vois. Très bien, au diable les idoles. Je ne m'approcherai plus jamais d'elles. J'ai trouvé le capitaine enchaîné, il n'est plus nécessaire de voyager à travers les portails.";
			link.l1.go = "LSC_hello_9";
			AddQuestRecord("BaronReturn", "12");
		break;
		
		case "LSC_hello_9":
			dialog.text = "Quand tu étais au cimetière de navires. As-tu trouvé mon tambourin là-bas ?";
			if (CheckCharacterItem(pchar, "buben"))
			{
				link.l1 = "Je pense que oui. Jette un œil.";
				link.l1.go = "LSC_buben";
			}
			else
			{
				link.l1 = "Non. Malheureusement, je ne l'ai pas trouvé. Mais je sais où se trouve l'île et je peux l'atteindre. Je chercherai votre tambourin.";
				link.l1.go = "LSC_hello_10";
			}
		break;
		
		case "LSC_hello_10":
			dialog.text = "Cherche-le, mon pâle ami. Je te le demande instamment. Sans mon tambourin, je n'entends pas bien les esprits.";
			link.l1 = "Très bien, Œil de Serpent. À plus tard !";
			link.l1.go = "exit";
		break;
		
		case "LSC_buben":
			RemoveItems(pchar, "buben", 1);
			PlaySound("interface\important_item.wav");
			dialog.text = "C'est mon tambourin. Merci, mon ami pâle. Je peux te récompenser. Je te présente cette arme, que ton peuple n'aura pas avant longtemps. Cette arme est l'arme des visages pâles de mon temps.";
			link.l1 = "Intéressant ! Montre-le-moi, ami peau-rouge...";
			link.l1.go = "LSC_buben_1";
		break;
		
		case "LSC_buben_1":
			GiveItem2Character(pchar, "pistol7");
			Log_Info("You have received a Colt revolver");
			PlaySound("interface\important_item.wav");
			TakeNItems(pchar, "shotgun_cartridge", 3);
			TakeNItems(pchar, "GunCap_colt", 3);
			dialog.text = "Prends-le. Il n'y a que trois charges dedans, le reste, je l'ai utilisé. Mais peut-être que tu apprendras à en fabriquer. J'ai perdu quelques dizaines de pièces pour les charges au cimetière des navires, tu peux les y trouver.";
			link.l1 = "Oho! C'est un pistolet! Je n'ai jamais vu quelque chose de pareil auparavant... quelle étrange machine ? Un mécanisme rotatif... cinq charges ! Magnifique !";
			link.l1.go = "LSC_buben_2";
		break;
		
		case "LSC_buben_2":
			dialog.text = "Ça s'appelle un revolver Colt. Aucun autre pistolet comme celui-ci à ton époque. Facile à utiliser, relève le chien et appuie sur la détente. Ça tire bien.";
			link.l1 = "Merci ! Merci, Œil de Serpent ! Ce sera une belle surprise pour mes ennemis... Dommage qu'il n'y ait que trois charges...";
			link.l1.go = "LSC_buben_3";
		break;
		
		case "LSC_buben_3":
			dialog.text = "Essaie d'apprendre à fabriquer des charges pour revolver Colt. Alors tu seras un grand guerrier de ton temps. Ah, mon frère pâle, j'ai oublié de te demander de trouver ma pipe au cimetière des navires. C'était une très jolie pipe.";
			if (CheckCharacterItem(pchar, "smoking_tube"))
			{
				link.l1 = "Ha ! Et je me demandais à qui pouvait bien appartenir cette pipe peinte ? Jette un œil.";
				link.l1.go = "LSC_tube";
			}
			else
			{
				link.l1 = "Très bien. Je chercherai aussi ta pipe. À bientôt !";
				link.l1.go = "exit";
			}
			npchar.quest.LSC_tube = "true";
		break;
		
		case "LSC_tube":
			RemoveItems(pchar, "smoking_tube", 1);
			PlaySound("interface\important_item.wav");
			dialog.text = "C'est ma pipe, mon frère. Je suis content que tu l'aies trouvée. Et je peux te donner un autre cadeau pour cela. C'est un livre astucieux des visages pâles de mon temps. Je ne peux pas le comprendre. Essaie de trouver un homme astucieux qui peut lire et comprendre ce livre.";
			link.l1 = "Merci, Œil de Serpent. Je pense que je connais quelqu'un qui sera intéressé par cela.";
			link.l1.go = "LSC_tube_1";
		break;
		
		case "LSC_tube_1":
			GiveItem2Character(pchar, "chemistry");
			Log_Info("You have received a Lavoisier's chemistry textbook");
			PlaySound("interface\important_item.wav");
			dialog.text = "Donne-lui ça, frère blanc. Ce livre contient de grands secrets de la sagesse des visages pâles.";
			link.l1 = "Bien. À bientôt, Oeil de Serpent !";
			link.l1.go = "exit";
		break;
		
		// лечение Натаниэля
		case "Saga_nathaniel":
			dialog.text = "Je t'écoute, frère au visage pâle.";
			link.l1 = "J'ai amené le capitaine enchaîné, que je cherchais au cimetière des navires, avec moi. Il est très malade. Je sais que seul vous pouvez le soigner...";
			link.l1.go = "Saga_nathaniel_1";
		break;
		
		case "Saga_nathaniel_1":
			dialog.text = "Kukulcan a consumé sa santé. Je pense que je peux l'aider à guérir. Mais cela prendra pas moins d'une pleine lune. Kukulcan a dévoré le capitaine il y a longtemps et la maladie s'est profondément répandue en lui.";
			link.l1 = "S'il vous plaît, guérissez-le, chaman ! Je vous apporterai tout ce dont vous avez besoin !";
			link.l1.go = "Saga_nathaniel_2";
		break;
		
		case "Saga_nathaniel_2":
			dialog.text = "Je vais essayer, frère blanc. Tu n'as rien à m'apporter. J'ai tout ce qu'il me faut. Le temps renforce la maladie mais le capitaine enchaîné sera de nouveau en bonne santé dans une lune.";
			link.l1 = "Merci, frère peau-rouge. Tu es de nouveau mon sauveur.";
			link.l1.go = "Saga_nathaniel_3";
		break;
		
		case "Saga_nathaniel_3":
			dialog.text = "Laisse le capitaine enchaîné à ma cabane, frère blanc, et marche sans souci. Emmène aussi sa femme, personne ne peut voir mes rites.";
			link.l1 = "Très bien, Œil-de-serpent. Je prendrai Danielle avec moi. À bientôt !";
			link.l1.go = "Saga_nathaniel_4";
		break;
		
		case "Saga_nathaniel_4":
			DialogExit();
			pchar.questTemp.Saga.BaronReturn = "treatment";
			sld = characterFromId("Nathaniel");
			RemovePassenger(Pchar, sld);
			LAi_SetStayType(sld);
			sld.location = "none";
			pchar.quest.Saga_NatanTreatment1.win_condition.l1 = "ExitFromLocation";
			pchar.quest.Saga_NatanTreatment1.win_condition.l1.location = pchar.location;
			pchar.quest.Saga_NatanTreatment1.function = "Saga_NatanTreatment";
		break;
		
		case "calendar":
			dialog.text = "Je t'écoute, mon ami.";
			link.l1 = "Tu te souviens de notre conversation sur les statues de Kukulcan ? Tu as dit 'elles devraient amener les gens à un endroit spécial'.";
			link.l1.go = "calendar_1";
		break;
		
		case "calendar_1":
			dialog.text = "Je me souviens, capitaine blanc.";
			link.l1 = "Je sais où ces statues ont dû déplacer les gens qui ont été dévorés par Kukulcan.";
			link.l1.go = "calendar_2";
		break;
		
		case "calendar_2":
			dialog.text = "Où?";
			link.l1 = "À l'ancienne cité maya de Tayasal. Elle est située au cœur de la jungle de Main.";
			link.l1.go = "calendar_3";
		break;
		
		case "calendar_3":
			dialog.text = "Très intéressant. Comment le savez-vous ?";
			link.l1 = "C'est une longue histoire, Œil de Serpent. Je comprends aussi comment tu es arrivé ici. Tu n'es même pas encore né, n'est-ce pas ?";
			link.l1.go = "calendar_4";
		break;
		
		case "calendar_4":
			dialog.text = "  Même mon père n'est pas né à votre époque. Mais moi, je vis à votre époque et c'est un grand mystère. ";
			link.l1 = "C'est en fait explicable. Un prêtre Itza nommé Kanek, qui vit à Tayasal, a invoqué Kukulcan pour qu'il naisse en tant que mortel dans ce monde et absorbe la sagesse de la race blanche. Il a également créé un trou temporel qui a téléporté quelques hommes du futur dans notre temps...";
			link.l1.go = "calendar_5";
		break;
		
		case "calendar_5":
			dialog.text = "Permettre à Kukulcan d'absorber la sagesse des gens du futur ?";
			link.l1 = "Oui. Et Kukulcan prévoit de retourner dans le passé pour transmettre le savoir au peuple Maya qui est mort il y a longtemps. L'histoire sera changée et les Mayas régneront sur l'Amérique et peut-être même au-delà...";
			link.l1.go = "calendar_6";
		break;
		
		case "calendar_6":
			dialog.text = "";
			link.l1 = "Mais quelque chose est arrivé aux portails et ils ont commencé à téléporter les gens en cercle au lieu de Tayasal. Et c'est pourquoi je suis ici, j'ai besoin de ton conseil, Œil de Serpent.";
			link.l1.go = "calendar_7";
		break;
		
		case "calendar_7":
			dialog.text = "Pourquoi moi, capitaine blanc?";
			link.l1 = "Parce que tu as été dévoré par Kukulcan. Et parce que la statue de Kukulcan près de ton village a une étrange marque sur cette carte, qui est fortement liée aux rites de Kanek.";
			link.l1.go = "calendar_8";
		break;
		
		case "calendar_8":
			dialog.text = "Montre-moi cette carte ?";
			link.l1 = "Tiens, regarde...";
			link.l1.go = "calendar_9";
		break;
		
		case "calendar_9":
			RemoveItems(pchar, "skinmap", 1);
			dialog.text = "(regardant) Ce panneau rond, oui ? Et qu'est-ce que cela signifie ?";
			link.l1 = "Je ne sais pas, chaman. Je sais seulement qu'une seule des trois statues de Kukulcan porte cette marque. Et que la statue avec la marque est la vôtre. J'en conclus que votre statue est spéciale. Avez-vous des idées?";
			link.l1.go = "calendar_10";
		break;
		
		case "calendar_10":
			dialog.text = "Donne-moi jusqu'à demain matin, frère blanc. Laisse-moi cette carte en cuir. J'ai besoin de consulter les esprits. Reviens demain.";
			link.l1 = "D'accord, frère peau-rouge. Je serai là demain. Merci de m'aider.";
			link.l1.go = "calendar_11";
		break;
		
		case "calendar_11":
			DialogExit();
			SetFunctionTimerCondition("Tieyasal_CalendarThink", 0, 0, 1, false);
			pchar.questTemp.Tieyasal = "calendar_think";
			NextDiag.CurrentNode = "calendar_wait";
		break;
		
		case "calendar_wait":
			dialog.text = "Viens plus tard, frère blanc. Ne me dérange pas maintenant.";
			link.l1 = "Bien sûr, chaman...";
			link.l1.go = "exit";
			NextDiag.TempNode = "calendar_wait";
		break;
		
		case "calendar_12":
			dialog.text = "J'ai quelque chose à te dire, frère blanc.";
			link.l1 = "As-tu trouvé quelque chose? Ou as-tu une idée?";
			link.l1.go = "calendar_13";
		break;
		
		case "calendar_13":
			dialog.text = "Les esprits ancestraux m'ont donné une vision et je suis allé à Kukulcan avec la carte. J'ai cherché et trouvé. Cela doit être ce que tu cherches, frère blanc.";
			link.l1 = "Qu'as-tu trouvé ?";
			link.l1.go = "calendar_14";
		break;
		
		case "calendar_14":
			dialog.text = "La statue de Kukulcan a deux pinces en fer et une cavité. La cavité a une forme ronde et lisse. Elle s'oriente vers l'objet rond et plat de votre carte en cuir.";
			link.l1 = "Qu'est-ce que c'est ?";
			link.l1.go = "calendar_15";
		break;
		
		case "calendar_15":
			dialog.text = "Je ne sais pas. Je sais seulement qu'il est rond, plat, de la taille d'une petite citrouille et peut-être épais comme un doigt. Vous pouvez aller voir les encoches et les pinces par vous-même. La pince doit le maintenir.";
			link.l1 = "As-tu une idée ? Ou une supposition de ce que cela pourrait être ?";
			link.l1.go = "calendar_16";
		break;
		
		case "calendar_16":
			dialog.text = "La pierre a une trace de feu. Je sais ce qui lui est arrivé. Une flamme du ciel l'a frappée.";
			link.l1 = "Foudre? Est-ce que la foudre l'a frappé?";
			link.l1.go = "calendar_17";
		break;
		
		case "calendar_17":
			dialog.text = "J'en suis sûr. J'ai demandé à Miskito à propos de cet idole. Un guerrier a dit qu'il y a longtemps, quelques jolies choses peintes étaient vues à la statue. Très semblables à des pierres. Il m'a dit que c'étaient de très jolies pierres rouges. Un homme blanc du village blanc les a achetées.";
			link.l1 = "Hm. Si je comprends bien, il semble que la foudre ait frappé ce 'quelque chose' rond, l'ait brisé en morceaux et ensuite ces morceaux ont été vendus à un type blanc ?";
			link.l1.go = "calendar_18";
		break;
		
		case "calendar_18":
			dialog.text = "Il semble bien.";
			link.l1 = "Et qui était cet homme blanc ? Ton guerrier te l'a-t-il dit ?";
			link.l1.go = "calendar_19";
		break;
		
		case "calendar_19":
			dialog.text = "Il me l'a dit. Il était un grand ami des Miskitos et il vit dans le village de Blueweld. Son nom est Diable de la Forêt. Je le connais, tu dois le connaître aussi.";
			link.l1 = "Jan Svenson ? Attends une seconde... des rochers peints en rouge, dis-tu ? On dirait que j'ai eu beaucoup de chance. Regarde ici, chaman, regarde ces rochers rouges que j'ai ! Le Diable de la Forêt me les a offerts.";
			link.l1.go = "calendar_20";
		break;
		
		case "calendar_20":
			Log_Info("You have given ornamental pattern fragments");
			RemoveItems(pchar, "splinter_js", 1);
			RemoveItems(pchar, "splinter_nh", 1);
			RemoveItems(pchar, "splinter_mt", 1);
			RemoveItems(pchar, "splinter_zm", 1);
			RemoveItems(pchar, "splinter_jb", 1);
			dialog.text = "Ca doit être eux. Cinq rochers. Regarde, frère blanc. Si tu les places ainsi... (les assemblant)";
			link.l1 = "...";
			link.l1.go = "calendar_21";
		break;
		
		case "calendar_21":
			dialog.text = "... alors nous avons un objet rond. Regarde ! Ils correspondent. C'était un seul objet auparavant.";
			link.l1 = "Merde ! Et ces choses ont été dans ma poche si longtemps... Écoute, chaman, si je mets les éclats dans l'encoche...";
			link.l1.go = "calendar_22";
		break;
		
		case "calendar_22":
			dialog.text = "Kukulcan crachera la victime à l'ancienne cité indienne comme vous l'avez dit.";
			link.l1 = "Ce serait formidable ! Je dois m'y rendre ! Penses-tu que l'ornement fonctionnera, s'il a été brisé en éclats ?";
			link.l1.go = "calendar_23";
		break;
		
		case "calendar_23":
			dialog.text = "Je pense que nous devons les rassembler puis placer l'ornement dans la niche.";
			link.l1 = "Les réunir? Mais comment pouvons-nous les rassembler ?";
			link.l1.go = "calendar_24";
		break;
		
		case "calendar_24":
			dialog.text = "Laisse cela à moi et aux esprits des ancêtres, frère blanc. Ce ne sont pas de simples pierres. C'est un objet miracle. Reviens dans trois nuits, frère blanc. J'invoque les esprits, la sagesse et l'habileté des vivants et j'essaie d'unir les éclats.";
			link.l1 = "Incroyable... Comment pourrai-je jamais te remercier, Oeil de Serpent ?";
			link.l1.go = "calendar_25";
		break;
		
		case "calendar_25":
			dialog.text = "Remercie-moi plus tard, frère blanc. Va maintenant. Reviens dans trois nuits.";
			link.l1 = "D'accord. J'espère que vous réussirez...";
			link.l1.go = "calendar_26";
		break;
		
		case "calendar_26":
			DialogExit();
			SetFunctionTimerCondition("Tieyasal_CalendarDone", 0, 0, 3, false);
			NextDiag.CurrentNode = "calendar_wait";
		break;
		
		case "calendar_28":
			dialog.text = "Je peux te rendre heureux, frère blanc.";
			link.l1 = "As-tu pu unir les éclats ?";
			link.l1.go = "calendar_29";
		break;
		
		case "calendar_29":
			dialog.text = "Oui. Ce n'était pas facile et il y a des cicatrices laissées sur le calendrier, mais c'est terminé maintenant.";
			link.l1 = "Calendrier ? Pourquoi l'as-tu appelé ainsi ?";
			link.l1.go = "calendar_30";
		break;
		
		case "calendar_30":
			dialog.text = "Parce que cette chose ronde est un calendrier. Je l'ai étudiée attentivement. Il y a un décompte du temps dessus. Les Indiens de l'ancienne cité comptent les nuits, les lunes, les années et les âges.";
			link.l1 = "Incroyable... Cependant, en pensant à ce que les prêtres mayas sont capables de faire - la création de ce calendrier ne semble pas être quelque chose de spécial.";
			link.l1.go = "calendar_31";
		break;
		
		case "calendar_31":
			GiveItem2Character(pchar, "calendar_maya");
			sld = ItemsFromID("calendar_maya");
			sld.shown = "0";
			Log_Info("You have received a Maya calendar");
			dialog.text = "Prends-le, capitaine blanc. Mets-le dans le renfoncement sur la statue. Alors peut-être qu'il te recrachera dans la cité indienne.";
			link.l1 = "Comment puis-je te rendre la pareille, Œil de Serpent ?";
			link.l1.go = "calendar_32";
		break;
		
		case "calendar_32":
			dialog.text = "Dis 'Merci'. Les dieux te guident sur ton chemin même si tu ne le vois pas. Les blancs disent - destin. Kukulcan t'a appelé, les dieux te guident. Va maintenant. Fais ton travail et laisse les bons esprits te guider.";
			link.l1 = "Merci, Oeil de Serpent ! Je ne t'oublierai jamais.";
			link.l1.go = "calendar_33";
		break;
		
		case "calendar_33":
			TakeNItems(pchar, "Ultimate_potion", 4);
			Log_Info("You have received four versatile potions");
			PlaySound("interface\important_item.wav");
			dialog.text = "Attendez. Nous avons presque oublié la chose la plus importante. Kukulcan dévore l'homme et absorbe sa vie. Je vous ai préparé des potions. Des potions comanches. Je vous les donne. J'ai fait quatre fioles, vous pouvez donc emmener trois compagnons loyaux et courageux avec vous.";
			link.l1 = "Tu as fait tant pour moi, frère peau-rouge...";
			link.l1.go = "calendar_34";
		break;
		
		case "calendar_34":
			dialog.text = "Frère n'est pas juste un mot pour les Indiens de la tribu Comanche. Quand tu reviendras de la ville de Kukulcan, visite notre village. Nous cuisinerons beaucoup, beaucoup de saraiaka. Je serai ravi de te voir.";
			link.l1 = "Bien sûr, frère peau-rouge ! Je viendrai certainement te rendre visite !";
			link.l1.go = "calendar_35";
		break;
		
		case "calendar_35":
			DialogExit();
			pchar.questTemp.Tieyasal = "calendar_place";
			NextDiag.CurrentNode = "First time";
			AddQuestRecord("Tieyasal", "17");
			sld = ItemsFromID("skinmap");
			sld.price = 100; // кожаную карту можно выкладывать 270912 
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}
