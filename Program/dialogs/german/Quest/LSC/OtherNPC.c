// диалоги прочих НПС по квесту LSC
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
	int i;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			dialog.text = "Brauchst du etwas?";
			link.l1 = "Nein, es ist nichts.";
			link.l1.go = "exit";			
			NextDiag.TempNode = "First time";
		break;
		
		//-----------------------------------бандосы Акулы в трюме с припасами--------------------------------------
		case "PantryGuard":
			dialog.text = "Ho, ho, schaut euch das mal an, Jungs! Wer kommt uns denn da besuchen! Ein Dieb, der die Kisten der Leute plündert! Komm her! Und du, Kumpel, versuch erst gar nicht, dich dumm zu stellen und dein Schwert zu zücken - ich werde aus so kurzer Entfernung nicht verfehlen... Chad wird sich wirklich freuen, dich zu sehen!";
			link.l1 = "Aber ich... Ich bin gerade erst angekommen!";
			link.l1.go = "PantryGuard_1";
		break;
		
		case "PantryGuard_1":
			dialog.text = "Du hast recht, ha-ha! Du bist wirklich in eine schöne Misere geraten, Kumpel... Und du wirst nicht entkommen. Jetzt, gib deine Waffen ab und folge mir! Der Käfig auf dem 'Tartarus' wartet schon so lange auf dich, Dieb!";
			link.l1 = "...";
			link.l1.go = "PantryGuard_2";
		break;
		
		case "PantryGuard_2":
			DialogExit();
			chrDisableReloadToLocation = false;
			SetLaunchFrameFormParam("Few hours later...", "", 0, 3);
			LaunchFrameForm();
			WaitDate("", 0, 0, 0, 7, 10); //крутим время
			RecalculateJumpTable();
			DoQuestFunctionDelay("LSC_GotoPrison", 3.0);
		break;
		
		case "CommonGuard":
			dialog.text = "Versuch nicht, hier etwas zu stehlen. Ich werde dich beobachten.";
			link.l1 = "Sie sind herzlich willkommen.";
			link.l1.go = "exit";
			NextDiag.TempNode = "CommonGuard";
		break;
		
		case "ChadGuard":
			dialog.text = "Geh und tu, was Chad dir gesagt hat. Rede nicht zu viel!";
			link.l1 = "Ja, ich bin auf dem Weg...";
			link.l1.go = "exit";
			NextDiag.TempNode = "ChadGuard";
		break;
		
		case "ChadGuard_Attack":
			dialog.text = "He! Was zur Hölle machst du da? Bastard! Jetzt bist du dran!";
			link.l1 = "...";
			link.l1.go = "ChadGuard_Attack_1";
		break;
		
		case "ChadGuard_Attack_1":
			DialogExit();
			sld = characterFromId("Chimiset");
			LAi_SetActorType(sld);
			LAi_ActorAnimation(sld, "afraid", "", -1);
			for(i = 1; i <= 3; i++)
			{				
				sld = CharacterFromID("ChadGuard_"+i);
				LAi_RemoveCheckMinHP(sld);
				LAi_SetWarriorType(sld);
				LAi_group_MoveCharacter(sld, "EnemyFight");
			}
			sld = characterFromId("Capper");
			LAi_SetWarriorType(sld);
			ChangeCharacterAddressGroup(sld, "Tartarusprison", "goto", "goto8");
			LAi_group_MoveCharacter(sld, "EnemyFight");
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("EnemyFight", "LSC_ChadGuard_Die");
			AddDialogExitQuest("MainHeroFightModeOn");
			pchar.GenQuest.Notsearchbody = true; // запрет обыска трупов
		break;
		
		// ----------------------------------Марчелло Циклоп--------------------------------
		// если ждали в каюте
		case "Cabin":
			dialog.text = "He, was zur Hölle machst du hier, verdammt noch mal? Wo ist Barbier?";
			link.l1 = "Unser Freund Adolfo ist ... krank. Er konnte nicht zum Treffen kommen, also bat er mich, ein wenig in seiner Kabine zu sitzen und auf dich zu warten.";
			link.l1.go = "Cabin_1";
		break;
		
		case "Cabin_A":
			dialog.text = "He, was zur Hölle machst du hier, verdammt noch mal?";
			link.l1 = "Unser Freund Adolfo ist... krank. Er konnte nicht zum Treffen kommen, also bat er mich, an seiner Stelle zu sein. Sozusagen.";
			link.l1.go = "Cabin_1";
		break;
		
		case "Cabin_1":
			dialog.text = "Klingt seltsam... er war heute Morgen noch in Ordnung und jetzt ist er krank.";
			link.l1 = "Nun, Sie wissen, wie die Dinge passieren. Der plötzliche Fieberanfall...";
			link.l1.go = "Cabin_2";
		break;
		
		case "Cabin_2":
			dialog.text = "Oh, ich mag dein Gesicht nicht. Du lügst. Barbier würde dieses Treffen niemand anderem anvertrauen. Sprich, Bastard, wer bist du und was hast du mit ihm gemacht?";
			link.l1 = "Weißt du, du bist auch kein hübsches Gesicht. Ich habe dir bereits gesagt, dass Barbier krank ist. Bist du ein langsamer Denker oder soll ich mich wiederholen? Er sollte dir den Schlüssel geben und...";
			link.l1.go = "Cabin_3";
		break;
		
		case "Cabin_3":
			DialogExit();
			sld = characterFromId("Mary");
			LAi_SetActorType(sld);
			LAi_CharacterEnableDialog(sld);
			LAi_ActorDialog(sld, pchar, "", -1, 0);
		break;
		
		// на Церес Смити - спасаем Мэри
		case "mary":
			dialog.text = "Verdammt! Du hast mich aufgespürt...";
			link.l1 = "Ja, Abschaum! Du wirst sie nicht berühren! Bereite dich auf den Tod vor!";
			link.l1.go = "mary_1";
		break;
		
		case "mary_1":
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);//разрешить драться
			DialogExit();
			LAi_SetWarriorType(npchar);
			LAi_group_MoveCharacter(npchar, "EnemyFight");
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("EnemyFight", "LSC_KillCyclop_CS");
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		
		// посланник от Акулы по варианту N
		case "SharkCureer":
			dialog.text = "Bist du "+GetFullName(pchar)+"?";
			link.l1 = "Ja, ich bin es. Was ist los?";
			link.l1.go = "SharkCureer_1";
		break;
		
		case "SharkCureer_1":
			dialog.text = "Hai hat mich geschickt. Er bittet dich, ihn so schnell wie möglich zu sehen. Er hat etwas Wichtiges für dich.";
			link.l1 = "Wo ist die Eile?.. Gut, ich gehe sofort zur 'San Agustin'.";
			link.l1.go = "SharkCureer_2";
		break;
		
		case "SharkCureer_2":
			// сюда можно поставить таймер на гибель Акулы, если не придёт до конца суток
			DialogExit();
			LAi_SetActorType(npchar);
			npchar.lifeday = 0;
			LAi_ActorGoToLocation(npchar, "reload", "reload1", "none", "", "", "", -1);
			sld = characterFromId("Dodson");
			sld.dialog.currentnode = "entrance_20"; // ноду Акуле
		break;
		
		// посланник от Акулы по варианту M
		case "SharkCureer_3":
			dialog.text = "Bist du "+GetFullName(pchar)+"?";
			link.l1 = "Ja, das bin ich. Was ist los?";
			link.l1.go = "SharkCureer_4";
		break;
		
		case "SharkCureer_4":
			if (!CheckAttribute(pchar, "questTemp.Saga.DodsonDie"))
			{
				dialog.text = "Uh, ich bin es leid, dich zu suchen... Der Hai und Layton Dexter. Sie bitten dich, sie sofort zu sehen. Es ist eine sehr wichtige Angelegenheit, also beeile dich.";
				link.l1 = "Ist es das? Gut, ich gehe sofort zum 'San Agustin'.";
				link.l1.go = "SharkCureer_6";
			}
			else
			{
				dialog.text = "Uh, ich habe es satt, dich zu suchen... Admiral Layton Dexter bittet dich, ihn sofort zu sehen. Es ist eine sehr wichtige Angelegenheit, also beeil dich.";
				link.l1 = "Admiral?";
				link.l1.go = "SharkCureer_5";
			}
		break;
		
		case "SharkCureer_5":
			dialog.text = "Ja. Als zweiter in der Befehlshierarchie wurde er nach dem Tod des Hais unser Admiral.";
			link.l1 = "Ich verstehe. Gut, ich gehe sofort zum 'San Agustin'.";
			link.l1.go = "SharkCureer_6";
		break;
		
		case "SharkCureer_6":
			DialogExit();
			LAi_SetActorType(npchar);
			npchar.lifeday = 0;
			LAi_ActorGoToLocation(npchar, "reload", "reload1", "none", "", "", "", -1);
		break;
		
		// тюремщик вместо Каппера
		case "Prisonboss":
			if (npchar.quest.meeting == "0")
			{
				dialog.text = "Ach, da bist du... Ich erinnere mich an dich, du bist der letzte Mann, der mit Chimiset gesprochen hat. Hast du ihn getötet?";
				link.l1 = "Hör auf mit dem Scheiß! Du weißt ganz genau, dass ich es nicht war. Ich glaube, du weißt, wer der Mörder ist.";
				link.l1.go = "meeting";
				npchar.quest.meeting = "1";
			}
			else
			{
				dialog.text = "Eh, es ist so langweilig, den ganzen Tag hier zu bleiben! Wenn du nur Rum und Karten mitbringen würdest, Kumpel, könnten wir vielleicht ein Spielchen wagen...";
				link.l1 = "Entschuldigung, Kumpel, ich habe keine Zeit dafür. Vielleicht später.";
				link.l1.go = "exit";
			}
			NextDiag.TempNode = "Prisonboss";
		break;
		
		case "meeting":
			dialog.text = "Ich habe ein paar Vermutungen, ja, aber ich habe keine Fakten. Niemand hat den Tod des schwarzen Kerls gesehen. Es gibt Gerüchte auf der ganzen Insel, dass wir, Sharks Leute, verantwortlich sind und sie sagen, dass irgendein Neuling dies auf Befehl des Admirals getan hat. Siehst du jetzt? Also geh nicht zu Rivados, besonders jetzt. Sie sind zu wütend.";
			link.l1 = "Gut. Ich habe es verstanden.";
			link.l1.go = "exit";
			NextDiag.TempNode = "Prisonboss";
		break;
		
		case "Prisonboss_M":
			dialog.text = "Eh, es ist so langweilig, den ganzen Tag hier zu bleiben! Wenn du nur Rum und Karten hierher bringen würdest, Kumpel, könnten wir vielleicht ein Spielchen wagen...";
			link.l1 = "Entschuldigung, Kumpel, ich habe keine Zeit für sowas. Vielleicht später.";
			link.l1.go = "exit";
			NextDiag.TempNode = "Prisonboss_M";
		break;
		
		// заместитель Акселя в магазине
		case "AxelHelper":
			dialog.text = "Was willst du, Kumpel?";
			link.l1 = "Hm. Und was machen Sie hier? Wo ist Axel?";
			link.l1.go = "AxelHelper_1";
		break;
		
		case "AxelHelper_1":
			dialog.text = "Axel ist beschäftigt. Er hat ein Treffen mit Donald Greenspen und er wird bis zum Ende des Tages bei ihm bleiben. Also, wenn du etwas kaufen willst - sprich morgen früh mit ihm. Und ich passe auf den Laden auf, also versuche nichts zu stehlen...";
			link.l1 = "Ich verstehe. Und warum macht er das heute? Gut, ich werde morgen früh hierher kommen.";
			link.l1.go = "exit";
			NextDiag.TempNode = "AxelHelper_2";
		break;
		
		case "AxelHelper_2":
			dialog.text = NPCStringReactionRepeat("Ich habe dir bereits alles erzählt. Komm morgen hierher.","Stör mich nicht, Kumpel. Hau ab!","Mach mich nicht wütend, Trottel!","Geh weg!!","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Gut.","Ich habe es, ich habe es.","Halt den Mund...","Was?!",npchar,Dialog.CurrentNode);
			link.l1.go = DialogGoNodeRepeat("exit", "", "", "", npchar, Dialog.CurrentNode);
		break;
		
		// мать Белого Мальчика - Агнес Кристиансен
		case "agnes":
			dialog.text = "Was wollen Sie, mein Herr?";
			link.l1 = "Hm... Es tut mir leid, Herrin. Verzeihen Sie meine Unverschämtheit und schlechten Manieren, aber ich möchte Sie etwas fragen: Kennen Sie einen Mann namens Ole Christiansen?";
			link.l1.go = "agnes_1";
		break;
		
		case "agnes_1":
			dialog.text = "Wiederhole noch einmal, was du gesagt hast... Ole Christiansen? Ole?!";
			link.l1 = "Ja. Sie nennen ihn auch den Weißen Jungen wegen seiner besonderen Haarfarbe. Kennst du ihn?";
			link.l1.go = "agnes_2";
		break;
		
		case "agnes_2":
			dialog.text = "Kenne ich ihn?! Er ist mein Sohn und er ist seit einem Jahrzehnt verschwunden! Wissen Sie, wo er ist, mein Herr? Sagen Sie mir schon, wo er ist, was ist mit ihm passiert?!";
			link.l1 = "Beruhigen Sie sich, Herrin, machen Sie sich keine Sorgen. Er geht es gut. Er ist auf meinem Schiff. Alles, was er tun muss, ist anzulegen und hierher zu kommen.";
			link.l1.go = "agnes_3";
		break;
		
		case "agnes_3":
			dialog.text = "Oh... Es scheint, dass der Herr endlich meine Gebete gehört hat! Sie können sich nicht vorstellen, wie ich mich gesorgt habe, als er vermisst wurde! Und es war mein und nur mein Fehler! Wo haben Sie ihn gefunden? Er ist kein gewöhnlicher Junge... nun, Sie müssen wissen, wovon ich spreche.";
			link.l1 = "Ich schon. Ja, er ist etwas Besonderes. Und er hat sich nicht verändert. Es scheint, dass er immer noch ein Kind ist. Ich habe ihn auf einer Insel gefunden. Wir haben uns zufällig getroffen. Er fragte mich nach einer weißen Perle... verdammt!... Nach einer Perle.";
			link.l1.go = "agnes_4";
		break;
		
		case "agnes_4":
			dialog.text = "Eine Perle? Oh, Gott! Perlen waren der Grund, warum mein Junge verschwunden ist! Es ist alles wegen dieser verdammten Halskette!";
			link.l1 = "Ist es wahr, dass Ole... sein Zuhause verlassen hat, weil er deine Perlenkette zerrissen hat?... Beruhige dich, Herrin, weine nicht!";
			link.l1.go = "agnes_5";
		break;
		
		case "agnes_5":
			dialog.text = "Ja, es ist wahr. Ole hat meine Halskette am Pier zerrissen und alle Perlen fielen ins Wasser. Ich habe so auf ihn geschimpft und mein verstorbener Ehemann... hat ihn bestraft. Ole verschwand am nächsten Tag. Du kannst dir nicht vorstellen, wie sehr ich mir Vorwürfe gemacht habe!";
			link.l1 = "Ole sammelt seit Jahren Perlen. Er nennt sie die weißen Perlen. Er hat sie alle für dich gesammelt und mich gebeten, ihn zu dir zu bringen. Ich hatte keine Details außer dem Haus mit dem roten Dach. Aber ich habe es endlich geschafft, dich zu finden.";
			link.l1.go = "agnes_6";
		break;
		
		case "agnes_6":
			dialog.text = "Sammeln von Perlen?! Oh, Gott! Ich bin meinem armen Jungen so schuldig! Ich... und er hat Perlen gesammelt! Oh!";
			link.l1 = "Ich vermute, ich sollte besser Ihren Sohn rufen, Herrin. Er war so begierig darauf, Sie zu sehen. Er sagte, dass Sie sich freuen werden, Perlen zu sehen. Aber ich denke, Sie werden nicht wegen ihnen glücklich sein...";
			link.l1.go = "agnes_7";
		break;
		
		case "agnes_7":
			dialog.text = "Herr... wären Sie so freundlich. Bringen Sie mir meinen Ole. Ich möchte ihn umarmen und um seine Vergebung bitten...";
			link.l1 = "Sicher, Herrin. Sie werden ihn sofort hierher bringen.";
			link.l1.go = "agnes_8";
		break;
		
		case "agnes_8":
			DialogExit();
			SetLaunchFrameFormParam("One hour later", "", 0, 5);
			LaunchFrameForm();
			WaitDate("", 0, 0, 0, 1, 10); //крутим время
			RecalculateJumpTable();
			DoQuestFunctionDelay("LSC_OleGoHome", 5.0);
		break;
		
		case "agnes_9":
			dialog.text = "";
			link.l1 = "Nun, Meisterin, hier ist Ihr Sohn - Ole Christiansen. Erkennen Sie ihn?";
			link.l1.go = "agnes_10";
		break;
		
		case "agnes_10": // перекидываем pchar
			DialogExit();
			LAi_SetActorType(pchar);
			LAi_ActorTurnToCharacter(pchar, characterFromID("Agnes"));
			ChangeShowIntarface();
			SetMainCharacterIndex(GetCharacterIndex("Agnes"));
			PChar = GetMainCharacter();			
			LAi_SetPlayerType(PChar);
			sld = characterFromId("Ole");
			sld.dialog.currentnode = "home";
			LAi_SetActorType(sld);
			LAi_ActorDialog(sld, pchar, "", -1, 0);
		break;
		
		case "agnes_11":
			dialog.text = "Herr... es tut mir leid, ich habe nicht nach Ihrem Namen gefragt... "+pchar.name+"?";
			link.l1 = ""+GetFullName(pchar)+", Herrin. Kapitän "+GetFullName(pchar)+".";
			link.l1.go = "agnes_12";
		break;
		
		case "agnes_12":
			dialog.text = "Kapitän, Sie können sich nicht vorstellen, wie dankbar ich für meinen Sohn bin! Sie haben ihm geholfen und ihn hierher gebracht. Sie haben mir das Leben zurückgegeben! Ich werde alles für meinen Jungen tun, ich werde ihm all meine Liebe geben, die er all die Jahre vermisst hat.";
			link.l1 = "Ich freue mich für Sie, Herrin. Und auch für Ole. Er ist ein guter Junge und hat mir in einer schwierigen Situation geholfen. Er hat ein gutes Herz. Ich kenne einen Mann, der von Ole vor dem Tod gerettet wurde.";
			link.l1.go = "agnes_13";
		break;
		
		case "agnes_13":
			dialog.text = "Mynheer, ich bestehe darauf, dass Sie morgen oder jederzeit, wenn Sie Zeit finden, hierher kommen müssen. Ich möchte Ihnen für meinen Sohn danken. Im Moment bin ich nur ein bisschen... nun, Sie wissen schon.";
			link.l1 = "Ich tue es, Herrin.";
			link.l1.go = "agnes_14";
		break;
		
		case "agnes_14":
			dialog.text = "Komm morgen wieder hierher. Ich werde dich angemessen für all das Gute belohnen, das du meinem Sohn und mir getan hast.";
			link.l1 = "Gut. Ich werde dich sicher besuchen!";
			link.l1.go = "agnes_15";
		break;
		
		case "agnes_15":
			DialogExit();
			bDisableCharacterMenu = false;//лоченые интерфейсы
			chrDisableReloadToLocation = false;//открыть локацию
			LAi_SetOwnerType(npchar);
			LocatorReloadEnterDisable("Marigo_town", "houseSp2", true);
			NextDiag.CurrentNode = "agnes_16";
			pchar.quest.LSC_Ole_return.win_condition.l1 = "Timer";
			pchar.quest.LSC_Ole_return.win_condition.l1.date.hour  = 8.0;
			pchar.quest.LSC_Ole_return.win_condition.l1.date.day   = GetAddingDataDay(0, 0, 1);
			pchar.quest.LSC_Ole_return.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 1);
			pchar.quest.LSC_Ole_return.win_condition.l1.date.year  = GetAddingDataYear(0, 0, 1);
			pchar.quest.LSC_Ole_return.function = "LSC_OleAgnesRegard";
			// удаляем Оле из пассажиров
			sld = characterFromId("Ole");
			RemovePassenger(Pchar, sld);
			DeleteAttribute(pchar, "GenQuest.Ole");
			DoQuestReloadToLocation("Marigo_town", "reload", "houseSp2", "");
		break;
		
		case "agnes_16":
			dialog.text = "Ach, da bist du ja, mein Herr "+GetFullName(pchar)+"! Komm, setz dich...";
			link.l1 = "Danke! Wie geht es Ole?";
			link.l1.go = "agnes_17";
		break;
		
		case "agnes_17":
			dialog.text = "Oh, du kannst dir nicht vorstellen, was du getan hast! Du warst ein Anblick für mein leidvolles Mutterherz... Ich bin dir zu Dank verpflichtet und werde für immer für dich beten.";
			link.l1 = "Sie bringen mich zum Erröten, Herrin...";
			link.l1.go = "agnes_18";
		break;
		
		case "agnes_18":
			dialog.text = "Ich wusste immer, dass Bescheidenheit das ist, was edle Menschen edel macht... Ich habe Geschenke für das vorbereitet, was du getan hast. Ja-ja! Und wage es nicht einmal abzulehnen! Hier, nimm das... Zuerst gibt es eine Truhe voller Dublonen. Zweitens, nimm diesen verzauberten Amulett, sie nennen es einen Skarabäus\nMein Mann besaß ihn, und ich bin sicher, dass er sich gefreut hätte zu wissen, dass sein Schatz einem so edlen Kapitän gehören wird, der meinen Sohn zu mir zurückgebracht hat. Mein Mann war ein Zimmermann, er pflegte zu sagen, dass der Skarabäus seine Arbeit beschleunigt\nIch hoffe, dass dieser Ring dir gut dienen wird. Du verdienst es zweifellos, ihn zu tragen! Und schließlich, nimm meine Schneiderwerkzeuge. Es ist ein feines Set. Du wirst in der Lage sein, eine Menge guter Dinge damit herzustellen.";
			link.l1 = "Oh! Das sind wirklich wertvolle Geschenke für jeden Kapitän! Danke, Herrin.";
			link.l1.go = "agnes_19";
		break;
		
		case "agnes_19":
			PlaySound("interface\important_item.wav");
			Log_Info("You have received a chest with doubloons");
			Log_Info("You have received the 'Scarab' amulet");
			Log_Info("You have received a sartorial set");
			GiveItem2Character(pchar, "chest");
			GiveItem2Character(pchar, "talisman7");
			GiveItem2Character(pchar, "tailor_tool");
			dialog.text = "Und ich möchte, dass du weißt, dass die Türen meines Hauses jederzeit für dich offen sind. Du wirst hier immer Essen, eine Flasche guten Weins und alles andere finden, was du willst.";
			link.l1 = "Danke für Ihre freundlichen Worte, Meisterin. Ich werde mich freuen, Sie zu sehen, wenn ich diese Stadt wieder besuche.";
			link.l1.go = "agnes_20";
		break;
		
		case "agnes_20":
			dialog.text = "Versäume es nicht zu kommen!";
			link.l1 = "Und jetzt muss ich gehen. Auf Wiedersehen und viel Glück!";
			link.l1.go = "agnes_21";
		break;
		
		case "agnes_21":
			DialogExit();
			NextDiag.CurrentNode = "agnes_22";
			AddCharacterExpToSkill(pchar, "Fortune", 350);
			AddCharacterExpToSkill(pchar, "Leadership", 500);
			ChangeCharacterComplexReputation(pchar, "nobility", 10);
			ChangeCharacterComplexReputation(pchar, "authority", 4);
		break;
		
		case "agnes_22":
			dialog.text = "Ach, Kapitän "+GetFullName(pchar)+"! Ich bin so froh, dich zu sehen! Komm und setz dich, ich werde dir ein Getränk servieren...";
			link.l1 = "Danke! Ich wollte dich nur begrüßen und wissen, wie es dir geht. Ich bin froh, dass es dir und Ole gut geht.";
			link.l1.go = "exit";
			NextDiag.TempNode = "agnes_22";
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		//----------------------------------------- специальные реакции -----------------------------------------------
		//обнаружение ГГ в сундуках
		case "Man_FackYou":
			dialog.text = LinkRandPhrase("Was machst du da, ah? Dieb!","Schau nur! Kaum habe ich mich in Gedanken verloren, hast du beschlossen, meine Truhe zu überprüfen!","Entschlossen, meine Kisten zu überprüfen? Das wirst du nicht ungestraft tun!");
			link.l1 = "Verdammt noch mal!";
			link.l1.go = "fight";
		break;
		
		case "Woman_FackYou":
			dialog.text = "Was?! Hast du beschlossen, meine Truhen zu überprüfen? Du kommst damit nicht davon!";
			link.l1 = "Dummes Mädchen!";
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
	}
}
