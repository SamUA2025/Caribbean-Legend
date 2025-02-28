// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Welche Fragen haben Sie?","Wie kann ich Ihnen helfen?"),"Du hast versucht, mir diese Frage vor kurzem zu stellen...","Jawohl, lass mich raten... Wieder mal im Kreis unterwegs?","Hör zu, ich mache hier die Finanzen, ich beantworte keine Fragen...","Block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Ich habe meine Meinung geändert...","Ich habe im Moment nichts zu besprechen."),"Umph, wo ist mein Gedächtnis hin...","Du hast es erraten, es tut mir leid...","Ich verstehe...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			if (CheckAttribute(pchar, "questTemp.Guardoftruth") && pchar.questTemp.Guardoftruth == "utensil" && !CheckAttribute(npchar, "quest.utensil"))
			{
				link.l1 = "Herr, ich habe eine etwas ungewöhnliche Angelegenheit. Ich weiß, dass ein französischer Freibeuter namens Gaius Marchais Ihnen kürzlich zwei einzigartige Gegenstände verkauft hat: ein goldenes Ostensorium und ein goldenes Räuchergefäß. Ich möchte sie von Ihnen kaufen.";
                link.l1.go = "guardoftruth";
			}
			if (CheckAttribute(npchar, "quest.GOT_chest") && CheckCharacterItem(pchar, "chest"))
			{
				link.l1 = "Ich habe Ihnen eine kleine Kiste mit Dublonen gebracht.";
                link.l1.go = "guardoftruth_3";
			}
		break;
		
		case "guardoftruth":
			dialog.text = "Oh, ja! Ich erinnere mich natürlich an sie! Ja, sie waren wirklich originell und vor allem teure Gegenstände. Aber du bist zu spät, Kapitän, ich habe sie nicht mehr. Ich habe sie bereits verkauft.";
			link.l1 = "Unglaublich! Und wer war an Kirchengeräten dieser Art interessiert? Mynheer, an wen haben Sie sie verkauft? Ich würde gerne versuchen, sie zurückzukaufen...";
			link.l1.go = "guardoftruth_1";
			npchar.quest.utensil = "true";
		break;
		
		case "guardoftruth_1":
			dialog.text = "Hm, und warum sollte ich Ihnen die Namen meiner Kunden nennen?";
			if (CheckAttribute(pchar, "questTemp.HWIC.Detector") && pchar.questTemp.HWIC.Detector == "self_win")
			{
				link.l1 = "Vielleicht, weil ich in den Augen des Gouverneurs Matthias Beck ein guter Freund bin und ich ihn um eine entsprechende Sanktion für dich bitten könnte?";
				link.l1.go = "guardoftruth_2_1";
			}
			else
			{
				if (CheckAttribute(pchar, "questTemp.HWIC.Detector") && pchar.questTemp.HWIC.Detector == "holl_win")
				{
					link.l1 = "Vielleicht, weil ich in guten Beziehungen zur Niederländischen Westindien-Kompanie stehe und vielen niederländischen Siedlern auf dem Archipel große Hilfe geleistet habe?";
					link.l1.go = "guardoftruth_2_2";
				}	
				else
				{
					link.l1 = "Vielleicht weil ich dafür bezahlen werde?";
					link.l1.go = "guardoftruth_2_3";
					npchar.quest.GOT_chest = "true";
				}
			}
		break;
		
		case "guardoftruth_2_1":
			dialog.text = "Ach, sicher du bist "+GetFullName(pchar)+", ein Freund des Gouverneurs selbst, der die kriminelle Verschwörung von Lucas Rodenburg aufgedeckt hat... Wie könnte ich das vergessen? Natürlich werde ich es Ihnen sagen.";
			link.l1 = "Dann bin ich ganz Ohr.";
			link.l1.go = "guardoftruth_4";
		break;
		
		case "guardoftruth_2_2":
			dialog.text = "Ach, richtig, du bist "+GetFullName(pchar)+", der große Eroberer des Piraten 'Geisterschiffs'. Wie könnte ich das vergessen? Natürlich werde ich es Ihnen sagen.";
			link.l1 = "Dann bin ich ganz Ohr.";
			link.l1.go = "guardoftruth_4";
		break;
		
		case "guardoftruth_2_3":
			dialog.text = "Also gut, dann. Für eine Truhe, die bis zum Rand mit Gold-Dublonen gefüllt ist, nehme ich an, werde ich Ihnen von denen erzählen, die Sie beim Kauf überholt haben.";
			if (CheckCharacterItem(pchar, "chest"))
			{
				link.l1 = "Hier, nimm. Das sind sehr wertvolle Gegenstände für mich...";
				link.l1.go = "guardoftruth_3";
			}
			else
			{
				link.l1 = "In Ordnung, ich bringe Ihnen, was Sie verlangen. Sie sind mir sehr teure Gegenstände...";
				link.l1.go = "exit";
			}
		break;
		
		case "guardoftruth_3":
			RemoveItems(pchar, "chest", 1);
			Log_Info("You've given a chest of doubloons");
			PlaySound("interface\important_item.wav");
			dialog.text = "Wunderbar. In diesem Fall bin ich bereit, einige Informationen mit Ihnen zu teilen.";
			link.l1 = "Ich bin ganz Ohr.";
			link.l1.go = "guardoftruth_4";
			DeleteAttribute(npchar, "quest.GOT_chest");
		break;
		
		case "guardoftruth_4":
			dialog.text = "Der goldene Weihrauchkessel wurde von einem Mann namens Rolande Moses gekauft, besser bekannt als Rollie der Kap. Warum dieser Metzger ein kostbares Kirchenrelikt brauchte, kann ich nicht herausfinden, aber aus irgendeinem Grund war er unsagbar darüber erfreut... Übrigens, ich bezweifle, dass du Rollie selbst treffen wirst.";
			link.l1 = "Warum ist das so?";
			link.l1.go = "guardoftruth_5";
		break;
		
		case "guardoftruth_5":
			dialog.text = "Weil dieser gierige Räuber einsamer englischer Kaufleute kürzlich mit seiner Schoner direkt in die Pfoten von Oberst Fox geraten ist. Kennst du ihn? ";
			link.l1 = "Natürlich! Der Kommandant der 'Seefüchse' in St. Jones auf Antigua...";
			link.l1.go = "guardoftruth_6";
		break;
		
		case "guardoftruth_6":
			dialog.text = "Nun, dann verstehen Sie, warum wir unseren armen Rolande nie wieder sehen werden. Der Oberst hat seine Schoner mit allen Überlebenden seiner Besatzung beschlagnahmt und sie nach St. Jones gebracht, wo ihnen wahrscheinlich bereits ein Seil um den Hals gelegt wurde.";
			link.l1 = "Ich verstehe. Und das Monstranz?";
			link.l1.go = "guardoftruth_7";
		break;
		
		case "guardoftruth_7":
			dialog.text = "Das Ostensorium wurde erst kürzlich von Senora Belinda de Ribero aus Cumana erworben. Eine sehr bemerkenswerte Senora, eine Verwandte von Fernando de Villegas selbst, dem Gouverneur von Cumana. Ich nehme an, dass sie es als Geschenk für die Kirche mitbringen wollte.";
			link.l1 = "Senora Belinda de Ribero? Kann ich sie in Cumana finden, richtig?";
			link.l1.go = "guardoftruth_8";
		break;
		
		case "guardoftruth_8":
			dialog.text = "Definitiv. Sie selbst sagte, dass sie direkt von Willemstad nach Hause gehen würde.";
			link.l1 = "In Ordnung. Danke, "+npchar.name+", du warst eine große Hilfe!";
			link.l1.go = "guardoftruth_9";
		break;
		
		case "guardoftruth_9":
			dialog.text = "Jederzeit, mein Herr. Besuchen Sie mich ab und zu!";
			link.l1 = "Ich wünsche Ihnen reiche Kunden mit fetten Brieftaschen und spärlichen Gehirnen... Ha-ha!";
			link.l1.go = "guardoftruth_10";
		break;
		
		case "guardoftruth_10":
			DialogExit();
			AddQuestRecord("Guardoftruth", "23");
			pchar.questTemp.Guardoftruth.Usurer = "true";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
