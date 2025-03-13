// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Quelles questions avez-vous ?","Comment puis-je vous aider ?"),"Vous avez essayé de me poser une question il y a peu de temps...","Je n'ai jamais rencontré de gens avec une telle curiosité dans mon chantier naval ou ailleurs dans cette ville.","Pourquoi toutes ces questions ? Mon travail est de construire des navires. Occupons-nous de cela.","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("J'ai changé d'avis...","Je n'ai rien à dire pour le moment."),"Oumph, où est passée ma mémoire...","Hm, eh bien...","Allez-y...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			// Addon-2016 Jason ”ЊЉ-Њартиника
			if (CheckAttribute(pchar, "questTemp.FMQM") && pchar.questTemp.FMQM == "begin")
            {
                link.l1 = "Ton homme m'a dit que tu voulais me voir. Je suis tout ouïe.";
                link.l1.go = "FMQM";
            }
			if (CheckAttribute(pchar, "questTemp.FMQM") && pchar.questTemp.FMQM == "oil" && GetSquadronGoods(pchar, GOOD_OIL) >= 50)
            {
                link.l1 = "J'ai fait le travail. "+FindRussianQtyString(GetSquadronGoods(pchar,GOOD_OIL))+" barils de résine sont dans mes cales.";
                link.l1.go = "FMQM_9";
            }
		break;
		
		// Addon-2016 Jason ”ЊЉ-Њартиника
		case "FMQM":
			pchar.quest.FMQM_Denial.over = "yes";
			dialog.text = "Oui-oui, capitaine "+GetFullName(pchar)+". J'ai vu votre navire entrer dans notre port et j'ai immédiatement envoyé mon ouvrier à votre rencontre. Passons directement aux affaires : vous êtes un nouveau venu, mais on dit que vous êtes déjà devenu un marin chevronné et que la fortune est de votre côté. C'est pourquoi j'ai une proposition commerciale pour vous.";
			link.l1 = "Intéressant ! Continuez, racontez-moi.";
			link.l1.go = "FMQM_1";
			DelLandQuestMark(npchar);
		break;
		
		case "FMQM_1":
			dialog.text = "As-tu déjà entendu parler de cette résine spéciale que les Espagnols produisent sur l'île de Trinidad ? C'est une ressource rare de valeur stratégique utilisée pour renforcer la coque des navires. Chaque baril coûte une somme rondelette car les Espagnols dirigent toute la résine vers les besoins de leur Marine. Chaque autorité coloniale garde le commerce de ce bien sous contrôle, pour faire simple, c'est de la pure contrebande.\nJ'ai besoin de cette résine pour une commande spéciale. Bien sûr, notre magasin n'en a pas, on peut dire la même chose de nos entrepôts militaires locaux ou ils ne veulent tout simplement pas la vendre. Cela n'a vraiment pas d'importance. Ce qui importe, c'est que j'ai besoin de la résine et je sais où en trouver. Tout ce qu'il me faut, c'est un capitaine à l'aise avec les abordages.";
			link.l1 = "Je pense que je commence à comprendre votre point de vue...";
			link.l1.go = "FMQM_2";
		break;
		
		case "FMQM_2":
			dialog.text = "Splendide. Maintenant écoutez, un petit convoi commercial a été localisé près de Trinidad ou, pour être plus précis, dans le port de San Jose. Un navire transporte un lot décent de la résine, la même résine dont j'ai cruellement besoin. Je vous en dirai plus si l'idée de piller les ennemis de notre nation vous plaît. Quelle est votre décision ?";
			link.l1 = "J'aime votre proposition. Je suis prêt à essayer.";
			link.l1.go = "FMQM_3";
			link.l2 = "Je vais passer, monsieur. Mon navire et mon équipage ne sont pas dans leur meilleur état en ce moment.";
			link.l2.go = "FMQM_exit";
		break;
		
		case "FMQM_exit":
			dialog.text = "Bien, c'est votre droit de faire ce que vous voulez. Désolé de vous avoir fait perdre votre temps, capitaine.";
			link.l1 = "Adieu.";
			link.l1.go = "FMQM_exit_1";
		break;
		
		case "FMQM_exit_1":
			DialogExit();
			pchar.questTemp.FMQM = "fail";
			AddQuestRecord("FMQ_Martinique", "3");
			CloseQuestHeader("FMQ_Martinique");
		break;
		
		case "FMQM_3":
			string sTemp = "barquentine";
			if (MOD_SKILL_ENEMY_RATE < 7) sTemp = "barque";// Addon 2016-1 Jason пиратскаЯ линейка
			dialog.text = "Alors écoute : le convoi se compose de trois navires, la résine sera parmi d'autres marchandises sur un "+sTemp+"appelé le 'Bensecho'. C'est votre cible principale. Comme je l'ai dit auparavant, les Espagnols naviguent de San Jose - Trinidad à San Juan - Porto Rico. Ils mettront les voiles demain, donc vous êtes libre de choisir où les attaquer.";
			link.l1 = "Compris. Et pour la récompense ?";
			link.l1.go = "FMQM_4";
		break;
		
		case "FMQM_4":
			dialog.text = "Tout ce qui m'intéresse, c'est la résine. Je paierai quinze doublons d'or pour chaque baril de cette substance. Selon mes informations, le 'Bensecho' transporte environ une centaine de barils.";
			link.l1 = "Sacrebleu! C'est une grosse somme!";
			link.l1.go = "FMQM_5";
		break;
		
		case "FMQM_5":
			dialog.text = "Oui. Je vous ai déjà dit que cette marchandise particulière est très chère et rare.";
			link.l1 = "Vous m'avez aussi dit que c'est une contrebande.";
			link.l1.go = "FMQM_6";
		break;
		
		case "FMQM_6":
			dialog.text = "N'ayez crainte, vous n'aurez pas besoin de l'apporter à la boutique ou aux contrebandiers. Venez me voir une fois le travail terminé, nous amarrerons votre navire dans mon chantier naval pour le réparer et ensuite déchargerons secrètement toute la cargaison la nuit. Personne ne soupçonnera rien.";
			link.l1 = "Tu penses plus vite que moi, maître. Très bien. Ne perdons pas de temps alors. Je suis en route pour prendre la mer.";
			link.l1.go = "FMQM_7";
		break;
		
		case "FMQM_7":
			dialog.text = "Bon vent, capitaine.";
			link.l1 = "... ";
			link.l1.go = "FMQM_8";
		break;
		
		case "FMQM_8":
			DialogExit();
			pchar.questTemp.FMQM = "convoy";
			AddQuestRecord("FMQ_Martinique", "4");
			SetFunctionTimerCondition("FMQM_ConvoyStart", 0, 0, 1, false);
		break;
		
		case "FMQM_9":
			dialog.text = "Excellent ! Mettons votre navire à quai comme convenu. Nous la déchargerons ce soir. Retournez à votre navire et laissez-moi préparer l'argent pour vous.";
			link.l1 = "Faisons cela.";
			link.l1.go = "FMQM_10";
			DelLandQuestMark(npchar);
		break;
		
		case "FMQM_10":
			pchar.quest.FMQM_Late.over = "yes";
			DialogExit();
			InterfaceStates.Buttons.Save.enable = false;
			chrDisableReloadToLocation = true;
			pchar.GenQuest.FrameLockEsc = true;
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], true);
			pchar.questTemp.FMQM = "remove_oil";
			pchar.questTemp.FMQM.Oil = "true";
			pchar.questTemp.FMQM.Qty = GetSquadronGoods(pchar, GOOD_OIL);
			DoQuestFunctionDelay("FMQM_WaitTime", 1.0);
			RemoveCharacterGoods(pchar, GOOD_OIL, GetSquadronGoods(pchar, GOOD_OIL));
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
