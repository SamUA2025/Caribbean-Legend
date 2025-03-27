void ApplyMigration(ref migrationState) {
	
	ref refShip;
	// Военная шнява "Леди Бет"
	makeref(refShip,ShipsTypes[SHIP_LADYBETH]);
	refShip.Name            			= "LadyBeth";
	refship.Soundtype					= "corvette";
	refShip.Class						= 4;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS24;
	refShip.MaxCaliber      			= 24;	
	refShip.Weight						= Tonnes2CWT(386);	
	refShip.Capacity        			= 2630;
	refShip.CannonsQuantity				= 20; // 9,9,2,0
	refShip.CannonsQuantityMin			= 20;
	refShip.rcannon 					= 9;
	refShip.lcannon 					= 9;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 0;		
	refShip.MaxCrew         			= 190;
	refShip.OptCrew         			= 152;
	refShip.MinCrew         			= 22;	
	refShip.SpeedRate       			= 14.5;
	refShip.TurnRate        			= 52.0;
	refShip.Price           			= 42000;
	refShip.HP              			= 2430;
	refShip.SP              			= 100;

	refship.Type.Merchant				= true;
	refship.Type.War					= true;
	refship.QuestShip                   = true;
	
	refShip.lowpolycrew 				= 12;

	refship.Rocking.y 					= 0.5;
	refship.Rocking.az 					= 0.04;
	
	refship.WaterLine					= 0.8;
	refship.SpeedDependWeight			= 0.27;
	refship.SubSeaDependWeight			= 0.6;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   			= 1.20;
	
	refship.CabinType          			= "Cabin_Medium"; 

	refship.InertiaAccelerationX	= 5.5;	refship.InertiaBrakingX		= 5.5;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 6.0;
	
	refShip.Height.Bombs.Y				= 2.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y				= 3.4;		refShip.Height.Grapes.DY	= 1.7;
	refShip.Height.Knippels.Y			= 13.2;		refShip.Height.Knippels.DY	= 11.6;
	refShip.Height.Balls.Y				= 2.0;		refShip.Height.Balls.DY		= 1.0;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.8;
	refShip.GeraldSails.rey_b3.vscale		= 0.8;
	
	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 12;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "4.0, 6.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	refShip.cannonr  = refShip.rcannon;
	refShip.cannonl  = refShip.lcannon;
	refShip.cannonf  = refShip.fcannon;
	refShip.cannonb  = refShip.bcannon;
	
	ref itm;
	int i, n;
    string sTemp, sVar;
	
	// Аркебуза конкистадора SP2
	ExpandItemsArray();
	n = TOTAL_ITEMS - 1;
	
	SP2InitStdMusket(n, "mushket9",    "Mushket1_SP2", "ITEMS_39",   10, 0.0001,  1,   39000, 150.0,   375.0, 22.0, 1, B_UNIQUE);
	SP2InitMushketExt(	"mushket9",  10.0,  25.0,  10.0,  20.0, "FencingH", "FencingL" );
	SP2InitGunExt("mushket9", "t1", "grapeshot", "gunpowder",  70.0, 120.0,  40.0,  90.0,  0.0,  0.0, 0, 1, 1, 0, 1, 1, 60, 45, 1);
	SP2InitGunExt("mushket9", "t2", "GunEchin", "",  70.0, 120.0,  40.0,  90.0,  0.0,  0.0, 0, 1, 1, 0, 1, 1, 45, 35, 0);
	SP2InitGrapeGunExt(	"mushket9",	"t1",		3,		75,		10.0,	9.0,	5);		// Аркебуза конкистадора SP2, картечь
	SP2InitGrapeGunExt(	"mushket9",	"t2",		3,		75,	    8.5,	7.85,	4);		// Аркебуза конкистадора SP2, ежовый заряд
	
	// Запчасти от Аркебузы конкистадора SP2
	for(i = 1; i <= 3; i++)
	{
		ExpandItemsArray();
		n = TOTAL_ITEMS - 1;
		
		makeref(itm,Items[n]);
		itm.id = "FirearmStockPart_" + i;
		itm.name = "itmname_FirearmStockPart_" + i;
		itm.describe = "itmdescr_FirearmStockPart_" + i;
		itm.model = "";
		itm.PartNumber = i;
		itm.picIndex = 12 + i;
		itm.picTexture = "ITEMS_39";
		itm.price = 0;
		itm.Weight = 0.5;
		itm.ItemType = "QUESTITEMS";
		itm.groupID	= SPECIAL_ITEM_TYPE;
	}
	
	// Оберег Устав Блеквуда SP2
	ExpandItemsArray();
	n = TOTAL_ITEMS - 1;
	
	SP2InitStdTalisman(n, "talisman18", "", "ITEMS_39", 16, rand(5000), 0.5, "");
	
	// Дневник Блеквуда
	ExpandItemsArray();
	n = TOTAL_ITEMS - 1;
	
	makeref(itm,Items[n]);
	itm.id = "LadyBeth_Book";
	itm.name = "itmname_LadyBeth_Book";
	itm.describe = "itmdescr_LadyBeth_Book";
	itm.model = "OpenBook";
	itm.picIndex = 15;
	itm.picTexture = "ITEMS_26";
	itm.price = 0;
	itm.Weight = 1.0;
	itm.ItemType = "QUESTITEMS";
	
	// карта Блеквуда
	ExpandItemsArray();
	n = TOTAL_ITEMS - 1;
	
	makeref(itm,Items[n]);
	itm.id = "LadyBeth_Map";
	itm.groupID = MAPS_ITEM_TYPE;
	itm.name = "itmname_LadyBeth_Map";
	itm.describe = "itmdescr_LadyBeth_Map";
	itm.model = "";
	itm.picIndex = 5;
	itm.picTexture = "ITEMS_27";
	itm.price = 0;
	itm.Weight = 0.1;
	itm.imageTga = "none";
	itm.imageType = "MapRead"; // текстовая форма
	itm.ItemType = "QUESTITEMS";
	itm.Atlas = 0;
	itm.mapType = "Special";

    // Fix
    for(i = 11; i <= 15; i++)
    {
        sTemp = "T" + i;
        Render.(sTemp).Jewelry.icollection = "On";
        DeleteAttribute(&Render, sTemp + ".Jewelry.incas_collection");
    }
    Render.T11.Jewelry.icollection.min = 1;
    Render.T11.Jewelry.icollection.dif = 1;
    Render.T12.Jewelry.icollection.min = 1;
    Render.T12.Jewelry.icollection.dif = 1;
    Render.T13.Jewelry.icollection.min = 1;
    Render.T13.Jewelry.icollection.dif = 1;
    Render.T14.Jewelry.icollection.min = 2;
    Render.T14.Jewelry.icollection.dif = 2;
    Render.T15.Jewelry.icollection.min = 3;
    Render.T15.Jewelry.icollection.dif = 3;

    // Описания карт сокровищ (shuffle bag)
    for(i = 1; i <= 3; i++)
    {
        sTemp = "T" + i;
        for(int j = 1; j <= 3; j++)
        {
            sVar = "v" + j;
            Render.TresuareMapDescribe.(sTemp).(sVar) = j;
        }
    }

    // --> Правки тиров
    Render.T8.Equip.spyglass3 = "On";
    Render.T9.Equip.spyglass3 = "On";
    Render.T12.Equip.spyglass4 = "On";
    Render.T13.Equip.spyglass4 = "On";
    Render.T14.Equip.spyglass4 = "On";
    Render.T10.Jewelry.berserker_potion = "On";
    Render.T10.Jewelry.berserker_potion.min = 1;
    Render.T10.Jewelry.berserker_potion.dif = 0;
    Render.T11.Jewelry.berserker_potion = "On";
    Render.T11.Jewelry.berserker_potion.min = 1;
    Render.T11.Jewelry.berserker_potion.dif = 0;
    Render.T12.Jewelry.berserker_potion = "On";
    Render.T12.Jewelry.berserker_potion.min = 1;
    Render.T12.Jewelry.berserker_potion.dif = 1;
    Render.T13.Jewelry.berserker_potion = "On";
    Render.T13.Jewelry.berserker_potion.min = 1;
    Render.T13.Jewelry.berserker_potion.dif = 1;
    SP2SetSingleItemToTiers(10, 15, "Jewelry", "recipe_GunEchin");
    SP2SetSingleItemToTiers(15, 15, "Jewelry", "Mineral32");
    SP2SetSingleItemToTiers(15, 15, "Jewelry", "Tigel");
    SP2SetSingleItemToTiers(15, 15, "Jewelry", "chemistry");
    SP2SetSingleItemToTiers(15, 15, "Special", "Map_Best");
    // <-- Правки тиров

    // --> Записки
    for(i = 1; i <= TREASURE_NOTES; i++)
    {
        sTemp = i; //Safe moment
        PChar.questTemp.Treasure_Stories.(sTemp) = i;
	}

	ExpandItemsArray();
	n = TOTAL_ITEMS - 1;

    makeref(itm,Items[n]);
    itm.id = "treasure_note";
    itm.groupID = SPECIAL_ITEM_TYPE;
    itm.name = "itmname_treasure_note";
    itm.describe = "itmdescr_treasure_note";
    itm.model = "";
    itm.picIndex = 16;
    itm.picTexture = "ITEMS_26";
    itm.price = 0;
    itm.Weight = 0.1;
    itm.ItemType = "QUESTITEMS";
    // <-- Записки
    
	worldMap.icon.num = 16;
	
	SeaShipCamera.SensivityDistance = 5.0;
}

