void ApplyMigration(ref migrationState) {
	
	if (CheckAttribute(pchar, "questTemp.Mtraxx") && pchar.questTemp.Mtraxx == "fail")
	{
		if(CheckAttribute(pchar, "questTemp.Mtraxx.CharleePrince"))
		{
			DeleteAttribute(pchar, "questTemp.Mtraxx.CharleePrince");
		}
		DelCharleePrince("");
	}
	if (CheckAttribute(pchar, "questTemp.Mtraxx") && pchar.questTemp.Mtraxx == "full_complete") // пиратская линейка пройдена полностью
	{
		if(CheckAttribute(pchar, "questTemp.Mtraxx.CharleePrince"))
		{
			DeleteAttribute(pchar, "questTemp.Mtraxx.CharleePrince");
		}
		DelCharleePrince("");
	}
	if (CheckAttribute(pchar, "questTemp.Mtraxx") && pchar.questTemp.Mtraxx == "full_complete_end")
	{
		if(CheckAttribute(pchar, "questTemp.Mtraxx.CharleePrince"))
		{
			DeleteAttribute(pchar, "questTemp.Mtraxx.CharleePrince");
		}
		DelCharleePrince("");
	}
}