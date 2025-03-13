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
			dialog.text = NPCStringReactionRepeat(""+GetSexPhrase("Biała twarz","Biała squaw")+"chce porozmawiać?","Znowu ty, "+GetSexPhrase("blada twarz","biała squaw")+"."," "+GetSexPhrase("Biała twarz lubi gadać. Jak squaw.","Biała squaw lubi rozmawiać.")+" ","Wielki Duch przyniósł białą twarz"+GetSexPhrase("bracie","siostra")+" do mnie.","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Tak.","Tak, to znowu ja.","Bardzo poetyckie.","Ja również cieszę się, że cię widzę.",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			
			if (npchar.quest.meeting == "0")
			{
				dialog.text = "Jak, biały bracie. Chcesz porozmawiać z Indianinem?";
				link.l1 = "Pozdrowienia, synu dżungli. Cieszę się, że cię widzę, ale muszę iść.";
				link.l1.go = "exit";
				npchar.quest.meeting = "1";
			}
			NextDiag.TempNode = "First time";
		break;

		//замечание по обнажённому оружию от персонажей типа citizen
		case "CitizenNotBlade":
			dialog.text = NPCharSexPhrase(NPChar,"Nie kusz duchów, blada twarzo! Schowaj długi nóż!","Nie spiesz się na śmierć, blady twarzy! Schowaj długi nóż!");
			link.l1 = LinkRandPhrase("Dobrze.","Jak sobie życzysz.","Jak powiadasz.");
			link.l1.go = "exit";
		break;

		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}
