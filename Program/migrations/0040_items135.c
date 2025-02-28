void ApplyMigration(ref migrationState) {
	
	// Галеон Святое Милосердие
	ref refShip;
	makeref(refShip,ShipsTypes[SHIP_GALEON_SM]);
	refShip.Name            			= "Galeon_sm";
	refship.Soundtype					= "frigate";
	refShip.Class						= 3;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS32;
	refShip.MaxCaliber      			= 32;
	refShip.Weight						= Tonnes2CWT(820);
	refShip.Capacity        			= 4900;
	refShip.CannonsQuantity				= 30;	// 2,2,13,13
	refShip.CannonsQuantityMin			= 30;
	refShip.rcannon 					= 13;
	refShip.lcannon 					= 13;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 2;	
	refShip.MaxCrew         			= 394;
	refShip.OptCrew         			= 315;
	refShip.MinCrew         			= 27;
	refShip.SpeedRate					= 13.25;
	refShip.TurnRate        			= 42.5;
	refShip.Price           			= 57500;
	refShip.HP              			= 4750;
	refShip.SP              			= 100;
	refship.Type.Merchant				= false;
	refship.Type.War					= true;	
	refship.QuestShip					= true; 
	refShip.lowpolycrew 				= 16;
	
	refship.Rocking.y 					= 0.45;
	refship.Rocking.az 					= 0.035;
	
	refship.WaterLine					= 1.0;
	refship.SpeedDependWeight			= 0.15;
	refship.SubSeaDependWeight			= 0.95;
	refship.TurnDependWeight			= 0.2;
	refship.WindAgainstSpeed   			= 0.60;
	
	refship.CabinType          			= "Cabin_Medium2"; 
	refship.DeckType           			= "Medium";
		
	refship.InertiaAccelerationX	= 4.0;	refship.InertiaBrakingX		= 4.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 4.0;
	
	refShip.Height.Bombs.Y				= 4.3;		refShip.Height.Bombs.DY		= 2.1;
	refShip.Height.Grapes.Y				= 5.6;		refShip.Height.Grapes.DY	= 2.8;
	refShip.Height.Knippels.Y			= 18.7;		refShip.Height.Knippels.DY	= 12.7;
	refShip.Height.Balls.Y				= 4.3;		refShip.Height.Balls.DY		= 2.1;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;
	refShip.GeraldSails.rey_b3.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 16.5;
	refship.Track1.Width	= "5.2, 7.3";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 10.5;
	refship.Track2.Width	= "6.0, 8.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	refShip.cannonr  = refShip.rcannon;
	refShip.cannonl  = refShip.lcannon;
	refShip.cannonf  = refShip.fcannon;
	refShip.cannonb  = refShip.bcannon;
	
	//галеон стандартный
	makeref(refShip,ShipsTypes[SHIP_GALEON_L]);
	refShip.CannonsQuantity				= 26; // 2,2,11,11	2,2,10,10
	refShip.CannonsQuantityMin			= 24;
	refShip.rcannon 					= 11;
	refShip.lcannon 					= 11;
	refShip.cannonr  = refShip.rcannon;
	refShip.cannonl  = refShip.lcannon;
	refShip.cannonf  = refShip.fcannon;
	refShip.cannonb  = refShip.bcannon;
	// если корабль уже у игрока
	for (i = 0; i < REAL_SHIPS_QUANTITY; i++)
	{
		if(!CheckAttribute(&RealShips[i],"BaseType")) continue;
		if(RealShips[i].BaseType == SHIP_GALEON_L)
		{
			RealShips[i].cannonr  = RealShips[i].rcannon;
			RealShips[i].cannonl  = RealShips[i].lcannon;
			RealShips[i].cannonf  = RealShips[i].fcannon;
			RealShips[i].cannonb  = RealShips[i].bcannon;
		}
	}
	
	ExpandItemsArray();
	ReinitBlade(TOTAL_ITEMS - 1, "lacrima_patris", "ITEMS_39",   9,  TGT_QUEST,   B_EXCELLENT, "FencingH", 9, 1.05, 1.10, 0, 0, 0,100000); // Меч священника ДЛЦ
	ExpandItemsArray();
	ReinitTalisman(TOTAL_ITEMS - 1, "talisman16", "", "ITEMS_24",  7, rand(5000), 0.5,             ""); // Золотой нож cle 1.5
	ExpandItemsArray();
	ReinitTalisman(TOTAL_ITEMS - 1, "talisman17", "", "ITEMS_39",  8, rand(5000), 0.5,             ""); // Оберег Liber Misericordiae cle 1.5 DLC
	
	ref rItem = ItemsFromID("gold_dublon");
	rItem.component.t2.id 	=  "Chest_open";
	rItem.component.t2.use =  "Additional";
	rItem.component.t2.qty =  0;
	
	rItem = ItemsFromID("potion4");
	rItem.component.t9.id 	=  "potion3";
	rItem.component.t9.use =  "Component";
	rItem.component.t9.qty =  3;
	rItem.component.t10.id 	=  "alchemy_tool";
	rItem.component.t10.use =  "AlchemyTool";
	rItem.component.t10.qty =  1;
	rItem.component.t11.id 	=  "mineral27";
	rItem.component.t11.use =  "AlchemyTool";
	rItem.component.t11.qty =  1;
	
	rItem = ItemsFromID("totem_07");
	rItem.component.t4.id 	=  "mineral35";
	rItem.component.t4.use =  "Component";
	rItem.component.t4.qty =  1;
	rItem.component.t5.id 	=  "Mechanic_Tool";
	rItem.component.t5.use =  "AlchemyTool";
	rItem.component.t5.qty =  1;
	rItem.component.t6.id 	=  "mineral5";
	rItem.component.t6.use =  "AlchemyTool";
	rItem.component.t6.qty =  1;
}

