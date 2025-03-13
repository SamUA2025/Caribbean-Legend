// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Comment puis-je vous aider ?","Que puis-je faire pour vous ?"),"Dis-moi, qu'est-ce qui te tracasse, "+GetAddress_Form(NPChar)+"?","Pour la troisième fois, "+GetAddress_Form(NPChar)+", que désirez-vous?","J'en ai assez de toi. Dégage !","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("J'ai changé d'avis, mes excuses.","Ce n'est rien, excusez-moi."),"Pardonnez-moi, ce n'est rien.","Tu as raison, c'est déjà la troisième fois. Pardonne-moi...","Mes excuses.",npchar,Dialog.CurrentNode);		
			link.l1.go = "exit";
			// калеуче
			if (CheckAttribute(pchar, "questTemp.Caleuche") && pchar.questTemp.Caleuche == "graveyard" && !CheckAttribute(npchar, "quest.caleuche"))
			{
				link.l1 = "Écoutez, avez-vous vu ou rencontré un homme du nom de Joachim Merriman, ici à La Havane ou dans ses environs ? C'est un Señor d'âge moyen, Portugais avec une moustache, une barbiche impériale et des yeux perçants. Peut-être dans une crique ou dans la jungle ? Je le cherche.";
				link.l1.go = "caleuche";
			}
		break;
		
		// калеуче
		case "caleuche":
			dialog.text = "N-non, marin, c-certainement pas. Je reçois rarement des visiteurs ici, vous voyez, euh... et je... je n'ai pas v-vu quelqu'un comme l'homme que vous avez décrit, donc...";
			link.l1 = "Vraiment ? Alors pourquoi bégayes-tu et caches-tu tes yeux ? Ne me mens pas maintenant, tu connais la vérité. Tu ferais mieux de me le dire à nouveau - as-tu vu cet homme ?";
			link.l1.go = "caleuche_1";
		break;
		
		case "caleuche_1":
			dialog.text = "J-Je vous dis, Senor, je n'ai v-vu personne! J-Je b-begaye d-depuis que je suis e-enfant...";
			link.l1 = "Mensonges, que des mensonges. Je le vois dans tes yeux. Où est-il, où est Merriman ?! Dis-moi, MAINTENANT !";
			link.l1.go = "caleuche_2";
		break;
		
		case "caleuche_2":
			dialog.text = "Je ne connais aucun Merriman ! Je n'ai jamais entendu ce nom auparavant non plus ! Et n'essaie pas de me faire du mal ou le Commandant te pendra au fort ! Alors fais attention, garçon !";
			link.l1 = "Oh, tu crois ça ? Très bien. Maintenant, écoute-moi attentivement : Joachim Merriman est un sorcier. La Sainte Inquisition est à sa recherche. Il y a de nombreuses années, en Europe, il a été condamné à être brûlé sur le bûcher pour profanation de tombes, souillure des morts et sorcellerie. Et je sais avec certitude que maintenant il se cache quelque part, ici, dans les faubourgs de La Havane...";
			link.l1.go = "caleuche_3";
		break;
		
		case "caleuche_3":
			dialog.text = "...";
			link.l1 = "...récemment, j'ai nettoyé la grotte voisine des zombies et je sais qui est responsable ! Assurément, où irait Merriman sinon au cimetière ! Vous savez où il est. Mais faites comme bon vous semble, je ne vous toucherai pas, mais je rendrai visite aux Inquisiteurs à Santiago. Le père Vincento trouvera très intrigant que Joachim Merriman se cache dans le cimetière de La Havane avec son complice, le gardien local...";
			link.l1.go = "caleuche_4";
		break;
		
		case "caleuche_4":
			dialog.text = "... ";
			link.l1 = "...La couleur a-t-elle déjà quitté ton visage ? Je te donne ma parole de noble : Un jour après que j'aurai rapporté mes découvertes, toute l'île grouillera de soldats espagnols. Et tu seras étiré sur un chevalet, suppliant et pleurant jusqu'à ce que tu révèles où se cache ce sorcier. Pas plus tard que cela, tu seras brûlé sur le bûcher comme son complice pendant que j'assisterai à l'auto-da-fé. Comment cela te plairait-il ?";
			link.l1.go = "caleuche_5";
		break;
		
		case "caleuche_5":
			dialog.text = "P-pitié, señor ! Je ne participe à rien de tout cela, je le jure ! Je... je ne pouvais rien faire... Comment pouvais-je m'opposer à lui ?! C'est un homme terrible, il peut... vous n'avez aucune idée de ce qu'il peut faire ! Miséricorde, je vous en supplie !";
			link.l1 = "Croyez-moi, je sais de quoi il est capable. Je l'ai vu de mes propres yeux. Alors ? Où est-il ? Dites-le-moi et je vous promets que je ne vous mêlerai pas à cette affaire.";
			link.l1.go = "caleuche_6";
		break;
		
		case "caleuche_6":
			dialog.text = "Il... Il se cache dans une grotte sous le cimetière. On ne peut y accéder que par la porte de la chapelle. Quand il sort, je me cache dans ma maison et je m'y terre. Tu n'as aucune idée à quel point je voudrais me débarrasser de cette horreur ! \nMais je n'oserais même pas m'approcher. J'ai... J'ai vu qu'il creusait une tombe fraîche, et puis... puis le mort s'est levé et a marché autour du cimetière au clair de lune ! J'ai presque perdu la raison ce jour-là ! Mais Merriman m'a interdit de partir. Il m'a menacé, disant que si je quittais ma maison sans sa permission, même pour une demi-journée, il me trouverait et me transformerait en cette abomination... un squelette ambulant !";
			link.l1 = "À quelle fréquence quitte-t-il sa grotte ?";
			link.l1.go = "caleuche_7";
		break;
		
		case "caleuche_7":
			dialog.text = "Eh bien, je lui apporte de la nourriture et des potions de soin de la ville et... tout ce qu'il demande. Il part une ou deux fois par mois... quand la lune est pleine. Il laisse une note à la porte, écrit ce dont il a besoin... J-je la livre et la pose à la porte, et il la prend une fois qu'il est revenu.";
			link.l1 = "Je vois. Cette porte vers son antre - est-elle verrouillée d'une manière quelconque ?";
			link.l1.go = "caleuche_8";
		break;
		
		case "caleuche_8":
			dialog.text = "C'est vrai. C'est toujours fermé. C'est très solide et la serrure est massive et complexe.";
			link.l1 = "Hm... Merriman n'est pas un imbécile, il doit sûrement avoir une autre sortie de sa tanière, comme sa maison en Europe. Si nous forcions la porte, il s'éclipserait, ne pouvant jamais être retrouvé. Hmmm...";
			link.l1.go = "caleuche_9";
		break;
		
		case "caleuche_9":
			dialog.text = "Señor, jurez-vous que vous ne me livrerez pas à l'Inquisition ?";
			link.l1 = "Je t'ai donné ma parole, et la parole d'un noble est sacrée. Je jure que je ne te dénoncerai pas.";
			link.l1.go = "caleuche_10";
		break;
		
		case "caleuche_10":
			dialog.text = "Oh bénisse vous, Señor ! Je sais comment arriver à la grotte. Il y a une clé, une deuxième clé... Je l'ai. Merriman ne sait pas qu'il y a deux clés pour cette serrure. Je n'oserais jamais entrer, mais vous...";
			link.l1 = "Donne-moi la clef, et je te délivrerai de ce cauchemar.";
			link.l1.go = "caleuche_11";
		break;
		
		case "caleuche_11":
			GiveItem2Character(pchar, "kaleuche_key");
			ChangeItemDescribe("kaleuche_key", "itmdescr_kaleuche_key_crypt");
			dialog.text = "Voici, Senor. Allez-vous vraiment entrer dans son antre ?";
			link.l1 = "Je le suis. Enferme-toi dans ta maison et attends-là quand je rentre. Si je ne reviens pas, laisse tout et cours aussi vite que tu peux.";
			link.l1.go = "caleuche_12";
		break;
		
		case "caleuche_12":
			dialog.text = "Mais soyez prudent, Señor. Des bruits effrayants ont été entendus venant de sa grotte et je crains même de penser à qui pourrait l'habiter. Mais Merriman n'est pas seul - c'est certain.";
			link.l1 = "Je prendrai toutes les mesures possibles. Adieu.";
			link.l1.go = "caleuche_13";
		break;
		
		case "caleuche_13":
			DialogExit();
			AddQuestRecord("Caleuche", "30");
			pchar.questTemp.Caleuche = "merriman";
			pchar.quest.caleuche_merriman_cave.win_condition.l1 = "locator";
			pchar.quest.caleuche_merriman_cave.win_condition.l1.location = "Havana_CryptBig2";
			pchar.quest.caleuche_merriman_cave.win_condition.l1.locator_group = "reload";
			pchar.quest.caleuche_merriman_cave.win_condition.l1.locator = "reload2";
			pchar.quest.caleuche_merriman_cave.function = "Caleuche_OpenMerrimanCave";
			pchar.quest.caleuche_merriman_cave1.win_condition.l1 = "location";
			pchar.quest.caleuche_merriman_cave1.win_condition.l1.location = "Havana_CryptDungeon";
			pchar.quest.caleuche_merriman_cave1.function = "Caleuche_InMerrimanCave";
			if(bImCasual) NewGameTip("Exploration mode: timer is not disabled. Meet the deadline!");
			SetFunctionTimerCondition("Caleuche_MerrimanCaveOver", 0, 0, 3, false); // таймер
			npchar.quest.caleuche = "true";
			// логово Мерримана
			int n = Findlocation("Havana_CryptDungeon");
			locations[n].id.label = "Merrimancave";
		break;
	}
	UnloadSegment(NPChar.FileDialog2); 
}
