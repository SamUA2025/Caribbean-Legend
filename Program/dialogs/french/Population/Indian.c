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
			dialog.text = NPCStringReactionRepeat(""+GetSexPhrase("Visage pâle","Blanche squaw")+" veut parler ?","Toi encore, "+GetSexPhrase("visage pâle","femme blanche")+".","Bonjour, monami."+GetSexPhrase("Visage pâle aime parler. Comme une squaw.","Squaw blanche aime parler.")+"Bonjour, mon ami.","Le Grand Esprit a amené le visage pâle"+GetSexPhrase("frère","sœur")+"à moi.","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Oui.","Oui, c'est encore moi.","Très poétique.","Je suis heureux de te voir aussi.",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			
			if (npchar.quest.meeting == "0")
			{
				dialog.text = "Comment, frère blanc. Tu veux parler avec l'Indien ?";
				link.l1 = "Salutations, fils de la jungle. Je suis heureux de te voir mais je dois partir.";
				link.l1.go = "exit";
				npchar.quest.meeting = "1";
			}
			NextDiag.TempNode = "First time";
		break;

		//замечание по обнажённому оружию от персонажей типа citizen
		case "CitizenNotBlade":
			dialog.text = NPCharSexPhrase(NPChar,"Ne tente pas les esprits, visage pâle ! Range le long couteau !","Ne te précipite pas vers la mort, visage pâle ! Range le long couteau !");
			link.l1 = LinkRandPhrase("D'accord.","Comme vous le souhaitez.","Comme vous dites.");
			link.l1.go = "exit";
		break;

		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}
