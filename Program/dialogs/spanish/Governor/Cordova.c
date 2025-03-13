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
			dialog.text = "¿Qué desea?";
			link.l1 = "Nada.";
			link.l1.go = "exit";			
			NextDiag.TempNode = "First time";
		break;
		
		case "":
			dialog.text = "Entendido. Пожалуйста, предоставьте текст для перевода.";
			link.l1 = "";
			link.l1.go = "";			
		break;
		
		case "":
			dialog.text = "Hola, Capitán.";
			link.l1 = "Entendido. Пожалуйста, предоставьте английский текст для перевода.";
			link.l1.go = "";			
		break;
		
		case "":
			dialog.text = "";
			link.l1 = "Entendido. Вышлите текст для перевода.";
			link.l1.go = "";			
		break;
		
		case "":
			dialog.text = "Hola, Amigo.";
			link.l1 = "";
			link.l1.go = "";			
		break;
		
		case "":
			dialog.text = "Понял. Пожалуйста, предоставьте текст для перевода.";
			link.l1 = " ";
			link.l1.go = "";			
		break;
		
		case "":
			dialog.text = " ";
			link.l1 = "Entendido. Пожалуйста, предоставьте текст для перевода.";
			link.l1.go = "";			
		break;
		
		case "":
			dialog.text = "";
			link.l1 = "";
			link.l1.go = "";			
		break;
		
		case "":
			dialog.text = "Entendido, я переведу текст, если он будет предоставлен.";
			link.l1 = "";
			link.l1.go = "";			
		break;
		
		case "":
			dialog.text = "Hola, Amigo.";
			link.l1 = "Entendido. Por favor, предоставьте текст для перевода.";
			link.l1.go = "";			
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
	}
}
