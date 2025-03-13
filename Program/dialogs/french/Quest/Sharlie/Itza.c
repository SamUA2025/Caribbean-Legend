// диалоги Уракана, Канека и прочих индейцев ица
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
	int i, iTemp;
	string sTemp;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			dialog.text = "Y a-t-il quelque chose dont vous avez besoin ?";
			link.l1 = "Non, rien.";
			link.l1.go = "exit";			
			NextDiag.TempNode = "First time";
		break;
		
		// ица-горожане
		case "itza_ctz":
			dialog.text = LinkRandPhrase("Un autre visage pâle... Grand prêtre heureux de te tailler le cœur...","Visage pâle sait comment venir à Tayasal, mais personne ne quitte la ville !","Je suis surpris, visage pâle : tu n'es pas encore parti vers le monde des esprits... Marche tant que tu le peux, bientôt tu verras tes ancêtres.");
			link.l1 = LinkRandPhrase("Eh bien, eh bien. Nous verrons...","N'essaie pas de m'effrayer, guerrier à la peau rouge. J'ai vu pire que ça.","Va, va. Essaie d'effrayer les enfants.");
			link.l1.go = "exit";
			NextDiag.TempNode = "itza_ctz";
		break;
		
		case "itza_ctz_1":
			dialog.text = LinkRandPhrase("Bénis-moi pour la bataille avec l'ennemi, grand Cavil !","Le grand Cavil et le grand Kukulcan nous honorent de leur présence. Même chez les anciens Mayas, cela n'arrivait pas !","Nous transmettons la légende de la grande bataille de Kukulcan et Cavil à nos enfants !");
			link.l1 = "... ";
			link.l1.go = "exit";
			NextDiag.TempNode = "itza_ctz_1";
		break;
		
		// Уракан - вождь ица
		case "urakan":
			dialog.text = "Tu es un grand guerrier, visage pâle. Nous apportons ton sang aux dieux. Tu mourras avec dignité.";
			link.l1 = "Doucement, guerrier à la peau rouge. Je ne vais pas permettre à ton Kanek de m'offrir en sacrifice à Kukulcan ou à quiconque d'autre d'ailleurs. Tes guerriers n'ont pas réussi à me capturer. Chacun d'entre eux est tombé au combat.";
			link.l1.go = "urakan_1";
		break;
		
		case "urakan_1":
			dialog.text = "Oui, toi, noble guerrier, visage pâle. Mais tu ne pourrais résister à des centaines de guerriers Tayasal Itza. Cependant, tu prononces des mots intéressants. Comment connais-tu le grand Kanek et Kukulcan ?";
			link.l1 = "Eh bien, laissez-moi deviner... Puisque vous n'êtes pas Kanek, votre nom doit être Urakan et vous êtes le fils du prêtre Kanek ?";
			link.l1.go = "urakan_2";
		break;
		
		case "urakan_2":
			dialog.text = "Tes lèvres disent la vérité, visage pâle. Je suis Urakan, et je suis surpris.";
			link.l1 = "Tu vas être encore plus surpris quand tu verras ça... Regarde.";
			link.l1.go = "urakan_3";
		break;
		
		case "urakan_3":
			dialog.text = "Oh, dieux! Si visage pale a masque, cela signifie que le temps est venu... Vous etes celui dont Kukulcan a parle. Il a ordonne de vous amener a lui quand vous arriverez a Tayasal. Il sait que vous venez.";
			link.l1 = "Kukulcan ?! Il est ici à Tayasal ?";
			link.l1.go = "urakan_4";
		break;
		
		case "urakan_4":
			dialog.text = "Oui, guerrier blanc. Quetzalcoatl vient à Tayasal. Bientôt, il partira pour apporter la lumière aux ancêtres, grande cité des Mayas.";
			link.l1 = "Mille millions de sabords ! Alors, il est déjà là... (abaissant la voix) Urakan, je sais tout. Je sais que c'est toi qui as envoyé Ksatl Cha avec le Gardien de la Vérité pour chercher Ksocheatem et le masque de Kukulcan...";
			link.l1.go = "urakan_5";
		break;
		
		case "urakan_5":
			dialog.text = " ";
			link.l1 = "Je vois de la surprise dans vos yeux mais aussi du doute, grand chef Urakan. Vous n'êtes pas satisfait de Kukulcan, ai-je raison ?";
			link.l1.go = "urakan_6";
		break;
		
		case "urakan_6":
			dialog.text = "Chaque guerrier Itza est heureux que le grand Kukulcan vienne, guerrier blanc. Tu dois te tenir devant Kukulcan. Il t'attend depuis de nombreuses nuits. Il est un grand prophète. Il sait tout à l'avance. Va au Serpent Volant, tu n'as pas d'autre chemin. Nous ne te permettons pas de quitter Tayasal.";
			link.l1 = "Ne comprends-tu pas que dès que Kukulcan franchira les portes du temps, vous tous, ainsi que toi personnellement, cesserez d'exister ? Et le meilleur dans tout ça, c'est que vous renaîtrez dans une autre image, dans un autre corps... Peut-être comme un simple guerrier, ou peut-être même comme un infirme ou un mendiant...";
			link.l1.go = "urakan_7";
		break;
		
		case "urakan_7":
			dialog.text = "Va, guerrier à la peau pâle. Tu trouveras Kukulcan dans le Grand temple des guerriers d'Itza. Va tout droit sur le pont, jusqu'à ce que tu vois une grande pyramide. Entre par la porte inférieure du temple et approche-toi du sanctuaire.";
			link.l1 = "D'accord. J'irai à Kukulcan, car je vois que nous ne pouvons échapper à cette rencontre. Mais je vous ai prévenu.";
			link.l1.go = "urakan_8";
		break;
		
		case "urakan_8":
			DialogExit();
			LAi_SetPlayerType(pchar);
			LAi_SetWarriorType(npchar);
			LAi_warrior_SetStay(npchar, true);
			LAi_warrior_DialogEnable(npchar, true);
			NextDiag.CurrentNode = "urakan_9";
			DeleteAttribute(pchar, "GenQuest.Notsearchbody");
			AddQuestRecord("Tieyasal", "25");
			pchar.quest.Tieyasal_Templegreat.win_condition.l1 = "location";
			pchar.quest.Tieyasal_Templegreat.win_condition.l1.location = "Temple_great";
			pchar.quest.Tieyasal_Templegreat.function = "Tieyasal_InGreatTemple";
			// экспа за бой
			AddComplexSelfExpToScill(300, 300, 300, 300);
			AddCharacterExpToSkill(pchar, "Leadership", 500);
			AddCharacterExpToSkill(pchar, "Fortune", 300);
		break;
		
		case "urakan_9":
			dialog.text = "Va, guerrier blanc. Kukulcan t'attend.";
			link.l1 = "Je suis en route...";
			link.l1.go = "exit";
			NextDiag.TempNode = "urakan_9";
		break;
		
		case "urakan_10":
			PlaySound("Voice\English\Complete.wav");
			dialog.text = "C'est devenu réalité ! Quand je vois comment tu combats Kukulcan, je sais que tu es Cavil lui-même. Tu es venu à Tayasal pour sauver le peuple Itza de la mort à cause de mon père et de Kukulcan. Mon père, le grand prêtre Kanek, a condamné le peuple Itza à la gloire des ancêtres mayas depuis longtemps disparus.\nJe suis le chef de guerre Urakan qui protège le peuple Itza depuis de nombreuses années. Aucun visage pâle ne quitte Tayasal vivant. Moi et les guerriers nous assurons que le peuple Itza reste protégé et en vie pendant de très nombreuses années à venir. Je ne veux pas sacrifier tout mon peuple.";
			link.l1 = "Je le savais, Urakan. Et je t'ai demandé de m'aider sur le pont.";
			link.l1.go = "urakan_11";
		break;
		
		case "urakan_11":
			dialog.text = "Rien n'échappe aux yeux du grand Cavil. Pardonne à Urakan de ne pas comprendre qui tu es vraiment.";
			link.l1 = "Ne t'inquiète pas, chef. J'ai vaincu l'incarnation mortelle de Kukulcan, mais nous avons une seconde tâche importante devant nous - fermer les portes du passé. Ce trou temporel contre nature doit être éliminé. M'aideras-tu ?";
			link.l1.go = "urakan_12";
		break;
		
		case "urakan_12":
			dialog.text = "Qu'est-ce qu'Urakan peut faire pour toi, ô Cavil ?";
			link.l1 = "Tu as envoyé Ksatl Cha avec le Gardien de la Vérité pour chercher Ksocheatem et le masque de Kukulcan. Donc, tu sais qu'il peut être utilisé pour fermer les portes du temps. Ton père t'en a-t-il parlé ?";
			link.l1.go = "urakan_13";
		break;
		
		case "urakan_13":
			dialog.text = "Pere ne parle pas. J'étudie les écrits dans le temple de la Connaissance et de la Sagesse. Mais beaucoup de choses sont floues pour Urakan. Peut-être que Cavil peut comprendre ?";
			link.l1 = "Qu'as-tu découvert exactement ?";
			link.l1.go = "urakan_14";
		break;
		
		case "urakan_14":
			dialog.text = "J'apprends par cœur. L'écriture proclame : 'Quand le soleil se lève contre la pluie, et que le feu entre eux forme un triangle, frappe la jambe de Tohil contre l'autre et incinère le masque de Kukulcan sur l'autel du temps. Et scelle les portes du temps d'Itzamna jusqu'à la fin des jours.'";
			link.l1 = "Quoi.";
			link.l1.go = "urakan_15";
		break;
		
		case "urakan_15":
			dialog.text = "Oui.";
			link.l1 = "Jesus... Montre-moi les portes.";
			link.l1.go = "urakan_16";
		break;
		
		case "urakan_16":
			dialog.text = "Ils se trouvent dans le temple Kukulcan. Mais la porte là-bas est verrouillée. Seul mon père peut verrouiller et déverrouiller. Lorsqu'il ouvre la porte du temple Kukulcan, il dit : 'Le soleil vient et va, l'eau tombe et se retire, le feu s'allume et s'éteint, la guerre et la paix s'interchangent, mais seul le ciel est éternel. Au-dessus du temps, il n'y a que le ciel.'";
			link.l1 = "Intéressant... Souvenons-nous de cela et voyons ce que nous pouvons faire...";
			link.l1.go = "urakan_17";
		break;
		
		case "urakan_17":
			dialog.text = "Je reste ici, en bas, près de l'autel du temps. Je vois chaque pyramide et bâtiment de Taysal de l'intérieur. Trouve les clés. Je reste ici.";
			link.l1 = "Si j'ai des questions importantes, je viendrai certainement te voir.";
			link.l1.go = "urakan_18";
		break;
		
		case "urakan_18":
			DialogExit();
			NextDiag.CurrentNode = "urakan_adv";
			DeleteAttribute(pchar, "GenQuest.Notsearchbody");
			pchar.quest.Tieyasal_UrakanTemple.win_condition.l1 = "location";
			pchar.quest.Tieyasal_UrakanTemple.win_condition.l1.location = "Tenochtitlan";
			pchar.quest.Tieyasal_UrakanTemple.function = "Tieyasal_UrakanInTemple";
			AddQuestRecord("Tieyasal", "26");
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocator(npchar, "quest", "urakan", "", -1);
			// экспа за бой
			AddComplexSelfExpToScill(1000, 1000, 1000, 1000);
			AddCharacterExpToSkill(pchar, "Leadership", 3000);
			AddCharacterExpToSkill(pchar, "Fortune", 1500);
		break;
		
		case "urakan_adv":
			dialog.text = "Urakan peut-il aider le grand Cavil avec des conseils ou des actions ?";
			if (Tieyasal_CheckTablets() && !CheckAttribute(npchar, "quest.tablets"))
			{
				link.l1 = "Regarde cette tablette que j'ai trouvée. À en juger par l'endroit où je l'ai trouvée, elle doit avoir un rapport avec ton père et ce n'est clairement pas un objet ordinaire...";
				link.l1.go = "tablets";
			}
			if (CheckAttribute(npchar, "quest.treasureentrance"))
			{
				link.l1 = "J'ai trouvé une autre entrée au sommet du Grand Temple, mais elle est scellée. Comment puis-je y entrer ? Peut-être que ce que je cherche s'y trouve.";
				link.l1.go = "treasure";
			}
			link.l9 = "Rien pour l'instant, Urakan. Je me débrouillerai tout seul...";
			link.l9.go = "exit";
			NextDiag.TempNode = "urakan_adv";
		break;
		
		case "tablets":
			dialog.text = "Les plaques de pierre des dieux. Père en a plusieurs pièces différentes et elles lui sont très précieuses. Les anciens bâtisseurs de Tayasal utilisaient ces plaques pour activer des mécanismes cachés, ouvrir et fermer des portes, et même réaliser des rituels magiques. \nElles fonctionnent si on les place au bon endroit - c'est ce que fait mon père. Mais moi, je suis un guerrier tout comme toi, je ne sais pas comment les utiliser correctement. Peut-être que Cavil le sait ?";
			link.l1 = "Nous allons certainement tirer cela au clair...";
			link.l1.go = "exit";
			npchar.quest.tablets = "true";
			NextDiag.TempNode = "urakan_adv";
			AddQuestRecord("Tieyasal", "31");
		break;
		
		case "treasure":
			dialog.text = "C'est la porte vers les trésors de Tayasal. Là se trouvent les richesses des Indiens Itza. Seul mon père peut ouvrir et fermer cette porte. Personne n'ose entrer pour les trésors sans lui. Pas même moi.";
			link.l1 = "Comment votre père a-t-il ouvert l'entrée ?";
			link.l1.go = "treasure_1";
		break;
		
		case "treasure_1":
			dialog.text = "Mon père dit : 'Tout trésor a deux faces. Seul celui qui connaît ces deux faces accède aux trésors de Tayasal.' Ce que cela signifie - je ne sais pas. Peut-être, Cavil devine ?";
			link.l1 = "Nous trouverons une solution à celui-ci aussi...";
			link.l1.go = "exit";
			NextDiag.TempNode = "urakan_adv";
			DeleteAttribute(npchar, "quest.treasureentrance");
			AddQuestRecord("Tieyasal", "32");
		break;
		
		case "urakan_19":
			PlaySound("Voice\English\Complete.wav");
			dialog.text = "Tu l'as fait, ô grand Cavil ! Les gens d'Itza sont maintenant en sécurité. Moi, Urakan, fils de Kanek, je t'assure que je ne déshonorerai pas l'honneur que tu m'as accordé et je protégerai Tayasal de toute invasion de visage pâle déshonorant en ton nom.";
			link.l1 = "Je le crois volontiers, chef. Eh bien, nous pouvons célébrer maintenant : nous avons mis fin aux plans traîtres de Kukulcan. Il ne pourra plus jamais matérialiser une révolution temporelle.";
			link.l1.go = "urakan_20";
		break;
		
		case "urakan_20":
			PlaySound("interface\abordage_wining.wav");
			dialog.text = "Gloire grand Cavil ! À moi et à ma génération revient le grand honneur de voir à Tayasal deux dieux. Nous écrivons cette histoire pour nos enfants. Ils connaîtront la bataille des dieux à Tayasal ! Gloire à Cavil ! Gloire !";
			link.l1 = "J'ai besoin d'un verre...";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("Tieyasal_Win_IndianBead");
		break;
		
		// Канек - жрец ица
		case "kanek":
			dialog.text = "Tu te tiens devant le Serpent Ailé, visage pâle. L'esprit du puissant Kukulcan en chair humaine. Tu as la chance d'être son frère par le père de son incarnation, tout comme j'ai la chance d'être le père de sa mère, la femme qui l'a mis au monde. C'est un grand honneur. C'est peut-être pour cela que tu es devenu un guerrier fort et que tu es encore en vie.\nMais ton temps viendra à manquer, visage pâle. Nous commencerons une nouvelle ère, l'ère des grands Maya. Nous établirons notre propre pouvoir et ne laisserons jamais les visages pâles venir dans notre monde. Bientôt. Moi, Kanek le prêtre, je vais commencer le rituel !";
			link.l1 = "Merveilleux...";
			link.l1.go = "kanek_1";
		break;
		
		case "kanek_1":
			DialogExit();
			sld = characterFromId("Mishelle");
			sld.dialog.currentnode = "kukulkan_3";
			LAi_SetActorType(sld);
			LAi_ActorDialogDelay(sld, pchar, "", 0.7);
		break;
		
		case "kanek_2":
			dialog.text = "Urakan, tu as entendu ce que notre seigneur a dit. Soumets-toi maintenant !";
			link.l1 = "Quand les grands se battent entre eux, il vaut mieux pour nous, simples mortels, de rester à l'écart et d'observer de loin, père...";
			link.l1.go = "kanek_3";
		break;
		
		case "kanek_3":
			dialog.text = "Quoi ?! Reprends tes esprits, fiston !";
			link.l1 = "Cet homme est le frère de Kukulcan et un grand guerrier. Je vois l'incarnation de Cavil lui-même en lui ! Personne d'autre que lui ne peut résister à un dieu comme ÇA. Pas de plaisanterie dans un duel de dieux, père ! Et si tu apportes des offrandes à Kukulcan, mes guerriers donneront leur sang à Cavil !";
			link.l1.go = "kanek_4";
		break;
		
		case "kanek_4":
			dialog.text = "Es-tu sain d'esprit, Urakan?";
			link.l1 = "De nombreuses années j'ai, nommé après Hurakan, protégé avec succès nos terres au nom de Cavil contre l'invasion des étrangers. Des centaines d'entre eux sont tombés sous nos massues et personne n'a quitté Tayasal. Mais jamais de ma vie je n'ai vu un guerrier aussi fort et agile que ce visage pâle. S'il est capable de vaincre Kukulcan, alors il est l'incarnation de l'esprit de Cavil lui-même !";
			link.l1.go = "kanek_5";
		break;
		
		case "kanek_5":
			DialogExit();
			sld = characterFromId("Mishelle");
			sld.dialog.currentnode = "kukulkan_win_5";
			LAi_SetActorType(sld);
			LAi_ActorDialogNow(sld, pchar, "", -1);
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}
