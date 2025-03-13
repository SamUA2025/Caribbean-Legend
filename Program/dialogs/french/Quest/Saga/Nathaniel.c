// Натаниэль Хоук - пиратский барон Марун-Тауна
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
			dialog.text = "Vous désirez quelque chose ?";
			link.l1 = "Non, ce n'est rien.";
			link.l1.go = "exit";			
			NextDiag.TempNode = "First time";
		break;
		
		case "diffindoor":
			PlaySound("Voice\English\saga\Nataniel Hawk-02.wav");
			dialog.text = "Ah... qui es-tu, diable ?.. Khe... (toux sévère avec enrouement) Maudite faiblesse...";
			link.l1 = "Salutations, Nathaniel. Vous êtes Nathaniel Hawk, n'est-ce pas ?";
			link.l1.go = "diffindoor_1";
		break;
		
		case "diffindoor_1":
			dialog.text = "Oui, c'est moi, si je peux encore me nommer ainsi. J'étais autrefois Nathaniel Hawk, mais maintenant je ne suis qu'un sac de merde au regard triste. Que cette statue aille se faire pendre ! Elle a aspiré toute vie de moi.";
			link.l1 = "Je connais ce sentiment...";
			link.l1.go = "diffindoor_2";
		break;
		
		case "diffindoor_2":
			dialog.text = "Comment as-tu pu, garçon, si tu ne réalises même pas de quoi je parle ? A-kha... Sais-tu ce que ça fait de se transformer en un vieillard à moitié mort alors que j'étais juste en bonne santé et fort il y a une minute ?\nJ'ai vu beaucoup de choses, je pensais que ce temple indien ancien que j'ai visité dans ma jeunesse aurait tué ma capacité à être surpris, mais ça... pourquoi ne l'ai-je pas vu venir ! Cette satanée statue ressemblait au vieux idole qui ouvrait la porte du temple !";
			link.l1 = "D'accord, Nathan, parlons. Permettez-moi de me présenter, je suis "+GetFullName(pchar)+" . D'abord, je vous comprends très bien car je suis venu ici de la même manière que vous - en utilisant le portail Kukulcan.";
			link.l1.go = "diffindoor_3";
		break;
		
		case "diffindoor_3":
			dialog.text = "Vraiment ?! Alors pourquoi as-tu l'air en pleine forme ? Ou bien ce... Kukulcan n'a-t-il blessé que moi ?";
			link.l1 = "Snake Eye, le chaman Miskito, qui t'a aidé à t'échapper, m'a donné une potion très puissante. Je l'ai bue dès que je me suis réveillé à San Augustine. Elle m'a complètement guéri. Je suis sûr que Snake Eye peut t'aider aussi. Nous devons juste t'amener à lui.";
			link.l1.go = "diffindoor_4";
		break;
		
		case "diffindoor_4":
			dialog.text = "Ah, cet Indien ! Une potion ? Et pourquoi ne m'en a-t-il pas donné une aussi ?";
			link.l1 = "Il a dit qu'il n'y avait pas de temps. Tu étais poursuivi et la seule chose qu'il pouvait faire était de te montrer le chemin de la fuite - le portail.";
			link.l1.go = "diffindoor_5";
		break;
		
		case "diffindoor_5":
			PlaySound("Voice\English\saga\Nataniel Hawk-01.wav");
			dialog.text = "Évasion ? Oh... Ne vois-tu pas mon état actuel ? Je ne peux même pas tenir un sabre. Comment peux-tu appeler ça une évasion ? Dieu merci, il y a encore de bonnes âmes en ce monde. Ole, que Dieu le bénisse... Connais-tu Ole ?";
			link.l1 = "Oui. En fait, c'est lui qui m'a parlé de vous, il m'a raconté comment il vous nourrissait de rats et comment vous continuez à boire, bouteille après bouteille...";
			link.l1.go = "diffindoor_6";
		break;
		
		case "diffindoor_6":
			dialog.text = "Je mourrai plus vite qu'une chandelle allumée si je ne bois pas de rhum. C'est la seule chose qui me maintient en vie. Rhum...";
			link.l1 = "Tu te sens toujours aussi mal ? Comme après la téléportation ?";
			link.l1.go = "diffindoor_7";
		break;
		
		case "diffindoor_7":
			dialog.text = "Eh bien, je ne me sens pas tout à fait pareil... Mais pas vraiment mieux non plus. Mon vieux, dis-moi pourquoi tu avais besoin de voir le vieux Nathan ? Pourquoi diable es-tu venu ici, sur cette vieille épave pourrie ? Pour bavarder avec moi ?";
			link.l1 = "En fait, oui. Vous n'allez pas me croire, mais la raison pour laquelle j'ai traversé toutes ces péripéties avec la téléportation était de vous trouver. Je travaille pour les Frères de la Côte et je représente Jan Svenson.";
			link.l1.go = "diffindoor_8";
		break;
		
		case "diffindoor_8":
			dialog.text = "Merde... le Diable de la Forêt ? Argh... Es-tu venu ici pour m'achever ? En fait, non ? Tu es trop bavard pour un assassin. Je t'en prie - ne me torture pas. Si on t'a ordonné de me soutirer quelque chose - je te dirai tout moi-même, je n'ai rien à cacher.";
			link.l1 = "Que voulez-vous dire ? A-ah, je vois. Vous, tout comme Danielle, pensez que c'est Svenson qui a organisé cette embuscade contre vous dans la selva. Je peux vous assurer que Jan n'en est pas responsable. Au contraire, il est de votre côté et s'inquiète beaucoup de votre disparition.";
			link.l1.go = "diffindoor_9";
		break;
		
		case "diffindoor_9":
			dialog.text = "Vraiment? Je suis foutrement content d'entendre cela. Et j'y pensais déjà... mais qui a fait ça? Mon détachement a été détruit en quelques minutes. Ils nous attendaient. Ils avaient même des canons de navire! Ils ont fauché la moitié de mes hommes avec de la mitraille et ensuite ils nous ont achevés avec leurs mousquets...";
			link.l1 = "Pour être honnête, je ne connais pas les détails, mais je suis sûr que Jackman est derrière tout cela. Trop de coïncidences, d'abord Blaze, puis toi... Jackman veut s'emparer du pouvoir et élimine tous ceux qui se dressent sur son chemin. Il règne maintenant sur Maroon Town à ta place.";
			link.l1.go = "diffindoor_10";
		break;
		
		case "diffindoor_10":
			dialog.text = "Jackman ? Salaud ! Eh...la Confrérie s'est divisée ces dernières années, tout était différent avant. Zachariah est devenu fou avec ses affaires religieuses, Tyrex n'en a rien à foutre de quoi que ce soit et Barbazon ne s'intéresse qu'aux doublons. C'était tout autre il y a vingt ans...";
			link.l1 = "Comment vous ont-ils capturé ? Racontez-moi en plus.";
			link.l1.go = "diffindoor_11";
		break;
		
		case "diffindoor_11":
			dialog.text = "Il n'y a rien d'intéressant à raconter ! Comme je l'ai dit, ces bandits avaient tout planifié. Ils agissaient proprement, étaient coordonnés et suivaient clairement les ordres de quelqu'un. Ils auraient pu me tuer cent fois, mais ils ne l'ont pas fait. Ils me voulaient vivant. Ils m'ont emmené dans une mine abandonnée et m'ont enfermé dans l'une des cabanes. 'Jusqu'à ce que le chef arrive', disaient-ils. Je pensais que Svenson était le chef, mais il semble que Jackman soit aux commandes. Je ne sais pas ce qu'il aurait pu vouloir de moi, mais je suis sûr que je n'aurais pas vécu longtemps après avoir discuté avec lui.";
			link.l1 = "Je n'en doute pas. Svenson est sûr que Jackman a tué Blaze Sharp... Comment avez-vous réussi à vous échapper ?";
			link.l1.go = "diffindoor_12";
		break;
		
		case "diffindoor_12":
			dialog.text = "Ce Serpent Indien Œil-de-Serpent a réussi d'une manière ou d'une autre à se faufiler dans la mine. Autant que je comprenne, les Miskitos n'aiment pas les bandits. Quoi qu'il en soit, Œil-de-Serpent a organisé mon évasion pour une raison quelconque. Il a creusé un tunnel jusqu'à moi, est entré, a coupé mes cordes et nous nous sommes enfuis dans la jungle.\nIl voulait m'emmener dans son village, chez les Miskitos. Mais on dirait que Jackman me voulait vraiment, car une grande chasse a été organisée. Ils étaient proches de nos talons. Œil-de-Serpent a fait de son mieux pour les tromper, mais ils ont toujours réussi à retrouver notre piste. Ils avaient de bons éclaireurs, sans aucun doute.\nNous étions proches du village d'Œil-de-Serpent quand ils nous ont finalement trouvés. À ce moment-là, mon estomac était vide depuis deux jours et j'étais complètement épuisé car j'avais aussi gravement endommagé ma jambe. Il était minuit et je me souviens encore à quel point l'étoile au-dessus de la statue était brillante... Œil-de-Serpent a dit que ma seule chance était d'atteindre l'idole et de la toucher.\nJe pensais que cet homme était fou, mais vous savez ce qu'on dit sur attraper des brins de paille. J'ai boité jusqu'à la statue, je l'ai touchée... et puis des choses folles ont commencé à se produire !";
			link.l1 = "Tu n'as pas besoin de continuer, je sais ce qui s'est passé ensuite.";
			link.l1.go = "diffindoor_13";
		break;
		
		case "diffindoor_13":
			dialog.text = "Je m'étais retrouvé dans la cale humide d'un navire naufragé. J'étais à moitié mort. Je ne pouvais pas marcher, seulement ramper. Chaque minute, mon état empirait. Ole est arrivé juste à temps. Il m'a versé un mélange caribéen qui avait un goût de chiottes, un mélange d'antidote et d'essence de guérison. Puis il m'a donné du rhum.\nJe me suis senti mieux immédiatement. Ensuite, il a trouvé et utilisé un vieux tronc pour me déplacer ici. Je vis ici depuis un certain temps maintenant, je ne sais pas exactement combien de temps, j'ai perdu la notion du temps.";
			link.l1 = "Tout ira bien, Nathan. Svenson et moi avons de grands projets et votre rôle y est très important. Vous devez retourner à votre poste à Maroon Town et nous nous occuperons de cette vermine de Jackman.";
			link.l1.go = "diffindoor_14";
		break;
		
		case "diffindoor_14":
			dialog.text = "Maroon Town? Et comment exactement imagines-tu que cela va fonctionner? Regarde-moi, je suis une épave imbibée de rhum! Inutile... Non, les années de mon autorité sur Maroon Town sont révolues à jamais. Je suis piégé dans ce fichu cimetière de navires. Combien de temps vais-je tenir? Un mois, deux, un an?\nEt puis je finirai par m'allonger sur ces planches pourries et Ole jettera ce qui reste de Nathaniel Hawk à la mer. Le pire, c'est que je ne reverrai plus mon Dannie. Eh, c'est fini, l'ami.";
			link.l1 = "Ne sois pas si pessimiste. Je vais te sortir d'ici.";
			link.l1.go = "diffindoor_15";
		break;
		
		case "diffindoor_15":
			dialog.text = "Comment allez-vous me sortir d'ici ? Et comment allons-nous quitter cet endroit ? Il n'y a pas de navires. Voulez-vous construire un radeau ?";
			link.l1 = "Non. Je quitterai cet endroit de la même manière que je suis venu. Je sais où se trouve la statue... enfin, à peu près. Je la trouverai et ensuite je reviendrai pour toi et Shark Dodson. Nous te conduirons ensuite à Snake Eye. Il te soignera.";
			link.l1.go = "diffindoor_16";
		break;
		
		case "diffindoor_16":
			dialog.text = "Qu'as-tu dit? Shark Dodson? Est-ce que Steve est aussi ici? Quel endroit étrange...";
			link.l1 = "Oui, il est ici. Il est le 'gouverneur' de cette île, pour ainsi dire. Je lui ai parlé de vous, mais il ne sait rien.";
			link.l1.go = "diffindoor_17";
		break;
		
		case "diffindoor_17":
			dialog.text = " Et il ne devrait pas. Je ne veux pas qu'il me voie dans cet état. Vous avez dit que le chaman me guérira... J'ai du mal à le croire. Vous avez mentionné Dannie aussi... L'avez-vous vue ? ";
			link.l1 = "Oui. Elle m'a trouvée elle-même à Blueweld. Elle a écouté ma conversation avec Svenson et compris que Jan n'avait pas l'intention de te tuer et qu'il travaille contre Jackman. Elle a rejoint mon navire en tant qu'officier pour m'aider à te retrouver.";
			link.l1.go = "diffindoor_18";
		break;
		
		case "diffindoor_18":
			dialog.text = "Eh, ma chère Dannie ! Elle n'a pas changé... aussi imprudente que dans sa jeunesse... Tu ne peux même pas imaginer à quel point je veux la voir et la serrer dans mes bras maintenant ! J'ai beaucoup réfléchi en restant allongé ici. Tu vois, camarade, on commence à voir les choses sous un autre jour quand on est proche de la mort. J'ai passé si peu de temps avec ma femme!\nLes raids en mer, les affaires officielles des Frères, gouverner Maroon Town. Et elle m'a toujours soutenu en tout : restée seule pendant des semaines, se querellant avec d'autres pirates pendant mon absence, commandant notre navire... Ma Dannie est la meilleure femme du monde ! Et moi... j'aurais dû lui dire plus souvent que je l'aime!\nJe me souviens du jour où nous avons décidé d'être ensemble! En fait, c'était le jour où j'ai rencontré et combattu pour la première fois des choses surnaturelles. Tout cela est arrivé à cause de cet idole maudit qui ressemblait exactement aux statues. Cela ne te dérange pas d'entendre une histoire ? Elle est assez intéressante.";
			link.l1 = "Pas du tout ! Dis-moi !";
			link.l1.go = "story";
			link.l2 = "Nathan, nous n'avons pas le temps pour les souvenirs agréables. Raconte-moi ça plus tard, quand nous serons assis au village Miskito avec une bouteille de vin.";
			link.l2.go = "diffindoor_19";
		break;
		
		case "story":
			dialog.text = "C'était il y a vingt-cinq ans... J'étais jeune, ardent et agité. Les Caraïbes étaient mon terrain de jeu. Je connaissais déjà Dannie à l'époque. Je l'aimais bien, vraiment, et le sentiment était réciproque. Mais nous nous disputions souvent, nous querellions et nous raillions l'un l'autre. Jeunesse insensée... Je crois que nous étions un grand divertissement pour les marins respectés de l'époque !\nQuoi qu'il en soit, d'une manière ou d'une autre, Dannie et moi avons été impliqués dans la même histoire. Nous avions trouvé une carte de Khael Roa et on nous avait dit que c'était L'ENDROIT pour trouver de l'or indien. Nous avions également trouvé une idole dorée d'aspect étrange, une copie plus petite de la partie supérieure des statues.\nL'idole était dangereuse, elle aspirait la vitalité de ceux qui la portaient. Mais nous avions besoin de cet objet maudit pour accéder au trésor à l'intérieur du temple. Le seul problème était que nous n'avions aucune idée de la manière de l'utiliser correctement. Dannie et moi avons navigué vers l'île. Il y avait un ancien temple, recouvert d'herbe et d'arbres. Une fois entrés, nous nous sommes retrouvés à l'intérieur d'un immense labyrinthe.\nNous avons réussi à trouver le bon chemin et à atteindre la partie centrale du labyrinthe. Nous pensions que c'était une impasse, mais lorsque le désespoir a commencé à nous vaincre, nous avons vu une étrange plateforme avec une petite prise et une image dessus. J'ai mis l'idole dans la prise et...";
			link.l1 = "...";
			link.l1.go = "exit";
			pchar.questTemp.LSC.Natanstory = "idol";
			AddDialogExitQuest("Video_story");
			NextDiag.TempNode = "story_1";
		break;
		
		case "story_1":
			dialog.text = "La plate-forme en pierre a descendu de quelques pouces et l'un des murs s'est révélé être un passage secret. L'idole est restée à l'intérieur de la plate-forme, je n'ai pas réussi à la retirer. Enfin, nous avons atteint une salle gigantesque. Quel spectacle magnifique !\nLa structure la plus magnifique que j'aie jamais vue. Des sculptures sur les murs, des statues énormes... Nous avons fouillé toute la salle, mais n'avons trouvé aucun signe de trésors.";
			link.l1 = "Hé, cela arrive souvent à des gens comme nous. Beaucoup d'efforts et aucun résultat à la fin...";
			link.l1.go = "story_2";
		break;
		
		case "story_2":
			dialog.text = "Ce n'était pas pour rien. Après tout, nous sommes entrés dans une salle du trône avec une statue géante d'oiseau à son extrémité. Il y avait une lumière mystique près de la statue, elle ressemblait exactement à la lumière au-dessus de l'idole à minuit. Nous nous sommes approchés et avons vu une magnifique sphère volante. Je te jure, je te dis la pure vérité!\nC'était réel, mais en même temps, cela semblait ne pas l'être. Pendant que je réfléchissais, Dannie - oh, ce diable imprudent, a touché la sphère. Elle a commencé à briller encore plus fort et s'est finalement transformée en un petit objet dans ses mains...";
			link.l1 = "...";
			link.l1.go = "exit";
			pchar.questTemp.LSC.Natanstory = "temple";
			AddDialogExitQuest("Video_story");
			NextDiag.TempNode = "story_3";
		break;
		
		case "story_3":
			dialog.text = "Il semblait que nous avions commis un sacrilège. Le temple prit vie : tout autour de nous se mit à bouger, les murs tremblaient et tout s'effondrait. C'était comme si nous avions réveillé tous les démons indiens et qu'ils déversaient toute leur colère sur nous...";
			link.l1 = "Ouah !";
			link.l1.go = "story_4";
		break;
		
		case "story_4":
			dialog.text = "Il est difficile à croire, je sais. Mais...";
			link.l1 = "Je t'aurais traité de menteur il y a six mois. Mais j'ai vécu assez longtemps aux Caraïbes pour savoir que je n'ai aucune raison de me méfier de toi. Continue. Comment as-tu survécu ?";
			link.l1.go = "story_5";
		break;
		
		case "story_5":
			dialog.text = "Nous avons quitté le temple en courant et avons eu la chance de monter à bord de notre navire à temps. J'ai ordonné de lever l'ancre, nous voulions partir de cet endroit au plus vite.";
			link.l1 = "Heh! Alors, au final, tu n'as trouvé qu'un étrange artefact au lieu de trésors ? Quel joli et équivalent remplacement, hé-hé... Et as-tu découvert comment l'utiliser ? Ou était-il inutile ?";
			link.l1.go = "story_6";
		break;
		
		case "story_6":
			dialog.text = "Attendez un moment. L'histoire n'est pas encore terminée. Dannie avait l'artefact et dès que nous avons décidé d'aller à la cabine pour l'étudier, le ciel s'est assombri et un navire est apparu. Oh Dieu ! C'était...";
			link.l1 = "... ";
			link.l1.go = "exit";
			pchar.questTemp.LSC.Natanstory = "blackpearl";
			AddDialogExitQuest("Video_story");
			NextDiag.TempNode = "story_7";
		break;
		
		// вот тут делаем развилку, в зависимости прошёл ли игрок Калеуче
		case "story_7":
			dialog.text = "... Van der Decken lui-même !!";
			if (CheckAttribute(pchar, "questTemp.KhaelRoa"))
			{
				link.l1 = "Van der Decken? Hm...";
				link.l1.go = "story_8_1";
			}
			else
			{
				link.l1 = "Et qui est-il ?";
				link.l1.go = "story_8";
			}
		break;
		
		case "story_8":
			dialog.text = "N'as-tu jamais entendu parler du Hollandais Volant ?";
			link.l1 = "Qui n'a pas entendu parler du Hollandais Volant ! J'ai déjà rencontré un Hollandais et envoyé son capitaine par le fond. Ce n'était qu'un simple pirate qui avait décoré son navire de quelques fanfreluches de mascarade comme des algues et des voiles déchirées.";
			link.l1.go = "story_9";
		break;
		
		case "story_8_1":
			dialog.text = "Oui, mais c'était Van der Decken lui-même, le capitaine du Hollandais Volant !";
			link.l1 = "Intéressant. Continuez, je vous prie. Comment avez-vous réussi à vous en sortir ?";
			link.l1.go = "story_11";
		break;
		
		case "story_9":
			dialog.text = "Eh-heh, ami... Tu as coulé un plaisantin mais je parle du véritable Hollandais Volant. Un énorme vaisseau de guerre. Que Dieu te préserve de jamais la rencontrer en pleine mer. Son capitaine Van der Decken et son équipage ont été maudits jadis à naviguer sans repos à travers les mers pour l'éternité.\nJe me souviens de ses voiles noires déchirées, de l'équipage de morts se tenant sur le pont avec leurs lames dégainées et du capitaine lui-même - un squelette effrayant portant un tricorne noir... Jésus...";
			link.l1 = "Dis-tu la vérité ?";
			link.l1.go = "story_10";
		break;
		
		case "story_10":
			dialog.text = "Je peux jurer sur la Bible que je ne mens pas... Une rencontre avec le 'Vaisseau Fantôme' ne signifie que la mort certaine. Elle est puissante, très puissante, une seule salve de ses canons peut couler même une lourde frégate et son équipage... mais pire encore, comment êtes-vous censé combattre les morts-vivants ?";
			link.l1 = "Mais tu as survécu à ce cauchemar !";
			link.l1.go = "story_11";
		break;
		
		case "story_11":
			dialog.text = "C'est grâce à ma charmante Dannie et à l'artefact indien que nous avons pris du temple. J'avais ordonné de nous préparer au combat, mais je savais que c'était la fin de la route. Le 'Hollandais Volant' naviguait vers nous et je voyais son équipage redoutable et Van der Decken lui-même sur le pont. Le navire commençait à pointer ses canons sur nous mais...";
			link.l1 = "...";
			link.l1.go = "exit";
			pchar.questTemp.LSC.Natanstory = "artefact";
			AddDialogExitQuest("Video_story");
			NextDiag.TempNode = "story_12";
		break;
		
		case "story_12":
			dialog.text = "Dannie leva l'artefact et le lança. Je n'avais aucune idée de pourquoi elle aurait fait ça. Elle a dit quelque chose à propos de son intuition féminine... L'artefact s'est transformé en sphère lumineuse et a explosé, endommageant gravement le navire fantôme et démoralisant son équipage. J'ai ordonné d'ouvrir le feu sur le Hollandais.\nLa première volée les fit frémir. Nous avons attaqué à nouveau et tiré sur leur coque pourrie une deuxième fois, juste avant qu'ils ne puissent se remettre de l'influence de l'artefact et commencer à riposter...";
			link.l1 = "Alors, tu as dû les combattre de toute façon ?";
			link.l1.go = "story_13";
		break;
		
		case "story_13":
			dialog.text = "En effet. Et je jure que c'était le combat le plus difficile de ma vie. Leur fichu rafiot tenait à peine à flot, pourtant ils ont réussi à détruire la moitié de ma coque avant que nous les envoyions aux cieux en faisant exploser leur maudite soute à poudre.";
			link.l1 = "Alors, l'as-tu coulé ? As-tu coulé le Hollandais volant ?";
			link.l1.go = "story_14";
		break;
		
		case "story_14":
			dialog.text = "Oui, bon sang! Je l'ai fait!..";
			link.l1 = "...";
			link.l1.go = "exit";
			pchar.questTemp.LSC.Natanstory = "ending";
			AddDialogExitQuest("Video_story");
			NextDiag.TempNode = "story_15";
		break;
		
		case "story_15":
			dialog.text = "Ce maudit navire a coulé. Le soleil a recommencé à briller et le ciel est devenu clair. Et nous avons enfin commencé à nous sentir heureux... oh, tu ne peux même pas imaginer à quel point nous étions heureux. Nous avions battu la mort elle-même. Des moments comme ça rapprochent les gens. Et nous avons fait ce que nous aurions dû faire bien avant cette rencontre - nous nous sommes embrassés, nous nous sommes embrassés, nous avons dit que nous nous aimions et avons juré de rester ensemble pour toujours.";
			link.l1 = "Et vous êtes toujours ensemble...";
			link.l1.go = "story_16";
		break;
		
		case "story_16":
			dialog.text = "Oui, nous le sommes. Dannie et moi nous sommes mariés et je ne l'ai jamais regretté. Tu ne trouveras pas de meilleure épouse et sœur d'armes.";
			if (CheckAttribute(pchar, "questTemp.KhaelRoa"))
			{
				link.l1 = "Alors, maintenant je sais enfin qui est vraiment ce mystérieux capitaine, qui a réussi à couler le 'Hollandais Volant'... Tu es un vrai héros !";
				link.l1.go = "story_17_1";
			}
			else
			{
				link.l1 = "Alors, vous deux êtes de vrais héros, hein ? Vous avez réussi à couler le fameux navire fantôme. Attendez ! Vous avez dit que le 'Hollandais Volant' vole toujours... Comment est-ce possible si elle repose au fond de la mer ?";
				link.l1.go = "story_17";
			}
		break;
		
		case "story_17":
			dialog.text = "Eh, l'ami, tu ne sais rien... Tu peux couler Van der Decken, mais tu ne peux pas le tuer. La malédiction qui pèse sur lui et son équipage est trop forte, bien plus forte que la mort...";
			link.l1 = "... ";
			link.l1.go = "exit";
			pchar.questTemp.LSC.Natanstory = "VDDrepair";
			AddDialogExitQuest("Video_story");
			NextDiag.TempNode = "story_18";
		break;
		
		case "story_17_1":
			dialog.text = "Un héros je pourrais être, mais Van der Decken ne peut être tué. La malédiction qui pèse sur lui, son équipage et son navire est plus forte que la mort...";
			link.l1 = "...";
			link.l1.go = "exit";
			pchar.questTemp.LSC.Natanstory = "VDDrepair";
			AddDialogExitQuest("Video_story");
			NextDiag.TempNode = "story_18";
		break;
		
		case "story_18":
			dialog.text = "Chaque fois que tu coules le navire, son équipage répare leur vaisseau, le remet à flot et continue leur voyage éternel.";
			if (CheckAttribute(pchar, "questTemp.KhaelRoa"))
			{
				link.l1 = "Je sais, Nathaniel, je sais. Pourtant, le Hollandais Volant ne causera plus de soucis à personne.";
				link.l1.go = "story_22";
			}
			else
			{
				link.l1 = "Eh bien, tu sais, cela ressemble à une fable. Réparer un navire démantelé et sabordé...";
				link.l1.go = "story_19";
			}
		break;
		
		case "story_19":
			dialog.text = "Les gens ont vu le navire plusieurs fois après que nous l'ayons coulé... À vous de décider si vous croyez aux apparitions.";
			link.l1 = "Où se trouve cette île avec le temple, celle d'où tu as obtenu l'artefact ?";
			link.l1.go = "story_20";
		break;
		
		case "story_20":
			dialog.text = "C'est inexploré et situé quelque part à l'est de la mer des Caraïbes. J'ai laissé une carte de l'île à Maroon Town, mais comme tu le sais très bien, je ne peux pas y naviguer maintenant. Et pour être honnête, je n'en ai pas envie. La seule chose dont je me souviens, c'est son nom - Khael Roa...";
			link.l1 = "Quelle histoire intéressante. J'aimerais bien trouver cette île !";
			link.l1.go = "story_21";
		break;
		
		case "story_21":
			dialog.text = "Oh, je ne le recommande pas... Je ne vais pas y retourner, c'est certain.";
			link.l1 = "Je voudrais le visiter de toute façon... Bien, merci pour votre histoire intéressante ! Maintenant, j'en sais plus sur votre femme. Vous êtes tous deux des légendes vivantes !";
			link.l1.go = "diffindoor_19";
			DeleteAttribute(pchar, "questTemp.LSC.Natanstory");
			pchar.questTemp.NatanStory = "true";
		break;
		
		case "story_22":
			dialog.text = "Que veux-tu insinuer, camarade ? Ne viens-je pas de te dire qu'il ne peut pas être tué ?";
			link.l1 = "Nathaniel, j'ai navigué jusqu'à Khael Roa. Et j'ai visité le temple des Chavins, où vous, Danielle et un vieil homme étiez il y a un quart de siècle. L'artefact que vous avez pris du temple à l'époque s'appelait 'l'orbe du soleil levant'. Cet artefact était la chose qui a attiré l'attention du 'Hollandais Volant' sur vous. Son capitaine était friand des artefacts Chavins.";
			link.l1.go = "story_23";
		break;
		
		case "story_23":
			dialog.text = "Vous êtes allé à Khael Roa ? Mais ce n'est simplement pas possible ! Me dites-vous la vérité ?";
			link.l1 = "Je le jure. Quand tu m'as parlé du labyrinthe et de la statue de l'oiseau géant, j'ai tout de suite compris où se trouvait cet endroit. Le chaman caribéen Tuttuathapak m'a raconté tes aventures. C'est lui qui m'a dirigé vers cette île. Elle est située à l'est de Saint-Christophe. Elle est très petite, en forme d'anneau. Il y a des rochers tout autour et une petite crique à l'intérieur. Et il y a juste un sentier envahi menant à un temple, qui est construit sous la forme d'une pyramide.";
			link.l1.go = "story_24";
		break;
		
		case "story_24":
			dialog.text = "Oui ! C'est Khael Roa. Mais pourquoi es-tu allé là-bas ?";
			link.l1 = "Pour lever la malédiction du Caleuche... enfin, du 'Hollandais Volant'. En fait, son nom était 'Cœur Volant', et le nom de son capitaine était 'Balthazar de Cordes'. Il y a cinquante ans, il a été maudit par Yum Cimil, un dieu indien de la Mort. J'ai pris le crâne de jade de Yum Cimil, qui avait été volé du temple par Balthazar il y a quelque temps, et je l'ai remis sur le piédestal devant cette statue de condor...";
			link.l1.go = "story_25";
		break;
		
		case "story_25":
			dialog.text = "";
			link.l1 = "...en retournant le crâne, j'ai levé la malédiction du Caleuche. Et comme j'avais deux autres amulettes Chavins avec moi, elle m'a attaqué près de l'île, exactement comme ce qui t'est arrivé à l'époque. Mais sans la malédiction, Balthazar n'était plus immortel, tout comme l'avait dit Tuttuathapak. Donc... le 'Hollandais volant' n'est plus. Je m'en suis personnellement occupé.";
			link.l1.go = "story_26";
		break;
		
		case "story_26":
			dialog.text = "Tonnerre et éclairs ! Je suis stupéfait ! Toi... Tu ne te moques pas du vieux Nathan, n'est-ce pas ? Non, je vois dans tes yeux que tu dis la vérité ! Tu es un vrai héros !";
			link.l1 = "Un héros ou non, mais j'ai vécu ma part d'aventures, tout comme toi. Eh bien, nous parlerons sûrement du passé bien d'autres fois, car maintenant nous avons un sujet commun.";
			link.l1.go = "diffindoor_19";
			DeleteAttribute(pchar, "questTemp.LSC.Natanstory");
		break;
		
		case "diffindoor_19":
			dialog.text = "Vas-tu me quitter maintenant, ami?";
			link.l1 = "Oui, Nathan. S'il te plaît, tiens bon jusqu'à mon retour. Prends soin de toi. Et surtout, reste en vie jusqu'à ce que je revienne et tout ira bien. Les Frères de la Côte ont besoin de toi, Danielle a besoin de toi.";
			link.l1.go = "diffindoor_20";
		break;
		
		case "diffindoor_20":
			dialog.text = "Est-ce que Dannie fait maintenant partie de ton équipage? Je te supplie, veille sur elle. Elle n'a pas changé depuis sa jeunesse, elle est toujours une tête brûlée et n'hésitera pas à passer par l'enfer. Dis-lui que je l'aime beaucoup...";
			link.l1 = "Bien sûr, je le ferai. Nous reviendrons ensemble pour toi, je te le promets, Nathan. Tiens bon, et garde la tête haute. Olé s'occupera de toi. À bientôt !";
			link.l1.go = "diffindoor_21";
		break;
		
		case "diffindoor_21":
			DialogExit();
			LAi_SetGroundSitTypeNoGroup(npchar);
			NextDiag.CurrentNode = "diffindoor_wait";
			pchar.questTemp.LSC.NatanTalk = "true"; // атрибут - разговор с Натаном состоялся
			AddQuestRecord("BaronReturn", "10");
			npchar.greeting = "nathaniel_1";
		break;
		
		case "diffindoor_wait":
			dialog.text = "Ah, c'est vous, "+pchar.name+" Pas encore quitté l'île ?";
			link.l1 = "Ne t'inquiète pas, Nathan, tout se déroule selon le plan. Repose-toi maintenant.";
			link.l1.go = "exit";
			NextDiag.TempNode = "diffindoor_wait";
		break;
		
		case "danny":
			PlaySound("Voice\English\saga\Nataniel Hawk-03.wav");
			dialog.text = "Danielle!.. Dannie! Ma Dannie!..";
			link.l1 = "...";
			link.l1.go = "danny_1";
		break;
		
		case "danny_1": // перекидываем pchar
			DialogExit();
			LAi_SetActorType(pchar);
			SetMainCharacterIndex(GetCharacterIndex("Nathaniel"));
			PChar = GetMainCharacter();			
			LAi_SetPlayerType(PChar);
			sld = characterFromId("Danielle");
			sld.dialog.currentnode = "nathaniel_6";
			LAi_SetActorType(sld);
			LAi_ActorDialog(sld, pchar, "", -1, 0);
			NextDiag.CurrentNode = "danny_2";
		break;
		
		case "danny_2":
			dialog.text = "Merci, mon ami. Merci pour tout et surtout pour ma Dannie...";
			link.l1 = "Vous êtes le bienvenu, Nathan.";
			link.l1.go = "exit";
			NextDiag.TempNode = "danny_2";
		break;
		
		// в Марун-Тауне
		case "marun_town":
			dialog.text = "Regardez qui vient de débarquer ! C'est "+GetFullName(pchar)+"  lui-même ! Entrez, entrez, ami ! Comment allez-vous ?";
			link.l1 = "Je vais bien. Et toi, Nathan ? Je vois qu'il n'y a plus de morosité. Tu as bonne mine. Œil de Serpent a vraiment bien travaillé !";
			link.l1.go = "marun_town_1";
		break;
		
		case "marun_town_1":
			ChangeCharacterComplexReputation(pchar, "fame", 3);
			dialog.text = "Oui, votre chaman est un faiseur de miracles. Je me sens même mieux qu'avant cette maudite téléportation ! Je me sens rajeuni de dix ans !"+pchar.name+", je vous dois beaucoup. Et je suis impressionné : vous avez aidé un parfait inconnu, traversant le portail maudit, m'arrachant des griffes de la mort, me ramenant à ma femme !\nEt encore plus ! Vous nous avez rendu notre navire et notre maison. Vous êtes maintenant notre meilleur ami. Pour toujours. Si jamais vous avez besoin de quelque chose - vous savez à qui demander ! Maroon Town vous offrira toujours protection, soutien et un refuge si vous en avez besoin.\nLe village entier se battra pour vous si vous êtes en danger. En temps de paix, vous trouverez ici amitié, le meilleur rhum, un lit douillet et un bon endroit pour vous reposer. Dannie et moi veillerons à cela.";
			link.l1 = "Merci, baron ! Je suis sincèrement heureux de vous voir en bonne santé et... avec Dannie.";
			link.l1.go = "marun_town_2";
		break;
		
		case "marun_town_2":
			dialog.text = "Je m'attendais à ta visite, "+pchar.name+",  et j'ai préparé un cadeau - une arme rare et puissante. Peut-être, un jour, aurez-vous besoin d'abattre de nombreux ennemis d'un seul coup et ce mortier de main vous aidera à le faire. 'Sclopetta' tire des grenades spéciales, alors j'ai aussi préparé des instructions pour les fabriquer. Tenez, prenez-le.";
			link.l1 = "Quelle excellente arme ! Merci !";
			link.l1.go = "marun_town_3";
		break;
		
		case "marun_town_3":
			GiveItem2Character(pchar, "grape_mushket"); 
			GiveItem2Character(pchar, "recipe_grenade"); 
			Log_Info("You have received a hand mortar");
			Log_Info("You have received a grenade instruction");
			PlaySound("interface\important_item.wav");
			dialog.text = "Viens nous voir plus souvent, "+pchar.name+" ! Dannie et moi serons toujours heureux de vous voir à tout moment.";
			link.l1 = "Ce sera un plaisir pour moi. Attendez-vous à me voir bientôt !";
			link.l1.go = "exit";
			NextDiag.TempNode = "marun_town_4";
		break;
		
		case "marun_town_4":
			dialog.text = "Ah, mon ami "+GetFullName(pchar)+" ! Entrez, entrez, Capitaine ! Comment allez-vous ? Besoin d'aide ?";
			// калеуче
			if (CheckAttribute(pchar, "questTemp.Caleuche.NatanInfo"))
			{
				link.l2 = "Nathan, je suis venu te voir pour une affaire très importante. Te souviens-tu quand tu m'as dit sur l'Île des Navires Abandonnés que toi et Dannie vous êtes infiltrés dans un temple indien et avez coulé le 'Hollandais Volant' ?";
				link.l2.go = "caleuche";
			}
			link.l1 = "Merci, je vais bien. Je voulais juste vous voir tous les deux.";
			link.l1.go = "exit";
			NextDiag.TempNode = "marun_town_4";
		break;
		
		case "caleuche":
			dialog.text = "Bien sûr, je le fais.";
			link.l1 = "Il me faut absolument atteindre cette île avec le temple. Je dois vraiment la trouver. Vous avez dit que vous aviez une carte de l'endroit. Pouvez-vous me donner les coordonnées ?";
			link.l1.go = "caleuche_1";
		break;
		
		case "caleuche_1":
			dialog.text = "Oh, ami, c'est une entreprise très dangereuse, tu sais... le temple de Khael Roa est maudit. Si tu savais seulement qui hante ses couloirs...";
			link.l1 = "En ce moment, il est habité par des monstres bien plus terrifiants que ceux que tu as vus à l'époque. Et j'irai quand même là-bas.";
			link.l1.go = "caleuche_2";
		break;
		
		case "caleuche_2":
			dialog.text = "Je ne me pardonnerai pas si tu péris là-bas. "+pchar.name+", Je t'en supplie : abandonne cette entreprise ! De plus, c'est là que le 'Hollandais Volant' est vu le plus souvent...";
			link.l1 = "Je l'ai déjà rencontré, et je sais comment le distancer. Nathan, s'il te plaît, donne-moi les coordonnées de Khael Roa et dis-moi tout ce que tu sais sur ce temple, à part qu'il est habité par des Indiens morts-vivants.";
			link.l1.go = "caleuche_3";
		break;
		
		case "caleuche_3":
			dialog.text = "Oh bien... Je ne peux te refuser, mais... tu n'as aucune idée de ce que Dannie et moi avons vécu là-bas ! Khael Roa est située à l'est d'Antigua. J'ai trouvé sa carte juste en rentrant à Maroon Town, c'est aux... (regardant) les coordonnées : 19 degrés 32' Nord, 62 degrés 25' Ouest.";
			link.l1 = "Je vais noter son emplacement dans mon journal... Merci, Nathan !";
			link.l1.go = "caleuche_4";
		break;
		
		case "caleuche_4":
			dialog.text = "You can thank me later. Now the details. The island of Khael Roa is a ring of rocks with a cove inside. Seek for the passage between the crags - it's fairly deep there. In the cove, you should cast anchor and disembark at the beach. Look for an old path heading deeper into the island - there's only one there. It will lead you to an Indian pyramid - this is the temple you seek.\nThe island itself is quiet, but the temple is crawling with abominations of all sorts. The entrance is located at the top of the pyramid. There will be three passages inside; you should take the middle one. Then you walk down the corridor and you will find a platform with four entrances or exits. This is where the temple creatures attacked me for the first time, so you should be careful.\nThen there is a labyrinth. It's very complex, and I, for the life of me, can't remember the right route. There is a multitude of foul creatures in the labyrinth. You must kill them all, then walk up to a hall with two entrances, six columns and a platform with nine stone slabs. This is the vestibule of the sanctuary. Its stone wall is closed, and I have no idea how you're going to open it.\nThere is some kind of mechanism, but I swear to God that I have no clue how it functions! I used an idol as a key. I inserted it into the central slab, and the door opened. But you don't have such an idol, so you'll have to figure out how this mechanism functions.";
			link.l1 = "D'accord, je ferai de mon mieux pour comprendre cela. Qu'en est-il du sanctuaire ?";
			link.l1.go = "caleuche_5";
		break;
		
		case "caleuche_5":
			dialog.text = "Le sanctuaire est une immense salle avec un plafond très haut et de grands escaliers en pierre. Vous ne pouvez pas les utiliser - ils sont trop anciens et pour la plupart effondrés. Mais les bâtisseurs du temple, semble-t-il, étaient aussi de grands sorciers. Il y a des portails, comme ceux de Kukulcan, et ils vous transporteront d'un endroit à un autre.\nVous les reconnaîtrez facilement - ils ressemblent à des tourbillons colorés. Il y aura deux portails au premier étage, mais l'un d'eux est un piège, alors soyez prudent ! Le bon portail vous mènera au deuxième étage. Là, vous devez trouver un autre portail pour monter encore plus haut, puis directement au cœur du temple !\nLà, à la grande statue de l'oiseau, fut placé cet artefact magique, que Dannie et moi avions emporté avec nous. Et je vous ai déjà dit ce qui s'est passé ensuite.";
			link.l1 = "Je me souviendrai de ce que tu viens de me dire. Merci, Nathaniel. Tu m'as beaucoup aidé.";
			link.l1.go = "caleuche_6";
		break;
		
		case "caleuche_6":
			dialog.text = "Prends soin de toi, "+pchar.name+"Les dédales et les salles du temple sont pleins de dangers. Un seul faux pas et tu es sûr d'y rester pour toujours.";
			link.l1 = "Praemonitus praemunitus, ami. J'ai été prévenu, ce qui signifie que je suis préparé. Je dois y aller maintenant. À bientôt !";
			link.l1.go = "caleuche_7";
		break;
		
		case "caleuche_7":
			dialog.text = "Bonne chance, "+pchar.name+" !";
			link.l1 = "Merci !";
			link.l1.go = "caleuche_8";
		break;
		
		case "caleuche_8":
			DialogExit();
			DeleteAttribute(pchar, "questTemp.NatanStory");
			DeleteAttribute(pchar, "questTemp.Caleuche.NatanInfo");
			AddQuestRecord("Caleuche", "35");
			NextDiag.CurrentNode = "marun_town_4";
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}
