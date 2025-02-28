// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Welche Fragen haben Sie?","Wie kann ich Ihnen helfen?"),"Du hast versucht, mir diese Frage vor kurzem zu stellen...","Ja, lass mich raten... Wieder mal im Kreis unterwegs?","Hör zu, ich mache hier die Finanzen, ich beantworte keine Fragen...","Block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Ich habe meine Meinung geändert...","Ich habe im Moment nichts zu besprechen."),"Hmpf, wo ist nur mein Gedächtnis hin...","Du hast es erraten, es tut mir leid...","Ich verstehe...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			//Голландский гамбит, Голландия
			if (CheckAttribute(pchar, "questTemp.HWIC.Holl") && pchar.questTemp.HWIC.Holl == "SantiagoTripBegin")
			{
				link.l1 = "Herr, ich bin Kapitän "+GetFullName(pchar)+", und ich bin hier auf einem Botengang für Lucas Rodenburg. Ich habe ein Paket von ihm für Sie.";
				link.l1.go = "SantiagoTripBank";	
			}
			if (CheckAttribute(pchar, "questTemp.HWIC.Holl") && pchar.questTemp.HWIC.Holl == "SantiagoTripReturn")
			{
				link.l1 = "Ich bin wegen der Antwort des älteren Lucas Rodenburg gekommen.";
				link.l1.go = "SantiagoTripBank_3";	
			}
			//Голландский гамбит, Голландия
		break;
		
		case "SantiagoTripBank":
			if (GetCharacterItem(pchar, "Chest") >= 5)
			{
			dialog.text = "Stell dir vor... ein Paket! Nun, gib es her, Ältester.";
			link.l1 = "Auch hat Senior Rodenburg darum gebeten, Ihnen dies zu übertragen...";
			link.l1.go = "SantiagoTripBank_1";
			RemoveItems(PChar, "NPC_Letter", 1);
			RemoveItems(PChar, "Chest", 5);
			DelLandQuestMark(npchar);
			}
			else
			{
			dialog.text = "Soweit ich weiß, sollte ich außer dem Paket noch etwas anderes erhalten, Kapitän. Also... wo ist es? Verstehen Sie, wovon ich spreche?";
			link.l1 = "Aber natürlich! Die Truhen werden auf meinem Schiff sicher bewacht. Ich werde sie Ihnen sofort liefern.";
			link.l1.go = "exit";
			}
		break;
		
		case "SantiagoTripBank_1":
			dialog.text = "Hm-m... interessant. Also er 'sendet seine Bedauern'. Nun-nun. Obwohl, das Bedauern des älteren Rodenburg ist ziemlich überzeugend, es ist schwer zu leugnen. Älterer, es wird einige Zeit dauern, eine angemessene Antwort zu schreiben, könnten Sie morgen um die Mittagszeit noch einmal vorbeikommen, um eine Antwort zu erhalten? Ruhen Sie sich in einer Taverne aus, gehen Sie durch die Stadt. Santiago hat viel zu bieten.";
			link.l1 = "Gut, ich werde morgen gegen Mittag zurück sein. Bis dann, Senor.";
			link.l1.go = "SantiagoTripBank_2";
		break;
		
		case "SantiagoTripBank_2":
			DialogExit();
			pchar.quest.SantiagoTripOver.over = "yes"; //снять таймер
			bDisableFastReload = true;
			pchar.quest.Santiago_Trip.win_condition.l1 = "location";
			pchar.quest.Santiago_Trip.win_condition.l1.location = "Santiago_town";
			pchar.quest.Santiago_Trip.function = "SantiagoTrip_Attack";
			pchar.questTemp.HWIC.Holl = "SantiagoTripAttack";
			LAi_LocationDisableOfficersGen("Santiago_town", true);//офицеров не пускать // 291112
		break;
		
		case "SantiagoTripBank_3":
			dialog.text = "Ja, natürlich... aber ich glaube, wir kommen auch ohne schriftliche Konventionalitäten aus. Sag ihm einfach diese Worte 'dieser Mann muss sterben'. Das wäre fair und wir hätten keine Probleme hinsichtlich des 'Wertes' der erhaltenen Entschuldigungen. Und der Vorfall wird als vollständig geklärt betrachtet.";
			link.l1 = "Gut, das werde ich mir merken, senor. Noch etwas?";
			link.l1.go = "SantiagoTripBank_4";
			DelLandQuestMark(npchar);
		break;
		
		case "SantiagoTripBank_4":
			dialog.text = "Ja, natürlich. Was ich gesagt habe, ist der Wille der Familie Giraldi. Und Sie können natürlich meine besten Wünsche an Senor Lucas weitergeben. Ich wünsche Ihnen eine faire Wind, Kapitän "+GetFullName(pchar)+".";
			link.l1 = "Ich verstehe. Auf Wiedersehen, Senior "+npchar.name+".";
			link.l1.go = "SantiagoTripBank_5";
		break;
		
		case "SantiagoTripBank_5":
			DialogExit();
			pchar.questTemp.HWIC.Holl = "SantiagoTripFinal";
			LAi_LocationDisableOfficersGen("Santiago_town", false);//офицеров пускать // 291112
			AddLandQuestMark(characterFromId("Lucas"), "questmarkmain");
			AddMapQuestMarkCity("Villemstad", true);
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
