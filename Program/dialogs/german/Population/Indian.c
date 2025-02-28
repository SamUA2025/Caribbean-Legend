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
			dialog.text = NPCStringReactionRepeat(""+GetSexPhrase("Bleichgesicht","Weiße Squaw")+" will reden?","Du schon wieder, "+GetSexPhrase("bleichgesicht","weiße Squaw")+".",""+GetSexPhrase("Bleichgesicht liebt Reden. Wie Squaw.","Die weiße Squaw liebt es zu reden.")+"","Großer Geist brachte bleiches Gesicht"+GetSexPhrase("Bruder","Schwester")+" zu mir.","Block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Ja.","Ja, ich schon wieder.","Sehr poetisch.","Ich freue mich auch, dich zu sehen.",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			
			if (npchar.quest.meeting == "0")
			{
				dialog.text = "Wie, weißer Bruder. Du willst mit Indianer sprechen?";
				link.l1 = "Grüße, Sohn des Dschungels. Ich freue mich, dich zu sehen, aber ich muss gehen.";
				link.l1.go = "exit";
				npchar.quest.meeting = "1";
			}
			NextDiag.TempNode = "First time";
		break;

		//замечание по обнажённому оружию от персонажей типа citizen
		case "CitizenNotBlade":
			dialog.text = NPCharSexPhrase(NPChar,"Versuche nicht die Geister zu versuchen, bleichgesicht! Leg das lange Messer weg!","Lass den Tod nicht überstürzen, Bleichgesicht! Leg das lange Messer weg!");
			link.l1 = LinkRandPhrase("Gut.","Wie du wünschst.","Wie du sagst.");
			link.l1.go = "exit";
		break;

		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}
