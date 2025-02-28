// Addon-2016 Jason, французские миниквесты (ФМК) Мартиника
void ProcessDialogEvent()
{
	ref sld, NPChar;
	aref Link, NextDiag;
	int i;
	string sTemp;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			dialog.text = "Ein offensichtlicher Fehler. Sag es den Entwicklern.";
			link.l1 = "Oh, das werde ich.";
			link.l1.go = "exit";
			NextDiag.TempNode = "First time";
		break;
		
		// квестодатель
		case "carpenter":
			DelMapQuestMarkCity("Fortfrance");
			LAi_SetImmortal(npchar, false);
			npchar.lifeday = 0;
			DelLandQuestMark(npchar);
			dialog.text = TimeGreeting()+", Kapitän. Darf ich mich vorstellen - "+GetFullName(npchar)+". Obwohl wir uns vor nicht allzu langer Zeit bereits getroffen haben, bezweifle ich, dass du dich an mich erinnerst.";
			link.l1 = "Grüß Gott, Monsieur. Und wo könnte ich Sie zuvor gesehen haben?";
			link.l1.go = "carpenter_1";
		break;
		
		case "carpenter_1":
			sTemp = "lugger 'Adeline'";
			if (pchar.questTemp.Sharlie.Ship == "sloop") sTemp = "sloop 'Black Dog'";
			dialog.text = "Unsere Werft. Sie haben gekauft "+sTemp+". Erinnerst du dich jetzt? Ich bin dort Tischler.";
			link.l1 = "Ja, ich habe dieses Schiff wirklich gekauft. Was wollen Sie, Monsieur "+GetFullName(npchar)+"?";
			link.l1.go = "carpenter_2";
		break;
		
		case "carpenter_2":
			sld = characterFromId("FortFrance_shipyarder");
			AddLandQuestMark(sld, "questmarkmain");
			dialog.text = "Unser Schiffsbauer "+GetFullName(sld)+" möchte mit Ihnen sprechen. Ich glaube, er hat ein Geschäftsvorschlag. Er hat Ihr Schiff in unserem Hafen gesehen und hat mich geschickt, um Sie zu finden. Wären Sie so freundlich, die Einladung anzunehmen?";
			link.l1 = "Gut. Ich werde Ihren Chef besuchen, sobald ich meine Geschäfte in der Stadt erledigt habe.";
			link.l1.go = "carpenter_3";
		break;
		
		case "carpenter_3":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorRunToLocation(npchar, "reload", "reload5_back", "none", "", "", "", 10.0);
			chrDisableReloadToLocation = false;
			pchar.questTemp.FMQM = "begin";
			AddQuestRecord("FMQ_Martinique", "1");
			SetFunctionTimerCondition("FMQM_Denial", 0, 0, 2, false);
		break;
		
		case "officer":
			PlaySound("Voice\English\soldier_arest_4.wav");
			dialog.text = "Nun-nun... Frische Schmuggler in meinem Netz!";
			link.l1 = "Eh...";
			link.l1.go = "officer_1";
		break;
		
		case "officer_1":
			dialog.text = "Hör auf mit dem Mist! Es gibt mehrere Fässer Harz in dieser Werft. Kapitän, Sie haben sie Ihrem Komplizen geliefert. Sie beide sind verhaftet und ich beschlagnahme die Ladung im Namen des Gesetzes!";
			link.l1 = "...";
			link.l1.go = "officer_2";
		break;
		
		case "officer_2":
			DialogExit();
			LAi_SetActorType(npchar);
			sld = characterFromId("FortFrance_shipyarder");
			LAi_SetActorType(sld);
			LAi_ActorDialogNow(sld, pchar, "", -1);
		break;
		
		case "officer_3":
			dialog.text = "Spielt nicht den Dummen, Meister! Welche Fässer? Ihr wisst genau, dass ich von den Fässern rede, die ihr kürzlich von diesem Seemannsschiff entladen habt! Ihr werdet beide in den Verliesen verrotten! Bewegt euch, Scheißkerle...";
			link.l1 = "";
			link.l1.go = "officer_4";
		break;
		
		case "officer_4":
			DialogExit();
			LAi_SetActorType(npchar);
			sld = characterFromId("FortFrance_shipyarder");
			LAi_SetActorType(sld);
			LAi_ActorDialogNow(sld, pchar, "", -1);
		break;
		
		case "officer_5":
			PlaySound("Voice\English\soldier\soldier arest-02.wav");
			dialog.text = "Dieses Harz, mein lieber Schiffsbauer, ist ein Gut von strategischem Wert, das unter direkter Kontrolle unseres Gouverneurs steht! Da Sie behaupten, es sei alles Ihrs - machen Sie es so. Sie sind unter Arrest, Sie werden diese Nacht in unseren komfortablen Verliesen verbringen und morgen werden Sie uns einen detaillierten Bericht darüber geben, wie Sie sie bekommen haben und zu welchem Zweck. Machen Sie sich keine Sorgen, wir werden letztendlich alles erfahren. Sie, Kapitän, dürfen gehen. Es ist Ihr Glückstag.";
			link.l1 = "";
			link.l1.go = "officer_6";
		break;
		
		case "officer_6":
			DialogExit();
			LAi_SetActorType(pchar);
			LAi_ActorTurnToCharacter(pchar, characterFromID("FMQM_officer"));
			sld = characterFromId("FortFrance_shipyarder");
			LAi_SetActorType(sld);
			LAi_ActorGoToLocation(sld, "reload", "reload1", "FortFrance_town", "officers", "reload5_3", "FMQM_ArestContinue", 8);
		break;
		
		case "officer_7":
			PlaySound("Voice\English\soldier_arest_2.wav");
			dialog.text = "Ich wusste, dass mit diesem Schiff etwas nicht stimmt... Sieht aus, als hätte ich Sie unterschätzt, Kapitän.";
			link.l1 = "Genau, Leutnant. Ich bin nicht so dumm. Ihre fröhliche Zusammenarbeit mit dem Schiffsbauer ist jetzt kompromittiert.";
			link.l1.go = "officer_8";
			DelLandQuestMark(npchar);
		break;
		
		case "officer_8":
			dialog.text = "Ich verstehe. Herzlichen Glückwunsch, du musst begabt sein, da es dir gelungen ist, mich aufzuspüren und mich zu überraschen. Jetzt sag mir, was du willst.";
			link.l1 = "Ist das nicht klar? Ich brauche mein Harz zurück. Das Harz, das du und dein Kumpel mir gestohlen haben.";
			link.l1.go = "officer_9";
		break;
		
		case "officer_9":
			dialog.text = "Gut. Du kannst es haben, aber nur die Hälfte deiner Ladung. Das ist alles, was ich hier versteckt habe. Ich hoffe, das reicht dir, denn mehr kann ich nicht anbieten.";
			link.l1 = "Bist du immer noch dabei, mich zu betrügen? Entschädige mich die andere Hälfte mit Gold oder mit Waren, die du hinter dir versteckt hast.";
			link.l1.go = "officer_10";
		break;
		
		case "officer_10":
			dialog.text = "Keine Option. Wende dich an unseren gemeinsamen Freund für die andere Hälfte.";
			link.l1 = "Bist du verdammt nochmal am Scherzen? Glaubst du das wirklich "+GetFullName(characterFromId("FortFrance_Schiffswerftarbeiter"))+" wird mir meine Fässer zurückgeben? Das ist lächerlich.";
			link.l1.go = "officer_11";
		break;
		
		case "officer_11":
			dialog.text = "Kapitän, nimm all das Harz, das ich habe, hab dein Leben und verdammt noch mal, hau ab. Ich kann diesem Handel mein Versprechen hinzufügen, dir in St. Pierre keine Probleme zu bereiten. Das ist mein letztes Angebot.";
			link.l1 = "Seit wann ist mein Leben Teil des Handels? Ha!";
			link.l1.go = "officer_12";
		break;
		
		case "officer_12":
			dialog.text = "Sieht so aus, als ob Sie sich nach dem Kampf immer noch unbesiegbar fühlen, Kapitän. Lassen Sie mich Ihnen das erklären: Das waren Anfänger, untrainiert und unmotiviert, Sie haben keine Chance gegen meine Truppe. Ich könnte Sie hier und jetzt töten, ohne zu feilschen, aber ich schätze das Leben meiner Männer. Einer von ihnen könnte verletzt oder sogar getötet werden, während er Sie tötet. Also nehmen Sie entweder mein großzügiges Angebot an oder bleiben Sie hier für immer. Zeit zu wählen.";
			link.l1 = "Verdammt seist du, Leutnant, aber ich bin gezwungen, deine Bedingungen zu akzeptieren. Ich bin hier stark unterlegen.";
			link.l1.go = "officer_13";
			link.l2 = "Zu selbstsicher, Leutnant? Ich vermute, ich sollte dir und deinen Söldnern eine Lektion erteilen. Du verdammter Harzhund!";
			link.l2.go = "officer_15";
		break;
		
		case "officer_13":
			dialog.text = "Sie sind ein vernünftiger Mann, Kapitän. Nehmen Sie Ihre Fässer und verschwinden Sie. Ich sollte Sie warnen, es wird Ihnen nicht helfen, vor dem Gouverneur mit dem Finger auf mich zu zeigen. Ich werde heute den Ort meines Verstecks ändern. Sparen Sie Ihre Zeit.";
			link.l1 = "Habe ich nicht vor. Ich verstehe die Sinnlosigkeit, die Behörden anzusprechen.";
			link.l1.go = "officer_14";
		break;
		
		case "officer_14":
			dialog.text = "Beeil dich, ich habe nicht viel Zeit zu verschwenden.";
			link.l1 = "...";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("FMQM_PeaceExit");
		break;
		
		case "officer_15":
			DialogExit();
			AddDialogExitQuestFunction("FMQM_BattleExit");
		break;
		
		case "greguar":
			PlaySound("Voice\English\LE\Greguar\Greguar_02.wav");
			dialog.text = "Oh! Was für ein Treffen! Grüße, Monsieur! Haben Sie einen großartigen Abend?";
			link.l1 = "Gute Nacht... ah, du bist es! Ich erinnere mich an dich, wir haben uns am allerersten Tag meiner Ankunft in der Karibik getroffen. Monsieur Gregoire Valinnie.";
			link.l1.go = "greguar_1";
		break;
		
		case "greguar_1":
			dialog.text = "Freut mich, dass du dich noch erinnerst. Ich sehe, du bist jetzt Kapitän. Kapitän "+GetFullName(pchar)+". Gratulation.";
			link.l1 = "Danke...";
			link.l1.go = "greguar_2";
		break;
		
		case "greguar_2":
			dialog.text = "Sie sehen beunruhigt aus, Kapitän. Was ist hier passiert? Ist etwas nicht in Ordnung?";
			link.l1 = "Etwas stimmt nicht...";
			link.l1.go = "greguar_3";
		break;
		
		case "greguar_3":
			dialog.text = "Herr, anstatt mitten auf der Straße zu stehen, gehen wir lieber in eine Taverne. Sie könnten ein oder zwei Pints gebrauchen. Dort können wir reden. Komm schon!";
			link.l1 = "...";
			link.l1.go = "greguar_4";
		break;
		
		case "greguar_4":
			DialogExit();
			NextDiag.CurrentNode = "greguar_5"; 
			FreeSitLocator("Fortfrance_tavern", "sit_front4");
			LAi_SetActorType(npchar);
			LAi_ActorRunToLocation(npchar, "reload", "reload4_back", "Fortfrance_tavern", "sit", "sit_front4", "FMQM_InTavern", -1);
		break;
		
		case "greguar_5":
			LAi_SetSitType(Pchar);
			dialog.text = "Mach voll, Kapitän...";
			link.l1 = "Mach es..";
			link.l1.go = "greguar_6";
		break;
		
		case "greguar_6":
			LAi_Fade("", "");
			WaitDate("",0,0,0,1,20);
			RecalculateJumpTable();
			dialog.text = "Wooh... Nun sag mir bitte, was los ist? Du siehst aus wie der Kerl, den sie letzte Woche gehängt haben. Er hatte genau das gleiche Gesicht, als er am Galgen stand.";
			link.l1 = "Sehen Sie, monseniour Gregoire... Sagen wir einfach, dass ich Probleme bei der Arbeit habe.";
			link.l1.go = "greguar_7";
		break;
		
		case "greguar_7":
			dialog.text = "Kapitän, Sie können alles mit mir teilen. Ich werde Sie nicht an den Gouverneur oder den Kommandanten verraten, darauf können Sie mir vertrauen. Vertrauen Sie mir nicht?";
			link.l1 = "Ich vertraue Ihnen, Monsieur.";
			link.l1.go = "greguar_8";
		break;
		
		case "greguar_8":
			dialog.text = "Dann bekenne und bringe etwas Erleichterung in deine Seele. Ich könnte in der Lage sein, dir zu helfen.";
			link.l1 = "Ein örtlicher Schiffsbauer hat mich angeheuert, um einen spanischen Konvoi zu plündern, der aus Trinidad ausgelaufen ist. Er hatte einen starken Bedarf an Harz, das war mein Ziel und er versprach, fünfzehn Dublonen pro Fass zu zahlen. Ich habe den Konvoi aufgespürt, geplündert und die Güter hierher gebracht. Sie haben mein Schiff repariert und die Fässer zur Werft gebracht. Wir waren dabei, unseren Handel abzuschließen, als dieser Offizier aufgetaucht ist... Ich frage mich, wie er es herausfinden konnte?";
			link.l1.go = "greguar_9";
		break;
		
		case "greguar_9":
			dialog.text = "";
			link.l1 = "Das war's, sie hatten uns. Ich denke, ich sollte dem Schiffsbauer ein Lob aussprechen - er hat die ganze Schuld auf sich genommen, ihnen erzählt, das Harz sei sein Eigentum und ich hätte nichts damit zu tun. Am Ende wird er verhaftet und meine Münze ist weg. Das Durcheinander mit der spanischen Karawane war eine Zeit- und Geldverschwendung, obwohl ich Glück hatte, nicht im Gefängnis zu landen. Schenken Sie noch einmal ein, Monsieur Gregoire.";
			link.l1.go = "greguar_10";
		break;
		
		case "greguar_10":
			dialog.text = "Also, der Schiffsbauer ist verhaftet?";
			link.l1 = "Nun, ja. Er wurde von genau dem Offizier ins Gefängnis gebracht, von dem ich gesprochen habe. Du hättest sie sehen sollen.";
			link.l1.go = "greguar_11";
		break;
		
		case "greguar_11":
			dialog.text = "Ja, ich habe sie beide gesehen, obwohl ich keine Ahnung hatte, dass Leutnant Felicien Gronier seinen alten Freund überhaupt verhaften könnte.";
			link.l1 = "Wh... was hast du gerade gesagt?";
			link.l1.go = "greguar_12";
		break;
		
		case "greguar_12":
			dialog.text = "Sie haben richtig gehört. Leutnant Felicien Gronier und Schiffsbauer "+GetFullName(characterFromId("FortFrance_Schiffswerftarbeiter"))+" sind alte Freunde. Sie dienten zusammen in der Armee zurück in Europa. Gronier ist im Militär geblieben und "+GetFullName(characterFromId("FortFrance_Schiffswerfter"))+" hat es geschafft, sein eigenes Geschäft zu gründen.";
			link.l1 = "Also kennen sie sich... Jetzt verstehe ich...";
			link.l1.go = "greguar_13";
		break;
		
		case "greguar_13":
			dialog.text = "Meine Liebe "+pchar.name+", es sieht so aus, als wären Sie hereingelegt worden. Sie sind immer noch ein Neuling hier und sie haben es ausgenutzt. Ich wette hundert Dublonen, dass Monsieur "+GetFullName(characterFromId("FortFrance_Schiffswerftarbeiter"))+" wird in drei Tagen oder weniger wieder in seiner Werft herumlaufen.";
			link.l1 = "Es scheint, Sie haben recht, Monsieur. Sie haben mich reingelegt. Keine Chance, dass dieser Offizier von dem Harz wusste. Perfektes Timing auch.";
			link.l1.go = "greguar_14";
		break;
		
		case "greguar_14":
			dialog.text = "Das ist die Karibik, Monsieur "+pchar.name+". Gewöhne dich daran. Vergiss das Aussehen, der schlimmste Abschaum hier sieht immer aus wie ein geehrter Edelmann.";
			link.l1 = "Ich habe diesen Satz schon einmal irgendwo gehört... Was soll ich mit ihnen machen? Sollte ich den Gouverneur ansprechen?";
			link.l1.go = "greguar_15";
		break;
		
		case "greguar_15":
			dialog.text = "Ich fürchte, dass in diesem Fall "+GetFullName(characterFromId("FortFrance_Schiffswerftarbeiter"))+" wird ihnen eine andere Geschichte erzählen und du wirst im Gefängnis landen.";
			link.l1 = "Typisch. Sehr gut dann! Da das Gesetz nicht auf meiner Seite ist, mache ich es auf meine Weise, verdammt noch mal! Ich gebe nicht so einfach auf.";
			link.l1.go = "greguar_16";
		break;
		
		case "greguar_16":
			dialog.text = "Bitte beruhigen Sie sich "+pchar.name+". Es ist der Ärger und Rum, der spricht, nicht du. Schlaf ein bisschen und denk dann nochmal darüber nach. Vielleicht wäre es das Beste für dich, es loszulassen. Leutnant Felicien Gronier und "+GetFullName(characterFromId("FortFrance_Schiffswerftarbeiter"))+" sind mächtige Leute hier, sie sind weit über deiner Liga. Mach nichts Dummes.";
			link.l1 = "Wir werden sehen. Danke, dass du mich aufgeklärt hast. Es ist gut, dass ich dich getroffen habe.";
			link.l1.go = "greguar_17";
		break;
		
		case "greguar_17":
			dialog.text = "Sei vorsichtig. Denke daran, was ich dir gesagt habe.";
			link.l1 = "Ich werde. Jetzt lasst uns einen letzten Drink nehmen!";
			link.l1.go = "exit";
			AddDialogExitQuest("FMQM_OutTavern");
		break;
		
		case "greguar_18":
			PlaySound("Voice\English\LE\Greguar\Greguar_03.wav");
			dialog.text = "Kapitän "+GetFullName(pchar)+"!";
			link.l1 = "Oh, Monsieur Gregoire! Sie schon wieder!";
			link.l1.go = "greguar_19";
		break;
		
		case "greguar_19":
			dialog.text = "Ja. Nach unserem Gespräch in der Taverne habe ich Nachforschungen über Leutnant Felicien Gronier angestellt. Es stellt sich heraus, dass er vor nicht allzu langer Zeit um einen zehntägigen Urlaub gebeten hat. Sein Antrag wurde genehmigt. Ich habe ihn heute gesehen, er nahm ein Langboot zu einer Tartane, die bald nach Guadeloupe segelte. Sie heißt Topas.\nIch habe dir alles erzählt, jetzt liegt es an dir. Ich bin sicher, du kannst das Muster in Groniers plötzlichem Wunsch, Urlaub zu nehmen und von der Insel auf einer frisch gebauten Tartane wegzusegeln, erkennen.";
			link.l1 = "Verdammt, jetzt ist alles kristallklar für mich, das ist sicher! In diesem Tartane ist mein Harz im Laderaum gelagert! Monseniour Gregoire, danke, Sie haben wirklich geholfen! Kann ich etwas für Sie im Gegenzug tun?";
			link.l1.go = "greguar_20";
		break;
		
		case "greguar_20":
			dialog.text = "Ach, komm schon, mein Freund. Wir sind Edelleute, wir sollten uns gegenseitig helfen. So leben wir. Ich glaube, du hättest dasselbe getan, wenn ich in deiner Lage wäre. Verliere keine Minute, segel nach Norden und finde den Offizier. Engagiere dich nicht in den Kampf, spüre ihn nur auf und finde heraus, was er vorhat. Beeil dich, Kapitän!";
			link.l1 = "Danke nochmal!";
			link.l1.go = "exit";
			AddDialogExitQuest("FMQM_HurryToSea");
		break;
		
		case "pirate":
			dialog.text = "Was schaust du an? Was willst du hier?";
			link.l1 = "He, Kumpel, ich bin hinter meinen Leckereien her. Siehst du diese Fässer dort drüben? Es ist mein Harz, für das sie mir keinen einzigen Pfennig bezahlt haben.";
			link.l1.go = "pirate_1";
			DelLandQuestMark(characterFromId("FMQM_Enemy_crew_2"));
		break;
		
		case "pirate_1":
			dialog.text = "Bist du ein Idiot oder was? Verzieh dich, solange du noch kannst!";
			link.l1 = "Ich habe zu viel Mühe aufgewendet, um dieses Harz zu bekommen, um ein paar dreckige Abschaum mich aufhalten zu lassen.";
			link.l1.go = "pirate_2";
		break;
		
		case "pirate_2":
			dialog.text = "Wir werden deinen feinen Anzug hier begraben!";
			link.l1 = "Oh, wie nett von dir, eine Beerdigung vorzuschlagen, aber ich fürchte, wir werden dich einfach hier am Strand lassen und die Möwen deine Eingeweide fressen lassen!";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("FMQM_ShoreFight");
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}