void SP2InitStdMusket(	int		ItemIndex, 
				string 	id, 
				string 	ModelID, 
				string 	picTexture,
				int		picIndex, 
				float	Rare, 
				int 	MinLevel, 
				int		Price, 
				float 	DmgMin, 
				float 	DmgMax, 
				float 	Weight,
				int 	Charges, 
				int 	Quality )
{
	ref	Mus;
	int	MusIndex;
	
	MusIndex = ItemIndex;
	makeref(Mus, Items[MusIndex]);
	
	Mus.id				= id;		
	Mus.groupID			= MUSKET_ITEM_TYPE;
	Mus.name			= "itmname_" + id;
	Mus.describe		= "itmdescr_" + id;		
	Mus.model			= ModelID;
	Mus.folder 			= "ammo";
	Mus.chargeQ			= Charges;
	Mus.picTexture		= picTexture;
	Mus.picIndex		= picIndex;
	Mus.dmg_min			= DmgMin;
	Mus.dmg_max			= DmgMax;
	Mus.price			= Price;	
	Mus.ItemType 		= "WEAPON";
	Mus.rare 			= Rare;
	Mus.quality 		= Quality;
	Mus.minlevel 		= MinLevel;
	Mus.Weight 			= Weight;
	Mus.ChargeSpeed 	= 10.0; // by default
	Mus.accuracy 		= 50.0; // by default
	Mus.TradeType 		= ITEM_TRADE_AMMUNITION;
}

