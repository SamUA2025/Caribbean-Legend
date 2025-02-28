void ApplyMigration(ref migrationState) {
	
	// корсет
	items[FindItem("cirass5")].price = 8000;
	// жилет беретера
	items[FindItem("cirass6")].price = 19000;
	// траншейный доспех
	items[FindItem("cirass1")].price = 58000;
	// дуэльный пистолет
	items[FindItem("pistol5")].price = 38500;
	// флотский карабин
	items[FindItem("mushket2")].price = 38500;
	// заказной мушкет
	items[FindItem("mushket7")].price = 77000;
	// 4х зарядный штуцер
	items[FindItem("mushket8")].price = 230000;
	// тинктура
	items[FindItem("recipe_berserker_potion")].price = 77000;
	// сундук алхимика для элексира
	ref rItem = ItemsFromID("potion2");
	rItem.component.t6.id 	=  "alchemy_tool";
	rItem.component.t6.use =  "AlchemyTool";
	rItem.component.t6.qty =  1;
	
	pchar.HeroModel = "Sharle_1,Sharle_2,Sharle_3,Sharle_4,Sharle_5,protocusto,Sharle_6,Sharle_8,Sharle_7,Sharle_9,Sharle_1,Sharle_11,Sharle_12,Sharle_13";
	
	ExpandItemsArray();
	
	ref	suit;
	int	suitIndex;
	
	suitIndex = TOTAL_ITEMS - 1;
	makeref(suit, Items[suitIndex]);
	
	suit.id					= "cirass9";		
	suit.groupID			= CIRASS_ITEM_TYPE;
	suit.name				= "itmname_" + "cirass9";
	suit.describe			= "itmdescr_" + "cirass9";		
	suit.folder 			= "items";
	suit.model				= "13";
	suit.picTexture			= "ITEMS_38";
	suit.picIndex			= 12;
	suit.price				= 230000;	
	suit.rare 				= 0.01;
	suit.minlevel 			= 20;
	suit.Weight 			= 15;
	suit.Clothes 			= false;
	suit.B_CirassLevel 		= 0.25;
	suit.G_CirassLevel 		= 0.25;
	suit.critical			= 0.3;
	suit.ItemType 			= "SUPPORT";
	suit.TradeType 			= ITEM_TRADE_AMMUNITION;
}
