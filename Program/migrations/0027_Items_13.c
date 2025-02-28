void ApplyMigration(ref migrationState) {
	
	pchar.HeroModel = "Sharle_1,Sharle_2,Sharle_3,Sharle_4,Sharle_5,protocusto,Sharle_6,Sharle_8,Sharle_7,Sharle_9,Sharle_1,Sharle_11,Sharle_12,Sharle_13,Sharle_14";
	if (GetCharacterIndex("Tichingitu") != -1)
	{
		ref rCharacter = characterFromId("Tichingitu");
		rCharacter.HeroModel = "Maskog,Maskog,Maskog,Maskog,Maskog,Maskog,Maskog,Maskog,Maskog,Maskog,Maskog,Maskog,Maskog,Maskog,Maskog_14";
	}
	
	ExpandItemsArray();
	
	ref	suit;
	int	suitIndex;

	suitIndex = TOTAL_ITEMS - 1;
	makeref(suit, Items[suitIndex]);
	
	suit.id					= "cirass10";		
	suit.groupID			= CIRASS_ITEM_TYPE;
	suit.name				= "itmname_" + "cirass10";
	suit.describe			= "itmdescr_" + "cirass10";		
	suit.folder 			= "items";
	suit.model				= "14";
	suit.picTexture			= "ITEMS_39";
	suit.picIndex			= 5;
	suit.price				= 38500;	
	suit.rare 				= 0.01;
	suit.minlevel 			= 20;
	suit.Weight 			= 15;
	suit.Clothes 			= false;
	suit.B_CirassLevel 		= 0.15;
	suit.G_CirassLevel 		= 0.15;
	suit.critical			= 0.5;
	suit.ItemType 			= "SUPPORT";
	suit.TradeType 			= ITEM_TRADE_AMMUNITION;
	
	ExpandItemsArray();
	ReinitBlade(TOTAL_ITEMS - 1, "blade_40", "ITEMS_39",   1,  TGT_QUEST,    B_ORDINARY, "FencingL", 9, 1.10, 1.10, 0, 0, 0, 17500); // Итальянская рапира cle
	ExpandItemsArray();
	ReinitBlade(TOTAL_ITEMS - 1, "blade_41", "ITEMS_39",   2,  TGT_QUEST,   B_EXCELLENT, "FencingS", 9, 1.10, 0.95, 1, 10, 1, 108000); // Цзянь cle
	ExpandItemsArray();
	ReinitBlade(TOTAL_ITEMS - 1, "blade_42", "ITEMS_39",   3,  TGT_QUEST,    B_ORDINARY, "FencingH", 9, 1.00, 1.00, 0, 0, 0, 	    1500); // Армейский палаш cle
	
	ExpandItemsArray();
	ReinitTalisman(TOTAL_ITEMS - 1, "talisman14", "", "ITEMS_39", 6, rand(5000), 0.5,    "navigator"); // Оберег 'Жаньи' cle 1.3
	ExpandItemsArray();
	ReinitTalisman(TOTAL_ITEMS - 1, "talisman15", "", "ITEMS_39", 7, rand(5000), 0.5,             ""); // Оберег 'Чёрная метка' cle 1.3 DLC
	
	int gunIndx = FindItem("pistol14");
	ReInitStdGun(gunIndx, "pistol14",			"pistol14",  "ITEMS_39",  4, 0.0001,  1,	  77000,	45.0,	165.0,	3.5,	2,	   B_UNIQUE);
	ReInitGunExt(	"pistol14", "t1", 		    "bullet",      "gunpowder",  65.0, 165.0,  45.0, 145.0,  0.0,  0.0, 1, 0, 0, 4, 0, 0, 70, 69, 1); // Дуэльный двухзарядный пистоль cle 1.3
	ReInitGunExt(	 "pistol14", "t2", 		   "cartridge",      "",         65.0, 165.0,  45.0, 145.0,  0.0,  0.0, 1, 0, 0, 4, 0, 0, 70, 35, 0); // Дуэльный двухзарядный пистоль cle 1.3
	if(CheckAttribute(pchar,"alchemy.bullet_double.isKnown"))
	{
		ReInitGunExt(	 "pistol14", "t3",   "bullet_double",               "", 130.0, 330.0,  90.0, 290.0,  0.0,  0.0, 1, 0, 0, 4, 0, 0, 70, 34, 0)); // Дуэльный двухзарядный пистоль cle 1.3
	}
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

void ReInitGunExt(string id,			
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
	
	if(Stun_NC || Stun_C) gun.stun = true;
}