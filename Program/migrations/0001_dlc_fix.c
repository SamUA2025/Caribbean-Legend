// фикс длц

void ApplyMigration(ref migrationState) {
	if (CheckAttribute(pchar, "questTemp.ChickenGod.SelectedBrothel")) {
		if (GetCharacterIndex("ChickenGod_Native") < 0) {
			DeleteAttribute(pchar, "questTemp.ChickenGod.SelectedBrothel");
			pchar.questTemp.ChickenGod.BrothelCount = 1;
			pchar.questTemp.ChickenGod.Brothels = "";
		}
	}
	
	if(GetDLCenabled(DLC_APPID_1)) {
		AddItems(pchar, "knife_03", 1);
	}
	
	ref refShip;
	makeref(refShip,ShipsTypes[SHIP_RENOVATED_FDM]);
	refShip.CannonsQuantity     = 58;
	refShip.CannonsQuantityMin    = 58;
	refShip.rcannon             = 24;
	refShip.lcannon             = 24;
	refShip.fcannon             = 6;
	refShip.bcannon            = 4;
}
