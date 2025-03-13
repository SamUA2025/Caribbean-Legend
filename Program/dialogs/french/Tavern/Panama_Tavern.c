// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat("Tous les rumeurs de "+GetCityName(npchar.city)+"à votre service. Que voudriez-vous savoir?","Nous en parlions justement. Tu as dû oublier...","C'est la troisième fois aujourd'hui que tu parles d'une question...","Tu répètes tout comme un perroquet...","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Tu sais, "+NPChar.name+" , peut-être la prochaine fois.","D'accord, j'ai oublié pour une raison quelconque...","Oui, c'est vraiment la troisième fois...","Oui...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			if (pchar.questTemp.Slavetrader == "FindRatPanama")
            {
                link.l1 = "J'ai entendu dire que vous aviez un corsaire du nom de Francois Gontier dans votre ville. Sauriez-vous où le trouver ?";
                link.l1.go = "Panama_rat_1";
            }
			// Addon-2016 Jason ”ЊЉ-ѓваделупа
			if (CheckAttribute(pchar, "questTemp.FMQG") && pchar.questTemp.FMQG == "headhunter_panama")
            {
                link.l1 = "Ecoutez, je suis à la recherche d'un homme nommé Bertrand Pinette, en avez-vous entendu parler ? Il est arrivé à Panama il n'y a pas longtemps. Un gentilhomme imposant avec une perruque. Il a peut-être été ici...";
                link.l1.go = "FMQG";
            }
		break;

		//-->работорговец
		case "Panama_rat_1":
			dialog.text = NPCStringReactionRepeat("Oui, nous avons eu un gaillard comme ça en ville. Il rôdait dans des endroits sombres... Puis quelques-uns de ses camarades sont venus lui rendre visite, on aurait dit une bande de coupe-jarrets. Il a quitté la ville avec eux.","Tu as déjà posé la question et je t'ai répondu.","Je t'ai dit, tu avais déjà posé des questions sur ce Gontier.","Ecoute, va-t'en et cesse de m'importuner ! As-tu complètement perdu la tête ?","block",0,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Et où est-il allé, sais-tu ?","Hm, je suppose que oui...","Oui, c'est vrai, j'ai demandé cela...","Désolé, "+npchar.name+"...",npchar,Dialog.CurrentNode);
			link.l1.go = "Panama_rat_2";
		break;
		
		case "Panama_rat_2":
			dialog.text = "Eh bien, il n'y a qu'une seule façon de sortir d'ici à pied - Portobello. Et il s'y est rendu à pieds. Alors cherchez-le là-bas.";
			link.l1 = "Merci, tu m'as été d'un grand secours!";
			link.l1.go = "exit";
			pchar.questTemp.Slavetrader = "FindRatPortobello";
			AddQuestRecord("Slavetrader", "21_1");
		break;
		//<--работорговец
		
		// Addon-2016 Jason ”ЊЉ-ѓваделупа
		case "FMQG":
			DelLandQuestMark(npchar);
			DelMapQuestMarkCity("panama");
			dialog.text = "Bertrand Pinette ? Français ? Jamais entendu parler de lui. Non, l'ami, nous n'avons pas vu de Français dans les parages depuis un moment.";
			link.l1 = "Quel dommage... Vous en êtes sûr ? Il est ami d'un important hidalgo nommé Don Carlos de Milyar. Ils devaient arriver ici ensemble.";
			link.l1.go = "FMQG_1";
		break;
		
		case "FMQG_1":
			dialog.text = "Señor de Milyar ? Ce gentilhomme a visité Panama il y a un an. En fait, Don Carlos de Milyar vit à Portobello. Il est un grand ami du gouverneur local.";
			link.l1 = "Je vois. Il n'était pas nécessaire de perdre du temps et de l'énergie dans la jungle. Merci, camarade.";
			link.l1.go = "FMQG_2";
		break;
		
		case "FMQG_2":
			DialogExit();
			pchar.questTemp.FMQG = "headhunter_portobello";
			AddQuestRecord("FMQ_Guadeloupe", "8");
			AddMapQuestMarkCity("PortoBello", true);
			AddLandQuestMark(characterFromId("PortoBello_tavernkeeper"), "questmarkmain");
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
