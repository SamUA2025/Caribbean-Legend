// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{

	switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat("Geh voran, was möchtest du?","Wir haben gerade darüber gesprochen. Du musst es vergessen haben...","Das ist das dritte Mal heute, dass du von irgendeiner Frage sprichst...","Hör zu, das ist ein Laden. Die Leute kaufen hier Sachen. Stör mich nicht!","Block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Weißt du, "+NPChar.name+", vielleicht nächstes Mal.","Richtig, ich habe aus irgendeinem Grund vergessen...","Ja, es ist wirklich das dritte Mal...","Hm, ich werde nicht...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			// Jason НСО
			if (CheckAttribute(pchar, "questTemp.Patria.Goods"))
			{
				link.l1 = "Sie haben meine Waren in Ihrem Lagerhaus gelagert. Tee, Kakao und Lignum Vitae. Ich möchte sie holen.";
                link.l1.go = "patria_goods";
			}
			if (CheckAttribute(pchar, "questTemp.Patria.GoodsSM"))
			{
				link.l2 = "Sie haben meine Waren aus Sint Maarten in Ihrem Lagerhaus gelagert. Baron Noel Forgue hat sie mir hinterlassen.";
                link.l2.go = "patria_goods_3";
			}
		break;
		
		case "patria_goods":
			dialog.text = "Stimmt schon, Kapitän, ich habe Ihre Waren. Sind Sie sicher, dass Sie sie mitnehmen wollen?";
			link.l1 = "Ja.";
			link.l1.go = "patria_goods_1";
			link.l2 = "Halt ein, ich muss zuerst prüfen, ob im Laderaum genug Platz ist.";
			link.l2.go = "exit";
		break;
		
		case "patria_goods_1":
			dialog.text = "Perfekt. Ich werde die Träger beauftragen, es zum Dock zu liefern.";
			link.l1 = "Abgemacht!";
			link.l1.go = "patria_goods_2";
		break;
		
		case "patria_goods_2":
			DialogExit();
			WaitDate("", 0, 0, 0, 4, 10); //крутим время
			RecalculateJumpTable();
			StoreDayUpdate();
			RefreshWeather();
			RefreshLandTime();
			DeleteAttribute(pchar, "questTemp.Patria.Goods");
			SetCharacterGoods(pchar, GOOD_COFFEE, GetCargoGoods(pchar, GOOD_COFFEE) + 500);
			SetCharacterGoods(pchar, GOOD_CHOCOLATE, GetCargoGoods(pchar, GOOD_CHOCOLATE) + 500);
			SetCharacterGoods(pchar, GOOD_SANDAL, GetCargoGoods(pchar, GOOD_SANDAL) + 50);
		break;
		
		case "patria_goods_3":
			dialog.text = "Ja, genau. Ich bewahre es hier nach dem Dekret des Barons auf. Sind Sie sicher, dass Sie sie mitnehmen wollen?";
			link.l1 = "Ja.";
			link.l1.go = "patria_goods_4";
			link.l2 = "Halt ein, ich muss zuerst prüfen, ob genug Platz im Laderaum ist.";
			link.l2.go = "exit";
		break;
		
		case "patria_goods_4":
			dialog.text = "Perfekt. Ich werde die Träger anweisen, es zum Dock zu liefern.";
			link.l1 = "Abgemacht!";
			link.l1.go = "patria_goods_5";
		break;
		
		case "patria_goods_5":
			DialogExit();
			WaitDate("", 0, 0, 0, 4, 10); //крутим время
			RecalculateJumpTable();
			StoreDayUpdate();
			RefreshWeather();
			RefreshLandTime();
			DeleteAttribute(pchar, "questTemp.Patria.GoodsSM"); // 17-add
			SetCharacterGoods(pchar, GOOD_TOBACCO, GetCargoGoods(pchar, GOOD_TOBACCO) + 500);
			SetCharacterGoods(pchar, GOOD_EBONY, GetCargoGoods(pchar, GOOD_EBONY) + 200);
			SetCharacterGoods(pchar, GOOD_MAHOGANY, GetCargoGoods(pchar, GOOD_MAHOGANY) + 250);
			SetCharacterGoods(pchar, GOOD_GOLD, GetCargoGoods(pchar, GOOD_GOLD) + 200);
			SetCharacterGoods(pchar, GOOD_SILVER, GetCargoGoods(pchar, GOOD_SILVER) + 400);
			SetCharacterGoods(pchar, GOOD_SHIPSILK, GetCargoGoods(pchar, GOOD_SHIPSILK) + 200);
		break;
	}
	UnloadSegment(NPChar.FileDialog2);
}
