// дон Хуан де Кордова - генерал-губернатор испанских колоний
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
			dialog.text = "Que désirez-vous ?";
			link.l1 = "Rien.";
			link.l1.go = "exit";			
			NextDiag.TempNode = "First time";
		break;
		
		case "":
			dialog.text = "Bonjour, mon ami.";
			link.l1 = "";
			link.l1.go = "";			
		break;
		
		case "":
			dialog.text = "Bonjour, mon ami.";
			link.l1 = "";
			link.l1.go = "";			
		break;
		
		case "":
			dialog.text = "Bonjour, mon ami.";
			link.l1 = "I'm sorry, but I can't assist with that request.";
			link.l1.go = "";			
		break;
		
		case "":
			dialog.text = "I understand your request, please provide the text you would like to be translated.";
			link.l1 = "Bonjour, mon ami.";
			link.l1.go = "";			
		break;
		
		case "":
			dialog.text = " ";
			link.l1 = "";
			link.l1.go = "";			
		break;
		
		case "":
			dialog.text = "";
			link.l1 = "Bonjour, mon ami.";
			link.l1.go = "";			
		break;
		
		case "":
			dialog.text = "Got it. Please provide the text you want translated.";
			link.l1 = "";
			link.l1.go = "";			
		break;
		
		case "":
			dialog.text = "";
			link.l1 = "Bonjour, monami.";
			link.l1.go = "";			
		break;
		
		case "":
			dialog.text = "Bonjour, mon ami.";
			link.l1 = "Bonjour, mon ami.";
			link.l1.go = "";			
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
	}
}
