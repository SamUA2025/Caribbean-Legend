// диалог каторжников в шахте
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;
	string sTemp;
	bool bOk;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			dialog.text = NPCStringReactionRepeat("Entschuldigung, aber es wäre besser für uns beide, wenn wir nicht mehr miteinander reden. Sie werden mich bestrafen, und Sie werden gebeten zu gehen.","Ich habe dir schon alles gesagt, Freund. Oder möchtest du, dass ich wegen dir ausgepeitscht werde?","Ich höre nicht zu...","Der Degen trifft und klan-ngt gegen die Spitzhacke...","Block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Schwere Regeln habt ihr hier ...","Nein, natürlich will ich es nicht.","Hmmm...","Papa, kannst du mich hören...",npchar,Dialog.CurrentNode); 
			link.l1.go = DialogGoNodeRepeat("exit", "", "", "", npchar, Dialog.CurrentNode);
			NextDiag.TempNode = "First time";
		break;

		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
			
		case "CitizenNotBlade":
			dialog.text = "Kapitän, was machen Sie? Verstecken Sie Ihre Waffe, bevor Sie viel Ärger bekommen!";
			link.l1 = LinkRandPhrase("Gut.","Gut.","Mach dir keine Sorgen, ich verstecke es...");
			link.l1.go = "exit";
		break;  
	}
}