void SP2InitMushketExt(string id, 
					float  DmgMin_butt,  
					float  DmgMax_butt, 
					float  DmgMin_bayonet, 
					float  DmgMax_bayonet, 
					string sAttack_butt, 
					string sAttack_bayonet )
{
	ref gun = ItemsFromID(id);
	gun.DmgMin_butt 	= DmgMin_butt;
	gun.DmgMax_butt 	= DmgMax_butt;
	gun.DmgMin_bayonet 	= DmgMin_bayonet;
	gun.DmgMax_bayonet 	= DmgMax_bayonet;
	gun.sAttack_butt 	= sAttack_butt;
	gun.sAttack_bayonet = sAttack_bayonet;	
}

void SP2InitGunExt(string id,			
				string sAttr,       
				string sBullet,     
				string sGunPowder,  
				float  DmgMin_NC,   
				float  DmgMax_NC,   
				float  DmgMin_C,    
				float  DmgMax_C,    
				float  EnergyP_NC,  
				float  EnergyP_C,   
				bool   Stun_NC,     
				bool   Stun_C,      
				bool   MultiDamage, 
				int    MisFire,     
				bool   SelfDamage,  
				bool   Explosion,   
				float  Accuracy,    
				int    ChargeSpeed, 
				bool   isDefault )
{
	ref gun = ItemsFromID(id);
	gun.type.(sAttr).bullet 		= sBullet;
	gun.type.(sAttr).gunpowder 		= sGunPowder;
	gun.type.(sAttr).DmgMin_NC		= DmgMin_NC;
	gun.type.(sAttr).DmgMax_NC		= DmgMax_NC;
	gun.type.(sAttr).DmgMin_C		= DmgMin_C;
	gun.type.(sAttr).DmgMax_C		= DmgMax_NC;
	gun.type.(sAttr).EnergyP_NC		= EnergyP_NC;
	gun.type.(sAttr).EnergyP_C		= EnergyP_C;
	gun.type.(sAttr).Stun_NC		= Stun_NC;
	gun.type.(sAttr).Stun_C			= Stun_C;
	gun.type.(sAttr).multidmg       = MultiDamage;
	gun.type.(sAttr).misfire        = MisFire;
	gun.type.(sAttr).SelfDamage     = SelfDamage;
	gun.type.(sAttr).Explosion      = Explosion;
	gun.type.(sAttr).Accuracy       = Accuracy;
	gun.type.(sAttr).ChargeSpeed    = ChargeSpeed;
	gun.type.(sAttr).Default        = isDefault;
}

