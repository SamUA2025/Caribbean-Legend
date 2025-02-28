// 3ий патч

void ApplyMigration(ref migrationState)
{
	ref loc = &locations[FindLocation("CommonResidence_3")];
	loc.models.always.back = "..\inside_back3";
	// продлить таймер
	SetFunctionTimerCondition("TorrentEddy", 8, 0, 0, false);
    
    ref rEnc;
    makeref(rEnc, EncountersTypes[ENCOUNTER_TYPE_PIRATE_SCOUNDREL]);
	rEnc.Type = ENCOUNTER_WAR;
	rEnc.MinRank = 30;
	rEnc.MaxRank = 1000;
	rEnc.worldMapShip = "manowar";
	Enc_AddShips(rEnc, "War", 1, 3);
	Enc_ExcludeNation(rEnc, ENGLAND);
	Enc_ExcludeNation(rEnc, FRANCE);
	Enc_ExcludeNation(rEnc, SPAIN);
	Enc_ExcludeNation(rEnc, HOLLAND);

	Enc_AddClasses(rEnc, 3, 0, 0, 2, 3);
	Enc_AddClasses(rEnc, 1000,0, 0, 2, 3);
	
	if(CheckAttribute(pchar, "questTemp.Sharlie.Ship")) Sharlie_removeLocks("");
}
