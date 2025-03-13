// официантка Наталия Бушелл
#include "DIALOGS\%language%\Rumours\Common_rumours.c"
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	ProcessCommonDialogRumors(NPChar, Link, NextDiag);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			if (pchar.questTemp.LSC == "return" && !CheckAttribute(npchar, "quest.return_isl"))
			{
				dialog.text = "Ah ! Et ils m'ont dit que tu t'étais noyé... Menteurs !";
				link.l1 = "Bien sûr qu'ils l'ont fait ! Ah ! Je vais bien !";
				link.l1.go = "exit";
				npchar.quest.return_isl = "true";
				break;
			}
			if (npchar.quest.meeting == "0")
			{
				dialog.text = "Bon jour, "+GetAddress_Form(NPChar)+"! Première fois ici ? Je ne vous ai jamais vu... J'espère que vous nous rendrez visite plus souvent, Sancho peut vous offrir une excellente variété de boissons. Oui, et je m'appelle Nathalie et j'aide Sancho avec les affaires de la taverne.";
				link.l1 = TimeGreeting()+". Mon nom est "+GetFullName(pchar)+"Ravi de vous rencontrer. Et vous ne pouviez pas me voir avant. Je suis arrivé ici récemment.";
				link.l1.go = "meeting";
				npchar.quest.meeting = "1";
			}
			else
			{
				dialog.text = "Ah, "+GetFullName(pchar)+"! "+TimeGreeting()+" ! Vous voulez quelque chose ? ";
				link.l1 = LinkRandPhrase("As-tu quelque chose d'intéressant à raconter ?","Y a-t-il du nouveau sur l'île ?","Me raconterez-vous les derniers commérages ?");
				link.l1.go = "rumours_LSC";
				link.l2 = "Je veux te poser quelques questions sur l'île.";
				link.l2.go = "int_quests"; //информационный блок
				link.l5 = "Je voulais juste savoir comment tu vas. À bientôt !";
				link.l5.go = "exit";
			}
			NextDiag.TempNode = "First time";
		break;
		
		case "meeting": // первая встреча
			dialog.text = "Récemment ? Un autre navire s'est-il échoué ? Je n'ai rien entendu... Ou n'êtes-vous pas arrivé ici tout comme monsieur Turam sur l'épave du mât ? Oh, pardonnez ma curiosité, la nature des femmes, vous savez.";
			link.l1 = "Non, c'est bon, Nathalie. Je suis arrivé ici sur une barque mais elle a coulé. Ce fut un plaisir de te rencontrer. À bientôt !";
			link.l1.go = "exit";
			link.l2 = "Non, c'est bon. Je voulais juste te poser quelques questions sur l'île.";
			link.l2.go = "int_quests"; //информационный блок
			NextDiag.TempNode = "First time";
		break;
		
