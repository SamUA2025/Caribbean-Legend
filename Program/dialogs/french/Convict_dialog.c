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
			dialog.text = NPCStringReactionRepeat("Désolé, mais il serait préférable pour nous deux si nous ne nous parlons plus. Ils me puniront, et on vous demandera de partir.","Je t'ai déjà tout dit, mon ami. Ou veux-tu que je sois fouetté à cause de toi?","Je n'écoute pas...","Le sp-ade frappe et clan-ang la pioche...","bloc",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Des règles sévères que vous avez ici...","Non, bien sûr, je n'en veux pas.","Hmmm...","Papa, peux-tu m'entendre...",npchar,Dialog.CurrentNode); 
			link.l1.go = DialogGoNodeRepeat("exit", "", "", "", npchar, Dialog.CurrentNode);
			NextDiag.TempNode = "First time";
		break;

		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
			
		case "CitizenNotBlade":
			dialog.text = "Capitaine, que faites-vous? Cachez votre arme, avant que vous n'ayez beaucoup d'ennuis!";
			link.l1 = LinkRandPhrase("D'accord.","D'accord.","Ne t'inquiète pas, je le cache...");
			link.l1.go = "exit";
		break;  
	}
}
