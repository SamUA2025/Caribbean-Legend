// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Quelles questions avez-vous?","Comment puis-je vous aider, "+GetAddress_Form(NPChar)+"?"),"Qu'est-ce que c'est, "+GetAddress_Form(NPChar)+"...","C'est la troisième fois que tu me déranges maintenant...","Plus de questions, je présume?","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("J'ai changé d'avis...","Je n'ai rien à dire pour le moment."),"Humph, où est passée ma mémoire...","Oui, c'est vraiment la troisième fois...","Non, quelles questions?...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			//Jason, суп из черепахи
			if (CheckAttribute(PChar, "questTemp.Terrapin") && pchar.questTemp.Terrapin == "baster" && !CheckAttribute(npchar, "quest.terrapin"))
			{
				link.l1 = "Je cherche mon vieux compagnon de bord Fernand Luc. J'ai deux ou trois questions à lui poser. J'ai entendu dire qu'il s'est bien amusé ici il y a une semaine...";
				link.l1.go = "terrapin";
			}
			//Sinistra Путеводная звезда
			if (CheckAttribute(pchar, "questTemp.PZ_BasTerTavern"))
			{
				link.l1 = "Mon ami et moi avions convenu de nous rencontrer ici, mais je ne le vois nulle part. Savez-vous où il est allé ? Est-il encore en ville, ou au moins sur l'île ? Il s'appelle Longway - il est chinois.";
				link.l1.go = "PZ_BasTerTavern_1";
			}
		break;
		
		//суп из черепахи
		case "terrapin":
			dialog.text = "Il pourrait encore passer du bon temps en enfer. Ton compagnon est mort, donc tu arrives un tantinet tard, capitaine. Cet homme là-bas, assis à la table la plus éloignée, a payé pour ses funérailles, bien que j'aie l'impression que c'est le même homme qui les a causées. Il a une tête de pendu, comme on dit. Il s'appelle Robert Martene. Si tu veux, tu peux aller le voir et lui demander toi-même. ";
			link.l1 = "Merci, l'ami. Je vais aller parler à monsieur Robert. Nous boirons à l'âme du pauvre vieux Luc pour qu'il repose en paix...";
			link.l1.go = "terrapin_1";
			npchar.quest.terrapin = "true";
		break;
		
		case "terrapin_1":
			DialogExit();
			AddQuestRecord("Terrapin", "4");
			pchar.questTemp.Terrapin = "rober";
		break;
		
		// Sinistra - Квест "Длинные тени старых грехов" ==>
		case "DTSG_BasTerTavern_1":
			dialog.text = "Y a-t-il vraiment à discuter? Il t'a attaqué, toi et ton ami, tu t'es défendu, je vois ça presque tous les jours. Beau boulot. Maintenant, je n'ai plus qu'à nettoyer ce bazar...";
			Link.l1 = "Vous nettoierez ça, je suis sûr que vous y êtes habitué maintenant. Que savez-vous de lui ?";
			Link.l1.go = "DTSG_BasTerTavern_2";
		break;
		
		case "DTSG_BasTerTavern_2":
			dialog.text = "Pas grand-chose, vraiment. Il est arrivé il y a quelques jours. Il appréciait l'endroit, a même loué une maison à la périphérie de la ville. Il venait souvent, payait régulièrement. Et, le plus important, il s’est comporté correctement tout ce temps, n’a jamais dit un mauvais mot à personne. Je suis encore choqué qu'il vous ait attaqué, vous et votre ami. Je pensais qu'il pourrait s'installer ici pour de bon.";
			Link.l1 = "D'une certaine manière, il l'a fait. Bon, ce n'est pas grand-chose, mais merci pour ça, mon ami. À la prochaine.";
			Link.l1.go = "DTSG_BasTerTavern_3";
		break;
		
		case "DTSG_BasTerTavern_3":
			DialogExit();
			DeleteAttribute(pchar, "questTemp.DTSG_BasTerTavern");
			LAi_LocationDisableOfficersGen("BasTer_tavern", false);
			SetQuestHeader("DTSG");
			AddQuestRecord("DTSG", "1");
			bDisableFastReload = false;
			chrDisableReloadToLocation = false;
			
			sld = CharacterFromID("Knippel");
			LAi_SetOfficerType(sld);
			sld.Dialog.Filename = "Quest\HollandGambit\Knippel.c";
			sld.Dialog.CurrentNode = "Knippel_officer";
			sld.location = "None";
			
			PChar.quest.DTSG_BasTerDom.win_condition.l1 = "locator";
			PChar.quest.DTSG_BasTerDom.win_condition.l1.location = "BasTer_town";
			PChar.quest.DTSG_BasTerDom.win_condition.l1.locator_group = "reload";
			PChar.quest.DTSG_BasTerDom.win_condition.l1.locator = "HutFish1";
			PChar.quest.DTSG_BasTerDom.win_condition = "DTSG_BasTerDom";
			
			SetTimerCondition("DTSG_BasTerDom_Timer", 0, 0, 7, false);
			SetTimerCondition("DTSG_Etap2", 0, 0, 14, false);
		break;
		// <== Квест "Длинные тени старых грехов" - Sinistra
		
		// Sinistra - Квест "Путеводная звезда" ==>
		
		case "PZ_BasTerTavern_1":
			dialog.text = "Ce nom ne me dit rien, et en général, je ne laisse pas entrer des gens comme lui dans mon établissement, ni je ne m'y intéresse.";
			Link.l1 = "D'accord. Très bien, à plus tard.";
			Link.l1.go = "PZ_BasTerTavern_2";
		break;
		
		case "PZ_BasTerTavern_2":
			DialogExit();
			bDisableLandEncounters = true;
			DeleteAttribute(pchar, "questTemp.PZ_BasTerTavern");
			DeleteAttribute(pchar, "questTemp.PZ_BasTerAlkash");
			pchar.questTemp.PZ_BasTerTavern2 = true;
			DeleteQuestCondition("PZ_BasTer_Opozdal");
			DelMapQuestMarkIsland("Guadeloupe");
			
			PChar.quest.PZ_BasTer_Strazha.win_condition.l1 = "location";
			PChar.quest.PZ_BasTer_Strazha.win_condition.l1.location = "BasTer_town";
			PChar.quest.PZ_BasTer_Strazha.win_condition = "PZ_BasTer_Strazha";
		break;
		
		// <== Квест "Путеводная звезда" - Sinistra
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
