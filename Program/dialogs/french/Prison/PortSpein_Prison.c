// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
 	switch(Dialog.CurrentNode)
	{
        case "quests":
            dialog.text = "Parle, je t'écoute";
			link.l1 = "Je me suis trompé. Adieu.";
			link.l1.go = "Exit";
			//Цена чахотки
			if (!CheckAttribute(npchar, "quest.Consumption") && CheckAttribute(pchar, "questTemp.Consumption") && pchar.questTemp.Consumption == "begin")
			{
				link.l1 = "On m'a informé qu'il y a une épidémie ici, ai-je raison?";
				link.l1.go = "Consumption";
			}
		break;
		
		//--> Цена чахотки
		case "Consumption":
			dialog.text = "Tu as raison, alors évite de visiter les cachots sans une raison sérieuse. Pourquoi t'intéresses-tu à cela ?";
			link.l1 = "Juste par curiosité. Donc, si mes gars se saoulent trop, font trop de bruit et finissent ici, devrais-je préparer du linge jaune alors ?";
			link.l1.go = "Consumption_1";
		break;
		
		case "Consumption_1":
			dialog.text = "Hélas, monsieur, je ne saisis pas la plaisanterie si c'en était une. Les cachots sont humides et froids et vous connaissez le climat. La consomption est un visiteur fréquent dans ces cachots. Je dois même payer mes gars pour apporter de la nourriture aux cellules. Patrouiller là-bas est considéré comme un travail forcé.";
			link.l1 = "Je suis désolé, je voulais juste savoir, à quel point est-ce sérieux ?";
			link.l1.go = "Consumption_2";
		break;
		
		case "Consumption_2":
			dialog.text = "Bien trop sérieux. Nous n'avons même pas de médecin ici, il est mort de cette maudite consommation aussi. Maintenant, seul un médecin de la garnison locale examine les prisonniers une fois par semaine. Mais qui se soucie de ces vagabonds et criminels ?\nLa plupart des gens pensent qu'ils méritaient totalement un tel sort et il est difficile de discuter de cela.";
			link.l1 = "Mes connaissances en médecine sont modestes, mais pour autant que je sache, la consomption est dangereuse et mortelle, mais elle ne tue pas les gens en quelques jours comme c'est le cas ici. Les victimes ne devraient-elles pas souffrir pendant des mois, voire des années ?";
			link.l1.go = "Consumption_3";
		break;
		
		case "Consumption_3":
			dialog.text = "Comme vous venez de le mentionner, vous n'êtes pas médecin, donc parler des caractéristiques de la maladie pourrait être juste... un mensonge inventé. J'ai simplement répété ce que notre médecin disait avant que la maladie ne l'emporte aussi. Je ne comprends donc pas votre curiosité et votre comportement cynique. Les gens meurent ici !";
			link.l1 = "N'as-tu pas dit qu'ils le méritaient ?";
			link.l1.go = "Consumption_4";
		break;
		
		case "Consumption_4":
			dialog.text = "Assez, senior ! Je crois que vous et moi avons d'autres affaires à traiter que de rivaliser d'esprit. La porte est juste derrière vous.";
			link.l1 = "Bien, pardonnez mon manque de tact, je pars déjà.";
			link.l1.go = "Consumption_5";
		break;
		
		case "Consumption_5":
			DialogExit();
			npchar.quest.Consumption = "true";
			pchar.questTemp.Consumption.Commandant = "true";
			AddQuestRecord("Consumption", "3");
			pchar.quest.Consumption.win_condition.l1 = "location";
			pchar.quest.Consumption.win_condition.l1.location = "PortSpein_houseF2";
			pchar.quest.Consumption.function = "Consumption_CommandantHouse";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
