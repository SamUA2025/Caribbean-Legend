
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog, "Links");

	makeref(NPChar, CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	switch (Dialog.CurrentNode)
	{
	// -----------------------------------Диалог первый - первая встреча
	case "First time":

		dialog.text = "Error opening dialog file.";
		if (CheckAttribute(CharacterRef, "Dialog.Filename"))
		{
			dialog.text = "No se puede abrir el archivo de diálogo " + CharacterRef.Dialog.Filename + " asignado a este personaje.";
		}
		link.l1 = "ok";
		link.l1.go = "Exit";
		NextDiag.TempNode = "First time";
		break;

	case "Exit":
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
		break;
	}
}
