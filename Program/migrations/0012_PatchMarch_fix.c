void ApplyMigration(ref migrationState) {
	
	//if (!CheckAttribute(pchar, "questTemp.regata"))
	//{
		if (CheckAttribute(pchar, "quest.Regata_TH"))
			pchar.quest.Regata_TH.over = "yes"; 
	//}
	
	ref itm = ItemsFromID("cirass6");
	itm.model = "10";
	itm = ItemsFromID("cirass7");
	itm.model = "11";
	itm = ItemsFromID("cirass8");
	itm.model = "12";
	pchar.HeroModel = "Sharle_1,Sharle_2,Sharle_3,Sharle_4,Sharle_5,protocusto,Sharle_6,Sharle_8,Sharle_7,Sharle_9,Sharle_1,Sharle_11,Sharle_12";
	
	ref loc = &locations[FindLocation("CommonResidence_4")];
    loc.models.always.back = "..\inside_back3";
	
	if(CheckAttribute(&ChrPerksList,"list.SharedExperience.PlayerOnly"))
		DeleteAttribute(&ChrPerksList,"list.SharedExperience.PlayerOnly");
	
	itm = ItemsFromID("bullet_double");
	itm.component.t3.id 	=  "gold_dublon";
	itm.component.t3.use =  "Component";
	itm.component.t3.qty =  1;
	
	itm = ItemsFromID("grapeshot_double");
	itm.component.t3.id 	=  "gold_dublon";
	itm.component.t3.use =  "Component";
	itm.component.t3.qty =  1;
}
