
void InitInterface(string iniName)
{
	EngineLayersOffOn(true);
	SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);
}

void ProcessBreakExit()
{
	IDoExit(RC_INTERFACE_QUICK_SAVE);
	SetTimeScale(1.0);
	TimeScaleCounter = 0;
}

void ProcessCancelExit()
{
	IDoExit(RC_INTERFACE_QUICK_SAVE);
	SetTimeScale(1.0);
	TimeScaleCounter = 0;
}

void IDoExit(int exitCode)
{

}

void DoPostExit()
{
	int exitCode = GetEventData();
	IDoExit(exitCode);
}