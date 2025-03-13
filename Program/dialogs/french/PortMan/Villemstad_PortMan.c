// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Quel genre de questions ?","Que veux-tu, "+GetAddress_Form(NPChar)+"?"),"Tu as déjà essayé de me poser une question "+GetAddress_Form(NPChar)+"...","Vous parlez de cette question pour la troisième fois aujourd'hui...","Écoute, si tu n'as rien à me dire concernant les affaires du port, alors ne me dérange pas avec tes questions.","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("J'ai changé d'avis.","Je n'ai rien à dire."),"Peu importe.","En effet, déjà la troisième fois...","Désolé, mais je ne suis pas intéressé par les affaires du port pour l'instant.",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";

			//работорговец
			if (pchar.questTemp.Slavetrader == "EscapeSlaveVillemstad_P")
            {
    			link.l1 = "Je voudrais en savoir plus sur la barque qui a disparu après la révolte des esclaves.";
    			link.l1.go = "EscapeSlave_Villemstad_P1";
            }
			//Голландский гамбит, против всех
			if (CheckAttribute(pchar, "questTemp.HWIC.Self") && pchar.questTemp.HWIC.Self == "SeekFleut")
            {
    			link.l1 = "Je veux trouver un capitaine nommé Toff Keller. Il possède un fluyt appelé 'Leiden'. On m'a dit qu'il visite souvent Willemstad, donc il ne sera pas difficile pour vous de m'aider.";
    			link.l1.go = "SeekTradeFleut";
            }
		break;

		//работорговец
		case "EscapeSlave_Villemstad_P1":
				dialog.text = "Hm... Et pourquoi cela t'intéresse-t-il? Les nègres sont ta spécialité?";
				link.l1 = "Je suis ici par ordre de Mathias Beck, le gouverneur. J'ai toutes les raisons de soupçonner que les nègres évadés ont volé ce navire et se sont enfuis avec. Je vous demande donc de m'assister de toutes les manières possibles dans ma recherche.";
				link.l1.go = "EscapeSlave_Villemstad_P2";
		break;
		
		case "EscapeSlave_Villemstad_P2":
				dialog.text = "Je vois. Eh bien, je ne peux pas vous aider. La barque '"+pchar.questTemp.Slavetrader.ShipName+"' était parti au matin, personne n'a rien vu. J'étais chez moi à dormir. Le gardien du quai a disparu aussi sans laisser de trace.\nLe gouverneur a envoyé un sloop pour essayer de le poursuivre tant que la piste était encore chaude, mais ils sont revenus bredouilles. Pas un signe des negres ni du '"+pchar.questTemp.Slavetrader.ShipName+"'. Pour être honnête, le sloop ne les a pas cherchés de trop près, tout le monde était encore en panique et pensait que des cafres sortiraient de la jungle en furie avec des fourches et des machettes - assoiffés de sang blanc.";
				link.l1 = "Ce n'était pas très utile, mais merci quand même. Adieu.";
				link.l1.go = "exit";
				AddQuestRecord("Slavetrader", "22_3");
				AddQuestUserData("Slavetrader", "sShipName", pchar.questTemp.Slavetrader.ShipName);
				pchar.questTemp.Slavetrader = "EscapeSlaveVillemstad_H";
		break;				
		//Голландский гамбит
		case "SeekTradeFleut":
			DelLandQuestMark(npchar);
			dialog.text = "Toff Keller ? Bien sûr que je le connais ! Il fait régulièrement des voyages vers San Jose, qui est sur la Trinidad, et Cumana. Il a récemment navigué vers Trinidad. Je suppose que tu peux le trouver là-bas.";
			link.l1 = "Merci !";
			link.l1.go = "SeekTradeFleut_1";
		break;
		
		case "SeekTradeFleut_1":
			DialogExit();
			AddMapQuestMarkIsland("Trinidad", true);
			pchar.questTemp.HWIC.Self = "FleutOnTrinidad";
			AddQuestRecord("Holl_Gambit", "3-59");
			pchar.quest.Seek_Fleut.win_condition.l1 = "location";
			pchar.quest.Seek_Fleut.win_condition.l1.location = "Trinidad";
			pchar.quest.Seek_Fleut.function = "CreateTradeFleut";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
