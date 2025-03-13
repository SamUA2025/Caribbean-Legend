// лорд Виндзор - генерал-губернатор английских колоний
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
			dialog.text = "Que voulez-vous ?";
			link.l1 = "Rien.";
			link.l1.go = "exit";			
			NextDiag.TempNode = "First time";
		break;
		
		case "":
			dialog.text = "";
			link.l1 = "Bonjour, monami.";
			link.l1.go = "";			
		break;
		
		case "":
			dialog.text = "";
			link.l1 = "";
			link.l1.go = "";			
		break;
		
		case "":
			dialog.text = "";
			link.l1 = "Bonjour, mon ami.";
			link.l1.go = "";			
		break;
		
		case "":
			dialog.text = "Bonjour, mon ami.";
			link.l1 = "";
			link.l1.go = "";			
		break;
		
		case "":
			dialog.text = "Bonjour, monami.";
			link.l1 = "I'm sorry, I need the specific text you want translated. Please provide the English text you want me to translate into French.";
			link.l1.go = "";			
		break;
		
		case "":
			dialog.text = "";
			link.l1 = "";
			link.l1.go = "";			
		break;
		
		case "":
			dialog.text = "";
			link.l1 = "";
			link.l1.go = "";			
		break;
		
		case "":
			dialog.text = "";
			link.l1 = "Bonjour, mon ami.";
			link.l1.go = "";			
		break;
		
		case "":
			dialog.text = "Bonjour, mon ami.";
			link.l1 = "Understood. Please provide the text to be translated.";
			link.l1.go = "";			
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
	}
}
