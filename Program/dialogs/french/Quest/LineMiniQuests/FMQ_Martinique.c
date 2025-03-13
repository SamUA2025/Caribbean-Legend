// Addon-2016 Jason, французские миниквесты (ФМК) Мартиника
void ProcessDialogEvent()
{
	ref sld, NPChar;
	aref Link, NextDiag;
	int i;
	string sTemp;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			dialog.text = "Un bogue évident. Informez les développeurs.";
			link.l1 = "Oh, je le ferai.";
			link.l1.go = "exit";
			NextDiag.TempNode = "First time";
		break;
		
		// квестодатель
		case "carpenter":
			DelMapQuestMarkCity("Fortfrance");
			LAi_SetImmortal(npchar, false);
			npchar.lifeday = 0;
			DelLandQuestMark(npchar);
			dialog.text = TimeGreeting()+", capitaine. Permettez-moi de me présenter - "+GetFullName(npchar)+"Bien que nous nous soyons déjà rencontrés il n'y a pas longtemps, je doute que vous vous souveniez de moi.";
			link.l1 = "Salut, monsieur. Et où pourrais-je vous avoir déjà vu ?";
			link.l1.go = "carpenter_1";
		break;
		
		case "carpenter_1":
			sTemp = "lugger 'Adeline'";
			if (pchar.questTemp.Sharlie.Ship == "sloop") sTemp = "sloop 'Black Dog'";
			dialog.text = "Notre chantier naval. Vous avez acheté "+sTemp+". Tu te souviens maintenant ? Je suis charpentier là-bas.";
			link.l1 = "Oui, j'ai vraiment acheté ce navire. Alors, que voulez-vous, monsieur "+GetFullName(npchar)+"?";
			link.l1.go = "carpenter_2";
		break;
		
		case "carpenter_2":
			sld = characterFromId("FortFrance_shipyarder");
			AddLandQuestMark(sld, "questmarkmain");
			dialog.text = "Notre constructeur de navires "+GetFullName(sld)+" veut vous parler. Je crois qu'il a une sorte de proposition d'affaire. Il a vu votre navire dans notre port et m'a envoyé vous chercher. Auriez-vous l'amabilité d'accepter l'invitation ?";
			link.l1 = "D'accord. Je rendrai visite à ton patron une fois que j'aurai terminé mes affaires en ville.";
			link.l1.go = "carpenter_3";
		break;
		
		case "carpenter_3":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorRunToLocation(npchar, "reload", "reload5_back", "none", "", "", "", 10.0);
			chrDisableReloadToLocation = false;
			pchar.questTemp.FMQM = "begin";
			AddQuestRecord("FMQ_Martinique", "1");
			SetFunctionTimerCondition("FMQM_Denial", 0, 0, 2, false);
		break;
		
		case "officer":
			PlaySound("Voice\English\soldier_arest_4.wav");
			dialog.text = "Eh bien, eh bien... De nouveaux contrebandiers dans mes filets !";
			link.l1 = "Eh...";
			link.l1.go = "officer_1";
		break;
		
		case "officer_1":
			dialog.text = "Ne racontez pas de salades ! Il y a plusieurs tonneaux de résine dans ce chantier naval. Capitaine, vous les avez livrés à votre complice. Vous êtes tous les deux en état d'arrestation et je confisque la cargaison au nom de la loi !";
			link.l1 = "... ";
			link.l1.go = "officer_2";
		break;
		
		case "officer_2":
			DialogExit();
			LAi_SetActorType(npchar);
			sld = characterFromId("FortFrance_shipyarder");
			LAi_SetActorType(sld);
			LAi_ActorDialogNow(sld, pchar, "", -1);
		break;
		
		case "officer_3":
			dialog.text = "Ne fais pas l'idiot, maître! Quels tonneaux? Tu sais bien que je parle des tonneaux que tu as récemment déchargés de ce navire de marin! Vous allez pourrir tous les deux dans les geôles! Allez, salauds...";
			link.l1 = "";
			link.l1.go = "officer_4";
		break;
		
		case "officer_4":
			DialogExit();
			LAi_SetActorType(npchar);
			sld = characterFromId("FortFrance_shipyarder");
			LAi_SetActorType(sld);
			LAi_ActorDialogNow(sld, pchar, "", -1);
		break;
		
		case "officer_5":
			PlaySound("Voice\English\soldier\soldier arest-02.wav");
			dialog.text = "Cette résine, mon cher maître charpentier, est un bien de valeur stratégique sous le contrôle direct de notre gouverneur ! Comme vous prétendez qu'elle vous appartient, faites à votre guise. Vous êtes en état d'arrestation, vous passerez cette nuit dans nos cachots confortables et demain vous nous donnerez un rapport détaillé de la façon dont vous les avez obtenues et dans quel but. Ne vous inquiétez pas, nous finirons par tout apprendre. Vous, capitaine, êtes libre de partir. C'est votre jour de chance.";
			link.l1 = "";
			link.l1.go = "officer_6";
		break;
		
		case "officer_6":
			DialogExit();
			LAi_SetActorType(pchar);
			LAi_ActorTurnToCharacter(pchar, characterFromID("FMQM_officer"));
			sld = characterFromId("FortFrance_shipyarder");
			LAi_SetActorType(sld);
			LAi_ActorGoToLocation(sld, "reload", "reload1", "FortFrance_town", "officers", "reload5_3", "FMQM_ArestContinue", 8);
		break;
		
		case "officer_7":
			PlaySound("Voice\English\soldier_arest_2.wav");
			dialog.text = "Je savais qu'il y avait quelque chose qui clochait avec ce navire... On dirait que je vous ai sous-estimé, capitaine.";
			link.l1 = "Exactement, lieutenant. Je ne suis pas si stupide. Ta joyeuse cooperation avec le constructeur naval est compromise maintenant.";
			link.l1.go = "officer_8";
			DelLandQuestMark(npchar);
		break;
		
		case "officer_8":
			dialog.text = "Je vois. Félicitations, vous devez être talentueux puisque vous avez réussi à me retrouver et à me surprendre. Maintenant, dites-moi ce que vous voulez.";
			link.l1 = "N'est-ce pas clair? J'ai besoin de récupérer ma résine. La résine que toi et ton complice m'avez volée.";
			link.l1.go = "officer_9";
		break;
		
		case "officer_9":
			dialog.text = "D'accord. Tu peux l'avoir, mais seulement la moitié de ton lot. C'est tout ce que j'ai planqué ici. J'espère que cela te suffira, car c'est tout ce que je peux offrir.";
			link.l1 = "Essaies-tu encore de m'entuber ? Compense-moi l'autre moitié avec de l'or ou avec des marchandises cachées derrière toi.";
			link.l1.go = "officer_10";
		break;
		
		case "officer_10":
			dialog.text = "Pas une option. Adressez-vous à notre ami commun pour l'autre moitié.";
			link.l1 = "Tu te fous de moi ? Tu crois vraiment que "+GetFullName(characterFromId("FortFrance_shipyarder"))+" me rendra mes tonneaux? C'est ridicule.";
			link.l1.go = "officer_11";
		break;
		
		case "officer_11":
			dialog.text = "Capitaine, prenez toute la resine que j'ai, sauvez votre peau et foutez le camp d'ici. Je peux ajouter a cette affaire ma promesse de ne causer aucun ennui pour vous a St. Pierre. C'est ma derniere offre.";
			link.l1 = "Depuis quand ma vie fait-elle partie du marché ? Ha !";
			link.l1.go = "officer_12";
		break;
		
		case "officer_12":
			dialog.text = "On dirait que vous vous sentez encore invincible après le combat, capitaine. Laissez-moi vous expliquer ceci : c'étaient des novices, non entraînés et démotivés, vous n'avez aucune chance contre mon escouade. Je pourrais vous faire tuer ici même sans négociation, mais je tiens à la vie de mes hommes. L'un d'eux pourrait être blessé ou même tué en vous éliminant. Alors soit vous acceptez mon offre généreuse, soit vous restez ici pour toujours. Il est temps de choisir.";
			link.l1 = "Va te faire foutre, lieutenant, mais je suis contraint d'accepter vos conditions. Je suis sérieusement en infériorité ici.";
			link.l1.go = "officer_13";
			link.l2 = "Trop sûr de toi, lieutenant ? Je suppose que je devrais vous donner, à vous et à vos mercenaires, une leçon. Espèce de chien de résine !";
			link.l2.go = "officer_15";
		break;
		
		case "officer_13":
			dialog.text = "Vous êtes un homme raisonnable, capitaine. Prenez vos barils et disparaissez. Je dois vous avertir, me pointer du doigt devant le gouverneur ne vous aidera pas. Je changerai l'emplacement de ma cachette aujourd'hui. Épargnez votre temps.";
			link.l1 = "Je n'allais pas le faire. Je comprends l'inutilité de m'adresser aux autorités.";
			link.l1.go = "officer_14";
		break;
		
		case "officer_14":
			dialog.text = "Dépêche-toi, je n'ai pas beaucoup de temps à perdre.";
			link.l1 = "... ";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("FMQM_PeaceExit");
		break;
		
		case "officer_15":
			DialogExit();
			AddDialogExitQuestFunction("FMQM_BattleExit");
		break;
		
		case "greguar":
			PlaySound("Voice\English\LE\Greguar\Greguar_02.wav");
			dialog.text = "Oh ! Quelle rencontre ! Salutations, monsieur ! Passez-vous une bonne nuit ?";
			link.l1 = "Bonne nuit... ah, c'est vous ! Je me souviens de vous, nous nous sommes rencontrés le tout premier jour de mon arrivée aux Caraïbes. Monsieur Gregoire Valinnie.";
			link.l1.go = "greguar_1";
		break;
		
		case "greguar_1":
			dialog.text = "Ravi que tu t'en souviennes. Je vois que tu es maintenant capitaine. Capitaine "+GetFullName(pchar)+" Félicitations.";
			link.l1 = "Merci...";
			link.l1.go = "greguar_2";
		break;
		
		case "greguar_2":
			dialog.text = "Vous semblez perturbé, capitaine. Que s'est-il passé ici ? Quelque chose ne va pas ?";
			link.l1 = "Quelque chose ne va pas...";
			link.l1.go = "greguar_3";
		break;
		
		case "greguar_3":
			dialog.text = "Monsieur, plutôt que de rester au milieu de la rue, allons plutôt dans une taverne. Vous pourriez prendre une pinte ou deux. Nous pourrons y parler. Allez, venez !";
			link.l1 = "... ";
			link.l1.go = "greguar_4";
		break;
		
		case "greguar_4":
			DialogExit();
			NextDiag.CurrentNode = "greguar_5"; 
			FreeSitLocator("Fortfrance_tavern", "sit_front4");
			LAi_SetActorType(npchar);
			LAi_ActorRunToLocation(npchar, "reload", "reload4_back", "Fortfrance_tavern", "sit", "sit_front4", "FMQM_InTavern", -1);
		break;
		
		case "greguar_5":
			LAi_SetSitType(Pchar);
			dialog.text = "Versez, capitaine...";
			link.l1 = "Vas-y..";
			link.l1.go = "greguar_6";
		break;
		
		case "greguar_6":
			LAi_Fade("", "");
			WaitDate("",0,0,0,1,20);
			RecalculateJumpTable();
			dialog.text = "Wooh... Maintenant, s'il te plaît, dis-moi ce qui ne va pas ? On dirait ce type qu'ils ont pendu la semaine dernière. Il avait exactement la même tête en se tenant sur la potence.";
			link.l1 = "Voyez-vous, monsieur Gregoire... Disons simplement que j'ai des ennuis au travail.";
			link.l1.go = "greguar_7";
		break;
		
		case "greguar_7":
			dialog.text = "Capitaine, vous pouvez tout partager avec moi. Je ne vais pas vous dénoncer au gouverneur ou au commandant, vous pouvez me faire confiance là-dessus. Ne me faites-vous pas confiance ?";
			link.l1 = "Je vous fais confiance, monsieur.";
			link.l1.go = "greguar_8";
		break;
		
		case "greguar_8":
			dialog.text = "Alors confessez et soulagez un peu votre âme. Je pourrais être en mesure de vous aider.";
			link.l1 = "Un constructeur naval local m'a engagé pour piller une caravane espagnole qui avait quitté Trinidad. Il avait un besoin urgent de résine, c'était ma cible et il a promis de payer quinze doublons par tonneau. J'ai suivi la caravane, l'ai pillée et ai apporté les marchandises ici. Ils ont mis mon navire en réparation et ont débarqué les tonneaux au chantier naval. Nous étions sur le point de conclure notre affaire quand cet officier est apparu... Je me demande comment il a pu le découvrir ?";
			link.l1.go = "greguar_9";
		break;
		
		case "greguar_9":
			dialog.text = "";
			link.l1 = "C'était ça, ils nous avaient. Je pense que je devrais donner du crédit au constructeur naval - il a pris toute la responsabilité sur lui, leur a dit que la résine est sa propriété et que je n'y suis pour rien. Au final, il est arrêté et ma pièce est perdue. Le désordre avec la caravane espagnole était une perte de temps et d'argent, bien que j'aie eu la chance de ne pas finir en prison. Remplis à nouveau, monseigneur Gregoire.";
			link.l1.go = "greguar_10";
		break;
		
		case "greguar_10":
			dialog.text = "Alors, le constructeur de navires est-il en état d'arrestation ?";
			link.l1 = "Eh bien, oui. Il a été emmené en prison par l'officier dont je parlais. Tu aurais dû les voir.";
			link.l1.go = "greguar_11";
		break;
		
		case "greguar_11":
			dialog.text = "Oui, je les ai vus tous les deux, bien que je n'avais aucune idée que le lieutenant Felicien Gronier pourrait éventuellement arrêter son vieil ami.";
			link.l1 = "Qu... qu'avez-vous dit ?";
			link.l1.go = "greguar_12";
		break;
		
		case "greguar_12":
			dialog.text = "Vous avez bien entendu. Lieutenant Felicien Gronier et constructeur naval "+GetFullName(characterFromId("FortFrance_shipyarder"))+" sont de vieux amis. Ils servaient ensemble dans l'armée en Europe autrefois. Gronier est resté dans l'armée et "+GetFullName(characterFromId("FortFrance_shipyarder"))+"a réussi à lancer sa propre affaire.";
			link.l1 = "Alors ils se connaissent... Maintenant je comprends...";
			link.l1.go = "greguar_13";
		break;
		
		case "greguar_13":
			dialog.text = "Mon cher "+pchar.name+", on dirait que vous avez été dupé. Vous êtes encore un nouveau ici et ils en ont profité. Je parie cent doublons que monsieur "+GetFullName(characterFromId("FortFrance_chantiernaval"))+"  se promènera à nouveau dans son chantier naval dans trois jours ou moins.";
			link.l1 = "Il semble que vous ayez raison, monsieur. Ils m'ont roulé. Il n'y a pas moyen que cet officier soit au courant de la résine. Et le timing parfait aussi.";
			link.l1.go = "greguar_14";
		break;
		
		case "greguar_14":
			dialog.text = "C'est les Caraïbes, monsieur "+pchar.name+" . Habitué-toi à cela. Oublie les apparences, la pire racaille ici a toujours l'air d'un noble honoré.";
			link.l1 = "J'ai entendu cette phrase quelque part auparavant... Que devrais-je faire avec eux ? Devrais-je m'adresser au gouverneur ?";
			link.l1.go = "greguar_15";
		break;
		
		case "greguar_15":
			dialog.text = "Je crains que dans ce cas "+GetFullName(characterFromId("FortFrance_chantiernaval"))+" racontera une autre histoire et tu finiras en prison.";
			link.l1 = "Bien sûr. Très bien alors ! Puisque la loi n'est pas de mon côté, je vais le faire à ma manière, bon sang ! Je ne vais pas abandonner comme ça.";
			link.l1.go = "greguar_16";
		break;
		
		case "greguar_16":
			dialog.text = "Veuillez vous calmer "+pchar.name+". C'est la colère et le rhum qui parlent, pas toi. Dors un peu et réfléchis-y à nouveau. Peut-être qu'il vaudrait mieux pour toi de laisser tomber. Lieutenant Felicien Gronier et "+GetFullName(characterFromId("FortFrance_shipyarder"))+" sont des gens puissants ici, ils sont bien au-dessus de ton niveau. Ne fais rien de stupide.";
			link.l1 = "Nous verrons. Merci de m'avoir éclairé. C'est bien de vous avoir rencontré.";
			link.l1.go = "greguar_17";
		break;
		
		case "greguar_17":
			dialog.text = "Sois prudent. Garde à l'esprit ce que je t'ai dit.";
			link.l1 = "Je le ferai. Maintenant, prenons un dernier verre !";
			link.l1.go = "exit";
			AddDialogExitQuest("FMQM_OutTavern");
		break;
		
		case "greguar_18":
			PlaySound("Voice\English\LE\Greguar\Greguar_03.wav");
			dialog.text = "Capitaine "+GetFullName(pchar)+"!";
			link.l1 = "Oh, monsieur Gregoire! Vous encore!";
			link.l1.go = "greguar_19";
		break;
		
		case "greguar_19":
			dialog.text = "Oui. Après notre discussion à la taverne, j'ai fait des recherches concernant le lieutenant Felicien Gronier. Il s'avère qu'il a demandé un congé de dix jours il n'y a pas longtemps. Sa demande a été approuvée. Je l'ai vu aujourd'hui, il a pris une chaloupe vers une tartane qui a bientôt mis le cap sur la Guadeloupe. Elle s'appelle le Topaz\nJe t'ai tout dit, c'est à toi de décider maintenant. Je suis sûr que tu peux voir le motif dans le soudain appel de Gronier à prendre un congé et à s'éloigner de l'île sur une tartane fraîchement construite.";
			link.l1 = "Bon sang, c'est clair comme de l'eau de roche pour moi maintenant, c'est sûr ! Cette tartane a ma résine stockée dans une soute à cargaison ! Monsieur Gregoire, merci, vous avez vraiment assuré ! Y a-t-il quelque chose que je pourrais faire pour vous en retour ?";
			link.l1.go = "greguar_20";
		break;
		
		case "greguar_20":
			dialog.text = "Oh, allons, mon ami. Nous sommes des gentilshommes, nous devrions nous entraider. C'est ainsi que nous vivons. Je crois que tu aurais fait la même chose si tu étais à ma place. Ne perds pas une minute, navigue vers le Nord et trouve l'officier. N'engage pas le combat, contente-toi de le suivre et découvre ce qu'il mijote. Vite, capitaine !";
			link.l1 = "Merci encore !";
			link.l1.go = "exit";
			AddDialogExitQuest("FMQM_HurryToSea");
		break;
		
		case "pirate":
			dialog.text = "Que regardes-tu ? Que veux-tu ici ?";
			link.l1 = "Salut, mon gars, je cherche mes marchandises. Tu vois ces tonneaux là-bas ? C'est ma résine pour laquelle ils ne m'ont pas payé un sou.";
			link.l1.go = "pirate_1";
			DelLandQuestMark(characterFromId("FMQM_Enemy_crew_2"));
		break;
		
		case "pirate_1":
			dialog.text = "Es-tu idiot ou quoi ? Dégage tant que tu le peux encore !";
			link.l1 = "J'ai mis trop d'efforts pour obtenir cette résine pour permettre à quelques sales canailles de m'arrêter.";
			link.l1.go = "pirate_2";
		break;
		
		case "pirate_2":
			dialog.text = "Nous allons enterrer ton beau costume ici !";
			link.l1 = "Oh comme c'est aimable de ta part de proposer un enterrement, mais j'ai bien peur que nous devions simplement te laisser ici sur la plage et laisser les mouettes dévorer tes entrailles !";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("FMQM_ShoreFight");
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}
