// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Quelles questions avez-vous ?","Comment puis-je vous aider ?"),"Tu as essayé de me poser une question il y a un moment...","Je n'ai jamais rencontré de gens avec une telle curiosité dans mon chantier naval ou ailleurs dans cette ville.","Pourquoi toutes ces questions ? Mon travail est de construire des navires. Occupons-nous de cela.","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("J'ai changé d'avis...","Je n'ai rien à dire pour le moment."),"Oumph, où est passée ma mémoire...","Hm, eh bien...","Continuez...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			// Addon 2016-1 Jason пиратскаЯ линейка
			if (CheckAttribute(pchar, "questTemp.Mtraxx") && pchar.questTemp.Mtraxx == "silk_2")
            {
                link.l1 = "Ecoutez, maître, vous construisez des navires ici, n'est-ce pas?.. Et vous changez aussi les voiles... avez-vous déjà pensé à... un meilleur tissu pour les voiles ?";
                link.l1.go = "mtraxx";
			}
		break;
		
		// Addon 2016-1 Jason пиратскаЯ линейка
		case "mtraxx":
            dialog.text = "Vous parlez par énigmes, monsieur... Parlez franchement, qu'est-ce qui vous amène ici ? Ne vous inquiétez pas, je ne suis pas du genre à jouer les gratte-papiers et ici ce n'est pas la douane.";
			link.l1 = "Ah, je suis heureux que nous soyons sur la même longueur d'onde ! Toile de voile en soie, monsieur. D'après ce que je comprends, il n'y a pas de meilleur matériau pour les voiles si la vitesse est votre préoccupation.";
			link.l1.go = "mtraxx_1";
		break;
		
		case "mtraxx_1":
            dialog.text = "Non seulement la vitesse, mais aussi sa capacité à naviguer au vent. Vous proposez de la soie navale à l'achat ? C'est une cargaison précieuse, en effet. Mais il y a un obstacle : je ne sais tout simplement pas comment l'utiliser en production. Suivez-vous ? Un matériau comme celui-ci nécessite un ensemble très spécial de capacités et de compétences que je n'ai pas. Pour être honnête, mon chantier naval a une spécialisation très différente, si vous m'aviez proposé des cordages du Tsarat de Russie, je les achèterais volontiers tous, peu importe le prix. Nous avons constamment besoin de cordages, cependant la soie navale n'est pas en demande ici, je suis désolé !";
			link.l1 = "Hm. Je vois. Merci pour votre temps, maître. Bonne chance !";
			link.l1.go = "mtraxx_2";
		break;
		
		case "mtraxx_2":
            DialogExit();
			AddQuestRecord("Roger_2", "4");
			pchar.questTemp.Mtraxx = "silk_3";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