void SP2InitGrapeGunExt(string id, string sAttr, int basedmg, int shards, float width, float height, int dispersion)
{
	ref gun = ItemsFromID(id);
	gun.type.(sAttr).basedmg = basedmg;
	gun.type.(sAttr).shards = shards;
	string sArea = "grapes_area_"+dispersion;
	gun.type.(sAttr).area = XI_ConvertString(sArea);
	gun.type.(sAttr).width = width;
	gun.type.(sAttr).height = height;
}

void SP2InitStdTalisman(	int		ItemIndex, 
						string 	id, 
						string 	ModelID, 
						string 	picTexture,
						int		picIndex, 
						int		Price, 
						float 	Weight,
						string	kind 	)
{
	ref	talisman;
	int	talismanIndex;
	
	talismanIndex = ItemIndex;
	makeref(talisman, Items[talismanIndex]);
	
	talisman.id				= id;		
	talisman.groupID		= TALISMAN_ITEM_TYPE;
	talisman.name			= "itmname_" + id;
	talisman.describe		= "itmdescr_" + id;		
	talisman.model			= ModelID;
	talisman.picTexture		= picTexture;
	talisman.picIndex		= picIndex;
	talisman.price			= Price + 10000;	
	talisman.rare 			= 0.0001;
	talisman.minlevel 		= 1;
	talisman.Weight 		= Weight;
	talisman.unique			= true;	
	talisman.ItemType 		= "ARTEFACT";
	if(kind != "") talisman.kind = kind;
	talisman.TradeType 		= ITEM_TRADE_JEWELRY;
}

void SP2SetSingleItemToTiers(int min, int max, string sType, string sItem)
{
    int i;
    string sTemp;
    for(i = min; i <= max; i++)
    {
        sTemp = "T" + i;
        Render.(sTemp).(sType).(sItem) = "On";
        if(sType != "Equip")
        {
            Render.(sTemp).(sType).(sItem).min = 1;
            Render.(sTemp).(sType).(sItem).dif = 0;
        }
    }
    Render.SingleTreasure.(sItem) = "";
}
