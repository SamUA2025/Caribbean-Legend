void ApplyMigration(ref migrationState) {
	
	object opt;
	ReadSavedOptionsEx(&opt, "options");
	InterfaceStates.CAMERASWING = 0;
	opt.cameramode.CAMERASWINGMode = sti(InterfaceStates.CAMERASWING);
	SaveSavedOptionsEx(&opt, "options");
}
