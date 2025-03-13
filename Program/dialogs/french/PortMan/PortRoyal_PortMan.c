// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Quel genre de questions ?","Que veux-tu, "+GetAddress_Form(NPChar)+"?"),"Tu as déjà essayé de me poser une question "+GetAddress_Form(NPChar)+"...","Vous avez parlé de cette question pour la troisième fois aujourd'hui...","Écoute, si tu n'as rien à me dire sur les affaires du port, alors ne me dérange pas avec tes questions.","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("J'ai changé d'avis.","Je n'ai rien à dire."),"Peu importe.","En effet, déjà la troisième fois...","Désolé, mais les affaires du port ne m'intéressent pas pour l'instant.",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
			
			if (pchar.questTemp.Slavetrader == "FindRatJamaica")
            {
                link.l1 = "Bonne journée. Le capitaine François Gontier s'est-il enregistré ici ? Il naviguait depuis Porto Bello sur une corvette nommée '"+pchar.questTemp.Slavetrader.ShipName+".";
                link.l1.go = "Jamaica_ratPP_1";
            }
			
		break;
		
		case "Jamaica_ratPP_1":
			dialog.text = NPCStringReactionRepeat("Non, il ne l'a pas fait. Et la corvette '"+pchar.questTemp.Slavetrader.ShipName+"n'a pas été vu à Port-Royal.","Vous avez déjà posé cette question et j'ai répondu.","Je vous dis que vous avez déjà posé des questions sur ce bonhomme Gontier.","S'il vous plaît, ne me distrayez pas de mon travail !","block",0,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Merci. Je continuerai à chercher.","Hum, eh bien...","Oui, j'ai vraiment demandé ...","Pardon, "+npchar.name+"...",npchar,Dialog.CurrentNode);
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
