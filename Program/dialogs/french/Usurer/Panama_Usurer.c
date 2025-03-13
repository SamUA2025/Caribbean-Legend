// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Quelles questions avez-vous ?","Comment puis-je vous aider ?"),"Vous avez essayé de me poser cette question il n'y a pas si longtemps...","Oui, laissez-moi deviner... Encore une fois à tourner en rond ?","Écoutez, je suis celui qui gère les finances ici, je ne réponds pas aux questions...","block",1,npchar,Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("J'ai changé d'avis...","Je n'ai rien à dire pour le moment."),"Hum, où est passée ma mémoire...","Vous avez deviné, je suis désolé...","Je comprends...",npchar,Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
		
		// Реакция ростовщика Панамы на репутацию ГГ или на разграбление Картахены по сюжету
		case "Panama_Deposit_NoReputation":
			dialog.text = "C'est exact... Un homme d'honneur aimé des sujets du Roi ne sera jamais refusé par ma banque, quelle que soit sa nationalité.";
			link.l1 = "Je comprends. Adieu.";
			link.l1.go = "exit";
		break;
		
		case "Panama_Deposit_Cartahena":
			dialog.text = "Mais ma fille et mon beau-père l'ont eu, malheureusement. Ils vivaient à Carthagène. Allez-vous-en, "+GetAddress_Form(NPChar)+"Vous n'êtes pas le bienvenu ici.";
			if (pchar.questTemp.Mtraxx.Retribution.Choice == "good")
			{
				link.l1 = " Pardonnez-moi. Adieu.";
				link.l1.go = "exit";
			}
			else
			{
				link.l1 = "Votre perte. Au revoir.";
				link.l1.go = "exit";
			}
			NextDiag.TempNode = "NeHochuRazgovarivat";
		break;
		
		case "Panama_Deposit_SgorelVklad":
			dialog.text = "Les fonds ont été saisis par la Couronne pour aider les victimes du sac de la ville de Carthagène. Je ne peux pas vous aider. Je vais vous demander de quitter ma banque immédiatement avant que j'appelle les gardes !";
			link.l1 = "Vous allez le regretter...";
			link.l1.go = "exit";
			NextDiag.TempNode = "NeHochuRazgovarivat";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
