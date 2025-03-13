// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Quel genre de questions ?","Que voulez-vous, "+GetAddress_Form(NPChar)+"?"),"Vous avez déjà essayé de me poser une question "+GetAddress_Form(NPChar)+"... ","Vous parlez de cette question pour la troisième fois aujourd'hui...","Écoutez, si vous n'avez rien à me dire sur les affaires du port, alors ne me dérangez pas avec vos questions.","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("J'ai changé d'avis.","Je n'ai rien à dire."),"Peu importe.","En effet, déjà la troisième fois...","Desole, mais je ne suis pas interesse par les affaires du port pour le moment.",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			
			if (pchar.questTemp.Slavetrader == "FindRatTortuga")
            {
                link.l1 = "Bonjour. Je cherche Francois Gontier. Sa corvette '"+pchar.questTemp.Slavetrader.ShipName+"doit avoir été ici dans votre port.";
                link.l1.go = "Tortuga_ratP_1";
            }
			
		break;

		case "Tortuga_ratP_1":
			dialog.text = NPCStringReactionRepeat("Hm... Je dois te décevoir. Corvette '"+pchar.questTemp.Slavetrader.ShipName+" n'a jamais été ici et Francois Gontier n'est pas non plus enregistré ici.","Vous avez déjà posé cette question et j'ai répondu.","Je vous dis que vous avez déjà posé des questions sur ce Gontier.","S'il vous plaît, ne me distrayez pas de mon travail !","block",0,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Merci. Je continuerai à chercher.","Hum, eh bien...","Oui, j'ai vraiment demandé ...","Pardonnez-moi, "+npchar.name+"... ",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;

	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
