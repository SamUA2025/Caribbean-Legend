// диалог освобожденных каторжников рудника
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			dialog.text = NPCStringReactionRepeat("¿Usted otra vez, señor?","Escuche, señor, será mejor que se aleje...","¡No me molestes, señor! Te lo pido amablemente.","Oh, no puedo soportar eso... Incluso remar en una galera era mejor.","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Sí, soy yo de nuevo.","No me digas qué hacer.","¿Y qué si sigo molestando?","¡Vuelve a la galera entonces!",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			
			if (npchar.quest.meeting == "0")
			{
				dialog.text = "¿Qué quiere, señor?";
				link.l1 = "¿De ti? Nada, supongo. Solo quería decir hola.";
				link.l1.go = "exit";
				npchar.quest.meeting = "1";
			}
			NextDiag.TempNode = "First time";
		break;

		//замечание по обнажённому оружию от персонажей типа citizen
		case "CitizenNotBlade":
			dialog.text = NPCharSexPhrase(NPChar,"¡No desafíes tu destino, camarada! ¡Guarda tu arma!","Escucha, soy un ciudadano de esta ciudad y te pido que envaines tu espada.");
			link.l1 = LinkRandPhrase("Bien...","Como desees...","Como usted diga...");
			link.l1.go = "exit";
		break;

		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}
