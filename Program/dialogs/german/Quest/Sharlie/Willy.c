// Вильям Патерсон
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
			dialog.text = "Gibt es etwas, was du willst?";
			link.l1 = "Nein, nichts.";
			link.l1.go = "exit";			
			NextDiag.TempNode = "First time";
		break;
		
		case "catoche":
			dialog.text = "Hallo, Monsieur. Verdammt noch mal, also bist du derjenige, der hier all den militärischen Aufruhr verursacht hat?!";
			link.l1 = TimeGreeting()+", Herr. Ja, es war mein Schiff, das die Landung gemacht hat. Was ist denn los? Wer sind Sie? Ein Engländer, nehme ich an?";
			link.l1.go = "catoche_1";
		break;
		
		case "catoche_1":
			dialog.text = "Ein Schotte, Monsieur. Kapitän der englischen Marine William Paterson, und das ist mein erster Maat und rechte Hand, Archibald Calhoun. Die Sache ist, es gibt eine spanische Festung im Dschungel. Meine Mission ist es, die verfluchten Bastarde aus der Festung zu vertreiben, die sie gefährlich nahe am englischen Territorium gebaut haben.\nKürzlich haben wir versucht, sie zu stürmen, aber die Bastarde haben es trotz ihrer Verluste geschafft, standzuhalten. Ich bin um Verstärkung gegangen und...";
			link.l1 = "Keine Notwendigkeit dafür jetzt. Ich habe Ihre unvollendeten Geschäfte abgeschlossen, das Dschungelfort ist leer. Der spanische Kommandant Diego de Montoya ist tot, und sein Geschwader wurde auch ausgelöscht.";
			link.l1.go = "catoche_2";
		break;
		
		case "catoche_2":
			dialog.text = "Welche Art von Selbstjustiz ist das? Was ist Ihre Motivation, solch eine militärische Aktion auf englischem Territorium zu initiieren?";
			link.l1 = "Ich wage es, Sie daran zu erinnern, Kapitän Paterson, dass dies nicht Belize ist. Welcher englische Besitz? All diese Aufregung begann wegen Don Diego de Montoya und seiner riskanten Entscheidung, mich und meine Schiffe anzugreifen.";
			link.l1.go = "catoche_3";
		break;
		
		case "catoche_3":
			dialog.text = "Ähm... und aus welchem Grund hat Don Diego Sie angegriffen, hm Kapitän?";
			link.l1 = "Er und ich haben eine langjährige Fehde... Seit dem Tag, als das Geschwader, das er anführte, St. Pierre angriff und ein wenig später mit meiner direkten Beteiligung ausgelöscht wurde.";
			link.l1.go = "catoche_4";
		break;
		
		case "catoche_4":
			dialog.text = "Bei meiner Seele! Ich brauchte diesen ehrwürdigen Caballero lebendig! Ich wollte ihn ausfragen, warum er eine Militärbasis im Dschungel eingerichtet hat. Das konnte nicht ohne Grund sein...";
			link.l1 = "Es tut mir Leid, aber er kann Ihnen jetzt nichts erzählen. Wie dem auch sei, die Festung könnte verwundete Soldaten aus der Garnison beherbergen. Gibt es eine Chance, dass sie reden könnten?";
			link.l1.go = "catoche_5";
		break;
		
		case "catoche_5":
			dialog.text = "Soldaten... Ach, was soll's mit einigen sturen Musketen!... Wo ist Don Diegos Leiche? Er könnte wichtige Dokumente bei sich gehabt haben!";
			link.l1 = "Ich habe Don Diego auf dem Boden des Waffenforts zurückgelassen. Wenn Ihr ihn so dringend braucht, könnt Ihr ihn dort finden. Ich glaube nicht, dass er davonlaufen kann.";
			link.l1.go = "catoche_6";
		break;
		
		case "catoche_6":
			dialog.text = "Eh... und wer hat dich gebeten, dich in die Angelegenheiten anderer einzumischen... Du hast mir schon genug Kopfschmerzen bereitet...";
			link.l1 = "Kapitän, ich verstehe nicht, warum Sie mich tadeln. Ich habe Ihre Arbeit getan, meine eigenen Leute in die Schlacht geschickt, mein eigenes Leben riskiert und trotzdem sind Sie unzufrieden. Alles, was Sie jetzt tun müssen, ist Port Royal über Ihren Erfolg in der Mission und all Ihre Angelegenheiten zu informieren. Ich werde keinen Ruhm für Ihre Ehre beanspruchen, das versichere ich Ihnen.";
			link.l1.go = "catoche_7";
		break;
		
		case "catoche_7":
			dialog.text = "Ruhm beanspruchen? Was meinst du mit Ehre?! Du verstehst es überhaupt nicht... Ach, gut. Auf Wiedersehen, Herr.";
			link.l1 = "Alles Gute auch für dich!";
			link.l1.go = "catoche_8";
		break;
		
		case "catoche_8":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorRunToLocation(npchar, "reload", "reload1", "none", "", "", "GuardOT_OpenCatocheDoor", 10.0);
			sld = CharacterFromID("Archy");
			LAi_CharacterEnableDialog(sld);
			LAi_SetActorType(sld);
			LAi_ActorRunToLocation(sld, "reload", "reload1", "none", "", "", "", 7.0);
			AddQuestRecord("Guardoftruth", "57");
		break;
		
		case "isladevieques":
			PlaySound("Voice\English\sharlie\Willie Paterson.wav");
			dialog.text = "Mann, Klatsch und Tratsch lügen nicht, dass du wie eine Katze neun Leben hast! "+TimeGreeting()+", Herr de Maure. Sie sehen nicht so gut aus...";
			link.l1 = TimeGreeting()+", Herr Paterson. Ich muss sagen, Sie und Ihr Freund Archibald haben Ihre Rollen gut gespielt und mich ziemlich gut getäuscht, Verdammt seid ihr alle! Ich habe es nicht kommen sehen...";
			link.l1.go = "isladevieques_1";
		break;
		
		case "isladevieques_1":
			dialog.text = "He, schwöre nicht vor den Toren des Heiligen Landes. Du hast es nicht kommen sehen? Ich bin geschmeichelt: Ich habe einen der berühmtesten Intriganten des Archipels getäuscht. Die Tagebuchidee war brillant, findest du nicht auch?\nIch musste dich an einen obskuren Ort locken, dich auf offenem Feld zu töten wäre ein Skandal, du bist ein enger Freund von Philippe de Poincy, habe ich recht? Jetzt wirst du verschwinden, ohne eine Spur zu hinterlassen und niemand wird jemals wissen, wie.";
			link.l1 = "Also, alles was Calhoun mir erzählt hat... war eine Lüge?";
			link.l1.go = "isladevieques_2";
		break;
		
		case "isladevieques_2":
			dialog.text = "Ganz und gar nicht. Ich hatte den armen Archibald wirklich an diesem Ort gefunden. Er hat jedoch keine Memoiren geschrieben, das Tagebuch, das Sie in seinem Zimmer gefunden haben, wurde auf meinen Befehl speziell für Sie geschrieben, Monseniour de Maure.\nIch habe Sie im Auge behalten, seit wir uns in Cape Catoche getroffen haben. Sie haben die Karte der Zwei Erscheinungen von Don Diegos Leiche genommen? Bestreiten Sie es nicht, ich weiß, dass Sie es waren.";
			link.l1 = "Du weißt auch vom Hüter der Wahrheit?";
			link.l1.go = "isladevieques_3";
		break;
		
		case "isladevieques_3":
			dialog.text = "Das ist eine dumme Frage. Natürlich tue ich das. Und ich weiß, dass du auch die Klaue des Häuptlings bei dir hast. Und bald wirst du diese Gegenstände zurückgeben, die dir nicht gehören.";
			link.l1 = "Ich bin froh, dass du nicht wie Don Diego schwankst. Ich schätze Ehrlichkeit und Direktheit. Wie ich verstehe, hast du den Kompass, den Pfeil des Weges?";
			link.l1.go = "isladevieques_4";
		break;
		
		case "isladevieques_4":
			dialog.text = "Haw-haw! Nun, wir werden bis zum Ende ehrlich sein... Glauben Sie wirklich, mein Herr, dass ich so ein Idiot bin, wie Sie und Don Diego, dass ich ein so kostbares Objekt bei mir tragen würde? Der Kompass ist auf Jamaika und nicht einmal in Port Royal, sondern an einem Ort, an den niemand auch nur denken würde und unter einem sicheren Schloss. Aber diese Information werden Sie nicht benötigen.";
			if (CheckAttribute(pchar, "questTemp.Guardoftruth.OfficerKill"))
			{
				link.l1 = "Wie ich verstehe, haben Sie mich schon begraben, Herr Paterson? Ich wage zu verkünden, dass die Katze noch ein Leben übrig hat!.. Wo sind meine Offiziere?";
				link.l1.go = "isladevieques_5_1";
			}
			else
			{
				link.l1 = "Wie ich verstehe, haben Sie mich bereits begraben, Herr Paterson? Ich wage zu behaupten, dass die Katze noch ein Leben übrig hat!..";
				link.l1.go = "isladevieques_5_2";
			}
		break;
		
		case "isladevieques_5_1":
			if (CheckAttribute(pchar, "questTemp.Guardoftruth.GirlKill"))
			{
				dialog.text = "Sorgen um Ihre Dame, Kapitän? Ihre Frau liegt dort drüben im Gebüsch mit einem Loch in ihrer Stirn. Sie hat den Weg für Sie geebnet und Sie werden ihr bald zur Seite gestellt. Ich sage, was für ein hübsches Mädchen sie war! Hoffentlich hast du sie mehr als einmal gefickt?";
				link.l1 = "Das ist ein Hurensohn! Du wirst dafür bezahlen, du Arschloch?!";
				link.l1.go = "isladevieques_6";
			}
			else
			{
				dialog.text = "Ihre Offiziere haben Ihnen den Weg geebnet, Monsieur de Maure. Sie liegen dort drüben im Gebüsch. Bald werden Sie sich zu ihnen gesellen.";
				link.l1 = "Das werden wir noch sehen!";
				link.l1.go = "isladevieques_6";
			}
		break;
		
		case "isladevieques_5_2":
			dialog.text = "Wir werden sicherstellen, dass es wirklich dein letzter bleibt.";
			link.l1 = "Wir werden sehen!";
			link.l1.go = "isladevieques_6";
		break;
		
		case "isladevieques_6":
			dialog.text = "Du bringst mich zum Lachen. Einer gegen eine ganze Truppe! Wie auch immer, genug geplaudert... Zielt mit euren Musketen! Feuer!";
			link.l1 = "...";
			link.l1.go = "isladevieques_7";
		break;
		
		case "isladevieques_7":
			DialogExit();
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);//разрешить драться patch-8
			LAi_ActorRunToLocation(npchar, "quest", "teleport", "IslaDeVieques_HouseEntrance", "quest", "mushketer", "GuardOT_WillyGetReady", 10.0);
			for(i=1; i<=5; i++)
			{
				sld = CharacterFromID("GuardOT_willymushketer_"+i);
				LAi_group_MoveCharacter(sld, "EnemyFight");
			}
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("EnemyFight", "GuardOT_WillyMushketerDie");
			DoQuestFunctionDelay("Terrapin_SetMusic", 0.2);
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
	}
}
