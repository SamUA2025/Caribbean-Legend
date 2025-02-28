// Арчибальд Колхаун
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
			dialog.text = "Gibt es etwas, was du brauchst?";
			link.l1 = "Nein, nichts.";
			link.l1.go = "exit";			
			NextDiag.TempNode = "First time";
		break;
		
		case "portroyal":
			dialog.text = "Ha, Monsieur de Maure! Willkommen in Port Royal! Erinnerst du dich noch an mich?";
			link.l1 = "Hmm...Du bist R. Calhoun, nicht wahr? Henry Calhoun?";
			link.l1.go = "portroyal_1";
		break;
		
		case "portroyal_1":
			dialog.text = "Fast... Archibald Calhoun.";
			link.l1 = "Oh, verzeihen Sie mir, Monsieur. Ja, ich erinnere mich an Sie. Wir haben uns in Cape Catoche, an der Bucht getroffen. Ihr Kapitän war auch dabei, William Patterson. Ich habe sein Geschwader erkannt.";
			link.l1.go = "portroyal_2";
		break;
		
		case "portroyal_2":
			dialog.text = "Absolut richtig! Bitte entschuldigen Sie meinen Kapitän. Er ist immer unhöflich zu Leuten, die er nicht kennt. Sie haben hervorragend gearbeitet, die Festung von Diego de Montoya zu überfallen, an der wir zufällig unsere Krallen geschärft haben...";
			link.l1 = "Es ist um der Gerechtigkeit willen, möchte ich hinzufügen, dass ohne die vorbereitenden Maßnahmen, die von Ihrem Kapitän angezeigt wurden, ich zweifelhaft sogar in der Lage gewesen wäre, zu den Gewinnen aufzulaufen, während ich unter dem Feuer der spanischen Kanonen stand. Hat Ihr Kommandant gefunden, wonach er gesucht hat?";
			link.l1.go = "portroyal_3";
		break;
		
		case "portroyal_3":
			dialog.text = "Ja. Er hat sich ziemlich tief in den Kasematten unter der Festung eingegraben und eine Art Archiv gefunden. Er war unsagbar zufrieden. Übrigens, wenn ich fragen darf, was hat dich dazu gebracht, diese Festung im Dschungel anzugreifen?";
			link.l1 = "Nachdem er von mir in Saint-Pierre besiegt wurde, begann Don Diego ein Komplott zu schmieden und startete schließlich einen offenen Angriff auf Kuba. Dann brach er den Kampf ab und floh in die Hügel Richtung Main. Nun, ich beschloss, diesen feigen Hund ein für alle Mal loszuwerden, damit er die Franzosen nie wieder in den Schmutz zieht.";
			link.l1.go = "portroyal_4";
		break;
		
		case "portroyal_4":
			dialog.text = "Ja, ich habe schon einige legendäre Geschichten über die Heldentaten von Kapitän Charles de Maure gehört. Jetzt habe ich es mit meinen eigenen Augen gesehen...";
			link.l1 = "Ja, ich habe auch ein paar Dinge über den Mut von William Paterson gehört. Du hast Glück, einen Kapitän wie ihn zu haben.";
			link.l1.go = "portroyal_5";
		break;
		
		case "portroyal_5":
			dialog.text = "Glücklicherweise ist das wahr. Obwohl er heutzutage ein so wichtiger Mann geworden ist, ein Mann der hohen Gesellschaft, Audienzen, Bälle, Paraden und private Partys... Man kann ihn nicht aus dem Gouverneurspalast locken, wann immer wir in Port Royal ankommen. Tatsächlich ist er jetzt wieder dort.\nKapitän Charles de Maure, könntest du einem schottischen Säufer einen Gefallen tun? Geselle dich zu meiner Gesellschaft und lass uns plaudern! Ich habe es satt, immer die gleichen Gesichter zu sehen und du scheinst ein guter Gesprächspartner zu sein. Komm zu mir, lass uns entspannen und ein Fass ausgezeichneten Whiskeys haben. Ich zahle!";
			link.l1 = "Hm... Verlockend, aber...";
			link.l1.go = "portroyal_6";
		break;
		
		case "portroyal_6":
			dialog.text = "Ach hör auf, Kapitän, du musst auch mal ruhen. Ich habe übrigens einige feine Vorspeisen, direkt vom örtlichen Händler. Ich miete ein Zimmer genau über dem Laden. Wann immer du Lust hast, etwas zu essen oder zu trinken, gehst du einfach die Treppe hinunter und es ist fertig, haha! Praktisch, oder? Komm schon, lass uns gehen!";
			link.l1 = "Du hast mich dazu überredet!";
			link.l1.go = "portroyal_7";
		break;
		
		case "portroyal_7":
			dialog.text = "Großartig. Folge mir!";
			link.l1 = "...";
			link.l1.go = "portroyal_8";
		break;
		
		case "portroyal_8":
			DialogExit();
			NextDiag.CurrentNode = "portroyal_9";
			LAi_SetActorType(pchar);
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload6_back", "PortRoyal_store", "goto", "goto2", "GuardOT_ArchyIntoStore", -1);
			LAi_ActorFollow(pchar, npchar, "", -1);
		break;
		
		case "portroyal_9":
			LAi_SetSitType(Pchar);
			dialog.text = "Siehst du, wie schön es hier ist? Schön und kalt... Hier sind einige Whiskyfässer! Prost, Kapitän!";
			link.l1 = "Nun, trinken wir auf unser glückliches Treffen und eine angenehme Bekanntschaft!";
			link.l1.go = "portroyal_10";
		break;
		
		case "portroyal_10":
			dialog.text = "Erfreut!... Ah! Sie sind kürzlich in der Karibik angekommen, nicht wahr, Monsieur de Maure?";
			link.l1 = "Vor relativ kurzer Zeit... oder doch nicht so kurz. Ich weiß wirklich nicht, wie ich es ausdrücken soll. Ich habe das Gefühl, dass ich hier schon die Hälfte meines Lebens gelebt habe.";
			link.l1.go = "portroyal_11";
		break;
		
		case "portroyal_11":
			dialog.text = "Oh, ich kenne dieses Gefühl... Obwohl ich schon lange hier bin. Und als ich auf dieser verdammten Insel gelandet bin, von der William mich gerettet hat... Ohoo, es fühlt sich wahrhaftig so an, als hätte ich dort drüben die Hälfte meines Lebens verabschiedet.";
			link.l1 = "Interessant! Welche Insel war das?";
			link.l1.go = "portroyal_12";
		break;
		
		case "portroyal_12":
			dialog.text = "Willy ist ein alter Freund von mir, wir kannten uns noch aus der Zeit, als ich die frische Luft Schottlands atmete... Gute Zeiten. Ich war töricht genug, mich mit verfluchten Papisten und dem Inquisitor selbst anzulegen, also organisierte er einen Anschlag auf mich. Damals war ich Händler, hatte meine eigene Flöte.\nAch, an jenem verfluchten Tag wurde mein Schiff von den Spaniern angegriffen, die sich als Piraten verkleidet hatten. Wir kämpften tapfer, aber sie schafften es, uns wie Ratten in die Enge zu treiben! Selbst damals verlor der alte Colhaun nicht den Kopf und sprang mit einem Fass Wasser und ein paar Brettern über Bord.\nIch nutzte die Dunkelheit und schwamm von meinem Schiff weg, unbeobachtet von den Soldaten. Die Überlebenschancen waren nicht sehr gut, aber auf dem Schiff zu bleiben bedeutete, überhaupt keine Chance zu haben. Zwei Tage später strandete ich an der Küste einer verlassenen Insel.\nIch hatte zu dieser Zeit schon eine Weile in der Karibik gelebt und doch hatte ich bis dahin noch nie von dieser Insel gehört! Sie ist klein und völlig unbewohnt... und ich verbrachte dort zwei Jahre, die sich wie eine Ewigkeit anfühlten. Ich weiß immer noch nicht, wie ich es geschafft habe, meinen Verstand intakt zu halten.";
			link.l1 = "Du hast zwei Jahre auf einer unbewohnten Insel gelebt?";
			link.l1.go = "portroyal_13";
		break;
		
		case "portroyal_13":
			dialog.text = "Das habe ich sicherlich, verfluchter Ort! Gut, dass es frisches Wasser gab. Ich ernährte mich von Krabben, Seepocken, Fischen und Vögeln. Deshalb habe ich es Krabbeninsel genannt. Ich hatte keine Waffe, also beherrschte ich den Harpunen-, Speer- und Pfeilschuss wie ein wilder Mann! Ohoo! Trink, trink, Kapitän! Mir macht es nichts aus, meinen Schnabel auch zu benetzen...";
			link.l1 = "Ja... Ich beneide dich nicht.";
			link.l1.go = "portroyal_14";
		break;
		
		case "portroyal_14":
			dialog.text = "Da haben Sie's! Das ist genau das, was ich gesagt habe, als ich zum ersten Mal den Strand von diesem großen Sandhaufen betreten habe: 'Alter Archy, deine Lage ist nicht beneidenswert, aber auch nicht hoffnungslos!' Und wissen Sie, was mich am Leben gehalten hat, Kapitän?";
			link.l1 = "Ein Schiff, das an der Insel vorbeifährt?";
			link.l1.go = "portroyal_15";
		break;
		
		case "portroyal_15":
			dialog.text = "Nein! Arbeit hat mich gerettet! Arbeit, Glaube und der Wunsch zu leben! Ich habe die ganze Insel erkundet, jede Ecke davon und ich wurde mit einer Kiste belohnt, gefüllt mit Schreinerwerkzeugen, Schreibutensilien und anderen Kleinigkeiten. Wissen Sie, was ich mir in diesem Moment gesagt habe? Gieß mehr ein, Kapitän, gieß einfach!\nIch sagte: Archie, du musst arbeiten, um deinen Verstand beisammen zu halten und Gott hat dir alles gegeben, um damit anzufangen. Jetzt siehst du! Ich begann ein Haus in der Nähe einer Bucht zu bauen und weißt du was? Es bewahrte mich vor üblen Gedanken und gab mir einen Grund zu leben!";
			link.l1 = "Sie sind eine lebende Inspiration, Herr Calhoun. Nicht jeder Mann wäre in der Lage, in einer solchen Situation viel zu tun, wenn überhaupt etwas...";
			link.l1.go = "portroyal_16";
		break;
		
		case "portroyal_16":
			dialog.text = "Ja, der alte Calhaun wurde aus einem Grund in Schottland geboren! Richtig! Wir sind die Söhne der Berge - stark, mutig und zäh, viel besser als diese Leichtgewichte aus dem Marschland. Schenke mehr ein... Richtig, worüber habe ich gesprochen? Ja! Ich habe hart gearbeitet und mir ein anständiges Haus gebaut. Ich habe auch ein Tagebuch für alltägliche Schreibereien meiner Missgeschicke angefangen. Ich nahm das Tagebuch mit, als Willy mich rettete.\nJetzt bewahre ich es in diesem Tisch hier auf und lese es in einem warmen, weichen Bett immer dann, wenn wir in Port Royal sind.\nIch habe alles darin aufgeschrieben, alles, was mir passiert ist, bevor und nachdem ich dort angekommen bin. Es ist einer der Gründe, warum ich noch bei Verstand bin.";
			link.l1 = "Also stellt sich heraus, dass Herr Paterson Sie von der Insel geholt hat? Aber wie konnte er sie finden? Sie sagten...";
			link.l1.go = "portroyal_17";
		break;
		
		case "portroyal_17":
			dialog.text = "Ja, ja, die Insel ist auf keiner Karte verzeichnet. Aber Willy, er ist der alte Willy! Er kann alles! Und er hat diese verdammt Insel gefunden und mich gerettet, und dafür werde ich ihm bis zum Ende meines Lebens dankbar sein. Ja...";
			link.l1 = "Mögen Sie es, Herrn Paterson zu dienen? Möchten Sie wieder auf Ihre eigenen Ressourcen zurückgreifen?";
			link.l1.go = "portroyal_18";
		break;
		
		case "portroyal_18":
			dialog.text = "Ich habe genug davon, unabhängig zu sein. Willy ist jung und erfolgreich und ich bin auch schon lange sein Freund. Was brauche ich noch mehr? Nein, ich werde bis ans Ende meiner Tage bei Willy sein, oder zumindest bis er mich das nächste Mal rauswirft, wenn ich wieder betrunken bin, haha! Apropos betrunken, schenk ein!";
			link.l1 = "Akh...(trinkt) Sag mir, Herr Calhoun. Ich habe gehört, du warst, äh, früher ein Schatzjäger. Ist das wahr oder ist es nur Unsinn?";
			link.l1.go = "portroyal_19";
		break;
		
		case "portroyal_19":
			dialog.text = "Wer hat Ihnen das gesagt? Nun, es hat keinen Sinn, es zu verbergen. Ich war mal einer. Hat sich allerdings nicht gut entwickelt, genau diese Schatzsucherei hat mich zu den verfluchten Jesuiten und der Insel geführt. Die heiligen Väter haben einen Mann wegen mir zu Tode gefoltert, und ich selbst... oh, lassen wir die Vergangenheit in der Vergangenheit.\nIch habe genug für meine Sünden bezahlt und hoffe, sie in der Zukunft nie zu wiederholen. Nein, das wird Willy nicht zulassen, da bin ich sicher!";
			link.l1 = "Hör zu, Archibald. Hast du jemals von einem Mann namens Miguel Dichoso gehört?";
			link.l1.go = "portroyal_20";
		break;
		
		case "portroyal_20":
			dialog.text = "Ich habe diesen Namen noch nie gehört. Wer ist er?";
			link.l1 = "Oh, niemand Interessantes... nur ein Mann, der gerne nach Abenteuern und Schätzen sucht. Aber da du noch nichts von ihm gehört hast, werden wir nicht über ihn reden.";
			link.l1.go = "portroyal_21";
		break;
		
		case "portroyal_21":
			dialog.text = "Ja, lass uns das nicht tun! Lass uns stattdessen über das alte Europa sprechen! Ich erinnere mich an vor zwanzig Jahren in Schottland...";
			link.l1 = "...";
			link.l1.go = "portroyal_22";
		break;
		
		case "portroyal_22":
			DialogExit();
			AddDialogExitQuest("GuardOT_MCOutFromArchyRoom");
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}
