// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Welche Art von Fragen, "+GetSexPhrase("mein Sohn","meine Tochter")+"?","Frag nur, ich höre zu..."),"Ich höre zu, sprich jetzt, "+GetSexPhrase("mein Sohn","meine Tochter")+"..., Freund.","Zum dritten Mal, "+GetSexPhrase("mein Sohn","meine Tochter")+", fragen Sie nach dem, was Sie brauchen.","Ein Geistlicher hat viel Arbeit und Sie lenken mich ab, "+GetSexPhrase("mein Sohn","meine Tochter")+"...","Block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Ich habe meine Meinung geändert...","Nicht zu dieser Zeit, Padre..."),"Ich habe nichts zu sagen, meine Entschuldigung.","Ich werde fragen, aber später. Verzeih mir, Vater.","Verzeihen Sie mir, heiliger Vater...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			// калеуче
			if (CheckAttribute(pchar, "questTemp.Caleuche") && pchar.questTemp.Caleuche == "priest")
			{
				link.l1 = "Entschuldigen Sie, Vater, einer der Geistlichen Ihrer Gemeinde hat mich gebeten, das Haus zu untersuchen, in dem Joachim Merriman ein Zimmer gemietet hat...";
				link.l1.go = "caleuche";
			}
		break;
		
		// калеуче
		case "caleuche":
			dialog.text = "So? Bist du dort gewesen, mein Sohn?";
			link.l1 = "Ich habe. Aber ehrlich gesagt, es wäre besser gewesen, wenn ich es nicht getan hätte. Ich wurde von einem Skelett mit einer riesigen Axt im Obergeschoss angegriffen. Ich konnte siegreich hervorgehen, obwohl es sicherlich nicht einfach war.";
			link.l1.go = "caleuche_1";
		break;
		
		case "caleuche_1":
			dialog.text = "Mein Herr, erbarme dich unserer Seelen! Meine schlimmsten Befürchtungen sind wahr geworden!";
			link.l1 = "Das ist noch nicht alles, Vater. Als ich es endlich niedergelegt hatte, kreischte es und klang wie eine Frau. Als ich die Knochen durchsuchte, fand ich etwas Schmuck, so dass man sicher annehmen kann, dass es die verschwundene Wirtin war.";
			link.l1.go = "caleuche_2";
		break;
		
		case "caleuche_2":
			dialog.text = "(bekreuzigt sich)... Armer Diener Gottes, möge der Herr ihre Seele zur Ruhe bringen...";
			link.l1 = "Es sieht so aus, als wäre Merriman tatsächlich ein Hexenmeister. Ich habe keine Ahnung, wie man einen lebenden Mann in eine solche Abscheulichkeit verwandeln kann.";
			link.l1.go = "caleuche_3";
		break;
		
		case "caleuche_3":
			dialog.text = "Joachim Merriman ist ein sehr furchterregender Hexenmeister, mein Sohn. Ich kannte ihn in Europa, aber zu der Zeit war er zu so etwas nicht fähig. Hier, in der Karibik, gelang es ihm, etwas in die Hände zu bekommen, das ihm übernatürliche Kräfte verlieh.";
			link.l1 = "Sie kannten Merriman, Vater?";
			link.l1.go = "caleuche_4";
		break;
		
		case "caleuche_4":
			dialog.text = "That I did. Back then I was just a humble priest in one of Lisbon's parishes. Joachim Merriman was a wealthy nobleman, and at some point he became interested in old manuscripts and scrolls brought by sailors from distant lands. He also began to study alchemy, but after some time he went into seclusion.\nPeople saw flashes of light in his house; sometimes they could also smell something strange. Then they saw him in the cemetery at nights. Once they saw him digging out a fresh corpse and bringing it to his home. And when patience ran out, local father superior contacted the Inquisition.\nWhen the guards breached the door of Merriman's house, Joachim was not there - he had escaped through a secret passage. They found a lab in the basement, and even the seasoned soldiers were shocked and sickened by what they saw. Whole rotting and dismembered bodies, human and animal skeletons, strange things... Fear and hatred for Merriman was so significant that his house was demolished in an instant.\nMerriman disappeared without a trace. The Inquisition began to search for him, sentencing him in his absence to burn at a stake as a dangerous warlock. But they never found him. And now, after all these years, I saw him again on the streets of Willemstad.";
			link.l1 = "Warum haben Sie es den Inquisitoren nicht erzählt?";
			link.l1.go = "caleuche_5";
		break;
		
		case "caleuche_5":
			dialog.text = "Mein Sohn, weißt du nicht, dass unsere Kirche im Streit mit der Inquisition steht? Ich würde mich lieber von Pater Vincento und seinen Schlägern fernhalten.";
			link.l1 = "Ich verstehe. Vater, ich glaube, ich weiß, woher Merriman seine Kraft bezog. Er hat sich eines alten Artefakts bemächtigt, eines Jadetotenschädels von Yum Cimil, einem alten Todesgott, der von den Indianern des Chavin-Stammes verehrt wurde.";
			link.l1.go = "caleuche_6";
		break;
		
		case "caleuche_6":
			dialog.text = "Hm, Merriman war bekannt dafür, zauberhafte Rituale und Experimente an Leichen durchzuführen, also könnte es durchaus wahr sein. Ich danke Gott, dass dieser furchtbare Mann Willemstad verlassen hat und dass du die teuflischen Samen, die er hier zu pflanzen versuchte, zerstört hast. Wir sind dir, mein Sohn, schwer verpflichtet. Bitte akzeptiere diese geweihten Gegenstände als deine Belohnung.";
			link.l1 = "Danke, Vater";
			link.l1.go = "caleuche_7";
		break;
		
		case "caleuche_7":
			Log_Info("You have received church amulets");
			PlaySound("interface\important_item.wav");
			GiveItem2Character(pchar, "amulet_2"); 
			GiveItem2Character(pchar, "amulet_6"); 
			GiveItem2Character(pchar, "amulet_8"); 
			GiveItem2Character(pchar, "amulet_10"); 
			ref sld = characterFromId("Havana_Priest");
			dialog.text = "Aber das war nicht das Ende unserer Sorgen, mein Sohn. Kürzlich habe ich einen Brief erhalten von "+sld.name+", Vater Oberer der Kirche in Havanna. Er bringt schreckliche Nachrichten. In einer Höhle, im Dschungel von Kuba, haben Jäger furchterregende Abscheulichkeiten gesehen, die wandelnden Toten. Und es ist umso belastender, wenn man bedenkt, dass in letzter Zeit Menschen verschwunden sind, nachdem sie in den Dschungel gegangen sind.";
			link.l1 = "Hmm... meinst du, dass dies auch Merrimans Werk ist?";
			if (CheckCharacterItem(pchar, "HolTradeLicence") && GetDaysContinueNationLicence(HOLLAND) >= 30) link.l1.go = "caleuche_8_1";
			else link.l1.go = "caleuche_8";
		break;
		
		case "caleuche_8":
			sld = characterFromId("Havana_Priest");
			dialog.text = "Ich weiß nicht, was ich denken soll, mein Sohn. Aber wenn dieser schwarze Hexer so mächtig geworden ist, sind alle Bewohner des Archipels in großer Gefahr. Nur Gott weiß, was dieser Diener des Teufels im Sinn haben könnte\nIch hoffe doch, dass Vater "+sld.name+" war falsch, aber trotzdem - bitte gehen Sie nach Havanna und sprechen Sie mit ihm. Ich habe eine Handelslizenz für Sie vorbereitet, die einen Monat gültig ist. Damit können Sie ohne Schwierigkeiten den Hafen von Havanna betreten.";
			link.l1 = "In Ordnung, Vater. Ich gehe nach Havanna.";
			link.l1.go = "caleuche_9";
			npchar.quest.givelicence = true;
		break;
		
		case "caleuche_8_1":
			sld = characterFromId("Havana_Priest");
			dialog.text = "Ich weiß nicht, was ich denken soll, mein Sohn. Aber wenn dieser schwarze Hexer so mächtig geworden ist, sind alle Bewohner des Archipels in großer Gefahr. Nur Gott weiß, was dieser Diener der Teufel im Sinn haben könnte.\nIch hoffe wirklich, dass Vater "+sld.name+" war falsch, aber egal - Ich bitte Sie, nach Havanna zu reisen und mit ihm zu sprechen.";
			link.l1 = "Natürlich, Vater. Ich werde sofort nach Havanna aufbrechen.";
			link.l1.go = "caleuche_9";
		break;
		
		case "caleuche_9":
			dialog.text = "Ich freue mich, dass du ein wahrer Sohn der Kirche bist. Ich werde Tag und Nacht für deine Gesundheit und dein Wohlergehen beten. Gehe mit meinem Segen. Möge der Herr dich in deinem Kampf gegen diese unheiligen Mächte stärken.";
			link.l1 = "Danke und Auf Wiedersehen, Vater.";
			link.l1.go = "caleuche_10";
		break;
		
		case "caleuche_10":
			DialogExit();
			AddQuestRecord("Caleuche", "26");
			AddCharacterMaxHealth(pchar, 1);
			if (CheckAttribute(npchar, "quest.givelicence")) GiveNationLicence(HOLLAND, 30);
			ChangeCharacterComplexReputation(pchar, "nobility", 2);
			ChangeCharacterComplexReputation(pchar, "authority", 1);
			ChangeCharacterComplexReputation(pchar, "fame", 3);
			ChangeCharacterNationReputation(pchar, HOLLAND, 5);
			AddCharacterExpToSkill(pchar, "Leadership", 300);
			pchar.questTemp.Caleuche = "havana";
			Caleuche_PrepareCubaGrot();
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
