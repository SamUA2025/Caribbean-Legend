void ApplyMigration(ref migrationState) {
	
	ref rItem = ItemsFromID("potion2");
	rItem.component.t3.qty =  3;
	
	rItem = ItemsFromID("potion4");
	rItem.component.t1.qty =  3;
}