//--------------------------------------- блок вопросов и ответов ---------------------------------------------
		case "int_quests":
			dialog.text = "J'écoute.";
			if (!CheckAttribute(npchar, "quest.answer_1"))
			{
				link.l1 = "Vous travaillez à la taverne. Que pouvez-vous me dire sur le propriétaire ?";
				link.l1.go = "ansewer_1";
			}
			if (!CheckAttribute(npchar, "quest.answer_2"))
			{
				link.l2 = "Et comment es-tu arrivé ici ?";
				link.l2.go = "ansewer_2";
			}
			if (!CheckAttribute(npchar, "quest.answer_3"))
			{
				link.l3 = "Combien de personnes vivent ici ?";
				link.l3.go = "ansewer_3";
			}
			if (!CheckAttribute(npchar, "quest.answer_4"))
			{
				link.l4 = "Ne suis-tu jamais surpris de voir de nouveaux visages ici ?";
				link.l4.go = "ansewer_4";
			}
			link.l10 = "Aucune question. Si vous voulez bien m'excuser...";
			link.l10.go = "exit";
		break;
		
		case "ansewer_1":
			dialog.text = "Seulement des choses positives,  "+GetAddress_Form(NPChar)+"Sancho a toujours une grande variété de boissons - des vieux vins aux simples bières et rhum. Il y a plusieurs années, il a trouvé un énorme stock de vins millésimés. Sancho a passé deux mois à déplacer des caisses de bouteilles dans son magasin\nEt maintenant, nous sommes bien approvisionnés en vin que seuls les gouverneurs pouvaient se permettre de posséder autant dans l'archipel. Le rhum n'est pas un problème non plus. Sancho peut vous offrir non seulement des boissons, mais aussi des nouvelles fraîches, un bon conseil et un lit chaud pour passer la nuit.";
			link.l1 = "Je vois...";
			link.l1.go = "int_quests";
			npchar.quest.answer_1 = "true";
		break;
		
		case "ansewer_2":
			dialog.text = "Oh, c'est une triste histoire. Il y a sept ans, j'ai fugué avec mon prétendant de la maison de mes parents et nous avons décidé de déménager à Belize depuis Santiago. Le navigateur a fait une erreur près de Main, donc nous avons navigué dans la mauvaise direction vers le Nord et avons été pris par une tempête. Notre navire a coulé non loin de l'anneau extérieur. Mon prétendant est mort ce jour-là, tout comme la plupart des autres. Moi et les survivants avons commencé de nouvelles vies ici, sur l'Île Justice.";
			link.l1 = "Triste histoire...";
			link.l1.go = "int_quests";
			npchar.quest.answer_2 = "true";
		break;
		
		case "ansewer_3":
			dialog.text = "Pas mal de monde. Les clans des Rivados et des Narvals sont nombreux, ils vivent ici depuis des décennies. Il n'y a pas tant de gens ordinaires, mais la taverne est pleine chaque soir. J'ai du mal à servir les boissons.";
			link.l1 = "Vraiment ? Intéressant.";
			link.l1.go = "int_quests";
			npchar.quest.answer_3 = "true";
		break;
		
		case "ansewer_4":
			dialog.text = "Et pourquoi devrions-nous ? Il y a beaucoup de nouveaux visages qui arrivent très souvent. Je ne sais même pas combien d'entre nous vivent ici. Parfois, je vois un homme pour la première fois et il me dit qu'il vit ici depuis un an.";
			link.l1 = "Eh bien...";
			link.l1.go = "int_quests";
			npchar.quest.answer_4 = "true";
		break;
// <-- блок вопросов и ответов
		
//----------------------------------------- специальные реакции -----------------------------------------------
		//обнаружение ГГ в сундуках
		case "Man_FackYou":
			dialog.text = LinkRandPhrase("Que fais-tu là, hein ? Voleur !","Regarde-moi ça ! A peine ai-je été perdu dans ma contemplation, que tu as décidé de fouiller mon coffre !","Tu as décidé d'inspecter mes coffres ? Tu ne t'en tireras pas comme ça !");
			link.l1 = "Bon sang !";
			link.l1.go = "fight";
		break;
		
		case "Woman_FackYou":
			dialog.text = "Quoi ?! Décidé de fouiller dans mes coffres ? Tu ne t'en tireras pas comme ça !";
			link.l1 = "Fille insensée !";
			link.l1.go = "exit_setOwner";
			LAi_group_Attack(NPChar, Pchar);
		break;
		
		case "fight":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			LAi_SetOwnerTypeNoGroup(npchar);
			LAi_group_Attack(NPChar, Pchar);
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		
		case "exit_setOwner":
			LAi_SetOwnerTypeNoGroup(npchar);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		//замечание по обнажённому оружию
		case "LSCNotBlade":
			dialog.text = LinkRandPhrase("Ecoute, tu ferais mieux de ranger tes armes. Ça me rend nerveux.","Sachez qu'ici, courir avec une lame n'est pas toléré. Rangez-la.","Écoute, ne joue pas au chevalier médiéval en courant avec une arme. Range-la, cela ne te va pas...");
			link.l1 = LinkRandPhrase("Très bien.","D'accord.","Comme vous dites...");
			link.l1.go = "exit";
			NextDiag.TempNode = "First Time";
		break;	
		
		case "CitizenNotBlade":
			if (loadedLocation.type == "town")
			{
				dialog.text = NPCharSexPhrase(NPChar,"Écoutez, je suis citoyen de la ville et je vous demanderais de rengainer votre épée.","Écoute, je suis citoyen de la ville et je te demanderais de rengainer ton épée.");
				link.l1 = LinkRandPhrase("D'accord.","D'accord.","Comme tu dis...");
			}
			else
			{
				dialog.text = NPCharSexPhrase(NPChar,"Sois prudent, l'ami, en courant avec une arme. Je pourrais devenir nerveux...","Je n'aime pas quand les gens marchent devant moi avec leur arme prête. Ça me fait peur...");
				link.l1 = RandPhraseSimple("Compris.","Je l'emporte.");
			}
			link.l1.go = "exit";
			NextDiag.TempNode = "First Time";
		break;
// <-- специальные реакции
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}
