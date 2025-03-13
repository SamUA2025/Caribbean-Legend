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
			dialog.text = NPCStringReactionRepeat("Vous encore, señor?","Ecoutez, monsieur, vous feriez mieux de vous éloigner...","Ne me dérangez pas, monsieur ! Je vous prie gentiment.","Oh, je ne peux pas supporter cela... Même ramer sur une galère était mieux.","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Oui, c'est encore moi.","Ne me dis pas quoi faire.","Et que se passe-t-il si je continue à ennuyer?","Retourne à la cambuse alors !",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			
			if (npchar.quest.meeting == "0")
			{
				dialog.text = "Que voulez-vous, señor ?";
				link.l1 = "De toi ? Rien, je suppose. Je voulais juste dire bonjour.";
				link.l1.go = "exit";
				npchar.quest.meeting = "1";
			}
			NextDiag.TempNode = "First time";
		break;

		//замечание по обнажённому оружию от персонажей типа citizen
		case "CitizenNotBlade":
			dialog.text = NPCharSexPhrase(NPChar,"Ne défie pas ton destin, camarade ! Range ton arme !","Ecoutez, je suis un citoyen de cette ville et je vous demande de rengainer votre lame.");
			link.l1 = LinkRandPhrase("Très bien...","Comme vous le souhaitez...","Comme vous le dites...");
			link.l1.go = "exit";
		break;

		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}
