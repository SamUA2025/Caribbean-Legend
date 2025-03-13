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
			dialog.text = "¿Qué quieres?";
			link.l1 = "Nada.";
			link.l1.go = "exit";			
			NextDiag.TempNode = "First time";
		break;
		
		case "":
			dialog.text = "Entendido, estoy listo para comenzar.";
			link.l1 = "Hola, Amigo.";
			link.l1.go = "";			
		break;
		
		case "":
			dialog.text = "";
			link.l1 = "";
			link.l1.go = "";			
		break;
		
		case "":
			dialog.text = "Hola, amigo.";
			link.l1 = "Entendido. Пожалуйста, предоставьте текст, который нужно перевести.";
			link.l1.go = "";			
		break;
		
		case "":
			dialog.text = "Entendido. Пожалуйста, представьте текст для перевода.";
			link.l1 = "Entendido. Proporcione строки для перевода.";
			link.l1.go = "";			
		break;
		
		case "":
			dialog.text = "Entendido. Puedes предоставить текст для перевода?";
			link.l1 = "Hola, amigo.";
			link.l1.go = "";			
		break;
		
		case "":
			dialog.text = "Entendido. Пожалуйста, предоставь тексты для перевода.";
			link.l1 = "Entendido. Proporciona текст для перевода.";
			link.l1.go = "";			
		break;
		
		case "":
			dialog.text = "Entendido. Estoy listo para comenzar con la traducción.";
			link.l1 = "Entendido, por favor, предоставьте текст для перевода.";
			link.l1.go = "";			
		break;
		
		case "":
			dialog.text = "Entendido, предоставьте текст для перевода.";
			link.l1 = "Hola, Amigo.";
			link.l1.go = "";			
		break;
		
		case "":
			dialog.text = "Entendido, жду текст для перевода.";
			link.l1 = " ";
			link.l1.go = "";			
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
	}
}
