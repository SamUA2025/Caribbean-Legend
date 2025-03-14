void ApplyMigration(ref migrationState) {
	
	ReInitGrapeGunExt(	"pistol2",	"t1",		3,		30,		4.25,	5.0,	3);		// трёхствольный дробовик, картечь
	ReInitGrapeGunExt(	"pistol3",	"t1",		4,		25,		6.0,	5.0,	4);		// тромбон, картечь
	ReInitGrapeGunExt(	"pistol8",	"t1",		4,		70,		5.0,	3.0,	2);		// бландербуз, картечь
	ReInitGrapeGunExt(	"pistol8",	"t3",		4,		70,		4.25,	2.5,	1);		// бландербуз, ежовый заряд
	ReInitGrapeGunExt(	"howdah",	"t1",		3,		55,		3.0,	5.5,	2);		// гауда, картечь
	ReInitGrapeGunExt(	"howdah",	"t2",		3,		55,		2.5,	4.75,	1);		// гауда, ежовый заряд
	ReInitGrapeGunExt(	"mushket3",	"t1",		3,		45,		6.0,	3.0,	3);		// аркебуза, картечь
	ReInitGrapeGunExt(	"mushket6",	"t1",		3,		60,		4.0,	3.5,	2);		// башенный мушкетон, картечь
	ReInitGrapeGunExt(	"mushket6",	"t2",		3,		60,		3.5,	2.75,	1);		// башенный мушкетон, ежовый заряд
	if(CheckAttribute(pchar,"alchemy.grapeshot_double.isKnown"))
	{
		ReInitGrapeGunExt(	"pistol2",	"t2",		3,		50,		4.25,	5.0,	3);		// трёхствольный дробовик, двойной заряд
		ReInitGrapeGunExt(	"pistol3",	"t2",		4,		40,		6.0,	5.0,	4);		// тромбон, двойной заряд
		ReInitGrapeGunExt(	"pistol8",	"t4",		4,		110,	5.0,	3.0,	2);		// бландербуз, двойной заряд
		ReInitGrapeGunExt(	"howdah",	"t3",		3,		85,		3.0,	5.5,	2);		// гауда, двойной заряд
	}
}

void ReInitGrapeGunExt(string id, string sAttr, int basedmg, int shards, float width, float height, int dispersion)
{
	ref gun = ItemsFromID(id);
	gun.type.(sAttr).basedmg = basedmg;
	gun.type.(sAttr).shards = shards;
	string sArea = "grapes_area_"+dispersion;
	gun.type.(sAttr).area = XI_ConvertString(sArea);
	gun.type.(sAttr).width = width;
	gun.type.(sAttr).height = height;
}