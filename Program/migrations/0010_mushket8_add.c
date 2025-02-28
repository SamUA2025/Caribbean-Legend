void ApplyMigration(ref migrationState) {
	// рецепт разборного ружья
	pchar.quest.mushket8.win_condition.l1 = "item";
	pchar.quest.mushket8.win_condition.l1.item = "mushket8";
	pchar.quest.mushket8.function = "mushket8_craft";
	
	ref loc = &locations[FindLocation("CarolineBank")];
	loc.private1.items.mushket8 = 1;
}
