// Диего де Монтойя
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
			dialog.text = "Gibt es etwas, das du willst?";
			link.l1 = "Nein, nichts.";
			link.l1.go = "exit";			
			NextDiag.TempNode = "First time";
		break;
		
		case "patrol":
			dialog.text = TimeGreeting()+", "+GetFullName(npchar)+", Chef der San Jose Patrouille. Wir haben eine Nachricht über verdächtiges Verhalten am Stadtrand erhalten. Wären Sie so freundlich uns zu erklären, wer Sie sind und was Sie vorhaben?";
			link.l1 = "Kapitän "+GetFullName(pchar)+", Herr Offizier. Ich bin hier unter der Autorität und den direkten Anweisungen des Inquisitor-Vaters Vincento. Hier ist ein Dokument, das meine Autorisierung bestätigt.";
			link.l1.go = "patrol_1";
		break;
		
		case "patrol_1":
			dialog.text = "In Ordnung... Alles sieht gut aus. Es ist ordnungsgemäß ausgefüllt mit der Unterschrift des Inquisitors. Entschuldigen Sie meine Verdächtigungen. Was machen Sie am Leuchtturm?";
			link.l1 = "Ich bin nicht befugt, solche Fragen zu beantworten. Wenn Sie wirklich an dem Zweck meiner Arbeit für den Inquisitor interessiert sind, würde ich Ihnen empfehlen, sich direkt an ihn in Santiago zur Klärung zu wenden. Sie sind ein Offizier, sicherlich haben Sie Kenntnis von militärischen und Dienstgeheimnissen. Das Einzige, was ich Ihnen sagen kann, ist, dass ich die Umstände eines gestrandeten spanischen Schiffes untersuche.";
			link.l1.go = "patrol_2";
		break;
		
		case "patrol_2":
			dialog.text = "Meine Entschuldigung noch einmal, Monsieur. Ich wage es nicht, Sie weiter zu verzögern... ach, einen Moment! Habe ich gerade die Klinge aus kaltem Stahl gesehen oder war es nur meine Einbildung? Was für ein interessanter Dolch den du hast! Kannst du ihn mir zeigen?";
			link.l1 = "Stelle sicher, dass du nicht vergisst, es zurückzugeben. Es ist mir sehr wichtig.";
			link.l1.go = "patrol_3";
		break;
		
		case "patrol_3":
			dialog.text = "Dios mio! Ich kenne diesen Dolch, ich habe ihn in einem der Bücher in der Bibliothek gesehen! Das ist der Dolch von Cortes selbst! Es ist hier gebrandmarkt... Monsieur, bitte lehnen Sie nicht ab. Lassen Sie mich diesen Dolch haben! Ich sammle alte und personalisierte Waffen und das ist einfach ein unglaubliches Exemplar. Ich werde gut dafür bezahlen.";
			link.l1 = "Herr, dieser Dolch steht nicht zum Verkauf. Ich habe ihn als Geschenk erhalten und habe nicht vor, ihn an irgendjemanden zu verkaufen. Geben Sie ihn bitte zurück.";
			link.l1.go = "patrol_4";
		break;
		
		case "patrol_4":
			dialog.text = "Du wirst nicht einmal mit fünfhundert Gold-Dublonen glücklich sein? Das ist eine ganze Menge Geld. Du könntest ein Schiff damit kaufen!";
			link.l1 = "Nein. Ich habe bereits ein Schiff und der Dolch ist einzigartig. Ich werde ihn nicht verkaufen.";
			link.l1.go = "patrol_5";
		break;
		
		case "patrol_5":
			dialog.text = "Eh, das ist zu schade... Gut, nimm deinen Wertgegenstand. Ich wage es nicht, dich länger zu stören. Viel Glück!";
			link.l1 = "Alles Gute, Offizier.";
			link.l1.go = "patrol_6";
		break;
		
		case "patrol_6":
			DialogExit();
			AddQuestRecord("Guardoftruth", "42");
			LAi_ActorGoToLocation(npchar, "reload", "reload2", "none", "", "", "GuardOT_ClearMayakPatrol", 12.0);
			for(i=1; i<=3; i++)
			{
				sld = characterFromId("GOT_spamayaksold_"+i);
				sld.lifeday = 0;
				LAi_SetActorType(sld);
				LAi_ActorGoToLocation(sld, "reload", "reload2", "none", "", "", "", 10.0);
			}
		break;
		
		case "shore":
			PlaySound("Voice\English\Sharlie\Diego De Montoya.wav");
			dialog.text = "Genug! Ich möchte mit ihm reden...";
			link.l1 = "Also, ich sehe Diego de Montoya selbst direkt vor mir... Aber verzeihen Sie mir, Senor. Wir haben uns zuvor getroffen, nicht wahr? Oh ja, genau. Trinidad, am örtlichen Leuchtturm. Aber ich bin mir sicher, dass Sie sich dort anders genannt haben...";
			link.l1.go = "shore_1";
		break;
		
		case "shore_1":
			dialog.text = "Ihre Erinnerung dient Ihnen gut, Herr. Nun, Sie sind nicht der Einzige, der in der Lage ist, Intrigen zu schüren und Kriege hinter den Kulissen zu führen. Ich bin gut informiert über Ihren unauslöschlichen Wunsch, mich zu sehen. Nun, es scheint, dass Ihr Wunsch in Erfüllung gegangen ist.";
			link.l1 = "Das war nicht genau die Art von Begegnung, auf die ich gehofft hatte, Senor.";
			link.l1.go = "shore_2";
		break;
		
		case "shore_2":
			dialog.text = "Nun, es ist was es ist. Aber ich gebe dir die Chance, hier lebend rauszukommen, wenn du mir deinen Dolch gibst.";
			link.l1 = "Hat Ihre Leidenschaft für das Sammeln von Raritäten Sie wirklich so weit in die Röhre geschickt, Caballero, dass Sie eine so gut durchdachte Falle für mich vorbereiten mussten? Oh, das glaube ich nicht. Hält Sie der Hüter der Wahrheit auf Trab oder liege ich völlig daneben?";
			link.l1.go = "shore_3";
		break;
		
		case "shore_3":
			dialog.text = "Ich habe keine Ahnung, wovon du redest. Der Dolch muss dahin zurückkehren, wo er hingehört, und das ist alles, was du wissen musst. Du wolltest ihn nicht für Gold aufgeben, also wirst du ihn jetzt für dein eigenes Leben aufgeben.";
			link.l1 = "Glauben Sie wirklich, senor, dass ich an das glauben werde, was Sie mir gerade erzählt haben? Sie haben bereits entschieden, dass ich diese Bucht nicht verlasse, nicht wahr?";
			link.l1.go = "shore_4";
		break;
		
		case "shore_4":
			dialog.text = "Und was ist, wenn ich dir mein Wort gebe?";
			link.l1 = "Das Wort für einen 'Froschesser'? Hm...";
			link.l1.go = "shore_5";
		break;
		
		case "shore_5":
			dialog.text = "Herr, ich gebe Ihnen eine letzte Chance. Entweder Sie übergeben den Dolch, der mich interessiert, oder ich werde in wenigen Minuten Ihre tote Leiche plündern. Widerstand ist zwecklos, wir haben eine überwältigende Überzahl.";
			if (CheckAttribute(pchar, "questTemp.Guardoftruth.SanAntonio")) link.l1 = "Sie haben mich überrascht, senor, das ist sicher. Denken Sie wirklich, dass ich so ein sturer Tölpel bin, dass ich meinen Kopf in die Kiefer eines Hais stecken würde, ohne mir die Mühe zu machen, meinen Harpunen zu schnappen? Leute, tötet sie!";
			else link.l1 = "Die wahre Macht liegt nicht in der Zahl, sondern im Können, senor!";
			link.l1.go = "shore_6";
		break;
		
		case "shore_6":
			DialogExit();
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
			LAi_SetActorType(npchar);
			LAi_ActorRunToLocation(npchar, "goto", "goto5", "none", "", "", "", 10.0);
			if (CheckAttribute(pchar, "questTemp.Guardoftruth.SanAntonio"))
			{
				PlaySound("interface\abordage_wining.wav");
				PlaySound("interface\abordage_wining.wav");
				for(i=1; i<=10; i++)
				{
					sld = characterFromId("GuardOT_Oursoldier_"+i);
					LAi_SetWarriorType(sld);
					ChangeCharacterAddressGroup(sld, "Shore15", "reload", "reload1_back");
					LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
				}
			}
			sld = CharacterFromID("spa_baseprisoner");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, "EnemyFight");
			for(i=1; i<=13; i++)
			{
				sld = characterFromId("GOT_spashore_"+i);
				LAi_SetWarriorType(sld);
				LAi_group_MoveCharacter(sld, "EnemyFight");
			}
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("EnemyFight", "GuardOT_DiegoShoreGuardDie");
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
	}
}
