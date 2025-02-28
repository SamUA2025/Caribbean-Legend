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
			dialog.text = NPCStringReactionRepeat("Sie schon wieder, Senor?","Hören Sie, Herr, Sie sollten besser gehen...","Belästigen Sie mich nicht, Sir! Ich bitte Sie freundlich.","Oh, das kann ich nicht ertragen... Selbst das Rudern einer Galeere war besser.","Block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Ja, ich bin es wieder.","Sag mir nicht, was ich tun soll.","Und was ist, wenn ich weiter nerve?","Zurück zur Galeere dann!",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			
			if (npchar.quest.meeting == "0")
			{
				dialog.text = "Was wollen Sie, Senor?";
				link.l1 = "Von dir? Nichts, nehme ich an. Wollte nur hallo sagen.";
				link.l1.go = "exit";
				npchar.quest.meeting = "1";
			}
			NextDiag.TempNode = "First time";
		break;

		//замечание по обнажённому оружию от персонажей типа citizen
		case "CitizenNotBlade":
			dialog.text = NPCharSexPhrase(NPChar,"Lass das Schicksal nicht herausfordern, Kumpel! Leg deine Waffe weg!","Hör zu, ich bin Bürger dieser Stadt und ich bitte dich, dein Schwert zu scheiden.");
			link.l1 = LinkRandPhrase("Gut...","Wie du wünschst...","Wie du sagst...");
			link.l1.go = "exit";
		break;

		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}