void ReinitBlade(int ItemIndex, 
					string 	ModelID, 
					string 	picTexture,
					int		picIndex,
					string  TargetGroup,
					int     Quality,
					string  BladeType,
					int     BladeNum,
					float   Lenght,
					float   Curve,
					bool    isGenerable,
					int     GenerationQty, 
					bool 	isGenerablePrice,
					int     Price)
{
	
	ref	blade;
	int	bladeIndex;
	float MaxAttack = 0.0;
	
	bladeIndex = ItemIndex;
	makeref(blade, Items[bladeIndex]);
	
	blade.id				= ModelID;		
	blade.groupID 			= BLADE_ITEM_TYPE;
	blade.model				= ModelID;
	blade.name				= "itmname_" + ModelID;
	blade.describe			= "itmdescr_" + ModelID;		
	blade.folder 			= "ammo";
	blade.picTexture		= picTexture;
	blade.picIndex			= picIndex;
	blade.param.time 		= 0.1;
	blade.param.colorstart 	= argb(64, 64, 64, 64);
	blade.param.colorend 	= argb(0, 32, 32, 32);
	blade.ItemType 			= "WEAPON";
	blade.lenght 			= Lenght;
	blade.curve				= Curve;
 	blade.FencingType       = BladeType;
	blade.quality			= Quality;
	blade.target			= TargetGroup;
	blade.TradeType 		= ITEM_TRADE_AMMUNITION;
	
	if(isGenerable)				blade.Generation.qty 	= GenerationQty;
	if(isGenerablePrice)    	
	{
		blade.Generation.price 	= true; // Флаг "генерить цену"	
	}
	else blade.price 	= Price;	
	
	switch (BladeType) 
	{
		case "FencingL" :
			blade.Weight 	= 2.0 + fRandSmall(1.0); 
			MaxAttack		= FencingL_MaxAttack;
		break;
		case "FencingS" :
			blade.Weight 	= 2.4 + fRandSmall(1.2);
			MaxAttack		= FencingS_MaxAttack;			
		break;
		case "FencingH" :
			blade.Weight 	= 3.0 + fRandSmall(1.5); 
			MaxAttack		= FencingH_MaxAttack;
		break;
	}
	if(ModelID == "blade_40") blade.Weight = 5.0;
	if(ModelID == "blade_41") blade.Weight = 2.0;
	if(ModelID == "blade_42") blade.Weight = 3.0;
	
	blade.Balance = fRandSmall(2.0);
	switch (Quality)
	{
		case B_POOR :
			blade.Attack 	= MaxAttack * (42.5 + fRandSmall(15.0))/100.0;			
			blade.rare 	 	= 0.1;
			blade.minlevel 	= 1;
		break;
		case B_ORDINARY :
			blade.Attack 	= MaxAttack * (55.0 + fRandSmall(15.0))/100.0;
			blade.rare 	 	= 0.01;
			blade.minlevel 	= 1;
		break;
		case B_GOOD :
			blade.Attack 	= MaxAttack * (70.0 + fRandSmall(15.0))/100.0;
			blade.rare 	 	= 0.001;
			blade.minlevel 	= 10;
			if(TargetGroup == TGT_QUEST) // для квестового оружия атаку считаем по максимуму
			{
				blade.Attack 	= MaxAttack * 0.85;	
			}
			if(BladeType == "FencingL") blade.Balance = 0.0 + fRandSmall(1.0);
			if(BladeType == "FencingS") blade.Balance = 2.0 - fRandSmall(1.0);
			if(BladeType == "FencingH") blade.Balance = 2.0 - fRandSmall(1.0);
		break;
		case B_EXCELLENT :
			blade.Attack 	= MaxAttack * (85.0 + fRandSmall(15.0))/100.0;
			blade.rare 	 	= 0.0001;
			blade.minlevel 	= 15;
			if(TargetGroup == TGT_QUEST) // для квестового оружия атаку считаем по максимуму
			{
				blade.Attack 	= MaxAttack;	
			}
			if(BladeType == "FencingL") blade.Balance = 0.0 + fRandSmall(0.5);
			if(BladeType == "FencingS") blade.Balance = 2.0 - fRandSmall(0.5);
			if(BladeType == "FencingH") blade.Balance = 2.0 - fRandSmall(0.5);
		break;
	}
	
	if(ModelID == "blade_40") blade.Balance = 0.0;
	if(ModelID == "blade_41") blade.Balance = 1.0;
	
	if(ModelID == "blade_41") blade.Attack = 90.0;
	if(ModelID == "blade_42") blade.Attack = 70.0;
	
	switch (BladeType) 
	{
		case "FencingL" :
			if(isGenerablePrice) 
			{
				blade.price  = makeint(35.0 * (1.0/Curve + Lenght) * (stf(blade.Attack) * 2.0 - 30.0));
			}	
			else blade.price = Price;			
		break;
		case "FencingS" :
			if(isGenerablePrice) 
			{
				blade.price  = makeint(25.0 * (Curve + Lenght) * (stf(blade.Attack) * 2.0 - 40.0));
			}	
			else blade.price = Price;			
		break;
		case "FencingH" :
			if(isGenerablePrice) 
			{
				blade.price  = makeint(20.0 * ((Curve + 1.0) * 1.0/Lenght) * (stf(blade.Attack) * 2.0 - 50.0));
			}	
			else blade.price = Price;			
		break;
	}
}

void ReinitTalisman(	int		ItemIndex, 
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

void ReInitStdGun(	int		ItemIndex, 
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
	ref	gun;
	int	gunIndex;
	
	gunIndex = ItemIndex;
	makeref(gun, Items[gunIndex]);
	
	gun.id				= id;		
	gun.groupID			= GUN_ITEM_TYPE;
	gun.name			= "itmname_" + id;
	gun.describe		= "itmdescr_" + id;		
	gun.model			= ModelID;
	gun.folder 			= "ammo";
	gun.chargeQ			= Charges;
	gun.picTexture		= picTexture;
	gun.picIndex		= picIndex;
	gun.dmg_min			= DmgMin;
	gun.dmg_max			= DmgMax;
	gun.price			= Price;	
	gun.ItemType 		= "WEAPON";
	gun.rare 			= Rare;
	gun.quality 		= Quality;
	gun.minlevel 		= MinLevel;
	gun.Weight 			= Weight;
	gun.ChargeSpeed 	= 10.0; // by default
	gun.accuracy 		= 50.0; // by default
	gun.TradeType 		= ITEM_TRADE_AMMUNITION;
}