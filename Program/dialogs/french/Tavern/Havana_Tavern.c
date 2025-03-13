// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat("Tous les rumeurs de "+GetCityName(npchar.city)+"à votre service. Que voudriez-vous savoir?","Nous en parlions justement. Vous devez avoir oublié...","C'est la troisième fois aujourd'hui que tu parles d'une question...","Tu te répètes comme un perroquet...","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Tu sais, "+NPChar.name+", peut-être la prochaine fois.","D'accord, j'ai oublié pour une raison quelconque...","Oui, c'est vraiment la troisième fois...","Ouai...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			if (CheckAttribute(pchar, "questTemp.Slavetrader") && pchar.questTemp.Slavetrader == "FindRatHavana")
            {
                link.l1 = "Aurait-il par hasard Francois Gontier fait escale dans votre ville ? Il a une corvette '"+pchar.questTemp.Slavetrader.ShipName+", juste au cas où... ";
                link.l1.go = "Havana_ratT_1";
            }
			if (CheckAttribute(npchar, "quest.batabano"))
            {
                link.l1 = "Dis-moi, camarade, où pourrais-je trouver Don Diego de Montoya ? Suis-je en retard ? Est-il déjà parti pour le continent ?";
                link.l1.go = "guardoftruth";
            }
			// калеуче
			if (CheckAttribute(pchar, "questTemp.Caleuche") && pchar.questTemp.Caleuche == "graveyard" && !CheckAttribute(npchar, "quest.caleuche"))
			{
				link.l1 = "Ecoute, un homme du nom de Joachim Merriman est-il passé par ici ? Un médecin d'âge moyen, portugais, avec une moustache, une barbe impériale et des yeux perçants ? Peut-être qu'il voulait louer une chambre ?";
				link.l1.go = "caleuche";
			}
		break;

		case "Havana_ratT_1":
			dialog.text = "Ah, ce sombre gaillard ? Oui, il est passé chez moi. Je vais te dire quelque chose : il avait rendez-vous avec Oregon-et-Haskon. Il a demandé à recevoir une patente. Mais ça n'a pas marché pour lui et il est parti de là.";
			Link.l1 = "Et où a-t-il mis les voiles, savez-vous ? Je le poursuis depuis Porto Bello et je n'arrive pas à le trouver.";
			Link.l1.go = "Havana_ratT_2";
		break;
		
		case "Havana_ratT_2":
			dialog.text = "Que lui voulez-vous ? Il a peur des étrangers, il se cache toujours de tout le monde, dès qu'il voit un étranger armé, il saisit une épée. Il ne se promène qu'entouré de quatre gardes. Se pourrait-il que vous soyez l'homme dont il se méfie ?";
			Link.l1 = "Seigneur, les gens le disent encore et encore ! Quoi, ai-je l'air d'un tueur ? C'est mon vieux compagnon, je suis pressé de lui transmettre des nouvelles, il sera fort réjoui de savoir qu'il n'a plus besoin de se cacher, personne ne le cherche.";
			Link.l1.go = "Havana_ratT_3";
		break;
		
		case "Havana_ratT_3":
			dialog.text = "Pas besoin qu'il se cache ? Ha-ha-ha ! Juste un jour avant son départ de La Havane, une bande entière de vauriens a essayé de le tuer dans la jungle... Bien sûr, il avait ses propres hommes et ils les ont transformés en chair à pâté en un clin d'œil. Et vous voilà en train de dire...";
			Link.l1 = "Oh, allez. C'étaient probablement juste des bandits locaux essayant de mettre la main sur sa bourse. Tu sais bien combien de vauriens traînent dans la jungle. Alors, où est-il allé ?";
			Link.l1.go = "Havana_ratT_4";
		break;
		
		case "Havana_ratT_4":
			dialog.text = "Eh bien, après qu'il ait été envoyé loin et pour longtemps de la résidence, il n'arrêtait pas de répéter qu'il se rendrait aux mangeurs de grenouilles, à ses compatriotes. Il est parti pour la Tortue, vers un certain d'Ogeron... Il a aussi marmonné quelque chose à propos de son amante, mais je n'ai pas bien compris.";
			Link.l1 = "Alors, Tortuga? Super! J'espère que je l'attraperai là-bas. Merci, "+npchar.name+", tu as été d'une aide précieuse. Adieu.";
			Link.l1.go = "exit";
			AddQuestRecord("Slavetrader", "21_7");
			pchar.questTemp.Slavetrader = "FindRatTortuga";
			pchar.quest.Slavetrader_findTortugaRat.win_condition.l1 = "location";
            pchar.quest.Slavetrader_findTortugaRat.win_condition.l1.location = "Tortuga_HouseHut";
            pchar.quest.Slavetrader_findTortugaRat.win_condition = "Slavetrader_findTortugaRat";
		break;

		case "guardoftruth":
			dialog.text = "Hm...Et pourquoi un Français s'intéresserait-il à Don Diego, hein ?";
			link.l1 = "Le fait que je sois français est sans importance. Ce qui compte, c'est ce document signé par l'Inquisiteur. Regardez... voyez-vous maintenant? J'ai un message urgent pour Diego.";
			link.l1.go = "guardoftruth_1";
		break;
		
		case "guardoftruth_1":
			dialog.text = "Ah-ha, donc vous travaillez pour Sa Révérence, le Père Vincento ? Cela change la donne. Don Diego de Montoya est parti il y a deux jours avec son escadre, mais il est vite revenu avec son lougre courrier. Un de ses navires a sombré sur les récifs au sud de Cuba, alors il a acheté du matériel de réparation juste aujourd'hui.\nVérifiez la baie au sud, vous y trouverez un navire et l'homme lui-même. Je doute qu'ils aient déjà réussi à boucher les trous.";
			link.l1 = "Merci, l'ami ! Tu m'as beaucoup aidé !";
			link.l1.go = "guardoftruth_2";
		break;
		
		case "guardoftruth_2":
			dialog.text = "Pas du tout, à tout moment. Je suis toujours heureux d'aider un frère Jésuite.";
			link.l1 = "Oui, pax vobiscum et tout cela.";
			link.l1.go = "guardoftruth_3";
		break;
		
		case "guardoftruth_3":
			DialogExit();
			DeleteAttribute(npchar, "quest.batabano");
			AddQuestRecord("Guardoftruth", "47");
			pchar.quest.GuardOT_Batabano.win_condition.l1 = "location";
			pchar.quest.GuardOT_Batabano.win_condition.l1.location = "Shore13";
			pchar.quest.GuardOT_Batabano.function = "GuardOT_SanAntonioPrepare";
		break;
		
		// калеуче
		case "caleuche":
			dialog.text = "Le diable le sait, mon pote. Il pourrait être arrivé, mais je n'en sais rien. Désolé.";
			link.l1 = "Je vois. Dommage. Je vais continuer ma recherche...";
			link.l1.go = "exit";
			npchar.quest.caleuche = "true";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
