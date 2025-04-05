void ApplyMigration(ref migrationState) {
	
	ref itm;
	int n;
	
	makeref(itm, items[FindItem("Reserve_item_11")]); // Разбросанные записки
	itm.id = "PR_Letter"; 
	itm.name = "itmname_PR_letter";
	itm.describe = "itmdescr_PR_letter";
	itm.model = "Letter_sp2";
	itm.picIndex = 6;
	itm.picTexture = "ITEMS_26";
	itm.price = 0;
	itm.Weight = 0.5;
	itm.ItemType = "QUESTITEMS";
	
	makeref(itm, items[FindItem("Reserve_item_12")]); // ключ от подсвечника Порт Рояль
	itm.id = "key_candlestick_PortRoyal";
	itm.name = "itmname_key_candlestick_PortRoyal";
	itm.describe = "itmdescr_key_candlestick_PortRoyal";
	itm.model = "keysimple";
	itm.picIndex = 16;
	itm.picTexture = "ITEMS_34";
	itm.Weight = 0.3;
	itm.useLocation = "PortRoyal_WineCellar";
	itm.useLocator = "button01";
	itm.price = 0;
	itm.ItemType = "QUESTITEMS";
	
	makeref(itm, items[FindItem("Reserve_item_13")]); // ключ от подсвечника Виллемстад
	itm.id = "key_candlestick_Villemstad";
	itm.name = "itmname_key_candlestick_Villemstad";
	itm.describe = "itmdescr_key_candlestick_Villemstad";
	itm.model = "keysimple";
	itm.picIndex = 4;
	itm.picTexture = "ITEMS_24";
	itm.Weight = 0.3;
	itm.useLocation = "Villemstad_WineCellar";
	itm.useLocator = "button01";
	itm.price = 0;
	itm.ItemType = "QUESTITEMS";
	
	ExpandItemsArray();
	n = TOTAL_ITEMS - 1;
	
	makeref(itm,Items[n]);
	itm.id = "hat1";
	itm.groupID	= HAT_ITEM_TYPE;
	itm.name = "itmname_hat1";
	itm.describe = "itmdescr_hat1";
	itm.model = "hat1";
	itm.picIndex = 1;
	itm.picTexture = "ITEMS_40";
	itm.price = 22000;
	itm.Weight = 0.1;
	itm.ItemType = "SUPPORT";
	itm.TradeType = ITEM_TRADE_AMMUNITION;
	
	ExpandItemsArray();
	n = TOTAL_ITEMS - 1;
	
	makeref(itm,Items[n]);
	itm.id = "hat2";
	itm.groupID	= HAT_ITEM_TYPE;
	itm.name = "itmname_hat2";
	itm.describe = "itmdescr_hat2";
	itm.model = "hat2";
	itm.picIndex = 2;
	itm.picTexture = "ITEMS_40";
	itm.price = 75000;
	itm.Weight = 0.1;
	itm.ItemType = "SUPPORT";
	itm.TradeType = ITEM_TRADE_AMMUNITION;
	
	ExpandItemsArray();
	n = TOTAL_ITEMS - 1;
	
	makeref(itm,Items[n]);
	itm.id = "hat3";
	itm.groupID	= HAT_ITEM_TYPE;
	itm.name = "itmname_hat3";
	itm.describe = "itmdescr_hat3";
	itm.model = "hat3";
	itm.picIndex = 3;
	itm.picTexture = "ITEMS_40";
	itm.price = 18000;
	itm.Weight = 0.1;
	itm.ItemType = "SUPPORT";
	itm.TradeType = ITEM_TRADE_AMMUNITION;
	
	ExpandItemsArray();
	n = TOTAL_ITEMS - 1;
	
	makeref(itm,Items[n]);
	itm.id = "hat4";
	itm.groupID	= HAT_ITEM_TYPE;
	itm.name = "itmname_hat4";
	itm.describe = "itmdescr_hat4";
	itm.model = "hat4";
	itm.picIndex = 4;
	itm.picTexture = "ITEMS_40";
	itm.price = 87000;
	itm.Weight = 0.1;
	itm.ItemType = "SUPPORT";
	itm.TradeType = ITEM_TRADE_AMMUNITION;
	
	ExpandItemsArray();
	n = TOTAL_ITEMS - 1;
	
	makeref(itm,Items[n]);
	itm.id = "hat5";
	itm.groupID	= HAT_ITEM_TYPE;
	itm.name = "itmname_hat5";
	itm.describe = "itmdescr_hat5";
	itm.model = "hat5";
	itm.picIndex = 5;
	itm.picTexture = "ITEMS_40";
	itm.price = 800000;
	itm.Weight = 0.1;
	itm.ItemType = "SUPPORT";
	itm.TradeType = ITEM_TRADE_AMMUNITION;
	
	ExpandItemsArray();
	n = TOTAL_ITEMS - 1;
	
	makeref(itm,Items[n]);
	itm.id = "hat6";
	itm.groupID	= HAT_ITEM_TYPE;
	itm.name = "itmname_hat6";
	itm.describe = "itmdescr_hat6";
	itm.model = "hat6";
	itm.picIndex = 6;
	itm.picTexture = "ITEMS_40";
	itm.price = 115000;
	itm.Weight = 0.1;
	itm.ItemType = "SUPPORT";
	itm.TradeType = ITEM_TRADE_AMMUNITION;
	
	ExpandItemsArray();
	n = TOTAL_ITEMS - 1;
	
	makeref(itm,Items[n]);
	itm.id = "hat7";
	itm.groupID	= HAT_ITEM_TYPE;
	itm.name = "itmname_hat7";
	itm.describe = "itmdescr_hat7";
	itm.model = "hat7";
	itm.picIndex = 7;
	itm.picTexture = "ITEMS_40";
	itm.price = 77777;
	itm.Weight = 0.1;
	itm.ItemType = "SUPPORT";
	itm.TradeType = ITEM_TRADE_AMMUNITION;
	
	ExpandItemsArray();
	n = TOTAL_ITEMS - 1;
	
	makeref(itm,Items[n]);
	itm.id = "hat8";
	itm.groupID	= HAT_ITEM_TYPE;
	itm.name = "itmname_hat8";
	itm.describe = "itmdescr_hat8";
	itm.model = "hat8";
	itm.picIndex = 8;
	itm.picTexture = "ITEMS_40";
	itm.price = 450000;
	itm.Weight = 0.1;
	itm.ItemType = "SUPPORT";
	itm.TradeType = ITEM_TRADE_AMMUNITION;

    // Сокровища
    InitWeightParameters();
	TreasureTiersInit(SandBoxMode);
}
