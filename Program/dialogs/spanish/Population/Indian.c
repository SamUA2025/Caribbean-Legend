//Jason общий диалог индейцев на улицах
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
			dialog.text = NPCStringReactionRepeat(""+GetSexPhrase("Rostro pálido","Squaw blanca")+"¿quiere hablar?","Tú otra vez, "+GetSexPhrase("cara pálida","mujer blanca")+".",""+GetSexPhrase("Carablanca le gusta hablar. Como una mujer.","La mujer blanca ama hablar.")+"","El Gran Espíritu trajo al rostro pálido "+GetSexPhrase("hermano","hermana")+" a mí.","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Sí.","Sí, yo de nuevo.","Muy poético.","Me alegra verte también.",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			
			if (npchar.quest.meeting == "0")
			{
				dialog.text = "¿Cómo, hermano blanco? ¿Quieres hablar con el indio?";
				link.l1 = "Saludos, hijo de la jungla. Me alegra verte, pero tengo que irme.";
				link.l1.go = "exit";
				npchar.quest.meeting = "1";
			}
			NextDiag.TempNode = "First time";
		break;

		//замечание по обнажённому оружию от персонажей типа citizen
		case "CitizenNotBlade":
			dialog.text = NPCharSexPhrase(NPChar,"¡No tientes a los espíritus, cara pálida! ¡Guarda el cuchillo largo!","¡No te apresures a la muerte, cara pálida! ¡Guarda el cuchillo largo!");
			link.l1 = LinkRandPhrase("Bien.","Como desees.","Como usted diga.");
			link.l1.go = "exit";
		break;

		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}
