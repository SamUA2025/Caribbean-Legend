// Якоб ван Берг - злодей и пират, капитан Миража
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			if (CheckAttribute(pchar, "questTemp.HWIC.Holl") && pchar.questTemp.HWIC.Holl == "JacobInRoom")
			{
				dialog.text = "Argh! Hic... Wer zum Teufel bist du? Wo ist der verdammte Chinese? Ich rede mit dir, bist du taub? Hic!";
				link.l1 = "Ich höre dich laut und klar, also schrei nicht. Kein Chinese wird kommen. Ich bin an seiner Stelle hier.";
				link.l1.go = "HollJacob_inRoom";
				DelLandQuestMark(npchar);
				break;
			}
			dialog.text = "Ein Fehler. Sag es den Entwicklern.";
			link.l1 = "Wenn du meinst...";
			link.l1.go = "exit";
			NextDiag.TempNode = "First time";
		break;

		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		case "HollJacob_inRoom":
			dialog.text = "Was? Wer bist du? Was zum Teufel machst du hier? Ich habe dir eine Frage gestellt, Abschaum!";
			link.l1 = "Das brauchst du nicht zu wissen. Ich brauche dein Schiff.";
			link.l1.go = "HollJacob_inRoom_1";			
		break;
		
		case "HollJacob_inRoom_1":
			dialog.text = "Argh... Was?! Du verdammter... warte! Du bist ein verdammter englischer Hund! Zum Teufel! Sie haben mich schließlich aufgespürt... Ende der Linie für dich! Ich werde mich nicht ergeben!";
			link.l1 = "Nun, ich brauche nicht, dass du dich ergibst...";
			link.l1.go = "HollJacob_inRoom_fight";			
		break;
		
		case "HollJacob_inRoom_fight":
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.questTemp.HWIC.Holl.JacobCity+"_tavern_upstairs")], false);
			pchar.quest.JacobOnMainOver.over = "yes";//снять таймер
			chrDisableReloadToLocation = true;
			LAi_group_MoveCharacter(npchar, "EnemyFight");
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
            LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
            LAi_group_SetCheck("EnemyFight", "HollJacob_dead");
			DialogExit();
			AddDialogExitQuest("MainHeroFightModeOn");	
		break;
		
		case "JacobBerg_abordage":
			if (CheckAttribute(pchar, "questTemp.HWIC.Eng"))
			{
				dialog.text = "Argh! Verdammt! Was für ein Durcheinander! Du bist kein Händler, oder?";
				link.l1 = "So ein schlauer Junge. Meine Crew besteht aus ausgewählten englischen Marines, also warst du von Anfang an erledigt. Richard Fleetwood und ich haben die Geschichte des Händlers erfunden und hier bist du. Deine Abenteuer sind beendet, Bastard!";
				link.l1.go = "JacobBerg_abordage_1";
			}
			else
			{
				dialog.text = "Endlich haben wir uns getroffen, Kapitän. Du bist ein schlauer Kerl... Es ist zu lange her, seit ich einen so ernsthaften Gegner getroffen habe.";
				link.l1 = "Und ich bin dein letzter Gegner, Jacob. Du wirst hier nicht lebend rauskommen.";
				link.l1.go = "JacobBerg_abordage_3";
			}
		break;
		
		case "JacobBerg_abordage_1":
			dialog.text = "Es sieht so aus. Deine Crew hat das Schiff erobert und ich rechne nicht damit, verschont zu werden. Aber ich werde dich zur Hölle schicken, bevor sie dir zu Hilfe kommen! Van Berg wird sein Leben teuer verkaufen!";
			link.l1 = "Das ist nur deine Meinung. Ich denke, dass dein Leben keinen einzigen Pfennig wert ist. Genug dieser Worte, mach dich bereit!";
			link.l1.go = "JacobBerg_abordage_2";			
		break;
		
		case "JacobBerg_abordage_2":
			LAi_SetCurHPMax(NPChar);
			LAi_GetCharacterMaxEnergy(NPChar);			
			QuestAboardCabinDialogExitWithBattle(""); 
			DialogExit();	
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		
		case "JacobBerg_abordage_3":
			dialog.text = "Ach wirklich? Ich habe dafür gesorgt, dass du nicht entkommst. Ich habe eine Lunte zum Pulverraum geschickt. Bald werden unsere Schiffe in Stücke gesprengt.";
			link.l1 = "Ich denke, dass nur du und deine alte Badewanne in die Luft gehen werden. Ich werde dich ausnehmen, mein Schiff befreien und das Feuerwerk beobachten, während ich davon segel.";
			link.l1.go = "JacobBerg_abordage_4";			
		break;
		
		case "JacobBerg_abordage_4":
			dialog.text = "Nicht, wenn ich dich zuerst töte, aus dem Fenster springe, ans Ufer schwimme und das Feuerwerk selbst anschaue!";
			link.l1 = "Pflock?";
			link.l1.go = "JacobBerg_abordage_5";			
		break;
		
		case "JacobBerg_abordage_5":
			LAi_SetCurHPMax(NPChar);
			LAi_GetCharacterMaxEnergy(NPChar);			
			QuestAboardCabinDialogExitWithBattle("PrepareToBoom2"); 
			DialogExit();	
			AddDialogExitQuest("MainHeroFightModeOn");
			pchar.GenQuest.Detonation = true; // patch-4
		break;
}
}
