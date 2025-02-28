void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
	int i;
	string sTemp;
	
	DeleteAttribute(&Dialog,"Links");
	
	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	switch(Dialog.CurrentNode)
	{
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		case "First time":
			dialog.text = "Was wollt ihr?";
			link.l1 = "Nichts.";
			link.l1.go = "exit";
		break;
		
		case "startoff":
			dialog.text = "Kapitän de Maure! Willkommen in Tortuga!";
			link.l1 = "Guten Tag, Leutnant. Genießen Sie den Meerblick mit Ihren Freunden?";
			link.l1.go = "startoff_joke";
			link.l2 = "Zurück, Leutnant.";
			link.l2.go = "startoff_silence";
			
			AddDialogExitQuestFunction("Tonzag_Arrested");
		break;
		
		case "startoff_joke":
			dialog.text = "Kapitän, Ihr Ruf eilt Ihnen voraus, und die Oberen haben beschlossen, eine kleine Tour zu den Schönheiten unserer lieblichen Insel Tortuga zu arrangieren. Wir beginnen sofort - mit den Gefängniszellen der Stadt. Ihre Offiziere sind ebenfalls eingeladen.";
			link.l1 = "Leutnant, ich bin nicht irgendein struppiger Schmuggler, den Sie am Strand aufgegriffen haben. Keine Scherze, bitte. Erklären Sie die Angelegenheiten ordnungsgemäß.";
			link.l1.go = "startoff_joke_1";
			link.l2 = "Dann verschwenden wir keine Zeit! Führen Sie den Weg, Leutnant!";
			link.l2.go = "startoff_joke_2";
		break;
		
		case "startoff_silence":
			dialog.text = "Ich sehe, dass der Umgang mit euch, Seeleuten, einen anderen Ansatz erfordert. Soldaten, bereitet euch auf den Kampf vor! Kapitän de Maure, Sie und Ihre Offiziere sind unter Arrest. Geben Sie Ihre Waffen ab!";
			link.l1 = "Ich kann dir eine Kugel geben - wo willst du sie, Leutnant? Mit euch Landratten gibt es keinen anderen Weg.";
			link.l1.go = "startoff_silence_1";
			link.l2 = "Nach welchem Gesetz? Wenn Sie eine bewaffnete Gruppe ohne Blutvergießen festnehmen wollen, Leutnant, müssen Sie sich mehr anstrengen.";
			link.l2.go = "startoff_silence_2";
		break;
		
		case "startoff_joke_1":
			dialog.text = "Für mich seid ihr alle gleich... Entschuldigung, aber es wird keine Erklärungen geben, Kapitän. Befehle von oben. Gebt eure Waffen ab, wenn ihr so freundlich wärt.";
			link.l1 = "Ich brauche keine Schwierigkeiten... nicht jetzt. Tu, was sie sagen.";
			link.l1.go = "exit";
			
			AddCharacterExpToSkill(pchar, "Leadership", 100);
			ChangeCharacterComplexReputation(pchar, "nobility", +5);
		break;
		
		case "startoff_joke_2":
			dialog.text = "Äh... Ich glaube, du hast mich nicht ganz verstanden. Kapitän, du und deine Offiziere seid verhaftet! Übergebt eure Waffen und kommt mit uns!";
			link.l1 = "Ich brauche keine Probleme... nicht jetzt. Tu, was sie sagen.";
			link.l1.go = "exit";
			
			AddCharacterExpToSkill(pchar, "Fortune", 100);
		break;
		
		case "startoff_silence_1":
			dialog.text = "Noch ein Wort, Kapitän, und wir begraben dich hier direkt. Waffen auf den Boden, sofort!";
			link.l1 = "Ich brauche keine Probleme... nicht jetzt. Tu, was sie sagen.";
			link.l1.go = "exit";
			
			AddComplexSelfExpToScill(100, 100, 100, 100);
			ChangeCharacterComplexReputation(pchar, "nobility", -5);
		break;
		
		case "startoff_silence_2":
			dialog.text = "Ich habe keine Angst vor Blut, Kapitän. Selbst wenn Sie wie durch ein Wunder überleben, werden Sie nie wieder einen Fuß auf Tortuga setzen. Und unser Militärgeheimdienst glaubt, dass Sie Ihren Zugang zu dieser Insel sehr schätzen.";
			link.l1 = "Ich brauche keine Schwierigkeiten... nicht jetzt. Tu, was sie sagen.";
			link.l1.go = "exit";
			
			AddCharacterExpToSkill(pchar, "Leadership", 100);
			ChangeCharacterComplexReputation(pchar, "authority", 5);
		break;
		
		case "tonzag_after_boarding":
			dialog.text = "Kapitän, die Dinge sind Scheiße! Der Feind hat uns fest im Griff, ich fürchte, sie lassen nicht los, bis wir tot sind! Unsere Leute stecken gerade in echten Schwierigkeiten, und die meisten Geschützmannschaften sind außer Gefecht!";
			link.l1 = "Ich werde ihnen helfen. Übernimm das Kommando und bring uns hier raus!";
			link.l1.go = "tonzag_after_boarding_1";
			DelLandQuestMark(npchar);
		break;
		
		case "tonzag_after_boarding_1":
			dialog.text = "Ja, Herr!";
			link.l1 = "";
			link.l1.go = "exit";
			
			AddDialogExitQuestFunction("Tonzag_GoToGunDeck");
		break;
		
		case "tonzag_after_victory":
			dialog.text = "Sieg, Kapitän! Die Landungspartei wurde zerstört, der Feind hat sich zur Rückzug entschieden und ist nach Süden gegangen. Der Zustand des Schiffes ist akzeptabel. Lebende Mannschaft: "+GetCrewQuantity(pchar)+" Leute. Bericht abgeschlossen!";
			link.l1 = "Danke! Rum für alle und verstärkt die Wache, bis wir den Hafen erreichen!";
			link.l1.go = "tonzag_after_victory_1";
		break;
		
		case "tonzag_after_victory_1":
			dialog.text = "Hurra! Jawohl!";
			link.l1 = "";
			link.l1.go = "exit";
			
			AddDialogExitQuestFunction("Tonzag_AlonsoBoardingDialog");
		break;
		
		case "killer":
			dialog.text = "Und da ist der Mann selbst! Hast du das blutige Massaker draußen gesehen? Es ist alles dein Werk, Verräter! Aber du wirst für alles bezahlen: für Porto Bello, für Gruoh und für diese Mine!";
			link.l1 = "Warte, was soll das...";
			link.l1.go = "exit";
			
			AddDialogExitQuestFunction("Tonzag_FightInMine");
		break;
		
		case "mine_head":
			dialog.text = "";
			link.l1 = "Agh! Das verheißt nichts Gutes...";
			link.l1.go = "mine_head_1";
		break;
		
		case "mine_head_1":
			dialog.text = "San Santiago, bewahre mich! Schurkerei! Welches Monster könnte so eine Tat begehen? Antwort, senor!";
			link.l1 = "Beruhige dich, señor! Stelle dich zuerst vor! Ja, hier fand ein monströses Gemetzel statt, aber die Leute, die es begangen haben, sind bereits tot. Ich habe die Minen persönlich mit ihren Überresten 'dekoriert'...";
			link.l1.go = "mine_head_2";
		break;
		
		case "mine_head_2":
			dialog.text = "Ich bin "+GetFullName(npchar)+", Chefingenieur der königlichen Los Teques Mine. Ich bin gerade von einem monatelangen Auftrag zurückgekehrt und...was sehe ich! Was hier passiert ist, ist ein Verbrechen gegen Gott und die Menschheit, also bitte ich Sie, Ihre Waffen sofort zu übergeben. Die Behörden von Caracas werden diese Schurkerei untersuchen!";
			link.l1 = " Ich kann nicht nachkommen, senor, und ich schwöre, ich hatte nichts mit diesem Massaker zu tun! Aber wenn du darauf bestehst, wird dein eigener Körper dem Haufen hinzugefügt.";
			link.l1.go = "mine_head_3";
		break;
		
		case "mine_head_3":
			dialog.text = "Ich fürchte den Tod nicht, aber ich weiß immer, wann ich mich zurückziehen muss. Geh, aber denk daran, ich werde berichten, was hier passiert ist, und ich werde kein einziges Detail auslassen!";
			link.l1 = "Ich kann dem nicht zustimmen, Señor. Es tut mir leid, dass es dazu gekommen ist. Zum Kampf!";
			link.l1.go = "mine_head_fight";
			link.l2 = "Es scheint, Sie suchen den Tod, Señor. Aber heute wird niemand sonst sterben. Wir gehen, und ich hoffe, dieses Detail schafft es auch in Ihren Bericht!";
			link.l2.go = "mine_head_peace";
		break;
		
		case "mine_head_peace":
			DialogExit();
			
			AddDialogExitQuestFunction("Tonzag_LetMineHeadGo");
		break;
		
		case "mine_head_fight":
			DialogExit();
			
			AddDialogExitQuestFunction("Tonzag_FightMineHead");
		break;
		
		case "alonso":
			dialog.text = "Was sollen wir mit dem Gefangenen tun, Kapitän?";
			link.l1 = "Nichts Besonderes, lass ihn einfach nicht sterben oder fliehen.";
			link.l1.go = "alonso_1";
		break;
		
		case "alonso_1":
			dialog.text = "Jawohl! Ich nehme an, ich muss an der heutigen Vernehmung nicht teilnehmen, Kapitän?";
			link.l1 = "Warum nicht? Hast du beschlossen, deinen Beruf zu wechseln, Alonso?";
			link.l1.go = "alonso_2";
		break;
		
		case "alonso_2":
			dialog.text = "Ha-ha, nein, Kapitän. Ich liebe diesen Job, aber es scheint, dass Sie einen neuen Meister des Handwerks an Bord haben!";
			link.l1 = "Herkules? Wo hast du diese Idee her?";
			link.l1.go = "alonso_3";
		break;
		
		case "alonso_3":
			dialog.text = "Nun, Kapitän, der alte Mann hat extra für diesen Anlass sein Werkzeug mitgebracht und es benutzt. Ich muss nicht mal meines rausholen. Ha!";
			link.l1 = "Ich sehe... Wie du warst!";
			link.l1.go = "exit";
			
			AddDialogExitQuestFunction("Tonzag_DrinkAgain");
		break;
		
		case "captive":
			dialog.text = "Ah ... Charles de Maure. Lassen Sie mich im Namen der gesamten Liga meine Entschuldigungen anbieten. Der Befehl, Sie in Ruhe zu lassen, erreichte uns zu spät. Unsere Organisation hat keine Ansprüche gegen Sie, Kapitän. Was dieses kahle Tier betrifft ... Pfui! Solange er an Ihrer Leine ist, ist er sicher, aber mein Rat an Sie ist, ihn nicht zu behalten und ihn in der Gosse verrotten zu lassen, wo er hingehört!";
			link.l1 = "Danke für die Empfehlung, aber ich bin mehr daran interessiert, warum jemand mich vor deinen Söldnern schützt.";
			link.l1.go = "captive_1";
		break;
		
		case "captive_1":
			dialog.text = "Ich kann es nicht wissen, Kapitän. Ich vermute, die Anweisungen kamen von unserem neuen Gönner. Hast du von ihm gehört, Verräter? Die Liga ist jetzt wieder oben!";
			link.l1 = "Und wer ist er?";
			link.l1.go = "captive_2";
		break;
		
		case "captive_2":
			dialog.text = "Ich kann es nicht wissen, Kapitän, und selbst wenn ich es wüsste, solche Dinge geben wir nicht preis.";
			link.l1 = "In diesem Fall, erzähl mir etwas anderes, und du kannst gehen, wohin du willst. Du hast mein Wort.";
			link.l1.go = "captive_3";
		break;
		
		case "captive_3":
			dialog.text = "So einfach? Gut, Kapitän, stellen Sie Ihre Fragen und lassen Sie mich gehen. Ich verspreche, ich werde nicht zur Liga zurückkehren, auch wenn ich könnte.";
			link.l1 = "Warum bist du so besessen von Hercule? Zu viel Ärger für nur einen Deserteur.";
			link.l1.go = "captive_4";
		break;
		
		case "captive_4":
			dialog.text = "Was hast du ihm erzählt, du Hund? Alles ist nicht so, wie es scheint, Kapitän! Die Liga bewegt sich ständig, Codes ändern sich, Arbeitgeber variieren. Möchtest du gehen? Kein Problem! Der Ausgang ist nur für die obersten Offiziere geschlossen, und dieser Abschaum war nie einer. Seine Frau, sicher, aber wir respektierten Madame Tonzag zu sehr, um für sie keine Ausnahme zu machen.";
			link.l1 = "Dann warum?";
			link.l1.go = "captive_5";
		break;
		
		case "captive_5":
			dialog.text = "Es gab eine Sache in Porto Bello... Es war groß. Verstehen Sie, Ihr Freund ist nicht einfach gegangen, hat nicht einfach den Vertrag gebrochen, hat nicht einfach die Gruppe getötet, die kam, um seinen Job zu beenden. Er verursachte ein wahres Massaker in den Straßen und erschwerte unsere Beziehung zu den Kastiliern erheblich. Eine seltene Piratenüberfall sät so viel Terror wie die guten Katholiken an jenem Tag erlebten. Bei Gott, ich wäre vielleicht sogar beeindruckt gewesen, wenn es jemand anderes getan hätte.";
			link.l1 = "Noch eine Massaker? Wie interessant. Mach weiter.";
			link.l1.go = "captive_6";
		break;
		
		case "captive_6":
			dialog.text = "Der damalige stellvertretende Direktor der Gesellschaft, Rodenburg, griff ein. Er schaffte es irgendwie, die ganze Angelegenheit unter den Teppich zu kehren, aber nicht bevor wir viele unserer besten Männer durch die spanischen Strafaktionen verloren hatten. Nach einiger Zeit jedoch, machten wir wieder Geschäfte mit ihnen... Ah! Aber wir haben nichts vergessen, und sobald sich die Gelegenheit bot, versuchten wir uns zu rächen. Der Anstifter von allem, Tonzag, musste getötet werden.";
			link.l1 = "Du hast das nicht geschafft. Was ist mit der Mine?";
			link.l1.go = "captive_7";
		break;
		
		case "captive_7":
			dialog.text = "We were forced to do it. Getting rid of that scum required too much expense; we needed gold. All because of him... But the attempted assassination failed, and I returned to Los Teques to tidy up a bit... How did you figure out where to look?";
			link.l1 = "Es ist egal. Ich muss mich mit eurem Anführer treffen. Ich möchte das Missverständnis persönlich klären, da die Garantien von eurem geheimnisvollen Gönner jederzeit ablaufen können.";
			link.l1.go = "captive_8";
		break;
		
		case "captive_8":
			dialog.text = "Ich bin sicher, dass sie bereits in Caracas auf Sie warten, Kapitän. Sehen Sie, ich verberge nichts vor Ihnen.";
			link.l1 = "";
			link.l1.go = "exit";
			
			AddDialogExitQuestFunction("Tonzag_HoldDialog");
		break;
		
		case "captive_9":
			dialog.text = "Kommandant Arno ist gestorben, jetzt hat Austin das Kommando.";
			link.l1 = "";
			link.l1.go = "exit";
			
			AddDialogExitQuestFunction("Tonzag_HoldDialog2");
		break;
		
		case "captive_10":
			dialog.text = "Ich habe all Ihre Fragen beantwortet, Kapitän. Halten Sie Ihr Wort.";
			link.l1 = "Ich lasse dich gehen. Verlasse mein Schiff und bete, dass mich in Caracas kein Hinterhalt erwartet.";
			link.l1.go = "captive_spare";
			link.l2 = "Danke für das interessante Gespräch. Hercule nach dem, was ich in der Mine gesehen habe, ein Massaker vorzuwerfen, war allerdings etwas zu viel. Ab zur Hölle, wo du hingehörst.";
			link.l2.go = "captive_execute";
		break;
		
		case "captive_execute":
			DialogExit();
			
			AddDialogExitQuestFunction("Tonzag_ExecuteCaptive");
		break;
		
		case "captive_spare":
			DialogExit();
			
			AddDialogExitQuestFunction("Tonzag_ReturnToCabin2");
		break;
		
		case "cureer":
			dialog.text = "Meine Herren, Sie sind zu einem Treffen eingeladen. Sie werden in der Kirche erwartet, daher ist die Sicherheit garantiert.";
			link.l1 = "Das war schnell...";
			link.l1.go = "exit";
			
			AddDialogExitQuestFunction("Tonzag_CureerGoAway");
		break;
		
		case "ostin":
			StartQuestMovie(true, false, true);
			PlaySound("VOICE\" + LanguageGetLanguage() + "\OliverTrast02.wav");
			dialog.text = "Charles de Maure. Hercule. Du wirst hier nicht lebend herauskommen.";
			link.l1 = "Immer ein netter Weg, ein Gespräch zu beginnen. Brauchst du wirklich all das?";
			link.l1.go = "ostin_1";
		break;
		
		case "ostin_1":
			dialog.text = "Mit dir, Kapitän, sind die Dinge nicht ganz einfach. Siehst du, unser neuer Patron bestand darauf, dass du in Ruhe gelassen wirst...und er kann seine Bitten in seinen Arsch schieben! Ich hasse deine Art sehr! Du segelst unter deinen hübschen, weißen Segeln, denkst, dass das Eis in deinem Mund nicht schmelzen wird. Aber wenn das Stahl meiner Klinge in dich eindringt, schreit ihr alle wie Mädchen. Das muss man lieben, Charles, das sag ich dir! Es ist eine Weile her, seit ich das getan habe...und jetzt habe ich dich direkt vor mir, hübscher Junge.";
			link.l1 = "Du bist krank, Kumpel.";
			link.l1.go = "ostin_2";
		break;
		
		case "ostin_2":
			dialog.text = "Nein, ich kann dich nicht gehen lassen. Mit deinem Freund ist es jedoch viel einfacher - meine Jungs haben keine Verwendung für ihn, aber es gibt immer noch einige seiner alten messbaren Liga-Kumpel, die nicht ganz überzeugt von der Wirksamkeit meiner Methoden sind...Zu sehr daran gewöhnt, sauber zu arbeiten, für die sauberen Dublonen, von der sauberen Gesellschaft. Aber ich kenne genau das Ding, das ihre Meinungen ändern wird - ein frecher Sünderkopf auf einem Tablett, ha-ha!";
			link.l1 = "Du hast den falschen Ort dafür gewählt, du kranker Bastard. Willst du wirklich einen Kampf in einer Kirche beginnen?";
			link.l1.go = "ostin_3";
		break;
		
		case "ostin_3":
			dialog.text = "Sicher, warum nicht? Mitleid mit den Leuten? Es mag nicht so lukrativ sein wie in Los Teques, aber wir werden immer noch eine gute Zeit haben. Wir werden die Wände von Gottes Haus bemalen, ah-ha! Kapitän, du wirst genug Farbe liefern.";
			link.l1 = "Ich verstehe. Du beneidest uns, nicht wahr, du verrückte Ratte? Beneidest du unsere Freiheit? Dass die Mädchen sich freuen, uns zu sehen und dass Münzen in unseren Taschen klingeln? Sieh dich an: Wo haben dich deine Gönner ausgegraben, Schwein? Wer hat dich in die Kirche gelassen?";
			link.l1.go = "ostin_4";
		break;
		
		case "ostin_4":
			dialog.text = "Friss Dreck, du kleiner Scheißer!";
			link.l1 = "";
			link.l1.go = "exit";
			
			AddDialogExitQuestFunction("Tonzag_ChurchVystrel");
		break;
		
	}
} 
