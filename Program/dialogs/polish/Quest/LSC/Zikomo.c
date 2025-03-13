// телохранитель лидера ривадос Эдди - Зикомо
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			dialog.text = "Czego chcesz, biały człowieku? Zikomo nie rozmawia z tobą. Porozmawiaj z Czarnym Eddiem. On jest szefem.";
			link.l1 = "Nie mów!";
			link.l1.go = "exit";			
			NextDiag.TempNode = "First time";
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
	}
}
