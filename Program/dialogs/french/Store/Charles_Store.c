// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{

	switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat("Allez-y, que voulez-vous ?","Nous parlions justement de cela. Vous avez dû oublier...","C'est la troisième fois aujourd'hui que tu parles d'une question...","Ecoutez, ceci est un magasin. Les gens achètent des choses ici. Ne me dérangez pas !","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Tu sais, "+NPChar.name+", peut-être la prochaine fois.","D'accord, j'ai oublié pour une raison quelconque...","Oui, c'est vraiment la troisième fois...","Hum, je ne vais pas...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			// Jason НСО
			if (CheckAttribute(pchar, "questTemp.Patria.Goods"))
			{
				link.l1 = "Vous avez mes marchandises entreposées dans votre entrepôt. Thé, cacao et bois de gaïac. Je veux les récupérer.";
                link.l1.go = "patria_goods";
			}
			if (CheckAttribute(pchar, "questTemp.Patria.GoodsSM"))
			{
				link.l2 = "Vous avez mes marchandises de Sint Maarten entreposées dans votre entrepôt. Le Baron Noel Forgue me les a laissées.";
                link.l2.go = "patria_goods_3";
			}
		break;
		
		case "patria_goods":
			dialog.text = "Exactement, capitaine, j'ai vos marchandises. Êtes-vous sûr de vouloir les prendre ?";
			link.l1 = "Oui.";
			link.l1.go = "patria_goods_1";
			link.l2 = "Attendez, je dois d'abord vérifier s'il y a assez de place dans la cale.";
			link.l2.go = "exit";
		break;
		
		case "patria_goods_1":
			dialog.text = "Parfait. Je vais ordonner aux porteurs de le livrer au quai.";
			link.l1 = "Marché conclu !";
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
			dialog.text = "Oui, exactement. Je le garde ici par décret du baron. Es-tu sûr de vouloir les prendre ?";
			link.l1 = "Oui.";
			link.l1.go = "patria_goods_4";
			link.l2 = "Attendez, je dois d'abord vérifier s'il y a assez de place dans la cale.";
			link.l2.go = "exit";
		break;
		
		case "patria_goods_4":
			dialog.text = "Parfait. Je vais ordonner aux porteurs de le livrer au quai.";
			link.l1 = "Marché conclu!";
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
